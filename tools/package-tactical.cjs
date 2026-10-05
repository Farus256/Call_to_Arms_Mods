// Read-only audit of the installation; package output stays in the workspace.
const fs=require('fs'),path=require('path'),cp=require('child_process'),crypto=require('crypto'),assert=require('assert/strict');
const repo=path.resolve(__dirname,'..'),prefix='mods/ultimate_frontline_bundle/resource/';
const target=process.argv[2]||'D:/Programs/Steam/steamapps/common/Call to Arms - Gates of Hell/'+prefix;
const output=path.resolve(process.argv[3]||path.join(repo,'../_survival_work/tactical-package'));
const build=require('../docs/realism/tactical/build.json'),breeds=require('../docs/realism/tactical/breed-profiles.json');
const files=[...new Set([...build.files,...breeds.entries.map(e=>e.file),
 'map/multi/ufb_survival.inc','script/multiplayer/modes/conquest/orders.lua',
 'script/multiplayer/ufb_order_guard.lua','script/multiplayer/ufb_objective_balance.lua',
 'set/interaction_entity/human.inc','set/interaction_entity/ufb_stress.inc',
 'set/squads.set','set/fxmanager.set','map/multi/HF-dcg_script.inc','set/stuff/rifle/grenade/dyakonov.he.ammo'])].sort();
files.push(...JSON.parse(fs.readFileSync(path.join(repo,'docs/realism/battlefield-persistence.json'))).files.map(e=>e.file));
files.splice(0,files.length,...new Set(files).values());
// A stale package from an older run must not silently retain a shader override.
assert(!fs.existsSync(path.join(output,'resource/shader')),'Move the old package shader folder to backup before rebuilding');
const sha=b=>crypto.createHash('sha256').update(b).digest('hex');
const oldManifestPath=path.join(output,'manifest.json');
const oldManifest=fs.existsSync(oldManifestPath)?JSON.parse(fs.readFileSync(oldManifestPath,'utf8')):null;
const priorEntries=new Map(oldManifest&&path.resolve(oldManifest.target)===path.resolve(target)?oldManifest.files.map(e=>[e.file,e.afterSHA256]):[]);
const entries=[];
for(const file of files){
 const source=path.join(repo,prefix,file),dest=path.join(target,file),data=fs.readFileSync(source);
 let before=null;
 if(fs.existsSync(dest)){
  before=fs.readFileSync(dest);
  if(!before.equals(data)&&sha(before)!==priorEntries.get(file)){
    const git=cp.spawnSync('git',['-c','safe.directory='+repo.replaceAll('\\','/'),'show','HEAD:'+prefix+file],{cwd:repo,maxBuffer:5000000});
   const old=git.status===0?git.stdout:fs.existsSync(path.join(build.source,file))?fs.readFileSync(path.join(build.source,file)):null;
   assert(old&&old.equals(before),'Installed resource differs from preserved baseline: '+file);
  }
 }
 entries.push({file,beforeSHA256:before?sha(before):null,afterSHA256:sha(data)});
}
for(const entry of entries){const dest=path.join(output,'resource',entry.file);fs.mkdirSync(path.dirname(dest),{recursive:true});fs.copyFileSync(path.join(repo,prefix,entry.file),dest);}
fs.writeFileSync(path.join(output,'manifest.json'),JSON.stringify({baseline:'HEAD',target,files:entries},null,2)+'\n');
fs.copyFileSync(path.join(__dirname,'Apply-TacticalPatch.ps1'),path.join(output,'Apply-TacticalPatch.ps1'));
if(fs.existsSync(path.join(repo,'docs/realism/tactical/REPORT_RU.md')))fs.copyFileSync(path.join(repo,'docs/realism/tactical/REPORT_RU.md'),path.join(output,'REPORT_RU.md'));
console.log(JSON.stringify({output,files:entries.length,existing:entries.filter(e=>e.beforeSHA256).length,note:'Not installed'},null,2));
