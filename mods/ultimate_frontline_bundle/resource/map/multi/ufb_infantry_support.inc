; Native properties preserve the engine's inventory, medic and manual-order rules.
; Each switch is enabled once; the player's later auto-medic toggle remains effective.

{"ufb/support/native pickup"
 {condition {terms {"1.entities" {selector {source advanced} {ignore_captured_by_user 0} {group
 {select {prop {prop human}}}
 {include {prop {prop human}} {state {state user_control}} {state {state operatable}}}
 {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {tag {tag _ufb_native_pickup_initialized}}}}}}}}
 {actions
  {"actor_state" {selector {source advanced} {ignore_captured_by_user 0} {group
 {select {prop {prop human}}}
 {include {prop {prop human}} {state {state user_control}} {state {state operatable}}}
 {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {tag {tag _ufb_native_pickup_initialized}}}}} {ai {take_new_weapon_from_ground on}}}
  {"entity_state" {selector {source advanced} {ignore_captured_by_user 0} {group
 {select {prop {prop human}}}
 {include {prop {prop human}} {state {state user_control}} {state {state operatable}}}
 {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {tag {tag _ufb_native_pickup_initialized}}}}} {tag_add _ufb_native_pickup_initialized}}
  {"con" {text "[UFB support] initialized native pickup"}}
  {"delay" {time 2}}
  {"trigger" {name "ufb/support/native pickup"}}
 }
}

{"ufb/support/native medic"
 {condition {terms {"1.entities" {selector {source advanced} {ignore_captured_by_user 0} {group
 {select {tag {tag medic}}}
 {include {prop {prop human}} {state {state user_control}} {state {state operatable}}}
 {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {tag {tag _ufb_native_medic_initialized}}}}}}}}
 {actions
  {"actor_state" {selector {source advanced} {ignore_captured_by_user 0} {group
 {select {tag {tag medic}}}
 {include {prop {prop human}} {state {state user_control}} {state {state operatable}}}
 {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {tag {tag _ufb_native_medic_initialized}}}}} {ai {auto_medic on}}}
  {"entity_state" {selector {source advanced} {ignore_captured_by_user 0} {group
 {select {tag {tag medic}}}
 {include {prop {prop human}} {state {state user_control}} {state {state operatable}}}
 {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {tag {tag _ufb_native_medic_initialized}}}}} {tag_add _ufb_native_medic_initialized}}
  {"con" {text "[UFB support] initialized native medic"}}
  {"delay" {time 2}}
  {"trigger" {name "ufb/support/native medic"}}
 }
}

