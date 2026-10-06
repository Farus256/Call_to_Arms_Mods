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
 {delay 40 {call "ufb_settle_corpse_pool"}}
 else
 {if rand 0.125000000000
 {spawn "bloodstain_50s" "basis" x}
 {delay 50 {call "ufb_settle_corpse_pool"}}
 else
 {if rand 0.142857142857
 {spawn "bloodstain_60s" "basis" x}
 {delay 60 {call "ufb_settle_corpse_pool"}}
 else
 {if rand 0.166666666667
 {spawn "bloodstain_70s" "basis" x}
 {delay 70 {call "ufb_settle_corpse_pool"}}
 else
 {if rand 0.200000000000
 {spawn "bloodstain" "basis" x}
 {delay 80 {call "ufb_settle_corpse_pool"}}
 else
 {if rand 0.250000000000
 {spawn "bloodstain_90s" "basis" x}
 {delay 90 {call "ufb_settle_corpse_pool"}}
 else
 {if rand 0.333333333333
 {spawn "bloodstain_100s" "basis" x}
 {delay 100 {call "ufb_settle_corpse_pool"}}
 else
 {if rand 0.500000000000
 {spawn "bloodstain_110s" "basis" x}
 {delay 110 {call "ufb_settle_corpse_pool"}}
 else
 {spawn "bloodstain_120s" "basis" x}
 {delay 120 {call "ufb_settle_corpse_pool"}}
}
}
}
}
}
}
}
}
}
{on "ufb_settle_corpse_pool"
 {if dead
  {if not burned
   {if not under_water {spawn "ufb_corpse_pool_settled" "basis" x}}
  }
 }
}
