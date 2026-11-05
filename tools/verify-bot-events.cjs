// Bot event contract: GEM keeps one handler per event and runs callbacks unprotected
// (luaD_throw -> panic -> abort, crash 0xc0000409 without a minidump). Every mode must
// subscribe each event once, run OnGameStart, and survive quants/timers without a Lua error.
// Usage: node tools/verify-bot-events.cjs [reference-script-dir] [resource-dir]
const fs = require('fs'), path = require('path'), assert = require('assert/strict');
const { lua, lauxlib, lualib, to_luastring, to_jsstring } = require('fengari');
const repo = path.resolve(__dirname, '..');
const vanilla = path.resolve(process.argv[2] || path.join(repo, '../_survival_work/hf-update-20261105/reference/resource/script'));
assert(fs.existsSync(vanilla), 'Pass the current effective game + HF script directory; the HF 4 test must not use an old vanilla snapshot.');
const roots = [
  path.join(process.argv[3] ? path.resolve(process.argv[3]) : path.join(repo, 'mods/ultimate_frontline_bundle/resource'), 'script'),
  vanilla,
];
const resolve = name => {
  const rel = name.replace(/^\/?(resource\/)?script\//, '') + '.lua';
  for (const root of roots) { const file = path.join(root, rel); if (fs.existsSync(file)) return file; }
  return null;
};

const harness = (mode, army) => `
local handlers, subs, timers, nextTimer = {}, {}, {}, 0
logs = {}
print = function(...) local t = {} for i = 1, select('#', ...) do t[#t + 1] = tostring(select(i, ...)) end logs[#logs + 1] = table.concat(t, ' ') end
local stub = {__index = function() return function() end end}
BotApi = {
  Instance = {spawnPointName = 'a11', gameMode = '${mode}', enemyTeam = 'b', team = 'a', ownTeamSize = 2,
    playerId = 3, army = '${army}', hostId = 1, difficulty = 'normal', unitMode = 'mid'},
  Commands = setmetatable({CanSpawn = function() return true end, Income = function() return 0 end,
    TimeToSpawnUnit = function() return 0 end, IsUnitAvailable = function() return true end,
    Spawn = function() return true end}, stub),
  Scene = setmetatable({Flags = {}, Waypoints = {}, Squads = {}, IsSquadExists = function() return true end,
    IsSquadTagged = function() return false end, QueryScene = function() return {} end,
    GetVar = function() return 0 end}, stub),
  Conquest = {FirstPlayerId = 3, FirstEnemyId = 1, DefenderBotId = 3, ArmyCPLimit = 100, Risk = 0,
    PlayerSpawnPoint = 'b1', Attacking = false, ArmyCP = 0, OperationDay = 1, ArmySquads = {}},
  Events = {GameStart = 'GameStart', GameEnd = 'GameEnd', Quant = 'Quant', GameSpawn = 'GameSpawn',
    Waypoint = 'Waypoint', PrepTimeOver = 'PrepTimeOver', WinnerDecided = 'WinnerDecided',
    -- Observed in game.log 2026-10-06: a second GameStart subscription never ran, so the first one is kept.
    Subscribe = function(self, ev, fn) subs[ev] = (subs[ev] or 0) + 1; handlers[ev] = handlers[ev] or fn end,
    SetQuantTimer = function(self, fn) nextTimer = nextTimer + 1; timers[nextTimer] = fn; return nextTimer end,
    KillQuantTimer = function(self, id) timers[id] = nil end},
}
function module_exists(name) return jsResolve(name) end
table.insert(package.searchers, 2, function(name)
  local file = jsResolve(name)
  if not file then return 'not found ' .. name end
  return function() return dofile(file) end
end)
function dispatch(ev, args) if handlers[ev] then handlers[ev](args) end end
function fireTimers() local due = timers; timers = {}; for _, fn in pairs(due) do fn() end end
function subscriptions() return subs end
`;

function run(name, mode, army, script, body) {
  const L = lauxlib.luaL_newstate(); lualib.luaL_openlibs(L);
  lua.lua_pushcfunction(L, S => {
    const file = resolve(to_jsstring(lauxlib.luaL_checkstring(S, 1)));
    if (file) lua.lua_pushstring(S, to_luastring(file.split(path.sep).join('/'))); else lua.lua_pushnil(S);
    return 1;
  });
  lua.lua_setglobal(L, to_luastring('jsResolve'));
  const code = harness(mode, army) + `require([[resource/script/multiplayer/modes/${script}]])\n` + body;
  const status = lauxlib.luaL_dostring(L, to_luastring(code));
  const message = status === lua.LUA_OK ? null : to_jsstring(lua.lua_tostring(L, -1));
  lua.lua_close(L);
  assert.equal(message, null, `${name}: ${message}`);
  console.log('ok -', name);
}

const lifecycle = `
for ev, n in pairs(subscriptions()) do assert(n == 1, ev .. ' subscribed ' .. n .. ' times') end
dispatch('GameStart')
for _, line in ipairs(logs) do assert(not line:find('[UFB] Lua error', 1, true), line) end
local started = false
for _, line in ipairs(logs) do if line:find('AI Bot is player#', 1, true) then started = true end end
assert(started, 'OnGameStart did not run')
for i = 1, 50 do dispatch('Quant'); fireTimers() end
dispatch('GameSpawn', {squadId = 1}); fireTimers(); dispatch('Quant')
dispatch('GameEnd'); fireTimers()
for _, line in ipairs(logs) do assert(not line:find('[UFB] Lua error', 1, true), line) end
`;
run('ignored squads retain native combat behavior', 'battle_zones', 'ger', 'battlezones', `
local captures, seeks = 0, 0
BotApi.Scene.Flags = {{name='f1',occupant='b'}}
BotApi.Scene.IsSquadTagged = function(_,squad,tag) return tag == '_lua_ignore' end
BotApi.Commands.CaptureFlag = function() captures = captures + 1 end
BotApi.Commands.SeekAndDestroy = function() seeks = seeks + 1 end
math.random = function() return 0 end
CaptureFlag(1001)
assert(seeks == 1 and captures == 0, '_lua_ignore must reach the native seek-and-destroy decision')
BotApi.Scene.Waypoints = {'w1'}
GotoNextWaypoint(1001)
assert(captures == 0, 'waypoint movement must not override an ignored squad')
dispatch('GameEnd')
`);
run('battle_zones lifecycle', 'battle_zones', 'ger', 'battlezones', lifecycle);
run('ammunition lifecycle', 'ammunition', 'fin', 'battlezones', lifecycle);
run('annihilation lifecycle', 'annihilation', 'ger', 'battlezones', lifecycle);
run('frontlines lifecycle', 'frontlines', 'ger', 'frontlines', lifecycle);
run('evacuation lifecycle', 'evacuation', 'rus', 'laststand', lifecycle);
for (const army of ['ger', 'rus', 'fin', 'usa', 'eng']) {
  run('conquest defender lifecycle ' + army, 'campaign_capture_the_flag', army, 'conquest', lifecycle);
  run('conquest attacker lifecycle ' + army, 'campaign_capture_the_flag', army, 'conquest', 'BotApi.Conquest.Attacking = true\n' + lifecycle);
}

// A script error inside an engine callback must be logged, not escape to the engine.
run('callback errors are contained', 'battle_zones', 'ger', 'battlezones', `
dispatch('GameStart'); fireTimers()
BotApi.Commands.CanSpawn = function() error('boom') end
dispatch('Quant'); dispatch('Quant')
BotApi.Events:SetQuantTimer(function() error('timer boom') end, 1); fireTimers()
local quant, timer = 0, 0
for _, line in ipairs(logs) do
  if line:find('boom', 1, true) then quant = quant + 1 end
  if line:find('timer boom', 1, true) then timer = timer + 1 end
end
assert(quant == 2 and timer == 1, 'each distinct error logged once: ' .. quant .. '/' .. timer)
`);
