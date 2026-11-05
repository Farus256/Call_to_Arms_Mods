// Reviewed, per-weapon overrides. Native presets, damage and firing ranges stay intact.
const fs=require('fs'),p=require('path'),assert=require('assert/strict'),s=require('./lib/sdl.cjs');
const repo=p.resolve(__dirname,'..'),reference=p.resolve(repo,'../_survival_work/hf-update-20261105/reference/resource');
const guns=['107mm_m1910','107mm_m1910_30','28mm_pzb41','77mm_qf_hv','85mm_zis53','88mm_rw43'];
const launchers={faustpatrone_30:{range:30,penetration:140},panzerfaust_30:{range:30,penetration:200},panzerfaust_30_fin:{range:30,penetration:200},panzerfaust_100:{range:50,penetration:200},recoilless_m18:{range:90,penetration:80}};
const number=v=>Number(v.toFixed(8)).toString();
function gun(text){
 const tree=s.parse(text),edits=[];
 for(const n of s.all(tree,n=>n.kind==='('&&/^penetration_(?:long|medium)$/.test(s.name(n)||''))){
  const args=Object.fromEntries(n.tokens.slice(1).map((t,i)=>[t.value,n.children[i]?.tokens[0]?.value]));
  const range=Number(args.range);if(!range)continue;
  const bound=s.name(n)==='penetration_long'?205:155;if(range>bound)continue;
  const a=Number(args.a),b=Number(args.b),c=Number(args.c),d=Number(args.d),e=Number(args.e);
  const anchors=[[10,a+1.3+(a-b)/4.4],[30,a],[100,b],[155,c],[205,d],[250,e]];
  const left=anchors.findLastIndex(([x])=>x<=range);assert(left>=0&&left<anchors.length-1);
  const end=range===anchors[left][0]?anchors[left][1]:anchors[left][1]+(anchors[left+1][1]-anchors[left][1])*(range-anchors[left][0])/(anchors[left+1][0]-anchors[left][0]);
  const points=[...anchors.filter(([x])=>x<range),[range,end],[range+15,0]];
  assert(points.every((v,i)=>i===0||v[0]>points[i-1][0]));
  edits.push({start:n.start,end:n.end,text:`{parameters "${args.shell}"\n\t\t{projectileDamageTable ${points.map(([x,y])=>`{${x} ${number(y)}}`).join(' ')}}\n\t\t{range ${range} ${range}}\n\t}`});
 }
 for(const e of edits.sort((a,b)=>b.start-a.start))text=text.slice(0,e.start)+e.text+text.slice(e.end);
 return {text,curves:edits.length};
}
function launcher(text,policy){const tree=s.parse(text),nodes=s.all(tree,n=>s.name(n)==='projectileDamageTable');assert.equal(nodes.length,1);const n=nodes[0],{range,penetration}=policy;return text.slice(0,n.start)+`{projectileDamageTable {0 ${penetration}} {${range} ${number(penetration*0.8)}} {${range*5} 0}}`+text.slice(n.end);}
function expected(ref=reference){
 const files=[],read=f=>fs.readFileSync(p.join(ref,f),'latin1');
 const malformed='set/stuff/gun/105mm_m10525',bad=read(malformed),at=bad.lastIndexOf('\t)');assert(at>=0);const repaired=bad.slice(0,at)+bad.slice(at+2);s.parse(repaired);files.push({file:malformed,text:repaired});
 let curves=0;
 for(const name of guns){const file='set/stuff/gun/'+name,result=gun(read(file));assert(result.curves>0);curves+=result.curves;files.push({file,text:result.text});}assert.equal(curves,9);
 for(const [name,policy]of Object.entries(launchers)){const file='set/stuff/bazooka/'+name+'.weapon';files.push({file,text:launcher(read(file),policy)});}
 return files;
}
function verify(root=p.join(repo,'mods/ultimate_frontline_bundle/resource'),ref=reference){for(const e of expected(ref)){const text=fs.readFileSync(p.join(root,e.file),'latin1');assert.equal(text,e.text,e.file);s.parse(text);}return {gunSyntaxFixed:true,correctedGunCurves:9,correctedGunFiles:6,smoothedOtherATWeapons:5,nativeWeaponFieldsOutsideReviewedCurves:true};}
if(require.main===module){if(process.argv.includes('--build'))for(const e of expected()){const f=p.join(repo,'mods/ultimate_frontline_bundle/resource',e.file);fs.mkdirSync(p.dirname(f),{recursive:true});fs.writeFileSync(f,e.text,'latin1');}console.log(JSON.stringify(verify()));}
module.exports={gun,launcher,expected,verify,guns,launchers};
