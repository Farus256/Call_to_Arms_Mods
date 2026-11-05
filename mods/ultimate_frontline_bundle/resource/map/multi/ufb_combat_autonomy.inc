; UFB combat autonomy. Native commands consume existing inventory and keep native ranges.
; Diplomacy is evaluated for EACH owning player, including cooperative and opposing teams.
; Player ownership and active user capture are separate native states.
; Only stationary troops already firing may receive extra offensive orders.
; Prepared launchers are excluded from grenade/smoke switching; idle stowing is bot-only.


; at: one reserved pair per player; no drop-orders or fire-mode changes.
(define "ufb_combat_at"
 {"ufb/combat/at/acquire %player"
  {condition {terms {"1.see_actors" {selector {source advanced}
{ignore_captured_by_user 1}
{group
 {select {prop {prop human}}}
 {include {player {player "%player"}}
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
{tag {tag _ufb_suppress_actor_%player}}
{with_item {type using} {item "rocketlauncher"}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_combat_at_cooldown}}
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_launcher_actor_%player}}
{tag {tag _ufb_combat_at_actor_%player}}
{tag {tag _ufb_combat_critical_actor_%player}}
{tag {tag _ufb_combat_ap_actor_%player}}
{tag {tag _ufb_combat_smoke_actor_%player}}
{tag {tag _ufb_combat_idle_actor_%player}}}
}
{amount 1}}
{enemy {source advanced}
{ignore_captured_by_user 0}
{group {select {prop {prop vehicle}} {prop {prop tank}} {prop {prop car}} {prop {prop cannon}}} {include {relation {relation enemy} {player "%player"}}
{state {state operatable}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop airborne}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}}}}}
{distance {mode in_range} {min 12} {max 16}}
{detection visible}
{tag {"tag pair"} {"for selector" _ufb_combat_at_actor_%player} {"for enemy" _ufb_combat_at_target_%player}}}}}
  {actions
   {"effect" {selector {ignore_captured_by_user 0} {tag _ufb_combat_at_actor_%player}} {effect ufb_reserve_job}}
   
   {"delay" {time 6}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_combat_at_actor_%player}} {tag_remove _ufb_combat_at_actor_%player}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_combat_at_target_%player}} {tag_remove _ufb_combat_at_target_%player}}
   {"delay" {time 2}}
   {"trigger" {name "ufb/combat/at/acquire %player"}}
  }
 }
 {"ufb/combat/at/apply %player"
  {condition {expression "1 & !2"} {terms
   {"1.see_actors" {selector {source advanced}
{ignore_captured_by_user 1}
{group
 {select {tag {tag _ufb_combat_at_actor_%player}}}
 {include {player {player "%player"}}
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
{tag {tag _ufb_suppress_actor_%player}}
{with_item {type using} {item "rocketlauncher"}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_combat_at_cooldown}}}
}}
{enemy {source advanced}
{ignore_captured_by_user 0}
{group {select {tag {tag _ufb_combat_at_target_%player}}} {include {relation {relation enemy} {player "%player"}}
{state {state operatable}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop airborne}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}}}}}
{distance {mode in_range} {min 12} {max 16}}
{detection visible}}
   {"2.near" {units {ignore_captured_by_user 0} {tag _ufb_combat_at_target_%player}}
{near_to {source advanced} {ignore_captured_by_user 0} {group {select {prop {prop human}}} {include {relation {relation ally} {player "%player"}} {state {state operatable}}} {exclude {state {state dead}}}}}
{distance 12}}
   
  }}
  {actions
   {"con" {text "[UFB combat] at order: player %player"}}
   {"effect" {selector {source advanced}
{ignore_captured_by_user 1}
{group
 {select {tag {tag _ufb_combat_at_actor_%player}}}
 {include {player {player "%player"}}
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
{tag {tag _ufb_suppress_actor_%player}}
{with_item {type using} {item "rocketlauncher"}}}
}} {effect ufb_combat_at_cooldown}}
{"action" {selector {source advanced}
{ignore_captured_by_user 1}
{group
 {select {tag {tag _ufb_combat_at_actor_%player}}}
 {include {player {player "%player"}}
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
{tag {tag _ufb_suppress_actor_%player}}
{with_item {type using} {item "rocketlauncher"}}}
}} {action throw_at_grenade} {target {ignore_captured_by_user 0} {tag _ufb_combat_at_target_%player}}}
   {"delay" {time 1}}
   {"trigger" {name "ufb/combat/at/apply %player"}}
  }
 }
)

