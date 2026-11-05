; UFB combat autonomy. Native commands consume existing inventory and keep native ranges.
; Sides come from native {team} selectors; multiplayer missions define no diplomacy.
; Player ownership and active user capture are separate native states.
; Only stationary troops already firing may receive extra offensive orders.
; Prepared launchers are excluded from grenade/smoke switching; without armor nearby any
; soldier returns to a firearm, except one under direct user capture.


; at: one reserved pair per player; no drop-orders or fire-mode changes.
(define "ufb_combat_at"
 {"ufb/combat/at/acquire %team"
  {condition {terms {"1.see_actors" {selector {source advanced}
{ignore_captured_by_user 1}
{group
 {select {prop {prop human}}}
 {include {team {team %team}}
{prop {prop human}}
{state {state operatable}}
{state {state user_control}}
{prop {prop shooting}}
{with_item {type amount} {item "at"} {min 1}}}
 {exclude {state {state dead}}
{state {state inactive}}
{state {state linked}}
{prop {prop crew}}
{prop {prop repairing}}
{prop {prop throwing}}
{tag {tag _lua_mi}}
{tag {tag _lua_ignore}}
{tag {tag _ai_do_not_disturb}}
{tag {tag repairing}}
{tag {tag bleeding}}
{tag {tag _bleeding}}
{tag {tag wounded}}
{tag {tag _bleedout_}}
{tag {tag wounded_animation_playing}}
{tag {tag medic}}
{tag {tag _ai_medic}}
{tag {tag bot_medic}}
{tag {tag _ufb_healing_active}}
{tag {tag _ufb_autonomy_moving}}
{tag {tag _ai_wounded_carrier}}
{tag {tag _ai_ap_grenade}}
{tag {tag _ai_at_grenade}}
{tag {tag _ai_smoke_grenade}}
{tag {tag _ai_suppressed_by_mg}}
{tag {tag _ai_mgunner}}
{tag {tag _ai_reloading}}
{tag {tag _ai_looting_weapon}}
{tag {tag crew}}
{tag {tag tcrew}}
{tag {tag ecrew}}
{tag {tag ecrew_a}}
{tag {tag ecrew_b}}
{tag {tag bot_arty}}
{tag {tag bot_aa_guard}}
{tag {tag _ufb_crew_safe}}
{tag {tag _ufb_hf_cover_active}}
{tag {tag _ai_wirecutter_in_action}}
{tag {tag bot_inf_flank_in_progress}}
{tag {tag _ufb_smoke_120m_actor}}
{tag {tag _ufb_smoke_60m_actor}}
{tag {tag _ufb_smoke_wirecutter_actor}}
{tag {tag _ai_at_launcher_30}}
{tag {tag _ai_at_launcher_40}}
{tag {tag _ai_at_launcher_50}}
{tag {tag _ai_at_launcher_60}}
{tag {tag _ai_at_launcher_70}}
{tag {tag _ai_at_launcher_80}}
{tag {tag _ai_at_launcher_90}}
{tag {tag _ufb_suppress_actor_%team}}
{with_item {type using} {item "rocketlauncher"}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_combat_at_cooldown}}
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_launcher_actor_%team}}
{tag {tag _ufb_combat_at_actor_%team}}
{tag {tag _ufb_combat_critical_actor_%team}}
{tag {tag _ufb_combat_ap_actor_%team}}
{tag {tag _ufb_combat_smoke_actor_%team}}}
}}
{enemy {source advanced}
{ignore_captured_by_user 0}
{group {select {prop {prop vehicle}} {prop {prop tank}} {prop {prop car}} {prop {prop cannon}}} {include {team {team %foe}}
{state {state operatable}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop airborne}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}}}}}
{distance {mode in_range} {min 12} {max 16}}
{detection visible}
{tag {"tag pair"} {"for selector" _ufb_combat_at_pick_%team} {"for enemy" _ufb_combat_at_target_%team}}}}}
  {actions
   {"entity_state" {selector {amount 1} {ignore_captured_by_user 0} {tag _ufb_combat_at_pick_%team}} {tag_add _ufb_combat_at_actor_%team}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_combat_at_pick_%team}} {tag_remove _ufb_combat_at_pick_%team}}
   {"effect" {selector {ignore_captured_by_user 0} {tag _ufb_combat_at_actor_%team}} {effect ufb_reserve_job}}
   
   {"delay" {time 6}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_combat_at_actor_%team}} {tag_remove _ufb_combat_at_actor_%team}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_combat_at_target_%team}} {tag_remove _ufb_combat_at_target_%team}}
   {"delay" {time 2}}
   {"trigger" {name "ufb/combat/at/acquire %team"}}
  }
 }
 {"ufb/combat/at/apply %team"
  {condition {expression "1 & !2"} {terms
   {"1.see_actors" {selector {source advanced}
{ignore_captured_by_user 1}
{group
 {select {tag {tag _ufb_combat_at_actor_%team}}}
 {include {team {team %team}}
{prop {prop human}}
{state {state operatable}}
{state {state user_control}}
{prop {prop shooting}}
{with_item {type amount} {item "at"} {min 1}}}
 {exclude {state {state dead}}
{state {state inactive}}
{state {state linked}}
{prop {prop crew}}
{prop {prop repairing}}
{prop {prop throwing}}
{tag {tag _lua_mi}}
{tag {tag _lua_ignore}}
{tag {tag _ai_do_not_disturb}}
{tag {tag repairing}}
{tag {tag bleeding}}
{tag {tag _bleeding}}
{tag {tag wounded}}
{tag {tag _bleedout_}}
{tag {tag wounded_animation_playing}}
{tag {tag medic}}
{tag {tag _ai_medic}}
{tag {tag bot_medic}}
{tag {tag _ufb_healing_active}}
{tag {tag _ufb_autonomy_moving}}
{tag {tag _ai_wounded_carrier}}
{tag {tag _ai_ap_grenade}}
{tag {tag _ai_at_grenade}}
{tag {tag _ai_smoke_grenade}}
{tag {tag _ai_suppressed_by_mg}}
{tag {tag _ai_mgunner}}
{tag {tag _ai_reloading}}
{tag {tag _ai_looting_weapon}}
{tag {tag crew}}
{tag {tag tcrew}}
{tag {tag ecrew}}
{tag {tag ecrew_a}}
{tag {tag ecrew_b}}
{tag {tag bot_arty}}
{tag {tag bot_aa_guard}}
{tag {tag _ufb_crew_safe}}
{tag {tag _ufb_hf_cover_active}}
{tag {tag _ai_wirecutter_in_action}}
{tag {tag bot_inf_flank_in_progress}}
{tag {tag _ufb_smoke_120m_actor}}
{tag {tag _ufb_smoke_60m_actor}}
{tag {tag _ufb_smoke_wirecutter_actor}}
{tag {tag _ai_at_launcher_30}}
{tag {tag _ai_at_launcher_40}}
{tag {tag _ai_at_launcher_50}}
{tag {tag _ai_at_launcher_60}}
{tag {tag _ai_at_launcher_70}}
{tag {tag _ai_at_launcher_80}}
{tag {tag _ai_at_launcher_90}}
{tag {tag _ufb_suppress_actor_%team}}
{with_item {type using} {item "rocketlauncher"}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_combat_at_cooldown}}}
}}
{enemy {source advanced}
{ignore_captured_by_user 0}
{group {select {tag {tag _ufb_combat_at_target_%team}}} {include {team {team %foe}}
{state {state operatable}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop airborne}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}}}}}
{distance {mode in_range} {min 12} {max 16}}
{detection visible}}
   {"2.near" {units {ignore_captured_by_user 0} {tag _ufb_combat_at_target_%team}}
{near_to {source advanced} {ignore_captured_by_user 0} {group {select {prop {prop human}}} {include {team {team %team}} {state {state operatable}}} {exclude {state {state dead}}}}}
{distance 12}}
   
  }}
  {actions
   {"con" {text "[UFB combat] at order: team %team"}}
   {"effect" {selector {source advanced}
{ignore_captured_by_user 1}
{group
 {select {tag {tag _ufb_combat_at_actor_%team}}}
 {include {team {team %team}}
{prop {prop human}}
{state {state operatable}}
{state {state user_control}}
{with_item {type amount} {item "at"} {min 1}}}
 {exclude {state {state dead}}
{state {state inactive}}
{state {state linked}}
{prop {prop crew}}
{prop {prop repairing}}
{prop {prop throwing}}
{tag {tag _lua_mi}}
{tag {tag _lua_ignore}}
{tag {tag _ai_do_not_disturb}}
{tag {tag repairing}}
{tag {tag bleeding}}
{tag {tag _bleeding}}
{tag {tag wounded}}
{tag {tag _bleedout_}}
{tag {tag wounded_animation_playing}}
{tag {tag medic}}
{tag {tag _ai_medic}}
{tag {tag bot_medic}}
{tag {tag _ufb_healing_active}}
{tag {tag _ufb_autonomy_moving}}
{tag {tag _ai_wounded_carrier}}
{tag {tag _ai_ap_grenade}}
{tag {tag _ai_at_grenade}}
{tag {tag _ai_smoke_grenade}}
{tag {tag _ai_suppressed_by_mg}}
{tag {tag _ai_mgunner}}
{tag {tag _ai_reloading}}
{tag {tag _ai_looting_weapon}}
{tag {tag crew}}
{tag {tag tcrew}}
{tag {tag ecrew}}
{tag {tag ecrew_a}}
{tag {tag ecrew_b}}
{tag {tag bot_arty}}
{tag {tag bot_aa_guard}}
{tag {tag _ufb_crew_safe}}
{tag {tag _ufb_hf_cover_active}}
{tag {tag _ai_wirecutter_in_action}}
{tag {tag bot_inf_flank_in_progress}}
{tag {tag _ufb_smoke_120m_actor}}
{tag {tag _ufb_smoke_60m_actor}}
{tag {tag _ufb_smoke_wirecutter_actor}}
{tag {tag _ai_at_launcher_30}}
{tag {tag _ai_at_launcher_40}}
{tag {tag _ai_at_launcher_50}}
{tag {tag _ai_at_launcher_60}}
{tag {tag _ai_at_launcher_70}}
{tag {tag _ai_at_launcher_80}}
{tag {tag _ai_at_launcher_90}}
{tag {tag _ufb_suppress_actor_%team}}
{with_item {type using} {item "rocketlauncher"}}}
}} {effect ufb_combat_at_cooldown}}
{"action" {selector {source advanced}
{ignore_captured_by_user 1}
{group
 {select {tag {tag _ufb_combat_at_actor_%team}}}
 {include {team {team %team}}
{prop {prop human}}
{state {state operatable}}
{state {state user_control}}
{with_item {type amount} {item "at"} {min 1}}}
 {exclude {state {state dead}}
{state {state inactive}}
{state {state linked}}
{prop {prop crew}}
{prop {prop repairing}}
{prop {prop throwing}}
{tag {tag _lua_mi}}
{tag {tag _lua_ignore}}
{tag {tag _ai_do_not_disturb}}
{tag {tag repairing}}
{tag {tag bleeding}}
{tag {tag _bleeding}}
{tag {tag wounded}}
{tag {tag _bleedout_}}
{tag {tag wounded_animation_playing}}
{tag {tag medic}}
{tag {tag _ai_medic}}
{tag {tag bot_medic}}
{tag {tag _ufb_healing_active}}
{tag {tag _ufb_autonomy_moving}}
{tag {tag _ai_wounded_carrier}}
{tag {tag _ai_ap_grenade}}
{tag {tag _ai_at_grenade}}
{tag {tag _ai_smoke_grenade}}
{tag {tag _ai_suppressed_by_mg}}
{tag {tag _ai_mgunner}}
{tag {tag _ai_reloading}}
{tag {tag _ai_looting_weapon}}
{tag {tag crew}}
{tag {tag tcrew}}
{tag {tag ecrew}}
{tag {tag ecrew_a}}
{tag {tag ecrew_b}}
{tag {tag bot_arty}}
{tag {tag bot_aa_guard}}
{tag {tag _ufb_crew_safe}}
{tag {tag _ufb_hf_cover_active}}
{tag {tag _ai_wirecutter_in_action}}
{tag {tag bot_inf_flank_in_progress}}
{tag {tag _ufb_smoke_120m_actor}}
{tag {tag _ufb_smoke_60m_actor}}
{tag {tag _ufb_smoke_wirecutter_actor}}
{tag {tag _ai_at_launcher_30}}
{tag {tag _ai_at_launcher_40}}
{tag {tag _ai_at_launcher_50}}
{tag {tag _ai_at_launcher_60}}
{tag {tag _ai_at_launcher_70}}
{tag {tag _ai_at_launcher_80}}
{tag {tag _ai_at_launcher_90}}
{tag {tag _ufb_suppress_actor_%team}}
{with_item {type using} {item "rocketlauncher"}}}
}
{amount 1}} {action throw_at_grenade} {target {ignore_captured_by_user 0} {tag _ufb_combat_at_target_%team}}}
   {"delay" {time 1}}
   {"trigger" {name "ufb/combat/at/apply %team"}}
  }
 }
)

