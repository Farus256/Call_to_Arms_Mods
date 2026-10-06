const fs=require('fs'),path=require('path'),assert=require('assert/strict'),crypto=require('crypto');
const s=require('./lib/sdl.cjs'),cfg=require('./blood-pools.json');
const root=path.resolve(__dirname,'../mods/ultimate_frontline_bundle/resource');
const read=f=>fs.readFileSync(path.join(root,f),'utf8');
const name=t=>t===80?'bloodstain':`bloodstain_${t}s`;
let checks=0;const check=(ok,msg)=>{assert(ok,msg);checks++;};
const human=s.parse(read('set/interaction_entity/human.inc'));
check(read('set/interaction_entity/human.inc').includes('(include "ufb_corpse_pool.inc")'),'pool scheduler is loaded');
const helper=s.parse(read('set/interaction_entity/ufb_corpse_pool.inc'));
const macro=helper.children.find(n=>s.name(n)==='define');
check(macro.children[0].tokens.map(t=>t.value).join(' ')==='if not ufb_pool_scheduled','one scheduling guard per corpse');
check(s.all(macro,n=>s.name(n)==='set'&&n.tokens[1].value==='ufb_pool_scheduled'&&n.tokens[2].value==='1').length===1,'guard is set before timer');
for(const key of ['dead','not burned','not under_water'])check(s.all(macro,n=>s.name(n)==='if'&&n.tokens.slice(1).map(t=>t.value).join(' ')===key).length===1,'spawn eligibility: '+key);
const event=n=>helper.children.find(c=>s.name(c)==='on'&&c.tokens[1].value===n);
const wait=n=>Number(s.child(event(n),'ufb_schedule_pool').children[0].tokens[0].value);
// Macro arguments are native wait(25), whose single argument is a token in ().
const delay=s.all(macro,n=>s.name(n)==='delay')[0];
const spread=Number(delay.tokens[2].value);
const onset=wait('ufb_schedule_corpse_pool');
const bleedout=wait('ufb_schedule_bleedout_pool');
check(onset-spread===10&&onset+spread===40,'immediate death: start at 10-40s');
const stop=s.all(human,n=>s.name(n)==='on'&&n.tokens[1]?.value==='stop_personage')[0];
const guard=s.all(stop,n=>s.name(n)==='if'&&n.tokens[1]?.value==='dead')[0];
check(s.all(guard,n=>s.name(n)==='call'&&n.tokens[1]?.value==='ufb_schedule_bleedout_pool').length===1,'revived soldiers never queue a corpse pool');
const checkDelay=s.all(stop,n=>s.name(n)==='delay'&&s.all(n,c=>c===guard).length)[0];
const spent=Number(checkDelay.tokens[1].value);
check(spent+bleedout-spread===10&&spent+bleedout+spread===40,'bleedout: existing death-check second included');
check(!s.all(human,n=>s.name(n)==='spawn'&&n.tokens[1]?.value==='bloodstain').length,'no immediate corpse-pool bypass');
const roll=event('ufb_spawn_corpse_pool');
const branches=s.all(roll,n=>s.name(n)==='if'&&n.tokens[1]?.value==='rand');
check(branches.length===cfg.growthSeconds.length-1,'one random choice, not independent spawns');
let probability=1,probabilities=[];
for(let i=0;i<branches.length;i++){
 const p=Number(branches[i].tokens[2].value);probabilities.push(probability*p);probability*=1-p;
 check(Math.abs(p-1/(cfg.growthSeconds.length-i))<1e-10,'uniform remaining choice: '+i);
}
probabilities.push(probability);
for(let p of probabilities)check(Math.abs(p-1/cfg.growthSeconds.length)<1e-10,'equal selection probability');
check(s.all(roll,n=>s.name(n)==='spawn').map(n=>n.tokens[1].value).join(',')===cfg.growthSeconds.map(name).join(','),'all growth variants reachable, once');
for(const seconds of cfg.growthSeconds){
 const a=s.parse(read('entity/fx/hit/'+name(seconds)+'.def'));
 const views=a.children[0].children;
 check(views.length===2,'growth + persistent final pool');
 const first=s.child(views[0],'sprite'),second=s.child(views[1],'sprite');
 check(Number(s.child(s.child(first,'timer'),'duration').tokens[1].value)===seconds,'exact growth duration '+seconds);
 const linear=s.child(s.child(first,'scale'),'linear');
 check(Number(s.child(linear,'min').tokens[1].value)===cfg.initialScale&&Number(s.child(linear,'max').tokens[1].value)===cfg.finalScale,'bounded linear growth');
 check(Number(s.child(views[1],'delay').tokens[1].value)===seconds,'final view starts when growth ends');
 check(Number(s.child(second,'scale').tokens[1].value)===cfg.finalScale,'no size jump at handoff');
 check(Number(s.child(s.child(second,'timer'),'duration').tokens[1].value)===cfg.persistenceSeconds,'pool survives the growth timer');
 for(const v of views)check(!!s.child(v,'ground')&&!!s.child(v,'dynamic')&&!!s.child(v,'notifyowner'),'terrain projection and FX ownership');
}
for(const f of JSON.parse(fs.readFileSync(path.resolve(__dirname,'../docs/realism/blood-pools.json'))).files)
 check(crypto.createHash('sha256').update(read(f.file)).digest('hex')===f.sha256,'generated file hash');
console.log(`Blood pools: ${checks} checks passed; onset 10-40s, nine uniform growth durations 40-120s, one pool per corpse. Native rendering/handoff requires a new battle.`);
