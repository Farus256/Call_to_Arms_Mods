// Map-local wreck metadata: live vehicle definitions and models stay native.
const fs=require('fs'),p=require('path'),cp=require('child_process'),assert=require('assert/strict'),s=require('./lib/sdl.cjs');
const resource=p.resolve(__dirname,'../mods/ultimate_frontline_bundle/resource'),file='map/multi/dcg_rasputitsa/map';
const wrecks=new Map([['10001','panzer3f'],['10002','panzer3e'],['10004','stug3b']]);
function nativeDefinition(file){
 const game='D:/Programs/Steam/steamapps/common/Call to Arms - Gates of Hell/resource/entity/-vehicle.pak';
 const hf=p.resolve(__dirname,'../../3359417100/resource/entity/-vehicle.pak');
 const loose=p.resolve(__dirname,'../../3359417100/resource',file);
 if(fs.existsSync(loose))return fs.readFileSync(loose,'latin1');
 const script='import sys,zipfile; entry=sys.argv[3]; a=zipfile.ZipFile(sys.argv[1]); b=zipfile.ZipFile(sys.argv[2]); sys.stdout.buffer.write((b if entry in b.namelist() else a).read(entry))';
 return cp.execFileSync('py',['-3.12','-c',script,game,hf,file.slice(7)],{windowsHide:true,maxBuffer:1024*1024}).toString('latin1');
}
const definition=model=>`entity/-vehicle/germany/tank_medium/${model}/${model}.def`;
const wreckName=model=>'ufb_wreck_'+model;
function definitions(){return [...wrecks.values()].map(model=>{
 const file=definition(model),original=nativeDefinition(file),tree=s.parse(original);
 const nodes=s.all(tree,n=>s.name(n)==='extender'&&n.tokens[1]?.value==='enumerator');assert.equal(nodes.length,1);
 const n=nodes[0],text=original.slice(0,n.start)+original.slice(n.end);
 return {file:p.posix.join(p.posix.dirname(file),wreckName(model)+'.def'),text};
});}
const value=(n,k)=>s.child(n,k)?.tokens[1]?.value;
function repair(text){
 const tree=s.parse(text),edits=[];let matched=0;
 for(const n of s.all(tree,n=>s.name(n)==='Entity'&&wrecks.has(value(n,'MID')))){
  const model=wrecks.get(value(n,'MID'));assert([model,wreckName(model)].includes(n.tokens[1]?.value));
  if(n.tokens[1].value===model)edits.push({start:n.tokens[1].start,end:n.tokens[1].end,text:JSON.stringify(wreckName(model))});
  assert.equal(value(n,'SkeletonSrc'),model+'_xx','Wreck skeleton changed');
  assert(s.child(s.child(n,'Chassis'),'Broken'),'Not a wreck');
  const body=n.children.find(c=>s.name(c)==='Component'&&c.tokens[1]?.value==='body');assert.equal(value(body,'State'),'destroyed');assert.equal(value(body,'Health'),'0');
  const ext=n.children.filter(c=>s.name(c)==='Extender'&&c.tokens[1]?.value==='enumerator');assert(ext.length<=1);
  for(const e of ext){assert.deepEqual(e.children.map(s.name),['number','digit_folder']);edits.push({start:e.start,end:e.end,text:''});}
  matched++;
 }
 assert.equal(matched,3,'Unexpected Rasputitsa wreck roster');
 for(const e of edits.sort((a,b)=>b.start-a.start))text=text.slice(0,e.start)+e.text+text.slice(e.end);
 s.parse(text);return text;
}
function baseline(){
 const pak='D:/Programs/Steam/steamapps/common/Call to Arms - Gates of Hell/resource/map/multi.pak';
 return cp.execFileSync('py',['-3.12','-c','import sys,zipfile;sys.stdout.buffer.write(zipfile.ZipFile(sys.argv[1]).read(sys.argv[2]))',pak,'multi/dcg_rasputitsa/map'],{windowsHide:true,maxBuffer:4*1024*1024}).toString('latin1');
}
function verify(root=resource){const original=baseline(),actual=fs.readFileSync(p.join(root,file),'latin1');assert.equal(actual,repair(original),'Unexpected Rasputitsa map changes');assert.equal(repair(actual),actual);for(const e of definitions())assert.equal(fs.readFileSync(p.join(root,e.file),'latin1'),e.text);return {wreckDefinitionsWithoutEnumerator:3,savedWreckEnumeratorBlocksRemoved:3,nativeEnumeratorAbsenceVerified:false,mapPositionsAndCombatVehiclesPreserved:true};}
function build(root=resource){for(const e of definitions()){const f=p.join(root,e.file);fs.mkdirSync(p.dirname(f),{recursive:true});fs.writeFileSync(f,e.text,'latin1');}const dest=p.join(root,file);fs.mkdirSync(p.dirname(dest),{recursive:true});fs.writeFileSync(dest,repair(baseline()),'latin1');}
if(require.main===module){if(process.argv.includes('--build'))build();console.log(JSON.stringify(verify()));}
module.exports={repair,build,verify,baseline,file,wrecks,definitions,wreckName,nativeDefinition};
