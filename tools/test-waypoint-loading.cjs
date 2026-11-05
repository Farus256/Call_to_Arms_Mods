const fs=require('fs'),path=require('path'),assert=require('assert/strict');
const s=require('./lib/sdl.cjs'),wp=require('./lib/gem-waypoints.cjs'),g=require('./garrison-layout.cjs');
const resource=path.resolve(process.argv[2]||g.resource),multi=path.join(resource,'map/multi');
assert.throws(()=>wp.checkID('11021'),/outside engine pool/,'Regression: crash ID must be rejected before installation');
wp.checkID('8191');assert.throws(()=>wp.checkID('8192'),/outside engine pool/);
const refs=n=>s.all(n,c=>['transition','waypoint','target_waypoint'].includes(s.name(c))&&c.tokens.length===2).map(c=>c.tokens[1].value);
const shared=['ufb_garrison_functions.inc','ufb_garrison_script.inc'].flatMap(f=>refs(s.parse(fs.readFileSync(path.join(multi,f),'latin1'))));
let maps=0,total=0,max=0;
for(const entry of fs.readdirSync(multi,{withFileTypes:true}).filter(e=>e.isDirectory())){
 const dir=path.join(multi,entry.name);if(!fs.existsSync(path.join(dir,'ufb_garrison_layout.inc')))continue;
 const points=wp.collect(path.join(dir,'campaign_capture_the_flag.mi'),resource);maps++;total+=points.size;
 for(const id of points.keys())if(/^\d+$/.test(id))max=Math.max(max,Number(id));
 const generated=s.parse(fs.readFileSync(path.join(dir,'ufb_garrison_layout.inc'),'latin1'));
 for(const id of [...shared,...refs(generated)])assert(points.has(id),'Dangling garrison reference '+entry.name+' '+id);
 for(const n of generated.children)for(const id of refs(n))assert.equal(g.aliasParts(id).spawn,g.aliasParts(s.name(n)).spawn,'Chain crosses player entrances');
}
assert.equal(maps,117);
console.log(JSON.stringify({maps,waypointsIncludingHF:total,maxNumericID:max,numericCapacity:wp.numericCapacity,uniqueIDs:true,allGarrisonReferencesResolved:true}));
