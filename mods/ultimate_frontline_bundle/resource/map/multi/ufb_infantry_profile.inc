; Mission-scoped tuning: campaign/story missions do not include this file.
(define "ufb_infantry_candidates"
    {source advanced}
    {ignore_captured_by_user 0}
    {group
        {select {prop {prop human}}}
        {include {state {state operatable}}}
        {exclude
            {prop {prop crew}} {tag {tag crew}}
            {state {state linked}} {state {state inactive}} {state {state dead}}
            {tag {tag _ufb_infantry_profile}}
        }
    }
)
{"ufb/infantry/cautious profile"
    {condition {terms {"1.entities" {selector ("ufb_infantry_candidates")}}}}
    {actions
        {"actor_state"
            {selector ("ufb_infantry_candidates")}
            {ai {advance_ratio 0.5} {retreat_ratio 3}}
        }
        {"entity_state" {selector ("ufb_infantry_candidates")} {tag_add _ufb_infantry_profile}}
        {"delay" {time 3}}
        {"trigger" {name "ufb/infantry/cautious profile"}}
    }
}
