; UFB survival layer: local event marks are consumed once by map logic.
; Tuning: hit cover radius 12 m / 5 s active mark; blast cover radius 16 m / 8 s active mark;
; movement is slow and retreat ratios are 2.5 / 3. Values are intentionally
; plain so a balance pass can change them without touching Lua or the UI.
(define "ufb_hit_candidates"
    {source advanced}
    {group {select {tag {tag _ufb_stress_hit}}}
        {include {tag {tag _bot}} {prop {prop human}} {state {state operatable}}}
        {exclude {state {state user_control}} {state {state linked}} {tag {tag _ufb_survival_hit_active}} {tag {tag _ufb_heroic}}}}
)
(define "ufb_blast_candidates"
    {source advanced}
    {group {select {tag {tag _ufb_stress_blast}}}
        {include {tag {tag _bot}} {prop {prop human}} {state {state operatable}}}
        {exclude {state {state user_control}} {state {state linked}} {tag {tag _ufb_survival_blast_active}} {tag {tag _ufb_heroic}}}}
)

{"ufb/survival/hit"
    {condition {terms {"1.entities" {selector ("ufb_hit_candidates")}}}}
    {actions
        {"actor_state" {selector ("ufb_hit_candidates")}
            {drop orders} {fire_mode open} {move_mode zone} {move_radius 12}
            {ai_move {mode enable}} {movement {speed slow}}
            {ai {advance_ratio "0.05"} {retreat_ratio "2.5"} {no_retreat off}}}
        {"actor_to_cover" {selector ("ufb_hit_candidates")} {drop orders}}
        {"entity_state" {selector ("ufb_hit_candidates")} {tag_add _ufb_survival_hit_active}}
        {"entity_state" {selector {tag _ufb_survival_hit_active}} {tag_remove _ufb_stress_hit}}
        {"delay" {time 5}}
        {"entity_state" {selector {tag _ufb_survival_hit_active}} {tag_remove _ufb_survival_hit_active}}
        {"delay" {time 0.1}} {"trigger" {name "ufb/survival/hit"}}
    }
}

{"ufb/survival/blast"
    {condition {terms {"1.entities" {selector ("ufb_blast_candidates")}}}}
    {actions
        {"actor_state" {selector ("ufb_blast_candidates")}
            {drop orders} {fire_mode open} {move_mode zone} {move_radius 16}
            {ai_move {mode enable}} {movement {speed slow}}
            {ai {advance_ratio "0.02"} {retreat_ratio 3} {no_retreat off}}}
        {"actor_to_cover" {selector ("ufb_blast_candidates")} {drop orders}}
        {"entity_state" {selector ("ufb_blast_candidates")} {tag_add _ufb_survival_blast_active}}
        {"entity_state" {selector {tag _ufb_survival_blast_active}} {tag_remove _ufb_stress_blast}}
        {"delay" {time 8}}
        {"entity_state" {selector {tag _ufb_survival_blast_active}} {tag_remove _ufb_survival_blast_active}}
        {"delay" {time 0.1}} {"trigger" {name "ufb/survival/blast"}}
    }
}
