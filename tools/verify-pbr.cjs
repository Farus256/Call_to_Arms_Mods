// Offline compile of the actual PBR include tree. Prototype output is never installed.
const fs=require('fs'),path=require('path'),cp=require('child_process'),assert=require('assert/strict');
const repo=path.resolve(__dirname,'..');
const src=path.resolve(process.argv[2]||path.join(repo,'../_survival_work/audit-20261004/upstream/shader/dx10'));
const out=path.resolve(process.argv[3]||path.join(repo,'../_survival_work/audit-20261004/pbr-probe'));
const fxc=process.env.UFB_FXC||'C:/Program Files (x86)/Windows Kits/10/bin/10.0.26100.0/x64/fxc.exe';
assert(fs.existsSync(path.join(src,'ps.hlsl')),'Supply the complete extracted shader tree with Workshop PBR overlaid');
assert(fs.existsSync(fxc),'Set UFB_FXC to Windows SDK fxc.exe');
assert(src!==out&&!out.startsWith(src+path.sep),'Output must be outside the source tree');
const candidate=path.join(out,'prototype');fs.cpSync(src,candidate,{recursive:true});
const conversion=path.join(candidate,'pbr/phong2pbr.hlsl');
let text=fs.readFileSync(conversion,'utf8');
const start=text.indexOf('inline void universalT('),end=text.indexOf('\n}',start);
assert(start>=0&&end>start,'Review updated PBR conversion first');
text=text.slice(0,end)+'\n    // Offline probe only: preserve lighting; soften legacy-object highlight peaks.\n    roughness = max(roughness, (float)0.35);'+text.slice(end);
fs.writeFileSync(conversion,text);
const variants={diffuse:[],normal_specular:['BUMP=1','SPEC=1'],foliage:['BUMP=1','SPEC=1','NEED_ALPHA=1','ALPHA_TEST=1','FAKE_TRANSLUCENCY=1'],pbr:['BUMP=1','SPEC=1','PARALLAX=1','LIGHTMAP=1','TEXCOORDS=2'],pbr_lite:['BUMP=1','SPEC=1','PARALLAX=1','FULL_SPECULAR=1'],shadows:['BUMP=1','SPEC=1','SHADOW=1','SM_SLICES=3'],pbr_shadows:['BUMP=1','SPEC=1','PARALLAX=1','LIGHTMAP=1','TEXCOORDS=2','SHADOW=1','SM_SLICES=3'],pbr_emission:['BUMP=1','SPEC=1','PARALLAX=1','LIGHTMAP=1','FULL_SPECULAR=1','TEXCOORDS=2']};
const results=[];
for(const [name,defs] of Object.entries(variants))for(const [version,dir] of [['baseline',src],['prototype',candidate]]){
 const defines=['LIGHT=1','PARALLEL_LIGHT=1','DIFFUSE=1',...(defs.some(d=>d.startsWith('TEXCOORDS='))?[]:['TEXCOORDS=1']),...defs];
 const run=cp.spawnSync(fxc,['/nologo','/T','ps_4_0','/E','PS','/O3','/I',dir,...defines.flatMap(d=>['/D',d]),'/Fo',path.join(out,name+'-'+version+'.cso'),path.join(dir,'ps.hlsl')],{encoding:'utf8',windowsHide:true});
 const log=(run.stdout||'')+(run.stderr||'')+(run.error||'');fs.writeFileSync(path.join(out,name+'-'+version+'.log'),log);
 const warnings=[...log.matchAll(/warning (X\d+): (.*)/g)].map(m=>m[1]+': '+m[2].trim());
 results.push({name,version,defines,status:run.status,warnings});
 console.log(name,version,run.status===0?'PASS':'FAIL');if(run.status!==0)console.log(log);
}
assert(results.every(r=>r.status===0),'Shader compilation failed');
for(const name of Object.keys(variants))assert.deepEqual(results.find(r=>r.name===name&&r.version==='prototype').warnings,results.find(r=>r.name===name&&r.version==='baseline').warnings,'New warning: '+name);
// Confirm real PBR branches are identical: the probe affects legacy conversion only.
for(const name of ['diffuse','pbr','pbr_lite','pbr_shadows','pbr_emission'])assert(fs.readFileSync(path.join(out,name+'-baseline.cso')).equals(fs.readFileSync(path.join(out,name+'-prototype.cso'))),'Unexpected change outside legacy specular conversion: '+name);
const peak=r=>1/(Math.PI*Math.pow(r,4));
const report={source:src,prototypeOnly:true,installed:false,gameBattleTested:false,legacyRoughnessFloor:0.35,ggxPeak:{baseline:peak(0.1),probe:peak(0.1+0.9*0.35),note:'At N dot H = 1; an analytic highlight peak, not rendered brightness.'},results};
const docs=path.join(repo,'docs/realism/combat-audit');fs.mkdirSync(docs,{recursive:true});
fs.writeFileSync(path.join(docs,'pbr-probe.json'),JSON.stringify(report,null,2)+'\n');
