// Focused source/event contract proof. Does not emulate GEM combat or navigation.
// Usage: node tools/verify-conquest-compatibility.cjs package-dir [resource-dir] [native-script-dir]
const fs=require('fs'),path=require('path'),assert=require('assert/strict'),{createRequire}=require('module');
const s=require('./lib/sdl.cjs');
const pkg=path.resolve(process.argv[2]);
const resource=path.resolve(process.argv[3]||path.join(__dirname,'../mods/ultimate_frontline_bundle/resource'));
const scope=JSON.parse(fs.readFileSync(path.join(pkg,'patch-scope.json'),'utf8'));
const vars=scope.vars,names=scope.names,direct=new Set(['actor_state','actor_fire','actor_to_cover','action','inventory','animation','effect']);
const read=(base,rel)=>fs.readFileSync(path.join(base,rel),'latin1');
const hf=read(resource,'map/multi/HF-dcg_script.inc'),before=read(path.join(pkg,'baseline'),'map/multi/HF-dcg_script.inc');
const tree=s.parse(hf),old=s.parse(before),shape=(n,t)=>({kind:n.kind,tokens:n.tokens.map(x=>t.slice(x.start,x.end)),children:n.children.map(c=>shape(c,t))});
const val=(n,key)=>s.child(n,key)?.tokens[1]?.value;
function guard(n){
 if(s.name(n)!=='switch'||n.children.length!==1||s.name(n.children[0])!=='case')return null;
 const branch=n.children[0],cond=s.child(branch,'condition'),variable=cond&&val(cond,'var');
 if(!vars.includes(variable))return null;
 assert.equal(val(cond,'type'),'cmp_i');assert.equal(val(cond,'op'),'==');assert.equal(val(cond,'value'),'0');
 const body=branch.children.filter(c=>c!==cond);assert.equal(body.length,1,'guard must enclose a single command, without delays');
 return {variable,body};
}
function flatten(n,t){const g=guard(n);if(g)return g.body.flatMap(c=>flatten(c,t));return [{kind:n.kind,tokens:n.tokens.map(x=>t.slice(x.start,x.end)),children:n.children.flatMap(c=>flatten(c,t))}];}
function expression(expr,terms){
 const tokens=expr.match(/\d+|[!&|()]/g)||[];let i=0;
 function atom(){const t=tokens[i++];if(t==='!')return !atom();if(t==='('){const v=or();assert.equal(tokens[i++],')');return v;}assert(t in terms,'missing expression term '+t);return terms[t];}
 function and(){let v=atom();while(tokens[i]==='&'){i++;const r=atom();v=v&&r;}return v;}
 function or(){let v=and();while(tokens[i]==='|'){i++;const r=and();v=v||r;}return v;}
 const v=or();assert.equal(i,tokens.length);return v;
}
function evaluate(cond,state,predicates){const terms=s.child(cond,'terms').children,values={};for(const term of terms){const id=s.name(term).split('.')[0];values[id]=vars.includes(val(term,'var'))?state[val(term,'var')]===0:predicates[id];}return expression(val(cond,'expression')||terms.map(c=>s.name(c).split('.')[0]).join(' & '),values);}
const isTrigger=n=>s.child(n,'condition')&&s.child(n,'actions');
const current=s.all(tree,isTrigger),original=s.all(old,isTrigger);assert.equal(current.length,original.length);
let guarded=0,starts=0,cleanupCount=0;
function walk(n,parents=[]){
 for(const c of n.children){
  const g=guard(c);if(g){walk(g.body[0]===c?c:{children:g.body},[...parents,g.variable]);continue;}
  const pureCleanup=s.name(c)==='entity_state'&&c.children.every(x=>s.name(x)==='selector'||(s.name(x)==='tag_remove'&&x.tokens[1]?.value!=='_lua_mi'));
  if(direct.has(s.name(c))||(s.name(c)==='entity_state'&&!pureCleanup)){
   assert.deepEqual(parents.slice(-vars.length),vars,'late order lacks fresh guards: '+s.name(c));guarded++;
   // Every possible retreat/result combination must block this queued command.
   for(let mask=1;mask<16;mask++)assert(!parents.every(v=>((mask>>vars.indexOf(v))&1)===0));
  }else if(pureCleanup){assert.equal(parents.length,0,'ephemeral tag cleanup must remain available during retreat');cleanupCount++;}
  else if(['switch','case','default','loop','if','actions'].includes(s.name(c)))walk(c,parents);
 }
}
for(let i=0;i<current.length;i++){
 const now=current[i],prev=original[i];assert.equal(s.name(now),s.name(prev));
 if(!names.includes(s.name(now))){assert.deepEqual(shape(now,hf),shape(prev,before),'unrelated HF trigger changed: '+s.name(now));continue;}
 const cond=s.child(now,'condition'),pc=s.child(prev,'condition'),terms=s.child(cond,'terms').children;
 const guardTerms=terms.filter(c=>vars.includes(val(c,'var'))),nativeTerms=terms.filter(c=>!vars.includes(val(c,'var')));
 if(s.name(now)==='hf inf ai/mine clearing/clear mines detag')assert.equal(guardTerms.length,0,'completion cleanup must still start during retreat');
 else{
  assert.deepEqual(guardTerms.map(c=>val(c,'var')),vars);
  for(let mask=0;mask<(1<<nativeTerms.length);mask++){
   const predicates=Object.fromEntries(nativeTerms.map((c,j)=>[s.name(c).split('.')[0],!!(mask&(1<<j))]));
   const normal=Object.fromEntries(vars.map(v=>[v,0]));assert.equal(evaluate(cond,normal,predicates),evaluate(pc,normal,predicates),'normal trigger condition changed');
   for(let stopped=1;stopped<16;stopped++){const state=Object.fromEntries(vars.map((v,j)=>[v,(stopped>>j)&1]));assert.equal(evaluate(cond,state,predicates),false);starts++;}
  }
 }
 walk(s.child(now,'actions'));
 const clean=flatten(now,hf)[0],expected=shape(prev,before);
 const cleanCondition=clean.children.find(c=>c.tokens[0]==='condition');
 // Conditions were separately exercised above; compare original predicates and action bytes.
 cleanCondition.children=cleanCondition.children.filter(c=>c.tokens[0]!=='expression');
 const oldExpression=expected.children.find(c=>c.tokens[0]==='condition').children.find(c=>c.tokens[0]==='expression');
 if(oldExpression)cleanCondition.children.unshift(oldExpression);
 const cleanTerms=cleanCondition.children.find(c=>c.tokens[0]==='terms');
 cleanTerms.children=cleanTerms.children.filter(c=>!c.children.some(x=>x.tokens[0]==='var'&&vars.some(v=>x.tokens[1]==='"'+v+'"')));
 if(s.name(now)==='hf medic ai/heal'){
  const originalExclude=s.child(s.child(s.child(s.child(pc,'terms').children[0],'selector'),'group'),'exclude');
  const faulty=originalExclude.children.find(c=>s.name(c)==='tag'&&s.all(c,x=>s.name(x)==='tag'&&x.tokens[1]?.value==='_ai_medic_work').length);assert(faulty);
  function removeFaulty(n){n.children=n.children.filter(c=>JSON.stringify(c)!==JSON.stringify(shape(faulty,before)));n.children.forEach(removeFaulty);}removeFaulty(expected.children.find(c=>c.tokens[0]==='condition'));
 }
 assert.deepEqual(clean,expected,'ordinary behavior/selectors/delays changed: '+s.name(now));
}
assert.equal(guarded,scope.guardedCommands);
// Human event edits must only remove the busy marker; all other events stay identical.
const human=s.parse(read(resource,'set/interaction_entity/human.inc')),oldHuman=s.parse(read(path.join(pkg,'baseline'),'set/interaction_entity/human.inc'));
const events=t=>s.all(t,n=>s.name(n)==='on');
const nowEvents=events(human),oldEvents=events(oldHuman);assert.equal(nowEvents.length,oldEvents.length);
let releases=0;
function tags(n,actor){for(const c of n.children){if(s.name(c)==='tags'){if(c.tokens[1].value==='add')actor.add(c.tokens[2].value);else actor.delete(c.tokens[2].value);}else if(s.name(c)==='if'){if(actor.has(c.tokens[2]?.value))tags(c,actor);}}}
for(let i=0;i<nowEvents.length;i++){
 const n=nowEvents[i],prev=oldEvents[i],name=n.tokens[1]?.value;
 const plain=n=>({kind:n.kind,tokens:n.tokens.map(t=>t.value),children:n.children.map(plain)});
 const actual=plain(n),expected=plain(prev);
 if(['ai_medic_cooldown','stop_healing'].includes(name)){
  const removes=s.all(n,c=>s.name(c)==='tags'&&c.tokens[1]?.value==='remove'&&c.tokens[2]?.value==='_ai_medic_work');assert.equal(removes.length,1);releases++;
  function strip(n){n.children=n.children.filter(c=>!(c.tokens[0]==='tags'&&c.tokens[2]==='_ai_medic_work'));n.children.forEach(strip);}strip(actual);
  const actor=new Set(['_ai_medic','_ai_medic_work']);
  if(name==='ai_medic_cooldown'){
   tags(n,actor);assert(actor.has('_ai_medic_cooldown')&&actor.has('_ai_medic_work'),'no premature release before pause');
   const delay=s.child(n,'delay');assert.equal(delay.tokens[1].value,'20');tags(delay,actor);assert(!actor.has('_ai_medic_cooldown'));
  }else tags(n,actor);
  assert(!actor.has('_ai_medic_work')&&actor.has('_ai_medic'),'release only work marker');
 }
 assert.deepEqual(actual,expected,'unrelated human behavior changed: '+name);
}
// The medic can find a second patient after recovery, and a failed/distant first
// job cannot permanently exclude it merely by retaining the historical HF marker.
const heal=current.find(n=>s.name(n)==='hf medic ai/heal');
const group=s.child(s.child(s.child(s.child(heal,'condition'),'terms').children[0],'selector'),'group');
function facet(n,actor){const v=n.tokens[1]?.value;if(s.name(n)==='tag')return n.children.length?n.children.some(c=>facet(c,actor)):actor.tags.has(v);if(s.name(n)==='state')return n.children.length?n.children.every(c=>facet(c,actor)):actor.states.has(v);throw Error('unsupported medic selector facet '+s.name(n));}
function eligible(actor){return s.child(group,'select').children.some(c=>facet(c,actor))&&s.child(group,'include').children.every(c=>facet(c,actor))&&!s.child(group,'exclude').children.some(c=>facet(c,actor));}
const medic={tags:new Set(['_ai_medic','_ai_medic_work']),states:new Set(['operatable'])};
assert(eligible(medic),'stale work tag must not permanently block the next patient');
medic.tags.add('_ai_medic_cooldown');assert(!eligible(medic),'existing recovery pause retained');
tags(s.child(nowEvents.find(n=>n.tokens[1]?.value==='ai_medic_cooldown'),'delay'),medic.tags);
assert(eligible(medic)&&!medic.tags.has('_ai_medic_work'),'ready for second patient after pause');
medic.states.add('user_control');assert(!eligible(medic),'manual control protected');medic.states.delete('user_control');
medic.tags.add('repairing');assert(!eligible(medic),'repair task protected');
// Execute the real current Conquest loader/orders using the established BotApi harness.
const tool=path.join(__dirname,'verify-bot-events.cjs'),code=fs.readFileSync(tool,'utf8');
const native=process.argv[4]||path.join(pkg,'../audit-20261009/layers/game/script');
const extra=`
run('native shared wave target and target change', 'campaign_capture_the_flag','ger','conquest', \`
 dispatch('GameStart'); ConquestState.botDefender=false; ConquestState.attackerWaveTargetFlagName='f1'
 BotApi.Scene.Flags={{name='f1',occupant='b'},{name='f2',occupant='b'}}; flagLocationMap=nil
 local commands={}; BotApi.Commands.CaptureFlag=function(_,id,name) commands[#commands+1]={id,name};return true end
 CaptureFlag(1001);CaptureFlag(1002);assert(commands[1][2]=='f1' and commands[2][2]=='f1')
 ConquestState.attackerWaveTargetFlagName='f2';CaptureFlag(1001);assert(commands[3][2]=='f2')
 \`)
run('all active HF tank ranges reserved, cooldown released', 'campaign_capture_the_flag','ger','conquest', \`
 dispatch('GameStart');ConquestState.botDefender=false
 BotApi.Scene.Flags={{name='f1',occupant='b'}};flagLocationMap=nil
 local job=nil;BotApi.Scene.IsSquadTagged=function(_,_,tag) return tag==job or tag=='_ai_tank_alert_cooldown' end
 local orders=0;BotApi.Commands.CaptureFlag=function()orders=orders+1 end
 for range=120,220,10 do job='_ai_tank_range_'..range..'_alert';CaptureFlag(1003);assert(orders==0,job) end
 job='ai_start_finishing_off';CaptureFlag(1003);assert(orders==0)
 job=nil;CaptureFlag(1003);assert(orders==1,'cooldown must not hold orders')
 \`)
`;
// Harness resources resolve from __dirname, so use its real source or a temporary installed view.
let harnessCode=code;
const sourceResource=path.join(__dirname,'../mods/ultimate_frontline_bundle/resource');
if(path.resolve(resource)!==path.resolve(sourceResource))harnessCode=code.replace("path.join(repo, 'mods/ultimate_frontline_bundle/resource/script')",JSON.stringify(path.join(resource,'script')));
assert(harnessCode!==code||path.resolve(resource)===path.resolve(sourceResource),'installed harness resource substitution failed');
new Function('require','__dirname','process','console',harnessCode+'\n'+extra)(createRequire(tool),__dirname,{argv:['node',tool,native]},console);
console.log(JSON.stringify({ok:true,hfTriggers:scope.triggers,guardedCommands:guarded,retreatStartCombinations:starts,cleanupCommands:cleanupCount,medicReleaseEvents:releases,ordinaryBehaviorPreserved:true,gameEngineEmulated:false}));
