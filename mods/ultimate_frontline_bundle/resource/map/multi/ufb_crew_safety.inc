; UFB Conquest crew safety. Breed crew identity is queried as a property;
; the tag alternative also supports mission-created crew with an explicit tag.
; No movement orders are issued to user-controlled units.

(define "ufb_crew_candidates"
    {source advanced}
    {ignore_captured_by_user 0}
    {group
        {select {prop {prop crew}} {tag {tag crew}}}
        {include {prop {prop human}} {state {state operatable}}}
        {exclude
            {state {state linked}} {state {state inactive}} {state {state dead}}
            {tag {tag _ufb_crew_profile}}
        }
    }
)

{"ufb/crew/cautious profile"
    {condition {terms {"1.entities" {selector ("ufb_crew_candidates")}}}}
    {actions
        {"actor_state"
            {selector ("ufb_crew_candidates")}
            {ai {advance_ratio 0.1} {retreat_ratio 2} {no_retreat off}}
        }
        {"entity_state" {selector ("ufb_crew_candidates")} {tag_add _ufb_crew_profile}}
        {"delay" {time 3}}
        {"trigger" {name "ufb/crew/cautious profile"}}
    }
}

(define "ufb_bot_crew_candidates"
    {source advanced}
    {group
        {select {tag {tag _ufb_crew_profile}}}
        {include {state {state operatable}}}
        {exclude
            {player {player "0"}}
            {state {state user_control}} {state {state linked}}
            {state {state inactive}} {state {state dead}}
            {tag {tag _ufb_crew_safe}} {tag {tag _lua_mi}}
            {tag {tag repairing}} {tag {tag tcrew}} {tag {tag ecrew}}
            {tag {tag ecrew_a}} {tag {tag ecrew_b}}
            {tag {tag bleeding}} {tag {tag wounded_animation_playing}}
            {tag {tag cmp_def}} {tag {tag _ai_medic}}
        }
    }
)

{"ufb/crew/take cover"
    {condition {terms
        {"1.entities" {selector ("ufb_bot_crew_candidates")}}
        {"2.cmp_i" {var "bot_retreat_active$"} {op "=="} {value 0}}
    }}
    {actions
        {"entity_state" {selector ("ufb_bot_crew_candidates")} {tag_add _ufb_crew_pending}}
        {"actor_state"
            {selector {tag _ufb_crew_pending}}
            {drop orders}
            {fire_mode open}
            {move_mode zone} {move_radius 12}
            {ai_move {mode enable}}
            {ai {advance_ratio 0.1} {retreat_ratio 2} {no_retreat off}}
        }
        {"actor_to_cover" {selector {tag _ufb_crew_pending}} {drop orders}}
        {"entity_state" {selector {tag _ufb_crew_pending}} {tag_add _ufb_crew_safe}}
        {"entity_state" {selector {tag _ufb_crew_pending}} {tag_remove _ufb_crew_pending}}
        {"delay" {time 3}}
        {"trigger" {name "ufb/crew/take cover"}}
    }
}

; Reboarding clears protection, so a crewed tank can receive normal orders.
{"ufb/crew/reboarded"
    {condition {terms {"1.entities" {selector
        {source advanced}
        {group
            {select {tag {tag _ufb_crew_profile}}}
            {include {state {state linked}}}
        }
    }}}}
    {actions
        {"entity_state" {selector {tag _ufb_crew_safe} {state linked}} {tag_remove _ufb_crew_safe}}
        {"entity_state" {selector {tag _ufb_crew_profile} {state linked}} {tag_remove _ufb_crew_profile}}
        {"delay" {time 3}}
        {"trigger" {name "ufb/crew/reboarded"}}
    }
}
