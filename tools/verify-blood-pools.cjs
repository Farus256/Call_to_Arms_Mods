const fs=require('fs'),path=require('path'),assert=require('assert/strict'),crypto=require('crypto');
const s=require('./lib/sdl.cjs'),cfg=require('./blood-pools.json');
const root=path.resolve(__dirname,'../mods/ultimate_frontline_bundle/resource');
const read=f=>fs.readFileSync(path.join(root,f),'utf8');
const defaultGrowth=cfg.growthSeconds[Math.floor(cfg.growthSeconds.length/2)];
const name=t=>t===defaultGrowth?'bloodstain':`bloodstain_${t}s`;
let checks=0;const check=(ok,msg)=>{assert(ok,msg);checks++;};
const human=s.parse(read('set/interaction_entity/human.inc'));
check(read('set/interaction_entity/human.inc').includes('(include "ufb_corpse_pool.inc")'),'pool scheduler is loaded');
const helper=s.parse(read('set/interaction_entity/ufb_corpse_pool.inc'));
const macro=helper.children.find(n=>s.name(n)==='define');
check(macro.children[0].tokens.map(t=>t.value).join(' ')==='if not ufb_pool_scheduled','one scheduling guard per corpse');
check(s.all(macro,n=>s.name(n)==='set'&&n.tokens[1].value==='ufb_pool_scheduled'&&n.tokens[2].value==='1').length===1,'guard is set before timer');
const scheduleGuard=macro.children[0];
const once=s.child(scheduleGuard,'set'),chance=s.child(scheduleGuard,'if');
check(scheduleGuard.children.indexOf(once)<scheduleGuard.children.indexOf(chance),'no pool: chance is not rerolled on duplicate death callbacks');
check(cfg.spawnChance===0.05&&chance.tokens[1].value==='rand'&&Number(chance.tokens[2].value)===0.05,'one 5% roll per corpse');
check(s.all(chance,n=>s.name(n)==='delay').length===1,'one timer only after the successful chance roll');
check(cfg.growthSeconds.join(',')==='120,150,180,210,240,270,300,330,360','growth slowed three times for every variant');
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
const die=s.all(human,n=>s.name(n)==='on'&&n.tokens[1]?.value==='die_with_blood')[0];
check(!s.all(die,n=>s.name(n)==='spawn'&&n.tokens[1]?.value==='blood').length,'large native death splash cannot resemble an immediate pool on every corpse');
check(s.all(die,n=>s.name(n)==='spawn'&&n.tokens[1]?.value==='ground_blood_small').length===1,'small death trace preserved');
const trace=s.child(s.child(s.parse(read('entity/fx/hit/ground_blood_small.def')).children[0],'decalview'),'sprite');
const traceScale=s.child(trace,'scale').tokens.slice(1).reduce((sum,t)=>sum+Number(t.value),0);
check(traceScale<=0.1,'death splash remains smaller than the final pool');
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
 check(views.length===1&&s.name(views[0])==='particleview','growth uses a live particle, not a frozen scale-1 decal');
 const generator=s.child(views[0],'generator');
 check(s.child(generator,'totalparticles').tokens[1].value==='1','one ground particle per corpse');
 check(Number(s.child(s.child(generator,'particleinit'),'lifetime').tokens[1].value)===seconds,'exact growth duration '+seconds);
 const stage=s.child(s.child(views[0],'visualizer'),'stage'),first=s.child(stage,'sprite');
 check(s.child(stage,'flags').tokens.slice(1).map(t=>t.value).join(' ')==='ground','ground alignment, no killparticle freezes growth');
 check(s.child(s.child(first,'timer'),'duration').tokens[1].value==='-1','animation follows particle age');
 const linear=s.child(s.child(first,'scale'),'linear');
 check(Number(s.child(linear,'min').tokens[1].value)===cfg.initialScale&&Number(s.child(linear,'max').tokens[1].value)===cfg.finalScale,'bounded linear growth');
 const handoff=s.all(roll,n=>s.name(n)==='delay'&&n.tokens[1]?.value===String(seconds));
 check(handoff.length===1&&s.child(handoff[0],'call').tokens[1].value==='ufb_settle_corpse_pool','settled decal is delayed by entity event, never by a decalview');
 check(!s.all(a,n=>s.name(n)==='decalview'||s.name(n)==='delay').length,'no immediate final decal in a growth FX');
}
const settled=s.parse(read('entity/fx/hit/ufb_corpse_pool_settled.def'));
const final=s.child(settled.children[0],'decalview'),sprite=s.child(final,'sprite');
check(Number(s.child(sprite,'scale').tokens[1].value)===cfg.finalScale&&!s.child(sprite,'scale').children.length,'final decal has a bounded scalar scale');
check(Number(s.child(s.child(sprite,'timer'),'duration').tokens[1].value)===cfg.persistenceSeconds,'finished pool persists');
check(!!s.child(final,'ground')&&!!s.child(final,'dynamic'),'finished pool projects onto terrain');
const settleEvent=event('ufb_settle_corpse_pool');
for(const key of ['dead','not burned','not under_water'])check(s.all(settleEvent,n=>s.name(n)==='if'&&n.tokens.slice(1).map(t=>t.value).join(' ')===key).length===1,'handoff eligibility: '+key);
for(const kind of ['tiny','small','medium','big']){
 const fx=s.parse(read('entity/fx/hit/blood_'+kind+'.def')).children[0];
 const trace=fx.children.find(n=>s.name(n)==='decalview'&&n.tokens[1]?.value==='ufb_hit_ground');
 check(!!trace,'a ground trace remains after '+kind+' blood particles expire');
 check(Number(s.child(s.child(trace,'sprite'),'scale').tokens[1].value)<=0.1,'impact trace is not a large pool');
 check(!!s.child(trace,'ground')&&!!s.child(trace,'dynamic'),'hit trace is projected on ground');
}
const dummy=s.parse(read('set/interaction_entity/dummy.inc'));
check(!s.all(dummy,n=>s.name(n)==='spawn'&&n.tokens[1]?.value==='bloodstain').length,'body parts cannot bypass corpse timing by spawning a pool on landing');
for(const f of JSON.parse(fs.readFileSync(path.resolve(__dirname,'../docs/realism/blood-pools.json'))).files)
 check(crypto.createHash('sha256').update(read(f.file)).digest('hex')===f.sha256,'generated file hash');
console.log(`Blood pools: ${checks} checks passed; onset 10-40s, nine uniform growth durations 120-360s, chance ${cfg.spawnChance*100}%, at most one pool per corpse. Native rendering/handoff requires a new battle.`);
