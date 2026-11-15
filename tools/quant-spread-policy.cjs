// Which mission triggers are spread over quants, and how often their heavy terms are checked.
// Nominal idle scan intervals: combat 0.5 s; bookkeeping 1 s (native polling was ~0.25 s).
// Successful cycles also execute the original action delays; engine quant scheduling adds granularity.
const fs=require('fs'),p=require('path'),q=require('./lib/quant-spread.cjs');
// Tag pair terms mark the matched soldier/target inside the timed gates as well.
const ALLOW_TAG_PAIR=true;
const files=['HF-dcg_script.inc','ufb_combat_autonomy.inc','ufb_infantry_support.inc','ufb_medical_support.inc','ufb_static_weapons.inc'];
const combat=/^(hf inf ai\/(antitank|grenade|melee|near player|pilot)|hf tank ai\/|ufb\/(combat|launcher|suppress|fear|tank|air|shout|surrender\/claim)\/)/;
const period=name=>['ufb/class','ufb/morale/profile'].includes(name)?0:combat.test(name)?0.5:1;
function usage(dir,overrides={}){
 const names=new Set([...fs.readdirSync(dir).filter(f=>f.endsWith('.inc')),...Object.keys(overrides)]);
 return q.externallyUsed([...names].map(f=>overrides[f]??fs.readFileSync(p.join(dir,f),'latin1')));
}
const apply=(text,u,stats={})=>q.spread(text,{period,usage:u,allowTagPair:ALLOW_TAG_PAIR,stats});
// Generated {file,text} list -> same list with the mission scripts spread.
function spreadFiles(list,dir){
 const mission=e=>e.file.startsWith('map/multi/')&&files.includes(p.basename(e.file));
 const u=usage(dir,Object.fromEntries(list.filter(mission).map(e=>[p.basename(e.file),e.text])));
 return list.map(e=>mission(e)?{...e,text:apply(e.text,u)}:e);
}
module.exports={files,period,usage,apply,spreadFiles,ALLOW_TAG_PAIR};