; launcher: one reserved pair per player; no drop-orders or fire-mode changes.
(define "ufb_combat_launcher"
 {"ufb/combat/launcher/acquire %player"
  {condition {terms {"1.see_actors" {selector {source advanced}
{ignore_captured_by_user 1}
{group
 {select {prop {prop human}}}
 {include {player {player "%player"}}
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
{tag {tag _ufb_suppress_actor_%player}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_combat_launcher_cooldown}}
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_launcher_actor_%player}}
{tag {tag _ufb_combat_at_actor_%player}}
{tag {tag _ufb_combat_critical_actor_%player}}
{tag {tag _ufb_combat_ap_actor_%player}}
{tag {tag _ufb_combat_smoke_actor_%player}}
{tag {tag _ufb_combat_idle_actor_%player}}}
}
{amount 1}}
{enemy {source advanced}
{ignore_captured_by_user 0}
{group {select {prop {prop vehicle}} {prop {prop tank}} {prop {prop car}} {prop {prop cannon}}} {include {relation {relation enemy} {player "%player"}}
{state {state operatable}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop airborne}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}}}}}
{distance {mode in_range} {min 18} {max 25}}
{detection visible}
{tag {"tag pair"} {"for selector" _ufb_combat_launcher_actor_%player} {"for enemy" _ufb_combat_launcher_target_%player}}}}}
  {actions
   {"effect" {selector {ignore_captured_by_user 0} {tag _ufb_combat_launcher_actor_%player}} {effect ufb_reserve_job}}
   
   {"delay" {time 6}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_combat_launcher_actor_%player}} {tag_remove _ufb_combat_launcher_actor_%player}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_combat_launcher_target_%player}} {tag_remove _ufb_combat_launcher_target_%player}}
   {"delay" {time 2}}
   {"trigger" {name "ufb/combat/launcher/acquire %player"}}
  }
 }
 {"ufb/combat/launcher/apply %player"
  {condition {expression "1 & !2"} {terms
   {"1.see_actors" {selector {source advanced}
{ignore_captured_by_user 1}
{group
 {select {tag {tag _ufb_combat_launcher_actor_%player}}}
 {include {player {player "%player"}}
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
{tag {tag _ufb_suppress_actor_%player}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_combat_launcher_cooldown}}}
}}
{enemy {source advanced}
{ignore_captured_by_user 0}
{group {select {tag {tag _ufb_combat_launcher_target_%player}}} {include {relation {relation enemy} {player "%player"}}
{state {state operatable}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop airborne}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}}}}}
{distance {mode in_range} {min 18} {max 25}}
{detection visible}}
   {"2.near" {units {ignore_captured_by_user 0} {tag _ufb_combat_launcher_target_%player}}
{near_to {source advanced} {ignore_captured_by_user 0} {group {select {prop {prop human}}} {include {relation {relation ally} {player "%player"}} {state {state operatable}}} {exclude {state {state dead}}}}}
{distance 12}}
   
  }}
  {actions
   {"con" {text "[UFB combat] launcher order: player %player"}}
   {"effect" {selector {source advanced}
{ignore_captured_by_user 1}
{group
 {select {tag {tag _ufb_combat_launcher_actor_%player}}}
 {include {player {player "%player"}}
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
{tag {tag _ufb_suppress_actor_%player}}}
}} {effect ufb_combat_launcher_cooldown}}
{"action" {selector {source advanced}
{ignore_captured_by_user 1}
{group
 {select {tag {tag _ufb_combat_launcher_actor_%player}}}
 {include {player {player "%player"}}
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
{tag {tag _ufb_suppress_actor_%player}}}
}} {action bazooka_shot} {target {ignore_captured_by_user 0} {tag _ufb_combat_launcher_target_%player}}}
   {"delay" {time 1}}
   {"trigger" {name "ufb/combat/launcher/apply %player"}}
  }
 }
)