(define "ufb_player_body_loot"
 {"ufb/support/loot %weapon/acquire %player"
  {condition {terms {"1.see_actors"
   {selector {source advanced} {ignore_captured_by_user 1}
 {group {select {prop {prop human}}}
 {include {prop {prop human}} {state {state operatable}} {player {player "%player"}} {with_item {type existance} {item "rifle"}} {with_item {type using} {item "rifle"}} {state {state user_control}}}
 {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} {prop {prop repairing}} {prop {prop throwing}}
 {tag {tag _lua_mi}} {tag {tag _lua_ignore}} {tag {tag _ai_do_not_disturb}} {tag {tag repairing}} {tag {tag reloading}} {tag {tag bleeding}} {tag {tag _bleeding}} {tag {tag wounded}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag medic}} {tag {tag _ai_medic}} {tag {tag bot_medic}} {tag {tag _ufb_healing_active}} {tag {tag _ufb_autonomy_moving}} {tag {tag _ai_wounded_carrier}} {tag {tag _ai_ap_grenade}} {tag {tag _ai_at_grenade}} {tag {tag _ai_smoke_grenade}} {tag {tag _ai_suppressed_by_mg}} {tag {tag _ai_mgunner}} {tag {tag _ai_reloading}} {tag {tag _ai_looting_weapon}} {tag {tag crew}} {tag {tag tcrew}} {tag {tag ecrew}} {tag {tag ecrew_a}} {tag {tag ecrew_b}} {tag {tag bot_arty}} {tag {tag bot_aa_guard}} {tag {tag _ufb_crew_safe}} {tag {tag _ufb_hf_cover_active}} {tag {tag _ai_wirecutter_in_action}} {tag {tag bot_inf_flank_in_progress}} {tag {tag _ufb_smoke_120m_actor}} {tag {tag _ufb_smoke_60m_actor}} {tag {tag _ufb_smoke_wirecutter_actor}} {tag {tag _ai_at_launcher_30}} {tag {tag _ai_at_launcher_40}} {tag {tag _ai_at_launcher_50}} {tag {tag _ai_at_launcher_60}} {tag {tag _ai_at_launcher_70}} {tag {tag _ai_at_launcher_80}} {tag {tag _ai_at_launcher_90}} {tag {tag _ufb_combat_busy}}
 {with_item {type existance} {item "sniper"}} {with_item {type using} {item "rocketlauncher"}} {with_item {type existance} {item "loot_riflegrenade"}} {with_item {type existance} {item "loot_atrifle"}} {with_item {type existance} {item "loot_mgun"}} {with_item {type existance} {item "loot_assaultrifle"}} {with_item {type existance} {item "loot_battlerifle"}} {with_item {type existance} {item "loot_autorifle"}} {with_item {type existance} {item "loot_semirifle"}} {tag {tag _ufb_loot_cooldown}}
 {tag {tag _ufb_job_reserved}} {tag {tag _ufb_suppress_actor_%player}} {tag {tag _ufb_loot_mgun_actor_%player}} {tag {tag _ufb_loot_assaultrifle_actor_%player}} {tag {tag _ufb_loot_battlerifle_actor_%player}} {tag {tag _ufb_loot_autorifle_actor_%player}} {tag {tag _ufb_loot_semirifle_actor_%player}} {tag {tag _ufb_combat_launcher_actor_%player}} {tag {tag _ufb_combat_at_actor_%player}} {tag {tag _ufb_combat_critical_actor_%player}} {tag {tag _ufb_combat_ap_actor_%player}} {tag {tag _ufb_combat_smoke_actor_%player}}
 }}}
   {enemy {source advanced} {ignore_captured_by_user 0} {group {select {prop {prop human}}} {include {state {state dead}} {with_item {type existance} {item "loot_%weapon"}}} {exclude {state {state linked}} {tag {tag hidden}} {tag {tag _ai_wounded_target_linked}} {tag {tag bleeding}} {tag {tag start_personage}} {tag {tag wounded_animation_playing}}}}}
   {distance {mode near_than} {meters 3}}
   {tag {"tag pair"} {"for selector" _ufb_loot_%weapon_actor_%player} {"for enemy" _ufb_loot_%weapon_body_%player}}
  }}}
  {actions
   {"effect" {selector {ignore_captured_by_user 0} {tag _ufb_loot_%weapon_actor_%player}} {effect ufb_reserve_job}}
   {"delay" {time 1}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_loot_%weapon_actor_%player}} {tag_remove _ufb_job_reserved}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_loot_%weapon_actor_%player}} {tag_remove _ufb_loot_%weapon_actor_%player}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_loot_%weapon_body_%player}} {tag_remove _ufb_loot_%weapon_body_%player}}
   {"delay" {time 8}}
   {"trigger" {name "ufb/support/loot %weapon/acquire %player"}}
  }
 }
 {"ufb/support/loot %weapon/apply %player"
  {condition {expression "1 & !2"} {terms
   {"1.near" {units {source advanced} {ignore_captured_by_user 1}
 {group {select {tag {tag _ufb_loot_%weapon_actor_%player}}}
 {include {prop {prop human}} {state {state operatable}} {player {player "%player"}} {with_item {type existance} {item "rifle"}} {with_item {type using} {item "rifle"}} {state {state user_control}}}
 {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} {prop {prop repairing}} {prop {prop throwing}}
 {tag {tag _lua_mi}} {tag {tag _lua_ignore}} {tag {tag _ai_do_not_disturb}} {tag {tag repairing}} {tag {tag reloading}} {tag {tag bleeding}} {tag {tag _bleeding}} {tag {tag wounded}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag medic}} {tag {tag _ai_medic}} {tag {tag bot_medic}} {tag {tag _ufb_healing_active}} {tag {tag _ufb_autonomy_moving}} {tag {tag _ai_wounded_carrier}} {tag {tag _ai_ap_grenade}} {tag {tag _ai_at_grenade}} {tag {tag _ai_smoke_grenade}} {tag {tag _ai_suppressed_by_mg}} {tag {tag _ai_mgunner}} {tag {tag _ai_reloading}} {tag {tag _ai_looting_weapon}} {tag {tag crew}} {tag {tag tcrew}} {tag {tag ecrew}} {tag {tag ecrew_a}} {tag {tag ecrew_b}} {tag {tag bot_arty}} {tag {tag bot_aa_guard}} {tag {tag _ufb_crew_safe}} {tag {tag _ufb_hf_cover_active}} {tag {tag _ai_wirecutter_in_action}} {tag {tag bot_inf_flank_in_progress}} {tag {tag _ufb_smoke_120m_actor}} {tag {tag _ufb_smoke_60m_actor}} {tag {tag _ufb_smoke_wirecutter_actor}} {tag {tag _ai_at_launcher_30}} {tag {tag _ai_at_launcher_40}} {tag {tag _ai_at_launcher_50}} {tag {tag _ai_at_launcher_60}} {tag {tag _ai_at_launcher_70}} {tag {tag _ai_at_launcher_80}} {tag {tag _ai_at_launcher_90}} {tag {tag _ufb_combat_busy}}
 {with_item {type existance} {item "sniper"}} {with_item {type using} {item "rocketlauncher"}} {with_item {type existance} {item "loot_riflegrenade"}} {with_item {type existance} {item "loot_atrifle"}} {with_item {type existance} {item "loot_mgun"}} {with_item {type existance} {item "loot_assaultrifle"}} {with_item {type existance} {item "loot_battlerifle"}} {with_item {type existance} {item "loot_autorifle"}} {with_item {type existance} {item "loot_semirifle"}} {tag {tag _ufb_loot_cooldown}}
 
 }}} {near_to {source advanced} {ignore_captured_by_user 0} {group {select {tag {tag _ufb_loot_%weapon_body_%player}}} {include {state {state dead}} {with_item {type existance} {item "loot_%weapon"}}} {exclude {state {state linked}} {tag {tag bleeding}} {tag {tag start_personage}} {tag {tag wounded_animation_playing}}}}} {distance 3}}
   {"2.see_actors" {selector {source advanced} {ignore_captured_by_user 1}
 {group {select {tag {tag _ufb_loot_%weapon_actor_%player}}}
 {include {prop {prop human}} {state {state operatable}} {player {player "%player"}} {with_item {type existance} {item "rifle"}} {with_item {type using} {item "rifle"}} {state {state user_control}}}
 {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} {prop {prop repairing}} {prop {prop throwing}}
 {tag {tag _lua_mi}} {tag {tag _lua_ignore}} {tag {tag _ai_do_not_disturb}} {tag {tag repairing}} {tag {tag reloading}} {tag {tag bleeding}} {tag {tag _bleeding}} {tag {tag wounded}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag medic}} {tag {tag _ai_medic}} {tag {tag bot_medic}} {tag {tag _ufb_healing_active}} {tag {tag _ufb_autonomy_moving}} {tag {tag _ai_wounded_carrier}} {tag {tag _ai_ap_grenade}} {tag {tag _ai_at_grenade}} {tag {tag _ai_smoke_grenade}} {tag {tag _ai_suppressed_by_mg}} {tag {tag _ai_mgunner}} {tag {tag _ai_reloading}} {tag {tag _ai_looting_weapon}} {tag {tag crew}} {tag {tag tcrew}} {tag {tag ecrew}} {tag {tag ecrew_a}} {tag {tag ecrew_b}} {tag {tag bot_arty}} {tag {tag bot_aa_guard}} {tag {tag _ufb_crew_safe}} {tag {tag _ufb_hf_cover_active}} {tag {tag _ai_wirecutter_in_action}} {tag {tag bot_inf_flank_in_progress}} {tag {tag _ufb_smoke_120m_actor}} {tag {tag _ufb_smoke_60m_actor}} {tag {tag _ufb_smoke_wirecutter_actor}} {tag {tag _ai_at_launcher_30}} {tag {tag _ai_at_launcher_40}} {tag {tag _ai_at_launcher_50}} {tag {tag _ai_at_launcher_60}} {tag {tag _ai_at_launcher_70}} {tag {tag _ai_at_launcher_80}} {tag {tag _ai_at_launcher_90}} {tag {tag _ufb_combat_busy}}
 {with_item {type existance} {item "sniper"}} {with_item {type using} {item "rocketlauncher"}} {with_item {type existance} {item "loot_riflegrenade"}} {with_item {type existance} {item "loot_atrifle"}} {with_item {type existance} {item "loot_mgun"}} {with_item {type existance} {item "loot_assaultrifle"}} {with_item {type existance} {item "loot_battlerifle"}} {with_item {type existance} {item "loot_autorifle"}} {with_item {type existance} {item "loot_semirifle"}} {tag {tag _ufb_loot_cooldown}}
 
 }}}
    {enemy {source advanced} {ignore_captured_by_user 0} {group {select {prop {prop human}} {prop {prop vehicle}}} {include {state {state operatable}} {relation {relation enemy} {player "%player"}}} {exclude {state {state dead}} {state {state inactive}}}}}
    {distance {mode near_than} {meters 30}} {detection visible}
   }
  }}
  {actions
   {"inventory" {selector {source advanced} {ignore_captured_by_user 1}
 {group {select {tag {tag _ufb_loot_%weapon_actor_%player}}}
 {include {prop {prop human}} {state {state operatable}} {player {player "%player"}} {with_item {type existance} {item "rifle"}} {with_item {type using} {item "rifle"}} {state {state user_control}}}
 {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} {prop {prop repairing}} {prop {prop throwing}}
 {tag {tag _lua_mi}} {tag {tag _lua_ignore}} {tag {tag _ai_do_not_disturb}} {tag {tag repairing}} {tag {tag reloading}} {tag {tag bleeding}} {tag {tag _bleeding}} {tag {tag wounded}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag medic}} {tag {tag _ai_medic}} {tag {tag bot_medic}} {tag {tag _ufb_healing_active}} {tag {tag _ufb_autonomy_moving}} {tag {tag _ai_wounded_carrier}} {tag {tag _ai_ap_grenade}} {tag {tag _ai_at_grenade}} {tag {tag _ai_smoke_grenade}} {tag {tag _ai_suppressed_by_mg}} {tag {tag _ai_mgunner}} {tag {tag _ai_reloading}} {tag {tag _ai_looting_weapon}} {tag {tag crew}} {tag {tag tcrew}} {tag {tag ecrew}} {tag {tag ecrew_a}} {tag {tag ecrew_b}} {tag {tag bot_arty}} {tag {tag bot_aa_guard}} {tag {tag _ufb_crew_safe}} {tag {tag _ufb_hf_cover_active}} {tag {tag _ai_wirecutter_in_action}} {tag {tag bot_inf_flank_in_progress}} {tag {tag _ufb_smoke_120m_actor}} {tag {tag _ufb_smoke_60m_actor}} {tag {tag _ufb_smoke_wirecutter_actor}} {tag {tag _ai_at_launcher_30}} {tag {tag _ai_at_launcher_40}} {tag {tag _ai_at_launcher_50}} {tag {tag _ai_at_launcher_60}} {tag {tag _ai_at_launcher_70}} {tag {tag _ai_at_launcher_80}} {tag {tag _ai_at_launcher_90}} {tag {tag _ufb_combat_busy}}
 {with_item {type existance} {item "sniper"}} {with_item {type using} {item "rocketlauncher"}} {with_item {type existance} {item "loot_riflegrenade"}} {with_item {type existance} {item "loot_atrifle"}} {with_item {type existance} {item "loot_mgun"}} {with_item {type existance} {item "loot_assaultrifle"}} {with_item {type existance} {item "loot_battlerifle"}} {with_item {type existance} {item "loot_autorifle"}} {with_item {type existance} {item "loot_semirifle"}} {tag {tag _ufb_loot_cooldown}}
 
 }}} {action take_from} {item "loot_%weapon"}
    {entity {source advanced} {ignore_captured_by_user 0} {group {select {tag {tag _ufb_loot_%weapon_body_%player}}} {include {state {state dead}} {with_item {type existance} {item "loot_%weapon"}}} {exclude {state {state linked}} {tag {tag bleeding}} {tag {tag start_personage}} {tag {tag wounded_animation_playing}}}}}
   }
   {"effect" {selector {source advanced} {ignore_captured_by_user 1} {group {select {tag {tag _ufb_loot_%weapon_actor_%player}}} {include {with_item {type existance} {item "loot_%weapon"}}}}} {effect ufb_loot_cooldown}}
   {"con" {text "[UFB support] corpse weapon pickup order: %weapon, player %player"}}
   {"delay" {time 2}}
   {"trigger" {name "ufb/support/loot %weapon/apply %player"}}
  }
 }
)
("ufb_player_body_loot" player(0) weapon(mgun))
("ufb_player_body_loot" player(0) weapon(assaultrifle))
("ufb_player_body_loot" player(0) weapon(battlerifle))
("ufb_player_body_loot" player(0) weapon(autorifle))
("ufb_player_body_loot" player(0) weapon(semirifle))
("ufb_player_body_loot" player(1) weapon(mgun))
("ufb_player_body_loot" player(1) weapon(assaultrifle))
("ufb_player_body_loot" player(1) weapon(battlerifle))
("ufb_player_body_loot" player(1) weapon(autorifle))
("ufb_player_body_loot" player(1) weapon(semirifle))
("ufb_player_body_loot" player(2) weapon(mgun))
("ufb_player_body_loot" player(2) weapon(assaultrifle))
("ufb_player_body_loot" player(2) weapon(battlerifle))
("ufb_player_body_loot" player(2) weapon(autorifle))
("ufb_player_body_loot" player(2) weapon(semirifle))
("ufb_player_body_loot" player(3) weapon(mgun))
("ufb_player_body_loot" player(3) weapon(assaultrifle))
("ufb_player_body_loot" player(3) weapon(battlerifle))
("ufb_player_body_loot" player(3) weapon(autorifle))
("ufb_player_body_loot" player(3) weapon(semirifle))
("ufb_player_body_loot" player(4) weapon(mgun))
("ufb_player_body_loot" player(4) weapon(assaultrifle))
("ufb_player_body_loot" player(4) weapon(battlerifle))
("ufb_player_body_loot" player(4) weapon(autorifle))
("ufb_player_body_loot" player(4) weapon(semirifle))
("ufb_player_body_loot" player(5) weapon(mgun))
("ufb_player_body_loot" player(5) weapon(assaultrifle))
("ufb_player_body_loot" player(5) weapon(battlerifle))
("ufb_player_body_loot" player(5) weapon(autorifle))
("ufb_player_body_loot" player(5) weapon(semirifle))
("ufb_player_body_loot" player(6) weapon(mgun))
("ufb_player_body_loot" player(6) weapon(assaultrifle))
("ufb_player_body_loot" player(6) weapon(battlerifle))
("ufb_player_body_loot" player(6) weapon(autorifle))
("ufb_player_body_loot" player(6) weapon(semirifle))
("ufb_player_body_loot" player(7) weapon(mgun))
("ufb_player_body_loot" player(7) weapon(assaultrifle))
("ufb_player_body_loot" player(7) weapon(battlerifle))
("ufb_player_body_loot" player(7) weapon(autorifle))
("ufb_player_body_loot" player(7) weapon(semirifle))
("ufb_player_body_loot" player(8) weapon(mgun))
("ufb_player_body_loot" player(8) weapon(assaultrifle))
("ufb_player_body_loot" player(8) weapon(battlerifle))
("ufb_player_body_loot" player(8) weapon(autorifle))
("ufb_player_body_loot" player(8) weapon(semirifle))
("ufb_player_body_loot" player(9) weapon(mgun))
("ufb_player_body_loot" player(9) weapon(assaultrifle))
("ufb_player_body_loot" player(9) weapon(battlerifle))
("ufb_player_body_loot" player(9) weapon(autorifle))
("ufb_player_body_loot" player(9) weapon(semirifle))
("ufb_player_body_loot" player(10) weapon(mgun))
("ufb_player_body_loot" player(10) weapon(assaultrifle))
("ufb_player_body_loot" player(10) weapon(battlerifle))
("ufb_player_body_loot" player(10) weapon(autorifle))
("ufb_player_body_loot" player(10) weapon(semirifle))
("ufb_player_body_loot" player(11) weapon(mgun))
("ufb_player_body_loot" player(11) weapon(assaultrifle))
("ufb_player_body_loot" player(11) weapon(battlerifle))
("ufb_player_body_loot" player(11) weapon(autorifle))
("ufb_player_body_loot" player(11) weapon(semirifle))
("ufb_player_body_loot" player(12) weapon(mgun))
("ufb_player_body_loot" player(12) weapon(assaultrifle))
("ufb_player_body_loot" player(12) weapon(battlerifle))
("ufb_player_body_loot" player(12) weapon(autorifle))
("ufb_player_body_loot" player(12) weapon(semirifle))
("ufb_player_body_loot" player(13) weapon(mgun))
("ufb_player_body_loot" player(13) weapon(assaultrifle))
("ufb_player_body_loot" player(13) weapon(battlerifle))
("ufb_player_body_loot" player(13) weapon(autorifle))
("ufb_player_body_loot" player(13) weapon(semirifle))
("ufb_player_body_loot" player(14) weapon(mgun))
("ufb_player_body_loot" player(14) weapon(assaultrifle))
("ufb_player_body_loot" player(14) weapon(battlerifle))
("ufb_player_body_loot" player(14) weapon(autorifle))
("ufb_player_body_loot" player(14) weapon(semirifle))
("ufb_player_body_loot" player(15) weapon(mgun))
("ufb_player_body_loot" player(15) weapon(assaultrifle))
("ufb_player_body_loot" player(15) weapon(battlerifle))
("ufb_player_body_loot" player(15) weapon(autorifle))
("ufb_player_body_loot" player(15) weapon(semirifle))
("ufb_player_body_loot" player(16) weapon(mgun))
("ufb_player_body_loot" player(16) weapon(assaultrifle))
("ufb_player_body_loot" player(16) weapon(battlerifle))
("ufb_player_body_loot" player(16) weapon(autorifle))
("ufb_player_body_loot" player(16) weapon(semirifle))

