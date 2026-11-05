; UFB stationary weapons. See tools/static-weapons.cjs.
{"ufb/morale/profile"
 {condition {terms {"1.entities" {selector {source advanced} {ignore_captured_by_user 0} {group
 {select {prop {prop human}}}
 {include {prop {prop human}} {state {state operatable}}}
 {exclude {state {state user_control}} {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} {tag {tag _ufb_morale}}}}}}}}
 {actions
  {"actor_state" {selector {source advanced} {ignore_captured_by_user 0} {group
 {select {prop {prop human}}}
 {include {prop {prop human}} {state {state operatable}}}
 {exclude {state {state user_control}} {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} {tag {tag _ufb_morale}}}}} {ai {retreat_ratio "2.2"}}}
  {"entity_state" {selector {source advanced} {ignore_captured_by_user 0} {group
 {select {prop {prop human}}}
 {include {prop {prop human}} {state {state operatable}}}
 {exclude {state {state user_control}} {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} {tag {tag _ufb_morale}}}}} {tag_add _ufb_morale}}
  {"delay" {time 3}}
{"trigger" {name "ufb/morale/profile"}}
 }
}
{"ufb/morale/shaken"
 {condition {terms {"1.entities" {selector {source advanced} {ignore_captured_by_user 0} {group
 {select {tag {tag _ufb_recent_hit}}}
 {include {prop {prop human}} {state {state operatable}}}
 {exclude {state {state user_control}} {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} {tag {tag _ufb_shaken}}}}}}}}
 {actions
  {"actor_state" {selector {source advanced} {ignore_captured_by_user 0} {group
 {select {tag {tag _ufb_recent_hit}}}
 {include {prop {prop human}} {state {state operatable}}}
 {exclude {state {state user_control}} {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} {tag {tag _ufb_shaken}}}}} {ai {retreat_ratio "1.4"}}}
  {"effect" {selector {source advanced} {ignore_captured_by_user 0} {group
 {select {tag {tag _ufb_recent_hit}}}
 {include {prop {prop human}} {state {state operatable}}}
 {exclude {state {state user_control}} {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} {tag {tag _ufb_shaken}}}}} {effect ufb_shaken}}
  {"delay" {time 3}}
{"trigger" {name "ufb/morale/shaken"}}
 }
}
{"ufb/morale/steady"
 {condition {terms {"1.entities" {selector {source advanced} {ignore_captured_by_user 0} {group
 {select {tag {tag _ufb_steady}}}
 {include {prop {prop human}} {state {state operatable}}}
 {exclude {state {state user_control}} {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} }}}}}}
 {actions
  {"actor_state" {selector {source advanced} {ignore_captured_by_user 0} {group
 {select {tag {tag _ufb_steady}}}
 {include {prop {prop human}} {state {state operatable}}}
 {exclude {state {state user_control}} {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop crew}} }}} {ai {retreat_ratio "2.2"}}}
  {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_steady}} {tag_remove _ufb_shaken}}
  {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_steady}} {tag_remove _ufb_steady}}
  {"delay" {time 3}}
{"trigger" {name "ufb/morale/steady"}}
 }
}
(define "ufb_surrender_claim"
 {"ufb/surrender/claim %player"
  {condition {terms {"1.see_actors"
   {selector {source advanced} {ignore_captured_by_user 0} {group {select {tag {tag _ufb_prisoner_unclaimed}}} {exclude {state {state dead}} {state {state inactive}}}}}
   {enemy {source advanced} {ignore_captured_by_user 0} {group {select {prop {prop human}}} {include {player {player "%player"}} {state {state user_control}} {state {state operatable}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}}
   {distance {mode in_range} {min 0} {max 25}}
   {tag {"tag pair"} {"for selector" _ufb_prisoner_mine_%player}}
  }}}
  {actions
   {"player" {selector {ignore_captured_by_user 0} {tag _ufb_prisoner_mine_%player}} {operation set} {player "%player"}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_prisoner_mine_%player}} {tag_remove _ufb_prisoner_unclaimed}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_prisoner_mine_%player}} {tag_remove _ufb_prisoner_mine_%player}}
   {"delay" {time 0.5}}
{"trigger" {name "ufb/surrender/claim %player"}}
  }
 }
)
(define "ufb_static_weapons"
{"ufb/gun/abandon light %team"
 {condition {terms {"1.see_actors" {selector {source advanced} {ignore_captured_by_user 1} {group
 {select {prop {prop mg_stan}} {prop {prop mortar}}}
 {include {team {team %team}} {prop {prop cannon}} {state {state operatable}} {state {state inhabited}}}
 {exclude {prop {prop bunker}} {prop {prop hatch}} {prop {prop muzzle_20mm_25mm_auto}} {state {state dead}} {state {state inactive}} {state {state linked}} {tag {tag _ufb_gun_left_%team}} {prop {prop muzzle_hmg}} {prop {prop muzzle_hmg_dshk}} {prop {prop muzzle_hmg_m2hb}} {prop {prop c_mg_heavy}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group
 {select {prop {prop tank}} {prop {prop armored_car}}}
 {include {team {team %foe}} {state {state operatable}} }
 {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop airborne}}}}} {distance {mode in_range} {min 0} {max 80}} {detection visible} {tag {"tag pair"} {"for selector" _ufb_gun_flee_%team}}}}}
 {actions
  {"effect" {selector {ignore_captured_by_user 0} {tag _ufb_gun_flee_%team}} {effect emit_crew}}
  {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_gun_flee_%team}} {tag_add _ufb_gun_left_%team}}
  {"entity_state" {selector {source advanced} {ignore_captured_by_user 0} {group {select {tag {tag _ufb_gun_flee_%team}}} {exclude {state {state user_control}}}}} {tag_add _ufb_gun_return_%team}}
  {"con" {text "[UFB gun] crew abandons light gun: team %team"}}
  {"delay" {time 6}}
  {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_gun_flee_%team}} {tag_remove _ufb_gun_flee_%team}}
  {"delay" {time 2}}
{"trigger" {name "ufb/gun/abandon light %team"}}
 }
}
{"ufb/gun/abandon heavy %team"
 {condition {terms {"1.see_actors" {selector {source advanced} {ignore_captured_by_user 1} {group
 {select {prop {prop muzzle_hmg}} {prop {prop muzzle_hmg_dshk}} {prop {prop muzzle_hmg_m2hb}} {prop {prop c_mg_heavy}}}
 {include {team {team %team}} {prop {prop cannon}} {state {state operatable}} {state {state inhabited}}}
 {exclude {prop {prop bunker}} {prop {prop hatch}} {prop {prop muzzle_20mm_25mm_auto}} {state {state dead}} {state {state inactive}} {state {state linked}} {tag {tag _ufb_gun_left_%team}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group
 {select {prop {prop medium}} {prop {prop heavy}}}
 {include {team {team %foe}} {state {state operatable}} {prop {prop with_gun}}}
 {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop airborne}}}}} {distance {mode in_range} {min 0} {max 80}} {detection visible} {tag {"tag pair"} {"for selector" _ufb_gun_flee_%team}}}}}
 {actions
  {"effect" {selector {ignore_captured_by_user 0} {tag _ufb_gun_flee_%team}} {effect emit_crew}}
  {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_gun_flee_%team}} {tag_add _ufb_gun_left_%team}}
  {"entity_state" {selector {source advanced} {ignore_captured_by_user 0} {group {select {tag {tag _ufb_gun_flee_%team}}} {exclude {state {state user_control}}}}} {tag_add _ufb_gun_return_%team}}
  {"con" {text "[UFB gun] crew abandons heavy gun: team %team"}}
  {"delay" {time 6}}
  {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_gun_flee_%team}} {tag_remove _ufb_gun_flee_%team}}
  {"delay" {time 2}}
{"trigger" {name "ufb/gun/abandon heavy %team"}}
 }
}
{"ufb/gun/crew %team"
 {condition {terms {"1.see_actors" {selector {source advanced} {ignore_captured_by_user 1} {group
 {select {prop {prop human}}}
 {include {team {team %team}} {state {state operatable}}}
 {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {tag {tag _ufb_gun_crew_%team}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group {select {tag {tag _ufb_gun_flee_%team}}}}}
  {distance {mode near_than} {meters 7}}
  {tag {"tag pair"} {"for selector" _ufb_gun_crew_new_%team}}
 }}}
 {actions
  {"effect" {selector {ignore_captured_by_user 0} {tag _ufb_gun_crew_new_%team}} {effect ufb_gun_flee_%team}}
  {"delay" {time 0.2}}
  {"action" {selector {ignore_captured_by_user 0} {tag _ufb_gun_crew_new_%team}} {drop "orders sensor senseless"} {action move}
   {target {ignore_captured_by_user 0} {tag _ufb_gun_flee_point_%team}}}
  {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_gun_crew_new_%team}} {tag_remove _ufb_gun_crew_new_%team}}
  {"delay" {time 0.5}}
{"trigger" {name "ufb/gun/crew %team"}}
 }
}
{"ufb/gun/cover %team"
 {condition {terms {"1.entities" {selector {ignore_captured_by_user 0} {tag _ufb_gun_cover_%team}}}}}
 {actions
  {"actor_to_cover" {selector {ignore_captured_by_user 0} {tag _ufb_gun_cover_%team}} {drop orders}}
  {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_gun_cover_%team}} {tag_remove _ufb_gun_cover_%team}}
  {"delay" {time 2}}
{"trigger" {name "ufb/gun/cover %team"}}
 }
}
{"ufb/gun/rearm %team"
 {condition {terms {"1.entities" {selector {ignore_captured_by_user 0} {tag _ufb_gun_left_%team}}}}}
 {actions
  {"delay" {time 60}}
  {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_gun_left_%team}} {tag_remove _ufb_gun_left_%team}}
  {"delay" {time 1}}
{"trigger" {name "ufb/gun/rearm %team"}}
 }
}
{"ufb/gun/deploy mg %team"
 {condition {terms {"1.see_actors" {selector {source advanced} {ignore_captured_by_user 0} {group
 {select {prop {prop mg_stan}}}
 {include {team {team %team}} {prop {prop cannon}} {state {state operatable}} {state {state inhabited}}}
 {exclude {state {state user_control}} {prop {prop fixed}} {tag {tag _lua_mi}} {tag {tag bot_arty}} {tag {tag _ufb_gun_deployed}} {tag {tag _ufb_gun_left_%team}} {prop {prop bunker}} {prop {prop hatch}} {prop {prop muzzle_20mm_25mm_auto}} {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop mortar}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group
 {select {prop {prop human}} {prop {prop vehicle}}}
 {include {team {team %foe}} {state {state operatable}}}
 {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop airborne}}}}} {distance {mode in_range} {min 40} {max 130}} {detection visible} {tag {"tag pair"} {"for selector" _ufb_gun_deploy_%team}}}}}
 {actions
  {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_gun_deploy_%team}} {tag_add _ufb_gun_deployed}}
  {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_gun_deploy_%team}} {tag_add _lua_mi}}
  {"actor_state" {selector {ignore_captured_by_user 0} {tag _ufb_gun_deploy_%team}} {drop orders} {move_mode hold} {cannon fire}}
  {"con" {text "[UFB gun] bot deploys mg: team %team"}}
  {"delay" {time 4}}
  {"switch"
  {"case" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 0} {group
 {select {tag {tag _ufb_gun_deploy_%team}}}
 {include {prop {prop cannon_sandbag_standard}}}
 {exclude {prop {prop no_sandbags}} {tag {tag _ufb_gun_fort_checked}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group
 {select {prop {prop human}} {prop {prop vehicle}}}
 {include {team {team %foe}} {state {state operatable}}}
 {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop airborne}}}}} {distance {mode in_range} {min 0} {max 40}} {detection visible}}}
  {"default"
   {"switch"
    {"case" {condition {type rand} {value 0.6}}
     {"effect" {selector {source advanced} {ignore_captured_by_user 0} {group
 {select {tag {tag _ufb_gun_deploy_%team}}}
 {include {prop {prop cannon_sandbag_standard}}}
 {exclude {prop {prop no_sandbags}} {tag {tag _ufb_gun_fort_checked}}}}} {effect construction_sandbag_cannon_standard_ai}}
     {"con" {text "[UFB gun] bot sandbags standard: team %team"}}
    }
   }
   {"entity_state" {selector {source advanced} {ignore_captured_by_user 0} {group
 {select {tag {tag _ufb_gun_deploy_%team}}}
 {include {prop {prop cannon_sandbag_standard}}}
 {exclude {prop {prop no_sandbags}} {tag {tag _ufb_gun_fort_checked}}}}} {tag_add _ufb_gun_fort_checked}}
  }
 }
  {"switch"
  {"case" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 0} {group
 {select {tag {tag _ufb_gun_deploy_%team}}}
 {include {prop {prop cannon_sandbag_small}}}
 {exclude {prop {prop no_sandbags}} {tag {tag _ufb_gun_fort_checked}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group
 {select {prop {prop human}} {prop {prop vehicle}}}
 {include {team {team %foe}} {state {state operatable}}}
 {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop airborne}}}}} {distance {mode in_range} {min 0} {max 40}} {detection visible}}}
  {"default"
   {"switch"
    {"case" {condition {type rand} {value 0.6}}
     {"effect" {selector {source advanced} {ignore_captured_by_user 0} {group
 {select {tag {tag _ufb_gun_deploy_%team}}}
 {include {prop {prop cannon_sandbag_small}}}
 {exclude {prop {prop no_sandbags}} {tag {tag _ufb_gun_fort_checked}}}}} {effect construction_sandbag_cannon_shallow_ai}}
     {"con" {text "[UFB gun] bot sandbags small: team %team"}}
    }
   }
   {"entity_state" {selector {source advanced} {ignore_captured_by_user 0} {group
 {select {tag {tag _ufb_gun_deploy_%team}}}
 {include {prop {prop cannon_sandbag_small}}}
 {exclude {prop {prop no_sandbags}} {tag {tag _ufb_gun_fort_checked}}}}} {tag_add _ufb_gun_fort_checked}}
  }
 }
  {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_gun_deploy_%team}} {tag_remove _ufb_gun_deploy_%team}}
  {"delay" {time 2}}
{"trigger" {name "ufb/gun/deploy mg %team"}}
 }
}
{"ufb/gun/deploy mortar %team"
 {condition {terms {"1.see_actors" {selector {source advanced} {ignore_captured_by_user 0} {group
 {select {prop {prop mortar}}}
 {include {team {team %team}} {prop {prop cannon}} {state {state operatable}} {state {state inhabited}}}
 {exclude {state {state user_control}} {prop {prop fixed}} {tag {tag _lua_mi}} {tag {tag bot_arty}} {tag {tag _ufb_gun_deployed}} {tag {tag _ufb_gun_left_%team}} {prop {prop bunker}} {prop {prop hatch}} {prop {prop muzzle_20mm_25mm_auto}} {state {state dead}} {state {state inactive}} {state {state linked}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group
 {select {prop {prop human}} {prop {prop vehicle}}}
 {include {team {team %foe}} {state {state operatable}}}
 {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop airborne}}}}} {distance {mode in_range} {min 60} {max 240}} {detection visible} {tag {"tag pair"} {"for selector" _ufb_gun_deploy_%team}}}}}
 {actions
  {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_gun_deploy_%team}} {tag_add _ufb_gun_deployed}}
  {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_gun_deploy_%team}} {tag_add _lua_mi}}
  {"actor_state" {selector {ignore_captured_by_user 0} {tag _ufb_gun_deploy_%team}} {drop orders} {move_mode hold} {cannon fire}}
  {"con" {text "[UFB gun] bot deploys mortar: team %team"}}
  {"delay" {time 4}}
  {"switch"
  {"case" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 0} {group
 {select {tag {tag _ufb_gun_deploy_%team}}}
 {include {prop {prop cannon_sandbag_standard}}}
 {exclude {prop {prop no_sandbags}} {tag {tag _ufb_gun_fort_checked}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group
 {select {prop {prop human}} {prop {prop vehicle}}}
 {include {team {team %foe}} {state {state operatable}}}
 {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop airborne}}}}} {distance {mode in_range} {min 0} {max 40}} {detection visible}}}
  {"default"
   {"switch"
    {"case" {condition {type rand} {value 0.6}}
     {"effect" {selector {source advanced} {ignore_captured_by_user 0} {group
 {select {tag {tag _ufb_gun_deploy_%team}}}
 {include {prop {prop cannon_sandbag_standard}}}
 {exclude {prop {prop no_sandbags}} {tag {tag _ufb_gun_fort_checked}}}}} {effect construction_sandbag_cannon_standard_ai}}
     {"con" {text "[UFB gun] bot sandbags standard: team %team"}}
    }
   }
   {"entity_state" {selector {source advanced} {ignore_captured_by_user 0} {group
 {select {tag {tag _ufb_gun_deploy_%team}}}
 {include {prop {prop cannon_sandbag_standard}}}
 {exclude {prop {prop no_sandbags}} {tag {tag _ufb_gun_fort_checked}}}}} {tag_add _ufb_gun_fort_checked}}
  }
 }
  {"switch"
  {"case" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 0} {group
 {select {tag {tag _ufb_gun_deploy_%team}}}
 {include {prop {prop cannon_sandbag_small}}}
 {exclude {prop {prop no_sandbags}} {tag {tag _ufb_gun_fort_checked}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group
 {select {prop {prop human}} {prop {prop vehicle}}}
 {include {team {team %foe}} {state {state operatable}}}
 {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop airborne}}}}} {distance {mode in_range} {min 0} {max 40}} {detection visible}}}
  {"default"
   {"switch"
    {"case" {condition {type rand} {value 0.6}}
     {"effect" {selector {source advanced} {ignore_captured_by_user 0} {group
 {select {tag {tag _ufb_gun_deploy_%team}}}
 {include {prop {prop cannon_sandbag_small}}}
 {exclude {prop {prop no_sandbags}} {tag {tag _ufb_gun_fort_checked}}}}} {effect construction_sandbag_cannon_shallow_ai}}
     {"con" {text "[UFB gun] bot sandbags small: team %team"}}
    }
   }
   {"entity_state" {selector {source advanced} {ignore_captured_by_user 0} {group
 {select {tag {tag _ufb_gun_deploy_%team}}}
 {include {prop {prop cannon_sandbag_small}}}
 {exclude {prop {prop no_sandbags}} {tag {tag _ufb_gun_fort_checked}}}}} {tag_add _ufb_gun_fort_checked}}
  }
 }
  {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_gun_deploy_%team}} {tag_remove _ufb_gun_deploy_%team}}
  {"delay" {time 2}}
{"trigger" {name "ufb/gun/deploy mortar %team"}}
 }
}
{"ufb/gun/deploy at %team"
 {condition {terms {"1.see_actors" {selector {source advanced} {ignore_captured_by_user 0} {group
 {select {prop {prop sq_at_gun}} {prop {prop sq_at_light}}}
 {include {team {team %team}} {prop {prop cannon}} {state {state operatable}} {state {state inhabited}}}
 {exclude {state {state user_control}} {prop {prop fixed}} {tag {tag _lua_mi}} {tag {tag bot_arty}} {tag {tag _ufb_gun_deployed}} {tag {tag _ufb_gun_left_%team}} {prop {prop bunker}} {prop {prop hatch}} {prop {prop muzzle_20mm_25mm_auto}} {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop mg_stan}} {prop {prop mortar}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group
 {select {prop {prop human}} {prop {prop vehicle}}}
 {include {team {team %foe}} {state {state operatable}}}
 {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop airborne}}}}} {distance {mode in_range} {min 60} {max 220}} {detection visible} {tag {"tag pair"} {"for selector" _ufb_gun_deploy_%team}}}}}
 {actions
  {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_gun_deploy_%team}} {tag_add _ufb_gun_deployed}}
  {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_gun_deploy_%team}} {tag_add _lua_mi}}
  {"actor_state" {selector {ignore_captured_by_user 0} {tag _ufb_gun_deploy_%team}} {drop orders} {move_mode hold} {cannon fire}}
  {"con" {text "[UFB gun] bot deploys at: team %team"}}
  {"delay" {time 4}}
  {"switch"
  {"case" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 0} {group
 {select {tag {tag _ufb_gun_deploy_%team}}}
 {include {prop {prop cannon_sandbag_standard}}}
 {exclude {prop {prop no_sandbags}} {tag {tag _ufb_gun_fort_checked}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group
 {select {prop {prop human}} {prop {prop vehicle}}}
 {include {team {team %foe}} {state {state operatable}}}
 {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop airborne}}}}} {distance {mode in_range} {min 0} {max 40}} {detection visible}}}
  {"default"
   {"switch"
    {"case" {condition {type rand} {value 0.6}}
     {"effect" {selector {source advanced} {ignore_captured_by_user 0} {group
 {select {tag {tag _ufb_gun_deploy_%team}}}
 {include {prop {prop cannon_sandbag_standard}}}
 {exclude {prop {prop no_sandbags}} {tag {tag _ufb_gun_fort_checked}}}}} {effect construction_sandbag_cannon_standard_ai}}
     {"con" {text "[UFB gun] bot sandbags standard: team %team"}}
    }
   }
   {"entity_state" {selector {source advanced} {ignore_captured_by_user 0} {group
 {select {tag {tag _ufb_gun_deploy_%team}}}
 {include {prop {prop cannon_sandbag_standard}}}
 {exclude {prop {prop no_sandbags}} {tag {tag _ufb_gun_fort_checked}}}}} {tag_add _ufb_gun_fort_checked}}
  }
 }
  {"switch"
  {"case" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 0} {group
 {select {tag {tag _ufb_gun_deploy_%team}}}
 {include {prop {prop cannon_sandbag_small}}}
 {exclude {prop {prop no_sandbags}} {tag {tag _ufb_gun_fort_checked}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group
 {select {prop {prop human}} {prop {prop vehicle}}}
 {include {team {team %foe}} {state {state operatable}}}
 {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop airborne}}}}} {distance {mode in_range} {min 0} {max 40}} {detection visible}}}
  {"default"
   {"switch"
    {"case" {condition {type rand} {value 0.6}}
     {"effect" {selector {source advanced} {ignore_captured_by_user 0} {group
 {select {tag {tag _ufb_gun_deploy_%team}}}
 {include {prop {prop cannon_sandbag_small}}}
 {exclude {prop {prop no_sandbags}} {tag {tag _ufb_gun_fort_checked}}}}} {effect construction_sandbag_cannon_shallow_ai}}
     {"con" {text "[UFB gun] bot sandbags small: team %team"}}
    }
   }
   {"entity_state" {selector {source advanced} {ignore_captured_by_user 0} {group
 {select {tag {tag _ufb_gun_deploy_%team}}}
 {include {prop {prop cannon_sandbag_small}}}
 {exclude {prop {prop no_sandbags}} {tag {tag _ufb_gun_fort_checked}}}}} {tag_add _ufb_gun_fort_checked}}
  }
 }
  {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_gun_deploy_%team}} {tag_remove _ufb_gun_deploy_%team}}
  {"delay" {time 2}}
{"trigger" {name "ufb/gun/deploy at %team"}}
 }
}
{"ufb/gun/return %team"
 {condition {expression "1 & 2 & !3"} {terms {"1.entities" {selector {source advanced} {ignore_captured_by_user 0} {group
 {select {tag {tag _ufb_gun_return_%team}}}
 {exclude {state {state inhabited}} {state {state dead}} {state {state inactive}} {tag {tag destroyed}} {tag {tag _no-recrew}}}}}} {"2.entities" {selector {source advanced} {ignore_captured_by_user 1} {group
 {select {tag {tag _ufb_gun_back_%team}}}
 {include {state {state operatable}}}
 {exclude {state {state user_control}} {state {state dead}} {state {state inactive}} {state {state linked}} {tag {tag repairing}}}}}} {"3.see_actors" {selector {source advanced} {ignore_captured_by_user 1} {group
 {select {tag {tag _ufb_gun_back_%team}}}
 {include {state {state operatable}}}
 {exclude {state {state user_control}} {state {state dead}} {state {state inactive}} {state {state linked}} {tag {tag repairing}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group
 {select {prop {prop tank}} {prop {prop armored_car}}}
 {include {team {team %foe}} {state {state operatable}} }
 {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop airborne}}}}} {distance {mode in_range} {min 0} {max 110}} {detection visible}}}}
 {actions
  {"delay" {time 15}}
  {"switch"
   {"case" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {group
 {select {tag {tag _ufb_gun_back_%team}}}
 {include {state {state operatable}}}
 {exclude {state {state user_control}} {state {state dead}} {state {state inactive}} {state {state linked}} {tag {tag repairing}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group
 {select {prop {prop tank}} {prop {prop armored_car}}}
 {include {team {team %foe}} {state {state operatable}} }
 {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop airborne}}}}} {distance {mode in_range} {min 0} {max 110}} {detection visible}}}
   {"default"
    {"board" {selector {source advanced} {ignore_captured_by_user 1} {group
 {select {tag {tag _ufb_gun_back_%team}}}
 {include {state {state operatable}}}
 {exclude {state {state user_control}} {state {state dead}} {state {state inactive}} {state {state linked}} {tag {tag repairing}}}}} {vehicle {source advanced} {ignore_captured_by_user 0} {group
 {select {tag {tag _ufb_gun_return_%team}}}
 {exclude {state {state inhabited}} {state {state dead}} {state {state inactive}} {tag {tag destroyed}} {tag {tag _no-recrew}}}} {amount 1}}}
    {"con" {text "[UFB gun] bot crew returns to its gun: team %team"}}
    {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_gun_back_%team}} {tag_remove _ufb_gun_back_%team}}
    {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_gun_return_%team}} {tag_remove _ufb_gun_return_%team}}
   }
  }
  {"delay" {time 5}}
{"trigger" {name "ufb/gun/return %team"}}
 }
}
{"ufb/tank/bail %team"
 {condition {terms {"1.see_actors" {selector {source advanced} {ignore_captured_by_user 1} {group
 {select {prop {prop tank}}}
 {include {team {team %team}} {state {state inhabited}} {tag {tag gun_broken}}}
 {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {state {state chassis_work}} {tag {tag _ufb_tank_bailed}} {tag {tag burned}} {tag {tag ammo_broken}} {tag {tag ammo_cooked}} {tag {tag barrel_fire}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group
 {select {prop {prop human}} {prop {prop vehicle}}}
 {include {team {team %foe}} {state {state operatable}}}
 {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop airborne}}}}} {distance {mode in_range} {min 0} {max 200}} {detection visible}}}}
 {actions
  {"delay" {time 20}}
  {"if" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {group
 {select {prop {prop tank}}}
 {include {team {team %team}} {state {state inhabited}} {tag {tag gun_broken}}}
 {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {state {state chassis_work}} {tag {tag _ufb_tank_bailed}} {tag {tag burned}} {tag {tag ammo_broken}} {tag {tag ammo_cooked}} {tag {tag barrel_fire}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group
 {select {prop {prop human}} {prop {prop vehicle}}}
 {include {team {team %foe}} {state {state operatable}}}
 {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop airborne}}}}} {distance {mode in_range} {min 0} {max 200}} {detection visible}}
   {"entity_state" {selector {source advanced} {ignore_captured_by_user 1} {group
 {select {prop {prop tank}}}
 {include {team {team %team}} {state {state inhabited}} {tag {tag gun_broken}}}
 {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {state {state chassis_work}} {tag {tag _ufb_tank_bailed}} {tag {tag burned}} {tag {tag ammo_broken}} {tag {tag ammo_cooked}} {tag {tag barrel_fire}}}}} {tag_add _ufb_tank_bail_%team}}
   {"effect" {selector {ignore_captured_by_user 0} {tag _ufb_tank_bail_%team}} {effect emit_crew}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_tank_bail_%team}} {tag_add _ufb_tank_bailed}}
   {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_tank_bail_%team}} {tag_remove _ufb_tank_bail_%team}}
   {"con" {text "[UFB tank] crew bails out: team %team"}}
  }
  {"delay" {time 3}}
{"trigger" {name "ufb/tank/bail %team"}}
 }
}
{"ufb/fear/blast %team"
 {condition {terms {"1.entities" {selector {source advanced} {ignore_captured_by_user 1} {group
 {select {tag {tag _ufb_blast_new}}}
 {include {team {team %team}} {state {state operatable}}}
 {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {state {state user_control}} {prop {prop crew}} {prop {prop repairing}} {prop {prop throwing}}
 {tag {tag _lua_mi}} {tag {tag _lua_ignore}} {tag {tag _ai_do_not_disturb}} {tag {tag repairing}} {tag {tag reloading}} {tag {tag bleeding}} {tag {tag _bleeding}} {tag {tag wounded}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag medic}} {tag {tag _ai_medic}} {tag {tag bot_medic}} {tag {tag _ufb_healing_active}} {tag {tag _ai_wounded_carrier}} {tag {tag _ai_ap_grenade}} {tag {tag _ai_at_grenade}} {tag {tag _ai_smoke_grenade}} {tag {tag _ai_suppressed_by_mg}} {tag {tag _ai_mgunner}} {tag {tag _ai_reloading}} {tag {tag _ai_looting_weapon}} {tag {tag crew}} {tag {tag tcrew}} {tag {tag ecrew}} {tag {tag ecrew_a}} {tag {tag ecrew_b}} {tag {tag bot_arty}} {tag {tag bot_aa_guard}} {tag {tag _ufb_crew_safe}} {tag {tag _ufb_hf_cover_active}} {tag {tag _ai_wirecutter_in_action}} {tag {tag bot_inf_flank_in_progress}} {tag {tag _ufb_smoke_120m_actor}} {tag {tag _ufb_smoke_60m_actor}} {tag {tag _ufb_smoke_wirecutter_actor}} {tag {tag _ai_at_launcher_30}} {tag {tag _ai_at_launcher_40}} {tag {tag _ai_at_launcher_50}} {tag {tag _ai_at_launcher_60}} {tag {tag _ai_at_launcher_70}} {tag {tag _ai_at_launcher_80}} {tag {tag _ai_at_launcher_90}} {tag {tag _ufb_combat_busy}} {tag {tag _ufb_job_reserved}}}}}}}}
 {actions
  {"actor_to_cover" {selector {source advanced} {ignore_captured_by_user 1} {group
 {select {tag {tag _ufb_blast_new}}}
 {include {team {team %team}} {state {state operatable}}}
 {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {state {state user_control}} {prop {prop crew}} {prop {prop repairing}} {prop {prop throwing}}
 {tag {tag _lua_mi}} {tag {tag _lua_ignore}} {tag {tag _ai_do_not_disturb}} {tag {tag repairing}} {tag {tag reloading}} {tag {tag bleeding}} {tag {tag _bleeding}} {tag {tag wounded}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag medic}} {tag {tag _ai_medic}} {tag {tag bot_medic}} {tag {tag _ufb_healing_active}} {tag {tag _ai_wounded_carrier}} {tag {tag _ai_ap_grenade}} {tag {tag _ai_at_grenade}} {tag {tag _ai_smoke_grenade}} {tag {tag _ai_suppressed_by_mg}} {tag {tag _ai_mgunner}} {tag {tag _ai_reloading}} {tag {tag _ai_looting_weapon}} {tag {tag crew}} {tag {tag tcrew}} {tag {tag ecrew}} {tag {tag ecrew_a}} {tag {tag ecrew_b}} {tag {tag bot_arty}} {tag {tag bot_aa_guard}} {tag {tag _ufb_crew_safe}} {tag {tag _ufb_hf_cover_active}} {tag {tag _ai_wirecutter_in_action}} {tag {tag bot_inf_flank_in_progress}} {tag {tag _ufb_smoke_120m_actor}} {tag {tag _ufb_smoke_60m_actor}} {tag {tag _ufb_smoke_wirecutter_actor}} {tag {tag _ai_at_launcher_30}} {tag {tag _ai_at_launcher_40}} {tag {tag _ai_at_launcher_50}} {tag {tag _ai_at_launcher_60}} {tag {tag _ai_at_launcher_70}} {tag {tag _ai_at_launcher_80}} {tag {tag _ai_at_launcher_90}} {tag {tag _ufb_combat_busy}} {tag {tag _ufb_job_reserved}}}}} {drop orders}}
  {"entity_state" {selector {source advanced} {ignore_captured_by_user 1} {group
 {select {tag {tag _ufb_blast_new}}}
 {include {team {team %team}} {state {state operatable}}}
 {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {state {state user_control}} {prop {prop crew}} {prop {prop repairing}} {prop {prop throwing}}
 {tag {tag _lua_mi}} {tag {tag _lua_ignore}} {tag {tag _ai_do_not_disturb}} {tag {tag repairing}} {tag {tag reloading}} {tag {tag bleeding}} {tag {tag _bleeding}} {tag {tag wounded}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag medic}} {tag {tag _ai_medic}} {tag {tag bot_medic}} {tag {tag _ufb_healing_active}} {tag {tag _ai_wounded_carrier}} {tag {tag _ai_ap_grenade}} {tag {tag _ai_at_grenade}} {tag {tag _ai_smoke_grenade}} {tag {tag _ai_suppressed_by_mg}} {tag {tag _ai_mgunner}} {tag {tag _ai_reloading}} {tag {tag _ai_looting_weapon}} {tag {tag crew}} {tag {tag tcrew}} {tag {tag ecrew}} {tag {tag ecrew_a}} {tag {tag ecrew_b}} {tag {tag bot_arty}} {tag {tag bot_aa_guard}} {tag {tag _ufb_crew_safe}} {tag {tag _ufb_hf_cover_active}} {tag {tag _ai_wirecutter_in_action}} {tag {tag bot_inf_flank_in_progress}} {tag {tag _ufb_smoke_120m_actor}} {tag {tag _ufb_smoke_60m_actor}} {tag {tag _ufb_smoke_wirecutter_actor}} {tag {tag _ai_at_launcher_30}} {tag {tag _ai_at_launcher_40}} {tag {tag _ai_at_launcher_50}} {tag {tag _ai_at_launcher_60}} {tag {tag _ai_at_launcher_70}} {tag {tag _ai_at_launcher_80}} {tag {tag _ai_at_launcher_90}} {tag {tag _ufb_combat_busy}} {tag {tag _ufb_job_reserved}}}}} {tag_remove _ufb_blast_new}}
  {"delay" {time 0.5}}
{"trigger" {name "ufb/fear/blast %team"}}
 }
}
{"ufb/shout/mg %team"
 {condition {expression "1 | 2"} {terms
  {"1.see_actors" {selector {source advanced} {ignore_captured_by_user 0} {group
 {select {prop {prop human}}}
 {include {team {team %team}} {state {state operatable}}}
 {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group
 {select {prop {prop mg_stan}}}
 {include {team {team %foe}} {state {state operatable}} {state {state inhabited}}}
 {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {distance {mode in_range} {min 0} {max 130}} {detection visible} {tag {"tag pair"} {"for selector" _ufb_mg_shout_%team}}}
  {"2.see_actors" {selector {source advanced} {ignore_captured_by_user 0} {group
 {select {prop {prop human}}}
 {include {team {team %team}} {state {state operatable}}}
 {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group
 {select {prop {prop human}}}
 {include {team {team %foe}} {state {state operatable}} {with_item {type using} {item "mgun"}} {prop {prop shooting}}}
 {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {distance {mode in_range} {min 0} {max 130}} {detection visible} {tag {"tag pair"} {"for selector" _ufb_mg_shout_%team}}}
 }}
 {actions
  {"effect" {selector {amount 1} {ignore_captured_by_user 0} {tag _ufb_mg_shout_%team}} {effect ufb_mg_shout}}
  {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_mg_shout_%team}} {tag_remove _ufb_mg_shout_%team}}
  {"delay" {time 45}}
{"trigger" {name "ufb/shout/mg %team"}}
 }
}
{"ufb/surrender/mark %team"
 {condition {terms {"1.see_actors" {selector {source advanced} {ignore_captured_by_user 0} {group
 {select {tag {tag _ufb_was_hit}}}
 {include {prop {prop human}} {state {state operatable}} {team {team %foe}}}
 {exclude {state {state user_control}} {state {state dead}} {state {state inactive}} {state {state linked}} {tag {tag start_personage}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag _lua_mi}} {tag {tag _ufb_surrendered}} {tag {tag medic}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group
 {select {prop {prop human}}}
 {include {team {team %team}} {state {state user_control}} {state {state operatable}}}
 {exclude {state {state dead}} {state {state inactive}} {state {state linked}}}}} {distance {mode in_range} {min 0} {max 15}} {detection visible} {tag {"tag pair"} {"for selector" _ufb_surrender_%team}}}}}
 {actions
  {"delay" {time 2}}
  {"actor_state" {selector {ignore_captured_by_user 0} {tag _ufb_surrender_%team}} {drop orders} {fire_mode hold} {move_mode free} {ai_move {mode disable}} {movement {speed slow} {type normal}}}
  {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_surrender_%team}} {tag_add _ufb_surrendered}}
  {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_surrender_%team}} {tag_add _ufb_native_pickup_initialized}}
  {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_surrender_%team}} {tag_add _ufb_prisoner_unclaimed}}
  {"delay" {time 0.5}}
  {"inventory" {selector {ignore_captured_by_user 0} {tag _ufb_surrender_%team}} {action drop}}
  {"delay" {time 2}}
  {"actor_state" {selector {ignore_captured_by_user 0} {tag _ufb_surrender_%team}} {drop orders} {fire_mode hold} {move_mode free} {ai_move {mode disable}} {movement {speed slow} {type normal}}}
  {"delay" {time 0.5}}
  {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_surrender_%team}} {tag_add _ufb_prisoner}}
  {"if" {condition {type entities} {selector {ignore_captured_by_user 0} {tag _ufb_surrender_%team}}}
   {"con" {text "[UFB surrender] wounded soldier gives up to player %team"}}
  }
  {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_surrender_%team}} {tag_remove _ufb_surrender_%team}}
  {"delay" {time 4}}
{"trigger" {name "ufb/surrender/mark %team"}}
 }
}
{"ufb/surrender/hands %team"
 {condition {terms {"1.entities" {selector {source advanced} {ignore_captured_by_user 1} {group
 {select {tag {tag _ufb_prisoner}}}
 {include {team {team %team}} {state {state operatable}}}
 {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {tag {tag _ufb_autonomy_moving}}}}}}}}
 {actions
  {"animation" {selector {source advanced} {ignore_captured_by_user 1} {group
 {select {tag {tag _ufb_prisoner}}}
 {include {team {team %team}} {state {state operatable}}}
 {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {tag {tag _ufb_autonomy_moving}}}}} {collage stand_giveup_1} {cicledelay 0} {delay 0} {totalTime 6} {flags loop}}
  {"delay" {time 7}}
{"trigger" {name "ufb/surrender/hands %team"}}
 }
}
{"ufb/surrender/helped %team"
 {condition {terms {"1.see_actors" {selector {source advanced} {ignore_captured_by_user 0} {group {select {tag {tag _ufb_surrender_%team}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group
 {select {prop {prop human}} {prop {prop vehicle}}}
 {include {team {team %foe}} {state {state operatable}}}
 {exclude {state {state dead}} {state {state inactive}} {tag {tag _ufb_was_hit}}}}} {distance {mode in_range} {min 0} {max 25}} {tag {"tag pair"} {"for selector" _ufb_surrender_helped_%team}}}}}
 {actions
  {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_surrender_helped_%team}} {tag_remove _ufb_surrender_%team}}
  {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_surrender_helped_%team}} {tag_remove _ufb_surrender_helped_%team}}
  {"delay" {time 0.3}}
{"trigger" {name "ufb/surrender/helped %team"}}
 }
}
{"ufb/gun/release %team"
 {condition {expression "1 & !2"} {terms {"1.entities" {selector {source advanced} {ignore_captured_by_user 0} {group
 {select {tag {tag _ufb_gun_deployed}}}
 {include {team {team %team}}}
 {exclude {state {state dead}} {state {state inactive}}}}}} {"2.see_actors" {selector {source advanced} {ignore_captured_by_user 0} {group
 {select {tag {tag _ufb_gun_deployed}}}
 {include {team {team %team}}}
 {exclude {state {state dead}} {state {state inactive}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group
 {select {prop {prop human}} {prop {prop vehicle}}}
 {include {team {team %foe}} {state {state operatable}}}
 {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop airborne}}}}} {distance {mode in_range} {min 0} {max 240}} {detection visible}}}}
 {actions
  {"delay" {time 30}}
  {"if" {condition {type entities} {selector {source advanced} {ignore_captured_by_user 0} {group
 {select {tag {tag _ufb_gun_deployed}}}
 {include {team {team %team}}}
 {exclude {state {state dead}} {state {state inactive}}}}}}
   {"switch"
    {"case" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 0} {group
 {select {tag {tag _ufb_gun_deployed}}}
 {include {team {team %team}}}
 {exclude {state {state dead}} {state {state inactive}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group
 {select {prop {prop human}} {prop {prop vehicle}}}
 {include {team {team %foe}} {state {state operatable}}}
 {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop airborne}}}}} {distance {mode in_range} {min 0} {max 240}} {detection visible}}}
    {"default"
     {"actor_state" {selector {source advanced} {ignore_captured_by_user 0} {group
 {select {tag {tag _ufb_gun_deployed}}}
 {include {team {team %team}}}
 {exclude {state {state dead}} {state {state inactive}}}}} {drop orders} {move_mode free} {cannon move}}
     {"entity_state" {selector {source advanced} {ignore_captured_by_user 0} {group
 {select {tag {tag _ufb_gun_deployed}}}
 {include {team {team %team}}}
 {exclude {state {state dead}} {state {state inactive}}}}} {tag_remove _lua_mi}}
     {"entity_state" {selector {source advanced} {ignore_captured_by_user 0} {group
 {select {tag {tag _ufb_gun_deployed}}}
 {include {team {team %team}}}
 {exclude {state {state dead}} {state {state inactive}}}}} {tag_remove _ufb_gun_deployed}}
     {"con" {text "[UFB gun] bot packs up, no enemy in sight: team %team"}}
    }
   }
  }
  {"delay" {time 5}}
{"trigger" {name "ufb/gun/release %team"}}
 }
}
{"ufb/fear/tank %team"
 {condition {terms {"1.see_actors" {selector {source advanced} {ignore_captured_by_user 1} {group
 {select {prop {prop human}}}
 {include {team {team %team}} {state {state operatable}}}
 {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {state {state user_control}} {prop {prop crew}} {prop {prop repairing}} {prop {prop throwing}}
 {tag {tag _lua_mi}} {tag {tag _lua_ignore}} {tag {tag _ai_do_not_disturb}} {tag {tag repairing}} {tag {tag reloading}} {tag {tag bleeding}} {tag {tag _bleeding}} {tag {tag wounded}} {tag {tag _bleedout_}} {tag {tag wounded_animation_playing}} {tag {tag medic}} {tag {tag _ai_medic}} {tag {tag bot_medic}} {tag {tag _ufb_healing_active}} {tag {tag _ai_wounded_carrier}} {tag {tag _ai_ap_grenade}} {tag {tag _ai_at_grenade}} {tag {tag _ai_smoke_grenade}} {tag {tag _ai_suppressed_by_mg}} {tag {tag _ai_mgunner}} {tag {tag _ai_reloading}} {tag {tag _ai_looting_weapon}} {tag {tag crew}} {tag {tag tcrew}} {tag {tag ecrew}} {tag {tag ecrew_a}} {tag {tag ecrew_b}} {tag {tag bot_arty}} {tag {tag bot_aa_guard}} {tag {tag _ufb_crew_safe}} {tag {tag _ufb_hf_cover_active}} {tag {tag _ai_wirecutter_in_action}} {tag {tag bot_inf_flank_in_progress}} {tag {tag _ufb_smoke_120m_actor}} {tag {tag _ufb_smoke_60m_actor}} {tag {tag _ufb_smoke_wirecutter_actor}} {tag {tag _ai_at_launcher_30}} {tag {tag _ai_at_launcher_40}} {tag {tag _ai_at_launcher_50}} {tag {tag _ai_at_launcher_60}} {tag {tag _ai_at_launcher_70}} {tag {tag _ai_at_launcher_80}} {tag {tag _ai_at_launcher_90}} {tag {tag _ufb_combat_busy}} {tag {tag _ufb_job_reserved}} {tag {tag _ufb_tank_fear}}
 {with_item {type existance} {item "rocketlauncher"}} {with_item {type existance} {item "at"}} {with_item {type existance} {item "at_rifle"}} {with_item {type existance} {item "flame"}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group
 {select {prop {prop tank}} {prop {prop armored_car}}}
 {include {team {team %foe}} {state {state operatable}} }
 {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {prop {prop airborne}}}}} {distance {mode in_range} {min 0} {max 30}} {detection visible} {tag {"tag pair"} {"for selector" _ufb_tank_fear_new_%team}}}}}
 {actions
  {"effect" {selector {ignore_captured_by_user 0} {tag _ufb_tank_fear_new_%team}} {effect ufb_tank_fear}}
  {"effect" {selector {amount 1} {ignore_captured_by_user 0} {tag _ufb_tank_fear_new_%team}} {effect ufb_tank_fear_shout}}
  {"actor_to_cover" {selector {ignore_captured_by_user 0} {tag _ufb_tank_fear_new_%team}} {drop orders}}
  {"entity_state" {selector {ignore_captured_by_user 0} {tag _ufb_tank_fear_new_%team}} {tag_remove _ufb_tank_fear_new_%team}}
  {"delay" {time 3}}
{"trigger" {name "ufb/fear/tank %team"}}
 }
}
)
("ufb_static_weapons" team(a) foe(b))
("ufb_static_weapons" team(b) foe(a))
("ufb_surrender_claim" player(0))
("ufb_surrender_claim" player(1))
("ufb_surrender_claim" player(2))
("ufb_surrender_claim" player(3))
("ufb_surrender_claim" player(4))
("ufb_surrender_claim" player(5))
("ufb_surrender_claim" player(6))
("ufb_surrender_claim" player(7))
("ufb_surrender_claim" player(8))
("ufb_surrender_claim" player(9))
("ufb_surrender_claim" player(10))
("ufb_surrender_claim" player(11))
("ufb_surrender_claim" player(12))
("ufb_surrender_claim" player(13))
("ufb_surrender_claim" player(14))
("ufb_surrender_claim" player(15))
("ufb_surrender_claim" player(16))