; launcher: one reserved pair per player; no drop-orders or fire-mode changes.
(define "ufb_combat_launcher"
 {"ufb/combat/launcher/acquire %team"
  {condition {terms {"1.see_actors" {selector {source advanced}
{ignore_captured_by_user 1}
{group
 {select {prop {prop human}}}
 {include {team {team %team}}
{prop {prop human}}
{state {state operatable}}
{state {state user_control}}
{prop {prop shooting}}
{with_item {type amount} {item "rocketlauncher"} {min 1}}}
 {exclude {state {state dead}}
{state {state inactive}}
{state {state linked}}
{prop {prop crew}}
{prop {prop repairing}}
{prop {prop throwing}}
{tag {tag _lua_mi}}
{tag {tag _lua_ignore}}
{tag {tag _ai_do_not_disturb}}
{tag {tag repairing}}
{tag {tag bleeding}}
{tag {tag _bleeding}}
{tag {tag wounded}}
{tag {tag _bleedout_}}
{tag {tag wounded_animation_playing}}
{tag {tag medic}}
{tag {tag _ai_medic}}
{tag {tag bot_medic}}
{tag {tag _ufb_healing_active}}
{tag {tag _ufb_autonomy_moving}}
{tag {tag _ai_wounded_carrier}}
{tag {tag _ai_ap_grenade}}
{tag {tag _ai_at_grenade}}
{tag {tag _ai_smoke_grenade}}
{tag {tag _ai_suppressed_by_mg}}
{tag {tag _ai_mgunner}}
{tag {tag _ai_reloading}}
{tag {tag _ai_looting_weapon}}
{tag {tag crew}}
{tag {tag tcrew}}
{tag {tag ecrew}}
{tag {tag ecrew_a}}
{tag {tag ecrew_b}}
{tag {tag bot_arty}}
{tag {tag bot_aa_guard}}
{tag {tag _ufb_crew_safe}}
{tag {tag _ufb_hf_cover_active}}
{tag {tag _ai_wirecutter_in_action}}
{tag {tag bot_inf_flank_in_progress}}
{tag {tag _ufb_smoke_120m_actor}}
{tag {tag _ufb_smoke_60m_actor}}
{tag {tag _ufb_smoke_wirecutter_actor}}
{tag {tag _ai_at_launcher_30}}
{tag {tag _ai_at_launcher_40}}
{tag {tag _ai_at_launcher_50}}
{tag {tag _ai_at_launcher_60}}
{tag {tag _ai_at_launcher_70}}
{tag {tag _ai_at_launcher_80}}
{tag {tag _ai_at_launcher_90}}
{tag {tag _ufb_suppress_actor_%team}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_combat_launcher_cooldown}}
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_launcher_actor_%team}}
{tag {tag _ufb_combat_at_actor_%team}}
{tag {tag _ufb_combat_critical_actor_%team}}
{tag {tag _ufb_combat_ap_actor_%team}}
{tag {tag _ufb_combat_smoke_actor_%team}}}
}}
{enemy {source advanced}
{ignore_captured_by_user 0}
{group {select {prop {prop vehicle}} {prop {prop tank}} {prop {prop car}} {prop {prop cannon}}} {include {team {team %foe}}
{state {state operatable}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop airborne}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}}}}}
{distance {mode in_range} {min 18} {max 25}}
{detection visible}
{tag {"tag pair"} {"for selector" _ufb_combat_launcher_pick_%team} {"for enemy" _ufb_combat_launcher_target_%team}}}}}
  {actions
   {"entity_state" {selector {amount 1} {ignore_captured_by_user 0} {tag _ufb_combat_launcher_pick_%team}} {tag_add _ufb_combat_launcher_actor_%team}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_combat_launcher_pick_%team}} {tag_remove _ufb_combat_launcher_pick_%team}}
   {"effect" {selector {ignore_captured_by_user 0} {tag _ufb_combat_launcher_actor_%team}} {effect ufb_reserve_job}}
   
   {"delay" {time 6}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_combat_launcher_actor_%team}} {tag_remove _ufb_combat_launcher_actor_%team}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_combat_launcher_target_%team}} {tag_remove _ufb_combat_launcher_target_%team}}
   {"delay" {time 2}}
   {"trigger" {name "ufb/combat/launcher/acquire %team"}}
  }
 }
 {"ufb/combat/launcher/apply %team"
  {condition {expression "1 & !2"} {terms
   {"1.see_actors" {selector {source advanced}
{ignore_captured_by_user 1}
{group
 {select {tag {tag _ufb_combat_launcher_actor_%team}}}
 {include {team {team %team}}
{prop {prop human}}
{state {state operatable}}
{state {state user_control}}
{prop {prop shooting}}
{with_item {type amount} {item "rocketlauncher"} {min 1}}}
 {exclude {state {state dead}}
{state {state inactive}}
{state {state linked}}
{prop {prop crew}}
{prop {prop repairing}}
{prop {prop throwing}}
{tag {tag _lua_mi}}
{tag {tag _lua_ignore}}
{tag {tag _ai_do_not_disturb}}
{tag {tag repairing}}
{tag {tag bleeding}}
{tag {tag _bleeding}}
{tag {tag wounded}}
{tag {tag _bleedout_}}
{tag {tag wounded_animation_playing}}
{tag {tag medic}}
{tag {tag _ai_medic}}
{tag {tag bot_medic}}
{tag {tag _ufb_healing_active}}
{tag {tag _ufb_autonomy_moving}}
{tag {tag _ai_wounded_carrier}}
{tag {tag _ai_ap_grenade}}
{tag {tag _ai_at_grenade}}
{tag {tag _ai_smoke_grenade}}
{tag {tag _ai_suppressed_by_mg}}
{tag {tag _ai_mgunner}}
{tag {tag _ai_reloading}}
{tag {tag _ai_looting_weapon}}
{tag {tag crew}}
{tag {tag tcrew}}
{tag {tag ecrew}}
{tag {tag ecrew_a}}
{tag {tag ecrew_b}}
{tag {tag bot_arty}}
{tag {tag bot_aa_guard}}
{tag {tag _ufb_crew_safe}}
{tag {tag _ufb_hf_cover_active}}
{tag {tag _ai_wirecutter_in_action}}
{tag {tag bot_inf_flank_in_progress}}
{tag {tag _ufb_smoke_120m_actor}}
{tag {tag _ufb_smoke_60m_actor}}
{tag {tag _ufb_smoke_wirecutter_actor}}
{tag {tag _ai_at_launcher_30}}
{tag {tag _ai_at_launcher_40}}
{tag {tag _ai_at_launcher_50}}
{tag {tag _ai_at_launcher_60}}
{tag {tag _ai_at_launcher_70}}
{tag {tag _ai_at_launcher_80}}
{tag {tag _ai_at_launcher_90}}
{tag {tag _ufb_suppress_actor_%team}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_combat_launcher_cooldown}}}
}}
{enemy {source advanced}
{ignore_captured_by_user 0}
{group {select {tag {tag _ufb_combat_launcher_target_%team}}} {include {team {team %foe}}
{state {state operatable}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop airborne}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}}}}}
{distance {mode in_range} {min 18} {max 25}}
{detection visible}}
   {"2.near" {units {ignore_captured_by_user 0} {tag _ufb_combat_launcher_target_%team}}
{near_to {source advanced} {ignore_captured_by_user 0} {group {select {prop {prop human}}} {include {team {team %team}} {state {state operatable}}} {exclude {state {state dead}}}}}
{distance 12}}
   
  }}
  {actions
   {"con" {text "[UFB combat] launcher order: team %team"}}
   {"effect" {selector {source advanced}
{ignore_captured_by_user 1}
{group
 {select {tag {tag _ufb_combat_launcher_actor_%team}}}
 {include {team {team %team}}
{prop {prop human}}
{state {state operatable}}
{state {state user_control}}
{with_item {type amount} {item "rocketlauncher"} {min 1}}}
 {exclude {state {state dead}}
{state {state inactive}}
{state {state linked}}
{prop {prop crew}}
{prop {prop repairing}}
{prop {prop throwing}}
{tag {tag _lua_mi}}
{tag {tag _lua_ignore}}
{tag {tag _ai_do_not_disturb}}
{tag {tag repairing}}
{tag {tag bleeding}}
{tag {tag _bleeding}}
{tag {tag wounded}}
{tag {tag _bleedout_}}
{tag {tag wounded_animation_playing}}
{tag {tag medic}}
{tag {tag _ai_medic}}
{tag {tag bot_medic}}
{tag {tag _ufb_healing_active}}
{tag {tag _ufb_autonomy_moving}}
{tag {tag _ai_wounded_carrier}}
{tag {tag _ai_ap_grenade}}
{tag {tag _ai_at_grenade}}
{tag {tag _ai_smoke_grenade}}
{tag {tag _ai_suppressed_by_mg}}
{tag {tag _ai_mgunner}}
{tag {tag _ai_reloading}}
{tag {tag _ai_looting_weapon}}
{tag {tag crew}}
{tag {tag tcrew}}
{tag {tag ecrew}}
{tag {tag ecrew_a}}
{tag {tag ecrew_b}}
{tag {tag bot_arty}}
{tag {tag bot_aa_guard}}
{tag {tag _ufb_crew_safe}}
{tag {tag _ufb_hf_cover_active}}
{tag {tag _ai_wirecutter_in_action}}
{tag {tag bot_inf_flank_in_progress}}
{tag {tag _ufb_smoke_120m_actor}}
{tag {tag _ufb_smoke_60m_actor}}
{tag {tag _ufb_smoke_wirecutter_actor}}
{tag {tag _ai_at_launcher_30}}
{tag {tag _ai_at_launcher_40}}
{tag {tag _ai_at_launcher_50}}
{tag {tag _ai_at_launcher_60}}
{tag {tag _ai_at_launcher_70}}
{tag {tag _ai_at_launcher_80}}
{tag {tag _ai_at_launcher_90}}
{tag {tag _ufb_suppress_actor_%team}}}
}} {effect ufb_combat_launcher_cooldown}}
{"action" {selector {source advanced}
{ignore_captured_by_user 1}
{group
 {select {tag {tag _ufb_combat_launcher_actor_%team}}}
 {include {team {team %team}}
{prop {prop human}}
{state {state operatable}}
{state {state user_control}}
{with_item {type amount} {item "rocketlauncher"} {min 1}}}
 {exclude {state {state dead}}
{state {state inactive}}
{state {state linked}}
{prop {prop crew}}
{prop {prop repairing}}
{prop {prop throwing}}
{tag {tag _lua_mi}}
{tag {tag _lua_ignore}}
{tag {tag _ai_do_not_disturb}}
{tag {tag repairing}}
{tag {tag bleeding}}
{tag {tag _bleeding}}
{tag {tag wounded}}
{tag {tag _bleedout_}}
{tag {tag wounded_animation_playing}}
{tag {tag medic}}
{tag {tag _ai_medic}}
{tag {tag bot_medic}}
{tag {tag _ufb_healing_active}}
{tag {tag _ufb_autonomy_moving}}
{tag {tag _ai_wounded_carrier}}
{tag {tag _ai_ap_grenade}}
{tag {tag _ai_at_grenade}}
{tag {tag _ai_smoke_grenade}}
{tag {tag _ai_suppressed_by_mg}}
{tag {tag _ai_mgunner}}
{tag {tag _ai_reloading}}
{tag {tag _ai_looting_weapon}}
{tag {tag crew}}
{tag {tag tcrew}}
{tag {tag ecrew}}
{tag {tag ecrew_a}}
{tag {tag ecrew_b}}
{tag {tag bot_arty}}
{tag {tag bot_aa_guard}}
{tag {tag _ufb_crew_safe}}
{tag {tag _ufb_hf_cover_active}}
{tag {tag _ai_wirecutter_in_action}}
{tag {tag bot_inf_flank_in_progress}}
{tag {tag _ufb_smoke_120m_actor}}
{tag {tag _ufb_smoke_60m_actor}}
{tag {tag _ufb_smoke_wirecutter_actor}}
{tag {tag _ai_at_launcher_30}}
{tag {tag _ai_at_launcher_40}}
{tag {tag _ai_at_launcher_50}}
{tag {tag _ai_at_launcher_60}}
{tag {tag _ai_at_launcher_70}}
{tag {tag _ai_at_launcher_80}}
{tag {tag _ai_at_launcher_90}}
{tag {tag _ufb_suppress_actor_%team}}}
}
{amount 1}} {action bazooka_shot} {target {ignore_captured_by_user 0} {tag _ufb_combat_launcher_target_%team}}}
   {"delay" {time 1}}
   {"trigger" {name "ufb/combat/launcher/apply %team"}}
  }
 }
)

