const fs=require('fs'),p=require('path'),assert=require('assert/strict'),s=require('./lib/sdl.cjs');
const repo=p.resolve(__dirname,'..'),root=p.resolve(process.argv[2]||p.join(repo,'mods/ultimate_frontline_bundle/resource')),reference=p.resolve(repo,'../_survival_work/hf-update-20261105/reference/resource');
const shape=n=>({kind:n.kind,tokens:n.tokens.map(t=>t.value),children:n.children.map(shape)}),read=(base,f)=>fs.readFileSync(p.join(base,f),'latin1');
const values=n=>n.children.map(c=>c.tokens.map(t=>Number(t.value)));
const cases={'107mm_m1910':{apcbche:[190,97.4]},'107mm_m1910_30':{apcbche:[200,95.8]},'28mm_pzb41':{apcr:[150,44.18181818]},'77mm_qf_hv':{apcbc:[200,118.1],apds:[200,162]},'85mm_zis53':{aphe:[200,93.5],aphebc:[200,96.9],apcr:[200,75.7]},'88mm_rw43':{heat:[120,185]}};
let checks=0,curves=0;
for(const [name,types]of Object.entries(cases)){
 const file='set/stuff/gun/'+name,tree=s.parse(read(root,file)),native=s.parse(read(reference,file));
 for(const [shell,[range,end]]of Object.entries(types)){
  const owner=s.all(tree,n=>s.name(n)==='parameters'&&n.tokens[1]?.value===shell&&s.child(n,'projectileDamageTable'))[0];assert(owner,name+' '+shell);const points=values(s.child(owner,'projectileDamageTable'));
  assert(points.every((v,i)=>v.every(Number.isFinite)&&v[1]>=0&&(i===0||v[0]>points[i-1][0]&&v[1]<=points[i-1][1])));checks++;
  assert.equal(points.at(-2)[0],range);assert(Math.abs(points.at(-2)[1]-end)<1e-7);assert.deepEqual(points.at(-1),[range+15,0]);checks++;
  assert.deepEqual(s.child(owner,'range').tokens.slice(1).map(t=>Number(t.value)),[range,range]);checks++;
  const old=s.all(native,n=>n.kind==='('&&/^penetration_(long|medium)$/.test(s.name(n)||'')&&n.children[n.tokens.findIndex(t=>t.value==='shell')-1]?.tokens[0]?.value===shell)[0];assert(old);
  const parent=s.all(tree,n=>n.children.includes(owner))[0]||tree;parent.children[parent.children.indexOf(owner)]=old;curves++;
 }
 assert.deepEqual(shape(tree),shape(native),'Unrelated weapon fields changed: '+name);checks++;
}
const other={faustpatrone_30:[30,140,112],panzerfaust_30:[30,200,160],panzerfaust_30_fin:[30,200,160],panzerfaust_100:[50,200,160],recoilless_m18:[90,80,64]};
for(const [name,[range,start,end]]of Object.entries(other)){
 const file='set/stuff/bazooka/'+name+'.weapon',tree=s.parse(read(root,file)),native=s.parse(read(reference,file)),table=s.all(tree,n=>s.name(n)==='projectileDamageTable')[0],old=s.all(native,n=>s.name(n)==='projectileDamageTable')[0];
 assert.deepEqual(values(table),[[0,start],[range,end],[range*5,0]]);checks++;
 table.children=old.children;assert.deepEqual(shape(tree),shape(native),'Launcher range, damage or other fields changed: '+name);checks++;
}
const bad=read(reference,'set/stuff/gun/105mm_m10525'),fixed=read(root,'set/stuff/gun/105mm_m10525'),at=bad.lastIndexOf('\t)');assert.equal(fixed,bad.slice(0,at)+bad.slice(at+2));s.parse(fixed);checks++;
const walk=d=>fs.readdirSync(d,{withFileTypes:true}).flatMap(e=>e.isDirectory()?walk(p.join(d,e.name)):[p.join(d,e.name)]);let parsed=0;
for(const f of walk(p.join(reference,'set/stuff')).filter(f=>!f.endsWith('.fsm'))){const rel=p.relative(reference,f),local=p.join(root,rel);s.parse(fs.readFileSync(fs.existsSync(local)?local:f,'latin1'));parsed++;}
console.log(JSON.stringify({checks,gunCurves:curves,otherATCurves:5,weaponAndItemFilesParsed:parsed,unrelatedWeaponDataPreserved:true,gemBattleTested:false}));