; critical: one reserved pair per player; no drop-orders or fire-mode changes.
(define "ufb_combat_critical"
 {"ufb/combat/critical/acquire %player"
  {condition {terms {"1.see_actors" {selector {source advanced}
{ignore_captured_by_user 1}
{group
 {select {tag {tag _ufb_recent_hit}}}
 {include {player {player "%player"}}
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
{tag {tag _ufb_suppress_actor_%player}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_combat_critical_cooldown}}
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_launcher_actor_%player}}
{tag {tag _ufb_combat_at_actor_%player}}
{tag {tag _ufb_combat_critical_actor_%player}}
{tag {tag _ufb_combat_ap_actor_%player}}
{tag {tag _ufb_combat_smoke_actor_%player}}
{tag {tag _ufb_combat_idle_actor_%player}}}
}
{amount 1}}
{enemy {source advanced}
{ignore_captured_by_user 0}
{group {select {prop {prop human}}} {include {relation {relation enemy} {player "%player"}}
{state {state operatable}}
{with_item {type using} {item "mgun"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop airborne}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}}}}}
{distance {mode in_range} {min 18} {max 25}}
{detection visible}
{tag {"tag pair"} {"for selector" _ufb_combat_critical_actor_%player} {"for enemy" _ufb_combat_critical_target_%player}}}}}
  {actions
   {"effect" {selector {ignore_captured_by_user 0} {tag _ufb_combat_critical_actor_%player}} {effect ufb_reserve_job}}
   {"effect" {selector {ignore_captured_by_user 0} {tag _ufb_combat_critical_target_%player}} {effect ufb_combat_probe_cover_%player}}
   {"delay" {time 6}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_combat_critical_actor_%player}} {tag_remove _ufb_combat_critical_actor_%player}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_combat_critical_target_%player}} {tag_remove _ufb_combat_critical_target_%player}}
   {"delay" {time 2}}
   {"trigger" {name "ufb/combat/critical/acquire %player"}}
  }
 }
 {"ufb/combat/critical/apply %player"
  {condition {expression "1 & !2 & !3"} {terms
   {"1.see_actors" {selector {source advanced}
{ignore_captured_by_user 1}
{group
 {select {tag {tag _ufb_combat_critical_actor_%player}}}
 {include {player {player "%player"}}
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
{tag {tag _ufb_suppress_actor_%player}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_combat_critical_cooldown}}}
}}
{enemy {source advanced}
{ignore_captured_by_user 0}
{group {select {tag {tag _ufb_combat_critical_target_%player}}} {include {relation {relation enemy} {player "%player"}}
{state {state operatable}}
{with_item {type using} {item "mgun"}}
{tag {tag _ufb_combat_cover_%player}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop airborne}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}}}}}
{distance {mode in_range} {min 18} {max 25}}
{detection visible}}
   {"2.near" {units {ignore_captured_by_user 0} {tag _ufb_combat_critical_target_%player}}
{near_to {source advanced} {ignore_captured_by_user 0} {group {select {prop {prop human}}} {include {relation {relation ally} {player "%player"}} {state {state operatable}}} {exclude {state {state dead}}}}}
{distance 12}}
   {"3.see_actors" {selector {source advanced}
{ignore_captured_by_user 1}
{group
 {select {tag {tag _ufb_combat_critical_actor_%player}}}
 {include {player {player "%player"}}
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
{tag {tag _ufb_suppress_actor_%player}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_combat_critical_cooldown}}}
}}
{enemy {source advanced}
{ignore_captured_by_user 0}
{group {select {prop {prop vehicle}} {prop {prop tank}} {prop {prop car}} {prop {prop cannon}}} {include {relation {relation enemy} {player "%player"}}
{state {state operatable}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop airborne}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}}}}}
{distance {mode in_range} {min 0} {max 110}}
{detection visible}}
  }}
  {actions
   {"con" {text "[UFB combat] critical order: player %player"}}
   {"effect" {selector {source advanced}
{ignore_captured_by_user 1}
{group
 {select {tag {tag _ufb_combat_critical_actor_%player}}}
 {include {player {player "%player"}}
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
{tag {tag _ufb_suppress_actor_%player}}}
}} {effect ufb_combat_critical_cooldown}}
{"action" {selector {source advanced}
{ignore_captured_by_user 1}
{group
 {select {tag {tag _ufb_combat_critical_actor_%player}}}
 {include {player {player "%player"}}
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
{tag {tag _ufb_suppress_actor_%player}}}
}} {action bazooka_shot} {target {ignore_captured_by_user 0} {tag _ufb_combat_critical_target_%player}}}
   {"delay" {time 1}}
   {"trigger" {name "ufb/combat/critical/apply %player"}}
  }
 }
)

