// Resource lifecycle model; does not simulate animations or engine inventory.
const fs=require('fs'),path=require('path'),assert=require('assert/strict');
const s=require('./lib/sdl.cjs');
const root=path.resolve(__dirname,'../mods/ultimate_frontline_bundle/resource');
const read=f=>fs.readFileSync(path.join(root,'set/interaction_entity',f),'utf8');
const events=s.parse(read('ufb_wounds.inc')).children;
const human=s.parse(read('human.inc'));
let checks=0;const check=(value,message)=>{assert(value,message);checks++;};
const event=(list,name)=>s.all({children:list},n=>s.name(n)==='on'&&n.tokens[1]?.value===name)[0];
check(read('human.inc').includes('(include "ufb_wounds.inc")'),'helper included globally');
for(const [from,to] of [['start_personage','ufb_wound_start'],['stop_personage','ufb_wound_stop']]){
 const n=event(human.children,from);
 check(s.all(n,c=>s.name(c)==='call_synced'&&c.tokens[1]?.value===to).length===1,'synchronised hook: '+from);
 check(!s.all(n,c=>s.name(c)==='ani_play').length,'no unguarded animation in '+from);
}
const cancel=event(human.children,'lie_wounded_animation_stop');
check(s.all(cancel,n=>s.name(n)==='kill_delay'&&n.tokens[1]?.value==='ufb_wound_animation').length===1,'mission stop cancels pending animation');
check(s.all(cancel,n=>s.name(n)==='kill_delay'&&n.tokens[1]?.value==='ufb_wound_death_pose').length===1,'mission stop also cancels delayed death pose');
check(!s.all({children:events},n=>['clear_inventory','spawn','delete'].includes(s.name(n))).length,'no inventory deletion or replacement items');
const drop=s.all({children:events},n=>s.name(n)==='holder_drop');
check(drop.length===1&&drop[0].tokens[1].value==='hand_right','drop only the existing right-hand item');
const start=event(events,'ufb_wound_start');
const rolls=s.all(start,n=>s.name(n)==='if'&&n.tokens[1]?.value==='rand');
check(Number(rolls[0].tokens[2].value)===0.5,'half the eligible wounded are animated');
check(Math.abs(Number(rolls[1].tokens[2].value)-1/3)<1e-10,'uniform first animation');
check(rolls[1].tokens.slice(-4).map(t=>t.value).join(' ')==='else rand 0.5 else','uniform second and third animation');

class Actor{
 constructor(rolls=[0.1,0.1]){
  this.rolls=[...rolls];this.tags=new Set(['start_personage']);this.personage=true;this.water=false;this.dead=false;
  this.time=0;this.timers=new Map();this.animations=new Set();this.animationCalls=[];this.burned=false;this.blast=false;this.hand={id:17,kind:'rifle'};this.dropped=[];this.rollCount=0;
 }
 event(name){this.run(event(events,name).children);}
 condition(tokens){let t=[...tokens],invert=t[0]==='not';if(invert)t.shift();let value;
  if(t[0]==='tagged')value=this.tags.has(t[1]);
  else if(t[0]==='rand'){check(this.rolls.length>0,'unexpected extra random draw');this.rollCount++;value=this.rolls.shift()<Number(t[1]);}
  else if(t[0]==='terrain_fx')value=this.water;
  else if(t[0]==='personage')value=this.personage;
  else if(t[0]==='dead')value=this.dead;
  else if(t[0]==='burned')value=this.burned;
  else if(t[0]==='kill_flags')value=this.blast;
  else throw Error('Unsupported condition '+t);
  return invert?!value:value;
 }
 run(nodes){for(const n of nodes){const t=n.tokens.map(t=>t.value),op=t[0];
  if(op==='if'){
   const boundaries=n.tokens.map((x,i)=>x.value==='else'?i:-1).filter(i=>i>=0);
   const headers=[1,...boundaries.map(i=>i+1)];
   for(let j=0;j<headers.length;j++){
    const header=t.slice(headers[j],boundaries[j]);
    if(header.length&&!this.condition(header))continue;
    const low=j?n.tokens[boundaries[j-1]].start:n.start;
    const high=j<boundaries.length?n.tokens[boundaries[j]].start:n.end;
    this.run(n.children.filter(c=>c.start>low&&c.start<high));break;
   }
  }else if(op==='tags'){if(t[1]==='add')this.tags.add(t[2]);else this.tags.delete(t[2]);}
  else if(op==='holder_drop'){if(this.hand){this.dropped.push(this.hand);this.hand=null;}}
  else if(op==='delay'){const id=t[2]||Symbol();check(!this.timers.has(id),'duplicate timer');this.timers.set(id,{at:this.time+Number(t[1]),nodes:n.children});}
  else if(op==='kill_delay')this.timers.delete(t[1]);
  else if(op==='ani_play'){this.animations.add(t[1]);this.animationCalls.push(t[1]);}
  else if(op==='ani_stop')this.animations.delete(t[1]);
  else throw Error('Unsupported action '+op);
 }}
 advance(dt){const end=this.time+dt;while(true){const pending=[...this.timers].filter(([,v])=>v.at<=end).sort((a,b)=>a[1].at-b[1].at);if(!pending.length)break;const [id,v]=pending[0];this.time=v.at;this.timers.delete(id);this.run(v.nodes);}this.time=end;}
}
let a=new Actor([0.9]);a.event('ufb_wound_start');a.event('ufb_wound_start');a.advance(10);
check(a.rollCount===1&&a.dropped.length===0&&a.animations.size===0&&a.hand.id===17,'still wounded keeps weapon; duplicate start cannot reroll');
for(const [rolls,animation] of [[[0.1,0.1],'lie_wounded'],[[0.1,0.8,0.1],'lie_wounded_1'],[[0.1,0.8,0.9],'lie_wounded_2']]){
 a=new Actor(rolls);const weapon=a.hand;a.event('ufb_wound_start');a.event('ufb_wound_start');a.advance(2.9);
 check(a.dropped.length===1&&a.dropped[0]===weapon&&!a.hand,'one original weapon released');
 check(a.tags.has('ufb_dropped_weapon'),'dropped weapon tagged on wounded soldier');
 check(!a.animations.size,'animation waits for knockdown');a.advance(0.1);
 check(a.animations.size===1&&a.animations.has(animation),'selected wound animation: '+animation);
 a.personage=false;a.tags.delete('start_personage');a.event('ufb_wound_stop');a.advance(1);
 check(!a.animations.size&&!a.tags.has('wounded_animation_playing')&&!a.tags.has('_ufb_wound_chosen'),'revival clears loop and episode tags');
 check(a.tags.has('ufb_revived_unarmed')&&!a.tags.has('ufb_dropped_weapon'),'revived unarmed soldier tagged for weapon pickup');
 check(!a.tags.has('wounded_dead'),'revived actor never gets death pose/tag');
}
a=new Actor();a.event('ufb_wound_start');a.advance(1);a.personage=false;a.tags.delete('start_personage');a.event('ufb_wound_stop');a.advance(10);
check(!a.animations.size&&!a.timers.size,'early revival cancels delayed animation');
a=new Actor();a.event('ufb_wound_start');a.tags.add('wounded_dead');a.dead=true;a.personage=false;a.advance(3);
check(!a.animations.size,'finishing off prevents a delayed live-wound loop');a.event('ufb_wound_stop');a.advance(1);
check(!a.animationCalls.includes('lie_die'),'an already finished-off actor does not restart its death pose');
a=new Actor();a.water=true;a.event('ufb_wound_start');a.advance(3);
check(a.rollCount===0&&!a.dropped.length&&!a.animations.size,'water does not get land-wound animation');
a=new Actor();a.hand=null;a.event('ufb_wound_start');a.advance(3);
check(!a.dropped.length&&a.animations.has('lie_wounded'),'empty hand remains safe, no duplicated item');
a=new Actor([0.9,0.1,0.1]);a.event('ufb_wound_start');a.event('ufb_wound_stop');a.advance(1);a.tags.add('start_personage');a.event('ufb_wound_start');a.advance(3);
check(a.rollCount===3&&a.dropped.length===1,'new wound episode gets a new independent choice');

