const fs=require('fs'),path=require('path'),assert=require('assert/strict'),crypto=require('crypto');
const s=require('./lib/sdl.cjs'),cfg=require('./battlefield-persistence.json');
const root=path.join(__dirname,'../mods/ultimate_frontline_bundle/resource'),base=path.join(__dirname,'baselines/battlefield-persistence');
const read=(dir,rel)=>fs.readFileSync(path.join(dir,rel),'utf8');
const shape=n=>({kind:n.kind,tokens:n.tokens.map(t=>t.value),children:n.children.map(shape)});
let effects=0,generators=0;
for(const [folder,names,seconds] of [['detonation',cfg.vehicleEffects,cfg.metalParticleSeconds],['hit',cfg.sandbagEffects,cfg.sandbagParticleSeconds]])for(const name of names){
 const rel=`entity/fx/${folder}/${name}.def`,old=s.parse(read(base,rel)),now=s.parse(read(root,rel));
 const oldGen=s.all(old,n=>s.name(n)==='entitygenerator'),newGen=s.all(now,n=>s.name(n)==='entitygenerator');
 assert.equal(newGen.length,oldGen.length,'no extra debris generators');
 for(let i=0;i<newGen.length;i++){
  const a=oldGen[i],b=newGen[i];
  assert.deepEqual(shape(s.child(a,'totalparticles')),shape(s.child(b,'totalparticles')),'unchanged number of particles');
  const life=s.child(s.child(b,'particleinit'),'lifetime');
  assert.equal(Number(life.tokens[1].value),seconds);assert.equal(life.tokens.length,2,'no short random lifetime');
  assert.equal(s.all(b,n=>s.name(n)==='fx').length,0,'no persistent smoke emitter');
  // Normalize the only allowed edits and compare the entire effect tree.
  life.tokens=s.child(s.child(a,'particleinit'),'lifetime').tokens;
  const ae=a.children.filter(n=>s.name(n)==='entity'),be=b.children.filter(n=>s.name(n)==='entity');
  ae.forEach((n,j)=>be[j].children=n.children);
  generators++;
 }
 assert.deepEqual(shape(now),shape(old),'all dust, sparks, lights, sounds and debris motion preserved: '+rel);effects++;
}
const oldProp=read(base,'properties/small_part_harmless.inc'),prop=read(root,'properties/ufb_metal_part_harmless.inc');
assert.equal(prop,oldProp.replace(' "delete_after_spawn"',''),'only deletion property removed; harmless physics retained');
assert(read(root,'properties/small_part_harmless.inc').includes('"delete_after_spawn"'),'global debris cleanup remains');
for(const name of ['piece_small_steel','piece_tiny_steel']){
 const rel=`entity/service/slicer/${name}.def`;
 assert.equal(read(root,rel).replace('/properties/ufb_metal_part_harmless.inc','/properties/small_part_harmless.inc'),read(base,rel));
}
const manager=s.parse(read(root,'set/entitymanager.set'));
const fxManager=s.parse(read(root,'set/fxmanager.set'));
for(const [names,count,time] of [[cfg.vehicleEffects,cfg.vehicleEffectLimit,cfg.metalParticleSeconds],[cfg.sandbagEffects,cfg.sandbagEffectLimit,cfg.sandbagParticleSeconds]])for(const name of names){
 const groups=s.all(fxManager,n=>s.name(n)==='group'&&n.children.some(c=>s.name(c)==='fx'&&c.tokens[1]?.value===name));
 assert.equal(groups.length,1,'one bounded FX group per persistent effect');
 assert.equal(Number(s.child(groups[0],'countLimit').tokens[1].value),count);
 assert.equal(Number(s.child(groups[0],'timeLimit').tokens[1].value),time);
}
const groups=s.all(manager,n=>s.name(n)==='group');
for(const [name,count,entities] of [['ufb_small_metal',cfg.smallMetalLimit,['piece_small_steel','piece_tiny_steel','piece_small_steel_construction']],['ufb_medium_metal',cfg.mediumMetalLimit,['piece_medium_steel','piece_medium_steel_construction']]]){
 const group=groups.find(n=>n.tokens[1].value===name);assert(group);
 assert.equal(Number(s.child(group,'limit').tokens[1].value),count);
 assert.equal(s.all(group,n=>s.name(n)==='mod').length,0,'same limit in every mode');
 for(const entity of entities)assert.equal(s.all(manager,n=>s.name(n)==='entity'&&n.tokens[1]?.value===entity).length,1,'no conflicting cleanup groups');
}
for(const file of JSON.parse(fs.readFileSync(path.join(__dirname,'../docs/realism/battlefield-persistence.json'))).files)
 assert.equal(crypto.createHash('sha256').update(fs.readFileSync(path.join(root,file.file))).digest('hex'),file.sha256);
console.log(`Battlefield persistence: ${effects} effects / ${generators} debris generators; physics, transient FX, limits and hashes passed. Engine rendering/FPS untested.`);
