// Stationary MG/mortar crews: abandon the gun against armor they cannot hurt,
// bot deployment at first contact, native AI sandbags, and bot fear of tanks.
// Only native commands are used: emit_crew, actor_state cannon/move_mode,
// construction_sandbag_cannon_*_ai, actor_to_cover and voice sets.
const fs=require('fs'),p=require('path');
const {protectedHumanTags,sides}=require('./infantry-job-policy.cjs');
const T=x=>`{tag {tag ${x}}}`,P=x=>`{prop {prop ${x}}}`,S=x=>`{state {state ${x}}}`;
const I=(x,type='existance')=>`{with_item {type ${type}} {item "${x}"}}`;
const players=Array.from({length:17},(_,i)=>i); // Only surrender needs a concrete owner.
const tagged=x=>`{ignore_captured_by_user 0} {tag ${x}}`;
// Tunables, in meters unless stated. Real battles may want these adjusted.
const tune={abandon:80,crewReach:7,returnClear:110,fortifyChance:0.6,fortifyMinEnemy:40,deploy:{mg:[40,130],mortar:[60,240],at:[60,220]},holdCalm:90,tankFear:30,bailEnemy:200,bailWait:20,hatchCalm:20,truckStop:150,surrenderEnemy:15,surrenderFriend:25,calmRetreat:2.2,shakenRetreat:1.4};
const hmgProps=['muzzle_hmg','muzzle_hmg_dshk','muzzle_hmg_m2hb','c_mg_heavy'];
// {select} holds only tags, zones and squads: a {prop} there is dropped and the group then
// matches every entity (call_to_arms.exe 0x9dcf50). {include} is "all of", so "A or B" of
// props needs a tag. New spawns get theirs within one classify() pass.
const classes={_ufb_k_tank:['tank'],_ufb_k_armor:['tank','armored_car'],_ufb_k_armor_big:['medium','heavy'],_ufb_k_gun_light:['mg_stan','mortar'],_ufb_k_gun_heavy:hmgProps,_ufb_k_gun_at:['sq_at_gun','sq_at_light']};
// A bunker or ring mount is the cover; 20 mm and the ampulomet can hurt light armor.
const notAGunPit=[P('bunker'),P('hatch'),P('muzzle_20mm_25mm_auto'),S('dead'),S('inactive'),S('linked')];
const gunFor=exclude=>`{source advanced} {ignore_captured_by_user 1} {group
 {select ${T('_ufb_k_gun_light')}}
 {include {team {team %team}} ${P('cannon')} ${S('operatable')} ${S('inhabited')}}
 {exclude ${[...notAGunPit,...exclude].join(' ')}}}`;
const lightGun=gunFor([T('_ufb_gun_left_%team'),...hmgProps.map(P)]);
const heavyGun=`{source advanced} {ignore_captured_by_user 1} {group
 {select ${T('_ufb_k_gun_heavy')}}
 {include {team {team %team}} ${P('cannon')} ${S('operatable')} ${S('inhabited')}}
 {exclude ${[...notAGunPit,T('_ufb_gun_left_%team')].join(' ')}}}`;
const threat=(kind,include=[])=>`{source advanced} {ignore_captured_by_user 0} {group
 {select ${T(kind)}}
 {include {team {team %foe}} ${S('operatable')} ${include.join(' ')}}
 {exclude ${S('dead')} ${S('inactive')} ${S('linked')} ${P('airborne')}}}`;
const armor=threat('_ufb_k_armor'); // Rifle-caliber MG and mortar: all armor.
const heavyArmor=threat('_ufb_k_armor_big',[P('with_gun')]); // 12.7 mm still hurts light armor.
const anyEnemy=`{source advanced} {ignore_captured_by_user 0} {group
 {include {team {team %foe}} ${S('operatable')}}
 {exclude ${S('dead')} ${S('inactive')} ${S('linked')} ${P('airborne')}}}`;
