; Only tags and short-lived target coordinates; no damage, health or free ammunition.
{on "ufb_reserve_job"
 {tags add "_ufb_job_reserved"}
 {delay 6 {tags remove "_ufb_job_reserved"}}
}
{on "ufb_launcher_keep"
 {tags add "_ufb_launcher_keep"}
 {delay 10 {tags remove "_ufb_launcher_keep"}}
}
{on "ufb_launcher_grace"
 {tags add "_ufb_launcher_seen"}
 {delay 12 {tags add "_ufb_launcher_ready"}}
 {delay 24 {tags remove "_ufb_launcher_seen"} {tags remove "_ufb_launcher_ready"}}
}
{on "ufb_autonomy_move_on" {tags add "_ufb_autonomy_moving"}}
{on "ufb_autonomy_move_off" {tags remove "_ufb_autonomy_moving"}}
{on "ufb_combat_hit"
 {if not dead {if not linked {if not tagged "_ufb_recent_hit"
  {tags add "_ufb_recent_hit"}
  {delay 8 {tags remove "_ufb_recent_hit"}}
 }}}
}

{on "ufb_combat_ap_cooldown"
 {tags add "_ufb_combat_busy"}
 {tags add "_ufb_combat_ap_cooldown"}
 {delay 6 {tags remove "_ufb_combat_busy"}}
 {delay 12 {tags remove "_ufb_combat_ap_cooldown"}}
}

{on "ufb_combat_at_cooldown"
 {tags add "_ufb_combat_busy"}
 {tags add "_ufb_combat_at_cooldown"}
 {delay 6 {tags remove "_ufb_combat_busy"}}
 {delay 10 {tags remove "_ufb_combat_at_cooldown"}}
}

{on "ufb_combat_launcher_cooldown"
 {tags add "_ufb_combat_busy"}
 {tags add "_ufb_combat_launcher_cooldown"}
 {delay 6 {tags remove "_ufb_combat_busy"}}
 {delay 8 {tags remove "_ufb_combat_launcher_cooldown"}}
}

{on "ufb_combat_smoke_cooldown"
 {tags add "_ufb_combat_busy"}
 {tags add "_ufb_combat_smoke_cooldown"}
 {delay 6 {tags remove "_ufb_combat_busy"}}
 {delay 35 {tags remove "_ufb_combat_smoke_cooldown"}}
}

{on "ufb_combat_critical_cooldown"
 {tags add "_ufb_combat_busy"}
 {tags add "_ufb_combat_critical_cooldown"}
 {delay 6 {tags remove "_ufb_combat_busy"}}
 {delay 30 {tags remove "_ufb_combat_critical_cooldown"}}
}

(define "ufb_combat_target_events"
 {on "ufb_combat_probe_cover_%player"
  {if in_cover
   {tags add "_ufb_combat_cover_%player"}
   {delay 1 {tags remove "_ufb_combat_cover_%player"}}
  else {tags remove "_ufb_combat_cover_%player"}}
 }
 {on "ufb_combat_smoke_point_%player" sync
  {spawn "ufb_smoke_screen_point" local_offset 200 0 0 constrain_after_dir
   {tags add "_ufb_combat_smoke_point_%player"}
   {delay 3 {delete}}
  }
 }
)
("ufb_combat_target_events" player(0))
("ufb_combat_target_events" player(1))
("ufb_combat_target_events" player(2))
("ufb_combat_target_events" player(3))
("ufb_combat_target_events" player(4))
("ufb_combat_target_events" player(5))
("ufb_combat_target_events" player(6))
("ufb_combat_target_events" player(7))
("ufb_combat_target_events" player(8))
("ufb_combat_target_events" player(9))
("ufb_combat_target_events" player(10))
("ufb_combat_target_events" player(11))
("ufb_combat_target_events" player(12))
("ufb_combat_target_events" player(13))
("ufb_combat_target_events" player(14))
("ufb_combat_target_events" player(15))
("ufb_combat_target_events" player(16))

(include "ufb_infantry_support_events.inc")
(include "ufb_static_weapon_events.inc")
