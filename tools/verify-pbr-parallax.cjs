// UFB shader/dx10/material.inc = Workshop PBR material.inc + vanilla terrain parallax basis (TEX_BLEND only).
// Needs fxc (UFB_FXC) and the extracted shader tree with Workshop PBR overlaid (same inputs as verify-pbr.cjs).
const fs=require('fs'),p=require('path'),cp=require('child_process'),os=require('os'),assert=require('assert/strict');
const repo=p.resolve(__dirname,'..');
const workshop=p.resolve(repo,'../3548575715/resource/shader/dx10/material.inc'),ufbDir=p.join(repo,'mods/ultimate_frontline_bundle/resource/shader/dx10');
const tree=p.resolve(process.argv[2]||p.join(repo,'../_survival_work/audit-20261004/upstream/shader/dx10'));
const fxc=process.env.UFB_FXC||'C:/Program Files (x86)/Windows Kits/10/bin/10.0.26100.0/x64/fxc.exe';
assert(fs.existsSync(p.join(tree,'ps.hlsl'))&&fs.existsSync(fxc),'Need the shader tree and fxc.exe');
// 1. Override is the Workshop file plus exactly one TEX_BLEND block; a Workshop update fails here.
const ufb=fs.readFileSync(p.join(ufbDir,'material.inc'),'latin1');
const block=ufb.match(/#ifdef TEX_BLEND\r\n\t\/\/ UFB:[\s\S]*?#endif\r\n/);assert(block,'UFB terrain block missing');
assert.equal(ufb.replace(block[0],''),fs.readFileSync(workshop,'latin1'),'Workshop PBR material.inc changed: rebase the UFB override');
// 2. Compile: everything outside TEX_BLEND stays byte-identical to Workshop PBR; terrain variants compile.
const tmp=fs.mkdtempSync(p.join(os.tmpdir(),'ufb-pbr-')),ws=p.join(tmp,'ws'),pt=p.join(tmp,'pt');
fs.cpSync(tree,ws,{recursive:true});fs.cpSync(tree,pt,{recursive:true});
for(const f of ['pbr/light.hlsl','pbr/phong2pbr.hlsl'])for(const d of [ws,pt])fs.copyFileSync(p.join(ufbDir,f),p.join(d,f));
fs.copyFileSync(p.join(ufbDir,'material.inc'),p.join(pt,'material.inc'));
const common='USE_VCOLOR TEXCOORDS=1 PARALLEL_LIGHT LIGHT DIFFUSE FOGMAP SHADOW SM_SLICES=3 SHADOW_HIGH USING_TEX_ARRAY';
const variants={ // terrain defines copied from the game's shader_cache headers
 terrain:'BUMP SPEC PARALLAX TEX_BLEND LAYER1 GLOBAL_NORMALMAP',terrain_haze:'HAZE BUMP SPEC PARALLAX TEX_BLEND LAYER1 GLOBAL_NORMALMAP',
 object_parallax:'BUMP SPEC PARALLAX',layered_parallax:'BUMP SPEC PARALLAX LAYER1 GLOBAL_NORMALMAP',pbr:'BUMP SPEC PARALLAX LIGHTMAP',
 pbr_lite:'BUMP SPEC PARALLAX FULL_SPECULAR',bump:'BUMP SPEC',lightmap:'SPEC LIGHTMAP'};
const build=(dir,name,defs)=>{const out=p.join(tmp,name+'-'+p.basename(dir)+'.cso');
 const r=cp.spawnSync(fxc,['/nologo','/T','ps_5_0','/E','PS','/O3','/I',dir,...(common+' '+defs).split(' ').flatMap(d=>['/D',d]),'/Fo',out,p.join(dir,'ps.hlsl')],{encoding:'utf8',windowsHide:true});
 assert.equal(r.status,0,name+' '+p.basename(dir)+': '+r.stdout+r.stderr);return fs.readFileSync(out);};
const result={};
for(const [name,defs] of Object.entries(variants)){const same=build(ws,name,defs).equals(build(pt,name,defs));result[name]=same?'identical':'changed';
 assert.equal(same,!/TEX_BLEND/.test(defs),name+(same?' should change':' changed outside terrain'));}
fs.rmSync(tmp,{recursive:true,force:true});
console.log(JSON.stringify({terrainParallaxBasis:'vanilla',overrideMatchesWorkshop:true,variants:result}));
