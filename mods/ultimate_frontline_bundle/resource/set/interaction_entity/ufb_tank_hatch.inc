; UFB: tanks button up under fire and open again when it is quiet. See tools/native/ufb_hatch.cpp.
{"tank"
 {on bullet_hit {call "ufb_hatch_danger"}}
 {on blast_hit {call "ufb_hatch_danger"}}
 {on "ufb_hatch_danger"
  {if operatable
   {tags add "_ufb_hatch_hit"}
   {if not tagged "_ufb_hatch_shut"
    {tags add "_ufb_hatch_shut"}
    {delay 0.1 {crew_enable group "ufb_hatch" 0} {call "ufb_hatch_lids_close"}} ; never inside the hit calculation itself
    {call "ufb_hatch_wait"}
   }
  }
 }
 {on "ufb_hatch_lids_close"
  {if tagged "_ufb_k_tank"
   {if has_place "commander" {call "commander_hatch_close"}}
   {if has_place "charger" {call "charger_hatch_close"}}
   {if has_place "charger2" {call "charger2_hatch_close"}}
  }
 }
 {on "ufb_hatch_lids_open"
  {if tagged "_ufb_k_tank"
   {if has_place "commander" {if crew_in_place "commander" {call "commander_hatch_open"}}}
   {if has_place "charger" {if crew_in_place "charger" {call "charger_hatch_open"}}}
   {if has_place "charger2" {if crew_in_place "charger2" {call "charger2_hatch_open"}}}
  }
 }
 {on "ufb_hatch_wait"
  {tags remove "_ufb_hatch_hit"}
  {delay 20
   {if tagged "_ufb_hatch_hit"
    {call "ufb_hatch_wait"}
   else
    {tags remove "_ufb_hatch_shut"}
    {tags remove "_ufb_hatch_logged"}
    {crew_enable group "ufb_hatch" 1}
    {call "ufb_hatch_lids_open"}
   }
  }
 }
}