; ap: one reserved pair per player; no drop-orders or fire-mode changes.
(define "ufb_combat_ap"
 {"ufb/combat/ap/acquire %player"
  {condition {terms {"1.see_actors" {selector {source advanced}
{ignore_captured_by_user 1}
{group
 {select {prop {prop human}}}
 {include {player {player "%player"}}
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
{tag {tag _ufb_suppress_actor_%player}}
{with_item {type using} {item "rocketlauncher"}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_combat_ap_cooldown}}
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_launcher_actor_%player}}
{tag {tag _ufb_combat_at_actor_%player}}
{tag {tag _ufb_combat_critical_actor_%player}}
{tag {tag _ufb_combat_ap_actor_%player}}
{tag {tag _ufb_combat_smoke_actor_%player}}
{tag {tag _ufb_combat_idle_actor_%player}}}
}
{amount 1}}
{enemy {source advanced}
{ignore_captured_by_user 0}
{group {select {prop {prop human}}} {include {relation {relation enemy} {player "%player"}}
{state {state operatable}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop airborne}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}}}}}
{distance {mode in_range} {min 14} {max 20}}
{detection visible}
{tag {"tag pair"} {"for selector" _ufb_combat_ap_actor_%player} {"for enemy" _ufb_combat_ap_target_%player}}}}}
  {actions
   {"effect" {selector {ignore_captured_by_user 0} {tag _ufb_combat_ap_actor_%player}} {effect ufb_reserve_job}}
   
   {"delay" {time 6}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_combat_ap_actor_%player}} {tag_remove _ufb_combat_ap_actor_%player}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_combat_ap_target_%player}} {tag_remove _ufb_combat_ap_target_%player}}
   {"delay" {time 2}}
   {"trigger" {name "ufb/combat/ap/acquire %player"}}
  }
 }
 {"ufb/combat/ap/apply %player"
  {condition {expression "1 & !2"} {terms
   {"1.see_actors" {selector {source advanced}
{ignore_captured_by_user 1}
{group
 {select {tag {tag _ufb_combat_ap_actor_%player}}}
 {include {player {player "%player"}}
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
{tag {tag _ufb_suppress_actor_%player}}
{with_item {type using} {item "rocketlauncher"}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_combat_ap_cooldown}}}
}}
{enemy {source advanced}
{ignore_captured_by_user 0}
{group {select {tag {tag _ufb_combat_ap_target_%player}}} {include {relation {relation enemy} {player "%player"}}
{state {state operatable}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop airborne}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}}}}}
{distance {mode in_range} {min 14} {max 20}}
{detection visible}}
   {"2.near" {units {ignore_captured_by_user 0} {tag _ufb_combat_ap_target_%player}}
{near_to {source advanced} {ignore_captured_by_user 0} {group {select {prop {prop human}}} {include {relation {relation ally} {player "%player"}} {state {state operatable}}} {exclude {state {state dead}}}}}
{distance 12}}
   
  }}
  {actions
   {"con" {text "[UFB combat] ap order: player %player"}}
   {"effect" {selector {source advanced}
{ignore_captured_by_user 1}
{group
 {select {tag {tag _ufb_combat_ap_actor_%player}}}
 {include {player {player "%player"}}
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
{tag {tag _ufb_suppress_actor_%player}}
{with_item {type using} {item "rocketlauncher"}}}
}} {effect ufb_combat_ap_cooldown}}
{"action" {selector {source advanced}
{ignore_captured_by_user 1}
{group
 {select {tag {tag _ufb_combat_ap_actor_%player}}}
 {include {player {player "%player"}}
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
{tag {tag _ufb_suppress_actor_%player}}
{with_item {type using} {item "rocketlauncher"}}}
}} {action throw_ap_grenade} {target {ignore_captured_by_user 0} {tag _ufb_combat_ap_target_%player}}}
   {"delay" {time 1}}
   {"trigger" {name "ufb/combat/ap/apply %player"}}
  }
 }
)

