const fs=require('fs'),p=require('path'),s=require('./lib/sdl.cjs'),assert=require('assert/strict');
const files=['ufb_crew_safety.inc','ufb_crew_skirmish.inc'];
function mission(text){
 text=text.replace('{tag {tag _ufb_crew_safe}} {tag {tag _lua_mi}}','{tag {tag _ufb_crew_safe}} {tag {tag _ufb_crew_cover_retry}} {tag {tag _lua_mi}}');
 return text.replace('{"entity_state" {selector {tag _ufb_crew_pending}} {tag_add _ufb_crew_safe}}','{"effect" {selector {tag _ufb_crew_pending}} {effect ufb_crew_cover_lease}}');
}
const events=`; Bounded crew cover ownership; retry only after a failed attempt has cooled down.
{on "ufb_crew_cover_release" sync
 {kill_delay "ufb_crew_cover_result"} {kill_delay "ufb_crew_cover_review"}
 {tags remove "_ufb_crew_safe"} {tags add "_ufb_crew_cover_retry"}
 {kill_delay "ufb_crew_cover_retry"}
 {delay 12 "ufb_crew_cover_retry" {tags remove "_ufb_crew_cover_retry"}}
}
{on "ufb_crew_cover_review" sync
 {if not dead {if not linked {if in_cover
  {delay 3 "ufb_crew_cover_review" {call "ufb_crew_cover_review"}}
 else {call "ufb_crew_cover_release"}}
 else {call "ufb_crew_cover_release"}}
 else {call "ufb_crew_cover_release"}}
}
{on "ufb_crew_cover_lease" sync
 {tags add "_ufb_crew_safe"}
 {kill_delay "ufb_crew_cover_result"} {kill_delay "ufb_crew_cover_review"}
 {delay 0.5 "ufb_crew_cover_result"
  {if not in_cover {if not tagged "_ufb_autonomy_moving" {call "ufb_crew_cover_release"}}}
 }
 {delay 12 "ufb_crew_cover_review" {call "ufb_crew_cover_review"}}
}
`;
function human(text){if(text.includes('(include "ufb_crew_cover_events.inc")'))return text;const root=s.parse(text).children[0];assert.equal(s.name(root),'human');return text.slice(0,root.end-1)+'\n(include "ufb_crew_cover_events.inc")\n'+text.slice(root.end-1);}
function build(root=p.resolve(__dirname,'../mods/ultimate_frontline_bundle/resource')){for(const f of files){const path=p.join(root,'map/multi',f);fs.writeFileSync(path,mission(fs.readFileSync(path,'latin1')),'latin1');}const h=p.join(root,'set/interaction_entity/human.inc');fs.writeFileSync(h,human(fs.readFileSync(h,'latin1')),'latin1');fs.writeFileSync(p.join(root,'set/interaction_entity/ufb_crew_cover_events.inc'),events,'latin1');}
module.exports={mission,human,events,build};if(require.main===module)build();
