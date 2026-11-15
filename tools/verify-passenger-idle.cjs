// Execute the emitted entity events, including the passenger timer and cancellation.
const fs=require('fs'),p=require('path'),assert=require('assert/strict'),s=require('./lib/sdl.cjs');
const a=require('./atmosphere-addons.cjs'),idle=require('./atmosphere-passenger-idle.cjs');
const tree=s.parse(fs.readFileSync(p.join(a.output,'resource/set/interaction_entity/ufb_passenger_idle.inc'),'latin1')).children[0];
const key=n=>n.tokens.slice(1).map(t=>t.value).filter(t=>t!=='sync').join(' ');
const events=new Map(tree.children.map(n=>[key(n),n]));let scenarios=0;
class Passenger{
 constructor(seat){this.seat=seat;this.linked=true;this.alive=true;this.tags=new Set();this.now=0;this.timers=[];this.plays=[];this.active=false;this.roll=0;}
 event(name){const n=events.get(name);assert(n,name);this.run(n.children);}
 run(nodes){for(const n of nodes){const type=s.name(n),args=n.tokens.slice(1).map(t=>t.value);
  if(type==='if'){
   const neg=args[0]==='not';if(neg)args.shift();
   const ok=args[0]==='operatable'?this.alive:args[0]==='linked'?this.linked:args[0]==='tagged'?this.tags.has(args[1]):args[0]==='name'?this.seat===args[1]:args[0]==='rand'?this.roll<Number(args[1]):undefined;
   assert.notEqual(ok,undefined,'Unsupported event condition '+args.join(' '));if(neg?!ok:ok)this.run(n.children);
  }else if(type==='tags'){if(args[0]==='add')this.tags.add(args[1]);else this.tags.delete(args[1]);}
  else if(type==='call')this.event(args[0]);
  else if(type==='kill_delay')this.timers=this.timers.filter(t=>t.tag!==args[0]);
  else if(type==='delay')this.timers.push({at:this.now+Number(args[0]),tag:args[1],nodes:n.children});
  else if(type==='ani_play'){assert.equal(args[0],idle.sequence);this.plays.push(this.now);this.active=true;}
  else if(type==='ani_stop'){assert.equal(args[0],idle.sequence);this.active=false;}
  else throw Error('Passenger event changes more than animation: '+type);
 }}
 advance(seconds){const end=this.now+seconds;for(;;){this.timers.sort((a,b)=>a.at-b.at);if(!this.timers.length||this.timers[0].at>end)break;const next=this.timers.shift();this.now=next.at;this.run(next.nodes);}this.now=end;}
}
function test(name,fn){fn();scenarios++;console.log('ok - '+name);}
test('only seat1..seat15 passengers play the single head clip',()=>{
 for(let i=1;i<=15;i++){const x=new Passenger('seat'+i);x.event('board in');assert.equal(x.plays.length,1);assert.equal(x.timers.length,1);}
 for(const seat of ['driver','commander','gunner','loader','mg1','seat16','']){const x=new Passenger(seat);x.event('board in');x.advance(25);assert.equal(x.plays.length,0,seat);assert.equal(x.timers.length,0,seat);}
});
test('repeated boarding replaces the timer and cannot multiply polling',()=>{
 const x=new Passenger('seat1');x.event('board in');x.event('board in');assert.equal(x.timers.length,1);x.advance(16);assert.deepEqual(x.plays,[0,0,8,16]);assert.equal(x.timers.length,1);
});
test('leaving the vehicle cancels both the animation and future polling',()=>{
 const x=new Passenger('seat1');x.event('board in');x.linked=false;x.event('board out');assert.equal(x.active,false);assert.equal(x.timers.length,0);x.advance(30);assert.deepEqual(x.plays,[0]);
});
test('firing, reload, hits and head IK immediately stop the clip',()=>{
 for(const event of ['fire','reload','process_bullet_hit','blast_hit','ik begin ik_leftright']){const x=new Passenger('seat1');x.event('board in');x.event(event);assert.equal(x.active,false,event);assert.equal(x.timers.length,1,event);}
});
test('combat and medical job tags suppress playback without changing the job',()=>{
 for(const tag of idle.protectedTags){const x=new Passenger('seat1');x.tags.add(tag);x.event('board in');x.advance(16);assert.equal(x.plays.length,0,tag);assert(x.tags.has(tag));x.tags.delete(tag);x.advance(8);assert.deepEqual(x.plays,[24]);}
});
test('death or wounded stop cancels the passenger loop permanently',()=>{
 for(const event of ['die','stop_personage']){const x=new Passenger('seat1');x.event('board in');x.event(event);x.alive=false;x.advance(25);assert.deepEqual(x.plays,[0]);assert.equal(x.timers.length,0);assert.equal(x.active,false);}
});
test('a rejected chance still keeps one bounded eight-second timer',()=>{
 const x=new Passenger('seat1');x.roll=1;x.event('board in');x.advance(32);assert.equal(x.plays.length,0);assert.equal(x.timers.length,1);assert.equal(x.timers[0].at,40);
});
console.log(JSON.stringify({scenarios,passed:true,passengerOnly:true,engineAnimationBlendingTested:false}));
