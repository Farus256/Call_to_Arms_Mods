// HF evacuation: dispatch a newly linked carrier once. Animation/proximity
// observations do not identify the human in that carrier's inventory.
const s=require('./lib/sdl.cjs'),assert=require('assert/strict');
const prefix='hf inf ai/wounded evac/';
const raw=(text,n)=>text.slice(n.start,n.end);
const value=(n,key)=>s.child(n,key)?.tokens[1]?.value;
function repair(text){
 const tree=s.parse(text),edits=[];
 const owner=name=>{const n=tree.children.find(n=>s.name(n)===prefix+name);assert(n,name);return n;};
 const carry=owner('wounded carry away'),actions=s.child(carry,'actions');
 const dispatch=s.child(actions,'switch');assert(dispatch);
 const retire=actions.children.find(n=>s.name(n)==='entity_state'&&value(n,'tag_remove')==='_ai_wounded_carrier_selected');assert(retire);
 // Keep the selected tag until both dispatch branches have consumed it.
 if(retire.start<dispatch.start){
  edits.push({...retire,text:''});
  edits.push({start:dispatch.end,end:dispatch.end,text:'\n'+raw(text,retire)});
 }
 const selectors=s.all(dispatch,n=>s.name(n)==='selector');assert.equal(selectors.length,2);
 for(const sel of selectors){
  const include=s.child(s.child(sel,'group'),'include');assert(include);
  if(!s.all(include,n=>s.name(n)==='tag'&&value(n,'tag')==='_ai_wounded_carrier_selected').length)
   edits.push({start:include.end-1,end:include.end-1,text:' {tag {tag _ai_wounded_carrier_selected}} '});
 }
 const inventory=owner('wounded carrier inv check');
 const count=s.all(s.child(inventory,'condition'),n=>s.name(n)==='count');assert.equal(count.length,1);
 assert.equal(value(count[0],'op'),'>');const threshold=s.child(count[0],'value');
 assert(['0','1'].includes(threshold.tokens[1].value));
 if(threshold.tokens[1].value!=='0')edits.push({...threshold,text:'{value 0}'});
 const cleanup=s.all(s.child(inventory,'actions'),n=>s.name(n)==='entity_state'&&value(n,'tag_remove')==='_ai_wounded_carrier_linked');assert.equal(cleanup.length,1);
 if(!s.all(s.child(inventory,'actions'),n=>s.name(n)==='tag_remove'&&n.tokens[1]?.value==='_lua_mi').length){
  const selector=raw(text,s.child(cleanup[0],'selector'));
  edits.push({start:cleanup[0].start,end:cleanup[0].start,text:`{"entity_state" ${selector} {tag_remove _lua_mi} {tag_remove _ai_wounded_carrier_abort}}\n`});
 }
 // Retain the named handler for old saves, but only clean stale abort markers
 // after a carrier is empty. A nearby corpse/late pose tag must never drop a patient.
 const anim=owner('wounded carrier anim check');
 if(s.all(anim,n=>s.name(n)==='inventory').length){
  const release=s.all(anim,n=>s.name(n)==='entity_state'&&value(n,'tag_remove')==='_ai_wounded_carrier_abort');assert.equal(release.length,1);
  const emptySelector=raw(text,s.child(release[0],'selector'));
  const body=`{"${prefix}wounded carrier anim check"
 {condition {terms {"1.entities" ${emptySelector}}}}
 {actions ${raw(text,release[0])}
 {"delay" {time 5}} {"trigger" {name "${prefix}wounded carrier anim check"}}}}`;
  edits.push({...anim,text:body});
 }
 for(const e of edits.sort((a,b)=>b.start-a.start||b.end-a.end))text=text.slice(0,e.start)+e.text+text.slice(e.end);
 s.parse(text);return text;
}
module.exports={repair,prefix};
