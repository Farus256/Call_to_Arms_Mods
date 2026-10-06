// Consume the archive/loose-file VFS collected by audit-audio.ps1.
const fs=require('fs'),path=require('path'),assert=require('assert/strict');
const root=path.resolve(__dirname,'../mods/ultimate_frontline_bundle/resource');
const index=JSON.parse(fs.readFileSync(process.argv[2]||path.join(__dirname,'../../_survival_work/task-20261006/audio/index.json'),'utf8').replace(/^\uFEFF/,''));
const files=Object.keys(index.effective),text=fs.readFileSync(path.join(root,'set/interaction_entity/weapons-defines.inc'),'utf8');
const links=[...text.matchAll(/\{link_sound\s+"[^"\r\n]+"\s+"([^"\r\n]+)"/g)].map(m=>m[1]).filter(x=>!x.includes('%'));
const missing=[...new Set(links.filter(x=>!files.some(p=>p.startsWith('sound/'+x.toLowerCase().replaceAll('\\','/').replace(/^\//,'')))))];
assert.equal(missing.length,0,'Missing weapon sound folders: '+missing.join(', '));
let waveFiles=0;
for(const [file,origin]of Object.entries(index.effective))if(origin.root.includes('3408719680')&&origin.file&&file.endsWith('.wav')){
 const wave=fs.readFileSync(origin.file);
 assert(wave.toString('ascii',0,4)==='RIFF'&&wave.toString('ascii',8,12)==='WAVE','Invalid WAVE container: '+file);waveFiles++;
}
console.log(`Audio: ${links.length} weapon links resolved; ${waveFiles} effective Wobble WAV headers valid. Playback, attenuation and clipping untested.`);
