const fs=require('fs'),path=require('path'),assert=require('assert/strict');
const s=require('./lib/sdl.cjs');
const root=path.join(__dirname,'../mods/ultimate_frontline_bundle/resource');
const cfg=require('./tactical-balance.json');
const read=rel=>fs.readFileSync(path.join(root,rel),'utf8');
let checks=0;function check(value,message){assert(value,message);checks++;}
const levels=s.all(s.parse(read('set/ability/health.set')),n=>s.name(n)==='level');
const factor=label=>Number(levels.find(n=>n.tokens[1].value===label).tokens[2].value);
check(factor('0%')===0,'zero health sentinel preserved');
check(factor('100%')===1,'fallback health factor');
for(const n of levels){const v=Number(n.tokens[2].value);check(v>=0&&v<=cfg.maximumBreedHealthMultiplier,'bounded breed HP');}
for(const label of ['150%','200%','300%','375%','500%']){
 const hp=cfg.baseHealth*factor(label);
 check(hp>=70&&hp<=80.5,'compressed tier health');
 check(Math.ceil(hp/70)<=2,'at most two 70 damage body hits');
 check(Math.ceil(hp/49)<=2,'at most two 49 damage body hits');
}
// Verify actual resource values, not only the generator configuration.
const human=s.parse(read('properties/human.ext'));
const vitality=human.children.find(n=>s.name(n)==='extender'&&n.tokens[1].value==='vitality');
check(Number(s.child(s.child(vitality,'Health'),'max').tokens[1].value)===70,'base HP emitted');
for(const n of s.all(s.parse(read('set/ability/veterancy.set')),n=>s.name(n)==='health'))check(Number(n.tokens[1].value)===0,'veterancy health bonus removed');
const supply=s.parse(read('properties/resupply.inc'));
for(const [name,radius] of Object.entries(cfg.supplyRadius)){
 const def=supply.children.find(n=>s.name(n)==='define'&&n.tokens[1].value===name);
 check(Number(s.child(s.child(def,'extender'),'radius').tokens[1].value)===radius,'supply radius '+name);
}
const build=JSON.parse(fs.readFileSync(path.join(__dirname,'../docs/realism/tactical/build.json')));
const source=rel=>fs.readFileSync(path.join(build.source,rel),'utf8');
const sourceHuman=s.parse(source('properties/human.ext'));
const oldVitality=sourceHuman.children.find(n=>s.name(n)==='extender'&&n.tokens[1].value==='vitality');
const shape=n=>({kind:n.kind,tokens:n.tokens.map(t=>t.value),children:n.children.map(shape)});
for(const key of ['Stamina','Damage','DamageBlast','DamageTPC']){
 assert.deepEqual(shape(s.child(vitality,key)),shape(s.child(oldVitality,key)),key+' preserved');checks++;
}
const chassis=human.children.find(n=>s.name(n)==='Chassis');
const oldChassis=sourceHuman.children.find(n=>s.name(n)==='Chassis');
for(const [posture,modes] of Object.entries(cfg.rotationDegreesPerSecond))for(const [mode,value] of Object.entries(modes)){
 const current=s.child(s.child(chassis,posture),mode),original=s.child(s.child(oldChassis,posture),mode);
 check(Number(current.tokens[3].value)===value,'rotation '+posture+'/'+mode);
 check(current.tokens[1].value===original.tokens[1].value&&current.tokens[2].value===original.tokens[2].value,'translation/animation preserved '+mode);
}
const maskRadius=text=>text.replace(/\{radius\s+[\d.]+\}/g,'{radius VALUE}');
const supplyWithoutBrokenEntry=source('properties/resupply.inc').replace(/\{item "ufb_dyakonov_heat"\s+"ammo" 1\s+\{value 5\}\}/,'; UFB: unsupported Dyakonov HEAT supply entry removed (runtime No Stuff error).');
check(maskRadius(read('properties/resupply.inc'))===maskRadius(supplyWithoutBrokenEntry),'supply preserved except radii and confirmed invalid HEAT entry');
check(!read('properties/resupply.inc').includes('{item "ufb_dyakonov_heat"'),'runtime missing-item request removed');
const ammo=s.parse(read('set/target/ammo.set')),oldAmmo=s.parse(source('set/target/ammo.set'));
const car=s.all(ammo,n=>s.name(n)==='car')[0];
check(car.children.findIndex(n=>s.name(n)==='mgun')<car.children.findIndex(n=>s.name(n)==='ammo rocketlauncher'),'MG before consumable AT against soft vehicles');
for(const targetClass of ['armoredcar','tank_light','tank_medium','tank_heavy']){
 const current=s.all(ammo,n=>s.name(n)===targetClass),old=s.all(oldAmmo,n=>s.name(n)===targetClass);
 assert.deepEqual(current.map(shape),old.map(shape),'Armored target class not broadened: '+targetClass);checks++;
}
let cpCount=0;
for(const rel of build.files.filter(f=>f.includes('/bots_'))){for(const n of s.all(s.parse(read(rel)),n=>s.name(n)==='balancingFactorBonus')){
 const cp=s.child(n,'cp');if(cp){check(Number(cp.tokens[1].value)===1,'bot CP equality '+rel);cpCount++;}
}}
check(cpCount===28,'all discovered CP factors checked');

