// The engine bleed-out timer becomes a fallback above the slowest UFB tier (ufb_bleedout.inc, 20 min).
// node tools/bleedout.cjs --build   write set/difficulty/*.dl from the HF/game reference
// node tools/bleedout.cjs           verify only
const fs=require('fs'),p=require('path'),assert=require('assert/strict'),s=require('./lib/sdl.cjs');
const repo=p.resolve(__dirname,'..'),resource=p.join(repo,'mods/ultimate_frontline_bundle/resource');
const reference=p.resolve(repo,'../_survival_work/hf-update-20261107/reference/resource');
const files=['easy','normal','hard','heroic','multiplayer'].map(n=>`set/difficulty/${n}.dl`);
const fallback={min:1320,max:1380},slowestTier=1200;
assert(fallback.min>slowestTier);
function expected(file){
 let text=fs.readFileSync(p.join(reference,file),'latin1'),n=0;
 text=text.replace(/\{death_delay_(min|max)\s+\d+\}/g,(_,k)=>{n++;return `{death_delay_${k} ${fallback[k]}}`;});
 assert.equal(n,2,'death_delay pair in '+file);s.parse(text);return text;
}
function verify(){
 for(const f of files)assert.equal(fs.readFileSync(p.join(resource,f),'latin1'),expected(f),'Bleed-out drift: '+f);
 const tiers=fs.readFileSync(p.join(resource,'set/interaction_entity/ufb_bleedout.inc'),'latin1');
 const delays=[...tiers.matchAll(/\{delay (\d+) "ufb_bleedout"/g)].map(m=>Number(m[1]));
 assert.equal(delays.length,9);assert.equal(Math.max(...delays),slowestTier);
 return {bleedoutTiers:3,bleedoutFallbackSeconds:[fallback.min,fallback.max],difficultyFiles:files.length};
}
if(require.main===module){
 if(process.argv.includes('--build'))for(const f of files){const d=p.join(resource,f);fs.mkdirSync(p.dirname(d),{recursive:true});fs.writeFileSync(d,expected(f),'latin1');}
 console.log(JSON.stringify(verify()));
}
module.exports={verify,files};
// For checks that compare human.inc with an older reviewed copy: undo exactly the bleed-out edits.
function withoutBleedout(node){
 const hooks=['ufb_bleedout.inc','ufb_bleedout_start','ufb_bleedout'];
 const undo=n=>{
  if(['include','call','kill_delay'].includes(s.name(n))&&hooks.includes(n.tokens[1]?.value))return [];
  const words=n.tokens.map(t=>t.value).join(' ');
  if(words==='if not tagged _ufb_wound_still')return n.children.flatMap(undo);
  if(words==='if rand 0.33 else rand 0.5 else'&&n.children.some(c=>c.tokens[1]?.value==='lie_wounded_1'))n.tokens[5].value='0.33';
  withoutBleedout(n);
  return [n];
 };
 node.children=node.children.flatMap(undo);
 return node;
}
module.exports.withoutBleedout=withoutBleedout;
