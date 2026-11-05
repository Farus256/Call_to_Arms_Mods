; UFB stationary weapons. See tools/static-weapons.cjs.
(define "ufb_static_weapons"
{"ufb/gun/abandon light %player"
 {condition {terms {"1.see_actors" {selector {source advanced} {ignore_captured_by_user 1} {group
 {select {prop {prop mg_stan}} {prop {prop mortar}}}
 {include {player {player "%player"}} {prop {prop cannon}} {state {state operatable}} {state {state inhabited}}}
 {exclude {prop {prop bunker}} {prop {prop hatch}} {prop {prop muzzle_20mm_25mm_auto}} {state {state dead}} {state {state inactive}} {state {state linked}} {tag {tag _ufb_gun_left_%player}} {prop {prop muzzle_hmg}} {prop {prop muzzle_hmg_dshk}} {prop {prop muzzle_hmg_m2hb}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group
 {select {prop {prop tank}} {prop {prop armored_car}}}
 {include {relation {relation enemy} {player "%player"}} {state {state operatable}} }
 {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop airborne}}}}} {distance {mode in_range} {min 0} {max 80}} {detection visible} {tag {"tag pair"} {"for selector" _ufb_gun_flee_%player}}}}}
 {actions
  {"effect" {selector {ignore_captured_by_user 0} {tag _ufb_gun_flee_%player}} {effect emit_crew}}
  {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_gun_flee_%player}} {tag_add _ufb_gun_left_%player}}
  {"con" {text "[UFB gun] crew abandons light gun: player %player"}}
  {"delay" {time 6}}
  {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_gun_flee_%player}} {tag_remove _ufb_gun_flee_%player}}
  {"delay" {time 2}}
{"trigger" {name "ufb/gun/abandon light %player"}}
 }
}
{"ufb/gun/abandon heavy %player"
 {condition {terms {"1.see_actors" {selector {source advanced} {ignore_captured_by_user 1} {group
 {select {prop {prop muzzle_hmg}} {prop {prop muzzle_hmg_dshk}} {prop {prop muzzle_hmg_m2hb}}}
 {include {player {player "%player"}} {prop {prop cannon}} {state {state operatable}} {state {state inhabited}}}
 {exclude {prop {prop bunker}} {prop {prop hatch}} {prop {prop muzzle_20mm_25mm_auto}} {state {state dead}} {state {state inactive}} {state {state linked}} {tag {tag _ufb_gun_left_%player}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group
 {select {prop {prop medium}} {prop {prop heavy}}}
 {include {relation {relation enemy} {player "%player"}} {state {state operatable}} {prop {prop with_gun}}}
 {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop airborne}}}}} {distance {mode in_range} {min 0} {max 80}} {detection visible} {tag {"tag pair"} {"for selector" _ufb_gun_flee_%player}}}}}
 {actions
  {"effect" {selector {ignore_captured_by_user 0} {tag _ufb_gun_flee_%player}} {effect emit_crew}}
  {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_gun_flee_%player}} {tag_add _ufb_gun_left_%player}}
  {"con" {text "[UFB gun] crew abandons heavy gun: player %player"}}
  {"delay" {time 6}}
  {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_gun_flee_%player}} {tag_remove _ufb_gun_flee_%player}}
  {"delay" {time 2}}
{"trigger" {name "ufb/gun/abandon heavy %player"}}
 }
}
{"ufb/gun/crew %player"
 {condition {terms {"1.see_actors" {selector {source advanced} {ignore_captured_by_user 1} {group
 {select {prop {prop human}}}
 {include {player {player "%player"}} {state {state operatable}}}
 {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {tag {tag _ufb_gun_crew_%player}}}}} {enemy {ignore_captured_by_user 0} {tag _ufb_gun_flee_%player}}
  {distance {mode near_than} {meters 7}}
  {tag {"tag pair"} {"for selector" _ufb_gun_crew_new_%player}}
 }}}
 {actions
  {"effect" {selector {ignore_captured_by_user 0} {tag _ufb_gun_crew_new_%player}} {effect ufb_gun_flee_%player}}
  {"delay" {time 0.2}}
  {"action" {selector {ignore_captured_by_user 0} {tag _ufb_gun_crew_new_%player}} {drop "orders sensor senseless"} {action move}
   {target {ignore_captured_by_user 0} {tag _ufb_gun_flee_point_%player}}}
  {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_gun_crew_new_%player}} {tag_remove _ufb_gun_crew_new_%player}}
  {"delay" {time 0.5}}
{"trigger" {name "ufb/gun/crew %player"}}
 }
}
{"ufb/gun/cover %player"
 {condition {terms {"1.entities" {selector {ignore_captured_by_user 0} {tag _ufb_gun_cover_%player}}}}}
 {actions
  {"actor_to_cover" {selector {ignore_captured_by_user 0} {tag _ufb_gun_cover_%player}} {drop orders}}
  {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_gun_cover_%player}} {tag_remove _ufb_gun_cover_%player}}
  {"delay" {time 2}}
{"trigger" {name "ufb/gun/cover %player"}}
 }
}
{"ufb/gun/rearm %player"
 {condition {terms {"1.entities" {selector {ignore_captured_by_user 0} {tag _ufb_gun_left_%player}}}}}
 {actions
  {"delay" {time 60}}
  {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_gun_left_%player}} {tag_remove _ufb_gun_left_%player}}
  {"delay" {time 1}}
{"trigger" {name "ufb/gun/rearm %player"}}
 }
}
{"ufb/gun/deploy mg %player"
 {condition {terms {"1.see_actors" {selector {source advanced} {ignore_captured_by_user 0} {group
 {select {prop {prop mg_stan}}}
 {include {player {player "%player"}} {prop {prop cannon}} {state {state operatable}} {state {state inhabited}}}
 {exclude {state {state user_control}} {prop {prop fixed}} {tag {tag _lua_mi}} {tag {tag bot_arty}} {tag {tag _ufb_gun_deployed}} {tag {tag _ufb_gun_left_%player}} {prop {prop bunker}} {prop {prop hatch}} {prop {prop muzzle_20mm_25mm_auto}} {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop mortar}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group
 {select {prop {prop human}} {prop {prop vehicle}}}
 {include {relation {relation enemy} {player "%player"}} {state {state operatable}}}
 {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop airborne}}}}} {distance {mode in_range} {min 40} {max 130}} {detection visible} {tag {"tag pair"} {"for selector" _ufb_gun_deploy_%player}}}}}
 {actions
  {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_gun_deploy_%player}} {tag_add _ufb_gun_deployed}}
  {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_gun_deploy_%player}} {tag_add _lua_mi}}
  {"actor_state" {selector {ignore_captured_by_user 0} {tag _ufb_gun_deploy_%player}} {drop orders} {move_mode hold} {cannon fire}}
  {"con" {text "[UFB gun] bot deploys mg: player %player"}}
  {"delay" {time 4}}
  {"switch"
  {"case" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 0} {group
 {select {tag {tag _ufb_gun_deploy_%player}}}
 {include {prop {prop cannon_sandbag_standard}}}
 {exclude {prop {prop no_sandbags}} {tag {tag _ufb_gun_fort_checked}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group
 {select {prop {prop human}} {prop {prop vehicle}}}
 {include {relation {relation enemy} {player "%player"}} {state {state operatable}}}
 {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop airborne}}}}} {distance {mode in_range} {min 0} {max 40}} {detection visible}}}
  {"default"
   {"switch"
    {"case" {condition {type rand} {value 0.6}}
     {"effect" {selector {source advanced} {ignore_captured_by_user 0} {group
 {select {tag {tag _ufb_gun_deploy_%player}}}
 {include {prop {prop cannon_sandbag_standard}}}
 {exclude {prop {prop no_sandbags}} {tag {tag _ufb_gun_fort_checked}}}}} {effect construction_sandbag_cannon_standard_ai}}
     {"con" {text "[UFB gun] bot sandbags standard: player %player"}}
    }
   }
   {"entity_state" {selector {source advanced} {ignore_captured_by_user 0} {group
 {select {tag {tag _ufb_gun_deploy_%player}}}
 {include {prop {prop cannon_sandbag_standard}}}
 {exclude {prop {prop no_sandbags}} {tag {tag _ufb_gun_fort_checked}}}}} {tag_add _ufb_gun_fort_checked}}
  }
 }
  {"switch"
  {"case" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 0} {group
 {select {tag {tag _ufb_gun_deploy_%player}}}
 {include {prop {prop cannon_sandbag_small}}}
 {exclude {prop {prop no_sandbags}} {tag {tag _ufb_gun_fort_checked}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group
 {select {prop {prop human}} {prop {prop vehicle}}}
 {include {relation {relation enemy} {player "%player"}} {state {state operatable}}}
 {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop airborne}}}}} {distance {mode in_range} {min 0} {max 40}} {detection visible}}}
  {"default"
   {"switch"
    {"case" {condition {type rand} {value 0.6}}
     {"effect" {selector {source advanced} {ignore_captured_by_user 0} {group
 {select {tag {tag _ufb_gun_deploy_%player}}}
 {include {prop {prop cannon_sandbag_small}}}
 {exclude {prop {prop no_sandbags}} {tag {tag _ufb_gun_fort_checked}}}}} {effect construction_sandbag_cannon_shallow_ai}}
     {"con" {text "[UFB gun] bot sandbags small: player %player"}}
    }
   }
   {"entity_state" {selector {source advanced} {ignore_captured_by_user 0} {group
 {select {tag {tag _ufb_gun_deploy_%player}}}
 {include {prop {prop cannon_sandbag_small}}}
 {exclude {prop {prop no_sandbags}} {tag {tag _ufb_gun_fort_checked}}}}} {tag_add _ufb_gun_fort_checked}}
  }
 }
  {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_gun_deploy_%player}} {tag_remove _ufb_gun_deploy_%player}}
  {"delay" {time 2}}
{"trigger" {name "ufb/gun/deploy mg %player"}}
 }
}
{"ufb/gun/deploy mortar %player"
 {condition {terms {"1.see_actors" {selector {source advanced} {ignore_captured_by_user 0} {group
 {select {prop {prop mortar}}}
 {include {player {player "%player"}} {prop {prop cannon}} {state {state operatable}} {state {state inhabited}}}
 {exclude {state {state user_control}} {prop {prop fixed}} {tag {tag _lua_mi}} {tag {tag bot_arty}} {tag {tag _ufb_gun_deployed}} {tag {tag _ufb_gun_left_%player}} {prop {prop bunker}} {prop {prop hatch}} {prop {prop muzzle_20mm_25mm_auto}} {state {state dead}} {state {state inactive}} {state {state linked}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group
 {select {prop {prop human}} {prop {prop vehicle}}}
 {include {relation {relation enemy} {player "%player"}} {state {state operatable}}}
 {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop airborne}}}}} {distance {mode in_range} {min 60} {max 240}} {detection visible} {tag {"tag pair"} {"for selector" _ufb_gun_deploy_%player}}}}}
 {actions
  {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_gun_deploy_%player}} {tag_add _ufb_gun_deployed}}
  {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_gun_deploy_%player}} {tag_add _lua_mi}}
  {"actor_state" {selector {ignore_captured_by_user 0} {tag _ufb_gun_deploy_%player}} {drop orders} {move_mode hold} {cannon fire}}
  {"con" {text "[UFB gun] bot deploys mortar: player %player"}}
  {"delay" {time 4}}
  {"switch"
  {"case" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 0} {group
 {select {tag {tag _ufb_gun_deploy_%player}}}
 {include {prop {prop cannon_sandbag_standard}}}
 {exclude {prop {prop no_sandbags}} {tag {tag _ufb_gun_fort_checked}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group
 {select {prop {prop human}} {prop {prop vehicle}}}
 {include {relation {relation enemy} {player "%player"}} {state {state operatable}}}
 {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop airborne}}}}} {distance {mode in_range} {min 0} {max 40}} {detection visible}}}
  {"default"
   {"switch"
    {"case" {condition {type rand} {value 0.6}}
     {"effect" {selector {source advanced} {ignore_captured_by_user 0} {group
 {select {tag {tag _ufb_gun_deploy_%player}}}
 {include {prop {prop cannon_sandbag_standard}}}
 {exclude {prop {prop no_sandbags}} {tag {tag _ufb_gun_fort_checked}}}}} {effect construction_sandbag_cannon_standard_ai}}
     {"con" {text "[UFB gun] bot sandbags standard: player %player"}}
    }
   }
   {"entity_state" {selector {source advanced} {ignore_captured_by_user 0} {group
 {select {tag {tag _ufb_gun_deploy_%player}}}
 {include {prop {prop cannon_sandbag_standard}}}
 {exclude {prop {prop no_sandbags}} {tag {tag _ufb_gun_fort_checked}}}}} {tag_add _ufb_gun_fort_checked}}
  }
 }
  {"switch"
  {"case" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 0} {group
 {select {tag {tag _ufb_gun_deploy_%player}}}
 {include {prop {prop cannon_sandbag_small}}}
 {exclude {prop {prop no_sandbags}} {tag {tag _ufb_gun_fort_checked}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group
 {select {prop {prop human}} {prop {prop vehicle}}}
 {include {relation {relation enemy} {player "%player"}} {state {state operatable}}}
 {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop airborne}}}}} {distance {mode in_range} {min 0} {max 40}} {detection visible}}}
  {"default"
   {"switch"
    {"case" {condition {type rand} {value 0.6}}
     {"effect" {selector {source advanced} {ignore_captured_by_user 0} {group
 {select {tag {tag _ufb_gun_deploy_%player}}}
 {include {prop {prop cannon_sandbag_small}}}
 {exclude {prop {prop no_sandbags}} {tag {tag _ufb_gun_fort_checked}}}}} {effect construction_sandbag_cannon_shallow_ai}}
     {"con" {text "[UFB gun] bot sandbags small: player %player"}}
    }
   }
   {"entity_state" {selector {source advanced} {ignore_captured_by_user 0} {group
 {select {tag {tag _ufb_gun_deploy_%player}}}
 {include {prop {prop cannon_sandbag_small}}}
 {exclude {prop {prop no_sandbags}} {tag {tag _ufb_gun_fort_checked}}}}} {tag_add _ufb_gun_fort_checked}}
  }
 }
  {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_gun_deploy_%player}} {tag_remove _ufb_gun_deploy_%player}}
  {"delay" {time 2}}
{"trigger" {name "ufb/gun/deploy mortar %player"}}
 }
}
{"ufb/gun/release %player"
 {condition {expression "1 & !2"} {terms {"1.entities" {selector {source advanced} {ignore_captured_by_user 0} {group
 {select {tag {tag _ufb_gun_deployed}}}
 {include {player {player "%player"}}}
 {exclude {state {state dead}} {state {state inactive}}}}}} {"2.see_actors" {selector {source advanced} {ignore_captured_by_user 0} {group
 {select {tag {tag _ufb_gun_deployed}}}
 {include {player {player "%player"}}}
 {exclude {state {state dead}} {state {state inactive}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group
 {select {prop {prop human}} {prop {prop vehicle}}}
 {include {relation {relation enemy} {player "%player"}} {state {state operatable}}}
 {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop airborne}}}}} {distance {mode in_range} {min 0} {max 240}} {detection visible}}}}
 {actions
  {"delay" {time 30}}
  {"if" {condition {type entities} {selector {source advanced} {ignore_captured_by_user 0} {group
 {select {tag {tag _ufb_gun_deployed}}}
 {include {player {player "%player"}}}
 {exclude {state {state dead}} {state {state inactive}}}}}}
   {"switch"
    {"case" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 0} {group
 {select {tag {tag _ufb_gun_deployed}}}
 {include {player {player "%player"}}}
 {exclude {state {state dead}} {state {state inactive}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group
 {select {prop {prop human}} {prop {prop vehicle}}}
 {include {relation {relation enemy} {player "%player"}} {state {state operatable}}}
 {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop airborne}}}}} {distance {mode in_range} {min 0} {max 240}} {detection visible}}}
    {"default"
     {"actor_state" {selector {source advanced} {ignore_captured_by_user 0} {group
 {select {tag {tag _ufb_gun_deployed}}}
 {include {player {player "%player"}}}
 {exclude {state {state dead}} {state {state inactive}}}}} {drop orders} {move_mode free} {cannon move}}
     {"entity_state" {selector {source advanced} {ignore_captured_by_user 0} {group
 {select {tag {tag _ufb_gun_deployed}}}
 {include {player {player "%player"}}}
 {exclude {state {state dead}} {state {state inactive}}}}} {tag_remove _lua_mi}}
     {"entity_state" {selector {source advanced} {ignore_captured_by_user 0} {group
 {select {tag {tag _ufb_gun_deployed}}}
 {include {player {player "%player"}}}
 {exclude {state {state dead}} {state {state inactive}}}}} {tag_remove _ufb_gun_deployed}}
     {"con" {text "[UFB gun] bot packs up, no enemy in sight: player %player"}}
    }
   }
  }
  {"delay" {time 5}}
{"trigger" {name "ufb/gun/release %player"}}
 }
}
{"ufb/fear/tank %player"
 {condition {terms {"1.see_actors" {selector {source advanced} {ignore_captured_by_user 1} {group
 {select {prop {prop human}}}
 {include {player {player "%player"}} {state {state operatable}}}
 {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {state {state user_control}} {prop {prop crew}} {prop {prop repairing}} {prop {prop throwing}}
 {tag {tag _lua_mi}} {tag {tag _lua_ignore}} {tag {tag _ai_do_not_disturb}} {tag {tag repairing}} {tag {tag reloading}} {tag {tag bleeding}} {tag {tag _bleeding}} {tag {tag wounded}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag medic}} {tag {tag _ai_medic}} {tag {tag bot_medic}} {tag {tag _ufb_healing_active}} {tag {tag _ai_wounded_carrier}} {tag {tag _ai_ap_grenade}} {tag {tag _ai_at_grenade}} {tag {tag _ai_smoke_grenade}} {tag {tag _ai_suppressed_by_mg}} {tag {tag _ai_mgunner}} {tag {tag _ai_reloading}} {tag {tag _ai_looting_weapon}} {tag {tag crew}} {tag {tag tcrew}} {tag {tag ecrew}} {tag {tag ecrew_a}} {tag {tag ecrew_b}} {tag {tag bot_arty}} {tag {tag bot_aa_guard}} {tag {tag _ufb_crew_safe}} {tag {tag _ufb_hf_cover_active}} {tag {tag _ai_wirecutter_in_action}} {tag {tag bot_inf_flank_in_progress}} {tag {tag _ufb_smoke_120m_actor}} {tag {tag _ufb_smoke_60m_actor}} {tag {tag _ufb_smoke_wirecutter_actor}} {tag {tag _ai_at_launcher_30}} {tag {tag _ai_at_launcher_40}} {tag {tag _ai_at_launcher_50}} {tag {tag _ai_at_launcher_60}} {tag {tag _ai_at_launcher_70}} {tag {tag _ai_at_launcher_80}} {tag {tag _ai_at_launcher_90}} {tag {tag _ufb_combat_busy}} {tag {tag _ufb_job_reserved}} {tag {tag _ufb_tank_fear}}
 {with_item {type existance} {item "rocketlauncher"}} {with_item {type existance} {item "at"}} {with_item {type existance} {item "at_rifle"}} {with_item {type existance} {item "flame"}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group
 {select {prop {prop tank}} {prop {prop armored_car}}}
 {include {relation {relation enemy} {player "%player"}} {state {state operatable}} }
 {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop airborne}}}}} {distance {mode in_range} {min 0} {max 30}} {detection visible} {tag {"tag pair"} {"for selector" _ufb_tank_fear_new_%player}}}}}
 {actions
  {"effect" {selector {ignore_captured_by_user 0} {tag _ufb_tank_fear_new_%player}} {effect ufb_tank_fear}}
  {"actor_to_cover" {selector {ignore_captured_by_user 0} {tag _ufb_tank_fear_new_%player}} {drop orders}}
  {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_tank_fear_new_%player}} {tag_remove _ufb_tank_fear_new_%player}}
  {"delay" {time 3}}
{"trigger" {name "ufb/fear/tank %player"}}
 }
}
)
("ufb_static_weapons" player(0))
("ufb_static_weapons" player(1))
("ufb_static_weapons" player(2))
("ufb_static_weapons" player(3))
("ufb_static_weapons" player(4))
("ufb_static_weapons" player(5))
("ufb_static_weapons" player(6))
("ufb_static_weapons" player(7))
("ufb_static_weapons" player(8))
("ufb_static_weapons" player(9))
("ufb_static_weapons" player(10))
("ufb_static_weapons" player(11))
("ufb_static_weapons" player(12))
("ufb_static_weapons" player(13))
("ufb_static_weapons" player(14))
("ufb_static_weapons" player(15))
("ufb_static_weapons" player(16))
