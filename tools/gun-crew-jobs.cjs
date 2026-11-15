// Bounded per-gun leases. Capture real linked crew before emit_crew, never nearby infantry.
const fs=require('fs'),p=require('path'),assert=require('assert/strict'),s=require('./lib/sdl.cjs');
const {protectedHumanTags,sides}=require('./infantry-job-policy.cjs');
const SLOTS=16,RETURN_DISTANCE=80,LEASE_SECONDS=140,JOB_SECONDS=120;
const T=x=>`{tag {tag ${x}}}`,P=x=>`{prop {prop ${x}}}`,S=x=>`{state {state ${x}}}`;
const tag=(kind,slot)=>`_ufb_gun_${kind}_${slot}_%team`;
const simple=t=>`{ignore_captured_by_user 0} {tag ${t}}`;
const exists=who=>`{type entities} {selector ${who}}`;
const name=(kind,slot)=>`ufb/gun/${kind}${slot?' '+slot:''} %team`;
const clear=(who,t)=>`{"entity_state" {selector ${who}} {tag_remove ${t}}}`;
const loop=(kind,slot,time)=>`{"delay" {time ${time}}} {"trigger" {name "${name(kind,slot)}"}}`;
function men(slot,{bot=false,cover=false,eligible=true}={}){
 const blocked=protectedHumanTags.filter(t=>!['_ufb_gun_job_active','crew','tcrew','ecrew','ecrew_a','ecrew_b'].includes(t));
 return `{source advanced} {ignore_captured_by_user 1} {group {select ${T(tag(cover?'cover':'crew',slot))}}
 {include ${P('human')} ${S('operatable')} {team {team %team}}}
 {exclude ${S('dead')} ${S('inactive')} ${S('linked')} ${bot?S('user_control'):''} ${eligible?[P('repairing'),P('throwing'),...blocked.map(T),'_ufb_combat_busy','_ufb_job_reserved'].map(x=>x.startsWith('{')?x:T(x)).join(' '):''}}}`;
}
function gun(slot,free=false){return `{source advanced} {ignore_captured_by_user 1} {group {select ${T(tag('owner',slot))}}
 {include ${P('cannon')} ${S('operatable')} {team {team %team}}} {exclude ${S('dead')} ${S('inactive')} ${free?`${S('inhabited')} ${T('destroyed')} ${T('"_no-recrew"')}`:''}}}`;}
