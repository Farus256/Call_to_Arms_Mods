// Execute the emitted mission SDL against small deterministic scenes.
// This verifies policy/lifecycle, not GEM ballistics or animation timing.
const fs=require('fs'),p=require('path'),assert=require('assert/strict'),s=require('./lib/sdl.cjs');
const quantSpread=require('./lib/quant-spread.cjs');
const combat=require('./combat-autonomy.cjs');
const root=p.resolve(process.argv[2]||p.join(__dirname,'../mods/ultimate_frontline_bundle/resource'));
const text=rel=>fs.readFileSync(p.join(root,rel),'latin1');
combat.verify(root);
const mission=text('map/multi/ufb_combat_autonomy.inc'),events=text('set/interaction_entity/ufb_combat_events.inc');
function expand(source){
 const nodes=s.parse(source).children,defs=new Map(nodes.filter(n=>s.name(n)==='define').map(n=>[n.tokens[1].value,n]));
 const output=[];for(const n of nodes){
  if(s.name(n)==='define'||s.name(n)==='include')continue;
  if(n.kind!=='('){n.src=source;output.push(n);continue;}
  const def=defs.get(s.name(n));assert(def,'Missing macro '+s.name(n));
  let body=def.children.map(c=>source.slice(c.start,c.end)).join('\n');
  for(let i=1;i<n.tokens.length;i++)body=body.replaceAll('%'+n.tokens[i].value,n.children[i-1].tokens.map(t=>t.value).join(' '));
  output.push(...s.parse(body).children.map(c=>Object.assign(c,{src:body})));
 }
 return output;
}
const TRIGGERS=361;const triggers=new Map([...expand(mission),...expand(text('map/multi/ufb_infantry_support.inc')),...expand(text('map/multi/ufb_static_weapons.inc')),...expand(text('map/multi/ufb_logistics.inc')),...expand(text('map/multi/ufb_medical_support.inc'))].map(n=>[s.name(n),n]));
assert.equal(triggers.size,TRIGGERS,'duplicate/missing expanded triggers');
const hatch=s.parse(text('set/interaction_entity/ufb_tank_hatch.inc')).children[0];
const eventMap=new Map([...hatch.children,...s.parse(text('set/interaction_entity/ufb_gun_bindings.inc')).children.flatMap(n=>n.children),...expand(events),...expand(text('set/interaction_entity/ufb_crew_cover_events.inc')),...expand(text('set/interaction_entity/ufb_infantry_support_events.inc')),...expand(text('set/interaction_entity/ufb_static_weapon_events.inc')),...expand(text('set/interaction_entity/ufb_medical_events.inc'))].filter(n=>s.name(n)==='on').map(n=>[n.tokens[1].value,n]));
for(const n of s.parse(text('set/interaction_entity/human.inc')).children[0].children.filter(n=>s.name(n)==='on'&&['ufb_hf_cover_prepare','ufb_hf_cover_committed'].includes(n.tokens[1]?.value)))eventMap.set(n.tokens[1].value,n);
const value=(n,key)=>s.child(n,key)?.tokens[1]?.value;
const scanTerms=(n,type)=>[...s.child(s.child(n,'condition'),'terms').children,...(quantSpread.gates(n,n.src)||[]).map(g=>g.condition)].filter(t=>s.name(t).split('.')[1]===type||value(t,'type')===type);
const words=x=>String(x).split(/\s+/);
let checks=0,scenarios=0;
function test(name,fn){fn();scenarios++;console.log('ok - '+name);}
function check(v,msg){assert(v,msg);checks++;}
const weapon=(tags,ammo=3)=>({tags:new Set(words(tags)),amount:1,ammo});
// Native ownership (control user) and CapturedByUser are distinct save fields.
function unit(id,player,x,opts={}){return {id,player,x,team:opts.team??player,props:new Set(['human']),states:new Set(['operatable',...(opts.bot?[]:['user_control'])]),captured:false,ai:{},tags:new Set([...(opts.hit?['_ufb_recent_hit']:[]),...(opts.shooting?['_ufb_firing']:[])]),items:[weapon('weapon bullet rifle'),weapon('weapon rocketlauncher'),{tags:new Set(['fg']),amount:2},{tags:new Set(['at']),amount:2},{tags:new Set(['smoke']),amount:2}],held:new Set(['weapon','rifle','bullet']),visible:true,covered:false,...opts};}
// call_to_arms.exe 0x9dcf50: the only clauses {select} can hold. Anything else is dropped,
// and a group with an empty select matches every entity.
const selectable=new Set(['mids','tag','zone','zone_ex','squad','inventory_items']);
const teamName=e=>e.team===0||e.team==='a'?'a':'b';
class Scene{
 constructor(entities){this.entities=entities;this.now=0;this.timers=[];this.commands=[];this.jobs=[];this.points=[];this.native=[];this.roll=0;}
 // Class tags come from a looping trigger: settle them before any other one runs.
 classify(){this.actions(quantSpread.body(triggers.get('ufb/class'),triggers.get('ufb/class').src).filter(c=>s.name(c)==='entity_state'));}
 playerTeam(id){return this.entities.find(e=>e.player===Number(id))?.team??Number(id);}
 match(e,n){
  const key=s.name(n),v=n.tokens[1]?.value;
  if(key==='tag')return e.tags.has(v??value(n,'tag'));
  if(key==='prop')return e.props.has(v??value(n,'prop'));
  if(key==='state')return words(v??value(n,'state')).every(w=>e.states.has(w));
  if(key==='player')return e.player===Number(v??value(n,'player'));
  if(key==='team')return teamName(e)===(v==='team'?value(n,'team'):v??value(n,'team'));
  if(key==='relation'){const ally=e.team===this.playerTeam(value(n,'player'));return value(n,'relation')==='ally'?ally:!ally;}
  if(key==='with_item'){
   const tags=words(value(n,'item')),type=value(n,'type');
   if(type==='using')return tags.every(t=>e.held.has(t));
   const matches=e.items.filter(i=>i.amount>0&&tags.every(t=>i.tags.has(t)));
   return type==='amount'?matches.reduce((n,i)=>n+i.amount,0)>=Number(value(n,'min')||0):matches.length>0;
  }
  throw Error('Unsupported selector clause '+key);
 }
 select(n){
  let a=this.entities.filter(e=>!(value(n,'ignore_captured_by_user')!=='0'&&e.captured));
  const group=s.child(n,'group');
  if(group){const raw=s.child(group,'select'),picked=raw?.children.filter(c=>selectable.has(s.name(c))),sel=picked?.length?{children:picked}:null,inc=s.child(group,'include'),ex=s.child(group,'exclude');a=a.filter(e=>(!sel||sel.children.some(c=>this.match(e,c)))&&(!inc||inc.children.every(c=>this.match(e,c)))&&(!ex||!ex.children.some(c=>this.match(e,c))));}
  for(const c of n.children.filter(c=>['tag','prop','state','player'].includes(s.name(c))))a=a.filter(e=>this.match(e,c));
  const sort=s.child(n,'sort');if(value(sort||{children:[]},'type')==='entity'){const from=this.select(s.child(sort,'entity'))[0];if(from)a.sort((a,b)=>Math.abs(a.x-from.x)-Math.abs(b.x-from.x));}
  const amount=s.child(n,'amount')?.tokens[1]?.value;if(amount)a=a.slice(0,Number(amount));
  return a;
 }
 term(n,type){
  if(type==='rand')return this.roll<Number(value(n,'value'));
  if(type==='cmp_i'){assert.equal(value(n,'op'),'==');return Number(this.vars?.[value(n,'var')]||0)===Number(value(n,'value'));}
  if(type==='entities')return this.select(s.child(n,'selector')).length>0;
  if(type==='near'){return this.select(s.child(n,'units')).some(a=>this.select(s.child(n,'near_to')).some(b=>Math.abs(a.x-b.x)<=Number(value(n,'distance'))));}
  if(type==='see_actors'){
   const distance=s.child(n,'distance'),lo=Number(value(distance,'min')||0),hi=Number(value(distance,'max')||value(distance,'meters'));
   // HF follows tag pair with {amount 1} actions, so assume every visible pair is tagged.
   let seen=false;const tag=s.child(n,'tag');
   for(const a of this.select(s.child(n,'selector')))for(const b of this.select(s.child(n,'enemy')))if(a!==b&&b.visible&&Math.abs(a.x-b.x)>=lo&&Math.abs(a.x-b.x)<=hi){
    seen=true;if(!tag)return true;a.tags.add(s.child(tag,'for selector').tokens[1].value);const other=s.child(tag,'for enemy')?.tokens[1].value;if(other)b.tags.add(other);
   }
   return seen;
  }
  throw Error('Unsupported term '+type);
 }
 condition(n){
  const vals={};for(const t of s.child(n,'terms').children){const [id,type]=s.name(t).split('.');vals[id]=this.term(t,type);}
  const exp=value(n,'expression');if(!exp)return Object.values(vals).every(Boolean);
  return Function('return '+exp.replace(/\d+/g,id=>String(vals[id])).replaceAll('&','&&').replaceAll('|','||'))();
 }
 later(seconds,fn){this.timers.push({at:this.now+seconds,fn});}
 advance(seconds){const end=this.now+seconds;for(;;){this.timers.sort((a,b)=>a.at-b.at);if(!this.timers.length||this.timers[0].at>end)break;const t=this.timers.shift();this.now=t.at;t.fn();}this.now=end;}
 event(name,e){if(/_hatch_(close|open)$/.test(name)&&!eventMap.has(name)){this.commands.push({name,actor:e.id,at:this.now});return;}if(name==='emit_crew'||name.startsWith('construction_sandbag')){this.native.push({name,gun:e.id});if(name==='emit_crew'){e.states.delete('inhabited');for(const member of Object.values(e.crewLinks||{}))member.states.delete('linked');}return;}const node=eventMap.get(name);assert(node,'Missing event '+name);this.eventNodes(node.children,e);}
 eventNodes(nodes,e){for(const n of nodes){
  const key=s.name(n);
  if(key==='tags'){if(n.tokens[1].value==='add')e.tags.add(n.tokens[2].value);else e.tags.delete(n.tokens[2].value);}
  else if(key==='delay'){const d=n.tokens[2]?.value,variance=d&&!Number.isNaN(Number(d))?Number(d)*(this.variation||0):0;this.later(Number(n.tokens[1].value)+variance,()=>this.eventNodes(n.children,e));if(d&&Number.isNaN(Number(d)))Object.assign(this.timers.at(-1),{owner:e,tag:d});}
  else if(key==='if'){
   const els=n.tokens.map((t,i)=>t.value==='else'?i:-1).filter(i=>i>=0),starts=[1,...els.map(i=>i+1)];
   for(let b=0;b<starts.length;b++){
    const args=n.tokens.slice(starts[b],els[b]).map(t=>t.value),negate=args[0]==='not';if(negate)args.shift();
    const ok=!args.length||args[0]==='tagged'?(!args.length||e.tags.has(args[1])):args[0]==='in_cover'?e.covered:args[0]==='linked'?e.states.has('linked'):args[0]==='has_place'?args[1] in (e.seats||e.crewLinks||{}):args[0]==='crew_in_place'?!!(e.crewLinks?.[args[1]]||e.seats?.[args[1]]):e.states.has(args[0]);
    if(!(negate?!ok:ok))continue;
    const low=b?n.tokens[els[b-1]].start:n.start,high=b<els.length?n.tokens[els[b]].start:n.end;
    this.eventNodes(n.children.filter(c=>c.start>low&&c.start<high).flatMap(c=>s.name(c)?[c]:c.children),e);break;
   }
  }else if(key==='spawn'){
   const at=n.tokens.findIndex(t=>t.value==='local_offset'),offset=at<0?0:Number(n.tokens[at+1].value)/20;
   const point={id:'point'+this.points.length,x:e.x+offset,player:e.player,team:e.team,props:new Set(),states:new Set(),tags:new Set(),items:[],held:new Set(),visible:true};this.entities.push(point);this.points.push(point);this.eventNodes(n.children,point);
  }else if(key==='delete')this.entities=this.entities.filter(x=>x!==e);
  else if(key==='with_linked_entity'){const member=e.crewLinks?.[n.tokens[1].value];if(member)this.eventNodes(n.children,member);}
  else if(key==='crew_enable')this.commands.push({name:'crew_enable',group:n.tokens[2].value,value:n.tokens[3].value,at:this.now});
  else if(key==='kill_delay')this.timers=this.timers.filter(t=>!(t.owner===e&&t.tag===n.tokens[1].value));
  else if(key==='talk')this.commands.push({name:'talk',actor:e.id,line:n.tokens[1].value,at:this.now});
  else if(key==='call'||key==='call_synced')this.event(n.tokens[1].value,e);
  else throw Error('Unsupported entity event '+key);
 }}
 // Native HF waits inside if/switch blocks (413 nested delays), so a nested block resumes its parent via done.
 actions(nodes,at=0,done){for(let i=at;i<nodes.length;i++){
  const n=nodes[i],key=s.name(n),next=()=>this.actions(nodes,i+1,done);
  if(key==='delay'){this.later(Number(value(n,'time')),next);return;}
  if(key==='trigger'){this.jobs.push(value(n,'name'));continue;}
  if(key==='con')continue;
  if(key==='delete'){const doomed=this.select(s.child(n,'selector'));this.entities=this.entities.filter(e=>!doomed.includes(e));continue;}
  if(key==='emit'){for(const e of this.select(s.child(n,'selector'))){e.states.delete('inhabited');this.commands.push({name:'emit',actor:e.id,at:this.now});}continue;}
  if(key==='switch'){
   const branch=n.children.find(c=>s.name(c)==='case'&&this.term(s.child(c,'condition'),value(s.child(c,'condition'),'type')))||n.children.find(c=>s.name(c)==='default');
   if(branch){this.actions(branch.children.filter(c=>s.name(c)!=='condition'),0,next);return;}continue;
  }
  if(key==='if'){if(this.term(s.child(n,'condition'),value(s.child(n,'condition'),'type'))){this.actions(n.children.filter(c=>s.name(c)!=='condition'),0,next);return;}continue;}
  const actors=this.select(s.child(n,'selector')),boardVehicle=key==='board'?this.select(s.child(n,'vehicle'))[0]:null;
  for(const e of actors){
   if(key==='entity_state'){const add=value(n,'tag_add'),remove=value(n,'tag_remove');if(add)e.tags.add(add);if(remove)e.tags.delete(remove);}
   else if(key==='effect')this.event(value(n,'effect'),e);
   else if(key==='actor_state'){for(const field of s.child(n,'ai')?.children||[]){const v=field.tokens[1].value;e.ai[s.name(field)]=v==='on'?true:v==='off'?false:Number(v);}if(s.child(n,'cannon'))e.cannon=value(n,'cannon');if(s.child(n,'move_mode'))e.moveMode=value(n,'move_mode');}
   else if(key==='actor_to_cover')this.commands.push({name:'cover',actor:e.id,at:this.now});
   else if(key==='board'){const gun=boardVehicle;if(gun&&!e.pathBlocked){gun.states.add('inhabited');e.states.add('linked');this.commands.push({name:'board',actor:e.id,target:gun.id,at:this.now});}}
   else if(key==='player')e.player=Number(value(n,'player'));
   else if(key==='animation')this.commands.push({name:'animation',actor:e.id,clip:value(n,'collage'),at:this.now});
   else if(key==='inventory'){
    if(value(n,'action')==='drop'){
     const tag=value(n,'item');
     for(const item of [...e.items])if(!tag||words(tag).every(t=>item.tags.has(t))){e.items=e.items.filter(i=>i!==item);if(item.patient){item.patient.states.delete('linked');item.patient.x=e.x;}}
    }
    else if(value(n,'action')==='take_from'){
     const donor=this.select(s.child(n,'entity'))[0],item=donor?.items.find(i=>i.amount>0&&words(value(n,'item')).every(t=>i.tags.has(t)));
     if(item&&e.items.length<(e.maxItems||100)){
      const limit=Number(value(n,'amount')||item.amount);
      if(item.amount>limit){item.amount-=limit;e.items.push({...item,tags:new Set(item.tags),amount:limit});}
      else {donor.items=donor.items.filter(i=>i!==item);e.items.push(item);}
     }
    }else {const w=e.items.find(i=>i.amount>0&&words(value(n,'item')).every(t=>i.tags.has(t)));if(w)e.held=new Set(w.tags);}
   }
   else if(key==='actor_fire'){
    const target=this.select(s.child(n,'enemies'))[0],gun=e.items.find(i=>i.tags.has('mgun')&&i.ammo>0);if(target&&gun&&e.held.has('mgun')){gun.ammo--;this.commands.push({name:'actor_fire',actor:e.id,target:target.id,at:this.now});}
   }
   else if(key==='action'){
    const name=value(n,'action'),target=this.select(s.child(n,'target'))[0];if(!target)continue;
    if(name==='collect'&&!e.pathBlocked&&!target.states.has('linked')){e.items.push({tags:new Set(['human']),amount:1,patient:target});target.states.add('linked');}
    if(name==='move'&&!e.pathBlocked&&[...target.tags].some(t=>t.startsWith('_ufb_rescue_')))e.x=target.x;
    const itemTag={throw_ap_grenade:'fg',throw_at_grenade:'at',throw_sk_grenade:'smoke',bazooka_shot:'rocketlauncher'}[name];
    const item=itemTag&&e.items.find(i=>i.amount>0&&i.tags.has(itemTag));if(itemTag&&(!item||(name==='bazooka_shot'&&item.ammo<=0)))continue;
    if(itemTag){if(name==='bazooka_shot')item.ammo--;else item.amount--;}
    this.commands.push({name,actor:e.id,target:target.id,at:this.now});
   }else throw Error('Unsupported mission action '+key);
  }
 }if(done)done();}
 run(kind,phase='acquire',player='a'){return this.fire(triggers.get(`ufb/combat/${kind}/${phase} ${player}`));}
 named(name){this.classify();const n=triggers.get(name);assert(n,'Missing trigger '+name);return this.fire(n);}
 // A quant-spread trigger is polled on cheap terms and gates heavy ones in its actions: a test call is the
 // scan moment (phase delay skipped) and reports whether the gates passed, like the original condition.
 wouldFire(n){const g=quantSpread.gates(n,n.src);return this.condition(s.child(n,'condition'))&&(!g||g.every(x=>this.term(x.condition,value(x.condition,'type'))!==x.negate));}
 fire(n){assert(n);if(!this.condition(s.child(n,'condition')))return false;
  const kids=s.child(n,'actions').children,g=quantSpread.gates(n,n.src);
  if(!g){this.actions(kids);return true;}
  // Evaluate each gate once: tag pair mutates the candidate tags, so evaluating
  // it again can exclude the soldier just selected by the first evaluation.
  const yes=g.every(x=>this.term(x.condition,value(x.condition,'type'))!==x.negate);
  this.actions(yes?[...quantSpread.body(n,n.src),...kids.slice(-2)]:kids.slice(-2));return yes;}
 // Loot acquire is a timed scan whose condition is always true; success = the native actor tag pair was set.
 looted(kind,player){this.named(`ufb/support/loot ${kind}/acquire ${player}`);return this.entities.some(e=>e.tags.has(`_ufb_loot_${kind}_actor_${player}`));}
}
function battle(opts={}){const a=unit('a',0,0,{shooting:true,hit:true,...opts}),b=unit('b',1,20,{team:1});b.held=new Set(['mgun']);b.covered=true;return {a,b,w:new Scene([a,b])};}