; critical: one reserved pair per player; no drop-orders or fire-mode changes.
(define "ufb_combat_critical"
 {"ufb/combat/critical/acquire %team"
  {condition {terms {"1.see_actors" {selector {source advanced}
{ignore_captured_by_user 1}
{group
 {select {tag {tag _ufb_recent_hit}}}
 {include {team {team %team}}
{prop {prop human}}
{state {state operatable}}
{prop {prop shooting}}
{with_item {type amount} {item "rocketlauncher"} {min 1}}}
 {exclude {state {state dead}}
{state {state inactive}}
{state {state linked}}
{prop {prop crew}}
{prop {prop repairing}}
{prop {prop throwing}}
{tag {tag _lua_mi}}
{tag {tag _lua_ignore}}
{tag {tag _ai_do_not_disturb}}
{tag {tag repairing}}
{tag {tag reloading}}
{tag {tag bleeding}}
{tag {tag _bleeding}}
{tag {tag wounded}}
{tag {tag _bleedout_}}
{tag {tag wounded_animation_playing}}
{tag {tag medic}}
{tag {tag _ai_medic}}
{tag {tag bot_medic}}
{tag {tag _ufb_healing_active}}
{tag {tag _ufb_autonomy_moving}}
{tag {tag _ai_wounded_carrier}}
{tag {tag _ai_ap_grenade}}
{tag {tag _ai_at_grenade}}
{tag {tag _ai_smoke_grenade}}
{tag {tag _ai_suppressed_by_mg}}
{tag {tag _ai_mgunner}}
{tag {tag _ai_reloading}}
{tag {tag _ai_looting_weapon}}
{tag {tag crew}}
{tag {tag tcrew}}
{tag {tag ecrew}}
{tag {tag ecrew_a}}
{tag {tag ecrew_b}}
{tag {tag bot_arty}}
{tag {tag bot_aa_guard}}
{tag {tag _ufb_crew_safe}}
{tag {tag _ufb_hf_cover_active}}
{tag {tag _ai_wirecutter_in_action}}
{tag {tag bot_inf_flank_in_progress}}
{tag {tag _ufb_smoke_120m_actor}}
{tag {tag _ufb_smoke_60m_actor}}
{tag {tag _ufb_smoke_wirecutter_actor}}
{tag {tag _ai_at_launcher_30}}
{tag {tag _ai_at_launcher_40}}
{tag {tag _ai_at_launcher_50}}
{tag {tag _ai_at_launcher_60}}
{tag {tag _ai_at_launcher_70}}
{tag {tag _ai_at_launcher_80}}
{tag {tag _ai_at_launcher_90}}
{tag {tag _ufb_suppress_actor_%team}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_combat_critical_cooldown}}
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_launcher_actor_%team}}
{tag {tag _ufb_combat_at_actor_%team}}
{tag {tag _ufb_combat_critical_actor_%team}}
{tag {tag _ufb_combat_ap_actor_%team}}
{tag {tag _ufb_combat_smoke_actor_%team}}}
}}
{enemy {source advanced}
{ignore_captured_by_user 0}
{group {select {prop {prop human}}} {include {team {team %foe}}
{state {state operatable}}
{with_item {type using} {item "mgun"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop airborne}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}}}}}
{distance {mode in_range} {min 18} {max 25}}
{detection visible}
{tag {"tag pair"} {"for selector" _ufb_combat_critical_pick_%team} {"for enemy" _ufb_combat_critical_target_%team}}}}}
  {actions
   {"entity_state" {selector {amount 1} {ignore_captured_by_user 0} {tag _ufb_combat_critical_pick_%team}} {tag_add _ufb_combat_critical_actor_%team}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_combat_critical_pick_%team}} {tag_remove _ufb_combat_critical_pick_%team}}
   {"effect" {selector {ignore_captured_by_user 0} {tag _ufb_combat_critical_actor_%team}} {effect ufb_reserve_job}}
   {"effect" {selector {ignore_captured_by_user 0} {tag _ufb_combat_critical_target_%team}} {effect ufb_combat_probe_cover_%team}}
   {"delay" {time 6}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_combat_critical_actor_%team}} {tag_remove _ufb_combat_critical_actor_%team}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_combat_critical_target_%team}} {tag_remove _ufb_combat_critical_target_%team}}
   {"delay" {time 2}}
   {"trigger" {name "ufb/combat/critical/acquire %team"}}
  }
 }
 {"ufb/combat/critical/apply %team"
  {condition {expression "1 & !2 & !3"} {terms
   {"1.see_actors" {selector {source advanced}
{ignore_captured_by_user 1}
{group
 {select {tag {tag _ufb_combat_critical_actor_%team}}}
 {include {team {team %team}}
{prop {prop human}}
{state {state operatable}}
{prop {prop shooting}}
{with_item {type amount} {item "rocketlauncher"} {min 1}}}
 {exclude {state {state dead}}
{state {state inactive}}
{state {state linked}}
{prop {prop crew}}
{prop {prop repairing}}
{prop {prop throwing}}
{tag {tag _lua_mi}}
{tag {tag _lua_ignore}}
{tag {tag _ai_do_not_disturb}}
{tag {tag repairing}}
{tag {tag reloading}}
{tag {tag bleeding}}
{tag {tag _bleeding}}
{tag {tag wounded}}
{tag {tag _bleedout_}}
{tag {tag wounded_animation_playing}}
{tag {tag medic}}
{tag {tag _ai_medic}}
{tag {tag bot_medic}}
{tag {tag _ufb_healing_active}}
{tag {tag _ufb_autonomy_moving}}
{tag {tag _ai_wounded_carrier}}
{tag {tag _ai_ap_grenade}}
{tag {tag _ai_at_grenade}}
{tag {tag _ai_smoke_grenade}}
{tag {tag _ai_suppressed_by_mg}}
{tag {tag _ai_mgunner}}
{tag {tag _ai_reloading}}
{tag {tag _ai_looting_weapon}}
{tag {tag crew}}
{tag {tag tcrew}}
{tag {tag ecrew}}
{tag {tag ecrew_a}}
{tag {tag ecrew_b}}
{tag {tag bot_arty}}
{tag {tag bot_aa_guard}}
{tag {tag _ufb_crew_safe}}
{tag {tag _ufb_hf_cover_active}}
{tag {tag _ai_wirecutter_in_action}}
{tag {tag bot_inf_flank_in_progress}}
{tag {tag _ufb_smoke_120m_actor}}
{tag {tag _ufb_smoke_60m_actor}}
{tag {tag _ufb_smoke_wirecutter_actor}}
{tag {tag _ai_at_launcher_30}}
{tag {tag _ai_at_launcher_40}}
{tag {tag _ai_at_launcher_50}}
{tag {tag _ai_at_launcher_60}}
{tag {tag _ai_at_launcher_70}}
{tag {tag _ai_at_launcher_80}}
{tag {tag _ai_at_launcher_90}}
{tag {tag _ufb_suppress_actor_%team}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_combat_critical_cooldown}}}
}}
{enemy {source advanced}
{ignore_captured_by_user 0}
{group {select {tag {tag _ufb_combat_critical_target_%team}}} {include {team {team %foe}}
{state {state operatable}}
{with_item {type using} {item "mgun"}}
{tag {tag _ufb_combat_cover_%team}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop airborne}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}}}}}
{distance {mode in_range} {min 18} {max 25}}
{detection visible}}
   {"2.near" {units {ignore_captured_by_user 0} {tag _ufb_combat_critical_target_%team}}
{near_to {source advanced} {ignore_captured_by_user 0} {group {select {prop {prop human}}} {include {team {team %team}} {state {state operatable}}} {exclude {state {state dead}}}}}
{distance 12}}
   {"3.see_actors" {selector {source advanced}
{ignore_captured_by_user 1}
{group
 {select {tag {tag _ufb_combat_critical_actor_%team}}}
 {include {team {team %team}}
{prop {prop human}}
{state {state operatable}}
{prop {prop shooting}}
{with_item {type amount} {item "rocketlauncher"} {min 1}}}
 {exclude {state {state dead}}
{state {state inactive}}
{state {state linked}}
{prop {prop crew}}
{prop {prop repairing}}
{prop {prop throwing}}
{tag {tag _lua_mi}}
{tag {tag _lua_ignore}}
{tag {tag _ai_do_not_disturb}}
{tag {tag repairing}}
{tag {tag reloading}}
{tag {tag bleeding}}
{tag {tag _bleeding}}
{tag {tag wounded}}
{tag {tag _bleedout_}}
{tag {tag wounded_animation_playing}}
{tag {tag medic}}
{tag {tag _ai_medic}}
{tag {tag bot_medic}}
{tag {tag _ufb_healing_active}}
{tag {tag _ufb_autonomy_moving}}
{tag {tag _ai_wounded_carrier}}
{tag {tag _ai_ap_grenade}}
{tag {tag _ai_at_grenade}}
{tag {tag _ai_smoke_grenade}}
{tag {tag _ai_suppressed_by_mg}}
{tag {tag _ai_mgunner}}
{tag {tag _ai_reloading}}
{tag {tag _ai_looting_weapon}}
{tag {tag crew}}
{tag {tag tcrew}}
{tag {tag ecrew}}
{tag {tag ecrew_a}}
{tag {tag ecrew_b}}
{tag {tag bot_arty}}
{tag {tag bot_aa_guard}}
{tag {tag _ufb_crew_safe}}
{tag {tag _ufb_hf_cover_active}}
{tag {tag _ai_wirecutter_in_action}}
{tag {tag bot_inf_flank_in_progress}}
{tag {tag _ufb_smoke_120m_actor}}
{tag {tag _ufb_smoke_60m_actor}}
{tag {tag _ufb_smoke_wirecutter_actor}}
{tag {tag _ai_at_launcher_30}}
{tag {tag _ai_at_launcher_40}}
{tag {tag _ai_at_launcher_50}}
{tag {tag _ai_at_launcher_60}}
{tag {tag _ai_at_launcher_70}}
{tag {tag _ai_at_launcher_80}}
{tag {tag _ai_at_launcher_90}}
{tag {tag _ufb_suppress_actor_%team}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_combat_critical_cooldown}}}
}}
{enemy {source advanced}
{ignore_captured_by_user 0}
{group {select {prop {prop vehicle}} {prop {prop tank}} {prop {prop car}} {prop {prop cannon}}} {include {team {team %foe}}
{state {state operatable}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop airborne}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}}}}}
{distance {mode in_range} {min 0} {max 110}}
{detection visible}}
  }}
  {actions
   {"con" {text "[UFB combat] critical order: team %team"}}
   {"effect" {selector {source advanced}
{ignore_captured_by_user 1}
{group
 {select {tag {tag _ufb_combat_critical_actor_%team}}}
 {include {team {team %team}}
{prop {prop human}}
{state {state operatable}}
{with_item {type amount} {item "rocketlauncher"} {min 1}}}
 {exclude {state {state dead}}
{state {state inactive}}
{state {state linked}}
{prop {prop crew}}
{prop {prop repairing}}
{prop {prop throwing}}
{tag {tag _lua_mi}}
{tag {tag _lua_ignore}}
{tag {tag _ai_do_not_disturb}}
{tag {tag repairing}}
{tag {tag reloading}}
{tag {tag bleeding}}
{tag {tag _bleeding}}
{tag {tag wounded}}
{tag {tag _bleedout_}}
{tag {tag wounded_animation_playing}}
{tag {tag medic}}
{tag {tag _ai_medic}}
{tag {tag bot_medic}}
{tag {tag _ufb_healing_active}}
{tag {tag _ufb_autonomy_moving}}
{tag {tag _ai_wounded_carrier}}
{tag {tag _ai_ap_grenade}}
{tag {tag _ai_at_grenade}}
{tag {tag _ai_smoke_grenade}}
{tag {tag _ai_suppressed_by_mg}}
{tag {tag _ai_mgunner}}
{tag {tag _ai_reloading}}
{tag {tag _ai_looting_weapon}}
{tag {tag crew}}
{tag {tag tcrew}}
{tag {tag ecrew}}
{tag {tag ecrew_a}}
{tag {tag ecrew_b}}
{tag {tag bot_arty}}
{tag {tag bot_aa_guard}}
{tag {tag _ufb_crew_safe}}
{tag {tag _ufb_hf_cover_active}}
{tag {tag _ai_wirecutter_in_action}}
{tag {tag bot_inf_flank_in_progress}}
{tag {tag _ufb_smoke_120m_actor}}
{tag {tag _ufb_smoke_60m_actor}}
{tag {tag _ufb_smoke_wirecutter_actor}}
{tag {tag _ai_at_launcher_30}}
{tag {tag _ai_at_launcher_40}}
{tag {tag _ai_at_launcher_50}}
{tag {tag _ai_at_launcher_60}}
{tag {tag _ai_at_launcher_70}}
{tag {tag _ai_at_launcher_80}}
{tag {tag _ai_at_launcher_90}}
{tag {tag _ufb_suppress_actor_%team}}}
}} {effect ufb_combat_critical_cooldown}}
{"action" {selector {source advanced}
{ignore_captured_by_user 1}
{group
 {select {tag {tag _ufb_combat_critical_actor_%team}}}
 {include {team {team %team}}
{prop {prop human}}
{state {state operatable}}
{with_item {type amount} {item "rocketlauncher"} {min 1}}}
 {exclude {state {state dead}}
{state {state inactive}}
{state {state linked}}
{prop {prop crew}}
{prop {prop repairing}}
{prop {prop throwing}}
{tag {tag _lua_mi}}
{tag {tag _lua_ignore}}
{tag {tag _ai_do_not_disturb}}
{tag {tag repairing}}
{tag {tag reloading}}
{tag {tag bleeding}}
{tag {tag _bleeding}}
{tag {tag wounded}}
{tag {tag _bleedout_}}
{tag {tag wounded_animation_playing}}
{tag {tag medic}}
{tag {tag _ai_medic}}
{tag {tag bot_medic}}
{tag {tag _ufb_healing_active}}
{tag {tag _ufb_autonomy_moving}}
{tag {tag _ai_wounded_carrier}}
{tag {tag _ai_ap_grenade}}
{tag {tag _ai_at_grenade}}
{tag {tag _ai_smoke_grenade}}
{tag {tag _ai_suppressed_by_mg}}
{tag {tag _ai_mgunner}}
{tag {tag _ai_reloading}}
{tag {tag _ai_looting_weapon}}
{tag {tag crew}}
{tag {tag tcrew}}
{tag {tag ecrew}}
{tag {tag ecrew_a}}
{tag {tag ecrew_b}}
{tag {tag bot_arty}}
{tag {tag bot_aa_guard}}
{tag {tag _ufb_crew_safe}}
{tag {tag _ufb_hf_cover_active}}
{tag {tag _ai_wirecutter_in_action}}
{tag {tag bot_inf_flank_in_progress}}
{tag {tag _ufb_smoke_120m_actor}}
{tag {tag _ufb_smoke_60m_actor}}
{tag {tag _ufb_smoke_wirecutter_actor}}
{tag {tag _ai_at_launcher_30}}
{tag {tag _ai_at_launcher_40}}
{tag {tag _ai_at_launcher_50}}
{tag {tag _ai_at_launcher_60}}
{tag {tag _ai_at_launcher_70}}
{tag {tag _ai_at_launcher_80}}
{tag {tag _ai_at_launcher_90}}
{tag {tag _ufb_suppress_actor_%team}}}
}
{amount 1}} {action bazooka_shot} {target {ignore_captured_by_user 0} {tag _ufb_combat_critical_target_%team}}}
   {"delay" {time 1}}
   {"trigger" {name "ufb/combat/critical/apply %team"}}
  }
 }
)

