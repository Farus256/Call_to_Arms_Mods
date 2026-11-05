// Mission-local waypoint registry, including SDL files inserted into waypoint groups.
// GoH 1.067.0 initializes its numeric waypoint allocator with 0x2000 slots.
const fs=require('fs'),path=require('path'),assert=require('assert/strict'),s=require('./sdl.cjs');
const numericCapacity=8192;
const isPoint=n=>s.child(n,'position')||s.child(n,'Position');
function checkID(id){
 if(/^\d+$/.test(id))assert(Number(id)<numericCapacity,'Numeric waypoint ID outside engine pool (0..8191): '+id);
}
function collect(file,resource){
 const root=path.resolve(resource),points=new Map();
 const mission=s.parse(fs.readFileSync(file,'latin1')).children[0];
 const script=mission.children.find(n=>s.child(n,'functions'));assert(script,'Missing mission script: '+file);
 function visit(nodes,owner,stack){
  for(const n of nodes){
   if(n.kind==='('&&s.name(n)==='include'){
    const ref=n.tokens[1]?.value;assert(ref,'Empty waypoint include');
    const next=path.resolve(ref.startsWith('/')?root:path.dirname(owner),ref.replace(/^\//,''));
    assert(next.startsWith(root+path.sep),'Waypoint include outside resource: '+ref);
    assert(!stack.includes(next),'Recursive waypoint include: '+next);
    visit(s.parse(fs.readFileSync(next,'latin1')).children,next,[...stack,next]);
   }else if(isPoint(n)){
    const id=s.name(n);checkID(id);
    assert(!points.has(id),'Duplicate waypoint '+id+' in '+owner+' and '+points.get(id)?.file);
    points.set(id,{node:n,file:owner});
   }
  }
 }
 for(const group of script.children.filter(n=>s.name(n)==='waypoints'))visit(group.children,path.resolve(file),[path.resolve(file)]);
 return points;
}
module.exports={collect,checkID,numericCapacity};
