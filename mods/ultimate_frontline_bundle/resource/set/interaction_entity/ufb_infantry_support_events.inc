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
 {on "ufb_suppress_point_%player"
  {if in_cover {call "ufb_suppress_point_spawn_%player"}
  else lying {call "ufb_suppress_point_spawn_%player"}
  else squatting {call "ufb_suppress_point_spawn_%player"}}
 }
 {on "ufb_suppress_point_spawn_%player" sync
  {spawn "ufb_smoke_screen_point" "basis" x
   {tags add "_ufb_suppress_point_%player"}
   {delay 4 1 {delete}}
  }
 }
)
("ufb_suppress_point_events" player(0))
("ufb_suppress_point_events" player(1))
("ufb_suppress_point_events" player(2))
("ufb_suppress_point_events" player(3))
("ufb_suppress_point_events" player(4))
("ufb_suppress_point_events" player(5))
("ufb_suppress_point_events" player(6))
("ufb_suppress_point_events" player(7))
("ufb_suppress_point_events" player(8))
("ufb_suppress_point_events" player(9))
("ufb_suppress_point_events" player(10))
("ufb_suppress_point_events" player(11))
("ufb_suppress_point_events" player(12))
("ufb_suppress_point_events" player(13))
("ufb_suppress_point_events" player(14))
("ufb_suppress_point_events" player(15))
("ufb_suppress_point_events" player(16))
