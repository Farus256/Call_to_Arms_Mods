// Focused source/SDL contracts and actual Lua execution with mocked BotApi.
// Usage: node tools/verify-infantry-ai.cjs package-dir [resource-dir] [native-script-dir]
const fs=require('fs'),path=require('path'),assert=require('assert/strict'),{createRequire}=require('module');
const s=require('./lib/sdl.cjs'),luaparse=require('luaparse');
const {unitsPerMetre}=require('./garrison-layout.json');
const pkg=path.resolve(process.argv[2]),resource=path.resolve(process.argv[3]||path.join(__dirname,'../mods/ultimate_frontline_bundle/resource'));
const vanilla=path.resolve(process.argv[4]||path.join(pkg,'../audit-20261009/layers/game/script'));
const scope=JSON.parse(fs.readFileSync(path.join(pkg,'patch-scope.json'),'utf8'));
const read=(root,rel)=>fs.readFileSync(path.join(root,rel),'latin1'),baseline=path.join(pkg,'baseline');
const hfRel='map/multi/HF-dcg_script.inc',hf=read(resource,hfRel),old=read(baseline,hfRel),tree=s.parse(hf),oldTree=s.parse(old);
const triggers=t=>s.all(t,n=>s.child(n,'condition')&&s.child(n,'actions'));
const shape=n=>({kind:n.kind,tokens:n.tokens.map(t=>t.value),children:n.children.map(shape)});
const vars=['attacker_retreat_requested$','defender_retreat_requested$','bot_retreat_active$','winner_decided$'];
const nowTriggers=triggers(tree),beforeTriggers=triggers(oldTree);assert.equal(nowTriggers.length,beforeTriggers.length);
let smokeChecks=0,coverChecks=0;
function findGuard(root,target,parents=[]){for(const n of root.children){if(n===target)return parents.find(p=>s.name(p)==='switch');const found=findGuard(n,target,[...parents,n]);if(found)return found;}return null;}
function checkGuards(root,target,parents=[]){for(const n of root.children){
 const branch=s.name(n)==='case'&&s.child(n,'condition'),v=branch&&s.child(branch,'var')?.tokens[1]?.value;
 const next=v&&vars.includes(v)?[...parents,v]:parents;
 if(n===target){assert.deepEqual(next,vars,'queued HF command must recheck all retreat/result flags');return true;}
 if(checkGuards(n,target,next))return true;
}return false;}
for(let i=0;i<nowTriggers.length;i++){
 const n=nowTriggers[i],b=beforeTriggers[i];assert.equal(s.name(n),s.name(b));
 const edits=[];
 if(scope.smoke.includes(s.name(n))){
  const cmd=s.all(n,c=>s.name(c)==='action'&&s.child(c,'action')?.tokens[1]?.value==='throw_sk_grenade');assert.equal(cmd.length,1);
  const c=cmd[0],actor=s.child(s.child(c,'selector'),'tag').tokens[1].value,target=s.child(s.child(c,'target'),'tag').tokens[1];
  const suffix=s.name(n).slice('hf inf ai/grenade smoke '.length);
  assert.equal(target.value,`_ufb_smoke_${suffix}_screen`,'smoke must use a reachable forward screen, not the distant enemy');
  const points=s.all(n,c=>s.name(c)==='effect'&&s.child(c,'effect')?.tokens[1]?.value===`ufb_smoke_screen_${suffix}`);assert.equal(points.length,1);
  assert.deepEqual(shape(s.child(points[0],'selector')),shape(s.child(c,'selector')),'smoke point must belong to the selected thrower');
  checkGuards(s.child(n,'actions'),points[0]);
  const pointGuard=findGuard(s.child(n,'actions'),points[0]);assert(pointGuard);edits.push({start:pointGuard.start,end:pointGuard.end,value:''});
  const rotation=s.all(n,c=>s.name(c)==='action'&&s.child(c,'action')?.tokens[1]?.value==='rotate')[0];assert(rotation.start<points[0].start&&points[0].start<c.start,'turn toward threat before making and using the screen point');
  const prev=s.all(b,c=>s.name(c)==='action'&&s.child(c,'action')?.tokens[1]?.value==='attack_ground')[0];assert(prev);
  assert.notEqual(s.child(s.child(prev,'target'),'tag').tokens[1].value,actor,'baseline must reproduce unreachable targeting');
  checkGuards(s.child(n,'actions'),c);
  const verb=s.child(c,'action').tokens[1];edits.push({start:verb.start,end:verb.end,value:'attack_ground'});
  edits.push({start:target.start,end:target.end,value:s.child(s.child(prev,'target'),'tag').tokens[1].value});smokeChecks++;
 }
 if(scope.cover.includes(s.name(n))){
  const cmd=s.all(n,c=>s.name(c)==='actor_to_cover');assert.equal(cmd.length,1);
  const effects=s.all(n,c=>s.name(c)==='effect'&&s.child(c,'effect')?.tokens[1]?.value==='ufb_hf_cover_committed');assert.equal(effects.length,1);
  assert.deepEqual(shape(s.child(cmd[0],'selector')),shape(s.child(effects[0],'selector')),'only the HF-selected actors get cover ownership');
  checkGuards(s.child(n,'actions'),cmd[0]);checkGuards(s.child(n,'actions'),effects[0]);
  const guarded=findGuard(s.child(n,'actions'),effects[0]);assert(guarded);edits.push({start:guarded.start,end:guarded.end,value:''});
  const excludes=s.all(s.child(n,'condition'),c=>s.name(c)==='exclude')[0];
  const marker=excludes.children.find(c=>s.name(c)==='tag'&&s.child(c,'tag')?.tokens[1]?.value==='_ufb_hf_cover_active');assert(marker);
  edits.push({start:marker.start,end:marker.end,value:''});coverChecks++;
 }
 let text=hf.slice(n.start,n.end);for(const e of edits.sort((a,b)=>b.start-a.start))text=text.slice(0,e.start-n.start)+e.value+text.slice(e.end-n.start);
 assert.deepEqual(shape(s.parse(text).children[0]),shape(b),'unrelated HF behavior changed: '+s.name(n));
}
assert.equal(smokeChecks,3);assert.equal(coverChecks,3);
// The event owns only a bounded marker; no queued movement commands can restart during retreat.
const humanRel='set/interaction_entity/human.inc',human=s.parse(read(resource,humanRel)),oldHuman=s.parse(read(baseline,humanRel));
const added=s.all(human,n=>s.name(n)==='on'&&n.tokens[1]?.value==='ufb_hf_cover_committed');assert.equal(added.length,1);
const event=added[0],delay=s.child(event,'delay');assert.equal(delay.tokens[1].value,'3');assert.equal(delay.tokens[2].value,'ufb_hf_cover_expiry');
assert.equal(s.child(event,'kill_delay').tokens[1].value,'ufb_hf_cover_expiry');
assert.equal(s.child(event,'tags').tokens[2].value,'_ufb_hf_cover_active');assert.equal(s.child(delay,'tags').tokens[1].value,'remove');
assert.deepEqual(event.children.map(s.name),['kill_delay','tags','delay']);
const smokeDir=path.join(resource,'set/stuff/grenade/smoke grenade');let minSmokeRange=Infinity;
for(const f of fs.readdirSync(smokeDir)){
 const grenade=s.parse(fs.readFileSync(path.join(smokeDir,f),'latin1')),throwNode=s.all(grenade,n=>s.name(n)==='throw')[0];
 const campaign=throwNode.children.find(n=>s.name(n)==='mod'&&n.tokens[1]?.value==='gametype:campaign_capture_the_flag');
 minSmokeRange=Math.min(minSmokeRange,Number(s.child(campaign||throwNode,'range').tokens[1].value));
}
const screenDistances=[];
for(const suffix of ['120m','60m','wirecutter']){
 const events=s.all(human,n=>s.name(n)==='on'&&n.tokens[1]?.value===`ufb_smoke_screen_${suffix}`);assert.equal(events.length,1);
 assert.equal(events[0].tokens[2].value,'sync');assert.deepEqual(events[0].children.map(s.name),['spawn']);
 const spawn=s.child(events[0],'spawn');assert.deepEqual(spawn.tokens.map(t=>t.value),['spawn','ufb_smoke_screen_point','local_offset','200','0','0','constrain_after_dir']);
 const screenDistance=Math.hypot(...spawn.tokens.slice(3,6).map(t=>Number(t.value)))/unitsPerMetre;
 assert.equal(screenDistance,10,'GEM world coordinates must be converted to metres');screenDistances.push(screenDistance);
 assert.equal(s.child(spawn,'tags').tokens[2].value,`_ufb_smoke_${suffix}_screen`);
 const expiry=s.child(spawn,'delay');assert.equal(expiry.tokens[1].value,'4');assert(s.child(expiry,'delete'));
 assert.deepEqual(spawn.children.map(s.name),['tags','delay'],'point creation must not emit smoke or replenish grenades');
}
// Bounds derived from actual grenade resources, independent of threat distance or facing.
for(const screenDistance of screenDistances)for(const distance of [7,33,60,65,120])for(const angle of [0,Math.PI/2,Math.PI,-Math.PI/4]){
 const point=[screenDistance*Math.cos(angle),screenDistance*Math.sin(angle)],enemy=[distance*Math.cos(angle),distance*Math.sin(angle)];
 assert(Math.hypot(...point)<minSmokeRange,'screen exceeds a real grenade range');
 assert(point[0]*enemy[0]+point[1]*enemy[1]>0,'screen must lie ahead rather than under the thrower');
}
const marker=s.parse(read(resource,'entity/service/ufb_smoke_screen_point/ufb_smoke_screen_point.def'));
assert.equal(s.name(marker.children[0]),'game_entity');assert.deepEqual(marker.children[0].children.map(s.name),['Skeleton','constrain','obstacleID']);
assert.equal(s.child(marker.children[0],'constrain').tokens[1].value,'ground');
const addedNames=['ufb_hf_cover_committed','ufb_smoke_screen_120m','ufb_smoke_screen_60m','ufb_smoke_screen_wirecutter'];
const humanShape=shape(human);humanShape.children[0].children=humanShape.children[0].children.filter(n=>!(n.tokens[0]==='on'&&addedNames.includes(n.tokens[1])));
assert.deepEqual(humanShape,shape(oldHuman),'other human events must remain identical');
const survivalRel='map/multi/ufb_survival.inc',survival=s.parse(read(resource,survivalRel)),oldSurvival=s.parse(read(baseline,survivalRel));
const coverTags=['_ai_suppressed_by_mg','_ai_mgunner','_ai_reloading','_ufb_hf_cover_active'];
const ex=s.all(survival,n=>s.name(n)==='exclude')[0];for(const tag of coverTags)assert(ex.children.some(n=>s.child(n,'tag')?.tokens[1]?.value===tag));
ex.children=ex.children.filter(n=>!coverTags.includes(s.child(n,'tag')?.tokens[1]?.value));assert.deepEqual(shape(survival),shape(oldSurvival));
// Pin the new scoring override to the installed updated native implementation: only four existing functions may differ.
const scoringRel='script/multiplayer/modes/conquest/purchase_scoring.lua',scoring=read(resource,scoringRel),native=fs.readFileSync(path.join(pkg,'native-purchase_scoring.lua'),'latin1');
const parse=t=>luaparse.parse(t,{comments:false,luaVersion:'5.2'}),currentAst=parse(scoring),nativeAst=parse(native);
const functionName=n=>n.type==='FunctionDeclaration'&&n.identifier?.type==='Identifier'?n.identifier.name:null;
const allowed=['GetInfantryOrganicSupportFit','GetArmoredInfantrySupportFit','GetLaneFit','BuildFallbackCandidates'];
currentAst.body=currentAst.body.filter(n=>functionName(n)!=='GetHFInfantrySupportFit');
for(const name of allowed){const i=currentAst.body.findIndex(n=>functionName(n)===name),oldFn=nativeAst.body.find(n=>functionName(n)===name);assert(i>=0&&oldFn);assert.notDeepEqual(currentAst.body[i],oldFn);currentAst.body[i]=oldFn;}
assert.deepEqual(currentAst,nativeAst,'native wave purchase algorithm changed outside specialist compatibility');
const tool=path.join(__dirname,'verify-bot-events.cjs');let harness=fs.readFileSync(tool,'utf8');
harness=harness.replace("path.join(repo, 'mods/ultimate_frontline_bundle/resource/script')",JSON.stringify(path.join(resource,'script')));
const baseLua=path.join(pkg,'baseline/script/multiplayer/units').split(path.sep).join('/'),nativeLua=path.join(pkg,'native-purchase_scoring.lua').split(path.sep).join('/');
let extra=`
run('HF cover blocks normal orders and resumes a fresh target','campaign_capture_the_flag','ger','conquest', \`
 dispatch('GameStart');ConquestState.botDefender=false
 BotApi.Scene.Flags={{name='a',occupant='b'}};flagLocationMap=nil
 local job=nil;local alive=true;local stop=false;local commands={};local timers={};local queued={};local nextId=0
 BotApi.Scene.IsSquadTagged=function(_,_,tag)assert(alive,'must not query tags of a removed squad');return job==tag end
 BotApi.Scene.IsSquadExists=function()return alive end
 BotApi.Commands.CaptureFlag=function(_,id,flag)commands[#commands+1]={id,flag} end
 BotApi.Events.SetQuantTimer=function(_,fn)nextId=nextId+1;timers[nextId]=fn;queued[nextId]=fn;return nextId end
 BotApi.Events.KillQuantTimer=function(_,id)timers[id]=nil end
 ShouldStopNormalSquadOrders=function()return stop end
 local function count()local n=0;for _ in pairs(timers)do n=n+1 end;return n end
 local function fire(id)local f=timers[id];assert(f);timers[id]=nil;f()end
 for _,tag in ipairs({'_ai_suppressed_by_mg','_ai_mgunner','_ai_reloading','_ufb_hf_cover_active'})do
  job=tag;local before=#commands;BotApi.Scene.Flags={{name='a',occupant='b'}};flagLocationMap=nil
  CaptureFlag(1001);local oldId=nextId;assert(#commands==before and count()==1,'cover interrupted: '..tag)
  CaptureFlag(1001);local replacement=nextId;queued[oldId]();assert(count()==1 and replacement==nextId,'stale retry replaced current owner')
  fire(replacement);assert(#commands==before and count()==1,'active cover must remain protected')
  job=nil;BotApi.Scene.Flags={{name='b',occupant='b'}};flagLocationMap=nil;fire(nextId)
  assert(#commands==before+1 and commands[#commands][2]=='b' and count()==0,'resume must select current native target')
 end
 job='_ai_reloading';local before=#commands;CaptureFlag(1001);stop=true;fire(nextId)
 assert(#commands==before and count()==0,'retreat must cancel deferred cover resumption');stop=false
 CaptureFlag(1001);alive=false;fire(nextId);assert(count()==0 and #commands==before,'dead squad must retire retry');alive=true
 CaptureFlag(1001);local ending=nextId;dispatch('GameEnd');queued[ending]();assert(count()==0 and #commands==before,'game end must reject queued retry')
 \`)
`;
const coverOnly=process.argv[5]==='cover-only';
for(const army of coverOnly?[]:['ger','rus','fin','usa','eng']){
 const entries={ger:361,rus:336,fin:161,usa:161,eng:234}[army];
 const changed=scope.rosterChanges.filter(x=>x.army===army).map(x=>x.unit);
 extra+=`
run('HF specialists and unchanged native purchases ${army}','campaign_capture_the_flag','${army}','conquest', \`
 dispatch('GameStart')
 local patched=ConquestPurchaseScoring;ConquestPurchaseScoring=nil;dofile('${nativeLua}');local native=ConquestPurchaseScoring;ConquestPurchaseScoring=patched
 local current=Purchases['conquest.${army}'][1].Units
 dofile('${baseLua}/${army}/conquest.${army}.lua');local previous=Purchases['conquest.${army}'][1].Units;Purchases['conquest.${army}'][1].Units=current
 assert(#current==#previous and #current==${entries},'HF roster entries removed or duplicated')
 local lanes={'infantry_body','infantry_organic_support','armored_body','armored_infantry_support','armored_mobile_support',
  'secondary_armored_force','anti_tank_force','artillery_support_force','aa_support_force','probe_mobile','probe_infantry','probe_light_armor'}
 local changed={};for _,name in ipairs({${changed.map(x=>`'${x}'`).join(',')}})do changed[name]=true end
 local byName={};local unchanged={};local services=0;local fighters=0
 for i,unit in ipairs(current)do
  byName[unit.unit]=unit;assert(unit.unit==previous[i].unit,'HF squad identity/order changed')
  assert(unit.availability==previous[i].availability and unit.grade==previous[i].grade,'purchase weights changed')
  local fits=0
  for _,lane in ipairs(lanes)do
   local fit=patched.GetLaneFitForSim(unit,lane);if fit>0 then fits=fits+1 end
   if not changed[unit.unit]then assert(fit==native.GetLaneFitForSim(previous[i],lane),'unrelated lane fit changed: '..unit.unit..'/'..lane) end
  end
  if patched.UnitHasTag(unit,'Service')then services=services+1;assert(fits==0) else fighters=fighters+1;assert(fits>0,'combat specialist has no category: '..unit.unit) end
  if not changed[unit.unit]then
   unchanged[#unchanged+1]=unit
   assert(patched.GetPurchaseForceCost(unit)==native.GetPurchaseForceCost(previous[i]),'force accounting changed')
   for k,v in pairs(previous[i])do
    if type(v)=='table'then assert(table.concat(v,',')==table.concat(unit[k] or {},','),'unrelated roster metadata changed')
    else assert(v==unit[k],'unrelated roster metadata changed')end
   end
  end
 end
 assert(services==1 and fighters==#current-1)
 local medic=byName['single_medic(${army})'];local flame=byName['single_flamer(${army})'];local service=byName['detect_error_vehicle']
 assert(patched.UnitHasTag(medic,'Medic') and not patched.UnitHasTag(medic,'Recon'))
 assert(patched.UnitHasTag(flame,'Flamethrower') and patched.GetPurchaseForceCost(flame)==0.35,'small specialist team must keep native single cost')
 for _,unit in ipairs({medic,flame})do
  for _,lane in ipairs(lanes)do
   assert((patched.GetLaneFitForSim(unit,lane)>0)==(lane=='infantry_organic_support' or lane=='armored_infantry_support'),'specialist assigned outside support: '..lane)
  end
  for _,lane in ipairs({'infantry_organic_support','armored_infantry_support'})do
   ConquestState.purchasePlan={phase='attacker_wave',intent='main_attack',lanes={{name=lane,budget=1,spent=0}}}
   assert(patched.SelectUnitForCurrentPlan({unit})==unit and ConquestState.pendingPurchaseLane==lane,'actual scorer cannot select support specialist')
  end
 end
 ConquestState.purchasePlan={phase='attacker_wave',intent='probe',lanes={{name='probe_infantry',budget=1,spent=0}}}
 assert(patched.SelectUnitForCurrentPlan({medic,flame,service})==nil,'probe fallback must not buy medics, flame teams, or diagnostics')
 ConquestState.purchasePlan=nil;assert(patched.SelectUnitForCurrentPlan({service})==nil,'fallback must not buy diagnostics')
 if '${army}'=='ger'then
  assert(patched.GetPlatformLabel(byName['squad_mot_sappers_ai'])=='InfantrySquad')
  assert(patched.GetLaneFitForSim(byName['sdkfz10_5'],'aa_support_force')>0)
 elseif '${army}'=='rus'then assert(patched.GetLaneFitForSim(byName['single_riflegrenade_early(rus)'],'anti_tank_force')>0)end
 -- The same seeds and unchanged HF units must give the same purchases in every native lane.
 ConquestState.purchasePhase='attacker_wave'
 for _,lane in ipairs(lanes)do for seed=1,4 do
  local function plan()return {phase='attacker_wave',intent='main_attack',lanes={{name=lane,budget=4,spent=0}}}end
  math.randomseed(seed);ConquestState.purchasePlan=plan();ConquestPurchaseScoring=native;local a=native.SelectUnitForCurrentPlan(unchanged)
  local oldLane,oldCost=ConquestState.pendingPurchaseLane,ConquestState.pendingPurchaseForceCost
  math.randomseed(seed);ConquestState.purchasePlan=plan();ConquestPurchaseScoring=patched;local b=patched.SelectUnitForCurrentPlan(unchanged)
  assert(a==b and oldLane==ConquestState.pendingPurchaseLane and oldCost==ConquestState.pendingPurchaseForceCost,'native selection changed outside specialist fix: '..lane)
 end end
 for seed=1,24 do
  math.randomseed(seed);ConquestState.purchasePlan={phase='attacker_wave',intent='probe',lanes={{name='probe_infantry',budget=4,spent=0}}}
  local picked=patched.SelectUnitForCurrentPlan(current);assert(picked and not patched.UnitHasTag(picked,'Medic') and not patched.UnitHasTag(picked,'Flamethrower') and not patched.UnitHasTag(picked,'Service'))
 end
 \`)
`;
}
let scenarios=0;
new Function('require','__dirname','process','console',harness+'\n'+extra)(createRequire(tool),__dirname,{argv:['node',tool,vanilla]},
 {log:(...args)=>{scenarios++;console.log(...args);}});
console.log(JSON.stringify({ok:true,hfSmokeTriggers:smokeChecks,smokeScreenDistanceMetres:10,shortestSmokeThrowRangeMetres:minSmokeRange,hfCoverTriggers:coverChecks,rosterEntries:coverOnly?null:1253,rosterMetadataChanges:scope.rosterChanges.length,combatEntriesWithoutCategory:coverOnly?null:0,serviceEntries:coverOnly?null:5,nativeDifferentialPurchaseCases:coverOnly?0:240,luaScenarios:scenarios,limitations:'SDL contracts and mocked BotApi; no live GEM battle/navigation/throw animation'}));
