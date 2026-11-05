// Stationary MG/mortar crews: abandon the gun against armor they cannot hurt,
// bot deployment at first contact, native AI sandbags, and bot fear of tanks.
// Only native commands are used: emit_crew, actor_state cannon/move_mode,
// construction_sandbag_cannon_*_ai, actor_to_cover and voice sets.
const fs=require('fs'),p=require('path');
const {protectedHumanTags}=require('./infantry-job-policy.cjs');
const T=x=>`{tag {tag ${x}}}`,P=x=>`{prop {prop ${x}}}`,S=x=>`{state {state ${x}}}`;
const I=(x,type='existance')=>`{with_item {type ${type}} {item "${x}"}}`;
const players=Array.from({length:17},(_,i)=>i);
const tagged=x=>`{ignore_captured_by_user 0} {tag ${x}}`;
// Tunables, in meters unless stated. Real battles may want these adjusted.
const tune={abandon:80,crewReach:7,fortifyChance:0.6,fortifyMinEnemy:40,deploy:{mg:[40,130],mortar:[60,240]},tankFear:30};
const hmgProps=['muzzle_hmg','muzzle_hmg_dshk','muzzle_hmg_m2hb'];
// A bunker or ring mount is the cover; 20 mm and the ampulomet can hurt light armor.
const notAGunPit=[P('bunker'),P('hatch'),P('muzzle_20mm_25mm_auto'),S('dead'),S('inactive'),S('linked')];
const gunFor=exclude=>`{source advanced} {ignore_captured_by_user 1} {group
 {select ${P('mg_stan')} ${P('mortar')}}
 {include {player {player "%player"}} ${P('cannon')} ${S('operatable')} ${S('inhabited')}}
 {exclude ${[...notAGunPit,...exclude].join(' ')}}}`;
const lightGun=gunFor([T('_ufb_gun_left_%player'),...hmgProps.map(P)]);
const heavyGun=`{source advanced} {ignore_captured_by_user 1} {group
 {select ${hmgProps.map(P).join(' ')}}
 {include {player {player "%player"}} ${P('cannon')} ${S('operatable')} ${S('inhabited')}}
 {exclude ${[...notAGunPit,T('_ufb_gun_left_%player')].join(' ')}}}`;
const threat=(select,include=[])=>`{source advanced} {ignore_captured_by_user 0} {group
 {select ${select.map(P).join(' ')}}
 {include {relation {relation enemy} {player "%player"}} ${S('operatable')} ${include.join(' ')}}
 {exclude ${S('dead')} ${S('inactive')} ${S('linked')} ${P('airborne')}}}`;
const armor=threat(['tank','armored_car']); // Rifle-caliber MG and mortar: all armor.
const heavyArmor=threat(['medium','heavy'],[P('with_gun')]); // 12.7 mm still hurts light armor.
const anyEnemy=`{source advanced} {ignore_captured_by_user 0} {group
 {select ${P('human')} ${P('vehicle')}}
 {include {relation {relation enemy} {player "%player"}} ${S('operatable')}}
 {exclude ${S('dead')} ${S('inactive')} ${S('linked')} ${P('airborne')}}}`;
const see=(a,e,max,pair,min=0)=>`{selector ${a}} {enemy ${e}} {distance {mode in_range} {min ${min}} {max ${max}}} {detection visible}${pair?` {tag {"tag pair"} {"for selector" ${pair}}}`:''}`;
const loop=(name,time)=>`{"delay" {time ${time}}}\n{"trigger" {name "${name}"}}`;
const clear=(from,x)=>`{"entity_state" {selector ${tagged(from)}} {tag_remove ${x}}}`;

