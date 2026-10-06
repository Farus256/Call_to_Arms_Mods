// Native event delays + timed decal views. No per-frame corpse polling.
const fs=require('fs'),path=require('path'),assert=require('assert/strict'),crypto=require('crypto');
const s=require('./lib/sdl.cjs'),cfg=require('./blood-pools.json');
const root=path.resolve(__dirname,'../mods/ultimate_frontline_bundle/resource');
const reportPath=path.resolve(__dirname,'../docs/realism/blood-pools.json');
const previous=fs.existsSync(reportPath)?JSON.parse(fs.readFileSync(reportPath)):null;
const sha=text=>crypto.createHash('sha256').update(text).digest('hex');
const [low,high]=cfg.startDelaySeconds;
assert(low>=1&&high>=low&&cfg.initialScale>0&&cfg.finalScale>cfg.initialScale);
assert(cfg.growthSeconds.length&&cfg.growthSeconds.every(t=>Number.isFinite(t)&&t>0));
const name=t=>t===80?'bloodstain':`bloodstain_${t}s`;
function effect(seconds){return `{fx
 ; Stock GoH blood, +15% size. Linear growth ends exactly at ${seconds}s.
 {decalview "growing pool"
  {sprite "$/particle/bloodstain"
   {timer {mode play} {duration ${seconds}}}
   {scale 1 {linear {min ${cfg.initialScale}} {max ${cfg.finalScale}}}}
   {visibility 1}
   {preturn 180 180}
  }
  {dynamic} {ground} {layer grounddynamic} {notifyowner}
 }
 ; The delayed view keeps the FX alive and retains the completed pool.
 {decalview "settled pool"
  {delay ${seconds}}
  {sprite "$/particle/bloodstain"
   {timer {duration ${cfg.persistenceSeconds}}}
   {scale ${cfg.finalScale}}
   {visibility 1 {linear {min 1} {max 0.7}}}
   {preturn 180 180}
  }
  {dynamic} {ground} {layer grounddynamic} {notifyowner}
 }
}
`;}
function choice(index){
 const action=`{spawn "${name(cfg.growthSeconds[index])}" "basis" x}`;
 const remaining=cfg.growthSeconds.length-index;
 return remaining===1?action:`{if rand ${(1/remaining).toFixed(12)}\n ${action}\n else\n ${choice(index+1)}\n}`;
}
const mean=(low+high)/2,spread=(high-low)/2;
const helper=`; Included inside human.inc. A corpse schedules one pool only.
(define "ufb_schedule_pool"
 {if not "ufb_pool_scheduled"
  {set "ufb_pool_scheduled" 1}
  {delay %wait ${spread}
   {if dead
    {if not burned
     {if not under_water {call_synced "ufb_spawn_corpse_pool"}}
    }
   }
  }
 }
)
{on "ufb_schedule_corpse_pool" ("ufb_schedule_pool" wait(${mean}))}
; stop_personage checks death after 1s: subtract that second, not add it twice.
{on "ufb_schedule_bleedout_pool" ("ufb_schedule_pool" wait(${mean-1}))}
{on "ufb_spawn_corpse_pool"
 ${choice(0)}
}
`;
const outputs=cfg.growthSeconds.map(t=>({file:`entity/fx/hit/${name(t)}.def`,text:effect(t)}));
for(const file of ['bloodstain_rot120','bloodstain_rot240'])outputs.push({file:`entity/fx/hit/${file}.def`,text:effect(80)});
outputs.push({file:'set/interaction_entity/ufb_corpse_pool.inc',text:helper});
for(const output of outputs){
 s.parse(output.text);
 const dest=path.join(root,output.file),old=previous?.files.find(f=>f.file===output.file);
 if(old&&fs.existsSync(dest))assert([old.sha256,sha(output.text)].includes(sha(fs.readFileSync(dest))),'Edited output; merge first: '+output.file);
}
for(const output of outputs){const dest=path.join(root,output.file);fs.mkdirSync(path.dirname(dest),{recursive:true});fs.writeFileSync(dest,output.text);}
fs.writeFileSync(reportPath,JSON.stringify({gameBattleTested:false,config:cfg,files:outputs.map(o=>({file:o.file,sha256:sha(o.text)}))},null,2)+'\n');
console.log('Built '+outputs.length+' corpse pool resources.');
