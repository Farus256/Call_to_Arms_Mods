{on "ufb_supply_cooldown" {tags add "_ufb_supply_cooldown"} {delay 12 {tags remove "_ufb_supply_cooldown"}}}
{on "ufb_rescue_cooldown" {tags add "_ufb_rescue_cooldown"} {delay 90 {tags remove "_ufb_rescue_cooldown"}}}
{on "ufb_medic_smoke_cooldown" {tags add "_ufb_medic_smoke_cooldown"} {delay 35 {tags remove "_ufb_medic_smoke_cooldown"}}}
(define "ufb_medical_points"
 {on "ufb_rescue_points_%team" sync
  {spawn "ufb_smoke_screen_point" "basis" x {tags add "_ufb_rescue_origin_%team"} {delay 70 {delete}}}
  {spawn "ufb_smoke_screen_point" local_offset -500 0 0 constrain_after_dir {tags add "_ufb_rescue_rear_%team"} {delay 70 {delete}}}
 }
 {on "ufb_medic_smoke_point_%team" sync
  {spawn "ufb_smoke_screen_point" local_offset 160 0 0 constrain_after_dir {tags add "_ufb_medic_smoke_point_%team"} {delay 3 {delete}}}
 }
)
("ufb_medical_points" team(a))
("ufb_medical_points" team(b))