// Regression: still/early-finished wounds keep the engine-selected death pose.
a=new Actor([0.9]);a.event('ufb_wound_start');a.dead=true;a.personage=false;a.event('ufb_wound_stop');a.advance(1);
check(!a.animationCalls.includes('lie_die'),'still wounded is not switched to an animated death pose');
a=new Actor();a.event('ufb_wound_start');a.dead=true;a.personage=false;a.advance(3);
check(!a.animations.size,'death without wounded_dead tag still blocks the delayed living loop');
// An actual running wound loop gets one ordinary bleedout transition.
a=new Actor();a.event('ufb_wound_start');a.advance(3);a.dead=true;a.personage=false;a.event('ufb_wound_stop');a.advance(1);
check(a.animationCalls.filter(n=>n==='lie_die').length===1,'animated bleedout transitions exactly once');
a.event('ufb_wound_stop');a.advance(1);
check(a.animationCalls.filter(n=>n==='lie_die').length===1,'duplicate stop cannot restart death');
for(const mode of ['burned','burn_animation','blast','water']){
 a=new Actor();a.event('ufb_wound_start');a.advance(3);a.dead=true;a.personage=false;
 if(mode==='burn_animation')a.tags.add(mode);else a[mode]=true;
 a.event('ufb_wound_stop');a.advance(1);
 check(!a.animations.has('lie_die')&&!a.tags.has('wounded_animation_playing'),'special death is preserved: '+mode);
}
// A revived man wounded again before the old one-second timer must be untouched.
a=new Actor([0.1,0.1,0.9]);a.event('ufb_wound_start');a.advance(3);a.personage=false;a.event('ufb_wound_stop');a.advance(0.2);
a.personage=true;a.tags.add('start_personage');a.event('ufb_wound_start');a.dead=true;a.personage=false;a.advance(1);
check(!a.animations.has('lie_die'),'new wound episode cancels old death-pose callback');
a=new Actor();a.event('ufb_wound_start');a.advance(3);a.dead=true;a.personage=false;a.event('ufb_wound_stop');a.event('ufb_wound_stop');a.advance(1);
check(a.animationCalls.filter(n=>n==='lie_die').length===1,'duplicate stop before the timer keeps the one pending transition');
a=new Actor();a.event('ufb_wound_start');a.run(cancel.children);a.advance(4);
check(!a.animations.size&&!a.timers.size,'mission stop cancels a not-yet-started wound loop');
a=new Actor();a.event('ufb_wound_start');a.advance(3);a.dead=true;a.personage=false;a.event('ufb_wound_stop');a.run(cancel.children);a.advance(1);
check(!a.animations.size&&!a.timers.size,'mission stop cancels the pending death transition');
for(const mode of ['burned','burn_animation']){
 a=new Actor();a.event('ufb_wound_start');if(mode==='burn_animation')a.tags.add(mode);else a[mode]=true;a.advance(3);
 check(!a.animations.size,'burning cannot start a late wound loop: '+mode);
}
console.log(`Wounds: ${checks} checks passed. Native holder placement and rendered animations require battle verification.`);
