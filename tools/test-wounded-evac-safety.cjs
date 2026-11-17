// Structural/data-flow regression. This does not simulate GEM animation or inventory.
const fs=require('fs'),p=require('path'),a=require('assert/strict'),s=require('./lib/sdl.cjs'),fix=require('./wounded-evac-safety.cjs');
const root=p.resolve(__dirname,'..'),rel='map/multi/HF-dcg_script.inc';
const old=fs.readFileSync(p.resolve(root,'../_survival_work/hf-update-20261117/reference/resource',rel),'latin1');
const next=fix.repair(old),current=fs.readFileSync(p.join(root,'mods/ultimate_frontline_bundle/resource',rel),'latin1');
a.equal(fix.repair(next),next);a.equal(fix.repair(current),current);
const owner=(text,name)=>s.parse(text).children.find(n=>s.name(n)===fix.prefix+name);
const val=(n,key)=>s.child(n,key)?.tokens[1]?.value;
const dispatch=text=>s.child(s.child(owner(text,'wounded carry away'),'actions'),'switch');
const requirements=sel=>s.all(sel,n=>s.name(n)==='tag'&&n.tokens.length===2).map(n=>n.tokens[1].value);
// Tag-only fixtures intentionally share all state/inventory fields. Only task identity differs.
const first=new Set(['_ai_wounded_carrier_linked']);
const second=new Set(['_ai_wounded_carrier_linked','_ai_wounded_carrier_selected']);
for(const sel of s.all(dispatch(old),n=>s.name(n)==='selector'))a(requirements(sel).every(t=>first.has(t)),'Old dispatch includes an already dispatched carrier');
for(const text of [next,current]){
 for(const sel of s.all(dispatch(text),n=>s.name(n)==='selector')){
  // Ignore extra UFB exclusion guards when testing the positive membership predicates.
  const group=s.child(sel,'group'),needed=[...requirements(s.child(group,'select')),...requirements(s.child(group,'include'))];
  a(needed.includes('_ai_wounded_carrier_linked'));a(needed.includes('_ai_wounded_carrier_selected'));
  a(!needed.every(t=>first.has(t)));a(needed.every(t=>second.has(t)));
 }
 const actions=s.child(owner(text,'wounded carry away'),'actions');
 a(actions.children.find(n=>val(n,'tag_remove')==='_ai_wounded_carrier_selected').start>dispatch(text).end,'Retire selection only after dispatch');
 const anim=owner(text,'wounded carrier anim check');
 a.equal(s.all(anim,n=>s.name(n)==='inventory').length,0,'A nearby corpse cannot cause a drop');
 a.equal(s.all(anim,n=>(s.name(n)||'').includes('see_actors')).length,0,'Pose observations are not item identity');
 const inv=owner(text,'wounded carrier inv check'),count=s.all(inv,n=>s.name(n)==='count')[0];
 a.equal(val(count,'op'),'>');a.equal(val(count,'value'),'0','A single empty carrier must be released');
 a(s.all(inv,n=>s.name(n)==='tag_remove'&&n.tokens[1]?.value==='_lua_mi').length,'Release Lua order ownership');
 a(s.all(owner(text,'wounded carrier near tent'),n=>s.name(n)==='inventory'&&val(n,'action')==='drop').length,'Medpoint unloading preserved');
 a(s.all(dispatch(text),n=>s.name(n)==='call'&&val(n,'function')==='carry_wounded_tent_false').length,'No-tent evacuation preserved');
}
// Every other native trigger is byte-identical under this repair.
const changed=new Set(['wounded carry away','wounded carrier inv check','wounded carrier anim check'].map(n=>fix.prefix+n));
const shape=n=>[n.kind,n.tokens.map(t=>t.value),n.children.map(shape)];
a.deepEqual(s.parse(old).children.filter(n=>!changed.has(s.name(n))).map(shape),s.parse(next).children.filter(n=>!changed.has(s.name(n))).map(shape));
console.log(JSON.stringify({repeatDispatchExcluded:true,nearbyCorpseCannotDropPatient:true,singleEmptyCarrierReleased:true,unrelatedNativeTriggersPreserved:true,engineExecutionTested:false}));
