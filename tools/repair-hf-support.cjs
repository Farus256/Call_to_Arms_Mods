const fs=require('fs'),p=require('path'),assert=require('assert/strict'),s=require('./lib/sdl.cjs');
const repo=p.resolve(__dirname,'..'),rel='map/multi/HF-dcg_script.inc';
const root=p.join(repo,'mods/ultimate_frontline_bundle/resource');
const names=['hf inf ai/medics/medics spawn','hf inf ai/medics/medic passive','hf inf ai/medics/medic active move'];
const shape=n=>({kind:n.kind,tokens:n.tokens.map(t=>t.value),children:n.children.map(shape)});
function repair(text){
 const tree=s.parse(text),edits=[];
 for(const name of names){
  const node=tree.children.find(n=>s.name(n)===name);assert(node,name);
  const calls=s.all(node,n=>s.name(n)==='trigger');assert.equal(calls.length,1,name);
  const token=s.child(calls[0],'name').tokens[1];
  if(token.value!==name)edits.push({start:token.start,end:token.end,text:JSON.stringify(name)});
 }
 const loot=tree.children.find(n=>s.name(n)==='define'&&n.tokens[1]?.value==='hf_looting_body');assert(loot);
 const state=s.all(loot,n=>s.name(n)==='actor_state'&&s.all(n,n=>s.name(n)==='follow_commander'&&n.tokens[1]?.value==='off').length);
 assert(state.length<=1);
 // Do not override stance or squad following for an inventory transfer.
 for(const n of state)edits.push({start:n.start,end:n.end,text:'; UFB: retain the soldier\'s existing stance and squad following.'});
 for(const e of edits.sort((a,b)=>b.start-a.start))text=text.slice(0,e.start)+e.text+text.slice(e.end);
 return text;
}
function verify(resource=root,ref=p.resolve(repo,'../_survival_work/hf-update-20261105/reference/resource')){
 const current=s.parse(fs.readFileSync(p.join(resource,rel),'latin1'));
 const native=s.parse(require('./hf-logic-fixes.cjs').repair(repair(fs.readFileSync(p.join(ref,rel),'latin1'))));
 const targets=[...names,'hf_looting_body','hf_looting_ground'];
 for(const name of targets){
  const find=tree=>tree.children.find(n=>s.name(n)===name||s.name(n)==='define'&&n.tokens[1]?.value===name);
  assert.deepEqual(shape(find(current)),shape(find(native)),'HF support differs beyond the reviewed repairs: '+name);
 }
 return {nativeHFWeaponLootingRetained:true,nativeHFMedicsRetained:true,repairedMedicLoops:3,preservedLootingStance:true};
}
if(require.main===module){
 if(process.argv.includes('--build')){const f=p.join(root,rel);fs.writeFileSync(f,repair(fs.readFileSync(f,'latin1')),'latin1');}
 console.log(JSON.stringify(verify()));
}
module.exports={repair,verify};
