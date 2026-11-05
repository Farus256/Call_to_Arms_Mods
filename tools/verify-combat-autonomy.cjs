// Execute the emitted mission SDL against small deterministic scenes.
// This verifies policy/lifecycle, not GEM ballistics or animation timing.
const fs=require('fs'),p=require('path'),assert=require('assert/strict'),s=require('./lib/sdl.cjs');
const combat=require('./combat-autonomy.cjs');
const root=p.resolve(process.argv[2]||p.join(__dirname,'../mods/ultimate_frontline_bundle/resource'));
const text=rel=>fs.readFileSync(p.join(root,rel),'latin1');
combat.verify(root);
const mission=text('map/multi/ufb_combat_autonomy.inc'),events=text('set/interaction_entity/ufb_combat_events.inc');
function expand(source){
 const nodes=s.parse(source).children,defs=new Map(nodes.filter(n=>s.name(n)==='define').map(n=>[n.tokens[1].value,n]));
 const output=[];for(const n of nodes){
  if(s.name(n)==='define'||s.name(n)==='include')continue;
  if(n.kind!=='('){output.push(n);continue;}
  const def=defs.get(s.name(n));assert(def,'Missing macro '+s.name(n));
  let body=def.children.map(c=>source.slice(c.start,c.end)).join('\n');
  for(let i=1;i<n.tokens.length;i++)body=body.replaceAll('%'+n.tokens[i].value,n.children[i-1].tokens.map(t=>t.value).join(' '));
  output.push(...s.parse(body).children);
 }
 return output;
}
const triggers=new Map([...expand(mission),...expand(text('map/multi/ufb_infantry_support.inc')),...expand(text('map/multi/ufb_static_weapons.inc'))].map(n=>[s.name(n),n]));
assert.equal(triggers.size,580,'duplicate/missing expanded triggers');
const eventMap=new Map([...expand(events),...expand(text('set/interaction_entity/ufb_infantry_support_events.inc')),...expand(text('set/interaction_entity/ufb_static_weapon_events.inc'))].filter(n=>s.name(n)==='on').map(n=>[n.tokens[1].value,n]));
const value=(n,key)=>s.child(n,key)?.tokens[1]?.value;
const words=x=>String(x).split(/\s+/);
let checks=0,scenarios=0;
function test(name,fn){fn();scenarios++;console.log('ok - '+name);}
function check(v,msg){assert(v,msg);checks++;}
const weapon=(tags,ammo=3)=>({tags:new Set(words(tags)),amount:1,ammo});
// Native ownership (control user) and CapturedByUser are distinct save fields.
function unit(id,player,x,opts={}){return {id,player,x,team:opts.team??player,props:new Set(['human',...(opts.shooting?['shooting']:[])]),states:new Set(['operatable',...(opts.bot?[]:['user_control'])]),captured:false,ai:{},tags:new Set(opts.hit?['_ufb_recent_hit']:[]),items:[weapon('weapon bullet rifle'),weapon('weapon rocketlauncher'),{tags:new Set(['fg']),amount:2},{tags:new Set(['at']),amount:2},{tags:new Set(['smoke']),amount:2}],held:new Set(['weapon','rifle','bullet']),visible:true,covered:false,...opts};}
class Scene{
 constructor(entities){this.entities=entities;this.now=0;this.timers=[];this.commands=[];this.jobs=[];this.points=[];this.native=[];this.roll=0;}
 playerTeam(id){return this.entities.find(e=>e.player===Number(id))?.team??Number(id);}
 match(e,n){
  const key=s.name(n),v=n.tokens[1]?.value;
  if(key==='tag')return e.tags.has(v??value(n,'tag'));
  if(key==='prop')return e.props.has(v??value(n,'prop'));
  if(key==='state')return words(v??value(n,'state')).every(w=>e.states.has(w));
  if(key==='player')return e.player===Number(v??value(n,'player'));
  if(key==='relation'){const ally=e.team===this.playerTeam(value(n,'player'));return value(n,'relation')==='ally'?ally:!ally;}
  if(key==='with_item'){
   const tags=words(value(n,'item')),type=value(n,'type');
   return type==='using'?tags.every(t=>e.held.has(t)):e.items.some(i=>i.amount>0&&tags.every(t=>i.tags.has(t)));
  }
  throw Error('Unsupported selector clause '+key);
 }
 select(n){
  let a=this.entities.filter(e=>!(value(n,'ignore_captured_by_user')!=='0'&&e.captured));
  const group=s.child(n,'group');
  if(group){const sel=s.child(group,'select'),inc=s.child(group,'include'),ex=s.child(group,'exclude');a=a.filter(e=>(!sel||sel.children.some(c=>this.match(e,c)))&&(!inc||inc.children.every(c=>this.match(e,c)))&&(!ex||!ex.children.some(c=>this.match(e,c))));}
  for(const c of n.children.filter(c=>['tag','prop','state','player'].includes(s.name(c))))a=a.filter(e=>this.match(e,c));
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
 event(name,e){if(name==='emit_crew'||name.startsWith('construction_sandbag')){this.native.push({name,gun:e.id});if(name==='emit_crew')e.states.delete('inhabited');return;}const node=eventMap.get(name);assert(node,'Missing event '+name);this.eventNodes(node.children,e);}
 eventNodes(nodes,e){for(const n of nodes){
  const key=s.name(n);
  if(key==='tags'){if(n.tokens[1].value==='add')e.tags.add(n.tokens[2].value);else e.tags.delete(n.tokens[2].value);}
  else if(key==='delay'){const d=n.tokens[2]?.value,variance=d&&!Number.isNaN(Number(d))?Number(d)*(this.variation||0):0;this.later(Number(n.tokens[1].value)+variance,()=>this.eventNodes(n.children,e));}
  else if(key==='if'){
   const els=n.tokens.map((t,i)=>t.value==='else'?i:-1).filter(i=>i>=0),starts=[1,...els.map(i=>i+1)];
   for(let b=0;b<starts.length;b++){
    const args=n.tokens.slice(starts[b],els[b]).map(t=>t.value),negate=args[0]==='not';if(negate)args.shift();
    const ok=!args.length||args[0]==='tagged'?(!args.length||e.tags.has(args[1])):args[0]==='in_cover'?e.covered:e.states.has(args[0]);
    if(!(negate?!ok:ok))continue;
    const low=b?n.tokens[els[b-1]].start:n.start,high=b<els.length?n.tokens[els[b]].start:n.end;
    this.eventNodes(n.children.filter(c=>c.start>low&&c.start<high).flatMap(c=>s.name(c)?[c]:c.children),e);break;
   }
  }else if(key==='spawn'){
   const at=n.tokens.findIndex(t=>t.value==='local_offset'),offset=at<0?0:Number(n.tokens[at+1].value)/20;
   const point={id:'point'+this.points.length,x:e.x+offset,player:e.player,team:e.team,props:new Set(),states:new Set(),tags:new Set(),items:[],held:new Set(),visible:true};this.entities.push(point);this.points.push(point);this.eventNodes(n.children,point);
  }else if(key==='delete')this.entities=this.entities.filter(x=>x!==e);
  else if(key==='talk')this.commands.push({name:'talk',actor:e.id,line:n.tokens[1].value,at:this.now});
  else if(key==='call'||key==='call_synced')this.event(n.tokens[1].value,e);
  else throw Error('Unsupported entity event '+key);
 }}
 actions(nodes,at=0){for(let i=at;i<nodes.length;i++){
  const n=nodes[i],key=s.name(n);
  if(key==='delay'){this.later(Number(value(n,'time')),()=>this.actions(nodes,i+1));return;}
  if(key==='trigger'){this.jobs.push(value(n,'name'));continue;}
  if(key==='con')continue;
  if(key==='switch'){
   const branch=n.children.find(c=>s.name(c)==='case'&&this.term(s.child(c,'condition'),value(s.child(c,'condition'),'type')))||n.children.find(c=>s.name(c)==='default');
   if(branch)this.actions(branch.children.filter(c=>s.name(c)!=='condition'));continue;
  }
  if(key==='if'){if(this.term(s.child(n,'condition'),value(s.child(n,'condition'),'type')))this.actions(n.children.filter(c=>s.name(c)!=='condition'));continue;}
  const actors=this.select(s.child(n,'selector'));
  for(const e of actors){
   if(key==='entity_state'){const add=value(n,'tag_add'),remove=value(n,'tag_remove');if(add)e.tags.add(add);if(remove)e.tags.delete(remove);}
   else if(key==='effect')this.event(value(n,'effect'),e);
   else if(key==='actor_state'){for(const field of s.child(n,'ai')?.children||[])e.ai[s.name(field)]=field.tokens[1].value==='on';if(s.child(n,'cannon')){e.cannon=value(n,'cannon');e.moveMode=value(n,'move_mode');}}
   else if(key==='actor_to_cover')this.commands.push({name:'cover',actor:e.id,at:this.now});
   else if(key==='inventory'){
    if(value(n,'action')==='take_from'){
     const donor=this.select(s.child(n,'entity'))[0],item=donor?.items.find(i=>i.amount>0&&words(value(n,'item')).every(t=>i.tags.has(t)));
     if(item&&e.items.length<(e.maxItems||100)){donor.items=donor.items.filter(i=>i!==item);e.items.push(item);}
    }else {const w=e.items.find(i=>i.amount>0&&words(value(n,'item')).every(t=>i.tags.has(t)));if(w)e.held=new Set(w.tags);}
   }
   else if(key==='actor_fire'){
    const target=this.select(s.child(n,'enemies'))[0],gun=e.items.find(i=>i.tags.has('mgun')&&i.ammo>0);if(target&&gun&&e.held.has('mgun')){gun.ammo--;this.commands.push({name:'actor_fire',actor:e.id,target:target.id,at:this.now});}
   }
   else if(key==='action'){
    const name=value(n,'action'),target=this.select(s.child(n,'target'))[0];if(!target)continue;
    const itemTag={throw_ap_grenade:'fg',throw_at_grenade:'at',throw_sk_grenade:'smoke',bazooka_shot:'rocketlauncher'}[name];
    const item=itemTag&&e.items.find(i=>i.amount>0&&i.tags.has(itemTag));if(itemTag&&(!item||(name==='bazooka_shot'&&item.ammo<=0)))continue;
    if(itemTag){if(name==='bazooka_shot')item.ammo--;else item.amount--;}
    this.commands.push({name,actor:e.id,target:target.id,at:this.now});
   }else throw Error('Unsupported mission action '+key);
  }
 }}
 run(kind,phase='acquire',player=0){const n=triggers.get(`ufb/combat/${kind}/${phase} ${player}`);assert(n);const yes=this.condition(s.child(n,'condition'));if(yes)this.actions(s.child(n,'actions').children);return yes;}
 named(name){const n=triggers.get(name);assert(n,'Missing trigger '+name);const yes=this.condition(s.child(n,'condition'));if(yes)this.actions(s.child(n,'actions').children);return yes;}
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
 const {a,b,w}=battle({bot:true});check(w.run('critical'));check(b.tags.has('_ufb_combat_cover_0'));check(w.run('critical','apply'));assert.equal(w.commands[0].name,'bazooka_shot');assert.equal(a.items.find(i=>i.tags.has('rocketlauncher')).ammo,2);
 for(const mode of ['no-hit','no-cover','no-mgun']){const z=battle();if(mode==='no-hit')z.a.tags.clear();if(mode==='no-cover')z.b.covered=false;if(mode==='no-mgun')z.b.held=new Set(['rifle']);z.w.run('critical');check(!z.w.run('critical','apply'),mode);}
});
test('critical shot aborts for armor, allied blast risk, or expired cover probe',()=>{for(const mode of ['armor','ally','expired']){const {w}=battle();w.run('critical');if(mode==='armor'){const car=unit('car',1,50);car.props=new Set(['vehicle']);w.entities.push(car);}if(mode==='ally')w.entities.push(unit('ally',2,20,{team:0}));if(mode==='expired')w.advance(1.1);check(!w.run('critical','apply'),mode);}});
test('anti-tank grenade and launcher assist use a vehicle, never allied armor',()=>{for(const kind of ['at','launcher']){const {b,w}=battle();b.x=kind==='at'?15:20;b.props=new Set(['vehicle']);check(w.run(kind));check(w.run(kind,'apply'));check(w.commands.some(c=>c.name===(kind==='at'?'throw_at_grenade':'bazooka_shot')));}});
test('smoke is thrown toward a nearby point, not the distant threat',()=>{const {b,w}=battle();b.x=60;check(w.run('smoke'));check(w.run('smoke','apply'));w.advance(0.9);const cmd=w.commands.find(c=>c.name==='throw_sk_grenade');check(cmd);assert.equal(w.points[0].x,10);assert.equal(cmd.target,w.points[0].id);w.advance(3.1);check(!w.entities.some(e=>e.id===cmd.target),'smoke marker must expire');});
test('white phosphorus picked up after smoke acquisition still blocks automation',()=>{const {a,b,w}=battle();b.x=60;check(w.run('smoke'));a.items.push({tags:new Set(['m15_wp']),amount:1});w.run('smoke','apply');w.advance(1);check(!w.commands.some(c=>c.name==='throw_sk_grenade'),'WP must remain excluded after acquisition');});
test('drawing a launcher after smoke acquisition prevents the throw',()=>{const {a,b,w}=battle();b.x=60;w.run('smoke');a.held=new Set(['weapon','rocketlauncher']);w.run('smoke','apply');w.advance(1);check(!w.commands.some(c=>c.name==='throw_sk_grenade'));});
test('busy expiry never bypasses a longer individual cooldown',()=>{const {a,b,w}=battle();w.run('critical');w.run('critical','apply');w.advance(6.01);a.tags.add('_ufb_combat_critical_actor_0');b.tags.add('_ufb_combat_critical_target_0');w.event('ufb_combat_probe_cover_0',b);check(!w.run('critical','apply'),'30-second critical cooldown must outlive the 6-second job lock');});
test('player-slot tags and diplomacy remain isolated at slot 16',()=>{const a=unit('p16',16,0,{shooting:true}),b=unit('enemy',1,20),w=new Scene([a,b]);check(w.run('ap','acquire',16));check(a.tags.has('_ufb_combat_ap_actor_16'));check(!w.run('ap','apply',0));check(w.run('ap','apply',16));});

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
 local guard=dofile('${file}');local capture=guard.Wrap(function()orders=orders+1 end,false)
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
 const {a,corpse,w}=looting(),gun=corpse.items[0];check(w.named('ufb/support/loot mgun/acquire 0'));check(w.named('ufb/support/loot mgun/apply 0'));check(a.items.includes(gun)&&corpse.items.length===0);check(!w.named('ufb/support/loot mgun/apply 0'));
});
test('player corpse looting refuses wounded men, prepared launchers, medics and a combat threat',()=>{
 for(const mode of ['wounded','launcher','medic','enemy']){
  const {a,corpse,w}=looting();if(mode==='wounded')corpse.tags.add('start_personage');if(mode==='launcher')a.held=new Set(['weapon','rocketlauncher']);if(mode==='medic')a.tags.add('medic');
  const acquired=w.named('ufb/support/loot mgun/acquire 0');if(mode==='enemy')w.entities.push(unit('threat',1,20));
  check(!acquired||!w.named('ufb/support/loot mgun/apply 0'),mode);check(corpse.items.length===1);
 }
});
test('a full inventory cannot destroy the source weapon or produce an extra one',()=>{
 const {a,corpse,w}=looting();a.maxItems=a.items.length;const gun=corpse.items[0];w.named('ufb/support/loot mgun/acquire 0');w.named('ufb/support/loot mgun/apply 0');check(corpse.items[0]===gun);check(!a.items.includes(gun));
});
function suppress(){const {a,b,w}=battle();a.items.push(weapon('weapon bullet mgun loot_mgun',20));a.held=new Set(['weapon','bullet','mgun']);b.x=60;return {a,b,w};}
test('MG pressure uses a frozen last-seen point after the enemy disappears and moves',()=>{
 const {b,w}=suppress();w.variation=1;check(w.named('ufb/suppress/acquire 0'));check(w.named('ufb/suppress/apply 0'));const point=w.points[0];assert.equal(point.x,60);
 b.x=1000;b.visible=false;w.advance(4.1);const shots=w.commands.filter(c=>c.name==='actor_fire');check(shots.length===3);check(shots.every(c=>c.target===point.id));assert.equal(point.x,60);w.advance(1);check(!w.entities.includes(point));
});
test('MG pressure never starts on an unseen or upright unprotected target',()=>{
 for(const mode of ['hidden','upright']){const {b,w}=suppress();if(mode==='hidden')b.visible=false;else b.covered=false;w.named('ufb/suppress/acquire 0');check(!w.named('ufb/suppress/apply 0'),mode);check(w.commands.length===0);}
});
test('random MG pressure expires at both 3 and 5 seconds and remains bounded',()=>{
 for(const variation of [-1,1]){const {w}=suppress();w.variation=variation;w.named('ufb/suppress/acquire 0');w.named('ufb/suppress/apply 0');w.advance(10);assert.equal(w.commands.filter(c=>c.name==='actor_fire').length,variation===-1?2:3);check(w.points.every(point=>!w.entities.includes(point)));}
});
test('a launcher drawn or an ally entering the old target area stops subsequent MG bursts',()=>{
 for(const mode of ['launcher','ally']){const {a,w}=suppress();w.variation=1;w.named('ufb/suppress/acquire 0');w.named('ufb/suppress/apply 0');if(mode==='launcher')a.held=new Set(['weapon','rocketlauncher']);else w.entities.push(unit('ally',2,60,{team:0}));w.advance(6);assert.equal(w.commands.filter(c=>c.name==='actor_fire').length,1,mode);}
});
test('active healing cannot be interrupted by grenades, looting or MG pressure',()=>{
 const {a,w}=battle();a.tags.add('_ufb_healing_active');check(!w.run('ap'));const z=looting();z.a.tags.add('_ufb_healing_active');check(!z.w.named('ufb/support/loot mgun/acquire 0'));const m=suppress();m.a.tags.add('_ufb_healing_active');check(!m.w.named('ufb/suppress/acquire 0'));
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
 for(const stance of ['lying','squatting']){const {b,w}=suppress();b.covered=false;b.states.add(stance);check(w.named('ufb/suppress/acquire 0'));check(w.named('ufb/suppress/apply 0'));}
});
test('grenade and MG routines cannot reserve the same soldier simultaneously',()=>{
 for(const first of ['grenade','mg']){const {b,w}=suppress();b.x=20;
  if(first==='grenade'){check(w.run('ap'));check(!w.named('ufb/suppress/acquire 0'));}
  else {check(w.named('ufb/suppress/acquire 0'));check(!w.run('ap'));}
 }
});
test('corpse loot handlers are isolated for every weapon class and boundary player slot',()=>{
 const kinds=['mgun','assaultrifle','battlerifle','autorifle','semirifle'];
 for(const player of [0,16])for(const kind of kinds){const z=looting();z.a.player=player;z.a.team=player;z.corpse.items=[weapon('weapon bullet '+kind+' loot_'+kind)];const gun=z.corpse.items[0];
  check(z.w.named('ufb/support/loot '+kind+'/acquire '+player));
  for(const wrong of kinds.filter(k=>k!==kind))check(!z.w.named('ufb/support/loot '+wrong+'/apply '+player),'another class consumed this reservation');
  check(z.w.named('ufb/support/loot '+kind+'/apply '+player));check(z.a.items.includes(gun)&&z.corpse.items.length===0);check(z.a.tags.has('_ufb_loot_cooldown'));
 }
});
test('a failed inventory transfer does not consume a loot cooldown',()=>{
 const z=looting();z.a.maxItems=z.a.items.length;check(z.w.named('ufb/support/loot mgun/acquire 0'));check(z.w.named('ufb/support/loot mgun/apply 0'));check(!z.a.tags.has('_ufb_loot_cooldown'));check(!z.a.tags.has('_ufb_combat_busy'));check(z.corpse.items.length===1);
});
test('an upright target immediately releases the MG reservation for a grenade',()=>{
 const z=suppress();z.b.covered=false;z.b.x=20;check(z.w.named('ufb/suppress/acquire 0'));check(!z.w.named('ufb/suppress/apply 0'));check(!z.a.tags.has('_ufb_suppress_actor_0'));check(!z.a.tags.has('_ufb_job_reserved'));check(z.w.run('ap'));
});
test('native HF cannot reacquire a soldier during an active UFB job',()=>{
 const z=suppress();z.a.states.delete('user_control');z.a.tags.add('_bot');z.b.tags.add('_user');z.b.props.add('shooting');
 check(z.w.named('ufb/suppress/acquire 0'));check(z.w.named('ufb/suppress/apply 0'));
 const hf=s.parse(text('map/multi/HF-dcg_script.inc')),under=hf.children.find(n=>s.name(n)==='hf inf ai/under mg fire');
 const selector=s.child(s.child(s.child(s.child(under,'condition'),'terms'),'1.see_actors'),'selector');check(!z.w.select(selector).includes(z.a));
});
test('UFB also respects a specialist job already reserved by native HF',()=>{
 for(const tag of ['_ai_suppressed_by_mg','_ai_mgunner','_ai_reloading','_ai_at_launcher_80','_ai_ap_grenade']){const z=suppress();z.a.tags.add(tag);check(!z.w.named('ufb/suppress/acquire 0'),tag);const a=battle();a.a.tags.add(tag);check(!a.w.run('critical'),tag);}
});
test('ordinary medics remain protected before the healing animation begins',()=>{
 for(const kind of ['ap','critical','smoke','at','launcher']){const z=battle();z.a.tags.add('medic');if(kind==='smoke')z.b.x=60;if(kind==='at'){z.b.x=15;z.b.props=new Set(['vehicle']);}if(kind==='launcher')z.b.props=new Set(['vehicle']);check(!z.w.run(kind),kind);}
});
test('native user capture blocks extra orders even while the soldier is firing',()=>{
 for(const kind of ['ap','critical','smoke','at','launcher']){const z=battle({captured:true});if(kind==='smoke')z.b.x=60;if(kind==='at'){z.b.x=15;z.b.props=new Set(['vehicle']);}if(kind==='launcher')z.b.props=new Set(['vehicle']);check(!z.w.run(kind),kind);}
 const z=looting();z.a.captured=true;check(!z.w.named('ufb/support/loot mgun/acquire 0'));
});
test('troops that are not firing receive no new offensive or smoke command',()=>{
 for(const kind of ['ap','critical','smoke','at','launcher']){const z=battle({shooting:false});if(kind==='smoke')z.b.x=60;if(kind==='at'){z.b.x=15;z.b.props=new Set(['vehicle']);}if(kind==='launcher')z.b.props=new Set(['vehicle']);check(!z.w.run(kind),kind);check(z.w.commands.length===0);}
});
test('movement and late user capture cancel pending grenade orders',()=>{
 for(const mode of ['moving','capture']){const z=battle();check(z.w.run('ap'));if(mode==='moving')z.w.event('ufb_autonomy_move_on',z.a);else z.a.captured=true;check(!z.w.run('ap','apply'));check(z.w.commands.length===0);}
 const z=battle();z.w.event('ufb_autonomy_move_on',z.a);check(!z.w.run('ap'));z.w.event('ufb_autonomy_move_off',z.a);check(z.w.run('ap'));
});
test('movement or manual capture stops later MG bursts',()=>{
 for(const mode of ['moving','capture']){const z=suppress();z.w.variation=1;check(z.w.named('ufb/suppress/acquire 0'));check(z.w.named('ufb/suppress/apply 0'));if(mode==='moving')z.w.event('ufb_autonomy_move_on',z.a);else z.a.captured=true;z.w.advance(6);assert.equal(z.w.commands.filter(c=>c.name==='actor_fire').length,1);}
});
test('a player MG that stops firing receives no further scripted bursts',()=>{
 const z=suppress();z.w.variation=1;check(z.w.named('ufb/suppress/acquire 0'));check(z.w.named('ufb/suppress/apply 0'));z.a.props.delete('shooting');z.w.advance(6);assert.equal(z.w.commands.filter(c=>c.name==='actor_fire').length,1);
});
test('automatic AT target selectors ignore infantry while retaining armor sorting',()=>{
 const actual=s.parse(text('set/target/human_ap.inc')),base=s.parse(fs.readFileSync(p.join(combat.reference,'set/target/human_ap.inc'),'latin1'));let count=0;
 for(const selector of actual.children){const unit=s.child(selector,'unit'),group=s.child(selector,'group');if(!/^range_\d+$/.test(unit?.tokens[2]?.value||'')&&unit?.tokens[2]?.value!=='ap')continue;
  const ignores=group.children.filter(n=>s.name(n)==='ignore'&&value(n,'class')==='human');check(ignores.length===1);group.children=group.children.filter(n=>!ignores.includes(n));count++;
 }
 check(count>=7);assert.deepEqual(shape(actual),shape(base));
});
const launcher=(klass,opts={})=>{const a=unit('at',0,0,{hit:false,...opts});a.held=new Set(['weapon','rocketlauncher',klass]);const b=unit('foe',1,200,{team:1});return {a,b,w:new Scene([a,b])};};
const tick=(z,seconds=40)=>{for(let i=0;i<seconds/2;i++){z.w.named('ufb/launcher/keep near 0');z.w.named('ufb/launcher/keep far 0');z.w.named('ufb/launcher/tick 0');z.w.advance(2);}};
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
 const stays=mode=>{const z=launcher('range_30');if(mode==='capture')z.a.captured=true;if(mode==='reload')z.a.tags.add('reloading');if(mode==='shot')z.a.props.add('shooting');if(mode==='only')z.a.items=z.a.items.filter(i=>!i.tags.has('bullet'));tick(z);return z.a.held.has('rocketlauncher');};
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
function gunScene(props,enemy,opts={}){const g=gun('gun',0,0,props,opts),a=unit('crew1',0,2,{bot:opts.bot}),w=new Scene([g,a,enemy]);return {g,a,enemy,w};}
test('rifle-caliber MG and mortar crews abandon the gun to tanks and armored cars',()=>{
 for(const props of [['mg_stan'],['mortar']])for(const threat of [['tank','medium'],['tank','light'],['armored_car']]){
  const z=gunScene(props,armorUnit(60,threat));check(z.w.named('ufb/gun/abandon light 0'));check(z.w.native.some(n=>n.name==='emit_crew'));check(!z.g.states.has('inhabited'));
 }
});
test('12.7 mm guns stand against light armor and leave only before medium or heavy tanks',()=>{
 const stand=threat=>{const z=gunScene(['mg_stan','muzzle_hmg_m2hb'],armorUnit(60,threat));return !z.w.named('ufb/gun/abandon heavy 0')&&!z.w.named('ufb/gun/abandon light 0');};
 check(stand(['tank','light']));check(stand(['armored_car']));check(!stand(['tank','medium']));check(!stand(['tank','heavy']));
});
test('crews stay for infantry, trucks, distant or unseen armor, friendly armor and bunkers',()=>{
 const none=(props,e)=>{const z=gunScene(props,e);return !z.w.named('ufb/gun/abandon light 0')&&!z.w.native.length;};
 check(none(['mg_stan'],unit('rifleman',1,30,{team:1})));
 const truck=armorUnit(40,['car']);truck.props.delete('with_gun');check(none(['mg_stan'],truck));
 check(none(['mg_stan'],armorUnit(120,['tank'])));check(none(['mg_stan'],{...armorUnit(40,['tank']),visible:false}));
 check(none(['mg_stan'],{...armorUnit(40,['tank']),team:0}));check(none(['mg_stan','bunker'],armorUnit(40,['tank'])));check(none(['mg_stan','muzzle_20mm_25mm_auto'],armorUnit(40,['tank'])));
});
test('a gun under direct control stays manned; a crew put back gets a 60 s pause',()=>{
 const held=gunScene(['mg_stan'],armorUnit(60,['tank']));held.g.captured=true;check(!held.w.named('ufb/gun/abandon light 0'));
 const z=gunScene(['mg_stan'],armorUnit(60,['tank']));check(z.w.named('ufb/gun/abandon light 0'));z.w.advance(8);z.g.states.add('inhabited');z.w.jobs.length=0;check(!z.w.named('ufb/gun/abandon light 0'));check(z.w.named('ufb/gun/rearm 0'));z.w.advance(61);check(z.w.named('ufb/gun/abandon light 0'));
});
test('the crew shouts, runs about 35 m away from a marker and then takes cover',()=>{
 const z=gunScene(['mortar'],armorUnit(60,['tank']));z.w.named('ufb/gun/abandon light 0');check(z.w.named('ufb/gun/crew 0'));z.w.advance(0.3);
 check(z.w.commands.some(c=>c.name==='talk'&&c.actor==='crew1'&&c.line==='retreat'));const run=z.w.commands.find(c=>c.name==='move');check(run&&run.actor==='crew1');assert.equal(z.w.points[0].x,z.a.x-35);check(z.a.tags.has('_lua_mi'));
 check(!z.w.named('ufb/gun/crew 0'),'crew is ordered only once');z.w.advance(12);check(!z.a.tags.has('_lua_mi'));check(z.w.named('ufb/gun/cover 0'));check(z.w.commands.some(c=>c.name==='cover'));
});
test('a bot gun deploys at first distant contact and holds off Lua orders',()=>{
 const z=gunScene(['mg_stan','cannon_sandbag_standard'],unit('foe',1,100,{team:1}),{bot:true});z.w.roll=0.9;check(z.w.named('ufb/gun/deploy mg 0'));assert.equal(z.g.cannon,'fire');assert.equal(z.g.moveMode,'hold');check(z.g.tags.has('_lua_mi'));
 const near=gunScene(['mg_stan'],unit('foe',1,20,{team:1}),{bot:true});check(!near.w.named('ufb/gun/deploy mg 0'));
 const mine=gunScene(['mg_stan'],unit('foe',1,100,{team:1}));check(!mine.w.named('ufb/gun/deploy mg 0'),'player guns are placed by the player');
 const mortar=gunScene(['mortar'],unit('foe',1,200,{team:1}),{bot:true});check(mortar.w.named('ufb/gun/deploy mortar 0'));check(!mortar.w.named('ufb/gun/deploy mg 0'));
});
test('sandbags: 60 percent roll once per gun, native size, never where the game forbids them',()=>{
 const bags=(props,roll,x=100)=>{const z=gunScene(props,unit('foe',1,x,{team:1}),{bot:true});z.w.roll=roll;z.w.named('ufb/gun/deploy mg 0');z.w.advance(5);return z;};
 assert.equal(bags(['mg_stan','cannon_sandbag_standard'],0.59).w.native[0]?.name,'construction_sandbag_cannon_standard_ai');
 assert.equal(bags(['mg_stan','cannon_sandbag_small'],0.59).w.native[0]?.name,'construction_sandbag_cannon_shallow_ai');
 check(!bags(['mg_stan','cannon_sandbag_standard'],0.61).w.native.length);check(!bags(['mg_stan','no_sandbags','cannon_sandbag_standard'],0).w.native.length);check(!bags(['mg_stan'],0).w.native.length);
 const lost=bags(['mg_stan','cannon_sandbag_standard'],0.61);lost.w.advance(3);check(lost.g.tags.has('_ufb_gun_fort_checked'),'failed roll must not repeat');
 const close=gunScene(['mg_stan','cannon_sandbag_standard'],unit('foe',1,100,{team:1}),{bot:true});close.w.roll=0;close.w.named('ufb/gun/deploy mg 0');close.enemy.x=30;close.w.advance(5);check(!close.w.native.length,'no digging in with the enemy next to the gun');
});
test('a deployed bot gun packs up only after enemies stay out of sight',()=>{
 const z=gunScene(['mg_stan'],unit('foe',1,100,{team:1}),{bot:true});z.w.named('ufb/gun/deploy mg 0');z.w.advance(6);check(!z.w.named('ufb/gun/release 0'));z.enemy.visible=false;check(z.w.named('ufb/gun/release 0'));z.w.advance(31);assert.equal(z.g.cannon,'move');check(!z.g.tags.has('_lua_mi'));check(!z.g.tags.has('_ufb_gun_deployed'));
 const y=gunScene(['mg_stan'],unit('foe',1,100,{team:1}),{bot:true});y.w.named('ufb/gun/deploy mg 0');y.w.advance(6);y.enemy.visible=false;y.w.named('ufb/gun/release 0');y.enemy.visible=true;y.w.advance(31);assert.equal(y.g.cannon,'fire','enemy back in sight during the pause');
});
test('bot infantry without AT weapons shouts and runs for cover from close armor; players keep control',()=>{
 const scene=(opts={},strip=true)=>{const a=unit('inf',0,0,{bot:true,...opts});if(strip)a.items=a.items.filter(i=>!i.tags.has('rocketlauncher')&&!i.tags.has('at'));return {a,w:new Scene([a,armorUnit(25,['tank'])])};};
 const z=scene();check(z.w.named('ufb/fear/tank 0'));check(z.w.commands.some(c=>c.name==='cover'));check(z.w.commands.some(c=>c.line==='alert_tank'));check(!z.w.named('ufb/fear/tank 0'),'25 s pause');z.w.advance(26);check(z.w.named('ufb/fear/tank 0'));
 for(const item of ['rocketlauncher','at']){const y=scene({},false);y.a.items=y.a.items.filter(i=>!(i.tags.has('rocketlauncher')||i.tags.has('at'))||i.tags.has(item));check(!y.w.named('ufb/fear/tank 0'),'AT soldier stands: '+item);}check(!scene({bot:false}).w.named('ufb/fear/tank 0'),'player soldier keeps orders');
});
test('voice rates change only the three chosen lines',()=>{
 const native=fs.readFileSync(p.join(combat.reference,'set/talk/voicelines_human.inc'),'latin1'),now=text('set/talk/voicelines_human.inc'),rate=(t,n)=>value(s.parse(t).children.find(c=>c.tokens[1]?.value===n),'freq');
 for(const [line,freq]of Object.entries(require('./static-weapons.cjs').voiceRates)){assert.equal(Number(rate(now,line)),freq);checks++;}
 assert.equal(now.replace(/\{freq [0-9.]+\}/g,''),native.replace(/\{freq [0-9.]+\}/g,''));checks++;
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
 const stand=gunScene(['mg_stan','c_mg_heavy'],armorUnit(60,['tank','light']));check(!stand.w.named('ufb/gun/abandon light 0'));check(!stand.w.named('ufb/gun/abandon heavy 0'));
 const go=gunScene(['mg_stan','c_mg_heavy'],armorUnit(60,['tank','heavy']));check(go.w.named('ufb/gun/abandon heavy 0'));
});
test('only one soldier shouts when a squad scatters from armor',()=>{
 const strip=a=>{a.items=a.items.filter(i=>!i.tags.has('rocketlauncher')&&!i.tags.has('at'));return a;};
 const a=strip(unit('a',0,0,{bot:true})),c=strip(unit('c',0,1,{bot:true})),w=new Scene([a,c,armorUnit(25,['tank'])]);check(w.named('ufb/fear/tank 0'));check(w.commands.filter(x=>x.name==='cover').length===2);check(w.commands.filter(x=>x.line==='alert_tank').length===1);
});
test('generated selectors use only forms proven by HF',()=>{
 for(const [name,n]of triggers){
  for(const g of s.all(n,x=>s.name(x)==='select'))check(!s.child(g,'with_item')||/ufb\/combat\/smoke/.test(name),'with_item in select: '+name);
  for(const term of s.all(s.child(n,'condition'),x=>/\.see_actors$/.test(s.name(x)||'')))if(/^ufb\/(gun|launcher|fear)/.test(name))check(s.child(s.child(term,'enemy'),'source'),'simple enemy selector: '+name);
 }
});
test('no condition limits candidates before the distance test',()=>{
 for(const [name,n]of triggers)for(const term of s.all(s.child(n,'condition'),x=>/\.see_actors$/.test(s.name(x)||'')))for(const side of ['selector','enemy'])check(!s.child(s.child(term,side),'amount'),name);
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
 check(!z.w.condition(s.child(trigger,'condition')));z.b.props.add('shooting');check(z.w.condition(s.child(trigger,'condition')));z.b.visible=false;check(!z.w.condition(s.child(trigger,'condition')));
});
test('HF launcher draw and attack both recheck visibility and native range',()=>{
 const trigger=hfMacro('hf_rocketlauncher'),term=s.child(s.child(s.child(trigger,'condition'),'terms'),'1.see_actors'),z=battle({bot:true});z.a.tags.add('_bot');z.b.tags.add('_user');z.b.props=new Set(['vehicle','tank']);z.a.items.push(weapon('weapon rocketlauncher range_30'));
 z.b.x=50;check(!z.w.condition(s.child(trigger,'condition')));z.b.x=25;check(z.w.condition(s.child(trigger,'condition')));
 const gates=s.all(s.child(trigger,'actions'),n=>s.name(n)==='if'&&value(s.child(n,'condition'),'type')==='see_actors');check(gates.length===2);
 for(const gate of gates){const condition=s.child(gate,'condition');check(z.w.term(condition,'see_actors'));z.b.x=35;check(!z.w.term(condition,'see_actors'));z.b.x=25;z.b.visible=false;check(!z.w.term(condition,'see_actors'));z.b.visible=true;z.a.captured=true;check(!z.w.term(condition,'see_actors'));z.a.captured=false;}
});
console.log(JSON.stringify({scenarios,checks,passed:true,gemBattleTested:false}));
