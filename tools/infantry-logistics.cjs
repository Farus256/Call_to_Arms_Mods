// Exact native filling groups; only a tag is added to each handheld firearm.
const fs=require('fs'),p=require('path'),assert=require('assert/strict'),s=require('./lib/sdl.cjs');
const {protectedHumanTags,sides}=require('./infantry-job-policy.cjs');
const T=x=>`{tag {tag ${x}}}`,P=x=>`{prop {prop ${x}}}`,S=x=>`{state {state ${x}}}`;
const I=(item,type='existance')=>`{with_item {type ${type}} {item "${item}"}${type==='amount'?' {min 24}':''}}`;
const walk=d=>fs.readdirSync(d,{withFileTypes:true}).flatMap(e=>e.isDirectory()?walk(p.join(d,e.name)):[p.join(d,e.name)]);
const cached=new Map();
function catalog(ref){
 if(cached.has(ref))return cached.get(ref);
 const dir=p.join(ref,'set/stuff'),all=walk(dir),index=new Map();
 for(const f of all){const ext=p.extname(f);if(['','.pattern','.weapon'].includes(ext))index.set((ext==='.pattern'?'pattern ':'')+p.basename(f,ext),f);}
 function filling(f,seen=new Set()){
  if(seen.has(f))throw Error('Cyclic weapon inheritance '+f);seen.add(f);
  const node=s.parse(fs.readFileSync(f,'latin1')).children[0];
  const own=s.child(node,'filling');if(own)return own.tokens[1]?.value;
  const parent=s.name(node)==='from'&&index.get(node.tokens[1]?.value);
  return parent?filling(parent,seen):null;
 }
 const weapons=[];
 for(const f of all){const rel=p.relative(ref,f).replaceAll('\\','/');
  if(!/^set\/stuff\/(?:mgun|rifle|smg|pistol)\//.test(rel)||!['','.weapon'].includes(p.extname(f)))continue;
  const fill=filling(f);if(!fill)continue;
  // Launchers/rifle grenades and vehicle guns in those folders are not supply clients.
  if(/(?:grenade|antitank|atrifle|tank|lafette|stationary)/i.test(rel)||/flare|kampfpistole/.test(fill))continue;
  weapons.push({file:rel,fill,source:fs.readFileSync(f,'latin1')});
 }
 const fills=[...new Set(weapons.map(w=>w.fill))].sort();
 const groups=fills.map((fill,i)=>({fill,tag:'ufb_supply_'+i}));
 for(const w of weapons){
  w.tag=groups.find(g=>g.fill===w.fill).tag;
  w.removeTags=[];
  let node=s.parse(w.source).children[0],parent=s.name(node)==='from'&&index.get(node.tokens[1]?.value);
  while(parent){
   const rel=p.relative(ref,parent).replaceAll('\\','/'),ancestor=weapons.find(a=>a.file===rel);
   if(ancestor&&ancestor.fill!==w.fill)w.removeTags.push(groups.find(g=>g.fill===ancestor.fill).tag);
   node=s.parse(fs.readFileSync(parent,'latin1')).children[0];parent=s.name(node)==='from'&&index.get(node.tokens[1]?.value);
  }
 }
 assert(weapons.length>100&&groups.length>10,'Incomplete firearm reference');
 const result={weapons,groups};cached.set(ref,result);return result;
}
function marker(w){const tree=s.parse(w.source),node=tree.children[0];return w.source.slice(0,node.end-1)+`\n\t{tag "${w.removeTags.map(t=>'-'+t+' ').join('')}${w.tag}"} ; UFB: native filling group, no weapon statistics changed\n`+w.source.slice(node.end-1);}
function corpse(fill,tag){return `{source advanced} {ignore_captured_by_user 0} {group ${tag?`{select ${T(tag)}}`:''}
 {include ${P('human')} ${S('dead')} ${I(fill)}}
 {exclude ${S('linked')} ${T('hidden')} ${T('bleeding')} ${T('_bleedout_')} ${T('wounded_animation_playing')} ${T('_ai_wounded_target_linked')}}}`;}
function transfers(ref,actor,donor){return catalog(ref).groups.map(g=>`{"if" {condition {type entities} {selector ${actor.replace('{include ',`{include ${I(g.tag)} `)}}}
 {"inventory" {selector ${actor}} {action take_from} {item "${g.fill}"} {amount 120} {entity ${donor}}}
}`).join('\n');}
function mission(ref){
 let text='; Resupply only from dead bodies within inventory reach, using the actual weapon filling.\n';
 // A polled entities condition re-scanned every soldier against ~50 tags each quant, x152 triggers:
 // constant frametime spikes. The cheap always-true rand fires at once; the real check is the timed
 // see_actors gate below. Periods 4.0-5.9s keep the 152 checks from landing on one quant.
 for(const [i,g] of catalog(ref).groups.entries()){
  const actor=`{source advanced} {ignore_captured_by_user 1} {group
   {include ${P('human')} ${S('operatable')} {team {team %team}} ${I(g.tag,'using')}}
   {exclude ${S('dead')} ${S('inactive')} ${S('linked')} ${P('crew')} ${P('repairing')} ${P('throwing')} ${I(g.fill,'amount')}
    ${[...protectedHumanTags,'_ufb_combat_busy','_ufb_job_reserved','_ufb_supply_cooldown'].map(T).join(' ')}}}`;
  const picked=`{source advanced} {ignore_captured_by_user 1} {amount 1} {group {select ${T('_ufb_supply_actor_%team')}} {include ${P('human')} ${S('operatable')} ${I(g.tag,'using')}} {exclude ${S('dead')} ${S('inactive')} ${S('linked')}}}`;
  const donor=corpse(g.fill,'_ufb_supply_body_%team').replace('{source advanced}',`{source advanced} {amount 1} {sort {type entity} {entity ${picked}}}`);
  text+=`(define "ufb_supply_${g.tag}"
 {"ufb/supply/${g.tag} %team"
  {condition {terms {"1.rand" {value 1}}}}
  {actions
   {"if" {condition {type see_actors} {selector ${actor}} {enemy ${corpse(g.fill)}} {distance {mode near_than} {meters 3}}
    {tag {"tag pair"} {"for selector" _ufb_supply_actor_%team} {"for enemy" _ufb_supply_body_%team}}}
    {"switch"
     {"case" {condition {type see_actors} {selector ${picked}} {enemy {source advanced} {ignore_captured_by_user 0} {group {include {team {team %foe}} ${S('operatable')}} {exclude ${S('dead')} ${S('inactive')}}}} {distance {mode near_than} {meters 25}} {detection visible}}}
     {"default"
      {"inventory" {selector ${picked}} {action take_from} {item "${g.fill}"} {amount 120} {entity ${donor}}}
      {"effect" {selector ${picked}} {effect ufb_supply_cooldown}}
     }
    }
   }
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_actor_%team}} {tag_remove _ufb_supply_actor_%team}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_body_%team}} {tag_remove _ufb_supply_body_%team}}
   {"delay" {time ${(4+(i%20)*0.1).toFixed(1)}}}
   {"trigger" {name "ufb/supply/${g.tag} %team"}}
  }
 }
)\n`;
  for(const [team,foe]of sides)text+=`("ufb_supply_${g.tag}" team(${team}) foe(${foe}))\n`;
 }
 return text+'\n(include "/map/multi/ufb_medical_support.inc")\n';
}
function expected(ref){const c=catalog(ref);return [
 ...c.weapons.map(w=>({file:w.file,text:marker(w)})),
 {file:'map/multi/ufb_logistics.inc',text:mission(ref)},
 ...require('./medical-support.cjs').expected()
];}
module.exports={catalog,marker,transfers,mission,expected};
