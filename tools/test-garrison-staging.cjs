// Regression: a spawn disc must fit inside its selector, not just its centre.
const fs=require('fs'),path=require('path'),assert=require('assert/strict');
const g=require('./garrison-layout.cjs'),s=require('./lib/sdl.cjs'),st=require('./lib/garrison-staging.cjs');
const node=text=>s.parse(text).children[0];
const circle=node('{zone "circle" {position 0 0 0}{Radius 1000}}');
assert(st.contains(circle,[800,0,0]));
assert(!st.contains(circle,[800,0,0],300),'Centre inside is insufficient for a spawn disc');
assert(st.contains(circle,[700,0,0],300),'Boundary contact must be allowed');
const poly=node('{zone "poly" {position 100 200 0}{Point 0 0}{Point 1000 0}{Point 1000 1000}{Point 0 1000}}');
assert(st.contains(poly,[200,700,0]));
assert(!st.contains(poly,[200,700,0],300));
assert(st.contains(poly,[400,700,0],300));
assert(st.contains(poly,[100,700,0]));
assert(!st.contains(poly,[100,700,0],1));
assert(!st.contains(poly,[0,700,0],1));
let maps=0,anchors=0,samples=0;
const root=path.join(g.resource,'map/multi');
for(const entry of fs.readdirSync(root,{withFileTypes:true}).filter(e=>e.isDirectory())){
 const folder=path.join(root,entry.name);if(!fs.existsSync(path.join(folder,'ufb_garrison_layout.inc')))continue;
 maps++;const file=path.join(folder,'campaign_capture_the_flag.mi'),text=fs.readFileSync(file,'latin1'),data=g.mapData(text),zones=st.zones(data);
 for(const [id,n]of data.points){
  const group=data.groups.get(id);if(!/^[ab]_def_spawns$/.test(group))continue;anchors++;
  const zone=zones.get('forward'+(Number(id)-(group[0]==='a'?14:19))),p=st.xyz(n),radius=Number(s.child(n,'radius')?.tokens[1]?.value||0);
  assert(st.contains(zone,p,radius),entry.name+' '+id+': spawn radius escapes selector');
  for(let i=0;i<64;i++){const angle=i*Math.PI/32; samples++;
   assert(st.contains(zone,[p[0]+radius*Math.cos(angle),p[1]+radius*Math.sin(angle),p[2]]),entry.name+' '+id+': spawn sample outside selector');
  }
 }
 assert.equal(st.repairAddedAnchors(text,data).text,text,'Repair must be idempotent: '+entry.name);
}
assert.equal(maps,117);assert.equal(anchors,1170);
console.log(JSON.stringify({maps,anchors,spawnBoundarySamples:samples,allSpawnDiscsContained:true}));