function abandon(kind,gun,enemy){
 const name=`ufb/gun/abandon ${kind} %player`;
 return `{"${name}"
 {condition {terms {"1.see_actors" ${see(gun,enemy,tune.abandon,'_ufb_gun_flee_%player')}}}}
 {actions
  {"effect" {selector ${tagged('_ufb_gun_flee_%player')}} {effect emit_crew}}
  {"entity_state" {selector ${tagged('_ufb_gun_flee_%player')}} {tag_add _ufb_gun_left_%player}}
  {"con" {text "[UFB gun] crew abandons ${kind} gun: player %player"}}
  {"delay" {time 6}}
  ${clear('_ufb_gun_flee_%player','_ufb_gun_flee_%player')}
  ${loop(name,2)}
 }
}`;
}
function crew(){
 const fresh=`{source advanced} {ignore_captured_by_user 1} {group
 {select ${P('human')}}
 {include {player {player "%player"}} ${S('operatable')}}
 {exclude ${S('dead')} ${S('inactive')} ${S('linked')} ${T('_ufb_gun_crew_%player')}}}`;
 return `{"ufb/gun/crew %player"
 {condition {terms {"1.see_actors" {selector ${fresh}} {enemy ${tagged('_ufb_gun_flee_%player')}}
  {distance {mode near_than} {meters ${tune.crewReach}}}
  {tag {"tag pair"} {"for selector" _ufb_gun_crew_new_%player}}
 }}}
 {actions
  {"effect" {selector ${tagged('_ufb_gun_crew_new_%player')}} {effect ufb_gun_flee_%player}}
  {"delay" {time 0.2}}
  {"action" {selector ${tagged('_ufb_gun_crew_new_%player')}} {drop "orders sensor senseless"} {action move}
   {target ${tagged('_ufb_gun_flee_point_%player')}}}
  ${clear('_ufb_gun_crew_new_%player','_ufb_gun_crew_new_%player')}
  ${loop('ufb/gun/crew %player',0.5)}
 }
}
{"ufb/gun/cover %player"
 {condition {terms {"1.entities" {selector ${tagged('_ufb_gun_cover_%player')}}}}}
 {actions
  {"actor_to_cover" {selector ${tagged('_ufb_gun_cover_%player')}} {drop orders}}
  ${clear('_ufb_gun_cover_%player','_ufb_gun_cover_%player')}
  ${loop('ufb/gun/cover %player',2)}
 }
}
{"ufb/gun/rearm %player"
 {condition {terms {"1.entities" {selector ${tagged('_ufb_gun_left_%player')}}}}}
 {actions
  {"delay" {time 60}}
  ${clear('_ufb_gun_left_%player','_ufb_gun_left_%player')}
  ${loop('ufb/gun/rearm %player',1)}
 }
}`;
}
const botGun=(prop,extra=[])=>`{source advanced} {ignore_captured_by_user 0} {group
 {select ${prop.map(P).join(' ')}}
 {include {player {player "%player"}} ${P('cannon')} ${S('operatable')} ${S('inhabited')}}
 {exclude ${S('user_control')} ${P('fixed')} ${T('_lua_mi')} ${T('bot_arty')} ${T('_ufb_gun_deployed')} ${T('_ufb_gun_left_%player')} ${[...notAGunPit,...extra].join(' ')}}}`;