const releaseMen=slot=>`{"effect" {selector ${simple(tag('crew',slot))}} {effect ufb_gun_release_${slot}_%team}}`;
function allocation(){
 const pending='_ufb_gun_flee_%team';let text='';
 for(let slot=0;slot<SLOTS;slot++){
  const owner=simple(tag('owner',slot)),point=simple(tag('lease',slot));
  text+=`{"switch" {"case" {condition ${exists(point)}}} {"default"
   {"switch" {"case" {condition ${exists(owner)}}} {"default"
    {"if" {condition ${exists(simple(pending))}}
     {"entity_state" {selector {amount 1} ${simple(pending)}} {tag_add ${tag('owner',slot)}}}
     ${clear(owner,pending)}
     {"effect" {selector ${owner}} {effect ufb_gun_bind_${slot}_%team}}
     {"if" {condition ${exists(point)}} {"effect" {selector ${gun(slot)}} {effect emit_crew}}}
    }
   }}
  }}\n`;
 }
 // Capacity overflow uses native dismount only; it cannot steal another gun's crew lease.
 return text+`{"effect" {selector ${simple(pending)}} {effect ufb_gun_left_cooldown_%team}}
 {"effect" {selector ${simple(pending)}} {effect emit_crew}}
 ${clear(simple(pending),pending)}`;
}
function mission(armor,see){let out='';
 for(let slot=0;slot<SLOTS;slot++){
  const crew=men(slot),owner=gun(slot,true),lease=simple(tag('lease',slot));
  // near is existential. Select one nearest eligible man so the same distance
  // check also bounds the person who actually receives board, not a whole group.
  const returning=men(slot,{bot:true}).replace('{source advanced}',`{source advanced} {amount 1} {sort {type entity} {entity ${owner}}}`);
  const pending=tag('escaped',slot),notEscaped=`{source advanced} {ignore_captured_by_user 0} {group {select ${T(tag('owner',slot))}} {exclude ${T(pending)}}}`;
  const close=`{units ${returning}} {near_to ${owner}} {distance ${RETURN_DISTANCE}}`;
  const danger=see(returning,armor,110);
  const inhabited=`{source advanced} {ignore_captured_by_user 0} {group {select ${T(tag('owner',slot))}} {include ${S('inhabited')}}}`;
  const cleanup=`${releaseMen(slot)} {"effect" {selector ${simple(tag('owner',slot))}} {effect ufb_gun_release_owner_${slot}_%team}}`;
  const returnGate=`{"if" {condition ${exists(owner)}} {"if" {condition {type near} ${close}}
   {"switch" {"case" {condition {type see_actors} ${danger}}} {"default"
    {"board" {selector ${returning}} {vehicle ${owner} {amount 1}}}
   }}
  }}`;
  out+=`{"${name('crew',slot)}"
 {condition {expression "1 & 2"} {terms {"1.entities" {selector ${crew}}} {"2.entities" {selector ${notEscaped}}}}}
 {actions
  {"entity_state" {selector ${simple(tag('owner',slot))}} {tag_add ${pending}}}
  {"effect" {selector ${crew}} {effect ufb_gun_escape_${slot}_%team}}
  {"delay" {time 0.2}}
  {"if" {condition ${exists(lease)}} {"action" {selector ${crew}} {drop "orders sensor senseless"} {action move} {target ${lease}}}}
  ${loop('crew',slot,0.5)}
 }
}
{"${name('cover',slot)}"
 {condition {terms {"1.entities" {selector ${men(slot,{cover:true})}}}}}
 {actions
  {"actor_to_cover" {selector ${men(slot,{cover:true})}} {drop orders}}
  ${clear(simple(tag('cover',slot)),tag('cover',slot))}
  ${loop('cover',slot,1)}
 }
}
{"${name('return',slot)}"
 {condition {expression "4 | (1 & 2 & !3)"} {terms {"1.entities" {selector ${owner}}} {"2.near" ${close}} {"3.see_actors" ${danger}} {"4.entities" {selector ${inhabited}}}}}
 {actions
  {"switch" {"case" {condition ${exists(inhabited)}} ${cleanup}} {"default"
  {"delay" {time 15}}
  ${returnGate}
  {"delay" {time 0.5}}
  {"if" {condition ${exists(inhabited)}}
   ${cleanup}
  }
  }}
  ${loop('return',slot,1)}
 }
}
`;
 }
 return out;
}
const seats=['commander','driver',...['gunner','charger','loader','seat'].flatMap(x=>[...(x==='seat'?[]:[x]),...Array.from({length:x==='seat'?15:8},(_,i)=>x+(i+1))])];
function bindings(){let body='{\"vehicle\"\n {on "ufb_gun_left_cooldown_%team" {tags add "_ufb_gun_left_%team"} {kill_delay "ufb_gun_left_expiry"} {delay 60 "ufb_gun_left_expiry" {tags remove "_ufb_gun_left_%team"}}}\n';
 for(let slot=0;slot<SLOTS;slot++)body+=`{on "ufb_gun_bind_${slot}_%team" sync
  {call "ufb_gun_left_cooldown_%team"} {tags add "_ufb_gun_bound"}
  {kill_delay "ufb_gun_owner_expiry"}
  {delay ${JOB_SECONDS} "ufb_gun_owner_expiry" {call "ufb_gun_release_owner_${slot}_%team"}}
  {spawn "ufb_smoke_screen_point" local_offset -700 0 0 constrain_after_dir {tags add "${tag('lease',slot)}"} {delay ${LEASE_SECONDS} {delete}}}
  ${seats.map(seat=>`{if has_place "${seat}" {if crew_in_place "${seat}" {with_linked_entity "${seat}" {call "ufb_gun_bind_man_${slot}_%team"}}}}`).join('\n')}
 }
 {on "ufb_gun_release_owner_${slot}_%team" {kill_delay "ufb_gun_owner_expiry"} {tags remove "${tag('owner',slot)}"} {tags remove "${tag('escaped',slot)}"} {tags remove "_ufb_gun_bound"}}
`;
 body+='}\n';let result='';for(const [team]of sides)result+=body.replaceAll('%team',team);return result;
}
function events(){let out='';for(let slot=0;slot<SLOTS;slot++)out+=`{on "ufb_gun_bind_man_${slot}_%team"
 {if operatable {if not tagged "medic" {if not tagged "_ufb_healing_active" {if not tagged "_ufb_job_reserved" {if not tagged "_ufb_combat_busy"
  {tags add "${tag('crew',slot)}"} {tags add "_ufb_gun_job_active"}
  {kill_delay "ufb_gun_man_expiry"}
  {delay ${JOB_SECONDS} "ufb_gun_man_expiry" {call "ufb_gun_release_${slot}_%team"}}
 }}}}}
}
{on "ufb_gun_escape_${slot}_%team"
 {talk "retreat"}
 {delay 12 {if tagged "${tag('crew',slot)}" {tags add "${tag('cover',slot)}"}}}
}
{on "ufb_gun_release_${slot}_%team"
 {kill_delay "ufb_gun_man_expiry"}
 {tags remove "${tag('crew',slot)}"} {tags remove "${tag('cover',slot)}"} {tags remove "_ufb_gun_job_active"}
}
`;
 let result='';for(const [team]of sides)result+=out.replaceAll('%team',team);return result;
}
function registry(text){const tree=s.parse(text).children[0],file='ufb_gun_bindings.inc';const found=tree.children.filter(n=>s.name(n)==='include'&&n.tokens[1]?.value===file);assert(found.length<=1);if(found.length)return text;return text.slice(0,tree.end-1)+`\n (include "${file}")\n`+text.slice(tree.end-1);}
function expected(){const root=p.resolve(__dirname,'../mods/ultimate_frontline_bundle/resource');return [{file:'set/interaction_entity/ufb_gun_bindings.inc',text:bindings()},{file:'set/interaction_entity/entity.set',text:registry(fs.readFileSync(p.join(root,'set/interaction_entity/entity.set'),'latin1'))}];}
module.exports={SLOTS,RETURN_DISTANCE,LEASE_SECONDS,JOB_SECONDS,seats,tag,name,men,gun,allocation,mission,bindings,events,registry,expected};
