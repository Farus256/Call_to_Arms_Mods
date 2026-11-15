// A failed native cover search must not reserve an infantryman as if he were moving.
const fs=require('fs'),p=require('path'),assert=require('assert/strict'),s=require('./lib/sdl.cjs');
const prepare='ufb_hf_cover_prepare',committed='ufb_hf_cover_committed',attempt='_ufb_hf_cover_attempt';
const raw=(text,n)=>text.slice(n.start,n.end);
const shape=n=>[n.kind,n.tokens.map(t=>t.value),n.children.map(shape)];
function prepared(tree){
 for(const parent of [tree,...s.all(tree,()=>true)])for(let i=0;i<parent.children.length;i++){
  const command=parent.children[i];if(s.name(command)!=='actor_to_cover')continue;
  const before=parent.children[i-1],after=parent.children[i+1];assert.equal(s.name(before||{}),'effect');assert.equal(s.name(after||{}),'effect');
  assert.equal(s.child(before,'effect')?.tokens[1]?.value,prepare);assert.equal(s.child(after,'effect')?.tokens[1]?.value,committed);
  const selector=s.child(command,'selector');assert.deepEqual(shape(s.child(after,'selector')),shape(selector),'Cover reservation must use the same actor selection');
  const original=structuredClone(selector),include=s.child(s.child(original,'group'),'include');
  assert(include);const guards=include.children.filter(n=>s.name(n)==='tag'&&s.child(n,'tag')?.tokens[1]?.value===attempt);assert.equal(guards.length,1);
  include.children=include.children.filter(n=>n!==guards[0]);
  assert.deepEqual(shape(s.child(before,'selector')),shape(original),'Preparation must keep the original command scope');
 }
}
function repair(text){
 const existing=s.parse(text),commands=s.all(existing,n=>s.name(n)==='actor_to_cover');
 const hasAttempt=n=>s.all(s.child(n,'selector'),n=>s.name(n)==='tag'&&s.child(n,'tag')?.tokens[1]?.value===attempt).length===1;
 const effects=name=>s.all(existing,n=>s.name(n)==='effect'&&s.child(n,'effect')?.tokens[1]?.value===name);
 if(commands.length&&commands.every(hasAttempt)&&effects(prepare).length===commands.length&&effects(committed).length===commands.length){prepared(existing);return text;}
 // Rebuild the six command sites from their selectors. This also upgrades the
 // three old, unconditional reservation effects without duplicating them.
 let tree=s.parse(text),edits=[];
 for(const n of s.all(tree,n=>s.name(n)==='effect'&&[prepare,committed].includes(s.child(n,'effect')?.tokens[1]?.value)))edits.push({start:n.start,end:n.end,text:''});
 for(const e of edits.sort((a,b)=>b.start-a.start))text=text.slice(0,e.start)+e.text+text.slice(e.end);
 tree=s.parse(text);edits=[];
 for(const n of s.all(tree,n=>s.name(n)==='actor_to_cover')){
  const selector=s.child(n,'selector');assert(selector);const include=s.child(s.child(selector,'group'),'include');assert(include,'Cover selector must first pass order-safety');
  const tags=s.all(include,n=>s.name(n)==='tag'&&s.child(n,'tag')?.tokens[1]?.value===attempt);assert(tags.length<=1);
  let original=raw(text,selector);
  if(tags.length){const t=tags[0];original=original.slice(0,t.start-selector.start)+original.slice(t.end-selector.start);}
  // Keep byte-stable whitespace when rebuilding an already prepared selector.
  const ast=s.parse(original).children[0],group=s.child(ast,'group'),inc=s.child(group,'include');
  const insertion=inc.end-1,guarded=original.slice(0,insertion)+`{tag {tag ${attempt}}}`+original.slice(insertion);
  let command=raw(text,n);command=command.slice(0,selector.start-n.start)+guarded+command.slice(selector.end-n.start);
  edits.push({start:n.start,end:n.end,text:`{"effect" ${original} {effect ${prepare}}}\n${command}\n{"effect" ${guarded} {effect ${committed}}}`});
 }
 for(const e of edits.sort((a,b)=>b.start-a.start))text=text.slice(0,e.start)+e.text+text.slice(e.end);
 prepared(s.parse(text));return text;
}
function human(text){
 const tree=s.parse(text),old=s.all(tree,n=>s.name(n)==='on'&&[prepare,committed].includes(n.tokens[1]?.value));
 const events=`{on "${prepare}" sync
 {tags remove "${attempt}"}
 {if not dead {if not linked {if not in_cover
  {if not tagged "_ufb_hf_cover_retry" {if not tagged "_ufb_hf_cover_active" {tags add "${attempt}"}}}
 }}}
}
{on "${committed}" sync
 {tags remove "${attempt}"}
 {kill_delay "ufb_hf_cover_expiry"}
 {kill_delay "ufb_hf_cover_result"}
 {tags add "_ufb_hf_cover_active"}
 {delay 3 "ufb_hf_cover_expiry" {tags remove "_ufb_hf_cover_active"}}
 {delay 0.5 "ufb_hf_cover_result"
  {if not dead {if not linked {if not in_cover {if not tagged "_ufb_autonomy_moving"
   {tags remove "_ufb_hf_cover_active"}
   {tags add "_ufb_hf_cover_retry"}
   {kill_delay "ufb_hf_cover_retry_expiry"}
   {delay 12 "ufb_hf_cover_retry_expiry" {tags remove "_ufb_hf_cover_retry"}}
  }}}}
 }
}\n`;
 const shape=n=>[n.kind,n.tokens.map(t=>t.value),n.children.map(shape)];
 const expected=s.parse(events).children;
 if(tree.children.length===1&&s.name(tree.children[0])==='human'&&old.length===2&&old.every(n=>tree.children[0].children.includes(n))&&JSON.stringify(old.map(shape))===JSON.stringify(expected.map(shape)))return text;
 for(const n of old.sort((a,b)=>b.start-a.start))text=text.slice(0,n.start)+text.slice(n.end);
 const main=s.parse(text).children;assert.equal(main.length,1);assert.equal(s.name(main[0]),'human');
 const end=main[0].end-1;
 return text.slice(0,end)+'\n'+events+text.slice(end);
}
function verify(resource=p.resolve(__dirname,'../mods/ultimate_frontline_bundle/resource')){
 const mission=fs.readFileSync(p.join(resource,'map/multi/HF-dcg_script.inc'),'latin1'),entity=fs.readFileSync(p.join(resource,'set/interaction_entity/human.inc'),'latin1');
 const humanTree=s.parse(entity);assert.equal(humanTree.children.length,1,'Entity events must stay inside the human definition');assert.equal(s.name(humanTree.children[0]),'human');
 const shape=n=>[n.kind,n.tokens.map(t=>t.value),n.children.map(shape)];
 assert.deepEqual(shape(s.parse(repair(mission))),shape(s.parse(mission)),'Cover guards missing');
 assert.deepEqual(shape(s.parse(human(entity))),shape(s.parse(entity)),'Cover result events missing');
 const commands=s.all(s.parse(mission),n=>s.name(n)==='actor_to_cover').length;assert.equal(commands,6);
 return {coverCommandsGuarded:commands,failedCoverReservationReleasedAfterSeconds:0.5,failedCoverRetrySeconds:12};
}
module.exports={repair,human,verify,prepare,committed,attempt};
