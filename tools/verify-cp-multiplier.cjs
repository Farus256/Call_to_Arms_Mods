// Semantic regression proof: CP amounts double once, timings, prices and all other data survive.
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
 if(row.schedules){
  const a=args(native),b=args(text);assert.equal(a.length,b.length);
  for(let i=0;i<a.length;i++){
   const old=amounts(a[i]),next=amounts(b[i]);assert.equal(old.length,next.length);
   for(let j=0;j<old.length;j++){assert.equal(next[j][0],old[j][0],'CP timing changed');assert.equal(next[j][1],old[j][1]*2,'CP must be exactly x2');values++;if(old[j][0]!==null)times++;}
  }
  let i=0;const restored=text.replace(/\bcp(?:_[ab])?\(([^)]*)\)/g,(m,value)=>value.includes('%')?m:m.slice(0,m.indexOf('(')+1)+a[i++]+')');
  assert.equal(restored,native,'Other preset fields changed: '+row.file);nonCPFiles++;
 }else{
  const a=s.parse(native),b=s.parse(text);assert.equal(a.children.length,b.children.length);
  for(let i=0;i<a.children.length;i++){
   const old=a.children[i],next=b.children[i];
   for(const field of ['GlobalMaxCP','StageCP','SpecialCP','EmplacementCP']){
    const x=s.child(old,field),y=s.child(next,field);assert.deepEqual(y.tokens.slice(1).map(t=>Number(t.value)),x.tokens.slice(1).map(t=>Number(t.value)*2));
   }
   const oldBots=s.child(old,'Bots'),newBots=s.child(next,'Bots');
   const oldCP=s.child(oldBots,'CP'),newCP=s.child(newBots,'CP');
   assert.deepEqual(amounts(s.child(newCP,'Base').tokens[1].value),amounts(s.child(oldCP,'Base').tokens[1].value).map(([day,value])=>[day,value*2]));
   for(const field of ['RoundMultiplier','AttackMultiplier'])assert.deepEqual(shape(s.child(newCP,field)),shape(s.child(oldCP,field)),field+' would apply x2 twice');
   const oldBudget=s.child(s.child(old,'Resources'),'Budget'),newBudget=s.child(s.child(next,'Resources'),'Budget');
   assert.deepEqual(amounts(s.child(newBudget,'Start').tokens[1].value),amounts(s.child(oldBudget,'Start').tokens[1].value).map(([day,value])=>[day,value*2]));
   for(const field of ['Limit','PointsPerSecond'])assert.equal(Number(s.child(newBudget,field).tokens[1].value),Number(s.child(oldBudget,field).tokens[1].value)*2);
   // Remove only the reviewed CP amounts, then compare every remaining native setting.
   function rest(n,path=[]){
    const nextPath=[...path,s.name(n)];
    const skip=nextPath.length===3&&['GlobalMaxCP','StageCP','SpecialCP','EmplacementCP'].includes(s.name(n))||nextPath.slice(-3).join('/')==='Bots/CP/Base'||nextPath.slice(-3,-1).join('/')==='Resources/Budget'&&['Start','Limit','PointsPerSecond'].includes(s.name(n));
    if(skip)return null;
    return {kind:n.kind,tokens:n.tokens.map(t=>t.value),children:n.children.map(c=>rest(c,nextPath)).filter(Boolean)};
   }
   assert.deepEqual(rest(a),rest(b),'Non-CP campaign economy changed: '+row.file);
  }
 }
}
console.log(JSON.stringify({...cp.verify(resource,reference),checkedCPAmounts:values,unchangedScheduleTimes:times,unrelatedPresetDataPreserved:nonCPFiles,campaignDifficultyFactorsPreserved:true,unitPricesUnchanged:true}));
