// Narrow edits to the installed HF mission logic, preserving earlier UFB repairs.
const fs=require('fs'),p=require('path'),assert=require('assert/strict'),s=require('./lib/sdl.cjs');
const guards=['_ufb_job_reserved','_ufb_combat_busy','_ufb_healing_active'];
const shape=n=>({kind:n.kind,tokens:n.tokens.map(t=>t.value),children:n.children.map(shape)});
function repair(text){
 const tree=s.parse(text),edits=[];
 const top=name=>tree.children.find(n=>s.name(n)===name||s.name(n)==='define'&&n.tokens[1]?.value===name);
 const wire=top('hf inf ai/grenade smoke wirecutter');assert(wire);
 const enemy=s.child(s.child(s.child(s.child(wire,'condition'),'terms'),'1.see_actors'),'enemy');
 for(const n of s.all(s.child(s.child(enemy,'group'),'exclude'),n=>s.name(n)==='tag'&&n.children[0]?.tokens[1]?.value==='_ai_wirecutter_in_action'))edits.push({start:n.start,end:n.end,text:''});
 const tank=top('ai_alert_range_antitank');assert(tank);
 for(const a of s.all(s.child(tank.children[0],'actions'),n=>s.name(n)==='action'&&s.child(n,'action')?.tokens[1]?.value==='rotate'||s.name(n)==='actor_state'&&s.child(n,'move_mode')?.tokens[1]?.value==='hold')){
  const sel=s.child(a,'selector');assert(sel);
  for(const n of s.all(sel,n=>s.name(n)==='tag'&&n.children[0]?.tokens[1]?.value==='_ai_tank_alert_cooldown'))edits.push({start:n.start,end:n.end,text:''});
 }
 const mg=top('hf inf ai/under mg fire');assert(mg);
 const mgEnemy=s.child(s.child(s.child(s.child(mg,'condition'),'terms'),'1.see_actors'),'enemy');
 const mgInclude=s.child(s.child(mgEnemy,'group'),'include');
 for(const n of s.all(mgInclude,n=>s.name(n)==='prop'&&n.children[0]?.tokens[1]?.value==='shooting'))edits.push({start:n.start,end:n.end,text:'{tag {tag _ufb_firing}}'});
 if(!s.all(mgInclude,n=>s.name(n)==='tag'&&n.children[0]?.tokens[1]?.value==='_ufb_firing').length&&!s.all(mgInclude,n=>s.name(n)==='prop'&&n.children[0]?.tokens[1]?.value==='shooting').length)edits.push({start:mgInclude.end-1,end:mgInclude.end-1,text:'\n {tag {tag _ufb_firing}}\n'});
 const rocket=top('hf_rocketlauncher');assert(rocket);
 const max=s.all(rocket,n=>s.name(n)==='max'&&n.tokens[1]?.value==='%r2');assert(max.length<=1);
 for(const n of max)edits.push({start:n.tokens[1].start,end:n.tokens[1].end,text:'%meters'});
 // Every advanced source selector for acquisition and actual actor commands
 // observes the same UFB reservation. Enemy/target selectors are not rewritten.
 function visit(n,parents=[]){for(const c of n.children){
  if(s.name(c)==='selector'&&s.child(c,'group')){
   const group=s.child(c,'group');let exclude=s.child(group,'exclude');
   const protectedOwner=parents.some(a=>/^hf inf ai\/medics\//.test(s.name(a)||''));
   const tags=protectedOwner?guards.filter(x=>x!=='_ufb_healing_active'):[...guards,'medic'];
   const missing=tags.filter(tag=>!s.all(exclude||{children:[]},n=>s.name(n)==='tag'&&n.children[0]?.tokens[1]?.value===tag).length);
   if(missing.length){const body=missing.map(tag=>`{tag {tag ${tag}}}`).join('\n');if(exclude)edits.push({start:exclude.end-1,end:exclude.end-1,text:'\n'+body+'\n'});else edits.push({start:group.end-1,end:group.end-1,text:'\n{exclude '+body+'}\n'});}
  }
  visit(c,[...parents,c]);
 }}visit(tree);
 for(const e of edits.sort((a,b)=>b.start-a.start||b.end-a.end))text=text.slice(0,e.start)+e.text+text.slice(e.end);
 s.parse(text);return rangeGates(text);
}
function rangeGates(text){
 const tree=s.parse(text),rocket=tree.children.find(n=>s.name(n)==='define'&&n.tokens[1]?.value==='hf_rocketlauncher');
 if(text.slice(rocket.start,rocket.end).includes('; UFB: recheck native AT range'))return text;
 const edits=[];
 for(const n of s.all(rocket,n=>s.name(n)==='inventory'||s.name(n)==='action'&&s.child(n,'action')?.tokens[1]?.value==='attack')){
  const actor=`{source advanced} {ignore_captured_by_user 1} {group {select {tag {tag _ai_at_launcher_%meters}}} {include {prop {prop human}} {state {state operatable}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {state {state user_control}} ${guards.map(t=>`{tag {tag ${t}}}`).join(' ')} {tag {tag medic}}}}`;
  const target='{source advanced} {ignore_captured_by_user 0} {group {select {tag {tag _ai_at_launcher_target_%meters}}} {include {state {state operatable}}} {exclude {state {state dead}} {state {state inactive}}}}';
  const before=text.slice(n.start,n.end);
  edits.push({start:n.start,end:n.end,text:`; UFB: recheck native AT range before drawing or issuing an attack.\n{"if" {condition {type see_actors} {selector ${actor}} {enemy ${target}} {distance {mode in_range} {min 0} {max %meters}} {detection visible}}\n${before}\n}`});
 }
 assert.equal(edits.length,2);for(const e of edits.sort((a,b)=>b.start-a.start))text=text.slice(0,e.start)+e.text+text.slice(e.end);s.parse(text);return text;
}
function humanMovement(text){const tree=s.parse(text),edits=[];{const fire=s.all(tree,n=>s.name(n)==='on'&&n.tokens[1]?.value==='fire'&&n.tokens[2]?.value==='hand_right')[0];assert(fire);if(!s.all(fire,n=>s.name(n)==='call'&&n.tokens[1]?.value==='ufb_firing').length)edits.push({start:fire.tokens[2].end,end:fire.tokens[2].end,text:'\n\t\t{call "ufb_firing"}'});}{const blast=s.all(tree,n=>s.name(n)==='on'&&n.tokens[1]?.value==='blast_hit')[0];assert(blast);const alive=blast.children.find(n=>s.name(n)==='if');assert(alive);if(!s.all(blast,n=>s.name(n)==='call'&&n.tokens[1]?.value==='ufb_near_blast').length)edits.push({start:alive.tokens.at(-1).end,end:alive.tokens.at(-1).end,text:'\n\t\t\t{if min_energy 0.45 {call "ufb_near_blast"}}'});}for(const mode of ['on','off']){const n=s.all(tree,n=>s.name(n)==='on'&&n.tokens[1]?.value==='move'&&n.tokens[2]?.value===mode)[0];assert(n);const call='ufb_autonomy_move_'+mode;if(!s.all(n,n=>s.name(n)==='call'&&n.tokens[1]?.value===call).length)edits.push({start:n.tokens[2].end,end:n.tokens[2].end,text:`\n {call "${call}"}`});}for(const e of edits.sort((a,b)=>b.start-a.start))text=text.slice(0,e.start)+e.text+text.slice(e.end);return text;}
function verify(resource){const f=p.join(resource,'map/multi/HF-dcg_script.inc'),text=fs.readFileSync(f,'latin1');assert.deepEqual(shape(s.parse(repair(text))),shape(s.parse(text)),'HF repairs are missing');const human=fs.readFileSync(p.join(resource,'set/interaction_entity/human.inc'),'latin1');assert.equal(humanMovement(human),human,'Movement hooks missing');return {hfSharedJobProtection:true,tankAlertCooldownFixed:true,wirecutterSmokeFixed:true,mgRequiresShooting:true,launcherDrawWithinNativeRange:true};}
if(require.main===module){const root=p.resolve(__dirname,'../mods/ultimate_frontline_bundle/resource');if(process.argv.includes('--build')){for(const [file,fn]of [['map/multi/HF-dcg_script.inc',repair],['set/interaction_entity/human.inc',humanMovement]]){const f=p.join(root,file);fs.writeFileSync(f,fn(fs.readFileSync(f,'latin1')),'latin1');}}console.log(JSON.stringify(verify(root)));}
module.exports={repair,verify,guards,humanMovement};
