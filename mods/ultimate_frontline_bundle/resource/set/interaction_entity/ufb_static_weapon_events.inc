; Crew and infantry events for stationary weapon reactions.
{on "ufb_tank_fear"
 {tags add "_ufb_tank_fear"}
 {delay 25 {tags remove "_ufb_tank_fear"}}
}
{on "ufb_tank_fear_shout" {talk "alert_tank"}}
{on "ufb_mg_shout" {talk "ufb_alert_mgun"}}
{on "ufb_air_alert" {tags add "_ufb_air_alert_cooldown"} {talk "ufb_alert_airborne"} {delay 90 {tags remove "_ufb_air_alert_cooldown"}}}
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
 {call "ufb_morale_quiet"}
}
{on "ufb_morale_quiet"
 {tags remove "_ufb_steady"}
 {kill_delay "ufb_morale_quiet_end"}
 {delay 40 "ufb_morale_quiet_end" {tags add "_ufb_steady"}}
}
{on "ufb_gun_bind_man_0_a"
 {if operatable {if not tagged "medic" {if not tagged "_ufb_healing_active" {if not tagged "_ufb_job_reserved" {if not tagged "_ufb_combat_busy"
  {tags add "_ufb_gun_crew_0_a"} {tags add "_ufb_gun_job_active"}
  {kill_delay "ufb_gun_man_expiry"}
  {delay 120 "ufb_gun_man_expiry" {call "ufb_gun_release_0_a"}}
 }}}}}
}
{on "ufb_gun_escape_0_a"
 {talk "retreat"}
 {delay 12 {if tagged "_ufb_gun_crew_0_a" {tags add "_ufb_gun_cover_0_a"}}}
}
{on "ufb_gun_release_0_a"
 {kill_delay "ufb_gun_man_expiry"}
 {tags remove "_ufb_gun_crew_0_a"} {tags remove "_ufb_gun_cover_0_a"} {tags remove "_ufb_gun_job_active"}
}
{on "ufb_gun_bind_man_1_a"
 {if operatable {if not tagged "medic" {if not tagged "_ufb_healing_active" {if not tagged "_ufb_job_reserved" {if not tagged "_ufb_combat_busy"
  {tags add "_ufb_gun_crew_1_a"} {tags add "_ufb_gun_job_active"}
  {kill_delay "ufb_gun_man_expiry"}
  {delay 120 "ufb_gun_man_expiry" {call "ufb_gun_release_1_a"}}
 }}}}}
}
{on "ufb_gun_escape_1_a"
 {talk "retreat"}
 {delay 12 {if tagged "_ufb_gun_crew_1_a" {tags add "_ufb_gun_cover_1_a"}}}
}
{on "ufb_gun_release_1_a"
 {kill_delay "ufb_gun_man_expiry"}
 {tags remove "_ufb_gun_crew_1_a"} {tags remove "_ufb_gun_cover_1_a"} {tags remove "_ufb_gun_job_active"}
}
{on "ufb_gun_bind_man_2_a"
 {if operatable {if not tagged "medic" {if not tagged "_ufb_healing_active" {if not tagged "_ufb_job_reserved" {if not tagged "_ufb_combat_busy"
  {tags add "_ufb_gun_crew_2_a"} {tags add "_ufb_gun_job_active"}
  {kill_delay "ufb_gun_man_expiry"}
  {delay 120 "ufb_gun_man_expiry" {call "ufb_gun_release_2_a"}}
 }}}}}
}
{on "ufb_gun_escape_2_a"
 {talk "retreat"}
 {delay 12 {if tagged "_ufb_gun_crew_2_a" {tags add "_ufb_gun_cover_2_a"}}}
}
{on "ufb_gun_release_2_a"
 {kill_delay "ufb_gun_man_expiry"}
 {tags remove "_ufb_gun_crew_2_a"} {tags remove "_ufb_gun_cover_2_a"} {tags remove "_ufb_gun_job_active"}
}
{on "ufb_gun_bind_man_3_a"
 {if operatable {if not tagged "medic" {if not tagged "_ufb_healing_active" {if not tagged "_ufb_job_reserved" {if not tagged "_ufb_combat_busy"
  {tags add "_ufb_gun_crew_3_a"} {tags add "_ufb_gun_job_active"}
  {kill_delay "ufb_gun_man_expiry"}
  {delay 120 "ufb_gun_man_expiry" {call "ufb_gun_release_3_a"}}
 }}}}}
}
{on "ufb_gun_escape_3_a"
 {talk "retreat"}
 {delay 12 {if tagged "_ufb_gun_crew_3_a" {tags add "_ufb_gun_cover_3_a"}}}
}
{on "ufb_gun_release_3_a"
 {kill_delay "ufb_gun_man_expiry"}
 {tags remove "_ufb_gun_crew_3_a"} {tags remove "_ufb_gun_cover_3_a"} {tags remove "_ufb_gun_job_active"}
}
{on "ufb_gun_bind_man_4_a"
 {if operatable {if not tagged "medic" {if not tagged "_ufb_healing_active" {if not tagged "_ufb_job_reserved" {if not tagged "_ufb_combat_busy"
  {tags add "_ufb_gun_crew_4_a"} {tags add "_ufb_gun_job_active"}
  {kill_delay "ufb_gun_man_expiry"}
  {delay 120 "ufb_gun_man_expiry" {call "ufb_gun_release_4_a"}}
 }}}}}
}
{on "ufb_gun_escape_4_a"
 {talk "retreat"}
 {delay 12 {if tagged "_ufb_gun_crew_4_a" {tags add "_ufb_gun_cover_4_a"}}}
}
{on "ufb_gun_release_4_a"
 {kill_delay "ufb_gun_man_expiry"}
 {tags remove "_ufb_gun_crew_4_a"} {tags remove "_ufb_gun_cover_4_a"} {tags remove "_ufb_gun_job_active"}
}
{on "ufb_gun_bind_man_5_a"
 {if operatable {if not tagged "medic" {if not tagged "_ufb_healing_active" {if not tagged "_ufb_job_reserved" {if not tagged "_ufb_combat_busy"
  {tags add "_ufb_gun_crew_5_a"} {tags add "_ufb_gun_job_active"}
  {kill_delay "ufb_gun_man_expiry"}
  {delay 120 "ufb_gun_man_expiry" {call "ufb_gun_release_5_a"}}
 }}}}}
}
{on "ufb_gun_escape_5_a"
 {talk "retreat"}
 {delay 12 {if tagged "_ufb_gun_crew_5_a" {tags add "_ufb_gun_cover_5_a"}}}
}
{on "ufb_gun_release_5_a"
 {kill_delay "ufb_gun_man_expiry"}
 {tags remove "_ufb_gun_crew_5_a"} {tags remove "_ufb_gun_cover_5_a"} {tags remove "_ufb_gun_job_active"}
}
{on "ufb_gun_bind_man_6_a"
 {if operatable {if not tagged "medic" {if not tagged "_ufb_healing_active" {if not tagged "_ufb_job_reserved" {if not tagged "_ufb_combat_busy"
  {tags add "_ufb_gun_crew_6_a"} {tags add "_ufb_gun_job_active"}
  {kill_delay "ufb_gun_man_expiry"}
  {delay 120 "ufb_gun_man_expiry" {call "ufb_gun_release_6_a"}}
 }}}}}
}
{on "ufb_gun_escape_6_a"
 {talk "retreat"}
 {delay 12 {if tagged "_ufb_gun_crew_6_a" {tags add "_ufb_gun_cover_6_a"}}}
}
{on "ufb_gun_release_6_a"
 {kill_delay "ufb_gun_man_expiry"}
 {tags remove "_ufb_gun_crew_6_a"} {tags remove "_ufb_gun_cover_6_a"} {tags remove "_ufb_gun_job_active"}
}
{on "ufb_gun_bind_man_7_a"
 {if operatable {if not tagged "medic" {if not tagged "_ufb_healing_active" {if not tagged "_ufb_job_reserved" {if not tagged "_ufb_combat_busy"
  {tags add "_ufb_gun_crew_7_a"} {tags add "_ufb_gun_job_active"}
  {kill_delay "ufb_gun_man_expiry"}
  {delay 120 "ufb_gun_man_expiry" {call "ufb_gun_release_7_a"}}
 }}}}}
}
{on "ufb_gun_escape_7_a"
 {talk "retreat"}
 {delay 12 {if tagged "_ufb_gun_crew_7_a" {tags add "_ufb_gun_cover_7_a"}}}
}
{on "ufb_gun_release_7_a"
 {kill_delay "ufb_gun_man_expiry"}
 {tags remove "_ufb_gun_crew_7_a"} {tags remove "_ufb_gun_cover_7_a"} {tags remove "_ufb_gun_job_active"}
}
{on "ufb_gun_bind_man_8_a"
 {if operatable {if not tagged "medic" {if not tagged "_ufb_healing_active" {if not tagged "_ufb_job_reserved" {if not tagged "_ufb_combat_busy"
  {tags add "_ufb_gun_crew_8_a"} {tags add "_ufb_gun_job_active"}
  {kill_delay "ufb_gun_man_expiry"}
  {delay 120 "ufb_gun_man_expiry" {call "ufb_gun_release_8_a"}}
 }}}}}
}
{on "ufb_gun_escape_8_a"
 {talk "retreat"}
 {delay 12 {if tagged "_ufb_gun_crew_8_a" {tags add "_ufb_gun_cover_8_a"}}}
}
{on "ufb_gun_release_8_a"
 {kill_delay "ufb_gun_man_expiry"}
 {tags remove "_ufb_gun_crew_8_a"} {tags remove "_ufb_gun_cover_8_a"} {tags remove "_ufb_gun_job_active"}
}
{on "ufb_gun_bind_man_9_a"
 {if operatable {if not tagged "medic" {if not tagged "_ufb_healing_active" {if not tagged "_ufb_job_reserved" {if not tagged "_ufb_combat_busy"
  {tags add "_ufb_gun_crew_9_a"} {tags add "_ufb_gun_job_active"}
  {kill_delay "ufb_gun_man_expiry"}
  {delay 120 "ufb_gun_man_expiry" {call "ufb_gun_release_9_a"}}
 }}}}}
}
{on "ufb_gun_escape_9_a"
 {talk "retreat"}
 {delay 12 {if tagged "_ufb_gun_crew_9_a" {tags add "_ufb_gun_cover_9_a"}}}
}
{on "ufb_gun_release_9_a"
 {kill_delay "ufb_gun_man_expiry"}
 {tags remove "_ufb_gun_crew_9_a"} {tags remove "_ufb_gun_cover_9_a"} {tags remove "_ufb_gun_job_active"}
}
{on "ufb_gun_bind_man_10_a"
 {if operatable {if not tagged "medic" {if not tagged "_ufb_healing_active" {if not tagged "_ufb_job_reserved" {if not tagged "_ufb_combat_busy"
  {tags add "_ufb_gun_crew_10_a"} {tags add "_ufb_gun_job_active"}
  {kill_delay "ufb_gun_man_expiry"}
  {delay 120 "ufb_gun_man_expiry" {call "ufb_gun_release_10_a"}}
 }}}}}
}
{on "ufb_gun_escape_10_a"
 {talk "retreat"}
 {delay 12 {if tagged "_ufb_gun_crew_10_a" {tags add "_ufb_gun_cover_10_a"}}}
}
{on "ufb_gun_release_10_a"
 {kill_delay "ufb_gun_man_expiry"}
 {tags remove "_ufb_gun_crew_10_a"} {tags remove "_ufb_gun_cover_10_a"} {tags remove "_ufb_gun_job_active"}
}
{on "ufb_gun_bind_man_11_a"
 {if operatable {if not tagged "medic" {if not tagged "_ufb_healing_active" {if not tagged "_ufb_job_reserved" {if not tagged "_ufb_combat_busy"
  {tags add "_ufb_gun_crew_11_a"} {tags add "_ufb_gun_job_active"}
  {kill_delay "ufb_gun_man_expiry"}
  {delay 120 "ufb_gun_man_expiry" {call "ufb_gun_release_11_a"}}
 }}}}}
}
{on "ufb_gun_escape_11_a"
 {talk "retreat"}
 {delay 12 {if tagged "_ufb_gun_crew_11_a" {tags add "_ufb_gun_cover_11_a"}}}
}
{on "ufb_gun_release_11_a"
 {kill_delay "ufb_gun_man_expiry"}
 {tags remove "_ufb_gun_crew_11_a"} {tags remove "_ufb_gun_cover_11_a"} {tags remove "_ufb_gun_job_active"}
}
{on "ufb_gun_bind_man_12_a"
 {if operatable {if not tagged "medic" {if not tagged "_ufb_healing_active" {if not tagged "_ufb_job_reserved" {if not tagged "_ufb_combat_busy"
  {tags add "_ufb_gun_crew_12_a"} {tags add "_ufb_gun_job_active"}
  {kill_delay "ufb_gun_man_expiry"}
  {delay 120 "ufb_gun_man_expiry" {call "ufb_gun_release_12_a"}}
 }}}}}
}
{on "ufb_gun_escape_12_a"
 {talk "retreat"}
 {delay 12 {if tagged "_ufb_gun_crew_12_a" {tags add "_ufb_gun_cover_12_a"}}}
}
{on "ufb_gun_release_12_a"
 {kill_delay "ufb_gun_man_expiry"}
 {tags remove "_ufb_gun_crew_12_a"} {tags remove "_ufb_gun_cover_12_a"} {tags remove "_ufb_gun_job_active"}
}
{on "ufb_gun_bind_man_13_a"
 {if operatable {if not tagged "medic" {if not tagged "_ufb_healing_active" {if not tagged "_ufb_job_reserved" {if not tagged "_ufb_combat_busy"
  {tags add "_ufb_gun_crew_13_a"} {tags add "_ufb_gun_job_active"}
  {kill_delay "ufb_gun_man_expiry"}
  {delay 120 "ufb_gun_man_expiry" {call "ufb_gun_release_13_a"}}
 }}}}}
}
{on "ufb_gun_escape_13_a"
 {talk "retreat"}
 {delay 12 {if tagged "_ufb_gun_crew_13_a" {tags add "_ufb_gun_cover_13_a"}}}
}
{on "ufb_gun_release_13_a"
 {kill_delay "ufb_gun_man_expiry"}
 {tags remove "_ufb_gun_crew_13_a"} {tags remove "_ufb_gun_cover_13_a"} {tags remove "_ufb_gun_job_active"}
}
{on "ufb_gun_bind_man_14_a"
 {if operatable {if not tagged "medic" {if not tagged "_ufb_healing_active" {if not tagged "_ufb_job_reserved" {if not tagged "_ufb_combat_busy"
  {tags add "_ufb_gun_crew_14_a"} {tags add "_ufb_gun_job_active"}
  {kill_delay "ufb_gun_man_expiry"}
  {delay 120 "ufb_gun_man_expiry" {call "ufb_gun_release_14_a"}}
 }}}}}
}
{on "ufb_gun_escape_14_a"
 {talk "retreat"}
 {delay 12 {if tagged "_ufb_gun_crew_14_a" {tags add "_ufb_gun_cover_14_a"}}}
}
{on "ufb_gun_release_14_a"
 {kill_delay "ufb_gun_man_expiry"}
 {tags remove "_ufb_gun_crew_14_a"} {tags remove "_ufb_gun_cover_14_a"} {tags remove "_ufb_gun_job_active"}
}
{on "ufb_gun_bind_man_15_a"
 {if operatable {if not tagged "medic" {if not tagged "_ufb_healing_active" {if not tagged "_ufb_job_reserved" {if not tagged "_ufb_combat_busy"
  {tags add "_ufb_gun_crew_15_a"} {tags add "_ufb_gun_job_active"}
  {kill_delay "ufb_gun_man_expiry"}
  {delay 120 "ufb_gun_man_expiry" {call "ufb_gun_release_15_a"}}
 }}}}}
}
{on "ufb_gun_escape_15_a"
 {talk "retreat"}
 {delay 12 {if tagged "_ufb_gun_crew_15_a" {tags add "_ufb_gun_cover_15_a"}}}
}
{on "ufb_gun_release_15_a"
 {kill_delay "ufb_gun_man_expiry"}
 {tags remove "_ufb_gun_crew_15_a"} {tags remove "_ufb_gun_cover_15_a"} {tags remove "_ufb_gun_job_active"}
}
{on "ufb_gun_bind_man_0_b"
 {if operatable {if not tagged "medic" {if not tagged "_ufb_healing_active" {if not tagged "_ufb_job_reserved" {if not tagged "_ufb_combat_busy"
  {tags add "_ufb_gun_crew_0_b"} {tags add "_ufb_gun_job_active"}
  {kill_delay "ufb_gun_man_expiry"}
  {delay 120 "ufb_gun_man_expiry" {call "ufb_gun_release_0_b"}}
 }}}}}
}
{on "ufb_gun_escape_0_b"
 {talk "retreat"}
 {delay 12 {if tagged "_ufb_gun_crew_0_b" {tags add "_ufb_gun_cover_0_b"}}}
}
{on "ufb_gun_release_0_b"
 {kill_delay "ufb_gun_man_expiry"}
 {tags remove "_ufb_gun_crew_0_b"} {tags remove "_ufb_gun_cover_0_b"} {tags remove "_ufb_gun_job_active"}
}
{on "ufb_gun_bind_man_1_b"
 {if operatable {if not tagged "medic" {if not tagged "_ufb_healing_active" {if not tagged "_ufb_job_reserved" {if not tagged "_ufb_combat_busy"
  {tags add "_ufb_gun_crew_1_b"} {tags add "_ufb_gun_job_active"}
  {kill_delay "ufb_gun_man_expiry"}
  {delay 120 "ufb_gun_man_expiry" {call "ufb_gun_release_1_b"}}
 }}}}}
}
{on "ufb_gun_escape_1_b"
 {talk "retreat"}
 {delay 12 {if tagged "_ufb_gun_crew_1_b" {tags add "_ufb_gun_cover_1_b"}}}
}
{on "ufb_gun_release_1_b"
 {kill_delay "ufb_gun_man_expiry"}
 {tags remove "_ufb_gun_crew_1_b"} {tags remove "_ufb_gun_cover_1_b"} {tags remove "_ufb_gun_job_active"}
}
{on "ufb_gun_bind_man_2_b"
 {if operatable {if not tagged "medic" {if not tagged "_ufb_healing_active" {if not tagged "_ufb_job_reserved" {if not tagged "_ufb_combat_busy"
  {tags add "_ufb_gun_crew_2_b"} {tags add "_ufb_gun_job_active"}
  {kill_delay "ufb_gun_man_expiry"}
  {delay 120 "ufb_gun_man_expiry" {call "ufb_gun_release_2_b"}}
 }}}}}
}
{on "ufb_gun_escape_2_b"
 {talk "retreat"}
 {delay 12 {if tagged "_ufb_gun_crew_2_b" {tags add "_ufb_gun_cover_2_b"}}}
}
{on "ufb_gun_release_2_b"
 {kill_delay "ufb_gun_man_expiry"}
 {tags remove "_ufb_gun_crew_2_b"} {tags remove "_ufb_gun_cover_2_b"} {tags remove "_ufb_gun_job_active"}
}
{on "ufb_gun_bind_man_3_b"
 {if operatable {if not tagged "medic" {if not tagged "_ufb_healing_active" {if not tagged "_ufb_job_reserved" {if not tagged "_ufb_combat_busy"
  {tags add "_ufb_gun_crew_3_b"} {tags add "_ufb_gun_job_active"}
  {kill_delay "ufb_gun_man_expiry"}
  {delay 120 "ufb_gun_man_expiry" {call "ufb_gun_release_3_b"}}
 }}}}}
}
{on "ufb_gun_escape_3_b"
 {talk "retreat"}
 {delay 12 {if tagged "_ufb_gun_crew_3_b" {tags add "_ufb_gun_cover_3_b"}}}
}
{on "ufb_gun_release_3_b"
 {kill_delay "ufb_gun_man_expiry"}
 {tags remove "_ufb_gun_crew_3_b"} {tags remove "_ufb_gun_cover_3_b"} {tags remove "_ufb_gun_job_active"}
}
{on "ufb_gun_bind_man_4_b"
 {if operatable {if not tagged "medic" {if not tagged "_ufb_healing_active" {if not tagged "_ufb_job_reserved" {if not tagged "_ufb_combat_busy"
  {tags add "_ufb_gun_crew_4_b"} {tags add "_ufb_gun_job_active"}
  {kill_delay "ufb_gun_man_expiry"}
  {delay 120 "ufb_gun_man_expiry" {call "ufb_gun_release_4_b"}}
 }}}}}
}
{on "ufb_gun_escape_4_b"
 {talk "retreat"}
 {delay 12 {if tagged "_ufb_gun_crew_4_b" {tags add "_ufb_gun_cover_4_b"}}}
}
{on "ufb_gun_release_4_b"
 {kill_delay "ufb_gun_man_expiry"}
 {tags remove "_ufb_gun_crew_4_b"} {tags remove "_ufb_gun_cover_4_b"} {tags remove "_ufb_gun_job_active"}
}
{on "ufb_gun_bind_man_5_b"
 {if operatable {if not tagged "medic" {if not tagged "_ufb_healing_active" {if not tagged "_ufb_job_reserved" {if not tagged "_ufb_combat_busy"
  {tags add "_ufb_gun_crew_5_b"} {tags add "_ufb_gun_job_active"}
  {kill_delay "ufb_gun_man_expiry"}
  {delay 120 "ufb_gun_man_expiry" {call "ufb_gun_release_5_b"}}
 }}}}}
}
{on "ufb_gun_escape_5_b"
 {talk "retreat"}
 {delay 12 {if tagged "_ufb_gun_crew_5_b" {tags add "_ufb_gun_cover_5_b"}}}
}
{on "ufb_gun_release_5_b"
 {kill_delay "ufb_gun_man_expiry"}
 {tags remove "_ufb_gun_crew_5_b"} {tags remove "_ufb_gun_cover_5_b"} {tags remove "_ufb_gun_job_active"}
}
{on "ufb_gun_bind_man_6_b"
 {if operatable {if not tagged "medic" {if not tagged "_ufb_healing_active" {if not tagged "_ufb_job_reserved" {if not tagged "_ufb_combat_busy"
  {tags add "_ufb_gun_crew_6_b"} {tags add "_ufb_gun_job_active"}
  {kill_delay "ufb_gun_man_expiry"}
  {delay 120 "ufb_gun_man_expiry" {call "ufb_gun_release_6_b"}}
 }}}}}
}
{on "ufb_gun_escape_6_b"
 {talk "retreat"}
 {delay 12 {if tagged "_ufb_gun_crew_6_b" {tags add "_ufb_gun_cover_6_b"}}}
}
{on "ufb_gun_release_6_b"
 {kill_delay "ufb_gun_man_expiry"}
 {tags remove "_ufb_gun_crew_6_b"} {tags remove "_ufb_gun_cover_6_b"} {tags remove "_ufb_gun_job_active"}
}
{on "ufb_gun_bind_man_7_b"
 {if operatable {if not tagged "medic" {if not tagged "_ufb_healing_active" {if not tagged "_ufb_job_reserved" {if not tagged "_ufb_combat_busy"
  {tags add "_ufb_gun_crew_7_b"} {tags add "_ufb_gun_job_active"}
  {kill_delay "ufb_gun_man_expiry"}
  {delay 120 "ufb_gun_man_expiry" {call "ufb_gun_release_7_b"}}
 }}}}}
}
{on "ufb_gun_escape_7_b"
 {talk "retreat"}
 {delay 12 {if tagged "_ufb_gun_crew_7_b" {tags add "_ufb_gun_cover_7_b"}}}
}
{on "ufb_gun_release_7_b"
 {kill_delay "ufb_gun_man_expiry"}
 {tags remove "_ufb_gun_crew_7_b"} {tags remove "_ufb_gun_cover_7_b"} {tags remove "_ufb_gun_job_active"}
}
{on "ufb_gun_bind_man_8_b"
 {if operatable {if not tagged "medic" {if not tagged "_ufb_healing_active" {if not tagged "_ufb_job_reserved" {if not tagged "_ufb_combat_busy"
  {tags add "_ufb_gun_crew_8_b"} {tags add "_ufb_gun_job_active"}
  {kill_delay "ufb_gun_man_expiry"}
  {delay 120 "ufb_gun_man_expiry" {call "ufb_gun_release_8_b"}}
 }}}}}
}
{on "ufb_gun_escape_8_b"
 {talk "retreat"}
 {delay 12 {if tagged "_ufb_gun_crew_8_b" {tags add "_ufb_gun_cover_8_b"}}}
}
{on "ufb_gun_release_8_b"
 {kill_delay "ufb_gun_man_expiry"}
 {tags remove "_ufb_gun_crew_8_b"} {tags remove "_ufb_gun_cover_8_b"} {tags remove "_ufb_gun_job_active"}
}
{on "ufb_gun_bind_man_9_b"
 {if operatable {if not tagged "medic" {if not tagged "_ufb_healing_active" {if not tagged "_ufb_job_reserved" {if not tagged "_ufb_combat_busy"
  {tags add "_ufb_gun_crew_9_b"} {tags add "_ufb_gun_job_active"}
  {kill_delay "ufb_gun_man_expiry"}
  {delay 120 "ufb_gun_man_expiry" {call "ufb_gun_release_9_b"}}
 }}}}}
}
{on "ufb_gun_escape_9_b"
 {talk "retreat"}
 {delay 12 {if tagged "_ufb_gun_crew_9_b" {tags add "_ufb_gun_cover_9_b"}}}
}
{on "ufb_gun_release_9_b"
 {kill_delay "ufb_gun_man_expiry"}
 {tags remove "_ufb_gun_crew_9_b"} {tags remove "_ufb_gun_cover_9_b"} {tags remove "_ufb_gun_job_active"}
}
{on "ufb_gun_bind_man_10_b"
 {if operatable {if not tagged "medic" {if not tagged "_ufb_healing_active" {if not tagged "_ufb_job_reserved" {if not tagged "_ufb_combat_busy"
  {tags add "_ufb_gun_crew_10_b"} {tags add "_ufb_gun_job_active"}
  {kill_delay "ufb_gun_man_expiry"}
  {delay 120 "ufb_gun_man_expiry" {call "ufb_gun_release_10_b"}}
 }}}}}
}
{on "ufb_gun_escape_10_b"
 {talk "retreat"}
 {delay 12 {if tagged "_ufb_gun_crew_10_b" {tags add "_ufb_gun_cover_10_b"}}}
}
{on "ufb_gun_release_10_b"
 {kill_delay "ufb_gun_man_expiry"}
 {tags remove "_ufb_gun_crew_10_b"} {tags remove "_ufb_gun_cover_10_b"} {tags remove "_ufb_gun_job_active"}
}
{on "ufb_gun_bind_man_11_b"
 {if operatable {if not tagged "medic" {if not tagged "_ufb_healing_active" {if not tagged "_ufb_job_reserved" {if not tagged "_ufb_combat_busy"
  {tags add "_ufb_gun_crew_11_b"} {tags add "_ufb_gun_job_active"}
  {kill_delay "ufb_gun_man_expiry"}
  {delay 120 "ufb_gun_man_expiry" {call "ufb_gun_release_11_b"}}
 }}}}}
}
{on "ufb_gun_escape_11_b"
 {talk "retreat"}
 {delay 12 {if tagged "_ufb_gun_crew_11_b" {tags add "_ufb_gun_cover_11_b"}}}
}
{on "ufb_gun_release_11_b"
 {kill_delay "ufb_gun_man_expiry"}
 {tags remove "_ufb_gun_crew_11_b"} {tags remove "_ufb_gun_cover_11_b"} {tags remove "_ufb_gun_job_active"}
}
{on "ufb_gun_bind_man_12_b"
 {if operatable {if not tagged "medic" {if not tagged "_ufb_healing_active" {if not tagged "_ufb_job_reserved" {if not tagged "_ufb_combat_busy"
  {tags add "_ufb_gun_crew_12_b"} {tags add "_ufb_gun_job_active"}
  {kill_delay "ufb_gun_man_expiry"}
  {delay 120 "ufb_gun_man_expiry" {call "ufb_gun_release_12_b"}}
 }}}}}
}
{on "ufb_gun_escape_12_b"
 {talk "retreat"}
 {delay 12 {if tagged "_ufb_gun_crew_12_b" {tags add "_ufb_gun_cover_12_b"}}}
}
{on "ufb_gun_release_12_b"
 {kill_delay "ufb_gun_man_expiry"}
 {tags remove "_ufb_gun_crew_12_b"} {tags remove "_ufb_gun_cover_12_b"} {tags remove "_ufb_gun_job_active"}
}
{on "ufb_gun_bind_man_13_b"
 {if operatable {if not tagged "medic" {if not tagged "_ufb_healing_active" {if not tagged "_ufb_job_reserved" {if not tagged "_ufb_combat_busy"
  {tags add "_ufb_gun_crew_13_b"} {tags add "_ufb_gun_job_active"}
  {kill_delay "ufb_gun_man_expiry"}
  {delay 120 "ufb_gun_man_expiry" {call "ufb_gun_release_13_b"}}
 }}}}}
}
{on "ufb_gun_escape_13_b"
 {talk "retreat"}
 {delay 12 {if tagged "_ufb_gun_crew_13_b" {tags add "_ufb_gun_cover_13_b"}}}
}
{on "ufb_gun_release_13_b"
 {kill_delay "ufb_gun_man_expiry"}
 {tags remove "_ufb_gun_crew_13_b"} {tags remove "_ufb_gun_cover_13_b"} {tags remove "_ufb_gun_job_active"}
}
{on "ufb_gun_bind_man_14_b"
 {if operatable {if not tagged "medic" {if not tagged "_ufb_healing_active" {if not tagged "_ufb_job_reserved" {if not tagged "_ufb_combat_busy"
  {tags add "_ufb_gun_crew_14_b"} {tags add "_ufb_gun_job_active"}
  {kill_delay "ufb_gun_man_expiry"}
  {delay 120 "ufb_gun_man_expiry" {call "ufb_gun_release_14_b"}}
 }}}}}
}
{on "ufb_gun_escape_14_b"
 {talk "retreat"}
 {delay 12 {if tagged "_ufb_gun_crew_14_b" {tags add "_ufb_gun_cover_14_b"}}}
}
{on "ufb_gun_release_14_b"
 {kill_delay "ufb_gun_man_expiry"}
 {tags remove "_ufb_gun_crew_14_b"} {tags remove "_ufb_gun_cover_14_b"} {tags remove "_ufb_gun_job_active"}
}
{on "ufb_gun_bind_man_15_b"
 {if operatable {if not tagged "medic" {if not tagged "_ufb_healing_active" {if not tagged "_ufb_job_reserved" {if not tagged "_ufb_combat_busy"
  {tags add "_ufb_gun_crew_15_b"} {tags add "_ufb_gun_job_active"}
  {kill_delay "ufb_gun_man_expiry"}
  {delay 120 "ufb_gun_man_expiry" {call "ufb_gun_release_15_b"}}
 }}}}}
}
{on "ufb_gun_escape_15_b"
 {talk "retreat"}
 {delay 12 {if tagged "_ufb_gun_crew_15_b" {tags add "_ufb_gun_cover_15_b"}}}
}
{on "ufb_gun_release_15_b"
 {kill_delay "ufb_gun_man_expiry"}
 {tags remove "_ufb_gun_crew_15_b"} {tags remove "_ufb_gun_cover_15_b"} {tags remove "_ufb_gun_job_active"}
}
