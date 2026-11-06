// Semantic regression proof: preset CP amounts double once, timings and other data survive,
// and Conquest stays on HF values because the mod ships no resource profile of its own.
const fs=require('fs'),p=require('path'),assert=require('assert/strict');
const s=require('./lib/sdl.cjs'),cp=require('./cp-multiplier.cjs');
const resource=p.resolve(process.argv[2]||p.join(__dirname,'../mods/ultimate_frontline_bundle/resource'));
const reference=p.resolve(process.argv[3]||cp.defaultReference);
const shape=n=>({kind:n.kind,tokens:n.tokens.map(t=>t.value),children:n.children.map(shape)});
const args=text=>[...text.matchAll(/\bcp(?:_[ab])?\(([^)]*)\)/g)].filter(m=>!m[1].includes('%')).map(m=>m[1]);
const amounts=value=>value.includes(':')?value.split(/[ ,]+/).map(pair=>pair.split(':').map(Number)):[[null,Number(value)]];
let values=0,times=0,nonCPFiles=0;
const rows=cp.expected(reference);
for(const row of rows){
 const native=row.before.toString('latin1'),text=fs.readFileSync(p.join(resource,row.file),'latin1');s.parse(text);
 {
  const a=args(native),b=args(text);assert.equal(a.length,b.length);
  for(let i=0;i<a.length;i++){
   const old=amounts(a[i]),next=amounts(b[i]);assert.equal(old.length,next.length);
   for(let j=0;j<old.length;j++){assert.equal(next[j][0],old[j][0],'CP timing changed');assert.equal(next[j][1],old[j][1]*2,'CP must be exactly x2');values++;if(old[j][0]!==null)times++;}
  }
  let i=0;const restored=text.replace(/\bcp(?:_[ab])?\(([^)]*)\)/g,(m,value)=>value.includes('%')?m:m.slice(0,m.indexOf('(')+1)+a[i++]+')');
  assert.equal(restored,native,'Other preset fields changed: '+row.file);nonCPFiles++;
 }
}
for(const level of ['low','standard','high','very_high'])assert(!fs.existsSync(p.join(resource,`set/dynamic_campaign/resources_${level}.set`)),'Conquest CP must stay on HF values: '+level);
console.log(JSON.stringify({...cp.verify(resource,reference),checkedCPAmounts:values,unchangedScheduleTimes:times,unrelatedPresetDataPreserved:nonCPFiles,conquestUsesHF:true,unitPricesUnchanged:true}));