; A point is sampled while the target is visible. Later fire never targets or
; follows the hidden soldier. Three ordinary bursts at 0/2/4 seconds at most.
(define "ufb_mg_suppress"
 {"ufb/suppress/acquire %player"
  {condition {terms {"1.see_actors"
   {selector {source advanced} {ignore_captured_by_user 1}
 {group {select {prop {prop human}}}
 {include {prop {prop human}} {state {state operatable}} {player {player "%player"}}  {with_item {type using} {item "mgun"}} {prop {prop shooting}}}
 {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} {prop {prop repairing}} {prop {prop throwing}}
 {tag {tag _lua_mi}} {tag {tag _lua_ignore}} {tag {tag _ai_do_not_disturb}} {tag {tag repairing}} {tag {tag reloading}} {tag {tag bleeding}} {tag {tag _bleeding}} {tag {tag wounded}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag medic}} {tag {tag _ai_medic}} {tag {tag bot_medic}} {tag {tag _ufb_healing_active}} {tag {tag _ufb_autonomy_moving}} {tag {tag _ai_wounded_carrier}} {tag {tag _ai_ap_grenade}} {tag {tag _ai_at_grenade}} {tag {tag _ai_smoke_grenade}} {tag {tag _ai_suppressed_by_mg}} {tag {tag _ai_mgunner}} {tag {tag _ai_reloading}} {tag {tag _ai_looting_weapon}} {tag {tag crew}} {tag {tag tcrew}} {tag {tag ecrew}} {tag {tag ecrew_a}} {tag {tag ecrew_b}} {tag {tag bot_arty}} {tag {tag bot_aa_guard}} {tag {tag _ufb_crew_safe}} {tag {tag _ufb_hf_cover_active}} {tag {tag _ai_wirecutter_in_action}} {tag {tag bot_inf_flank_in_progress}} {tag {tag _ufb_smoke_120m_actor}} {tag {tag _ufb_smoke_60m_actor}} {tag {tag _ufb_smoke_wirecutter_actor}} {tag {tag _ai_at_launcher_30}} {tag {tag _ai_at_launcher_40}} {tag {tag _ai_at_launcher_50}} {tag {tag _ai_at_launcher_60}} {tag {tag _ai_at_launcher_70}} {tag {tag _ai_at_launcher_80}} {tag {tag _ai_at_launcher_90}} {tag {tag _ufb_combat_busy}}
 {tag {tag _ufb_suppress_cooldown}} {tag {tag _ufb_loot_actor_%player}}
 {tag {tag _ufb_job_reserved}} {tag {tag _ufb_suppress_actor_%player}} {tag {tag _ufb_loot_mgun_actor_%player}} {tag {tag _ufb_loot_assaultrifle_actor_%player}} {tag {tag _ufb_loot_battlerifle_actor_%player}} {tag {tag _ufb_loot_autorifle_actor_%player}} {tag {tag _ufb_loot_semirifle_actor_%player}} {tag {tag _ufb_combat_launcher_actor_%player}} {tag {tag _ufb_combat_at_actor_%player}} {tag {tag _ufb_combat_critical_actor_%player}} {tag {tag _ufb_combat_ap_actor_%player}} {tag {tag _ufb_combat_smoke_actor_%player}}
 }}}
   {enemy {source advanced} {ignore_captured_by_user 0} {group {select {prop {prop human}}} {include {state {state operatable}} {relation {relation enemy} {player "%player"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}}
   {distance {mode in_range} {min 20} {max 120}} {detection visible}
   {tag {"tag pair"} {"for selector" _ufb_suppress_actor_%player} {"for enemy" _ufb_suppress_enemy_%player}}
  }}}
  {actions
   {"effect" {selector {amount 1} {ignore_captured_by_user 0} {tag _ufb_suppress_enemy_%player}} {effect ufb_suppress_point_%player}}
   {"switch"
    {"case" {condition {type entities} {selector {ignore_captured_by_user 0} {tag _ufb_suppress_point_%player}}}
     {"effect" {selector {ignore_captured_by_user 0} {tag _ufb_suppress_actor_%player}} {effect ufb_reserve_job}}
    }
    {"default"
     {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_suppress_actor_%player}} {tag_remove _ufb_suppress_actor_%player}}
     {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_suppress_enemy_%player}} {tag_remove _ufb_suppress_enemy_%player}}
    }
   }
   {"delay" {time 6}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_suppress_actor_%player}} {tag_remove _ufb_suppress_actor_%player}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_suppress_enemy_%player}} {tag_remove _ufb_suppress_enemy_%player}}
   {"delay" {time 4}}
   {"trigger" {name "ufb/suppress/acquire %player"}}
  }
 }
 {"ufb/suppress/apply %player"
  {condition {expression "1 & 2 & !3 & !4"} {terms
   {"1.entities" {selector {source advanced} {ignore_captured_by_user 1}
 {group {select {tag {tag _ufb_suppress_actor_%player}}}
 {include {prop {prop human}} {state {state operatable}} {player {player "%player"}}  {with_item {type using} {item "mgun"}} }
 {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} {prop {prop repairing}} {prop {prop throwing}}
 {tag {tag _lua_mi}} {tag {tag _lua_ignore}} {tag {tag _ai_do_not_disturb}} {tag {tag repairing}} {tag {tag reloading}} {tag {tag bleeding}} {tag {tag _bleeding}} {tag {tag wounded}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag medic}} {tag {tag _ai_medic}} {tag {tag bot_medic}} {tag {tag _ufb_healing_active}} {tag {tag _ufb_autonomy_moving}} {tag {tag _ai_wounded_carrier}} {tag {tag _ai_ap_grenade}} {tag {tag _ai_at_grenade}} {tag {tag _ai_smoke_grenade}} {tag {tag _ai_suppressed_by_mg}} {tag {tag _ai_mgunner}} {tag {tag _ai_reloading}} {tag {tag _ai_looting_weapon}} {tag {tag crew}} {tag {tag tcrew}} {tag {tag ecrew}} {tag {tag ecrew_a}} {tag {tag ecrew_b}} {tag {tag bot_arty}} {tag {tag bot_aa_guard}} {tag {tag _ufb_crew_safe}} {tag {tag _ufb_hf_cover_active}} {tag {tag _ai_wirecutter_in_action}} {tag {tag bot_inf_flank_in_progress}} {tag {tag _ufb_smoke_120m_actor}} {tag {tag _ufb_smoke_60m_actor}} {tag {tag _ufb_smoke_wirecutter_actor}} {tag {tag _ai_at_launcher_30}} {tag {tag _ai_at_launcher_40}} {tag {tag _ai_at_launcher_50}} {tag {tag _ai_at_launcher_60}} {tag {tag _ai_at_launcher_70}} {tag {tag _ai_at_launcher_80}} {tag {tag _ai_at_launcher_90}} {tag {tag _ufb_combat_busy}}
 {tag {tag _ufb_suppress_cooldown}} {tag {tag _ufb_loot_actor_%player}}
 
 }}}}
   {"2.near" {units {source advanced} {ignore_captured_by_user 1}
 {group {select {tag {tag _ufb_suppress_actor_%player}}}
 {include {prop {prop human}} {state {state operatable}} {player {player "%player"}}  {with_item {type using} {item "mgun"}} }
 {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} {prop {prop repairing}} {prop {prop throwing}}
 {tag {tag _lua_mi}} {tag {tag _lua_ignore}} {tag {tag _ai_do_not_disturb}} {tag {tag repairing}} {tag {tag reloading}} {tag {tag bleeding}} {tag {tag _bleeding}} {tag {tag wounded}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag medic}} {tag {tag _ai_medic}} {tag {tag bot_medic}} {tag {tag _ufb_healing_active}} {tag {tag _ufb_autonomy_moving}} {tag {tag _ai_wounded_carrier}} {tag {tag _ai_ap_grenade}} {tag {tag _ai_at_grenade}} {tag {tag _ai_smoke_grenade}} {tag {tag _ai_suppressed_by_mg}} {tag {tag _ai_mgunner}} {tag {tag _ai_reloading}} {tag {tag _ai_looting_weapon}} {tag {tag crew}} {tag {tag tcrew}} {tag {tag ecrew}} {tag {tag ecrew_a}} {tag {tag ecrew_b}} {tag {tag bot_arty}} {tag {tag bot_aa_guard}} {tag {tag _ufb_crew_safe}} {tag {tag _ufb_hf_cover_active}} {tag {tag _ai_wirecutter_in_action}} {tag {tag bot_inf_flank_in_progress}} {tag {tag _ufb_smoke_120m_actor}} {tag {tag _ufb_smoke_60m_actor}} {tag {tag _ufb_smoke_wirecutter_actor}} {tag {tag _ai_at_launcher_30}} {tag {tag _ai_at_launcher_40}} {tag {tag _ai_at_launcher_50}} {tag {tag _ai_at_launcher_60}} {tag {tag _ai_at_launcher_70}} {tag {tag _ai_at_launcher_80}} {tag {tag _ai_at_launcher_90}} 
 
 
 }}} {near_to {ignore_captured_by_user 0} {tag _ufb_suppress_point_%player}} {distance 120}}
   {"3.near" {units {source advanced} {ignore_captured_by_user 1}
 {group {select {tag {tag _ufb_suppress_actor_%player}}}
 {include {prop {prop human}} {state {state operatable}} {player {player "%player"}}  {with_item {type using} {item "mgun"}} }
 {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} {prop {prop repairing}} {prop {prop throwing}}
 {tag {tag _lua_mi}} {tag {tag _lua_ignore}} {tag {tag _ai_do_not_disturb}} {tag {tag repairing}} {tag {tag reloading}} {tag {tag bleeding}} {tag {tag _bleeding}} {tag {tag wounded}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag medic}} {tag {tag _ai_medic}} {tag {tag bot_medic}} {tag {tag _ufb_healing_active}} {tag {tag _ufb_autonomy_moving}} {tag {tag _ai_wounded_carrier}} {tag {tag _ai_ap_grenade}} {tag {tag _ai_at_grenade}} {tag {tag _ai_smoke_grenade}} {tag {tag _ai_suppressed_by_mg}} {tag {tag _ai_mgunner}} {tag {tag _ai_reloading}} {tag {tag _ai_looting_weapon}} {tag {tag crew}} {tag {tag tcrew}} {tag {tag ecrew}} {tag {tag ecrew_a}} {tag {tag ecrew_b}} {tag {tag bot_arty}} {tag {tag bot_aa_guard}} {tag {tag _ufb_crew_safe}} {tag {tag _ufb_hf_cover_active}} {tag {tag _ai_wirecutter_in_action}} {tag {tag bot_inf_flank_in_progress}} {tag {tag _ufb_smoke_120m_actor}} {tag {tag _ufb_smoke_60m_actor}} {tag {tag _ufb_smoke_wirecutter_actor}} {tag {tag _ai_at_launcher_30}} {tag {tag _ai_at_launcher_40}} {tag {tag _ai_at_launcher_50}} {tag {tag _ai_at_launcher_60}} {tag {tag _ai_at_launcher_70}} {tag {tag _ai_at_launcher_80}} {tag {tag _ai_at_launcher_90}} 
 
 
 }}} {near_to {ignore_captured_by_user 0} {tag _ufb_suppress_point_%player}} {distance 12}}
   {"4.near" {units {ignore_captured_by_user 0} {tag _ufb_suppress_point_%player}} {near_to {source advanced} {ignore_captured_by_user 0} {group {select {prop {prop human}}} {include {state {state operatable}} {relation {relation ally} {player "%player"}}} {exclude {state {state dead}}}}} {distance 12}}
  }}
  {actions
   {"effect" {selector {source advanced} {ignore_captured_by_user 1}
 {group {select {tag {tag _ufb_suppress_actor_%player}}}
 {include {prop {prop human}} {state {state operatable}} {player {player "%player"}}  {with_item {type using} {item "mgun"}} }
 {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} {prop {prop repairing}} {prop {prop throwing}}
 {tag {tag _lua_mi}} {tag {tag _lua_ignore}} {tag {tag _ai_do_not_disturb}} {tag {tag repairing}} {tag {tag reloading}} {tag {tag bleeding}} {tag {tag _bleeding}} {tag {tag wounded}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag medic}} {tag {tag _ai_medic}} {tag {tag bot_medic}} {tag {tag _ufb_healing_active}} {tag {tag _ufb_autonomy_moving}} {tag {tag _ai_wounded_carrier}} {tag {tag _ai_ap_grenade}} {tag {tag _ai_at_grenade}} {tag {tag _ai_smoke_grenade}} {tag {tag _ai_suppressed_by_mg}} {tag {tag _ai_mgunner}} {tag {tag _ai_reloading}} {tag {tag _ai_looting_weapon}} {tag {tag crew}} {tag {tag tcrew}} {tag {tag ecrew}} {tag {tag ecrew_a}} {tag {tag ecrew_b}} {tag {tag bot_arty}} {tag {tag bot_aa_guard}} {tag {tag _ufb_crew_safe}} {tag {tag _ufb_hf_cover_active}} {tag {tag _ai_wirecutter_in_action}} {tag {tag bot_inf_flank_in_progress}} {tag {tag _ufb_smoke_120m_actor}} {tag {tag _ufb_smoke_60m_actor}} {tag {tag _ufb_smoke_wirecutter_actor}} {tag {tag _ai_at_launcher_30}} {tag {tag _ai_at_launcher_40}} {tag {tag _ai_at_launcher_50}} {tag {tag _ai_at_launcher_60}} {tag {tag _ai_at_launcher_70}} {tag {tag _ai_at_launcher_80}} {tag {tag _ai_at_launcher_90}} 
 
 
 }}} {effect ufb_suppress_cooldown}}
   {"con" {text "[UFB support] bounded MG suppression: player %player"}}
   {"switch"
 {"case" {condition {type near} {units {ignore_captured_by_user 0} {tag _ufb_suppress_point_%player}} {near_to {source advanced} {ignore_captured_by_user 0} {group {select {prop {prop human}}} {include {state {state operatable}} {relation {relation ally} {player "%player"}}} {exclude {state {state dead}}}}} {distance 12}}}
 {"default"
  {"if" {condition {type entities} {selector {ignore_captured_by_user 0} {tag _ufb_suppress_point_%player}}}
   {"actor_fire" {selector {source advanced} {ignore_captured_by_user 1}
 {group {select {tag {tag _ufb_suppress_actor_%player}}}
 {include {prop {prop human}} {state {state operatable}} {player {player "%player"}}  {with_item {type using} {item "mgun"}} }
 {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} {prop {prop repairing}} {prop {prop throwing}}
 {tag {tag _lua_mi}} {tag {tag _lua_ignore}} {tag {tag _ai_do_not_disturb}} {tag {tag repairing}} {tag {tag reloading}} {tag {tag bleeding}} {tag {tag _bleeding}} {tag {tag wounded}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag medic}} {tag {tag _ai_medic}} {tag {tag bot_medic}} {tag {tag _ufb_healing_active}} {tag {tag _ufb_autonomy_moving}} {tag {tag _ai_wounded_carrier}} {tag {tag _ai_ap_grenade}} {tag {tag _ai_at_grenade}} {tag {tag _ai_smoke_grenade}} {tag {tag _ai_suppressed_by_mg}} {tag {tag _ai_mgunner}} {tag {tag _ai_reloading}} {tag {tag _ai_looting_weapon}} {tag {tag crew}} {tag {tag tcrew}} {tag {tag ecrew}} {tag {tag ecrew_a}} {tag {tag ecrew_b}} {tag {tag bot_arty}} {tag {tag bot_aa_guard}} {tag {tag _ufb_crew_safe}} {tag {tag _ufb_hf_cover_active}} {tag {tag _ai_wirecutter_in_action}} {tag {tag bot_inf_flank_in_progress}} {tag {tag _ufb_smoke_120m_actor}} {tag {tag _ufb_smoke_60m_actor}} {tag {tag _ufb_smoke_wirecutter_actor}} {tag {tag _ai_at_launcher_30}} {tag {tag _ai_at_launcher_40}} {tag {tag _ai_at_launcher_50}} {tag {tag _ai_at_launcher_60}} {tag {tag _ai_at_launcher_70}} {tag {tag _ai_at_launcher_80}} {tag {tag _ai_at_launcher_90}} 
 {state {state user_control}}
 
 }}}
    {enemies {ignore_captured_by_user 0} {tag _ufb_suppress_point_%player}} {deviate} {interval 0} {time 0} {burst_mode once}
   }
   {"actor_fire" {selector {source advanced} {ignore_captured_by_user 1}
 {group {select {tag {tag _ufb_suppress_actor_%player}}}
 {include {prop {prop human}} {state {state operatable}} {player {player "%player"}}  {with_item {type using} {item "mgun"}} {state {state user_control}} {prop {prop shooting}}}
 {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} {prop {prop repairing}} {prop {prop throwing}}
 {tag {tag _lua_mi}} {tag {tag _lua_ignore}} {tag {tag _ai_do_not_disturb}} {tag {tag repairing}} {tag {tag reloading}} {tag {tag bleeding}} {tag {tag _bleeding}} {tag {tag wounded}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag medic}} {tag {tag _ai_medic}} {tag {tag bot_medic}} {tag {tag _ufb_healing_active}} {tag {tag _ufb_autonomy_moving}} {tag {tag _ai_wounded_carrier}} {tag {tag _ai_ap_grenade}} {tag {tag _ai_at_grenade}} {tag {tag _ai_smoke_grenade}} {tag {tag _ai_suppressed_by_mg}} {tag {tag _ai_mgunner}} {tag {tag _ai_reloading}} {tag {tag _ai_looting_weapon}} {tag {tag crew}} {tag {tag tcrew}} {tag {tag ecrew}} {tag {tag ecrew_a}} {tag {tag ecrew_b}} {tag {tag bot_arty}} {tag {tag bot_aa_guard}} {tag {tag _ufb_crew_safe}} {tag {tag _ufb_hf_cover_active}} {tag {tag _ai_wirecutter_in_action}} {tag {tag bot_inf_flank_in_progress}} {tag {tag _ufb_smoke_120m_actor}} {tag {tag _ufb_smoke_60m_actor}} {tag {tag _ufb_smoke_wirecutter_actor}} {tag {tag _ai_at_launcher_30}} {tag {tag _ai_at_launcher_40}} {tag {tag _ai_at_launcher_50}} {tag {tag _ai_at_launcher_60}} {tag {tag _ai_at_launcher_70}} {tag {tag _ai_at_launcher_80}} {tag {tag _ai_at_launcher_90}} 
 
 
 }}}
    {enemies {ignore_captured_by_user 0} {tag _ufb_suppress_point_%player}} {deviate} {interval 0} {time 0} {burst_mode once}
   }
  }
 }
}
   {"delay" {time 2}}
   {"switch"
 {"case" {condition {type near} {units {ignore_captured_by_user 0} {tag _ufb_suppress_point_%player}} {near_to {source advanced} {ignore_captured_by_user 0} {group {select {prop {prop human}}} {include {state {state operatable}} {relation {relation ally} {player "%player"}}} {exclude {state {state dead}}}}} {distance 12}}}
 {"default"
  {"if" {condition {type entities} {selector {ignore_captured_by_user 0} {tag _ufb_suppress_point_%player}}}
   {"actor_fire" {selector {source advanced} {ignore_captured_by_user 1}
 {group {select {tag {tag _ufb_suppress_actor_%player}}}
 {include {prop {prop human}} {state {state operatable}} {player {player "%player"}}  {with_item {type using} {item "mgun"}} }
 {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} {prop {prop repairing}} {prop {prop throwing}}
 {tag {tag _lua_mi}} {tag {tag _lua_ignore}} {tag {tag _ai_do_not_disturb}} {tag {tag repairing}} {tag {tag reloading}} {tag {tag bleeding}} {tag {tag _bleeding}} {tag {tag wounded}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag medic}} {tag {tag _ai_medic}} {tag {tag bot_medic}} {tag {tag _ufb_healing_active}} {tag {tag _ufb_autonomy_moving}} {tag {tag _ai_wounded_carrier}} {tag {tag _ai_ap_grenade}} {tag {tag _ai_at_grenade}} {tag {tag _ai_smoke_grenade}} {tag {tag _ai_suppressed_by_mg}} {tag {tag _ai_mgunner}} {tag {tag _ai_reloading}} {tag {tag _ai_looting_weapon}} {tag {tag crew}} {tag {tag tcrew}} {tag {tag ecrew}} {tag {tag ecrew_a}} {tag {tag ecrew_b}} {tag {tag bot_arty}} {tag {tag bot_aa_guard}} {tag {tag _ufb_crew_safe}} {tag {tag _ufb_hf_cover_active}} {tag {tag _ai_wirecutter_in_action}} {tag {tag bot_inf_flank_in_progress}} {tag {tag _ufb_smoke_120m_actor}} {tag {tag _ufb_smoke_60m_actor}} {tag {tag _ufb_smoke_wirecutter_actor}} {tag {tag _ai_at_launcher_30}} {tag {tag _ai_at_launcher_40}} {tag {tag _ai_at_launcher_50}} {tag {tag _ai_at_launcher_60}} {tag {tag _ai_at_launcher_70}} {tag {tag _ai_at_launcher_80}} {tag {tag _ai_at_launcher_90}} 
 {state {state user_control}}
 
 }}}
    {enemies {ignore_captured_by_user 0} {tag _ufb_suppress_point_%player}} {deviate} {interval 0} {time 0} {burst_mode once}
   }
   {"actor_fire" {selector {source advanced} {ignore_captured_by_user 1}
 {group {select {tag {tag _ufb_suppress_actor_%player}}}
 {include {prop {prop human}} {state {state operatable}} {player {player "%player"}}  {with_item {type using} {item "mgun"}} {state {state user_control}} {prop {prop shooting}}}
 {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} {prop {prop repairing}} {prop {prop throwing}}
 {tag {tag _lua_mi}} {tag {tag _lua_ignore}} {tag {tag _ai_do_not_disturb}} {tag {tag repairing}} {tag {tag reloading}} {tag {tag bleeding}} {tag {tag _bleeding}} {tag {tag wounded}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag medic}} {tag {tag _ai_medic}} {tag {tag bot_medic}} {tag {tag _ufb_healing_active}} {tag {tag _ufb_autonomy_moving}} {tag {tag _ai_wounded_carrier}} {tag {tag _ai_ap_grenade}} {tag {tag _ai_at_grenade}} {tag {tag _ai_smoke_grenade}} {tag {tag _ai_suppressed_by_mg}} {tag {tag _ai_mgunner}} {tag {tag _ai_reloading}} {tag {tag _ai_looting_weapon}} {tag {tag crew}} {tag {tag tcrew}} {tag {tag ecrew}} {tag {tag ecrew_a}} {tag {tag ecrew_b}} {tag {tag bot_arty}} {tag {tag bot_aa_guard}} {tag {tag _ufb_crew_safe}} {tag {tag _ufb_hf_cover_active}} {tag {tag _ai_wirecutter_in_action}} {tag {tag bot_inf_flank_in_progress}} {tag {tag _ufb_smoke_120m_actor}} {tag {tag _ufb_smoke_60m_actor}} {tag {tag _ufb_smoke_wirecutter_actor}} {tag {tag _ai_at_launcher_30}} {tag {tag _ai_at_launcher_40}} {tag {tag _ai_at_launcher_50}} {tag {tag _ai_at_launcher_60}} {tag {tag _ai_at_launcher_70}} {tag {tag _ai_at_launcher_80}} {tag {tag _ai_at_launcher_90}} 
 
 
 }}}
    {enemies {ignore_captured_by_user 0} {tag _ufb_suppress_point_%player}} {deviate} {interval 0} {time 0} {burst_mode once}
   }
  }
 }
}
   {"delay" {time 2}}
   {"switch"
 {"case" {condition {type near} {units {ignore_captured_by_user 0} {tag _ufb_suppress_point_%player}} {near_to {source advanced} {ignore_captured_by_user 0} {group {select {prop {prop human}}} {include {state {state operatable}} {relation {relation ally} {player "%player"}}} {exclude {state {state dead}}}}} {distance 12}}}
 {"default"
  {"if" {condition {type entities} {selector {ignore_captured_by_user 0} {tag _ufb_suppress_point_%player}}}
   {"actor_fire" {selector {source advanced} {ignore_captured_by_user 1}
 {group {select {tag {tag _ufb_suppress_actor_%player}}}
 {include {prop {prop human}} {state {state operatable}} {player {player "%player"}}  {with_item {type using} {item "mgun"}} }
 {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} {prop {prop repairing}} {prop {prop throwing}}
 {tag {tag _lua_mi}} {tag {tag _lua_ignore}} {tag {tag _ai_do_not_disturb}} {tag {tag repairing}} {tag {tag reloading}} {tag {tag bleeding}} {tag {tag _bleeding}} {tag {tag wounded}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag medic}} {tag {tag _ai_medic}} {tag {tag bot_medic}} {tag {tag _ufb_healing_active}} {tag {tag _ufb_autonomy_moving}} {tag {tag _ai_wounded_carrier}} {tag {tag _ai_ap_grenade}} {tag {tag _ai_at_grenade}} {tag {tag _ai_smoke_grenade}} {tag {tag _ai_suppressed_by_mg}} {tag {tag _ai_mgunner}} {tag {tag _ai_reloading}} {tag {tag _ai_looting_weapon}} {tag {tag crew}} {tag {tag tcrew}} {tag {tag ecrew}} {tag {tag ecrew_a}} {tag {tag ecrew_b}} {tag {tag bot_arty}} {tag {tag bot_aa_guard}} {tag {tag _ufb_crew_safe}} {tag {tag _ufb_hf_cover_active}} {tag {tag _ai_wirecutter_in_action}} {tag {tag bot_inf_flank_in_progress}} {tag {tag _ufb_smoke_120m_actor}} {tag {tag _ufb_smoke_60m_actor}} {tag {tag _ufb_smoke_wirecutter_actor}} {tag {tag _ai_at_launcher_30}} {tag {tag _ai_at_launcher_40}} {tag {tag _ai_at_launcher_50}} {tag {tag _ai_at_launcher_60}} {tag {tag _ai_at_launcher_70}} {tag {tag _ai_at_launcher_80}} {tag {tag _ai_at_launcher_90}} 
 {state {state user_control}}
 
 }}}
    {enemies {ignore_captured_by_user 0} {tag _ufb_suppress_point_%player}} {deviate} {interval 0} {time 0} {burst_mode once}
   }
   {"actor_fire" {selector {source advanced} {ignore_captured_by_user 1}
 {group {select {tag {tag _ufb_suppress_actor_%player}}}
 {include {prop {prop human}} {state {state operatable}} {player {player "%player"}}  {with_item {type using} {item "mgun"}} {state {state user_control}} {prop {prop shooting}}}
 {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} {prop {prop repairing}} {prop {prop throwing}}
 {tag {tag _lua_mi}} {tag {tag _lua_ignore}} {tag {tag _ai_do_not_disturb}} {tag {tag repairing}} {tag {tag reloading}} {tag {tag bleeding}} {tag {tag _bleeding}} {tag {tag wounded}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag medic}} {tag {tag _ai_medic}} {tag {tag bot_medic}} {tag {tag _ufb_healing_active}} {tag {tag _ufb_autonomy_moving}} {tag {tag _ai_wounded_carrier}} {tag {tag _ai_ap_grenade}} {tag {tag _ai_at_grenade}} {tag {tag _ai_smoke_grenade}} {tag {tag _ai_suppressed_by_mg}} {tag {tag _ai_mgunner}} {tag {tag _ai_reloading}} {tag {tag _ai_looting_weapon}} {tag {tag crew}} {tag {tag tcrew}} {tag {tag ecrew}} {tag {tag ecrew_a}} {tag {tag ecrew_b}} {tag {tag bot_arty}} {tag {tag bot_aa_guard}} {tag {tag _ufb_crew_safe}} {tag {tag _ufb_hf_cover_active}} {tag {tag _ai_wirecutter_in_action}} {tag {tag bot_inf_flank_in_progress}} {tag {tag _ufb_smoke_120m_actor}} {tag {tag _ufb_smoke_60m_actor}} {tag {tag _ufb_smoke_wirecutter_actor}} {tag {tag _ai_at_launcher_30}} {tag {tag _ai_at_launcher_40}} {tag {tag _ai_at_launcher_50}} {tag {tag _ai_at_launcher_60}} {tag {tag _ai_at_launcher_70}} {tag {tag _ai_at_launcher_80}} {tag {tag _ai_at_launcher_90}} 
 
 
 }}}
    {enemies {ignore_captured_by_user 0} {tag _ufb_suppress_point_%player}} {deviate} {interval 0} {time 0} {burst_mode once}
   }
  }
 }
}
   {"delay" {time 2}}
   {"trigger" {name "ufb/suppress/apply %player"}}
  }
 }
)
("ufb_mg_suppress" player(0))
("ufb_mg_suppress" player(1))
("ufb_mg_suppress" player(2))
("ufb_mg_suppress" player(3))
("ufb_mg_suppress" player(4))
("ufb_mg_suppress" player(5))
("ufb_mg_suppress" player(6))
("ufb_mg_suppress" player(7))
("ufb_mg_suppress" player(8))
("ufb_mg_suppress" player(9))
("ufb_mg_suppress" player(10))
("ufb_mg_suppress" player(11))
("ufb_mg_suppress" player(12))
("ufb_mg_suppress" player(13))
("ufb_mg_suppress" player(14))
("ufb_mg_suppress" player(15))
("ufb_mg_suppress" player(16))
