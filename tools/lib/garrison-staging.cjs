// Deployment selectors use forwardN; firing-position relocation must not move
// the spawn-point markers out of those selectors.
const assert=require('assert/strict'),s=require('./sdl.cjs');
const value=(n,key)=>s.child(n,key)?.tokens[1]?.value;
const position=n=>s.child(n,'position')||s.child(n,'Position');
const xyz=n=>position(n).tokens.slice(1).map(t=>Number(t.value));
function edits(text,changes){for(const e of changes.sort((a,b)=>b.start-a.start))text=text.slice(0,e.start)+e.text+text.slice(e.end);return text;}
function contains(zone,p,margin=0){
 const c=xyz(zone),type=zone.tokens[1].value;
 if(type==='circle')return Math.hypot(p[0]-c[0],p[1]-c[1])+margin<=Number(value(zone,'Radius')||value(zone,'radius'))+1e-8;
 assert.equal(type,'poly','Unsupported forward zone');
 const polygon=zone.children.filter(n=>s.name(n)==='Point').map(n=>[Number(n.tokens[1].value)+c[0],Number(n.tokens[2].value)+c[1]]);let inside=false;
 for(let i=0,j=polygon.length-1;i<polygon.length;j=i++){const a=polygon[i],b=polygon[j];
  const cross=(p[0]-a[0])*(b[1]-a[1])-(p[1]-a[1])*(b[0]-a[0]);
  if(Math.abs(cross)<1e-6&&p[0]>=Math.min(a[0],b[0])&&p[0]<=Math.max(a[0],b[0])&&p[1]>=Math.min(a[1],b[1])&&p[1]<=Math.max(a[1],b[1]))return margin===0;
  if((a[1]>p[1])!==(b[1]>p[1])&&p[0]<(b[0]-a[0])*(p[1]-a[1])/(b[1]-a[1])+a[0])inside=!inside;
 }
 if(!inside||margin===0)return inside;
 // A disc inside a concave polygon must clear every boundary segment.
 return polygon.every((a,i)=>{
  const b=polygon[(i+1)%polygon.length],dx=b[0]-a[0],dy=b[1]-a[1],length=dx*dx+dy*dy;
  const t=length?Math.max(0,Math.min(1,((p[0]-a[0])*dx+(p[1]-a[1])*dy)/length)):0;
  return Math.hypot(p[0]-a[0]-t*dx,p[1]-a[1]-t*dy)+1e-8>=margin;
 });
}
function zones(data){return new Map(data.script.children.filter(n=>s.name(n)==='zone'&&/^forward[1-5]$/.test(value(n,'Name'))).map(n=>[value(n,'Name'),n]));}
function nativeSpawnRouting(text){
 const changes=[];
 for(const owner of s.all(s.parse(text),n=>/^dcg2\/botdefend\/start[23]flags$/.test(s.name(n))))
  for(const n of s.all(owner,n=>s.name(n)==='switch')){
   const cases=n.children.filter(c=>s.name(c)==='case');
   if(cases.length!==4||!cases.every(c=>value(s.child(c,'condition'),'var')==='player_spawn_name$'))continue;
   const fallback=s.child(n,'default');assert.equal(fallback.children.length,1);const original=fallback.children[0];assert.equal(s.name(original),'placement');
   changes.push({start:n.start,end:n.end,text:text.slice(original.start,original.end)});
  }
 assert(changes.length>0,'No relocated spawn placements');return {text:edits(text,changes),count:changes.length};
}
// Preserve anchors only when their entire spawn radius fits the selector.
// Replacement authored positions retain an additional 300-unit spawn buffer.
function repairAddedAnchors(text,data){
 const forward=zones(data),changes=[],records=[];
 for(const [id,n]of data.points){const group=data.groups.get(id);if(!/^[ab]_def_spawns$/.test(group))continue;
  const flag=String(Number(id)-(group[0]==='a'?14:19)),zone=forward.get('forward'+flag);assert(zone);
  const radius=Number(value(n,'radius')||value(n,'Radius')||0);
  if(contains(zone,xyz(n),radius))continue;
  const candidates=[...data.points].filter(([other,p])=>data.groups.get(other).startsWith(group[0]+'_f'+flag+'_def_')&&xyz(p).length===3&&contains(zone,xyz(p),radius+300));
  const distance=p=>Math.hypot(xyz(p)[0]-xyz(n)[0],xyz(p)[1]-xyz(n)[1]);
  candidates.sort((a,b)=>distance(a[1])-distance(b[1])||a[0].localeCompare(b[0]));assert(candidates.length,'No authored staging position for '+id);
  const [chosen,node]=candidates[0],p=position(n);changes.push({start:p.start,end:p.end,text:'{position '+xyz(node).join(' ')+'}'});records.push({id,chosen,position:xyz(node)});
 }
 return {text:edits(text,changes),records};
}
function repairKarvolaZones(text,data){
 const changes=[];
 for(const [name,zone]of zones(data)){const flag=name.slice(-1),hub=data.points.get(flag),p=position(zone),f=data.flags[flag];
  assert.equal(zone.tokens[1].value,'circle');assert(hub&&f);const centre=[f[0],f[1],xyz(hub)[2]];
  changes.push({start:p.start,end:p.end,text:'{position '+centre.join(' ')+'}'});
 }
 assert.equal(changes.length,5);return edits(text,changes);
}
module.exports={contains,zones,xyz,position,nativeSpawnRouting,repairAddedAnchors,repairKarvolaZones};
