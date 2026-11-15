const {protectedHumanTags,sides}=require('./infantry-job-policy.cjs');
const T=x=>`{tag {tag ${x}}}`,P=x=>`{prop {prop ${x}}}`,S=x=>`{state {state ${x}}}`;
const I=(x,type='existance')=>`{with_item {type ${type}} {item "${x}"}${type==='amount'?' {min 1}':''}}`;
const tagged=(tag,captured=0)=>`{ignore_captured_by_user ${captured}} {tag ${tag}}`;
function sel({pick='',include=[],exclude=[],one=false,captured=1}={}){return `{source advanced} {ignore_captured_by_user ${captured}} ${one?'{amount 1}':''} {group ${pick?`{select ${T(pick)}}`:''} {include ${include.join(' ')}} {exclude ${exclude.join(' ')}}}`;}
const alive=[P('human'),S('operatable')],invalid=[S('dead'),S('inactive'),S('linked'),T('bleeding'),T('_bleedout_')];
const enemy=sel({captured:0,include:[S('operatable'),'{team {team %foe}}'],exclude:[S('dead'),S('inactive'),S('linked')]});
const see=(a,b,max,at,bt,visible=false)=>`{selector ${a}} {enemy ${b}} {distance {mode near_than} {meters ${max}}} ${visible?'{detection visible}':''} ${at?`{tag {"tag pair"} {"for selector" ${at}} ${bt?`{"for enemy" ${bt}}`:''}}`:''}`;
const state=(who,key,tag)=>`{"entity_state" {selector ${who}} {${key} ${tag}}}`;
const effect=(who,event)=>`{"effect" {selector ${who}} {effect ${event}}}`;
const clear=tag=>state(tagged(tag),'tag_remove',tag);
const action=(who,name,target)=>`{"action" {selector ${who}} {action ${name}} {target ${target}}}`;
const near=(who,to,d)=>`{units ${who}} {near_to ${to}} {distance ${d}}`;
const exists=who=>`{type entities} {selector ${who}}`;
const pause=t=>`{"delay" {time ${t}}}`;
const loop=(name,t)=>`${pause(t)} {"trigger" {name "${name}"}}`;
function rescue(){
 const role='_ufb_rescue_actor_%team',patient='_ufb_rescue_patient_%team',goal='_ufb_rescue_goal_%team',threat='_ufb_rescue_threat_%team';
 const raw=tagged(role),active=sel({pick:role,include:[...alive,S('user_control'),T('_ufb_rescue_active'),'{team {team %team}}'],exclude:invalid,one:true});
 const idle=sel({include:[...alive,S('user_control'),'{team {team %team}}'],exclude:[...invalid,P('crew'),P('repairing'),P('throwing'),I('human'),...protectedHumanTags.map(T),T('_ufb_job_reserved'),T('_ufb_combat_busy'),T('_ufb_rescue_cooldown')]});
 const hurt=sel({captured:0,include:[P('human'),S('user_control'),T('bleeding'),'{team {team %team}}'],exclude:[S('dead'),S('inactive'),S('linked'),T('_ufb_rescue_patient'),T('_ai_wounded_target_linked') ]});
 const casualty=sel({captured:0,pick:patient,include:[P('human'),T('bleeding')],exclude:[S('dead'),S('inactive'),S('linked')],one:true});
 const medic=sel({captured:0,pick:'medic',include:[...alive,'{team {team %team}}'],exclude:invalid});
 const carrying=sel({pick:role,include:[...alive,S('user_control'),T('_ufb_rescue_active'),T('_ufb_rescue_route'),I('human')],exclude:invalid,one:true});
 const origin=tagged('_ufb_rescue_origin_%team'),destination=tagged(goal);
 const threatProbe=`{"if" {condition {type see_actors} ${see(active,enemy,90,role,threat,true)}}}`;
 const returnSafe=`{"switch" {"case" {condition {type near} ${near(origin,tagged(threat),30)}}} {"default" ${action(active,'move',origin)}}}`;
 // Timed 1s scan replaces the polled rand+see_actors condition (engine short-circuit is unknown); success still waits 10s.
 return `(define "ufb_rescue"
 {"ufb/rescue/acquire %team"
  {condition {terms {"1.rand" {value 1}}}}
  {actions
   {"if" {condition {type see_actors} ${see(idle,hurt,6)}}
   {"switch" {"case" {condition {type see_actors} ${see(idle,enemy,15,null,null,true)}}} {"default"
   {"if" {condition {type see_actors} ${see(idle,hurt,6,'_ufb_rescue_carrier_pick_%team')}}}
   ${state('{amount 1} '+tagged('_ufb_rescue_carrier_pick_%team'),'tag_add',role)}
   ${clear('_ufb_rescue_carrier_pick_%team')}
   ${state(raw,'tag_add','_ufb_rescue_active')}
   {"if" {condition {type see_actors} ${see(active,hurt,6,role,'_ufb_rescue_patient_pick_%team')}}}
   ${state('{amount 1} '+tagged('_ufb_rescue_patient_pick_%team'),'tag_add',patient)}
   ${state(tagged(patient),'tag_add','_ufb_rescue_patient')}
   ${clear('_ufb_rescue_patient_pick_%team')}
   ${effect(active,'ufb_rescue_points_%team')}
   ${effect(raw,'ufb_rescue_cooldown')}
   ${threatProbe}
   {"if" {condition {type see_actors} ${see(active,medic,45,role,'_ufb_rescue_medic_pick_%team')}}
    ${state('{amount 1} '+tagged('_ufb_rescue_medic_pick_%team'),'tag_add',goal)}
   }
   ${clear('_ufb_rescue_medic_pick_%team')}
   {"switch"
    {"case" {condition ${exists(destination)}}}
    {"default" ${state(tagged('_ufb_rescue_rear_%team'),'tag_add',goal)}}
   }
   {"switch"
    {"case" {condition {type near} ${near(destination,tagged(threat),30)}}}
    {"default"
     {"if" {condition ${exists(casualty)}}
      ${state(raw,'tag_add','_ufb_rescue_route')}
      ${action(active,'collect',casualty)}
      {"con" {text "[UFB rescue] pickup order: team %team"}}
     }
    }
   }
   ${pause(6)}
   ${threatProbe}
   {"switch" {"case" {condition {type near} ${near(destination,tagged(threat),30)}}} {"default" ${action(carrying,'move',destination)}}}
   ${pause(14)}
   {"inventory" {selector ${carrying}} {action drop} {item "human"} {amount 1}}
   ${pause(2)}
   ${threatProbe}
   {"if" {condition ${exists(sel({pick:role,include:[...alive,T('_ufb_rescue_active'),T('_ufb_rescue_route')],exclude:[...invalid,I('human')],one:true}))}} ${returnSafe}}
   ${pause(24)}
   ${state(raw,'tag_remove','_ufb_rescue_active')}
   ${state(raw,'tag_remove','_ufb_rescue_route')}
   ${state(tagged(patient),'tag_remove','_ufb_rescue_patient')}
   ${clear(role)} ${clear(patient)} ${clear(goal)} ${clear(threat)}
   {"delete" {selector ${origin}}}
   {"delete" {selector ${tagged('_ufb_rescue_rear_%team')}}}
   ${pause(9)}
   }}}
   ${loop('ufb/rescue/acquire %team',1)}
  }
 }
 ; Once the user captures the carrier, this job can never resume later on deselection.
 {"ufb/rescue/manual %team"
  {condition {expression "1 & !2"} {terms
   {"1.entities" {selector ${sel({captured:0,pick:role,include:[T('_ufb_rescue_active')]})}}}
   {"2.entities" {selector ${sel({pick:role,include:[T('_ufb_rescue_active')]})}}}
  }}
  {actions ${state(raw,'tag_remove','_ufb_rescue_active')} ${loop('ufb/rescue/manual %team',0.5)}}
 }
)`;
}
function smoke(){
 const role='_ufb_medic_smoke_actor_%team',point='_ufb_medic_smoke_point_%team';
 const medic=sel({pick:'medic',include:[...alive,'{team {team %team}}',I('smoke','amount')],exclude:[...invalid,P('repairing'),P('throwing'),T('_ufb_healing_active'),T('_ufb_job_reserved'),T('_ufb_combat_busy'),T('_ufb_medic_smoke_cooldown'),T('_ufb_rescue_active'),I('rocketlauncher','using'),...['m15_wp','m42_wp','no77_wp'].map(x=>I(x))]});
 const active=sel({pick:role,one:true,include:[...alive,I('smoke','amount')],exclude:[...invalid,P('throwing'),T('_ufb_healing_active')]});
 const hurt=sel({captured:0,include:[P('human'),T('bleeding'),'{team {team %team}}'],exclude:[S('dead'),S('inactive'),S('linked')]});
 return `(define "ufb_medic_smoke"
 {"ufb/medic/smoke %team"
  {condition {expression "1 & 2"} {terms
   {"1.see_actors" ${see(medic,hurt,18)}}
   {"2.see_actors" ${see(medic,enemy,90,null,null,true)}}
  }}
  {actions
   {"if" {condition {type see_actors} ${see(medic,hurt,18,role)}}}
   {"if" {condition {type see_actors} ${see(active,enemy,90,null,null,true)}}
   ${effect(active,'ufb_reserve_job')}
   ${effect(active,'ufb_medic_smoke_point_%team')}
   ${effect(active,'ufb_medic_smoke_cooldown')}
   ${action(active,'throw_sk_grenade',tagged(point))}
   }
   ${clear(role)}
   {"con" {text "[UFB medic] protective smoke: team %team"}}
   ${loop('ufb/medic/smoke %team',4)}
  }
 }
)`;
}
function mission(){let out=rescue()+'\n'+smoke()+'\n';for(const [team,foe]of sides)for(const kind of ['rescue','medic_smoke'])out+=`("ufb_${kind}" team(${team}) foe(${foe}))\n`;return out;}
function events(){let out=`{on "ufb_supply_cooldown" {tags add "_ufb_supply_cooldown"} {delay 12 {tags remove "_ufb_supply_cooldown"}}}
{on "ufb_rescue_cooldown" {tags add "_ufb_rescue_cooldown"} {delay 90 {tags remove "_ufb_rescue_cooldown"}}}
{on "ufb_medic_smoke_cooldown" {tags add "_ufb_medic_smoke_cooldown"} {delay 35 {tags remove "_ufb_medic_smoke_cooldown"}}}
(define "ufb_medical_points"
 {on "ufb_rescue_points_%team" sync
  {spawn "ufb_smoke_screen_point" "basis" x {tags add "_ufb_rescue_origin_%team"} {delay 70 {delete}}}
  {spawn "ufb_smoke_screen_point" local_offset -500 0 0 constrain_after_dir {tags add "_ufb_rescue_rear_%team"} {delay 70 {delete}}}
 }
 {on "ufb_medic_smoke_point_%team" sync
  {spawn "ufb_smoke_screen_point" local_offset 160 0 0 constrain_after_dir {tags add "_ufb_medic_smoke_point_%team"} {delay 3 {delete}}}
 }
)
`;for(const [team]of sides)out+=`("ufb_medical_points" team(${team}))\n`;return out;}
function expected(){return [{file:'map/multi/ufb_medical_support.inc',text:mission()},{file:'set/interaction_entity/ufb_medical_events.inc',text:events()}];}
module.exports={mission,events,expected};
