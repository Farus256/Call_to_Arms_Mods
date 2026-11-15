// Audit the effective HF + atmosphere + final UFB stack, not just generated output.
const fs=require('fs'),p=require('path'),assert=require('assert/strict'),s=require('./lib/sdl.cjs'),a=require('./atmosphere-addons.cjs');
const e=a.expected(),work=a.work,comp=p.join(a.output,'resource'),repo=p.resolve(__dirname,'..');
const ufb=p.join(repo,'mods/ultimate_frontline_bundle/resource'),reference=p.resolve(repo,'../_survival_work/hf-update-20261107/reference/resource');
const read=f=>fs.readFileSync(f,'latin1');
const base=new Set(JSON.parse(fs.readFileSync(p.join(work,'base-paths.json'),'utf8')));
const assets=JSON.parse(fs.readFileSync(p.join(work,'asset-manifest.json'),'utf8'));
const files=new Set([...base,...e.texts.keys(),...assets.map(f=>f.file)]);
const resolve=rel=>[ufb,comp,...require('./animation-compat.cjs').externalRoots(),reference].map(root=>p.join(root,rel)).find(f=>fs.existsSync(f));
const current=rel=>read(resolve(rel));
let includes=0;
for(const [file,text]of e.texts){assert.equal(read(p.join(comp,file)),text,file);
 for(const n of s.all(s.parse(text),n=>s.name(n)==='include')){
  const target=n.tokens[1]?.value?.replaceAll('\\','/');if(!target||target.includes('%'))continue;
  const path=target.startsWith('/')?target.slice(1):p.posix.normalize(p.posix.dirname(file)+'/'+target);
  assert(resolve(path)||files.has(path.toLowerCase()),'Missing include '+target+' from '+file);includes++;
 }
}
// No late overrides of WAVE's idle selection, HF's human properties or native construction events.
for(const file of a.retiredIdleFiles)for(const root of [comp,ufb])assert(!fs.existsSync(p.join(root,file)),'Idle override remains: '+file);
assert.equal(current('properties/human.ext'),read(p.join(reference,'properties/human.ext')));
const passenger=require('./atmosphere-passenger-idle.cjs');
for(const file of ['properties/animation/human/_reg_vehicle_crew.inc','set/interaction_entity/construction/placement.inc']){
 const tree=s.parse(current(file)),last=tree.children.pop();
 assert.equal(last.tokens[1].value,file.startsWith('properties/')?passenger.sequence:'../ufb_passenger_idle.inc');
 const shape=n=>[n.kind,n.tokens.map(t=>t.value),n.children.map(shape)];
 assert.deepEqual(shape(tree),shape(s.parse(read(p.join(reference,file)))),file+' native content changed');
}
for(const [file,text]of e.texts)assert(!/ufb_idle_|ufb_select_idle_crouch|zona_/.test(text),'Foot Idle hook remains: '+file);
for(const list of [e.assets,assets])assert.deepEqual(list.filter(f=>Number(f.id??f.source)===3350281452||f.file.startsWith('properties/animation/human_addon/')).map(f=>f.file),[passenger.asset]);
const head=e.assets.find(f=>f.file===passenger.asset);assert(head?.loose);
const data=fs.readFileSync(head.loose),bmap=data.indexOf(Buffer.from('BMAP'));assert(bmap>=0);assert.equal(data.readUInt32LE(bmap+4),1);
assert.equal(data.subarray(bmap+12,bmap+12+data.readUInt32LE(bmap+8)).toString(),'head');
require('./animation-compat.cjs').verify(ufb,reference);
const events=current('set/talk/voicelines_human.inc');assert.equal(events,read(p.join(ufb,'set/talk/voicelines_human.inc')));
// Expand the new voice macros to find typoed paths and unsupported voice families.
const defs=new Map();
function load(text,file){for(const n of s.parse(text).children){
 const process=n=>{if(s.name(n)==='include'){const rel=p.posix.normalize(p.posix.dirname(file)+'/'+n.tokens[1].value);load(current(rel),rel);}
 else if(s.name(n)==='define')defs.set(n.tokens[1].value,n);
 else n.children.forEach(process);};process(n);
}}
load(current('set/talk.set'),'set/talk.set');
function expand(name,args,depth=0){assert(depth<8,name);const def=defs.get(name);assert(def,'Missing voice macro '+name);
 const sub=t=>t.replace(/%(\d+)/g,(_,n)=>{assert(args[Number(n)]!==undefined,name+' arg '+n);return args[Number(n)];});
 const result=[];
 for(const n of def.children){if(n.kind==='('){if(n.tokens.length>1)assert.equal(n.tokens[1].value,'args');result.push(...expand(sub(n.tokens[0].value),n.tokens.slice(2).map(t=>sub(t.value)),depth+1));}
 else if(s.name(n)==='phrase')result.push(Object.fromEntries(n.children.filter(n=>['language','voice','sound'].includes(s.name(n))).map(n=>[s.name(n),sub(n.tokens[1].value)])));}
 return result;
}
const folders=new Set();for(const f of files){if(f.startsWith('sound/talk/')){const stem=f.replace(/\.wav$/,'').replace(/\.set$/,'');folders.add(stem);let dir=p.posix.dirname(stem);while(dir.startsWith('sound/talk/')){folders.add(dir);dir=p.posix.dirname(dir);}}}
const missing=[],families=new Set();let phrases=0;
for(const actor of ['human','tank','cannon']){
 const rel='set/talk/voicelines_'+actor+'.inc',tree=s.parse(current(rel));
 for(const call of s.all(tree,n=>n.kind==='('&&n.tokens[0]?.value===actor+'_phrases')){
  const folder=call.tokens[2]?.value;assert(folder,rel);
  for(const phrase of expand(actor+'_phrases',[folder])){phrases++;families.add(phrase.language);if(!folders.has('sound/'+phrase.sound.toLowerCase()))missing.push({actor,folder,...phrase});}
 }
}
const breedVoices=new Set();for(const [file,text]of e.texts)if(file.startsWith('set/breed/')){const n=s.child(s.parse(text).children[0],'voice');if(n)breedVoices.add(n.tokens[1].value);}
for(const family of breedVoices)assert(families.has(family),'Unregistered breed voice '+family);
fs.writeFileSync(p.join(work,'voice-path-audit.json'),JSON.stringify({phrases,missingCount:missing.length,missing},null,2));
assert.equal(missing.length,0,'Voice paths must resolve');
const report={...a.verify(),resolvedIncludes:includes,expandedVoicePhrases:phrases,voiceFamilies:families.size,missingVoicePaths:missing.length,nativeHFAndWaveAnimationsRetained:true,gemBattleTested:false};
fs.writeFileSync(p.join(work,'verification.json'),JSON.stringify(report,null,2));
console.log(JSON.stringify(report));
