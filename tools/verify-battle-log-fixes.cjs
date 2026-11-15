// Regression proof for overlapping placement batches and map-local wreck data.
const fs=require('fs'),p=require('path'),assert=require('assert/strict'),s=require('./lib/sdl.cjs'),g=require('./garrison-safety.cjs');
const resource=p.resolve(__dirname,'../mods/ultimate_frontline_bundle/resource');
let checks=0;const check=(x,m)=>{assert(x,m);checks++;};
const fixture=`
{"dcg2/init" {condition} {actions {"call" {function "init"}}}}
{"dcg2/botdefend/start2flags" {condition} {actions {"call" {function "debug"}}}}
{"dcg2/botdefend/setup" {condition {type entities} {selector {tag todo}}}
 {actions {"call" {function "place"}} {"delay" {time 1.2}} {"trigger" {name "dcg2/botdefend/setup"}}}}
{"dcg2/botdefend/cartank_to_set" {condition {type entities} {selector {tag tank}}}
 {actions {"call" {function "bot_mobiles_stop"} {context {specified} {selector {tag tank}}}}
 {"delay" {time 0.5}} {"trigger" {name "dcg2/botdefend/cartank_to_set"}}}}
`;
const functions=`
{"init" {"delay" {time 0.1}}}
{"debug" {"delay" {time 0.1}}}
{"place" {"entity_state" {selector {tag todo} {amount 1}} {tag_add selected}}
 {"delay" {time 2}}
 {"entity_state" {selector {tag selected}} {tag_add done} {tag_remove todo} {tag_remove selected}}}
{"bot_mobiles_stop" {"switch" {"case" {condition {type rand} {value 1}}
 {"action" {action cancel}} {"delay" {time 0.2}} {"action" {action rotate}}}
 {"default" {"action" {action cancel}} {"delay" {time 0.2}} {"action" {action rotate}}}}}
`;
const fixed=g.repair(fixture,functions);assert.equal(g.repair(fixed,functions),fixed);checks++;
const readySource=fs.readFileSync(p.join(resource,'map/multi/dcg_script.inc'),'latin1');
function readyPredicate(source,vehiclesRunning){
 const n=s.parse(source).children.find(n=>s.name(n)==='dcg2/botdefend/garrison_ready'),c=s.child(n,'condition');
 const values={1:true,2:false,3:false,4:false,5:true,6:vehiclesRunning};
 return Function('return '+s.child(c,'expression').tokens[1].value.replace(/\b\d+\b/g,n=>String(values[n])).replaceAll('&','&&'))();
}
check(readyPredicate(readySource,true),'Reproduce ready flag before the last vehicle worker finishes');
const readyFixed=g.repair(readySource,fs.readFileSync(p.join(resource,'map/multi/ufb_garrison_functions.inc'),'latin1'));
check(!readyPredicate(readyFixed,true),'Vehicle rotation must finish before garrison_ready');check(readyPredicate(readyFixed,false),'Completion remains available after the final vehicle');
const vals=(n,key)=>s.child(n,key)?.tokens[1]?.value;
class Schedule{
 constructor(source){this.owners=new Map(s.parse(source).children.map(n=>[s.name(n),n]));this.functions=new Map(s.parse(functions).children.map(n=>[s.name(n),n]));this.entities=[];this.jobs=[];this.now=0;this.seq=0;this.armed=new Set();this.active=new Map();this.overlaps=0;this.placements=[];this.running=0;this.peak=0;}
 add(id){this.entities.push({id,tags:new Set(['todo'])});this.poll();}
 later(seconds,fn){this.jobs.push({at:this.now+seconds,seq:this.seq++,fn});}
 advance(to){for(let steps=0;;steps++){assert(steps<1000,'Unbounded worker scheduling');this.jobs.sort((a,b)=>a.at-b.at||a.seq-b.seq);const j=this.jobs[0];if(!j||j.at>to)break;this.jobs.shift();this.now=j.at;j.fn();this.poll();}this.now=to;this.poll();}
 select(selector){if(!selector)return[];let a=this.entities.filter(e=>e.tags.has(vals(selector,'tag')));const amount=Number(vals(selector,'amount'));return amount?a.slice(0,amount):a;}
 condition(n){const type=vals(n,'type');if(type==='entities')return this.select(s.child(n,'selector')).length>0;if(type==='rand')return true;throw Error('Unreviewed fixture condition '+type);}
 poll(){for(const name of [...this.armed])if(this.condition(s.child(this.owners.get(name),'condition')))this.start(name);}
 start(name){const node=this.owners.get(name);this.armed.add(name);if(!this.condition(s.child(node,'condition')))return;this.armed.delete(name);const active=this.active.get(name)||0;if(active)this.overlaps++;this.active.set(name,active+1);this.run(s.child(node,'actions').children,()=>this.active.set(name,this.active.get(name)-1));}
 run(nodes,done){let i=0;const next=()=>{
  while(i<nodes.length){const n=nodes[i++],kind=s.name(n);
   if(kind==='delay'){this.later(Number(vals(n,'time')),next);return;}
   if(kind==='call'){this.run(this.functions.get(vals(n,'function')).children,()=>{});continue;}
   if(kind==='trigger'){this.start(vals(n,'name'));continue;}
   if(kind==='while'){
    const body=n.children.filter(c=>s.name(c)!=='condition');const loop=()=>{if(!this.condition(s.child(n,'condition'))){next();return;}this.run(body,loop);};loop();return;
   }
   if(kind==='entity_state'){
    for(const e of this.select(s.child(n,'selector'))){const add=vals(n,'tag_add'),remove=vals(n,'tag_remove');if(add==='selected'){this.placements.push(e.id);this.running++;this.peak=Math.max(this.peak,this.running);}if(add)e.tags.add(add);if(remove)e.tags.delete(remove);if(add==='done'){e.tags.delete('selected');this.running--;}}
    continue;
   }
   throw Error('Unreviewed fixture action '+kind);
  }done();
 };next();}
}
for(const [name,source]of [['original',fixture],['fixed',fixed]]){
 const w=new Schedule(source);w.add('first');w.start('dcg2/botdefend/setup');w.later(1.5,()=>w.add('arrival-during-placement'));w.advance(9);w.add('arrival-after-idle');w.advance(16);
 if(name==='original'){check(w.overlaps>0,'Fixture must reproduce overlapping self-restarts');check(new Set(w.placements).size<w.placements.length,'Fixture must reproduce duplicate placement');}
 else{check(w.overlaps===0,'Only one placement worker');assert.deepEqual(w.placements,['first','arrival-during-placement','arrival-after-idle']);checks++;check(w.peak===1,'Selected actor stays owned until delayed completion');check(w.entities.every(e=>e.tags.has('done')&&!e.tags.has('selected')&&!e.tags.has('todo')),'No stranded tags or lost late arrivals');check(w.armed.has('dcg2/botdefend/setup'),'Worker remains available for future purchases');}
}
const inline=s.all(s.parse(fixed),n=>s.name(n)==='action'&&n.tokens.length===1);assert.equal(inline.length,4);for(const n of inline){assert.equal(vals(s.child(n,'selector'),'tag'),'tank');checks++;}
// Reject scope changes instead of silently applying context to unrelated functions.
assert.throws(()=>g.repair(fixture.replace('{function "bot_mobiles_stop"} {context','{function "place"} {context'),functions),/Unreviewed scoped/);checks++;
const wreck=require('./native-wreck-fixes.cjs'),original=wreck.baseline(),patched=wreck.repair(original),ast=s.parse(original);
const shape=n=>[n.kind,n.tokens.map(t=>t.value),n.children.map(shape)];
for(const n of s.all(ast,n=>s.name(n)==='Entity'&&wreck.wrecks.has(vals(n,'MID')))){n.children=n.children.filter(c=>!(s.name(c)==='Extender'&&c.tokens[1]?.value==='enumerator'));n.tokens[1].value=wreck.wreckName(wreck.wrecks.get(vals(n,'MID')));}
assert.deepEqual(shape(s.parse(patched)),shape(ast),'Only three wreck number blocks and their local definition names may change');checks++;
assert.throws(()=>wreck.repair(original.replace('{MID 10001}','{MID 99999}')),/Unexpected Rasputitsa wreck roster/);checks++;
console.log(JSON.stringify({checks,...g.verify(),...wreck.verify(),...require('./cover-safety.cjs').verify(),gemBattleTested:false}));
