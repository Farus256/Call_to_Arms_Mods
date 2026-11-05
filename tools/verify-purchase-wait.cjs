// Resource availability can change before the native 91-second selection timeout.
// The AI must retry the SAME candidate promptly and keep the native deadline for reselection.
const fs=require('fs'),p=require('path'),assert=require('assert/strict');
const {lua,lauxlib,lualib,to_luastring,to_jsstring}=require('fengari');
const resource=p.resolve(process.argv[2]||p.join(__dirname,'../mods/ultimate_frontline_bundle/resource'));
const utility=fs.readFileSync(p.join(resource,'script/multiplayer/modes/utility.lua'),'utf8');
const setup=`
local now,nextId,timers,queued,attempts,buys,selections,availableAt=0,0,{},{},0,0,0,5000
local messages={};print=function(...) messages[#messages+1]=table.concat({...},' ') end
BotApi={Instance={spawnPointName='a1',gameMode='battle_zones',enemyTeam='b',team='a',ownTeamSize=2,playerId=1},
 Scene={IsSquadExists=function() return true end,Flags={},Waypoints={},Squads={}},Commands={CanSpawn=function() return true end,IsUnitAvailable=function() return true end,TimeToSpawnUnit=function() return 0 end},
 Events={Subscribe=function() end,SetQuantTimer=function(_,fn,delay) nextId=nextId+1;timers[nextId]={fn=fn,due=now+delay};queued[nextId]=fn;return nextId end,KillQuantTimer=function(_,id) timers[id]=nil end}}
local function count()local n=0;for _ in pairs(timers)do n=n+1 end;return n end
`;
function run(name,body){
 const code=setup+utility+`
GetCurrentSpawnWaitTime=function()return 90000 end
GameModeSpawnCooldown=function()return 1000 end
UpdateUnitToSpawn=function()selections=selections+1;Context.SpawnInfo={unit='candidate'..selections} end
GameModeSpawnUnit=function()attempts=attempts+1;if now>=availableAt then buys=buys+1;return true end;return false end
local function advance(ms)
 local endAt=now+ms
 while now<endAt do
  now=math.min(now+500,endAt)
  local due={};for id,t in pairs(timers)do if t.due<=now then due[#due+1]=id end end;table.sort(due)
  for _,id in ipairs(due)do local t=timers[id];if t then timers[id]=nil;t.fn() end end
  TrySpawnUnit()
 end
end
`+body;
 const L=lauxlib.luaL_newstate();lualib.luaL_openlibs(L);const status=lauxlib.luaL_dostring(L,to_luastring(code));
 const message=status===lua.LUA_OK?null:to_jsstring(lua.lua_tostring(L,-1));lua.lua_close(L);assert.equal(message,null,name+': '+message);console.log('ok - '+name);
}
run('buy within one second after resources become available',`
TrySpawnUnit();advance(5500)
assert(buys==1,'resources became available at 5s but the bot is still waiting for the 91s timeout')
assert(selections==1,'availability retries must keep the same chosen unit')
assert(attempts<=7,'retry work must be bounded to once per second')
`);
run('unavailable purchase keeps its native reselection deadline',`
availableAt=math.huge;TrySpawnUnit();advance(90000)
assert(selections==1,'do not reroll the chosen unit before the native timeout')
assert(count()<=2,'waiting must have at most one retry and one deadline timer')
advance(1000);assert(selections==2,'native 91-second deadline must release the pending selection')
assert(attempts<=94,'spawn retries must be bounded')
`);
run('successful purchase rejects old queued wait callbacks',`
TrySpawnUnit();local old={};for id,fn in pairs(queued)do old[#old+1]=fn end
advance(5500);assert(buys==1)
Context.SpawnInfo={unit='newer-unit'}
for _,fn in ipairs(old)do fn() end
assert(Context.SpawnInfo.unit=='newer-unit','stale timeout cleared a newer choice')
`);
run('game end cancels every purchase wait timer',`
availableAt=math.huge;TrySpawnUnit();local old={};for _,fn in pairs(queued)do old[#old+1]=fn end
OnGameStop();assert(count()==0,'game end left a purchase timer')
for _,fn in ipairs(old)do fn() end
assert(count()==0 and not Context.SpawnWait.RetryPendingUnit,'queued callbacks revived a stopped purchase')
`);
run('a new unit lock cancels its pending wait without losing later purchases',`
BotApi.Commands.TimeToSpawnUnit=function(_,unit)if unit=='candidate1' and now>=2000 then return 180000 end;return 0 end
TrySpawnUnit();advance(5500)
assert(buys==1 and selections==2,'a newly locked unit must release its wait so another eligible unit can be bought')
`);
