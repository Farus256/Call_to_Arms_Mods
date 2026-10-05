// Read-only game audit; writes evidence only to the requested report directory.
const fs=require('fs'),path=require('path'),crypto=require('crypto');
const s=require('./lib/sdl.cjs'),lua=require('luaparse');
const repo=path.resolve(__dirname,'..');
const snapshot=path.resolve(process.argv[2]||path.join(repo,'../_survival_work/audit-20261005'));
const installed=path.resolve(process.argv[3]||'D:/Programs/Steam/steamapps/common/Call to Arms - Gates of Hell/mods');
const walk=d=>fs.existsSync(d)?fs.readdirSync(d,{withFileTypes:true}).flatMap(e=>e.isDirectory()?walk(path.join(d,e.name)):[path.join(d,e.name)]):[];
const rel=(root,file)=>path.relative(root,file).replaceAll('\\','/');
const sha=file=>crypto.createHash('sha256').update(fs.readFileSync(file)).digest('hex');
function validateMods(n,inside=false){
 const mod=n.kind==='('&&s.name(n)==='mod';
 if(mod){
  if(inside)throw Error('Nested mods not supported');
  if(!(n.tokens.length===2||n.tokens.length===3&&n.tokens[1].value==='not'))throw Error('Unsupported mod header');
 }
 for(const c of n.children)validateMods(c,inside||mod);
}
const report={gameBattleTested:false,syntax:{sdl:0,lua51:0,issues:[]},installed:{checked:0,missing:[],different:[],extra:[]},breeds:{checked:0,changedUpstream:[],missingUpstream:[],newUpstream:[],directHealth:[]},missions:{total:0,withCoverInclude:0,byMode:{}},difficulty:{},shaderOverrides:[]};
for(const file of walk(path.join(repo,'mods'))){
 const fileRel=rel(path.join(repo,'mods'),file),target=path.join(installed,fileRel);
 report.installed.checked++;
 if(!fs.existsSync(target))report.installed.missing.push(fileRel);
 else if(sha(file)!==sha(target))report.installed.different.push(fileRel);
 if(fileRel.includes('/shader/'))report.shaderOverrides.push(fileRel);
 const ext=path.extname(file).toLowerCase();
 if(!['.set','.inc','.mi','.ext','.def','.info','.lua','.dl','.pattern','.weapon','.ammo','.grenade','.presets'].includes(ext)&&!fileRel.endsWith('/.presets')&&!fileRel.includes('/set/stuff/'))continue;
 const text=fs.readFileSync(file,'utf8');
 try{
  if(ext==='.lua'){lua.parse(text,{luaVersion:'5.1'});report.syntax.lua51++;}
  else{validateMods(s.parse(text));report.syntax.sdl++;}
 }catch(e){report.syntax.issues.push({file:fileRel,message:e.message});}
 if(fileRel.startsWith('ultimate_frontline_bundle/resource/map/multi/')&&ext==='.mi'){
  const mode=path.basename(file,'.mi'),covered=text.includes('(include "/map/multi/ufb_infantry_profile.inc")');
  report.missions.total++;if(covered)report.missions.withCoverInclude++;
  const row=report.missions.byMode[mode]??={total:0,withCoverInclude:0};row.total++;if(covered)row.withCoverInclude++;
 }
}
for(const mod of ['hortens_frontline_patch','ultimate_frontline_bundle'])for(const file of walk(path.join(installed,mod))){
 const fileRel=rel(installed,file);if(!fs.existsSync(path.join(repo,'mods',fileRel)))report.installed.extra.push(fileRel);
}
const manifest=JSON.parse(fs.readFileSync(path.join(repo,'docs/realism/tactical/breed-profiles.json'),'utf8'));
const known=new Set(manifest.entries.map(e=>e.file));
for(const e of manifest.entries){
 report.breeds.checked++;
 const file=path.join(snapshot,'upstream',e.file);
 if(!fs.existsSync(file))report.breeds.missingUpstream.push(e.file);
 else if(sha(file)!==e.sourceSHA256)report.breeds.changedUpstream.push(e.file);
 const ast=s.parse(fs.readFileSync(path.join(repo,'mods/ultimate_frontline_bundle/resource',e.file),'utf8'));
 const health=s.all(ast,n=>['health','vitality'].includes((s.name(n)||'').toLowerCase()));
 if(health.length)report.breeds.directHealth.push({file:e.file,values:health.map(n=>n.tokens.map(t=>t.value))});
}
for(const file of walk(path.join(snapshot,'upstream/set/breed'))){
 const name=rel(path.join(snapshot,'upstream'),file);
 if(!known.has(name)&&path.extname(file)==='.set'&&s.parse(fs.readFileSync(file,'utf8')).children.some(n=>s.name(n)==='breed'))report.breeds.newUpstream.push(name);
}
for(const file of walk(path.join(snapshot,'upstream/set/difficulty'))){
 const ast=s.parse(fs.readFileSync(file,'utf8'));
 report.difficulty[path.basename(file)]=s.all(ast,n=>s.name(n)==='health').map(n=>n.tokens.slice(1).map(t=>t.value));
}
fs.mkdirSync(snapshot,{recursive:true});fs.writeFileSync(path.join(snapshot,'current-state.json'),JSON.stringify(report,null,2)+'\n');
console.log(JSON.stringify(report,null,2));
if(report.syntax.issues.length||report.installed.missing.length||report.installed.different.length||report.breeds.changedUpstream.length||report.breeds.missingUpstream.length||report.breeds.newUpstream.length)process.exitCode=1;
