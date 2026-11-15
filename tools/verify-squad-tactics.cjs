const fs=require('fs'),p=require('path'),assert=require('assert/strict');
const {lua,lauxlib,lualib,to_luastring,to_jsstring}=require('fengari');
const root=p.resolve(__dirname,'../mods/ultimate_frontline_bundle/resource/script/multiplayer').replaceAll('\\','/');
const code=`
local now,id,timers,queued,jobs,dead,orders=0,0,{},{},{},{},{}
BotApi={Scene={IsSquadExists=function(_,sq)return not dead[sq] end,IsSquadTagged=function(_,sq,tag)return jobs[sq] and jobs[sq][tag] or false end},
Events={SetQuantTimer=function(_,fn,delay)id=id+1;timers[id]={fn=fn,at=now+delay};queued[id]=fn;return id end,KillQuantTimer=function(_,key)timers[key]=nil end},
Commands={CaptureFlag=function(_,sq,target)orders[#orders+1]={sq=sq,target=target,at=now}end}}
local retreat=false
ShouldStopNormalSquadOrders=function()return retreat end
local function advance(time)
 while true do local first,key
  for k,t in pairs(timers)do if t.at<=time and (not first or t.at<first.at)then first,key=t,k end end
  if not first then break end;timers[key]=nil;now=first.at;first.fn()
 end;now=time
end
local function count()local n=0;for _ in pairs(timers)do n=n+1 end;return n end
local tactics=dofile('${root}/ufb_squad_tactics.lua')
local protected=function(sq)return jobs[sq] and jobs[sq].busy end
local resumed={};local resume=function(sq)resumed[#resumed+1]=sq end
for i, tag in ipairs({'_ufb_k_armor','_ufb_k_gun_light','_ufb_k_gun_heavy','_ufb_k_gun_at','bot_arty','bot_aa_guard'}) do
 local sq=300+i;jobs[sq]={[tag]=true};local n=#orders;tactics.Capture(sq,'native',protected,resume)
 assert(#orders==n+1 and orders[#orders].at==now and count()==0 and tactics.Role(sq)==nil,'native class delayed: '..tag)
end
orders={}
tactics.Capture(1,'front',protected,resume);tactics.Capture(2,'front',protected,resume);tactics.Capture(3,'front',protected,resume)
assert(tactics.Role(1)=='advance' and tactics.Role(2)=='cover' and tactics.Role(3)=='reserve')
assert(#orders==1 and orders[1].sq==1 and orders[1].at==0)
advance(1499);assert(#orders==1);advance(1500);assert(#orders==2 and orders[2].sq==2)
advance(3000);assert(#orders==3 and orders[3].sq==3)
for _,o in ipairs(orders)do assert(o.target=='front')end
advance(12000);assert(count()==0 and tactics.Role(1)==nil)
tactics.Capture(4,'next',protected,resume);tactics.Capture(5,'next',protected,resume);tactics.Capture(6,'next',protected,resume)
jobs[4]={_ufb_recent_hit=true};advance(12750);assert(orders[#orders].sq==6,'reserve reinforces early when lead is hit')
tactics.Capture(7,'other',protected,resume);tactics.Capture(8,'other',protected,resume);dead[8]=true;local n=#orders;advance(15000);assert(#orders==n,'dead cover cannot receive a command')
tactics.Capture(9,'guarded',protected,resume);tactics.Capture(10,'guarded',protected,resume);jobs[10]={busy=true};advance(16500);assert(resumed[1]==10,'HF ownership resumes through Guard instead of being overridden')
tactics.Capture(11,'end',protected,resume);tactics.Capture(12,'end',protected,resume);local ending=id;retreat=true;local previous=#orders;advance(19500);assert(#orders==previous,'retreat cancels pending cohort movement')
retreat=false;tactics.Capture(13,'stop',protected,resume);tactics.Capture(14,'stop',protected,resume);local stale=id;tactics.Stop();assert(count()==0);queued[stale]();tactics.Capture(15,'stop',protected,resume);assert(count()==0)
-- Fresh module tests bounded overflow and complete cleanup for repeated same-target cohorts.
local bounded=dofile('${root}/ufb_squad_tactics.lua')
for i=1,200 do bounded.Capture(1000+i,'same',protected,resume)end
assert(count()<=24*3,'bounded cohort timers')
bounded.Stop();assert(count()==0,'all predecessor cohort expiry timers retired')
-- Test the real Guard timer, not merely an assertion that some timer exists.
package.preload['/script/multiplayer/ufb_squad_tactics']=function()return dofile('${root}/ufb_squad_tactics.lua')end
package.cpath='';BotApi.Scene.Waypoints={};local guard=dofile('${root}/ufb_order_guard.lua');jobs[77]={_ufb_job_reserved=true};local issued=0
local wrapped=guard.Wrap(function()issued=issued+1 end,false);wrapped(77)
local retry;for _,t in pairs(timers)do retry=t end;assert(retry and retry.at-now==750,'750 ms resume timer')
jobs[77]=nil;advance(now+750);assert(issued==1 and count()==0)
-- A newer explicit order owns the squad, including waypoint and fallback orders.
local capture=guard.Wrap(function(sq)return guard.Capture(sq,'oldObjective')end,false)
capture(80);capture(81);local pendingCohort=id
BotApi.Scene.Waypoints={1}
local waypoint=guard.Wrap(function(sq)return BotApi.Commands:CaptureFlag(sq,'newWaypoint')end,true)
waypoint(81);local afterNew=#orders;queued[pendingCohort]();advance(now+3000)
assert(#orders==afterNew and orders[#orders].target=='newWaypoint','stale cohort callback overwrote a newer waypoint order')
capture(82)
local fallback=guard.Wrap(function(sq)return BotApi.Commands:CaptureFlag(sq,'fallback')end,false)
fallback(82);afterNew=#orders;advance(now+3000)
assert(#orders==afterNew and orders[#orders].target=='fallback','stale cohort callback overwrote a newer fallback order')
guard.Stop()
`;
const state=lauxlib.luaL_newstate();lualib.luaL_openlibs(state);const status=lauxlib.luaL_dostring(state,to_luastring(code));
const error=status===lua.LUA_OK?null:to_jsstring(lua.lua_tostring(state,-1));lua.lua_close(state);assert.equal(error,null,error);
console.log(JSON.stringify({squadRoles:true,sharedObjective:true,stagedRelease:true,underFireReinforcement:true,protectedJobs:true,deadSquads:true,retreat:true,boundedTimers:true,staleCallbacks:true,newOrdersCancelPendingCohorts:true,nativeClassOrdersImmediate:true,resumeMilliseconds:750,passed:true}));
