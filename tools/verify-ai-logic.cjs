const fs=require('fs'),path=require('path'),assert=require('assert/strict');
const {lua,lauxlib,lualib,to_luastring,to_jsstring}=require('fengari');
const resource=path.resolve(process.argv[2]||path.join(__dirname,'../mods/ultimate_frontline_bundle/resource'));
const baseline=process.argv[3]&&path.resolve(process.argv[3]);
const base='script/multiplayer/modes/',read=(folder,file)=>fs.readFileSync(path.join(folder==='effective'?baseline:resource,base+file+'.lua'),'utf8');
let checks=0;const results=[];
const setup=`
local timers, queued, nextTimer, alive, orders, logs = {}, {}, 0, true, 0, {}
local function timerCount() local n=0;for _ in pairs(timers) do n=n+1 end;return n end
local function fire(id) local fn=timers[id];assert(fn);timers[id]=nil;fn() end
local function check(ok,msg) assert(ok,msg); checks=checks+1 end
checks=0
print=function(...) logs[#logs+1]={...} end
BotApi={Instance={spawnPointName='a1',gameMode='battle_zones',enemyTeam='b',team='a',ownTeamSize=2,playerId=2},
 Commands={CanSpawn=function() return true end, Income=function() return 1000 end,TimeToSpawnUnit=function() return 0 end,IsUnitAvailable=function() return true end},
 Scene={Flags={},Waypoints={},Squads={},IsSquadExists=function() return alive end,IsSquadTagged=function() return false end,
 QueryScene=function() return {{1,{0,0,0,0,0,0,0}},{2,{0,0,0,0,0,0,0}}} end},
 Events={Subscribe=function() end,SetQuantTimer=function(_,fn,delay) nextTimer=nextTimer+1;timers[nextTimer]=fn;queued[nextTimer]=fn;return nextTimer end,
 KillQuantTimer=function(_,id) timers[id]=nil end}}
package.preload['/script/multiplayer/modes/utility']=function() return {} end
package.preload['/script/multiplayer/ufb_order_guard']=function() return {Wrap=function(fn) return fn end} end
`;
function run(name,old,mode,body){
 if(old&&!baseline)return;
 const state=lauxlib.luaL_newstate();lualib.luaL_openlibs(state);
 const code=setup+read(old?'effective':'stage','utility')+'\n'+(mode?read(old?'effective':'stage',mode):'')+'\n'+body+'\nreturn checks';
 const status=lauxlib.luaL_dostring(state,to_luastring(code));if(status!==lua.LUA_OK)throw Error(name+': '+to_jsstring(lua.lua_tostring(state,-1)));
 const n=lua.lua_tointeger(state,-1);checks+=n;results.push({name,assertions:n});lua.lua_close(state);
}
run('Reproduce old duplicate timers and stale ownership',true,null,`
SetSquadOrder(function() orders=orders+1 end,1,150000)
SetSquadOrder(function() orders=orders+1 end,1,150000)
check(timerCount()==2,'old duplicate reproduced')
OnGameStop();check(timerCount()==1,'old orphan survives stop')
`);
run('Timer replacement, cancelled callbacks, dead squads and stop',false,null,`
local order=function() orders=orders+1 end
SetSquadOrder(order,1,150000);local old=nextTimer
SetSquadOrder(order,1,150000)
check(timerCount()==1 and orders==2,'one recurring chain')
queued[old]();check(orders==2 and timerCount()==1,'cancelled callback inert')
fire(nextTimer);check(orders==3 and timerCount()==1,'live order repeats once')
alive=false;fire(nextTimer);check(orders==3 and timerCount()==0 and Context.SquadTimers[1]==nil,'dead squad retires')
SetSquadOrder(order,1,150000);check(orders==3 and timerCount()==0,'cannot order dead squad')
alive=true;SetSquadOrder(order,1,150000);local ending=nextTimer;OnGameStop()
check(timerCount()==0 and next(Context.SquadTimers)==nil,'stop clears ownership')
queued[ending]();check(timerCount()==0 and orders==4,'late stop callback inert')
`);
for(const old of [true,false])run((old?'Reproduce':'Fix')+' Frontlines preparation order storm',old,'frontlines',`
CaptureFlag=function() orders=orders+1 end
SetSquadOrder(CaptureFlag,1,150000);OnPrepTimeOver()
check(orders==${old?3:2},'preparation assignment count')
check(timerCount()==${old?2:1},'preparation timer count')
`);
for(const old of [true,false])run((old?'Reproduce':'Fix')+' repeated empty purchases',old,null,`
local selections=0
UpdateUnitToSpawn=function() selections=selections+1;Context.SpawnInfo=nil end
for i=1,1000 do TrySpawnUnit() end
check(selections==${old?1000:1},'bounded empty-roster work')
${old?'':`fire(nextTimer);TrySpawnUnit();check(selections==2,'retry resumes');OnGameStop();check(timerCount()==0,'retry cleared at stop')`}
`);
run('Weighted selection, zero weights and diagnostics independence',false,null,`
debug.getinfo=function() error('stack inspection used') end
table.sort=function() error('sorting used') end
local originalRandom=math.random
local items={{w=1,name='a'},{w=3,name='b'},{w=0,name='never'}}
local counts={a=0,b=0};local rates=0
for i=0,99 do math.random=function() return (i+0.5)/100 end
 local selected=GetRandomItem(items,function(t) rates=rates+1;return t.w end)
 counts[selected.name]=counts[selected.name]+1
end
check(counts.a==25 and counts.b==75,'weight ratio preserved')
check(rates==300,'one weight evaluation per item')
check(GetRandomItem({},function() error('unexpected') end)==nil,'empty safe')
check(GetRandomItem({0,-1,math.huge,0/0},function(t) return t end)==nil,'invalid weights safe')
check(GetRandomItem({{w=0},{w=1}},function(t) return t.w end).w==1,'zero excluded')
check(#logs==0,'no misleading Caller nil diagnostics')
captureBackFlag=true;GetRandomItem(items,function(t) return t.w end);check(captureBackFlag,'selection does not mutate strategic state')
check(GetPlayerUnitCounts({{9,{77}},{2,{11}}},2)[1]==11,'ID independent of row index')
check(next(GetPlayerUnitCounts(nil,2))==nil,'empty scene safe')
check(next(GetPlayerUnitCounts({{9,{77}}},2))==nil,'missing player safe')
`);
for(const mode of ['battlezones','frontlines','laststand'])for(const old of [true,false])run((old?'Reproduce':'Fix')+' '+mode+' purchase class weights',old,mode,`
captureBackFlag=false;team='b'
GetCurrentSpawnWaitTime=function() return 90000 end
local limitCalls=0;GetUnitSelectionTTSLimit=function() limitCalls=limitCalls+1;return 90000 end
local weights={}
GetRandomItem=function(items,getRate) for _,v in pairs(items) do weights[v.unit]=getRate(v) end end
GetUnitToSpawn({{unit='squad',type={'Infantry','Squad','Class2'},priority=1},{unit='gun',type={'Cannon','Class2'},priority=1},{unit='vehicle',type={'Vehicle','Class2'},priority=1}})
check(math.abs(weights.squad-${old?1.3467:2.01})<0.000001,'single squad class multiplier')
check(math.abs(weights.gun-${old?0.035912:0.0536})<0.000001,'single cannon class multiplier')
check(math.abs(weights.vehicle-0.067)<0.000001,'vehicle multiplier preserved')
check(limitCalls==${old?3:1},'selection limit read once')
BotApi.Scene.QueryScene=function() return {{1,{0,0,0,0,0,0,0}},{2,{20,0,3,0,0,0,0}}} end
GetUnitToSpawn({{unit='inf',type={'Infantry','Class1'},priority=1}})
check(math.abs(weights.inf-${old?0.1:1})<0.000001,'AT troops counted once against total limit')
`);
for(const old of [true,false])run((old?'Reproduce':'Fix')+' rear flag roster starvation',old,'battlezones',`
captureBackFlag=true
local unit={unit='inf',type={'Infantry','Class1'},priority=1}
check((GetUnitToSpawn({unit})==nil)==${old?'true':'false'},'available non-Aux infantry purchase')
check(captureBackFlag,'rear-flag objective retained until assignment')
`);
for(const mode of ['battlezones','frontlines','laststand'])run(mode+' missing and reordered scene rows',false,mode,`
captureBackFlag=false;GetCurrentSpawnWaitTime=function() return 90000 end
local unit={unit='inf',type={'Infantry','Class1'},priority=1}
BotApi.Scene.QueryScene=function() return {} end
check(GetUnitToSpawn({unit})==unit,'empty scene accepted')
BotApi.Scene.QueryScene=function() return {{2,{20,0,3,0,0,0,0}},{8,{40}}} end
check(GetUnitToSpawn({unit})==unit,'reordered scene accepted')
`);
console.log('Logic:',checks,'assertions;',results.length,'scenarios; mocked BotApi, no game launch');