; smoke: one reserved pair per player; no drop-orders or fire-mode changes.
(define "ufb_combat_smoke"
 {"ufb/combat/smoke/acquire %player"
  {condition {terms {"1.see_actors" {selector {source advanced}
{ignore_captured_by_user 1}
{group
 {select {tag {tag _ufb_recent_hit}}}
 {include {player {player "%player"}}
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
{tag {tag _ufb_suppress_actor_%player}}
{with_item {type using} {item "rocketlauncher"}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_combat_smoke_cooldown}}
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_launcher_actor_%player}}
{tag {tag _ufb_combat_at_actor_%player}}
{tag {tag _ufb_combat_critical_actor_%player}}
{tag {tag _ufb_combat_ap_actor_%player}}
{tag {tag _ufb_combat_smoke_actor_%player}}
{tag {tag _ufb_combat_idle_actor_%player}}
{with_item {type existance} {item "m15_wp"}}
{with_item {type existance} {item "m42_wp"}}
{with_item {type existance} {item "no77_wp"}}}
}
{amount 1}}
{enemy {source advanced}
{ignore_captured_by_user 0}
{group {select {prop {prop vehicle}} {prop {prop tank}} {prop {prop car}} {prop {prop cannon}} {with_item {type using} {item "mgun"}}} {include {relation {relation enemy} {player "%player"}}
{state {state operatable}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop airborne}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}}}}}
{distance {mode in_range} {min 30} {max 110}}
{detection visible}
{tag {"tag pair"} {"for selector" _ufb_combat_smoke_actor_%player} {"for enemy" _ufb_combat_smoke_target_%player}}}}}
  {actions
   {"effect" {selector {ignore_captured_by_user 0} {tag _ufb_combat_smoke_actor_%player}} {effect ufb_reserve_job}}
   
   {"delay" {time 6}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_combat_smoke_actor_%player}} {tag_remove _ufb_combat_smoke_actor_%player}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_combat_smoke_target_%player}} {tag_remove _ufb_combat_smoke_target_%player}}
   {"delay" {time 2}}
   {"trigger" {name "ufb/combat/smoke/acquire %player"}}
  }
 }
 {"ufb/combat/smoke/apply %player"
  {condition {expression "1"} {terms
   {"1.see_actors" {selector {source advanced}
{ignore_captured_by_user 1}
{group
 {select {tag {tag _ufb_combat_smoke_actor_%player}}}
 {include {player {player "%player"}}
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
{tag {tag _ufb_suppress_actor_%player}}
{with_item {type using} {item "rocketlauncher"}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_combat_smoke_cooldown}}
{with_item {type existance} {item "m15_wp"}}
{with_item {type existance} {item "m42_wp"}}
{with_item {type existance} {item "no77_wp"}}}
}}
{enemy {source advanced}
{ignore_captured_by_user 0}
{group {select {tag {tag _ufb_combat_smoke_target_%player}}} {include {relation {relation enemy} {player "%player"}}
{state {state operatable}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop airborne}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}}}}}
{distance {mode in_range} {min 30} {max 110}}
{detection visible}}
   
   
  }}
  {actions
   {"con" {text "[UFB combat] smoke order: player %player"}}
   {"effect" {selector {source advanced}
{ignore_captured_by_user 1}
{group
 {select {tag {tag _ufb_combat_smoke_actor_%player}}}
 {include {player {player "%player"}}
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
{tag {tag _ufb_suppress_actor_%player}}
{with_item {type using} {item "rocketlauncher"}}
{with_item {type existance} {item "m15_wp"}}
{with_item {type existance} {item "m42_wp"}}
{with_item {type existance} {item "no77_wp"}}}
}} {effect ufb_combat_smoke_cooldown}}
{"effect" {selector {source advanced}
{ignore_captured_by_user 1}
{group
 {select {tag {tag _ufb_combat_smoke_actor_%player}}}
 {include {player {player "%player"}}
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
{tag {tag _ufb_suppress_actor_%player}}
{with_item {type using} {item "rocketlauncher"}}
{with_item {type existance} {item "m15_wp"}}
{with_item {type existance} {item "m42_wp"}}
{with_item {type existance} {item "no77_wp"}}}
}} {effect ufb_combat_smoke_point_%player}}
{"action" {selector {source advanced}
{ignore_captured_by_user 1}
{group
 {select {tag {tag _ufb_combat_smoke_actor_%player}}}
 {include {player {player "%player"}}
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
{tag {tag _ufb_suppress_actor_%player}}
{with_item {type using} {item "rocketlauncher"}}
{with_item {type existance} {item "m15_wp"}}
{with_item {type existance} {item "m42_wp"}}
{with_item {type existance} {item "no77_wp"}}}
}} {action throw_sk_grenade} {target {ignore_captured_by_user 0} {tag _ufb_combat_smoke_point_%player}}}
   {"delay" {time 1}}
   {"trigger" {name "ufb/combat/smoke/apply %player"}}
  }
 }
)

