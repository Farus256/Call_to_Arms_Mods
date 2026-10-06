// Regression checks against current resources, not an engine or combat simulator.
const fs=require('fs'),path=require('path'),assert=require('assert/strict');
const s=require('./lib/sdl.cjs');
const root=path.resolve(__dirname,'../mods/ultimate_frontline_bundle/resource');
const read=f=>fs.readFileSync(path.join(root,f),'utf8');
let checks=0;const check=(ok,message)=>{assert(ok,message);checks++;};
const human=s.parse(read('set/interaction_entity/human.inc'));
const wound=s.all(human,n=>s.name(n)==='on'&&n.tokens[1]?.value==='personage_check')[0];
check(s.all(wound,n=>s.name(n)==='mod').length===0,'no automatic MP ban on wounded AI or player soldiers');
check(s.all(wound,n=>s.name(n)==='if'&&n.tokens[1]?.value==='rand'&&n.tokens[2]?.value==='0.30').length===1,'one wound roll, 30% eligible MP fatalities');
const source=read('set/interaction_entity/human.inc').slice(wound.start,wound.end);
for(const term of ['swimming','burned','"crush"','"no_revive"','"hero_unit"'])check(source.includes(term),'native exception retained: '+term);
check(s.all(wound,n=>s.name(n)==='call_synced'&&n.tokens[1]?.value==='mp_personage_0').length===1,'random wound decision remains synchronised');
const hf=s.parse(read('map/multi/hf-dcg_script.inc'));
const medic=s.all(hf,n=>s.name(n)==='hf medic ai/heal')[0];
check(!!medic,'Horten medic handler exists');
check(s.all(medic,n=>s.name(n)==='action'&&n.tokens[1]?.value==='medic').length===1,'medic order replaces mere movement');
const range=s.all(medic,n=>s.name(n)==='distance')[0];
check(s.child(range,'min').tokens[1].value==='0'&&s.child(range,'max').tokens[1].value==='45','bounded local rescue, no 15-20m gap');
for(const tag of ['_ai_medic','bot_medic'])check(read('script/multiplayer/ufb_order_guard.lua').includes('"'+tag+'"'),'general bot orders protect '+tag);
const debris=s.parse(read('set/interaction_entity/ufb_persistent_debris.inc'));
check(read('set/interaction_entity/dummy.inc').includes('(include "ufb_persistent_debris.inc")'),'debris handlers are loaded');
for(const kind of ['small','medium']){
 const rule=debris.children.find(n=>s.name(n)===kind+' part ufb_persistent_debris');
 check(!!rule,'specific debris rule: '+kind);
 const spawn=s.child(rule,'on');
 check(spawn.tokens.includes(spawn.tokens.find(t=>t.value==='overload')),'spawn overrides original cleanup');
 check(!s.all(spawn,n=>['delete','hide'].includes(s.name(n))).length,'no deletion timer: '+kind);
 check(s.all(spawn,n=>s.name(n)==='volumes').length>0,'native spawn collision grace retained');
}
for(const name of ['piece_small_steel','piece_tiny_steel','piece_small_steel_construction','piece_medium_steel','piece_medium_steel_construction','piece_medium_sand','piece_big_steel','piece_large_steel'])
 check(read('entity/service/slicer/'+name+'.def').includes('"ufb_persistent_debris"'),'sliced fragment gets persistence: '+name);
for(const kind of ['shallow','standard'])check(read(`entity/construction/_military/fortifications/sandbag_old/sandbag_cannon_${kind}/sandbag_cannon_${kind}_ai.def`).includes('{DynCmpPersistent}'),'AI sandbag persists: '+kind);
check(read('properties/small_part_harmless.inc').includes('"delete_after_spawn"'),'casings and other tiny debris retain cleanup');
for(const file of ['bloodstain','bloodstain_rot120','bloodstain_rot240','ground_blood_big','ground_blood_small','ground_blood01','ground_blood02','ground_blood03']){
 const tree=s.parse(read('entity/fx/hit/'+file+'.def'));
 const views=s.all(tree,n=>n.tokens.some(t=>t.value==='decalview'));
 check(views.length>0,'projected terrain blood: '+file);
 check(!s.all(tree,n=>n.tokens.some(t=>t.value==='spriteview')).length,'no flat pool quad: '+file);
 for(const view of views){
  check(!!s.child(view,'dynamic')&&!!s.child(view,'ground'),'projection flags: '+file);
  const sprite=s.child(view,'sprite');check(['$/particle/bloodstain','$/particle/blood_splash'].includes(sprite.tokens[1]?.value),'stock GoH texture: '+file);
  const scale=s.child(sprite,'scale'),growth=s.child(scale,'npower');
  const maximum=growth?Number(s.child(growth,'max').tokens[1].value):Number(scale.tokens[1].value)+Number(scale.tokens[2]?.value||0);
  check(maximum<=0.23,'bounded blood size: '+file);
 }
}
console.log(`Crew/effects: ${checks} static regression checks passed. Repairer role selection remains unimplemented; engine/battle validation required.`);
