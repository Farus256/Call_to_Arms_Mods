// UFB must not shadow HF release scripts with the old 2026-09-24 dev snapshot (resync 2026-10-17).
// Run: node tools/verify-hf-resync.cjs [HF workshop folder]   (needs unzip on PATH)
const fs=require('fs'),path=require('path'),cp=require('child_process'),assert=require('assert/strict');
const repo=path.resolve(__dirname,'..'),res=path.join(repo,'mods/ultimate_frontline_bundle/resource');
const hfPak=path.join(process.argv[2]||path.join(repo,'../3359417100'),'resource/gamelogic.pak');
const hf=e=>cp.execFileSync('unzip',['-p',hfPak,e],{maxBuffer:1<<26}).toString('utf8');
const ufb=f=>fs.readFileSync(path.join(res,f),'utf8');
const lf=s=>s.replace(/\r/g,'');
// HF release wins for these: UFB copies were unmodified dev snapshots.
for(const f of ['tank/tank-main.inc','tank/damage-armoredcar.inc','tank/damage-heavy.inc','tank/damage-light.inc','tank/damage-medium.inc',
 'vehicle/vehicle-main.inc','vehicle/car-main.inc','vehicle/moto.inc','airborne.inc','cannon.inc','muzzle.inc','explosive.inc',
 'grenade.inc','killzones.inc','construction/special.inc'])assert(!fs.existsSync(path.join(res,'set/interaction_entity',f)),'stale HF copy: '+f);
assert(!fs.existsSync(path.join(res,'set/vision/vision_fields.inc')),'UFB vision_fields override is back (narrow FOV)');
// weapons-defines = HF release + three sound folders that exist in the game.
const soundFix=[['s1/recoil/Shared/Mortar/','s2/recoil/Shared/Mortar/'],['s3/recoil/Shared/Mortar/','s2/recoil/Shared/Mortar/'],['s3/recoil/Shared/Cannon/','s3/recoil/Cannon/']];
let wd=lf(hf('set/interaction_entity/weapons-defines.inc'));
for(const [a,b] of soundFix)wd=wd.split('"weapon/shot/cannon/'+a+'"').join('"weapon/shot/cannon/'+b+'"');
assert.equal(lf(ufb('set/interaction_entity/weapons-defines.inc')),wd,'weapons-defines.inc drifted from HF release + sound fixes');
// stuff = HF release + dropped_weapon tag on ground hit.
const st=lf(hf('set/interaction_entity/stuff.inc')).replace('\t\t{on ground_hit %override\n','\t\t{on ground_hit %override\n\t\t\t{tags add "dropped_weapon"}\n');
assert.equal(lf(ufb('set/interaction_entity/stuff.inc')),st,'stuff.inc drifted from HF release + dropped_weapon');
const human=ufb('properties/human.ext');
assert(!/\(mod "gametype:[^"]*" \{(Min)?RecognizeTime/.test(human),'RecognizeTime gametype override is back');
for(const f of ['set/interaction_entity/weapons-defines.inc','set/interaction_entity/stuff.inc','properties/human.ext']){
 const t=ufb(f).replace(/;.*$/gm,'').replace(/"[^"\n]*"/g,'');
 for(const [o,c] of [['{','}'],['(',')']])assert.equal(t.split(o).length,t.split(c).length,'unbalanced '+o+c+' in '+f);
}
console.log('HF resync OK');
