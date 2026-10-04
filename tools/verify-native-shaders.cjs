// Compile an isolated vanilla tree. This does not describe the active mod stack.
const fs=require('fs'),path=require('path'),cp=require('child_process'),assert=require('assert/strict');
const repo=path.resolve(__dirname,'..'),workspace=path.resolve(repo,'..');
assert(process.argv[2],'Pass the DX10 shader source directory extracted from the installed shader.pak');
const src=path.resolve(process.argv[2]),out=path.resolve(process.argv[3]||path.join(workspace,'_survival_work/native-shader-check'));
const walk=d=>fs.readdirSync(d,{withFileTypes:true}).flatMap(e=>e.isDirectory()?walk(path.join(d,e.name)):[path.join(d,e.name)]);
const sources=walk(src);
for(const file of sources)assert(!/#include\s*["<][^">]*pbr[\\/]/i.test(fs.readFileSync(file,'utf8')),'Native shader unexpectedly includes PBR: '+file);
const fxc=process.env.UFB_FXC||'C:/Program Files (x86)/Windows Kits/10/bin/10.0.26100.0/x64/fxc.exe';
assert(fs.existsSync(fxc));fs.mkdirSync(out,{recursive:true});
const variants={diffuse:[],normal_specular:['BUMP=1','SPEC=1'],foliage:['BUMP=1','SPEC=1','NEED_ALPHA=1','ALPHA_TEST=1','FAKE_TRANSLUCENCY=1'],parallax:['BUMP=1','SPEC=1','PARALLAX=1','LIGHTMAP=1','TEXCOORDS=2'],full_specular:['BUMP=1','SPEC=1','PARALLAX=1','FULL_SPECULAR=1'],shadows:['BUMP=1','SPEC=1','SHADOW=1','SM_SLICES=3']};
const results=[];
for(const [name,defs] of Object.entries(variants)){
 const defines=['LIGHT=1','PARALLEL_LIGHT=1','DIFFUSE=1',...(defs.some(d=>d.startsWith('TEXCOORDS='))?[]:['TEXCOORDS=1']),...defs];
 const run=cp.spawnSync(fxc,['/nologo','/T','ps_4_0','/E','PS','/O3','/I',src,...defines.flatMap(d=>['/D',d]),'/Fo',path.join(out,name+'.cso'),path.join(src,'ps.hlsl')],{encoding:'utf8',windowsHide:true});
 const log=(run.stdout||'')+(run.stderr||'')+(run.error||'');fs.writeFileSync(path.join(out,name+'.log'),log);
 results.push({name,status:run.status,defines,warnings:[...log.matchAll(/warning (X\d+): (.*)/g)].map(m=>m[1]+': '+m[2].trim())});
 console.log(name,run.status===0?'PASS':'FAIL');if(run.status!==0)console.log(log);
}
assert(results.every(r=>r.status===0),'Native shader compile failed');
fs.mkdirSync(path.join(repo,'docs/realism/shader-removal'),{recursive:true});
fs.writeFileSync(path.join(repo,'docs/realism/shader-removal/verification.json'),JSON.stringify({source:src,sourceFiles:sources.length,pbrIncludes:0,gameLaunched:false,cacheCleared:false,results},null,2)+'\n');