; ap: one reserved pair per player; no drop-orders or fire-mode changes.
(define "ufb_combat_ap"
 {"ufb/combat/ap/acquire %team"
  {condition {terms {"1.see_actors" {selector {source advanced}
{ignore_captured_by_user 1}
{group
 {select {prop {prop human}}}
 {include {team {team %team}}
{prop {prop human}}
{state {state operatable}}
{state {state user_control}}
{prop {prop shooting}}
{with_item {type amount} {item "fg"} {min 1}}}
 {exclude {state {state dead}}
{state {state inactive}}
{state {state linked}}
{prop {prop crew}}
{prop {prop repairing}}
{prop {prop throwing}}
{tag {tag _lua_mi}}
{tag {tag _lua_ignore}}
{tag {tag _ai_do_not_disturb}}
{tag {tag repairing}}
{tag {tag bleeding}}
{tag {tag _bleeding}}
{tag {tag wounded}}
{tag {tag _bleedout_}}
{tag {tag wounded_animation_playing}}
{tag {tag medic}}
{tag {tag _ai_medic}}
{tag {tag bot_medic}}
{tag {tag _ufb_healing_active}}
{tag {tag _ufb_autonomy_moving}}
{tag {tag _ai_wounded_carrier}}
{tag {tag _ai_ap_grenade}}
{tag {tag _ai_at_grenade}}
{tag {tag _ai_smoke_grenade}}
{tag {tag _ai_suppressed_by_mg}}
{tag {tag _ai_mgunner}}
{tag {tag _ai_reloading}}
{tag {tag _ai_looting_weapon}}
{tag {tag crew}}
{tag {tag tcrew}}
{tag {tag ecrew}}
{tag {tag ecrew_a}}
{tag {tag ecrew_b}}
{tag {tag bot_arty}}
{tag {tag bot_aa_guard}}
{tag {tag _ufb_crew_safe}}
{tag {tag _ufb_hf_cover_active}}
{tag {tag _ai_wirecutter_in_action}}
{tag {tag bot_inf_flank_in_progress}}
{tag {tag _ufb_smoke_120m_actor}}
{tag {tag _ufb_smoke_60m_actor}}
{tag {tag _ufb_smoke_wirecutter_actor}}
{tag {tag _ai_at_launcher_30}}
{tag {tag _ai_at_launcher_40}}
{tag {tag _ai_at_launcher_50}}
{tag {tag _ai_at_launcher_60}}
{tag {tag _ai_at_launcher_70}}
{tag {tag _ai_at_launcher_80}}
{tag {tag _ai_at_launcher_90}}
{tag {tag _ufb_suppress_actor_%team}}
{with_item {type using} {item "rocketlauncher"}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_combat_ap_cooldown}}
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_launcher_actor_%team}}
{tag {tag _ufb_combat_at_actor_%team}}
{tag {tag _ufb_combat_critical_actor_%team}}
{tag {tag _ufb_combat_ap_actor_%team}}
{tag {tag _ufb_combat_smoke_actor_%team}}}
}}
{enemy {source advanced}
{ignore_captured_by_user 0}
{group {select {prop {prop human}}} {include {team {team %foe}}
{state {state operatable}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop airborne}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}}}}}
{distance {mode in_range} {min 14} {max 20}}
{detection visible}
{tag {"tag pair"} {"for selector" _ufb_combat_ap_pick_%team} {"for enemy" _ufb_combat_ap_target_%team}}}}}
  {actions
   {"entity_state" {selector {amount 1} {ignore_captured_by_user 0} {tag _ufb_combat_ap_pick_%team}} {tag_add _ufb_combat_ap_actor_%team}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_combat_ap_pick_%team}} {tag_remove _ufb_combat_ap_pick_%team}}
   {"effect" {selector {ignore_captured_by_user 0} {tag _ufb_combat_ap_actor_%team}} {effect ufb_reserve_job}}
   
   {"delay" {time 6}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_combat_ap_actor_%team}} {tag_remove _ufb_combat_ap_actor_%team}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_combat_ap_target_%team}} {tag_remove _ufb_combat_ap_target_%team}}
   {"delay" {time 2}}
   {"trigger" {name "ufb/combat/ap/acquire %team"}}
  }
 }
 {"ufb/combat/ap/apply %team"
  {condition {expression "1 & !2"} {terms
   {"1.see_actors" {selector {source advanced}
{ignore_captured_by_user 1}
{group
 {select {tag {tag _ufb_combat_ap_actor_%team}}}
 {include {team {team %team}}
{prop {prop human}}
{state {state operatable}}
{state {state user_control}}
{prop {prop shooting}}
{with_item {type amount} {item "fg"} {min 1}}}
 {exclude {state {state dead}}
{state {state inactive}}
{state {state linked}}
{prop {prop crew}}
{prop {prop repairing}}
{prop {prop throwing}}
{tag {tag _lua_mi}}
{tag {tag _lua_ignore}}
{tag {tag _ai_do_not_disturb}}
{tag {tag repairing}}
{tag {tag bleeding}}
{tag {tag _bleeding}}
{tag {tag wounded}}
{tag {tag _bleedout_}}
{tag {tag wounded_animation_playing}}
{tag {tag medic}}
{tag {tag _ai_medic}}
{tag {tag bot_medic}}
{tag {tag _ufb_healing_active}}
{tag {tag _ufb_autonomy_moving}}
{tag {tag _ai_wounded_carrier}}
{tag {tag _ai_ap_grenade}}
{tag {tag _ai_at_grenade}}
{tag {tag _ai_smoke_grenade}}
{tag {tag _ai_suppressed_by_mg}}
{tag {tag _ai_mgunner}}
{tag {tag _ai_reloading}}
{tag {tag _ai_looting_weapon}}
{tag {tag crew}}
{tag {tag tcrew}}
{tag {tag ecrew}}
{tag {tag ecrew_a}}
{tag {tag ecrew_b}}
{tag {tag bot_arty}}
{tag {tag bot_aa_guard}}
{tag {tag _ufb_crew_safe}}
{tag {tag _ufb_hf_cover_active}}
{tag {tag _ai_wirecutter_in_action}}
{tag {tag bot_inf_flank_in_progress}}
{tag {tag _ufb_smoke_120m_actor}}
{tag {tag _ufb_smoke_60m_actor}}
{tag {tag _ufb_smoke_wirecutter_actor}}
{tag {tag _ai_at_launcher_30}}
{tag {tag _ai_at_launcher_40}}
{tag {tag _ai_at_launcher_50}}
{tag {tag _ai_at_launcher_60}}
{tag {tag _ai_at_launcher_70}}
{tag {tag _ai_at_launcher_80}}
{tag {tag _ai_at_launcher_90}}
{tag {tag _ufb_suppress_actor_%team}}
{with_item {type using} {item "rocketlauncher"}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_combat_ap_cooldown}}}
}}
{enemy {source advanced}
{ignore_captured_by_user 0}
{group {select {tag {tag _ufb_combat_ap_target_%team}}} {include {team {team %foe}}
{state {state operatable}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop airborne}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}}}}}
{distance {mode in_range} {min 14} {max 20}}
{detection visible}}
   {"2.near" {units {ignore_captured_by_user 0} {tag _ufb_combat_ap_target_%team}}
{near_to {source advanced} {ignore_captured_by_user 0} {group {select {prop {prop human}}} {include {team {team %team}} {state {state operatable}}} {exclude {state {state dead}}}}}
{distance 12}}
   
  }}
  {actions
   {"con" {text "[UFB combat] ap order: team %team"}}
   {"effect" {selector {source advanced}
{ignore_captured_by_user 1}
{group
 {select {tag {tag _ufb_combat_ap_actor_%team}}}
 {include {team {team %team}}
{prop {prop human}}
{state {state operatable}}
{state {state user_control}}
{with_item {type amount} {item "fg"} {min 1}}}
 {exclude {state {state dead}}
{state {state inactive}}
{state {state linked}}
{prop {prop crew}}
{prop {prop repairing}}
{prop {prop throwing}}
{tag {tag _lua_mi}}
{tag {tag _lua_ignore}}
{tag {tag _ai_do_not_disturb}}
{tag {tag repairing}}
{tag {tag bleeding}}
{tag {tag _bleeding}}
{tag {tag wounded}}
{tag {tag _bleedout_}}
{tag {tag wounded_animation_playing}}
{tag {tag medic}}
{tag {tag _ai_medic}}
{tag {tag bot_medic}}
{tag {tag _ufb_healing_active}}
{tag {tag _ufb_autonomy_moving}}
{tag {tag _ai_wounded_carrier}}
{tag {tag _ai_ap_grenade}}
{tag {tag _ai_at_grenade}}
{tag {tag _ai_smoke_grenade}}
{tag {tag _ai_suppressed_by_mg}}
{tag {tag _ai_mgunner}}
{tag {tag _ai_reloading}}
{tag {tag _ai_looting_weapon}}
{tag {tag crew}}
{tag {tag tcrew}}
{tag {tag ecrew}}
{tag {tag ecrew_a}}
{tag {tag ecrew_b}}
{tag {tag bot_arty}}
{tag {tag bot_aa_guard}}
{tag {tag _ufb_crew_safe}}
{tag {tag _ufb_hf_cover_active}}
{tag {tag _ai_wirecutter_in_action}}
{tag {tag bot_inf_flank_in_progress}}
{tag {tag _ufb_smoke_120m_actor}}
{tag {tag _ufb_smoke_60m_actor}}
{tag {tag _ufb_smoke_wirecutter_actor}}
{tag {tag _ai_at_launcher_30}}
{tag {tag _ai_at_launcher_40}}
{tag {tag _ai_at_launcher_50}}
{tag {tag _ai_at_launcher_60}}
{tag {tag _ai_at_launcher_70}}
{tag {tag _ai_at_launcher_80}}
{tag {tag _ai_at_launcher_90}}
{tag {tag _ufb_suppress_actor_%team}}
{with_item {type using} {item "rocketlauncher"}}}
}} {effect ufb_combat_ap_cooldown}}
{"action" {selector {source advanced}
{ignore_captured_by_user 1}
{group
 {select {tag {tag _ufb_combat_ap_actor_%team}}}
 {include {team {team %team}}
{prop {prop human}}
{state {state operatable}}
{state {state user_control}}
{with_item {type amount} {item "fg"} {min 1}}}
 {exclude {state {state dead}}
{state {state inactive}}
{state {state linked}}
{prop {prop crew}}
{prop {prop repairing}}
{prop {prop throwing}}
{tag {tag _lua_mi}}
{tag {tag _lua_ignore}}
{tag {tag _ai_do_not_disturb}}
{tag {tag repairing}}
{tag {tag bleeding}}
{tag {tag _bleeding}}
{tag {tag wounded}}
{tag {tag _bleedout_}}
{tag {tag wounded_animation_playing}}
{tag {tag medic}}
{tag {tag _ai_medic}}
{tag {tag bot_medic}}
{tag {tag _ufb_healing_active}}
{tag {tag _ufb_autonomy_moving}}
{tag {tag _ai_wounded_carrier}}
{tag {tag _ai_ap_grenade}}
{tag {tag _ai_at_grenade}}
{tag {tag _ai_smoke_grenade}}
{tag {tag _ai_suppressed_by_mg}}
{tag {tag _ai_mgunner}}
{tag {tag _ai_reloading}}
{tag {tag _ai_looting_weapon}}
{tag {tag crew}}
{tag {tag tcrew}}
{tag {tag ecrew}}
{tag {tag ecrew_a}}
{tag {tag ecrew_b}}
{tag {tag bot_arty}}
{tag {tag bot_aa_guard}}
{tag {tag _ufb_crew_safe}}
{tag {tag _ufb_hf_cover_active}}
{tag {tag _ai_wirecutter_in_action}}
{tag {tag bot_inf_flank_in_progress}}
{tag {tag _ufb_smoke_120m_actor}}
{tag {tag _ufb_smoke_60m_actor}}
{tag {tag _ufb_smoke_wirecutter_actor}}
{tag {tag _ai_at_launcher_30}}
{tag {tag _ai_at_launcher_40}}
{tag {tag _ai_at_launcher_50}}
{tag {tag _ai_at_launcher_60}}
{tag {tag _ai_at_launcher_70}}
{tag {tag _ai_at_launcher_80}}
{tag {tag _ai_at_launcher_90}}
{tag {tag _ufb_suppress_actor_%team}}
{with_item {type using} {item "rocketlauncher"}}}
}
{amount 1}} {action throw_ap_grenade} {target {ignore_captured_by_user 0} {tag _ufb_combat_ap_target_%team}}}
   {"delay" {time 1}}
   {"trigger" {name "ufb/combat/ap/apply %team"}}
  }
 }
)

