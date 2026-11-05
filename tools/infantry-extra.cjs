// Native support switches and bounded fire at a frozen, previously visible point.
const fs=require('fs'),p=require('path'),assert=require('assert/strict'),s=require('./lib/sdl.cjs');
const T=x=>`{tag {tag ${x}}}`,P=x=>`{prop {prop ${x}}}`,S=x=>`{state {state ${x}}}`;
const I=(x,type='existance')=>`{with_item {type ${type}} {item "${x}"}}`;
const actorTag=kind=>`_ufb_${kind}_actor_%player`;
const protectedHumanTags=require('./infantry-job-policy.cjs').protectedHumanTags;
function selector({kind,acquire=false,item,player=true,extra=[],exclude=[],using}={}){
 return `{source advanced} {ignore_captured_by_user 1}
 {group {select ${acquire?P('human'):T(actorTag(kind))}}
 {include ${P('human')} ${S('operatable')} ${player?`{player {player "%player"}}`:''} ${item?I(item):''} ${using?I(using,'using'):''} ${extra.join(' ')}}
 {exclude ${S('dead')} ${S('inactive')} ${S('linked')} ${P('crew')} ${P('repairing')} ${P('throwing')}
 ${[...protectedHumanTags,'_ufb_combat_busy'].map(T).join(' ')}
 ${exclude.join(' ')}
 ${acquire?[T('_ufb_job_reserved'),T(actorTag('suppress')),...['mgun','assaultrifle','battlerifle','autorifle','semirifle'].map(k=>T(actorTag('loot_'+k))),...['launcher','at','critical','ap','smoke','idle'].map(k=>T(`_ufb_combat_${k}_actor_%player`))].join(' '):''}
 }}${acquire?' {amount 1}':''}`;
}
function support(){
 const init=(medic=false)=>`{source advanced} {ignore_captured_by_user 0} {group
 {select ${medic?T('medic'):P('human')}}
 {include ${P('human')} ${S('user_control')} ${S('operatable')}}
 {exclude ${S('dead')} ${S('inactive')} ${S('linked')} ${T(medic?'_ufb_native_medic_initialized':'_ufb_native_pickup_initialized')}}}`;
 let text=`; Native properties preserve the engine's inventory, medic and manual-order rules.
; Each switch is enabled once; the player's later auto-medic toggle remains effective.
`;
 for(const [name,sel,property,tag]of [
  ['pickup',init(false),'take_new_weapon_from_ground','_ufb_native_pickup_initialized'],
  ['medic',init(true),'auto_medic','_ufb_native_medic_initialized']
 ])text+=`
{"ufb/support/native ${name}"
 {condition {terms {"1.entities" {selector ${sel}}}}}
 {actions
  {"actor_state" {selector ${sel}} {ai {${property} on}}}
  {"entity_state" {selector ${sel}} {tag_add ${tag}}}
  {"con" {text "[UFB support] initialized native ${name}"}}
  {"delay" {time 2}}
  {"trigger" {name "ufb/support/native ${name}"}}
 }
}
`;
 const kinds=['mgun','assaultrifle','battlerifle','autorifle','semirifle'];
 // Only a plain rifle carrier upgrades here; no forced crawling, following changes,
 // inventory creation, replacing a prepared launcher, or stealing from wounded men.
 const common={kind:'loot_%weapon',item:'rifle',extra:[S('user_control')],using:'rifle',exclude:[I('sniper'),I('rocketlauncher','using'),I('loot_riflegrenade'),I('loot_atrifle'),...kinds.map(k=>I('loot_'+k)),T('_ufb_loot_cooldown')]};
 const actor=selector({...common,acquire:true});
 const body=`{source advanced} {ignore_captured_by_user 0} {group {select ${P('human')}} {include ${S('dead')} ${I('loot_%weapon')}} {exclude ${S('linked')} ${T('hidden')} ${T('_ai_wounded_target_linked')} ${T('bleeding')} ${T('start_personage')} ${T('wounded_animation_playing')}}} {amount 1}`;
 text+=`
(define "ufb_player_body_loot"
 {"ufb/support/loot %weapon/acquire %player"
  {condition {terms {"1.see_actors"
   {selector ${actor}}
   {enemy ${body}}
   {distance {mode near_than} {meters 3}}
   {tag {"tag pair"} {"for selector" ${actorTag('loot_%weapon')}} {"for enemy" _ufb_loot_%weapon_body_%player}}
  }}}
  {actions
   {"effect" {selector {ignore_captured_by_user 0} {tag ${actorTag('loot_%weapon')}}} {effect ufb_reserve_job}}
   {"delay" {time 1}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag ${actorTag('loot_%weapon')}}} {tag_remove _ufb_job_reserved}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag ${actorTag('loot_%weapon')}}} {tag_remove ${actorTag('loot_%weapon')}}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_loot_%weapon_body_%player}} {tag_remove _ufb_loot_%weapon_body_%player}}
   {"delay" {time 8}}
   {"trigger" {name "ufb/support/loot %weapon/acquire %player"}}
  }
 }
 {"ufb/support/loot %weapon/apply %player"
  {condition {expression "1 & !2"} {terms
   {"1.near" {units ${selector(common)}} {near_to {source advanced} {ignore_captured_by_user 0} {group {select ${T('_ufb_loot_%weapon_body_%player')}} {include ${S('dead')} ${I('loot_%weapon')}} {exclude ${S('linked')} ${T('bleeding')} ${T('start_personage')} ${T('wounded_animation_playing')}}}} {distance 3}}
   {"2.see_actors" {selector ${selector(common)}}
    {enemy {source advanced} {ignore_captured_by_user 0} {group {select ${P('human')} ${P('vehicle')}} {include ${S('operatable')} {relation {relation enemy} {player "%player"}}} {exclude ${S('dead')} ${S('inactive')}}}}
    {distance {mode near_than} {meters 30}} {detection visible}
   }
  }}
  {actions
   {"inventory" {selector ${selector(common)}} {action take_from} {item "loot_%weapon"}
    {entity {source advanced} {ignore_captured_by_user 0} {group {select ${T('_ufb_loot_%weapon_body_%player')}} {include ${S('dead')} ${I('loot_%weapon')}} {exclude ${S('linked')} ${T('bleeding')} ${T('start_personage')} ${T('wounded_animation_playing')}}}}
   }
   {"effect" {selector {source advanced} {ignore_captured_by_user 1} {group {select ${T(actorTag('loot_%weapon'))}} {include ${I('loot_%weapon')}}}} {effect ufb_loot_cooldown}}
   {"con" {text "[UFB support] corpse weapon pickup order: %weapon, player %player"}}
   {"delay" {time 2}}
   {"trigger" {name "ufb/support/loot %weapon/apply %player"}}
  }
 }
)
`;
 for(let player=0;player<=16;player++)for(const weapon of kinds)text+=`("ufb_player_body_loot" player(${player}) weapon(${weapon}))\n`;
 return text+suppression();
}
function suppression(){
 const base={kind:'suppress',using:'mgun',extra:[P('shooting')],exclude:[T('_ufb_suppress_cooldown'),T(actorTag('loot'))]};
 const active=selector({kind:'suppress',using:'mgun'}).replace(T('_ufb_combat_busy'),'');
 const botActive=selector({kind:'suppress',using:'mgun',exclude:[S('user_control')]}).replace(T('_ufb_combat_busy'),'');
 const playerActive=selector({kind:'suppress',using:'mgun',extra:[S('user_control'),P('shooting')]}).replace(T('_ufb_combat_busy'),'');
 const point='{ignore_captured_by_user 0} {tag _ufb_suppress_point_%player}';
 const nearFriend=`{units ${point}} {near_to {source advanced} {ignore_captured_by_user 0} {group {select ${P('human')}} {include ${S('operatable')} {relation {relation ally} {player "%player"}}} {exclude ${S('dead')}}}} {distance 12}`;
 const shot=`{"switch"
 {"case" {condition {type near} ${nearFriend}}}
 {"default"
  {"if" {condition {type entities} {selector ${point}}}
   {"actor_fire" {selector ${botActive}}
    {enemies ${point}} {deviate} {interval 0} {time 0} {burst_mode once}
   }
   {"actor_fire" {selector ${playerActive}}
    {enemies ${point}} {deviate} {interval 0} {time 0} {burst_mode once}
   }
  }
 }
}`;
 let text=`
; A point is sampled while the target is visible. Later fire never targets or
; follows the hidden soldier. Three ordinary bursts at 0/2/4 seconds at most.
(define "ufb_mg_suppress"
 {"ufb/suppress/acquire %player"
  {condition {terms {"1.see_actors"
   {selector ${selector({...base,acquire:true})}}
   {enemy {source advanced} {ignore_captured_by_user 0} {group {select ${P('human')}} {include ${S('operatable')} {relation {relation enemy} {player "%player"}}} {exclude ${S('dead')} ${S('inactive')} ${S('linked')}}} {amount 1}}
   {distance {mode in_range} {min 20} {max 120}} {detection visible}
   {tag {"tag pair"} {"for selector" ${actorTag('suppress')}} {"for enemy" _ufb_suppress_enemy_%player}}
  }}}
  {actions
   {"effect" {selector {ignore_captured_by_user 0} {tag _ufb_suppress_enemy_%player}} {effect ufb_suppress_point_%player}}
   {"switch"
    {"case" {condition {type entities} {selector ${point}}}
     {"effect" {selector {ignore_captured_by_user 0} {tag ${actorTag('suppress')}}} {effect ufb_reserve_job}}
    }
    {"default"
     {"entity_state" {selector {ignore_captured_by_user 0} {tag ${actorTag('suppress')}}} {tag_remove ${actorTag('suppress')}}}
     {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_suppress_enemy_%player}} {tag_remove _ufb_suppress_enemy_%player}}
    }
   }
   {"delay" {time 6}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag ${actorTag('suppress')}}} {tag_remove ${actorTag('suppress')}}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_suppress_enemy_%player}} {tag_remove _ufb_suppress_enemy_%player}}
   {"delay" {time 4}}
   {"trigger" {name "ufb/suppress/acquire %player"}}
  }
 }
 {"ufb/suppress/apply %player"
  {condition {expression "1 & 2 & !3 & !4"} {terms
   {"1.entities" {selector ${selector({...base,extra:[]})}}}
   {"2.near" {units ${active}} {near_to ${point}} {distance 120}}
   {"3.near" {units ${active}} {near_to ${point}} {distance 12}}
   {"4.near" ${nearFriend}}
  }}
  {actions
   {"effect" {selector ${active}} {effect ufb_suppress_cooldown}}
   {"con" {text "[UFB support] bounded MG suppression: player %player"}}
   ${shot}
   {"delay" {time 2}}
   ${shot}
   {"delay" {time 2}}
   ${shot}
   {"delay" {time 2}}
   {"trigger" {name "ufb/suppress/apply %player"}}
  }
 }
)
`;
 for(let player=0;player<=16;player++)text+=`("ufb_mg_suppress" player(${player}))\n`;
 return text;
}
function events(){
 let text=`{on "ufb_loot_cooldown"
 {tags add "_ufb_combat_busy"} {tags add "_ufb_loot_cooldown"}
 {delay 4 {tags remove "_ufb_combat_busy"}}
 {delay 20 {tags remove "_ufb_loot_cooldown"}}
}
{on "ufb_suppress_cooldown"
 {tags add "_ufb_combat_busy"} {tags add "_ufb_suppress_cooldown"}
 {delay 6 {tags remove "_ufb_combat_busy"}}
 {delay 15 {tags remove "_ufb_suppress_cooldown"}}
}
(define "ufb_suppress_point_events"
 {on "ufb_suppress_point_%player"
  {if in_cover {call "ufb_suppress_point_spawn_%player"}
  else lying {call "ufb_suppress_point_spawn_%player"}
  else squatting {call "ufb_suppress_point_spawn_%player"}}
 }
 {on "ufb_suppress_point_spawn_%player" sync
  {spawn "ufb_smoke_screen_point" "basis" x
   {tags add "_ufb_suppress_point_%player"}
   {delay 4 1 {delete}}
  }
 }
)
`;
 for(let player=0;player<=16;player++)text+=`("ufb_suppress_point_events" player(${player}))\n`;
 return text;
}
function panzerfaust(base){
 const n=s.all(s.parse(base),n=>s.name(n)==='projectileDamageTable')[0];assert(n);
 return base.slice(0,n.start)+'{projectileDamageTable {0 200} {40 160} {200 0}}'+base.slice(n.end);
}
function expected(ref){return [
 {file:'map/multi/ufb_infantry_support.inc',text:support()},
 {file:'set/interaction_entity/ufb_infantry_support_events.inc',text:events()},
 {file:'set/stuff/bazooka/panzerfaust_60.weapon',text:panzerfaust(fs.readFileSync(p.join(ref,'set/stuff/bazooka/panzerfaust_60.weapon'),'latin1'))}
];}
module.exports={support,events,panzerfaust,expected};
