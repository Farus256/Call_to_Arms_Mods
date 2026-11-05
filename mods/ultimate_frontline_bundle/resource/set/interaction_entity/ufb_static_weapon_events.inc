; Crew and infantry events for stationary weapon reactions.
{on "ufb_tank_fear"
 {tags add "_ufb_tank_fear"}
 {delay 25 {tags remove "_ufb_tank_fear"}}
}
{on "ufb_tank_fear_shout" {talk "alert_tank"}}
{on "ufb_mg_shout" {talk "ufb_alert_mgun"}}
{on "ufb_near_blast"
 {if not tagged "_ufb_blast_cover"
  {tags add "_ufb_blast_cover"}
  {tags add "_ufb_blast_new"}
  {delay 1 {tags remove "_ufb_blast_new"}}
  {delay 20 {tags remove "_ufb_blast_cover"}}
 }
}
{on "ufb_shaken"
 {tags add "_ufb_shaken"}
 {delay 40 {tags add "_ufb_steady"}}
}
(define "ufb_gun_events"
 {on "ufb_gun_flee_%player"
  {tags add "_ufb_gun_crew_%player"}
  {tags add "_ufb_gun_back_%player"}
  {tags add "_lua_mi"}
  {talk "retreat"}
  {call "ufb_gun_flee_point_%player"}
  {delay 12
   {tags add "_ufb_gun_cover_%player"}
   {tags remove "_lua_mi"}
  }
  {delay 30 {tags remove "_ufb_gun_crew_%player"}}
  {delay 120 {tags remove "_ufb_gun_back_%player"}}
 }
 {on "ufb_gun_flee_point_%player" sync
  {spawn "ufb_smoke_screen_point" local_offset -700 0 0 constrain_after_dir
   {tags add "_ufb_gun_flee_point_%player"}
   {delay 14 {delete}}
  }
 }
)
("ufb_gun_events" player(0))
("ufb_gun_events" player(1))
("ufb_gun_events" player(2))
("ufb_gun_events" player(3))
("ufb_gun_events" player(4))
("ufb_gun_events" player(5))
("ufb_gun_events" player(6))
("ufb_gun_events" player(7))
("ufb_gun_events" player(8))
("ufb_gun_events" player(9))
("ufb_gun_events" player(10))
("ufb_gun_events" player(11))
("ufb_gun_events" player(12))
("ufb_gun_events" player(13))
("ufb_gun_events" player(14))
("ufb_gun_events" player(15))
("ufb_gun_events" player(16))
