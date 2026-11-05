// Native HF 4 job ownership: suppress Lua movement during the HF pause, then resume.
// node tools/verify-hf4-ai.cjs [UFB resource]
const fs=require('fs'),p=require('path'),assert=require('assert/strict');
const {lua,lauxlib,lualib,to_luastring,to_jsstring}=require('fengari');
const s=require('./lib/sdl.cjs');
const resource=p.resolve(process.argv[2]||p.join(__dirname,'../mods/ultimate_frontline_bundle/resource'));
const human=s.parse(fs.readFileSync(p.join(resource,'set/interaction_entity/human.inc'),'latin1'));
for(const event of ['ai_wirecutter_animation','ai_generic_cooldown_5sec','ai_generic_cooldown_60sec']){
 const n=s.all(human,n=>s.name(n)==='on'&&n.tokens[1]?.value===event)[0];assert(n,'Missing HF 4 event: '+event);
 assert(s.all(n,n=>s.name(n)==='tags'&&n.tokens[1]?.value==='add'&&n.tokens[2]?.value==='_ai_do_not_disturb').length,event+' does not reserve its job');
 assert(s.all(n,n=>s.name(n)==='delay'&&s.all(n,c=>s.name(c)==='tags'&&c.tokens[1]?.value==='remove'&&c.tokens[2]?.value==='_ai_do_not_disturb').length).length,event+' does not release its job');
}
const file=p.join(resource,'script/multiplayer/ufb_order_guard.lua').replaceAll('\\','/');
const code=`
local jobs,timers,queued,id,orders,exists,retreat = {},{},{},0,0,true,false
BotApi={Scene={Waypoints={},IsSquadExists=function() return exists end,IsSquadTagged=function(_,squad,tag) return jobs[tag] or false end},
 Events={SetQuantTimer=function(_,fn,delay) assert(delay>0);id=id+1;timers[id]=fn;queued[id]=fn;return id end,KillQuantTimer=function(_,key) timers[key]=nil end}}
ShouldStopNormalSquadOrders=function() return retreat end
local guard=dofile('${file}')
local function count() local n=0;for _ in pairs(timers) do n=n+1 end;return n end
local function fire(key) local fn=timers[key];assert(fn);timers[key]=nil;fn() end
local capture=guard.Wrap(function() orders=orders+1 end,false)
jobs._ai_do_not_disturb=true
capture(10);assert(orders==0,'HF 4 pause was overwritten by a Lua capture order')
assert(count()==1,'temporary HF job needs one resume timer')
local stale=id;capture(10);assert(count()==1,'repeated assignment must replace, not multiply the retry')
queued[stale]();assert(orders==0 and count()==1,'cancelled callback must not resume an HF job')
jobs._ai_do_not_disturb=nil;fire(id)
assert(orders==1 and count()==0,'squad must resume after HF releases its job')
jobs._lua_mi=true;capture(10);assert(orders==1 and count()==0,'permanent mission job must not create a polling loop');jobs._lua_mi=nil
jobs._ai_do_not_disturb=true;capture(10);exists=false;fire(id)
assert(orders==1 and count()==0,'dead squad must not retain retries');exists=true
capture(10);retreat=true;fire(id);assert(orders==1 and count()==0,'retreat must cancel deferred orders');retreat=false
capture(10);local ending=id;guard.Stop();queued[ending]();capture(10)
assert(orders==1 and count()==0,'game end must cancel queued and future orders')
`;
const L=lauxlib.luaL_newstate();lualib.luaL_openlibs(L);
const status=lauxlib.luaL_dostring(L,to_luastring(code));
const error=status===lua.LUA_OK?null:to_jsstring(lua.lua_tostring(L,-1));lua.lua_close(L);assert.equal(error,null,error);
console.log('HF 4 AI: native pause ownership, bounded retries, release, death, retreat and game end passed.');