(define "ufb_combat_idle"
 {"ufb/combat/idle/acquire %player"
  {condition {terms {"1.entities" {selector {source advanced}
{ignore_captured_by_user 1}
{group
 {select {prop {prop human}}}
 {include {player {player "%player"}}
{prop {prop human}}
{state {state operatable}}
{with_item {type amount} {item "weapon bullet"} {min 1}}
{with_item {type using} {item "rocketlauncher"}}}
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
{tag {tag _ufb_suppress_actor_%player}}
{state {state user_control}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_combat_idle_cooldown}}
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_launcher_actor_%player}}
{tag {tag _ufb_combat_at_actor_%player}}
{tag {tag _ufb_combat_critical_actor_%player}}
{tag {tag _ufb_combat_ap_actor_%player}}
{tag {tag _ufb_combat_smoke_actor_%player}}
{tag {tag _ufb_combat_idle_actor_%player}}}
}
{amount 1}}}}}
  {actions
   {"entity_state" {selector {source advanced}
{ignore_captured_by_user 1}
{group
 {select {prop {prop human}}}
 {include {player {player "%player"}}
{prop {prop human}}
{state {state operatable}}
{with_item {type amount} {item "weapon bullet"} {min 1}}
{with_item {type using} {item "rocketlauncher"}}}
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
{tag {tag _ufb_suppress_actor_%player}}
{state {state user_control}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_combat_idle_cooldown}}
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_launcher_actor_%player}}
{tag {tag _ufb_combat_at_actor_%player}}
{tag {tag _ufb_combat_critical_actor_%player}}
{tag {tag _ufb_combat_ap_actor_%player}}
{tag {tag _ufb_combat_smoke_actor_%player}}
{tag {tag _ufb_combat_idle_actor_%player}}}
}
{amount 1}} {tag_add _ufb_combat_idle_actor_%player}}
   {"delay" {time 0.5}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_combat_idle_actor_%player}} {tag_remove _ufb_combat_idle_actor_%player}}
   {"delay" {time 1.5}}
   {"trigger" {name "ufb/combat/idle/acquire %player"}}
  }
 }
 {"ufb/combat/idle/apply %player"
  {condition {expression "1 & !3"} {terms
   {"1.entities" {selector {source advanced}
{ignore_captured_by_user 1}
{group
 {select {tag {tag _ufb_combat_idle_actor_%player}}}
 {include {player {player "%player"}}
{prop {prop human}}
{state {state operatable}}
{with_item {type amount} {item "weapon bullet"} {min 1}}
{with_item {type using} {item "rocketlauncher"}}}
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
{tag {tag _ufb_suppress_actor_%player}}
{state {state user_control}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_combat_idle_cooldown}}}
}}}
   {"2.see_actors" {selector {source advanced}
{ignore_captured_by_user 1}
{group
 {select {tag {tag _ufb_combat_idle_actor_%player}}}
 {include {player {player "%player"}}
{prop {prop human}}
{state {state operatable}}}
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
{tag {tag _ufb_suppress_actor_%player}}
{state {state user_control}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_combat_idle_cooldown}}}
}}
{enemy {source advanced}
{ignore_captured_by_user 0}
{group {select {prop {prop human}}} {include {relation {relation enemy} {player "%player"}}
{state {state operatable}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop airborne}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}}}}}
{distance {mode in_range} {min 0} {max 110}}
{detection visible}}
   {"3.see_actors" {selector {source advanced}
{ignore_captured_by_user 1}
{group
 {select {tag {tag _ufb_combat_idle_actor_%player}}}
 {include {player {player "%player"}}
{prop {prop human}}
{state {state operatable}}}
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
{tag {tag _ufb_suppress_actor_%player}}
{state {state user_control}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_combat_idle_cooldown}}}
}}
{enemy {source advanced}
{ignore_captured_by_user 0}
{group {select {prop {prop vehicle}} {prop {prop tank}} {prop {prop car}} {prop {prop cannon}}} {include {relation {relation enemy} {player "%player"}}
{state {state operatable}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop airborne}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}}}}}
{distance {mode in_range} {min 0} {max 110}}
{detection visible}}
  }}
  {actions
   {"inventory" {selector {source advanced}
{ignore_captured_by_user 1}
{group
 {select {tag {tag _ufb_combat_idle_actor_%player}}}
 {include {player {player "%player"}}
{prop {prop human}}
{state {state operatable}}
{with_item {type amount} {item "weapon bullet"} {min 1}}
{with_item {type using} {item "rocketlauncher"}}}
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
{tag {tag _ufb_suppress_actor_%player}}
{state {state user_control}}}
}} {action take} {item "weapon bullet"}}
   {"delay" {time 1}}
   {"trigger" {name "ufb/combat/idle/apply %player"}}
  }
 }
)

