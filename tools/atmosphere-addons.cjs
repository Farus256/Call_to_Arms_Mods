// Build a private compatibility layer from subscribed Workshop sources.
// Large third-party assets stay outside Git. No Workshop source is modified.
const fs=require('fs'),p=require('path'),assert=require('assert/strict'),crypto=require('crypto'),s=require('./lib/sdl.cjs');
const repo=p.resolve(__dirname,'..'),root=p.dirname(repo);
const work=p.join(root,'_ai_work/workshop-atmosphere-20261107');
const ref=p.join(root,'_survival_work/hf-update-20261107/reference/resource');
const ufb=p.join(repo,'mods/ultimate_frontline_bundle/resource');
const output=p.join(work,'package/ufb_atmosphere');
const read=f=>fs.readFileSync(f,'latin1'),sha=t=>crypto.createHash('sha256').update(t).digest('hex');
const shape=n=>[n.kind,n.tokens.map(t=>t.value),n.children.map(shape)];
const same=(a,b)=>JSON.stringify(shape(a))===JSON.stringify(shape(b));
const sources=[3805812451,3341685402,2894538979,3661578543,3514735223,3825215999,3438057060,3350281452];
// Remove the old Idle port's overrides so WAVE, HF and the game provide these files again.
const retiredIdleFiles=['properties/human.ext','properties/ufb_idle.ext','set/interaction_entity/human_idle.inc','set/interaction_entity/ufb_idle_passenger.inc'];
const list=id=>JSON.parse(fs.readFileSync(p.join(work,'extracted',String(id),'files.json'),'utf8'));
const source=(id,file)=>read(p.join(work,'extracted',String(id),'resource',file));
const current=file=>read(fs.existsSync(p.join(ufb,file))?p.join(ufb,file):p.join(ref,file));
const edits=(text,changes)=>{for(const e of changes.sort((a,b)=>b.start-a.start))text=text.slice(0,e.start)+e.text+text.slice(e.end);return text;};
function expected(){
 const texts=new Map(),assets=[],audit={sources,breeds:0,windPresets:0,particleFiles:0,ufbOverridesRetained:[],excludedOldFiles:[],checks:0,movementSoundGains:[]};
 const put=(f,t)=>{s.parse(t);texts.set(f,t);};
 // The crater meshes, vehicle sounds, OST and captured textures have no unit AI overrides.
 for(const id of [3805812451,3341685402,2894538979,3438057060])for(const f of list(id)){
  if(/\.(txt|bak|bat)$/i.test(f.file))continue;
  if(f.textSHA256){
   const original=source(id,f.file),audio=id===3341685402?require('./atmosphere-audio.cjs').tune(f.file,original):{text:original};
   if(id===3805812451&&f.file==='properties/crater_bush.inc'){
    const materials=s.parse(current('set/material.set'));assert(s.all(materials,n=>s.name(n)==='ground').length,'Native ground material missing');
    assert(!s.all(s.parse(original),n=>s.name(n)==='volume'&&n.tokens[1]?.value==='defaultmaterial').length);
    // These are ground/camouflage volumes. Their original bullet/contact/obstacle
    // flags and the downloaded geometry stay unchanged; only missing material is supplied.
    audio.text+='\n; UFB: initialize the physical material for crater volumes.\n{volume defaultmaterial "ground"}\n';
    const checked=s.parse(audio.text);checked.children=checked.children.filter(n=>!(s.name(n)==='volume'&&n.tokens[1]?.value==='defaultmaterial'));
    assert(same(checked,s.parse(original)));audit.craterVolumeMaterial='ground';
   }
   put(f.file,audio.text);if(audio.audit)audit.movementSoundGains.push(audio.audit);
  }else assets.push({id,...f});
 }
 const trench='properties/trench.inc',trenchBase=current(trench),trenchTree=s.parse(trenchBase);
 const remove=s.all(trenchTree,n=>s.name(n)==='RemoveEntities');assert.equal(remove.length,1);
 put(trench,edits(trenchBase,[{...remove[0],text:'; UFB: retain bushes while digging.'}]));
 // Keep current HF inventories, protection, perks, economy and visual skins byte-for-byte.
 for(const f of list(3514735223).filter(f=>f.file.startsWith('set/breed/')&&fs.existsSync(p.join(ref,f.file)))){
  const mod=s.parse(source(3514735223,f.file)).children[0],voice=s.child(mod,'voice');if(!voice)continue;
  const base=current(f.file),tree=s.parse(base).children[0],national=s.child(tree,'nationality');
  if(!national||s.child(mod,'nationality')?.tokens[1]?.value!==national.tokens[1]?.value)continue;
  const old=s.child(tree,'voice'),t=old?edits(base,[{...old,text:source(3514735223,f.file).slice(voice.start,voice.end)}]):edits(base,[{start:national.end,end:national.end,text:' '+source(3514735223,f.file).slice(voice.start,voice.end)}]);
  const before=s.parse(base).children[0],after=s.parse(t).children[0];
  before.children=before.children.filter(n=>s.name(n)!=='voice');after.children=after.children.filter(n=>s.name(n)!=='voice');assert(same(before,after),f.file);
  put(f.file,t);audit.breeds++;audit.checks++;
 }
 // Only voice definitions change. Event conditions and UFB aircraft filters stay in charge.
 const talk=current('set/talk.set'),talkTree=s.parse(talk),groups=new Set(['phrases','phrases_cannon','phrases_tank']);
 const oldGroups=s.all(talkTree,n=>s.name(n)==='define'&&groups.has(n.tokens[1]?.value));assert.equal(oldGroups.length,3);
 const tables=['talk_define_target.inc','talk_define_va.inc','talk_define_deal.inc','talk_type_human.inc','talk_type_cannon.inc','talk_type_tank.inc'];
 const replacement=tables.map(f=>`(include "${f}")`).join('\n');
 const mergedTalk=edits(talk,oldGroups.map((n,i)=>({...n,text:i===0?replacement:''})));
 const paths=[...JSON.parse(fs.readFileSync(p.join(work,'base-paths.json'),'utf8')),...list(3514735223).map(f=>f.file)];
 const voices=require('./atmosphere-voices.cjs').compile({talk:mergedTalk,tables:tables.map(f=>source(3514735223,'set/'+f)),events:Object.fromEntries(['human','tank','cannon'].map(actor=>[actor,current('set/talk/voicelines_'+actor+'.inc')])),paths});
 put('set/talk.set',voices.text);audit.voiceCoverage=voices.report;
 for(const f of tables)put('set/'+f,source(3514735223,'set/'+f));
 audit.voiceSoundCategoriesFixed=0;
 for(const f of list(3514735223).filter(f=>f.file.startsWith('sound/talk/'))){if(f.textSHA256){
  const base=source(3514735223,f.file),bad=s.all(s.parse(base),n=>(s.name(n)==='loudness'&&n.tokens[1]?.value==='vehicle_engine')||(s.name(n)==='tag'&&n.tokens[1]?.value==='environment'));
  // Child folders inherit the game's sound/talk/folder.set (the native talk preset).
  assert(f.file!=='sound/talk/folder.set','Root talk preset needs a reviewed merge');
  put(f.file,edits(base,bad.map(n=>({...n,text:''}))));if(bad.length)audit.voiceSoundCategoriesFixed++;
 }else assets.push({id:3514735223,...f});}
 // Merge only wind and wave wind speed into HF's current environmental presets.
 for(const f of list(3825215999).filter(f=>f.file.startsWith('set/environment/'))){
  assert(fs.existsSync(p.join(ref,f.file)),f.file);
  const base=current(f.file),mod=source(3825215999,f.file),a=s.parse(base),b=s.parse(mod),changes=[];
  const aw=s.all(a,n=>s.name(n)==='wind'),bw=s.all(b,n=>s.name(n)==='wind');assert.equal(aw.length,1);assert.equal(bw.length,1);
  changes.push({...aw[0],text:mod.slice(bw[0].start,bw[0].end)});
  const av=s.all(a,n=>s.name(n)==='wind_speed_mps'),bv=s.all(b,n=>s.name(n)==='wind_speed_mps');assert.equal(av.length,bv.length);
  av.forEach((n,i)=>changes.push({...n,text:mod.slice(bv[i].start,bv[i].end)}));
  const t=edits(base,changes),strip=n=>{n.children=n.children.filter(n=>!['wind','wind_speed_mps'].includes(s.name(n)));n.children.forEach(strip);return n;};
  assert(same(strip(s.parse(base)),strip(s.parse(t))),f.file);put(f.file,t);audit.windPresets++;audit.checks++;
 }
 // Particle definitions affect rendering only; keep all previously tuned UFB smoke/blood effects.
 for(const f of list(3825215999).filter(f=>f.file.startsWith('entity/fx/'))){
  if(fs.existsSync(p.join(ufb,f.file))){audit.ufbOverridesRetained.push(f.file);continue;}
  put(f.file,source(3825215999,f.file));audit.particleFiles++;
 }
 const dogs='set/interaction_entity/dogs.inc',dogSource=source(3825215999,dogs),engine=s.parse(dogSource).children.find(n=>s.name(n)==='engine');assert(engine);
 put(dogs,current(dogs)+'\n; Enhanced Wind & Smoke: wreck plume only.\n'+dogSource.slice(engine.start,engine.end)+'\n');
 const passenger=require('./atmosphere-passenger-idle.cjs').expected({source,current});
 for(const [file,text]of Object.entries(passenger.texts))put(file,text);
 for(const file of list(3350281452).filter(f=>passenger.assets.includes(f.file)))assets.push({id:3350281452,...file});
 assert.equal(assets.filter(f=>f.id===3350281452).length,1);audit.passengerIdle=passenger.report;
 audit.excludedOldFiles=['Idle Animations: all foot and full-body clips; WAVE/HF/native poses retained','Voices: full breed inventories, source event conditions, UI portraits, rename.bat','Wind: replacement dog AI'];
 for(const [file,text] of texts){assert(!file.includes('..'));if(fs.existsSync(p.join(ufb,file)))assert.equal(text,read(p.join(ufb,file)),'UFB would override companion: '+file);}
 return {texts,assets,audit};
}
function build(){const e=expected();fs.mkdirSync(output,{recursive:true});
 for(const file of retiredIdleFiles){assert(!e.texts.has(file));const dest=p.join(output,'resource',file);if(fs.existsSync(dest))fs.unlinkSync(dest);}
 for(const [file,text] of e.texts){const dest=p.join(output,'resource',file);fs.mkdirSync(p.dirname(dest),{recursive:true});fs.writeFileSync(dest,text,'latin1');}
 fs.writeFileSync(p.join(output,'mod.info'),'{mod\n {name "UFB Atmosphere - HF 4 compatibility"}\n {desc "Private compatibility build: crater cover, engine/tracks audio, Red Orchestra OST, bushes, expanded voices, wind/smoke, captured textures and one passenger head idle clip. WAVE/HF/native foot and crew poses retained. Load after HF/WAVE/Colditz, BEFORE ultimate_frontline_bundle. Original authors retain their assets. Do not enable original eight mods alongside this layer."}\n {minGameVersion "1.066"}\n {maxGameVersion "1.068"}\n {require "mod_3359417100"}\n}\n');
 fs.writeFileSync(p.join(work,'assets-plan.json'),JSON.stringify(e.assets,null,2));
 const manifest=[...e.texts].map(([file,text])=>({file,sha256:sha(Buffer.from(text,'latin1'))}));
 fs.writeFileSync(p.join(work,'text-manifest.json'),JSON.stringify(manifest,null,2));
 fs.writeFileSync(p.join(work,'preservation.json'),JSON.stringify(e.audit,null,2));return {...e.audit,textFiles:e.texts.size,assets:e.assets.length};
}
function verify(){const e=expected();for(const file of retiredIdleFiles)assert(!fs.existsSync(p.join(output,'resource',file)),'Retired Idle override: '+file);for(const [file,text]of e.texts)assert.equal(read(p.join(output,'resource',file)),text,file);return {...e.audit,textFiles:e.texts.size,assets:e.assets.length};}
if(require.main===module)console.log(JSON.stringify(process.argv.includes('--build')?build():verify()));
module.exports={expected,verify,output,work,retiredIdleFiles};
