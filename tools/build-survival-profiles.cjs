// Build-time breed classification. At runtime only tags and bounded entity timers.
const fs=require('fs'),path=require('path'),assert=require('assert/strict'),crypto=require('crypto');
const s=require('./lib/sdl.cjs'),cfg=require('./survival-profiles.json');
const repo=path.resolve(__dirname,'..');
const output=path.join(repo,'mods/ultimate_frontline_bundle/resource'),backup=path.join(repo,'../_survival_work/tactical-before');
const manifestPath=path.join(repo,'docs/realism/tactical/breed-profiles.json');
const previous=fs.existsSync(manifestPath)?JSON.parse(fs.readFileSync(manifestPath,'utf8')):{entries:[]};
// Rebuild from the last reviewed source tree, not a stale pre-update snapshot.
const sources=path.resolve(process.argv[2]||previous.source||path.join(repo,'../_survival_work/system-effective'));
const previousEntries=new Map(previous.entries.map(e=>[e.file,e]));
const sha=data=>crypto.createHash('sha256').update(data).digest('hex');
assert(sources!==output,'Preserved sources required');
const validProfile=p=>Object.hasOwn(cfg.profiles,p);
assert(validProfile(cfg.defaultProfile));
for(const p of Object.values(cfg.tierProfiles))assert(validProfile(p));
for(const [rel,p] of Object.entries(cfg.overrides)){assert(validProfile(p));assert(rel.startsWith('set/breed/')&&rel.endsWith('.set')&&!rel.includes('..'));}
for(const p of Object.values(cfg.profiles)){
 for(const key of ['shakenSeconds','overwhelmedSeconds','coverProtectionSeconds','overwhelmedCoverSeconds'])assert(Number.isFinite(p[key])&&p[key]>0);
 assert(p.composureChance>=0&&p.composureChance<=1&&Number.isFinite(p.composureChance));
 assert(p.coverProtectionSeconds<cfg.coverCooldownSeconds);
 assert(p.overwhelmedCoverSeconds>=p.coverProtectionSeconds&&p.overwhelmedCoverSeconds<cfg.overwhelmedCooldownSeconds);
}
for(const key of ['refractorySeconds','pendingSeconds','composureRetrySeconds','composureDurationSeconds','coverCooldownSeconds','overwhelmedCooldownSeconds'])assert(Number.isFinite(cfg[key])&&cfg[key]>0);
assert(cfg.composureDurationSeconds<cfg.composureRetrySeconds);
assert(Number.isFinite(cfg.intenseFireWindowSeconds)&&cfg.intenseFireWindowSeconds>cfg.refractorySeconds);
assert(Object.values(cfg.profiles).every(p=>cfg.intenseFireWindowSeconds<p.shakenSeconds));
const walk=d=>fs.readdirSync(d,{withFileTypes:true}).flatMap(e=>e.isDirectory()?walk(path.join(d,e.name)):[path.join(d,e.name)]);
function save(rel,text,encoding='utf8'){
 s.parse(text);const dest=path.join(output,rel),bak=path.join(backup,rel);
 if(fs.existsSync(dest)&&!fs.existsSync(bak)&&!previousEntries.has(rel)){fs.mkdirSync(path.dirname(bak),{recursive:true});fs.copyFileSync(dest,bak);}
 fs.mkdirSync(path.dirname(dest),{recursive:true});fs.writeFileSync(dest,text,{encoding});
}
const counts={},entries=[],pending=[];
for(const file of walk(path.join(sources,'set/breed')).filter(f=>f.endsWith('.set'))){
 const rel=path.relative(sources,file).replaceAll('\\','/'),raw=fs.readFileSync(file);
 const encoding=Buffer.from(raw.toString('utf8'),'utf8').equals(raw)?'utf8':'latin1';
 const text=raw.toString(encoding),ast=s.parse(text);
 const breed=ast.children.find(n=>s.name(n)==='breed');if(!breed)continue;
 const tiers=[...new Set(s.all(breed,n=>/^tier[1-5]_/.test(s.name(n)||'')).map(n=>s.name(n)[4]))];
 // Conflicting presets cannot safely imply experience. Use an explicit override or fallback.
 const tier=tiers.length===1?tiers[0]:null;
 const profile=cfg.overrides[rel]||(tier?cfg.tierProfiles[tier]:cfg.defaultProfile);
 assert(validProfile(profile),rel);
 let result=text;
 if(cfg.enabled){
  const tagNodes=breed.children.filter(n=>s.name(n)==='tags');assert(tagNodes.length<=1,'Ambiguous tags: '+rel);
  if(tagNodes.length){
   const tag=tagNodes[0];assert(!tag.tokens.some(t=>t.value.startsWith('_ufb_profile_')),'Source snapshot already generated: '+rel);
   result=text.slice(0,tag.end-1)+` "_ufb_profile_${profile}"`+text.slice(tag.end-1);
  }else result=text.slice(0,breed.end-1)+`\n\t{tags "_ufb_profile_${profile}"}\n`+text.slice(breed.end-1);
 }
 // Verify all original tokens/blocks survive, including user inventories and armors.
 const normalize=(n,strip)=>({kind:n.kind,tokens:n.tokens.filter(t=>!strip||!t.value.startsWith('_ufb_profile_')).map(t=>t.value),children:n.children.filter(c=>!strip||s.name(c)!=='tags'||c.tokens.length>2||!c.tokens[1]?.value.startsWith('_ufb_profile_')).map(c=>normalize(c,strip))});
 assert.deepEqual(normalize(s.parse(result),true),normalize(ast,false),'Breed preservation: '+rel);
 const generatedSHA256=sha(Buffer.from(result,encoding)),dest=path.join(output,rel);
 if(fs.existsSync(dest)){
  const current=sha(fs.readFileSync(dest));
  assert([sha(raw),generatedSHA256,previousEntries.get(rel)?.generatedSHA256].includes(current),'Output edited since snapshot/build; preserve and merge first: '+rel);
 }
 pending.push({rel,result,encoding});counts[profile]=(counts[profile]||0)+1;
 entries.push({file:rel,profile,tier,reason:cfg.overrides[rel]?'override':tier?'tier':'fallback',sourceSHA256:sha(raw),generatedSHA256});
}
for(const rel of Object.keys(cfg.overrides))assert(entries.some(e=>e.file===rel),'Override does not match a breed: '+rel);
const currentFiles=new Set(entries.map(e=>e.file));
for(const rel of previousEntries.keys())assert(currentFiles.has(rel),'Source removed a previously generated breed; resolve stale overlay explicitly: '+rel);
// Select an entire command, not a numeric expression: GEM event syntax has no
// documented arbitrary arithmetic or variables for these timer arguments.
function profileCommand(fn){
 return Object.entries(cfg.profiles).filter(([name])=>name!==cfg.defaultProfile).reduceRight((tail,[name,p])=>`{if tagged "_ufb_profile_${name}"\n${fn(p)}\nelse\n${tail}\n}`,fn(cfg.profiles[cfg.defaultProfile]));
}
const delay=(seconds,name,tag)=>`{delay ${seconds} "${name}" {tags remove "${tag}"}}`;
let events='; Generated by tools/build-survival-profiles.cjs; tune tools/survival-profiles.json.\n';
if(cfg.enabled)events+=`{on "ufb_stress" sync
 {if not tagged "_ufb_stress_refractory"
  {tags add "_ufb_stress_refractory"}
  ${delay(cfg.refractorySeconds,'ufb_stress_refractory_expiry','_ufb_stress_refractory')}
  {if not dead
   {if not user_control
    {if tagged "_ufb_recent_fire"
     {tags add "_ufb_overwhelmed"}
     {kill_delay "ufb_overwhelmed_expiry"}
     ${profileCommand(p=>delay(p.overwhelmedSeconds,'ufb_overwhelmed_expiry','_ufb_overwhelmed'))}
    }
    {tags add "_ufb_recent_fire"}
    {kill_delay "ufb_recent_fire_expiry"}
    ${delay(cfg.intenseFireWindowSeconds,'ufb_recent_fire_expiry','_ufb_recent_fire')}
    {tags add "_ufb_shaken"}
    {kill_delay "ufb_shaken_expiry"}
    ${profileCommand(p=>delay(p.shakenSeconds,'ufb_shaken_expiry','_ufb_shaken'))}
    {if not tagged "_ufb_composure_checked"
     {tags add "_ufb_composure_checked"}
     ${delay(cfg.composureRetrySeconds,'ufb_composure_reset','_ufb_composure_checked')}
     ${profileCommand(p=>`{if rand ${p.composureChance}\n{tags add "_ufb_heroic"}\n${delay(cfg.composureDurationSeconds,'ufb_heroic_expiry','_ufb_heroic')}\n}`)}
    }
    {if not tagged "_ufb_cover_cooldown"
     {if not tagged "_ufb_heroic"
      {tags add "_ufb_stress_pending"}
      {kill_delay "ufb_pending_expiry"}
      ${delay(cfg.pendingSeconds,'ufb_pending_expiry','_ufb_stress_pending')}
     }
    }
   }
  }
 }
}
{on "ufb_cover_committed" sync
 {if not tagged "_ufb_cover_cooldown"
  {tags remove "_ufb_stress_pending"}
  {kill_delay "ufb_pending_expiry"}
  {tags add "_ufb_cover_cooldown"}
  {tags add "_ufb_cover_active"}
  {if tagged "_ufb_overwhelmed"
   ${profileCommand(p=>delay(p.overwhelmedCoverSeconds,'ufb_cover_active_expiry','_ufb_cover_active'))}
  else
   ${profileCommand(p=>delay(p.coverProtectionSeconds,'ufb_cover_active_expiry','_ufb_cover_active'))}
  }
  {if tagged "_ufb_overwhelmed"
   ${delay(cfg.overwhelmedCooldownSeconds,'ufb_cover_cooldown_expiry','_ufb_cover_cooldown')}
  else
   ${delay(cfg.coverCooldownSeconds,'ufb_cover_cooldown_expiry','_ufb_cover_cooldown')}
  }
 }
}
`;
else events+='{on "ufb_stress" sync}\n{on "ufb_cover_committed" sync}\n';
// Complete all breed preflight checks before mutating any output.
for(const {rel,result,encoding} of pending)save(rel,result,encoding);
save('set/interaction_entity/ufb_stress.inc',events);
fs.mkdirSync(path.join(repo,'docs/realism/tactical'),{recursive:true});
fs.writeFileSync(manifestPath,JSON.stringify({source:sources,enabled:cfg.enabled,counts,entries},null,2)+'\n');
console.log(JSON.stringify({breeds:entries.length,counts,enabled:cfg.enabled,preservation:'all original breed tokens retained'},null,2));