("ufb_combat_launcher" player(0))

("ufb_combat_at" player(0))

("ufb_combat_critical" player(0))

("ufb_combat_ap" player(0))

("ufb_combat_smoke" player(0))

("ufb_combat_idle" player(0))

("ufb_combat_launcher" player(1))

("ufb_combat_at" player(1))

("ufb_combat_critical" player(1))

("ufb_combat_ap" player(1))

("ufb_combat_smoke" player(1))

("ufb_combat_idle" player(1))

("ufb_combat_launcher" player(2))

("ufb_combat_at" player(2))

("ufb_combat_critical" player(2))

("ufb_combat_ap" player(2))

("ufb_combat_smoke" player(2))

("ufb_combat_idle" player(2))

("ufb_combat_launcher" player(3))

("ufb_combat_at" player(3))

("ufb_combat_critical" player(3))

("ufb_combat_ap" player(3))

("ufb_combat_smoke" player(3))

("ufb_combat_idle" player(3))

("ufb_combat_launcher" player(4))

("ufb_combat_at" player(4))

("ufb_combat_critical" player(4))

("ufb_combat_ap" player(4))

("ufb_combat_smoke" player(4))

("ufb_combat_idle" player(4))

("ufb_combat_launcher" player(5))

("ufb_combat_at" player(5))