function fortify(size,event){
 // Only guns the game itself marks as sandbag-capable; no_sandbags never carries these props.
 const gun=`{source advanced} {ignore_captured_by_user 0} {group
 {select ${T('_ufb_gun_deploy_%player')}}
 {include ${P('cannon_sandbag_'+size)}}
 {exclude ${P('no_sandbags')} ${T('_ufb_gun_fort_checked')}}}`;
 return `{"switch"
  {"case" {condition {type see_actors} ${see(gun,anyEnemy,tune.fortifyMinEnemy)}}}
  {"default"
   {"switch"
    {"case" {condition {type rand} {value ${tune.fortifyChance}}}
     {"effect" {selector ${gun}} {effect ${event}}}
     {"con" {text "[UFB gun] bot sandbags ${size}: player %player"}}
    }
   }
   {"entity_state" {selector ${gun}} {tag_add _ufb_gun_fort_checked}}
  }
 }`;
}
function deploy(kind,props,exclude){
 const name=`ufb/gun/deploy ${kind} %player`,[min,max]=tune.deploy[kind];
 const pair='_ufb_gun_deploy_%player';
 return `{"${name}"
 {condition {terms {"1.see_actors" ${see(botGun(props,exclude),anyEnemy,max,pair,min)}}}}
 {actions
  {"entity_state" {selector ${tagged(pair)}} {tag_add _ufb_gun_deployed}}
  {"entity_state" {selector ${tagged(pair)}} {tag_add _lua_mi}}
  {"actor_state" {selector ${tagged(pair)}} {drop orders} {move_mode hold} {cannon fire}}
  {"con" {text "[UFB gun] bot deploys ${kind}: player %player"}}
  {"delay" {time 4}}
  ${fortify('standard','construction_sandbag_cannon_standard_ai')}
  ${fortify('small','construction_sandbag_cannon_shallow_ai')}
  ${clear(pair,pair)}
  ${loop(name,2)}
 }
}`;
}
function release(){
 const gun=`{source advanced} {ignore_captured_by_user 0} {group
 {select ${T('_ufb_gun_deployed')}}
 {include {player {player "%player"}}}
 {exclude ${S('dead')} ${S('inactive')}}}`;
 const seeing=see(gun,anyEnemy,tune.deploy.mortar[1]);
 return `{"ufb/gun/release %player"
 {condition {expression "1 & !2"} {terms {"1.entities" {selector ${gun}}} {"2.see_actors" ${seeing}}}}
 {actions
  {"delay" {time 30}}
  {"if" {condition {type entities} {selector ${gun}}}
   {"switch"
    {"case" {condition {type see_actors} ${seeing}}}
    {"default"
     {"actor_state" {selector ${gun}} {drop orders} {move_mode free} {cannon move}}
     {"entity_state" {selector ${gun}} {tag_remove _lua_mi}}
     {"entity_state" {selector ${gun}} {tag_remove _ufb_gun_deployed}}
     {"con" {text "[UFB gun] bot packs up, no enemy in sight: player %player"}}
    }
   }
  }
  ${loop('ufb/gun/release %player',5)}
 }
}`;
}
function fear(){
 const soldier=`{source advanced} {ignore_captured_by_user 1} {group
 {select ${P('human')}}
 {include {player {player "%player"}} ${S('operatable')}}
 {exclude ${S('dead')} ${S('inactive')} ${S('linked')} ${S('user_control')} ${P('crew')} ${P('repairing')} ${P('throwing')}
 ${[...protectedHumanTags.filter(x=>x!=='_ufb_autonomy_moving'),'_ufb_combat_busy','_ufb_job_reserved','_ufb_tank_fear'].map(T).join(' ')}
 ${['rocketlauncher','at','at_rifle','flame'].map(x=>I(x)).join(' ')}}}`;
 return `{"ufb/fear/tank %player"
 {condition {terms {"1.see_actors" ${see(soldier,armor,tune.tankFear,'_ufb_tank_fear_new_%player')}}}}
 {actions
  {"effect" {selector ${tagged('_ufb_tank_fear_new_%player')}} {effect ufb_tank_fear}}
  {"actor_to_cover" {selector ${tagged('_ufb_tank_fear_new_%player')}} {drop orders}}
  ${clear('_ufb_tank_fear_new_%player','_ufb_tank_fear_new_%player')}
  ${loop('ufb/fear/tank %player',3)}
 }
}`;
}
function mission(){
 const mg=['mg_stan'],mortar=['mortar'];
 let text=`; UFB stationary weapons. See tools/static-weapons.cjs.
(define "ufb_static_weapons"
${abandon('light',lightGun,armor)}
${abandon('heavy',heavyGun,heavyArmor)}
${crew()}
${deploy('mg',mg,[P('mortar')])}
${deploy('mortar',mortar,[])}
${release()}
${fear()}
)
`;
 for(const player of players)text+=`("ufb_static_weapons" player(${player}))\n`;
 return text;
}
function events(){
 let text=`; Crew and infantry events for stationary weapon reactions.
{on "ufb_tank_fear"
 {tags add "_ufb_tank_fear"}
 {talk "alert_tank"}
 {delay 25 {tags remove "_ufb_tank_fear"}}
}
(define "ufb_gun_events"
 {on "ufb_gun_flee_%player"
  {tags add "_ufb_gun_crew_%player"}
  {tags add "_lua_mi"}
  {talk "retreat"}
  {call "ufb_gun_flee_point_%player"}
  {delay 12
   {tags add "_ufb_gun_cover_%player"}
   {tags remove "_lua_mi"}
  }
  {delay 30 {tags remove "_ufb_gun_crew_%player"}}
 }
 {on "ufb_gun_flee_point_%player" sync
  {spawn "ufb_smoke_screen_point" local_offset -700 0 0 constrain_after_dir
   {tags add "_ufb_gun_flee_point_%player"}
   {delay 14 {delete}}
  }
 }
)
`;
 for(const player of players)text+=`("ufb_gun_events" player(${player}))\n`;
 return text;
}
// Louder soldiers from the game's own voice sets; only trigger rates change.
const voiceRates={alert_tank:1,alert_airborne:0.5,in_battle:0.35};
function voices(base){
 for(const [talk,freq]of Object.entries(voiceRates)){
  const next=base.replace(new RegExp(`(\\{talk "${talk}"[^\\n]*\\r?\\n[^\\n]*\\r?\\n\\s*\\{freq )[0-9.]+`),`$1${freq}`);
  if(next===base)throw Error('Voice rate not found: '+talk);
  base=next;
 }
 return base;
}
function expected(ref){return [
 {file:'map/multi/ufb_static_weapons.inc',text:mission()},
 {file:'set/interaction_entity/ufb_static_weapon_events.inc',text:events()},
 {file:'set/talk/voicelines_human.inc',text:voices(fs.readFileSync(p.join(ref,'set/talk/voicelines_human.inc'),'latin1'))}
];}
module.exports={mission,events,voices,expected,tune,voiceRates};
