// Offline FXC check. Requires a complete extracted shader include tree and Windows SDK.
const fs=require('fs'),path=require('path'),cp=require('child_process'),assert=require('assert/strict');
const repo=path.resolve(__dirname,'..');
const src=path.resolve(process.argv[2]||path.join(repo,'../_realism_work/visual_motion_fix/effective/shader/dx10'));
const out=path.resolve(process.argv[3]||path.join(repo,'../_survival_work/pbr-check'));
const fxc=process.env.UFB_FXC||'C:/Program Files (x86)/Windows Kits/10/bin/10.0.26100.0/x64/fxc.exe';
assert(fs.existsSync(path.join(src,'ps.hlsl')),'Supply a complete DX10 source tree');
assert(fs.existsSync(fxc),'Set UFB_FXC to your Windows SDK fxc.exe');
assert(src!==out&&!out.startsWith(src+path.sep),'Output must be outside source tree');
const patched=path.join(out,'current');
fs.cpSync(src,patched,{recursive:true});
fs.copyFileSync(path.join(repo,'mods/ultimate_frontline_bundle/resource/shader/dx10/pbr/light.hlsl'),path.join(patched,'pbr/light.hlsl'));
const variants={diffuse:[],normal_specular:['BUMP=1','SPEC=1'],foliage:['BUMP=1','SPEC=1','NEED_ALPHA=1','ALPHA_TEST=1','FAKE_TRANSLUCENCY=1'],pbr:['BUMP=1','SPEC=1','PARALLAX=1','LIGHTMAP=1','TEXCOORDS=2'],pbr_lite:['BUMP=1','SPEC=1','PARALLAX=1','FULL_SPECULAR=1'],shadows:['BUMP=1','SPEC=1','SHADOW=1','SM_SLICES=3']};
const results=[];
for(const [name,defs] of Object.entries(variants))for(const [version,dir] of [['baseline',src],['current',patched]]){
 const file=path.join(out,name+'-'+version+'.cso');
 const defines=['LIGHT=1','PARALLEL_LIGHT=1','DIFFUSE=1',...(defs.some(d=>d.startsWith('TEXCOORDS='))?[]:['TEXCOORDS=1']),...defs];
 const run=cp.spawnSync(fxc,['/nologo','/T','ps_4_0','/E','PS','/O3','/I',dir,...defines.flatMap(d=>['/D',d]),'/Fo',file,path.join(dir,'ps.hlsl')],{encoding:'utf8',windowsHide:true});
 const log=(run.stdout||'')+(run.stderr||'')+(run.error||'');
 fs.writeFileSync(path.join(out,name+'-'+version+'.log'),log);
 const warnings=[...log.matchAll(/warning (X\d+): (.*)/g)].map(m=>m[1]+': '+m[2].trim());
 results.push({name,version,defines,status:run.status,bytes:run.status===0?fs.statSync(file).size:null,warnings});
 console.log(name,version,run.status===0?'PASS':'FAIL');if(run.status!==0)console.log(log);
}
fs.mkdirSync(path.join(repo,'docs/realism/tactical'),{recursive:true});
fs.writeFileSync(path.join(repo,'docs/realism/tactical/shader-compilation.json'),JSON.stringify({compiler:fxc,target:'ps_4_0',entry:'PS',note:'Offline compile, not SMS Launcher or winter map validation',results},null,2)+'\n');
assert(results.every(r=>r.status===0),'Shader compile failure');
for(const name of Object.keys(variants))assert.deepEqual(results.find(r=>r.name===name&&r.version==='current').warnings,results.find(r=>r.name===name&&r.version==='baseline').warnings,'New shader warning: '+name);
