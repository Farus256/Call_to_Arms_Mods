// Narrow overlays from reviewed, versioned baselines. No shader or global physics changes.
const fs=require('fs'),path=require('path'),assert=require('assert/strict'),crypto=require('crypto');
const s=require('./lib/sdl.cjs'),cfg=require('./battlefield-persistence.json');
const repo=path.resolve(__dirname,'..'),root=path.join(repo,'mods/ultimate_frontline_bundle/resource');
const base=path.join(__dirname,'baselines/battlefield-persistence');
const reportPath=path.join(repo,'docs/realism/battlefield-persistence.json');
const previous=fs.existsSync(reportPath)?JSON.parse(fs.readFileSync(reportPath)).files:[];
const hash=b=>crypto.createHash('sha256').update(b).digest('hex');
const outputs=[];
for(const key of ['metalParticleSeconds','sandbagParticleSeconds','smallMetalLimit','mediumMetalLimit','sandbagDebrisLimit'])assert(Number.isFinite(cfg[key])&&cfg[key]>0,key);
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
  // Native metal entity-generators have no mover: persistence alone cannot
  // keep their debris on the terrain. Reuse native sandbag collision syntax.
  const view=s.all(ast,n=>n.children.includes(gen))[0];assert(view);
  if(!s.child(view,'mover'))changes.push([{start:view.end-1,end:view.end-1},
   '\n  {mover {collisions {terrain} {restitution 0.15}} {nodependonwind}}\n ']);
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
const sliced=['piece_small_steel','piece_tiny_steel','piece_small_steel_construction','piece_medium_steel','piece_medium_steel_construction','piece_medium_sand','piece_big_steel','piece_large_steel'];
for(const name of sliced){
 const rel=`entity/service/slicer/${name}.def`,original=read(rel);
 const changed=original.replace('/properties/small_part_harmless.inc','/properties/ufb_metal_part_harmless.inc')
  .replace(/\{props\b/,'{props "ufb_persistent_debris"');
 assert(changed.includes('"ufb_persistent_debris"'));
 queue(rel,cfg.enabled?changed:original,original);
}
for(const name of ['#metall1','#metall2','#metall3','#sandbag_01','#sandbag_02','#sandbag_01_win','#sandbag_02_win']){
 const rel=`entity/particle/${name}/${name}.def`,original=read(rel);
 const changed=original.replace(/\{props\b/i,'{props "ufb_persistent_debris"');
 assert(changed.includes('"ufb_persistent_debris"'));
 queue(rel,cfg.enabled?changed:original,original);
}
const debris='set/interaction_entity/ufb_persistent_debris.inc';
queue(debris,cfg.enabled?`; Only explicitly marked metal and sandbag fragments; casings keep stock cleanup.
{"ufb_persistent_debris" {on "check_delete_part" overload}}
{"small part ufb_persistent_debris"
 {on spawn overload
  {delay 0.01 {volumes disable bullet contact blast touch}}
  {delay 2 {call "activate_volumes"}}
 }
}
{"medium part ufb_persistent_debris"
 {on spawn overload
  {delay 0.05 {volumes disable bullet contact blast touch}}
  {delay 1 {volumes enable bullet contact blast}}
 }
}
`:'; UFB debris persistence disabled.\n');
// Horten/stock AI variants deliberately omit persistence even though ordinary
// emplacements retain it. Preserve the model, collision and all cover volumes.
for(const kind of ['shallow','standard']){
 const rel=`entity/construction/_military/fortifications/sandbag_old/sandbag_cannon_${kind}/sandbag_cannon_${kind}_ai.def`;
 const original=read(rel);assert(!original.includes('DynCmpPersistent'));
 queue(rel,cfg.enabled?original.replace('{constrain surface}','{DynCmpPersistent}\n\t{constrain surface}'):original,original);
}
const rel='set/entitymanager.set',original=read(rel),ast=s.parse(original),changes=[];
const classes={ufb_small_metal:['piece_small_steel','piece_tiny_steel','piece_small_steel_construction'],ufb_medium_metal:['piece_medium_steel','piece_medium_steel_construction'],ufb_sandbag_debris:['piece_medium_sand']};
for(const n of s.all(ast,n=>s.name(n)==='entity'))if(Object.values(classes).flat().includes(n.tokens[1]?.value))changes.push([n,'; UFB: moved to bounded metal-fragment group']);
const manager=s.child(ast,'entitymanager');assert(manager);
const limits={ufb_small_metal:cfg.smallMetalLimit,ufb_medium_metal:cfg.mediumMetalLimit,ufb_sandbag_debris:cfg.sandbagDebrisLimit};
const groups=Object.entries(classes).map(([name,entities])=>`\n {group "${name}" gameentity\n  {limit ${limits[name]}}\n  {remove dissolve}\n${entities.map(e=>`  {entity "${e}"}`).join('\n')}\n }\n`).join('');
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