; smoke: one reserved pair per player; no drop-orders or fire-mode changes.
(define "ufb_combat_smoke"
 {"ufb/combat/smoke/acquire %team"
  {condition {terms {"1.see_actors" {selector {source advanced}
{ignore_captured_by_user 1}
{group
 {select {tag {tag _ufb_recent_hit}}}
 {include {team {team %team}}
{prop {prop human}}
{state {state operatable}}
{state {state user_control}}
{prop {prop shooting}}
{with_item {type amount} {item "smoke"} {min 1}}}
 {exclude {state {state dead}}
{state {state inactive}}
{state {state linked}}
{prop {prop crew}}
{prop {prop repairing}}
{prop {prop throwing}}
{tag {tag _lua_mi}}
{tag {tag _lua_ignore}}
{tag {tag _ai_do_not_disturb}}
{tag {tag repairing}}
{tag {tag bleeding}}
{tag {tag _bleeding}}
{tag {tag wounded}}
{tag {tag _bleedout_}}
{tag {tag wounded_animation_playing}}
{tag {tag medic}}
{tag {tag _ai_medic}}
{tag {tag bot_medic}}
{tag {tag _ufb_healing_active}}
{tag {tag _ufb_autonomy_moving}}
{tag {tag _ai_wounded_carrier}}
{tag {tag _ai_ap_grenade}}
{tag {tag _ai_at_grenade}}
{tag {tag _ai_smoke_grenade}}
{tag {tag _ai_suppressed_by_mg}}
{tag {tag _ai_mgunner}}
{tag {tag _ai_reloading}}
{tag {tag _ai_looting_weapon}}
{tag {tag crew}}
{tag {tag tcrew}}
{tag {tag ecrew}}
{tag {tag ecrew_a}}
{tag {tag ecrew_b}}
{tag {tag bot_arty}}
{tag {tag bot_aa_guard}}
{tag {tag _ufb_crew_safe}}
{tag {tag _ufb_hf_cover_active}}
{tag {tag _ai_wirecutter_in_action}}
{tag {tag bot_inf_flank_in_progress}}
{tag {tag _ufb_smoke_120m_actor}}
{tag {tag _ufb_smoke_60m_actor}}
{tag {tag _ufb_smoke_wirecutter_actor}}
{tag {tag _ai_at_launcher_30}}
{tag {tag _ai_at_launcher_40}}
{tag {tag _ai_at_launcher_50}}
{tag {tag _ai_at_launcher_60}}
{tag {tag _ai_at_launcher_70}}
{tag {tag _ai_at_launcher_80}}
{tag {tag _ai_at_launcher_90}}
{tag {tag _ufb_suppress_actor_%team}}
{with_item {type using} {item "rocketlauncher"}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_combat_smoke_cooldown}}
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_launcher_actor_%team}}
{tag {tag _ufb_combat_at_actor_%team}}
{tag {tag _ufb_combat_critical_actor_%team}}
{tag {tag _ufb_combat_ap_actor_%team}}
{tag {tag _ufb_combat_smoke_actor_%team}}
{with_item {type existance} {item "m15_wp"}}
{with_item {type existance} {item "m42_wp"}}
{with_item {type existance} {item "no77_wp"}}}
}}
{enemy {source advanced}
{ignore_captured_by_user 0}
{group {select {prop {prop vehicle}} {prop {prop tank}} {prop {prop car}} {prop {prop cannon}} {with_item {type using} {item "mgun"}}} {include {team {team %foe}}
{state {state operatable}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop airborne}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}}}}}
{distance {mode in_range} {min 30} {max 110}}
{detection visible}
{tag {"tag pair"} {"for selector" _ufb_combat_smoke_pick_%team} {"for enemy" _ufb_combat_smoke_target_%team}}}}}
  {actions
   {"entity_state" {selector {amount 1} {ignore_captured_by_user 0} {tag _ufb_combat_smoke_pick_%team}} {tag_add _ufb_combat_smoke_actor_%team}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_combat_smoke_pick_%team}} {tag_remove _ufb_combat_smoke_pick_%team}}
   {"effect" {selector {ignore_captured_by_user 0} {tag _ufb_combat_smoke_actor_%team}} {effect ufb_reserve_job}}
   
   {"delay" {time 6}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_combat_smoke_actor_%team}} {tag_remove _ufb_combat_smoke_actor_%team}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_combat_smoke_target_%team}} {tag_remove _ufb_combat_smoke_target_%team}}
   {"delay" {time 2}}
   {"trigger" {name "ufb/combat/smoke/acquire %team"}}
  }
 }
 {"ufb/combat/smoke/apply %team"
  {condition {expression "1"} {terms
   {"1.see_actors" {selector {source advanced}
{ignore_captured_by_user 1}
{group
 {select {tag {tag _ufb_combat_smoke_actor_%team}}}
 {include {team {team %team}}
{prop {prop human}}
{state {state operatable}}
{state {state user_control}}
{prop {prop shooting}}
{with_item {type amount} {item "smoke"} {min 1}}}
 {exclude {state {state dead}}
{state {state inactive}}
{state {state linked}}
{prop {prop crew}}
{prop {prop repairing}}
{prop {prop throwing}}
{tag {tag _lua_mi}}
{tag {tag _lua_ignore}}
{tag {tag _ai_do_not_disturb}}
{tag {tag repairing}}
{tag {tag bleeding}}
{tag {tag _bleeding}}
{tag {tag wounded}}
{tag {tag _bleedout_}}
{tag {tag wounded_animation_playing}}
{tag {tag medic}}
{tag {tag _ai_medic}}
{tag {tag bot_medic}}
{tag {tag _ufb_healing_active}}
{tag {tag _ufb_autonomy_moving}}
{tag {tag _ai_wounded_carrier}}
{tag {tag _ai_ap_grenade}}
{tag {tag _ai_at_grenade}}
{tag {tag _ai_smoke_grenade}}
{tag {tag _ai_suppressed_by_mg}}
{tag {tag _ai_mgunner}}
{tag {tag _ai_reloading}}
{tag {tag _ai_looting_weapon}}
{tag {tag crew}}
{tag {tag tcrew}}
{tag {tag ecrew}}
{tag {tag ecrew_a}}
{tag {tag ecrew_b}}
{tag {tag bot_arty}}
{tag {tag bot_aa_guard}}
{tag {tag _ufb_crew_safe}}
{tag {tag _ufb_hf_cover_active}}
{tag {tag _ai_wirecutter_in_action}}
{tag {tag bot_inf_flank_in_progress}}
{tag {tag _ufb_smoke_120m_actor}}
{tag {tag _ufb_smoke_60m_actor}}
{tag {tag _ufb_smoke_wirecutter_actor}}
{tag {tag _ai_at_launcher_30}}
{tag {tag _ai_at_launcher_40}}
{tag {tag _ai_at_launcher_50}}
{tag {tag _ai_at_launcher_60}}
{tag {tag _ai_at_launcher_70}}
{tag {tag _ai_at_launcher_80}}
{tag {tag _ai_at_launcher_90}}
{tag {tag _ufb_suppress_actor_%team}}
{with_item {type using} {item "rocketlauncher"}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_combat_smoke_cooldown}}
{with_item {type existance} {item "m15_wp"}}
{with_item {type existance} {item "m42_wp"}}
{with_item {type existance} {item "no77_wp"}}}
}}
{enemy {source advanced}
{ignore_captured_by_user 0}
{group {select {tag {tag _ufb_combat_smoke_target_%team}}} {include {team {team %foe}}
{state {state operatable}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop airborne}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}}}}}
{distance {mode in_range} {min 30} {max 110}}
{detection visible}}
   
   
  }}
  {actions
   {"con" {text "[UFB combat] smoke order: team %team"}}
   {"effect" {selector {source advanced}
{ignore_captured_by_user 1}
{group
 {select {tag {tag _ufb_combat_smoke_actor_%team}}}
 {include {team {team %team}}
{prop {prop human}}
{state {state operatable}}
{state {state user_control}}
{with_item {type amount} {item "smoke"} {min 1}}}
 {exclude {state {state dead}}
{state {state inactive}}
{state {state linked}}
{prop {prop crew}}
{prop {prop repairing}}
{prop {prop throwing}}
{tag {tag _lua_mi}}
{tag {tag _lua_ignore}}
{tag {tag _ai_do_not_disturb}}
{tag {tag repairing}}
{tag {tag bleeding}}
{tag {tag _bleeding}}
{tag {tag wounded}}
{tag {tag _bleedout_}}
{tag {tag wounded_animation_playing}}
{tag {tag medic}}
{tag {tag _ai_medic}}
{tag {tag bot_medic}}
{tag {tag _ufb_healing_active}}
{tag {tag _ufb_autonomy_moving}}
{tag {tag _ai_wounded_carrier}}
{tag {tag _ai_ap_grenade}}
{tag {tag _ai_at_grenade}}
{tag {tag _ai_smoke_grenade}}
{tag {tag _ai_suppressed_by_mg}}
{tag {tag _ai_mgunner}}
{tag {tag _ai_reloading}}
{tag {tag _ai_looting_weapon}}
{tag {tag crew}}
{tag {tag tcrew}}
{tag {tag ecrew}}
{tag {tag ecrew_a}}
{tag {tag ecrew_b}}
{tag {tag bot_arty}}
{tag {tag bot_aa_guard}}
{tag {tag _ufb_crew_safe}}
{tag {tag _ufb_hf_cover_active}}
{tag {tag _ai_wirecutter_in_action}}
{tag {tag bot_inf_flank_in_progress}}
{tag {tag _ufb_smoke_120m_actor}}
{tag {tag _ufb_smoke_60m_actor}}
{tag {tag _ufb_smoke_wirecutter_actor}}
{tag {tag _ai_at_launcher_30}}
{tag {tag _ai_at_launcher_40}}
{tag {tag _ai_at_launcher_50}}
{tag {tag _ai_at_launcher_60}}
{tag {tag _ai_at_launcher_70}}
{tag {tag _ai_at_launcher_80}}
{tag {tag _ai_at_launcher_90}}
{tag {tag _ufb_suppress_actor_%team}}
{with_item {type using} {item "rocketlauncher"}}
{with_item {type existance} {item "m15_wp"}}
{with_item {type existance} {item "m42_wp"}}
{with_item {type existance} {item "no77_wp"}}}
}} {effect ufb_combat_smoke_cooldown}}
{"effect" {selector {source advanced}
{ignore_captured_by_user 1}
{group
 {select {tag {tag _ufb_combat_smoke_actor_%team}}}
 {include {team {team %team}}
{prop {prop human}}
{state {state operatable}}
{state {state user_control}}
{with_item {type amount} {item "smoke"} {min 1}}}
 {exclude {state {state dead}}
{state {state inactive}}
{state {state linked}}
{prop {prop crew}}
{prop {prop repairing}}
{prop {prop throwing}}
{tag {tag _lua_mi}}
{tag {tag _lua_ignore}}
{tag {tag _ai_do_not_disturb}}
{tag {tag repairing}}
{tag {tag bleeding}}
{tag {tag _bleeding}}
{tag {tag wounded}}
{tag {tag _bleedout_}}
{tag {tag wounded_animation_playing}}
{tag {tag medic}}
{tag {tag _ai_medic}}
{tag {tag bot_medic}}
{tag {tag _ufb_healing_active}}
{tag {tag _ufb_autonomy_moving}}
{tag {tag _ai_wounded_carrier}}
{tag {tag _ai_ap_grenade}}
{tag {tag _ai_at_grenade}}
{tag {tag _ai_smoke_grenade}}
{tag {tag _ai_suppressed_by_mg}}
{tag {tag _ai_mgunner}}
{tag {tag _ai_reloading}}
{tag {tag _ai_looting_weapon}}
{tag {tag crew}}
{tag {tag tcrew}}
{tag {tag ecrew}}
{tag {tag ecrew_a}}
{tag {tag ecrew_b}}
{tag {tag bot_arty}}
{tag {tag bot_aa_guard}}
{tag {tag _ufb_crew_safe}}
{tag {tag _ufb_hf_cover_active}}
{tag {tag _ai_wirecutter_in_action}}
{tag {tag bot_inf_flank_in_progress}}
{tag {tag _ufb_smoke_120m_actor}}
{tag {tag _ufb_smoke_60m_actor}}
{tag {tag _ufb_smoke_wirecutter_actor}}
{tag {tag _ai_at_launcher_30}}
{tag {tag _ai_at_launcher_40}}
{tag {tag _ai_at_launcher_50}}
{tag {tag _ai_at_launcher_60}}
{tag {tag _ai_at_launcher_70}}
{tag {tag _ai_at_launcher_80}}
{tag {tag _ai_at_launcher_90}}
{tag {tag _ufb_suppress_actor_%team}}
{with_item {type using} {item "rocketlauncher"}}
{with_item {type existance} {item "m15_wp"}}
{with_item {type existance} {item "m42_wp"}}
{with_item {type existance} {item "no77_wp"}}}
}
{amount 1}} {effect ufb_combat_smoke_point_%team}}
{"action" {selector {source advanced}
{ignore_captured_by_user 1}
{group
 {select {tag {tag _ufb_combat_smoke_actor_%team}}}
 {include {team {team %team}}
{prop {prop human}}
{state {state operatable}}
{state {state user_control}}
{with_item {type amount} {item "smoke"} {min 1}}}
 {exclude {state {state dead}}
{state {state inactive}}
{state {state linked}}
{prop {prop crew}}
{prop {prop repairing}}
{prop {prop throwing}}
{tag {tag _lua_mi}}
{tag {tag _lua_ignore}}
{tag {tag _ai_do_not_disturb}}
{tag {tag repairing}}
{tag {tag bleeding}}
{tag {tag _bleeding}}
{tag {tag wounded}}
{tag {tag _bleedout_}}
{tag {tag wounded_animation_playing}}
{tag {tag medic}}
{tag {tag _ai_medic}}
{tag {tag bot_medic}}
{tag {tag _ufb_healing_active}}
{tag {tag _ufb_autonomy_moving}}
{tag {tag _ai_wounded_carrier}}
{tag {tag _ai_ap_grenade}}
{tag {tag _ai_at_grenade}}
{tag {tag _ai_smoke_grenade}}
{tag {tag _ai_suppressed_by_mg}}
{tag {tag _ai_mgunner}}
{tag {tag _ai_reloading}}
{tag {tag _ai_looting_weapon}}
{tag {tag crew}}
{tag {tag tcrew}}
{tag {tag ecrew}}
{tag {tag ecrew_a}}
{tag {tag ecrew_b}}
{tag {tag bot_arty}}
{tag {tag bot_aa_guard}}
{tag {tag _ufb_crew_safe}}
{tag {tag _ufb_hf_cover_active}}
{tag {tag _ai_wirecutter_in_action}}
{tag {tag bot_inf_flank_in_progress}}
{tag {tag _ufb_smoke_120m_actor}}
{tag {tag _ufb_smoke_60m_actor}}
{tag {tag _ufb_smoke_wirecutter_actor}}
{tag {tag _ai_at_launcher_30}}
{tag {tag _ai_at_launcher_40}}
{tag {tag _ai_at_launcher_50}}
{tag {tag _ai_at_launcher_60}}
{tag {tag _ai_at_launcher_70}}
{tag {tag _ai_at_launcher_80}}
{tag {tag _ai_at_launcher_90}}
{tag {tag _ufb_suppress_actor_%team}}
{with_item {type using} {item "rocketlauncher"}}
{with_item {type existance} {item "m15_wp"}}
{with_item {type existance} {item "m42_wp"}}
{with_item {type existance} {item "no77_wp"}}}
}
{amount 1}} {action throw_sk_grenade} {target {ignore_captured_by_user 0} {tag _ufb_combat_smoke_point_%team}}}
   {"delay" {time 1}}
   {"trigger" {name "ufb/combat/smoke/apply %team"}}
  }
 }
)

