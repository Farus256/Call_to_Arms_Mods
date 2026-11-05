// Verify the HF 4 update against a fresh game + HF text-resource reference.
// node tools/verify-hf4-update.cjs [UFB resource] [reference resource]
const fs=require('fs'),p=require('path'),assert=require('assert/strict');
const s=require('./lib/sdl.cjs'),lua=require('luaparse');
const repo=p.resolve(__dirname,'..'),work=p.resolve(repo,'../_survival_work/hf-update-20261105');
const resource=p.resolve(process.argv[2]||p.join(repo,'mods/ultimate_frontline_bundle/resource'));
const reference=p.resolve(process.argv[3]||p.join(work,'reference/resource'));
const walk=d=>fs.existsSync(d)?fs.readdirSync(d,{withFileTypes:true}).flatMap(e=>e.isDirectory()?walk(p.join(d,e.name)):[p.join(d,e.name)]):[];
const read=f=>fs.readFileSync(f,'latin1'),shape=n=>({kind:n.kind,tokens:n.tokens.map(t=>t.value),children:n.children.map(shape)});
const local=walk(resource),relative=f=>p.relative(resource,f).replaceAll('\\','/');
const animation=require('./animation-compat.cjs');
const resolve=(rel)=>[resource,...animation.externalRoots(),reference].map(root=>p.join(root,rel)).find(f=>fs.existsSync(f));
const balance=/^(set\/(breed\/|stuff\/|ability\/|dynamic_campaign\/|multiplayer\/|target\/|vision\/)|set\/(ballistics\.set|small_firearms_accuracy\.inc|squads\.set|talk\.set)$|properties\/(human\.ext|vehicle\.ext|resupply\.inc|human_fsm\/))/;
const cp=require('./cp-multiplier.cjs'),cpFiles=new Set(cp.expected(reference).map(e=>e.file));
const combat=require('./combat-autonomy.cjs'),combatFiles=new Set(['set/target/ammo.set','set/target/human_fg.inc','set/target/human_ap.inc','set/stuff/bazooka/panzerfaust_60.weapon']);
const weaponFixes=require('./weapon-logic-fixes.cjs'),weaponFiles=new Set(weaponFixes.expected(reference).map(e=>e.file));
for(const f of local)assert(!balance.test(relative(f))||cpFiles.has(relative(f))||combatFiles.has(relative(f))||weaponFiles.has(relative(f)),'Old balance override: '+relative(f));
const cpResult=cp.verify(resource,reference);
const combatResult=combat.verify(resource,reference);
const supportResult=require('./repair-hf-support.cjs').verify(resource,reference);
const animationResult=require('./animation-compat.cjs').verify(resource,reference);
const weaponResult=weaponFixes.verify(resource,reference);
const hfLogicResult=require('./hf-logic-fixes.cjs').verify(resource);
const human=read(p.join(resource,'set/interaction_entity/human.inc'));
const visual=new Set(['die_with_blood','explosion','crush','bm_explosion','ufb_smoke_screen_120m','ufb_smoke_screen_60m','ufb_smoke_screen_wirecutter','ufb_hf_cover_committed']);
const nativeHuman=s.parse(read(p.join(reference,'set/interaction_entity/human.inc'))).children[0];
const currentHuman=s.parse(human).children[0];
const mechanic=n=>!(s.name(n)==='on'&&visual.has(n.tokens[1]?.value))&&!(s.name(n)==='include'&&n.tokens[1]?.value==='ufb_combat_events.inc');
// Remove only the native bleedout pool from the reference before comparing mechanics.
const nativeStop=s.all(nativeHuman,n=>s.name(n)==='on'&&n.tokens[1]?.value==='stop_personage')[0];
const nativePool=s.all(nativeStop,n=>s.name(n)==='spawn'&&n.tokens[1]?.value==='bloodstain');
assert.equal(nativePool.length,1,'Expected one native bleedout pool');
const nativePoolParent=s.all(nativeStop,n=>n.children.includes(nativePool[0]))[0];
nativePoolParent.children=nativePoolParent.children.filter(n=>n!==nativePool[0]);
const humanShape=n=>{const copy=shape(n);if(s.name(n)==='on'&&n.tokens[1]?.value==='bullet_hit')copy.children=copy.children.filter(c=>!(c.tokens[0]==='call'&&c.tokens[1]==='ufb_combat_hit'));if(s.name(n)==='on'&&['start_healing','stop_healing'].includes(n.tokens[1]?.value))copy.children=copy.children.filter(c=>!(c.tokens[0]==='tags'&&c.tokens[2]==='_ufb_healing_active'));if(s.name(n)==='on'&&n.tokens[1]?.value==='move')copy.children=copy.children.filter(c=>!(c.tokens[0]==='call'&&['ufb_autonomy_move_on','ufb_autonomy_move_off'].includes(c.tokens[1])));return copy;};
assert.deepEqual(currentHuman.children.filter(mechanic).map(humanShape),nativeHuman.children.filter(mechanic).map(shape),'Native HF human mechanics changed');
const hfFile='map/multi/HF-dcg_script.inc',hf=read(p.join(resource,hfFile)),hfTree=s.parse(hf),nativeHF=s.parse(read(p.join(reference,hfFile)));
const key=n=>n.kind+':'+n.tokens.map(t=>t.value).join('|');
const currentKeys=new Map();
for(const n of hfTree.children){const k=key(n);currentKeys.set(k,(currentKeys.get(k)||0)+1);}
const nativeKeys=new Map();
for(const n of nativeHF.children){const k=key(n);nativeKeys.set(k,(nativeKeys.get(k)||0)+1);}
for(const [k,count] of nativeKeys)assert((currentKeys.get(k)||0)>=count,'New HF definition or macro variant lost: '+k);
// Repeated macro calls share a name but carry different ranges. Checking names alone misses stale arguments.
const calls=ast=>ast.children.filter(n=>n.kind==='('&&!['define','include'].includes(s.name(n))).map(shape);
assert.deepEqual(calls(hfTree),calls(nativeHF),'HF macro call arguments or ranges changed');
let sdlFiles=0,luaFiles=0,includes=0,requires=0;
for(const file of local){
 const rel=relative(file),ext=p.extname(file).toLowerCase();
 if(ext==='.lua'){
  const t=read(file);lua.parse(t,{luaVersion:'5.1'});luaFiles++;
  for(const m of t.matchAll(/require\s*\(\s*(?:\[\[([^\]]+)\]\]|["']([^"']+)["'])\s*\)/g)){
   const name=m[1]||m[2],target=name.replace(/^\/?(?:resource\/)?script\//,'script/')+'.lua';
   assert(resolve(target),'Missing Lua module: '+name+' from '+rel);requires++;
  }
 }
 if(!['.mi','.inc','.def','.ext','.set'].includes(ext))continue;
 const t=read(file);assert(!/^<<<<<<< |^>>>>>>> /m.test(t),'Unresolved conflict: '+rel);
 const ast=s.parse(t);sdlFiles++;
 if(rel.startsWith('map/'))for(const condition of s.all(ast,n=>s.name(n)==='condition')){
  const terms=s.child(condition,'terms');if(!terms)continue;
  const ids=terms.children.map(n=>(s.name(n)||'').split('.')[0]);
  assert.equal(new Set(ids).size,ids.length,'Duplicate condition term IDs: '+rel);
  const expr=s.child(condition,'expression')?.tokens[1]?.value;
  if(expr)for(const m of expr.matchAll(/\b\d+\b/g))assert(ids.includes(m[0]),'Undefined expression term '+m[0]+' in '+rel);
 }
 assert(!/ufb_(?:infantry_profile|survival|stress|wounds)\.inc/.test(t),'Retired tuning still referenced: '+rel);
 for(const n of s.all(ast,n=>n.kind==='('&&s.name(n)==='include')){
  const value=n.tokens[1]?.value;if(!value||value.includes('%'))continue;
  const target=value.replaceAll('\\','/');
  const virt=target.startsWith('/')?target.slice(1):p.posix.normalize(p.posix.dirname(rel)+'/'+target);
  assert(!virt.startsWith('../')&&resolve(virt),'Missing include '+value+' from '+rel);includes++;
 }
}
// Every saved garrison variant fits GoH's waypoint allocator and resolves its references.
const isPoint=n=>s.child(n,'position')||s.child(n,'Position');
const refs=n=>s.all(n,c=>['transition','waypoint','target_waypoint'].includes(s.name(c))&&c.tokens.length===2).map(c=>c.tokens[1].value);
const shared=['ufb_garrison_functions.inc','ufb_garrison_script.inc'].flatMap(f=>refs(s.parse(read(p.join(resource,'map/multi',f)))));
let maps=0,waypoints=0,maxID=0;
for(const file of local.filter(f=>p.basename(f)==='ufb_garrison_layout.inc')){
 const mission=p.join(p.dirname(file),'campaign_capture_the_flag.mi'),tree=s.parse(read(mission)).children[0];
 const script=tree.children.find(n=>s.child(n,'functions'));assert(script,'Mission script missing: '+mission);
 const points=new Map();
 function visit(nodes,owner,stack){for(const n of nodes){
  if(n.kind==='('&&s.name(n)==='include'){
   const name=n.tokens[1].value.replaceAll('\\','/'),rel=name.startsWith('/')?name.slice(1):p.posix.normalize(p.posix.dirname(owner)+'/'+name);
   assert(!stack.includes(rel),'Recursive waypoint include: '+rel);const target=resolve(rel);assert(target,rel);visit(s.parse(read(target)).children,rel,[...stack,rel]);
  }else if(isPoint(n)){
   const id=s.name(n);assert(!points.has(id),'Duplicate waypoint '+id+' in '+mission);
   if(/^\d+$/.test(id)){assert(Number(id)<8192,'Waypoint outside engine pool: '+id);maxID=Math.max(maxID,Number(id));}
   points.set(id,n);
  }
 }}
 for(const group of script.children.filter(n=>s.name(n)==='waypoints'))visit(group.children,relative(mission),[]);
 for(const id of [...shared,...refs(s.parse(read(file)))])assert(points.has(id),'Dangling garrison waypoint '+id+' in '+mission);
 const wrapperIncludes=s.all(script,n=>n.kind==='('&&s.name(n)==='include').map(n=>n.tokens[1]?.value);
 assert(!wrapperIncludes.includes('../dcg_script.inc')&&!wrapperIncludes.includes('../dcg_functions.inc'),'Native and UFB wrappers load twice: '+mission);
 maps++;waypoints+=points.size;
}
assert.equal(maps,117,'Additional maps/garrisons lost');
const info=read(p.join(resource,'../mod.info'));assert(info.includes('4.0.0')&&/^[ \t]*\{require "mod_3359417100"\}/m.test(info),'HF dependency missing');
console.log(JSON.stringify({nativeHFBalanceOutsideReviewedWeaponFixes:true,linearPanzerfaust60:true,...weaponResult,...hfLogicResult,commandPointMultiplier:cpResult.multiplier,combatAutonomy:combatResult.combatAutonomy,nativeHumanDamageAndWounds:true,...supportResult,...animationResult,allHFDefinitionsRetained:true,sdlFiles,luaFiles,includes,requires,garrisonMaps:maps,waypoints,maxWaypointID:maxID}));