test('frag helper reacts for a player and consumes only existing stock',()=>{const {a,w}=battle();check(w.run('ap'));check(w.run('ap','apply'));assert.equal(w.commands[0].name,'throw_ap_grenade');assert.equal(a.items.find(i=>i.tags.has('fg')).amount,1);});
test('healthy player troops already fighting can throw without an incoming hit',()=>{const {w}=battle({hit:false,shooting:true});check(w.run('ap'));check(w.run('ap','apply'));});
test('native repair and grenade animations are not interrupted',()=>{for(const prop of ['repairing','throwing']){const {a,w}=battle();a.props.add(prop);check(!w.run('ap'),prop);}});
test('a manually drawn launcher and a newly wounded actor are excluded from grenade switching',()=>{for(const mode of ['launcher','wounded']){const {a,w}=battle();w.run('ap');if(mode==='launcher')a.held=new Set(['weapon','rocketlauncher']);else a.tags.add('wounded');check(!w.run('ap','apply'),mode);}});
test('diplomacy rejects a teammate even if it has a different player id',()=>{const {b,w}=battle();b.team=0;check(!w.run('ap'));});
test('ally moving into blast area after acquisition blocks the throw',()=>{const {w}=battle();w.run('ap');w.entities.push(unit('ally',2,19,{team:0}));check(!w.run('ap','apply'));});
test('a distant vehicle does not prohibit an ordinary frag against nearby infantry',()=>{const {w}=battle();w.run('ap');const car=unit('tank',1,40);car.props=new Set(['vehicle','tank']);w.entities.push(car);check(w.run('ap','apply'));});
test('hidden targets, linked troops, and a target leaving range are rejected',()=>{for(const mode of ['hidden','linked','range']){const {a,b,w}=battle();w.run('ap');if(mode==='hidden')b.visible=false;if(mode==='linked')a.states.add('linked');if(mode==='range')b.x=40;check(!w.run('ap','apply'),mode);}});
test('critical launcher needs a recent impact and a nearby machine gunner in cover',()=>{
 const {a,b,w}=battle({bot:true});check(w.run('critical'));check(b.tags.has('_ufb_combat_cover_a'));check(w.run('critical','apply'));assert.equal(w.commands[0].name,'bazooka_shot');assert.equal(a.items.find(i=>i.tags.has('rocketlauncher')).ammo,2);
 for(const mode of ['no-hit','no-cover','no-mgun']){const z=battle();if(mode==='no-hit')z.a.tags.clear();if(mode==='no-cover')z.b.covered=false;if(mode==='no-mgun')z.b.held=new Set(['rifle']);z.w.run('critical');check(!z.w.run('critical','apply'),mode);}
});
test('critical shot aborts for armor, allied blast risk, or expired cover probe',()=>{for(const mode of ['armor','ally','expired']){const {w}=battle();w.run('critical');if(mode==='armor'){const car=unit('car',1,50);car.props=new Set(['vehicle']);w.entities.push(car);}if(mode==='ally')w.entities.push(unit('ally',2,20,{team:0}));if(mode==='expired')w.advance(1.1);check(!w.run('critical','apply'),mode);}});
test('anti-tank grenade and launcher assist use a vehicle, never allied armor',()=>{for(const kind of ['at','launcher']){const {b,w}=battle();b.x=kind==='at'?15:20;b.props=new Set(['vehicle']);check(w.run(kind));check(w.run(kind,'apply'));check(w.commands.some(c=>c.name===(kind==='at'?'throw_at_grenade':'bazooka_shot')));}});
test('smoke is thrown toward a nearby point, not the distant threat',()=>{const {b,w}=battle();b.x=60;check(w.run('smoke'));check(w.run('smoke','apply'));w.advance(0.9);const cmd=w.commands.find(c=>c.name==='throw_sk_grenade');check(cmd);assert.equal(w.points[0].x,10);assert.equal(cmd.target,w.points[0].id);w.advance(3.1);check(!w.entities.some(e=>e.id===cmd.target),'smoke marker must expire');});
test('white phosphorus picked up after smoke acquisition still blocks automation',()=>{const {a,b,w}=battle();b.x=60;check(w.run('smoke'));a.items.push({tags:new Set(['m15_wp']),amount:1});w.run('smoke','apply');w.advance(1);check(!w.commands.some(c=>c.name==='throw_sk_grenade'),'WP must remain excluded after acquisition');});
test('drawing a launcher after smoke acquisition prevents the throw',()=>{const {a,b,w}=battle();b.x=60;w.run('smoke');a.held=new Set(['weapon','rocketlauncher']);w.run('smoke','apply');w.advance(1);check(!w.commands.some(c=>c.name==='throw_sk_grenade'));});
test('busy expiry never bypasses a longer individual cooldown',()=>{const {a,b,w}=battle();w.run('critical');w.run('critical','apply');w.advance(6.01);a.tags.add('_ufb_combat_critical_actor_a');b.tags.add('_ufb_combat_critical_target_a');w.event('ufb_combat_probe_cover_a',b);check(!w.run('critical','apply'),'30-second critical cooldown must outlive the 6-second job lock');});
test('sides stay isolated: team b acts on team a and uses its own tags',()=>{const a=unit('p',16,0,{shooting:true,team:1}),b=unit('enemy',1,20,{team:0}),w=new Scene([a,b]);check(w.run('ap','acquire','b'));check(a.tags.has('_ufb_combat_ap_actor_b'));check(!w.run('ap','apply','a'));check(w.run('ap','apply','b'));});

