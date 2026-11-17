// Conquest phase boundaries with real HF modules and deterministic engine callbacks.
const fs=require('fs'),p=require('path'),assert=require('assert/strict');
const {lua,lauxlib,lualib,to_luastring,to_jsstring}=require('fengari');
const repo=p.resolve(__dirname,'..'),work=p.resolve(repo,'../_ai_work/conquest-audit-20261109');
const resource=p.resolve(process.argv.find(a=>a.startsWith('--resource='))?.slice(11)||p.join(repo,'mods/ultimate_frontline_bundle/resource'));
const roots=[resource,p.join(work,'effective-resource'),p.resolve(repo,'../_survival_work/hf-update-20261117/reference/resource')];
const load=file=>{const path=roots.map(root=>p.join(root,file)).find(f=>fs.existsSync(f));assert(path,file);return `dofile([[${path.replaceAll('\\','/')} ]])`.replace(' ]])',']])');};
const moduleLoad=name=>load('script/multiplayer/modes/conquest/'+name+'.lua');
const setup=`
local now,nextId,timers,queued,vars,starts,queries=0,0,{},{},{},{},0
local function count()local n=0;for _ in pairs(timers)do n=n+1 end;return n end
local function advance(untilTime)
 while true do local first,key
  for id,t in pairs(timers)do if t.at<=untilTime and (not first or t.at<first.at or t.at==first.at and id<key)then first,key=t,id end end
  if not first then break end;timers[key]=nil;now=first.at;first.fn()
 end;now=untilTime
end
print=function()end;printDebug=false;team='a';enemyTeam='b';spawnSide='a';Purchases={}
BotApi={Instance={playerId=3,hostId=1,army='ger',difficulty='normal',spawnPointName='a1',gameMode='campaign_capture_the_flag',enemyTeam='b',team='a',ownTeamSize=1},
 Conquest={FirstPlayerId=1,FirstEnemyId=3,DefenderBotId=3,ArmyCPLimit=100,Risk=0,Attacking=false,ArmyCP=0,OperationDay=1,ArmySquads={}},
 Events={Subscribe=function()end,SetQuantTimer=function(_,fn,delay)nextId=nextId+1;timers[nextId]={fn=fn,at=now+delay};queued[nextId]=fn;return nextId end,KillQuantTimer=function(_,id)timers[id]=nil end},
 Scene={Flags={{name='f1',occupant='a'}},Squads={},Waypoints={},GetVar=function(_,key)return vars[key] or 0 end,SetVar=function(_,key,value)vars[key]=value end,QueryScene=function()queries=queries+1;return {}end,IsSquadExists=function()return true end,IsSquadTagged=function()return false end},
 Commands={GameOver=function()end,IsUnitAvailable=function()return true end,TimeToSpawnUnit=function()return 0 end}}
math.random=function(low,high)if low then return low end;return 0.25 end
${moduleLoad('runtime_config')}
${moduleLoad('runtime_state')}
${moduleLoad('scene')}
${moduleLoad('scene_memory')}
${moduleLoad('battle_result')}
${moduleLoad('purchase_pressure')}
ConquestState.botDefender=true;ConquestState.defenderOpeningFinished=true
Context={SpawnWait={}}
ConquestWaves={StartPurchasePhase=function(phase,target)ConquestState.purchasePhase=phase;starts[#starts+1]={at=now,phase=phase,target=target}end,ResolveGarrisonReadyBeforePurchase=function()return true end,CanPurchaseUnit=function()return true end}
ConquestPurchaseProfiles={FinishPurchasePhasePlan=function()end}
${moduleLoad('defender_counterattack')}
local function owner(value)BotApi.Scene.Flags[1].occupant=value;ConquestDefenderCounterattack.UpdateFlagOwnership()end
ConquestDefenderCounterattack.UpdateFlagOwnership()
`;
let scenarios=0,failures=0;const rows=[];
function run(name,body){const L=lauxlib.luaL_newstate();lualib.luaL_openlibs(L);const status=lauxlib.luaL_dostring(L,to_luastring(setup+body));const error=status===lua.LUA_OK?null:to_jsstring(lua.lua_tostring(L,-1));lua.lua_close(L);rows.push({name,passed:!error,...(error?{error}:{})});scenarios++;if(error)failures++;console.log((error?'FAIL':'ok')+' - '+name+(error?': '+error:''));}
run('normal counterattack keeps the native 50 s confirmation and response delay',`
owner('b');advance(59999);assert(#starts==0);advance(60000);assert(#starts==1 and queries==1)
`);
run('regaining and losing the flag restarts its confirmation window',`
owner('b');advance(10000);owner('a');advance(20000);owner('b');advance(79999);assert(#starts==0,'counterattack used the earlier flag loss');advance(80000);assert(#starts==1)
`);
run('a queued old confirmation cannot confirm a newer flag loss',`
owner('b');local stale=queued[nextId];advance(10000);owner('a');advance(20000);owner('b');stale();advance(79999);assert(#starts==0,'old confirmation affected replacement');advance(80000);assert(#starts==1)
`);
run('a queued old response cannot start a replacement counterattack',`
owner('b');advance(50000);local stale=queued[nextId];advance(55000);owner('a');advance(56000);owner('b');stale();assert(#starts==0,'old response started a replacement');advance(115999);assert(#starts==0);advance(116000);assert(#starts==1)
`);
run('a regained flag removes pending timers immediately',`
owner('b');owner('a');assert(count()==0 and next(ConquestState.counterattackPendingByFlag)==nil,'pending counterattack survived regain')
`);
run('retreat cancels pending counterattacks without taking new scene snapshots',`
owner('b');vars.defender_retreat_requested=1;advance(60000);assert(#starts==0 and queries==0,'counterattack started during bot retreat')
`);
run('a missing objective cannot consume the counterattack budget',`
owner('b');BotApi.Scene.Flags={};advance(60000);assert(#starts==0 and queries==0,'counterattack started without its objective')
`);
run('opening garrisons stay protected until their purchase stage ends',`
ConquestState.defenderOpeningFinished=false;owner('b');advance(60000);assert(#starts==0);ConquestState.defenderOpeningFinished=true;ConquestDefenderCounterattack.UpdateFlagOwnership();assert(#starts==1)
`);
run('native total and per-objective counterattack limits remain enforced',`
for i=1,5 do BotApi.Scene.Flags[i]={name='f'..i,occupant='a'}end;ConquestDefenderCounterattack.UpdateFlagOwnership()
for _,f in ipairs(BotApi.Scene.Flags)do f.occupant='b'end;ConquestDefenderCounterattack.UpdateFlagOwnership();advance(60000)
for i=1,5 do ConquestDefenderCounterattack.FinishActive();ConquestDefenderCounterattack.TryStartAnyPending()end
assert(#starts==ConquestConfig.DefenderCounterattack.MaxTotal and queries==#starts)
for _,n in pairs(ConquestState.counterattacksByFlag)do assert(n<=ConquestConfig.DefenderCounterattack.MaxPerFlag)end
`);
run('game end cancels counterattack timers and rejects already queued callbacks',`
owner('b');local stale=queued[nextId];${load('script/multiplayer/modes/utility.lua')}
OnGameStop();assert(count()==0,'game end left counterattack timers');stale();assert(count()==0 and #starts==0)
`);
const purchaseSetup=`
ConquestAttackerWaveOff={ShouldDeferPurchaseForWaveOff=function()return false end}
ConquestAttackerFailure={ShouldDeferPurchaseForFailureCheck=function()return false end}
local limitCalls,ttsCalls=0,0
GetUnitSelectionTTSLimit=function()limitCalls=limitCalls+1;return 90000 end
${moduleLoad('purchase_scoring')}
${moduleLoad('purchase')}
local function candidate(name)return {unit=name,availability='1.0',base={'Infantry','Squad'},class={},grade='Grade2',posture={'Flexible'},roles={'Line'},effects={}}end
BotApi.Commands.TimeToSpawnUnit=function(_,name)ttsCalls=ttsCalls+1;return name=='locked' and 180000 or name=='pending' and 60000 or 0 end
`;
run('a long-locked purchase does not starve an available campaign unit',purchaseSetup+`
for i=0,19 do math.random=function(low)if low then return low end;return (i+0.5)/20 end
 local u=GetUnitToSpawn({candidate('locked'),candidate('ready')});assert(u and u.unit=='ready','selected a unit beyond the native wait deadline')
end;assert(queries==0)
`);
run('a short unit timer remains an eligible purchase with one limit read',purchaseSetup+`
local u=GetUnitToSpawn({candidate('pending')});assert(u and u.unit=='pending');assert(limitCalls<=1 and ttsCalls<=1 and queries==0)
`);
run('an entirely locked roster returns an empty choice for the bounded retry',purchaseSetup+`
assert(GetUnitToSpawn({candidate('locked')})==nil,'long-locked roster still selected a unit')
`);
for(const army of ['ger','rus','fin','usa','eng'])run(army+' campaign roster produces valid choices on all difficulties',purchaseSetup+`
${load('script/multiplayer/units/'+army+'/conquest.'+army+'.lua')}
local list=Purchases['conquest.${army}'][1].Units;assert(#list>0)
for _,difficulty in ipairs({'easy','normal','hard','heroic'})do
 BotApi.Instance.difficulty=difficulty
 for _,phase in ipairs({'defender_opening','attacker_wave','defender_counterattack'})do
  ConquestState.purchasePhase=phase;ConquestState.purchasePlan=nil
  local u=GetUnitToSpawn(list);assert(u and u.unit and ConquestPurchaseScoring.GetPurchaseForceCost(u)>0,difficulty..' '..phase)
 end
end
assert(queries==0,'roster scoring added scene queries')
`);
const result={scenarios,failures,passed:failures===0,engineMovementEmulated:false,results:rows};
const report=process.argv.find(a=>a.startsWith('--report='));if(report)fs.writeFileSync(p.resolve(report.slice(9)),JSON.stringify(result,null,2));
console.log(JSON.stringify({scenarios,failures,passed:result.passed}));if(failures)process.exitCode=1;
