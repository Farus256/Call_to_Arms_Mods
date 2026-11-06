// HF 4 targeting and native mission commands, with reviewed weapon-only fixes.
const fs=require('fs'),p=require('path'),assert=require('assert/strict'),s=require('./lib/sdl.cjs');
const repo=p.resolve(__dirname,'..');
const reference=p.resolve(repo,'../_survival_work/hf-update-20261105/reference/resource');
const resource=p.join(repo,'mods/ultimate_frontline_bundle/resource');
const read=(root,rel)=>fs.readFileSync(p.join(root,rel),'latin1');
const shape=n=>({kind:n.kind,tokens:n.tokens.map(t=>t.value),children:n.children.map(shape)});
const heavyMgTargets=['tank_light','tank_light_super','tank_medium','tank_heavy','tank_superheavy'];
function ammo(base){
 const tree=s.parse(base),edits=[];
 for(const target of tree.children[0].children.filter(n=>s.name(n)==='human')){
  // HF keeps sidearm rows only for a weapon already in hand, so an empty rifle never yields to a pistol.
  const sidearm=target.children.find(n=>s.name(n)==='bullet');assert(sidearm);
  {let eol=base.indexOf('\n',sidearm.end);if(base[eol-1]==='\r')eol--;edits.push({start:eol,end:eol,text:'\n\t\t{"pistol"}\t\t\t\t\t\t\t; UFB: draw a sidearm when the main weapon is dry\n\t\t{"revolver"}\t\t\t\t\t\t; UFB: draw a sidearm when the main weapon is dry'});}
  if(target.tokens[1]?.value==='in_cover')for(const n of target.children.filter(n=>s.name(n)==='grenade fg')){
   assert(!s.child(n,'check_grenade'));edits.push({start:n.end-1,end:n.end-1,text:' {check_grenade}'});
  }
  // Keep a deliberately prepared player launcher. Automatic human target
  // acquisition is restricted separately; explicit bazooka_shot still works.
  const first=target.children[0];
  edits.push({start:first.start,end:first.start,text:'; UFB: respect a player launcher already prepared in hand.\n'+['panzerfaust','ammo rocketlauncher'].map(name=>'\t\t{'+JSON.stringify(name)+' {enable_for_ai 0} {ready_for_shot}}').join('\n')+'\n\t\t'});
  const launchers=target.children.filter(n=>['panzerfaust','ammo rocketlauncher'].includes(s.name(n)));
  assert.equal(launchers.length,2); // Native prepared-weapon entries only.
  const after=target.children.find(n=>s.name(n)==='ptr');assert(after);
  // Reserve HEAT rifle grenades for armor while an ordinary firearm is usable.
  const heat=target.children.find(n=>s.name(n)==='ammo rifle_grenade_at');assert(heat);
  edits.push({start:heat.start,end:heat.end,text:''});
  edits.push({start:after.end,end:after.end,text:'\n\t\t{"ammo rifle_grenade_at" {check_grenade}}'});
 }
 // HF lists hmgun only for tank_light, so a heavy MG tracks heavier armor without firing.
 // Tracks first; after they break, keep firing at the hull instead of staring at it.
 for(const target of tree.children[0].children.filter(n=>heavyMgTargets.includes(s.name(n)))){
  const mover=target.children.find(n=>s.name(n)==='hmgun'&&s.child(n,'volume')?.tokens[1]?.value==='mover');
  const anchor=mover||target.children.filter(n=>s.name(n)==='ptr').at(-1);assert(anchor,s.name(target));
  let eol=base.indexOf('\n',anchor.end);if(base[eol-1]==='\r')eol--;
  edits.push({start:eol,end:eol,text:(mover?'':'\n\t\t{"hmgun" {volume "mover"}}\t\t; UFB: heavy MG at running gear')+'\n\t\t{"hmgun" {volume "body"}}\t\t; UFB: keep firing once the tracks are gone'});
 }
 for(const e of edits.sort((a,b)=>b.start-a.start||b.end-a.end))base=base.slice(0,e.start)+e.text+base.slice(e.end);
 return base;
}
function antiTankTargets(base){
 const tree=s.parse(base),edits=[];
 for(const selector of tree.children){const unit=s.child(selector,'unit'),group=s.child(selector,'group');if(!unit||!group)continue;
  if(!/^range_\d+$/.test(unit.tokens[2]?.value||'')&&unit.tokens[2]?.value!=='ap')continue;
  edits.push({start:group.tokens[0].end,end:group.tokens[0].end,text:'\n\t\t; UFB: automatic AT targeting reserves infantry for explicit critical/manual shots.\n\t\t{ignore {class human}}'});
 }
 assert(edits.length>=7);for(const e of edits.sort((a,b)=>b.start-a.start))base=base.slice(0,e.start)+e.text+base.slice(e.end);return base;
}
function fragTargets(base){
 const at=base.indexOf('{ignore');assert(at>=0);
 const end=base.indexOf('\n',at);assert(end>=0);
 return base.slice(0,end)+'\n\n\t\t; UFB: a hand frag is for nearby infantry before armored targets.\n\t\t{sort {class human} {attacking} {in_range 25}}\n\t\t{sort {class human} {in_range 25}}\n'+base.slice(end);
}