// Execute the restricted event-language subset used by the new resource.
// This tests event lifecycle, not the engine's AI or navigation.
const events=s.parse(read('set/interaction_entity/ufb_stress.inc')).children;
class Actor {
 constructor(random=0.5){this.tags=new Set();this.timers=new Map();this.time=0;this.random=random;this.dead=false;this.manual=false;}
 event(name){const n=events.find(n=>n.tokens[1]?.value===name);assert(n);this.run(n.children);}
 run(nodes){for(const n of nodes){const t=n.tokens.map(t=>t.value),op=t[0];
  if(op==='tags'){if(t[1]==='add')this.tags.add(t[2]);else this.tags.delete(t[2]);}
  else if(op==='kill_delay')this.timers.delete(t[1]);
  else if(op==='delay'){check(!this.timers.has(t[2]),'no duplicate named timer');this.timers.set(t[2],{at:this.time+Number(t[1]),nodes:n.children});}
  else if(op==='if'){
   let i=1,invert=t[i]==='not';if(invert)i++;
   let condition;
   if(t[i]==='tagged')condition=this.tags.has(t[i+1]);
   else if(t[i]==='dead')condition=this.dead;
   else if(t[i]==='user_control')condition=this.manual;
   else if(t[i]==='rand')condition=this.random<Number(t[i+1]);
   else throw Error('Unsupported condition '+t);
   if(invert)condition=!condition;
   const branch=n.tokens.find(t=>t.value==='else');
   this.run(n.children.filter(c=>condition?(!branch||c.start<branch.start):(branch&&c.start>branch.start)));
  }else throw Error('Unsupported event command '+op);
 }}
 advance(dt){const end=this.time+dt;while(true){const entries=[...this.timers.entries()].filter(([,v])=>v.at<=end).sort((a,b)=>a[1].at-b[1].at);if(!entries.length)break;const [id,v]=entries[0];this.time=v.at;this.timers.delete(id);this.run(v.nodes);}this.time=end;}
}
let a=new Actor();a.event('ufb_stress');a.event('ufb_stress');
check(!a.tags.has('_ufb_overwhelmed'),'same projectile hit+blast not counted twice');
a.advance(0.6);a.event('ufb_stress');check(a.tags.has('_ufb_overwhelmed'),'repeated threat accumulates');
a.event('ufb_cover_committed');
check(a.tags.has('_ufb_cover_active')&&!a.tags.has('_ufb_stress_pending'),'cover consumes its mark');
a.advance(1);a.event('ufb_cover_committed');
a.advance(4.1);check(!a.tags.has('_ufb_cover_active'),'duplicate delivery cannot extend cover protection');
check(!a.tags.has('_ufb_cover_active')&&a.tags.has('_ufb_cover_cooldown'),'short order protection then normal orders');
a.advance(9);check(!a.tags.has('_ufb_cover_cooldown'),'overwhelmed cooldown expires');
a.advance(90);check(a.tags.size===0&&a.timers.size===0,'complete quiet recovery');
a=new Actor();a.event('ufb_stress');a.advance(1.5);a.event('ufb_stress');a.advance(0.6);
check(a.tags.has('_ufb_stress_pending'),'old expiry cannot erase newer event');a.advance(1.5);check(!a.tags.has('_ufb_stress_pending'),'unconsumed mark expires');
a=new Actor(0);a.event('ufb_stress');check(a.tags.has('_ufb_heroic')&&!a.tags.has('_ufb_stress_pending'),'rare composure');
a.advance(7);a.event('ufb_stress');check(!a.tags.has('_ufb_heroic')&&a.tags.has('_ufb_stress_pending'),'no repeated composure lottery during cooldown');
a=new Actor();a.manual=true;a.event('ufb_stress');check(!a.tags.has('_ufb_stress_pending'),'direct control protected');
a=new Actor();a.dead=true;a.event('ufb_stress');check(!a.tags.has('_ufb_stress_pending'),'dead actor ignored');
const profiles=require('./survival-profiles.json');
for(const [name,p] of Object.entries(profiles.profiles)){
 a=new Actor();a.tags.add('_ufb_profile_'+name);a.event('ufb_stress');
 check(a.timers.get('ufb_shaken_expiry').at===p.shakenSeconds,'profile recovery '+name);
 a.advance(0.6);a.event('ufb_stress');check(a.tags.has('_ufb_overwhelmed'),'every profile has a stress limit '+name);
 check(a.timers.get('ufb_overwhelmed_expiry').at===a.time+p.overwhelmedSeconds,'overwhelm recovery '+name);
 a.event('ufb_cover_committed');check(a.timers.get('ufb_cover_active_expiry').at===a.time+p.overwhelmedCoverSeconds,'profile intense-fire cover protection '+name);
 a.advance(100);check(a.tags.size===1&&a.tags.has('_ufb_profile_'+name),'quiet recovery retains only permanent profile '+name);
 a=new Actor(p.composureChance/2);a.tags.add('_ufb_profile_'+name);a.event('ufb_stress');check(a.tags.has('_ufb_heroic'),'profile composure roll '+name);
 a=new Actor(Math.min(1,p.composureChance*2));a.tags.add('_ufb_profile_'+name);a.event('ufb_stress');check(!a.tags.has('_ufb_heroic'),'profile composure bounded '+name);
 a=new Actor();a.tags.add('_ufb_profile_'+name);a.event('ufb_stress');a.advance(profiles.intenseFireWindowSeconds+0.1);
 check(a.tags.has('_ufb_shaken')&&!a.tags.has('_ufb_recent_fire'),'long stress outlasts immediate fire '+name);
 a.event('ufb_stress');check(!a.tags.has('_ufb_overwhelmed'),'separated impacts are not intense fire '+name);
 a.event('ufb_cover_committed');check(a.timers.get('ufb_cover_active_expiry').at===a.time+p.coverProtectionSeconds,'ordinary cover duration '+name);
 a.advance(100);check(a.tags.size===1&&a.timers.size===0,'new fire timer fully recovers '+name);
}
const breedReport=JSON.parse(fs.readFileSync(path.join(__dirname,'../docs/realism/tactical/breed-profiles.json')));
const crypto=require('crypto');
for(const e of breedReport.entries){
 check(crypto.createHash('sha256').update(fs.readFileSync(path.join(root,e.file))).digest('hex')===e.generatedSHA256,'generated breed intact '+e.file);
}
check(breedReport.entries.length===10088,'entire discovered breed set covered');
const humanEvents=read('set/interaction_entity/human.inc');
const impact=s.all(s.parse(humanEvents),n=>s.name(n)==='define'&&n.tokens[1]?.value==='contact_part')[0];assert(impact);
function impactDamage(n,easy,user){
 if(s.name(n)==='human_health')return n.children[0].tokens[0].value==='%ud'?20:60;
 let nodes=n.children;
 if(s.name(n)==='if'&&['difficulty','user_control'].includes(n.tokens[1]?.value)){
  const yes=n.tokens[1].value==='difficulty'?easy:user,branch=n.tokens.find(t=>t.value==='else');
  nodes=nodes.filter(c=>yes?(!branch||c.start<branch.start):(branch&&c.start>branch.start));
 }
 return nodes.reduce((total,c)=>total+impactDamage(c,easy,user),0);
}
check(impactDamage(impact,true,true)===20,'easy player rubble hit applies reduced damage once');
check(impactDamage(impact,true,false)===60,'easy AI rubble hit once');
check(impactDamage(impact,false,true)===60,'normal rubble hit once');
check((humanEvents.slice(impact.start,impact.end).match(/%x/g)||[]).length===1,'one knockdown invocation per impact');
const cover=s.parse(read('map/multi/ufb_survival.inc'));
check(s.all(cover,n=>s.name(n)==='actor_state').length===0,'no permanent actor state override');
const excludes=s.all(cover,n=>s.name(n)==='exclude').flatMap(n=>s.all(n,n=>s.name(n)==='tag')).flatMap(n=>n.tokens.slice(1).map(t=>t.value));
for(const tag of ['_user','player','crew','medic','repairing','_lua_mi','_ai_at_grenade','_ufb_heroic','_ufb_cover_cooldown'])check(excludes.includes(tag),'protected '+tag);

