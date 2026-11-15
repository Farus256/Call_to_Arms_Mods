; Resupply only from dead bodies within inventory reach, using the actual weapon filling.
(define "ufb_supply_ufb_supply_0"
 {"ufb/supply/ufb_supply_0 %team"
  {condition {terms {"1.rand" {value 1}}}}
  {actions
   {"if" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {group
   {include {prop {prop human}} {state {state operatable}} {team {team %team}} {with_item {type using} {item "ufb_supply_0"}}}
   {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} {prop {prop repairing}} {prop {prop throwing}} {with_item {type amount} {item "ammo 7_65mm_pistol"} {min 24}}
    {tag {tag _ufb_surrendered}} {tag {tag _lua_mi}} {tag {tag _lua_ignore}} {tag {tag _ai_do_not_disturb}} {tag {tag repairing}} {tag {tag reloading}} {tag {tag bleeding}} {tag {tag _bleeding}} {tag {tag wounded}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag medic}} {tag {tag _ai_medic}} {tag {tag bot_medic}} {tag {tag _ufb_healing_active}} {tag {tag _ufb_autonomy_moving}} {tag {tag _ai_wounded_carrier}} {tag {tag _ai_ap_grenade}} {tag {tag _ai_at_grenade}} {tag {tag _ai_smoke_grenade}} {tag {tag _ai_suppressed_by_mg}} {tag {tag _ai_mgunner}} {tag {tag _ai_reloading}} {tag {tag _ai_looting_weapon}} {tag {tag crew}} {tag {tag tcrew}} {tag {tag ecrew}} {tag {tag ecrew_a}} {tag {tag ecrew_b}} {tag {tag bot_arty}} {tag {tag bot_aa_guard}} {tag {tag _ufb_crew_safe}} {tag {tag _ufb_hf_cover_active}} {tag {tag _ai_wirecutter_in_action}} {tag {tag bot_inf_flank_in_progress}} {tag {tag _ufb_smoke_120m_actor}} {tag {tag _ufb_smoke_60m_actor}} {tag {tag _ufb_smoke_wirecutter_actor}} {tag {tag _ai_at_launcher_30}} {tag {tag _ai_at_launcher_40}} {tag {tag _ai_at_launcher_50}} {tag {tag _ai_at_launcher_60}} {tag {tag _ai_at_launcher_70}} {tag {tag _ai_at_launcher_80}} {tag {tag _ai_at_launcher_90}} {tag {tag _ufb_rescue_active}} {tag {tag _ufb_gun_job_active}} {tag {tag _ufb_combat_busy}} {tag {tag _ufb_job_reserved}} {tag {tag _ufb_supply_cooldown}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group 
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo 7_65mm_pistol"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}} {distance {mode near_than} {meters 3}}
    {tag {"tag pair"} {"for selector" _ufb_supply_actor_%team} {"for enemy" _ufb_supply_body_%team}}}
    {"switch"
     {"case" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_0"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group {include {team {team %foe}} {state {state operatable}}} {exclude {state {state dead}} {state {state inactive}}}}} {distance {mode near_than} {meters 25}} {detection visible}}}
     {"default"
      {"inventory" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_0"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {action take_from} {item "ammo 7_65mm_pistol"} {amount 120} {entity {source advanced} {amount 1} {sort {type entity} {entity {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_0"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}}} {ignore_captured_by_user 0} {group {select {tag {tag _ufb_supply_body_%team}}}
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo 7_65mm_pistol"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}}}
      {"effect" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_0"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {effect ufb_supply_cooldown}}
     }
    }
   }
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_actor_%team}} {tag_remove _ufb_supply_actor_%team}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_body_%team}} {tag_remove _ufb_supply_body_%team}}
   {"delay" {time 4.0}}
   {"trigger" {name "ufb/supply/ufb_supply_0 %team"}}
  }
 }
)
("ufb_supply_ufb_supply_0" team(a) foe(b))
("ufb_supply_ufb_supply_0" team(b) foe(a))
(define "ufb_supply_ufb_supply_1"
 {"ufb/supply/ufb_supply_1 %team"
  {condition {terms {"1.rand" {value 1}}}}
  {actions
   {"if" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {group
   {include {prop {prop human}} {state {state operatable}} {team {team %team}} {with_item {type using} {item "ufb_supply_1"}}}
   {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} {prop {prop repairing}} {prop {prop throwing}} {with_item {type amount} {item "ammo atrifle_eng"} {min 24}}
    {tag {tag _ufb_surrendered}} {tag {tag _lua_mi}} {tag {tag _lua_ignore}} {tag {tag _ai_do_not_disturb}} {tag {tag repairing}} {tag {tag reloading}} {tag {tag bleeding}} {tag {tag _bleeding}} {tag {tag wounded}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag medic}} {tag {tag _ai_medic}} {tag {tag bot_medic}} {tag {tag _ufb_healing_active}} {tag {tag _ufb_autonomy_moving}} {tag {tag _ai_wounded_carrier}} {tag {tag _ai_ap_grenade}} {tag {tag _ai_at_grenade}} {tag {tag _ai_smoke_grenade}} {tag {tag _ai_suppressed_by_mg}} {tag {tag _ai_mgunner}} {tag {tag _ai_reloading}} {tag {tag _ai_looting_weapon}} {tag {tag crew}} {tag {tag tcrew}} {tag {tag ecrew}} {tag {tag ecrew_a}} {tag {tag ecrew_b}} {tag {tag bot_arty}} {tag {tag bot_aa_guard}} {tag {tag _ufb_crew_safe}} {tag {tag _ufb_hf_cover_active}} {tag {tag _ai_wirecutter_in_action}} {tag {tag bot_inf_flank_in_progress}} {tag {tag _ufb_smoke_120m_actor}} {tag {tag _ufb_smoke_60m_actor}} {tag {tag _ufb_smoke_wirecutter_actor}} {tag {tag _ai_at_launcher_30}} {tag {tag _ai_at_launcher_40}} {tag {tag _ai_at_launcher_50}} {tag {tag _ai_at_launcher_60}} {tag {tag _ai_at_launcher_70}} {tag {tag _ai_at_launcher_80}} {tag {tag _ai_at_launcher_90}} {tag {tag _ufb_rescue_active}} {tag {tag _ufb_gun_job_active}} {tag {tag _ufb_combat_busy}} {tag {tag _ufb_job_reserved}} {tag {tag _ufb_supply_cooldown}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group 
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo atrifle_eng"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}} {distance {mode near_than} {meters 3}}
    {tag {"tag pair"} {"for selector" _ufb_supply_actor_%team} {"for enemy" _ufb_supply_body_%team}}}
    {"switch"
     {"case" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_1"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group {include {team {team %foe}} {state {state operatable}}} {exclude {state {state dead}} {state {state inactive}}}}} {distance {mode near_than} {meters 25}} {detection visible}}}
     {"default"
      {"inventory" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_1"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {action take_from} {item "ammo atrifle_eng"} {amount 120} {entity {source advanced} {amount 1} {sort {type entity} {entity {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_1"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}}} {ignore_captured_by_user 0} {group {select {tag {tag _ufb_supply_body_%team}}}
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo atrifle_eng"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}}}
      {"effect" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_1"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {effect ufb_supply_cooldown}}
     }
    }
   }
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_actor_%team}} {tag_remove _ufb_supply_actor_%team}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_body_%team}} {tag_remove _ufb_supply_body_%team}}
   {"delay" {time 4.1}}
   {"trigger" {name "ufb/supply/ufb_supply_1 %team"}}
  }
 }
)
("ufb_supply_ufb_supply_1" team(a) foe(b))
("ufb_supply_ufb_supply_1" team(b) foe(a))
(define "ufb_supply_ufb_supply_2"
 {"ufb/supply/ufb_supply_2 %team"
  {condition {terms {"1.rand" {value 1}}}}
  {actions
   {"if" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {group
   {include {prop {prop human}} {state {state operatable}} {team {team %team}} {with_item {type using} {item "ufb_supply_2"}}}
   {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} {prop {prop repairing}} {prop {prop throwing}} {with_item {type amount} {item "ammo atrifle_ger"} {min 24}}
    {tag {tag _ufb_surrendered}} {tag {tag _lua_mi}} {tag {tag _lua_ignore}} {tag {tag _ai_do_not_disturb}} {tag {tag repairing}} {tag {tag reloading}} {tag {tag bleeding}} {tag {tag _bleeding}} {tag {tag wounded}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag medic}} {tag {tag _ai_medic}} {tag {tag bot_medic}} {tag {tag _ufb_healing_active}} {tag {tag _ufb_autonomy_moving}} {tag {tag _ai_wounded_carrier}} {tag {tag _ai_ap_grenade}} {tag {tag _ai_at_grenade}} {tag {tag _ai_smoke_grenade}} {tag {tag _ai_suppressed_by_mg}} {tag {tag _ai_mgunner}} {tag {tag _ai_reloading}} {tag {tag _ai_looting_weapon}} {tag {tag crew}} {tag {tag tcrew}} {tag {tag ecrew}} {tag {tag ecrew_a}} {tag {tag ecrew_b}} {tag {tag bot_arty}} {tag {tag bot_aa_guard}} {tag {tag _ufb_crew_safe}} {tag {tag _ufb_hf_cover_active}} {tag {tag _ai_wirecutter_in_action}} {tag {tag bot_inf_flank_in_progress}} {tag {tag _ufb_smoke_120m_actor}} {tag {tag _ufb_smoke_60m_actor}} {tag {tag _ufb_smoke_wirecutter_actor}} {tag {tag _ai_at_launcher_30}} {tag {tag _ai_at_launcher_40}} {tag {tag _ai_at_launcher_50}} {tag {tag _ai_at_launcher_60}} {tag {tag _ai_at_launcher_70}} {tag {tag _ai_at_launcher_80}} {tag {tag _ai_at_launcher_90}} {tag {tag _ufb_rescue_active}} {tag {tag _ufb_gun_job_active}} {tag {tag _ufb_combat_busy}} {tag {tag _ufb_job_reserved}} {tag {tag _ufb_supply_cooldown}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group 
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo atrifle_ger"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}} {distance {mode near_than} {meters 3}}
    {tag {"tag pair"} {"for selector" _ufb_supply_actor_%team} {"for enemy" _ufb_supply_body_%team}}}
    {"switch"
     {"case" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_2"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group {include {team {team %foe}} {state {state operatable}}} {exclude {state {state dead}} {state {state inactive}}}}} {distance {mode near_than} {meters 25}} {detection visible}}}
     {"default"
      {"inventory" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_2"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {action take_from} {item "ammo atrifle_ger"} {amount 120} {entity {source advanced} {amount 1} {sort {type entity} {entity {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_2"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}}} {ignore_captured_by_user 0} {group {select {tag {tag _ufb_supply_body_%team}}}
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo atrifle_ger"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}}}
      {"effect" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_2"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {effect ufb_supply_cooldown}}
     }
    }
   }
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_actor_%team}} {tag_remove _ufb_supply_actor_%team}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_body_%team}} {tag_remove _ufb_supply_body_%team}}
   {"delay" {time 4.2}}
   {"trigger" {name "ufb/supply/ufb_supply_2 %team"}}
  }
 }
)
("ufb_supply_ufb_supply_2" team(a) foe(b))
("ufb_supply_ufb_supply_2" team(b) foe(a))
(define "ufb_supply_ufb_supply_3"
 {"ufb/supply/ufb_supply_3 %team"
  {condition {terms {"1.rand" {value 1}}}}
  {actions
   {"if" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {group
   {include {prop {prop human}} {state {state operatable}} {team {team %team}} {with_item {type using} {item "ufb_supply_3"}}}
   {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} {prop {prop repairing}} {prop {prop throwing}} {with_item {type amount} {item "ammo atrifle_ger2"} {min 24}}
    {tag {tag _ufb_surrendered}} {tag {tag _lua_mi}} {tag {tag _lua_ignore}} {tag {tag _ai_do_not_disturb}} {tag {tag repairing}} {tag {tag reloading}} {tag {tag bleeding}} {tag {tag _bleeding}} {tag {tag wounded}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag medic}} {tag {tag _ai_medic}} {tag {tag bot_medic}} {tag {tag _ufb_healing_active}} {tag {tag _ufb_autonomy_moving}} {tag {tag _ai_wounded_carrier}} {tag {tag _ai_ap_grenade}} {tag {tag _ai_at_grenade}} {tag {tag _ai_smoke_grenade}} {tag {tag _ai_suppressed_by_mg}} {tag {tag _ai_mgunner}} {tag {tag _ai_reloading}} {tag {tag _ai_looting_weapon}} {tag {tag crew}} {tag {tag tcrew}} {tag {tag ecrew}} {tag {tag ecrew_a}} {tag {tag ecrew_b}} {tag {tag bot_arty}} {tag {tag bot_aa_guard}} {tag {tag _ufb_crew_safe}} {tag {tag _ufb_hf_cover_active}} {tag {tag _ai_wirecutter_in_action}} {tag {tag bot_inf_flank_in_progress}} {tag {tag _ufb_smoke_120m_actor}} {tag {tag _ufb_smoke_60m_actor}} {tag {tag _ufb_smoke_wirecutter_actor}} {tag {tag _ai_at_launcher_30}} {tag {tag _ai_at_launcher_40}} {tag {tag _ai_at_launcher_50}} {tag {tag _ai_at_launcher_60}} {tag {tag _ai_at_launcher_70}} {tag {tag _ai_at_launcher_80}} {tag {tag _ai_at_launcher_90}} {tag {tag _ufb_rescue_active}} {tag {tag _ufb_gun_job_active}} {tag {tag _ufb_combat_busy}} {tag {tag _ufb_job_reserved}} {tag {tag _ufb_supply_cooldown}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group 
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo atrifle_ger2"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}} {distance {mode near_than} {meters 3}}
    {tag {"tag pair"} {"for selector" _ufb_supply_actor_%team} {"for enemy" _ufb_supply_body_%team}}}
    {"switch"
     {"case" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_3"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group {include {team {team %foe}} {state {state operatable}}} {exclude {state {state dead}} {state {state inactive}}}}} {distance {mode near_than} {meters 25}} {detection visible}}}
     {"default"
      {"inventory" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_3"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {action take_from} {item "ammo atrifle_ger2"} {amount 120} {entity {source advanced} {amount 1} {sort {type entity} {entity {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_3"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}}} {ignore_captured_by_user 0} {group {select {tag {tag _ufb_supply_body_%team}}}
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo atrifle_ger2"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}}}
      {"effect" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_3"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {effect ufb_supply_cooldown}}
     }
    }
   }
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_actor_%team}} {tag_remove _ufb_supply_actor_%team}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_body_%team}} {tag_remove _ufb_supply_body_%team}}
   {"delay" {time 4.3}}
   {"trigger" {name "ufb/supply/ufb_supply_3 %team"}}
  }
 }
)
("ufb_supply_ufb_supply_3" team(a) foe(b))
("ufb_supply_ufb_supply_3" team(b) foe(a))
(define "ufb_supply_ufb_supply_4"
 {"ufb/supply/ufb_supply_4 %team"
  {condition {terms {"1.rand" {value 1}}}}
  {actions
   {"if" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {group
   {include {prop {prop human}} {state {state operatable}} {team {team %team}} {with_item {type using} {item "ufb_supply_4"}}}
   {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} {prop {prop repairing}} {prop {prop throwing}} {with_item {type amount} {item "ammo atrifle_rus"} {min 24}}
    {tag {tag _ufb_surrendered}} {tag {tag _lua_mi}} {tag {tag _lua_ignore}} {tag {tag _ai_do_not_disturb}} {tag {tag repairing}} {tag {tag reloading}} {tag {tag bleeding}} {tag {tag _bleeding}} {tag {tag wounded}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag medic}} {tag {tag _ai_medic}} {tag {tag bot_medic}} {tag {tag _ufb_healing_active}} {tag {tag _ufb_autonomy_moving}} {tag {tag _ai_wounded_carrier}} {tag {tag _ai_ap_grenade}} {tag {tag _ai_at_grenade}} {tag {tag _ai_smoke_grenade}} {tag {tag _ai_suppressed_by_mg}} {tag {tag _ai_mgunner}} {tag {tag _ai_reloading}} {tag {tag _ai_looting_weapon}} {tag {tag crew}} {tag {tag tcrew}} {tag {tag ecrew}} {tag {tag ecrew_a}} {tag {tag ecrew_b}} {tag {tag bot_arty}} {tag {tag bot_aa_guard}} {tag {tag _ufb_crew_safe}} {tag {tag _ufb_hf_cover_active}} {tag {tag _ai_wirecutter_in_action}} {tag {tag bot_inf_flank_in_progress}} {tag {tag _ufb_smoke_120m_actor}} {tag {tag _ufb_smoke_60m_actor}} {tag {tag _ufb_smoke_wirecutter_actor}} {tag {tag _ai_at_launcher_30}} {tag {tag _ai_at_launcher_40}} {tag {tag _ai_at_launcher_50}} {tag {tag _ai_at_launcher_60}} {tag {tag _ai_at_launcher_70}} {tag {tag _ai_at_launcher_80}} {tag {tag _ai_at_launcher_90}} {tag {tag _ufb_rescue_active}} {tag {tag _ufb_gun_job_active}} {tag {tag _ufb_combat_busy}} {tag {tag _ufb_job_reserved}} {tag {tag _ufb_supply_cooldown}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group 
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo atrifle_rus"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}} {distance {mode near_than} {meters 3}}
    {tag {"tag pair"} {"for selector" _ufb_supply_actor_%team} {"for enemy" _ufb_supply_body_%team}}}
    {"switch"
     {"case" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_4"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group {include {team {team %foe}} {state {state operatable}}} {exclude {state {state dead}} {state {state inactive}}}}} {distance {mode near_than} {meters 25}} {detection visible}}}
     {"default"
      {"inventory" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_4"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {action take_from} {item "ammo atrifle_rus"} {amount 120} {entity {source advanced} {amount 1} {sort {type entity} {entity {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_4"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}}} {ignore_captured_by_user 0} {group {select {tag {tag _ufb_supply_body_%team}}}
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo atrifle_rus"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}}}
      {"effect" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_4"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {effect ufb_supply_cooldown}}
     }
    }
   }
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_actor_%team}} {tag_remove _ufb_supply_actor_%team}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_body_%team}} {tag_remove _ufb_supply_body_%team}}
   {"delay" {time 4.4}}
   {"trigger" {name "ufb/supply/ufb_supply_4 %team"}}
  }
 }
)
("ufb_supply_ufb_supply_4" team(a) foe(b))
("ufb_supply_ufb_supply_4" team(b) foe(a))
(define "ufb_supply_ufb_supply_5"
 {"ufb/supply/ufb_supply_5 %team"
  {condition {terms {"1.rand" {value 1}}}}
  {actions
   {"if" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {group
   {include {prop {prop human}} {state {state operatable}} {team {team %team}} {with_item {type using} {item "ufb_supply_5"}}}
   {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} {prop {prop repairing}} {prop {prop throwing}} {with_item {type amount} {item "ammo bar_mag"} {min 24}}
    {tag {tag _ufb_surrendered}} {tag {tag _lua_mi}} {tag {tag _lua_ignore}} {tag {tag _ai_do_not_disturb}} {tag {tag repairing}} {tag {tag reloading}} {tag {tag bleeding}} {tag {tag _bleeding}} {tag {tag wounded}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag medic}} {tag {tag _ai_medic}} {tag {tag bot_medic}} {tag {tag _ufb_healing_active}} {tag {tag _ufb_autonomy_moving}} {tag {tag _ai_wounded_carrier}} {tag {tag _ai_ap_grenade}} {tag {tag _ai_at_grenade}} {tag {tag _ai_smoke_grenade}} {tag {tag _ai_suppressed_by_mg}} {tag {tag _ai_mgunner}} {tag {tag _ai_reloading}} {tag {tag _ai_looting_weapon}} {tag {tag crew}} {tag {tag tcrew}} {tag {tag ecrew}} {tag {tag ecrew_a}} {tag {tag ecrew_b}} {tag {tag bot_arty}} {tag {tag bot_aa_guard}} {tag {tag _ufb_crew_safe}} {tag {tag _ufb_hf_cover_active}} {tag {tag _ai_wirecutter_in_action}} {tag {tag bot_inf_flank_in_progress}} {tag {tag _ufb_smoke_120m_actor}} {tag {tag _ufb_smoke_60m_actor}} {tag {tag _ufb_smoke_wirecutter_actor}} {tag {tag _ai_at_launcher_30}} {tag {tag _ai_at_launcher_40}} {tag {tag _ai_at_launcher_50}} {tag {tag _ai_at_launcher_60}} {tag {tag _ai_at_launcher_70}} {tag {tag _ai_at_launcher_80}} {tag {tag _ai_at_launcher_90}} {tag {tag _ufb_rescue_active}} {tag {tag _ufb_gun_job_active}} {tag {tag _ufb_combat_busy}} {tag {tag _ufb_job_reserved}} {tag {tag _ufb_supply_cooldown}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group 
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo bar_mag"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}} {distance {mode near_than} {meters 3}}
    {tag {"tag pair"} {"for selector" _ufb_supply_actor_%team} {"for enemy" _ufb_supply_body_%team}}}
    {"switch"
     {"case" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_5"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group {include {team {team %foe}} {state {state operatable}}} {exclude {state {state dead}} {state {state inactive}}}}} {distance {mode near_than} {meters 25}} {detection visible}}}
     {"default"
      {"inventory" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_5"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {action take_from} {item "ammo bar_mag"} {amount 120} {entity {source advanced} {amount 1} {sort {type entity} {entity {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_5"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}}} {ignore_captured_by_user 0} {group {select {tag {tag _ufb_supply_body_%team}}}
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo bar_mag"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}}}
      {"effect" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_5"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {effect ufb_supply_cooldown}}
     }
    }
   }
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_actor_%team}} {tag_remove _ufb_supply_actor_%team}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_body_%team}} {tag_remove _ufb_supply_body_%team}}
   {"delay" {time 4.5}}
   {"trigger" {name "ufb/supply/ufb_supply_5 %team"}}
  }
 }
)
("ufb_supply_ufb_supply_5" team(a) foe(b))
("ufb_supply_ufb_supply_5" team(b) foe(a))
(define "ufb_supply_ufb_supply_6"
 {"ufb/supply/ufb_supply_6 %team"
  {condition {terms {"1.rand" {value 1}}}}
  {actions
   {"if" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {group
   {include {prop {prop human}} {state {state operatable}} {team {team %team}} {with_item {type using} {item "ufb_supply_6"}}}
   {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} {prop {prop repairing}} {prop {prop throwing}} {with_item {type amount} {item "ammo bergmann_stick"} {min 24}}
    {tag {tag _ufb_surrendered}} {tag {tag _lua_mi}} {tag {tag _lua_ignore}} {tag {tag _ai_do_not_disturb}} {tag {tag repairing}} {tag {tag reloading}} {tag {tag bleeding}} {tag {tag _bleeding}} {tag {tag wounded}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag medic}} {tag {tag _ai_medic}} {tag {tag bot_medic}} {tag {tag _ufb_healing_active}} {tag {tag _ufb_autonomy_moving}} {tag {tag _ai_wounded_carrier}} {tag {tag _ai_ap_grenade}} {tag {tag _ai_at_grenade}} {tag {tag _ai_smoke_grenade}} {tag {tag _ai_suppressed_by_mg}} {tag {tag _ai_mgunner}} {tag {tag _ai_reloading}} {tag {tag _ai_looting_weapon}} {tag {tag crew}} {tag {tag tcrew}} {tag {tag ecrew}} {tag {tag ecrew_a}} {tag {tag ecrew_b}} {tag {tag bot_arty}} {tag {tag bot_aa_guard}} {tag {tag _ufb_crew_safe}} {tag {tag _ufb_hf_cover_active}} {tag {tag _ai_wirecutter_in_action}} {tag {tag bot_inf_flank_in_progress}} {tag {tag _ufb_smoke_120m_actor}} {tag {tag _ufb_smoke_60m_actor}} {tag {tag _ufb_smoke_wirecutter_actor}} {tag {tag _ai_at_launcher_30}} {tag {tag _ai_at_launcher_40}} {tag {tag _ai_at_launcher_50}} {tag {tag _ai_at_launcher_60}} {tag {tag _ai_at_launcher_70}} {tag {tag _ai_at_launcher_80}} {tag {tag _ai_at_launcher_90}} {tag {tag _ufb_rescue_active}} {tag {tag _ufb_gun_job_active}} {tag {tag _ufb_combat_busy}} {tag {tag _ufb_job_reserved}} {tag {tag _ufb_supply_cooldown}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group 
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo bergmann_stick"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}} {distance {mode near_than} {meters 3}}
    {tag {"tag pair"} {"for selector" _ufb_supply_actor_%team} {"for enemy" _ufb_supply_body_%team}}}
    {"switch"
     {"case" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_6"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group {include {team {team %foe}} {state {state operatable}}} {exclude {state {state dead}} {state {state inactive}}}}} {distance {mode near_than} {meters 25}} {detection visible}}}
     {"default"
      {"inventory" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_6"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {action take_from} {item "ammo bergmann_stick"} {amount 120} {entity {source advanced} {amount 1} {sort {type entity} {entity {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_6"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}}} {ignore_captured_by_user 0} {group {select {tag {tag _ufb_supply_body_%team}}}
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo bergmann_stick"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}}}
      {"effect" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_6"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {effect ufb_supply_cooldown}}
     }
    }
   }
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_actor_%team}} {tag_remove _ufb_supply_actor_%team}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_body_%team}} {tag_remove _ufb_supply_body_%team}}
   {"delay" {time 4.6}}
   {"trigger" {name "ufb/supply/ufb_supply_6 %team"}}
  }
 }
)
("ufb_supply_ufb_supply_6" team(a) foe(b))
("ufb_supply_ufb_supply_6" team(b) foe(a))
(define "ufb_supply_ufb_supply_7"
 {"ufb/supply/ufb_supply_7 %team"
  {condition {terms {"1.rand" {value 1}}}}
  {actions
   {"if" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {group
   {include {prop {prop human}} {state {state operatable}} {team {team %team}} {with_item {type using} {item "ufb_supply_7"}}}
   {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} {prop {prop repairing}} {prop {prop throwing}} {with_item {type amount} {item "ammo bren_drum_mag"} {min 24}}
    {tag {tag _ufb_surrendered}} {tag {tag _lua_mi}} {tag {tag _lua_ignore}} {tag {tag _ai_do_not_disturb}} {tag {tag repairing}} {tag {tag reloading}} {tag {tag bleeding}} {tag {tag _bleeding}} {tag {tag wounded}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag medic}} {tag {tag _ai_medic}} {tag {tag bot_medic}} {tag {tag _ufb_healing_active}} {tag {tag _ufb_autonomy_moving}} {tag {tag _ai_wounded_carrier}} {tag {tag _ai_ap_grenade}} {tag {tag _ai_at_grenade}} {tag {tag _ai_smoke_grenade}} {tag {tag _ai_suppressed_by_mg}} {tag {tag _ai_mgunner}} {tag {tag _ai_reloading}} {tag {tag _ai_looting_weapon}} {tag {tag crew}} {tag {tag tcrew}} {tag {tag ecrew}} {tag {tag ecrew_a}} {tag {tag ecrew_b}} {tag {tag bot_arty}} {tag {tag bot_aa_guard}} {tag {tag _ufb_crew_safe}} {tag {tag _ufb_hf_cover_active}} {tag {tag _ai_wirecutter_in_action}} {tag {tag bot_inf_flank_in_progress}} {tag {tag _ufb_smoke_120m_actor}} {tag {tag _ufb_smoke_60m_actor}} {tag {tag _ufb_smoke_wirecutter_actor}} {tag {tag _ai_at_launcher_30}} {tag {tag _ai_at_launcher_40}} {tag {tag _ai_at_launcher_50}} {tag {tag _ai_at_launcher_60}} {tag {tag _ai_at_launcher_70}} {tag {tag _ai_at_launcher_80}} {tag {tag _ai_at_launcher_90}} {tag {tag _ufb_rescue_active}} {tag {tag _ufb_gun_job_active}} {tag {tag _ufb_combat_busy}} {tag {tag _ufb_job_reserved}} {tag {tag _ufb_supply_cooldown}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group 
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo bren_drum_mag"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}} {distance {mode near_than} {meters 3}}
    {tag {"tag pair"} {"for selector" _ufb_supply_actor_%team} {"for enemy" _ufb_supply_body_%team}}}
    {"switch"
     {"case" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_7"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group {include {team {team %foe}} {state {state operatable}}} {exclude {state {state dead}} {state {state inactive}}}}} {distance {mode near_than} {meters 25}} {detection visible}}}
     {"default"
      {"inventory" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_7"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {action take_from} {item "ammo bren_drum_mag"} {amount 120} {entity {source advanced} {amount 1} {sort {type entity} {entity {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_7"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}}} {ignore_captured_by_user 0} {group {select {tag {tag _ufb_supply_body_%team}}}
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo bren_drum_mag"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}}}
      {"effect" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_7"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {effect ufb_supply_cooldown}}
     }
    }
   }
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_actor_%team}} {tag_remove _ufb_supply_actor_%team}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_body_%team}} {tag_remove _ufb_supply_body_%team}}
   {"delay" {time 4.7}}
   {"trigger" {name "ufb/supply/ufb_supply_7 %team"}}
  }
 }
)
("ufb_supply_ufb_supply_7" team(a) foe(b))
("ufb_supply_ufb_supply_7" team(b) foe(a))
(define "ufb_supply_ufb_supply_8"
 {"ufb/supply/ufb_supply_8 %team"
  {condition {terms {"1.rand" {value 1}}}}
  {actions
   {"if" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {group
   {include {prop {prop human}} {state {state operatable}} {team {team %team}} {with_item {type using} {item "ufb_supply_8"}}}
   {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} {prop {prop repairing}} {prop {prop throwing}} {with_item {type amount} {item "ammo bren_mag"} {min 24}}
    {tag {tag _ufb_surrendered}} {tag {tag _lua_mi}} {tag {tag _lua_ignore}} {tag {tag _ai_do_not_disturb}} {tag {tag repairing}} {tag {tag reloading}} {tag {tag bleeding}} {tag {tag _bleeding}} {tag {tag wounded}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag medic}} {tag {tag _ai_medic}} {tag {tag bot_medic}} {tag {tag _ufb_healing_active}} {tag {tag _ufb_autonomy_moving}} {tag {tag _ai_wounded_carrier}} {tag {tag _ai_ap_grenade}} {tag {tag _ai_at_grenade}} {tag {tag _ai_smoke_grenade}} {tag {tag _ai_suppressed_by_mg}} {tag {tag _ai_mgunner}} {tag {tag _ai_reloading}} {tag {tag _ai_looting_weapon}} {tag {tag crew}} {tag {tag tcrew}} {tag {tag ecrew}} {tag {tag ecrew_a}} {tag {tag ecrew_b}} {tag {tag bot_arty}} {tag {tag bot_aa_guard}} {tag {tag _ufb_crew_safe}} {tag {tag _ufb_hf_cover_active}} {tag {tag _ai_wirecutter_in_action}} {tag {tag bot_inf_flank_in_progress}} {tag {tag _ufb_smoke_120m_actor}} {tag {tag _ufb_smoke_60m_actor}} {tag {tag _ufb_smoke_wirecutter_actor}} {tag {tag _ai_at_launcher_30}} {tag {tag _ai_at_launcher_40}} {tag {tag _ai_at_launcher_50}} {tag {tag _ai_at_launcher_60}} {tag {tag _ai_at_launcher_70}} {tag {tag _ai_at_launcher_80}} {tag {tag _ai_at_launcher_90}} {tag {tag _ufb_rescue_active}} {tag {tag _ufb_gun_job_active}} {tag {tag _ufb_combat_busy}} {tag {tag _ufb_job_reserved}} {tag {tag _ufb_supply_cooldown}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group 
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo bren_mag"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}} {distance {mode near_than} {meters 3}}
    {tag {"tag pair"} {"for selector" _ufb_supply_actor_%team} {"for enemy" _ufb_supply_body_%team}}}
    {"switch"
     {"case" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_8"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group {include {team {team %foe}} {state {state operatable}}} {exclude {state {state dead}} {state {state inactive}}}}} {distance {mode near_than} {meters 25}} {detection visible}}}
     {"default"
      {"inventory" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_8"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {action take_from} {item "ammo bren_mag"} {amount 120} {entity {source advanced} {amount 1} {sort {type entity} {entity {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_8"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}}} {ignore_captured_by_user 0} {group {select {tag {tag _ufb_supply_body_%team}}}
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo bren_mag"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}}}
      {"effect" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_8"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {effect ufb_supply_cooldown}}
     }
    }
   }
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_actor_%team}} {tag_remove _ufb_supply_actor_%team}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_body_%team}} {tag_remove _ufb_supply_body_%team}}
   {"delay" {time 4.8}}
   {"trigger" {name "ufb/supply/ufb_supply_8 %team"}}
  }
 }
)
("ufb_supply_ufb_supply_8" team(a) foe(b))
("ufb_supply_ufb_supply_8" team(b) foe(a))
(define "ufb_supply_ufb_supply_9"
 {"ufb/supply/ufb_supply_9 %team"
  {condition {terms {"1.rand" {value 1}}}}
  {actions
   {"if" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {group
   {include {prop {prop human}} {state {state operatable}} {team {team %team}} {with_item {type using} {item "ufb_supply_9"}}}
   {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} {prop {prop repairing}} {prop {prop throwing}} {with_item {type amount} {item "ammo chauchat"} {min 24}}
    {tag {tag _ufb_surrendered}} {tag {tag _lua_mi}} {tag {tag _lua_ignore}} {tag {tag _ai_do_not_disturb}} {tag {tag repairing}} {tag {tag reloading}} {tag {tag bleeding}} {tag {tag _bleeding}} {tag {tag wounded}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag medic}} {tag {tag _ai_medic}} {tag {tag bot_medic}} {tag {tag _ufb_healing_active}} {tag {tag _ufb_autonomy_moving}} {tag {tag _ai_wounded_carrier}} {tag {tag _ai_ap_grenade}} {tag {tag _ai_at_grenade}} {tag {tag _ai_smoke_grenade}} {tag {tag _ai_suppressed_by_mg}} {tag {tag _ai_mgunner}} {tag {tag _ai_reloading}} {tag {tag _ai_looting_weapon}} {tag {tag crew}} {tag {tag tcrew}} {tag {tag ecrew}} {tag {tag ecrew_a}} {tag {tag ecrew_b}} {tag {tag bot_arty}} {tag {tag bot_aa_guard}} {tag {tag _ufb_crew_safe}} {tag {tag _ufb_hf_cover_active}} {tag {tag _ai_wirecutter_in_action}} {tag {tag bot_inf_flank_in_progress}} {tag {tag _ufb_smoke_120m_actor}} {tag {tag _ufb_smoke_60m_actor}} {tag {tag _ufb_smoke_wirecutter_actor}} {tag {tag _ai_at_launcher_30}} {tag {tag _ai_at_launcher_40}} {tag {tag _ai_at_launcher_50}} {tag {tag _ai_at_launcher_60}} {tag {tag _ai_at_launcher_70}} {tag {tag _ai_at_launcher_80}} {tag {tag _ai_at_launcher_90}} {tag {tag _ufb_rescue_active}} {tag {tag _ufb_gun_job_active}} {tag {tag _ufb_combat_busy}} {tag {tag _ufb_job_reserved}} {tag {tag _ufb_supply_cooldown}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group 
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo chauchat"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}} {distance {mode near_than} {meters 3}}
    {tag {"tag pair"} {"for selector" _ufb_supply_actor_%team} {"for enemy" _ufb_supply_body_%team}}}
    {"switch"
     {"case" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_9"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group {include {team {team %foe}} {state {state operatable}}} {exclude {state {state dead}} {state {state inactive}}}}} {distance {mode near_than} {meters 25}} {detection visible}}}
     {"default"
      {"inventory" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_9"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {action take_from} {item "ammo chauchat"} {amount 120} {entity {source advanced} {amount 1} {sort {type entity} {entity {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_9"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}}} {ignore_captured_by_user 0} {group {select {tag {tag _ufb_supply_body_%team}}}
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo chauchat"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}}}
      {"effect" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_9"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {effect ufb_supply_cooldown}}
     }
    }
   }
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_actor_%team}} {tag_remove _ufb_supply_actor_%team}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_body_%team}} {tag_remove _ufb_supply_body_%team}}
   {"delay" {time 4.9}}
   {"trigger" {name "ufb/supply/ufb_supply_9 %team"}}
  }
 }
)
("ufb_supply_ufb_supply_9" team(a) foe(b))
("ufb_supply_ufb_supply_9" team(b) foe(a))
(define "ufb_supply_ufb_supply_10"
 {"ufb/supply/ufb_supply_10 %team"
  {condition {terms {"1.rand" {value 1}}}}
  {actions
   {"if" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {group
   {include {prop {prop human}} {state {state operatable}} {team {team %team}} {with_item {type using} {item "ufb_supply_10"}}}
   {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} {prop {prop repairing}} {prop {prop throwing}} {with_item {type amount} {item "ammo de_lisle_carbine_mag"} {min 24}}
    {tag {tag _ufb_surrendered}} {tag {tag _lua_mi}} {tag {tag _lua_ignore}} {tag {tag _ai_do_not_disturb}} {tag {tag repairing}} {tag {tag reloading}} {tag {tag bleeding}} {tag {tag _bleeding}} {tag {tag wounded}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag medic}} {tag {tag _ai_medic}} {tag {tag bot_medic}} {tag {tag _ufb_healing_active}} {tag {tag _ufb_autonomy_moving}} {tag {tag _ai_wounded_carrier}} {tag {tag _ai_ap_grenade}} {tag {tag _ai_at_grenade}} {tag {tag _ai_smoke_grenade}} {tag {tag _ai_suppressed_by_mg}} {tag {tag _ai_mgunner}} {tag {tag _ai_reloading}} {tag {tag _ai_looting_weapon}} {tag {tag crew}} {tag {tag tcrew}} {tag {tag ecrew}} {tag {tag ecrew_a}} {tag {tag ecrew_b}} {tag {tag bot_arty}} {tag {tag bot_aa_guard}} {tag {tag _ufb_crew_safe}} {tag {tag _ufb_hf_cover_active}} {tag {tag _ai_wirecutter_in_action}} {tag {tag bot_inf_flank_in_progress}} {tag {tag _ufb_smoke_120m_actor}} {tag {tag _ufb_smoke_60m_actor}} {tag {tag _ufb_smoke_wirecutter_actor}} {tag {tag _ai_at_launcher_30}} {tag {tag _ai_at_launcher_40}} {tag {tag _ai_at_launcher_50}} {tag {tag _ai_at_launcher_60}} {tag {tag _ai_at_launcher_70}} {tag {tag _ai_at_launcher_80}} {tag {tag _ai_at_launcher_90}} {tag {tag _ufb_rescue_active}} {tag {tag _ufb_gun_job_active}} {tag {tag _ufb_combat_busy}} {tag {tag _ufb_job_reserved}} {tag {tag _ufb_supply_cooldown}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group 
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo de_lisle_carbine_mag"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}} {distance {mode near_than} {meters 3}}
    {tag {"tag pair"} {"for selector" _ufb_supply_actor_%team} {"for enemy" _ufb_supply_body_%team}}}
    {"switch"
     {"case" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_10"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group {include {team {team %foe}} {state {state operatable}}} {exclude {state {state dead}} {state {state inactive}}}}} {distance {mode near_than} {meters 25}} {detection visible}}}
     {"default"
      {"inventory" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_10"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {action take_from} {item "ammo de_lisle_carbine_mag"} {amount 120} {entity {source advanced} {amount 1} {sort {type entity} {entity {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_10"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}}} {ignore_captured_by_user 0} {group {select {tag {tag _ufb_supply_body_%team}}}
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo de_lisle_carbine_mag"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}}}
      {"effect" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_10"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {effect ufb_supply_cooldown}}
     }
    }
   }
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_actor_%team}} {tag_remove _ufb_supply_actor_%team}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_body_%team}} {tag_remove _ufb_supply_body_%team}}
   {"delay" {time 5.0}}
   {"trigger" {name "ufb/supply/ufb_supply_10 %team"}}
  }
 }
)
("ufb_supply_ufb_supply_10" team(a) foe(b))
("ufb_supply_ufb_supply_10" team(b) foe(a))
(define "ufb_supply_ufb_supply_11"
 {"ufb/supply/ufb_supply_11 %team"
  {condition {terms {"1.rand" {value 1}}}}
  {actions
   {"if" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {group
   {include {prop {prop human}} {state {state operatable}} {team {team %team}} {with_item {type using} {item "ufb_supply_11"}}}
   {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} {prop {prop repairing}} {prop {prop throwing}} {with_item {type amount} {item "ammo eng_revolver_clip_38"} {min 24}}
    {tag {tag _ufb_surrendered}} {tag {tag _lua_mi}} {tag {tag _lua_ignore}} {tag {tag _ai_do_not_disturb}} {tag {tag repairing}} {tag {tag reloading}} {tag {tag bleeding}} {tag {tag _bleeding}} {tag {tag wounded}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag medic}} {tag {tag _ai_medic}} {tag {tag bot_medic}} {tag {tag _ufb_healing_active}} {tag {tag _ufb_autonomy_moving}} {tag {tag _ai_wounded_carrier}} {tag {tag _ai_ap_grenade}} {tag {tag _ai_at_grenade}} {tag {tag _ai_smoke_grenade}} {tag {tag _ai_suppressed_by_mg}} {tag {tag _ai_mgunner}} {tag {tag _ai_reloading}} {tag {tag _ai_looting_weapon}} {tag {tag crew}} {tag {tag tcrew}} {tag {tag ecrew}} {tag {tag ecrew_a}} {tag {tag ecrew_b}} {tag {tag bot_arty}} {tag {tag bot_aa_guard}} {tag {tag _ufb_crew_safe}} {tag {tag _ufb_hf_cover_active}} {tag {tag _ai_wirecutter_in_action}} {tag {tag bot_inf_flank_in_progress}} {tag {tag _ufb_smoke_120m_actor}} {tag {tag _ufb_smoke_60m_actor}} {tag {tag _ufb_smoke_wirecutter_actor}} {tag {tag _ai_at_launcher_30}} {tag {tag _ai_at_launcher_40}} {tag {tag _ai_at_launcher_50}} {tag {tag _ai_at_launcher_60}} {tag {tag _ai_at_launcher_70}} {tag {tag _ai_at_launcher_80}} {tag {tag _ai_at_launcher_90}} {tag {tag _ufb_rescue_active}} {tag {tag _ufb_gun_job_active}} {tag {tag _ufb_combat_busy}} {tag {tag _ufb_job_reserved}} {tag {tag _ufb_supply_cooldown}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group 
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo eng_revolver_clip_38"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}} {distance {mode near_than} {meters 3}}
    {tag {"tag pair"} {"for selector" _ufb_supply_actor_%team} {"for enemy" _ufb_supply_body_%team}}}
    {"switch"
     {"case" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_11"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group {include {team {team %foe}} {state {state operatable}}} {exclude {state {state dead}} {state {state inactive}}}}} {distance {mode near_than} {meters 25}} {detection visible}}}
     {"default"
      {"inventory" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_11"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {action take_from} {item "ammo eng_revolver_clip_38"} {amount 120} {entity {source advanced} {amount 1} {sort {type entity} {entity {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_11"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}}} {ignore_captured_by_user 0} {group {select {tag {tag _ufb_supply_body_%team}}}
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo eng_revolver_clip_38"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}}}
      {"effect" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_11"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {effect ufb_supply_cooldown}}
     }
    }
   }
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_actor_%team}} {tag_remove _ufb_supply_actor_%team}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_body_%team}} {tag_remove _ufb_supply_body_%team}}
   {"delay" {time 5.1}}
   {"trigger" {name "ufb/supply/ufb_supply_11 %team"}}
  }
 }
)
("ufb_supply_ufb_supply_11" team(a) foe(b))
("ufb_supply_ufb_supply_11" team(b) foe(a))
(define "ufb_supply_ufb_supply_12"
 {"ufb/supply/ufb_supply_12 %team"
  {condition {terms {"1.rand" {value 1}}}}
  {actions
   {"if" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {group
   {include {prop {prop human}} {state {state operatable}} {team {team %team}} {with_item {type using} {item "ufb_supply_12"}}}
   {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} {prop {prop repairing}} {prop {prop throwing}} {with_item {type amount} {item "ammo eng_revolver_clip_45"} {min 24}}
    {tag {tag _ufb_surrendered}} {tag {tag _lua_mi}} {tag {tag _lua_ignore}} {tag {tag _ai_do_not_disturb}} {tag {tag repairing}} {tag {tag reloading}} {tag {tag bleeding}} {tag {tag _bleeding}} {tag {tag wounded}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag medic}} {tag {tag _ai_medic}} {tag {tag bot_medic}} {tag {tag _ufb_healing_active}} {tag {tag _ufb_autonomy_moving}} {tag {tag _ai_wounded_carrier}} {tag {tag _ai_ap_grenade}} {tag {tag _ai_at_grenade}} {tag {tag _ai_smoke_grenade}} {tag {tag _ai_suppressed_by_mg}} {tag {tag _ai_mgunner}} {tag {tag _ai_reloading}} {tag {tag _ai_looting_weapon}} {tag {tag crew}} {tag {tag tcrew}} {tag {tag ecrew}} {tag {tag ecrew_a}} {tag {tag ecrew_b}} {tag {tag bot_arty}} {tag {tag bot_aa_guard}} {tag {tag _ufb_crew_safe}} {tag {tag _ufb_hf_cover_active}} {tag {tag _ai_wirecutter_in_action}} {tag {tag bot_inf_flank_in_progress}} {tag {tag _ufb_smoke_120m_actor}} {tag {tag _ufb_smoke_60m_actor}} {tag {tag _ufb_smoke_wirecutter_actor}} {tag {tag _ai_at_launcher_30}} {tag {tag _ai_at_launcher_40}} {tag {tag _ai_at_launcher_50}} {tag {tag _ai_at_launcher_60}} {tag {tag _ai_at_launcher_70}} {tag {tag _ai_at_launcher_80}} {tag {tag _ai_at_launcher_90}} {tag {tag _ufb_rescue_active}} {tag {tag _ufb_gun_job_active}} {tag {tag _ufb_combat_busy}} {tag {tag _ufb_job_reserved}} {tag {tag _ufb_supply_cooldown}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group 
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo eng_revolver_clip_45"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}} {distance {mode near_than} {meters 3}}
    {tag {"tag pair"} {"for selector" _ufb_supply_actor_%team} {"for enemy" _ufb_supply_body_%team}}}
    {"switch"
     {"case" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_12"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group {include {team {team %foe}} {state {state operatable}}} {exclude {state {state dead}} {state {state inactive}}}}} {distance {mode near_than} {meters 25}} {detection visible}}}
     {"default"
      {"inventory" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_12"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {action take_from} {item "ammo eng_revolver_clip_45"} {amount 120} {entity {source advanced} {amount 1} {sort {type entity} {entity {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_12"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}}} {ignore_captured_by_user 0} {group {select {tag {tag _ufb_supply_body_%team}}}
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo eng_revolver_clip_45"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}}}
      {"effect" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_12"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {effect ufb_supply_cooldown}}
     }
    }
   }
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_actor_%team}} {tag_remove _ufb_supply_actor_%team}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_body_%team}} {tag_remove _ufb_supply_body_%team}}
   {"delay" {time 5.2}}
   {"trigger" {name "ufb/supply/ufb_supply_12 %team"}}
  }
 }
)
("ufb_supply_ufb_supply_12" team(a) foe(b))
("ufb_supply_ufb_supply_12" team(b) foe(a))
(define "ufb_supply_ufb_supply_13"
 {"ufb/supply/ufb_supply_13 %team"
  {condition {terms {"1.rand" {value 1}}}}
  {actions
   {"if" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {group
   {include {prop {prop human}} {state {state operatable}} {team {team %team}} {with_item {type using} {item "ufb_supply_13"}}}
   {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} {prop {prop repairing}} {prop {prop throwing}} {with_item {type amount} {item "ammo eng_smg"} {min 24}}
    {tag {tag _ufb_surrendered}} {tag {tag _lua_mi}} {tag {tag _lua_ignore}} {tag {tag _ai_do_not_disturb}} {tag {tag repairing}} {tag {tag reloading}} {tag {tag bleeding}} {tag {tag _bleeding}} {tag {tag wounded}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag medic}} {tag {tag _ai_medic}} {tag {tag bot_medic}} {tag {tag _ufb_healing_active}} {tag {tag _ufb_autonomy_moving}} {tag {tag _ai_wounded_carrier}} {tag {tag _ai_ap_grenade}} {tag {tag _ai_at_grenade}} {tag {tag _ai_smoke_grenade}} {tag {tag _ai_suppressed_by_mg}} {tag {tag _ai_mgunner}} {tag {tag _ai_reloading}} {tag {tag _ai_looting_weapon}} {tag {tag crew}} {tag {tag tcrew}} {tag {tag ecrew}} {tag {tag ecrew_a}} {tag {tag ecrew_b}} {tag {tag bot_arty}} {tag {tag bot_aa_guard}} {tag {tag _ufb_crew_safe}} {tag {tag _ufb_hf_cover_active}} {tag {tag _ai_wirecutter_in_action}} {tag {tag bot_inf_flank_in_progress}} {tag {tag _ufb_smoke_120m_actor}} {tag {tag _ufb_smoke_60m_actor}} {tag {tag _ufb_smoke_wirecutter_actor}} {tag {tag _ai_at_launcher_30}} {tag {tag _ai_at_launcher_40}} {tag {tag _ai_at_launcher_50}} {tag {tag _ai_at_launcher_60}} {tag {tag _ai_at_launcher_70}} {tag {tag _ai_at_launcher_80}} {tag {tag _ai_at_launcher_90}} {tag {tag _ufb_rescue_active}} {tag {tag _ufb_gun_job_active}} {tag {tag _ufb_combat_busy}} {tag {tag _ufb_job_reserved}} {tag {tag _ufb_supply_cooldown}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group 
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo eng_smg"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}} {distance {mode near_than} {meters 3}}
    {tag {"tag pair"} {"for selector" _ufb_supply_actor_%team} {"for enemy" _ufb_supply_body_%team}}}
    {"switch"
     {"case" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_13"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group {include {team {team %foe}} {state {state operatable}}} {exclude {state {state dead}} {state {state inactive}}}}} {distance {mode near_than} {meters 25}} {detection visible}}}
     {"default"
      {"inventory" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_13"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {action take_from} {item "ammo eng_smg"} {amount 120} {entity {source advanced} {amount 1} {sort {type entity} {entity {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_13"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}}} {ignore_captured_by_user 0} {group {select {tag {tag _ufb_supply_body_%team}}}
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo eng_smg"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}}}
      {"effect" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_13"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {effect ufb_supply_cooldown}}
     }
    }
   }
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_actor_%team}} {tag_remove _ufb_supply_actor_%team}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_body_%team}} {tag_remove _ufb_supply_body_%team}}
   {"delay" {time 5.3}}
   {"trigger" {name "ufb/supply/ufb_supply_13 %team"}}
  }
 }
)
("ufb_supply_ufb_supply_13" team(a) foe(b))
("ufb_supply_ufb_supply_13" team(b) foe(a))
(define "ufb_supply_ufb_supply_14"
 {"ufb/supply/ufb_supply_14 %team"
  {condition {terms {"1.rand" {value 1}}}}
  {actions
   {"if" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {group
   {include {prop {prop human}} {state {state operatable}} {team {team %team}} {with_item {type using} {item "ufb_supply_14"}}}
   {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} {prop {prop repairing}} {prop {prop throwing}} {with_item {type amount} {item "ammo fedorov"} {min 24}}
    {tag {tag _ufb_surrendered}} {tag {tag _lua_mi}} {tag {tag _lua_ignore}} {tag {tag _ai_do_not_disturb}} {tag {tag repairing}} {tag {tag reloading}} {tag {tag bleeding}} {tag {tag _bleeding}} {tag {tag wounded}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag medic}} {tag {tag _ai_medic}} {tag {tag bot_medic}} {tag {tag _ufb_healing_active}} {tag {tag _ufb_autonomy_moving}} {tag {tag _ai_wounded_carrier}} {tag {tag _ai_ap_grenade}} {tag {tag _ai_at_grenade}} {tag {tag _ai_smoke_grenade}} {tag {tag _ai_suppressed_by_mg}} {tag {tag _ai_mgunner}} {tag {tag _ai_reloading}} {tag {tag _ai_looting_weapon}} {tag {tag crew}} {tag {tag tcrew}} {tag {tag ecrew}} {tag {tag ecrew_a}} {tag {tag ecrew_b}} {tag {tag bot_arty}} {tag {tag bot_aa_guard}} {tag {tag _ufb_crew_safe}} {tag {tag _ufb_hf_cover_active}} {tag {tag _ai_wirecutter_in_action}} {tag {tag bot_inf_flank_in_progress}} {tag {tag _ufb_smoke_120m_actor}} {tag {tag _ufb_smoke_60m_actor}} {tag {tag _ufb_smoke_wirecutter_actor}} {tag {tag _ai_at_launcher_30}} {tag {tag _ai_at_launcher_40}} {tag {tag _ai_at_launcher_50}} {tag {tag _ai_at_launcher_60}} {tag {tag _ai_at_launcher_70}} {tag {tag _ai_at_launcher_80}} {tag {tag _ai_at_launcher_90}} {tag {tag _ufb_rescue_active}} {tag {tag _ufb_gun_job_active}} {tag {tag _ufb_combat_busy}} {tag {tag _ufb_job_reserved}} {tag {tag _ufb_supply_cooldown}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group 
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo fedorov"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}} {distance {mode near_than} {meters 3}}
    {tag {"tag pair"} {"for selector" _ufb_supply_actor_%team} {"for enemy" _ufb_supply_body_%team}}}
    {"switch"
     {"case" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_14"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group {include {team {team %foe}} {state {state operatable}}} {exclude {state {state dead}} {state {state inactive}}}}} {distance {mode near_than} {meters 25}} {detection visible}}}
     {"default"
      {"inventory" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_14"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {action take_from} {item "ammo fedorov"} {amount 120} {entity {source advanced} {amount 1} {sort {type entity} {entity {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_14"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}}} {ignore_captured_by_user 0} {group {select {tag {tag _ufb_supply_body_%team}}}
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo fedorov"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}}}
      {"effect" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_14"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {effect ufb_supply_cooldown}}
     }
    }
   }
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_actor_%team}} {tag_remove _ufb_supply_actor_%team}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_body_%team}} {tag_remove _ufb_supply_body_%team}}
   {"delay" {time 5.4}}
   {"trigger" {name "ufb/supply/ufb_supply_14 %team"}}
  }
 }
)
("ufb_supply_ufb_supply_14" team(a) foe(b))
("ufb_supply_ufb_supply_14" team(b) foe(a))
(define "ufb_supply_ufb_supply_15"
 {"ufb/supply/ufb_supply_15 %team"
  {condition {terms {"1.rand" {value 1}}}}
  {actions
   {"if" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {group
   {include {prop {prop human}} {state {state operatable}} {team {team %team}} {with_item {type using} {item "ufb_supply_15"}}}
   {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} {prop {prop repairing}} {prop {prop throwing}} {with_item {type amount} {item "ammo fg42"} {min 24}}
    {tag {tag _ufb_surrendered}} {tag {tag _lua_mi}} {tag {tag _lua_ignore}} {tag {tag _ai_do_not_disturb}} {tag {tag repairing}} {tag {tag reloading}} {tag {tag bleeding}} {tag {tag _bleeding}} {tag {tag wounded}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag medic}} {tag {tag _ai_medic}} {tag {tag bot_medic}} {tag {tag _ufb_healing_active}} {tag {tag _ufb_autonomy_moving}} {tag {tag _ai_wounded_carrier}} {tag {tag _ai_ap_grenade}} {tag {tag _ai_at_grenade}} {tag {tag _ai_smoke_grenade}} {tag {tag _ai_suppressed_by_mg}} {tag {tag _ai_mgunner}} {tag {tag _ai_reloading}} {tag {tag _ai_looting_weapon}} {tag {tag crew}} {tag {tag tcrew}} {tag {tag ecrew}} {tag {tag ecrew_a}} {tag {tag ecrew_b}} {tag {tag bot_arty}} {tag {tag bot_aa_guard}} {tag {tag _ufb_crew_safe}} {tag {tag _ufb_hf_cover_active}} {tag {tag _ai_wirecutter_in_action}} {tag {tag bot_inf_flank_in_progress}} {tag {tag _ufb_smoke_120m_actor}} {tag {tag _ufb_smoke_60m_actor}} {tag {tag _ufb_smoke_wirecutter_actor}} {tag {tag _ai_at_launcher_30}} {tag {tag _ai_at_launcher_40}} {tag {tag _ai_at_launcher_50}} {tag {tag _ai_at_launcher_60}} {tag {tag _ai_at_launcher_70}} {tag {tag _ai_at_launcher_80}} {tag {tag _ai_at_launcher_90}} {tag {tag _ufb_rescue_active}} {tag {tag _ufb_gun_job_active}} {tag {tag _ufb_combat_busy}} {tag {tag _ufb_job_reserved}} {tag {tag _ufb_supply_cooldown}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group 
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo fg42"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}} {distance {mode near_than} {meters 3}}
    {tag {"tag pair"} {"for selector" _ufb_supply_actor_%team} {"for enemy" _ufb_supply_body_%team}}}
    {"switch"
     {"case" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_15"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group {include {team {team %foe}} {state {state operatable}}} {exclude {state {state dead}} {state {state inactive}}}}} {distance {mode near_than} {meters 25}} {detection visible}}}
     {"default"
      {"inventory" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_15"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {action take_from} {item "ammo fg42"} {amount 120} {entity {source advanced} {amount 1} {sort {type entity} {entity {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_15"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}}} {ignore_captured_by_user 0} {group {select {tag {tag _ufb_supply_body_%team}}}
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo fg42"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}}}
      {"effect" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_15"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {effect ufb_supply_cooldown}}
     }
    }
   }
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_actor_%team}} {tag_remove _ufb_supply_actor_%team}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_body_%team}} {tag_remove _ufb_supply_body_%team}}
   {"delay" {time 5.5}}
   {"trigger" {name "ufb/supply/ufb_supply_15 %team"}}
  }
 }
)
("ufb_supply_ufb_supply_15" team(a) foe(b))
("ufb_supply_ufb_supply_15" team(b) foe(a))
(define "ufb_supply_ufb_supply_16"
 {"ufb/supply/ufb_supply_16 %team"
  {condition {terms {"1.rand" {value 1}}}}
  {actions
   {"if" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {group
   {include {prop {prop human}} {state {state operatable}} {team {team %team}} {with_item {type using} {item "ufb_supply_16"}}}
   {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} {prop {prop repairing}} {prop {prop throwing}} {with_item {type amount} {item "ammo fm_24_29_mag"} {min 24}}
    {tag {tag _ufb_surrendered}} {tag {tag _lua_mi}} {tag {tag _lua_ignore}} {tag {tag _ai_do_not_disturb}} {tag {tag repairing}} {tag {tag reloading}} {tag {tag bleeding}} {tag {tag _bleeding}} {tag {tag wounded}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag medic}} {tag {tag _ai_medic}} {tag {tag bot_medic}} {tag {tag _ufb_healing_active}} {tag {tag _ufb_autonomy_moving}} {tag {tag _ai_wounded_carrier}} {tag {tag _ai_ap_grenade}} {tag {tag _ai_at_grenade}} {tag {tag _ai_smoke_grenade}} {tag {tag _ai_suppressed_by_mg}} {tag {tag _ai_mgunner}} {tag {tag _ai_reloading}} {tag {tag _ai_looting_weapon}} {tag {tag crew}} {tag {tag tcrew}} {tag {tag ecrew}} {tag {tag ecrew_a}} {tag {tag ecrew_b}} {tag {tag bot_arty}} {tag {tag bot_aa_guard}} {tag {tag _ufb_crew_safe}} {tag {tag _ufb_hf_cover_active}} {tag {tag _ai_wirecutter_in_action}} {tag {tag bot_inf_flank_in_progress}} {tag {tag _ufb_smoke_120m_actor}} {tag {tag _ufb_smoke_60m_actor}} {tag {tag _ufb_smoke_wirecutter_actor}} {tag {tag _ai_at_launcher_30}} {tag {tag _ai_at_launcher_40}} {tag {tag _ai_at_launcher_50}} {tag {tag _ai_at_launcher_60}} {tag {tag _ai_at_launcher_70}} {tag {tag _ai_at_launcher_80}} {tag {tag _ai_at_launcher_90}} {tag {tag _ufb_rescue_active}} {tag {tag _ufb_gun_job_active}} {tag {tag _ufb_combat_busy}} {tag {tag _ufb_job_reserved}} {tag {tag _ufb_supply_cooldown}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group 
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo fm_24_29_mag"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}} {distance {mode near_than} {meters 3}}
    {tag {"tag pair"} {"for selector" _ufb_supply_actor_%team} {"for enemy" _ufb_supply_body_%team}}}
    {"switch"
     {"case" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_16"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group {include {team {team %foe}} {state {state operatable}}} {exclude {state {state dead}} {state {state inactive}}}}} {distance {mode near_than} {meters 25}} {detection visible}}}
     {"default"
      {"inventory" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_16"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {action take_from} {item "ammo fm_24_29_mag"} {amount 120} {entity {source advanced} {amount 1} {sort {type entity} {entity {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_16"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}}} {ignore_captured_by_user 0} {group {select {tag {tag _ufb_supply_body_%team}}}
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo fm_24_29_mag"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}}}
      {"effect" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_16"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {effect ufb_supply_cooldown}}
     }
    }
   }
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_actor_%team}} {tag_remove _ufb_supply_actor_%team}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_body_%team}} {tag_remove _ufb_supply_body_%team}}
   {"delay" {time 5.6}}
   {"trigger" {name "ufb/supply/ufb_supply_16 %team"}}
  }
 }
)
("ufb_supply_ufb_supply_16" team(a) foe(b))
("ufb_supply_ufb_supply_16" team(b) foe(a))
(define "ufb_supply_ufb_supply_17"
 {"ufb/supply/ufb_supply_17 %team"
  {condition {terms {"1.rand" {value 1}}}}
  {actions
   {"if" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {group
   {include {prop {prop human}} {state {state operatable}} {team {team %team}} {with_item {type using} {item "ufb_supply_17"}}}
   {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} {prop {prop repairing}} {prop {prop throwing}} {with_item {type amount} {item "ammo hdm_mag"} {min 24}}
    {tag {tag _ufb_surrendered}} {tag {tag _lua_mi}} {tag {tag _lua_ignore}} {tag {tag _ai_do_not_disturb}} {tag {tag repairing}} {tag {tag reloading}} {tag {tag bleeding}} {tag {tag _bleeding}} {tag {tag wounded}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag medic}} {tag {tag _ai_medic}} {tag {tag bot_medic}} {tag {tag _ufb_healing_active}} {tag {tag _ufb_autonomy_moving}} {tag {tag _ai_wounded_carrier}} {tag {tag _ai_ap_grenade}} {tag {tag _ai_at_grenade}} {tag {tag _ai_smoke_grenade}} {tag {tag _ai_suppressed_by_mg}} {tag {tag _ai_mgunner}} {tag {tag _ai_reloading}} {tag {tag _ai_looting_weapon}} {tag {tag crew}} {tag {tag tcrew}} {tag {tag ecrew}} {tag {tag ecrew_a}} {tag {tag ecrew_b}} {tag {tag bot_arty}} {tag {tag bot_aa_guard}} {tag {tag _ufb_crew_safe}} {tag {tag _ufb_hf_cover_active}} {tag {tag _ai_wirecutter_in_action}} {tag {tag bot_inf_flank_in_progress}} {tag {tag _ufb_smoke_120m_actor}} {tag {tag _ufb_smoke_60m_actor}} {tag {tag _ufb_smoke_wirecutter_actor}} {tag {tag _ai_at_launcher_30}} {tag {tag _ai_at_launcher_40}} {tag {tag _ai_at_launcher_50}} {tag {tag _ai_at_launcher_60}} {tag {tag _ai_at_launcher_70}} {tag {tag _ai_at_launcher_80}} {tag {tag _ai_at_launcher_90}} {tag {tag _ufb_rescue_active}} {tag {tag _ufb_gun_job_active}} {tag {tag _ufb_combat_busy}} {tag {tag _ufb_job_reserved}} {tag {tag _ufb_supply_cooldown}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group 
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo hdm_mag"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}} {distance {mode near_than} {meters 3}}
    {tag {"tag pair"} {"for selector" _ufb_supply_actor_%team} {"for enemy" _ufb_supply_body_%team}}}
    {"switch"
     {"case" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_17"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group {include {team {team %foe}} {state {state operatable}}} {exclude {state {state dead}} {state {state inactive}}}}} {distance {mode near_than} {meters 25}} {detection visible}}}
     {"default"
      {"inventory" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_17"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {action take_from} {item "ammo hdm_mag"} {amount 120} {entity {source advanced} {amount 1} {sort {type entity} {entity {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_17"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}}} {ignore_captured_by_user 0} {group {select {tag {tag _ufb_supply_body_%team}}}
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo hdm_mag"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}}}
      {"effect" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_17"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {effect ufb_supply_cooldown}}
     }
    }
   }
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_actor_%team}} {tag_remove _ufb_supply_actor_%team}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_body_%team}} {tag_remove _ufb_supply_body_%team}}
   {"delay" {time 5.7}}
   {"trigger" {name "ufb/supply/ufb_supply_17 %team"}}
  }
 }
)
("ufb_supply_ufb_supply_17" team(a) foe(b))
("ufb_supply_ufb_supply_17" team(b) foe(a))
(define "ufb_supply_ufb_supply_18"
 {"ufb/supply/ufb_supply_18 %team"
  {condition {terms {"1.rand" {value 1}}}}
  {actions
   {"if" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {group
   {include {prop {prop human}} {state {state operatable}} {team {team %team}} {with_item {type using} {item "ufb_supply_18"}}}
   {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} {prop {prop repairing}} {prop {prop throwing}} {with_item {type amount} {item "ammo hmgun_ger"} {min 24}}
    {tag {tag _ufb_surrendered}} {tag {tag _lua_mi}} {tag {tag _lua_ignore}} {tag {tag _ai_do_not_disturb}} {tag {tag repairing}} {tag {tag reloading}} {tag {tag bleeding}} {tag {tag _bleeding}} {tag {tag wounded}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag medic}} {tag {tag _ai_medic}} {tag {tag bot_medic}} {tag {tag _ufb_healing_active}} {tag {tag _ufb_autonomy_moving}} {tag {tag _ai_wounded_carrier}} {tag {tag _ai_ap_grenade}} {tag {tag _ai_at_grenade}} {tag {tag _ai_smoke_grenade}} {tag {tag _ai_suppressed_by_mg}} {tag {tag _ai_mgunner}} {tag {tag _ai_reloading}} {tag {tag _ai_looting_weapon}} {tag {tag crew}} {tag {tag tcrew}} {tag {tag ecrew}} {tag {tag ecrew_a}} {tag {tag ecrew_b}} {tag {tag bot_arty}} {tag {tag bot_aa_guard}} {tag {tag _ufb_crew_safe}} {tag {tag _ufb_hf_cover_active}} {tag {tag _ai_wirecutter_in_action}} {tag {tag bot_inf_flank_in_progress}} {tag {tag _ufb_smoke_120m_actor}} {tag {tag _ufb_smoke_60m_actor}} {tag {tag _ufb_smoke_wirecutter_actor}} {tag {tag _ai_at_launcher_30}} {tag {tag _ai_at_launcher_40}} {tag {tag _ai_at_launcher_50}} {tag {tag _ai_at_launcher_60}} {tag {tag _ai_at_launcher_70}} {tag {tag _ai_at_launcher_80}} {tag {tag _ai_at_launcher_90}} {tag {tag _ufb_rescue_active}} {tag {tag _ufb_gun_job_active}} {tag {tag _ufb_combat_busy}} {tag {tag _ufb_job_reserved}} {tag {tag _ufb_supply_cooldown}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group 
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo hmgun_ger"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}} {distance {mode near_than} {meters 3}}
    {tag {"tag pair"} {"for selector" _ufb_supply_actor_%team} {"for enemy" _ufb_supply_body_%team}}}
    {"switch"
     {"case" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_18"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group {include {team {team %foe}} {state {state operatable}}} {exclude {state {state dead}} {state {state inactive}}}}} {distance {mode near_than} {meters 25}} {detection visible}}}
     {"default"
      {"inventory" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_18"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {action take_from} {item "ammo hmgun_ger"} {amount 120} {entity {source advanced} {amount 1} {sort {type entity} {entity {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_18"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}}} {ignore_captured_by_user 0} {group {select {tag {tag _ufb_supply_body_%team}}}
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo hmgun_ger"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}}}
      {"effect" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_18"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {effect ufb_supply_cooldown}}
     }
    }
   }
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_actor_%team}} {tag_remove _ufb_supply_actor_%team}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_body_%team}} {tag_remove _ufb_supply_body_%team}}
   {"delay" {time 5.8}}
   {"trigger" {name "ufb/supply/ufb_supply_18 %team"}}
  }
 }
)
("ufb_supply_ufb_supply_18" team(a) foe(b))
("ufb_supply_ufb_supply_18" team(b) foe(a))
(define "ufb_supply_ufb_supply_19"
 {"ufb/supply/ufb_supply_19 %team"
  {condition {terms {"1.rand" {value 1}}}}
  {actions
   {"if" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {group
   {include {prop {prop human}} {state {state operatable}} {team {team %team}} {with_item {type using} {item "ufb_supply_19"}}}
   {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} {prop {prop repairing}} {prop {prop throwing}} {with_item {type amount} {item "ammo kg_m21_mag"} {min 24}}
    {tag {tag _ufb_surrendered}} {tag {tag _lua_mi}} {tag {tag _lua_ignore}} {tag {tag _ai_do_not_disturb}} {tag {tag repairing}} {tag {tag reloading}} {tag {tag bleeding}} {tag {tag _bleeding}} {tag {tag wounded}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag medic}} {tag {tag _ai_medic}} {tag {tag bot_medic}} {tag {tag _ufb_healing_active}} {tag {tag _ufb_autonomy_moving}} {tag {tag _ai_wounded_carrier}} {tag {tag _ai_ap_grenade}} {tag {tag _ai_at_grenade}} {tag {tag _ai_smoke_grenade}} {tag {tag _ai_suppressed_by_mg}} {tag {tag _ai_mgunner}} {tag {tag _ai_reloading}} {tag {tag _ai_looting_weapon}} {tag {tag crew}} {tag {tag tcrew}} {tag {tag ecrew}} {tag {tag ecrew_a}} {tag {tag ecrew_b}} {tag {tag bot_arty}} {tag {tag bot_aa_guard}} {tag {tag _ufb_crew_safe}} {tag {tag _ufb_hf_cover_active}} {tag {tag _ai_wirecutter_in_action}} {tag {tag bot_inf_flank_in_progress}} {tag {tag _ufb_smoke_120m_actor}} {tag {tag _ufb_smoke_60m_actor}} {tag {tag _ufb_smoke_wirecutter_actor}} {tag {tag _ai_at_launcher_30}} {tag {tag _ai_at_launcher_40}} {tag {tag _ai_at_launcher_50}} {tag {tag _ai_at_launcher_60}} {tag {tag _ai_at_launcher_70}} {tag {tag _ai_at_launcher_80}} {tag {tag _ai_at_launcher_90}} {tag {tag _ufb_rescue_active}} {tag {tag _ufb_gun_job_active}} {tag {tag _ufb_combat_busy}} {tag {tag _ufb_job_reserved}} {tag {tag _ufb_supply_cooldown}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group 
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo kg_m21_mag"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}} {distance {mode near_than} {meters 3}}
    {tag {"tag pair"} {"for selector" _ufb_supply_actor_%team} {"for enemy" _ufb_supply_body_%team}}}
    {"switch"
     {"case" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_19"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group {include {team {team %foe}} {state {state operatable}}} {exclude {state {state dead}} {state {state inactive}}}}} {distance {mode near_than} {meters 25}} {detection visible}}}
     {"default"
      {"inventory" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_19"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {action take_from} {item "ammo kg_m21_mag"} {amount 120} {entity {source advanced} {amount 1} {sort {type entity} {entity {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_19"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}}} {ignore_captured_by_user 0} {group {select {tag {tag _ufb_supply_body_%team}}}
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo kg_m21_mag"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}}}
      {"effect" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_19"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {effect ufb_supply_cooldown}}
     }
    }
   }
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_actor_%team}} {tag_remove _ufb_supply_actor_%team}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_body_%team}} {tag_remove _ufb_supply_body_%team}}
   {"delay" {time 5.9}}
   {"trigger" {name "ufb/supply/ufb_supply_19 %team"}}
  }
 }
)
("ufb_supply_ufb_supply_19" team(a) foe(b))
("ufb_supply_ufb_supply_19" team(b) foe(a))
(define "ufb_supply_ufb_supply_20"
 {"ufb/supply/ufb_supply_20 %team"
  {condition {terms {"1.rand" {value 1}}}}
  {actions
   {"if" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {group
   {include {prop {prop human}} {state {state operatable}} {team {team %team}} {with_item {type using} {item "ufb_supply_20"}}}
   {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} {prop {prop repairing}} {prop {prop throwing}} {with_item {type amount} {item "ammo lewis_mag"} {min 24}}
    {tag {tag _ufb_surrendered}} {tag {tag _lua_mi}} {tag {tag _lua_ignore}} {tag {tag _ai_do_not_disturb}} {tag {tag repairing}} {tag {tag reloading}} {tag {tag bleeding}} {tag {tag _bleeding}} {tag {tag wounded}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag medic}} {tag {tag _ai_medic}} {tag {tag bot_medic}} {tag {tag _ufb_healing_active}} {tag {tag _ufb_autonomy_moving}} {tag {tag _ai_wounded_carrier}} {tag {tag _ai_ap_grenade}} {tag {tag _ai_at_grenade}} {tag {tag _ai_smoke_grenade}} {tag {tag _ai_suppressed_by_mg}} {tag {tag _ai_mgunner}} {tag {tag _ai_reloading}} {tag {tag _ai_looting_weapon}} {tag {tag crew}} {tag {tag tcrew}} {tag {tag ecrew}} {tag {tag ecrew_a}} {tag {tag ecrew_b}} {tag {tag bot_arty}} {tag {tag bot_aa_guard}} {tag {tag _ufb_crew_safe}} {tag {tag _ufb_hf_cover_active}} {tag {tag _ai_wirecutter_in_action}} {tag {tag bot_inf_flank_in_progress}} {tag {tag _ufb_smoke_120m_actor}} {tag {tag _ufb_smoke_60m_actor}} {tag {tag _ufb_smoke_wirecutter_actor}} {tag {tag _ai_at_launcher_30}} {tag {tag _ai_at_launcher_40}} {tag {tag _ai_at_launcher_50}} {tag {tag _ai_at_launcher_60}} {tag {tag _ai_at_launcher_70}} {tag {tag _ai_at_launcher_80}} {tag {tag _ai_at_launcher_90}} {tag {tag _ufb_rescue_active}} {tag {tag _ufb_gun_job_active}} {tag {tag _ufb_combat_busy}} {tag {tag _ufb_job_reserved}} {tag {tag _ufb_supply_cooldown}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group 
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo lewis_mag"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}} {distance {mode near_than} {meters 3}}
    {tag {"tag pair"} {"for selector" _ufb_supply_actor_%team} {"for enemy" _ufb_supply_body_%team}}}
    {"switch"
     {"case" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_20"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group {include {team {team %foe}} {state {state operatable}}} {exclude {state {state dead}} {state {state inactive}}}}} {distance {mode near_than} {meters 25}} {detection visible}}}
     {"default"
      {"inventory" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_20"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {action take_from} {item "ammo lewis_mag"} {amount 120} {entity {source advanced} {amount 1} {sort {type entity} {entity {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_20"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}}} {ignore_captured_by_user 0} {group {select {tag {tag _ufb_supply_body_%team}}}
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo lewis_mag"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}}}
      {"effect" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_20"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {effect ufb_supply_cooldown}}
     }
    }
   }
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_actor_%team}} {tag_remove _ufb_supply_actor_%team}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_body_%team}} {tag_remove _ufb_supply_body_%team}}
   {"delay" {time 4.0}}
   {"trigger" {name "ufb/supply/ufb_supply_20 %team"}}
  }
 }
)
("ufb_supply_ufb_supply_20" team(a) foe(b))
("ufb_supply_ufb_supply_20" team(b) foe(a))
(define "ufb_supply_ufb_supply_21"
 {"ufb/supply/ufb_supply_21 %team"
  {condition {terms {"1.rand" {value 1}}}}
  {actions
   {"if" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {group
   {include {prop {prop human}} {state {state operatable}} {team {team %team}} {with_item {type using} {item "ufb_supply_21"}}}
   {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} {prop {prop repairing}} {prop {prop throwing}} {with_item {type amount} {item "ammo lewis_mag_rus"} {min 24}}
    {tag {tag _ufb_surrendered}} {tag {tag _lua_mi}} {tag {tag _lua_ignore}} {tag {tag _ai_do_not_disturb}} {tag {tag repairing}} {tag {tag reloading}} {tag {tag bleeding}} {tag {tag _bleeding}} {tag {tag wounded}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag medic}} {tag {tag _ai_medic}} {tag {tag bot_medic}} {tag {tag _ufb_healing_active}} {tag {tag _ufb_autonomy_moving}} {tag {tag _ai_wounded_carrier}} {tag {tag _ai_ap_grenade}} {tag {tag _ai_at_grenade}} {tag {tag _ai_smoke_grenade}} {tag {tag _ai_suppressed_by_mg}} {tag {tag _ai_mgunner}} {tag {tag _ai_reloading}} {tag {tag _ai_looting_weapon}} {tag {tag crew}} {tag {tag tcrew}} {tag {tag ecrew}} {tag {tag ecrew_a}} {tag {tag ecrew_b}} {tag {tag bot_arty}} {tag {tag bot_aa_guard}} {tag {tag _ufb_crew_safe}} {tag {tag _ufb_hf_cover_active}} {tag {tag _ai_wirecutter_in_action}} {tag {tag bot_inf_flank_in_progress}} {tag {tag _ufb_smoke_120m_actor}} {tag {tag _ufb_smoke_60m_actor}} {tag {tag _ufb_smoke_wirecutter_actor}} {tag {tag _ai_at_launcher_30}} {tag {tag _ai_at_launcher_40}} {tag {tag _ai_at_launcher_50}} {tag {tag _ai_at_launcher_60}} {tag {tag _ai_at_launcher_70}} {tag {tag _ai_at_launcher_80}} {tag {tag _ai_at_launcher_90}} {tag {tag _ufb_rescue_active}} {tag {tag _ufb_gun_job_active}} {tag {tag _ufb_combat_busy}} {tag {tag _ufb_job_reserved}} {tag {tag _ufb_supply_cooldown}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group 
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo lewis_mag_rus"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}} {distance {mode near_than} {meters 3}}
    {tag {"tag pair"} {"for selector" _ufb_supply_actor_%team} {"for enemy" _ufb_supply_body_%team}}}
    {"switch"
     {"case" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_21"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group {include {team {team %foe}} {state {state operatable}}} {exclude {state {state dead}} {state {state inactive}}}}} {distance {mode near_than} {meters 25}} {detection visible}}}
     {"default"
      {"inventory" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_21"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {action take_from} {item "ammo lewis_mag_rus"} {amount 120} {entity {source advanced} {amount 1} {sort {type entity} {entity {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_21"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}}} {ignore_captured_by_user 0} {group {select {tag {tag _ufb_supply_body_%team}}}
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo lewis_mag_rus"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}}}
      {"effect" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_21"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {effect ufb_supply_cooldown}}
     }
    }
   }
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_actor_%team}} {tag_remove _ufb_supply_actor_%team}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_body_%team}} {tag_remove _ufb_supply_body_%team}}
   {"delay" {time 4.1}}
   {"trigger" {name "ufb/supply/ufb_supply_21 %team"}}
  }
 }
)
("ufb_supply_ufb_supply_21" team(a) foe(b))
("ufb_supply_ufb_supply_21" team(b) foe(a))
(define "ufb_supply_ufb_supply_22"
 {"ufb/supply/ufb_supply_22 %team"
  {condition {terms {"1.rand" {value 1}}}}
  {actions
   {"if" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {group
   {include {prop {prop human}} {state {state operatable}} {team {team %team}} {with_item {type using} {item "ufb_supply_22"}}}
   {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} {prop {prop repairing}} {prop {prop throwing}} {with_item {type amount} {item "ammo m1907_mag"} {min 24}}
    {tag {tag _ufb_surrendered}} {tag {tag _lua_mi}} {tag {tag _lua_ignore}} {tag {tag _ai_do_not_disturb}} {tag {tag repairing}} {tag {tag reloading}} {tag {tag bleeding}} {tag {tag _bleeding}} {tag {tag wounded}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag medic}} {tag {tag _ai_medic}} {tag {tag bot_medic}} {tag {tag _ufb_healing_active}} {tag {tag _ufb_autonomy_moving}} {tag {tag _ai_wounded_carrier}} {tag {tag _ai_ap_grenade}} {tag {tag _ai_at_grenade}} {tag {tag _ai_smoke_grenade}} {tag {tag _ai_suppressed_by_mg}} {tag {tag _ai_mgunner}} {tag {tag _ai_reloading}} {tag {tag _ai_looting_weapon}} {tag {tag crew}} {tag {tag tcrew}} {tag {tag ecrew}} {tag {tag ecrew_a}} {tag {tag ecrew_b}} {tag {tag bot_arty}} {tag {tag bot_aa_guard}} {tag {tag _ufb_crew_safe}} {tag {tag _ufb_hf_cover_active}} {tag {tag _ai_wirecutter_in_action}} {tag {tag bot_inf_flank_in_progress}} {tag {tag _ufb_smoke_120m_actor}} {tag {tag _ufb_smoke_60m_actor}} {tag {tag _ufb_smoke_wirecutter_actor}} {tag {tag _ai_at_launcher_30}} {tag {tag _ai_at_launcher_40}} {tag {tag _ai_at_launcher_50}} {tag {tag _ai_at_launcher_60}} {tag {tag _ai_at_launcher_70}} {tag {tag _ai_at_launcher_80}} {tag {tag _ai_at_launcher_90}} {tag {tag _ufb_rescue_active}} {tag {tag _ufb_gun_job_active}} {tag {tag _ufb_combat_busy}} {tag {tag _ufb_job_reserved}} {tag {tag _ufb_supply_cooldown}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group 
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo m1907_mag"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}} {distance {mode near_than} {meters 3}}
    {tag {"tag pair"} {"for selector" _ufb_supply_actor_%team} {"for enemy" _ufb_supply_body_%team}}}
    {"switch"
     {"case" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_22"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group {include {team {team %foe}} {state {state operatable}}} {exclude {state {state dead}} {state {state inactive}}}}} {distance {mode near_than} {meters 25}} {detection visible}}}
     {"default"
      {"inventory" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_22"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {action take_from} {item "ammo m1907_mag"} {amount 120} {entity {source advanced} {amount 1} {sort {type entity} {entity {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_22"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}}} {ignore_captured_by_user 0} {group {select {tag {tag _ufb_supply_body_%team}}}
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo m1907_mag"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}}}
      {"effect" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_22"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {effect ufb_supply_cooldown}}
     }
    }
   }
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_actor_%team}} {tag_remove _ufb_supply_actor_%team}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_body_%team}} {tag_remove _ufb_supply_body_%team}}
   {"delay" {time 4.2}}
   {"trigger" {name "ufb/supply/ufb_supply_22 %team"}}
  }
 }
)
("ufb_supply_ufb_supply_22" team(a) foe(b))
("ufb_supply_ufb_supply_22" team(b) foe(a))
(define "ufb_supply_ufb_supply_23"
 {"ufb/supply/ufb_supply_23 %team"
  {condition {terms {"1.rand" {value 1}}}}
  {actions
   {"if" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {group
   {include {prop {prop human}} {state {state operatable}} {team {team %team}} {with_item {type using} {item "ufb_supply_23"}}}
   {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} {prop {prop repairing}} {prop {prop throwing}} {with_item {type amount} {item "ammo m1911_mag"} {min 24}}
    {tag {tag _ufb_surrendered}} {tag {tag _lua_mi}} {tag {tag _lua_ignore}} {tag {tag _ai_do_not_disturb}} {tag {tag repairing}} {tag {tag reloading}} {tag {tag bleeding}} {tag {tag _bleeding}} {tag {tag wounded}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag medic}} {tag {tag _ai_medic}} {tag {tag bot_medic}} {tag {tag _ufb_healing_active}} {tag {tag _ufb_autonomy_moving}} {tag {tag _ai_wounded_carrier}} {tag {tag _ai_ap_grenade}} {tag {tag _ai_at_grenade}} {tag {tag _ai_smoke_grenade}} {tag {tag _ai_suppressed_by_mg}} {tag {tag _ai_mgunner}} {tag {tag _ai_reloading}} {tag {tag _ai_looting_weapon}} {tag {tag crew}} {tag {tag tcrew}} {tag {tag ecrew}} {tag {tag ecrew_a}} {tag {tag ecrew_b}} {tag {tag bot_arty}} {tag {tag bot_aa_guard}} {tag {tag _ufb_crew_safe}} {tag {tag _ufb_hf_cover_active}} {tag {tag _ai_wirecutter_in_action}} {tag {tag bot_inf_flank_in_progress}} {tag {tag _ufb_smoke_120m_actor}} {tag {tag _ufb_smoke_60m_actor}} {tag {tag _ufb_smoke_wirecutter_actor}} {tag {tag _ai_at_launcher_30}} {tag {tag _ai_at_launcher_40}} {tag {tag _ai_at_launcher_50}} {tag {tag _ai_at_launcher_60}} {tag {tag _ai_at_launcher_70}} {tag {tag _ai_at_launcher_80}} {tag {tag _ai_at_launcher_90}} {tag {tag _ufb_rescue_active}} {tag {tag _ufb_gun_job_active}} {tag {tag _ufb_combat_busy}} {tag {tag _ufb_job_reserved}} {tag {tag _ufb_supply_cooldown}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group 
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo m1911_mag"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}} {distance {mode near_than} {meters 3}}
    {tag {"tag pair"} {"for selector" _ufb_supply_actor_%team} {"for enemy" _ufb_supply_body_%team}}}
    {"switch"
     {"case" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_23"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group {include {team {team %foe}} {state {state operatable}}} {exclude {state {state dead}} {state {state inactive}}}}} {distance {mode near_than} {meters 25}} {detection visible}}}
     {"default"
      {"inventory" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_23"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {action take_from} {item "ammo m1911_mag"} {amount 120} {entity {source advanced} {amount 1} {sort {type entity} {entity {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_23"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}}} {ignore_captured_by_user 0} {group {select {tag {tag _ufb_supply_body_%team}}}
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo m1911_mag"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}}}
      {"effect" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_23"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {effect ufb_supply_cooldown}}
     }
    }
   }
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_actor_%team}} {tag_remove _ufb_supply_actor_%team}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_body_%team}} {tag_remove _ufb_supply_body_%team}}
   {"delay" {time 4.3}}
   {"trigger" {name "ufb/supply/ufb_supply_23 %team"}}
  }
 }
)
("ufb_supply_ufb_supply_23" team(a) foe(b))
("ufb_supply_ufb_supply_23" team(b) foe(a))
(define "ufb_supply_ufb_supply_24"
 {"ufb/supply/ufb_supply_24 %team"
  {condition {terms {"1.rand" {value 1}}}}
  {actions
   {"if" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {group
   {include {prop {prop human}} {state {state operatable}} {team {team %team}} {with_item {type using} {item "ufb_supply_24"}}}
   {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} {prop {prop repairing}} {prop {prop throwing}} {with_item {type amount} {item "ammo m1_carbine_mag"} {min 24}}
    {tag {tag _ufb_surrendered}} {tag {tag _lua_mi}} {tag {tag _lua_ignore}} {tag {tag _ai_do_not_disturb}} {tag {tag repairing}} {tag {tag reloading}} {tag {tag bleeding}} {tag {tag _bleeding}} {tag {tag wounded}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag medic}} {tag {tag _ai_medic}} {tag {tag bot_medic}} {tag {tag _ufb_healing_active}} {tag {tag _ufb_autonomy_moving}} {tag {tag _ai_wounded_carrier}} {tag {tag _ai_ap_grenade}} {tag {tag _ai_at_grenade}} {tag {tag _ai_smoke_grenade}} {tag {tag _ai_suppressed_by_mg}} {tag {tag _ai_mgunner}} {tag {tag _ai_reloading}} {tag {tag _ai_looting_weapon}} {tag {tag crew}} {tag {tag tcrew}} {tag {tag ecrew}} {tag {tag ecrew_a}} {tag {tag ecrew_b}} {tag {tag bot_arty}} {tag {tag bot_aa_guard}} {tag {tag _ufb_crew_safe}} {tag {tag _ufb_hf_cover_active}} {tag {tag _ai_wirecutter_in_action}} {tag {tag bot_inf_flank_in_progress}} {tag {tag _ufb_smoke_120m_actor}} {tag {tag _ufb_smoke_60m_actor}} {tag {tag _ufb_smoke_wirecutter_actor}} {tag {tag _ai_at_launcher_30}} {tag {tag _ai_at_launcher_40}} {tag {tag _ai_at_launcher_50}} {tag {tag _ai_at_launcher_60}} {tag {tag _ai_at_launcher_70}} {tag {tag _ai_at_launcher_80}} {tag {tag _ai_at_launcher_90}} {tag {tag _ufb_rescue_active}} {tag {tag _ufb_gun_job_active}} {tag {tag _ufb_combat_busy}} {tag {tag _ufb_job_reserved}} {tag {tag _ufb_supply_cooldown}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group 
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo m1_carbine_mag"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}} {distance {mode near_than} {meters 3}}
    {tag {"tag pair"} {"for selector" _ufb_supply_actor_%team} {"for enemy" _ufb_supply_body_%team}}}
    {"switch"
     {"case" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_24"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group {include {team {team %foe}} {state {state operatable}}} {exclude {state {state dead}} {state {state inactive}}}}} {distance {mode near_than} {meters 25}} {detection visible}}}
     {"default"
      {"inventory" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_24"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {action take_from} {item "ammo m1_carbine_mag"} {amount 120} {entity {source advanced} {amount 1} {sort {type entity} {entity {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_24"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}}} {ignore_captured_by_user 0} {group {select {tag {tag _ufb_supply_body_%team}}}
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo m1_carbine_mag"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}}}
      {"effect" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_24"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {effect ufb_supply_cooldown}}
     }
    }
   }
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_actor_%team}} {tag_remove _ufb_supply_actor_%team}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_body_%team}} {tag_remove _ufb_supply_body_%team}}
   {"delay" {time 4.4}}
   {"trigger" {name "ufb/supply/ufb_supply_24 %team"}}
  }
 }
)
("ufb_supply_ufb_supply_24" team(a) foe(b))
("ufb_supply_ufb_supply_24" team(b) foe(a))
(define "ufb_supply_ufb_supply_25"
 {"ufb/supply/ufb_supply_25 %team"
  {condition {terms {"1.rand" {value 1}}}}
  {actions
   {"if" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {group
   {include {prop {prop human}} {state {state operatable}} {team {team %team}} {with_item {type using} {item "ufb_supply_25"}}}
   {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} {prop {prop repairing}} {prop {prop throwing}} {with_item {type amount} {item "ammo m26"} {min 24}}
    {tag {tag _ufb_surrendered}} {tag {tag _lua_mi}} {tag {tag _lua_ignore}} {tag {tag _ai_do_not_disturb}} {tag {tag repairing}} {tag {tag reloading}} {tag {tag bleeding}} {tag {tag _bleeding}} {tag {tag wounded}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag medic}} {tag {tag _ai_medic}} {tag {tag bot_medic}} {tag {tag _ufb_healing_active}} {tag {tag _ufb_autonomy_moving}} {tag {tag _ai_wounded_carrier}} {tag {tag _ai_ap_grenade}} {tag {tag _ai_at_grenade}} {tag {tag _ai_smoke_grenade}} {tag {tag _ai_suppressed_by_mg}} {tag {tag _ai_mgunner}} {tag {tag _ai_reloading}} {tag {tag _ai_looting_weapon}} {tag {tag crew}} {tag {tag tcrew}} {tag {tag ecrew}} {tag {tag ecrew_a}} {tag {tag ecrew_b}} {tag {tag bot_arty}} {tag {tag bot_aa_guard}} {tag {tag _ufb_crew_safe}} {tag {tag _ufb_hf_cover_active}} {tag {tag _ai_wirecutter_in_action}} {tag {tag bot_inf_flank_in_progress}} {tag {tag _ufb_smoke_120m_actor}} {tag {tag _ufb_smoke_60m_actor}} {tag {tag _ufb_smoke_wirecutter_actor}} {tag {tag _ai_at_launcher_30}} {tag {tag _ai_at_launcher_40}} {tag {tag _ai_at_launcher_50}} {tag {tag _ai_at_launcher_60}} {tag {tag _ai_at_launcher_70}} {tag {tag _ai_at_launcher_80}} {tag {tag _ai_at_launcher_90}} {tag {tag _ufb_rescue_active}} {tag {tag _ufb_gun_job_active}} {tag {tag _ufb_combat_busy}} {tag {tag _ufb_job_reserved}} {tag {tag _ufb_supply_cooldown}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group 
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo m26"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}} {distance {mode near_than} {meters 3}}
    {tag {"tag pair"} {"for selector" _ufb_supply_actor_%team} {"for enemy" _ufb_supply_body_%team}}}
    {"switch"
     {"case" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_25"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group {include {team {team %foe}} {state {state operatable}}} {exclude {state {state dead}} {state {state inactive}}}}} {distance {mode near_than} {meters 25}} {detection visible}}}
     {"default"
      {"inventory" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_25"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {action take_from} {item "ammo m26"} {amount 120} {entity {source advanced} {amount 1} {sort {type entity} {entity {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_25"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}}} {ignore_captured_by_user 0} {group {select {tag {tag _ufb_supply_body_%team}}}
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo m26"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}}}
      {"effect" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_25"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {effect ufb_supply_cooldown}}
     }
    }
   }
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_actor_%team}} {tag_remove _ufb_supply_actor_%team}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_body_%team}} {tag_remove _ufb_supply_body_%team}}
   {"delay" {time 4.5}}
   {"trigger" {name "ufb/supply/ufb_supply_25 %team"}}
  }
 }
)
("ufb_supply_ufb_supply_25" team(a) foe(b))
("ufb_supply_ufb_supply_25" team(b) foe(a))
(define "ufb_supply_ufb_supply_26"
 {"ufb/supply/ufb_supply_26 %team"
  {condition {terms {"1.rand" {value 1}}}}
  {actions
   {"if" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {group
   {include {prop {prop human}} {state {state operatable}} {team {team %team}} {with_item {type using} {item "ufb_supply_26"}}}
   {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} {prop {prop repairing}} {prop {prop throwing}} {with_item {type amount} {item "ammo m38_42_mag"} {min 24}}
    {tag {tag _ufb_surrendered}} {tag {tag _lua_mi}} {tag {tag _lua_ignore}} {tag {tag _ai_do_not_disturb}} {tag {tag repairing}} {tag {tag reloading}} {tag {tag bleeding}} {tag {tag _bleeding}} {tag {tag wounded}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag medic}} {tag {tag _ai_medic}} {tag {tag bot_medic}} {tag {tag _ufb_healing_active}} {tag {tag _ufb_autonomy_moving}} {tag {tag _ai_wounded_carrier}} {tag {tag _ai_ap_grenade}} {tag {tag _ai_at_grenade}} {tag {tag _ai_smoke_grenade}} {tag {tag _ai_suppressed_by_mg}} {tag {tag _ai_mgunner}} {tag {tag _ai_reloading}} {tag {tag _ai_looting_weapon}} {tag {tag crew}} {tag {tag tcrew}} {tag {tag ecrew}} {tag {tag ecrew_a}} {tag {tag ecrew_b}} {tag {tag bot_arty}} {tag {tag bot_aa_guard}} {tag {tag _ufb_crew_safe}} {tag {tag _ufb_hf_cover_active}} {tag {tag _ai_wirecutter_in_action}} {tag {tag bot_inf_flank_in_progress}} {tag {tag _ufb_smoke_120m_actor}} {tag {tag _ufb_smoke_60m_actor}} {tag {tag _ufb_smoke_wirecutter_actor}} {tag {tag _ai_at_launcher_30}} {tag {tag _ai_at_launcher_40}} {tag {tag _ai_at_launcher_50}} {tag {tag _ai_at_launcher_60}} {tag {tag _ai_at_launcher_70}} {tag {tag _ai_at_launcher_80}} {tag {tag _ai_at_launcher_90}} {tag {tag _ufb_rescue_active}} {tag {tag _ufb_gun_job_active}} {tag {tag _ufb_combat_busy}} {tag {tag _ufb_job_reserved}} {tag {tag _ufb_supply_cooldown}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group 
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo m38_42_mag"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}} {distance {mode near_than} {meters 3}}
    {tag {"tag pair"} {"for selector" _ufb_supply_actor_%team} {"for enemy" _ufb_supply_body_%team}}}
    {"switch"
     {"case" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_26"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group {include {team {team %foe}} {state {state operatable}}} {exclude {state {state dead}} {state {state inactive}}}}} {distance {mode near_than} {meters 25}} {detection visible}}}
     {"default"
      {"inventory" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_26"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {action take_from} {item "ammo m38_42_mag"} {amount 120} {entity {source advanced} {amount 1} {sort {type entity} {entity {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_26"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}}} {ignore_captured_by_user 0} {group {select {tag {tag _ufb_supply_body_%team}}}
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo m38_42_mag"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}}}
      {"effect" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_26"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {effect ufb_supply_cooldown}}
     }
    }
   }
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_actor_%team}} {tag_remove _ufb_supply_actor_%team}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_body_%team}} {tag_remove _ufb_supply_body_%team}}
   {"delay" {time 4.6}}
   {"trigger" {name "ufb/supply/ufb_supply_26 %team"}}
  }
 }
)
("ufb_supply_ufb_supply_26" team(a) foe(b))
("ufb_supply_ufb_supply_26" team(b) foe(a))
(define "ufb_supply_ufb_supply_27"
 {"ufb/supply/ufb_supply_27 %team"
  {condition {terms {"1.rand" {value 1}}}}
  {actions
   {"if" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {group
   {include {prop {prop human}} {state {state operatable}} {team {team %team}} {with_item {type using} {item "ufb_supply_27"}}}
   {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} {prop {prop repairing}} {prop {prop throwing}} {with_item {type amount} {item "ammo m3_grease_mag"} {min 24}}
    {tag {tag _ufb_surrendered}} {tag {tag _lua_mi}} {tag {tag _lua_ignore}} {tag {tag _ai_do_not_disturb}} {tag {tag repairing}} {tag {tag reloading}} {tag {tag bleeding}} {tag {tag _bleeding}} {tag {tag wounded}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag medic}} {tag {tag _ai_medic}} {tag {tag bot_medic}} {tag {tag _ufb_healing_active}} {tag {tag _ufb_autonomy_moving}} {tag {tag _ai_wounded_carrier}} {tag {tag _ai_ap_grenade}} {tag {tag _ai_at_grenade}} {tag {tag _ai_smoke_grenade}} {tag {tag _ai_suppressed_by_mg}} {tag {tag _ai_mgunner}} {tag {tag _ai_reloading}} {tag {tag _ai_looting_weapon}} {tag {tag crew}} {tag {tag tcrew}} {tag {tag ecrew}} {tag {tag ecrew_a}} {tag {tag ecrew_b}} {tag {tag bot_arty}} {tag {tag bot_aa_guard}} {tag {tag _ufb_crew_safe}} {tag {tag _ufb_hf_cover_active}} {tag {tag _ai_wirecutter_in_action}} {tag {tag bot_inf_flank_in_progress}} {tag {tag _ufb_smoke_120m_actor}} {tag {tag _ufb_smoke_60m_actor}} {tag {tag _ufb_smoke_wirecutter_actor}} {tag {tag _ai_at_launcher_30}} {tag {tag _ai_at_launcher_40}} {tag {tag _ai_at_launcher_50}} {tag {tag _ai_at_launcher_60}} {tag {tag _ai_at_launcher_70}} {tag {tag _ai_at_launcher_80}} {tag {tag _ai_at_launcher_90}} {tag {tag _ufb_rescue_active}} {tag {tag _ufb_gun_job_active}} {tag {tag _ufb_combat_busy}} {tag {tag _ufb_job_reserved}} {tag {tag _ufb_supply_cooldown}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group 
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo m3_grease_mag"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}} {distance {mode near_than} {meters 3}}
    {tag {"tag pair"} {"for selector" _ufb_supply_actor_%team} {"for enemy" _ufb_supply_body_%team}}}
    {"switch"
     {"case" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_27"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group {include {team {team %foe}} {state {state operatable}}} {exclude {state {state dead}} {state {state inactive}}}}} {distance {mode near_than} {meters 25}} {detection visible}}}
     {"default"
      {"inventory" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_27"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {action take_from} {item "ammo m3_grease_mag"} {amount 120} {entity {source advanced} {amount 1} {sort {type entity} {entity {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_27"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}}} {ignore_captured_by_user 0} {group {select {tag {tag _ufb_supply_body_%team}}}
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo m3_grease_mag"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}}}
      {"effect" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_27"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {effect ufb_supply_cooldown}}
     }
    }
   }
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_actor_%team}} {tag_remove _ufb_supply_actor_%team}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_body_%team}} {tag_remove _ufb_supply_body_%team}}
   {"delay" {time 4.7}}
   {"trigger" {name "ufb/supply/ufb_supply_27 %team"}}
  }
 }
)
("ufb_supply_ufb_supply_27" team(a) foe(b))
("ufb_supply_ufb_supply_27" team(b) foe(a))
(define "ufb_supply_ufb_supply_28"
 {"ufb/supply/ufb_supply_28 %team"
  {condition {terms {"1.rand" {value 1}}}}
  {actions
   {"if" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {group
   {include {prop {prop human}} {state {state operatable}} {team {team %team}} {with_item {type using} {item "ufb_supply_28"}}}
   {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} {prop {prop repairing}} {prop {prop throwing}} {with_item {type amount} {item "ammo madsen"} {min 24}}
    {tag {tag _ufb_surrendered}} {tag {tag _lua_mi}} {tag {tag _lua_ignore}} {tag {tag _ai_do_not_disturb}} {tag {tag repairing}} {tag {tag reloading}} {tag {tag bleeding}} {tag {tag _bleeding}} {tag {tag wounded}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag medic}} {tag {tag _ai_medic}} {tag {tag bot_medic}} {tag {tag _ufb_healing_active}} {tag {tag _ufb_autonomy_moving}} {tag {tag _ai_wounded_carrier}} {tag {tag _ai_ap_grenade}} {tag {tag _ai_at_grenade}} {tag {tag _ai_smoke_grenade}} {tag {tag _ai_suppressed_by_mg}} {tag {tag _ai_mgunner}} {tag {tag _ai_reloading}} {tag {tag _ai_looting_weapon}} {tag {tag crew}} {tag {tag tcrew}} {tag {tag ecrew}} {tag {tag ecrew_a}} {tag {tag ecrew_b}} {tag {tag bot_arty}} {tag {tag bot_aa_guard}} {tag {tag _ufb_crew_safe}} {tag {tag _ufb_hf_cover_active}} {tag {tag _ai_wirecutter_in_action}} {tag {tag bot_inf_flank_in_progress}} {tag {tag _ufb_smoke_120m_actor}} {tag {tag _ufb_smoke_60m_actor}} {tag {tag _ufb_smoke_wirecutter_actor}} {tag {tag _ai_at_launcher_30}} {tag {tag _ai_at_launcher_40}} {tag {tag _ai_at_launcher_50}} {tag {tag _ai_at_launcher_60}} {tag {tag _ai_at_launcher_70}} {tag {tag _ai_at_launcher_80}} {tag {tag _ai_at_launcher_90}} {tag {tag _ufb_rescue_active}} {tag {tag _ufb_gun_job_active}} {tag {tag _ufb_combat_busy}} {tag {tag _ufb_job_reserved}} {tag {tag _ufb_supply_cooldown}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group 
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo madsen"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}} {distance {mode near_than} {meters 3}}
    {tag {"tag pair"} {"for selector" _ufb_supply_actor_%team} {"for enemy" _ufb_supply_body_%team}}}
    {"switch"
     {"case" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_28"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group {include {team {team %foe}} {state {state operatable}}} {exclude {state {state dead}} {state {state inactive}}}}} {distance {mode near_than} {meters 25}} {detection visible}}}
     {"default"
      {"inventory" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_28"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {action take_from} {item "ammo madsen"} {amount 120} {entity {source advanced} {amount 1} {sort {type entity} {entity {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_28"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}}} {ignore_captured_by_user 0} {group {select {tag {tag _ufb_supply_body_%team}}}
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo madsen"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}}}
      {"effect" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_28"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {effect ufb_supply_cooldown}}
     }
    }
   }
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_actor_%team}} {tag_remove _ufb_supply_actor_%team}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_body_%team}} {tag_remove _ufb_supply_body_%team}}
   {"delay" {time 4.8}}
   {"trigger" {name "ufb/supply/ufb_supply_28 %team"}}
  }
 }
)
("ufb_supply_ufb_supply_28" team(a) foe(b))
("ufb_supply_ufb_supply_28" team(b) foe(a))
(define "ufb_supply_ufb_supply_29"
 {"ufb/supply/ufb_supply_29 %team"
  {condition {terms {"1.rand" {value 1}}}}
  {actions
   {"if" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {group
   {include {prop {prop human}} {state {state operatable}} {team {team %team}} {with_item {type using} {item "ufb_supply_29"}}}
   {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} {prop {prop repairing}} {prop {prop throwing}} {with_item {type amount} {item "ammo mas38"} {min 24}}
    {tag {tag _ufb_surrendered}} {tag {tag _lua_mi}} {tag {tag _lua_ignore}} {tag {tag _ai_do_not_disturb}} {tag {tag repairing}} {tag {tag reloading}} {tag {tag bleeding}} {tag {tag _bleeding}} {tag {tag wounded}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag medic}} {tag {tag _ai_medic}} {tag {tag bot_medic}} {tag {tag _ufb_healing_active}} {tag {tag _ufb_autonomy_moving}} {tag {tag _ai_wounded_carrier}} {tag {tag _ai_ap_grenade}} {tag {tag _ai_at_grenade}} {tag {tag _ai_smoke_grenade}} {tag {tag _ai_suppressed_by_mg}} {tag {tag _ai_mgunner}} {tag {tag _ai_reloading}} {tag {tag _ai_looting_weapon}} {tag {tag crew}} {tag {tag tcrew}} {tag {tag ecrew}} {tag {tag ecrew_a}} {tag {tag ecrew_b}} {tag {tag bot_arty}} {tag {tag bot_aa_guard}} {tag {tag _ufb_crew_safe}} {tag {tag _ufb_hf_cover_active}} {tag {tag _ai_wirecutter_in_action}} {tag {tag bot_inf_flank_in_progress}} {tag {tag _ufb_smoke_120m_actor}} {tag {tag _ufb_smoke_60m_actor}} {tag {tag _ufb_smoke_wirecutter_actor}} {tag {tag _ai_at_launcher_30}} {tag {tag _ai_at_launcher_40}} {tag {tag _ai_at_launcher_50}} {tag {tag _ai_at_launcher_60}} {tag {tag _ai_at_launcher_70}} {tag {tag _ai_at_launcher_80}} {tag {tag _ai_at_launcher_90}} {tag {tag _ufb_rescue_active}} {tag {tag _ufb_gun_job_active}} {tag {tag _ufb_combat_busy}} {tag {tag _ufb_job_reserved}} {tag {tag _ufb_supply_cooldown}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group 
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo mas38"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}} {distance {mode near_than} {meters 3}}
    {tag {"tag pair"} {"for selector" _ufb_supply_actor_%team} {"for enemy" _ufb_supply_body_%team}}}
    {"switch"
     {"case" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_29"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group {include {team {team %foe}} {state {state operatable}}} {exclude {state {state dead}} {state {state inactive}}}}} {distance {mode near_than} {meters 25}} {detection visible}}}
     {"default"
      {"inventory" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_29"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {action take_from} {item "ammo mas38"} {amount 120} {entity {source advanced} {amount 1} {sort {type entity} {entity {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_29"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}}} {ignore_captured_by_user 0} {group {select {tag {tag _ufb_supply_body_%team}}}
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo mas38"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}}}
      {"effect" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_29"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {effect ufb_supply_cooldown}}
     }
    }
   }
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_actor_%team}} {tag_remove _ufb_supply_actor_%team}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_body_%team}} {tag_remove _ufb_supply_body_%team}}
   {"delay" {time 4.9}}
   {"trigger" {name "ufb/supply/ufb_supply_29 %team"}}
  }
 }
)
("ufb_supply_ufb_supply_29" team(a) foe(b))
("ufb_supply_ufb_supply_29" team(b) foe(a))
(define "ufb_supply_ufb_supply_30"
 {"ufb/supply/ufb_supply_30 %team"
  {condition {terms {"1.rand" {value 1}}}}
  {actions
   {"if" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {group
   {include {prop {prop human}} {state {state operatable}} {team {team %team}} {with_item {type using} {item "ufb_supply_30"}}}
   {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} {prop {prop repairing}} {prop {prop throwing}} {with_item {type amount} {item "ammo mp40"} {min 24}}
    {tag {tag _ufb_surrendered}} {tag {tag _lua_mi}} {tag {tag _lua_ignore}} {tag {tag _ai_do_not_disturb}} {tag {tag repairing}} {tag {tag reloading}} {tag {tag bleeding}} {tag {tag _bleeding}} {tag {tag wounded}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag medic}} {tag {tag _ai_medic}} {tag {tag bot_medic}} {tag {tag _ufb_healing_active}} {tag {tag _ufb_autonomy_moving}} {tag {tag _ai_wounded_carrier}} {tag {tag _ai_ap_grenade}} {tag {tag _ai_at_grenade}} {tag {tag _ai_smoke_grenade}} {tag {tag _ai_suppressed_by_mg}} {tag {tag _ai_mgunner}} {tag {tag _ai_reloading}} {tag {tag _ai_looting_weapon}} {tag {tag crew}} {tag {tag tcrew}} {tag {tag ecrew}} {tag {tag ecrew_a}} {tag {tag ecrew_b}} {tag {tag bot_arty}} {tag {tag bot_aa_guard}} {tag {tag _ufb_crew_safe}} {tag {tag _ufb_hf_cover_active}} {tag {tag _ai_wirecutter_in_action}} {tag {tag bot_inf_flank_in_progress}} {tag {tag _ufb_smoke_120m_actor}} {tag {tag _ufb_smoke_60m_actor}} {tag {tag _ufb_smoke_wirecutter_actor}} {tag {tag _ai_at_launcher_30}} {tag {tag _ai_at_launcher_40}} {tag {tag _ai_at_launcher_50}} {tag {tag _ai_at_launcher_60}} {tag {tag _ai_at_launcher_70}} {tag {tag _ai_at_launcher_80}} {tag {tag _ai_at_launcher_90}} {tag {tag _ufb_rescue_active}} {tag {tag _ufb_gun_job_active}} {tag {tag _ufb_combat_busy}} {tag {tag _ufb_job_reserved}} {tag {tag _ufb_supply_cooldown}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group 
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo mp40"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}} {distance {mode near_than} {meters 3}}
    {tag {"tag pair"} {"for selector" _ufb_supply_actor_%team} {"for enemy" _ufb_supply_body_%team}}}
    {"switch"
     {"case" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_30"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group {include {team {team %foe}} {state {state operatable}}} {exclude {state {state dead}} {state {state inactive}}}}} {distance {mode near_than} {meters 25}} {detection visible}}}
     {"default"
      {"inventory" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_30"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {action take_from} {item "ammo mp40"} {amount 120} {entity {source advanced} {amount 1} {sort {type entity} {entity {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_30"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}}} {ignore_captured_by_user 0} {group {select {tag {tag _ufb_supply_body_%team}}}
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo mp40"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}}}
      {"effect" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_30"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {effect ufb_supply_cooldown}}
     }
    }
   }
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_actor_%team}} {tag_remove _ufb_supply_actor_%team}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_body_%team}} {tag_remove _ufb_supply_body_%team}}
   {"delay" {time 5.0}}
   {"trigger" {name "ufb/supply/ufb_supply_30 %team"}}
  }
 }
)
("ufb_supply_ufb_supply_30" team(a) foe(b))
("ufb_supply_ufb_supply_30" team(b) foe(a))
(define "ufb_supply_ufb_supply_31"
 {"ufb/supply/ufb_supply_31 %team"
  {condition {terms {"1.rand" {value 1}}}}
  {actions
   {"if" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {group
   {include {prop {prop human}} {state {state operatable}} {team {team %team}} {with_item {type using} {item "ufb_supply_31"}}}
   {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} {prop {prop repairing}} {prop {prop throwing}} {with_item {type amount} {item "ammo pistol"} {min 24}}
    {tag {tag _ufb_surrendered}} {tag {tag _lua_mi}} {tag {tag _lua_ignore}} {tag {tag _ai_do_not_disturb}} {tag {tag repairing}} {tag {tag reloading}} {tag {tag bleeding}} {tag {tag _bleeding}} {tag {tag wounded}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag medic}} {tag {tag _ai_medic}} {tag {tag bot_medic}} {tag {tag _ufb_healing_active}} {tag {tag _ufb_autonomy_moving}} {tag {tag _ai_wounded_carrier}} {tag {tag _ai_ap_grenade}} {tag {tag _ai_at_grenade}} {tag {tag _ai_smoke_grenade}} {tag {tag _ai_suppressed_by_mg}} {tag {tag _ai_mgunner}} {tag {tag _ai_reloading}} {tag {tag _ai_looting_weapon}} {tag {tag crew}} {tag {tag tcrew}} {tag {tag ecrew}} {tag {tag ecrew_a}} {tag {tag ecrew_b}} {tag {tag bot_arty}} {tag {tag bot_aa_guard}} {tag {tag _ufb_crew_safe}} {tag {tag _ufb_hf_cover_active}} {tag {tag _ai_wirecutter_in_action}} {tag {tag bot_inf_flank_in_progress}} {tag {tag _ufb_smoke_120m_actor}} {tag {tag _ufb_smoke_60m_actor}} {tag {tag _ufb_smoke_wirecutter_actor}} {tag {tag _ai_at_launcher_30}} {tag {tag _ai_at_launcher_40}} {tag {tag _ai_at_launcher_50}} {tag {tag _ai_at_launcher_60}} {tag {tag _ai_at_launcher_70}} {tag {tag _ai_at_launcher_80}} {tag {tag _ai_at_launcher_90}} {tag {tag _ufb_rescue_active}} {tag {tag _ufb_gun_job_active}} {tag {tag _ufb_combat_busy}} {tag {tag _ufb_job_reserved}} {tag {tag _ufb_supply_cooldown}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group 
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo pistol"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}} {distance {mode near_than} {meters 3}}
    {tag {"tag pair"} {"for selector" _ufb_supply_actor_%team} {"for enemy" _ufb_supply_body_%team}}}
    {"switch"
     {"case" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_31"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group {include {team {team %foe}} {state {state operatable}}} {exclude {state {state dead}} {state {state inactive}}}}} {distance {mode near_than} {meters 25}} {detection visible}}}
     {"default"
      {"inventory" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_31"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {action take_from} {item "ammo pistol"} {amount 120} {entity {source advanced} {amount 1} {sort {type entity} {entity {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_31"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}}} {ignore_captured_by_user 0} {group {select {tag {tag _ufb_supply_body_%team}}}
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo pistol"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}}}
      {"effect" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_31"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {effect ufb_supply_cooldown}}
     }
    }
   }
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_actor_%team}} {tag_remove _ufb_supply_actor_%team}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_body_%team}} {tag_remove _ufb_supply_body_%team}}
   {"delay" {time 5.1}}
   {"trigger" {name "ufb/supply/ufb_supply_31 %team"}}
  }
 }
)
("ufb_supply_ufb_supply_31" team(a) foe(b))
("ufb_supply_ufb_supply_31" team(b) foe(a))
(define "ufb_supply_ufb_supply_32"
 {"ufb/supply/ufb_supply_32 %team"
  {condition {terms {"1.rand" {value 1}}}}
  {actions
   {"if" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {group
   {include {prop {prop human}} {state {state operatable}} {team {team %team}} {with_item {type using} {item "ufb_supply_32"}}}
   {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} {prop {prop repairing}} {prop {prop throwing}} {with_item {type amount} {item "ammo ppd34_stick"} {min 24}}
    {tag {tag _ufb_surrendered}} {tag {tag _lua_mi}} {tag {tag _lua_ignore}} {tag {tag _ai_do_not_disturb}} {tag {tag repairing}} {tag {tag reloading}} {tag {tag bleeding}} {tag {tag _bleeding}} {tag {tag wounded}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag medic}} {tag {tag _ai_medic}} {tag {tag bot_medic}} {tag {tag _ufb_healing_active}} {tag {tag _ufb_autonomy_moving}} {tag {tag _ai_wounded_carrier}} {tag {tag _ai_ap_grenade}} {tag {tag _ai_at_grenade}} {tag {tag _ai_smoke_grenade}} {tag {tag _ai_suppressed_by_mg}} {tag {tag _ai_mgunner}} {tag {tag _ai_reloading}} {tag {tag _ai_looting_weapon}} {tag {tag crew}} {tag {tag tcrew}} {tag {tag ecrew}} {tag {tag ecrew_a}} {tag {tag ecrew_b}} {tag {tag bot_arty}} {tag {tag bot_aa_guard}} {tag {tag _ufb_crew_safe}} {tag {tag _ufb_hf_cover_active}} {tag {tag _ai_wirecutter_in_action}} {tag {tag bot_inf_flank_in_progress}} {tag {tag _ufb_smoke_120m_actor}} {tag {tag _ufb_smoke_60m_actor}} {tag {tag _ufb_smoke_wirecutter_actor}} {tag {tag _ai_at_launcher_30}} {tag {tag _ai_at_launcher_40}} {tag {tag _ai_at_launcher_50}} {tag {tag _ai_at_launcher_60}} {tag {tag _ai_at_launcher_70}} {tag {tag _ai_at_launcher_80}} {tag {tag _ai_at_launcher_90}} {tag {tag _ufb_rescue_active}} {tag {tag _ufb_gun_job_active}} {tag {tag _ufb_combat_busy}} {tag {tag _ufb_job_reserved}} {tag {tag _ufb_supply_cooldown}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group 
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo ppd34_stick"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}} {distance {mode near_than} {meters 3}}
    {tag {"tag pair"} {"for selector" _ufb_supply_actor_%team} {"for enemy" _ufb_supply_body_%team}}}
    {"switch"
     {"case" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_32"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group {include {team {team %foe}} {state {state operatable}}} {exclude {state {state dead}} {state {state inactive}}}}} {distance {mode near_than} {meters 25}} {detection visible}}}
     {"default"
      {"inventory" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_32"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {action take_from} {item "ammo ppd34_stick"} {amount 120} {entity {source advanced} {amount 1} {sort {type entity} {entity {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_32"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}}} {ignore_captured_by_user 0} {group {select {tag {tag _ufb_supply_body_%team}}}
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo ppd34_stick"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}}}
      {"effect" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_32"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {effect ufb_supply_cooldown}}
     }
    }
   }
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_actor_%team}} {tag_remove _ufb_supply_actor_%team}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_body_%team}} {tag_remove _ufb_supply_body_%team}}
   {"delay" {time 5.2}}
   {"trigger" {name "ufb/supply/ufb_supply_32 %team"}}
  }
 }
)
("ufb_supply_ufb_supply_32" team(a) foe(b))
("ufb_supply_ufb_supply_32" team(b) foe(a))
(define "ufb_supply_ufb_supply_33"
 {"ufb/supply/ufb_supply_33 %team"
  {condition {terms {"1.rand" {value 1}}}}
  {actions
   {"if" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {group
   {include {prop {prop human}} {state {state operatable}} {team {team %team}} {with_item {type using} {item "ufb_supply_33"}}}
   {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} {prop {prop repairing}} {prop {prop throwing}} {with_item {type amount} {item "ammo ppd38_drum"} {min 24}}
    {tag {tag _ufb_surrendered}} {tag {tag _lua_mi}} {tag {tag _lua_ignore}} {tag {tag _ai_do_not_disturb}} {tag {tag repairing}} {tag {tag reloading}} {tag {tag bleeding}} {tag {tag _bleeding}} {tag {tag wounded}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag medic}} {tag {tag _ai_medic}} {tag {tag bot_medic}} {tag {tag _ufb_healing_active}} {tag {tag _ufb_autonomy_moving}} {tag {tag _ai_wounded_carrier}} {tag {tag _ai_ap_grenade}} {tag {tag _ai_at_grenade}} {tag {tag _ai_smoke_grenade}} {tag {tag _ai_suppressed_by_mg}} {tag {tag _ai_mgunner}} {tag {tag _ai_reloading}} {tag {tag _ai_looting_weapon}} {tag {tag crew}} {tag {tag tcrew}} {tag {tag ecrew}} {tag {tag ecrew_a}} {tag {tag ecrew_b}} {tag {tag bot_arty}} {tag {tag bot_aa_guard}} {tag {tag _ufb_crew_safe}} {tag {tag _ufb_hf_cover_active}} {tag {tag _ai_wirecutter_in_action}} {tag {tag bot_inf_flank_in_progress}} {tag {tag _ufb_smoke_120m_actor}} {tag {tag _ufb_smoke_60m_actor}} {tag {tag _ufb_smoke_wirecutter_actor}} {tag {tag _ai_at_launcher_30}} {tag {tag _ai_at_launcher_40}} {tag {tag _ai_at_launcher_50}} {tag {tag _ai_at_launcher_60}} {tag {tag _ai_at_launcher_70}} {tag {tag _ai_at_launcher_80}} {tag {tag _ai_at_launcher_90}} {tag {tag _ufb_rescue_active}} {tag {tag _ufb_gun_job_active}} {tag {tag _ufb_combat_busy}} {tag {tag _ufb_job_reserved}} {tag {tag _ufb_supply_cooldown}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group 
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo ppd38_drum"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}} {distance {mode near_than} {meters 3}}
    {tag {"tag pair"} {"for selector" _ufb_supply_actor_%team} {"for enemy" _ufb_supply_body_%team}}}
    {"switch"
     {"case" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_33"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group {include {team {team %foe}} {state {state operatable}}} {exclude {state {state dead}} {state {state inactive}}}}} {distance {mode near_than} {meters 25}} {detection visible}}}
     {"default"
      {"inventory" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_33"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {action take_from} {item "ammo ppd38_drum"} {amount 120} {entity {source advanced} {amount 1} {sort {type entity} {entity {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_33"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}}} {ignore_captured_by_user 0} {group {select {tag {tag _ufb_supply_body_%team}}}
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo ppd38_drum"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}}}
      {"effect" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_33"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {effect ufb_supply_cooldown}}
     }
    }
   }
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_actor_%team}} {tag_remove _ufb_supply_actor_%team}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_body_%team}} {tag_remove _ufb_supply_body_%team}}
   {"delay" {time 5.3}}
   {"trigger" {name "ufb/supply/ufb_supply_33 %team"}}
  }
 }
)
("ufb_supply_ufb_supply_33" team(a) foe(b))
("ufb_supply_ufb_supply_33" team(b) foe(a))
(define "ufb_supply_ufb_supply_34"
 {"ufb/supply/ufb_supply_34 %team"
  {condition {terms {"1.rand" {value 1}}}}
  {actions
   {"if" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {group
   {include {prop {prop human}} {state {state operatable}} {team {team %team}} {with_item {type using} {item "ufb_supply_34"}}}
   {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} {prop {prop repairing}} {prop {prop throwing}} {with_item {type amount} {item "ammo ppd40_drum"} {min 24}}
    {tag {tag _ufb_surrendered}} {tag {tag _lua_mi}} {tag {tag _lua_ignore}} {tag {tag _ai_do_not_disturb}} {tag {tag repairing}} {tag {tag reloading}} {tag {tag bleeding}} {tag {tag _bleeding}} {tag {tag wounded}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag medic}} {tag {tag _ai_medic}} {tag {tag bot_medic}} {tag {tag _ufb_healing_active}} {tag {tag _ufb_autonomy_moving}} {tag {tag _ai_wounded_carrier}} {tag {tag _ai_ap_grenade}} {tag {tag _ai_at_grenade}} {tag {tag _ai_smoke_grenade}} {tag {tag _ai_suppressed_by_mg}} {tag {tag _ai_mgunner}} {tag {tag _ai_reloading}} {tag {tag _ai_looting_weapon}} {tag {tag crew}} {tag {tag tcrew}} {tag {tag ecrew}} {tag {tag ecrew_a}} {tag {tag ecrew_b}} {tag {tag bot_arty}} {tag {tag bot_aa_guard}} {tag {tag _ufb_crew_safe}} {tag {tag _ufb_hf_cover_active}} {tag {tag _ai_wirecutter_in_action}} {tag {tag bot_inf_flank_in_progress}} {tag {tag _ufb_smoke_120m_actor}} {tag {tag _ufb_smoke_60m_actor}} {tag {tag _ufb_smoke_wirecutter_actor}} {tag {tag _ai_at_launcher_30}} {tag {tag _ai_at_launcher_40}} {tag {tag _ai_at_launcher_50}} {tag {tag _ai_at_launcher_60}} {tag {tag _ai_at_launcher_70}} {tag {tag _ai_at_launcher_80}} {tag {tag _ai_at_launcher_90}} {tag {tag _ufb_rescue_active}} {tag {tag _ufb_gun_job_active}} {tag {tag _ufb_combat_busy}} {tag {tag _ufb_job_reserved}} {tag {tag _ufb_supply_cooldown}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group 
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo ppd40_drum"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}} {distance {mode near_than} {meters 3}}
    {tag {"tag pair"} {"for selector" _ufb_supply_actor_%team} {"for enemy" _ufb_supply_body_%team}}}
    {"switch"
     {"case" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_34"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group {include {team {team %foe}} {state {state operatable}}} {exclude {state {state dead}} {state {state inactive}}}}} {distance {mode near_than} {meters 25}} {detection visible}}}
     {"default"
      {"inventory" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_34"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {action take_from} {item "ammo ppd40_drum"} {amount 120} {entity {source advanced} {amount 1} {sort {type entity} {entity {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_34"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}}} {ignore_captured_by_user 0} {group {select {tag {tag _ufb_supply_body_%team}}}
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo ppd40_drum"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}}}
      {"effect" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_34"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {effect ufb_supply_cooldown}}
     }
    }
   }
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_actor_%team}} {tag_remove _ufb_supply_actor_%team}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_body_%team}} {tag_remove _ufb_supply_body_%team}}
   {"delay" {time 5.4}}
   {"trigger" {name "ufb/supply/ufb_supply_34 %team"}}
  }
 }
)
("ufb_supply_ufb_supply_34" team(a) foe(b))
("ufb_supply_ufb_supply_34" team(b) foe(a))
(define "ufb_supply_ufb_supply_35"
 {"ufb/supply/ufb_supply_35 %team"
  {condition {terms {"1.rand" {value 1}}}}
  {actions
   {"if" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {group
   {include {prop {prop human}} {state {state operatable}} {team {team %team}} {with_item {type using} {item "ufb_supply_35"}}}
   {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} {prop {prop repairing}} {prop {prop throwing}} {with_item {type amount} {item "ammo pps_stick"} {min 24}}
    {tag {tag _ufb_surrendered}} {tag {tag _lua_mi}} {tag {tag _lua_ignore}} {tag {tag _ai_do_not_disturb}} {tag {tag repairing}} {tag {tag reloading}} {tag {tag bleeding}} {tag {tag _bleeding}} {tag {tag wounded}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag medic}} {tag {tag _ai_medic}} {tag {tag bot_medic}} {tag {tag _ufb_healing_active}} {tag {tag _ufb_autonomy_moving}} {tag {tag _ai_wounded_carrier}} {tag {tag _ai_ap_grenade}} {tag {tag _ai_at_grenade}} {tag {tag _ai_smoke_grenade}} {tag {tag _ai_suppressed_by_mg}} {tag {tag _ai_mgunner}} {tag {tag _ai_reloading}} {tag {tag _ai_looting_weapon}} {tag {tag crew}} {tag {tag tcrew}} {tag {tag ecrew}} {tag {tag ecrew_a}} {tag {tag ecrew_b}} {tag {tag bot_arty}} {tag {tag bot_aa_guard}} {tag {tag _ufb_crew_safe}} {tag {tag _ufb_hf_cover_active}} {tag {tag _ai_wirecutter_in_action}} {tag {tag bot_inf_flank_in_progress}} {tag {tag _ufb_smoke_120m_actor}} {tag {tag _ufb_smoke_60m_actor}} {tag {tag _ufb_smoke_wirecutter_actor}} {tag {tag _ai_at_launcher_30}} {tag {tag _ai_at_launcher_40}} {tag {tag _ai_at_launcher_50}} {tag {tag _ai_at_launcher_60}} {tag {tag _ai_at_launcher_70}} {tag {tag _ai_at_launcher_80}} {tag {tag _ai_at_launcher_90}} {tag {tag _ufb_rescue_active}} {tag {tag _ufb_gun_job_active}} {tag {tag _ufb_combat_busy}} {tag {tag _ufb_job_reserved}} {tag {tag _ufb_supply_cooldown}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group 
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo pps_stick"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}} {distance {mode near_than} {meters 3}}
    {tag {"tag pair"} {"for selector" _ufb_supply_actor_%team} {"for enemy" _ufb_supply_body_%team}}}
    {"switch"
     {"case" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_35"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group {include {team {team %foe}} {state {state operatable}}} {exclude {state {state dead}} {state {state inactive}}}}} {distance {mode near_than} {meters 25}} {detection visible}}}
     {"default"
      {"inventory" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_35"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {action take_from} {item "ammo pps_stick"} {amount 120} {entity {source advanced} {amount 1} {sort {type entity} {entity {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_35"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}}} {ignore_captured_by_user 0} {group {select {tag {tag _ufb_supply_body_%team}}}
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo pps_stick"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}}}
      {"effect" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_35"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {effect ufb_supply_cooldown}}
     }
    }
   }
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_actor_%team}} {tag_remove _ufb_supply_actor_%team}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_body_%team}} {tag_remove _ufb_supply_body_%team}}
   {"delay" {time 5.5}}
   {"trigger" {name "ufb/supply/ufb_supply_35 %team"}}
  }
 }
)
("ufb_supply_ufb_supply_35" team(a) foe(b))
("ufb_supply_ufb_supply_35" team(b) foe(a))
(define "ufb_supply_ufb_supply_36"
 {"ufb/supply/ufb_supply_36 %team"
  {condition {terms {"1.rand" {value 1}}}}
  {actions
   {"if" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {group
   {include {prop {prop human}} {state {state operatable}} {team {team %team}} {with_item {type using} {item "ufb_supply_36"}}}
   {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} {prop {prop repairing}} {prop {prop throwing}} {with_item {type amount} {item "ammo ppsh_drum"} {min 24}}
    {tag {tag _ufb_surrendered}} {tag {tag _lua_mi}} {tag {tag _lua_ignore}} {tag {tag _ai_do_not_disturb}} {tag {tag repairing}} {tag {tag reloading}} {tag {tag bleeding}} {tag {tag _bleeding}} {tag {tag wounded}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag medic}} {tag {tag _ai_medic}} {tag {tag bot_medic}} {tag {tag _ufb_healing_active}} {tag {tag _ufb_autonomy_moving}} {tag {tag _ai_wounded_carrier}} {tag {tag _ai_ap_grenade}} {tag {tag _ai_at_grenade}} {tag {tag _ai_smoke_grenade}} {tag {tag _ai_suppressed_by_mg}} {tag {tag _ai_mgunner}} {tag {tag _ai_reloading}} {tag {tag _ai_looting_weapon}} {tag {tag crew}} {tag {tag tcrew}} {tag {tag ecrew}} {tag {tag ecrew_a}} {tag {tag ecrew_b}} {tag {tag bot_arty}} {tag {tag bot_aa_guard}} {tag {tag _ufb_crew_safe}} {tag {tag _ufb_hf_cover_active}} {tag {tag _ai_wirecutter_in_action}} {tag {tag bot_inf_flank_in_progress}} {tag {tag _ufb_smoke_120m_actor}} {tag {tag _ufb_smoke_60m_actor}} {tag {tag _ufb_smoke_wirecutter_actor}} {tag {tag _ai_at_launcher_30}} {tag {tag _ai_at_launcher_40}} {tag {tag _ai_at_launcher_50}} {tag {tag _ai_at_launcher_60}} {tag {tag _ai_at_launcher_70}} {tag {tag _ai_at_launcher_80}} {tag {tag _ai_at_launcher_90}} {tag {tag _ufb_rescue_active}} {tag {tag _ufb_gun_job_active}} {tag {tag _ufb_combat_busy}} {tag {tag _ufb_job_reserved}} {tag {tag _ufb_supply_cooldown}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group 
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo ppsh_drum"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}} {distance {mode near_than} {meters 3}}
    {tag {"tag pair"} {"for selector" _ufb_supply_actor_%team} {"for enemy" _ufb_supply_body_%team}}}
    {"switch"
     {"case" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_36"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group {include {team {team %foe}} {state {state operatable}}} {exclude {state {state dead}} {state {state inactive}}}}} {distance {mode near_than} {meters 25}} {detection visible}}}
     {"default"
      {"inventory" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_36"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {action take_from} {item "ammo ppsh_drum"} {amount 120} {entity {source advanced} {amount 1} {sort {type entity} {entity {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_36"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}}} {ignore_captured_by_user 0} {group {select {tag {tag _ufb_supply_body_%team}}}
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo ppsh_drum"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}}}
      {"effect" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_36"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {effect ufb_supply_cooldown}}
     }
    }
   }
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_actor_%team}} {tag_remove _ufb_supply_actor_%team}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_body_%team}} {tag_remove _ufb_supply_body_%team}}
   {"delay" {time 5.6}}
   {"trigger" {name "ufb/supply/ufb_supply_36 %team"}}
  }
 }
)
("ufb_supply_ufb_supply_36" team(a) foe(b))
("ufb_supply_ufb_supply_36" team(b) foe(a))
(define "ufb_supply_ufb_supply_37"
 {"ufb/supply/ufb_supply_37 %team"
  {condition {terms {"1.rand" {value 1}}}}
  {actions
   {"if" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {group
   {include {prop {prop human}} {state {state operatable}} {team {team %team}} {with_item {type using} {item "ufb_supply_37"}}}
   {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} {prop {prop repairing}} {prop {prop throwing}} {with_item {type amount} {item "ammo ppsh_stick"} {min 24}}
    {tag {tag _ufb_surrendered}} {tag {tag _lua_mi}} {tag {tag _lua_ignore}} {tag {tag _ai_do_not_disturb}} {tag {tag repairing}} {tag {tag reloading}} {tag {tag bleeding}} {tag {tag _bleeding}} {tag {tag wounded}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag medic}} {tag {tag _ai_medic}} {tag {tag bot_medic}} {tag {tag _ufb_healing_active}} {tag {tag _ufb_autonomy_moving}} {tag {tag _ai_wounded_carrier}} {tag {tag _ai_ap_grenade}} {tag {tag _ai_at_grenade}} {tag {tag _ai_smoke_grenade}} {tag {tag _ai_suppressed_by_mg}} {tag {tag _ai_mgunner}} {tag {tag _ai_reloading}} {tag {tag _ai_looting_weapon}} {tag {tag crew}} {tag {tag tcrew}} {tag {tag ecrew}} {tag {tag ecrew_a}} {tag {tag ecrew_b}} {tag {tag bot_arty}} {tag {tag bot_aa_guard}} {tag {tag _ufb_crew_safe}} {tag {tag _ufb_hf_cover_active}} {tag {tag _ai_wirecutter_in_action}} {tag {tag bot_inf_flank_in_progress}} {tag {tag _ufb_smoke_120m_actor}} {tag {tag _ufb_smoke_60m_actor}} {tag {tag _ufb_smoke_wirecutter_actor}} {tag {tag _ai_at_launcher_30}} {tag {tag _ai_at_launcher_40}} {tag {tag _ai_at_launcher_50}} {tag {tag _ai_at_launcher_60}} {tag {tag _ai_at_launcher_70}} {tag {tag _ai_at_launcher_80}} {tag {tag _ai_at_launcher_90}} {tag {tag _ufb_rescue_active}} {tag {tag _ufb_gun_job_active}} {tag {tag _ufb_combat_busy}} {tag {tag _ufb_job_reserved}} {tag {tag _ufb_supply_cooldown}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group 
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo ppsh_stick"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}} {distance {mode near_than} {meters 3}}
    {tag {"tag pair"} {"for selector" _ufb_supply_actor_%team} {"for enemy" _ufb_supply_body_%team}}}
    {"switch"
     {"case" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_37"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group {include {team {team %foe}} {state {state operatable}}} {exclude {state {state dead}} {state {state inactive}}}}} {distance {mode near_than} {meters 25}} {detection visible}}}
     {"default"
      {"inventory" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_37"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {action take_from} {item "ammo ppsh_stick"} {amount 120} {entity {source advanced} {amount 1} {sort {type entity} {entity {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_37"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}}} {ignore_captured_by_user 0} {group {select {tag {tag _ufb_supply_body_%team}}}
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo ppsh_stick"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}}}
      {"effect" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_37"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {effect ufb_supply_cooldown}}
     }
    }
   }
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_actor_%team}} {tag_remove _ufb_supply_actor_%team}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_body_%team}} {tag_remove _ufb_supply_body_%team}}
   {"delay" {time 5.7}}
   {"trigger" {name "ufb/supply/ufb_supply_37 %team"}}
  }
 }
)
("ufb_supply_ufb_supply_37" team(a) foe(b))
("ufb_supply_ufb_supply_37" team(b) foe(a))
(define "ufb_supply_ufb_supply_38"
 {"ufb/supply/ufb_supply_38 %team"
  {condition {terms {"1.rand" {value 1}}}}
  {actions
   {"if" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {group
   {include {prop {prop human}} {state {state operatable}} {team {team %team}} {with_item {type using} {item "ufb_supply_38"}}}
   {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} {prop {prop repairing}} {prop {prop throwing}} {with_item {type amount} {item "ammo revolver_clip"} {min 24}}
    {tag {tag _ufb_surrendered}} {tag {tag _lua_mi}} {tag {tag _lua_ignore}} {tag {tag _ai_do_not_disturb}} {tag {tag repairing}} {tag {tag reloading}} {tag {tag bleeding}} {tag {tag _bleeding}} {tag {tag wounded}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag medic}} {tag {tag _ai_medic}} {tag {tag bot_medic}} {tag {tag _ufb_healing_active}} {tag {tag _ufb_autonomy_moving}} {tag {tag _ai_wounded_carrier}} {tag {tag _ai_ap_grenade}} {tag {tag _ai_at_grenade}} {tag {tag _ai_smoke_grenade}} {tag {tag _ai_suppressed_by_mg}} {tag {tag _ai_mgunner}} {tag {tag _ai_reloading}} {tag {tag _ai_looting_weapon}} {tag {tag crew}} {tag {tag tcrew}} {tag {tag ecrew}} {tag {tag ecrew_a}} {tag {tag ecrew_b}} {tag {tag bot_arty}} {tag {tag bot_aa_guard}} {tag {tag _ufb_crew_safe}} {tag {tag _ufb_hf_cover_active}} {tag {tag _ai_wirecutter_in_action}} {tag {tag bot_inf_flank_in_progress}} {tag {tag _ufb_smoke_120m_actor}} {tag {tag _ufb_smoke_60m_actor}} {tag {tag _ufb_smoke_wirecutter_actor}} {tag {tag _ai_at_launcher_30}} {tag {tag _ai_at_launcher_40}} {tag {tag _ai_at_launcher_50}} {tag {tag _ai_at_launcher_60}} {tag {tag _ai_at_launcher_70}} {tag {tag _ai_at_launcher_80}} {tag {tag _ai_at_launcher_90}} {tag {tag _ufb_rescue_active}} {tag {tag _ufb_gun_job_active}} {tag {tag _ufb_combat_busy}} {tag {tag _ufb_job_reserved}} {tag {tag _ufb_supply_cooldown}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group 
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo revolver_clip"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}} {distance {mode near_than} {meters 3}}
    {tag {"tag pair"} {"for selector" _ufb_supply_actor_%team} {"for enemy" _ufb_supply_body_%team}}}
    {"switch"
     {"case" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_38"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group {include {team {team %foe}} {state {state operatable}}} {exclude {state {state dead}} {state {state inactive}}}}} {distance {mode near_than} {meters 25}} {detection visible}}}
     {"default"
      {"inventory" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_38"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {action take_from} {item "ammo revolver_clip"} {amount 120} {entity {source advanced} {amount 1} {sort {type entity} {entity {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_38"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}}} {ignore_captured_by_user 0} {group {select {tag {tag _ufb_supply_body_%team}}}
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo revolver_clip"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}}}
      {"effect" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_38"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {effect ufb_supply_cooldown}}
     }
    }
   }
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_actor_%team}} {tag_remove _ufb_supply_actor_%team}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_body_%team}} {tag_remove _ufb_supply_body_%team}}
   {"delay" {time 5.8}}
   {"trigger" {name "ufb/supply/ufb_supply_38 %team"}}
  }
 }
)
("ufb_supply_ufb_supply_38" team(a) foe(b))
("ufb_supply_ufb_supply_38" team(b) foe(a))
(define "ufb_supply_ufb_supply_39"
 {"ufb/supply/ufb_supply_39 %team"
  {condition {terms {"1.rand" {value 1}}}}
  {actions
   {"if" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {group
   {include {prop {prop human}} {state {state operatable}} {team {team %team}} {with_item {type using} {item "ufb_supply_39"}}}
   {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} {prop {prop repairing}} {prop {prop throwing}} {with_item {type amount} {item "ammo rifle_eng clip"} {min 24}}
    {tag {tag _ufb_surrendered}} {tag {tag _lua_mi}} {tag {tag _lua_ignore}} {tag {tag _ai_do_not_disturb}} {tag {tag repairing}} {tag {tag reloading}} {tag {tag bleeding}} {tag {tag _bleeding}} {tag {tag wounded}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag medic}} {tag {tag _ai_medic}} {tag {tag bot_medic}} {tag {tag _ufb_healing_active}} {tag {tag _ufb_autonomy_moving}} {tag {tag _ai_wounded_carrier}} {tag {tag _ai_ap_grenade}} {tag {tag _ai_at_grenade}} {tag {tag _ai_smoke_grenade}} {tag {tag _ai_suppressed_by_mg}} {tag {tag _ai_mgunner}} {tag {tag _ai_reloading}} {tag {tag _ai_looting_weapon}} {tag {tag crew}} {tag {tag tcrew}} {tag {tag ecrew}} {tag {tag ecrew_a}} {tag {tag ecrew_b}} {tag {tag bot_arty}} {tag {tag bot_aa_guard}} {tag {tag _ufb_crew_safe}} {tag {tag _ufb_hf_cover_active}} {tag {tag _ai_wirecutter_in_action}} {tag {tag bot_inf_flank_in_progress}} {tag {tag _ufb_smoke_120m_actor}} {tag {tag _ufb_smoke_60m_actor}} {tag {tag _ufb_smoke_wirecutter_actor}} {tag {tag _ai_at_launcher_30}} {tag {tag _ai_at_launcher_40}} {tag {tag _ai_at_launcher_50}} {tag {tag _ai_at_launcher_60}} {tag {tag _ai_at_launcher_70}} {tag {tag _ai_at_launcher_80}} {tag {tag _ai_at_launcher_90}} {tag {tag _ufb_rescue_active}} {tag {tag _ufb_gun_job_active}} {tag {tag _ufb_combat_busy}} {tag {tag _ufb_job_reserved}} {tag {tag _ufb_supply_cooldown}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group 
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo rifle_eng clip"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}} {distance {mode near_than} {meters 3}}
    {tag {"tag pair"} {"for selector" _ufb_supply_actor_%team} {"for enemy" _ufb_supply_body_%team}}}
    {"switch"
     {"case" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_39"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group {include {team {team %foe}} {state {state operatable}}} {exclude {state {state dead}} {state {state inactive}}}}} {distance {mode near_than} {meters 25}} {detection visible}}}
     {"default"
      {"inventory" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_39"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {action take_from} {item "ammo rifle_eng clip"} {amount 120} {entity {source advanced} {amount 1} {sort {type entity} {entity {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_39"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}}} {ignore_captured_by_user 0} {group {select {tag {tag _ufb_supply_body_%team}}}
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo rifle_eng clip"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}}}
      {"effect" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_39"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {effect ufb_supply_cooldown}}
     }
    }
   }
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_actor_%team}} {tag_remove _ufb_supply_actor_%team}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_body_%team}} {tag_remove _ufb_supply_body_%team}}
   {"delay" {time 5.9}}
   {"trigger" {name "ufb/supply/ufb_supply_39 %team"}}
  }
 }
)
("ufb_supply_ufb_supply_39" team(a) foe(b))
("ufb_supply_ufb_supply_39" team(b) foe(a))
(define "ufb_supply_ufb_supply_40"
 {"ufb/supply/ufb_supply_40 %team"
  {condition {terms {"1.rand" {value 1}}}}
  {actions
   {"if" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {group
   {include {prop {prop human}} {state {state operatable}} {team {team %team}} {with_item {type using} {item "ufb_supply_40"}}}
   {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} {prop {prop repairing}} {prop {prop throwing}} {with_item {type amount} {item "ammo rifle_fra clip"} {min 24}}
    {tag {tag _ufb_surrendered}} {tag {tag _lua_mi}} {tag {tag _lua_ignore}} {tag {tag _ai_do_not_disturb}} {tag {tag repairing}} {tag {tag reloading}} {tag {tag bleeding}} {tag {tag _bleeding}} {tag {tag wounded}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag medic}} {tag {tag _ai_medic}} {tag {tag bot_medic}} {tag {tag _ufb_healing_active}} {tag {tag _ufb_autonomy_moving}} {tag {tag _ai_wounded_carrier}} {tag {tag _ai_ap_grenade}} {tag {tag _ai_at_grenade}} {tag {tag _ai_smoke_grenade}} {tag {tag _ai_suppressed_by_mg}} {tag {tag _ai_mgunner}} {tag {tag _ai_reloading}} {tag {tag _ai_looting_weapon}} {tag {tag crew}} {tag {tag tcrew}} {tag {tag ecrew}} {tag {tag ecrew_a}} {tag {tag ecrew_b}} {tag {tag bot_arty}} {tag {tag bot_aa_guard}} {tag {tag _ufb_crew_safe}} {tag {tag _ufb_hf_cover_active}} {tag {tag _ai_wirecutter_in_action}} {tag {tag bot_inf_flank_in_progress}} {tag {tag _ufb_smoke_120m_actor}} {tag {tag _ufb_smoke_60m_actor}} {tag {tag _ufb_smoke_wirecutter_actor}} {tag {tag _ai_at_launcher_30}} {tag {tag _ai_at_launcher_40}} {tag {tag _ai_at_launcher_50}} {tag {tag _ai_at_launcher_60}} {tag {tag _ai_at_launcher_70}} {tag {tag _ai_at_launcher_80}} {tag {tag _ai_at_launcher_90}} {tag {tag _ufb_rescue_active}} {tag {tag _ufb_gun_job_active}} {tag {tag _ufb_combat_busy}} {tag {tag _ufb_job_reserved}} {tag {tag _ufb_supply_cooldown}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group 
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo rifle_fra clip"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}} {distance {mode near_than} {meters 3}}
    {tag {"tag pair"} {"for selector" _ufb_supply_actor_%team} {"for enemy" _ufb_supply_body_%team}}}
    {"switch"
     {"case" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_40"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group {include {team {team %foe}} {state {state operatable}}} {exclude {state {state dead}} {state {state inactive}}}}} {distance {mode near_than} {meters 25}} {detection visible}}}
     {"default"
      {"inventory" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_40"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {action take_from} {item "ammo rifle_fra clip"} {amount 120} {entity {source advanced} {amount 1} {sort {type entity} {entity {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_40"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}}} {ignore_captured_by_user 0} {group {select {tag {tag _ufb_supply_body_%team}}}
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo rifle_fra clip"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}}}
      {"effect" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_40"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {effect ufb_supply_cooldown}}
     }
    }
   }
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_actor_%team}} {tag_remove _ufb_supply_actor_%team}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_body_%team}} {tag_remove _ufb_supply_body_%team}}
   {"delay" {time 4.0}}
   {"trigger" {name "ufb/supply/ufb_supply_40 %team"}}
  }
 }
)
("ufb_supply_ufb_supply_40" team(a) foe(b))
("ufb_supply_ufb_supply_40" team(b) foe(a))
(define "ufb_supply_ufb_supply_41"
 {"ufb/supply/ufb_supply_41 %team"
  {condition {terms {"1.rand" {value 1}}}}
  {actions
   {"if" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {group
   {include {prop {prop human}} {state {state operatable}} {team {team %team}} {with_item {type using} {item "ufb_supply_41"}}}
   {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} {prop {prop repairing}} {prop {prop throwing}} {with_item {type amount} {item "ammo rifle_ger"} {min 24}}
    {tag {tag _ufb_surrendered}} {tag {tag _lua_mi}} {tag {tag _lua_ignore}} {tag {tag _ai_do_not_disturb}} {tag {tag repairing}} {tag {tag reloading}} {tag {tag bleeding}} {tag {tag _bleeding}} {tag {tag wounded}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag medic}} {tag {tag _ai_medic}} {tag {tag bot_medic}} {tag {tag _ufb_healing_active}} {tag {tag _ufb_autonomy_moving}} {tag {tag _ai_wounded_carrier}} {tag {tag _ai_ap_grenade}} {tag {tag _ai_at_grenade}} {tag {tag _ai_smoke_grenade}} {tag {tag _ai_suppressed_by_mg}} {tag {tag _ai_mgunner}} {tag {tag _ai_reloading}} {tag {tag _ai_looting_weapon}} {tag {tag crew}} {tag {tag tcrew}} {tag {tag ecrew}} {tag {tag ecrew_a}} {tag {tag ecrew_b}} {tag {tag bot_arty}} {tag {tag bot_aa_guard}} {tag {tag _ufb_crew_safe}} {tag {tag _ufb_hf_cover_active}} {tag {tag _ai_wirecutter_in_action}} {tag {tag bot_inf_flank_in_progress}} {tag {tag _ufb_smoke_120m_actor}} {tag {tag _ufb_smoke_60m_actor}} {tag {tag _ufb_smoke_wirecutter_actor}} {tag {tag _ai_at_launcher_30}} {tag {tag _ai_at_launcher_40}} {tag {tag _ai_at_launcher_50}} {tag {tag _ai_at_launcher_60}} {tag {tag _ai_at_launcher_70}} {tag {tag _ai_at_launcher_80}} {tag {tag _ai_at_launcher_90}} {tag {tag _ufb_rescue_active}} {tag {tag _ufb_gun_job_active}} {tag {tag _ufb_combat_busy}} {tag {tag _ufb_job_reserved}} {tag {tag _ufb_supply_cooldown}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group 
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo rifle_ger"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}} {distance {mode near_than} {meters 3}}
    {tag {"tag pair"} {"for selector" _ufb_supply_actor_%team} {"for enemy" _ufb_supply_body_%team}}}
    {"switch"
     {"case" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_41"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group {include {team {team %foe}} {state {state operatable}}} {exclude {state {state dead}} {state {state inactive}}}}} {distance {mode near_than} {meters 25}} {detection visible}}}
     {"default"
      {"inventory" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_41"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {action take_from} {item "ammo rifle_ger"} {amount 120} {entity {source advanced} {amount 1} {sort {type entity} {entity {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_41"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}}} {ignore_captured_by_user 0} {group {select {tag {tag _ufb_supply_body_%team}}}
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo rifle_ger"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}}}
      {"effect" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_41"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {effect ufb_supply_cooldown}}
     }
    }
   }
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_actor_%team}} {tag_remove _ufb_supply_actor_%team}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_body_%team}} {tag_remove _ufb_supply_body_%team}}
   {"delay" {time 4.1}}
   {"trigger" {name "ufb/supply/ufb_supply_41 %team"}}
  }
 }
)
("ufb_supply_ufb_supply_41" team(a) foe(b))
("ufb_supply_ufb_supply_41" team(b) foe(a))
(define "ufb_supply_ufb_supply_42"
 {"ufb/supply/ufb_supply_42 %team"
  {condition {terms {"1.rand" {value 1}}}}
  {actions
   {"if" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {group
   {include {prop {prop human}} {state {state operatable}} {team {team %team}} {with_item {type using} {item "ufb_supply_42"}}}
   {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} {prop {prop repairing}} {prop {prop throwing}} {with_item {type amount} {item "ammo rifle_ger clip"} {min 24}}
    {tag {tag _ufb_surrendered}} {tag {tag _lua_mi}} {tag {tag _lua_ignore}} {tag {tag _ai_do_not_disturb}} {tag {tag repairing}} {tag {tag reloading}} {tag {tag bleeding}} {tag {tag _bleeding}} {tag {tag wounded}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag medic}} {tag {tag _ai_medic}} {tag {tag bot_medic}} {tag {tag _ufb_healing_active}} {tag {tag _ufb_autonomy_moving}} {tag {tag _ai_wounded_carrier}} {tag {tag _ai_ap_grenade}} {tag {tag _ai_at_grenade}} {tag {tag _ai_smoke_grenade}} {tag {tag _ai_suppressed_by_mg}} {tag {tag _ai_mgunner}} {tag {tag _ai_reloading}} {tag {tag _ai_looting_weapon}} {tag {tag crew}} {tag {tag tcrew}} {tag {tag ecrew}} {tag {tag ecrew_a}} {tag {tag ecrew_b}} {tag {tag bot_arty}} {tag {tag bot_aa_guard}} {tag {tag _ufb_crew_safe}} {tag {tag _ufb_hf_cover_active}} {tag {tag _ai_wirecutter_in_action}} {tag {tag bot_inf_flank_in_progress}} {tag {tag _ufb_smoke_120m_actor}} {tag {tag _ufb_smoke_60m_actor}} {tag {tag _ufb_smoke_wirecutter_actor}} {tag {tag _ai_at_launcher_30}} {tag {tag _ai_at_launcher_40}} {tag {tag _ai_at_launcher_50}} {tag {tag _ai_at_launcher_60}} {tag {tag _ai_at_launcher_70}} {tag {tag _ai_at_launcher_80}} {tag {tag _ai_at_launcher_90}} {tag {tag _ufb_rescue_active}} {tag {tag _ufb_gun_job_active}} {tag {tag _ufb_combat_busy}} {tag {tag _ufb_job_reserved}} {tag {tag _ufb_supply_cooldown}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group 
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo rifle_ger clip"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}} {distance {mode near_than} {meters 3}}
    {tag {"tag pair"} {"for selector" _ufb_supply_actor_%team} {"for enemy" _ufb_supply_body_%team}}}
    {"switch"
     {"case" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_42"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group {include {team {team %foe}} {state {state operatable}}} {exclude {state {state dead}} {state {state inactive}}}}} {distance {mode near_than} {meters 25}} {detection visible}}}
     {"default"
      {"inventory" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_42"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {action take_from} {item "ammo rifle_ger clip"} {amount 120} {entity {source advanced} {amount 1} {sort {type entity} {entity {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_42"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}}} {ignore_captured_by_user 0} {group {select {tag {tag _ufb_supply_body_%team}}}
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo rifle_ger clip"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}}}
      {"effect" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_42"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {effect ufb_supply_cooldown}}
     }
    }
   }
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_actor_%team}} {tag_remove _ufb_supply_actor_%team}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_body_%team}} {tag_remove _ufb_supply_body_%team}}
   {"delay" {time 4.2}}
   {"trigger" {name "ufb/supply/ufb_supply_42 %team"}}
  }
 }
)
("ufb_supply_ufb_supply_42" team(a) foe(b))
("ufb_supply_ufb_supply_42" team(b) foe(a))
(define "ufb_supply_ufb_supply_43"
 {"ufb/supply/ufb_supply_43 %team"
  {condition {terms {"1.rand" {value 1}}}}
  {actions
   {"if" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {group
   {include {prop {prop human}} {state {state operatable}} {team {team %team}} {with_item {type using} {item "ufb_supply_43"}}}
   {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} {prop {prop repairing}} {prop {prop throwing}} {with_item {type amount} {item "ammo rifle_ita clip"} {min 24}}
    {tag {tag _ufb_surrendered}} {tag {tag _lua_mi}} {tag {tag _lua_ignore}} {tag {tag _ai_do_not_disturb}} {tag {tag repairing}} {tag {tag reloading}} {tag {tag bleeding}} {tag {tag _bleeding}} {tag {tag wounded}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag medic}} {tag {tag _ai_medic}} {tag {tag bot_medic}} {tag {tag _ufb_healing_active}} {tag {tag _ufb_autonomy_moving}} {tag {tag _ai_wounded_carrier}} {tag {tag _ai_ap_grenade}} {tag {tag _ai_at_grenade}} {tag {tag _ai_smoke_grenade}} {tag {tag _ai_suppressed_by_mg}} {tag {tag _ai_mgunner}} {tag {tag _ai_reloading}} {tag {tag _ai_looting_weapon}} {tag {tag crew}} {tag {tag tcrew}} {tag {tag ecrew}} {tag {tag ecrew_a}} {tag {tag ecrew_b}} {tag {tag bot_arty}} {tag {tag bot_aa_guard}} {tag {tag _ufb_crew_safe}} {tag {tag _ufb_hf_cover_active}} {tag {tag _ai_wirecutter_in_action}} {tag {tag bot_inf_flank_in_progress}} {tag {tag _ufb_smoke_120m_actor}} {tag {tag _ufb_smoke_60m_actor}} {tag {tag _ufb_smoke_wirecutter_actor}} {tag {tag _ai_at_launcher_30}} {tag {tag _ai_at_launcher_40}} {tag {tag _ai_at_launcher_50}} {tag {tag _ai_at_launcher_60}} {tag {tag _ai_at_launcher_70}} {tag {tag _ai_at_launcher_80}} {tag {tag _ai_at_launcher_90}} {tag {tag _ufb_rescue_active}} {tag {tag _ufb_gun_job_active}} {tag {tag _ufb_combat_busy}} {tag {tag _ufb_job_reserved}} {tag {tag _ufb_supply_cooldown}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group 
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo rifle_ita clip"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}} {distance {mode near_than} {meters 3}}
    {tag {"tag pair"} {"for selector" _ufb_supply_actor_%team} {"for enemy" _ufb_supply_body_%team}}}
    {"switch"
     {"case" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_43"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group {include {team {team %foe}} {state {state operatable}}} {exclude {state {state dead}} {state {state inactive}}}}} {distance {mode near_than} {meters 25}} {detection visible}}}
     {"default"
      {"inventory" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_43"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {action take_from} {item "ammo rifle_ita clip"} {amount 120} {entity {source advanced} {amount 1} {sort {type entity} {entity {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_43"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}}} {ignore_captured_by_user 0} {group {select {tag {tag _ufb_supply_body_%team}}}
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo rifle_ita clip"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}}}
      {"effect" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_43"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {effect ufb_supply_cooldown}}
     }
    }
   }
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_actor_%team}} {tag_remove _ufb_supply_actor_%team}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_body_%team}} {tag_remove _ufb_supply_body_%team}}
   {"delay" {time 4.3}}
   {"trigger" {name "ufb/supply/ufb_supply_43 %team"}}
  }
 }
)
("ufb_supply_ufb_supply_43" team(a) foe(b))
("ufb_supply_ufb_supply_43" team(b) foe(a))
(define "ufb_supply_ufb_supply_44"
 {"ufb/supply/ufb_supply_44 %team"
  {condition {terms {"1.rand" {value 1}}}}
  {actions
   {"if" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {group
   {include {prop {prop human}} {state {state operatable}} {team {team %team}} {with_item {type using} {item "ufb_supply_44"}}}
   {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} {prop {prop repairing}} {prop {prop throwing}} {with_item {type amount} {item "ammo rifle_ita2 clip"} {min 24}}
    {tag {tag _ufb_surrendered}} {tag {tag _lua_mi}} {tag {tag _lua_ignore}} {tag {tag _ai_do_not_disturb}} {tag {tag repairing}} {tag {tag reloading}} {tag {tag bleeding}} {tag {tag _bleeding}} {tag {tag wounded}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag medic}} {tag {tag _ai_medic}} {tag {tag bot_medic}} {tag {tag _ufb_healing_active}} {tag {tag _ufb_autonomy_moving}} {tag {tag _ai_wounded_carrier}} {tag {tag _ai_ap_grenade}} {tag {tag _ai_at_grenade}} {tag {tag _ai_smoke_grenade}} {tag {tag _ai_suppressed_by_mg}} {tag {tag _ai_mgunner}} {tag {tag _ai_reloading}} {tag {tag _ai_looting_weapon}} {tag {tag crew}} {tag {tag tcrew}} {tag {tag ecrew}} {tag {tag ecrew_a}} {tag {tag ecrew_b}} {tag {tag bot_arty}} {tag {tag bot_aa_guard}} {tag {tag _ufb_crew_safe}} {tag {tag _ufb_hf_cover_active}} {tag {tag _ai_wirecutter_in_action}} {tag {tag bot_inf_flank_in_progress}} {tag {tag _ufb_smoke_120m_actor}} {tag {tag _ufb_smoke_60m_actor}} {tag {tag _ufb_smoke_wirecutter_actor}} {tag {tag _ai_at_launcher_30}} {tag {tag _ai_at_launcher_40}} {tag {tag _ai_at_launcher_50}} {tag {tag _ai_at_launcher_60}} {tag {tag _ai_at_launcher_70}} {tag {tag _ai_at_launcher_80}} {tag {tag _ai_at_launcher_90}} {tag {tag _ufb_rescue_active}} {tag {tag _ufb_gun_job_active}} {tag {tag _ufb_combat_busy}} {tag {tag _ufb_job_reserved}} {tag {tag _ufb_supply_cooldown}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group 
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo rifle_ita2 clip"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}} {distance {mode near_than} {meters 3}}
    {tag {"tag pair"} {"for selector" _ufb_supply_actor_%team} {"for enemy" _ufb_supply_body_%team}}}
    {"switch"
     {"case" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_44"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group {include {team {team %foe}} {state {state operatable}}} {exclude {state {state dead}} {state {state inactive}}}}} {distance {mode near_than} {meters 25}} {detection visible}}}
     {"default"
      {"inventory" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_44"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {action take_from} {item "ammo rifle_ita2 clip"} {amount 120} {entity {source advanced} {amount 1} {sort {type entity} {entity {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_44"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}}} {ignore_captured_by_user 0} {group {select {tag {tag _ufb_supply_body_%team}}}
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo rifle_ita2 clip"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}}}
      {"effect" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_44"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {effect ufb_supply_cooldown}}
     }
    }
   }
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_actor_%team}} {tag_remove _ufb_supply_actor_%team}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_body_%team}} {tag_remove _ufb_supply_body_%team}}
   {"delay" {time 4.4}}
   {"trigger" {name "ufb/supply/ufb_supply_44 %team"}}
  }
 }
)
("ufb_supply_ufb_supply_44" team(a) foe(b))
("ufb_supply_ufb_supply_44" team(b) foe(a))
(define "ufb_supply_ufb_supply_45"
 {"ufb/supply/ufb_supply_45 %team"
  {condition {terms {"1.rand" {value 1}}}}
  {actions
   {"if" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {group
   {include {prop {prop human}} {state {state operatable}} {team {team %team}} {with_item {type using} {item "ufb_supply_45"}}}
   {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} {prop {prop repairing}} {prop {prop throwing}} {with_item {type amount} {item "ammo rifle_rus"} {min 24}}
    {tag {tag _ufb_surrendered}} {tag {tag _lua_mi}} {tag {tag _lua_ignore}} {tag {tag _ai_do_not_disturb}} {tag {tag repairing}} {tag {tag reloading}} {tag {tag bleeding}} {tag {tag _bleeding}} {tag {tag wounded}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag medic}} {tag {tag _ai_medic}} {tag {tag bot_medic}} {tag {tag _ufb_healing_active}} {tag {tag _ufb_autonomy_moving}} {tag {tag _ai_wounded_carrier}} {tag {tag _ai_ap_grenade}} {tag {tag _ai_at_grenade}} {tag {tag _ai_smoke_grenade}} {tag {tag _ai_suppressed_by_mg}} {tag {tag _ai_mgunner}} {tag {tag _ai_reloading}} {tag {tag _ai_looting_weapon}} {tag {tag crew}} {tag {tag tcrew}} {tag {tag ecrew}} {tag {tag ecrew_a}} {tag {tag ecrew_b}} {tag {tag bot_arty}} {tag {tag bot_aa_guard}} {tag {tag _ufb_crew_safe}} {tag {tag _ufb_hf_cover_active}} {tag {tag _ai_wirecutter_in_action}} {tag {tag bot_inf_flank_in_progress}} {tag {tag _ufb_smoke_120m_actor}} {tag {tag _ufb_smoke_60m_actor}} {tag {tag _ufb_smoke_wirecutter_actor}} {tag {tag _ai_at_launcher_30}} {tag {tag _ai_at_launcher_40}} {tag {tag _ai_at_launcher_50}} {tag {tag _ai_at_launcher_60}} {tag {tag _ai_at_launcher_70}} {tag {tag _ai_at_launcher_80}} {tag {tag _ai_at_launcher_90}} {tag {tag _ufb_rescue_active}} {tag {tag _ufb_gun_job_active}} {tag {tag _ufb_combat_busy}} {tag {tag _ufb_job_reserved}} {tag {tag _ufb_supply_cooldown}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group 
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo rifle_rus"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}} {distance {mode near_than} {meters 3}}
    {tag {"tag pair"} {"for selector" _ufb_supply_actor_%team} {"for enemy" _ufb_supply_body_%team}}}
    {"switch"
     {"case" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_45"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group {include {team {team %foe}} {state {state operatable}}} {exclude {state {state dead}} {state {state inactive}}}}} {distance {mode near_than} {meters 25}} {detection visible}}}
     {"default"
      {"inventory" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_45"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {action take_from} {item "ammo rifle_rus"} {amount 120} {entity {source advanced} {amount 1} {sort {type entity} {entity {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_45"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}}} {ignore_captured_by_user 0} {group {select {tag {tag _ufb_supply_body_%team}}}
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo rifle_rus"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}}}
      {"effect" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_45"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {effect ufb_supply_cooldown}}
     }
    }
   }
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_actor_%team}} {tag_remove _ufb_supply_actor_%team}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_body_%team}} {tag_remove _ufb_supply_body_%team}}
   {"delay" {time 4.5}}
   {"trigger" {name "ufb/supply/ufb_supply_45 %team"}}
  }
 }
)
("ufb_supply_ufb_supply_45" team(a) foe(b))
("ufb_supply_ufb_supply_45" team(b) foe(a))
(define "ufb_supply_ufb_supply_46"
 {"ufb/supply/ufb_supply_46 %team"
  {condition {terms {"1.rand" {value 1}}}}
  {actions
   {"if" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {group
   {include {prop {prop human}} {state {state operatable}} {team {team %team}} {with_item {type using} {item "ufb_supply_46"}}}
   {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} {prop {prop repairing}} {prop {prop throwing}} {with_item {type amount} {item "ammo rifle_rus clip"} {min 24}}
    {tag {tag _ufb_surrendered}} {tag {tag _lua_mi}} {tag {tag _lua_ignore}} {tag {tag _ai_do_not_disturb}} {tag {tag repairing}} {tag {tag reloading}} {tag {tag bleeding}} {tag {tag _bleeding}} {tag {tag wounded}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag medic}} {tag {tag _ai_medic}} {tag {tag bot_medic}} {tag {tag _ufb_healing_active}} {tag {tag _ufb_autonomy_moving}} {tag {tag _ai_wounded_carrier}} {tag {tag _ai_ap_grenade}} {tag {tag _ai_at_grenade}} {tag {tag _ai_smoke_grenade}} {tag {tag _ai_suppressed_by_mg}} {tag {tag _ai_mgunner}} {tag {tag _ai_reloading}} {tag {tag _ai_looting_weapon}} {tag {tag crew}} {tag {tag tcrew}} {tag {tag ecrew}} {tag {tag ecrew_a}} {tag {tag ecrew_b}} {tag {tag bot_arty}} {tag {tag bot_aa_guard}} {tag {tag _ufb_crew_safe}} {tag {tag _ufb_hf_cover_active}} {tag {tag _ai_wirecutter_in_action}} {tag {tag bot_inf_flank_in_progress}} {tag {tag _ufb_smoke_120m_actor}} {tag {tag _ufb_smoke_60m_actor}} {tag {tag _ufb_smoke_wirecutter_actor}} {tag {tag _ai_at_launcher_30}} {tag {tag _ai_at_launcher_40}} {tag {tag _ai_at_launcher_50}} {tag {tag _ai_at_launcher_60}} {tag {tag _ai_at_launcher_70}} {tag {tag _ai_at_launcher_80}} {tag {tag _ai_at_launcher_90}} {tag {tag _ufb_rescue_active}} {tag {tag _ufb_gun_job_active}} {tag {tag _ufb_combat_busy}} {tag {tag _ufb_job_reserved}} {tag {tag _ufb_supply_cooldown}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group 
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo rifle_rus clip"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}} {distance {mode near_than} {meters 3}}
    {tag {"tag pair"} {"for selector" _ufb_supply_actor_%team} {"for enemy" _ufb_supply_body_%team}}}
    {"switch"
     {"case" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_46"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group {include {team {team %foe}} {state {state operatable}}} {exclude {state {state dead}} {state {state inactive}}}}} {distance {mode near_than} {meters 25}} {detection visible}}}
     {"default"
      {"inventory" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_46"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {action take_from} {item "ammo rifle_rus clip"} {amount 120} {entity {source advanced} {amount 1} {sort {type entity} {entity {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_46"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}}} {ignore_captured_by_user 0} {group {select {tag {tag _ufb_supply_body_%team}}}
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo rifle_rus clip"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}}}
      {"effect" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_46"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {effect ufb_supply_cooldown}}
     }
    }
   }
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_actor_%team}} {tag_remove _ufb_supply_actor_%team}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_body_%team}} {tag_remove _ufb_supply_body_%team}}
   {"delay" {time 4.6}}
   {"trigger" {name "ufb/supply/ufb_supply_46 %team"}}
  }
 }
)
("ufb_supply_ufb_supply_46" team(a) foe(b))
("ufb_supply_ufb_supply_46" team(b) foe(a))
(define "ufb_supply_ufb_supply_47"
 {"ufb/supply/ufb_supply_47 %team"
  {condition {terms {"1.rand" {value 1}}}}
  {actions
   {"if" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {group
   {include {prop {prop human}} {state {state operatable}} {team {team %team}} {with_item {type using} {item "ufb_supply_47"}}}
   {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} {prop {prop repairing}} {prop {prop throwing}} {with_item {type amount} {item "ammo rifle_swe clip"} {min 24}}
    {tag {tag _ufb_surrendered}} {tag {tag _lua_mi}} {tag {tag _lua_ignore}} {tag {tag _ai_do_not_disturb}} {tag {tag repairing}} {tag {tag reloading}} {tag {tag bleeding}} {tag {tag _bleeding}} {tag {tag wounded}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag medic}} {tag {tag _ai_medic}} {tag {tag bot_medic}} {tag {tag _ufb_healing_active}} {tag {tag _ufb_autonomy_moving}} {tag {tag _ai_wounded_carrier}} {tag {tag _ai_ap_grenade}} {tag {tag _ai_at_grenade}} {tag {tag _ai_smoke_grenade}} {tag {tag _ai_suppressed_by_mg}} {tag {tag _ai_mgunner}} {tag {tag _ai_reloading}} {tag {tag _ai_looting_weapon}} {tag {tag crew}} {tag {tag tcrew}} {tag {tag ecrew}} {tag {tag ecrew_a}} {tag {tag ecrew_b}} {tag {tag bot_arty}} {tag {tag bot_aa_guard}} {tag {tag _ufb_crew_safe}} {tag {tag _ufb_hf_cover_active}} {tag {tag _ai_wirecutter_in_action}} {tag {tag bot_inf_flank_in_progress}} {tag {tag _ufb_smoke_120m_actor}} {tag {tag _ufb_smoke_60m_actor}} {tag {tag _ufb_smoke_wirecutter_actor}} {tag {tag _ai_at_launcher_30}} {tag {tag _ai_at_launcher_40}} {tag {tag _ai_at_launcher_50}} {tag {tag _ai_at_launcher_60}} {tag {tag _ai_at_launcher_70}} {tag {tag _ai_at_launcher_80}} {tag {tag _ai_at_launcher_90}} {tag {tag _ufb_rescue_active}} {tag {tag _ufb_gun_job_active}} {tag {tag _ufb_combat_busy}} {tag {tag _ufb_job_reserved}} {tag {tag _ufb_supply_cooldown}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group 
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo rifle_swe clip"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}} {distance {mode near_than} {meters 3}}
    {tag {"tag pair"} {"for selector" _ufb_supply_actor_%team} {"for enemy" _ufb_supply_body_%team}}}
    {"switch"
     {"case" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_47"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group {include {team {team %foe}} {state {state operatable}}} {exclude {state {state dead}} {state {state inactive}}}}} {distance {mode near_than} {meters 25}} {detection visible}}}
     {"default"
      {"inventory" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_47"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {action take_from} {item "ammo rifle_swe clip"} {amount 120} {entity {source advanced} {amount 1} {sort {type entity} {entity {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_47"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}}} {ignore_captured_by_user 0} {group {select {tag {tag _ufb_supply_body_%team}}}
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo rifle_swe clip"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}}}
      {"effect" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_47"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {effect ufb_supply_cooldown}}
     }
    }
   }
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_actor_%team}} {tag_remove _ufb_supply_actor_%team}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_body_%team}} {tag_remove _ufb_supply_body_%team}}
   {"delay" {time 4.7}}
   {"trigger" {name "ufb/supply/ufb_supply_47 %team"}}
  }
 }
)
("ufb_supply_ufb_supply_47" team(a) foe(b))
("ufb_supply_ufb_supply_47" team(b) foe(a))
(define "ufb_supply_ufb_supply_48"
 {"ufb/supply/ufb_supply_48 %team"
  {condition {terms {"1.rand" {value 1}}}}
  {actions
   {"if" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {group
   {include {prop {prop human}} {state {state operatable}} {team {team %team}} {with_item {type using} {item "ufb_supply_48"}}}
   {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} {prop {prop repairing}} {prop {prop throwing}} {with_item {type amount} {item "ammo rifle_usa"} {min 24}}
    {tag {tag _ufb_surrendered}} {tag {tag _lua_mi}} {tag {tag _lua_ignore}} {tag {tag _ai_do_not_disturb}} {tag {tag repairing}} {tag {tag reloading}} {tag {tag bleeding}} {tag {tag _bleeding}} {tag {tag wounded}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag medic}} {tag {tag _ai_medic}} {tag {tag bot_medic}} {tag {tag _ufb_healing_active}} {tag {tag _ufb_autonomy_moving}} {tag {tag _ai_wounded_carrier}} {tag {tag _ai_ap_grenade}} {tag {tag _ai_at_grenade}} {tag {tag _ai_smoke_grenade}} {tag {tag _ai_suppressed_by_mg}} {tag {tag _ai_mgunner}} {tag {tag _ai_reloading}} {tag {tag _ai_looting_weapon}} {tag {tag crew}} {tag {tag tcrew}} {tag {tag ecrew}} {tag {tag ecrew_a}} {tag {tag ecrew_b}} {tag {tag bot_arty}} {tag {tag bot_aa_guard}} {tag {tag _ufb_crew_safe}} {tag {tag _ufb_hf_cover_active}} {tag {tag _ai_wirecutter_in_action}} {tag {tag bot_inf_flank_in_progress}} {tag {tag _ufb_smoke_120m_actor}} {tag {tag _ufb_smoke_60m_actor}} {tag {tag _ufb_smoke_wirecutter_actor}} {tag {tag _ai_at_launcher_30}} {tag {tag _ai_at_launcher_40}} {tag {tag _ai_at_launcher_50}} {tag {tag _ai_at_launcher_60}} {tag {tag _ai_at_launcher_70}} {tag {tag _ai_at_launcher_80}} {tag {tag _ai_at_launcher_90}} {tag {tag _ufb_rescue_active}} {tag {tag _ufb_gun_job_active}} {tag {tag _ufb_combat_busy}} {tag {tag _ufb_job_reserved}} {tag {tag _ufb_supply_cooldown}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group 
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo rifle_usa"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}} {distance {mode near_than} {meters 3}}
    {tag {"tag pair"} {"for selector" _ufb_supply_actor_%team} {"for enemy" _ufb_supply_body_%team}}}
    {"switch"
     {"case" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_48"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group {include {team {team %foe}} {state {state operatable}}} {exclude {state {state dead}} {state {state inactive}}}}} {distance {mode near_than} {meters 25}} {detection visible}}}
     {"default"
      {"inventory" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_48"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {action take_from} {item "ammo rifle_usa"} {amount 120} {entity {source advanced} {amount 1} {sort {type entity} {entity {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_48"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}}} {ignore_captured_by_user 0} {group {select {tag {tag _ufb_supply_body_%team}}}
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo rifle_usa"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}}}
      {"effect" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_48"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {effect ufb_supply_cooldown}}
     }
    }
   }
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_actor_%team}} {tag_remove _ufb_supply_actor_%team}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_body_%team}} {tag_remove _ufb_supply_body_%team}}
   {"delay" {time 4.8}}
   {"trigger" {name "ufb/supply/ufb_supply_48 %team"}}
  }
 }
)
("ufb_supply_ufb_supply_48" team(a) foe(b))
("ufb_supply_ufb_supply_48" team(b) foe(a))
(define "ufb_supply_ufb_supply_49"
 {"ufb/supply/ufb_supply_49 %team"
  {condition {terms {"1.rand" {value 1}}}}
  {actions
   {"if" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {group
   {include {prop {prop human}} {state {state operatable}} {team {team %team}} {with_item {type using} {item "ufb_supply_49"}}}
   {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} {prop {prop repairing}} {prop {prop throwing}} {with_item {type amount} {item "ammo rifle_usa clip"} {min 24}}
    {tag {tag _ufb_surrendered}} {tag {tag _lua_mi}} {tag {tag _lua_ignore}} {tag {tag _ai_do_not_disturb}} {tag {tag repairing}} {tag {tag reloading}} {tag {tag bleeding}} {tag {tag _bleeding}} {tag {tag wounded}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag medic}} {tag {tag _ai_medic}} {tag {tag bot_medic}} {tag {tag _ufb_healing_active}} {tag {tag _ufb_autonomy_moving}} {tag {tag _ai_wounded_carrier}} {tag {tag _ai_ap_grenade}} {tag {tag _ai_at_grenade}} {tag {tag _ai_smoke_grenade}} {tag {tag _ai_suppressed_by_mg}} {tag {tag _ai_mgunner}} {tag {tag _ai_reloading}} {tag {tag _ai_looting_weapon}} {tag {tag crew}} {tag {tag tcrew}} {tag {tag ecrew}} {tag {tag ecrew_a}} {tag {tag ecrew_b}} {tag {tag bot_arty}} {tag {tag bot_aa_guard}} {tag {tag _ufb_crew_safe}} {tag {tag _ufb_hf_cover_active}} {tag {tag _ai_wirecutter_in_action}} {tag {tag bot_inf_flank_in_progress}} {tag {tag _ufb_smoke_120m_actor}} {tag {tag _ufb_smoke_60m_actor}} {tag {tag _ufb_smoke_wirecutter_actor}} {tag {tag _ai_at_launcher_30}} {tag {tag _ai_at_launcher_40}} {tag {tag _ai_at_launcher_50}} {tag {tag _ai_at_launcher_60}} {tag {tag _ai_at_launcher_70}} {tag {tag _ai_at_launcher_80}} {tag {tag _ai_at_launcher_90}} {tag {tag _ufb_rescue_active}} {tag {tag _ufb_gun_job_active}} {tag {tag _ufb_combat_busy}} {tag {tag _ufb_job_reserved}} {tag {tag _ufb_supply_cooldown}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group 
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo rifle_usa clip"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}} {distance {mode near_than} {meters 3}}
    {tag {"tag pair"} {"for selector" _ufb_supply_actor_%team} {"for enemy" _ufb_supply_body_%team}}}
    {"switch"
     {"case" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_49"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group {include {team {team %foe}} {state {state operatable}}} {exclude {state {state dead}} {state {state inactive}}}}} {distance {mode near_than} {meters 25}} {detection visible}}}
     {"default"
      {"inventory" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_49"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {action take_from} {item "ammo rifle_usa clip"} {amount 120} {entity {source advanced} {amount 1} {sort {type entity} {entity {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_49"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}}} {ignore_captured_by_user 0} {group {select {tag {tag _ufb_supply_body_%team}}}
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo rifle_usa clip"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}}}
      {"effect" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_49"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {effect ufb_supply_cooldown}}
     }
    }
   }
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_actor_%team}} {tag_remove _ufb_supply_actor_%team}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_body_%team}} {tag_remove _ufb_supply_body_%team}}
   {"delay" {time 4.9}}
   {"trigger" {name "ufb/supply/ufb_supply_49 %team"}}
  }
 }
)
("ufb_supply_ufb_supply_49" team(a) foe(b))
("ufb_supply_ufb_supply_49" team(b) foe(a))
(define "ufb_supply_ufb_supply_50"
 {"ufb/supply/ufb_supply_50 %team"
  {condition {terms {"1.rand" {value 1}}}}
  {actions
   {"if" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {group
   {include {prop {prop human}} {state {state operatable}} {team {team %team}} {with_item {type using} {item "ufb_supply_50"}}}
   {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} {prop {prop repairing}} {prop {prop throwing}} {with_item {type amount} {item "ammo shotgun"} {min 24}}
    {tag {tag _ufb_surrendered}} {tag {tag _lua_mi}} {tag {tag _lua_ignore}} {tag {tag _ai_do_not_disturb}} {tag {tag repairing}} {tag {tag reloading}} {tag {tag bleeding}} {tag {tag _bleeding}} {tag {tag wounded}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag medic}} {tag {tag _ai_medic}} {tag {tag bot_medic}} {tag {tag _ufb_healing_active}} {tag {tag _ufb_autonomy_moving}} {tag {tag _ai_wounded_carrier}} {tag {tag _ai_ap_grenade}} {tag {tag _ai_at_grenade}} {tag {tag _ai_smoke_grenade}} {tag {tag _ai_suppressed_by_mg}} {tag {tag _ai_mgunner}} {tag {tag _ai_reloading}} {tag {tag _ai_looting_weapon}} {tag {tag crew}} {tag {tag tcrew}} {tag {tag ecrew}} {tag {tag ecrew_a}} {tag {tag ecrew_b}} {tag {tag bot_arty}} {tag {tag bot_aa_guard}} {tag {tag _ufb_crew_safe}} {tag {tag _ufb_hf_cover_active}} {tag {tag _ai_wirecutter_in_action}} {tag {tag bot_inf_flank_in_progress}} {tag {tag _ufb_smoke_120m_actor}} {tag {tag _ufb_smoke_60m_actor}} {tag {tag _ufb_smoke_wirecutter_actor}} {tag {tag _ai_at_launcher_30}} {tag {tag _ai_at_launcher_40}} {tag {tag _ai_at_launcher_50}} {tag {tag _ai_at_launcher_60}} {tag {tag _ai_at_launcher_70}} {tag {tag _ai_at_launcher_80}} {tag {tag _ai_at_launcher_90}} {tag {tag _ufb_rescue_active}} {tag {tag _ufb_gun_job_active}} {tag {tag _ufb_combat_busy}} {tag {tag _ufb_job_reserved}} {tag {tag _ufb_supply_cooldown}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group 
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo shotgun"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}} {distance {mode near_than} {meters 3}}
    {tag {"tag pair"} {"for selector" _ufb_supply_actor_%team} {"for enemy" _ufb_supply_body_%team}}}
    {"switch"
     {"case" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_50"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group {include {team {team %foe}} {state {state operatable}}} {exclude {state {state dead}} {state {state inactive}}}}} {distance {mode near_than} {meters 25}} {detection visible}}}
     {"default"
      {"inventory" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_50"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {action take_from} {item "ammo shotgun"} {amount 120} {entity {source advanced} {amount 1} {sort {type entity} {entity {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_50"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}}} {ignore_captured_by_user 0} {group {select {tag {tag _ufb_supply_body_%team}}}
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo shotgun"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}}}
      {"effect" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_50"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {effect ufb_supply_cooldown}}
     }
    }
   }
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_actor_%team}} {tag_remove _ufb_supply_actor_%team}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_body_%team}} {tag_remove _ufb_supply_body_%team}}
   {"delay" {time 5.0}}
   {"trigger" {name "ufb/supply/ufb_supply_50 %team"}}
  }
 }
)
("ufb_supply_ufb_supply_50" team(a) foe(b))
("ufb_supply_ufb_supply_50" team(b) foe(a))
(define "ufb_supply_ufb_supply_51"
 {"ufb/supply/ufb_supply_51 %team"
  {condition {terms {"1.rand" {value 1}}}}
  {actions
   {"if" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {group
   {include {prop {prop human}} {state {state operatable}} {team {team %team}} {with_item {type using} {item "ufb_supply_51"}}}
   {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} {prop {prop repairing}} {prop {prop throwing}} {with_item {type amount} {item "ammo stg44"} {min 24}}
    {tag {tag _ufb_surrendered}} {tag {tag _lua_mi}} {tag {tag _lua_ignore}} {tag {tag _ai_do_not_disturb}} {tag {tag repairing}} {tag {tag reloading}} {tag {tag bleeding}} {tag {tag _bleeding}} {tag {tag wounded}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag medic}} {tag {tag _ai_medic}} {tag {tag bot_medic}} {tag {tag _ufb_healing_active}} {tag {tag _ufb_autonomy_moving}} {tag {tag _ai_wounded_carrier}} {tag {tag _ai_ap_grenade}} {tag {tag _ai_at_grenade}} {tag {tag _ai_smoke_grenade}} {tag {tag _ai_suppressed_by_mg}} {tag {tag _ai_mgunner}} {tag {tag _ai_reloading}} {tag {tag _ai_looting_weapon}} {tag {tag crew}} {tag {tag tcrew}} {tag {tag ecrew}} {tag {tag ecrew_a}} {tag {tag ecrew_b}} {tag {tag bot_arty}} {tag {tag bot_aa_guard}} {tag {tag _ufb_crew_safe}} {tag {tag _ufb_hf_cover_active}} {tag {tag _ai_wirecutter_in_action}} {tag {tag bot_inf_flank_in_progress}} {tag {tag _ufb_smoke_120m_actor}} {tag {tag _ufb_smoke_60m_actor}} {tag {tag _ufb_smoke_wirecutter_actor}} {tag {tag _ai_at_launcher_30}} {tag {tag _ai_at_launcher_40}} {tag {tag _ai_at_launcher_50}} {tag {tag _ai_at_launcher_60}} {tag {tag _ai_at_launcher_70}} {tag {tag _ai_at_launcher_80}} {tag {tag _ai_at_launcher_90}} {tag {tag _ufb_rescue_active}} {tag {tag _ufb_gun_job_active}} {tag {tag _ufb_combat_busy}} {tag {tag _ufb_job_reserved}} {tag {tag _ufb_supply_cooldown}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group 
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo stg44"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}} {distance {mode near_than} {meters 3}}
    {tag {"tag pair"} {"for selector" _ufb_supply_actor_%team} {"for enemy" _ufb_supply_body_%team}}}
    {"switch"
     {"case" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_51"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group {include {team {team %foe}} {state {state operatable}}} {exclude {state {state dead}} {state {state inactive}}}}} {distance {mode near_than} {meters 25}} {detection visible}}}
     {"default"
      {"inventory" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_51"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {action take_from} {item "ammo stg44"} {amount 120} {entity {source advanced} {amount 1} {sort {type entity} {entity {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_51"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}}} {ignore_captured_by_user 0} {group {select {tag {tag _ufb_supply_body_%team}}}
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo stg44"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}}}
      {"effect" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_51"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {effect ufb_supply_cooldown}}
     }
    }
   }
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_actor_%team}} {tag_remove _ufb_supply_actor_%team}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_body_%team}} {tag_remove _ufb_supply_body_%team}}
   {"delay" {time 5.1}}
   {"trigger" {name "ufb/supply/ufb_supply_51 %team"}}
  }
 }
)
("ufb_supply_ufb_supply_51" team(a) foe(b))
("ufb_supply_ufb_supply_51" team(b) foe(a))
(define "ufb_supply_ufb_supply_52"
 {"ufb/supply/ufb_supply_52 %team"
  {condition {terms {"1.rand" {value 1}}}}
  {actions
   {"if" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {group
   {include {prop {prop human}} {state {state operatable}} {team {team %team}} {with_item {type using} {item "ufb_supply_52"}}}
   {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} {prop {prop repairing}} {prop {prop throwing}} {with_item {type amount} {item "ammo suomi_drum"} {min 24}}
    {tag {tag _ufb_surrendered}} {tag {tag _lua_mi}} {tag {tag _lua_ignore}} {tag {tag _ai_do_not_disturb}} {tag {tag repairing}} {tag {tag reloading}} {tag {tag bleeding}} {tag {tag _bleeding}} {tag {tag wounded}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag medic}} {tag {tag _ai_medic}} {tag {tag bot_medic}} {tag {tag _ufb_healing_active}} {tag {tag _ufb_autonomy_moving}} {tag {tag _ai_wounded_carrier}} {tag {tag _ai_ap_grenade}} {tag {tag _ai_at_grenade}} {tag {tag _ai_smoke_grenade}} {tag {tag _ai_suppressed_by_mg}} {tag {tag _ai_mgunner}} {tag {tag _ai_reloading}} {tag {tag _ai_looting_weapon}} {tag {tag crew}} {tag {tag tcrew}} {tag {tag ecrew}} {tag {tag ecrew_a}} {tag {tag ecrew_b}} {tag {tag bot_arty}} {tag {tag bot_aa_guard}} {tag {tag _ufb_crew_safe}} {tag {tag _ufb_hf_cover_active}} {tag {tag _ai_wirecutter_in_action}} {tag {tag bot_inf_flank_in_progress}} {tag {tag _ufb_smoke_120m_actor}} {tag {tag _ufb_smoke_60m_actor}} {tag {tag _ufb_smoke_wirecutter_actor}} {tag {tag _ai_at_launcher_30}} {tag {tag _ai_at_launcher_40}} {tag {tag _ai_at_launcher_50}} {tag {tag _ai_at_launcher_60}} {tag {tag _ai_at_launcher_70}} {tag {tag _ai_at_launcher_80}} {tag {tag _ai_at_launcher_90}} {tag {tag _ufb_rescue_active}} {tag {tag _ufb_gun_job_active}} {tag {tag _ufb_combat_busy}} {tag {tag _ufb_job_reserved}} {tag {tag _ufb_supply_cooldown}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group 
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo suomi_drum"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}} {distance {mode near_than} {meters 3}}
    {tag {"tag pair"} {"for selector" _ufb_supply_actor_%team} {"for enemy" _ufb_supply_body_%team}}}
    {"switch"
     {"case" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_52"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group {include {team {team %foe}} {state {state operatable}}} {exclude {state {state dead}} {state {state inactive}}}}} {distance {mode near_than} {meters 25}} {detection visible}}}
     {"default"
      {"inventory" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_52"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {action take_from} {item "ammo suomi_drum"} {amount 120} {entity {source advanced} {amount 1} {sort {type entity} {entity {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_52"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}}} {ignore_captured_by_user 0} {group {select {tag {tag _ufb_supply_body_%team}}}
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo suomi_drum"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}}}
      {"effect" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_52"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {effect ufb_supply_cooldown}}
     }
    }
   }
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_actor_%team}} {tag_remove _ufb_supply_actor_%team}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_body_%team}} {tag_remove _ufb_supply_body_%team}}
   {"delay" {time 5.2}}
   {"trigger" {name "ufb/supply/ufb_supply_52 %team"}}
  }
 }
)
("ufb_supply_ufb_supply_52" team(a) foe(b))
("ufb_supply_ufb_supply_52" team(b) foe(a))
(define "ufb_supply_ufb_supply_53"
 {"ufb/supply/ufb_supply_53 %team"
  {condition {terms {"1.rand" {value 1}}}}
  {actions
   {"if" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {group
   {include {prop {prop human}} {state {state operatable}} {team {team %team}} {with_item {type using} {item "ufb_supply_53"}}}
   {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} {prop {prop repairing}} {prop {prop throwing}} {with_item {type amount} {item "ammo suomi_stick"} {min 24}}
    {tag {tag _ufb_surrendered}} {tag {tag _lua_mi}} {tag {tag _lua_ignore}} {tag {tag _ai_do_not_disturb}} {tag {tag repairing}} {tag {tag reloading}} {tag {tag bleeding}} {tag {tag _bleeding}} {tag {tag wounded}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag medic}} {tag {tag _ai_medic}} {tag {tag bot_medic}} {tag {tag _ufb_healing_active}} {tag {tag _ufb_autonomy_moving}} {tag {tag _ai_wounded_carrier}} {tag {tag _ai_ap_grenade}} {tag {tag _ai_at_grenade}} {tag {tag _ai_smoke_grenade}} {tag {tag _ai_suppressed_by_mg}} {tag {tag _ai_mgunner}} {tag {tag _ai_reloading}} {tag {tag _ai_looting_weapon}} {tag {tag crew}} {tag {tag tcrew}} {tag {tag ecrew}} {tag {tag ecrew_a}} {tag {tag ecrew_b}} {tag {tag bot_arty}} {tag {tag bot_aa_guard}} {tag {tag _ufb_crew_safe}} {tag {tag _ufb_hf_cover_active}} {tag {tag _ai_wirecutter_in_action}} {tag {tag bot_inf_flank_in_progress}} {tag {tag _ufb_smoke_120m_actor}} {tag {tag _ufb_smoke_60m_actor}} {tag {tag _ufb_smoke_wirecutter_actor}} {tag {tag _ai_at_launcher_30}} {tag {tag _ai_at_launcher_40}} {tag {tag _ai_at_launcher_50}} {tag {tag _ai_at_launcher_60}} {tag {tag _ai_at_launcher_70}} {tag {tag _ai_at_launcher_80}} {tag {tag _ai_at_launcher_90}} {tag {tag _ufb_rescue_active}} {tag {tag _ufb_gun_job_active}} {tag {tag _ufb_combat_busy}} {tag {tag _ufb_job_reserved}} {tag {tag _ufb_supply_cooldown}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group 
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo suomi_stick"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}} {distance {mode near_than} {meters 3}}
    {tag {"tag pair"} {"for selector" _ufb_supply_actor_%team} {"for enemy" _ufb_supply_body_%team}}}
    {"switch"
     {"case" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_53"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group {include {team {team %foe}} {state {state operatable}}} {exclude {state {state dead}} {state {state inactive}}}}} {distance {mode near_than} {meters 25}} {detection visible}}}
     {"default"
      {"inventory" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_53"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {action take_from} {item "ammo suomi_stick"} {amount 120} {entity {source advanced} {amount 1} {sort {type entity} {entity {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_53"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}}} {ignore_captured_by_user 0} {group {select {tag {tag _ufb_supply_body_%team}}}
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo suomi_stick"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}}}
      {"effect" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_53"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {effect ufb_supply_cooldown}}
     }
    }
   }
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_actor_%team}} {tag_remove _ufb_supply_actor_%team}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_body_%team}} {tag_remove _ufb_supply_body_%team}}
   {"delay" {time 5.3}}
   {"trigger" {name "ufb/supply/ufb_supply_53 %team"}}
  }
 }
)
("ufb_supply_ufb_supply_53" team(a) foe(b))
("ufb_supply_ufb_supply_53" team(b) foe(a))
(define "ufb_supply_ufb_supply_54"
 {"ufb/supply/ufb_supply_54 %team"
  {condition {terms {"1.rand" {value 1}}}}
  {actions
   {"if" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {group
   {include {prop {prop human}} {state {state operatable}} {team {team %team}} {with_item {type using} {item "ufb_supply_54"}}}
   {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} {prop {prop repairing}} {prop {prop throwing}} {with_item {type amount} {item "ammo thompson_mag"} {min 24}}
    {tag {tag _ufb_surrendered}} {tag {tag _lua_mi}} {tag {tag _lua_ignore}} {tag {tag _ai_do_not_disturb}} {tag {tag repairing}} {tag {tag reloading}} {tag {tag bleeding}} {tag {tag _bleeding}} {tag {tag wounded}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag medic}} {tag {tag _ai_medic}} {tag {tag bot_medic}} {tag {tag _ufb_healing_active}} {tag {tag _ufb_autonomy_moving}} {tag {tag _ai_wounded_carrier}} {tag {tag _ai_ap_grenade}} {tag {tag _ai_at_grenade}} {tag {tag _ai_smoke_grenade}} {tag {tag _ai_suppressed_by_mg}} {tag {tag _ai_mgunner}} {tag {tag _ai_reloading}} {tag {tag _ai_looting_weapon}} {tag {tag crew}} {tag {tag tcrew}} {tag {tag ecrew}} {tag {tag ecrew_a}} {tag {tag ecrew_b}} {tag {tag bot_arty}} {tag {tag bot_aa_guard}} {tag {tag _ufb_crew_safe}} {tag {tag _ufb_hf_cover_active}} {tag {tag _ai_wirecutter_in_action}} {tag {tag bot_inf_flank_in_progress}} {tag {tag _ufb_smoke_120m_actor}} {tag {tag _ufb_smoke_60m_actor}} {tag {tag _ufb_smoke_wirecutter_actor}} {tag {tag _ai_at_launcher_30}} {tag {tag _ai_at_launcher_40}} {tag {tag _ai_at_launcher_50}} {tag {tag _ai_at_launcher_60}} {tag {tag _ai_at_launcher_70}} {tag {tag _ai_at_launcher_80}} {tag {tag _ai_at_launcher_90}} {tag {tag _ufb_rescue_active}} {tag {tag _ufb_gun_job_active}} {tag {tag _ufb_combat_busy}} {tag {tag _ufb_job_reserved}} {tag {tag _ufb_supply_cooldown}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group 
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo thompson_mag"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}} {distance {mode near_than} {meters 3}}
    {tag {"tag pair"} {"for selector" _ufb_supply_actor_%team} {"for enemy" _ufb_supply_body_%team}}}
    {"switch"
     {"case" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_54"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group {include {team {team %foe}} {state {state operatable}}} {exclude {state {state dead}} {state {state inactive}}}}} {distance {mode near_than} {meters 25}} {detection visible}}}
     {"default"
      {"inventory" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_54"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {action take_from} {item "ammo thompson_mag"} {amount 120} {entity {source advanced} {amount 1} {sort {type entity} {entity {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_54"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}}} {ignore_captured_by_user 0} {group {select {tag {tag _ufb_supply_body_%team}}}
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo thompson_mag"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}}}
      {"effect" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_54"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {effect ufb_supply_cooldown}}
     }
    }
   }
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_actor_%team}} {tag_remove _ufb_supply_actor_%team}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_body_%team}} {tag_remove _ufb_supply_body_%team}}
   {"delay" {time 5.4}}
   {"trigger" {name "ufb/supply/ufb_supply_54 %team"}}
  }
 }
)
("ufb_supply_ufb_supply_54" team(a) foe(b))
("ufb_supply_ufb_supply_54" team(b) foe(a))
(define "ufb_supply_ufb_supply_55"
 {"ufb/supply/ufb_supply_55 %team"
  {condition {terms {"1.rand" {value 1}}}}
  {actions
   {"if" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {group
   {include {prop {prop human}} {state {state operatable}} {team {team %team}} {with_item {type using} {item "ufb_supply_55"}}}
   {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} {prop {prop repairing}} {prop {prop throwing}} {with_item {type amount} {item "ammo thompson_mag stick"} {min 24}}
    {tag {tag _ufb_surrendered}} {tag {tag _lua_mi}} {tag {tag _lua_ignore}} {tag {tag _ai_do_not_disturb}} {tag {tag repairing}} {tag {tag reloading}} {tag {tag bleeding}} {tag {tag _bleeding}} {tag {tag wounded}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag medic}} {tag {tag _ai_medic}} {tag {tag bot_medic}} {tag {tag _ufb_healing_active}} {tag {tag _ufb_autonomy_moving}} {tag {tag _ai_wounded_carrier}} {tag {tag _ai_ap_grenade}} {tag {tag _ai_at_grenade}} {tag {tag _ai_smoke_grenade}} {tag {tag _ai_suppressed_by_mg}} {tag {tag _ai_mgunner}} {tag {tag _ai_reloading}} {tag {tag _ai_looting_weapon}} {tag {tag crew}} {tag {tag tcrew}} {tag {tag ecrew}} {tag {tag ecrew_a}} {tag {tag ecrew_b}} {tag {tag bot_arty}} {tag {tag bot_aa_guard}} {tag {tag _ufb_crew_safe}} {tag {tag _ufb_hf_cover_active}} {tag {tag _ai_wirecutter_in_action}} {tag {tag bot_inf_flank_in_progress}} {tag {tag _ufb_smoke_120m_actor}} {tag {tag _ufb_smoke_60m_actor}} {tag {tag _ufb_smoke_wirecutter_actor}} {tag {tag _ai_at_launcher_30}} {tag {tag _ai_at_launcher_40}} {tag {tag _ai_at_launcher_50}} {tag {tag _ai_at_launcher_60}} {tag {tag _ai_at_launcher_70}} {tag {tag _ai_at_launcher_80}} {tag {tag _ai_at_launcher_90}} {tag {tag _ufb_rescue_active}} {tag {tag _ufb_gun_job_active}} {tag {tag _ufb_combat_busy}} {tag {tag _ufb_job_reserved}} {tag {tag _ufb_supply_cooldown}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group 
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo thompson_mag stick"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}} {distance {mode near_than} {meters 3}}
    {tag {"tag pair"} {"for selector" _ufb_supply_actor_%team} {"for enemy" _ufb_supply_body_%team}}}
    {"switch"
     {"case" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_55"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group {include {team {team %foe}} {state {state operatable}}} {exclude {state {state dead}} {state {state inactive}}}}} {distance {mode near_than} {meters 25}} {detection visible}}}
     {"default"
      {"inventory" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_55"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {action take_from} {item "ammo thompson_mag stick"} {amount 120} {entity {source advanced} {amount 1} {sort {type entity} {entity {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_55"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}}} {ignore_captured_by_user 0} {group {select {tag {tag _ufb_supply_body_%team}}}
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo thompson_mag stick"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}}}
      {"effect" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_55"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {effect ufb_supply_cooldown}}
     }
    }
   }
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_actor_%team}} {tag_remove _ufb_supply_actor_%team}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_body_%team}} {tag_remove _ufb_supply_body_%team}}
   {"delay" {time 5.5}}
   {"trigger" {name "ufb/supply/ufb_supply_55 %team"}}
  }
 }
)
("ufb_supply_ufb_supply_55" team(a) foe(b))
("ufb_supply_ufb_supply_55" team(b) foe(a))
(define "ufb_supply_ufb_supply_56"
 {"ufb/supply/ufb_supply_56 %team"
  {condition {terms {"1.rand" {value 1}}}}
  {actions
   {"if" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {group
   {include {prop {prop human}} {state {state operatable}} {team {team %team}} {with_item {type using} {item "ufb_supply_56"}}}
   {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} {prop {prop repairing}} {prop {prop throwing}} {with_item {type amount} {item "ammo tt33"} {min 24}}
    {tag {tag _ufb_surrendered}} {tag {tag _lua_mi}} {tag {tag _lua_ignore}} {tag {tag _ai_do_not_disturb}} {tag {tag repairing}} {tag {tag reloading}} {tag {tag bleeding}} {tag {tag _bleeding}} {tag {tag wounded}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag medic}} {tag {tag _ai_medic}} {tag {tag bot_medic}} {tag {tag _ufb_healing_active}} {tag {tag _ufb_autonomy_moving}} {tag {tag _ai_wounded_carrier}} {tag {tag _ai_ap_grenade}} {tag {tag _ai_at_grenade}} {tag {tag _ai_smoke_grenade}} {tag {tag _ai_suppressed_by_mg}} {tag {tag _ai_mgunner}} {tag {tag _ai_reloading}} {tag {tag _ai_looting_weapon}} {tag {tag crew}} {tag {tag tcrew}} {tag {tag ecrew}} {tag {tag ecrew_a}} {tag {tag ecrew_b}} {tag {tag bot_arty}} {tag {tag bot_aa_guard}} {tag {tag _ufb_crew_safe}} {tag {tag _ufb_hf_cover_active}} {tag {tag _ai_wirecutter_in_action}} {tag {tag bot_inf_flank_in_progress}} {tag {tag _ufb_smoke_120m_actor}} {tag {tag _ufb_smoke_60m_actor}} {tag {tag _ufb_smoke_wirecutter_actor}} {tag {tag _ai_at_launcher_30}} {tag {tag _ai_at_launcher_40}} {tag {tag _ai_at_launcher_50}} {tag {tag _ai_at_launcher_60}} {tag {tag _ai_at_launcher_70}} {tag {tag _ai_at_launcher_80}} {tag {tag _ai_at_launcher_90}} {tag {tag _ufb_rescue_active}} {tag {tag _ufb_gun_job_active}} {tag {tag _ufb_combat_busy}} {tag {tag _ufb_job_reserved}} {tag {tag _ufb_supply_cooldown}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group 
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo tt33"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}} {distance {mode near_than} {meters 3}}
    {tag {"tag pair"} {"for selector" _ufb_supply_actor_%team} {"for enemy" _ufb_supply_body_%team}}}
    {"switch"
     {"case" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_56"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group {include {team {team %foe}} {state {state operatable}}} {exclude {state {state dead}} {state {state inactive}}}}} {distance {mode near_than} {meters 25}} {detection visible}}}
     {"default"
      {"inventory" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_56"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {action take_from} {item "ammo tt33"} {amount 120} {entity {source advanced} {amount 1} {sort {type entity} {entity {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_56"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}}} {ignore_captured_by_user 0} {group {select {tag {tag _ufb_supply_body_%team}}}
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo tt33"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}}}
      {"effect" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_56"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {effect ufb_supply_cooldown}}
     }
    }
   }
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_actor_%team}} {tag_remove _ufb_supply_actor_%team}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_body_%team}} {tag_remove _ufb_supply_body_%team}}
   {"delay" {time 5.6}}
   {"trigger" {name "ufb/supply/ufb_supply_56 %team"}}
  }
 }
)
("ufb_supply_ufb_supply_56" team(a) foe(b))
("ufb_supply_ufb_supply_56" team(b) foe(a))
(define "ufb_supply_ufb_supply_57"
 {"ufb/supply/ufb_supply_57 %team"
  {condition {terms {"1.rand" {value 1}}}}
  {actions
   {"if" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {group
   {include {prop {prop human}} {state {state operatable}} {team {team %team}} {with_item {type using} {item "ufb_supply_57"}}}
   {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} {prop {prop repairing}} {prop {prop throwing}} {with_item {type amount} {item "ammo vickers_berthier_mag"} {min 24}}
    {tag {tag _ufb_surrendered}} {tag {tag _lua_mi}} {tag {tag _lua_ignore}} {tag {tag _ai_do_not_disturb}} {tag {tag repairing}} {tag {tag reloading}} {tag {tag bleeding}} {tag {tag _bleeding}} {tag {tag wounded}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag medic}} {tag {tag _ai_medic}} {tag {tag bot_medic}} {tag {tag _ufb_healing_active}} {tag {tag _ufb_autonomy_moving}} {tag {tag _ai_wounded_carrier}} {tag {tag _ai_ap_grenade}} {tag {tag _ai_at_grenade}} {tag {tag _ai_smoke_grenade}} {tag {tag _ai_suppressed_by_mg}} {tag {tag _ai_mgunner}} {tag {tag _ai_reloading}} {tag {tag _ai_looting_weapon}} {tag {tag crew}} {tag {tag tcrew}} {tag {tag ecrew}} {tag {tag ecrew_a}} {tag {tag ecrew_b}} {tag {tag bot_arty}} {tag {tag bot_aa_guard}} {tag {tag _ufb_crew_safe}} {tag {tag _ufb_hf_cover_active}} {tag {tag _ai_wirecutter_in_action}} {tag {tag bot_inf_flank_in_progress}} {tag {tag _ufb_smoke_120m_actor}} {tag {tag _ufb_smoke_60m_actor}} {tag {tag _ufb_smoke_wirecutter_actor}} {tag {tag _ai_at_launcher_30}} {tag {tag _ai_at_launcher_40}} {tag {tag _ai_at_launcher_50}} {tag {tag _ai_at_launcher_60}} {tag {tag _ai_at_launcher_70}} {tag {tag _ai_at_launcher_80}} {tag {tag _ai_at_launcher_90}} {tag {tag _ufb_rescue_active}} {tag {tag _ufb_gun_job_active}} {tag {tag _ufb_combat_busy}} {tag {tag _ufb_job_reserved}} {tag {tag _ufb_supply_cooldown}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group 
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo vickers_berthier_mag"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}} {distance {mode near_than} {meters 3}}
    {tag {"tag pair"} {"for selector" _ufb_supply_actor_%team} {"for enemy" _ufb_supply_body_%team}}}
    {"switch"
     {"case" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_57"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group {include {team {team %foe}} {state {state operatable}}} {exclude {state {state dead}} {state {state inactive}}}}} {distance {mode near_than} {meters 25}} {detection visible}}}
     {"default"
      {"inventory" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_57"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {action take_from} {item "ammo vickers_berthier_mag"} {amount 120} {entity {source advanced} {amount 1} {sort {type entity} {entity {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_57"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}}} {ignore_captured_by_user 0} {group {select {tag {tag _ufb_supply_body_%team}}}
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo vickers_berthier_mag"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}}}
      {"effect" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_57"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {effect ufb_supply_cooldown}}
     }
    }
   }
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_actor_%team}} {tag_remove _ufb_supply_actor_%team}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_body_%team}} {tag_remove _ufb_supply_body_%team}}
   {"delay" {time 5.7}}
   {"trigger" {name "ufb/supply/ufb_supply_57 %team"}}
  }
 }
)
("ufb_supply_ufb_supply_57" team(a) foe(b))
("ufb_supply_ufb_supply_57" team(b) foe(a))
(define "ufb_supply_ufb_supply_58"
 {"ufb/supply/ufb_supply_58 %team"
  {condition {terms {"1.rand" {value 1}}}}
  {actions
   {"if" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {group
   {include {prop {prop human}} {state {state operatable}} {team {team %team}} {with_item {type using} {item "ufb_supply_58"}}}
   {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} {prop {prop repairing}} {prop {prop throwing}} {with_item {type amount} {item "ammo vickers_go_mag"} {min 24}}
    {tag {tag _ufb_surrendered}} {tag {tag _lua_mi}} {tag {tag _lua_ignore}} {tag {tag _ai_do_not_disturb}} {tag {tag repairing}} {tag {tag reloading}} {tag {tag bleeding}} {tag {tag _bleeding}} {tag {tag wounded}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag medic}} {tag {tag _ai_medic}} {tag {tag bot_medic}} {tag {tag _ufb_healing_active}} {tag {tag _ufb_autonomy_moving}} {tag {tag _ai_wounded_carrier}} {tag {tag _ai_ap_grenade}} {tag {tag _ai_at_grenade}} {tag {tag _ai_smoke_grenade}} {tag {tag _ai_suppressed_by_mg}} {tag {tag _ai_mgunner}} {tag {tag _ai_reloading}} {tag {tag _ai_looting_weapon}} {tag {tag crew}} {tag {tag tcrew}} {tag {tag ecrew}} {tag {tag ecrew_a}} {tag {tag ecrew_b}} {tag {tag bot_arty}} {tag {tag bot_aa_guard}} {tag {tag _ufb_crew_safe}} {tag {tag _ufb_hf_cover_active}} {tag {tag _ai_wirecutter_in_action}} {tag {tag bot_inf_flank_in_progress}} {tag {tag _ufb_smoke_120m_actor}} {tag {tag _ufb_smoke_60m_actor}} {tag {tag _ufb_smoke_wirecutter_actor}} {tag {tag _ai_at_launcher_30}} {tag {tag _ai_at_launcher_40}} {tag {tag _ai_at_launcher_50}} {tag {tag _ai_at_launcher_60}} {tag {tag _ai_at_launcher_70}} {tag {tag _ai_at_launcher_80}} {tag {tag _ai_at_launcher_90}} {tag {tag _ufb_rescue_active}} {tag {tag _ufb_gun_job_active}} {tag {tag _ufb_combat_busy}} {tag {tag _ufb_job_reserved}} {tag {tag _ufb_supply_cooldown}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group 
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo vickers_go_mag"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}} {distance {mode near_than} {meters 3}}
    {tag {"tag pair"} {"for selector" _ufb_supply_actor_%team} {"for enemy" _ufb_supply_body_%team}}}
    {"switch"
     {"case" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_58"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group {include {team {team %foe}} {state {state operatable}}} {exclude {state {state dead}} {state {state inactive}}}}} {distance {mode near_than} {meters 25}} {detection visible}}}
     {"default"
      {"inventory" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_58"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {action take_from} {item "ammo vickers_go_mag"} {amount 120} {entity {source advanced} {amount 1} {sort {type entity} {entity {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_58"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}}} {ignore_captured_by_user 0} {group {select {tag {tag _ufb_supply_body_%team}}}
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo vickers_go_mag"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}}}
      {"effect" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_58"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {effect ufb_supply_cooldown}}
     }
    }
   }
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_actor_%team}} {tag_remove _ufb_supply_actor_%team}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_body_%team}} {tag_remove _ufb_supply_body_%team}}
   {"delay" {time 5.8}}
   {"trigger" {name "ufb/supply/ufb_supply_58 %team"}}
  }
 }
)
("ufb_supply_ufb_supply_58" team(a) foe(b))
("ufb_supply_ufb_supply_58" team(b) foe(a))
(define "ufb_supply_ufb_supply_59"
 {"ufb/supply/ufb_supply_59 %team"
  {condition {terms {"1.rand" {value 1}}}}
  {actions
   {"if" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {group
   {include {prop {prop human}} {state {state operatable}} {team {team %team}} {with_item {type using} {item "ufb_supply_59"}}}
   {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} {prop {prop repairing}} {prop {prop throwing}} {with_item {type amount} {item "ammo zb26_mag"} {min 24}}
    {tag {tag _ufb_surrendered}} {tag {tag _lua_mi}} {tag {tag _lua_ignore}} {tag {tag _ai_do_not_disturb}} {tag {tag repairing}} {tag {tag reloading}} {tag {tag bleeding}} {tag {tag _bleeding}} {tag {tag wounded}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag medic}} {tag {tag _ai_medic}} {tag {tag bot_medic}} {tag {tag _ufb_healing_active}} {tag {tag _ufb_autonomy_moving}} {tag {tag _ai_wounded_carrier}} {tag {tag _ai_ap_grenade}} {tag {tag _ai_at_grenade}} {tag {tag _ai_smoke_grenade}} {tag {tag _ai_suppressed_by_mg}} {tag {tag _ai_mgunner}} {tag {tag _ai_reloading}} {tag {tag _ai_looting_weapon}} {tag {tag crew}} {tag {tag tcrew}} {tag {tag ecrew}} {tag {tag ecrew_a}} {tag {tag ecrew_b}} {tag {tag bot_arty}} {tag {tag bot_aa_guard}} {tag {tag _ufb_crew_safe}} {tag {tag _ufb_hf_cover_active}} {tag {tag _ai_wirecutter_in_action}} {tag {tag bot_inf_flank_in_progress}} {tag {tag _ufb_smoke_120m_actor}} {tag {tag _ufb_smoke_60m_actor}} {tag {tag _ufb_smoke_wirecutter_actor}} {tag {tag _ai_at_launcher_30}} {tag {tag _ai_at_launcher_40}} {tag {tag _ai_at_launcher_50}} {tag {tag _ai_at_launcher_60}} {tag {tag _ai_at_launcher_70}} {tag {tag _ai_at_launcher_80}} {tag {tag _ai_at_launcher_90}} {tag {tag _ufb_rescue_active}} {tag {tag _ufb_gun_job_active}} {tag {tag _ufb_combat_busy}} {tag {tag _ufb_job_reserved}} {tag {tag _ufb_supply_cooldown}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group 
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo zb26_mag"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}} {distance {mode near_than} {meters 3}}
    {tag {"tag pair"} {"for selector" _ufb_supply_actor_%team} {"for enemy" _ufb_supply_body_%team}}}
    {"switch"
     {"case" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_59"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group {include {team {team %foe}} {state {state operatable}}} {exclude {state {state dead}} {state {state inactive}}}}} {distance {mode near_than} {meters 25}} {detection visible}}}
     {"default"
      {"inventory" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_59"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {action take_from} {item "ammo zb26_mag"} {amount 120} {entity {source advanced} {amount 1} {sort {type entity} {entity {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_59"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}}} {ignore_captured_by_user 0} {group {select {tag {tag _ufb_supply_body_%team}}}
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "ammo zb26_mag"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}}}
      {"effect" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_59"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {effect ufb_supply_cooldown}}
     }
    }
   }
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_actor_%team}} {tag_remove _ufb_supply_actor_%team}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_body_%team}} {tag_remove _ufb_supply_body_%team}}
   {"delay" {time 5.9}}
   {"trigger" {name "ufb/supply/ufb_supply_59 %team"}}
  }
 }
)
("ufb_supply_ufb_supply_59" team(a) foe(b))
("ufb_supply_ufb_supply_59" team(b) foe(a))
(define "ufb_supply_ufb_supply_60"
 {"ufb/supply/ufb_supply_60 %team"
  {condition {terms {"1.rand" {value 1}}}}
  {actions
   {"if" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {group
   {include {prop {prop human}} {state {state operatable}} {team {team %team}} {with_item {type using} {item "ufb_supply_60"}}}
   {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} {prop {prop repairing}} {prop {prop throwing}} {with_item {type amount} {item "breda_m38_mag"} {min 24}}
    {tag {tag _ufb_surrendered}} {tag {tag _lua_mi}} {tag {tag _lua_ignore}} {tag {tag _ai_do_not_disturb}} {tag {tag repairing}} {tag {tag reloading}} {tag {tag bleeding}} {tag {tag _bleeding}} {tag {tag wounded}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag medic}} {tag {tag _ai_medic}} {tag {tag bot_medic}} {tag {tag _ufb_healing_active}} {tag {tag _ufb_autonomy_moving}} {tag {tag _ai_wounded_carrier}} {tag {tag _ai_ap_grenade}} {tag {tag _ai_at_grenade}} {tag {tag _ai_smoke_grenade}} {tag {tag _ai_suppressed_by_mg}} {tag {tag _ai_mgunner}} {tag {tag _ai_reloading}} {tag {tag _ai_looting_weapon}} {tag {tag crew}} {tag {tag tcrew}} {tag {tag ecrew}} {tag {tag ecrew_a}} {tag {tag ecrew_b}} {tag {tag bot_arty}} {tag {tag bot_aa_guard}} {tag {tag _ufb_crew_safe}} {tag {tag _ufb_hf_cover_active}} {tag {tag _ai_wirecutter_in_action}} {tag {tag bot_inf_flank_in_progress}} {tag {tag _ufb_smoke_120m_actor}} {tag {tag _ufb_smoke_60m_actor}} {tag {tag _ufb_smoke_wirecutter_actor}} {tag {tag _ai_at_launcher_30}} {tag {tag _ai_at_launcher_40}} {tag {tag _ai_at_launcher_50}} {tag {tag _ai_at_launcher_60}} {tag {tag _ai_at_launcher_70}} {tag {tag _ai_at_launcher_80}} {tag {tag _ai_at_launcher_90}} {tag {tag _ufb_rescue_active}} {tag {tag _ufb_gun_job_active}} {tag {tag _ufb_combat_busy}} {tag {tag _ufb_job_reserved}} {tag {tag _ufb_supply_cooldown}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group 
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "breda_m38_mag"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}} {distance {mode near_than} {meters 3}}
    {tag {"tag pair"} {"for selector" _ufb_supply_actor_%team} {"for enemy" _ufb_supply_body_%team}}}
    {"switch"
     {"case" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_60"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group {include {team {team %foe}} {state {state operatable}}} {exclude {state {state dead}} {state {state inactive}}}}} {distance {mode near_than} {meters 25}} {detection visible}}}
     {"default"
      {"inventory" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_60"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {action take_from} {item "breda_m38_mag"} {amount 120} {entity {source advanced} {amount 1} {sort {type entity} {entity {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_60"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}}} {ignore_captured_by_user 0} {group {select {tag {tag _ufb_supply_body_%team}}}
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "breda_m38_mag"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}}}
      {"effect" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_60"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {effect ufb_supply_cooldown}}
     }
    }
   }
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_actor_%team}} {tag_remove _ufb_supply_actor_%team}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_body_%team}} {tag_remove _ufb_supply_body_%team}}
   {"delay" {time 4.0}}
   {"trigger" {name "ufb/supply/ufb_supply_60 %team"}}
  }
 }
)
("ufb_supply_ufb_supply_60" team(a) foe(b))
("ufb_supply_ufb_supply_60" team(b) foe(a))
(define "ufb_supply_ufb_supply_61"
 {"ufb/supply/ufb_supply_61 %team"
  {condition {terms {"1.rand" {value 1}}}}
  {actions
   {"if" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {group
   {include {prop {prop human}} {state {state operatable}} {team {team %team}} {with_item {type using} {item "ufb_supply_61"}}}
   {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} {prop {prop repairing}} {prop {prop throwing}} {with_item {type amount} {item "hmgun_eng"} {min 24}}
    {tag {tag _ufb_surrendered}} {tag {tag _lua_mi}} {tag {tag _lua_ignore}} {tag {tag _ai_do_not_disturb}} {tag {tag repairing}} {tag {tag reloading}} {tag {tag bleeding}} {tag {tag _bleeding}} {tag {tag wounded}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag medic}} {tag {tag _ai_medic}} {tag {tag bot_medic}} {tag {tag _ufb_healing_active}} {tag {tag _ufb_autonomy_moving}} {tag {tag _ai_wounded_carrier}} {tag {tag _ai_ap_grenade}} {tag {tag _ai_at_grenade}} {tag {tag _ai_smoke_grenade}} {tag {tag _ai_suppressed_by_mg}} {tag {tag _ai_mgunner}} {tag {tag _ai_reloading}} {tag {tag _ai_looting_weapon}} {tag {tag crew}} {tag {tag tcrew}} {tag {tag ecrew}} {tag {tag ecrew_a}} {tag {tag ecrew_b}} {tag {tag bot_arty}} {tag {tag bot_aa_guard}} {tag {tag _ufb_crew_safe}} {tag {tag _ufb_hf_cover_active}} {tag {tag _ai_wirecutter_in_action}} {tag {tag bot_inf_flank_in_progress}} {tag {tag _ufb_smoke_120m_actor}} {tag {tag _ufb_smoke_60m_actor}} {tag {tag _ufb_smoke_wirecutter_actor}} {tag {tag _ai_at_launcher_30}} {tag {tag _ai_at_launcher_40}} {tag {tag _ai_at_launcher_50}} {tag {tag _ai_at_launcher_60}} {tag {tag _ai_at_launcher_70}} {tag {tag _ai_at_launcher_80}} {tag {tag _ai_at_launcher_90}} {tag {tag _ufb_rescue_active}} {tag {tag _ufb_gun_job_active}} {tag {tag _ufb_combat_busy}} {tag {tag _ufb_job_reserved}} {tag {tag _ufb_supply_cooldown}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group 
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "hmgun_eng"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}} {distance {mode near_than} {meters 3}}
    {tag {"tag pair"} {"for selector" _ufb_supply_actor_%team} {"for enemy" _ufb_supply_body_%team}}}
    {"switch"
     {"case" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_61"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group {include {team {team %foe}} {state {state operatable}}} {exclude {state {state dead}} {state {state inactive}}}}} {distance {mode near_than} {meters 25}} {detection visible}}}
     {"default"
      {"inventory" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_61"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {action take_from} {item "hmgun_eng"} {amount 120} {entity {source advanced} {amount 1} {sort {type entity} {entity {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_61"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}}} {ignore_captured_by_user 0} {group {select {tag {tag _ufb_supply_body_%team}}}
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "hmgun_eng"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}}}
      {"effect" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_61"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {effect ufb_supply_cooldown}}
     }
    }
   }
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_actor_%team}} {tag_remove _ufb_supply_actor_%team}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_body_%team}} {tag_remove _ufb_supply_body_%team}}
   {"delay" {time 4.1}}
   {"trigger" {name "ufb/supply/ufb_supply_61 %team"}}
  }
 }
)
("ufb_supply_ufb_supply_61" team(a) foe(b))
("ufb_supply_ufb_supply_61" team(b) foe(a))
(define "ufb_supply_ufb_supply_62"
 {"ufb/supply/ufb_supply_62 %team"
  {condition {terms {"1.rand" {value 1}}}}
  {actions
   {"if" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {group
   {include {prop {prop human}} {state {state operatable}} {team {team %team}} {with_item {type using} {item "ufb_supply_62"}}}
   {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} {prop {prop repairing}} {prop {prop throwing}} {with_item {type amount} {item "hmgun_rus"} {min 24}}
    {tag {tag _ufb_surrendered}} {tag {tag _lua_mi}} {tag {tag _lua_ignore}} {tag {tag _ai_do_not_disturb}} {tag {tag repairing}} {tag {tag reloading}} {tag {tag bleeding}} {tag {tag _bleeding}} {tag {tag wounded}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag medic}} {tag {tag _ai_medic}} {tag {tag bot_medic}} {tag {tag _ufb_healing_active}} {tag {tag _ufb_autonomy_moving}} {tag {tag _ai_wounded_carrier}} {tag {tag _ai_ap_grenade}} {tag {tag _ai_at_grenade}} {tag {tag _ai_smoke_grenade}} {tag {tag _ai_suppressed_by_mg}} {tag {tag _ai_mgunner}} {tag {tag _ai_reloading}} {tag {tag _ai_looting_weapon}} {tag {tag crew}} {tag {tag tcrew}} {tag {tag ecrew}} {tag {tag ecrew_a}} {tag {tag ecrew_b}} {tag {tag bot_arty}} {tag {tag bot_aa_guard}} {tag {tag _ufb_crew_safe}} {tag {tag _ufb_hf_cover_active}} {tag {tag _ai_wirecutter_in_action}} {tag {tag bot_inf_flank_in_progress}} {tag {tag _ufb_smoke_120m_actor}} {tag {tag _ufb_smoke_60m_actor}} {tag {tag _ufb_smoke_wirecutter_actor}} {tag {tag _ai_at_launcher_30}} {tag {tag _ai_at_launcher_40}} {tag {tag _ai_at_launcher_50}} {tag {tag _ai_at_launcher_60}} {tag {tag _ai_at_launcher_70}} {tag {tag _ai_at_launcher_80}} {tag {tag _ai_at_launcher_90}} {tag {tag _ufb_rescue_active}} {tag {tag _ufb_gun_job_active}} {tag {tag _ufb_combat_busy}} {tag {tag _ufb_job_reserved}} {tag {tag _ufb_supply_cooldown}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group 
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "hmgun_rus"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}} {distance {mode near_than} {meters 3}}
    {tag {"tag pair"} {"for selector" _ufb_supply_actor_%team} {"for enemy" _ufb_supply_body_%team}}}
    {"switch"
     {"case" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_62"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group {include {team {team %foe}} {state {state operatable}}} {exclude {state {state dead}} {state {state inactive}}}}} {distance {mode near_than} {meters 25}} {detection visible}}}
     {"default"
      {"inventory" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_62"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {action take_from} {item "hmgun_rus"} {amount 120} {entity {source advanced} {amount 1} {sort {type entity} {entity {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_62"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}}} {ignore_captured_by_user 0} {group {select {tag {tag _ufb_supply_body_%team}}}
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "hmgun_rus"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}}}
      {"effect" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_62"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {effect ufb_supply_cooldown}}
     }
    }
   }
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_actor_%team}} {tag_remove _ufb_supply_actor_%team}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_body_%team}} {tag_remove _ufb_supply_body_%team}}
   {"delay" {time 4.2}}
   {"trigger" {name "ufb/supply/ufb_supply_62 %team"}}
  }
 }
)
("ufb_supply_ufb_supply_62" team(a) foe(b))
("ufb_supply_ufb_supply_62" team(b) foe(a))
(define "ufb_supply_ufb_supply_63"
 {"ufb/supply/ufb_supply_63 %team"
  {condition {terms {"1.rand" {value 1}}}}
  {actions
   {"if" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {group
   {include {prop {prop human}} {state {state operatable}} {team {team %team}} {with_item {type using} {item "ufb_supply_63"}}}
   {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} {prop {prop repairing}} {prop {prop throwing}} {with_item {type amount} {item "hmgun_usa"} {min 24}}
    {tag {tag _ufb_surrendered}} {tag {tag _lua_mi}} {tag {tag _lua_ignore}} {tag {tag _ai_do_not_disturb}} {tag {tag repairing}} {tag {tag reloading}} {tag {tag bleeding}} {tag {tag _bleeding}} {tag {tag wounded}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag medic}} {tag {tag _ai_medic}} {tag {tag bot_medic}} {tag {tag _ufb_healing_active}} {tag {tag _ufb_autonomy_moving}} {tag {tag _ai_wounded_carrier}} {tag {tag _ai_ap_grenade}} {tag {tag _ai_at_grenade}} {tag {tag _ai_smoke_grenade}} {tag {tag _ai_suppressed_by_mg}} {tag {tag _ai_mgunner}} {tag {tag _ai_reloading}} {tag {tag _ai_looting_weapon}} {tag {tag crew}} {tag {tag tcrew}} {tag {tag ecrew}} {tag {tag ecrew_a}} {tag {tag ecrew_b}} {tag {tag bot_arty}} {tag {tag bot_aa_guard}} {tag {tag _ufb_crew_safe}} {tag {tag _ufb_hf_cover_active}} {tag {tag _ai_wirecutter_in_action}} {tag {tag bot_inf_flank_in_progress}} {tag {tag _ufb_smoke_120m_actor}} {tag {tag _ufb_smoke_60m_actor}} {tag {tag _ufb_smoke_wirecutter_actor}} {tag {tag _ai_at_launcher_30}} {tag {tag _ai_at_launcher_40}} {tag {tag _ai_at_launcher_50}} {tag {tag _ai_at_launcher_60}} {tag {tag _ai_at_launcher_70}} {tag {tag _ai_at_launcher_80}} {tag {tag _ai_at_launcher_90}} {tag {tag _ufb_rescue_active}} {tag {tag _ufb_gun_job_active}} {tag {tag _ufb_combat_busy}} {tag {tag _ufb_job_reserved}} {tag {tag _ufb_supply_cooldown}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group 
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "hmgun_usa"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}} {distance {mode near_than} {meters 3}}
    {tag {"tag pair"} {"for selector" _ufb_supply_actor_%team} {"for enemy" _ufb_supply_body_%team}}}
    {"switch"
     {"case" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_63"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group {include {team {team %foe}} {state {state operatable}}} {exclude {state {state dead}} {state {state inactive}}}}} {distance {mode near_than} {meters 25}} {detection visible}}}
     {"default"
      {"inventory" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_63"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {action take_from} {item "hmgun_usa"} {amount 120} {entity {source advanced} {amount 1} {sort {type entity} {entity {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_63"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}}} {ignore_captured_by_user 0} {group {select {tag {tag _ufb_supply_body_%team}}}
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "hmgun_usa"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}}}
      {"effect" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_63"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {effect ufb_supply_cooldown}}
     }
    }
   }
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_actor_%team}} {tag_remove _ufb_supply_actor_%team}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_body_%team}} {tag_remove _ufb_supply_body_%team}}
   {"delay" {time 4.3}}
   {"trigger" {name "ufb/supply/ufb_supply_63 %team"}}
  }
 }
)
("ufb_supply_ufb_supply_63" team(a) foe(b))
("ufb_supply_ufb_supply_63" team(b) foe(a))
(define "ufb_supply_ufb_supply_64"
 {"ufb/supply/ufb_supply_64 %team"
  {condition {terms {"1.rand" {value 1}}}}
  {actions
   {"if" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {group
   {include {prop {prop human}} {state {state operatable}} {team {team %team}} {with_item {type using} {item "ufb_supply_64"}}}
   {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} {prop {prop repairing}} {prop {prop throwing}} {with_item {type amount} {item "mgun_eng"} {min 24}}
    {tag {tag _ufb_surrendered}} {tag {tag _lua_mi}} {tag {tag _lua_ignore}} {tag {tag _ai_do_not_disturb}} {tag {tag repairing}} {tag {tag reloading}} {tag {tag bleeding}} {tag {tag _bleeding}} {tag {tag wounded}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag medic}} {tag {tag _ai_medic}} {tag {tag bot_medic}} {tag {tag _ufb_healing_active}} {tag {tag _ufb_autonomy_moving}} {tag {tag _ai_wounded_carrier}} {tag {tag _ai_ap_grenade}} {tag {tag _ai_at_grenade}} {tag {tag _ai_smoke_grenade}} {tag {tag _ai_suppressed_by_mg}} {tag {tag _ai_mgunner}} {tag {tag _ai_reloading}} {tag {tag _ai_looting_weapon}} {tag {tag crew}} {tag {tag tcrew}} {tag {tag ecrew}} {tag {tag ecrew_a}} {tag {tag ecrew_b}} {tag {tag bot_arty}} {tag {tag bot_aa_guard}} {tag {tag _ufb_crew_safe}} {tag {tag _ufb_hf_cover_active}} {tag {tag _ai_wirecutter_in_action}} {tag {tag bot_inf_flank_in_progress}} {tag {tag _ufb_smoke_120m_actor}} {tag {tag _ufb_smoke_60m_actor}} {tag {tag _ufb_smoke_wirecutter_actor}} {tag {tag _ai_at_launcher_30}} {tag {tag _ai_at_launcher_40}} {tag {tag _ai_at_launcher_50}} {tag {tag _ai_at_launcher_60}} {tag {tag _ai_at_launcher_70}} {tag {tag _ai_at_launcher_80}} {tag {tag _ai_at_launcher_90}} {tag {tag _ufb_rescue_active}} {tag {tag _ufb_gun_job_active}} {tag {tag _ufb_combat_busy}} {tag {tag _ufb_job_reserved}} {tag {tag _ufb_supply_cooldown}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group 
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "mgun_eng"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}} {distance {mode near_than} {meters 3}}
    {tag {"tag pair"} {"for selector" _ufb_supply_actor_%team} {"for enemy" _ufb_supply_body_%team}}}
    {"switch"
     {"case" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_64"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group {include {team {team %foe}} {state {state operatable}}} {exclude {state {state dead}} {state {state inactive}}}}} {distance {mode near_than} {meters 25}} {detection visible}}}
     {"default"
      {"inventory" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_64"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {action take_from} {item "mgun_eng"} {amount 120} {entity {source advanced} {amount 1} {sort {type entity} {entity {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_64"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}}} {ignore_captured_by_user 0} {group {select {tag {tag _ufb_supply_body_%team}}}
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "mgun_eng"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}}}
      {"effect" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_64"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {effect ufb_supply_cooldown}}
     }
    }
   }
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_actor_%team}} {tag_remove _ufb_supply_actor_%team}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_body_%team}} {tag_remove _ufb_supply_body_%team}}
   {"delay" {time 4.4}}
   {"trigger" {name "ufb/supply/ufb_supply_64 %team"}}
  }
 }
)
("ufb_supply_ufb_supply_64" team(a) foe(b))
("ufb_supply_ufb_supply_64" team(b) foe(a))
(define "ufb_supply_ufb_supply_65"
 {"ufb/supply/ufb_supply_65 %team"
  {condition {terms {"1.rand" {value 1}}}}
  {actions
   {"if" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {group
   {include {prop {prop human}} {state {state operatable}} {team {team %team}} {with_item {type using} {item "ufb_supply_65"}}}
   {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} {prop {prop repairing}} {prop {prop throwing}} {with_item {type amount} {item "mgun_fra"} {min 24}}
    {tag {tag _ufb_surrendered}} {tag {tag _lua_mi}} {tag {tag _lua_ignore}} {tag {tag _ai_do_not_disturb}} {tag {tag repairing}} {tag {tag reloading}} {tag {tag bleeding}} {tag {tag _bleeding}} {tag {tag wounded}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag medic}} {tag {tag _ai_medic}} {tag {tag bot_medic}} {tag {tag _ufb_healing_active}} {tag {tag _ufb_autonomy_moving}} {tag {tag _ai_wounded_carrier}} {tag {tag _ai_ap_grenade}} {tag {tag _ai_at_grenade}} {tag {tag _ai_smoke_grenade}} {tag {tag _ai_suppressed_by_mg}} {tag {tag _ai_mgunner}} {tag {tag _ai_reloading}} {tag {tag _ai_looting_weapon}} {tag {tag crew}} {tag {tag tcrew}} {tag {tag ecrew}} {tag {tag ecrew_a}} {tag {tag ecrew_b}} {tag {tag bot_arty}} {tag {tag bot_aa_guard}} {tag {tag _ufb_crew_safe}} {tag {tag _ufb_hf_cover_active}} {tag {tag _ai_wirecutter_in_action}} {tag {tag bot_inf_flank_in_progress}} {tag {tag _ufb_smoke_120m_actor}} {tag {tag _ufb_smoke_60m_actor}} {tag {tag _ufb_smoke_wirecutter_actor}} {tag {tag _ai_at_launcher_30}} {tag {tag _ai_at_launcher_40}} {tag {tag _ai_at_launcher_50}} {tag {tag _ai_at_launcher_60}} {tag {tag _ai_at_launcher_70}} {tag {tag _ai_at_launcher_80}} {tag {tag _ai_at_launcher_90}} {tag {tag _ufb_rescue_active}} {tag {tag _ufb_gun_job_active}} {tag {tag _ufb_combat_busy}} {tag {tag _ufb_job_reserved}} {tag {tag _ufb_supply_cooldown}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group 
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "mgun_fra"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}} {distance {mode near_than} {meters 3}}
    {tag {"tag pair"} {"for selector" _ufb_supply_actor_%team} {"for enemy" _ufb_supply_body_%team}}}
    {"switch"
     {"case" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_65"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group {include {team {team %foe}} {state {state operatable}}} {exclude {state {state dead}} {state {state inactive}}}}} {distance {mode near_than} {meters 25}} {detection visible}}}
     {"default"
      {"inventory" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_65"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {action take_from} {item "mgun_fra"} {amount 120} {entity {source advanced} {amount 1} {sort {type entity} {entity {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_65"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}}} {ignore_captured_by_user 0} {group {select {tag {tag _ufb_supply_body_%team}}}
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "mgun_fra"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}}}
      {"effect" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_65"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {effect ufb_supply_cooldown}}
     }
    }
   }
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_actor_%team}} {tag_remove _ufb_supply_actor_%team}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_body_%team}} {tag_remove _ufb_supply_body_%team}}
   {"delay" {time 4.5}}
   {"trigger" {name "ufb/supply/ufb_supply_65 %team"}}
  }
 }
)
("ufb_supply_ufb_supply_65" team(a) foe(b))
("ufb_supply_ufb_supply_65" team(b) foe(a))
(define "ufb_supply_ufb_supply_66"
 {"ufb/supply/ufb_supply_66 %team"
  {condition {terms {"1.rand" {value 1}}}}
  {actions
   {"if" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {group
   {include {prop {prop human}} {state {state operatable}} {team {team %team}} {with_item {type using} {item "ufb_supply_66"}}}
   {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} {prop {prop repairing}} {prop {prop throwing}} {with_item {type amount} {item "mgun_ger"} {min 24}}
    {tag {tag _ufb_surrendered}} {tag {tag _lua_mi}} {tag {tag _lua_ignore}} {tag {tag _ai_do_not_disturb}} {tag {tag repairing}} {tag {tag reloading}} {tag {tag bleeding}} {tag {tag _bleeding}} {tag {tag wounded}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag medic}} {tag {tag _ai_medic}} {tag {tag bot_medic}} {tag {tag _ufb_healing_active}} {tag {tag _ufb_autonomy_moving}} {tag {tag _ai_wounded_carrier}} {tag {tag _ai_ap_grenade}} {tag {tag _ai_at_grenade}} {tag {tag _ai_smoke_grenade}} {tag {tag _ai_suppressed_by_mg}} {tag {tag _ai_mgunner}} {tag {tag _ai_reloading}} {tag {tag _ai_looting_weapon}} {tag {tag crew}} {tag {tag tcrew}} {tag {tag ecrew}} {tag {tag ecrew_a}} {tag {tag ecrew_b}} {tag {tag bot_arty}} {tag {tag bot_aa_guard}} {tag {tag _ufb_crew_safe}} {tag {tag _ufb_hf_cover_active}} {tag {tag _ai_wirecutter_in_action}} {tag {tag bot_inf_flank_in_progress}} {tag {tag _ufb_smoke_120m_actor}} {tag {tag _ufb_smoke_60m_actor}} {tag {tag _ufb_smoke_wirecutter_actor}} {tag {tag _ai_at_launcher_30}} {tag {tag _ai_at_launcher_40}} {tag {tag _ai_at_launcher_50}} {tag {tag _ai_at_launcher_60}} {tag {tag _ai_at_launcher_70}} {tag {tag _ai_at_launcher_80}} {tag {tag _ai_at_launcher_90}} {tag {tag _ufb_rescue_active}} {tag {tag _ufb_gun_job_active}} {tag {tag _ufb_combat_busy}} {tag {tag _ufb_job_reserved}} {tag {tag _ufb_supply_cooldown}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group 
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "mgun_ger"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}} {distance {mode near_than} {meters 3}}
    {tag {"tag pair"} {"for selector" _ufb_supply_actor_%team} {"for enemy" _ufb_supply_body_%team}}}
    {"switch"
     {"case" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_66"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group {include {team {team %foe}} {state {state operatable}}} {exclude {state {state dead}} {state {state inactive}}}}} {distance {mode near_than} {meters 25}} {detection visible}}}
     {"default"
      {"inventory" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_66"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {action take_from} {item "mgun_ger"} {amount 120} {entity {source advanced} {amount 1} {sort {type entity} {entity {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_66"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}}} {ignore_captured_by_user 0} {group {select {tag {tag _ufb_supply_body_%team}}}
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "mgun_ger"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}}}
      {"effect" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_66"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {effect ufb_supply_cooldown}}
     }
    }
   }
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_actor_%team}} {tag_remove _ufb_supply_actor_%team}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_body_%team}} {tag_remove _ufb_supply_body_%team}}
   {"delay" {time 4.6}}
   {"trigger" {name "ufb/supply/ufb_supply_66 %team"}}
  }
 }
)
("ufb_supply_ufb_supply_66" team(a) foe(b))
("ufb_supply_ufb_supply_66" team(b) foe(a))
(define "ufb_supply_ufb_supply_67"
 {"ufb/supply/ufb_supply_67 %team"
  {condition {terms {"1.rand" {value 1}}}}
  {actions
   {"if" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {group
   {include {prop {prop human}} {state {state operatable}} {team {team %team}} {with_item {type using} {item "ufb_supply_67"}}}
   {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} {prop {prop repairing}} {prop {prop throwing}} {with_item {type amount} {item "mgun_ger belt"} {min 24}}
    {tag {tag _ufb_surrendered}} {tag {tag _lua_mi}} {tag {tag _lua_ignore}} {tag {tag _ai_do_not_disturb}} {tag {tag repairing}} {tag {tag reloading}} {tag {tag bleeding}} {tag {tag _bleeding}} {tag {tag wounded}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag medic}} {tag {tag _ai_medic}} {tag {tag bot_medic}} {tag {tag _ufb_healing_active}} {tag {tag _ufb_autonomy_moving}} {tag {tag _ai_wounded_carrier}} {tag {tag _ai_ap_grenade}} {tag {tag _ai_at_grenade}} {tag {tag _ai_smoke_grenade}} {tag {tag _ai_suppressed_by_mg}} {tag {tag _ai_mgunner}} {tag {tag _ai_reloading}} {tag {tag _ai_looting_weapon}} {tag {tag crew}} {tag {tag tcrew}} {tag {tag ecrew}} {tag {tag ecrew_a}} {tag {tag ecrew_b}} {tag {tag bot_arty}} {tag {tag bot_aa_guard}} {tag {tag _ufb_crew_safe}} {tag {tag _ufb_hf_cover_active}} {tag {tag _ai_wirecutter_in_action}} {tag {tag bot_inf_flank_in_progress}} {tag {tag _ufb_smoke_120m_actor}} {tag {tag _ufb_smoke_60m_actor}} {tag {tag _ufb_smoke_wirecutter_actor}} {tag {tag _ai_at_launcher_30}} {tag {tag _ai_at_launcher_40}} {tag {tag _ai_at_launcher_50}} {tag {tag _ai_at_launcher_60}} {tag {tag _ai_at_launcher_70}} {tag {tag _ai_at_launcher_80}} {tag {tag _ai_at_launcher_90}} {tag {tag _ufb_rescue_active}} {tag {tag _ufb_gun_job_active}} {tag {tag _ufb_combat_busy}} {tag {tag _ufb_job_reserved}} {tag {tag _ufb_supply_cooldown}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group 
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "mgun_ger belt"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}} {distance {mode near_than} {meters 3}}
    {tag {"tag pair"} {"for selector" _ufb_supply_actor_%team} {"for enemy" _ufb_supply_body_%team}}}
    {"switch"
     {"case" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_67"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group {include {team {team %foe}} {state {state operatable}}} {exclude {state {state dead}} {state {state inactive}}}}} {distance {mode near_than} {meters 25}} {detection visible}}}
     {"default"
      {"inventory" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_67"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {action take_from} {item "mgun_ger belt"} {amount 120} {entity {source advanced} {amount 1} {sort {type entity} {entity {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_67"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}}} {ignore_captured_by_user 0} {group {select {tag {tag _ufb_supply_body_%team}}}
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "mgun_ger belt"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}}}
      {"effect" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_67"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {effect ufb_supply_cooldown}}
     }
    }
   }
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_actor_%team}} {tag_remove _ufb_supply_actor_%team}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_body_%team}} {tag_remove _ufb_supply_body_%team}}
   {"delay" {time 4.7}}
   {"trigger" {name "ufb/supply/ufb_supply_67 %team"}}
  }
 }
)
("ufb_supply_ufb_supply_67" team(a) foe(b))
("ufb_supply_ufb_supply_67" team(b) foe(a))
(define "ufb_supply_ufb_supply_68"
 {"ufb/supply/ufb_supply_68 %team"
  {condition {terms {"1.rand" {value 1}}}}
  {actions
   {"if" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {group
   {include {prop {prop human}} {state {state operatable}} {team {team %team}} {with_item {type using} {item "ufb_supply_68"}}}
   {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} {prop {prop repairing}} {prop {prop throwing}} {with_item {type amount} {item "mgun_ger doubledrum"} {min 24}}
    {tag {tag _ufb_surrendered}} {tag {tag _lua_mi}} {tag {tag _lua_ignore}} {tag {tag _ai_do_not_disturb}} {tag {tag repairing}} {tag {tag reloading}} {tag {tag bleeding}} {tag {tag _bleeding}} {tag {tag wounded}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag medic}} {tag {tag _ai_medic}} {tag {tag bot_medic}} {tag {tag _ufb_healing_active}} {tag {tag _ufb_autonomy_moving}} {tag {tag _ai_wounded_carrier}} {tag {tag _ai_ap_grenade}} {tag {tag _ai_at_grenade}} {tag {tag _ai_smoke_grenade}} {tag {tag _ai_suppressed_by_mg}} {tag {tag _ai_mgunner}} {tag {tag _ai_reloading}} {tag {tag _ai_looting_weapon}} {tag {tag crew}} {tag {tag tcrew}} {tag {tag ecrew}} {tag {tag ecrew_a}} {tag {tag ecrew_b}} {tag {tag bot_arty}} {tag {tag bot_aa_guard}} {tag {tag _ufb_crew_safe}} {tag {tag _ufb_hf_cover_active}} {tag {tag _ai_wirecutter_in_action}} {tag {tag bot_inf_flank_in_progress}} {tag {tag _ufb_smoke_120m_actor}} {tag {tag _ufb_smoke_60m_actor}} {tag {tag _ufb_smoke_wirecutter_actor}} {tag {tag _ai_at_launcher_30}} {tag {tag _ai_at_launcher_40}} {tag {tag _ai_at_launcher_50}} {tag {tag _ai_at_launcher_60}} {tag {tag _ai_at_launcher_70}} {tag {tag _ai_at_launcher_80}} {tag {tag _ai_at_launcher_90}} {tag {tag _ufb_rescue_active}} {tag {tag _ufb_gun_job_active}} {tag {tag _ufb_combat_busy}} {tag {tag _ufb_job_reserved}} {tag {tag _ufb_supply_cooldown}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group 
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "mgun_ger doubledrum"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}} {distance {mode near_than} {meters 3}}
    {tag {"tag pair"} {"for selector" _ufb_supply_actor_%team} {"for enemy" _ufb_supply_body_%team}}}
    {"switch"
     {"case" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_68"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group {include {team {team %foe}} {state {state operatable}}} {exclude {state {state dead}} {state {state inactive}}}}} {distance {mode near_than} {meters 25}} {detection visible}}}
     {"default"
      {"inventory" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_68"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {action take_from} {item "mgun_ger doubledrum"} {amount 120} {entity {source advanced} {amount 1} {sort {type entity} {entity {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_68"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}}} {ignore_captured_by_user 0} {group {select {tag {tag _ufb_supply_body_%team}}}
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "mgun_ger doubledrum"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}}}
      {"effect" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_68"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {effect ufb_supply_cooldown}}
     }
    }
   }
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_actor_%team}} {tag_remove _ufb_supply_actor_%team}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_body_%team}} {tag_remove _ufb_supply_body_%team}}
   {"delay" {time 4.8}}
   {"trigger" {name "ufb/supply/ufb_supply_68 %team"}}
  }
 }
)
("ufb_supply_ufb_supply_68" team(a) foe(b))
("ufb_supply_ufb_supply_68" team(b) foe(a))
(define "ufb_supply_ufb_supply_69"
 {"ufb/supply/ufb_supply_69 %team"
  {condition {terms {"1.rand" {value 1}}}}
  {actions
   {"if" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {group
   {include {prop {prop human}} {state {state operatable}} {team {team %team}} {with_item {type using} {item "ufb_supply_69"}}}
   {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} {prop {prop repairing}} {prop {prop throwing}} {with_item {type amount} {item "mgun_ger mg08"} {min 24}}
    {tag {tag _ufb_surrendered}} {tag {tag _lua_mi}} {tag {tag _lua_ignore}} {tag {tag _ai_do_not_disturb}} {tag {tag repairing}} {tag {tag reloading}} {tag {tag bleeding}} {tag {tag _bleeding}} {tag {tag wounded}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag medic}} {tag {tag _ai_medic}} {tag {tag bot_medic}} {tag {tag _ufb_healing_active}} {tag {tag _ufb_autonomy_moving}} {tag {tag _ai_wounded_carrier}} {tag {tag _ai_ap_grenade}} {tag {tag _ai_at_grenade}} {tag {tag _ai_smoke_grenade}} {tag {tag _ai_suppressed_by_mg}} {tag {tag _ai_mgunner}} {tag {tag _ai_reloading}} {tag {tag _ai_looting_weapon}} {tag {tag crew}} {tag {tag tcrew}} {tag {tag ecrew}} {tag {tag ecrew_a}} {tag {tag ecrew_b}} {tag {tag bot_arty}} {tag {tag bot_aa_guard}} {tag {tag _ufb_crew_safe}} {tag {tag _ufb_hf_cover_active}} {tag {tag _ai_wirecutter_in_action}} {tag {tag bot_inf_flank_in_progress}} {tag {tag _ufb_smoke_120m_actor}} {tag {tag _ufb_smoke_60m_actor}} {tag {tag _ufb_smoke_wirecutter_actor}} {tag {tag _ai_at_launcher_30}} {tag {tag _ai_at_launcher_40}} {tag {tag _ai_at_launcher_50}} {tag {tag _ai_at_launcher_60}} {tag {tag _ai_at_launcher_70}} {tag {tag _ai_at_launcher_80}} {tag {tag _ai_at_launcher_90}} {tag {tag _ufb_rescue_active}} {tag {tag _ufb_gun_job_active}} {tag {tag _ufb_combat_busy}} {tag {tag _ufb_job_reserved}} {tag {tag _ufb_supply_cooldown}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group 
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "mgun_ger mg08"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}} {distance {mode near_than} {meters 3}}
    {tag {"tag pair"} {"for selector" _ufb_supply_actor_%team} {"for enemy" _ufb_supply_body_%team}}}
    {"switch"
     {"case" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_69"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group {include {team {team %foe}} {state {state operatable}}} {exclude {state {state dead}} {state {state inactive}}}}} {distance {mode near_than} {meters 25}} {detection visible}}}
     {"default"
      {"inventory" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_69"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {action take_from} {item "mgun_ger mg08"} {amount 120} {entity {source advanced} {amount 1} {sort {type entity} {entity {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_69"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}}} {ignore_captured_by_user 0} {group {select {tag {tag _ufb_supply_body_%team}}}
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "mgun_ger mg08"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}}}
      {"effect" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_69"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {effect ufb_supply_cooldown}}
     }
    }
   }
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_actor_%team}} {tag_remove _ufb_supply_actor_%team}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_body_%team}} {tag_remove _ufb_supply_body_%team}}
   {"delay" {time 4.9}}
   {"trigger" {name "ufb/supply/ufb_supply_69 %team"}}
  }
 }
)
("ufb_supply_ufb_supply_69" team(a) foe(b))
("ufb_supply_ufb_supply_69" team(b) foe(a))
(define "ufb_supply_ufb_supply_70"
 {"ufb/supply/ufb_supply_70 %team"
  {condition {terms {"1.rand" {value 1}}}}
  {actions
   {"if" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {group
   {include {prop {prop human}} {state {state operatable}} {team {team %team}} {with_item {type using} {item "ufb_supply_70"}}}
   {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} {prop {prop repairing}} {prop {prop throwing}} {with_item {type amount} {item "mgun_ger mg13"} {min 24}}
    {tag {tag _ufb_surrendered}} {tag {tag _lua_mi}} {tag {tag _lua_ignore}} {tag {tag _ai_do_not_disturb}} {tag {tag repairing}} {tag {tag reloading}} {tag {tag bleeding}} {tag {tag _bleeding}} {tag {tag wounded}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag medic}} {tag {tag _ai_medic}} {tag {tag bot_medic}} {tag {tag _ufb_healing_active}} {tag {tag _ufb_autonomy_moving}} {tag {tag _ai_wounded_carrier}} {tag {tag _ai_ap_grenade}} {tag {tag _ai_at_grenade}} {tag {tag _ai_smoke_grenade}} {tag {tag _ai_suppressed_by_mg}} {tag {tag _ai_mgunner}} {tag {tag _ai_reloading}} {tag {tag _ai_looting_weapon}} {tag {tag crew}} {tag {tag tcrew}} {tag {tag ecrew}} {tag {tag ecrew_a}} {tag {tag ecrew_b}} {tag {tag bot_arty}} {tag {tag bot_aa_guard}} {tag {tag _ufb_crew_safe}} {tag {tag _ufb_hf_cover_active}} {tag {tag _ai_wirecutter_in_action}} {tag {tag bot_inf_flank_in_progress}} {tag {tag _ufb_smoke_120m_actor}} {tag {tag _ufb_smoke_60m_actor}} {tag {tag _ufb_smoke_wirecutter_actor}} {tag {tag _ai_at_launcher_30}} {tag {tag _ai_at_launcher_40}} {tag {tag _ai_at_launcher_50}} {tag {tag _ai_at_launcher_60}} {tag {tag _ai_at_launcher_70}} {tag {tag _ai_at_launcher_80}} {tag {tag _ai_at_launcher_90}} {tag {tag _ufb_rescue_active}} {tag {tag _ufb_gun_job_active}} {tag {tag _ufb_combat_busy}} {tag {tag _ufb_job_reserved}} {tag {tag _ufb_supply_cooldown}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group 
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "mgun_ger mg13"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}} {distance {mode near_than} {meters 3}}
    {tag {"tag pair"} {"for selector" _ufb_supply_actor_%team} {"for enemy" _ufb_supply_body_%team}}}
    {"switch"
     {"case" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_70"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group {include {team {team %foe}} {state {state operatable}}} {exclude {state {state dead}} {state {state inactive}}}}} {distance {mode near_than} {meters 25}} {detection visible}}}
     {"default"
      {"inventory" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_70"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {action take_from} {item "mgun_ger mg13"} {amount 120} {entity {source advanced} {amount 1} {sort {type entity} {entity {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_70"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}}} {ignore_captured_by_user 0} {group {select {tag {tag _ufb_supply_body_%team}}}
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "mgun_ger mg13"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}}}
      {"effect" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_70"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {effect ufb_supply_cooldown}}
     }
    }
   }
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_actor_%team}} {tag_remove _ufb_supply_actor_%team}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_body_%team}} {tag_remove _ufb_supply_body_%team}}
   {"delay" {time 5.0}}
   {"trigger" {name "ufb/supply/ufb_supply_70 %team"}}
  }
 }
)
("ufb_supply_ufb_supply_70" team(a) foe(b))
("ufb_supply_ufb_supply_70" team(b) foe(a))
(define "ufb_supply_ufb_supply_71"
 {"ufb/supply/ufb_supply_71 %team"
  {condition {terms {"1.rand" {value 1}}}}
  {actions
   {"if" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {group
   {include {prop {prop human}} {state {state operatable}} {team {team %team}} {with_item {type using} {item "ufb_supply_71"}}}
   {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} {prop {prop repairing}} {prop {prop throwing}} {with_item {type amount} {item "mgun_ger mg13 drum"} {min 24}}
    {tag {tag _ufb_surrendered}} {tag {tag _lua_mi}} {tag {tag _lua_ignore}} {tag {tag _ai_do_not_disturb}} {tag {tag repairing}} {tag {tag reloading}} {tag {tag bleeding}} {tag {tag _bleeding}} {tag {tag wounded}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag medic}} {tag {tag _ai_medic}} {tag {tag bot_medic}} {tag {tag _ufb_healing_active}} {tag {tag _ufb_autonomy_moving}} {tag {tag _ai_wounded_carrier}} {tag {tag _ai_ap_grenade}} {tag {tag _ai_at_grenade}} {tag {tag _ai_smoke_grenade}} {tag {tag _ai_suppressed_by_mg}} {tag {tag _ai_mgunner}} {tag {tag _ai_reloading}} {tag {tag _ai_looting_weapon}} {tag {tag crew}} {tag {tag tcrew}} {tag {tag ecrew}} {tag {tag ecrew_a}} {tag {tag ecrew_b}} {tag {tag bot_arty}} {tag {tag bot_aa_guard}} {tag {tag _ufb_crew_safe}} {tag {tag _ufb_hf_cover_active}} {tag {tag _ai_wirecutter_in_action}} {tag {tag bot_inf_flank_in_progress}} {tag {tag _ufb_smoke_120m_actor}} {tag {tag _ufb_smoke_60m_actor}} {tag {tag _ufb_smoke_wirecutter_actor}} {tag {tag _ai_at_launcher_30}} {tag {tag _ai_at_launcher_40}} {tag {tag _ai_at_launcher_50}} {tag {tag _ai_at_launcher_60}} {tag {tag _ai_at_launcher_70}} {tag {tag _ai_at_launcher_80}} {tag {tag _ai_at_launcher_90}} {tag {tag _ufb_rescue_active}} {tag {tag _ufb_gun_job_active}} {tag {tag _ufb_combat_busy}} {tag {tag _ufb_job_reserved}} {tag {tag _ufb_supply_cooldown}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group 
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "mgun_ger mg13 drum"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}} {distance {mode near_than} {meters 3}}
    {tag {"tag pair"} {"for selector" _ufb_supply_actor_%team} {"for enemy" _ufb_supply_body_%team}}}
    {"switch"
     {"case" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_71"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group {include {team {team %foe}} {state {state operatable}}} {exclude {state {state dead}} {state {state inactive}}}}} {distance {mode near_than} {meters 25}} {detection visible}}}
     {"default"
      {"inventory" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_71"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {action take_from} {item "mgun_ger mg13 drum"} {amount 120} {entity {source advanced} {amount 1} {sort {type entity} {entity {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_71"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}}} {ignore_captured_by_user 0} {group {select {tag {tag _ufb_supply_body_%team}}}
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "mgun_ger mg13 drum"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}}}
      {"effect" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_71"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {effect ufb_supply_cooldown}}
     }
    }
   }
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_actor_%team}} {tag_remove _ufb_supply_actor_%team}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_body_%team}} {tag_remove _ufb_supply_body_%team}}
   {"delay" {time 5.1}}
   {"trigger" {name "ufb/supply/ufb_supply_71 %team"}}
  }
 }
)
("ufb_supply_ufb_supply_71" team(a) foe(b))
("ufb_supply_ufb_supply_71" team(b) foe(a))
(define "ufb_supply_ufb_supply_72"
 {"ufb/supply/ufb_supply_72 %team"
  {condition {terms {"1.rand" {value 1}}}}
  {actions
   {"if" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {group
   {include {prop {prop human}} {state {state operatable}} {team {team %team}} {with_item {type using} {item "ufb_supply_72"}}}
   {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} {prop {prop repairing}} {prop {prop throwing}} {with_item {type amount} {item "mgun_ita"} {min 24}}
    {tag {tag _ufb_surrendered}} {tag {tag _lua_mi}} {tag {tag _lua_ignore}} {tag {tag _ai_do_not_disturb}} {tag {tag repairing}} {tag {tag reloading}} {tag {tag bleeding}} {tag {tag _bleeding}} {tag {tag wounded}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag medic}} {tag {tag _ai_medic}} {tag {tag bot_medic}} {tag {tag _ufb_healing_active}} {tag {tag _ufb_autonomy_moving}} {tag {tag _ai_wounded_carrier}} {tag {tag _ai_ap_grenade}} {tag {tag _ai_at_grenade}} {tag {tag _ai_smoke_grenade}} {tag {tag _ai_suppressed_by_mg}} {tag {tag _ai_mgunner}} {tag {tag _ai_reloading}} {tag {tag _ai_looting_weapon}} {tag {tag crew}} {tag {tag tcrew}} {tag {tag ecrew}} {tag {tag ecrew_a}} {tag {tag ecrew_b}} {tag {tag bot_arty}} {tag {tag bot_aa_guard}} {tag {tag _ufb_crew_safe}} {tag {tag _ufb_hf_cover_active}} {tag {tag _ai_wirecutter_in_action}} {tag {tag bot_inf_flank_in_progress}} {tag {tag _ufb_smoke_120m_actor}} {tag {tag _ufb_smoke_60m_actor}} {tag {tag _ufb_smoke_wirecutter_actor}} {tag {tag _ai_at_launcher_30}} {tag {tag _ai_at_launcher_40}} {tag {tag _ai_at_launcher_50}} {tag {tag _ai_at_launcher_60}} {tag {tag _ai_at_launcher_70}} {tag {tag _ai_at_launcher_80}} {tag {tag _ai_at_launcher_90}} {tag {tag _ufb_rescue_active}} {tag {tag _ufb_gun_job_active}} {tag {tag _ufb_combat_busy}} {tag {tag _ufb_job_reserved}} {tag {tag _ufb_supply_cooldown}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group 
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "mgun_ita"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}} {distance {mode near_than} {meters 3}}
    {tag {"tag pair"} {"for selector" _ufb_supply_actor_%team} {"for enemy" _ufb_supply_body_%team}}}
    {"switch"
     {"case" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_72"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group {include {team {team %foe}} {state {state operatable}}} {exclude {state {state dead}} {state {state inactive}}}}} {distance {mode near_than} {meters 25}} {detection visible}}}
     {"default"
      {"inventory" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_72"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {action take_from} {item "mgun_ita"} {amount 120} {entity {source advanced} {amount 1} {sort {type entity} {entity {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_72"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}}} {ignore_captured_by_user 0} {group {select {tag {tag _ufb_supply_body_%team}}}
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "mgun_ita"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}}}
      {"effect" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_72"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {effect ufb_supply_cooldown}}
     }
    }
   }
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_actor_%team}} {tag_remove _ufb_supply_actor_%team}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_body_%team}} {tag_remove _ufb_supply_body_%team}}
   {"delay" {time 5.2}}
   {"trigger" {name "ufb/supply/ufb_supply_72 %team"}}
  }
 }
)
("ufb_supply_ufb_supply_72" team(a) foe(b))
("ufb_supply_ufb_supply_72" team(b) foe(a))
(define "ufb_supply_ufb_supply_73"
 {"ufb/supply/ufb_supply_73 %team"
  {condition {terms {"1.rand" {value 1}}}}
  {actions
   {"if" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {group
   {include {prop {prop human}} {state {state operatable}} {team {team %team}} {with_item {type using} {item "ufb_supply_73"}}}
   {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} {prop {prop repairing}} {prop {prop throwing}} {with_item {type amount} {item "mgun_rus"} {min 24}}
    {tag {tag _ufb_surrendered}} {tag {tag _lua_mi}} {tag {tag _lua_ignore}} {tag {tag _ai_do_not_disturb}} {tag {tag repairing}} {tag {tag reloading}} {tag {tag bleeding}} {tag {tag _bleeding}} {tag {tag wounded}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag medic}} {tag {tag _ai_medic}} {tag {tag bot_medic}} {tag {tag _ufb_healing_active}} {tag {tag _ufb_autonomy_moving}} {tag {tag _ai_wounded_carrier}} {tag {tag _ai_ap_grenade}} {tag {tag _ai_at_grenade}} {tag {tag _ai_smoke_grenade}} {tag {tag _ai_suppressed_by_mg}} {tag {tag _ai_mgunner}} {tag {tag _ai_reloading}} {tag {tag _ai_looting_weapon}} {tag {tag crew}} {tag {tag tcrew}} {tag {tag ecrew}} {tag {tag ecrew_a}} {tag {tag ecrew_b}} {tag {tag bot_arty}} {tag {tag bot_aa_guard}} {tag {tag _ufb_crew_safe}} {tag {tag _ufb_hf_cover_active}} {tag {tag _ai_wirecutter_in_action}} {tag {tag bot_inf_flank_in_progress}} {tag {tag _ufb_smoke_120m_actor}} {tag {tag _ufb_smoke_60m_actor}} {tag {tag _ufb_smoke_wirecutter_actor}} {tag {tag _ai_at_launcher_30}} {tag {tag _ai_at_launcher_40}} {tag {tag _ai_at_launcher_50}} {tag {tag _ai_at_launcher_60}} {tag {tag _ai_at_launcher_70}} {tag {tag _ai_at_launcher_80}} {tag {tag _ai_at_launcher_90}} {tag {tag _ufb_rescue_active}} {tag {tag _ufb_gun_job_active}} {tag {tag _ufb_combat_busy}} {tag {tag _ufb_job_reserved}} {tag {tag _ufb_supply_cooldown}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group 
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "mgun_rus"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}} {distance {mode near_than} {meters 3}}
    {tag {"tag pair"} {"for selector" _ufb_supply_actor_%team} {"for enemy" _ufb_supply_body_%team}}}
    {"switch"
     {"case" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_73"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group {include {team {team %foe}} {state {state operatable}}} {exclude {state {state dead}} {state {state inactive}}}}} {distance {mode near_than} {meters 25}} {detection visible}}}
     {"default"
      {"inventory" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_73"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {action take_from} {item "mgun_rus"} {amount 120} {entity {source advanced} {amount 1} {sort {type entity} {entity {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_73"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}}} {ignore_captured_by_user 0} {group {select {tag {tag _ufb_supply_body_%team}}}
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "mgun_rus"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}}}
      {"effect" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_73"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {effect ufb_supply_cooldown}}
     }
    }
   }
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_actor_%team}} {tag_remove _ufb_supply_actor_%team}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_body_%team}} {tag_remove _ufb_supply_body_%team}}
   {"delay" {time 5.3}}
   {"trigger" {name "ufb/supply/ufb_supply_73 %team"}}
  }
 }
)
("ufb_supply_ufb_supply_73" team(a) foe(b))
("ufb_supply_ufb_supply_73" team(b) foe(a))
(define "ufb_supply_ufb_supply_74"
 {"ufb/supply/ufb_supply_74 %team"
  {condition {terms {"1.rand" {value 1}}}}
  {actions
   {"if" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {group
   {include {prop {prop human}} {state {state operatable}} {team {team %team}} {with_item {type using} {item "ufb_supply_74"}}}
   {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} {prop {prop repairing}} {prop {prop throwing}} {with_item {type amount} {item "mgun_rus belt"} {min 24}}
    {tag {tag _ufb_surrendered}} {tag {tag _lua_mi}} {tag {tag _lua_ignore}} {tag {tag _ai_do_not_disturb}} {tag {tag repairing}} {tag {tag reloading}} {tag {tag bleeding}} {tag {tag _bleeding}} {tag {tag wounded}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag medic}} {tag {tag _ai_medic}} {tag {tag bot_medic}} {tag {tag _ufb_healing_active}} {tag {tag _ufb_autonomy_moving}} {tag {tag _ai_wounded_carrier}} {tag {tag _ai_ap_grenade}} {tag {tag _ai_at_grenade}} {tag {tag _ai_smoke_grenade}} {tag {tag _ai_suppressed_by_mg}} {tag {tag _ai_mgunner}} {tag {tag _ai_reloading}} {tag {tag _ai_looting_weapon}} {tag {tag crew}} {tag {tag tcrew}} {tag {tag ecrew}} {tag {tag ecrew_a}} {tag {tag ecrew_b}} {tag {tag bot_arty}} {tag {tag bot_aa_guard}} {tag {tag _ufb_crew_safe}} {tag {tag _ufb_hf_cover_active}} {tag {tag _ai_wirecutter_in_action}} {tag {tag bot_inf_flank_in_progress}} {tag {tag _ufb_smoke_120m_actor}} {tag {tag _ufb_smoke_60m_actor}} {tag {tag _ufb_smoke_wirecutter_actor}} {tag {tag _ai_at_launcher_30}} {tag {tag _ai_at_launcher_40}} {tag {tag _ai_at_launcher_50}} {tag {tag _ai_at_launcher_60}} {tag {tag _ai_at_launcher_70}} {tag {tag _ai_at_launcher_80}} {tag {tag _ai_at_launcher_90}} {tag {tag _ufb_rescue_active}} {tag {tag _ufb_gun_job_active}} {tag {tag _ufb_combat_busy}} {tag {tag _ufb_job_reserved}} {tag {tag _ufb_supply_cooldown}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group 
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "mgun_rus belt"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}} {distance {mode near_than} {meters 3}}
    {tag {"tag pair"} {"for selector" _ufb_supply_actor_%team} {"for enemy" _ufb_supply_body_%team}}}
    {"switch"
     {"case" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_74"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group {include {team {team %foe}} {state {state operatable}}} {exclude {state {state dead}} {state {state inactive}}}}} {distance {mode near_than} {meters 25}} {detection visible}}}
     {"default"
      {"inventory" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_74"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {action take_from} {item "mgun_rus belt"} {amount 120} {entity {source advanced} {amount 1} {sort {type entity} {entity {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_74"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}}} {ignore_captured_by_user 0} {group {select {tag {tag _ufb_supply_body_%team}}}
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "mgun_rus belt"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}}}
      {"effect" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_74"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {effect ufb_supply_cooldown}}
     }
    }
   }
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_actor_%team}} {tag_remove _ufb_supply_actor_%team}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_body_%team}} {tag_remove _ufb_supply_body_%team}}
   {"delay" {time 5.4}}
   {"trigger" {name "ufb/supply/ufb_supply_74 %team"}}
  }
 }
)
("ufb_supply_ufb_supply_74" team(a) foe(b))
("ufb_supply_ufb_supply_74" team(b) foe(a))
(define "ufb_supply_ufb_supply_75"
 {"ufb/supply/ufb_supply_75 %team"
  {condition {terms {"1.rand" {value 1}}}}
  {actions
   {"if" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {group
   {include {prop {prop human}} {state {state operatable}} {team {team %team}} {with_item {type using} {item "ufb_supply_75"}}}
   {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} {prop {prop repairing}} {prop {prop throwing}} {with_item {type amount} {item "mgun_usa"} {min 24}}
    {tag {tag _ufb_surrendered}} {tag {tag _lua_mi}} {tag {tag _lua_ignore}} {tag {tag _ai_do_not_disturb}} {tag {tag repairing}} {tag {tag reloading}} {tag {tag bleeding}} {tag {tag _bleeding}} {tag {tag wounded}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag medic}} {tag {tag _ai_medic}} {tag {tag bot_medic}} {tag {tag _ufb_healing_active}} {tag {tag _ufb_autonomy_moving}} {tag {tag _ai_wounded_carrier}} {tag {tag _ai_ap_grenade}} {tag {tag _ai_at_grenade}} {tag {tag _ai_smoke_grenade}} {tag {tag _ai_suppressed_by_mg}} {tag {tag _ai_mgunner}} {tag {tag _ai_reloading}} {tag {tag _ai_looting_weapon}} {tag {tag crew}} {tag {tag tcrew}} {tag {tag ecrew}} {tag {tag ecrew_a}} {tag {tag ecrew_b}} {tag {tag bot_arty}} {tag {tag bot_aa_guard}} {tag {tag _ufb_crew_safe}} {tag {tag _ufb_hf_cover_active}} {tag {tag _ai_wirecutter_in_action}} {tag {tag bot_inf_flank_in_progress}} {tag {tag _ufb_smoke_120m_actor}} {tag {tag _ufb_smoke_60m_actor}} {tag {tag _ufb_smoke_wirecutter_actor}} {tag {tag _ai_at_launcher_30}} {tag {tag _ai_at_launcher_40}} {tag {tag _ai_at_launcher_50}} {tag {tag _ai_at_launcher_60}} {tag {tag _ai_at_launcher_70}} {tag {tag _ai_at_launcher_80}} {tag {tag _ai_at_launcher_90}} {tag {tag _ufb_rescue_active}} {tag {tag _ufb_gun_job_active}} {tag {tag _ufb_combat_busy}} {tag {tag _ufb_job_reserved}} {tag {tag _ufb_supply_cooldown}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group 
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "mgun_usa"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}} {distance {mode near_than} {meters 3}}
    {tag {"tag pair"} {"for selector" _ufb_supply_actor_%team} {"for enemy" _ufb_supply_body_%team}}}
    {"switch"
     {"case" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_75"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group {include {team {team %foe}} {state {state operatable}}} {exclude {state {state dead}} {state {state inactive}}}}} {distance {mode near_than} {meters 25}} {detection visible}}}
     {"default"
      {"inventory" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_75"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {action take_from} {item "mgun_usa"} {amount 120} {entity {source advanced} {amount 1} {sort {type entity} {entity {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_75"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}}} {ignore_captured_by_user 0} {group {select {tag {tag _ufb_supply_body_%team}}}
 {include {prop {prop human}} {state {state dead}} {with_item {type existance} {item "mgun_usa"}}}
 {exclude {state {state linked}} {tag {tag hidden}} {tag {tag bleeding}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _ai_wounded_target_linked}}}}}}
      {"effect" {selector {source advanced} {ignore_captured_by_user 1} {amount 1} {group {select {tag {tag _ufb_supply_actor_%team}}} {include {prop {prop human}} {state {state operatable}} {with_item {type using} {item "ufb_supply_75"}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {effect ufb_supply_cooldown}}
     }
    }
   }
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_actor_%team}} {tag_remove _ufb_supply_actor_%team}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_supply_body_%team}} {tag_remove _ufb_supply_body_%team}}
   {"delay" {time 5.5}}
   {"trigger" {name "ufb/supply/ufb_supply_75 %team"}}
  }
 }
)
("ufb_supply_ufb_supply_75" team(a) foe(b))
("ufb_supply_ufb_supply_75" team(b) foe(a))

(include "/map/multi/ufb_medical_support.inc")