("ufb_combat_critical" player(5))

("ufb_combat_ap" player(5))

("ufb_combat_smoke" player(5))

("ufb_combat_idle" player(5))

("ufb_combat_launcher" player(6))

("ufb_combat_at" player(6))

("ufb_combat_critical" player(6))

("ufb_combat_ap" player(6))

("ufb_combat_smoke" player(6))

("ufb_combat_idle" player(6))

("ufb_combat_launcher" player(7))

("ufb_combat_at" player(7))

("ufb_combat_critical" player(7))

("ufb_combat_ap" player(7))

("ufb_combat_smoke" player(7))

("ufb_combat_idle" player(7))

("ufb_combat_launcher" player(8))

("ufb_combat_at" player(8))

("ufb_combat_critical" player(8))

("ufb_combat_ap" player(8))

("ufb_combat_smoke" player(8))

("ufb_combat_idle" player(8))

("ufb_combat_launcher" player(9))

("ufb_combat_at" player(9))

("ufb_combat_critical" player(9))

("ufb_combat_ap" player(9))

("ufb_combat_smoke" player(9))

("ufb_combat_idle" player(9))

("ufb_combat_launcher" player(10))

("ufb_combat_at" player(10))

("ufb_combat_critical" player(10))

("ufb_combat_ap" player(10))

("ufb_combat_smoke" player(10))

("ufb_combat_idle" player(10))

("ufb_combat_launcher" player(11))

("ufb_combat_at" player(11))

("ufb_combat_critical" player(11))

("ufb_combat_ap" player(11))

("ufb_combat_smoke" player(11))

("ufb_combat_idle" player(11))

("ufb_combat_launcher" player(12))

("ufb_combat_at" player(12))

("ufb_combat_critical" player(12))

("ufb_combat_ap" player(12))

("ufb_combat_smoke" player(12))

("ufb_combat_idle" player(12))

("ufb_combat_launcher" player(13))

("ufb_combat_at" player(13))

("ufb_combat_critical" player(13))

("ufb_combat_ap" player(13))

("ufb_combat_smoke" player(13))

("ufb_combat_idle" player(13))

("ufb_combat_launcher" player(14))

("ufb_combat_at" player(14))

("ufb_combat_critical" player(14))

("ufb_combat_ap" player(14))

("ufb_combat_smoke" player(14))

("ufb_combat_idle" player(14))

("ufb_combat_launcher" player(15))

("ufb_combat_at" player(15))

("ufb_combat_critical" player(15))

("ufb_combat_ap" player(15))

("ufb_combat_smoke" player(15))

("ufb_combat_idle" player(15))

("ufb_combat_launcher" player(16))

("ufb_combat_at" player(16))

("ufb_combat_critical" player(16))

("ufb_combat_ap" player(16))

("ufb_combat_smoke" player(16))

("ufb_combat_idle" player(16))
(include "/map/multi/ufb_infantry_support.inc")
