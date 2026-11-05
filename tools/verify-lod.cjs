// HF pulls near LOD switches in (vehicles 50 -> 30 m, buildings 90 -> 50 m) but extends far ones.
// UFB keeps the larger distance of HF and vanilla at each stage, so neither end gets worse.
// node tools/verify-lod.cjs [--build]   (needs unzip on PATH)
const fs=require('fs'),p=require('path'),cp=require('child_process'),assert=require('assert/strict');
const repo=p.resolve(__dirname,'..'),file='set/level_of_detail.inc';
const target=p.join(repo,'mods/ultimate_frontline_bundle/resource',file);
const reference=p.resolve(repo,'../_survival_work/hf-update-20261105/reference/resource',file);
const pak='D:/Programs/Steam/steamapps/common/Call to Arms - Gates of Hell/resource/gamelogic.pak';
const distance=/(\{distance\s+\("scale2?"\s+d2?\()(\d+)(\)\))/g;
// Category -> distances, in file order.
function stages(text){
 const map=new Map();let name=null;
 for(const line of text.split('\n')){
  if(/^\s*;/.test(line))continue;
  const head=line.match(/^\s*\{"([a-z_]+)"/);if(head){name=head[1];map.set(name,[]);continue;}
  if(name)for(const m of line.matchAll(distance))map.get(name).push(Number(m[2]));
 }
 return map;
}
function policy(hf,vanilla){
 const base=stages(vanilla);let name=null,stage=0;
 return hf.split('\n').map(line=>{
  if(/^\s*;/.test(line))return line;
  const head=line.match(/^\s*\{"([a-z_]+)"/);if(head){name=head[1];stage=0;return line;}
  return line.replace(distance,(all,before,value,after)=>{
   const own=stages(hf).get(name),old=base.get(name),i=stage++;
   return old&&old.length===own.length?before+Math.max(Number(value),old[i])+after:all;
  });
 }).join('\n');
}
const hf=fs.readFileSync(reference,'latin1');
const vanilla=cp.execFileSync('unzip',['-p',pak,file],{maxBuffer:1e7}).toString('latin1');
const expected=policy(hf,vanilla);
if(process.argv.includes('--build'))fs.writeFileSync(target,expected,'latin1');
const now=fs.readFileSync(target,'latin1');
assert.equal(now,expected,'level_of_detail.inc differs from the policy; run with --build');
const a=stages(now),h=stages(hf),v=stages(vanilla);let changed=0;
for(const [name,list]of a){
 assert(list.every((d,i)=>i===0||d>d===false&&d>=list[i-1]),'LOD stages must grow: '+name);
 list.forEach((d,i)=>{assert(d>=h.get(name)[i],'Below HF: '+name);if(d!==h.get(name)[i])changed++;});
 if(v.get(name)?.length===list.length)list.forEach((d,i)=>assert(d>=v.get(name)[i],'Below vanilla: '+name));
}
assert(a.get('vehicle')[0]>=v.get('vehicle')[0]);
console.log(JSON.stringify({categories:a.size,stagesRaised:changed,vehicle:a.get('vehicle').map(d=>d/20),building:a.get('decor_building').map(d=>d/20)}));
