{on "ufb_loot_cooldown"
 {tags add "_ufb_combat_busy"} {tags add "_ufb_loot_cooldown"}
 {delay 4 {tags remove "_ufb_combat_busy"}}
 {delay 20 {tags remove "_ufb_loot_cooldown"}}
}
{on "ufb_suppress_cooldown"
 {tags add "_ufb_combat_busy"} {tags add "_ufb_suppress_cooldown"}
 {delay 6 {tags remove "_ufb_combat_busy"}}
 {delay 15 {tags remove "_ufb_suppress_cooldown"}}
}
(define "ufb_suppress_point_events"
 {on "ufb_suppress_point_%team"
  {if in_cover {call "ufb_suppress_point_spawn_%team"}
  else lying {call "ufb_suppress_point_spawn_%team"}
  else squatting {call "ufb_suppress_point_spawn_%team"}}
 }
 {on "ufb_suppress_point_spawn_%team" sync
  {spawn "ufb_smoke_screen_point" "basis" x
   {tags add "_ufb_suppress_point_%team"}
   {delay 4 1 {delete}}
  }
 }
)
("ufb_suppress_point_events" team(a))
("ufb_suppress_point_events" team(b))
