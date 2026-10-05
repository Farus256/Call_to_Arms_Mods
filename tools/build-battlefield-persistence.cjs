// Narrow overlays from reviewed, versioned baselines. No shader or global physics changes.
const fs=require('fs'),path=require('path'),assert=require('assert/strict'),crypto=require('crypto');
const s=require('./lib/sdl.cjs'),cfg=require('./battlefield-persistence.json');
const repo=path.resolve(__dirname,'..'),root=path.join(repo,'mods/ultimate_frontline_bundle/resource');
const base=path.join(__dirname,'baselines/battlefield-persistence');
const reportPath=path.join(repo,'docs/realism/battlefield-persistence.json');
const previous=fs.existsSync(reportPath)?JSON.parse(fs.readFileSync(reportPath)).files:[];
const hash=b=>crypto.createHash('sha256').update(b).digest('hex');
const outputs=[];
for(const key of ['metalParticleSeconds','sandbagParticleSeconds','smallMetalLimit','mediumMetalLimit'])assert(Number.isFinite(cfg[key])&&cfg[key]>0,key);
function read(rel){return fs.readFileSync(path.join(base,rel),'utf8');}
function queue(rel,text,source=null){s.parse(text);outputs.push({rel,text,source});}
function replaceSpans(text,changes){for(const [n,value] of changes.sort((a,b)=>b[0].start-a[0].start))text=text.slice(0,n.start)+value+text.slice(n.end);return text;}
for(const [folder,names,match,seconds] of [
 ['detonation',cfg.vehicleEffects,/^#metall[123]$/,cfg.metalParticleSeconds],
 ['hit',cfg.sandbagEffects,/^#sandbag_0[12](_win)?$/,cfg.sandbagParticleSeconds]
])for(const name of names){
 const rel=`entity/fx/${folder}/${name}.def`,original=read(rel),ast=s.parse(original),changes=[];
 for(const gen of s.all(ast,n=>s.name(n)==='entitygenerator')){
  const entities=gen.children.filter(n=>s.name(n)==='entity');
  if(!entities.length||!entities.every(n=>match.test(n.tokens[1]?.value)))continue;
  const life=s.child(s.child(gen,'particleinit'),'lifetime');assert(life);
  changes.push([life,`{lifetime ${seconds}}`]);
  // Attached smoke/fire emitters would otherwise run for the entire debris lifetime.
  for(const entity of entities)for(const fx of entity.children.filter(n=>s.name(n)==='fx'))changes.push([fx,'; UFB: transient smoke/fire remains in the parent explosion.']);
 }
 assert(changes.length,rel+' has no eligible debris');
 queue(rel,cfg.enabled?replaceSpans(original,changes):original,original);
}
// Only sliced small metal bypasses the native 10-second deletion property.
const prop='properties/ufb_metal_part_harmless.inc',originalProp=read('properties/small_part_harmless.inc');
assert(originalProp.includes('"delete_after_spawn"'));
queue(prop,cfg.enabled?originalProp.replace(' "delete_after_spawn"',''):originalProp);
for(const name of ['piece_small_steel','piece_tiny_steel']){
 const rel=`entity/service/slicer/${name}.def`,original=read(rel);
 assert(original.includes('/properties/small_part_harmless.inc'));
 queue(rel,cfg.enabled?original.replace('/properties/small_part_harmless.inc','/properties/ufb_metal_part_harmless.inc'):original,original);
}
const rel='set/entitymanager.set',original=read(rel),ast=s.parse(original),changes=[];
const classes={ufb_small_metal:['piece_small_steel','piece_tiny_steel','piece_small_steel_construction'],ufb_medium_metal:['piece_medium_steel','piece_medium_steel_construction']};
for(const n of s.all(ast,n=>s.name(n)==='entity'))if(Object.values(classes).flat().includes(n.tokens[1]?.value))changes.push([n,'; UFB: moved to bounded metal-fragment group']);
const manager=s.child(ast,'entitymanager');assert(manager);
const groups=Object.entries(classes).map(([name,entities])=>`\n {group "${name}" gameentity\n  {limit ${name==='ufb_small_metal'?cfg.smallMetalLimit:cfg.mediumMetalLimit}}\n  {remove dissolve}\n${entities.map(e=>`  {entity "${e}"}`).join('\n')}\n }\n`).join('');
changes.push([{start:manager.end-1,end:manager.end-1},groups]);
queue(rel,cfg.enabled?replaceSpans(original,changes):original,original);
// Refuse to overwrite a user's subsequent edits, even on a rebuild.
for(const o of outputs){const dest=path.join(root,o.rel);if(fs.existsSync(dest)){
 const current=hash(fs.readFileSync(dest)),prior=previous.find(e=>e.file===o.rel);
 assert([hash(o.text),o.source&&hash(o.source),prior?.sha256].includes(current),'Changed output; merge first: '+o.rel);
}}
for(const o of outputs){const dest=path.join(root,o.rel);fs.mkdirSync(path.dirname(dest),{recursive:true});fs.writeFileSync(dest,o.text);}
fs.mkdirSync(path.dirname(reportPath),{recursive:true});
fs.writeFileSync(reportPath,JSON.stringify({enabled:cfg.enabled,gameBattleTested:false,files:outputs.map(o=>({file:o.rel,sha256:hash(o.text),baselineSHA256:o.source?hash(o.source):null}))},null,2)+'\n');
console.log(`Built ${outputs.length} battlefield persistence resources; enabled=${cfg.enabled}`);
