// Preserve the tested HF/BM dismemberment handlers, and verify both death paths
// share the single 5% pool decision. No rendering or ragdoll emulation here.
const fs=require('fs'),p=require('path'),assert=require('assert/strict'),s=require('./lib/sdl.cjs');
const root=p.resolve(process.argv[2]||p.join(__dirname,'../mods/ultimate_frontline_bundle/resource'));
const before=p.resolve(__dirname,'../../_ai_work/combat-review-20261105/source-before/resource');
const read=(base,file)=>fs.readFileSync(p.join(base,file),'latin1');
const shape=n=>({kind:n.kind,tokens:n.tokens.map(t=>t.value),children:n.children.map(shape)});
const human=s.parse(read(root,'set/interaction_entity/human.inc')),old=s.parse(read(before,'set/interaction_entity/human.inc'));
const event=(tree,name)=>s.all(tree,n=>s.name(n)==='on'&&n.tokens[1]?.value===name)[0];
let checks=0;
for(const name of ['explosion','bm_explosion','crush','hit-light','hit-heavy','ground_hit','die_with_blood']){
 const a=event(human,name),b=event(old,name);assert(a&&b,name);assert.deepEqual(shape(a),shape(b),'Dismemberment changed: '+name);checks++;
}
assert.equal(read(root,'set/interaction_entity/dummy.inc'),read(before,'set/interaction_entity/dummy.inc'),'body-part physics/landing changed');checks++;
assert(!s.all(human,n=>s.name(n)==='spawn'&&n.tokens[1]?.value==='bloodstain').length,'unconditional corpse pool remains');checks++;
const stop=event(human,'stop_personage'),calls=s.all(stop,n=>s.name(n)==='call'&&n.tokens[1]?.value==='ufb_schedule_bleedout_pool');assert.equal(calls.length,1);checks++;
const helper=s.parse(read(root,'set/interaction_entity/ufb_corpse_pool.inc'));
const macro=helper.children.find(n=>s.name(n)==='define'),roll=s.all(macro,n=>s.name(n)==='if'&&n.tokens[1]?.value==='rand');assert.equal(roll.length,1);assert.equal(Number(roll[0].tokens[2].value),0.05);checks++;
const guard=macro.children[0];assert.equal(s.name(guard),'if');assert.equal(s.child(guard,'set').tokens[2].value,'1');assert(s.child(guard,'set').end<roll[0].start);checks++;
for(const name of ['start_healing','stop_healing']){const tags=s.all(event(human,name),n=>s.name(n)==='tags'&&n.tokens[2]?.value==='_ufb_healing_active');assert.equal(tags.length,1);assert.equal(tags[0].tokens[1].value,name==='start_healing'?'add':'remove');checks++;}
const poolNodes=s.all(helper,n=>s.name(n)==='spawn'&&/^bloodstain/.test(n.tokens[1]?.value||''));assert.equal(poolNodes.length,9);checks++;
console.log(JSON.stringify({checks,dismembermentHandlersPreserved:7,bodyPartPhysicsPreserved:true,poolChance:0.05,unconditionalBleedoutPoolRemoved:true,renderingTested:false}));
