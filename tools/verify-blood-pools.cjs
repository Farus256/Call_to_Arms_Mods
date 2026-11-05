// Removal and preservation checks against the last reviewed gore implementation.
// node tools/verify-blood-pools.cjs [resource directory]
const fs=require('fs'),p=require('path'),assert=require('assert/strict'),cp=require('child_process');
const s=require('./lib/sdl.cjs');
const repo=p.resolve(__dirname,'..'),root=p.resolve(process.argv[2]||p.join(repo,'mods/ultimate_frontline_bundle/resource'));
const baseline='2fdbd19f10968a3d9c0df426d2f1d614d8a5c715';
const prefix='mods/ultimate_frontline_bundle/resource/';
const original=file=>cp.execFileSync('git',['show',baseline+':'+prefix+file],{cwd:repo,maxBuffer:4*1024*1024});
const read=file=>fs.readFileSync(p.join(root,file));
const walk=d=>fs.readdirSync(d,{withFileTypes:true}).flatMap(e=>e.isDirectory()?walk(p.join(d,e.name)):[p.join(d,e.name)]);
const poolName=name=>/^bloodstain(?:_(?:\d+s|rot120|rot240))?$/.test(name)||name==='ufb_corpse_pool_settled';
let checks=0;const check=(value,message)=>{assert(value,message);checks++;};
const human=s.parse(read('set/interaction_entity/human.inc').toString('latin1'));
const shape=n=>({kind:n.kind,tokens:n.tokens.map(t=>t.value),children:n.children.map(shape)});
const oldHuman=s.parse(original('set/interaction_entity/human.inc').toString('latin1'));
const hooks=new Set(['ufb_schedule_corpse_pool','ufb_schedule_bleedout_pool','ufb_corpse_pool.inc']);
let removedHooks=0;
function withoutPools(node){node.children=node.children.filter(n=>{const remove=['call','include'].includes(s.name(n))&&hooks.has(n.tokens[1]?.value);if(remove)removedHooks++;return !remove;});node.children.forEach(withoutPools);}
withoutPools(oldHuman);
// Reviewed later addition: blast reaction hook, unrelated to pools.
function withoutBlastHook(node){node.children=node.children.filter(n=>!(s.name(n)==='if'&&n.tokens[1]?.value==='min_energy'&&n.tokens[2]?.value==='0.45'&&s.child(n,'call')?.tokens[1]?.value==='ufb_near_blast'));node.children.forEach(withoutBlastHook);}
withoutBlastHook(human);
check(removedHooks===3,'baseline contains both death hooks and the include');
assert.deepEqual(shape(human),shape(oldHuman),'human actions changed beyond the three pool hooks');checks++;
check(!fs.existsSync(p.join(root,'set/interaction_entity/ufb_corpse_pool.inc')),'pool scheduler file removed');
const fxDir=p.join(root,'entity/fx/hit');
check(!fs.readdirSync(fxDir).some(f=>poolName(p.parse(f).name)),'all generated corpse-pool effects removed');
for(const file of walk(root).filter(f=>/\.(inc|ext|set|def|mi)$/i.test(f))){
 const ast=s.parse(fs.readFileSync(file,'latin1'));
 check(!s.all(ast,n=>n.tokens.some(t=>/^ufb_.*pool/.test(t.value))).length,'no pool callbacks/tags/includes: '+p.relative(root,file));
 check(!s.all(ast,n=>s.name(n)==='spawn'&&poolName(n.tokens[1]?.value||'')).length,'no spawning deleted pools: '+p.relative(root,file));
}
const bloodFiles=cp.execFileSync('git',['ls-tree','-r','--name-only',baseline,'--',prefix+'entity/fx/hit/'],{cwd:repo,encoding:'utf8'}).trim().split('\n').map(f=>f.slice(prefix.length)).filter(f=>/\/(?:blood|ground_blood)/.test(f)&&!poolName(p.parse(f).name));
for(const file of [...bloodFiles,'set/interaction_entity/dummy.inc']){
 assert(read(file).equals(original(file)),'other blood/body-part resource changed: '+file);checks++;
}
console.log(JSON.stringify({checks,corpsePoolsRemoved:true,deathHooksRemoved:removedHooks,otherBloodResourcesPreserved:bloodFiles.length,bodyPartPhysicsPreserved:true,humanActionsOtherwisePreserved:true,battleTested:false}));
