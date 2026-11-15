// One head-only Idle Animations clip, for ordinary passenger seats only.
const assert=require('assert/strict'),s=require('./lib/sdl.cjs');
const asset='properties/animation/human_addon/look/look_leftright.anm';
const sequence='ufb_passenger_idle_look',flag='ufb_passenger_idle',tick='ufb_passenger_idle_tick',poll='ufb_passenger_idle_poll';
const protectedTags=['bleeding','_bleedout_','wounded_animation_playing','reloading','_ai_reloading','_ai_do_not_disturb','_ufb_healing_active','_ufb_job_reserved','_ufb_recent_hit','_ufb_firing','_ufb_combat_busy','_ufb_gun_job_active'];
function expected({source,current}){
 const tree=s.parse(source(3350281452,'properties/animation/human_addon/human_anm_addon.ext'));
 const original=s.all(tree,n=>s.name(n)==='sequence'&&n.tokens[1]?.value==='look/look_leftright')[0];assert(original);
 const speed=s.child(original,'speed')?.tokens[1]?.value||'1';assert(Number(speed)>0);
 const stop=`{ani_stop "${sequence}"}`,cancel=`${stop} {kill_delay "${tick}"} {tags remove "${flag}"}`;
 const seats=Array.from({length:15},(_,i)=>`{if name "seat${i+1}" {tags add "${flag}"}}`).join('\n');
 const look=protectedTags.map(t=>`{if not tagged "${t}"`).join(' ')+` {if rand 0.35 {ani_play "${sequence}" 0.2}}`+'}'.repeat(protectedTags.length);
 const texts={
  'properties/animation/human/_reg_vehicle_crew.inc':current('properties/animation/human/_reg_vehicle_crew.inc')+`\n; UFB: one passenger head layer; native crew poses stay in charge.\n{sequence "${sequence}" {file "/${asset}"} {speed ${speed}} {smooth 0.2} {resume}}\n`,
  'set/interaction_entity/construction/placement.inc':current('set/interaction_entity/construction/placement.inc')+'\n(include "../ufb_passenger_idle.inc")\n',
  'set/interaction_entity/ufb_passenger_idle.inc':`{"human"
 {on board in sync
  ${cancel}
  ${seats}
  {if tagged "${flag}" {call "${poll}"}}
 }
 {on "${poll}"
  {kill_delay "${tick}"}
  {if operatable {if linked "vehicle" {if tagged "${flag}"
   ${look}
   {delay 8 "${tick}" {call "${poll}"}}
  }}}
 }
 {on board out sync ${cancel}}
 ${['die','stop_personage'].map(event=>`{on "${event}" sync ${cancel}}`).join('\n')}
 ${['fire','reload','process_bullet_hit','blast_hit'].map(event=>`{on "${event}" sync ${stop}}`).join('\n')}
 {on ik begin "ik_leftright" sync ${stop}}
}
`
 };
 for(const text of Object.values(texts))s.parse(text);
 return {texts,assets:[asset],report:{selectedClips:1,passengerHeadOnly:true,ordinaryPassengerSeats:15,footIdleChanged:false,crewFullBodyChanged:false,pollSeconds:8}};
}
module.exports={expected,asset,sequence,flag,tick,poll,protectedTags};
