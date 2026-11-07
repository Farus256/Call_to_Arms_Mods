; Wounded soldiers bleed out at one of three speeds, rolled once per wound:
; fast 30% (2-4 min), medium 45% (6-10 min), slow 25% (15-20 min).
; set/difficulty death_delay stays above the slow tier, so the engine timer is only a fallback.
; 30% lie still in their fall pose instead of the HF wounded loop, as in the base game.
; Healing ends the personage state, and stop_personage cancels the timer.
{on "ufb_bleedout_start"
 {kill_delay "ufb_bleedout"}
 {tags remove "_ufb_wound_still"}
 {if rand 0.3 {tags add "_ufb_wound_still"}}
 {if rand 0.3
  {if rand 0.33 {delay 120 "ufb_bleedout" {call "ufb_bleedout_die"}}
  else rand 0.5 {delay 180 "ufb_bleedout" {call "ufb_bleedout_die"}}
  else {delay 240 "ufb_bleedout" {call "ufb_bleedout_die"}}}
 else rand 0.65
  {if rand 0.33 {delay 360 "ufb_bleedout" {call "ufb_bleedout_die"}}
  else rand 0.5 {delay 480 "ufb_bleedout" {call "ufb_bleedout_die"}}
  else {delay 600 "ufb_bleedout" {call "ufb_bleedout_die"}}}
 else
  {if rand 0.33 {delay 900 "ufb_bleedout" {call "ufb_bleedout_die"}}
  else rand 0.5 {delay 1050 "ufb_bleedout" {call "ufb_bleedout_die"}}
  else {delay 1200 "ufb_bleedout" {call "ufb_bleedout_die"}}}
 }
}
{on "ufb_bleedout_die"
 {if personage {if not dead {die}}}
}
