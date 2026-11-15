// Prove command guards and timed scans preserve the original action bodies and conditions.
const fs=require('fs'),p=require('path'),assert=require('assert/strict'),s=require('./lib/sdl.cjs'),safety=require('./order-safety.cjs');
const quant=require('./lib/quant-spread.cjs');
const repo=p.resolve(__dirname,'..'),after=p.join(repo,'mods/ultimate_frontline_bundle/resource');
const before=p.resolve(repo,'../_ai_work/warnings-fix-20261107/source-before/ultimate_frontline_bundle/resource');
const reactions=new Set(['hf inf ai/near player','hf inf ai/under mg fire','hf inf ai/ai mgunner','hf inf ai/ai reloads']);
const consumer=n=>s.name(n)==='actor_to_cover'||s.name(n)==='actor_state'&&s.child(n,'drop')||s.name(n)==='effect'&&s.child(n,'effect')?.tokens[1]?.value==='ufb_hf_cover_committed';
let timedTriggers=0;
function normalize(text){
 const tree=s.parse(text);
 function condition(n,parents,gates=[]){
  const terms=s.child(n,'terms');if(!terms)return visit(n,parents,true);
  const expression=s.child(n,'expression')?.tokens[1]?.value||(terms.children.length===1?s.name(terms.children[0]).split('.')[0]:null);
  const literals=expression?.split('&').map(x=>x.trim().match(/^(!?)(\d+)$/));
  if(!literals||literals.some(x=>!x)){assert.equal(gates.length,0,'Unsupported converted expression');return visit(n,parents,true);}
  const byId=new Map(terms.children.map(t=>[s.name(t).split('.')[0],t]));
  const entries=literals.map(([,neg,id])=>{const t=byId.get(id);assert(t);return {type:s.name(t).split('.')[1],neg:!!neg,node:t};});
  entries.push(...gates.map(g=>({type:s.child(g.condition,'type').tokens[1].value,neg:g.negate,node:g.condition})));
  return ['condition','and',entries.filter(e=>!(e.type==='rand'&&!e.neg&&s.child(e.node,'value')?.tokens[1]?.value==='1')).map(e=>[e.type,e.neg,e.node.children.filter(c=>s.name(c)!=='type').map(c=>visit(c,[...parents,n]))]).sort((a,b)=>JSON.stringify(a).localeCompare(JSON.stringify(b)))];
 }
 function visit(n,parents=[],literalCondition=false){
  if(s.name(n)==='effect'&&['ufb_hf_cover_prepare','ufb_hf_cover_committed'].includes(s.child(n,'effect')?.tokens[1]?.value))return null;
  if(s.name(n)==='entity_state'&&s.child(n,'tag_add')?.tokens[1]?.value==='_ufb_k_crew'&&parents.some(p=>s.name(p)==='ufb/class'))return null;
  if(s.name(n)==='select'&&parents.some(p=>s.name(p)==='define'&&p.tokens[1]?.value==='ufb_crew_candidates'))return ['reviewed-crew-identity'];
  if(s.child(n,'condition')&&s.child(n,'actions')&&/^ufb\/(?:gun\/(?:crew|cover|return|rearm|abandon|deploy|release)|surrender\/(?:mark|helped)|morale\/)/.test(s.name(n)))return null;
  if(s.name(n)==='tag'&&n.children[0]?.tokens[1]?.value==='_ufb_gun_job_active'&&parents.some(p=>s.name(p)==='selector'))return null;
  if(s.name(n)==='tag'&&['_ufb_gun_job_active','_ufb_healing_active','_ufb_job_reserved'].includes(n.children[0]?.tokens[1]?.value)&&parents.some(p=>s.name(p)==='define'&&p.tokens[1]?.value==='ufb_bot_crew_candidates'))return null;
  if(s.name(n)==='selector'&&(consumer(parents.at(-1)||{})||parents.some(n=>s.name(n)==='condition')&&parents.some(n=>reactions.has(s.name(n)))))return ['reviewed-selector'];
  const gates=quant.gates(n,text);
  if(gates){
   timedTriggers++;const cond=s.child(n,'condition'),actions=s.child(n,'actions');
   const phase=s.name(actions.children[0])==='delay'?Number(s.child(actions.children[0],'time').tokens[1].value):0;
   const rest=Number(s.child(actions.children.at(-2),'time').tokens[1].value);
   assert.equal(phase+rest,require('./quant-spread-policy.cjs').period(s.name(n)),'Unexpected scan interval: '+s.name(n));
   return [n.kind,n.tokens.map(t=>t.value),n.children.map(c=>c===cond?condition(cond,[...parents,n],gates):c===actions?[c.kind,c.tokens.map(t=>t.value),[...quant.body(n,text),actions.children.at(-1)].map(x=>visit(x,[...parents,n,actions]))]:visit(c,[...parents,n]))];
  }
  if(!literalCondition&&s.name(n)==='condition'&&s.child(n,'terms'))return condition(n,parents);
  return [n.kind,n.tokens.map(t=>t.value),n.children.map(c=>visit(c,[...parents,n])).filter(x=>x!==null)];
 }
 return tree.children.map(n=>visit(n)).filter(x=>x!==null);
}
for(const file of safety.files){
 let a=fs.readFileSync(p.join(before,file),'latin1');const b=fs.readFileSync(p.join(after,file),'latin1');
 if(/ufb_crew_(safety|skirmish)\.inc$/.test(file))a=require('./crew-cover-safety.cjs').mission(a);
 if(file==='map/multi/HF-dcg_script.inc')a=require('./wounded-evac-safety.cjs').repair(a);
 assert.deepEqual(normalize(a),normalize(b),'Changes outside reviewed actor selectors: '+file);
 assert.equal(safety.repair(b),b,'Non-idempotent command guards: '+file);
}
console.log(JSON.stringify({files:safety.files.length,timedTriggerDefinitions:timedTriggers,unmodifiedActionChainsAndInternalDelaysPreserved:true,reviewedGunAndSurrenderAndMoraleChangesExcluded:true,originalEnemySelectorsPreserved:true,scanTimerDelaysCheckedAgainstPolicy:true}));