const {lua,lauxlib,lualib,to_luastring,to_jsstring}=require('fengari');
const state=lauxlib.luaL_newstate();lualib.luaL_openlibs(state);
const code=`local alive, subscriptions = {}, {}
BotApi={Scene={IsSquadExists=function(_,s) return alive[s] ~= false end},Events={GameEnd=1,Subscribe=function(_,_,fn) subscriptions[#subscriptions+1]=fn end}}
local B=(function() ${read('script/multiplayer/ufb_objective_balance.lua')} end)()
local flags={{name='a',owner='enemy',priority=1},{name='b',owner='enemy',priority=1},{name='c',owner='us',priority=1},{name='neutral',owner='none',priority=1000}}
local counts={a=0,b=0}
for i=1,20 do local f=B.Choose(i,flags,flags[1],'us');B.Commit(i,f);counts[f.name]=counts[f.name]+1 end
assert(counts.a==12 and counts.b==8,'two axes with bounded preferred bias')
local f=B.Choose(1,flags,flags[2],'us');assert(f.name=='a','stable objective')
flags[1].owner='us';f=B.Choose(1,flags,flags[2],'us');assert(f.name=='b','captured objective releases reservation')
for i=1,20 do alive[i]=false end
flags[1].owner='enemy';f=B.Choose(99,flags,flags[1],'us');assert(f.name=='a','dead squads do not reserve lanes')
assert(B.Choose(99,{},nil,'us')==nil,'no flags safe')
assert(B.Choose(99,flags,flags[3],'us')==flags[3],'native defense retained')
B.Enabled=false;assert(B.Choose(99,flags,flags[1],'us')==flags[1],'disable supported')
for _,fn in ipairs(subscriptions) do fn() end
return true`;
const status=lauxlib.luaL_dostring(state,to_luastring(code));assert(status===lua.LUA_OK,to_jsstring(lua.lua_tostring(state,-1)||to_luastring('Lua failed')));lua.lua_close(state);
const guardState=lauxlib.luaL_newstate();lualib.luaL_openlibs(guardState);
const guardCode=`
local nextID, timers, queued, subs, orders, alive, tagged = 0, {}, {}, {}, 0, true, true
BotApi={Scene={Waypoints={'entry'},IsSquadExists=function() return alive end,
 IsSquadTagged=function(_,_,tag) return tagged and tag=='_ufb_cover_active' end},
 Events={GameEnd=1,GameStart=2,Subscribe=function(_,event,fn) subs[event]=fn end,
 SetQuantTimer=function(_,fn) nextID=nextID+1;timers[nextID]=fn;queued[nextID]=fn;return nextID end,
 KillQuantTimer=function(_,id) assert(type(id)=='number','native API needs numeric timer ID');timers[id]=nil end}}
local G=(function() ${read('script/multiplayer/ufb_order_guard.lua')} end)()
local function fire(id) local fn=timers[id];assert(fn);timers[id]=nil;fn() end
local count=function() local n=0;for _ in pairs(timers)do n=n+1 end;return n end
local waypoint=G.Wrap(function() orders=orders+1 end,true)
local capture=G.Wrap(function() orders=orders+1 end,false)
capture(1);assert(orders==0 and count()==0,'capture protected without new retry chain')
waypoint(1);local old=nextID;assert(orders==0 and count()==1,'cover defers waypoint')
waypoint(1);local replacement=nextID;queued[old]();assert(count()==1 and nextID==replacement,'stale callback cannot erase or replace current owner')
tagged=false;fire(replacement);assert(orders==1 and count()==0,'route resumes once after cover')
waypoint(1);assert(orders==2,'normal route allowed')
tagged=true;waypoint(1);alive=false;fire(nextID);assert(count()==0 and orders==2,'dead squad retires')
alive=true;BotApi.Scene.Waypoints={};waypoint(1);assert(count()==0,'no retry without route')
BotApi.Scene.Waypoints={'entry'};waypoint(1);local ending=nextID;G.Stop();queued[ending]();waypoint(1)
assert(count()==0 and orders==2,'game end cannot rearm a queued retry')
assert(next(subs)==nil,'guard leaves GameStart/GameEnd to the game mode')
return true`;
const guardStatus=lauxlib.luaL_dostring(guardState,to_luastring(guardCode));
assert(guardStatus===lua.LUA_OK,to_jsstring(lua.lua_tostring(guardState,-1)||to_luastring('Guard failed')));lua.lua_close(guardState);
const integrationState=lauxlib.luaL_newstate();lualib.luaL_openlibs(integrationState);
const integration=`
local commands, guardTag, failed, chosen = {}, nil, false, 'a'
BotApi={Scene={Flags={{name='a',occupant='enemy'},{name='b',occupant='enemy'}},Waypoints={},
 IsSquadExists=function()return true end,IsSquadTagged=function(_,_,tag)return tag==guardTag end},
 Events={GameEnd=1,GameStart=2,Subscribe=function()end},
 Commands={CaptureFlag=function(_,id,name)commands[#commands+1]={id,name};if failed then return false end end,
 SeekAndDestroy=function()error('unexpected seek')end}}
package.preload['/script/multiplayer/ufb_order_guard']=function() ${read('script/multiplayer/ufb_order_guard.lua')} end
package.preload['/script/multiplayer/ufb_objective_balance']=function() ${read('script/multiplayer/ufb_objective_balance.lua')} end
team='us';printDebug=false
ConquestState={garrisonSquads={},botDefender=false}
local ending=false
ConquestBattleResult={IsWinnerDecided=function()return ending end,IsBotRetreatRequested=function()return false end}
getDefaultFlagPriority=function()return 1 end
GetFlagToCapture=function(_,_,flags)for _,flag in pairs(flags)do if flag.name==chosen then return flag end end end
${read('script/multiplayer/modes/conquest/orders.lua')}
CaptureFlag(1);CaptureFlag(2);assert(commands[1][2]=='a' and commands[2][2]=='a','Conquest keeps the native shared wave objective')
chosen='b';CaptureFlag(1);assert(commands[3][2]=='b','new native wave objective replaces the previous target')
for _,tag in ipairs({'_ufb_cover_active','_ai_at_grenade','_ufb_smoke_60m_actor','bot_medic','_lua_ignore'})do
 guardTag=tag;CaptureFlag(1);assert(#commands==3,'protected task interrupted: '..tag)
end
guardTag=nil;ConquestState.garrisonSquads[3]=true;CaptureFlag(3);assert(#commands==3,'garrison retained')
ending=true;CaptureFlag(4);assert(#commands==3,'battle end stops orders');ending=false
ConquestState.botDefender=true;chosen='b';CaptureFlag(4);assert(commands[4][2]=='b','defender counterattack keeps explicit objective')
ConquestState.botDefender=false;chosen='a';failed=true;assert(CaptureFlag(5)==false,'native failure propagated')
return true`;
const integrationStatus=lauxlib.luaL_dostring(integrationState,to_luastring(integration));
assert(integrationStatus===lua.LUA_OK,to_jsstring(lua.lua_tostring(integrationState,-1)||to_luastring('Integration failed')));lua.lua_close(integrationState);
console.log(`Tactical: ${checks} assertions; Lua objective and order-guard scenarios passed. SDL event model and mocked BotApi; no engine/battle validation.`);
