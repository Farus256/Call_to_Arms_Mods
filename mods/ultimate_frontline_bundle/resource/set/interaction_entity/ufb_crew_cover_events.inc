; Bounded crew cover ownership; retry only after a failed attempt has cooled down.
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
