// Compare with freshly extracted game resources; no game/API emulation here.
const fs=require('fs'),path=require('path'),assert=require('assert/strict'),crypto=require('crypto');
const s=require('./lib/sdl.cjs');
const repo=path.resolve(__dirname,'..');
const audit=path.resolve(process.argv[2]||path.join(repo,'../_survival_work/audit-20261004'));
const root=path.resolve(process.argv[3]||path.join(repo,'mods/ultimate_frontline_bundle/resource'));
const read=rel=>fs.readFileSync(path.join(root,rel),'utf8');
const native=rel=>fs.readFileSync(path.join(audit,'vanilla',rel),'utf8');
const shape=n=>({kind:n.kind,tokens:n.tokens.map(t=>t.value),children:n.children.map(shape)});
let checks=0;function check(ok,msg){assert(ok,msg);checks++;}
assert.deepEqual(shape(s.parse(read('set/squads.set'))),shape(s.parse(native('set/squads.set'))),'Native placement for both cooperative and competitive modes');checks++;
const actor=s.parse(read('properties/human.ext')),original=s.parse(native('properties/human.ext'));
const chassis=tree=>tree.children.find(n=>s.name(n)==='Chassis');
assert.deepEqual(shape(chassis(actor)),shape(chassis(original)),'Complete native locomotion, not only rotation values');checks++;
const switchTime=tree=>s.all(tree,n=>s.name(n)==='const'&&n.tokens[1]?.value==='weapon/change_time')[0].tokens[2].value;
check(switchTime(actor)===switchTime(original),'Native weapon-change cooldown');
const hf=s.parse(read('map/multi/HF-dcg_script.inc'));
const removed=['hf flanking infantry ai/detect and action','hf inf ai/melee/melee','hf inf ai/grenade ap','hf inf ai/grenade at',...[30,40,50,60,70,90].map(n=>'hf inf ai/rocketlauncher '+n+'m')];
for(const name of removed){
 check(!s.all(hf,n=>s.name(n)===name).length,'Forced routine removed: '+name);
 check(!s.all(hf,n=>s.name(n)==='trigger'&&s.child(n,'name')?.tokens[1]?.value===name).length,'No dangling trigger call: '+name);
}
check(!s.all(hf,n=>s.name(n)==='inventory'&&/^range_\d+$/.test(s.child(n,'item')?.tokens[1]?.value||'')).length,'No fixed-class launcher draw bypasses native range checks');
const oldPath=path.join(audit,'repository-before/map/multi/HF-dcg_script.inc');
if(fs.existsSync(oldPath)){
 const old=s.parse(fs.readFileSync(oldPath,'utf8'));
 const withoutForced=n=>({kind:n.kind,tokens:n.tokens.map(t=>t.value),children:n.children.filter(c=>!removed.includes(s.name(c))).map(withoutForced)});
 assert.deepEqual(withoutForced(old),shape(hf),'All other HF mission actions preserved');checks++;
 for(const name of removed)check(s.all(old,n=>s.name(n)===name&&s.child(n,'actions')).length===1,'Regression baseline contained '+name);
 const launchers=s.all(old,n=>/^hf inf ai\/rocketlauncher /.test(s.name(n)||'')&&s.child(n,'actions'));
 let mismatches=0;
 for(const n of launchers){
  const pair=s.all(n,c=>s.name(c)==='for enemy')[0]?.tokens[1]?.value;
  const target=s.all(n,c=>s.name(c)==='action'&&s.child(c,'action')?.tokens[1]?.value==='attack')[0];
  if(pair!==s.child(s.child(target,'target'),'tag').tokens[1].value)mismatches++;
 }
 check(mismatches===1,'Reproduced the 40m launcher target-tag mismatch');
}
// Range data only: arcs, elevation, cover and animation require a real battle.
const walk=d=>fs.readdirSync(d,{withFileTypes:true}).flatMap(e=>e.isDirectory()?walk(path.join(d,e.name)):[path.join(d,e.name)]);
const throws=[];
for(const file of walk(path.join(root,'set/stuff/grenade'))){
 for(const n of s.all(s.parse(fs.readFileSync(file,'utf8')),n=>s.name(n)==='throw')){
  const ranges=s.all(n,c=>s.name(c)==='range').map(c=>Number(c.tokens[1].value));
  check(ranges.every(v=>Number.isFinite(v)&&v>0&&v<=50),'Plausible finite hand-grenade range: '+file);
  throws.push({file:path.relative(root,file).replaceAll('\\','/'),base:ranges[0],nonStory:ranges[1]??ranges[0]});
 }
}
const grenadeSummary={count:throws.length,min:Math.min(...throws.map(e=>e.nonStory)),max:Math.max(...throws.map(e=>e.nonStory)),entries:throws};
const hp=s.child(actor.children.find(n=>s.name(n)==='extender'&&n.tokens[1]?.value==='vitality'),'Health');
check(s.child(hp,'max').tokens[1].value==='70','Actual resource has 70 base HP');
const levels=s.all(s.parse(read('set/ability/health.set')),n=>s.name(n)==='level');
check(levels.length===202&&levels.every(n=>Number(n.tokens[2].value)<=1.15),'All health levels capped');
for(const n of s.all(s.parse(read('set/ability/veterancy.set')),n=>s.name(n)==='health'))check(Number(n.tokens[1].value)===0,'No veteran HP increase');
// Existing local breed edits must survive an upstream audit, including Dyakonov fixes.
const breedManifest=require('../docs/realism/tactical/breed-profiles.json');
const sha=b=>crypto.createHash('sha256').update(b).digest('hex');
for(const e of breedManifest.entries){
 check(sha(fs.readFileSync(path.join(root,e.file)))===e.generatedSHA256,'Generated breed matches manifest: '+e.file);
 check(sha(fs.readFileSync(path.join(audit,'upstream',e.file)))===e.sourceSHA256,'Current upstream breed incorporated: '+e.file);
}
const he=s.parse(read('set/stuff/rifle/grenade/dyakonov.he.ammo'));
const heTag=s.all(he,n=>s.name(n)==='tag')[0];
check(['dyakonov','he','ammo'].every(t=>heTag.tokens[1].value.split(/\s+/).includes(t)),'Updated inventory selector resolves explicit HE ammo tags');
const upstreamHE=s.parse(fs.readFileSync(path.join(audit,'upstream/set/stuff/rifle/grenade/dyakonov.he.ammo'),'utf8'));
heTag.tokens[1].value=heTag.tokens[1].value.replace(' dyakonov he','');
assert.deepEqual(shape(he),shape(upstreamHE),'HE ballistics and all other fields preserved');checks++;
const report={checks,resource:root,nativeComparison:'fresh installed game archive',gameBattleTested:false,grenades:grenadeSummary};
fs.writeFileSync(path.join(audit,process.argv[3]?'installed-verification.json':'verification.json'),JSON.stringify(report,null,2)+'\n');
console.log(JSON.stringify({checks,nativeMovement:true,removedRoutines:removed.length,baseHP:70,grenadeRange:[grenadeSummary.min,grenadeSummary.max],gameBattleTested:false},null,2));
