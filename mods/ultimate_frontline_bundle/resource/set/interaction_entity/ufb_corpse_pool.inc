; Included inside human.inc. A corpse schedules one pool only.
(define "ufb_schedule_pool"
 {if not "ufb_pool_scheduled"
  {set "ufb_pool_scheduled" 1}
  {delay %wait 15
   {if dead
    {if not burned
     {if not under_water {call_synced "ufb_spawn_corpse_pool"}}
    }
   }
  }
 }
)
{on "ufb_schedule_corpse_pool" ("ufb_schedule_pool" wait(25))}
; stop_personage checks death after 1s: subtract that second, not add it twice.
{on "ufb_schedule_bleedout_pool" ("ufb_schedule_pool" wait(24))}
{on "ufb_spawn_corpse_pool"
 {if rand 0.111111111111
 {spawn "bloodstain_40s" "basis" x}
 else
 {if rand 0.125000000000
 {spawn "bloodstain_50s" "basis" x}
 else
 {if rand 0.142857142857
 {spawn "bloodstain_60s" "basis" x}
 else
 {if rand 0.166666666667
 {spawn "bloodstain_70s" "basis" x}
 else
 {if rand 0.200000000000
 {spawn "bloodstain" "basis" x}
 else
 {if rand 0.250000000000
 {spawn "bloodstain_90s" "basis" x}
 else
 {if rand 0.333333333333
 {spawn "bloodstain_100s" "basis" x}
 else
 {if rand 0.500000000000
 {spawn "bloodstain_110s" "basis" x}
 else
 {spawn "bloodstain_120s" "basis" x}
}
}
}
}
}
}
}
}
}
