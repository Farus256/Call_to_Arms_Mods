// This hub is included by WAVE's movement registration only. With WAVE disabled
// the native HF registration stays in charge, without duplicate sequence names.
const fs=require('fs'),p=require('path'),assert=require('assert/strict'),s=require('./lib/sdl.cjs');
const repo=p.resolve(__dirname,'..'),ref=p.resolve(repo,'../_survival_work/hf-update-20261105/reference/resource');
const file='properties/animation/human/##core_activator.inc';
const patch=p.resolve(repo,'../3566110308/resource/properties/animation/human/##CORE_ACTIVATOR.inc');
const names=['stand_fire_gun_down_1','stand_fire_gun_up_1','grenade_deflect'];
function expected(reference=ref){
 const native=fs.readFileSync(p.join(reference,'properties/animation/human/_reg_human_movement.inc'),'latin1'),tree=s.parse(native);
 const additions=names.map(name=>{const n=tree.children.find(n=>s.name(n)==='sequence'&&n.tokens[1]?.value===name);assert(n,name);return native.slice(n.start,n.end);});
 return {file,text:fs.readFileSync(patch,'latin1')+'\n; UFB: restore HF 4 registrations absent from the WAVE-HF movement file.\n'+additions.join('\n')+'\n'};
}
function verify(resource=p.join(repo,'mods/ultimate_frontline_bundle/resource'),reference=ref){const e=expected(reference);assert.equal(fs.readFileSync(p.join(resource,e.file),'latin1'),e.text);return {hf4AnimationBindingsRestored:names};}
if(require.main===module){if(process.argv.includes('--build')){const e=expected(),dest=p.join(repo,'mods/ultimate_frontline_bundle/resource',e.file);fs.mkdirSync(p.dirname(dest),{recursive:true});fs.writeFileSync(dest,e.text,'latin1');}console.log(JSON.stringify(verify()));}
const externalRoots=()=>[p.resolve(repo,'../3566110308/resource'),p.resolve(repo,'../_ai_work/combat-review-20261105/wave/resource')];
module.exports={expected,verify,externalRoots};
