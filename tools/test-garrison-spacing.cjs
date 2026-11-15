const a=require('assert/strict'),fs=require('fs'),p=require('path'),s=require('./lib/sdl.cjs'),g=require('./garrison-layout.cjs');
const candidate=(id,x,y=0)=>({id,point:[x*20,y*20,17]});
const entry=[0,0,0],objective=[0,0,0];
// The old finite penalty collapses different firing slots onto the one range-safe point.
const candidates=[candidate('1',100),candidate('2',80),candidate('3',60)];
const usage=new Map(),oldA=g.choose([0,0,17],candidates,entry,90,objective,usage,false),oldB=g.choose([1,0,17],candidates,entry,90,objective,usage,false);
a.deepEqual(oldA.point,oldB.point);
const used=[],newA=g.chooseVehicle([0,0,17],candidates,entry,90,objective,used),newB=g.chooseVehicle([1,0,17],candidates,entry,90,objective,used);
a.notDeepEqual(newA.point,newB.point);a.equal(newB.safe,false,'Report the conflicting range requirement');a(g.distance(newA.point,newB.point)>=20);
// Even a range-safe original occupies a slot and must be reserved.
const kept=[];g.chooseVehicle(candidates[0].point,candidates,entry,1,objective,kept);
const next=g.chooseVehicle(candidates[0].point,candidates,entry,1,objective,kept);a.notDeepEqual(next.point,candidates[0].point);
// Duplicate authored IDs are not distinct physical places; a hub is a last fallback.
const dup=[candidate('1',100),candidate('2',100),{...candidate('hub',150),hub:true}];
const filled=[];g.chooseVehicle(dup[0].point,dup,entry,1,objective,filled);const fallback=g.chooseVehicle(dup[1].point,dup,entry,1,objective,filled);a.equal(fallback.point[0],3000);a(fallback.unique);
const exhausted=g.chooseVehicle(dup[0].point,dup,entry,1,objective,filled);a.equal(exhausted.unique,false);a.equal(exhausted.spacingSafe,false);
let maps=0,slots=0,closePairs=0,min=Infinity;
const position=n=>(s.child(n,'position')||s.child(n,'Position'))?.tokens.slice(1).map(t=>Number(t.value));
for(const e of fs.readdirSync(p.join(g.resource,'map/multi'),{withFileTypes:true}).filter(e=>e.isDirectory())){
 const dir=p.join(g.resource,'map/multi',e.name),file=p.join(dir,'ufb_garrison_layout.inc');if(!fs.existsSync(file))continue;maps++;
 const data=g.mapData(fs.readFileSync(p.join(dir,'campaign_capture_the_flag.mi'),'latin1')),variants=Array.from({length:8},()=>[]);
 for(const n of s.parse(fs.readFileSync(file,'latin1')).children){const alias=g.aliasParts(s.name(n));if(!alias)continue;
  const orig=data.points.get(alias.id);a(orig);const group=data.groups.get(alias.id);if(!group.endsWith('_def_vehicle'))continue;
  const refs=s.all(orig,c=>['transition','waypoint','target_waypoint'].includes(s.name(c))&&c.tokens.length===2);
  if(!Number(s.child(orig,'RandomPosition')?.tokens[1]?.value||0)&&refs.length)continue;
  const point=position(n);slots++;
  a([...data.points].some(([id,c])=>data.groups.get(id).startsWith(group[0]+'_')&&data.groups.get(id).endsWith('_def_vehicle')&&JSON.stringify(position(c))===JSON.stringify(point)),'Invented terrain/height '+e.name+' '+alias.id);
  variants[alias.spawn-1].push(point);
 }
 for(const v of variants)for(let i=0;i<v.length;i++)for(let j=0;j<i;j++){const d=g.distance(v[i],v[j]);min=Math.min(min,d);if(d<20)closePairs++;a(d>0.5,'Duplicate firing coordinates: '+e.name);}
}
a.equal(maps,117);
console.log(JSON.stringify({maps,slots,minimumAuthoredSlotDistanceMetres:min,pairsBelowRequested20m:closePairs,noDuplicateFiringCoordinates:true,actualUnitsAndNativeScatterTested:false}));