const see=(a,e,max,pair,min=0)=>`{selector ${a}} {enemy ${e}} {distance {mode in_range} {min ${min}} {max ${max}}} {detection visible}${pair?` {tag {"tag pair"} {"for selector" ${pair}}}`:''}`;
const loop=(name,time)=>`{"delay" {time ${time}}}\n{"trigger" {name "${name}"}}`;
const clear=(from,x)=>`{"entity_state" {selector ${tagged(from)}} {tag_remove ${x}}}`;

function abandon(kind,gun,enemy){
 const name=`ufb/gun/abandon ${kind} %team`;
 return `{"${name}"
 {condition {terms {"1.see_actors" ${see(gun,enemy,tune.abandon,'_ufb_gun_flee_%team')}}}}
 {actions
  {"effect" {selector ${tagged('_ufb_gun_flee_%team')}} {effect emit_crew}}
  {"entity_state" {selector ${tagged('_ufb_gun_flee_%team')}} {tag_add _ufb_gun_left_%team}}
  {"entity_state" {selector {source advanced} {ignore_captured_by_user 0} {group {select ${T('_ufb_gun_flee_%team')}} {exclude ${S('user_control')}}}} {tag_add _ufb_gun_return_%team}}
  {"con" {text "[UFB gun] crew abandons ${kind} gun: team %team"}}
  {"delay" {time 6}}
  ${clear('_ufb_gun_flee_%team','_ufb_gun_flee_%team')}
  ${loop(name,2)}
 }
}`;
}
function crew(){
 const fresh=`{source advanced} {ignore_captured_by_user 1} {group
 {include ${P('human')} {team {team %team}} ${S('operatable')}}
 {exclude ${S('dead')} ${S('inactive')} ${S('linked')} ${T('_ufb_gun_crew_%team')}}}`;
 return `{"ufb/gun/crew %team"
 {condition {terms {"1.see_actors" {selector ${fresh}} {enemy {source advanced} {ignore_captured_by_user 0} {group {select ${T('_ufb_gun_flee_%team')}}}}
  {distance {mode near_than} {meters ${tune.crewReach}}}
  {tag {"tag pair"} {"for selector" _ufb_gun_crew_new_%team}}
 }}}
 {actions
  {"effect" {selector ${tagged('_ufb_gun_crew_new_%team')}} {effect ufb_gun_flee_%team}}
  {"delay" {time 0.2}}
  {"action" {selector ${tagged('_ufb_gun_crew_new_%team')}} {drop "orders sensor senseless"} {action move}
   {target ${tagged('_ufb_gun_flee_point_%team')}}}
  ${clear('_ufb_gun_crew_new_%team','_ufb_gun_crew_new_%team')}
  ${loop('ufb/gun/crew %team',0.5)}
 }
}
{"ufb/gun/cover %team"
 {condition {terms {"1.entities" {selector ${tagged('_ufb_gun_cover_%team')}}}}}
 {actions
  {"actor_to_cover" {selector {source advanced} {ignore_captured_by_user 0} {group {select ${T('_ufb_gun_cover_%team')}} {exclude ${S('dead')} ${S('inactive')} ${S('linked')}}}} {drop orders}}
  ${clear('_ufb_gun_cover_%team','_ufb_gun_cover_%team')}
  ${loop('ufb/gun/cover %team',2)}
 }
}
{"ufb/gun/rearm %team"
 {condition {terms {"1.entities" {selector ${tagged('_ufb_gun_left_%team')}}}}}
 {actions
  {"delay" {time 60}}
  ${clear('_ufb_gun_left_%team','_ufb_gun_left_%team')}
  ${loop('ufb/gun/rearm %team',1)}
 }
}`;
}
const botGun=(select,extra=[],also='')=>`{source advanced} {ignore_captured_by_user 0} {group
 {select ${T(select)}}
 {include {team {team %team}} ${P('cannon')} ${S('operatable')} ${S('inhabited')} ${also}}
 {exclude ${S('user_control')} ${P('fixed')} ${T('_lua_mi')} ${T('bot_arty')} ${T('_ufb_gun_deployed')} ${T('_ufb_gun_left_%team')} ${[...notAGunPit,...extra].join(' ')}}}`;
