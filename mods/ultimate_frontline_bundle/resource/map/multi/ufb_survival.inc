; UFB: one local cover order, no permanent movement/fire/AI profile changes.
; Entity events own expiry and cooldown. Polling does not delay unrelated actors.
; Disable this include in ufb_infantry_profile.inc to disable automatic cover.
(define "ufb_survival_candidates"
    {source advanced}
    {group
        {select {tag {tag _ufb_stress_pending}}}
        {include {tag {tag _bot}} {prop {prop human}} {state {state operatable}}}
        {exclude
            {state {state dead}} {state {state inactive}}
            {state {state user_control}} {state {state linked}}
            {prop {prop crew}} {tag {tag crew}} {tag {tag _user}} {tag {tag player}}
            {tag {tag _ai_medic}} {tag {tag bot_medic}} {tag {tag medic}}
            {tag {tag repairing}} {tag {tag tcrew}} {tag {tag ecrew}}
            {tag {tag ecrew_a}} {tag {tag ecrew_b}}
            {tag {tag wounded}} {tag {tag bleeding}} {tag {tag _bleeding}}
            {tag {tag wounded_animation_playing}} {tag {tag start_personage}}
            {tag {tag _lua_mi}} {tag {tag _lua_ignore}} {tag {tag _ufb_crew_safe}}
            {tag {tag bot_inf_flank_in_progress}}
            {tag {tag _ai_ap_grenade}} {tag {tag _ai_at_grenade}} {tag {tag _ai_smoke_grenade}}
            {tag {tag _ai_wirecutter_in_action}}
            {tag {tag _ufb_smoke_120m_actor}} {tag {tag _ufb_smoke_60m_actor}}
            {tag {tag _ufb_smoke_wirecutter_actor}} {tag {tag ai_close_inf}}
            {tag {tag bot_arty}} {tag {tag bot_aa_guard}}
            {tag {tag _ai_at_launcher_30}} {tag {tag _ai_at_launcher_40}}
            {tag {tag _ai_at_launcher_50}} {tag {tag _ai_at_launcher_60}}
            {tag {tag _ai_at_launcher_70}} {tag {tag _ai_at_launcher_90}}
            {tag {tag _ufb_cover_cooldown}} {tag {tag _ufb_heroic}}
        }
    }
)
{"ufb/survival/cover"
    {condition {terms {"1.entities" {selector ("ufb_survival_candidates")}}}}
    {actions
        {"actor_to_cover" {selector ("ufb_survival_candidates")} {drop orders}}
        {"effect" {selector ("ufb_survival_candidates")} {effect ufb_cover_committed}}
        {"delay" {time 0.25}}
        {"trigger" {name "ufb/survival/cover"}}
    }
}