(define "ufb_combat_launcher_release"
 {"ufb/launcher/keep near %team"
  {condition {terms {"1.see_actors" {selector {source advanced}
{ignore_captured_by_user 1}
{group
 {select {prop {prop human}}}
 {include {team {team %team}} {state {state operatable}} {with_item {type using} {item "rocketlauncher"}} {with_item {type amount} {item "weapon bullet"} {min 1}} }
 {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} {prop {prop repairing}} {prop {prop throwing}} {prop {prop shooting}} {tag {tag _ufb_job_reserved}} {tag {tag _ufb_combat_busy}} {tag {tag _lua_mi}} {tag {tag _lua_ignore}} {tag {tag _ai_do_not_disturb}} {tag {tag repairing}} {tag {tag reloading}} {tag {tag bleeding}} {tag {tag _bleeding}} {tag {tag wounded}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag medic}} {tag {tag _ai_medic}} {tag {tag bot_medic}} {tag {tag _ufb_healing_active}} {tag {tag _ai_wounded_carrier}} {tag {tag _ai_ap_grenade}} {tag {tag _ai_at_grenade}} {tag {tag _ai_smoke_grenade}} {tag {tag _ai_suppressed_by_mg}} {tag {tag _ai_mgunner}} {tag {tag _ai_reloading}} {tag {tag _ai_looting_weapon}} {tag {tag crew}} {tag {tag tcrew}} {tag {tag ecrew}} {tag {tag ecrew_a}} {tag {tag ecrew_b}} {tag {tag bot_arty}} {tag {tag bot_aa_guard}} {tag {tag _ufb_crew_safe}} {tag {tag _ufb_hf_cover_active}} {tag {tag _ai_wirecutter_in_action}} {tag {tag bot_inf_flank_in_progress}} {tag {tag _ufb_smoke_120m_actor}} {tag {tag _ufb_smoke_60m_actor}} {tag {tag _ufb_smoke_wirecutter_actor}} {tag {tag _ai_at_launcher_30}} {tag {tag _ai_at_launcher_40}} {tag {tag _ai_at_launcher_50}} {tag {tag _ai_at_launcher_60}} {tag {tag _ai_at_launcher_70}} {tag {tag _ai_at_launcher_80}} {tag {tag _ai_at_launcher_90}} {tag {tag _ufb_launcher_keep}} {with_item {type using} {item "range_60"}} {with_item {type using} {item "range_70"}} {with_item {type using} {item "range_80"}} {with_item {type using} {item "range_90"}}}
}} {enemy {source advanced}
{ignore_captured_by_user 0}
{group {select {prop {prop vehicle}} {prop {prop tank}} {prop {prop car}} {prop {prop cannon}}} {include {team {team %foe}}
{state {state operatable}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop airborne}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}}}}} {distance {mode in_range} {min 0} {max 70}} {detection visible} {tag {"tag pair"} {"for selector" _ufb_launcher_keep_near_%team}}}}}
  {actions
   {"effect" {selector {ignore_captured_by_user 0} {tag _ufb_launcher_keep_near_%team}} {effect ufb_launcher_keep}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_launcher_keep_near_%team}} {tag_remove _ufb_launcher_keep_near_%team}}
   {"delay" {time 1}}
   {"trigger" {name "ufb/launcher/keep near %team"}}
  }
 }
 {"ufb/launcher/keep far %team"
  {condition {terms {"1.see_actors" {selector {source advanced}
{ignore_captured_by_user 1}
{group
 {select {prop {prop human}}}
 {include {team {team %team}} {state {state operatable}} {with_item {type using} {item "rocketlauncher"}} {with_item {type amount} {item "weapon bullet"} {min 1}} }
 {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} {prop {prop repairing}} {prop {prop throwing}} {prop {prop shooting}} {tag {tag _ufb_job_reserved}} {tag {tag _ufb_combat_busy}} {tag {tag _lua_mi}} {tag {tag _lua_ignore}} {tag {tag _ai_do_not_disturb}} {tag {tag repairing}} {tag {tag reloading}} {tag {tag bleeding}} {tag {tag _bleeding}} {tag {tag wounded}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag medic}} {tag {tag _ai_medic}} {tag {tag bot_medic}} {tag {tag _ufb_healing_active}} {tag {tag _ai_wounded_carrier}} {tag {tag _ai_ap_grenade}} {tag {tag _ai_at_grenade}} {tag {tag _ai_smoke_grenade}} {tag {tag _ai_suppressed_by_mg}} {tag {tag _ai_mgunner}} {tag {tag _ai_reloading}} {tag {tag _ai_looting_weapon}} {tag {tag crew}} {tag {tag tcrew}} {tag {tag ecrew}} {tag {tag ecrew_a}} {tag {tag ecrew_b}} {tag {tag bot_arty}} {tag {tag bot_aa_guard}} {tag {tag _ufb_crew_safe}} {tag {tag _ufb_hf_cover_active}} {tag {tag _ai_wirecutter_in_action}} {tag {tag bot_inf_flank_in_progress}} {tag {tag _ufb_smoke_120m_actor}} {tag {tag _ufb_smoke_60m_actor}} {tag {tag _ufb_smoke_wirecutter_actor}} {tag {tag _ai_at_launcher_30}} {tag {tag _ai_at_launcher_40}} {tag {tag _ai_at_launcher_50}} {tag {tag _ai_at_launcher_60}} {tag {tag _ai_at_launcher_70}} {tag {tag _ai_at_launcher_80}} {tag {tag _ai_at_launcher_90}} {tag {tag _ufb_launcher_keep}} {with_item {type using} {item "range_30"}} {with_item {type using} {item "range_40"}} {with_item {type using} {item "range_50"}}}
}} {enemy {source advanced}
{ignore_captured_by_user 0}
{group {select {prop {prop vehicle}} {prop {prop tank}} {prop {prop car}} {prop {prop cannon}}} {include {team {team %foe}}
{state {state operatable}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop airborne}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}}}}} {distance {mode in_range} {min 0} {max 110}} {detection visible} {tag {"tag pair"} {"for selector" _ufb_launcher_keep_far_%team}}}}}
  {actions
   {"effect" {selector {ignore_captured_by_user 0} {tag _ufb_launcher_keep_far_%team}} {effect ufb_launcher_keep}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_launcher_keep_far_%team}} {tag_remove _ufb_launcher_keep_far_%team}}
   {"delay" {time 1}}
   {"trigger" {name "ufb/launcher/keep far %team"}}
  }
 }
 {"ufb/launcher/tick %team"
  {condition {terms {"1.entities" {selector {source advanced}
{ignore_captured_by_user 1}
{group
 {select {prop {prop human}}}
 {include {team {team %team}} {state {state operatable}} {with_item {type using} {item "rocketlauncher"}} {with_item {type amount} {item "weapon bullet"} {min 1}} }
 {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} {prop {prop repairing}} {prop {prop throwing}} {prop {prop shooting}} {tag {tag _ufb_job_reserved}} {tag {tag _ufb_combat_busy}} {tag {tag _lua_mi}} {tag {tag _lua_ignore}} {tag {tag _ai_do_not_disturb}} {tag {tag repairing}} {tag {tag reloading}} {tag {tag bleeding}} {tag {tag _bleeding}} {tag {tag wounded}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag medic}} {tag {tag _ai_medic}} {tag {tag bot_medic}} {tag {tag _ufb_healing_active}} {tag {tag _ai_wounded_carrier}} {tag {tag _ai_ap_grenade}} {tag {tag _ai_at_grenade}} {tag {tag _ai_smoke_grenade}} {tag {tag _ai_suppressed_by_mg}} {tag {tag _ai_mgunner}} {tag {tag _ai_reloading}} {tag {tag _ai_looting_weapon}} {tag {tag crew}} {tag {tag tcrew}} {tag {tag ecrew}} {tag {tag ecrew_a}} {tag {tag ecrew_b}} {tag {tag bot_arty}} {tag {tag bot_aa_guard}} {tag {tag _ufb_crew_safe}} {tag {tag _ufb_hf_cover_active}} {tag {tag _ai_wirecutter_in_action}} {tag {tag bot_inf_flank_in_progress}} {tag {tag _ufb_smoke_120m_actor}} {tag {tag _ufb_smoke_60m_actor}} {tag {tag _ufb_smoke_wirecutter_actor}} {tag {tag _ai_at_launcher_30}} {tag {tag _ai_at_launcher_40}} {tag {tag _ai_at_launcher_50}} {tag {tag _ai_at_launcher_60}} {tag {tag _ai_at_launcher_70}} {tag {tag _ai_at_launcher_80}} {tag {tag _ai_at_launcher_90}}}
}}}}}
  {actions
   {"effect" {selector {source advanced}
{ignore_captured_by_user 1}
{group
 {select {prop {prop human}}}
 {include {team {team %team}} {state {state operatable}} {with_item {type using} {item "rocketlauncher"}} {with_item {type amount} {item "weapon bullet"} {min 1}} }
 {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} {prop {prop repairing}} {prop {prop throwing}} {prop {prop shooting}} {tag {tag _ufb_job_reserved}} {tag {tag _ufb_combat_busy}} {tag {tag _lua_mi}} {tag {tag _lua_ignore}} {tag {tag _ai_do_not_disturb}} {tag {tag repairing}} {tag {tag reloading}} {tag {tag bleeding}} {tag {tag _bleeding}} {tag {tag wounded}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag medic}} {tag {tag _ai_medic}} {tag {tag bot_medic}} {tag {tag _ufb_healing_active}} {tag {tag _ai_wounded_carrier}} {tag {tag _ai_ap_grenade}} {tag {tag _ai_at_grenade}} {tag {tag _ai_smoke_grenade}} {tag {tag _ai_suppressed_by_mg}} {tag {tag _ai_mgunner}} {tag {tag _ai_reloading}} {tag {tag _ai_looting_weapon}} {tag {tag crew}} {tag {tag tcrew}} {tag {tag ecrew}} {tag {tag ecrew_a}} {tag {tag ecrew_b}} {tag {tag bot_arty}} {tag {tag bot_aa_guard}} {tag {tag _ufb_crew_safe}} {tag {tag _ufb_hf_cover_active}} {tag {tag _ai_wirecutter_in_action}} {tag {tag bot_inf_flank_in_progress}} {tag {tag _ufb_smoke_120m_actor}} {tag {tag _ufb_smoke_60m_actor}} {tag {tag _ufb_smoke_wirecutter_actor}} {tag {tag _ai_at_launcher_30}} {tag {tag _ai_at_launcher_40}} {tag {tag _ai_at_launcher_50}} {tag {tag _ai_at_launcher_60}} {tag {tag _ai_at_launcher_70}} {tag {tag _ai_at_launcher_80}} {tag {tag _ai_at_launcher_90}} {tag {tag _ufb_launcher_keep}} {tag {tag _ufb_launcher_seen}}}
}} {effect ufb_launcher_grace}}
   {"if" {condition {type entities} {selector {source advanced}
{ignore_captured_by_user 1}
{group
 {select {prop {prop human}}}
 {include {team {team %team}} {state {state operatable}} {with_item {type using} {item "rocketlauncher"}} {with_item {type amount} {item "weapon bullet"} {min 1}} {tag {tag _ufb_launcher_ready}}}
 {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} {prop {prop repairing}} {prop {prop throwing}} {prop {prop shooting}} {tag {tag _ufb_job_reserved}} {tag {tag _ufb_combat_busy}} {tag {tag _lua_mi}} {tag {tag _lua_ignore}} {tag {tag _ai_do_not_disturb}} {tag {tag repairing}} {tag {tag reloading}} {tag {tag bleeding}} {tag {tag _bleeding}} {tag {tag wounded}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag medic}} {tag {tag _ai_medic}} {tag {tag bot_medic}} {tag {tag _ufb_healing_active}} {tag {tag _ai_wounded_carrier}} {tag {tag _ai_ap_grenade}} {tag {tag _ai_at_grenade}} {tag {tag _ai_smoke_grenade}} {tag {tag _ai_suppressed_by_mg}} {tag {tag _ai_mgunner}} {tag {tag _ai_reloading}} {tag {tag _ai_looting_weapon}} {tag {tag crew}} {tag {tag tcrew}} {tag {tag ecrew}} {tag {tag ecrew_a}} {tag {tag ecrew_b}} {tag {tag bot_arty}} {tag {tag bot_aa_guard}} {tag {tag _ufb_crew_safe}} {tag {tag _ufb_hf_cover_active}} {tag {tag _ai_wirecutter_in_action}} {tag {tag bot_inf_flank_in_progress}} {tag {tag _ufb_smoke_120m_actor}} {tag {tag _ufb_smoke_60m_actor}} {tag {tag _ufb_smoke_wirecutter_actor}} {tag {tag _ai_at_launcher_30}} {tag {tag _ai_at_launcher_40}} {tag {tag _ai_at_launcher_50}} {tag {tag _ai_at_launcher_60}} {tag {tag _ai_at_launcher_70}} {tag {tag _ai_at_launcher_80}} {tag {tag _ai_at_launcher_90}} {tag {tag _ufb_launcher_keep}}}
}}}
    {"entity_state" {selector {source advanced}
{ignore_captured_by_user 1}
{group
 {select {prop {prop human}}}
 {include {team {team %team}} {state {state operatable}} {with_item {type using} {item "rocketlauncher"}} {with_item {type amount} {item "weapon bullet"} {min 1}} {tag {tag _ufb_launcher_ready}}}
 {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} {prop {prop repairing}} {prop {prop throwing}} {prop {prop shooting}} {tag {tag _ufb_job_reserved}} {tag {tag _ufb_combat_busy}} {tag {tag _lua_mi}} {tag {tag _lua_ignore}} {tag {tag _ai_do_not_disturb}} {tag {tag repairing}} {tag {tag reloading}} {tag {tag bleeding}} {tag {tag _bleeding}} {tag {tag wounded}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag medic}} {tag {tag _ai_medic}} {tag {tag bot_medic}} {tag {tag _ufb_healing_active}} {tag {tag _ai_wounded_carrier}} {tag {tag _ai_ap_grenade}} {tag {tag _ai_at_grenade}} {tag {tag _ai_smoke_grenade}} {tag {tag _ai_suppressed_by_mg}} {tag {tag _ai_mgunner}} {tag {tag _ai_reloading}} {tag {tag _ai_looting_weapon}} {tag {tag crew}} {tag {tag tcrew}} {tag {tag ecrew}} {tag {tag ecrew_a}} {tag {tag ecrew_b}} {tag {tag bot_arty}} {tag {tag bot_aa_guard}} {tag {tag _ufb_crew_safe}} {tag {tag _ufb_hf_cover_active}} {tag {tag _ai_wirecutter_in_action}} {tag {tag bot_inf_flank_in_progress}} {tag {tag _ufb_smoke_120m_actor}} {tag {tag _ufb_smoke_60m_actor}} {tag {tag _ufb_smoke_wirecutter_actor}} {tag {tag _ai_at_launcher_30}} {tag {tag _ai_at_launcher_40}} {tag {tag _ai_at_launcher_50}} {tag {tag _ai_at_launcher_60}} {tag {tag _ai_at_launcher_70}} {tag {tag _ai_at_launcher_80}} {tag {tag _ai_at_launcher_90}} {tag {tag _ufb_launcher_keep}}}
}} {tag_add _ufb_launcher_stow_%team}}
    {"inventory" {selector {source advanced}
{ignore_captured_by_user 1}
{group
 {select {prop {prop human}}}
 {include {team {team %team}} {state {state operatable}} {with_item {type using} {item "rocketlauncher"}} {with_item {type amount} {item "weapon bullet"} {min 1}} {tag {tag _ufb_launcher_ready}}}
 {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} {prop {prop repairing}} {prop {prop throwing}} {prop {prop shooting}} {tag {tag _ufb_job_reserved}} {tag {tag _ufb_combat_busy}} {tag {tag _lua_mi}} {tag {tag _lua_ignore}} {tag {tag _ai_do_not_disturb}} {tag {tag repairing}} {tag {tag reloading}} {tag {tag bleeding}} {tag {tag _bleeding}} {tag {tag wounded}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag medic}} {tag {tag _ai_medic}} {tag {tag bot_medic}} {tag {tag _ufb_healing_active}} {tag {tag _ai_wounded_carrier}} {tag {tag _ai_ap_grenade}} {tag {tag _ai_at_grenade}} {tag {tag _ai_smoke_grenade}} {tag {tag _ai_suppressed_by_mg}} {tag {tag _ai_mgunner}} {tag {tag _ai_reloading}} {tag {tag _ai_looting_weapon}} {tag {tag crew}} {tag {tag tcrew}} {tag {tag ecrew}} {tag {tag ecrew_a}} {tag {tag ecrew_b}} {tag {tag bot_arty}} {tag {tag bot_aa_guard}} {tag {tag _ufb_crew_safe}} {tag {tag _ufb_hf_cover_active}} {tag {tag _ai_wirecutter_in_action}} {tag {tag bot_inf_flank_in_progress}} {tag {tag _ufb_smoke_120m_actor}} {tag {tag _ufb_smoke_60m_actor}} {tag {tag _ufb_smoke_wirecutter_actor}} {tag {tag _ai_at_launcher_30}} {tag {tag _ai_at_launcher_40}} {tag {tag _ai_at_launcher_50}} {tag {tag _ai_at_launcher_60}} {tag {tag _ai_at_launcher_70}} {tag {tag _ai_at_launcher_80}} {tag {tag _ai_at_launcher_90}} {tag {tag _ufb_launcher_keep}}}
}} {action take} {item "weapon bullet"}}
    {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_launcher_stow_%team}} {tag_remove _ufb_launcher_ready}}
    {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_launcher_stow_%team}} {tag_remove _ufb_launcher_seen}}
    {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_launcher_stow_%team}} {tag_remove _ufb_launcher_stow_%team}}
    {"con" {text "[UFB combat] launcher stowed: team %team"}}
   }
   {"delay" {time 2}}
   {"trigger" {name "ufb/launcher/tick %team"}}
  }
 }
)

("ufb_combat_launcher" team(a) foe(b))

("ufb_combat_at" team(a) foe(b))

("ufb_combat_critical" team(a) foe(b))

("ufb_combat_ap" team(a) foe(b))

("ufb_combat_smoke" team(a) foe(b))

("ufb_combat_launcher_release" team(a) foe(b))

("ufb_combat_launcher" team(b) foe(a))

("ufb_combat_at" team(b) foe(a))

("ufb_combat_critical" team(b) foe(a))

("ufb_combat_ap" team(b) foe(a))

("ufb_combat_smoke" team(b) foe(a))

("ufb_combat_launcher_release" team(b) foe(a))
(include "/map/multi/ufb_infantry_support.inc")
(include "/map/multi/ufb_static_weapons.inc")