function fortify(size,event){
 // Only guns the game itself marks as sandbag-capable; no_sandbags never carries these props.
 const gun=`{source advanced} {ignore_captured_by_user 0} {group
 {select ${T('_ufb_gun_deploy_%team')}}
 {include ${P('cannon_sandbag_'+size)}}
 {exclude ${P('no_sandbags')} ${T('_ufb_gun_fort_checked')}}}`;
 return `{"switch"
  {"case" {condition {type see_actors} ${see(gun,anyEnemy,tune.fortifyMinEnemy)}}}
  {"default"
   {"switch"
    {"case" {condition {type rand} {value ${tune.fortifyChance}}}
     {"if" {condition {type entities} {selector ${gun}}}
      {"con" {text "[UFB gun] bot sandbags ${size}: team %team"}}
     }
     {"effect" {selector ${gun}} {effect ${event}}}
    }
   }
   {"entity_state" {selector ${gun}} {tag_add _ufb_gun_fort_checked}}
  }
 }`;
}
function deploy(kind,select,exclude,also){
 const name=`ufb/gun/deploy ${kind} %team`,[min,max]=tune.deploy[kind];
 const pair='_ufb_gun_deploy_%team';
 return `{"${name}"
 {condition {terms {"1.see_actors" ${see(botGun(select,exclude,also),anyEnemy,max,pair,min)}}}}
 {actions
  {"entity_state" {selector ${tagged(pair)}} {tag_add _ufb_gun_deployed}}
  {"entity_state" {selector ${tagged(pair)}} {tag_add _lua_mi}}
  {"actor_state" {selector ${tagged(pair)}} {drop orders} {move_mode hold} {cannon fire}}
  {"con" {text "[UFB gun] bot deploys ${kind}: team %team"}}
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
 {include {team {team %team}}}
 {exclude ${S('dead')} ${S('inactive')}}}`;
 const seeing=see(gun,anyEnemy,tune.deploy.mortar[1]);
 return `{"ufb/gun/release %team"
 {condition {expression "1 & !2"} {terms {"1.entities" {selector ${gun}}} {"2.see_actors" ${seeing}}}}
 {actions
  {"delay" {time ${tune.holdCalm}}}
  {"if" {condition {type entities} {selector ${gun}}}
   {"switch"
    {"case" {condition {type see_actors} ${seeing}}}
    {"default"
     {"actor_state" {selector ${gun}} {drop orders} {move_mode free} {cannon move}}
     {"entity_state" {selector ${gun}} {tag_remove _lua_mi}}
     {"entity_state" {selector ${gun}} {tag_remove _ufb_gun_deployed}}
     {"con" {text "[UFB gun] bot packs up, no enemy in sight: team %team"}}
    }
   }
  }
  ${loop('ufb/gun/release %team',5)}
 }
}`;
}
function fear(){
 const soldier=`{source advanced} {ignore_captured_by_user 1} {group
 {include ${P('human')} {team {team %team}} ${S('operatable')}}
 {exclude ${S('dead')} ${S('inactive')} ${S('linked')} ${S('user_control')} ${P('crew')} ${P('repairing')} ${P('throwing')}
 ${[...protectedHumanTags.filter(x=>x!=='_ufb_autonomy_moving'),'_ufb_combat_busy','_ufb_job_reserved','_ufb_tank_fear'].map(T).join(' ')}
 ${['rocketlauncher','at','at_rifle','flame'].map(x=>I(x)).join(' ')}}}`;
 return `{"ufb/fear/tank %team"
 {condition {terms {"1.see_actors" ${see(soldier,armor,tune.tankFear,'_ufb_tank_fear_new_%team')}}}}
 {actions
  {"effect" {selector ${tagged('_ufb_tank_fear_new_%team')}} {effect ufb_tank_fear}}
  {"effect" {selector {amount 1} ${tagged('_ufb_tank_fear_new_%team')}} {effect ufb_tank_fear_shout}}
  {"actor_to_cover" {selector ${tagged('_ufb_tank_fear_new_%team')}} {drop orders}}
  ${clear('_ufb_tank_fear_new_%team','_ufb_tank_fear_new_%team')}
  ${loop('ufb/fear/tank %team',3)}
 }
}`;
}
function gunReturn(){
 const gun=`{source advanced} {ignore_captured_by_user 0} {group
 {select ${T('_ufb_gun_return_%team')}}
 {exclude ${S('inhabited')} ${S('dead')} ${S('inactive')} ${T('destroyed')} ${T('_no-recrew')}}}`;
 const men=`{source advanced} {ignore_captured_by_user 1} {group
 {select ${T('_ufb_gun_back_%team')}}
 {include ${S('operatable')}}
 {exclude ${S('user_control')} ${S('dead')} ${S('inactive')} ${S('linked')} ${T('repairing')}}}`;
 const danger=see(men,armor,tune.returnClear);
 return `{"ufb/gun/return %team"
 {condition {expression "1 & 2 & !3"} {terms {"1.entities" {selector ${gun}}} {"2.entities" {selector ${men}}} {"3.see_actors" ${danger}}}}
 {actions
  {"delay" {time 15}}
  {"switch"
   {"case" {condition {type see_actors} ${danger}}}
   {"default"
    {"board" {selector ${men}} {vehicle ${gun} {amount 1}}}
    {"con" {text "[UFB gun] bot crew returns to its gun: team %team"}}
    ${clear('_ufb_gun_back_%team','_ufb_gun_back_%team')}
    ${clear('_ufb_gun_return_%team','_ufb_gun_return_%team')}
   }
  }
  ${loop('ufb/gun/return %team',5)}
 }
}`;
}
// Only a tank that can neither fight nor leave. Fire is left to the game: _burn plays
// the engine-fire scene and burn_emit decides when the crew gets out.
function tankBail(){
 const helpless=`{source advanced} {ignore_captured_by_user 1} {group
 {include ${P('tank')} {team {team %team}} ${S('inhabited')} ${T('gun_broken')}}
 {exclude ${S('dead')} ${S('inactive')} ${S('linked')} ${S('chassis_work')} ${T('_ufb_tank_bailed')} ${['burned','ammo_broken','ammo_cooked','barrel_fire'].map(T).join(' ')}}}`;
 const seen=see(helpless,anyEnemy,tune.bailEnemy);
 return `{"ufb/tank/bail %team"
 {condition {terms {"1.see_actors" ${seen}}}}
 {actions
  {"delay" {time ${tune.bailWait}}}
  {"if" {condition {type see_actors} ${seen}}
   {"entity_state" {selector ${helpless}} {tag_add _ufb_tank_bail_%team}}
   {"effect" {selector ${tagged('_ufb_tank_bail_%team')}} {effect emit_crew}}
   {"entity_state" {selector ${tagged('_ufb_tank_bail_%team')}} {tag_add _ufb_tank_bailed}}
   ${clear('_ufb_tank_bail_%team','_ufb_tank_bail_%team')}
   {"con" {text "[UFB tank] crew bails out: team %team"}}
  }
  ${loop('ufb/tank/bail %team',3)}
 }
}`;
}
function blastCover(){
 const men=`{source advanced} {ignore_captured_by_user 1} {group
 {select ${T('_ufb_blast_new')}}
 {include {team {team %team}} ${S('operatable')}}
 {exclude ${S('dead')} ${S('inactive')} ${S('linked')} ${S('user_control')} ${P('crew')} ${P('repairing')} ${P('throwing')}
 ${[...protectedHumanTags.filter(x=>x!=='_ufb_autonomy_moving'),'_ufb_combat_busy','_ufb_job_reserved'].map(T).join(' ')}}}`;
 return `{"ufb/fear/blast %team"
 {condition {terms {"1.entities" {selector ${men}}}}}
 {actions
  {"actor_to_cover" {selector ${men}} {drop orders}}
  {"entity_state" {selector ${men}} {tag_remove _ufb_blast_new}}
  ${loop('ufb/fear/blast %team',0.5)}
 }
}`;
}
function mgShout(){
 const pair='_ufb_mg_shout_%team',men=`{source advanced} {ignore_captured_by_user 0} {group
 {include ${P('human')} {team {team %team}} ${S('operatable')}}
 {exclude ${S('dead')} ${S('inactive')} ${S('linked')}}}`;
 const foe=include=>`{source advanced} {ignore_captured_by_user 0} {group
 {include {team {team %foe}} ${S('operatable')} ${include}}
 {exclude ${S('dead')} ${S('inactive')} ${S('linked')}}}`;
 return `{"ufb/shout/mg %team"
 {condition {expression "1 | 2"} {terms
  {"1.see_actors" ${see(men,foe(P('mg_stan')+' '+S('inhabited')),130,pair)}}
  {"2.see_actors" ${see(men,foe(P('human')+' '+I('mgun','using')+' '+T('_ufb_firing')),130,pair)}}
 }}
 {actions
  {"effect" {selector {amount 1} ${tagged(pair)}} {effect ufb_mg_shout}}
  ${clear(pair,pair)}
  ${loop('ufb/shout/mg %team',45)}
 }
}`;
}
// A side marks a lone wounded enemy; the claim passes him to the human actually next to him.
// HF's fixed player 0 may not be the user outside Conquest.
function surrender(){
 const pair='_ufb_surrender_%team',helped='_ufb_surrender_helped_%team';
 const victim=`{source advanced} {ignore_captured_by_user 0} {group
 {select ${T('_ufb_was_hit')}}
 {include ${P('human')} ${S('operatable')} {team {team %foe}}}
 {exclude ${S('user_control')} ${S('dead')} ${S('inactive')} ${S('linked')} ${T('start_personage')} ${T('_bleedout_')} ${T('wounded_animation_playing')} ${T('_lua_mi')} ${T('_ufb_surrendered')} ${T('medic')}}}`;
 const captor=`{source advanced} {ignore_captured_by_user 0} {group
 {include ${P('human')} {team {team %team}} ${S('user_control')} ${S('operatable')}}
 {exclude ${S('dead')} ${S('inactive')} ${S('linked')}}}`;
 const friend=`{source advanced} {ignore_captured_by_user 0} {group
 {include {team {team %foe}} ${S('operatable')}}
 {exclude ${S('dead')} ${S('inactive')} ${T('_ufb_was_hit')}}}`;
 const idle=`{source advanced} {ignore_captured_by_user 1} {group
 {select ${T('_ufb_prisoner')}}
 {include {team {team %team}} ${S('operatable')}}
 {exclude ${S('dead')} ${S('inactive')} ${S('linked')} ${T('_ufb_autonomy_moving')}}}`;
 const prisoner=tagged(pair),still=`{"actor_state" {selector ${prisoner}} {drop orders} {fire_mode hold} {move_mode free} {ai_move {mode disable}} {movement {speed slow} {type normal}}}`;
 return `{"ufb/surrender/mark %team"
 {condition {terms {"1.see_actors" ${see(victim,captor,tune.surrenderEnemy,pair)}}}}
 {actions
  {"delay" {time 2}}
  ${still}
  {"entity_state" {selector ${prisoner}} {tag_add _ufb_surrendered}}
  {"entity_state" {selector ${prisoner}} {tag_add _ufb_native_pickup_initialized}}
  {"entity_state" {selector ${prisoner}} {tag_add _ufb_prisoner_unclaimed}}
  {"delay" {time 0.5}}
  {"inventory" {selector ${prisoner}} {action drop}}
  {"delay" {time 2}}
  ${still}
  {"delay" {time 0.5}}
  {"entity_state" {selector ${prisoner}} {tag_add _ufb_prisoner}}
  {"if" {condition {type entities} {selector ${prisoner}}}
   {"con" {text "[UFB surrender] wounded soldier gives up to team %team"}}
  }
  ${clear(pair,pair)}
  ${loop('ufb/surrender/mark %team',4)}
 }
}
{"ufb/surrender/hands %team"
 {condition {terms {"1.entities" {selector ${idle}}}}}
 {actions
  {"animation" {selector ${idle}} {drop sensor} {collage stand_giveup_1} {cicledelay 0} {delay 0} {totalTime 8} {flags loop}}
  ${loop('ufb/surrender/hands %team',7)}
 }
}
{"ufb/surrender/helped %team"
 {condition {terms {"1.see_actors" {selector {source advanced} {ignore_captured_by_user 0} {group {select ${T(pair)}}}} {enemy ${friend}} {distance {mode in_range} {min 0} {max ${tune.surrenderFriend}}} {tag {"tag pair"} {"for selector" ${helped}}}}}}
 {actions
  ${clear(helped,pair)}
  ${clear(helped,helped)}
  ${loop('ufb/surrender/helped %team',0.3)}
 }
}`;
}
// The engine already weighs nearby strength and shouts "retreat"; these only make bots break sooner.
function surrenderClaim(){
 return `(define "ufb_surrender_claim"
 {"ufb/surrender/claim %player"
  {condition {terms {"1.see_actors"
   {selector {source advanced} {ignore_captured_by_user 0} {group {select ${T('_ufb_prisoner_unclaimed')}} {exclude ${S('dead')} ${S('inactive')}}}}
   {enemy {source advanced} {ignore_captured_by_user 0} {group {include ${P('human')} {player {player "%player"}} ${S('user_control')} ${S('operatable')}} {exclude ${S('dead')} ${S('inactive')} ${S('linked')}}}}
   {distance {mode in_range} {min 0} {max ${tune.surrenderEnemy+10}}}
   {tag {"tag pair"} {"for selector" _ufb_prisoner_mine_%player}}
  }}}
  {actions
   {"player" {selector ${tagged('_ufb_prisoner_mine_%player')}} {operation set} {player "%player"}}
   ${clear('_ufb_prisoner_mine_%player','_ufb_prisoner_unclaimed')}
   ${clear('_ufb_prisoner_mine_%player','_ufb_prisoner_mine_%player')}
   ${loop('ufb/surrender/claim %player',0.5)}
  }
 }
)`;
}
// Scripts cannot reach the native hatch button. ufb_hatch.dll turns this crew_enable into the
// engine's own SetSealed: the crew really goes inside. Without the DLL no seat has this
// group, so the command does nothing and the tank behaves as in the base game.
// Sealing keeps the crew "in place", so the game never plays its own lid animation for it.
// Armored cars are left out: their seats are open and these events move other parts.
function lids(state){
 const seat=place=>state==='open'?`{if has_place "${place}" {if crew_in_place "${place}" {call "${place}_hatch_open"}}}`:`{if has_place "${place}" {call "${place}_hatch_close"}}`;
 return ` {on "ufb_hatch_lids_${state}"
  {if tagged "_ufb_k_tank"
   ${['commander','charger','charger2'].map(seat).join('\n   ')}
  }
 }`;
}
function hatchBlock(){
 return `; UFB: tanks button up under fire and open again when it is quiet. See tools/native/ufb_hatch.cpp.
{"tank"
 {on bullet_hit {call "ufb_hatch_danger"}}
 {on blast_hit {call "ufb_hatch_danger"}}
 {on "ufb_hatch_danger"
  {if operatable
   {tags add "_ufb_hatch_hit"}
   {if not tagged "_ufb_hatch_shut"
    {tags add "_ufb_hatch_shut"}
    {delay 0.1 {crew_enable group "ufb_hatch" 0} {call "ufb_hatch_lids_close"}} ; never inside the hit calculation itself
    {call "ufb_hatch_wait"}
   }
  }
 }
${lids('close')}
${lids('open')}
 {on "ufb_hatch_wait"
  {tags remove "_ufb_hatch_hit"}
  {delay ${tune.hatchCalm}
   {if tagged "_ufb_hatch_hit"
    {call "ufb_hatch_wait"}
   else
    {tags remove "_ufb_hatch_shut"}
    {tags remove "_ufb_hatch_logged"}
    {crew_enable group "ufb_hatch" 1}
    {call "ufb_hatch_lids_open"}
   }
  }
 }
}
`;
}
// Motorized squads are one Lua squad, so a capture order drives the truck into the enemy.
function truckDismount(){
 const pair='_ufb_truck_stop_%team',name='ufb/truck/dismount %team';
 const truck=`{source advanced} {ignore_captured_by_user 1} {group
 {include ${P('car')} {team {team %team}} ${S('inhabited')} ${S('operatable')}}
 {exclude ${S('user_control')} ${S('dead')} ${S('inactive')} ${S('linked')} ${P('armored_car')} ${P('tank')} ${P('with_gun')} ${T('_ufb_truck_stopped')} ${['_lua_mi','hidden','bot_towing','tow_act','offmap_supply_on_map','offmap_supply_deployed'].map(T).join(' ')}}}`;
 return `{"${name}"
 {condition {terms {"1.see_actors" ${see(truck,anyEnemy,tune.truckStop,pair)}}}}
 {actions
  {"emit" {selector {ignore_captured_by_user 0} {tag ${pair}} {type vehicle} {state inhabited}} {drop orders}}
  {"entity_state" {selector ${tagged(pair)}} {tag_add _ufb_truck_stopped}}
  ${clear(pair,pair)}
  {"con" {text "[UFB truck] infantry dismounts before contact: team %team"}}
  ${loop(name,3)}
 }
}`;
}
function hatchLog(){
 const shut=`{source advanced} {ignore_captured_by_user 0} {group
 {select ${T('_ufb_hatch_shut')}}
 {include {team {team %team}}}
 {exclude ${T('_ufb_hatch_logged')}}}`;
 return `{"ufb/hatch/log %team"
 {condition {terms {"1.entities" {selector ${shut}}}}}
 {actions
  {"entity_state" {selector ${shut}} {tag_add _ufb_hatch_logged}}
  {"con" {text "[UFB hatch] tank buttons up: team %team"}}
  ${loop('ufb/hatch/log %team',5)}
 }
}`;
}
function morale(){
 const bots=(select,exclude)=>`{source advanced} {ignore_captured_by_user 0} {group
 ${select?`{select ${select}}`:''}
 {include ${P('human')} ${S('operatable')}}
 {exclude ${S('user_control')} ${S('dead')} ${S('inactive')} ${S('linked')} ${P('crew')} ${exclude}}}`;
 const fresh=bots('',T('_ufb_morale')),hurt=bots(T('_ufb_recent_hit'),T('_ufb_shaken')),calm=bots(T('_ufb_steady'),'');
 const step=(name,who,ratio,actions)=>`{"${name}"
 {condition {terms {"1.entities" {selector ${who}}}}}
 {actions
  {"actor_state" {selector ${who}} {ai {retreat_ratio "${ratio}"}}}
  ${actions}
  ${loop(name,3)}
 }
}`;
 return [step('ufb/morale/profile',fresh,tune.calmRetreat,`{"entity_state" {selector ${fresh}} {tag_add _ufb_morale}}`),
  step('ufb/morale/shaken',hurt,tune.shakenRetreat,`{"effect" {selector ${hurt}} {effect ufb_shaken}}`),
  step('ufb/morale/steady',calm,tune.calmRetreat,`${clear('_ufb_steady','_ufb_shaken')}\n  ${clear('_ufb_steady','_ufb_steady')}`)].join('\n');
}
// One pass every 3 s. Separate triggers would be polled against every entity all the time.
function classify(){
 const who=(tag,prop)=>`{source advanced} {ignore_captured_by_user 0} {group {include ${P(prop)}} {exclude ${T(tag)}}}`;
 const steps=Object.entries(classes).flatMap(([tag,props])=>props.map(prop=>`{"entity_state" {selector ${who(tag,prop)}} {tag_add ${tag}}}`));
 return `{"ufb/class"
 {condition {terms {"1.entities" {selector {source advanced} {ignore_captured_by_user 0} {group {include ${P('human')}}}}}}}
 {actions
  ${steps.join('\n  ')}
  ${loop('ufb/class',3)}
 }
}`;
}
function mission(){
 let text=`; UFB stationary weapons. See tools/static-weapons.cjs.
${classify()}
${morale()}
${surrenderClaim()}
(define "ufb_static_weapons"
${abandon('light',lightGun,armor)}
${abandon('heavy',heavyGun,heavyArmor)}
${crew()}
${deploy('mg','_ufb_k_gun_light',[P('mortar')])}
${deploy('mortar','_ufb_k_gun_light',[],P('mortar'))}
${deploy('at','_ufb_k_gun_at',[P('mg_stan'),P('mortar')])}
${gunReturn()}
${tankBail()}
${blastCover()}
${mgShout()}
${surrender()}
${release()}
${fear()}
${hatchLog()}
${truckDismount()}
)
`;
 for(const [team,foe] of sides)text+=`("ufb_static_weapons" team(${team}) foe(${foe}))\n`;
 for(const player of players)text+=`("ufb_surrender_claim" player(${player}))\n`;
 return text;
}
function events(){
 let text=`; Crew and infantry events for stationary weapon reactions.
{on "ufb_tank_fear"
 {tags add "_ufb_tank_fear"}
 {delay 25 {tags remove "_ufb_tank_fear"}}
}
{on "ufb_tank_fear_shout" {talk "alert_tank"}}
{on "ufb_mg_shout" {talk "ufb_alert_mgun"}}
{on "ufb_near_blast"
 {if not tagged "_ufb_blast_cover"
  {tags add "_ufb_blast_cover"}
  {tags add "_ufb_blast_new"}
  {delay 1 {tags remove "_ufb_blast_new"}}
  {delay 20 {tags remove "_ufb_blast_cover"}}
 }
}
{on "ufb_shaken"
 {tags add "_ufb_shaken"}
 {delay 40 {tags add "_ufb_steady"}}
}
(define "ufb_gun_events"
 {on "ufb_gun_flee_%team"
  {tags add "_ufb_gun_crew_%team"}
  {tags add "_ufb_gun_back_%team"}
  {tags add "_lua_mi"}
  {talk "retreat"}
  {call "ufb_gun_flee_point_%team"}
  {delay 12
   {tags add "_ufb_gun_cover_%team"}
   {tags remove "_lua_mi"}
  }
  {delay 30 {tags remove "_ufb_gun_crew_%team"}}
  {delay 120 {tags remove "_ufb_gun_back_%team"}}
 }
 {on "ufb_gun_flee_point_%team" sync
  {spawn "ufb_smoke_screen_point" local_offset -700 0 0 constrain_after_dir
   {tags add "_ufb_gun_flee_point_%team"}
   {delay 14 {delete}}
  }
 }
)
`;
 for(const [team] of sides)text+=`("ufb_gun_events" team(${team}))\n`;
 return text;
}
// Louder soldiers from the game's own voice sets; only trigger rates change.
const voiceRates={alert_tank:1,alert_airborne:0.5,in_battle:0.35,'ally die':1,bleeding_out:1,alert_at_gun:0.8};
const tankVoiceRates={tank_alert_airborne:0.5,tank_in_battle:0.35,'tank_bullet missed':0.4};
const mgLine='\r\n{talk "ufb_alert_mgun"\t;// UFB: scripted, real machine guns only\r\n\t("human_phrases" args alert_mgun)\r\n\t{freq 1}\r\n}\r\n';
function rates(base,table){
 for(const [talk,freq]of Object.entries(table)){
  const next=base.replace(new RegExp(`(\\{talk "${talk}"[^\\n]*\\r?\\n[^\\n]*\\r?\\n\\s*\\{freq )[0-9.]+`),`$1${freq}`);
  if(next===base)throw Error('Voice rate not found: '+talk);
  base=next;
 }
 return base;
}
const voices=base=>rates(base,voiceRates)+mgLine;
function expected(ref){return [
 {file:'map/multi/ufb_static_weapons.inc',text:mission()},
 {file:'set/interaction_entity/ufb_static_weapon_events.inc',text:events()},
 {file:'set/talk/voicelines_human.inc',text:voices(fs.readFileSync(p.join(ref,'set/talk/voicelines_human.inc'),'latin1'))},
 {file:'set/talk/voicelines_tank.inc',text:rates(fs.readFileSync(p.join(ref,'set/talk/voicelines_tank.inc'),'latin1'),tankVoiceRates)},
 {file:'set/interaction_entity/ufb_tank_hatch.inc',text:hatchBlock()}
];}
module.exports={mission,events,voices,expected,tune,voiceRates,tankVoiceRates,mgLine,hatchBlock};