// Entire untouched target classes remain byte-for-byte equivalent in their SDL data.
const native=s.parse(fs.readFileSync(p.join(combat.reference,'set/target/ammo.set'),'latin1')).children[0];
const current=s.parse(text('set/target/ammo.set')).children[0];
const shape=n=>({kind:n.kind,tokens:n.tokens.map(t=>t.value),children:n.children.map(shape)});
const withoutHeavyMg=n=>{const c=shape(n);if(combat.heavyMgTargets.includes(s.name(n)))c.children=c.children.filter(r=>r.tokens[0]!=='hmgun');return c;};
assert.deepEqual(current.children.filter(n=>s.name(n)!=='human').map(withoutHeavyMg),native.children.filter(n=>s.name(n)!=='human').map(withoutHeavyMg));
for(const n of current.children.filter(n=>s.name(n)==='human')){
 for(const row of n.children.filter(n=>s.name(n)==='grenade fg'))check(s.child(row,'check_grenade'),'native frag self-safety check retained for every infantry target');
 for(const launcher of ['panzerfaust','ammo rocketlauncher']){const rows=n.children.filter(row=>s.name(row)===launcher);check(rows.length===2);check(rows.every(row=>s.child(row,'ready_for_shot')),'no automatic launcher draw against infantry');}
}
test('ammo table keeps rifles and manual launchers without automatically drawing a launcher for infantry',()=>{
 const select=(mode,usable,{selected=false,covered=true,held='rifle',bot=false}={})=>{
  const rows=current.children.find(n=>n.tokens.map(t=>t.value).join(' ')==='human'+(mode?' '+mode:''));
  return rows.children.find(n=>usable.has(s.name(n))&&!(bot&&value(n,'enable_for_ai')==='0')&&!(!bot&&value(n,'enable_for_user')==='0')&&!(selected&&value(n,'enable_for_human_user')==='0')&&(!s.child(n,'ready_for_shot')||held===s.name(n))&&(!s.child(n,'check_grenade')||covered))?.tokens[0].value;
 };
 for(const mode of ['','in_cover','in_bush']){
  assert.equal(select(mode,new Set(['rifle','panzerfaust'])),'rifle');
  assert.equal(select(mode,new Set(['ammo rocketlauncher'])),undefined);
  assert.equal(select(mode,new Set(['panzerfaust']),{covered:false}),undefined);
  assert.equal(select(mode,new Set(['panzerfaust']),{selected:true}),undefined);
  assert.equal(select(mode,new Set(['rifle','panzerfaust']),{selected:true,covered:false,held:'panzerfaust'}),'panzerfaust');
  assert.equal(select(mode,new Set(['rifle','ammo rocketlauncher']),{selected:true,covered:false,held:'ammo rocketlauncher'}),'ammo rocketlauncher');
 }
});
test('Lua orders respect the active combat job and resume before the ammunition cooldown ends',()=>{
 const {lua,lauxlib,lualib,to_luastring,to_jsstring}=require('fengari');
 const file=p.join(root,'script/multiplayer/ufb_order_guard.lua').replaceAll('\\','/');
 const code=`local busy,timer,orders=true,nil,0
 BotApi={Scene={IsSquadExists=function()return true end,IsSquadTagged=function(_,_,tag)return (busy and tag=='_ufb_combat_busy') or tag=='_ufb_combat_critical_cooldown' end},Events={SetQuantTimer=function(_,fn)timer=fn;return 1 end,KillQuantTimer=function()timer=nil end}}
 package.preload['/script/multiplayer/ufb_squad_tactics']=function() return dofile('${p.join(root,'script/multiplayer/ufb_squad_tactics.lua').replaceAll('\\','/')}') end local guard=dofile('${file}');local capture=guard.Wrap(function()orders=orders+1 end,false)
 capture(1);assert(orders==0 and timer,'active shot must own its orders')
 busy=false;local resume=timer;timer=nil;resume();assert(orders==1 and not timer,'cooldown must not immobilize a squad after its shot')`;
 const L=lauxlib.luaL_newstate();lualib.luaL_openlibs(L);const result=lauxlib.luaL_dostring(L,to_luastring(code));const err=result===lua.LUA_OK?null:to_jsstring(lua.lua_tostring(L,-1));lua.lua_close(L);assert.equal(err,null,err);
});
test('native player pickup/medic properties are enabled once, and a later manual toggle stays off',()=>{
 const a=unit('medic',0,0);a.tags.add('medic');const ordinary=unit('rifle',0,5),bot=unit('enemy medic',1,50,{bot:true});bot.tags.add('medic');const w=new Scene([a,ordinary,bot]);
 check(w.named('ufb/support/native pickup'));check(a.ai.take_new_weapon_from_ground&&ordinary.ai.take_new_weapon_from_ground);check(!bot.ai.take_new_weapon_from_ground);
 check(w.named('ufb/support/native medic'));check(a.ai.auto_medic);check(!ordinary.ai.auto_medic&&!bot.ai.auto_medic);
 a.ai.auto_medic=false;check(!w.named('ufb/support/native medic'));check(!a.ai.auto_medic,'player toggle overwritten');
});
function looting(){const a=unit('rifle',0,0),corpse=unit('corpse',1,2);corpse.states=new Set(['dead']);corpse.items=[weapon('weapon bullet mgun loot_mgun',8)];return {a,corpse,w:new Scene([a,corpse])};}
test('a rifle carrier transfers the actual better weapon without creating or duplicating it',()=>{
 const {a,corpse,w}=looting(),gun=corpse.items[0];check(w.looted('mgun','a'));check(w.named('ufb/support/loot mgun/apply a'));check(a.items.includes(gun)&&corpse.items.length===0);check(!w.named('ufb/support/loot mgun/apply a'));
});
test('player corpse looting refuses wounded men, prepared launchers, medics and a combat threat',()=>{
 for(const mode of ['wounded','launcher','medic','enemy']){
  const {a,corpse,w}=looting();if(mode==='wounded')corpse.tags.add('start_personage');if(mode==='launcher')a.held=new Set(['weapon','rocketlauncher']);if(mode==='medic')a.tags.add('medic');
  const acquired=w.looted('mgun','a');if(mode==='enemy')w.entities.push(unit('threat',1,20));
  check(!acquired||!w.named('ufb/support/loot mgun/apply a'),mode);check(corpse.items.length===1);
 }
});
test('a full inventory cannot destroy the source weapon or produce an extra one',()=>{
 const {a,corpse,w}=looting();a.maxItems=a.items.length;const gun=corpse.items[0];w.looted('mgun','a');w.named('ufb/support/loot mgun/apply a');check(corpse.items[0]===gun);check(!a.items.includes(gun));
});
function suppress(){const {a,b,w}=battle();a.items.push(weapon('weapon bullet mgun loot_mgun',20));a.held=new Set(['weapon','bullet','mgun']);b.x=60;return {a,b,w};}
test('MG pressure uses a frozen last-seen point after the enemy disappears and moves',()=>{
 const {b,w}=suppress();w.variation=1;check(w.named('ufb/suppress/acquire a'));check(w.named('ufb/suppress/apply a'));const point=w.points[0];assert.equal(point.x,60);
 b.x=1000;b.visible=false;w.advance(4.1);const shots=w.commands.filter(c=>c.name==='actor_fire');check(shots.length===3);check(shots.every(c=>c.target===point.id));assert.equal(point.x,60);w.advance(1);check(!w.entities.includes(point));
});
test('MG pressure never starts on an unseen or upright unprotected target',()=>{
 for(const mode of ['hidden','upright']){const {b,w}=suppress();if(mode==='hidden')b.visible=false;else b.covered=false;w.named('ufb/suppress/acquire a');check(!w.named('ufb/suppress/apply a'),mode);check(w.commands.length===0);}
});
test('random MG pressure expires at both 3 and 5 seconds and remains bounded',()=>{
 for(const variation of [-1,1]){const {w}=suppress();w.variation=variation;w.named('ufb/suppress/acquire a');w.named('ufb/suppress/apply a');w.advance(10);assert.equal(w.commands.filter(c=>c.name==='actor_fire').length,variation===-1?2:3);check(w.points.every(point=>!w.entities.includes(point)));}
});
test('a launcher drawn or an ally entering the old target area stops subsequent MG bursts',()=>{
 for(const mode of ['launcher','ally']){const {a,w}=suppress();w.variation=1;w.named('ufb/suppress/acquire a');w.named('ufb/suppress/apply a');if(mode==='launcher')a.held=new Set(['weapon','rocketlauncher']);else w.entities.push(unit('ally',2,60,{team:0}));w.advance(6);assert.equal(w.commands.filter(c=>c.name==='actor_fire').length,1,mode);}
});
test('active healing cannot be interrupted by grenades, looting or MG pressure',()=>{
 const {a,w}=battle();a.tags.add('_ufb_healing_active');check(!w.run('ap'));const z=looting();z.a.tags.add('_ufb_healing_active');check(!z.w.looted('mgun','a'));const m=suppress();m.a.tags.add('_ufb_healing_active');check(!m.w.named('ufb/suppress/acquire a'));
});
test('Panzerfaust 60 has a straight penetration curve and unchanged native firing range',()=>{
 const path='set/stuff/bazooka/panzerfaust_60.weapon',tree=s.parse(text(path)),table=s.all(tree,n=>s.name(n)==='projectileDamageTable')[0];
 const points=table.children.map(n=>n.tokens.map(t=>Number(t.value)));assert.deepEqual(points,[[0,200],[40,160],[200,0]]);
 for(const [distance,pen]of points)assert.equal(pen,200-distance);
 const range=s.all(tree,n=>s.name(n)==='range')[0];assert.deepEqual(range.tokens.slice(1).map(t=>t.value),['40','40']);
 const nativeTree=s.parse(fs.readFileSync(p.join(combat.reference,path),'latin1'));const baseTable=s.all(nativeTree,n=>s.name(n)==='projectileDamageTable')[0];table.children=baseTable.children;assert.deepEqual(shape(tree),shape(nativeTree));
});
test('prepared launchers retain native vehicle priorities even when infantry is closer',()=>{
 for(const target of ['car','armoredcar','tank_light','tank_medium','tank_heavy','tank_superheavy']){
  const rows=current.children.find(n=>s.name(n)===target);assert(rows,target);
  const usable=new Set(['ammo rocketlauncher','rifle','small_arms','bullet']);
  const first=rows.children.find(n=>usable.has(s.name(n))&&value(n,'enable_for_user')!=='0');assert.equal(s.name(first),'ammo rocketlauncher',target);
 }
 const selectors=s.parse(fs.readFileSync(p.join(combat.reference,'set/target/human_ap.inc'),'latin1')).children;
 for(const selector of selectors){const sorts=s.child(selector,'group').children.filter(n=>s.name(n)==='sort');const tank=sorts.findIndex(n=>value(n,'class')==='tank_medium'),human=sorts.findIndex(n=>value(n,'class')==='human');check(tank>=0&&(human<0||tank<human),'native armor priority lost');}
});
test('lying and squatting create a suppression point without requiring a cover object',()=>{
 for(const stance of ['lying','squatting']){const {b,w}=suppress();b.covered=false;b.states.add(stance);check(w.named('ufb/suppress/acquire a'));check(w.named('ufb/suppress/apply a'));}
});
test('grenade and MG routines cannot reserve the same soldier simultaneously',()=>{
 for(const first of ['grenade','mg']){const {b,w}=suppress();b.x=20;
  if(first==='grenade'){check(w.run('ap'));check(!w.named('ufb/suppress/acquire a'));}
  else {check(w.named('ufb/suppress/acquire a'));check(!w.run('ap'));}
 }
});
test('corpse loot handlers are isolated for every weapon class and side',()=>{
 const kinds=['mgun','assaultrifle','battlerifle','autorifle','semirifle'];
 for(const player of ['a','b'])for(const kind of kinds){const z=looting();z.a.team=player;z.corpse.items=[weapon('weapon bullet '+kind+' loot_'+kind)];const gun=z.corpse.items[0];
  check(z.w.looted(kind,player));
  for(const wrong of kinds.filter(k=>k!==kind))check(!z.w.named('ufb/support/loot '+wrong+'/apply '+player),'another class consumed this reservation');
  check(z.w.named('ufb/support/loot '+kind+'/apply '+player));check(z.a.items.includes(gun)&&z.corpse.items.length===0);check(z.a.tags.has('_ufb_loot_cooldown'));
 }
});
test('a failed inventory transfer does not consume a loot cooldown',()=>{
 const z=looting();z.a.maxItems=z.a.items.length;check(z.w.looted('mgun','a'));check(z.w.named('ufb/support/loot mgun/apply a'));check(!z.a.tags.has('_ufb_loot_cooldown'));check(!z.a.tags.has('_ufb_combat_busy'));check(z.corpse.items.length===1);
});
test('an upright target immediately releases the MG reservation for a grenade',()=>{
 const z=suppress();z.b.covered=false;z.b.x=20;check(z.w.named('ufb/suppress/acquire a'));check(!z.w.named('ufb/suppress/apply a'));check(!z.a.tags.has('_ufb_suppress_actor_a'));check(!z.a.tags.has('_ufb_job_reserved'));check(z.w.run('ap'));
});
test('native HF cannot reacquire a soldier during an active UFB job',()=>{
 const z=suppress();z.a.states.delete('user_control');z.a.tags.add('_bot');z.b.tags.add('_user');z.b.tags.add('_ufb_firing');
 check(z.w.named('ufb/suppress/acquire a'));check(z.w.named('ufb/suppress/apply a'));
 const hf=s.parse(text('map/multi/HF-dcg_script.inc')),under=hf.children.find(n=>s.name(n)==='hf inf ai/under mg fire');
 const selector=s.child(s.child(s.child(s.child(under,'condition'),'terms'),'1.see_actors'),'selector');check(!z.w.select(selector).includes(z.a));
});
test('UFB also respects a specialist job already reserved by native HF',()=>{
 for(const tag of ['_ai_suppressed_by_mg','_ai_mgunner','_ai_reloading','_ai_at_launcher_80','_ai_ap_grenade']){const z=suppress();z.a.tags.add(tag);check(!z.w.named('ufb/suppress/acquire a'),tag);const a=battle();a.a.tags.add(tag);check(!a.w.run('critical'),tag);}
});
test('ordinary medics remain protected before the healing animation begins',()=>{
 for(const kind of ['ap','critical','smoke','at','launcher']){const z=battle();z.a.tags.add('medic');if(kind==='smoke')z.b.x=60;if(kind==='at'){z.b.x=15;z.b.props=new Set(['vehicle']);}if(kind==='launcher')z.b.props=new Set(['vehicle']);check(!z.w.run(kind),kind);}
});
test('native user capture blocks extra orders even while the soldier is firing',()=>{
 for(const kind of ['ap','critical','smoke','at','launcher']){const z=battle({captured:true});if(kind==='smoke')z.b.x=60;if(kind==='at'){z.b.x=15;z.b.props=new Set(['vehicle']);}if(kind==='launcher')z.b.props=new Set(['vehicle']);check(!z.w.run(kind),kind);}
 const z=looting();z.a.captured=true;check(!z.w.looted('mgun','a'));
});
test('troops that are not firing receive no new offensive or smoke command',()=>{
 for(const kind of ['ap','critical','smoke','at','launcher']){const z=battle({shooting:false});if(kind==='smoke')z.b.x=60;if(kind==='at'){z.b.x=15;z.b.props=new Set(['vehicle']);}if(kind==='launcher')z.b.props=new Set(['vehicle']);check(!z.w.run(kind),kind);check(z.w.commands.length===0);}
});
test('movement and late user capture cancel pending grenade orders',()=>{
 for(const mode of ['moving','capture']){const z=battle();check(z.w.run('ap'));if(mode==='moving')z.w.event('ufb_autonomy_move_on',z.a);else z.a.captured=true;check(!z.w.run('ap','apply'));check(z.w.commands.length===0);}
 const z=battle();z.w.event('ufb_autonomy_move_on',z.a);check(!z.w.run('ap'));z.w.event('ufb_autonomy_move_off',z.a);check(z.w.run('ap'));
});
test('movement or manual capture stops later MG bursts',()=>{
 for(const mode of ['moving','capture']){const z=suppress();z.w.variation=1;check(z.w.named('ufb/suppress/acquire a'));check(z.w.named('ufb/suppress/apply a'));if(mode==='moving')z.w.event('ufb_autonomy_move_on',z.a);else z.a.captured=true;z.w.advance(6);assert.equal(z.w.commands.filter(c=>c.name==='actor_fire').length,1);}
});
test('a player MG that stops firing receives no further scripted bursts',()=>{
 const z=suppress();z.w.variation=1;check(z.w.named('ufb/suppress/acquire a'));check(z.w.named('ufb/suppress/apply a'));z.a.tags.delete('_ufb_firing');z.w.advance(6);assert.equal(z.w.commands.filter(c=>c.name==='actor_fire').length,1);
});
test('automatic AT target selectors ignore infantry while retaining armor sorting',()=>{
 const actual=s.parse(text('set/target/human_ap.inc')),base=s.parse(fs.readFileSync(p.join(combat.reference,'set/target/human_ap.inc'),'latin1'));let count=0;
 for(const selector of actual.children){const unit=s.child(selector,'unit'),group=s.child(selector,'group');if(!/^range_\d+$/.test(unit?.tokens[2]?.value||'')&&unit?.tokens[2]?.value!=='ap')continue;
  const ignores=group.children.filter(n=>s.name(n)==='ignore'&&value(n,'class')==='human');check(ignores.length===1);group.children=group.children.filter(n=>!ignores.includes(n));count++;
 }
 check(count>=7);assert.deepEqual(shape(actual),shape(base));
});
const launcher=(klass,opts={})=>{const a=unit('at',0,0,{hit:false,...opts});a.held=new Set(['weapon','rocketlauncher',klass]);const b=unit('foe',1,200,{team:1});return {a,b,w:new Scene([a,b])};};
const tick=(z,seconds=40)=>{for(let i=0;i<seconds/2;i++){z.w.named('ufb/launcher/keep near a');z.w.named('ufb/launcher/keep far a');z.w.named('ufb/launcher/tick a');z.w.advance(2);}};
test('any soldier puts a launcher away when no armor is around',()=>{
 for(const bot of [false,true]){const z=launcher('range_30',{bot});tick(z);check(z.a.held.has('rifle'),'launcher kept with nothing to shoot, bot='+bot);}
});
test('moving does not delay the return to a firearm',()=>{const z=launcher('range_70');z.a.tags.add('_ufb_autonomy_moving');tick(z);check(z.a.held.has('rifle'));});
test('a launcher is not taken away the moment it is drawn',()=>{const z=launcher('range_30');tick(z,8);check(z.a.held.has('rocketlauncher'));});
test('near armor keeps the launcher, far or hidden armor does not',()=>{
 const armor=(klass,x,visible=true)=>{const z=launcher(klass);z.b.props=new Set(['vehicle','tank']);z.b.x=x;z.b.visible=visible;tick(z,60);return z.a.held.has('rocketlauncher');};
 check(armor('range_30',60));check(armor('range_70',100));
 check(!armor('range_30',95),'Panzerfaust against a tank 95 m away');check(!armor('range_70',130));check(!armor('range_30',40,false));
});
test('after the armor leaves, the launcher goes away too',()=>{
 const z=launcher('range_30');z.b.props=new Set(['vehicle','tank']);z.b.x=40;tick(z,30);check(z.a.held.has('rocketlauncher'));z.b.visible=false;tick(z,40);check(z.a.held.has('rifle'));
});
test('direct control, reloading, an active shot and a launcher-only soldier are left alone',()=>{
 const stays=mode=>{const z=launcher('range_30');if(mode==='capture')z.a.captured=true;if(mode==='reload')z.a.tags.add('reloading');if(mode==='shot')z.a.tags.add('_ufb_firing');if(mode==='only')z.a.items=z.a.items.filter(i=>!i.tags.has('bullet'));tick(z);return z.a.held.has('rocketlauncher');};
 for(const mode of ['capture','reload','shot','only'])check(stays(mode),mode);
});
test('heavy MG fires at tracks, then at the hull, on every armored class; rifle MG rows stay absent',()=>{
 for(const klass of combat.heavyMgTargets){
  const rows=current.children.find(n=>s.name(n)===klass).children.filter(n=>s.name(n)==='hmgun').map(n=>value(n,'volume'));
  assert.deepEqual(rows,['mover','body'],klass);checks++;
  check(!current.children.find(n=>s.name(n)===klass).children.some(n=>/^mgun/.test(s.name(n))),klass);
 }
});
const gun=(id,player,x,props,opts={})=>({id,player,x,team:player,props:new Set(['cannon','vehicle',...props]),states:new Set(['operatable','inhabited',...(opts.bot?[]:['user_control'])]),captured:false,ai:{},tags:new Set(),items:[],held:new Set(),visible:true,...opts});
const armorUnit=(x,props)=>{const e=unit('armor',1,x,{team:1});e.props=new Set(['vehicle','with_gun',...props]);return e;};
function gunScene(props,enemy,opts={}){const g=gun('gun',0,0,props,opts),a=unit('crew1',0,2,{bot:opts.bot}),w=new Scene([g,a,enemy]);g.crewLinks={gunner:a};a.states.add('linked');return {g,a,enemy,w};}
test('a prisoner keeps his hands up without a gap and stays out of combat routines',()=>{
 const hands=triggers.get('ufb/surrender/hands a'),clip=s.all(hands,n=>s.name(n)==='animation')[0],loop=s.all(hands,n=>s.name(n)==='delay').find(n=>value(n,'time'));
 check(Number(value(clip,'totalTime'))>Number(value(loop,'time')),'the next clip starts before the last one ends');
 const a=unit('me',0,0,{bot:true}),w=new Scene([a,armorUnit(20,['tank'])]);a.tags.add('_ufb_surrendered');check(!w.named('ufb/fear/tank a'),'a prisoner is not sent to cover');
});
test('anti-tank and field guns are never abandoned to armor',()=>{
 for(const props of [['sq_at_gun','detect_atgun_small'],['sq_at_light'],['detect_artillery'],['sq_he_medium']]){const z=gunScene(props,armorUnit(40,['tank','heavy']));check(!z.w.named('ufb/gun/abandon light a'),props[0]);check(!z.w.named('ufb/gun/abandon heavy a'),props[0]);check(z.g.states.has('inhabited'));}
});
test('infantry alone never counts as armor',()=>{
 const rifle=()=>unit('foe',1,40,{team:1});
 const mg=gunScene(['mg_stan'],rifle());check(!mg.w.named('ufb/gun/abandon light a'),'MG stays against infantry');
 const hmg=gunScene(['mg_stan','c_mg_heavy'],rifle());check(!hmg.w.named('ufb/gun/abandon heavy a'),'HMG stays against infantry');
 const a=unit('me',0,0,{bot:true}),w=new Scene([a,unit('foe',1,20,{team:1})]);check(!w.named('ufb/fear/tank a'),'no tank alarm for a rifleman');
});
test('deployment picks its own class of gun',()=>{
 const scene=props=>gunScene(props,unit('foe',1,100,{team:1}),{bot:true});
 check(scene(['mg_stan']).w.named('ufb/gun/deploy mg a'));check(!scene(['mortar']).w.named('ufb/gun/deploy mg a'));
 check(scene(['mortar']).w.named('ufb/gun/deploy mortar a'));check(!scene(['mg_stan']).w.named('ufb/gun/deploy mortar a'));check(!scene(['sq_at_gun']).w.named('ufb/gun/deploy mortar a'));
 check(scene(['sq_at_gun']).w.named('ufb/gun/deploy at a'));check(!scene(['detect_artillery']).w.named('ufb/gun/deploy at a'));
});
test('rifle-caliber MG and mortar crews abandon the gun to tanks and armored cars',()=>{
 for(const props of [['mg_stan'],['mortar']])for(const threat of [['tank','medium'],['tank','light'],['armored_car']]){
  const z=gunScene(props,armorUnit(60,threat));check(z.w.named('ufb/gun/abandon light a'));check(z.w.native.some(n=>n.name==='emit_crew'));check(!z.g.states.has('inhabited'));
 }
});
test('12.7 mm guns stand against light armor and leave only before medium or heavy tanks',()=>{
 const stand=threat=>{const z=gunScene(['mg_stan','muzzle_hmg_m2hb'],armorUnit(60,threat));return !z.w.named('ufb/gun/abandon heavy a')&&!z.w.named('ufb/gun/abandon light a');};
 check(stand(['tank','light']));check(stand(['armored_car']));check(!stand(['tank','medium']));check(!stand(['tank','heavy']));
});
test('crews stay for infantry, trucks, distant or unseen armor, friendly armor and bunkers',()=>{
 const none=(props,e)=>{const z=gunScene(props,e);return !z.w.named('ufb/gun/abandon light a')&&!z.w.native.length;};
 check(none(['mg_stan'],unit('rifleman',1,30,{team:1})));
 const truck=armorUnit(40,['car']);truck.props.delete('with_gun');check(none(['mg_stan'],truck));
 check(none(['mg_stan'],armorUnit(120,['tank'])));check(none(['mg_stan'],{...armorUnit(40,['tank']),visible:false}));
 check(none(['mg_stan'],{...armorUnit(40,['tank']),team:0}));check(none(['mg_stan','bunker'],armorUnit(40,['tank'])));check(none(['mg_stan','muzzle_20mm_25mm_auto'],armorUnit(40,['tank'])));
});
test('a gun under direct control stays manned; a crew put back gets a 60 s pause',()=>{
 const held=gunScene(['mg_stan'],armorUnit(60,['tank']));held.g.captured=true;check(!held.w.named('ufb/gun/abandon light a'));
 const z=gunScene(['mg_stan'],armorUnit(60,['tank']));check(z.w.named('ufb/gun/abandon light a'));z.w.advance(8);z.g.states.add('inhabited');check(z.w.named('ufb/gun/return a'));z.w.jobs.length=0;check(!z.w.named('ufb/gun/abandon light a'));z.w.advance(61);check(z.w.named('ufb/gun/abandon light a'));
});
test('the crew shouts, runs about 35 m away from a marker and then takes cover',()=>{
 const z=gunScene(['mortar'],armorUnit(60,['tank']));z.w.named('ufb/gun/abandon light a');check(z.w.named('ufb/gun/crew a'));z.w.advance(0.3);
 check(z.w.commands.some(c=>c.name==='talk'&&c.actor==='crew1'&&c.line==='retreat'));const run=z.w.commands.find(c=>c.name==='move');check(run&&run.actor==='crew1');assert.equal(z.w.points[0].x,z.g.x-35);check(z.a.tags.has('_ufb_gun_job_active'));
 check(!z.w.named('ufb/gun/crew a'),'crew is ordered only once');z.w.advance(12);check(!z.a.tags.has('_lua_mi'));check(z.w.named('ufb/gun/cover a'));check(z.w.commands.some(c=>c.name==='cover'));
});
test('a bot gun deploys at first distant contact and holds off Lua orders',()=>{
 const z=gunScene(['mg_stan','cannon_sandbag_standard'],unit('foe',1,100,{team:1}),{bot:true});z.w.roll=0.9;check(z.w.named('ufb/gun/deploy mg a'));assert.equal(z.g.cannon,'fire');assert.equal(z.g.moveMode,'hold');check(z.g.tags.has('_lua_mi'));
 const near=gunScene(['mg_stan'],unit('foe',1,20,{team:1}),{bot:true});check(!near.w.named('ufb/gun/deploy mg a'));
 const mine=gunScene(['mg_stan'],unit('foe',1,100,{team:1}));check(!mine.w.named('ufb/gun/deploy mg a'),'player guns are placed by the player');
 const mortar=gunScene(['mortar'],unit('foe',1,200,{team:1}),{bot:true});check(mortar.w.named('ufb/gun/deploy mortar a'));check(!mortar.w.named('ufb/gun/deploy mg a'));
});
test('sandbags: 60 percent roll once per gun, native size, never where the game forbids them',()=>{
 const bags=(props,roll,x=100)=>{const z=gunScene(props,unit('foe',1,x,{team:1}),{bot:true});z.w.roll=roll;z.w.named('ufb/gun/deploy mg a');z.w.advance(5);return z;};
 assert.equal(bags(['mg_stan','cannon_sandbag_standard'],0.59).w.native[0]?.name,'construction_sandbag_cannon_standard_ai');
 assert.equal(bags(['mg_stan','cannon_sandbag_small'],0.59).w.native[0]?.name,'construction_sandbag_cannon_shallow_ai');
 check(!bags(['mg_stan','cannon_sandbag_standard'],0.61).w.native.length);check(!bags(['mg_stan','no_sandbags','cannon_sandbag_standard'],0).w.native.length);check(!bags(['mg_stan'],0).w.native.length);
 const lost=bags(['mg_stan','cannon_sandbag_standard'],0.61);lost.w.advance(3);check(lost.g.tags.has('_ufb_gun_fort_checked'),'failed roll must not repeat');
 const close=gunScene(['mg_stan','cannon_sandbag_standard'],unit('foe',1,100,{team:1}),{bot:true});close.w.roll=0;close.w.named('ufb/gun/deploy mg a');close.enemy.x=30;close.w.advance(5);check(!close.w.native.length,'no digging in with the enemy next to the gun');
});
test('a deployed bot gun rechecks enemy visibility after its hold timer',()=>{
 const z=gunScene(['mg_stan'],unit('foe',1,100,{team:1}),{bot:true});z.w.named('ufb/gun/deploy mg a');z.w.advance(6);check(!z.w.named('ufb/gun/release a'));z.enemy.visible=false;check(z.w.named('ufb/gun/release a'));z.w.advance(91);assert.equal(z.g.cannon,'move');check(!z.g.tags.has('_lua_mi'));check(!z.g.tags.has('_ufb_gun_deployed'));
 const y=gunScene(['mg_stan'],unit('foe',1,100,{team:1}),{bot:true});y.w.named('ufb/gun/deploy mg a');y.w.advance(6);y.enemy.visible=false;y.w.named('ufb/gun/release a');y.enemy.visible=true;y.w.advance(91);assert.equal(y.g.cannon,'fire','enemy back in sight during the pause');
});
test('bot infantry without AT weapons shouts and runs for cover from close armor; players keep control',()=>{
 const scene=(opts={},strip=true)=>{const a=unit('inf',0,0,{bot:true,...opts});if(strip)a.items=a.items.filter(i=>!i.tags.has('rocketlauncher')&&!i.tags.has('at'));return {a,w:new Scene([a,armorUnit(25,['tank'])])};};
 const z=scene();check(z.w.named('ufb/fear/tank a'));check(z.w.commands.some(c=>c.name==='cover'));check(z.w.commands.some(c=>c.line==='alert_tank'));check(!z.w.named('ufb/fear/tank a'),'25 s pause');z.w.advance(26);check(z.w.named('ufb/fear/tank a'));
 for(const item of ['rocketlauncher','at']){const y=scene({},false);y.a.items=y.a.items.filter(i=>!(i.tags.has('rocketlauncher')||i.tags.has('at'))||i.tags.has(item));check(!y.w.named('ufb/fear/tank a'),'AT soldier stands: '+item);}check(!scene({bot:false}).w.named('ufb/fear/tank a'),'player soldier keeps orders');
});
test('voice rates change only the chosen lines',()=>{
 const native=fs.readFileSync(p.join(combat.reference,'set/talk/voicelines_human.inc'),'latin1'),now=text('set/talk/voicelines_human.inc'),rate=(t,n)=>value(s.parse(t).children.find(c=>c.tokens[1]?.value===n),'freq');
 for(const [line,freq]of Object.entries(require('./static-weapons.cjs').voiceRates)){assert.equal(Number(rate(now,line)),freq);checks++;}
 const tankNow=text('set/talk/voicelines_tank.inc');for(const [line,freq]of Object.entries(require('./static-weapons.cjs').tankVoiceRates)){assert.equal(Number(rate(tankNow,line)),freq);checks++;}
 const nativeShape=t=>{const tree=s.parse(t);tree.children=tree.children.filter(n=>!n.tokens[1]?.value.startsWith('ufb_'));for(const n of tree.children)n.children=n.children.filter(c=>s.name(c)!=='freq');return shape(tree);};
 assert.deepEqual(nativeShape(tankNow),nativeShape(fs.readFileSync(p.join(combat.reference,'set/talk/voicelines_tank.inc'),'latin1')));checks++;
 check(now.includes(require('./static-weapons.cjs').mgLine));assert.deepEqual(nativeShape(now),nativeShape(native));checks++;
});
test('several soldiers in range: one owner for the job, the rest stay free',()=>{
 const a=unit('a',0,0,{shooting:true}),c=unit('c',0,1,{shooting:true}),b=unit('b',1,20,{team:1});b.held=new Set(['mgun']);const w=new Scene([a,c,b]);
 check(w.run('ap'));check([a,c].filter(e=>e.tags.has('_ufb_job_reserved')).length===1,'reservation spread over the squad');
 check(w.run('ap','apply'));check(w.commands.filter(x=>x.name==='throw_ap_grenade').length===1);check([a,c].filter(e=>e.tags.has('_ufb_combat_busy')).length===1,'busy spread over the squad');
});
test('a launcher drawn again right after stowing gets the full wait',()=>{
 const z=launcher('range_30');tick(z);check(z.a.held.has('rifle'));check(!z.a.tags.has('_ufb_launcher_ready'));z.a.held=new Set(['weapon','rocketlauncher','range_30']);tick(z,6);check(z.a.held.has('rocketlauncher'),'redrawn launcher vanished at once');tick(z,20);check(z.a.held.has('rifle'));
});
test('13 mm MG 131 counts as a heavy MG',()=>{
 const stand=gunScene(['mg_stan','c_mg_heavy'],armorUnit(60,['tank','light']));check(!stand.w.named('ufb/gun/abandon light a'));check(!stand.w.named('ufb/gun/abandon heavy a'));
 const go=gunScene(['mg_stan','c_mg_heavy'],armorUnit(60,['tank','heavy']));check(go.w.named('ufb/gun/abandon heavy a'));
});
test('only one soldier shouts when a squad scatters from armor',()=>{
 const strip=a=>{a.items=a.items.filter(i=>!i.tags.has('rocketlauncher')&&!i.tags.has('at'));return a;};
 const a=strip(unit('a',0,0,{bot:true})),c=strip(unit('c',0,1,{bot:true})),w=new Scene([a,c,armorUnit(25,['tank'])]);check(w.named('ufb/fear/tank a'));check(w.commands.filter(x=>x.name==='cover').length===2);check(w.commands.filter(x=>x.line==='alert_tank').length===1);
});
test('bot AT guns deploy on contact and dig in like other guns',()=>{
 const z=gunScene(['sq_at_gun','cannon_sandbag_standard'],unit('foe',1,150,{team:1}),{bot:true});z.w.roll=0.5;check(z.w.named('ufb/gun/deploy at a'));assert.equal(z.g.cannon,'fire');z.w.advance(5);assert.equal(z.w.native[0]?.name,'construction_sandbag_cannon_standard_ai');
 check(!gunScene(['sq_at_gun'],unit('foe',1,150,{team:1})).w.named('ufb/gun/deploy at a'),'player guns stay manual');
 check(!gunScene(['mg_stan','sq_at_gun'],unit('foe',1,100,{team:1}),{bot:true}).w.named('ufb/gun/deploy at a'),'an MG keeps the MG rule');
});
const flee=()=>{const z=gunScene(['mg_stan'],armorUnit(60,['tank']),{bot:true});z.w.named('ufb/gun/abandon light a');z.w.named('ufb/gun/crew a');z.w.advance(3);return z;};
test('crew sent to cover must still be on foot and alive',()=>{
 const z=flee();z.w.advance(10);const man=z.w.entities.find(e=>e.tags.has('_ufb_gun_cover_0_a'));check(man);man.states.add('linked');z.w.commands.length=0;z.w.named('ufb/gun/cover a');check(!z.w.commands.some(c=>c.name==='cover'&&c.actor===man.id),'linked');
});
test('a bot crew returns to its gun after the armor leaves',()=>{
 const z=flee();check(!z.w.named('ufb/gun/return a'),'armor still in view');z.enemy.visible=false;check(z.w.named('ufb/gun/return a'));z.w.advance(16);const go=z.w.commands.find(c=>c.name==='board');check(go&&go.actor==='crew1'&&go.target==='gun');
 const back=flee();back.enemy.visible=false;back.w.named('ufb/gun/return a');back.enemy.visible=true;back.w.advance(16);check(!back.w.commands.some(c=>c.name==='board'),'armor came back during the wait');
 const barred=flee();barred.g.tags.add('_no-recrew');barred.enemy.visible=false;check(!barred.w.named('ufb/gun/return a'),'game forbids recrewing');
 const late=flee();late.w.advance(125);late.enemy.visible=false;check(!late.w.named('ufb/gun/return a'),'crew gone for two minutes has moved on');
});
test('a player crew is not walked back to the gun',()=>{const z=gunScene(['mg_stan'],armorUnit(60,['tank']));z.w.named('ufb/gun/abandon light a');z.w.named('ufb/gun/crew a');z.w.advance(3);z.enemy.visible=false;check(!z.w.named('ufb/gun/return a'));});
test('the game keeps its engine-fire scene; only a helpless tank is abandoned, after a pause',()=>{
 const tank=(tags,states,seen=true)=>{const g=gun('t',0,0,['tank'],{bot:true});tags.forEach(x=>g.tags.add(x));states.forEach(x=>g.states.add(x));const e=unit('foe',1,150,{team:1});e.visible=seen;const w=new Scene([g,e]);w.named('ufb/tank/bail a');return {g,e,w};};
 for(const fire of ['burned','ammo_broken','ammo_cooked','barrel_fire']){const z=tank([fire],[]);z.w.advance(30);check(!z.w.native.length,'fire scene belongs to the game: '+fire);const y=tank([fire,'gun_broken'],[]);y.w.advance(30);check(!y.w.native.length,'burning and helpless: '+fire);}
 const z=tank(['gun_broken'],[]);z.w.advance(19);check(!z.w.native.length,'not at once');z.w.advance(2);check(z.w.native.some(n=>n.name==='emit_crew'));check(z.g.tags.has('_ufb_tank_bailed'));
 const caught=tank(['gun_broken'],[]);caught.w.advance(5);caught.g.tags.add('burned');caught.w.advance(20);check(!caught.w.native.length,'fire started during the pause');
 const gone=tank(['gun_broken'],[]);gone.e.visible=false;gone.w.advance(21);check(!gone.w.native.length,'enemy left during the pause');
 check(!tank(['gun_broken'],['chassis_work']).w.wouldFire(triggers.get('ufb/tank/bail a')),'it can still drive away');check(!tank([],[]).w.wouldFire(triggers.get('ufb/tank/bail a')),'a live gun keeps fighting');check(!tank(['gun_broken'],[],false).w.wouldFire(triggers.get('ufb/tank/bail a')),'no enemy in sight');
 const held=gun('t',0,0,['tank'],{bot:true});held.tags.add('gun_broken');held.captured=true;const foe=unit('foe',1,150,{team:1});check(!new Scene([held,foe]).named('ufb/tank/bail a'));
});
test('a bot near a real blast runs for cover once; players and busy men do not',()=>{
 const z=unit('inf',0,0,{bot:true}),w=new Scene([z]);w.event('ufb_near_blast',z);check(w.named('ufb/fear/blast a'));check(w.commands.filter(c=>c.name==='cover').length===1);check(!w.named('ufb/fear/blast a'),'one order per blast');w.advance(2);check(!w.named('ufb/fear/blast a'));w.event('ufb_near_blast',z);check(!w.named('ufb/fear/blast a'),'20 s pause');w.advance(21);w.event('ufb_near_blast',z);check(w.named('ufb/fear/blast a'));
 const p=unit('mine',0,0),q=new Scene([p]);q.event('ufb_near_blast',p);check(!q.named('ufb/fear/blast a'));
 const r=unit('repair',0,0,{bot:true}),u=new Scene([r]);r.tags.add('repairing');u.event('ufb_near_blast',r);check(!u.named('ufb/fear/blast a'));
 const human=s.parse(text('set/interaction_entity/human.inc'));check(s.all(s.all(human,n=>s.name(n)==='on'&&n.tokens[1]?.value==='blast_hit')[0],n=>s.name(n)==='call'&&n.tokens[1]?.value==='ufb_near_blast').length===1);
});
test('bot morale: lower retreat threshold, sharper when hit, recovers; players untouched',()=>{
 const tune=require('./static-weapons.cjs').tune,z=unit('inf',0,0,{bot:true}),p=unit('mine',1,0),w=new Scene([z,p]);
 check(w.named('ufb/morale/profile'));assert.equal(z.ai.retreat_ratio,tune.calmRetreat);check(p.ai.retreat_ratio===undefined);check(!w.named('ufb/morale/profile'),'profile once');
 w.event('ufb_combat_hit',z);check(w.named('ufb/morale/shaken'));assert.equal(z.ai.retreat_ratio,tune.shakenRetreat);w.advance(41);check(w.named('ufb/morale/steady'));assert.equal(z.ai.retreat_ratio,tune.calmRetreat);check(!z.tags.has('_ufb_shaken'));
 const crew=unit('crew',0,0,{bot:true});crew.props.add('crew');check(!new Scene([crew]).named('ufb/morale/profile'));
});
test('machine gun shout names real machine guns only',()=>{
 const scene=e=>{const a=unit('a',0,0),b=unit('b',0,1),w=new Scene([a,b,e]);return {w,ok:w.named('ufb/shout/mg a')};};
 const nest=gun('mg',1,60,['mg_stan']);nest.team=1;const y=scene(nest);check(y.ok);assert.equal(y.w.commands.filter(c=>c.line==='ufb_alert_mgun').length,1);
 const at=gun('pak',1,60,['sq_at_gun']);at.team=1;check(!scene(at).ok,'an AT gun is not a machine gun');
 const gunner=unit('g',1,60,{team:1,shooting:true});gunner.held=new Set(['mgun']);check(scene(gunner).ok);
 const silent=unit('h',1,60,{team:1});silent.held=new Set(['mgun']);check(!scene(silent).ok);
});
function capture(opts={}){const v=unit('v',1,0,{team:1,bot:true}),c=unit('me',opts.owner??0,10,{team:0});if(opts.hit!==false)for(const tag of ['wounded','_ufb_shaken','_ufb_recent_hit'])v.tags.add(tag);const list=[v,c,...(opts.more||[])];const w=new Scene(list);return {v,c,w};}
const giveUp=(z,owner=0)=>{const yes=z.w.named('ufb/surrender/mark a');z.w.named('ufb/surrender/helped a');z.w.advance(2.1);z.w.named('ufb/surrender/claim '+owner);z.w.advance(4);return yes;};
test('a lone wounded bot gives up to the human next to him',()=>{
 const z=capture();check(giveUp(z));assert.equal(z.v.player,0);check(!z.v.items.length,'weapons dropped');assert.equal(z.v.moveMode,'free','the owner must be able to walk him');z.v.team=0;check(z.w.named('ufb/surrender/hands a'));check(z.w.commands.some(c=>c.name==='animation'&&c.clip==='stand_giveup_1'));z.w.commands.length=0;z.v.tags.add('_ufb_autonomy_moving');check(!z.w.named('ufb/surrender/hands a'),'no hands-up loop while walking');z.v.tags.delete('_ufb_autonomy_moving');check(z.w.named('ufb/surrender/hands a'),'hands go up again on stopping');z.v.captured=true;check(!z.w.named('ufb/surrender/hands a'),'direct control is free');z.v.captured=false;check(z.v.tags.has('_ufb_surrendered'));check(z.v.tags.has('_ufb_native_pickup_initialized'),'prisoner must not rearm');
 const other=capture({owner:3});giveUp(other,3);assert.equal(other.v.player,3,'not always player 0');check(!other.v.tags.has('_ufb_prisoner_unclaimed'));
});
test('no surrender when healthy, helped, far away, downed or to another bot',()=>{
 const stays=z=>{giveUp(z);return z.v.player===1;};
 check(stays(capture({hit:false})));check(stays(capture({more:[unit('mate',1,5,{team:1,bot:true})]})));
 const far=capture();far.c.x=40;check(stays(far));const down=capture();down.v.tags.add('start_personage');check(stays(down));
 const bot=capture();bot.c.states.delete('user_control');check(stays(bot));
});
test('no generated selector uses relation; every side filter is native team',()=>{
 for(const file of ['map/multi/ufb_combat_autonomy.inc','map/multi/ufb_infantry_support.inc','map/multi/ufb_static_weapons.inc']){check(!/\{relation\b/.test(text(file)),file);check(/\{team \{team %team\}\}/.test(text(file)),file);}
});
const hatchTank=()=>{const g=gun('tank',0,0,['tank','turret'],{bot:true});return {g,w:new Scene([g])};};
const hatchOrders=z=>z.w.commands.filter(c=>c.name==='crew_enable').map(c=>c.group+':'+c.value);
test('a tank asks for the real hatch when hit and opens it when quiet',()=>{
 for(const trigger of ['bullet_hit','blast_hit'])check(hatch.children.some(n=>s.name(n)==='on'&&n.tokens[1]?.value===trigger&&s.child(n,'call')?.tokens[1]?.value==='ufb_hatch_danger'),trigger+' must start the hatch logic');
 const z=hatchTank();z.w.event('ufb_hatch_danger',z.g);check(z.g.tags.has('_ufb_hatch_shut'));assert.deepEqual(hatchOrders(z),[],'not inside the hit calculation');z.w.advance(0.2);assert.deepEqual(hatchOrders(z),['ufb_hatch:0']);
 z.w.event('ufb_hatch_danger',z.g);z.w.advance(0.2);assert.deepEqual(hatchOrders(z),['ufb_hatch:0'],'a second bullet changes nothing');
 z.w.advance(41);check(!z.g.tags.has('_ufb_hatch_shut'));assert.deepEqual(hatchOrders(z),['ufb_hatch:0','ufb_hatch:1']);
 z.w.event('ufb_hatch_danger',z.g);z.w.advance(0.2);assert.equal(hatchOrders(z).length,3,'closes again on the next hit');
});
test('tank hatch lids follow the real hatch; armored cars are left alone',()=>{
 const z=hatchTank();z.g.seats={commander:1,charger:1};z.g.tags.add('_ufb_k_tank');const lids=()=>z.w.commands.filter(c=>/_hatch_(open|close)$/.test(c.name)).map(c=>c.name);
 z.w.event('ufb_hatch_danger',z.g);assert.deepEqual(lids(),[],'not inside the hit calculation');z.w.advance(0.2);assert.deepEqual(lids(),['commander_hatch_close','charger_hatch_close']);
 z.w.advance(41);assert.deepEqual(lids().slice(2),['commander_hatch_open','charger_hatch_open']);
 const car=hatchTank();car.g.seats={commander:1};car.w.event('ufb_hatch_danger',car.g);car.w.advance(41);check(!car.w.commands.some(c=>/_hatch_(open|close)$/.test(c.name)),'no class tag');
 const empty=hatchTank();empty.g.seats={};empty.g.tags.add('_ufb_k_tank');empty.w.event('ufb_hatch_danger',empty.g);empty.w.advance(41);check(!empty.w.commands.some(c=>/_hatch_(open|close)$/.test(c.name)),'no seat');
});
test('fresh fire keeps the hatch closed; only quiet opens it',()=>{
 const z=hatchTank();z.w.event('ufb_hatch_danger',z.g);z.w.advance(15);z.w.event('ufb_hatch_danger',z.g);z.w.advance(10);check(z.g.tags.has('_ufb_hatch_shut'),'hit during the wait');z.w.advance(21);check(!z.g.tags.has('_ufb_hatch_shut'));
});
test('hatch logic skips dead vehicles, logs once and needs no fake crew tricks',()=>{
 const dead=hatchTank();dead.g.states.delete('operatable');dead.w.event('ufb_hatch_danger',dead.g);check(!dead.g.tags.has('_ufb_hatch_shut'));
 const y=hatchTank();y.w.event('ufb_hatch_danger',y.g);check(y.w.named('ufb/hatch/log a'));check(!y.w.named('ufb/hatch/log a'));
 check(text('set/interaction_entity/entity.set').includes('ufb_tank_hatch.inc'));
 const all=text('set/interaction_entity/ufb_tank_hatch.inc')+text('set/interaction_entity/ufb_static_weapon_events.inc');check(!/volumes|animate_place|with_linked_entity/.test(all),'emulation removed');
});
test('the hatch DLL loader survives a missing library',()=>{
 const {lua,lauxlib,lualib,to_luastring,to_jsstring}=require('fengari');
 const file=p.join(root,'script/multiplayer/ufb_order_guard.lua').replaceAll('\\','/');
 const run=stub=>{const L=lauxlib.luaL_newstate();lualib.luaL_openlibs(L);const code=`BotApi={} local out={} print=function(x) out[#out+1]=x end package.cpath=[[D:\\Game\\binaries\\x64\\?.dll]] ${stub} package.preload['/script/multiplayer/ufb_squad_tactics']=function() return dofile('${p.join(root,'script/multiplayer/ufb_squad_tactics.lua').replaceAll('\\','/')}') end dofile('${file}') return table.concat(out,'|')`;const r=lauxlib.luaL_dostring(L,to_luastring(code));const v=to_jsstring(lua.lua_tostring(L,-1));lua.lua_close(L);assert.equal(r,lua.LUA_OK,v);return v;};
 assert.match(run('package.loadlib=function() return nil,"not found" end'),/unavailable: not found/);checks++;
 assert.match(run('package.loadlib=function() error("boom") end'),/unavailable/);checks++;
 assert.match(run('package.loadlib=function(path) assert(path:find("mods.ultimate_frontline_bundle.ufb_hatch.dll")) return function() end end'),/native hatch active/);checks++;
 assert.match(run('package.loadlib=function() return function() error("boom") end end'),/unavailable/);checks++;
});
test('the firing tag follows real shots and fades after the last one',()=>{
 const a=unit('a',0,0),w=new Scene([a]);check(!a.tags.has('_ufb_firing'));w.event('ufb_firing',a);check(a.tags.has('_ufb_firing'));w.advance(3);w.event('ufb_firing',a);w.advance(3);check(a.tags.has('_ufb_firing'),'next shot restarts the timer');w.advance(1.1);check(!a.tags.has('_ufb_firing'));
 const human=s.parse(text('set/interaction_entity/human.inc'));check(s.all(s.all(human,n=>s.name(n)==='on'&&n.tokens[1]?.value==='fire'&&n.tokens[2]?.value==='hand_right')[0],n=>s.name(n)==='call'&&n.tokens[1]?.value==='ufb_firing').length===1);
 for(const file of ['map/multi/ufb_combat_autonomy.inc','map/multi/ufb_infantry_support.inc','map/multi/ufb_static_weapons.inc','map/multi/HF-dcg_script.inc'])check(!/prop shooting|\{prop\s*\{prop\s+shooting/.test(text(file)),file);
});
test('a soldier with a dry main weapon draws a sidearm, and a loaded one keeps his rifle',()=>{
 for(const mode of ['','in_cover','in_bush']){const rows=current.children.find(n=>n.tokens.map(t=>t.value).join(' ')==='human'+(mode?' '+mode:''));
  const first=usable=>rows.children.find(n=>usable.has(s.name(n))&&!s.child(n,'ready_for_shot')&&value(n,'enable_for_ai')!=='0');
  assert.equal(s.name(first(new Set(['rifle','pistol']))),'rifle');assert.equal(s.name(first(new Set(['smg','pistol']))),'smg');assert.equal(s.name(first(new Set(['mgun','revolver']))),'mgun');assert.equal(s.name(first(new Set(['pistol']))),'pistol');assert.equal(s.name(first(new Set(['revolver']))),'revolver');checks+=5;}
});
const truckScene=(props,enemy,opts={})=>{const t=gun('truck',0,0,props,{bot:true,...opts});t.props.delete('cannon');return {t,w:new Scene([t,enemy])};};
test('motorized infantry dismounts before contact; armor and player trucks keep going',()=>{
 const z=truckScene(['car'],unit('foe',1,120,{team:1}));check(z.w.named('ufb/truck/dismount a'));check(z.w.commands.some(c=>c.name==='emit'&&c.actor==='truck'));check(!z.w.named('ufb/truck/dismount a'),'once');
 check(!truckScene(['car'],unit('foe',1,200,{team:1})).w.named('ufb/truck/dismount a'),'far enemy');
 check(!truckScene(['car'],{...unit('foe',1,120,{team:1}),visible:false}).w.named('ufb/truck/dismount a'),'unseen enemy');
 for(const armored of ['armored_car','tank','with_gun'])check(!truckScene(['car',armored],unit('foe',1,120,{team:1})).w.named('ufb/truck/dismount a'),armored);
 for(const job of ['_lua_mi','hidden','bot_towing','offmap_supply_on_map']){const z=truckScene(['car'],unit('foe',1,120,{team:1}));z.t.tags.add(job);check(!z.w.named('ufb/truck/dismount a'),job);}
 const mine=truckScene(['car'],unit('foe',1,120,{team:1}));mine.t.states.add('user_control');check(!mine.w.named('ufb/truck/dismount a'),'player truck');
});
test('generated selectors use only forms proven by HF',()=>{
 for(const [name,n]of triggers){
  for(const g of s.all(n,x=>s.name(x)==='select'))for(const c of g.children)check(selectable.has(s.name(c)),'{'+s.name(c)+'} in select does nothing: '+name);
  for(const term of scanTerms(n,'see_actors'))if(/^ufb\/(gun|launcher|fear|tank|shout|surrender)/.test(name))for(const side of ['selector','enemy'])check(s.child(s.child(term,side),'source'),'simple selector: '+name);
 }
});
test('every tag with a symbol is quoted',()=>{
 // Unquoted, the parser stops at the symbol, logs "Unread data" and matches the wrong tag.
 for(const file of ['map/multi/ufb_static_weapons.inc','map/multi/ufb_combat_autonomy.inc','map/multi/ufb_infantry_support.inc'])assert.deepEqual(text(file).match(/\{tag(?:_add|_remove)? (?!\{)[^"{}\s]*[^\w%"{}\s][^{}]*\}/g)||[],[],file);checks++;
});
test('acquisition scans keep all candidates; gun remanning selects the nearest owned man',()=>{
 let gates=0;
 for(const [name,n]of triggers){
  const terms=s.all(s.child(n,'condition'),x=>/\.see_actors$/.test(s.name(x)||''));
  // Timed scans gate on their actions instead: hand-written (rand + first if) and quant-spread ones.
  const first=s.child(n,'actions')?.children[0],spread=quantSpread.gates(n,n.src);
  if(spread){for(const g of spread)if(value(g.condition,'type')==='see_actors')terms.push(g.condition);gates++;}
  else if(s.child(s.child(n,'condition'),'terms')?.children.every(t=>s.name(t)==='1.rand')&&s.name(first)==='if'&&value(s.child(first,'condition'),'type')==='see_actors'){terms.push(s.child(first,'condition'));gates++;}
  for(const term of terms)for(const side of ['selector','enemy']){
   const selector=s.child(term,side),amount=s.child(selector,'amount');
   if(!amount){check(true);continue;}
   const match=name.match(/^ufb\/gun\/return(?: (\d+))? ([ab])$/);assert(match&&side==='selector',name);assert.equal(amount.tokens[1].value,'1');
   const sort=s.child(selector,'sort');assert.equal(value(sort,'type'),'entity');
   const ownerTags=s.all(s.child(sort,'entity'),n=>s.name(n)==='tag'&&n.tokens[1]).map(n=>n.tokens[1].value);
   assert(ownerTags.includes(`_ufb_gun_owner_${match[1]||0}_${match[2]}`));checks++;
  }
 }
 assert(gates>=2+152,'timed rescue and supply scans: '+gates);
});
function hfMacro(name){const source=text('map/multi/HF-dcg_script.inc'),tree=s.parse(source),def=tree.children.find(n=>s.name(n)==='define'&&n.tokens[1]?.value===name),call=tree.children.find(n=>n.kind==='('&&s.name(n)===name);assert(def&&call);return expand(source.slice(def.start,def.end)+' '+source.slice(call.start,call.end))[0];}
test('tank alert follow-up actions remain eligible during their own cooldown',()=>{
 const trigger=hfMacro('ai_alert_range_antitank'),actions=s.child(trigger,'actions'),z=battle({bot:true});z.a.props=new Set(['tank','vehicle']);z.a.tags.add('_ai_tank_range_160_alert');z.a.tags.add('_ai_tank_alert_cooldown');
 const rotate=s.all(actions,n=>s.name(n)==='action'&&value(n,'action')==='rotate')[0],hold=s.all(actions,n=>s.name(n)==='actor_state'&&value(n,'move_mode')==='hold')[0],attack=s.all(actions,n=>s.name(n)==='action'&&value(n,'action')==='attack')[0];
 for(const action of [rotate,hold,attack])check(z.w.select(s.child(action,'selector')).includes(z.a));
 const acquire=s.child(s.child(s.child(trigger,'condition'),'terms'),'1.see_actors');check(!z.w.select(s.child(acquire,'selector')).includes(z.a),'cooldown must still prohibit a new acquisition');
});
test('wirecutter smoke accepts the intended engineer instead of excluding him',()=>{
 const tree=s.parse(text('map/multi/HF-dcg_script.inc')),trigger=tree.children.find(n=>s.name(n)==='hf inf ai/grenade smoke wirecutter'),enemy=s.child(s.child(s.child(s.child(trigger,'condition'),'terms'),'1.see_actors'),'enemy');
 const engineer=unit('engineer',1,20,{bot:true});engineer.tags.add('_bot');engineer.tags.add('_ai_wirecutter_in_action');check(new Scene([engineer]).select(enemy).includes(engineer));
});
test('HF cover reaction requires a visible machine gunner actually firing',()=>{
 const tree=s.parse(text('map/multi/HF-dcg_script.inc')),trigger=tree.children.find(n=>s.name(n)==='hf inf ai/under mg fire'),z=battle({bot:true});z.a.tags.add('_bot');z.b.tags.add('_user');z.b.x=60;
 check(!z.w.condition(s.child(trigger,'condition')));z.b.tags.add('_ufb_firing');check(z.w.condition(s.child(trigger,'condition')));z.b.visible=false;check(!z.w.condition(s.child(trigger,'condition')));
});
test('HF launcher draw and attack both recheck visibility and native range',()=>{
 const trigger=hfMacro('hf_rocketlauncher'),z=battle({bot:true});z.a.tags.add('_bot');z.b.tags.add('_user');z.b.props=new Set(['vehicle','tank']);z.a.items.push(weapon('weapon rocketlauncher range_30'));
 z.b.x=50;check(!z.w.wouldFire(trigger));z.b.x=25;check(z.w.wouldFire(trigger));
 const gates=s.all({children:quantSpread.body(trigger,trigger.src)},n=>s.name(n)==='if'&&value(s.child(n,'condition'),'type')==='see_actors');check(gates.length===2);
 for(const gate of gates){const condition=s.child(gate,'condition');check(z.w.term(condition,'see_actors'));z.b.x=35;check(!z.w.term(condition,'see_actors'));z.b.x=25;z.b.visible=false;check(!z.w.term(condition,'see_actors'));z.b.visible=true;z.a.captured=true;check(!z.w.term(condition,'see_actors'));z.a.captured=false;}
});
const logistics=require('./infantry-logistics.cjs'),catalog=logistics.catalog(combat.reference);
const dp=catalog.groups.find(g=>g.fill==='mgun_rus');assert(dp);
function supply(){const a=unit('supply',0,0);a.items=[weapon('weapon bullet mgun '+dp.tag,0)];a.held=new Set(a.items[0].tags);
 const b=unit('body',1,2,{states:new Set(['dead'])});b.items=[{tags:new Set(['ammo','mgun_rus','bullet']),amount:200},{tags:new Set(['ammo','mgun_ger','bullet']),amount:150}];return {a,b,w:new Scene([a,b])};}
test('a captured DP receives its native ammunition with the weapon, after the gun leaves the corpse',()=>{
 const z=looting();z.corpse.items=[weapon('weapon bullet mgun loot_mgun '+dp.tag),{tags:new Set(['ammo','mgun_rus','bullet']),amount:100},{tags:new Set(['ammo','mgun_ger','bullet']),amount:100}];
 check(z.w.looted('mgun','a'));check(z.w.named('ufb/support/loot mgun/apply a'));
 check(z.a.items.some(i=>i.tags.has('mgun_rus')));check(!z.a.items.some(i=>i.tags.has('mgun_ger')));assert.equal(z.corpse.items.length,1);
});
test('nearby resupply transfers compatible rounds, conserves stock and caps the transfer',()=>{
 const z=supply();check(z.w.named('ufb/supply/'+dp.tag+' a'));assert.equal(z.a.items.find(i=>i.tags.has('mgun_rus')).amount,120);assert.equal(z.b.items.find(i=>i.tags.has('mgun_rus')).amount,80);assert.equal(z.b.items.find(i=>i.tags.has('mgun_ger')).amount,150);
 z.w.named('ufb/supply/'+dp.tag+' a');assert.equal(z.b.items.find(i=>i.tags.has('mgun_rus')).amount,80);
});
test('a bot can also take compatible rounds after finishing its native HF loot job',()=>{
 const z=supply();z.a.states.delete('user_control');z.a.tags.add('_ai_looting_weapon');z.w.named('ufb/supply/'+dp.tag+' a');assert.equal(z.b.items[0].amount,200);
 z.a.tags.delete('_ai_looting_weapon');z.w.named('ufb/supply/'+dp.tag+' a');assert.equal(z.a.items.find(i=>i.tags.has('mgun_rus')).amount,120);
});
test('resupply refuses capture, wounded donors, distant bodies, combat danger and a full bag',()=>{
 for(const mode of ['capture','wounded','far','danger','full','enough']){const z=supply();
  if(mode==='capture')z.a.captured=true;if(mode==='wounded'){z.b.states.delete('dead');z.b.tags.add('bleeding');}if(mode==='far')z.b.x=5;
  if(mode==='danger')z.w.entities.push(unit('foe',1,15));if(mode==='full')z.a.maxItems=z.a.items.length;
  if(mode==='enough')z.a.items.push({tags:new Set(['ammo','mgun_rus']),amount:30});
  z.w.named('ufb/supply/'+dp.tag+' a');assert.equal(z.b.items[0].amount,200,mode);
 }
});
test('resupply cannot reuse a stale corpse after a threat blocked the previous attempt',()=>{
 const z=supply(),foe=unit('foe',1,15);z.w.entities.push(foe);z.w.named('ufb/supply/'+dp.tag+' a');z.b.x=100;foe.visible=false;
 z.w.named('ufb/supply/'+dp.tag+' a');assert.equal(z.b.items[0].amount,200);check(!z.a.tags.has('_ufb_supply_actor_a'));
});
test('firearm markers preserve every native statistic and replace inherited incompatible markers',()=>{
 for(const w of catalog.weapons){const tree=s.parse(logistics.marker(w)),original=s.parse(w.source),node=tree.children[0];const tag=node.children.pop();check(s.name(tag)==='tag');assert.deepEqual(shape(tree),shape(original),w.file);checks++;}
 const st=s.parse(text('set/target/ammo.set'));for(const n of st.children[0].children.filter(n=>s.name(n)==='human'))check(n.children.some(n=>s.name(n)==='small_arms'&&!s.child(n,'ready_for_shot')),'usable reserve firearm draw');
});
function rescueScene({medic=true,foe=true}={}){
 const a=unit('rescuer',0,0),b=unit('casualty',0,3);b.tags.add('bleeding');
 const entities=[a,b];let m;if(medic){m=unit('medic',0,-30);m.tags.add('medic');entities.push(m);}let e;if(foe){e=unit('foe',1,50);entities.push(e);}
 return {a,b,m,e,w:new Scene(entities)};
}
test('player rescue collects a wounded ally, carries him to a medic, drops only the patient and returns',()=>{
 const z=rescueScene(),count=z.a.items.length;check(z.w.named('ufb/rescue/acquire a'));check(z.a.items.some(i=>i.tags.has('human')));check(z.a.tags.has('_ufb_rescue_active'));
 z.w.advance(6);assert.equal(z.a.x,-30);z.w.advance(14);assert.equal(z.b.x,-30);check(!z.b.states.has('linked'));assert.equal(z.a.items.length,count);
 z.w.advance(2);assert.equal(z.a.x,0);z.w.advance(25);check(!z.a.tags.has('_ufb_rescue_active'));check(!z.b.tags.has('_ufb_rescue_patient'));check(z.w.points.every(p=>!z.w.entities.includes(p)));
});
test('without a medic the casualty is carried toward the rear and the carrier returns',()=>{
 const z=rescueScene({medic:false});check(z.w.named('ufb/rescue/acquire a'));z.w.advance(20);assert.equal(z.b.x,-25);z.w.advance(2);assert.equal(z.a.x,0);
});
test('a danger near the destination or an enemy at point-blank range prevents evacuation',()=>{
 for(const close of [false,true]){const z=rescueScene();z.e.x=close?10:30;if(!close)z.m.x=10;z.w.named('ufb/rescue/acquire a');z.w.advance(22);check(!z.w.commands.some(c=>c.name==='collect'),String(close));check(!z.b.states.has('linked'));}
});
test('evacuation does not commandeer a moving, selected or busy soldier',()=>{
 for(const mode of ['moving','capture','busy']){const z=rescueScene();if(mode==='moving')z.a.tags.add('_ufb_autonomy_moving');if(mode==='capture')z.a.captured=true;if(mode==='busy')z.a.tags.add('_ufb_job_reserved');
  z.w.named('ufb/rescue/acquire a');check(!z.w.commands.some(c=>c.name==='collect'),mode);}
});
test('manual capture permanently cancels delayed rescue orders, including after deselection',()=>{
 const z=rescueScene();z.w.named('ufb/rescue/acquire a');z.w.advance(6);z.a.captured=true;check(z.w.named('ufb/rescue/manual a'));z.a.captured=false;
 const before=z.w.commands.length;z.w.advance(41);assert.equal(z.w.commands.length,before);check(z.a.items.some(i=>i.tags.has('human')),'carried patient stays under manual control');
});
test('a new threat at the saved position prevents the automatic return',()=>{
 const z=rescueScene();z.w.named('ufb/rescue/acquire a');z.w.advance(20);z.e.x=0;z.w.advance(2);assert.equal(z.a.x,-30);
});
test('failed pickup and multiple helpers cannot create a patient or reserve the whole squad',()=>{
 const z=rescueScene();z.a.pathBlocked=true;z.w.entities.push(unit('other',0,1));z.w.named('ufb/rescue/acquire a');
 assert.equal(z.w.entities.filter(e=>e.tags.has('_ufb_rescue_active')).length,1);z.w.advance(47);check(!z.a.items.some(i=>i.tags.has('human')));check(!z.b.states.has('linked'));check(!z.a.tags.has('_ufb_rescue_active'));
});
test('medic smoke needs both a wounded ally and a visible threat and consumes real stock',()=>{
 const z=rescueScene();z.a.tags.add('medic');z.m.tags.delete('medic');const before=z.a.items.find(i=>i.tags.has('smoke')).amount;
 check(z.w.named('ufb/medic/smoke a'));assert.equal(z.a.items.find(i=>i.tags.has('smoke')).amount,before-1);check(z.w.commands.some(c=>c.name==='throw_sk_grenade'));check(z.a.tags.has('_ufb_medic_smoke_cooldown'));check(!z.w.named('ufb/medic/smoke a'));
 z.w.advance(4);check(z.w.points.every(p=>!z.w.entities.includes(p)));
});
test('medics do not use smoke without stock, for dead enemies, without casualties or during healing/direct control',()=>{
 for(const mode of ['none','dead','no-patient','healing','capture','wp','hidden','linked']){const z=rescueScene();z.a.tags.add('medic');z.m.tags.delete('medic');
  if(mode==='none')z.a.items.find(i=>i.tags.has('smoke')).amount=0;if(mode==='dead')z.e.states.add('dead');if(mode==='no-patient')z.b.tags.clear();
  if(mode==='healing')z.a.tags.add('_ufb_healing_active');if(mode==='capture')z.a.captured=true;if(mode==='wp')z.a.items.push(weapon('m15_wp'));
  if(mode==='hidden')z.e.visible=false;if(mode==='linked')z.a.states.add('linked');z.w.named('ufb/medic/smoke a');check(!z.w.commands.some(c=>c.name==='throw_sk_grenade'),mode);
 }
});
test('air warning requires a living visible enemy aircraft, rather than a wreck, ally or ground vehicle',()=>{
 for(const mode of ['real','none','dead','inactive','ally','hidden','ground']){const a=unit('speaker',0,0),plane=unit('plane',1,150);plane.props=new Set(['vehicle','airborne']);
  if(mode==='dead')plane.states.add('dead');if(mode==='inactive')plane.states.add('inactive');if(mode==='ally')plane.team=0;if(mode==='hidden')plane.visible=false;if(mode==='ground')plane.props.delete('airborne');
  const w=new Scene(mode==='none'?[a]:[a,plane]);w.named('ufb/air/human a');assert.equal(w.commands.some(c=>c.name==='talk'&&c.line==='ufb_alert_airborne'),mode==='real',mode);
  if(mode==='real'){check(!w.named('ufb/air/human a'));w.advance(91);check(w.named('ufb/air/human a'));}
 }
});
const hfOrderSource=text('map/multi/HF-dcg_script.inc'),hfOrderTree=s.parse(hfOrderSource);
const hfRoutine=name=>Object.assign(hfOrderTree.children.find(n=>s.name(n)===name),{src:hfOrderSource});
function coverBatch(routine){const cover=s.all(routine,n=>s.name(n)==='actor_to_cover')[0];assert(cover);const parent=s.all(routine,n=>n.children.includes(cover))[0],at=parent.children.indexOf(cover);const batch=parent.children.slice(at-1,at+2);assert.deepEqual(batch.map(s.name),['effect','actor_to_cover','effect']);assert.equal(value(batch[0],'effect'),'ufb_hf_cover_prepare');assert.equal(value(batch[2],'effect'),'ufb_hf_cover_committed');return batch;}
test('near-player reaction cannot reset orders on passengers; an active foot soldier still reacts',()=>{
 const routine=hfRoutine('hf inf ai/near player'),drop=s.all(routine,n=>s.name(n)==='actor_state'&&s.child(n,'drop'))[0];assert(drop);
 const men=Array.from({length:5},(_,i)=>unit('passenger'+i,1,0,{bot:true}));
 for(const man of men){man.states.add('linked');man.tags.add('_ai_near_player');}
 const foot=unit('foot',1,0,{bot:true});foot.tags.add('_ai_near_player');
 const w=new Scene([...men,foot]);assert.deepEqual(w.select(s.child(drop,'selector')).map(e=>e.id),['foot']);
 const old=s.parse(fs.readFileSync(p.join(combat.reference,'map/multi/HF-dcg_script.inc'),'latin1')).children.find(n=>s.name(n)==='hf inf ai/near player');
 const oldDrop=s.all(old,n=>s.name(n)==='actor_state'&&s.child(n,'drop'))[0];assert.equal(w.select(s.child(oldDrop,'selector')).length,6,'Reproduce native linked-passenger selection');
 // Native HF acquisition used to include passengers before assigning this reaction tag.
 const acquire=s.child(scanTerms(routine,'see_actors')[0],'selector');assert(acquire);
 assert(!w.select(acquire).some(e=>e.states.has('linked')));
});
test('delayed HF cover rejects boarding, death and inactivity after acquisition',()=>{
 const batch=coverBatch(hfRoutine('hf inf ai/ai reloads'));
 for(const state of ['linked','dead','inactive','valid']){
  const man=unit(state,1,0,{bot:true});man.tags.add('_ai_reloading');const w=new Scene([man]);
  w.later(3,()=>w.actions(batch));if(state!=='valid')man.states.add(state);w.advance(3);
  assert.equal(w.commands.some(c=>c.name==='cover'),state==='valid',state);check(true);
 }
});

test('failed HF cover releases its reservation and bounds repeated searches',()=>{
 const man=unit('foot',1,0,{bot:true});man.tags.add('_ai_reloading');const w=new Scene([man]),batch=coverBatch(hfRoutine('hf inf ai/ai reloads'));
 w.actions(batch);assert.equal(w.commands.length,1);check(man.tags.has('_ufb_hf_cover_active'));
 w.advance(0.5);check(!man.tags.has('_ufb_hf_cover_active'));check(man.tags.has('_ufb_hf_cover_retry'));
 for(let i=0;i<20;i++){w.actions(batch);w.advance(0.5);}assert.equal(w.commands.length,1,'Failed searches do not repeat every scan');
 w.advance(2);w.actions(batch);assert.equal(w.commands.length,2,'A retry remains available');check(true);
});
test('moving or reaching cover confirms the HF reaction without a failed-search cooldown',()=>{
 for(const mode of ['moving','covered']){
  const man=unit(mode,1,0,{bot:true});man.tags.add('_ai_reloading');const w=new Scene([man]);w.actions(coverBatch(hfRoutine('hf inf ai/ai reloads')));
  if(mode==='moving')w.event('ufb_autonomy_move_on',man);else man.covered=true;
  w.advance(0.5);check(man.tags.has('_ufb_hf_cover_active'));check(!man.tags.has('_ufb_hf_cover_retry'));w.advance(2.5);check(!man.tags.has('_ufb_hf_cover_active'));
 }
});
test('a new position immediately makes a failed HF cover search eligible again',()=>{
 const man=unit('foot',1,0,{bot:true});man.tags.add('_ai_reloading');const w=new Scene([man]),batch=coverBatch(hfRoutine('hf inf ai/ai reloads'));
 w.actions(batch);w.advance(0.5);w.actions(batch);assert.equal(w.commands.length,1);
 w.event('ufb_autonomy_move_on',man);check(!man.tags.has('_ufb_hf_cover_retry'));w.actions(batch);assert.equal(w.commands.length,2);w.advance(0.5);check(!man.tags.has('_ufb_hf_cover_retry'));
});
test('HF does not move a soldier who already occupies cover or has a cover order in progress',()=>{
 for(const mode of ['covered','active']){const man=unit(mode,1,0,{bot:true});man.tags.add('_ai_reloading');if(mode==='covered')man.covered=true;else man.tags.add('_ufb_hf_cover_active');const w=new Scene([man]);w.actions(coverBatch(hfRoutine('hf inf ai/ai reloads')));assert.equal(w.commands.length,0,mode);check(!man.tags.has('_ufb_hf_cover_attempt'));}
});
test('a tagged Pak or marker cannot receive an infantry cover command',()=>{
 const cover=s.all(hfRoutine('hf inf ai/ai reloads'),n=>s.name(n)==='actor_to_cover')[0];
 const gun=unit('pak',1,0,{bot:true});gun.props=new Set(['vehicle','cannon']);gun.tags.add('_ai_reloading');
 const marker=unit('marker',1,0,{bot:true});marker.props.clear();marker.tags.add('_ai_reloading');
 const w=new Scene([gun,marker]);w.actions([cover]);assert.equal(w.commands.length,0);check(true);
 const old=s.parse(fs.readFileSync(p.join(combat.reference,'map/multi/HF-dcg_script.inc'),'latin1')).children.find(n=>s.name(n)==='hf inf ai/ai reloads');
 assert.equal(w.select(s.child(s.all(old,n=>s.name(n)==='actor_to_cover')[0],'selector')).length,2,'Reproduce untyped cover selection');
});
test('crew cover rechecks each tagged man without clearing another active actor',()=>{
 const tree=s.parse(text('map/multi/ufb_crew_skirmish.inc')),owner=tree.children.find(n=>s.name(n)==='ufb/crew/take cover');
 const commands=s.child(owner,'actions').children.filter(n=>s.name(n)==='actor_state'||s.name(n)==='actor_to_cover');
 const linked=unit('linked',1,0,{bot:true}),foot=unit('foot',1,0,{bot:true});for(const e of [linked,foot])e.tags.add('_ufb_crew_pending');linked.states.add('linked');
 const w=new Scene([linked,foot]);w.actions(commands);assert.deepEqual(w.commands.filter(c=>c.name==='cover').map(c=>c.actor),['foot']);
 assert.equal(linked.moveMode,undefined);assert.equal(foot.moveMode,'zone');check(true);
});
test('the malformed German squad expands to the same ten men with no eighth placeholder',()=>{
 const fix=require('./unit-template-fixes.cjs'),file=text(fix.file),tree=s.parse(file);
 const call=tree.children.find(n=>n.kind==='('&&file.slice(n.start,n.end).includes('name('+fix.unit+')'));assert(call);
 const raw=file.slice(call.start,call.end),args=Object.fromEntries([...raw.matchAll(/\b(c\d+)\(([^)]+)\)/g)].map(m=>[m[1],m[2]]));
 const settings=fs.readFileSync(p.join(combat.reference,'set/multiplayer/units/settings.set'),'latin1');
 const def=s.parse(settings).children.find(n=>s.name(n)==='define'&&n.tokens[1]?.value===s.name(call));assert(def);
 const previous=s.parse(settings).children.find(n=>s.name(n)==='define'&&n.tokens[1]?.value==='squad_with8types_doc');
 const meta=n=>[n.kind,n.tokens.map(t=>t.value),n.children.filter(c=>s.name(c)!=='content').map(meta)];
 assert.deepEqual(def.children.map(meta),previous.children.map(meta),'Template metadata must remain identical');
 const content=s.all(def,n=>s.name(n)==='content')[0].tokens[1].value;
 const expanded=content.replace(/%c\d+/g,key=>args[key.slice(1)]||key);
 assert(!/%c\d+/.test(expanded));
 const composition=[...expanded.matchAll(/\/(waffen_[^\s:]+):(\d+)/g)].map(m=>[m[1],Number(m[2])]);
 assert.equal(composition.length,7);assert.equal(composition.reduce((sum,[,n])=>sum+n,0),10);check(true);
});

test('timed loot scans evaluate tag pair once, clean up and rearm on success and failure',()=>{
 const n=triggers.get('ufb/support/loot mgun/acquire a'),kids=s.child(n,'actions').children;
 const phase=Number(value(kids[0],'time')),rest=Number(value(kids.at(-2),'time'));
 check(phase>0);assert.equal(phase+rest,1);
 for(const found of [true,false]){
  const {a,corpse,w}=looting();if(!found)corpse.x=50;
  let scans=0;const term=w.term.bind(w);
  w.term=(node,type)=>{if(type==='see_actors'&&s.child(node,'tag'))scans++;return term(node,type);};
  // Execute the emitted timer and gates, including the phase skipped by fire().
  w.actions(kids);w.advance(phase-0.01);assert.equal(scans,0);
  w.advance(0.01);assert.equal(scans,1);
  assert.equal(a.tags.has('_ufb_loot_mgun_actor_a'),found);
  assert.equal(corpse.tags.has('_ufb_loot_mgun_body_a'),found);
  w.advance((found?9:0)+rest-0.01);assert.equal(w.jobs.length,0);
  w.advance(0.02);assert.deepEqual(w.jobs,['ufb/support/loot mgun/acquire a']);
  assert.equal(scans,1);check(!a.tags.has('_ufb_loot_mgun_actor_a'));check(!corpse.tags.has('_ufb_loot_mgun_body_a'));
  assert.equal(corpse.items.length,1);
 }
});
test('previous-hit history alone and an unarmed captor cannot cause surrender',()=>{
 for(const mode of ['history','unarmed','calm']){const z=capture();
  if(mode==='history'){z.v.tags=new Set(['_ufb_was_hit']);}
  if(mode==='unarmed'){z.c.items=[];z.c.held=new Set();}
  if(mode==='calm')z.v.tags.delete('_ufb_shaken');
  giveUp(z);check(!z.v.tags.has('_ufb_surrendered'),mode);check(z.v.items.length>0,mode);
 }
});
test('wounded teammates still count as support and prevent group surrender',()=>{
 const mates=[unit('mate1',1,2,{bot:true}),unit('mate2',1,4,{bot:true})];
 for(const m of mates)for(const tag of ['wounded','_ufb_shaken','_ufb_recent_hit','_ufb_was_hit'])m.tags.add(tag);
 const z=capture({more:mates});giveUp(z);check([z.v,...mates].every(e=>e.player===1&&!e.tags.has('_ufb_surrendered')));
});
test('surrender rechecks the captor and new support at the commit point',()=>{
 for(const mode of ['far','hidden','unarmed','help']){const z=capture();check(z.w.named('ufb/surrender/mark a'));
  if(mode==='far')z.c.x=1000;if(mode==='hidden')z.c.visible=false;if(mode==='unarmed')z.c.held=new Set();if(mode==='help')z.w.entities.push(unit('friend',1,3,{bot:true}));
  z.w.advance(6);check(!z.v.tags.has('_ufb_surrendered'),mode);check(z.v.items.length>0,mode);
 }
});
test('surrender recheck commits each still eligible victim instead of the old whole batch',()=>{
 const z=capture(),other=unit('recovered',1,100,{bot:true}),captor=unit('otherCaptor',0,105);
 for(const tag of ['wounded','_ufb_shaken','_ufb_recent_hit'])other.tags.add(tag);
 z.w.entities.push(other,captor);check(z.w.named('ufb/surrender/mark a'));check(other.tags.has('_ufb_surrender_a'));other.tags.delete('wounded');z.w.advance(6);
 check(z.v.tags.has('_ufb_surrendered'));check(!other.tags.has('_ufb_surrendered'));check(other.items.length>0);
});
test('only the original linked crew receives the gun retreat job',()=>{
 const z=gunScene(['mg_stan'],armorUnit(60,['tank']),{bot:true}),rifle=unit('passer',0,3,{bot:true}),medic=unit('medic',0,4,{bot:true});
 medic.tags.add('medic');medic.tags.add('_ufb_healing_active');z.w.entities.push(rifle,medic);
 z.w.named('ufb/gun/abandon light a');z.w.named('ufb/gun/crew a');z.w.advance(0.3);
 assert.deepEqual(z.w.commands.filter(c=>c.name==='move').map(c=>c.actor),['crew1']);check(!rifle.tags.has('_ufb_gun_job_active'));check(!medic.tags.has('_ufb_gun_job_active'));
});
test('two guns retain their own crews despite reversed actor enumeration',()=>{
 const first=gun('first',0,0,['mg_stan'],{bot:true}),second=gun('second',0,50,['mortar'],{bot:true});
 const a=unit('firstCrew',0,2,{bot:true}),b=unit('secondCrew',0,52,{bot:true});a.states.add('linked');b.states.add('linked');first.crewLinks={gunner:a};second.crewLinks={gunner:b};
 const enemy=armorUnit(25,['tank']),w=new Scene([first,b,second,a,enemy]);w.named('ufb/gun/abandon light a');
 check(a.tags.has('_ufb_gun_crew_0_a')&&!b.tags.has('_ufb_gun_crew_0_a'));check(b.tags.has('_ufb_gun_crew_1_a'));
 w.named('ufb/gun/crew a');w.named('ufb/gun/crew 1 a');w.advance(13);enemy.visible=false;
 w.named('ufb/gun/return a');w.named('ufb/gun/return 1 a');w.advance(16);
 assert.deepEqual(w.commands.filter(c=>c.name==='board').map(c=>[c.actor,c.target]).sort(),[['firstCrew','first'],['secondCrew','second']]);
 check(!a.tags.has('_ufb_gun_job_active')&&!b.tags.has('_ufb_gun_job_active'));
});
test('crew jobs expire without stranded reservations or premature slot reuse',()=>{
 const z=flee();z.w.advance(118);check(!z.a.tags.has('_ufb_gun_job_active'));check(!z.g.tags.has('_ufb_gun_bound'));
 check(z.w.entities.some(e=>e.tags.has('_ufb_gun_lease_0_a')));z.w.advance(20);check(!z.w.entities.some(e=>e.tags.has('_ufb_gun_lease_0_a')));
});
test('a fresh hit restarts morale recovery from the latest threat',()=>{
 const a=unit('bot',0,0,{bot:true}),w=new Scene([a]);w.named('ufb/morale/profile');w.event('ufb_combat_hit',a);w.named('ufb/morale/shaken');
 w.advance(39);w.event('ufb_combat_hit',a);w.advance(1.1);check(!w.named('ufb/morale/steady'));check(a.tags.has('_ufb_shaken'));
 w.advance(39);check(w.named('ufb/morale/steady'));check(!a.tags.has('_ufb_shaken'));
});
test('classification and initial morale profile retain their original three-second cycle',()=>{
 for(const key of ['ufb/class','ufb/morale/profile']){const n=triggers.get(key);check(!quantSpread.gates(n,n.src));const delays=s.child(n,'actions').children.filter(c=>s.name(c)==='delay');assert.deepEqual(delays.map(n=>Number(value(n,'time'))),[3]);}
});
test('legacy crew profiles use valid classification tags and respect the new owner',()=>{
 for(const file of ['ufb_crew_safety.inc','ufb_crew_skirmish.inc']){
  const tree=s.parse(text('map/multi/'+file)),def=tree.children.find(n=>s.name(n)==='define'&&n.tokens[1]?.value==='ufb_crew_candidates');assert(def);
  const actor=unit('nativeCrew',0,0,{bot:true});actor.props.add('crew');const w=new Scene([actor]);w.classify();check(w.select(def).includes(actor));
  for(const select of s.all(def,n=>s.name(n)==='select'))check(select.children.every(n=>s.name(n)==='tag'));
  const bot=tree.children.find(n=>s.name(n)==='define'&&n.tokens[1]?.value==='ufb_bot_crew_candidates');actor.tags.add('_ufb_crew_profile');actor.tags.add('_bot');actor.tags.add('_ufb_gun_job_active');check(!w.select(bot).includes(actor));
 }
});
test('one nearby crewman cannot pull a distant crewman back to the gun',()=>{
 const z=gunScene(['mg_stan'],armorUnit(60,['tank']),{bot:true}),far=unit('distantCrew',0,0,{bot:true});far.states.add('linked');z.g.crewLinks.loader=far;z.w.entities.unshift(far);
 z.w.named('ufb/gun/abandon light a');z.w.named('ufb/gun/crew a');z.w.advance(13);far.x=200;z.enemy.visible=false;check(z.w.named('ufb/gun/return a'));z.w.advance(16);
 assert.deepEqual(z.w.commands.filter(c=>c.name==='board').map(c=>c.actor),['crew1']);checks++;
});
test('crew return rechecks boarding, ownership, distance and protection after its delay',()=>{
 for(const mode of ['dead','linked','player','healing','far','capturedGun','remanned','threat']){
  const z=flee();z.enemy.visible=false;check(z.w.named('ufb/gun/return a'));
  if(mode==='dead'||mode==='linked')z.a.states.add(mode);if(mode==='player')z.a.states.add('user_control');if(mode==='healing')z.a.tags.add('_ufb_healing_active');if(mode==='far')z.a.x=200;if(mode==='capturedGun')z.g.team=1;if(mode==='remanned')z.g.states.add('inhabited');if(mode==='threat')z.enemy.visible=true;
  z.w.advance(16);check(!z.w.commands.some(c=>c.name==='board'),mode);
 }
});
test('crew lease capacity falls back to native dismount without stealing people',()=>{
 const jobs=require('./gun-crew-jobs.cjs'),entities=[];
 for(let i=0;i<jobs.SLOTS+1;i++){const g=gun('g'+i,0,0,['mg_stan'],{bot:true}),a=unit('c'+i,0,2,{bot:true});a.states.add('linked');g.crewLinks={gunner:a};entities.push(g,a);}
 entities.push(armorUnit(60,['tank']));const w=new Scene(entities);check(w.named('ufb/gun/abandon light a'));
 assert.equal(w.native.filter(c=>c.name==='emit_crew').length,jobs.SLOTS+1);assert.equal(w.entities.filter(e=>e.tags.has('_ufb_gun_job_active')).length,jobs.SLOTS);
 const last=entities.find(e=>e.id==='c'+jobs.SLOTS);check(!last.tags.has('_ufb_gun_job_active'));check(!last.states.has('linked'));
});

test('empty guns do not pack up when the old hold timer expires',()=>{
 const z=gunScene(['mg_stan'],unit('foe',1,100,{team:1}),{bot:true});z.w.named('ufb/gun/deploy mg a');z.w.advance(6);z.enemy.visible=false;check(z.w.named('ufb/gun/release a'));
 z.w.advance(20);z.g.states.delete('inhabited');z.w.advance(71);assert.equal(z.g.cannon,'fire','empty gun received a folding command');check(!z.g.tags.has('_lua_mi'));check(!z.g.tags.has('_ufb_gun_deployed'));
});
test('delayed fortification stops when the crew leaves',()=>{
 const z=gunScene(['mg_stan','cannon_sandbag_standard'],unit('foe',1,100,{team:1}),{bot:true});z.w.roll=0;z.w.named('ufb/gun/deploy mg a');z.w.advance(2);z.g.states.delete('inhabited');z.w.advance(3);check(z.w.native.length===0,'empty gun received the sandbag construction effect');
});
test('overlapping MG and mortar deployments retain independent construction tags',()=>{
 const mg=gun('mg',0,0,['mg_stan','cannon_sandbag_standard'],{bot:true}),mortar=gun('mortar',0,10,['mortar','cannon_sandbag_small'],{bot:true}),enemy=unit('foe',1,100,{team:1}),w=new Scene([mg,mortar,enemy]);
 w.roll=0;w.named('ufb/gun/deploy mg a');w.advance(2);w.named('ufb/gun/deploy mortar a');w.advance(2.1);
 assert.deepEqual(w.native.map(x=>x.gun),['mg']);w.advance(2);assert.deepEqual(w.native.map(x=>[x.gun,x.name]),[['mg','construction_sandbag_cannon_standard_ai'],['mortar','construction_sandbag_cannon_shallow_ai']]);checks+=2;
});
test('a later deployment cannot be folded by another guns old timer',()=>{
 const z=gunScene(['mg_stan'],unit('foe',1,100,{team:1}),{bot:true});z.w.named('ufb/gun/deploy mg a');z.w.advance(6);z.enemy.visible=false;z.w.named('ufb/gun/release a');z.w.advance(45);
 const fresh=gun('fresh',0,10,['mg_stan'],{bot:true});fresh.tags.add('_ufb_gun_deployed');fresh.tags.add('_lua_mi');fresh.cannon='fire';z.w.entities.push(fresh);z.w.advance(46);
 assert.equal(z.g.cannon,'move');assert.equal(fresh.cannon,'fire');check(fresh.tags.has('_ufb_gun_deployed')&&fresh.tags.has('_lua_mi'));
});
test('every HF cannon command requires a live manned bot gun at execution',()=>{
 const tree=s.parse(text('map/multi/HF-dcg_script.inc')),commands=s.all(tree,n=>s.name(n)==='actor_state'&&s.child(n,'cannon'));assert.equal(commands.length,8);
 for(const command of commands){const selector=s.child(command,'selector'),group=s.child(selector,'group');const tags=[s.child(group,'select'),s.child(group,'include')].filter(Boolean).flatMap(n=>s.all(n,x=>s.name(x)==='tag'&&x.tokens[1]).map(n=>n.tokens[1].value));
  for(const mode of ['ready','empty','dead','inactive','linked','player','infantry']){
   const g=gun('hf',0,0,['mg_stan'],{bot:true});tags.forEach(t=>g.tags.add(t));if(mode==='empty')g.states.delete('inhabited');if(['dead','inactive','linked'].includes(mode))g.states.add(mode);if(mode==='player')g.states.add('user_control');if(mode==='infantry')g.props.delete('cannon');
   const w=new Scene([g]);w.actions([command]);assert.equal(g.cannon,mode==='ready'?value(command,'cannon'):undefined,mode+' '+value(command,'cannon'));checks++;
  }
 }
});

test('empty seats are not occupied seats',()=>{
 const w=new Scene([]),e=unit('seat',0,0,{seats:{commander:false}});
 const n=s.parse('{if crew_in_place "commander" {tags add "occupied"}}').children;
 w.eventNodes(n,e);check(!e.tags.has('occupied'));e.seats.commander=true;
 w.eventNodes(n,e);check(e.tags.has('occupied'));
});
test('crew cover failure releases ownership and bounds retries',()=>{
 const e=unit('crew',0,0,{bot:true}),w=new Scene([e]);w.event('ufb_crew_cover_lease',e);
 check(e.tags.has('_ufb_crew_safe'));w.advance(0.5);check(!e.tags.has('_ufb_crew_safe'));
 check(e.tags.has('_ufb_crew_cover_retry'));w.advance(12);check(!e.tags.has('_ufb_crew_cover_retry'));
});
test('crew movement cannot reserve a failed cover task forever',()=>{
 const e=unit('crew',0,0,{bot:true}),w=new Scene([e]);e.tags.add('_ufb_autonomy_moving');
 w.event('ufb_crew_cover_lease',e);w.advance(0.5);check(e.tags.has('_ufb_crew_safe'));
 w.advance(11.5);check(!e.tags.has('_ufb_crew_safe'));
});
test('successful crew cover holds only while covered and alive on foot',()=>{
 for(const mode of ['leave','dead','linked']){
  const e=unit('crew',0,0,{bot:true,covered:true}),w=new Scene([e]);w.event('ufb_crew_cover_lease',e);
  w.advance(12);check(e.tags.has('_ufb_crew_safe'));
  if(mode==='leave')e.covered=false;else e.states.add(mode);
  w.advance(3);check(!e.tags.has('_ufb_crew_safe'));
 }
});

console.log(JSON.stringify({scenarios,checks,passed:true,gemBattleTested:false}));
