// Rebalance the new movement recordings without changing AI hearing signals,
// distance curves, weapon levels, or the shared sound/defines.inc presets.
const assert=require('assert/strict'),s=require('./lib/sdl.cjs');
const presets={
 vehicle_engine:[0.40,0.35],vehicle_engine_idle:[0.30,0.45],
 vehicle_engine_small:[0.30,0.35],vehicle_engine_small_idle:[0.25,0.45],
 vehicle_engine_car:[0.50,0.35],vehicle_engine_car_idle:[0.35,0.45],
 vehicle_tracks:[0.80,0.30],vehicle_overlays:[0.50,0.40],
 // The source mod uses this preset in tracks/overlay/folder.set only.
 vehicle_wheels:[0.50,0.40]
};
function tune(file,text){
 if(!/^sound\/vehicle\/(engine|tracks)\/(?:[^/]+\/)*folder\.set$/.test(file))return {text};
 const tree=s.parse(text),sound=tree.children.find(n=>s.name(n)==='sound');assert(sound,file);
 const calls=sound.children.filter(n=>n.kind==='('&&s.name(n)!=='include');assert.equal(calls.length,1,file);
 const preset=s.name(calls[0]),values=presets[preset];assert(values,'Unreviewed movement sound preset: '+preset);
 const volumes=sound.children.filter(n=>s.name(n)?.toLowerCase()==='volume');assert(volumes.length<=1,file);
 const before=volumes[0]?Number(volumes[0].tokens[1].value):values[0];assert(before>0,file);
 const after=Number((before*values[1]).toFixed(6)),node=volumes[0];
 const change=node?{start:node.start,end:node.end,text:`{volume ${after}}`}:{start:sound.end-1,end:sound.end-1,text:`\n; UFB: movement recordings below cannon transients; native hearing and attenuation retained.\n{volume ${after}}\n`};
 const result=text.slice(0,change.start)+change.text+text.slice(change.end);
 const strip=t=>{const ast=s.parse(t);for(const n of ast.children)n.children=n.children.filter(c=>s.name(c)?.toLowerCase()!=='volume');return JSON.stringify(ast.children.map(shape));};
 assert.equal(strip(text),strip(result),file+' non-volume change');
 return {text:result,audit:{file,preset,before,after,gainDB:20*Math.log10(values[1])}};
}
const shape=n=>[n.kind,n.tokens.map(t=>t.value),n.children.map(shape)];
module.exports={tune,presets};