const jobs=['launcher','at','critical','ap','smoke'];
const tag=(kind,role)=>`_ufb_combat_${kind}_${role}_%team`;
const T=name=>`{tag {tag ${name}}}`;
const P=name=>`{prop {prop ${name}}}`;
const S=name=>`{state {state ${name}}}`;
const I=(item,type='amount')=>`{with_item {type ${type}} {item "${item}"}${type==='amount'?' {min 1}':''}}`;
const {protectedHumanTags:blocked,sides}=require('./infantry-job-policy.cjs');
function actor(kind,{acquire=false,all=false,item,using,extra=[],command=false,single=false}={}){
 const select=acquire?(kind==='critical'||kind==='smoke'?T('_ufb_recent_hit'):''):T(tag(kind,'actor'));
 const include=[`{team {team %team}}`,P('human'),S('operatable'),...(!all?[S('user_control')]:[]),...(!command?[T('_ufb_firing')]:[]),...(item?[I(item)]:[]),...(using?[I(using,'using')]:[]),...extra].join('\n');
 const exclude=[S('dead'),S('inactive'),S('linked'),P('crew'),P('repairing'),P('throwing'),...blocked.filter(tag=>all||tag!=='reloading').map(T),T('_ufb_suppress_actor_%team'),...(['ap','at','smoke'].includes(kind)?[I('rocketlauncher','using')]:[]),...(!command?[T('_ufb_combat_busy'),T(`_ufb_combat_${kind}_cooldown`)]:[]),...(acquire?[T('_ufb_job_reserved'),...jobs.map(j=>T(tag(j,'actor')))]:[]),...(kind==='smoke'?['m15_wp','m42_wp','no77_wp'].map(n=>I(n,'existance')):[])].join('\n');
 return `{source advanced}\n{ignore_captured_by_user 1}\n{group\n ${select?`{select ${select}}`:''}\n {include ${include}}\n {exclude ${exclude}}\n}${single?'\n{amount 1}':''}`;
}
function enemy({kind,paired=false,vehicle=false,mgun=false,cover=false}={}){
 const select=paired?`{select ${T(tag(kind,'target'))}} `:'';
 const include=[`{team {team %foe}}`,S('operatable'),...(paired?[]:[P(vehicle?'vehicle':'human')]),...(mgun?[I('mgun','using')]:[]),...(cover?[T(`_ufb_combat_cover_%team`)]:[])].join('\n');
 return `{source advanced}\n{ignore_captured_by_user 0}\n{group ${select}{include ${include}} {exclude ${S('dead')} ${S('inactive')} ${S('linked')} ${P('airborne')} ${T('bleeding')} ${T('_bleedout_')} ${T('wounded_animation_playing')}}}`;
}
function see(a,e,min,max,pair){return `{selector ${a}}\n{enemy ${e}}\n{distance {mode in_range} {min ${min}} {max ${max}}}\n{detection visible}${pair?`\n{tag {"tag pair"} {"for selector" ${tag(pair,'pick')}} {"for enemy" ${tag(pair,'target')}}}`:''}`;}
function friendlyNear(kind){return `{units {ignore_captured_by_user 0} {tag ${tag(kind,'target')}}}\n{near_to {source advanced} {ignore_captured_by_user 0} {group {include ${P('human')} {team {team %team}} ${S('operatable')}} {exclude ${S('dead')}}}}\n{distance 12}`;}
function clear(kind,role){return `{"entity_state" {selector {ignore_captured_by_user 0} {tag ${tag(kind,role)}}} {tag_remove ${tag(kind,role)}}}`;}
function action(kind,options,name,target){return `{"action" {selector ${actor(kind,{...options,command:true,single:true})}} {action ${name}} {target ${target||`{ignore_captured_by_user 0} {tag ${tag(kind,'target')}}`}}}`;}
function cooldown(kind,options){return `{"effect" {selector ${actor(kind,{...options,command:true})}} {effect ufb_combat_${kind}_cooldown}}`;}
function pairRoutine(kind,options){
 const {min,max,vehicle=false,mgun=false,all=false,item,using,armorGuard=false,friendlyGuard=true,command,cover=false,threat=false}=options;
 const aOptions={all,item,using};
 const acquireActor=actor(kind,{...aOptions,acquire:true});
 const pairedEnemy=enemy({kind,paired:true,vehicle,mgun,cover});
 const expr=['1',...(friendlyGuard?['!2']:[]),...(armorGuard?['!3']:[])].join(' & ');
 let execute=cooldown(kind,aOptions)+'\n'+action(kind,aOptions,command);
 if(kind==='smoke')execute=`${cooldown(kind,aOptions)}\n{"effect" {selector ${actor(kind,{...aOptions,command:true,single:true})}} {effect ufb_combat_smoke_point_%team}}\n${action(kind,aOptions,'throw_sk_grenade',`{ignore_captured_by_user 0} {tag _ufb_combat_smoke_point_%team}`)}`;
 return `; ${kind}: one reserved pair per player; no drop-orders or fire-mode changes.\n(define "ufb_combat_${kind}"
 {"ufb/combat/${kind}/acquire %team"
  {condition ${threat?`{expression "1 | 2"} {terms {"1.see_actors" ${see(acquireActor,enemy({vehicle:true}),min,max,kind)}} {"2.see_actors" ${see(acquireActor,enemy({mgun:true}),min,max,kind)}}}`:`{terms {"1.see_actors" ${see(acquireActor,enemy({vehicle,mgun}),min,max,kind)}}}`}}
  {actions
   {"entity_state" {selector {amount 1} {ignore_captured_by_user 0} {tag ${tag(kind,'pick')}}} {tag_add ${tag(kind,'actor')}}}
   ${clear(kind,'pick')}
   {"effect" {selector {ignore_captured_by_user 0} {tag ${tag(kind,'actor')}}} {effect ufb_reserve_job}}
   ${cover?`{"effect" {selector {ignore_captured_by_user 0} {tag ${tag(kind,'target')}}} {effect ufb_combat_probe_cover_%team}}`:''}
   {"delay" {time 6}}
   ${clear(kind,'actor')}
   ${clear(kind,'target')}
   {"delay" {time 2}}
   {"trigger" {name "ufb/combat/${kind}/acquire %team"}}
  }
 }
 {"ufb/combat/${kind}/apply %team"
  {condition {expression "${expr}"} {terms
   {"1.see_actors" ${see(actor(kind,aOptions),pairedEnemy,min,max)}}
   ${friendlyGuard?`{"2.near" ${friendlyNear(kind)}}`:''}
   ${armorGuard?`{"3.see_actors" ${see(actor(kind,aOptions),enemy({vehicle:true}),0,110)}}`:''}
  }}
  {actions
   {"con" {text "[UFB combat] ${kind} order: team %team"}}
   ${execute}
   {"delay" {time 1}}
   {"trigger" {name "ufb/combat/${kind}/apply %team"}}
  }
 }
)`;
}
// Launcher in hand with no armor around: every owner goes back to a firearm. Native
// weapon choice cannot do it: human_ap.inc gives a launcher holder no infantry targets.
const launcherTiers={near:{classes:[30,40,50],reach:70},far:{classes:[60,70,80,90],reach:110}};
const launcherClass=tier=>launcherTiers[tier].classes.map(m=>I('range_'+m,'using'));
function holder({include=[],exclude=[]}={}){
 const busy=blocked.filter(x=>x!=='_ufb_autonomy_moving').map(T);
 return `{source advanced}\n{ignore_captured_by_user 1}\n{group\n {include ${P('human')} {team {team %team}} ${S('operatable')} ${I('rocketlauncher','using')} ${I('weapon bullet')} ${include.join(' ')}}\n {exclude ${[S('dead'),S('inactive'),S('linked'),P('crew'),P('repairing'),P('throwing'),T('_ufb_firing'),T('_ufb_job_reserved'),T('_ufb_combat_busy'),...busy,...exclude].join(' ')}}\n}`;
}
function launcherRelease(){
 const keep=T('_ufb_launcher_keep');
 const armed=tier=>{
  const pair=`_ufb_launcher_keep_${tier}_%team`,name=`ufb/launcher/keep ${tier} %team`;
  const who=holder({exclude:[keep,...launcherClass(tier==='near'?'far':'near')]});
  return `{"${name}"
  {condition {terms {"1.see_actors" {selector ${who}} {enemy ${enemy({vehicle:true})}} {distance {mode in_range} {min 0} {max ${launcherTiers[tier].reach}}} {detection visible} {tag {"tag pair"} {"for selector" ${pair}}}}}}
  {actions
   {"effect" {selector {ignore_captured_by_user 0} {tag ${pair}}} {effect ufb_launcher_keep}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag ${pair}}} {tag_remove ${pair}}}
   {"delay" {time 1}}
   {"trigger" {name "${name}"}}
  }
 }`;
 };
 const ready=holder({include:[T('_ufb_launcher_ready')],exclude:[keep]});
 return `(define "ufb_combat_launcher_release"
 ${armed('near')}
 ${armed('far')}
 {"ufb/launcher/tick %team"
  {condition {terms {"1.entities" {selector ${holder()}}}}}
  {actions
   {"effect" {selector ${holder({exclude:[keep,T('_ufb_launcher_seen')]})}} {effect ufb_launcher_grace}}
   {"if" {condition {type entities} {selector ${ready}}}
    {"entity_state" {selector ${ready}} {tag_add _ufb_launcher_stow_%team}}
    {"inventory" {selector ${ready}} {action take} {item "weapon bullet"}}
    {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_launcher_stow_%team}} {tag_remove _ufb_launcher_ready}}
    {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_launcher_stow_%team}} {tag_remove _ufb_launcher_seen}}
    {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_launcher_stow_%team}} {tag_remove _ufb_launcher_stow_%team}}
    {"con" {text "[UFB combat] launcher stowed: team %team"}}
   }
   {"delay" {time 2}}
   {"trigger" {name "ufb/launcher/tick %team"}}
  }
 }
)`;
}
function mission(){
 const pieces=[`; UFB combat autonomy. Native commands consume existing inventory and keep native ranges.
; Sides come from native {team} selectors; multiplayer missions define no diplomacy.
; Player ownership and active user capture are separate native states.
; Only stationary troops already firing may receive extra offensive orders.
; Prepared launchers are excluded from grenade/smoke switching; without armor nearby any
; soldier returns to a firearm, except one under direct user capture.
`,
 pairRoutine('at',{min:12,max:16,item:'at',vehicle:true,command:'throw_at_grenade'}),
 pairRoutine('launcher',{min:18,max:25,item:'rocketlauncher',vehicle:true,command:'bazooka_shot'}),
 pairRoutine('critical',{min:18,max:25,item:'rocketlauncher',mgun:true,all:true,armorGuard:true,cover:true,command:'bazooka_shot'}),
 pairRoutine('ap',{min:14,max:20,item:'fg',command:'throw_ap_grenade'}),
 pairRoutine('smoke',{min:30,max:110,item:'smoke',threat:true,friendlyGuard:false,command:'throw_sk_grenade'}),
 launcherRelease()];
 for(const [team,foe] of sides)for(const kind of [...jobs,'launcher_release'])pieces.push(`("ufb_combat_${kind}" team(${team}) foe(${foe}))`);
 return pieces.join('\n\n')+'\n(include "/map/multi/ufb_infantry_support.inc")\n(include "/map/multi/ufb_static_weapons.inc")\n';
}
function events(){
 let out=`; Only tags and short-lived target coordinates; no damage, health or free ammunition.
{on "ufb_reserve_job"
 {tags add "_ufb_job_reserved"}
 {delay 6 {tags remove "_ufb_job_reserved"}}
}
; The engine's own shooting prop never reaches infantry; this comes from the weapon's fire event.
{on "ufb_firing"
 {tags add "_ufb_firing"}
 {kill_delay "ufb_firing_end"}
 {delay 4 "ufb_firing_end" {tags remove "_ufb_firing"}}
}
{on "ufb_launcher_keep"
 {tags add "_ufb_launcher_keep"}
 {delay 10 {tags remove "_ufb_launcher_keep"}}
}
{on "ufb_launcher_grace"
 {tags add "_ufb_launcher_seen"}
 {delay 12 {if tagged "_ufb_launcher_seen" {tags add "_ufb_launcher_ready"}}}
 {delay 24 {tags remove "_ufb_launcher_seen"} {tags remove "_ufb_launcher_ready"}}
}
{on "ufb_autonomy_move_on" {tags add "_ufb_autonomy_moving"}}
{on "ufb_autonomy_move_off" {tags remove "_ufb_autonomy_moving"}}
{on "ufb_combat_hit"
 {if not dead {if not linked {if not tagged "_ufb_recent_hit"
  {tags add "_ufb_recent_hit"}
  {tags add "_ufb_was_hit"}
  {delay 8 {tags remove "_ufb_recent_hit"}}
  {delay 90 {tags remove "_ufb_was_hit"}}
 }}}
}
`;
 for(const [kind,seconds]of Object.entries({ap:12,at:10,launcher:8,smoke:35,critical:30}))out+=`
{on "ufb_combat_${kind}_cooldown"
 {tags add "_ufb_combat_busy"}
 {tags add "_ufb_combat_${kind}_cooldown"}
 {delay 6 {tags remove "_ufb_combat_busy"}}
 {delay ${seconds} {tags remove "_ufb_combat_${kind}_cooldown"}}
}
`;
 out+=`
(define "ufb_combat_target_events"
 {on "ufb_combat_probe_cover_%team"
  {if in_cover
   {tags add "_ufb_combat_cover_%team"}
   {delay 1 {tags remove "_ufb_combat_cover_%team"}}
  else {tags remove "_ufb_combat_cover_%team"}}
 }
 {on "ufb_combat_smoke_point_%team" sync
  {spawn "ufb_smoke_screen_point" local_offset 200 0 0 constrain_after_dir
   {tags add "_ufb_combat_smoke_point_%team"}
   {delay 3 {delete}}
  }
 }
)
`;
 for(const [team] of sides)out+=`("ufb_combat_target_events" team(${team}))\n`;
 return out+'\n(include "ufb_infantry_support_events.inc")\n(include "ufb_static_weapon_events.inc")\n';
}
function expected(ref=reference){return [
 {file:'set/target/ammo.set',text:ammo(read(ref,'set/target/ammo.set'))},
 {file:'set/target/human_fg.inc',text:fragTargets(read(ref,'set/target/human_fg.inc'))},
 {file:'set/target/human_ap.inc',text:antiTankTargets(read(ref,'set/target/human_ap.inc'))},
 {file:'map/multi/ufb_combat_autonomy.inc',text:mission()},
 {file:'set/interaction_entity/ufb_combat_events.inc',text:events()},
 ...require('./infantry-extra.cjs').expected(ref),
 ...require('./static-weapons.cjs').expected(ref)
];}
function verify(root=resource,ref=reference){
 for(const e of expected(ref))assert.equal(read(root,e.file),e.text,e.file+' differs from reviewed autonomy policy');
 const human=s.parse(read(root,'set/interaction_entity/human.inc')).children[0];
 const hit=human.children.find(n=>s.name(n)==='on'&&n.tokens[1]?.value==='bullet_hit');
 assert.equal(s.all(hit,n=>s.name(n)==='call'&&n.tokens[1]?.value==='ufb_combat_hit').length,1,'Missing one recent-hit hook');
 assert.equal(human.children.filter(n=>s.name(n)==='include'&&n.tokens[1]?.value==='ufb_combat_events.inc').length,1);
 for(const f of ['map/multi/ufb_crew_safety.inc','map/multi/ufb_crew_skirmish.inc'])assert.equal(s.parse(read(root,f)).children.filter(n=>s.name(n)==='include'&&n.tokens[1]?.value==='/map/multi/ufb_combat_autonomy.inc').length,1,'Missing shared entry point: '+f);
 return {combatAutonomy:true,targetingFiles:3,sides:2,manualCaptureAndMovementProtected:true,automaticATInfantryTargetsRestricted:true};
}
if(require.main===module){
 if(process.argv.includes('--build')){const files=expected();for(const e of files){const dest=p.join(resource,e.file);fs.mkdirSync(p.dirname(dest),{recursive:true});fs.writeFileSync(dest,e.text,'latin1');}console.log('Built '+files.length+' combat-autonomy resources from fresh HF reference.');}
 else console.log(JSON.stringify(verify(process.argv[2]||resource)));
}
module.exports={heavyMgTargets,launcherTiers,ammo,fragTargets,antiTankTargets,mission,events,expected,verify,reference};
