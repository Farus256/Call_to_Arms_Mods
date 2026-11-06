// Restore CP capacity x2 in multiplayer presets on fresh HF data. Conquest keeps HF values:
// the mod must not ship set/dynamic_campaign/resources_*.set. Never changes unit costs.
// node tools/cp-multiplier.cjs --build [reference resource]
// Without --build, verify generated files only. Never writes into the game installation.
const fs=require('fs'),p=require('path'),assert=require('assert/strict'),crypto=require('crypto');
const s=require('./lib/sdl.cjs'),config=require('./cp-multiplier.json');
const repo=p.resolve(__dirname,'..'),defaultReference=p.resolve(repo,'../_survival_work/hf-update-20261105/reference/resource');
const defaultResource=p.join(repo,'mods/ultimate_frontline_bundle/resource');
const sha=b=>crypto.createHash('sha256').update(b).digest('hex');
const walk=d=>fs.readdirSync(d,{withFileTypes:true}).flatMap(e=>e.isDirectory()?walk(p.join(d,e.name)):[p.join(d,e.name)]);
const number=n=>String(Number((Number(n)*config.multiplier).toFixed(6)));
function schedule(value){
 const numeric=/^-?\d+(?:\.\d+)?$/;
 if(numeric.test(value.trim()))return number(value.trim());
 if(!/^-?\d+(?:\.\d+)?:-?\d+(?:\.\d+)?(?:[ ,]+-?\d+(?:\.\d+)?:-?\d+(?:\.\d+)?)*$/.test(value.trim()))throw Error('Unknown CP schedule: '+value);
 return value.replace(/(-?\d+(?:\.\d+)?):(-?\d+(?:\.\d+)?)/g,(_,time,cp)=>time+':'+number(cp));
}
function transform(file,buffer){
 assert(config.enabled&&config.multiplier===2,'Explicit CP x2 configuration required');
 let text=buffer.toString('latin1'),schedules=0;
 if(config.multiplayer&&/^set\/multiplayer\/games\/presets\/[^/]+\.inc$/.test(file)){
  text=text.replace(/\bcp(?:_[ab])?\(([^)]*)\)/g,(whole,value)=>{
   if(value.includes('%'))return whole;
   schedules++;return whole.slice(0,whole.indexOf('(')+1)+schedule(value)+')';
  });
 }
 s.parse(text);
 return {data:Buffer.from(text,'latin1'),schedules};
}
function expected(reference=defaultReference){
 const files=walk(p.join(reference,'set/multiplayer/games/presets'));
 return files.map(f=>{const file=p.relative(reference,f).replaceAll('\\','/'),before=fs.readFileSync(f),result=transform(file,before);return {file,before,...result};}).filter(e=>e.schedules);
}
function verify(resource=defaultResource,reference=defaultReference){
 const rows=expected(reference);
 for(const row of rows)assert.deepEqual(fs.readFileSync(p.join(resource,row.file)),row.data,'CP x2 drift: '+row.file);
 return {files:rows.length,cpSchedules:rows.reduce((n,r)=>n+r.schedules,0),multiplier:config.multiplier};
}
module.exports={transform,expected,verify,defaultReference};
if(require.main===module){
 const build=process.argv[2]==='--build',reference=p.resolve(process.argv[build?3:2]||defaultReference),rows=expected(reference);
 if(build){
  // Preflight every destination before the first write; reject unrelated local changes.
  for(const row of rows){const dest=p.join(defaultResource,row.file);if(fs.existsSync(dest)){const old=fs.readFileSync(dest);assert(old.equals(row.before)||old.equals(row.data),'Preserve modified CP file before building: '+row.file);}}
  for(const row of rows){const dest=p.join(defaultResource,row.file);fs.mkdirSync(p.dirname(dest),{recursive:true});fs.writeFileSync(dest,row.data);}
  const report={reference,config,files:rows.map(r=>({file:r.file,sourceSHA256:sha(r.before),generatedSHA256:sha(r.data),schedules:r.schedules}))};
  fs.writeFileSync(p.join(repo,'docs/CP_X2_BUILD.json'),JSON.stringify(report,null,2)+'\n');
 }
 console.log(JSON.stringify({...verify(defaultResource,reference),writtenToSource:build,gameInstallationWritten:false}));
}
