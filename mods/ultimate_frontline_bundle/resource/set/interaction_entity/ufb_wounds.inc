; Global human interaction: choose once per recoverable-wound episode.
; This 50% choice does not change the separate fatality/revival roll.
{on "ufb_wound_start" sync
 {if tagged "start_personage"
  {if not tagged "_ufb_wound_chosen"
   {tags add "_ufb_wound_chosen"}
   {if not terrain_fx "water"
    {if rand 0.5
     ; Native holder_drop releases the existing item, not a spawned copy.
     ; An empty right-hand holder is a no-op; inventory/armor stay intact.
     {holder_drop "hand_right"}
     {delay 3 "ufb_wound_animation"
      {if tagged "start_personage"
       {if not tagged "wounded_dead"
        {if personage
         {if not terrain_fx "water"
          {tags add "wounded_animation_playing"}
          {if rand 0.333333333333
           {ani_play "lie_wounded" loop}
          else rand 0.5
           {ani_play "lie_wounded_1" loop}
          else
           {ani_play "lie_wounded_2" loop}
          }
         }
        }
       }
      }
     }
    }
   }
  }
 }
}
{on "ufb_wound_stop" sync
 {kill_delay "ufb_wound_animation"}
 {ani_stop "lie_wounded"}
 {ani_stop "lie_wounded_1"}
 {ani_stop "lie_wounded_2"}
 {tags remove "wounded_animation_playing"}
 {tags remove "_ufb_wound_chosen"}
 ; stop_personage is also sent after revival. Never play a death animation
 ; on the revived actor; use the same delayed dead check as native bleedout.
 {delay 1
  {if dead
   {if not terrain_fx "water"
    {ani_play "lie_die"}
    {tags add "wounded_dead"}
   }
  else
   {tags remove "wounded_dead"}
  }
 }
}
