{"vehicle"
 {on "ufb_gun_left_cooldown_a" {tags add "_ufb_gun_left_a"} {kill_delay "ufb_gun_left_expiry"} {delay 60 "ufb_gun_left_expiry" {tags remove "_ufb_gun_left_a"}}}
{on "ufb_gun_bind_0_a" sync
  {call "ufb_gun_left_cooldown_a"} {tags add "_ufb_gun_bound"}
  {kill_delay "ufb_gun_owner_expiry"}
  {delay 120 "ufb_gun_owner_expiry" {call "ufb_gun_release_owner_0_a"}}
  {spawn "ufb_smoke_screen_point" local_offset -700 0 0 constrain_after_dir {tags add "_ufb_gun_lease_0_a"} {delay 140 {delete}}}
  {if has_place "commander" {if crew_in_place "commander" {with_linked_entity "commander" {call "ufb_gun_bind_man_0_a"}}}}
{if has_place "driver" {if crew_in_place "driver" {with_linked_entity "driver" {call "ufb_gun_bind_man_0_a"}}}}
{if has_place "gunner" {if crew_in_place "gunner" {with_linked_entity "gunner" {call "ufb_gun_bind_man_0_a"}}}}
{if has_place "gunner1" {if crew_in_place "gunner1" {with_linked_entity "gunner1" {call "ufb_gun_bind_man_0_a"}}}}
{if has_place "gunner2" {if crew_in_place "gunner2" {with_linked_entity "gunner2" {call "ufb_gun_bind_man_0_a"}}}}
{if has_place "gunner3" {if crew_in_place "gunner3" {with_linked_entity "gunner3" {call "ufb_gun_bind_man_0_a"}}}}
{if has_place "gunner4" {if crew_in_place "gunner4" {with_linked_entity "gunner4" {call "ufb_gun_bind_man_0_a"}}}}
{if has_place "gunner5" {if crew_in_place "gunner5" {with_linked_entity "gunner5" {call "ufb_gun_bind_man_0_a"}}}}
{if has_place "gunner6" {if crew_in_place "gunner6" {with_linked_entity "gunner6" {call "ufb_gun_bind_man_0_a"}}}}
{if has_place "gunner7" {if crew_in_place "gunner7" {with_linked_entity "gunner7" {call "ufb_gun_bind_man_0_a"}}}}
{if has_place "gunner8" {if crew_in_place "gunner8" {with_linked_entity "gunner8" {call "ufb_gun_bind_man_0_a"}}}}
{if has_place "charger" {if crew_in_place "charger" {with_linked_entity "charger" {call "ufb_gun_bind_man_0_a"}}}}
{if has_place "charger1" {if crew_in_place "charger1" {with_linked_entity "charger1" {call "ufb_gun_bind_man_0_a"}}}}
{if has_place "charger2" {if crew_in_place "charger2" {with_linked_entity "charger2" {call "ufb_gun_bind_man_0_a"}}}}
{if has_place "charger3" {if crew_in_place "charger3" {with_linked_entity "charger3" {call "ufb_gun_bind_man_0_a"}}}}
{if has_place "charger4" {if crew_in_place "charger4" {with_linked_entity "charger4" {call "ufb_gun_bind_man_0_a"}}}}
{if has_place "charger5" {if crew_in_place "charger5" {with_linked_entity "charger5" {call "ufb_gun_bind_man_0_a"}}}}
{if has_place "charger6" {if crew_in_place "charger6" {with_linked_entity "charger6" {call "ufb_gun_bind_man_0_a"}}}}
{if has_place "charger7" {if crew_in_place "charger7" {with_linked_entity "charger7" {call "ufb_gun_bind_man_0_a"}}}}
{if has_place "charger8" {if crew_in_place "charger8" {with_linked_entity "charger8" {call "ufb_gun_bind_man_0_a"}}}}
{if has_place "loader" {if crew_in_place "loader" {with_linked_entity "loader" {call "ufb_gun_bind_man_0_a"}}}}
{if has_place "loader1" {if crew_in_place "loader1" {with_linked_entity "loader1" {call "ufb_gun_bind_man_0_a"}}}}
{if has_place "loader2" {if crew_in_place "loader2" {with_linked_entity "loader2" {call "ufb_gun_bind_man_0_a"}}}}
{if has_place "loader3" {if crew_in_place "loader3" {with_linked_entity "loader3" {call "ufb_gun_bind_man_0_a"}}}}
{if has_place "loader4" {if crew_in_place "loader4" {with_linked_entity "loader4" {call "ufb_gun_bind_man_0_a"}}}}
{if has_place "loader5" {if crew_in_place "loader5" {with_linked_entity "loader5" {call "ufb_gun_bind_man_0_a"}}}}
{if has_place "loader6" {if crew_in_place "loader6" {with_linked_entity "loader6" {call "ufb_gun_bind_man_0_a"}}}}
{if has_place "loader7" {if crew_in_place "loader7" {with_linked_entity "loader7" {call "ufb_gun_bind_man_0_a"}}}}
{if has_place "loader8" {if crew_in_place "loader8" {with_linked_entity "loader8" {call "ufb_gun_bind_man_0_a"}}}}
{if has_place "seat1" {if crew_in_place "seat1" {with_linked_entity "seat1" {call "ufb_gun_bind_man_0_a"}}}}
{if has_place "seat2" {if crew_in_place "seat2" {with_linked_entity "seat2" {call "ufb_gun_bind_man_0_a"}}}}
{if has_place "seat3" {if crew_in_place "seat3" {with_linked_entity "seat3" {call "ufb_gun_bind_man_0_a"}}}}
{if has_place "seat4" {if crew_in_place "seat4" {with_linked_entity "seat4" {call "ufb_gun_bind_man_0_a"}}}}
{if has_place "seat5" {if crew_in_place "seat5" {with_linked_entity "seat5" {call "ufb_gun_bind_man_0_a"}}}}
{if has_place "seat6" {if crew_in_place "seat6" {with_linked_entity "seat6" {call "ufb_gun_bind_man_0_a"}}}}
{if has_place "seat7" {if crew_in_place "seat7" {with_linked_entity "seat7" {call "ufb_gun_bind_man_0_a"}}}}
{if has_place "seat8" {if crew_in_place "seat8" {with_linked_entity "seat8" {call "ufb_gun_bind_man_0_a"}}}}
{if has_place "seat9" {if crew_in_place "seat9" {with_linked_entity "seat9" {call "ufb_gun_bind_man_0_a"}}}}
{if has_place "seat10" {if crew_in_place "seat10" {with_linked_entity "seat10" {call "ufb_gun_bind_man_0_a"}}}}
{if has_place "seat11" {if crew_in_place "seat11" {with_linked_entity "seat11" {call "ufb_gun_bind_man_0_a"}}}}
{if has_place "seat12" {if crew_in_place "seat12" {with_linked_entity "seat12" {call "ufb_gun_bind_man_0_a"}}}}
{if has_place "seat13" {if crew_in_place "seat13" {with_linked_entity "seat13" {call "ufb_gun_bind_man_0_a"}}}}
{if has_place "seat14" {if crew_in_place "seat14" {with_linked_entity "seat14" {call "ufb_gun_bind_man_0_a"}}}}
{if has_place "seat15" {if crew_in_place "seat15" {with_linked_entity "seat15" {call "ufb_gun_bind_man_0_a"}}}}
 }
 {on "ufb_gun_release_owner_0_a" {kill_delay "ufb_gun_owner_expiry"} {tags remove "_ufb_gun_owner_0_a"} {tags remove "_ufb_gun_escaped_0_a"} {tags remove "_ufb_gun_bound"}}
{on "ufb_gun_bind_1_a" sync
  {call "ufb_gun_left_cooldown_a"} {tags add "_ufb_gun_bound"}
  {kill_delay "ufb_gun_owner_expiry"}
  {delay 120 "ufb_gun_owner_expiry" {call "ufb_gun_release_owner_1_a"}}
  {spawn "ufb_smoke_screen_point" local_offset -700 0 0 constrain_after_dir {tags add "_ufb_gun_lease_1_a"} {delay 140 {delete}}}
  {if has_place "commander" {if crew_in_place "commander" {with_linked_entity "commander" {call "ufb_gun_bind_man_1_a"}}}}
{if has_place "driver" {if crew_in_place "driver" {with_linked_entity "driver" {call "ufb_gun_bind_man_1_a"}}}}
{if has_place "gunner" {if crew_in_place "gunner" {with_linked_entity "gunner" {call "ufb_gun_bind_man_1_a"}}}}
{if has_place "gunner1" {if crew_in_place "gunner1" {with_linked_entity "gunner1" {call "ufb_gun_bind_man_1_a"}}}}
{if has_place "gunner2" {if crew_in_place "gunner2" {with_linked_entity "gunner2" {call "ufb_gun_bind_man_1_a"}}}}
{if has_place "gunner3" {if crew_in_place "gunner3" {with_linked_entity "gunner3" {call "ufb_gun_bind_man_1_a"}}}}
{if has_place "gunner4" {if crew_in_place "gunner4" {with_linked_entity "gunner4" {call "ufb_gun_bind_man_1_a"}}}}
{if has_place "gunner5" {if crew_in_place "gunner5" {with_linked_entity "gunner5" {call "ufb_gun_bind_man_1_a"}}}}
{if has_place "gunner6" {if crew_in_place "gunner6" {with_linked_entity "gunner6" {call "ufb_gun_bind_man_1_a"}}}}
{if has_place "gunner7" {if crew_in_place "gunner7" {with_linked_entity "gunner7" {call "ufb_gun_bind_man_1_a"}}}}
{if has_place "gunner8" {if crew_in_place "gunner8" {with_linked_entity "gunner8" {call "ufb_gun_bind_man_1_a"}}}}
{if has_place "charger" {if crew_in_place "charger" {with_linked_entity "charger" {call "ufb_gun_bind_man_1_a"}}}}
{if has_place "charger1" {if crew_in_place "charger1" {with_linked_entity "charger1" {call "ufb_gun_bind_man_1_a"}}}}
{if has_place "charger2" {if crew_in_place "charger2" {with_linked_entity "charger2" {call "ufb_gun_bind_man_1_a"}}}}
{if has_place "charger3" {if crew_in_place "charger3" {with_linked_entity "charger3" {call "ufb_gun_bind_man_1_a"}}}}
{if has_place "charger4" {if crew_in_place "charger4" {with_linked_entity "charger4" {call "ufb_gun_bind_man_1_a"}}}}
{if has_place "charger5" {if crew_in_place "charger5" {with_linked_entity "charger5" {call "ufb_gun_bind_man_1_a"}}}}
{if has_place "charger6" {if crew_in_place "charger6" {with_linked_entity "charger6" {call "ufb_gun_bind_man_1_a"}}}}
{if has_place "charger7" {if crew_in_place "charger7" {with_linked_entity "charger7" {call "ufb_gun_bind_man_1_a"}}}}
{if has_place "charger8" {if crew_in_place "charger8" {with_linked_entity "charger8" {call "ufb_gun_bind_man_1_a"}}}}
{if has_place "loader" {if crew_in_place "loader" {with_linked_entity "loader" {call "ufb_gun_bind_man_1_a"}}}}
{if has_place "loader1" {if crew_in_place "loader1" {with_linked_entity "loader1" {call "ufb_gun_bind_man_1_a"}}}}
{if has_place "loader2" {if crew_in_place "loader2" {with_linked_entity "loader2" {call "ufb_gun_bind_man_1_a"}}}}
{if has_place "loader3" {if crew_in_place "loader3" {with_linked_entity "loader3" {call "ufb_gun_bind_man_1_a"}}}}
{if has_place "loader4" {if crew_in_place "loader4" {with_linked_entity "loader4" {call "ufb_gun_bind_man_1_a"}}}}
{if has_place "loader5" {if crew_in_place "loader5" {with_linked_entity "loader5" {call "ufb_gun_bind_man_1_a"}}}}
{if has_place "loader6" {if crew_in_place "loader6" {with_linked_entity "loader6" {call "ufb_gun_bind_man_1_a"}}}}
{if has_place "loader7" {if crew_in_place "loader7" {with_linked_entity "loader7" {call "ufb_gun_bind_man_1_a"}}}}
{if has_place "loader8" {if crew_in_place "loader8" {with_linked_entity "loader8" {call "ufb_gun_bind_man_1_a"}}}}
{if has_place "seat1" {if crew_in_place "seat1" {with_linked_entity "seat1" {call "ufb_gun_bind_man_1_a"}}}}
{if has_place "seat2" {if crew_in_place "seat2" {with_linked_entity "seat2" {call "ufb_gun_bind_man_1_a"}}}}
{if has_place "seat3" {if crew_in_place "seat3" {with_linked_entity "seat3" {call "ufb_gun_bind_man_1_a"}}}}
{if has_place "seat4" {if crew_in_place "seat4" {with_linked_entity "seat4" {call "ufb_gun_bind_man_1_a"}}}}
{if has_place "seat5" {if crew_in_place "seat5" {with_linked_entity "seat5" {call "ufb_gun_bind_man_1_a"}}}}
{if has_place "seat6" {if crew_in_place "seat6" {with_linked_entity "seat6" {call "ufb_gun_bind_man_1_a"}}}}
{if has_place "seat7" {if crew_in_place "seat7" {with_linked_entity "seat7" {call "ufb_gun_bind_man_1_a"}}}}
{if has_place "seat8" {if crew_in_place "seat8" {with_linked_entity "seat8" {call "ufb_gun_bind_man_1_a"}}}}
{if has_place "seat9" {if crew_in_place "seat9" {with_linked_entity "seat9" {call "ufb_gun_bind_man_1_a"}}}}
{if has_place "seat10" {if crew_in_place "seat10" {with_linked_entity "seat10" {call "ufb_gun_bind_man_1_a"}}}}
{if has_place "seat11" {if crew_in_place "seat11" {with_linked_entity "seat11" {call "ufb_gun_bind_man_1_a"}}}}
{if has_place "seat12" {if crew_in_place "seat12" {with_linked_entity "seat12" {call "ufb_gun_bind_man_1_a"}}}}
{if has_place "seat13" {if crew_in_place "seat13" {with_linked_entity "seat13" {call "ufb_gun_bind_man_1_a"}}}}
{if has_place "seat14" {if crew_in_place "seat14" {with_linked_entity "seat14" {call "ufb_gun_bind_man_1_a"}}}}
{if has_place "seat15" {if crew_in_place "seat15" {with_linked_entity "seat15" {call "ufb_gun_bind_man_1_a"}}}}
 }
 {on "ufb_gun_release_owner_1_a" {kill_delay "ufb_gun_owner_expiry"} {tags remove "_ufb_gun_owner_1_a"} {tags remove "_ufb_gun_escaped_1_a"} {tags remove "_ufb_gun_bound"}}
{on "ufb_gun_bind_2_a" sync
  {call "ufb_gun_left_cooldown_a"} {tags add "_ufb_gun_bound"}
  {kill_delay "ufb_gun_owner_expiry"}
  {delay 120 "ufb_gun_owner_expiry" {call "ufb_gun_release_owner_2_a"}}
  {spawn "ufb_smoke_screen_point" local_offset -700 0 0 constrain_after_dir {tags add "_ufb_gun_lease_2_a"} {delay 140 {delete}}}
  {if has_place "commander" {if crew_in_place "commander" {with_linked_entity "commander" {call "ufb_gun_bind_man_2_a"}}}}
{if has_place "driver" {if crew_in_place "driver" {with_linked_entity "driver" {call "ufb_gun_bind_man_2_a"}}}}
{if has_place "gunner" {if crew_in_place "gunner" {with_linked_entity "gunner" {call "ufb_gun_bind_man_2_a"}}}}
{if has_place "gunner1" {if crew_in_place "gunner1" {with_linked_entity "gunner1" {call "ufb_gun_bind_man_2_a"}}}}
{if has_place "gunner2" {if crew_in_place "gunner2" {with_linked_entity "gunner2" {call "ufb_gun_bind_man_2_a"}}}}
{if has_place "gunner3" {if crew_in_place "gunner3" {with_linked_entity "gunner3" {call "ufb_gun_bind_man_2_a"}}}}
{if has_place "gunner4" {if crew_in_place "gunner4" {with_linked_entity "gunner4" {call "ufb_gun_bind_man_2_a"}}}}
{if has_place "gunner5" {if crew_in_place "gunner5" {with_linked_entity "gunner5" {call "ufb_gun_bind_man_2_a"}}}}
{if has_place "gunner6" {if crew_in_place "gunner6" {with_linked_entity "gunner6" {call "ufb_gun_bind_man_2_a"}}}}
{if has_place "gunner7" {if crew_in_place "gunner7" {with_linked_entity "gunner7" {call "ufb_gun_bind_man_2_a"}}}}
{if has_place "gunner8" {if crew_in_place "gunner8" {with_linked_entity "gunner8" {call "ufb_gun_bind_man_2_a"}}}}
{if has_place "charger" {if crew_in_place "charger" {with_linked_entity "charger" {call "ufb_gun_bind_man_2_a"}}}}
{if has_place "charger1" {if crew_in_place "charger1" {with_linked_entity "charger1" {call "ufb_gun_bind_man_2_a"}}}}
{if has_place "charger2" {if crew_in_place "charger2" {with_linked_entity "charger2" {call "ufb_gun_bind_man_2_a"}}}}
{if has_place "charger3" {if crew_in_place "charger3" {with_linked_entity "charger3" {call "ufb_gun_bind_man_2_a"}}}}
{if has_place "charger4" {if crew_in_place "charger4" {with_linked_entity "charger4" {call "ufb_gun_bind_man_2_a"}}}}
{if has_place "charger5" {if crew_in_place "charger5" {with_linked_entity "charger5" {call "ufb_gun_bind_man_2_a"}}}}
{if has_place "charger6" {if crew_in_place "charger6" {with_linked_entity "charger6" {call "ufb_gun_bind_man_2_a"}}}}
{if has_place "charger7" {if crew_in_place "charger7" {with_linked_entity "charger7" {call "ufb_gun_bind_man_2_a"}}}}
{if has_place "charger8" {if crew_in_place "charger8" {with_linked_entity "charger8" {call "ufb_gun_bind_man_2_a"}}}}
{if has_place "loader" {if crew_in_place "loader" {with_linked_entity "loader" {call "ufb_gun_bind_man_2_a"}}}}
{if has_place "loader1" {if crew_in_place "loader1" {with_linked_entity "loader1" {call "ufb_gun_bind_man_2_a"}}}}
{if has_place "loader2" {if crew_in_place "loader2" {with_linked_entity "loader2" {call "ufb_gun_bind_man_2_a"}}}}
{if has_place "loader3" {if crew_in_place "loader3" {with_linked_entity "loader3" {call "ufb_gun_bind_man_2_a"}}}}
{if has_place "loader4" {if crew_in_place "loader4" {with_linked_entity "loader4" {call "ufb_gun_bind_man_2_a"}}}}
{if has_place "loader5" {if crew_in_place "loader5" {with_linked_entity "loader5" {call "ufb_gun_bind_man_2_a"}}}}
{if has_place "loader6" {if crew_in_place "loader6" {with_linked_entity "loader6" {call "ufb_gun_bind_man_2_a"}}}}
{if has_place "loader7" {if crew_in_place "loader7" {with_linked_entity "loader7" {call "ufb_gun_bind_man_2_a"}}}}
{if has_place "loader8" {if crew_in_place "loader8" {with_linked_entity "loader8" {call "ufb_gun_bind_man_2_a"}}}}
{if has_place "seat1" {if crew_in_place "seat1" {with_linked_entity "seat1" {call "ufb_gun_bind_man_2_a"}}}}
{if has_place "seat2" {if crew_in_place "seat2" {with_linked_entity "seat2" {call "ufb_gun_bind_man_2_a"}}}}
{if has_place "seat3" {if crew_in_place "seat3" {with_linked_entity "seat3" {call "ufb_gun_bind_man_2_a"}}}}
{if has_place "seat4" {if crew_in_place "seat4" {with_linked_entity "seat4" {call "ufb_gun_bind_man_2_a"}}}}
{if has_place "seat5" {if crew_in_place "seat5" {with_linked_entity "seat5" {call "ufb_gun_bind_man_2_a"}}}}
{if has_place "seat6" {if crew_in_place "seat6" {with_linked_entity "seat6" {call "ufb_gun_bind_man_2_a"}}}}
{if has_place "seat7" {if crew_in_place "seat7" {with_linked_entity "seat7" {call "ufb_gun_bind_man_2_a"}}}}
{if has_place "seat8" {if crew_in_place "seat8" {with_linked_entity "seat8" {call "ufb_gun_bind_man_2_a"}}}}
{if has_place "seat9" {if crew_in_place "seat9" {with_linked_entity "seat9" {call "ufb_gun_bind_man_2_a"}}}}
{if has_place "seat10" {if crew_in_place "seat10" {with_linked_entity "seat10" {call "ufb_gun_bind_man_2_a"}}}}
{if has_place "seat11" {if crew_in_place "seat11" {with_linked_entity "seat11" {call "ufb_gun_bind_man_2_a"}}}}
{if has_place "seat12" {if crew_in_place "seat12" {with_linked_entity "seat12" {call "ufb_gun_bind_man_2_a"}}}}
{if has_place "seat13" {if crew_in_place "seat13" {with_linked_entity "seat13" {call "ufb_gun_bind_man_2_a"}}}}
{if has_place "seat14" {if crew_in_place "seat14" {with_linked_entity "seat14" {call "ufb_gun_bind_man_2_a"}}}}
{if has_place "seat15" {if crew_in_place "seat15" {with_linked_entity "seat15" {call "ufb_gun_bind_man_2_a"}}}}
 }
 {on "ufb_gun_release_owner_2_a" {kill_delay "ufb_gun_owner_expiry"} {tags remove "_ufb_gun_owner_2_a"} {tags remove "_ufb_gun_escaped_2_a"} {tags remove "_ufb_gun_bound"}}
{on "ufb_gun_bind_3_a" sync
  {call "ufb_gun_left_cooldown_a"} {tags add "_ufb_gun_bound"}
  {kill_delay "ufb_gun_owner_expiry"}
  {delay 120 "ufb_gun_owner_expiry" {call "ufb_gun_release_owner_3_a"}}
  {spawn "ufb_smoke_screen_point" local_offset -700 0 0 constrain_after_dir {tags add "_ufb_gun_lease_3_a"} {delay 140 {delete}}}
  {if has_place "commander" {if crew_in_place "commander" {with_linked_entity "commander" {call "ufb_gun_bind_man_3_a"}}}}
{if has_place "driver" {if crew_in_place "driver" {with_linked_entity "driver" {call "ufb_gun_bind_man_3_a"}}}}
{if has_place "gunner" {if crew_in_place "gunner" {with_linked_entity "gunner" {call "ufb_gun_bind_man_3_a"}}}}
{if has_place "gunner1" {if crew_in_place "gunner1" {with_linked_entity "gunner1" {call "ufb_gun_bind_man_3_a"}}}}
{if has_place "gunner2" {if crew_in_place "gunner2" {with_linked_entity "gunner2" {call "ufb_gun_bind_man_3_a"}}}}
{if has_place "gunner3" {if crew_in_place "gunner3" {with_linked_entity "gunner3" {call "ufb_gun_bind_man_3_a"}}}}
{if has_place "gunner4" {if crew_in_place "gunner4" {with_linked_entity "gunner4" {call "ufb_gun_bind_man_3_a"}}}}
{if has_place "gunner5" {if crew_in_place "gunner5" {with_linked_entity "gunner5" {call "ufb_gun_bind_man_3_a"}}}}
{if has_place "gunner6" {if crew_in_place "gunner6" {with_linked_entity "gunner6" {call "ufb_gun_bind_man_3_a"}}}}
{if has_place "gunner7" {if crew_in_place "gunner7" {with_linked_entity "gunner7" {call "ufb_gun_bind_man_3_a"}}}}
{if has_place "gunner8" {if crew_in_place "gunner8" {with_linked_entity "gunner8" {call "ufb_gun_bind_man_3_a"}}}}
{if has_place "charger" {if crew_in_place "charger" {with_linked_entity "charger" {call "ufb_gun_bind_man_3_a"}}}}
{if has_place "charger1" {if crew_in_place "charger1" {with_linked_entity "charger1" {call "ufb_gun_bind_man_3_a"}}}}
{if has_place "charger2" {if crew_in_place "charger2" {with_linked_entity "charger2" {call "ufb_gun_bind_man_3_a"}}}}
{if has_place "charger3" {if crew_in_place "charger3" {with_linked_entity "charger3" {call "ufb_gun_bind_man_3_a"}}}}
{if has_place "charger4" {if crew_in_place "charger4" {with_linked_entity "charger4" {call "ufb_gun_bind_man_3_a"}}}}
{if has_place "charger5" {if crew_in_place "charger5" {with_linked_entity "charger5" {call "ufb_gun_bind_man_3_a"}}}}
{if has_place "charger6" {if crew_in_place "charger6" {with_linked_entity "charger6" {call "ufb_gun_bind_man_3_a"}}}}
{if has_place "charger7" {if crew_in_place "charger7" {with_linked_entity "charger7" {call "ufb_gun_bind_man_3_a"}}}}
{if has_place "charger8" {if crew_in_place "charger8" {with_linked_entity "charger8" {call "ufb_gun_bind_man_3_a"}}}}
{if has_place "loader" {if crew_in_place "loader" {with_linked_entity "loader" {call "ufb_gun_bind_man_3_a"}}}}
{if has_place "loader1" {if crew_in_place "loader1" {with_linked_entity "loader1" {call "ufb_gun_bind_man_3_a"}}}}
{if has_place "loader2" {if crew_in_place "loader2" {with_linked_entity "loader2" {call "ufb_gun_bind_man_3_a"}}}}
{if has_place "loader3" {if crew_in_place "loader3" {with_linked_entity "loader3" {call "ufb_gun_bind_man_3_a"}}}}
{if has_place "loader4" {if crew_in_place "loader4" {with_linked_entity "loader4" {call "ufb_gun_bind_man_3_a"}}}}
{if has_place "loader5" {if crew_in_place "loader5" {with_linked_entity "loader5" {call "ufb_gun_bind_man_3_a"}}}}
{if has_place "loader6" {if crew_in_place "loader6" {with_linked_entity "loader6" {call "ufb_gun_bind_man_3_a"}}}}
{if has_place "loader7" {if crew_in_place "loader7" {with_linked_entity "loader7" {call "ufb_gun_bind_man_3_a"}}}}
{if has_place "loader8" {if crew_in_place "loader8" {with_linked_entity "loader8" {call "ufb_gun_bind_man_3_a"}}}}
{if has_place "seat1" {if crew_in_place "seat1" {with_linked_entity "seat1" {call "ufb_gun_bind_man_3_a"}}}}
{if has_place "seat2" {if crew_in_place "seat2" {with_linked_entity "seat2" {call "ufb_gun_bind_man_3_a"}}}}
{if has_place "seat3" {if crew_in_place "seat3" {with_linked_entity "seat3" {call "ufb_gun_bind_man_3_a"}}}}
{if has_place "seat4" {if crew_in_place "seat4" {with_linked_entity "seat4" {call "ufb_gun_bind_man_3_a"}}}}
{if has_place "seat5" {if crew_in_place "seat5" {with_linked_entity "seat5" {call "ufb_gun_bind_man_3_a"}}}}
{if has_place "seat6" {if crew_in_place "seat6" {with_linked_entity "seat6" {call "ufb_gun_bind_man_3_a"}}}}
{if has_place "seat7" {if crew_in_place "seat7" {with_linked_entity "seat7" {call "ufb_gun_bind_man_3_a"}}}}
{if has_place "seat8" {if crew_in_place "seat8" {with_linked_entity "seat8" {call "ufb_gun_bind_man_3_a"}}}}
{if has_place "seat9" {if crew_in_place "seat9" {with_linked_entity "seat9" {call "ufb_gun_bind_man_3_a"}}}}
{if has_place "seat10" {if crew_in_place "seat10" {with_linked_entity "seat10" {call "ufb_gun_bind_man_3_a"}}}}
{if has_place "seat11" {if crew_in_place "seat11" {with_linked_entity "seat11" {call "ufb_gun_bind_man_3_a"}}}}
{if has_place "seat12" {if crew_in_place "seat12" {with_linked_entity "seat12" {call "ufb_gun_bind_man_3_a"}}}}
{if has_place "seat13" {if crew_in_place "seat13" {with_linked_entity "seat13" {call "ufb_gun_bind_man_3_a"}}}}
{if has_place "seat14" {if crew_in_place "seat14" {with_linked_entity "seat14" {call "ufb_gun_bind_man_3_a"}}}}
{if has_place "seat15" {if crew_in_place "seat15" {with_linked_entity "seat15" {call "ufb_gun_bind_man_3_a"}}}}
 }
 {on "ufb_gun_release_owner_3_a" {kill_delay "ufb_gun_owner_expiry"} {tags remove "_ufb_gun_owner_3_a"} {tags remove "_ufb_gun_escaped_3_a"} {tags remove "_ufb_gun_bound"}}
{on "ufb_gun_bind_4_a" sync
  {call "ufb_gun_left_cooldown_a"} {tags add "_ufb_gun_bound"}
  {kill_delay "ufb_gun_owner_expiry"}
  {delay 120 "ufb_gun_owner_expiry" {call "ufb_gun_release_owner_4_a"}}
  {spawn "ufb_smoke_screen_point" local_offset -700 0 0 constrain_after_dir {tags add "_ufb_gun_lease_4_a"} {delay 140 {delete}}}
  {if has_place "commander" {if crew_in_place "commander" {with_linked_entity "commander" {call "ufb_gun_bind_man_4_a"}}}}
{if has_place "driver" {if crew_in_place "driver" {with_linked_entity "driver" {call "ufb_gun_bind_man_4_a"}}}}
{if has_place "gunner" {if crew_in_place "gunner" {with_linked_entity "gunner" {call "ufb_gun_bind_man_4_a"}}}}
{if has_place "gunner1" {if crew_in_place "gunner1" {with_linked_entity "gunner1" {call "ufb_gun_bind_man_4_a"}}}}
{if has_place "gunner2" {if crew_in_place "gunner2" {with_linked_entity "gunner2" {call "ufb_gun_bind_man_4_a"}}}}
{if has_place "gunner3" {if crew_in_place "gunner3" {with_linked_entity "gunner3" {call "ufb_gun_bind_man_4_a"}}}}
{if has_place "gunner4" {if crew_in_place "gunner4" {with_linked_entity "gunner4" {call "ufb_gun_bind_man_4_a"}}}}
{if has_place "gunner5" {if crew_in_place "gunner5" {with_linked_entity "gunner5" {call "ufb_gun_bind_man_4_a"}}}}
{if has_place "gunner6" {if crew_in_place "gunner6" {with_linked_entity "gunner6" {call "ufb_gun_bind_man_4_a"}}}}
{if has_place "gunner7" {if crew_in_place "gunner7" {with_linked_entity "gunner7" {call "ufb_gun_bind_man_4_a"}}}}
{if has_place "gunner8" {if crew_in_place "gunner8" {with_linked_entity "gunner8" {call "ufb_gun_bind_man_4_a"}}}}
{if has_place "charger" {if crew_in_place "charger" {with_linked_entity "charger" {call "ufb_gun_bind_man_4_a"}}}}
{if has_place "charger1" {if crew_in_place "charger1" {with_linked_entity "charger1" {call "ufb_gun_bind_man_4_a"}}}}
{if has_place "charger2" {if crew_in_place "charger2" {with_linked_entity "charger2" {call "ufb_gun_bind_man_4_a"}}}}
{if has_place "charger3" {if crew_in_place "charger3" {with_linked_entity "charger3" {call "ufb_gun_bind_man_4_a"}}}}
{if has_place "charger4" {if crew_in_place "charger4" {with_linked_entity "charger4" {call "ufb_gun_bind_man_4_a"}}}}
{if has_place "charger5" {if crew_in_place "charger5" {with_linked_entity "charger5" {call "ufb_gun_bind_man_4_a"}}}}
{if has_place "charger6" {if crew_in_place "charger6" {with_linked_entity "charger6" {call "ufb_gun_bind_man_4_a"}}}}
{if has_place "charger7" {if crew_in_place "charger7" {with_linked_entity "charger7" {call "ufb_gun_bind_man_4_a"}}}}
{if has_place "charger8" {if crew_in_place "charger8" {with_linked_entity "charger8" {call "ufb_gun_bind_man_4_a"}}}}
{if has_place "loader" {if crew_in_place "loader" {with_linked_entity "loader" {call "ufb_gun_bind_man_4_a"}}}}
{if has_place "loader1" {if crew_in_place "loader1" {with_linked_entity "loader1" {call "ufb_gun_bind_man_4_a"}}}}
{if has_place "loader2" {if crew_in_place "loader2" {with_linked_entity "loader2" {call "ufb_gun_bind_man_4_a"}}}}
{if has_place "loader3" {if crew_in_place "loader3" {with_linked_entity "loader3" {call "ufb_gun_bind_man_4_a"}}}}
{if has_place "loader4" {if crew_in_place "loader4" {with_linked_entity "loader4" {call "ufb_gun_bind_man_4_a"}}}}
{if has_place "loader5" {if crew_in_place "loader5" {with_linked_entity "loader5" {call "ufb_gun_bind_man_4_a"}}}}
{if has_place "loader6" {if crew_in_place "loader6" {with_linked_entity "loader6" {call "ufb_gun_bind_man_4_a"}}}}
{if has_place "loader7" {if crew_in_place "loader7" {with_linked_entity "loader7" {call "ufb_gun_bind_man_4_a"}}}}
{if has_place "loader8" {if crew_in_place "loader8" {with_linked_entity "loader8" {call "ufb_gun_bind_man_4_a"}}}}
{if has_place "seat1" {if crew_in_place "seat1" {with_linked_entity "seat1" {call "ufb_gun_bind_man_4_a"}}}}
{if has_place "seat2" {if crew_in_place "seat2" {with_linked_entity "seat2" {call "ufb_gun_bind_man_4_a"}}}}
{if has_place "seat3" {if crew_in_place "seat3" {with_linked_entity "seat3" {call "ufb_gun_bind_man_4_a"}}}}
{if has_place "seat4" {if crew_in_place "seat4" {with_linked_entity "seat4" {call "ufb_gun_bind_man_4_a"}}}}
{if has_place "seat5" {if crew_in_place "seat5" {with_linked_entity "seat5" {call "ufb_gun_bind_man_4_a"}}}}
{if has_place "seat6" {if crew_in_place "seat6" {with_linked_entity "seat6" {call "ufb_gun_bind_man_4_a"}}}}
{if has_place "seat7" {if crew_in_place "seat7" {with_linked_entity "seat7" {call "ufb_gun_bind_man_4_a"}}}}
{if has_place "seat8" {if crew_in_place "seat8" {with_linked_entity "seat8" {call "ufb_gun_bind_man_4_a"}}}}
{if has_place "seat9" {if crew_in_place "seat9" {with_linked_entity "seat9" {call "ufb_gun_bind_man_4_a"}}}}
{if has_place "seat10" {if crew_in_place "seat10" {with_linked_entity "seat10" {call "ufb_gun_bind_man_4_a"}}}}
{if has_place "seat11" {if crew_in_place "seat11" {with_linked_entity "seat11" {call "ufb_gun_bind_man_4_a"}}}}
{if has_place "seat12" {if crew_in_place "seat12" {with_linked_entity "seat12" {call "ufb_gun_bind_man_4_a"}}}}
{if has_place "seat13" {if crew_in_place "seat13" {with_linked_entity "seat13" {call "ufb_gun_bind_man_4_a"}}}}
{if has_place "seat14" {if crew_in_place "seat14" {with_linked_entity "seat14" {call "ufb_gun_bind_man_4_a"}}}}
{if has_place "seat15" {if crew_in_place "seat15" {with_linked_entity "seat15" {call "ufb_gun_bind_man_4_a"}}}}
 }
 {on "ufb_gun_release_owner_4_a" {kill_delay "ufb_gun_owner_expiry"} {tags remove "_ufb_gun_owner_4_a"} {tags remove "_ufb_gun_escaped_4_a"} {tags remove "_ufb_gun_bound"}}
{on "ufb_gun_bind_5_a" sync
  {call "ufb_gun_left_cooldown_a"} {tags add "_ufb_gun_bound"}
  {kill_delay "ufb_gun_owner_expiry"}
  {delay 120 "ufb_gun_owner_expiry" {call "ufb_gun_release_owner_5_a"}}
  {spawn "ufb_smoke_screen_point" local_offset -700 0 0 constrain_after_dir {tags add "_ufb_gun_lease_5_a"} {delay 140 {delete}}}
  {if has_place "commander" {if crew_in_place "commander" {with_linked_entity "commander" {call "ufb_gun_bind_man_5_a"}}}}
{if has_place "driver" {if crew_in_place "driver" {with_linked_entity "driver" {call "ufb_gun_bind_man_5_a"}}}}
{if has_place "gunner" {if crew_in_place "gunner" {with_linked_entity "gunner" {call "ufb_gun_bind_man_5_a"}}}}
{if has_place "gunner1" {if crew_in_place "gunner1" {with_linked_entity "gunner1" {call "ufb_gun_bind_man_5_a"}}}}
{if has_place "gunner2" {if crew_in_place "gunner2" {with_linked_entity "gunner2" {call "ufb_gun_bind_man_5_a"}}}}
{if has_place "gunner3" {if crew_in_place "gunner3" {with_linked_entity "gunner3" {call "ufb_gun_bind_man_5_a"}}}}
{if has_place "gunner4" {if crew_in_place "gunner4" {with_linked_entity "gunner4" {call "ufb_gun_bind_man_5_a"}}}}
{if has_place "gunner5" {if crew_in_place "gunner5" {with_linked_entity "gunner5" {call "ufb_gun_bind_man_5_a"}}}}
{if has_place "gunner6" {if crew_in_place "gunner6" {with_linked_entity "gunner6" {call "ufb_gun_bind_man_5_a"}}}}
{if has_place "gunner7" {if crew_in_place "gunner7" {with_linked_entity "gunner7" {call "ufb_gun_bind_man_5_a"}}}}
{if has_place "gunner8" {if crew_in_place "gunner8" {with_linked_entity "gunner8" {call "ufb_gun_bind_man_5_a"}}}}
{if has_place "charger" {if crew_in_place "charger" {with_linked_entity "charger" {call "ufb_gun_bind_man_5_a"}}}}
{if has_place "charger1" {if crew_in_place "charger1" {with_linked_entity "charger1" {call "ufb_gun_bind_man_5_a"}}}}
{if has_place "charger2" {if crew_in_place "charger2" {with_linked_entity "charger2" {call "ufb_gun_bind_man_5_a"}}}}
{if has_place "charger3" {if crew_in_place "charger3" {with_linked_entity "charger3" {call "ufb_gun_bind_man_5_a"}}}}
{if has_place "charger4" {if crew_in_place "charger4" {with_linked_entity "charger4" {call "ufb_gun_bind_man_5_a"}}}}
{if has_place "charger5" {if crew_in_place "charger5" {with_linked_entity "charger5" {call "ufb_gun_bind_man_5_a"}}}}
{if has_place "charger6" {if crew_in_place "charger6" {with_linked_entity "charger6" {call "ufb_gun_bind_man_5_a"}}}}
{if has_place "charger7" {if crew_in_place "charger7" {with_linked_entity "charger7" {call "ufb_gun_bind_man_5_a"}}}}
{if has_place "charger8" {if crew_in_place "charger8" {with_linked_entity "charger8" {call "ufb_gun_bind_man_5_a"}}}}
{if has_place "loader" {if crew_in_place "loader" {with_linked_entity "loader" {call "ufb_gun_bind_man_5_a"}}}}
{if has_place "loader1" {if crew_in_place "loader1" {with_linked_entity "loader1" {call "ufb_gun_bind_man_5_a"}}}}
{if has_place "loader2" {if crew_in_place "loader2" {with_linked_entity "loader2" {call "ufb_gun_bind_man_5_a"}}}}
{if has_place "loader3" {if crew_in_place "loader3" {with_linked_entity "loader3" {call "ufb_gun_bind_man_5_a"}}}}
{if has_place "loader4" {if crew_in_place "loader4" {with_linked_entity "loader4" {call "ufb_gun_bind_man_5_a"}}}}
{if has_place "loader5" {if crew_in_place "loader5" {with_linked_entity "loader5" {call "ufb_gun_bind_man_5_a"}}}}
{if has_place "loader6" {if crew_in_place "loader6" {with_linked_entity "loader6" {call "ufb_gun_bind_man_5_a"}}}}
{if has_place "loader7" {if crew_in_place "loader7" {with_linked_entity "loader7" {call "ufb_gun_bind_man_5_a"}}}}
{if has_place "loader8" {if crew_in_place "loader8" {with_linked_entity "loader8" {call "ufb_gun_bind_man_5_a"}}}}
{if has_place "seat1" {if crew_in_place "seat1" {with_linked_entity "seat1" {call "ufb_gun_bind_man_5_a"}}}}
{if has_place "seat2" {if crew_in_place "seat2" {with_linked_entity "seat2" {call "ufb_gun_bind_man_5_a"}}}}
{if has_place "seat3" {if crew_in_place "seat3" {with_linked_entity "seat3" {call "ufb_gun_bind_man_5_a"}}}}
{if has_place "seat4" {if crew_in_place "seat4" {with_linked_entity "seat4" {call "ufb_gun_bind_man_5_a"}}}}
{if has_place "seat5" {if crew_in_place "seat5" {with_linked_entity "seat5" {call "ufb_gun_bind_man_5_a"}}}}
{if has_place "seat6" {if crew_in_place "seat6" {with_linked_entity "seat6" {call "ufb_gun_bind_man_5_a"}}}}
{if has_place "seat7" {if crew_in_place "seat7" {with_linked_entity "seat7" {call "ufb_gun_bind_man_5_a"}}}}
{if has_place "seat8" {if crew_in_place "seat8" {with_linked_entity "seat8" {call "ufb_gun_bind_man_5_a"}}}}
{if has_place "seat9" {if crew_in_place "seat9" {with_linked_entity "seat9" {call "ufb_gun_bind_man_5_a"}}}}
{if has_place "seat10" {if crew_in_place "seat10" {with_linked_entity "seat10" {call "ufb_gun_bind_man_5_a"}}}}
{if has_place "seat11" {if crew_in_place "seat11" {with_linked_entity "seat11" {call "ufb_gun_bind_man_5_a"}}}}
{if has_place "seat12" {if crew_in_place "seat12" {with_linked_entity "seat12" {call "ufb_gun_bind_man_5_a"}}}}
{if has_place "seat13" {if crew_in_place "seat13" {with_linked_entity "seat13" {call "ufb_gun_bind_man_5_a"}}}}
{if has_place "seat14" {if crew_in_place "seat14" {with_linked_entity "seat14" {call "ufb_gun_bind_man_5_a"}}}}
{if has_place "seat15" {if crew_in_place "seat15" {with_linked_entity "seat15" {call "ufb_gun_bind_man_5_a"}}}}
 }
 {on "ufb_gun_release_owner_5_a" {kill_delay "ufb_gun_owner_expiry"} {tags remove "_ufb_gun_owner_5_a"} {tags remove "_ufb_gun_escaped_5_a"} {tags remove "_ufb_gun_bound"}}
{on "ufb_gun_bind_6_a" sync
  {call "ufb_gun_left_cooldown_a"} {tags add "_ufb_gun_bound"}
  {kill_delay "ufb_gun_owner_expiry"}
  {delay 120 "ufb_gun_owner_expiry" {call "ufb_gun_release_owner_6_a"}}
  {spawn "ufb_smoke_screen_point" local_offset -700 0 0 constrain_after_dir {tags add "_ufb_gun_lease_6_a"} {delay 140 {delete}}}
  {if has_place "commander" {if crew_in_place "commander" {with_linked_entity "commander" {call "ufb_gun_bind_man_6_a"}}}}
{if has_place "driver" {if crew_in_place "driver" {with_linked_entity "driver" {call "ufb_gun_bind_man_6_a"}}}}
{if has_place "gunner" {if crew_in_place "gunner" {with_linked_entity "gunner" {call "ufb_gun_bind_man_6_a"}}}}
{if has_place "gunner1" {if crew_in_place "gunner1" {with_linked_entity "gunner1" {call "ufb_gun_bind_man_6_a"}}}}
{if has_place "gunner2" {if crew_in_place "gunner2" {with_linked_entity "gunner2" {call "ufb_gun_bind_man_6_a"}}}}
{if has_place "gunner3" {if crew_in_place "gunner3" {with_linked_entity "gunner3" {call "ufb_gun_bind_man_6_a"}}}}
{if has_place "gunner4" {if crew_in_place "gunner4" {with_linked_entity "gunner4" {call "ufb_gun_bind_man_6_a"}}}}
{if has_place "gunner5" {if crew_in_place "gunner5" {with_linked_entity "gunner5" {call "ufb_gun_bind_man_6_a"}}}}
{if has_place "gunner6" {if crew_in_place "gunner6" {with_linked_entity "gunner6" {call "ufb_gun_bind_man_6_a"}}}}
{if has_place "gunner7" {if crew_in_place "gunner7" {with_linked_entity "gunner7" {call "ufb_gun_bind_man_6_a"}}}}
{if has_place "gunner8" {if crew_in_place "gunner8" {with_linked_entity "gunner8" {call "ufb_gun_bind_man_6_a"}}}}
{if has_place "charger" {if crew_in_place "charger" {with_linked_entity "charger" {call "ufb_gun_bind_man_6_a"}}}}
{if has_place "charger1" {if crew_in_place "charger1" {with_linked_entity "charger1" {call "ufb_gun_bind_man_6_a"}}}}
{if has_place "charger2" {if crew_in_place "charger2" {with_linked_entity "charger2" {call "ufb_gun_bind_man_6_a"}}}}
{if has_place "charger3" {if crew_in_place "charger3" {with_linked_entity "charger3" {call "ufb_gun_bind_man_6_a"}}}}
{if has_place "charger4" {if crew_in_place "charger4" {with_linked_entity "charger4" {call "ufb_gun_bind_man_6_a"}}}}
{if has_place "charger5" {if crew_in_place "charger5" {with_linked_entity "charger5" {call "ufb_gun_bind_man_6_a"}}}}
{if has_place "charger6" {if crew_in_place "charger6" {with_linked_entity "charger6" {call "ufb_gun_bind_man_6_a"}}}}
{if has_place "charger7" {if crew_in_place "charger7" {with_linked_entity "charger7" {call "ufb_gun_bind_man_6_a"}}}}
{if has_place "charger8" {if crew_in_place "charger8" {with_linked_entity "charger8" {call "ufb_gun_bind_man_6_a"}}}}
{if has_place "loader" {if crew_in_place "loader" {with_linked_entity "loader" {call "ufb_gun_bind_man_6_a"}}}}
{if has_place "loader1" {if crew_in_place "loader1" {with_linked_entity "loader1" {call "ufb_gun_bind_man_6_a"}}}}
{if has_place "loader2" {if crew_in_place "loader2" {with_linked_entity "loader2" {call "ufb_gun_bind_man_6_a"}}}}
{if has_place "loader3" {if crew_in_place "loader3" {with_linked_entity "loader3" {call "ufb_gun_bind_man_6_a"}}}}
{if has_place "loader4" {if crew_in_place "loader4" {with_linked_entity "loader4" {call "ufb_gun_bind_man_6_a"}}}}
{if has_place "loader5" {if crew_in_place "loader5" {with_linked_entity "loader5" {call "ufb_gun_bind_man_6_a"}}}}
{if has_place "loader6" {if crew_in_place "loader6" {with_linked_entity "loader6" {call "ufb_gun_bind_man_6_a"}}}}
{if has_place "loader7" {if crew_in_place "loader7" {with_linked_entity "loader7" {call "ufb_gun_bind_man_6_a"}}}}
{if has_place "loader8" {if crew_in_place "loader8" {with_linked_entity "loader8" {call "ufb_gun_bind_man_6_a"}}}}
{if has_place "seat1" {if crew_in_place "seat1" {with_linked_entity "seat1" {call "ufb_gun_bind_man_6_a"}}}}
{if has_place "seat2" {if crew_in_place "seat2" {with_linked_entity "seat2" {call "ufb_gun_bind_man_6_a"}}}}
{if has_place "seat3" {if crew_in_place "seat3" {with_linked_entity "seat3" {call "ufb_gun_bind_man_6_a"}}}}
{if has_place "seat4" {if crew_in_place "seat4" {with_linked_entity "seat4" {call "ufb_gun_bind_man_6_a"}}}}
{if has_place "seat5" {if crew_in_place "seat5" {with_linked_entity "seat5" {call "ufb_gun_bind_man_6_a"}}}}
{if has_place "seat6" {if crew_in_place "seat6" {with_linked_entity "seat6" {call "ufb_gun_bind_man_6_a"}}}}
{if has_place "seat7" {if crew_in_place "seat7" {with_linked_entity "seat7" {call "ufb_gun_bind_man_6_a"}}}}
{if has_place "seat8" {if crew_in_place "seat8" {with_linked_entity "seat8" {call "ufb_gun_bind_man_6_a"}}}}
{if has_place "seat9" {if crew_in_place "seat9" {with_linked_entity "seat9" {call "ufb_gun_bind_man_6_a"}}}}
{if has_place "seat10" {if crew_in_place "seat10" {with_linked_entity "seat10" {call "ufb_gun_bind_man_6_a"}}}}
{if has_place "seat11" {if crew_in_place "seat11" {with_linked_entity "seat11" {call "ufb_gun_bind_man_6_a"}}}}
{if has_place "seat12" {if crew_in_place "seat12" {with_linked_entity "seat12" {call "ufb_gun_bind_man_6_a"}}}}
{if has_place "seat13" {if crew_in_place "seat13" {with_linked_entity "seat13" {call "ufb_gun_bind_man_6_a"}}}}
{if has_place "seat14" {if crew_in_place "seat14" {with_linked_entity "seat14" {call "ufb_gun_bind_man_6_a"}}}}
{if has_place "seat15" {if crew_in_place "seat15" {with_linked_entity "seat15" {call "ufb_gun_bind_man_6_a"}}}}
 }
 {on "ufb_gun_release_owner_6_a" {kill_delay "ufb_gun_owner_expiry"} {tags remove "_ufb_gun_owner_6_a"} {tags remove "_ufb_gun_escaped_6_a"} {tags remove "_ufb_gun_bound"}}
{on "ufb_gun_bind_7_a" sync
  {call "ufb_gun_left_cooldown_a"} {tags add "_ufb_gun_bound"}
  {kill_delay "ufb_gun_owner_expiry"}
  {delay 120 "ufb_gun_owner_expiry" {call "ufb_gun_release_owner_7_a"}}
  {spawn "ufb_smoke_screen_point" local_offset -700 0 0 constrain_after_dir {tags add "_ufb_gun_lease_7_a"} {delay 140 {delete}}}
  {if has_place "commander" {if crew_in_place "commander" {with_linked_entity "commander" {call "ufb_gun_bind_man_7_a"}}}}
{if has_place "driver" {if crew_in_place "driver" {with_linked_entity "driver" {call "ufb_gun_bind_man_7_a"}}}}
{if has_place "gunner" {if crew_in_place "gunner" {with_linked_entity "gunner" {call "ufb_gun_bind_man_7_a"}}}}
{if has_place "gunner1" {if crew_in_place "gunner1" {with_linked_entity "gunner1" {call "ufb_gun_bind_man_7_a"}}}}
{if has_place "gunner2" {if crew_in_place "gunner2" {with_linked_entity "gunner2" {call "ufb_gun_bind_man_7_a"}}}}
{if has_place "gunner3" {if crew_in_place "gunner3" {with_linked_entity "gunner3" {call "ufb_gun_bind_man_7_a"}}}}
{if has_place "gunner4" {if crew_in_place "gunner4" {with_linked_entity "gunner4" {call "ufb_gun_bind_man_7_a"}}}}
{if has_place "gunner5" {if crew_in_place "gunner5" {with_linked_entity "gunner5" {call "ufb_gun_bind_man_7_a"}}}}
{if has_place "gunner6" {if crew_in_place "gunner6" {with_linked_entity "gunner6" {call "ufb_gun_bind_man_7_a"}}}}
{if has_place "gunner7" {if crew_in_place "gunner7" {with_linked_entity "gunner7" {call "ufb_gun_bind_man_7_a"}}}}
{if has_place "gunner8" {if crew_in_place "gunner8" {with_linked_entity "gunner8" {call "ufb_gun_bind_man_7_a"}}}}
{if has_place "charger" {if crew_in_place "charger" {with_linked_entity "charger" {call "ufb_gun_bind_man_7_a"}}}}
{if has_place "charger1" {if crew_in_place "charger1" {with_linked_entity "charger1" {call "ufb_gun_bind_man_7_a"}}}}
{if has_place "charger2" {if crew_in_place "charger2" {with_linked_entity "charger2" {call "ufb_gun_bind_man_7_a"}}}}
{if has_place "charger3" {if crew_in_place "charger3" {with_linked_entity "charger3" {call "ufb_gun_bind_man_7_a"}}}}
{if has_place "charger4" {if crew_in_place "charger4" {with_linked_entity "charger4" {call "ufb_gun_bind_man_7_a"}}}}
{if has_place "charger5" {if crew_in_place "charger5" {with_linked_entity "charger5" {call "ufb_gun_bind_man_7_a"}}}}
{if has_place "charger6" {if crew_in_place "charger6" {with_linked_entity "charger6" {call "ufb_gun_bind_man_7_a"}}}}
{if has_place "charger7" {if crew_in_place "charger7" {with_linked_entity "charger7" {call "ufb_gun_bind_man_7_a"}}}}
{if has_place "charger8" {if crew_in_place "charger8" {with_linked_entity "charger8" {call "ufb_gun_bind_man_7_a"}}}}
{if has_place "loader" {if crew_in_place "loader" {with_linked_entity "loader" {call "ufb_gun_bind_man_7_a"}}}}
{if has_place "loader1" {if crew_in_place "loader1" {with_linked_entity "loader1" {call "ufb_gun_bind_man_7_a"}}}}
{if has_place "loader2" {if crew_in_place "loader2" {with_linked_entity "loader2" {call "ufb_gun_bind_man_7_a"}}}}
{if has_place "loader3" {if crew_in_place "loader3" {with_linked_entity "loader3" {call "ufb_gun_bind_man_7_a"}}}}
{if has_place "loader4" {if crew_in_place "loader4" {with_linked_entity "loader4" {call "ufb_gun_bind_man_7_a"}}}}
{if has_place "loader5" {if crew_in_place "loader5" {with_linked_entity "loader5" {call "ufb_gun_bind_man_7_a"}}}}
{if has_place "loader6" {if crew_in_place "loader6" {with_linked_entity "loader6" {call "ufb_gun_bind_man_7_a"}}}}
{if has_place "loader7" {if crew_in_place "loader7" {with_linked_entity "loader7" {call "ufb_gun_bind_man_7_a"}}}}
{if has_place "loader8" {if crew_in_place "loader8" {with_linked_entity "loader8" {call "ufb_gun_bind_man_7_a"}}}}
{if has_place "seat1" {if crew_in_place "seat1" {with_linked_entity "seat1" {call "ufb_gun_bind_man_7_a"}}}}
{if has_place "seat2" {if crew_in_place "seat2" {with_linked_entity "seat2" {call "ufb_gun_bind_man_7_a"}}}}
{if has_place "seat3" {if crew_in_place "seat3" {with_linked_entity "seat3" {call "ufb_gun_bind_man_7_a"}}}}
{if has_place "seat4" {if crew_in_place "seat4" {with_linked_entity "seat4" {call "ufb_gun_bind_man_7_a"}}}}
{if has_place "seat5" {if crew_in_place "seat5" {with_linked_entity "seat5" {call "ufb_gun_bind_man_7_a"}}}}
{if has_place "seat6" {if crew_in_place "seat6" {with_linked_entity "seat6" {call "ufb_gun_bind_man_7_a"}}}}
{if has_place "seat7" {if crew_in_place "seat7" {with_linked_entity "seat7" {call "ufb_gun_bind_man_7_a"}}}}
{if has_place "seat8" {if crew_in_place "seat8" {with_linked_entity "seat8" {call "ufb_gun_bind_man_7_a"}}}}
{if has_place "seat9" {if crew_in_place "seat9" {with_linked_entity "seat9" {call "ufb_gun_bind_man_7_a"}}}}
{if has_place "seat10" {if crew_in_place "seat10" {with_linked_entity "seat10" {call "ufb_gun_bind_man_7_a"}}}}
{if has_place "seat11" {if crew_in_place "seat11" {with_linked_entity "seat11" {call "ufb_gun_bind_man_7_a"}}}}
{if has_place "seat12" {if crew_in_place "seat12" {with_linked_entity "seat12" {call "ufb_gun_bind_man_7_a"}}}}
{if has_place "seat13" {if crew_in_place "seat13" {with_linked_entity "seat13" {call "ufb_gun_bind_man_7_a"}}}}
{if has_place "seat14" {if crew_in_place "seat14" {with_linked_entity "seat14" {call "ufb_gun_bind_man_7_a"}}}}
{if has_place "seat15" {if crew_in_place "seat15" {with_linked_entity "seat15" {call "ufb_gun_bind_man_7_a"}}}}
 }
 {on "ufb_gun_release_owner_7_a" {kill_delay "ufb_gun_owner_expiry"} {tags remove "_ufb_gun_owner_7_a"} {tags remove "_ufb_gun_escaped_7_a"} {tags remove "_ufb_gun_bound"}}
{on "ufb_gun_bind_8_a" sync
  {call "ufb_gun_left_cooldown_a"} {tags add "_ufb_gun_bound"}
  {kill_delay "ufb_gun_owner_expiry"}
  {delay 120 "ufb_gun_owner_expiry" {call "ufb_gun_release_owner_8_a"}}
  {spawn "ufb_smoke_screen_point" local_offset -700 0 0 constrain_after_dir {tags add "_ufb_gun_lease_8_a"} {delay 140 {delete}}}
  {if has_place "commander" {if crew_in_place "commander" {with_linked_entity "commander" {call "ufb_gun_bind_man_8_a"}}}}
{if has_place "driver" {if crew_in_place "driver" {with_linked_entity "driver" {call "ufb_gun_bind_man_8_a"}}}}
{if has_place "gunner" {if crew_in_place "gunner" {with_linked_entity "gunner" {call "ufb_gun_bind_man_8_a"}}}}
{if has_place "gunner1" {if crew_in_place "gunner1" {with_linked_entity "gunner1" {call "ufb_gun_bind_man_8_a"}}}}
{if has_place "gunner2" {if crew_in_place "gunner2" {with_linked_entity "gunner2" {call "ufb_gun_bind_man_8_a"}}}}
{if has_place "gunner3" {if crew_in_place "gunner3" {with_linked_entity "gunner3" {call "ufb_gun_bind_man_8_a"}}}}
{if has_place "gunner4" {if crew_in_place "gunner4" {with_linked_entity "gunner4" {call "ufb_gun_bind_man_8_a"}}}}
{if has_place "gunner5" {if crew_in_place "gunner5" {with_linked_entity "gunner5" {call "ufb_gun_bind_man_8_a"}}}}
{if has_place "gunner6" {if crew_in_place "gunner6" {with_linked_entity "gunner6" {call "ufb_gun_bind_man_8_a"}}}}
{if has_place "gunner7" {if crew_in_place "gunner7" {with_linked_entity "gunner7" {call "ufb_gun_bind_man_8_a"}}}}
{if has_place "gunner8" {if crew_in_place "gunner8" {with_linked_entity "gunner8" {call "ufb_gun_bind_man_8_a"}}}}
{if has_place "charger" {if crew_in_place "charger" {with_linked_entity "charger" {call "ufb_gun_bind_man_8_a"}}}}
{if has_place "charger1" {if crew_in_place "charger1" {with_linked_entity "charger1" {call "ufb_gun_bind_man_8_a"}}}}
{if has_place "charger2" {if crew_in_place "charger2" {with_linked_entity "charger2" {call "ufb_gun_bind_man_8_a"}}}}
{if has_place "charger3" {if crew_in_place "charger3" {with_linked_entity "charger3" {call "ufb_gun_bind_man_8_a"}}}}
{if has_place "charger4" {if crew_in_place "charger4" {with_linked_entity "charger4" {call "ufb_gun_bind_man_8_a"}}}}
{if has_place "charger5" {if crew_in_place "charger5" {with_linked_entity "charger5" {call "ufb_gun_bind_man_8_a"}}}}
{if has_place "charger6" {if crew_in_place "charger6" {with_linked_entity "charger6" {call "ufb_gun_bind_man_8_a"}}}}
{if has_place "charger7" {if crew_in_place "charger7" {with_linked_entity "charger7" {call "ufb_gun_bind_man_8_a"}}}}
{if has_place "charger8" {if crew_in_place "charger8" {with_linked_entity "charger8" {call "ufb_gun_bind_man_8_a"}}}}
{if has_place "loader" {if crew_in_place "loader" {with_linked_entity "loader" {call "ufb_gun_bind_man_8_a"}}}}
{if has_place "loader1" {if crew_in_place "loader1" {with_linked_entity "loader1" {call "ufb_gun_bind_man_8_a"}}}}
{if has_place "loader2" {if crew_in_place "loader2" {with_linked_entity "loader2" {call "ufb_gun_bind_man_8_a"}}}}
{if has_place "loader3" {if crew_in_place "loader3" {with_linked_entity "loader3" {call "ufb_gun_bind_man_8_a"}}}}
{if has_place "loader4" {if crew_in_place "loader4" {with_linked_entity "loader4" {call "ufb_gun_bind_man_8_a"}}}}
{if has_place "loader5" {if crew_in_place "loader5" {with_linked_entity "loader5" {call "ufb_gun_bind_man_8_a"}}}}
{if has_place "loader6" {if crew_in_place "loader6" {with_linked_entity "loader6" {call "ufb_gun_bind_man_8_a"}}}}
{if has_place "loader7" {if crew_in_place "loader7" {with_linked_entity "loader7" {call "ufb_gun_bind_man_8_a"}}}}
{if has_place "loader8" {if crew_in_place "loader8" {with_linked_entity "loader8" {call "ufb_gun_bind_man_8_a"}}}}
{if has_place "seat1" {if crew_in_place "seat1" {with_linked_entity "seat1" {call "ufb_gun_bind_man_8_a"}}}}
{if has_place "seat2" {if crew_in_place "seat2" {with_linked_entity "seat2" {call "ufb_gun_bind_man_8_a"}}}}
{if has_place "seat3" {if crew_in_place "seat3" {with_linked_entity "seat3" {call "ufb_gun_bind_man_8_a"}}}}
{if has_place "seat4" {if crew_in_place "seat4" {with_linked_entity "seat4" {call "ufb_gun_bind_man_8_a"}}}}
{if has_place "seat5" {if crew_in_place "seat5" {with_linked_entity "seat5" {call "ufb_gun_bind_man_8_a"}}}}
{if has_place "seat6" {if crew_in_place "seat6" {with_linked_entity "seat6" {call "ufb_gun_bind_man_8_a"}}}}
{if has_place "seat7" {if crew_in_place "seat7" {with_linked_entity "seat7" {call "ufb_gun_bind_man_8_a"}}}}
{if has_place "seat8" {if crew_in_place "seat8" {with_linked_entity "seat8" {call "ufb_gun_bind_man_8_a"}}}}
{if has_place "seat9" {if crew_in_place "seat9" {with_linked_entity "seat9" {call "ufb_gun_bind_man_8_a"}}}}
{if has_place "seat10" {if crew_in_place "seat10" {with_linked_entity "seat10" {call "ufb_gun_bind_man_8_a"}}}}
{if has_place "seat11" {if crew_in_place "seat11" {with_linked_entity "seat11" {call "ufb_gun_bind_man_8_a"}}}}
{if has_place "seat12" {if crew_in_place "seat12" {with_linked_entity "seat12" {call "ufb_gun_bind_man_8_a"}}}}
{if has_place "seat13" {if crew_in_place "seat13" {with_linked_entity "seat13" {call "ufb_gun_bind_man_8_a"}}}}
{if has_place "seat14" {if crew_in_place "seat14" {with_linked_entity "seat14" {call "ufb_gun_bind_man_8_a"}}}}
{if has_place "seat15" {if crew_in_place "seat15" {with_linked_entity "seat15" {call "ufb_gun_bind_man_8_a"}}}}
 }
 {on "ufb_gun_release_owner_8_a" {kill_delay "ufb_gun_owner_expiry"} {tags remove "_ufb_gun_owner_8_a"} {tags remove "_ufb_gun_escaped_8_a"} {tags remove "_ufb_gun_bound"}}
{on "ufb_gun_bind_9_a" sync
  {call "ufb_gun_left_cooldown_a"} {tags add "_ufb_gun_bound"}
  {kill_delay "ufb_gun_owner_expiry"}
  {delay 120 "ufb_gun_owner_expiry" {call "ufb_gun_release_owner_9_a"}}
  {spawn "ufb_smoke_screen_point" local_offset -700 0 0 constrain_after_dir {tags add "_ufb_gun_lease_9_a"} {delay 140 {delete}}}
  {if has_place "commander" {if crew_in_place "commander" {with_linked_entity "commander" {call "ufb_gun_bind_man_9_a"}}}}
{if has_place "driver" {if crew_in_place "driver" {with_linked_entity "driver" {call "ufb_gun_bind_man_9_a"}}}}
{if has_place "gunner" {if crew_in_place "gunner" {with_linked_entity "gunner" {call "ufb_gun_bind_man_9_a"}}}}
{if has_place "gunner1" {if crew_in_place "gunner1" {with_linked_entity "gunner1" {call "ufb_gun_bind_man_9_a"}}}}
{if has_place "gunner2" {if crew_in_place "gunner2" {with_linked_entity "gunner2" {call "ufb_gun_bind_man_9_a"}}}}
{if has_place "gunner3" {if crew_in_place "gunner3" {with_linked_entity "gunner3" {call "ufb_gun_bind_man_9_a"}}}}
{if has_place "gunner4" {if crew_in_place "gunner4" {with_linked_entity "gunner4" {call "ufb_gun_bind_man_9_a"}}}}
{if has_place "gunner5" {if crew_in_place "gunner5" {with_linked_entity "gunner5" {call "ufb_gun_bind_man_9_a"}}}}
{if has_place "gunner6" {if crew_in_place "gunner6" {with_linked_entity "gunner6" {call "ufb_gun_bind_man_9_a"}}}}
{if has_place "gunner7" {if crew_in_place "gunner7" {with_linked_entity "gunner7" {call "ufb_gun_bind_man_9_a"}}}}
{if has_place "gunner8" {if crew_in_place "gunner8" {with_linked_entity "gunner8" {call "ufb_gun_bind_man_9_a"}}}}
{if has_place "charger" {if crew_in_place "charger" {with_linked_entity "charger" {call "ufb_gun_bind_man_9_a"}}}}
{if has_place "charger1" {if crew_in_place "charger1" {with_linked_entity "charger1" {call "ufb_gun_bind_man_9_a"}}}}
{if has_place "charger2" {if crew_in_place "charger2" {with_linked_entity "charger2" {call "ufb_gun_bind_man_9_a"}}}}
{if has_place "charger3" {if crew_in_place "charger3" {with_linked_entity "charger3" {call "ufb_gun_bind_man_9_a"}}}}
{if has_place "charger4" {if crew_in_place "charger4" {with_linked_entity "charger4" {call "ufb_gun_bind_man_9_a"}}}}
{if has_place "charger5" {if crew_in_place "charger5" {with_linked_entity "charger5" {call "ufb_gun_bind_man_9_a"}}}}
{if has_place "charger6" {if crew_in_place "charger6" {with_linked_entity "charger6" {call "ufb_gun_bind_man_9_a"}}}}
{if has_place "charger7" {if crew_in_place "charger7" {with_linked_entity "charger7" {call "ufb_gun_bind_man_9_a"}}}}
{if has_place "charger8" {if crew_in_place "charger8" {with_linked_entity "charger8" {call "ufb_gun_bind_man_9_a"}}}}
{if has_place "loader" {if crew_in_place "loader" {with_linked_entity "loader" {call "ufb_gun_bind_man_9_a"}}}}
{if has_place "loader1" {if crew_in_place "loader1" {with_linked_entity "loader1" {call "ufb_gun_bind_man_9_a"}}}}
{if has_place "loader2" {if crew_in_place "loader2" {with_linked_entity "loader2" {call "ufb_gun_bind_man_9_a"}}}}
{if has_place "loader3" {if crew_in_place "loader3" {with_linked_entity "loader3" {call "ufb_gun_bind_man_9_a"}}}}
{if has_place "loader4" {if crew_in_place "loader4" {with_linked_entity "loader4" {call "ufb_gun_bind_man_9_a"}}}}
{if has_place "loader5" {if crew_in_place "loader5" {with_linked_entity "loader5" {call "ufb_gun_bind_man_9_a"}}}}
{if has_place "loader6" {if crew_in_place "loader6" {with_linked_entity "loader6" {call "ufb_gun_bind_man_9_a"}}}}
{if has_place "loader7" {if crew_in_place "loader7" {with_linked_entity "loader7" {call "ufb_gun_bind_man_9_a"}}}}
{if has_place "loader8" {if crew_in_place "loader8" {with_linked_entity "loader8" {call "ufb_gun_bind_man_9_a"}}}}
{if has_place "seat1" {if crew_in_place "seat1" {with_linked_entity "seat1" {call "ufb_gun_bind_man_9_a"}}}}
{if has_place "seat2" {if crew_in_place "seat2" {with_linked_entity "seat2" {call "ufb_gun_bind_man_9_a"}}}}
{if has_place "seat3" {if crew_in_place "seat3" {with_linked_entity "seat3" {call "ufb_gun_bind_man_9_a"}}}}
{if has_place "seat4" {if crew_in_place "seat4" {with_linked_entity "seat4" {call "ufb_gun_bind_man_9_a"}}}}
{if has_place "seat5" {if crew_in_place "seat5" {with_linked_entity "seat5" {call "ufb_gun_bind_man_9_a"}}}}
{if has_place "seat6" {if crew_in_place "seat6" {with_linked_entity "seat6" {call "ufb_gun_bind_man_9_a"}}}}
{if has_place "seat7" {if crew_in_place "seat7" {with_linked_entity "seat7" {call "ufb_gun_bind_man_9_a"}}}}
{if has_place "seat8" {if crew_in_place "seat8" {with_linked_entity "seat8" {call "ufb_gun_bind_man_9_a"}}}}
{if has_place "seat9" {if crew_in_place "seat9" {with_linked_entity "seat9" {call "ufb_gun_bind_man_9_a"}}}}
{if has_place "seat10" {if crew_in_place "seat10" {with_linked_entity "seat10" {call "ufb_gun_bind_man_9_a"}}}}
{if has_place "seat11" {if crew_in_place "seat11" {with_linked_entity "seat11" {call "ufb_gun_bind_man_9_a"}}}}
{if has_place "seat12" {if crew_in_place "seat12" {with_linked_entity "seat12" {call "ufb_gun_bind_man_9_a"}}}}
{if has_place "seat13" {if crew_in_place "seat13" {with_linked_entity "seat13" {call "ufb_gun_bind_man_9_a"}}}}
{if has_place "seat14" {if crew_in_place "seat14" {with_linked_entity "seat14" {call "ufb_gun_bind_man_9_a"}}}}
{if has_place "seat15" {if crew_in_place "seat15" {with_linked_entity "seat15" {call "ufb_gun_bind_man_9_a"}}}}
 }
 {on "ufb_gun_release_owner_9_a" {kill_delay "ufb_gun_owner_expiry"} {tags remove "_ufb_gun_owner_9_a"} {tags remove "_ufb_gun_escaped_9_a"} {tags remove "_ufb_gun_bound"}}
{on "ufb_gun_bind_10_a" sync
  {call "ufb_gun_left_cooldown_a"} {tags add "_ufb_gun_bound"}
  {kill_delay "ufb_gun_owner_expiry"}
  {delay 120 "ufb_gun_owner_expiry" {call "ufb_gun_release_owner_10_a"}}
  {spawn "ufb_smoke_screen_point" local_offset -700 0 0 constrain_after_dir {tags add "_ufb_gun_lease_10_a"} {delay 140 {delete}}}
  {if has_place "commander" {if crew_in_place "commander" {with_linked_entity "commander" {call "ufb_gun_bind_man_10_a"}}}}
{if has_place "driver" {if crew_in_place "driver" {with_linked_entity "driver" {call "ufb_gun_bind_man_10_a"}}}}
{if has_place "gunner" {if crew_in_place "gunner" {with_linked_entity "gunner" {call "ufb_gun_bind_man_10_a"}}}}
{if has_place "gunner1" {if crew_in_place "gunner1" {with_linked_entity "gunner1" {call "ufb_gun_bind_man_10_a"}}}}
{if has_place "gunner2" {if crew_in_place "gunner2" {with_linked_entity "gunner2" {call "ufb_gun_bind_man_10_a"}}}}
{if has_place "gunner3" {if crew_in_place "gunner3" {with_linked_entity "gunner3" {call "ufb_gun_bind_man_10_a"}}}}
{if has_place "gunner4" {if crew_in_place "gunner4" {with_linked_entity "gunner4" {call "ufb_gun_bind_man_10_a"}}}}
{if has_place "gunner5" {if crew_in_place "gunner5" {with_linked_entity "gunner5" {call "ufb_gun_bind_man_10_a"}}}}
{if has_place "gunner6" {if crew_in_place "gunner6" {with_linked_entity "gunner6" {call "ufb_gun_bind_man_10_a"}}}}
{if has_place "gunner7" {if crew_in_place "gunner7" {with_linked_entity "gunner7" {call "ufb_gun_bind_man_10_a"}}}}
{if has_place "gunner8" {if crew_in_place "gunner8" {with_linked_entity "gunner8" {call "ufb_gun_bind_man_10_a"}}}}
{if has_place "charger" {if crew_in_place "charger" {with_linked_entity "charger" {call "ufb_gun_bind_man_10_a"}}}}
{if has_place "charger1" {if crew_in_place "charger1" {with_linked_entity "charger1" {call "ufb_gun_bind_man_10_a"}}}}
{if has_place "charger2" {if crew_in_place "charger2" {with_linked_entity "charger2" {call "ufb_gun_bind_man_10_a"}}}}
{if has_place "charger3" {if crew_in_place "charger3" {with_linked_entity "charger3" {call "ufb_gun_bind_man_10_a"}}}}
{if has_place "charger4" {if crew_in_place "charger4" {with_linked_entity "charger4" {call "ufb_gun_bind_man_10_a"}}}}
{if has_place "charger5" {if crew_in_place "charger5" {with_linked_entity "charger5" {call "ufb_gun_bind_man_10_a"}}}}
{if has_place "charger6" {if crew_in_place "charger6" {with_linked_entity "charger6" {call "ufb_gun_bind_man_10_a"}}}}
{if has_place "charger7" {if crew_in_place "charger7" {with_linked_entity "charger7" {call "ufb_gun_bind_man_10_a"}}}}
{if has_place "charger8" {if crew_in_place "charger8" {with_linked_entity "charger8" {call "ufb_gun_bind_man_10_a"}}}}
{if has_place "loader" {if crew_in_place "loader" {with_linked_entity "loader" {call "ufb_gun_bind_man_10_a"}}}}
{if has_place "loader1" {if crew_in_place "loader1" {with_linked_entity "loader1" {call "ufb_gun_bind_man_10_a"}}}}
{if has_place "loader2" {if crew_in_place "loader2" {with_linked_entity "loader2" {call "ufb_gun_bind_man_10_a"}}}}
{if has_place "loader3" {if crew_in_place "loader3" {with_linked_entity "loader3" {call "ufb_gun_bind_man_10_a"}}}}
{if has_place "loader4" {if crew_in_place "loader4" {with_linked_entity "loader4" {call "ufb_gun_bind_man_10_a"}}}}
{if has_place "loader5" {if crew_in_place "loader5" {with_linked_entity "loader5" {call "ufb_gun_bind_man_10_a"}}}}
{if has_place "loader6" {if crew_in_place "loader6" {with_linked_entity "loader6" {call "ufb_gun_bind_man_10_a"}}}}
{if has_place "loader7" {if crew_in_place "loader7" {with_linked_entity "loader7" {call "ufb_gun_bind_man_10_a"}}}}
{if has_place "loader8" {if crew_in_place "loader8" {with_linked_entity "loader8" {call "ufb_gun_bind_man_10_a"}}}}
{if has_place "seat1" {if crew_in_place "seat1" {with_linked_entity "seat1" {call "ufb_gun_bind_man_10_a"}}}}
{if has_place "seat2" {if crew_in_place "seat2" {with_linked_entity "seat2" {call "ufb_gun_bind_man_10_a"}}}}
{if has_place "seat3" {if crew_in_place "seat3" {with_linked_entity "seat3" {call "ufb_gun_bind_man_10_a"}}}}
{if has_place "seat4" {if crew_in_place "seat4" {with_linked_entity "seat4" {call "ufb_gun_bind_man_10_a"}}}}
{if has_place "seat5" {if crew_in_place "seat5" {with_linked_entity "seat5" {call "ufb_gun_bind_man_10_a"}}}}
{if has_place "seat6" {if crew_in_place "seat6" {with_linked_entity "seat6" {call "ufb_gun_bind_man_10_a"}}}}
{if has_place "seat7" {if crew_in_place "seat7" {with_linked_entity "seat7" {call "ufb_gun_bind_man_10_a"}}}}
{if has_place "seat8" {if crew_in_place "seat8" {with_linked_entity "seat8" {call "ufb_gun_bind_man_10_a"}}}}
{if has_place "seat9" {if crew_in_place "seat9" {with_linked_entity "seat9" {call "ufb_gun_bind_man_10_a"}}}}
{if has_place "seat10" {if crew_in_place "seat10" {with_linked_entity "seat10" {call "ufb_gun_bind_man_10_a"}}}}
{if has_place "seat11" {if crew_in_place "seat11" {with_linked_entity "seat11" {call "ufb_gun_bind_man_10_a"}}}}
{if has_place "seat12" {if crew_in_place "seat12" {with_linked_entity "seat12" {call "ufb_gun_bind_man_10_a"}}}}
{if has_place "seat13" {if crew_in_place "seat13" {with_linked_entity "seat13" {call "ufb_gun_bind_man_10_a"}}}}
{if has_place "seat14" {if crew_in_place "seat14" {with_linked_entity "seat14" {call "ufb_gun_bind_man_10_a"}}}}
{if has_place "seat15" {if crew_in_place "seat15" {with_linked_entity "seat15" {call "ufb_gun_bind_man_10_a"}}}}
 }
 {on "ufb_gun_release_owner_10_a" {kill_delay "ufb_gun_owner_expiry"} {tags remove "_ufb_gun_owner_10_a"} {tags remove "_ufb_gun_escaped_10_a"} {tags remove "_ufb_gun_bound"}}
{on "ufb_gun_bind_11_a" sync
  {call "ufb_gun_left_cooldown_a"} {tags add "_ufb_gun_bound"}
  {kill_delay "ufb_gun_owner_expiry"}
  {delay 120 "ufb_gun_owner_expiry" {call "ufb_gun_release_owner_11_a"}}
  {spawn "ufb_smoke_screen_point" local_offset -700 0 0 constrain_after_dir {tags add "_ufb_gun_lease_11_a"} {delay 140 {delete}}}
  {if has_place "commander" {if crew_in_place "commander" {with_linked_entity "commander" {call "ufb_gun_bind_man_11_a"}}}}
{if has_place "driver" {if crew_in_place "driver" {with_linked_entity "driver" {call "ufb_gun_bind_man_11_a"}}}}
{if has_place "gunner" {if crew_in_place "gunner" {with_linked_entity "gunner" {call "ufb_gun_bind_man_11_a"}}}}
{if has_place "gunner1" {if crew_in_place "gunner1" {with_linked_entity "gunner1" {call "ufb_gun_bind_man_11_a"}}}}
{if has_place "gunner2" {if crew_in_place "gunner2" {with_linked_entity "gunner2" {call "ufb_gun_bind_man_11_a"}}}}
{if has_place "gunner3" {if crew_in_place "gunner3" {with_linked_entity "gunner3" {call "ufb_gun_bind_man_11_a"}}}}
{if has_place "gunner4" {if crew_in_place "gunner4" {with_linked_entity "gunner4" {call "ufb_gun_bind_man_11_a"}}}}
{if has_place "gunner5" {if crew_in_place "gunner5" {with_linked_entity "gunner5" {call "ufb_gun_bind_man_11_a"}}}}
{if has_place "gunner6" {if crew_in_place "gunner6" {with_linked_entity "gunner6" {call "ufb_gun_bind_man_11_a"}}}}
{if has_place "gunner7" {if crew_in_place "gunner7" {with_linked_entity "gunner7" {call "ufb_gun_bind_man_11_a"}}}}
{if has_place "gunner8" {if crew_in_place "gunner8" {with_linked_entity "gunner8" {call "ufb_gun_bind_man_11_a"}}}}
{if has_place "charger" {if crew_in_place "charger" {with_linked_entity "charger" {call "ufb_gun_bind_man_11_a"}}}}
{if has_place "charger1" {if crew_in_place "charger1" {with_linked_entity "charger1" {call "ufb_gun_bind_man_11_a"}}}}
{if has_place "charger2" {if crew_in_place "charger2" {with_linked_entity "charger2" {call "ufb_gun_bind_man_11_a"}}}}
{if has_place "charger3" {if crew_in_place "charger3" {with_linked_entity "charger3" {call "ufb_gun_bind_man_11_a"}}}}
{if has_place "charger4" {if crew_in_place "charger4" {with_linked_entity "charger4" {call "ufb_gun_bind_man_11_a"}}}}
{if has_place "charger5" {if crew_in_place "charger5" {with_linked_entity "charger5" {call "ufb_gun_bind_man_11_a"}}}}
{if has_place "charger6" {if crew_in_place "charger6" {with_linked_entity "charger6" {call "ufb_gun_bind_man_11_a"}}}}
{if has_place "charger7" {if crew_in_place "charger7" {with_linked_entity "charger7" {call "ufb_gun_bind_man_11_a"}}}}
{if has_place "charger8" {if crew_in_place "charger8" {with_linked_entity "charger8" {call "ufb_gun_bind_man_11_a"}}}}
{if has_place "loader" {if crew_in_place "loader" {with_linked_entity "loader" {call "ufb_gun_bind_man_11_a"}}}}
{if has_place "loader1" {if crew_in_place "loader1" {with_linked_entity "loader1" {call "ufb_gun_bind_man_11_a"}}}}
{if has_place "loader2" {if crew_in_place "loader2" {with_linked_entity "loader2" {call "ufb_gun_bind_man_11_a"}}}}
{if has_place "loader3" {if crew_in_place "loader3" {with_linked_entity "loader3" {call "ufb_gun_bind_man_11_a"}}}}
{if has_place "loader4" {if crew_in_place "loader4" {with_linked_entity "loader4" {call "ufb_gun_bind_man_11_a"}}}}
{if has_place "loader5" {if crew_in_place "loader5" {with_linked_entity "loader5" {call "ufb_gun_bind_man_11_a"}}}}
{if has_place "loader6" {if crew_in_place "loader6" {with_linked_entity "loader6" {call "ufb_gun_bind_man_11_a"}}}}
{if has_place "loader7" {if crew_in_place "loader7" {with_linked_entity "loader7" {call "ufb_gun_bind_man_11_a"}}}}
{if has_place "loader8" {if crew_in_place "loader8" {with_linked_entity "loader8" {call "ufb_gun_bind_man_11_a"}}}}
{if has_place "seat1" {if crew_in_place "seat1" {with_linked_entity "seat1" {call "ufb_gun_bind_man_11_a"}}}}
{if has_place "seat2" {if crew_in_place "seat2" {with_linked_entity "seat2" {call "ufb_gun_bind_man_11_a"}}}}
{if has_place "seat3" {if crew_in_place "seat3" {with_linked_entity "seat3" {call "ufb_gun_bind_man_11_a"}}}}
{if has_place "seat4" {if crew_in_place "seat4" {with_linked_entity "seat4" {call "ufb_gun_bind_man_11_a"}}}}
{if has_place "seat5" {if crew_in_place "seat5" {with_linked_entity "seat5" {call "ufb_gun_bind_man_11_a"}}}}
{if has_place "seat6" {if crew_in_place "seat6" {with_linked_entity "seat6" {call "ufb_gun_bind_man_11_a"}}}}
{if has_place "seat7" {if crew_in_place "seat7" {with_linked_entity "seat7" {call "ufb_gun_bind_man_11_a"}}}}
{if has_place "seat8" {if crew_in_place "seat8" {with_linked_entity "seat8" {call "ufb_gun_bind_man_11_a"}}}}
{if has_place "seat9" {if crew_in_place "seat9" {with_linked_entity "seat9" {call "ufb_gun_bind_man_11_a"}}}}
{if has_place "seat10" {if crew_in_place "seat10" {with_linked_entity "seat10" {call "ufb_gun_bind_man_11_a"}}}}
{if has_place "seat11" {if crew_in_place "seat11" {with_linked_entity "seat11" {call "ufb_gun_bind_man_11_a"}}}}
{if has_place "seat12" {if crew_in_place "seat12" {with_linked_entity "seat12" {call "ufb_gun_bind_man_11_a"}}}}
{if has_place "seat13" {if crew_in_place "seat13" {with_linked_entity "seat13" {call "ufb_gun_bind_man_11_a"}}}}
{if has_place "seat14" {if crew_in_place "seat14" {with_linked_entity "seat14" {call "ufb_gun_bind_man_11_a"}}}}
{if has_place "seat15" {if crew_in_place "seat15" {with_linked_entity "seat15" {call "ufb_gun_bind_man_11_a"}}}}
 }
 {on "ufb_gun_release_owner_11_a" {kill_delay "ufb_gun_owner_expiry"} {tags remove "_ufb_gun_owner_11_a"} {tags remove "_ufb_gun_escaped_11_a"} {tags remove "_ufb_gun_bound"}}
{on "ufb_gun_bind_12_a" sync
  {call "ufb_gun_left_cooldown_a"} {tags add "_ufb_gun_bound"}
  {kill_delay "ufb_gun_owner_expiry"}
  {delay 120 "ufb_gun_owner_expiry" {call "ufb_gun_release_owner_12_a"}}
  {spawn "ufb_smoke_screen_point" local_offset -700 0 0 constrain_after_dir {tags add "_ufb_gun_lease_12_a"} {delay 140 {delete}}}
  {if has_place "commander" {if crew_in_place "commander" {with_linked_entity "commander" {call "ufb_gun_bind_man_12_a"}}}}
{if has_place "driver" {if crew_in_place "driver" {with_linked_entity "driver" {call "ufb_gun_bind_man_12_a"}}}}
{if has_place "gunner" {if crew_in_place "gunner" {with_linked_entity "gunner" {call "ufb_gun_bind_man_12_a"}}}}
{if has_place "gunner1" {if crew_in_place "gunner1" {with_linked_entity "gunner1" {call "ufb_gun_bind_man_12_a"}}}}
{if has_place "gunner2" {if crew_in_place "gunner2" {with_linked_entity "gunner2" {call "ufb_gun_bind_man_12_a"}}}}
{if has_place "gunner3" {if crew_in_place "gunner3" {with_linked_entity "gunner3" {call "ufb_gun_bind_man_12_a"}}}}
{if has_place "gunner4" {if crew_in_place "gunner4" {with_linked_entity "gunner4" {call "ufb_gun_bind_man_12_a"}}}}
{if has_place "gunner5" {if crew_in_place "gunner5" {with_linked_entity "gunner5" {call "ufb_gun_bind_man_12_a"}}}}
{if has_place "gunner6" {if crew_in_place "gunner6" {with_linked_entity "gunner6" {call "ufb_gun_bind_man_12_a"}}}}
{if has_place "gunner7" {if crew_in_place "gunner7" {with_linked_entity "gunner7" {call "ufb_gun_bind_man_12_a"}}}}
{if has_place "gunner8" {if crew_in_place "gunner8" {with_linked_entity "gunner8" {call "ufb_gun_bind_man_12_a"}}}}
{if has_place "charger" {if crew_in_place "charger" {with_linked_entity "charger" {call "ufb_gun_bind_man_12_a"}}}}
{if has_place "charger1" {if crew_in_place "charger1" {with_linked_entity "charger1" {call "ufb_gun_bind_man_12_a"}}}}
{if has_place "charger2" {if crew_in_place "charger2" {with_linked_entity "charger2" {call "ufb_gun_bind_man_12_a"}}}}
{if has_place "charger3" {if crew_in_place "charger3" {with_linked_entity "charger3" {call "ufb_gun_bind_man_12_a"}}}}
{if has_place "charger4" {if crew_in_place "charger4" {with_linked_entity "charger4" {call "ufb_gun_bind_man_12_a"}}}}
{if has_place "charger5" {if crew_in_place "charger5" {with_linked_entity "charger5" {call "ufb_gun_bind_man_12_a"}}}}
{if has_place "charger6" {if crew_in_place "charger6" {with_linked_entity "charger6" {call "ufb_gun_bind_man_12_a"}}}}
{if has_place "charger7" {if crew_in_place "charger7" {with_linked_entity "charger7" {call "ufb_gun_bind_man_12_a"}}}}
{if has_place "charger8" {if crew_in_place "charger8" {with_linked_entity "charger8" {call "ufb_gun_bind_man_12_a"}}}}
{if has_place "loader" {if crew_in_place "loader" {with_linked_entity "loader" {call "ufb_gun_bind_man_12_a"}}}}
{if has_place "loader1" {if crew_in_place "loader1" {with_linked_entity "loader1" {call "ufb_gun_bind_man_12_a"}}}}
{if has_place "loader2" {if crew_in_place "loader2" {with_linked_entity "loader2" {call "ufb_gun_bind_man_12_a"}}}}
{if has_place "loader3" {if crew_in_place "loader3" {with_linked_entity "loader3" {call "ufb_gun_bind_man_12_a"}}}}
{if has_place "loader4" {if crew_in_place "loader4" {with_linked_entity "loader4" {call "ufb_gun_bind_man_12_a"}}}}
{if has_place "loader5" {if crew_in_place "loader5" {with_linked_entity "loader5" {call "ufb_gun_bind_man_12_a"}}}}
{if has_place "loader6" {if crew_in_place "loader6" {with_linked_entity "loader6" {call "ufb_gun_bind_man_12_a"}}}}
{if has_place "loader7" {if crew_in_place "loader7" {with_linked_entity "loader7" {call "ufb_gun_bind_man_12_a"}}}}
{if has_place "loader8" {if crew_in_place "loader8" {with_linked_entity "loader8" {call "ufb_gun_bind_man_12_a"}}}}
{if has_place "seat1" {if crew_in_place "seat1" {with_linked_entity "seat1" {call "ufb_gun_bind_man_12_a"}}}}
{if has_place "seat2" {if crew_in_place "seat2" {with_linked_entity "seat2" {call "ufb_gun_bind_man_12_a"}}}}
{if has_place "seat3" {if crew_in_place "seat3" {with_linked_entity "seat3" {call "ufb_gun_bind_man_12_a"}}}}
{if has_place "seat4" {if crew_in_place "seat4" {with_linked_entity "seat4" {call "ufb_gun_bind_man_12_a"}}}}
{if has_place "seat5" {if crew_in_place "seat5" {with_linked_entity "seat5" {call "ufb_gun_bind_man_12_a"}}}}
{if has_place "seat6" {if crew_in_place "seat6" {with_linked_entity "seat6" {call "ufb_gun_bind_man_12_a"}}}}
{if has_place "seat7" {if crew_in_place "seat7" {with_linked_entity "seat7" {call "ufb_gun_bind_man_12_a"}}}}
{if has_place "seat8" {if crew_in_place "seat8" {with_linked_entity "seat8" {call "ufb_gun_bind_man_12_a"}}}}
{if has_place "seat9" {if crew_in_place "seat9" {with_linked_entity "seat9" {call "ufb_gun_bind_man_12_a"}}}}
{if has_place "seat10" {if crew_in_place "seat10" {with_linked_entity "seat10" {call "ufb_gun_bind_man_12_a"}}}}
{if has_place "seat11" {if crew_in_place "seat11" {with_linked_entity "seat11" {call "ufb_gun_bind_man_12_a"}}}}
{if has_place "seat12" {if crew_in_place "seat12" {with_linked_entity "seat12" {call "ufb_gun_bind_man_12_a"}}}}
{if has_place "seat13" {if crew_in_place "seat13" {with_linked_entity "seat13" {call "ufb_gun_bind_man_12_a"}}}}
{if has_place "seat14" {if crew_in_place "seat14" {with_linked_entity "seat14" {call "ufb_gun_bind_man_12_a"}}}}
{if has_place "seat15" {if crew_in_place "seat15" {with_linked_entity "seat15" {call "ufb_gun_bind_man_12_a"}}}}
 }
 {on "ufb_gun_release_owner_12_a" {kill_delay "ufb_gun_owner_expiry"} {tags remove "_ufb_gun_owner_12_a"} {tags remove "_ufb_gun_escaped_12_a"} {tags remove "_ufb_gun_bound"}}
{on "ufb_gun_bind_13_a" sync
  {call "ufb_gun_left_cooldown_a"} {tags add "_ufb_gun_bound"}
  {kill_delay "ufb_gun_owner_expiry"}
  {delay 120 "ufb_gun_owner_expiry" {call "ufb_gun_release_owner_13_a"}}
  {spawn "ufb_smoke_screen_point" local_offset -700 0 0 constrain_after_dir {tags add "_ufb_gun_lease_13_a"} {delay 140 {delete}}}
  {if has_place "commander" {if crew_in_place "commander" {with_linked_entity "commander" {call "ufb_gun_bind_man_13_a"}}}}
{if has_place "driver" {if crew_in_place "driver" {with_linked_entity "driver" {call "ufb_gun_bind_man_13_a"}}}}
{if has_place "gunner" {if crew_in_place "gunner" {with_linked_entity "gunner" {call "ufb_gun_bind_man_13_a"}}}}
{if has_place "gunner1" {if crew_in_place "gunner1" {with_linked_entity "gunner1" {call "ufb_gun_bind_man_13_a"}}}}
{if has_place "gunner2" {if crew_in_place "gunner2" {with_linked_entity "gunner2" {call "ufb_gun_bind_man_13_a"}}}}
{if has_place "gunner3" {if crew_in_place "gunner3" {with_linked_entity "gunner3" {call "ufb_gun_bind_man_13_a"}}}}
{if has_place "gunner4" {if crew_in_place "gunner4" {with_linked_entity "gunner4" {call "ufb_gun_bind_man_13_a"}}}}
{if has_place "gunner5" {if crew_in_place "gunner5" {with_linked_entity "gunner5" {call "ufb_gun_bind_man_13_a"}}}}
{if has_place "gunner6" {if crew_in_place "gunner6" {with_linked_entity "gunner6" {call "ufb_gun_bind_man_13_a"}}}}
{if has_place "gunner7" {if crew_in_place "gunner7" {with_linked_entity "gunner7" {call "ufb_gun_bind_man_13_a"}}}}
{if has_place "gunner8" {if crew_in_place "gunner8" {with_linked_entity "gunner8" {call "ufb_gun_bind_man_13_a"}}}}
{if has_place "charger" {if crew_in_place "charger" {with_linked_entity "charger" {call "ufb_gun_bind_man_13_a"}}}}
{if has_place "charger1" {if crew_in_place "charger1" {with_linked_entity "charger1" {call "ufb_gun_bind_man_13_a"}}}}
{if has_place "charger2" {if crew_in_place "charger2" {with_linked_entity "charger2" {call "ufb_gun_bind_man_13_a"}}}}
{if has_place "charger3" {if crew_in_place "charger3" {with_linked_entity "charger3" {call "ufb_gun_bind_man_13_a"}}}}
{if has_place "charger4" {if crew_in_place "charger4" {with_linked_entity "charger4" {call "ufb_gun_bind_man_13_a"}}}}
{if has_place "charger5" {if crew_in_place "charger5" {with_linked_entity "charger5" {call "ufb_gun_bind_man_13_a"}}}}
{if has_place "charger6" {if crew_in_place "charger6" {with_linked_entity "charger6" {call "ufb_gun_bind_man_13_a"}}}}
{if has_place "charger7" {if crew_in_place "charger7" {with_linked_entity "charger7" {call "ufb_gun_bind_man_13_a"}}}}
{if has_place "charger8" {if crew_in_place "charger8" {with_linked_entity "charger8" {call "ufb_gun_bind_man_13_a"}}}}
{if has_place "loader" {if crew_in_place "loader" {with_linked_entity "loader" {call "ufb_gun_bind_man_13_a"}}}}
{if has_place "loader1" {if crew_in_place "loader1" {with_linked_entity "loader1" {call "ufb_gun_bind_man_13_a"}}}}
{if has_place "loader2" {if crew_in_place "loader2" {with_linked_entity "loader2" {call "ufb_gun_bind_man_13_a"}}}}
{if has_place "loader3" {if crew_in_place "loader3" {with_linked_entity "loader3" {call "ufb_gun_bind_man_13_a"}}}}
{if has_place "loader4" {if crew_in_place "loader4" {with_linked_entity "loader4" {call "ufb_gun_bind_man_13_a"}}}}
{if has_place "loader5" {if crew_in_place "loader5" {with_linked_entity "loader5" {call "ufb_gun_bind_man_13_a"}}}}
{if has_place "loader6" {if crew_in_place "loader6" {with_linked_entity "loader6" {call "ufb_gun_bind_man_13_a"}}}}
{if has_place "loader7" {if crew_in_place "loader7" {with_linked_entity "loader7" {call "ufb_gun_bind_man_13_a"}}}}
{if has_place "loader8" {if crew_in_place "loader8" {with_linked_entity "loader8" {call "ufb_gun_bind_man_13_a"}}}}
{if has_place "seat1" {if crew_in_place "seat1" {with_linked_entity "seat1" {call "ufb_gun_bind_man_13_a"}}}}
{if has_place "seat2" {if crew_in_place "seat2" {with_linked_entity "seat2" {call "ufb_gun_bind_man_13_a"}}}}
{if has_place "seat3" {if crew_in_place "seat3" {with_linked_entity "seat3" {call "ufb_gun_bind_man_13_a"}}}}
{if has_place "seat4" {if crew_in_place "seat4" {with_linked_entity "seat4" {call "ufb_gun_bind_man_13_a"}}}}
{if has_place "seat5" {if crew_in_place "seat5" {with_linked_entity "seat5" {call "ufb_gun_bind_man_13_a"}}}}
{if has_place "seat6" {if crew_in_place "seat6" {with_linked_entity "seat6" {call "ufb_gun_bind_man_13_a"}}}}
{if has_place "seat7" {if crew_in_place "seat7" {with_linked_entity "seat7" {call "ufb_gun_bind_man_13_a"}}}}
{if has_place "seat8" {if crew_in_place "seat8" {with_linked_entity "seat8" {call "ufb_gun_bind_man_13_a"}}}}
{if has_place "seat9" {if crew_in_place "seat9" {with_linked_entity "seat9" {call "ufb_gun_bind_man_13_a"}}}}
{if has_place "seat10" {if crew_in_place "seat10" {with_linked_entity "seat10" {call "ufb_gun_bind_man_13_a"}}}}
{if has_place "seat11" {if crew_in_place "seat11" {with_linked_entity "seat11" {call "ufb_gun_bind_man_13_a"}}}}
{if has_place "seat12" {if crew_in_place "seat12" {with_linked_entity "seat12" {call "ufb_gun_bind_man_13_a"}}}}
{if has_place "seat13" {if crew_in_place "seat13" {with_linked_entity "seat13" {call "ufb_gun_bind_man_13_a"}}}}
{if has_place "seat14" {if crew_in_place "seat14" {with_linked_entity "seat14" {call "ufb_gun_bind_man_13_a"}}}}
{if has_place "seat15" {if crew_in_place "seat15" {with_linked_entity "seat15" {call "ufb_gun_bind_man_13_a"}}}}
 }
 {on "ufb_gun_release_owner_13_a" {kill_delay "ufb_gun_owner_expiry"} {tags remove "_ufb_gun_owner_13_a"} {tags remove "_ufb_gun_escaped_13_a"} {tags remove "_ufb_gun_bound"}}
{on "ufb_gun_bind_14_a" sync
  {call "ufb_gun_left_cooldown_a"} {tags add "_ufb_gun_bound"}
  {kill_delay "ufb_gun_owner_expiry"}
  {delay 120 "ufb_gun_owner_expiry" {call "ufb_gun_release_owner_14_a"}}
  {spawn "ufb_smoke_screen_point" local_offset -700 0 0 constrain_after_dir {tags add "_ufb_gun_lease_14_a"} {delay 140 {delete}}}
  {if has_place "commander" {if crew_in_place "commander" {with_linked_entity "commander" {call "ufb_gun_bind_man_14_a"}}}}
{if has_place "driver" {if crew_in_place "driver" {with_linked_entity "driver" {call "ufb_gun_bind_man_14_a"}}}}
{if has_place "gunner" {if crew_in_place "gunner" {with_linked_entity "gunner" {call "ufb_gun_bind_man_14_a"}}}}
{if has_place "gunner1" {if crew_in_place "gunner1" {with_linked_entity "gunner1" {call "ufb_gun_bind_man_14_a"}}}}
{if has_place "gunner2" {if crew_in_place "gunner2" {with_linked_entity "gunner2" {call "ufb_gun_bind_man_14_a"}}}}
{if has_place "gunner3" {if crew_in_place "gunner3" {with_linked_entity "gunner3" {call "ufb_gun_bind_man_14_a"}}}}
{if has_place "gunner4" {if crew_in_place "gunner4" {with_linked_entity "gunner4" {call "ufb_gun_bind_man_14_a"}}}}
{if has_place "gunner5" {if crew_in_place "gunner5" {with_linked_entity "gunner5" {call "ufb_gun_bind_man_14_a"}}}}
{if has_place "gunner6" {if crew_in_place "gunner6" {with_linked_entity "gunner6" {call "ufb_gun_bind_man_14_a"}}}}
{if has_place "gunner7" {if crew_in_place "gunner7" {with_linked_entity "gunner7" {call "ufb_gun_bind_man_14_a"}}}}
{if has_place "gunner8" {if crew_in_place "gunner8" {with_linked_entity "gunner8" {call "ufb_gun_bind_man_14_a"}}}}
{if has_place "charger" {if crew_in_place "charger" {with_linked_entity "charger" {call "ufb_gun_bind_man_14_a"}}}}
{if has_place "charger1" {if crew_in_place "charger1" {with_linked_entity "charger1" {call "ufb_gun_bind_man_14_a"}}}}
{if has_place "charger2" {if crew_in_place "charger2" {with_linked_entity "charger2" {call "ufb_gun_bind_man_14_a"}}}}
{if has_place "charger3" {if crew_in_place "charger3" {with_linked_entity "charger3" {call "ufb_gun_bind_man_14_a"}}}}
{if has_place "charger4" {if crew_in_place "charger4" {with_linked_entity "charger4" {call "ufb_gun_bind_man_14_a"}}}}
{if has_place "charger5" {if crew_in_place "charger5" {with_linked_entity "charger5" {call "ufb_gun_bind_man_14_a"}}}}
{if has_place "charger6" {if crew_in_place "charger6" {with_linked_entity "charger6" {call "ufb_gun_bind_man_14_a"}}}}
{if has_place "charger7" {if crew_in_place "charger7" {with_linked_entity "charger7" {call "ufb_gun_bind_man_14_a"}}}}
{if has_place "charger8" {if crew_in_place "charger8" {with_linked_entity "charger8" {call "ufb_gun_bind_man_14_a"}}}}
{if has_place "loader" {if crew_in_place "loader" {with_linked_entity "loader" {call "ufb_gun_bind_man_14_a"}}}}
{if has_place "loader1" {if crew_in_place "loader1" {with_linked_entity "loader1" {call "ufb_gun_bind_man_14_a"}}}}
{if has_place "loader2" {if crew_in_place "loader2" {with_linked_entity "loader2" {call "ufb_gun_bind_man_14_a"}}}}
{if has_place "loader3" {if crew_in_place "loader3" {with_linked_entity "loader3" {call "ufb_gun_bind_man_14_a"}}}}
{if has_place "loader4" {if crew_in_place "loader4" {with_linked_entity "loader4" {call "ufb_gun_bind_man_14_a"}}}}
{if has_place "loader5" {if crew_in_place "loader5" {with_linked_entity "loader5" {call "ufb_gun_bind_man_14_a"}}}}
{if has_place "loader6" {if crew_in_place "loader6" {with_linked_entity "loader6" {call "ufb_gun_bind_man_14_a"}}}}
{if has_place "loader7" {if crew_in_place "loader7" {with_linked_entity "loader7" {call "ufb_gun_bind_man_14_a"}}}}
{if has_place "loader8" {if crew_in_place "loader8" {with_linked_entity "loader8" {call "ufb_gun_bind_man_14_a"}}}}
{if has_place "seat1" {if crew_in_place "seat1" {with_linked_entity "seat1" {call "ufb_gun_bind_man_14_a"}}}}
{if has_place "seat2" {if crew_in_place "seat2" {with_linked_entity "seat2" {call "ufb_gun_bind_man_14_a"}}}}
{if has_place "seat3" {if crew_in_place "seat3" {with_linked_entity "seat3" {call "ufb_gun_bind_man_14_a"}}}}
{if has_place "seat4" {if crew_in_place "seat4" {with_linked_entity "seat4" {call "ufb_gun_bind_man_14_a"}}}}
{if has_place "seat5" {if crew_in_place "seat5" {with_linked_entity "seat5" {call "ufb_gun_bind_man_14_a"}}}}
{if has_place "seat6" {if crew_in_place "seat6" {with_linked_entity "seat6" {call "ufb_gun_bind_man_14_a"}}}}
{if has_place "seat7" {if crew_in_place "seat7" {with_linked_entity "seat7" {call "ufb_gun_bind_man_14_a"}}}}
{if has_place "seat8" {if crew_in_place "seat8" {with_linked_entity "seat8" {call "ufb_gun_bind_man_14_a"}}}}
{if has_place "seat9" {if crew_in_place "seat9" {with_linked_entity "seat9" {call "ufb_gun_bind_man_14_a"}}}}
{if has_place "seat10" {if crew_in_place "seat10" {with_linked_entity "seat10" {call "ufb_gun_bind_man_14_a"}}}}
{if has_place "seat11" {if crew_in_place "seat11" {with_linked_entity "seat11" {call "ufb_gun_bind_man_14_a"}}}}
{if has_place "seat12" {if crew_in_place "seat12" {with_linked_entity "seat12" {call "ufb_gun_bind_man_14_a"}}}}
{if has_place "seat13" {if crew_in_place "seat13" {with_linked_entity "seat13" {call "ufb_gun_bind_man_14_a"}}}}
{if has_place "seat14" {if crew_in_place "seat14" {with_linked_entity "seat14" {call "ufb_gun_bind_man_14_a"}}}}
{if has_place "seat15" {if crew_in_place "seat15" {with_linked_entity "seat15" {call "ufb_gun_bind_man_14_a"}}}}
 }
 {on "ufb_gun_release_owner_14_a" {kill_delay "ufb_gun_owner_expiry"} {tags remove "_ufb_gun_owner_14_a"} {tags remove "_ufb_gun_escaped_14_a"} {tags remove "_ufb_gun_bound"}}
{on "ufb_gun_bind_15_a" sync
  {call "ufb_gun_left_cooldown_a"} {tags add "_ufb_gun_bound"}
  {kill_delay "ufb_gun_owner_expiry"}
  {delay 120 "ufb_gun_owner_expiry" {call "ufb_gun_release_owner_15_a"}}
  {spawn "ufb_smoke_screen_point" local_offset -700 0 0 constrain_after_dir {tags add "_ufb_gun_lease_15_a"} {delay 140 {delete}}}
  {if has_place "commander" {if crew_in_place "commander" {with_linked_entity "commander" {call "ufb_gun_bind_man_15_a"}}}}
{if has_place "driver" {if crew_in_place "driver" {with_linked_entity "driver" {call "ufb_gun_bind_man_15_a"}}}}
{if has_place "gunner" {if crew_in_place "gunner" {with_linked_entity "gunner" {call "ufb_gun_bind_man_15_a"}}}}
{if has_place "gunner1" {if crew_in_place "gunner1" {with_linked_entity "gunner1" {call "ufb_gun_bind_man_15_a"}}}}
{if has_place "gunner2" {if crew_in_place "gunner2" {with_linked_entity "gunner2" {call "ufb_gun_bind_man_15_a"}}}}
{if has_place "gunner3" {if crew_in_place "gunner3" {with_linked_entity "gunner3" {call "ufb_gun_bind_man_15_a"}}}}
{if has_place "gunner4" {if crew_in_place "gunner4" {with_linked_entity "gunner4" {call "ufb_gun_bind_man_15_a"}}}}
{if has_place "gunner5" {if crew_in_place "gunner5" {with_linked_entity "gunner5" {call "ufb_gun_bind_man_15_a"}}}}
{if has_place "gunner6" {if crew_in_place "gunner6" {with_linked_entity "gunner6" {call "ufb_gun_bind_man_15_a"}}}}
{if has_place "gunner7" {if crew_in_place "gunner7" {with_linked_entity "gunner7" {call "ufb_gun_bind_man_15_a"}}}}
{if has_place "gunner8" {if crew_in_place "gunner8" {with_linked_entity "gunner8" {call "ufb_gun_bind_man_15_a"}}}}
{if has_place "charger" {if crew_in_place "charger" {with_linked_entity "charger" {call "ufb_gun_bind_man_15_a"}}}}
{if has_place "charger1" {if crew_in_place "charger1" {with_linked_entity "charger1" {call "ufb_gun_bind_man_15_a"}}}}
{if has_place "charger2" {if crew_in_place "charger2" {with_linked_entity "charger2" {call "ufb_gun_bind_man_15_a"}}}}
{if has_place "charger3" {if crew_in_place "charger3" {with_linked_entity "charger3" {call "ufb_gun_bind_man_15_a"}}}}
{if has_place "charger4" {if crew_in_place "charger4" {with_linked_entity "charger4" {call "ufb_gun_bind_man_15_a"}}}}
{if has_place "charger5" {if crew_in_place "charger5" {with_linked_entity "charger5" {call "ufb_gun_bind_man_15_a"}}}}
{if has_place "charger6" {if crew_in_place "charger6" {with_linked_entity "charger6" {call "ufb_gun_bind_man_15_a"}}}}
{if has_place "charger7" {if crew_in_place "charger7" {with_linked_entity "charger7" {call "ufb_gun_bind_man_15_a"}}}}
{if has_place "charger8" {if crew_in_place "charger8" {with_linked_entity "charger8" {call "ufb_gun_bind_man_15_a"}}}}
{if has_place "loader" {if crew_in_place "loader" {with_linked_entity "loader" {call "ufb_gun_bind_man_15_a"}}}}
{if has_place "loader1" {if crew_in_place "loader1" {with_linked_entity "loader1" {call "ufb_gun_bind_man_15_a"}}}}
{if has_place "loader2" {if crew_in_place "loader2" {with_linked_entity "loader2" {call "ufb_gun_bind_man_15_a"}}}}
{if has_place "loader3" {if crew_in_place "loader3" {with_linked_entity "loader3" {call "ufb_gun_bind_man_15_a"}}}}
{if has_place "loader4" {if crew_in_place "loader4" {with_linked_entity "loader4" {call "ufb_gun_bind_man_15_a"}}}}
{if has_place "loader5" {if crew_in_place "loader5" {with_linked_entity "loader5" {call "ufb_gun_bind_man_15_a"}}}}
{if has_place "loader6" {if crew_in_place "loader6" {with_linked_entity "loader6" {call "ufb_gun_bind_man_15_a"}}}}
{if has_place "loader7" {if crew_in_place "loader7" {with_linked_entity "loader7" {call "ufb_gun_bind_man_15_a"}}}}
{if has_place "loader8" {if crew_in_place "loader8" {with_linked_entity "loader8" {call "ufb_gun_bind_man_15_a"}}}}
{if has_place "seat1" {if crew_in_place "seat1" {with_linked_entity "seat1" {call "ufb_gun_bind_man_15_a"}}}}
{if has_place "seat2" {if crew_in_place "seat2" {with_linked_entity "seat2" {call "ufb_gun_bind_man_15_a"}}}}
{if has_place "seat3" {if crew_in_place "seat3" {with_linked_entity "seat3" {call "ufb_gun_bind_man_15_a"}}}}
{if has_place "seat4" {if crew_in_place "seat4" {with_linked_entity "seat4" {call "ufb_gun_bind_man_15_a"}}}}
{if has_place "seat5" {if crew_in_place "seat5" {with_linked_entity "seat5" {call "ufb_gun_bind_man_15_a"}}}}
{if has_place "seat6" {if crew_in_place "seat6" {with_linked_entity "seat6" {call "ufb_gun_bind_man_15_a"}}}}
{if has_place "seat7" {if crew_in_place "seat7" {with_linked_entity "seat7" {call "ufb_gun_bind_man_15_a"}}}}
{if has_place "seat8" {if crew_in_place "seat8" {with_linked_entity "seat8" {call "ufb_gun_bind_man_15_a"}}}}
{if has_place "seat9" {if crew_in_place "seat9" {with_linked_entity "seat9" {call "ufb_gun_bind_man_15_a"}}}}
{if has_place "seat10" {if crew_in_place "seat10" {with_linked_entity "seat10" {call "ufb_gun_bind_man_15_a"}}}}
{if has_place "seat11" {if crew_in_place "seat11" {with_linked_entity "seat11" {call "ufb_gun_bind_man_15_a"}}}}
{if has_place "seat12" {if crew_in_place "seat12" {with_linked_entity "seat12" {call "ufb_gun_bind_man_15_a"}}}}
{if has_place "seat13" {if crew_in_place "seat13" {with_linked_entity "seat13" {call "ufb_gun_bind_man_15_a"}}}}
{if has_place "seat14" {if crew_in_place "seat14" {with_linked_entity "seat14" {call "ufb_gun_bind_man_15_a"}}}}
{if has_place "seat15" {if crew_in_place "seat15" {with_linked_entity "seat15" {call "ufb_gun_bind_man_15_a"}}}}
 }
 {on "ufb_gun_release_owner_15_a" {kill_delay "ufb_gun_owner_expiry"} {tags remove "_ufb_gun_owner_15_a"} {tags remove "_ufb_gun_escaped_15_a"} {tags remove "_ufb_gun_bound"}}
}
{"vehicle"
 {on "ufb_gun_left_cooldown_b" {tags add "_ufb_gun_left_b"} {kill_delay "ufb_gun_left_expiry"} {delay 60 "ufb_gun_left_expiry" {tags remove "_ufb_gun_left_b"}}}
{on "ufb_gun_bind_0_b" sync
  {call "ufb_gun_left_cooldown_b"} {tags add "_ufb_gun_bound"}
  {kill_delay "ufb_gun_owner_expiry"}
  {delay 120 "ufb_gun_owner_expiry" {call "ufb_gun_release_owner_0_b"}}
  {spawn "ufb_smoke_screen_point" local_offset -700 0 0 constrain_after_dir {tags add "_ufb_gun_lease_0_b"} {delay 140 {delete}}}
  {if has_place "commander" {if crew_in_place "commander" {with_linked_entity "commander" {call "ufb_gun_bind_man_0_b"}}}}
{if has_place "driver" {if crew_in_place "driver" {with_linked_entity "driver" {call "ufb_gun_bind_man_0_b"}}}}
{if has_place "gunner" {if crew_in_place "gunner" {with_linked_entity "gunner" {call "ufb_gun_bind_man_0_b"}}}}
{if has_place "gunner1" {if crew_in_place "gunner1" {with_linked_entity "gunner1" {call "ufb_gun_bind_man_0_b"}}}}
{if has_place "gunner2" {if crew_in_place "gunner2" {with_linked_entity "gunner2" {call "ufb_gun_bind_man_0_b"}}}}
{if has_place "gunner3" {if crew_in_place "gunner3" {with_linked_entity "gunner3" {call "ufb_gun_bind_man_0_b"}}}}
{if has_place "gunner4" {if crew_in_place "gunner4" {with_linked_entity "gunner4" {call "ufb_gun_bind_man_0_b"}}}}
{if has_place "gunner5" {if crew_in_place "gunner5" {with_linked_entity "gunner5" {call "ufb_gun_bind_man_0_b"}}}}
{if has_place "gunner6" {if crew_in_place "gunner6" {with_linked_entity "gunner6" {call "ufb_gun_bind_man_0_b"}}}}
{if has_place "gunner7" {if crew_in_place "gunner7" {with_linked_entity "gunner7" {call "ufb_gun_bind_man_0_b"}}}}
{if has_place "gunner8" {if crew_in_place "gunner8" {with_linked_entity "gunner8" {call "ufb_gun_bind_man_0_b"}}}}
{if has_place "charger" {if crew_in_place "charger" {with_linked_entity "charger" {call "ufb_gun_bind_man_0_b"}}}}
{if has_place "charger1" {if crew_in_place "charger1" {with_linked_entity "charger1" {call "ufb_gun_bind_man_0_b"}}}}
{if has_place "charger2" {if crew_in_place "charger2" {with_linked_entity "charger2" {call "ufb_gun_bind_man_0_b"}}}}
{if has_place "charger3" {if crew_in_place "charger3" {with_linked_entity "charger3" {call "ufb_gun_bind_man_0_b"}}}}
{if has_place "charger4" {if crew_in_place "charger4" {with_linked_entity "charger4" {call "ufb_gun_bind_man_0_b"}}}}
{if has_place "charger5" {if crew_in_place "charger5" {with_linked_entity "charger5" {call "ufb_gun_bind_man_0_b"}}}}
{if has_place "charger6" {if crew_in_place "charger6" {with_linked_entity "charger6" {call "ufb_gun_bind_man_0_b"}}}}
{if has_place "charger7" {if crew_in_place "charger7" {with_linked_entity "charger7" {call "ufb_gun_bind_man_0_b"}}}}
{if has_place "charger8" {if crew_in_place "charger8" {with_linked_entity "charger8" {call "ufb_gun_bind_man_0_b"}}}}
{if has_place "loader" {if crew_in_place "loader" {with_linked_entity "loader" {call "ufb_gun_bind_man_0_b"}}}}
{if has_place "loader1" {if crew_in_place "loader1" {with_linked_entity "loader1" {call "ufb_gun_bind_man_0_b"}}}}
{if has_place "loader2" {if crew_in_place "loader2" {with_linked_entity "loader2" {call "ufb_gun_bind_man_0_b"}}}}
{if has_place "loader3" {if crew_in_place "loader3" {with_linked_entity "loader3" {call "ufb_gun_bind_man_0_b"}}}}
{if has_place "loader4" {if crew_in_place "loader4" {with_linked_entity "loader4" {call "ufb_gun_bind_man_0_b"}}}}
{if has_place "loader5" {if crew_in_place "loader5" {with_linked_entity "loader5" {call "ufb_gun_bind_man_0_b"}}}}
{if has_place "loader6" {if crew_in_place "loader6" {with_linked_entity "loader6" {call "ufb_gun_bind_man_0_b"}}}}
{if has_place "loader7" {if crew_in_place "loader7" {with_linked_entity "loader7" {call "ufb_gun_bind_man_0_b"}}}}
{if has_place "loader8" {if crew_in_place "loader8" {with_linked_entity "loader8" {call "ufb_gun_bind_man_0_b"}}}}
{if has_place "seat1" {if crew_in_place "seat1" {with_linked_entity "seat1" {call "ufb_gun_bind_man_0_b"}}}}
{if has_place "seat2" {if crew_in_place "seat2" {with_linked_entity "seat2" {call "ufb_gun_bind_man_0_b"}}}}
{if has_place "seat3" {if crew_in_place "seat3" {with_linked_entity "seat3" {call "ufb_gun_bind_man_0_b"}}}}
{if has_place "seat4" {if crew_in_place "seat4" {with_linked_entity "seat4" {call "ufb_gun_bind_man_0_b"}}}}
{if has_place "seat5" {if crew_in_place "seat5" {with_linked_entity "seat5" {call "ufb_gun_bind_man_0_b"}}}}
{if has_place "seat6" {if crew_in_place "seat6" {with_linked_entity "seat6" {call "ufb_gun_bind_man_0_b"}}}}
{if has_place "seat7" {if crew_in_place "seat7" {with_linked_entity "seat7" {call "ufb_gun_bind_man_0_b"}}}}
{if has_place "seat8" {if crew_in_place "seat8" {with_linked_entity "seat8" {call "ufb_gun_bind_man_0_b"}}}}
{if has_place "seat9" {if crew_in_place "seat9" {with_linked_entity "seat9" {call "ufb_gun_bind_man_0_b"}}}}
{if has_place "seat10" {if crew_in_place "seat10" {with_linked_entity "seat10" {call "ufb_gun_bind_man_0_b"}}}}
{if has_place "seat11" {if crew_in_place "seat11" {with_linked_entity "seat11" {call "ufb_gun_bind_man_0_b"}}}}
{if has_place "seat12" {if crew_in_place "seat12" {with_linked_entity "seat12" {call "ufb_gun_bind_man_0_b"}}}}
{if has_place "seat13" {if crew_in_place "seat13" {with_linked_entity "seat13" {call "ufb_gun_bind_man_0_b"}}}}
{if has_place "seat14" {if crew_in_place "seat14" {with_linked_entity "seat14" {call "ufb_gun_bind_man_0_b"}}}}
{if has_place "seat15" {if crew_in_place "seat15" {with_linked_entity "seat15" {call "ufb_gun_bind_man_0_b"}}}}
 }
 {on "ufb_gun_release_owner_0_b" {kill_delay "ufb_gun_owner_expiry"} {tags remove "_ufb_gun_owner_0_b"} {tags remove "_ufb_gun_escaped_0_b"} {tags remove "_ufb_gun_bound"}}
{on "ufb_gun_bind_1_b" sync
  {call "ufb_gun_left_cooldown_b"} {tags add "_ufb_gun_bound"}
  {kill_delay "ufb_gun_owner_expiry"}
  {delay 120 "ufb_gun_owner_expiry" {call "ufb_gun_release_owner_1_b"}}
  {spawn "ufb_smoke_screen_point" local_offset -700 0 0 constrain_after_dir {tags add "_ufb_gun_lease_1_b"} {delay 140 {delete}}}
  {if has_place "commander" {if crew_in_place "commander" {with_linked_entity "commander" {call "ufb_gun_bind_man_1_b"}}}}
{if has_place "driver" {if crew_in_place "driver" {with_linked_entity "driver" {call "ufb_gun_bind_man_1_b"}}}}
{if has_place "gunner" {if crew_in_place "gunner" {with_linked_entity "gunner" {call "ufb_gun_bind_man_1_b"}}}}
{if has_place "gunner1" {if crew_in_place "gunner1" {with_linked_entity "gunner1" {call "ufb_gun_bind_man_1_b"}}}}
{if has_place "gunner2" {if crew_in_place "gunner2" {with_linked_entity "gunner2" {call "ufb_gun_bind_man_1_b"}}}}
{if has_place "gunner3" {if crew_in_place "gunner3" {with_linked_entity "gunner3" {call "ufb_gun_bind_man_1_b"}}}}
{if has_place "gunner4" {if crew_in_place "gunner4" {with_linked_entity "gunner4" {call "ufb_gun_bind_man_1_b"}}}}
{if has_place "gunner5" {if crew_in_place "gunner5" {with_linked_entity "gunner5" {call "ufb_gun_bind_man_1_b"}}}}
{if has_place "gunner6" {if crew_in_place "gunner6" {with_linked_entity "gunner6" {call "ufb_gun_bind_man_1_b"}}}}
{if has_place "gunner7" {if crew_in_place "gunner7" {with_linked_entity "gunner7" {call "ufb_gun_bind_man_1_b"}}}}
{if has_place "gunner8" {if crew_in_place "gunner8" {with_linked_entity "gunner8" {call "ufb_gun_bind_man_1_b"}}}}
{if has_place "charger" {if crew_in_place "charger" {with_linked_entity "charger" {call "ufb_gun_bind_man_1_b"}}}}
{if has_place "charger1" {if crew_in_place "charger1" {with_linked_entity "charger1" {call "ufb_gun_bind_man_1_b"}}}}
{if has_place "charger2" {if crew_in_place "charger2" {with_linked_entity "charger2" {call "ufb_gun_bind_man_1_b"}}}}
{if has_place "charger3" {if crew_in_place "charger3" {with_linked_entity "charger3" {call "ufb_gun_bind_man_1_b"}}}}
{if has_place "charger4" {if crew_in_place "charger4" {with_linked_entity "charger4" {call "ufb_gun_bind_man_1_b"}}}}
{if has_place "charger5" {if crew_in_place "charger5" {with_linked_entity "charger5" {call "ufb_gun_bind_man_1_b"}}}}
{if has_place "charger6" {if crew_in_place "charger6" {with_linked_entity "charger6" {call "ufb_gun_bind_man_1_b"}}}}
{if has_place "charger7" {if crew_in_place "charger7" {with_linked_entity "charger7" {call "ufb_gun_bind_man_1_b"}}}}
{if has_place "charger8" {if crew_in_place "charger8" {with_linked_entity "charger8" {call "ufb_gun_bind_man_1_b"}}}}
{if has_place "loader" {if crew_in_place "loader" {with_linked_entity "loader" {call "ufb_gun_bind_man_1_b"}}}}
{if has_place "loader1" {if crew_in_place "loader1" {with_linked_entity "loader1" {call "ufb_gun_bind_man_1_b"}}}}
{if has_place "loader2" {if crew_in_place "loader2" {with_linked_entity "loader2" {call "ufb_gun_bind_man_1_b"}}}}
{if has_place "loader3" {if crew_in_place "loader3" {with_linked_entity "loader3" {call "ufb_gun_bind_man_1_b"}}}}
{if has_place "loader4" {if crew_in_place "loader4" {with_linked_entity "loader4" {call "ufb_gun_bind_man_1_b"}}}}
{if has_place "loader5" {if crew_in_place "loader5" {with_linked_entity "loader5" {call "ufb_gun_bind_man_1_b"}}}}
{if has_place "loader6" {if crew_in_place "loader6" {with_linked_entity "loader6" {call "ufb_gun_bind_man_1_b"}}}}
{if has_place "loader7" {if crew_in_place "loader7" {with_linked_entity "loader7" {call "ufb_gun_bind_man_1_b"}}}}
{if has_place "loader8" {if crew_in_place "loader8" {with_linked_entity "loader8" {call "ufb_gun_bind_man_1_b"}}}}
{if has_place "seat1" {if crew_in_place "seat1" {with_linked_entity "seat1" {call "ufb_gun_bind_man_1_b"}}}}
{if has_place "seat2" {if crew_in_place "seat2" {with_linked_entity "seat2" {call "ufb_gun_bind_man_1_b"}}}}
{if has_place "seat3" {if crew_in_place "seat3" {with_linked_entity "seat3" {call "ufb_gun_bind_man_1_b"}}}}
{if has_place "seat4" {if crew_in_place "seat4" {with_linked_entity "seat4" {call "ufb_gun_bind_man_1_b"}}}}
{if has_place "seat5" {if crew_in_place "seat5" {with_linked_entity "seat5" {call "ufb_gun_bind_man_1_b"}}}}
{if has_place "seat6" {if crew_in_place "seat6" {with_linked_entity "seat6" {call "ufb_gun_bind_man_1_b"}}}}
{if has_place "seat7" {if crew_in_place "seat7" {with_linked_entity "seat7" {call "ufb_gun_bind_man_1_b"}}}}
{if has_place "seat8" {if crew_in_place "seat8" {with_linked_entity "seat8" {call "ufb_gun_bind_man_1_b"}}}}
{if has_place "seat9" {if crew_in_place "seat9" {with_linked_entity "seat9" {call "ufb_gun_bind_man_1_b"}}}}
{if has_place "seat10" {if crew_in_place "seat10" {with_linked_entity "seat10" {call "ufb_gun_bind_man_1_b"}}}}
{if has_place "seat11" {if crew_in_place "seat11" {with_linked_entity "seat11" {call "ufb_gun_bind_man_1_b"}}}}
{if has_place "seat12" {if crew_in_place "seat12" {with_linked_entity "seat12" {call "ufb_gun_bind_man_1_b"}}}}
{if has_place "seat13" {if crew_in_place "seat13" {with_linked_entity "seat13" {call "ufb_gun_bind_man_1_b"}}}}
{if has_place "seat14" {if crew_in_place "seat14" {with_linked_entity "seat14" {call "ufb_gun_bind_man_1_b"}}}}
{if has_place "seat15" {if crew_in_place "seat15" {with_linked_entity "seat15" {call "ufb_gun_bind_man_1_b"}}}}
 }
 {on "ufb_gun_release_owner_1_b" {kill_delay "ufb_gun_owner_expiry"} {tags remove "_ufb_gun_owner_1_b"} {tags remove "_ufb_gun_escaped_1_b"} {tags remove "_ufb_gun_bound"}}
{on "ufb_gun_bind_2_b" sync
  {call "ufb_gun_left_cooldown_b"} {tags add "_ufb_gun_bound"}
  {kill_delay "ufb_gun_owner_expiry"}
  {delay 120 "ufb_gun_owner_expiry" {call "ufb_gun_release_owner_2_b"}}
  {spawn "ufb_smoke_screen_point" local_offset -700 0 0 constrain_after_dir {tags add "_ufb_gun_lease_2_b"} {delay 140 {delete}}}
  {if has_place "commander" {if crew_in_place "commander" {with_linked_entity "commander" {call "ufb_gun_bind_man_2_b"}}}}
{if has_place "driver" {if crew_in_place "driver" {with_linked_entity "driver" {call "ufb_gun_bind_man_2_b"}}}}
{if has_place "gunner" {if crew_in_place "gunner" {with_linked_entity "gunner" {call "ufb_gun_bind_man_2_b"}}}}
{if has_place "gunner1" {if crew_in_place "gunner1" {with_linked_entity "gunner1" {call "ufb_gun_bind_man_2_b"}}}}
{if has_place "gunner2" {if crew_in_place "gunner2" {with_linked_entity "gunner2" {call "ufb_gun_bind_man_2_b"}}}}
{if has_place "gunner3" {if crew_in_place "gunner3" {with_linked_entity "gunner3" {call "ufb_gun_bind_man_2_b"}}}}
{if has_place "gunner4" {if crew_in_place "gunner4" {with_linked_entity "gunner4" {call "ufb_gun_bind_man_2_b"}}}}
{if has_place "gunner5" {if crew_in_place "gunner5" {with_linked_entity "gunner5" {call "ufb_gun_bind_man_2_b"}}}}
{if has_place "gunner6" {if crew_in_place "gunner6" {with_linked_entity "gunner6" {call "ufb_gun_bind_man_2_b"}}}}
{if has_place "gunner7" {if crew_in_place "gunner7" {with_linked_entity "gunner7" {call "ufb_gun_bind_man_2_b"}}}}
{if has_place "gunner8" {if crew_in_place "gunner8" {with_linked_entity "gunner8" {call "ufb_gun_bind_man_2_b"}}}}
{if has_place "charger" {if crew_in_place "charger" {with_linked_entity "charger" {call "ufb_gun_bind_man_2_b"}}}}
{if has_place "charger1" {if crew_in_place "charger1" {with_linked_entity "charger1" {call "ufb_gun_bind_man_2_b"}}}}
{if has_place "charger2" {if crew_in_place "charger2" {with_linked_entity "charger2" {call "ufb_gun_bind_man_2_b"}}}}
{if has_place "charger3" {if crew_in_place "charger3" {with_linked_entity "charger3" {call "ufb_gun_bind_man_2_b"}}}}
{if has_place "charger4" {if crew_in_place "charger4" {with_linked_entity "charger4" {call "ufb_gun_bind_man_2_b"}}}}
{if has_place "charger5" {if crew_in_place "charger5" {with_linked_entity "charger5" {call "ufb_gun_bind_man_2_b"}}}}
{if has_place "charger6" {if crew_in_place "charger6" {with_linked_entity "charger6" {call "ufb_gun_bind_man_2_b"}}}}
{if has_place "charger7" {if crew_in_place "charger7" {with_linked_entity "charger7" {call "ufb_gun_bind_man_2_b"}}}}
{if has_place "charger8" {if crew_in_place "charger8" {with_linked_entity "charger8" {call "ufb_gun_bind_man_2_b"}}}}
{if has_place "loader" {if crew_in_place "loader" {with_linked_entity "loader" {call "ufb_gun_bind_man_2_b"}}}}
{if has_place "loader1" {if crew_in_place "loader1" {with_linked_entity "loader1" {call "ufb_gun_bind_man_2_b"}}}}
{if has_place "loader2" {if crew_in_place "loader2" {with_linked_entity "loader2" {call "ufb_gun_bind_man_2_b"}}}}
{if has_place "loader3" {if crew_in_place "loader3" {with_linked_entity "loader3" {call "ufb_gun_bind_man_2_b"}}}}
{if has_place "loader4" {if crew_in_place "loader4" {with_linked_entity "loader4" {call "ufb_gun_bind_man_2_b"}}}}
{if has_place "loader5" {if crew_in_place "loader5" {with_linked_entity "loader5" {call "ufb_gun_bind_man_2_b"}}}}
{if has_place "loader6" {if crew_in_place "loader6" {with_linked_entity "loader6" {call "ufb_gun_bind_man_2_b"}}}}
{if has_place "loader7" {if crew_in_place "loader7" {with_linked_entity "loader7" {call "ufb_gun_bind_man_2_b"}}}}
{if has_place "loader8" {if crew_in_place "loader8" {with_linked_entity "loader8" {call "ufb_gun_bind_man_2_b"}}}}
{if has_place "seat1" {if crew_in_place "seat1" {with_linked_entity "seat1" {call "ufb_gun_bind_man_2_b"}}}}
{if has_place "seat2" {if crew_in_place "seat2" {with_linked_entity "seat2" {call "ufb_gun_bind_man_2_b"}}}}
{if has_place "seat3" {if crew_in_place "seat3" {with_linked_entity "seat3" {call "ufb_gun_bind_man_2_b"}}}}
{if has_place "seat4" {if crew_in_place "seat4" {with_linked_entity "seat4" {call "ufb_gun_bind_man_2_b"}}}}
{if has_place "seat5" {if crew_in_place "seat5" {with_linked_entity "seat5" {call "ufb_gun_bind_man_2_b"}}}}
{if has_place "seat6" {if crew_in_place "seat6" {with_linked_entity "seat6" {call "ufb_gun_bind_man_2_b"}}}}
{if has_place "seat7" {if crew_in_place "seat7" {with_linked_entity "seat7" {call "ufb_gun_bind_man_2_b"}}}}
{if has_place "seat8" {if crew_in_place "seat8" {with_linked_entity "seat8" {call "ufb_gun_bind_man_2_b"}}}}
{if has_place "seat9" {if crew_in_place "seat9" {with_linked_entity "seat9" {call "ufb_gun_bind_man_2_b"}}}}
{if has_place "seat10" {if crew_in_place "seat10" {with_linked_entity "seat10" {call "ufb_gun_bind_man_2_b"}}}}
{if has_place "seat11" {if crew_in_place "seat11" {with_linked_entity "seat11" {call "ufb_gun_bind_man_2_b"}}}}
{if has_place "seat12" {if crew_in_place "seat12" {with_linked_entity "seat12" {call "ufb_gun_bind_man_2_b"}}}}
{if has_place "seat13" {if crew_in_place "seat13" {with_linked_entity "seat13" {call "ufb_gun_bind_man_2_b"}}}}
{if has_place "seat14" {if crew_in_place "seat14" {with_linked_entity "seat14" {call "ufb_gun_bind_man_2_b"}}}}
{if has_place "seat15" {if crew_in_place "seat15" {with_linked_entity "seat15" {call "ufb_gun_bind_man_2_b"}}}}
 }
 {on "ufb_gun_release_owner_2_b" {kill_delay "ufb_gun_owner_expiry"} {tags remove "_ufb_gun_owner_2_b"} {tags remove "_ufb_gun_escaped_2_b"} {tags remove "_ufb_gun_bound"}}
{on "ufb_gun_bind_3_b" sync
  {call "ufb_gun_left_cooldown_b"} {tags add "_ufb_gun_bound"}
  {kill_delay "ufb_gun_owner_expiry"}
  {delay 120 "ufb_gun_owner_expiry" {call "ufb_gun_release_owner_3_b"}}
  {spawn "ufb_smoke_screen_point" local_offset -700 0 0 constrain_after_dir {tags add "_ufb_gun_lease_3_b"} {delay 140 {delete}}}
  {if has_place "commander" {if crew_in_place "commander" {with_linked_entity "commander" {call "ufb_gun_bind_man_3_b"}}}}
{if has_place "driver" {if crew_in_place "driver" {with_linked_entity "driver" {call "ufb_gun_bind_man_3_b"}}}}
{if has_place "gunner" {if crew_in_place "gunner" {with_linked_entity "gunner" {call "ufb_gun_bind_man_3_b"}}}}
{if has_place "gunner1" {if crew_in_place "gunner1" {with_linked_entity "gunner1" {call "ufb_gun_bind_man_3_b"}}}}
{if has_place "gunner2" {if crew_in_place "gunner2" {with_linked_entity "gunner2" {call "ufb_gun_bind_man_3_b"}}}}
{if has_place "gunner3" {if crew_in_place "gunner3" {with_linked_entity "gunner3" {call "ufb_gun_bind_man_3_b"}}}}
{if has_place "gunner4" {if crew_in_place "gunner4" {with_linked_entity "gunner4" {call "ufb_gun_bind_man_3_b"}}}}
{if has_place "gunner5" {if crew_in_place "gunner5" {with_linked_entity "gunner5" {call "ufb_gun_bind_man_3_b"}}}}
{if has_place "gunner6" {if crew_in_place "gunner6" {with_linked_entity "gunner6" {call "ufb_gun_bind_man_3_b"}}}}
{if has_place "gunner7" {if crew_in_place "gunner7" {with_linked_entity "gunner7" {call "ufb_gun_bind_man_3_b"}}}}
{if has_place "gunner8" {if crew_in_place "gunner8" {with_linked_entity "gunner8" {call "ufb_gun_bind_man_3_b"}}}}
{if has_place "charger" {if crew_in_place "charger" {with_linked_entity "charger" {call "ufb_gun_bind_man_3_b"}}}}
{if has_place "charger1" {if crew_in_place "charger1" {with_linked_entity "charger1" {call "ufb_gun_bind_man_3_b"}}}}
{if has_place "charger2" {if crew_in_place "charger2" {with_linked_entity "charger2" {call "ufb_gun_bind_man_3_b"}}}}
{if has_place "charger3" {if crew_in_place "charger3" {with_linked_entity "charger3" {call "ufb_gun_bind_man_3_b"}}}}
{if has_place "charger4" {if crew_in_place "charger4" {with_linked_entity "charger4" {call "ufb_gun_bind_man_3_b"}}}}
{if has_place "charger5" {if crew_in_place "charger5" {with_linked_entity "charger5" {call "ufb_gun_bind_man_3_b"}}}}
{if has_place "charger6" {if crew_in_place "charger6" {with_linked_entity "charger6" {call "ufb_gun_bind_man_3_b"}}}}
{if has_place "charger7" {if crew_in_place "charger7" {with_linked_entity "charger7" {call "ufb_gun_bind_man_3_b"}}}}
{if has_place "charger8" {if crew_in_place "charger8" {with_linked_entity "charger8" {call "ufb_gun_bind_man_3_b"}}}}
{if has_place "loader" {if crew_in_place "loader" {with_linked_entity "loader" {call "ufb_gun_bind_man_3_b"}}}}
{if has_place "loader1" {if crew_in_place "loader1" {with_linked_entity "loader1" {call "ufb_gun_bind_man_3_b"}}}}
{if has_place "loader2" {if crew_in_place "loader2" {with_linked_entity "loader2" {call "ufb_gun_bind_man_3_b"}}}}
{if has_place "loader3" {if crew_in_place "loader3" {with_linked_entity "loader3" {call "ufb_gun_bind_man_3_b"}}}}
{if has_place "loader4" {if crew_in_place "loader4" {with_linked_entity "loader4" {call "ufb_gun_bind_man_3_b"}}}}
{if has_place "loader5" {if crew_in_place "loader5" {with_linked_entity "loader5" {call "ufb_gun_bind_man_3_b"}}}}
{if has_place "loader6" {if crew_in_place "loader6" {with_linked_entity "loader6" {call "ufb_gun_bind_man_3_b"}}}}
{if has_place "loader7" {if crew_in_place "loader7" {with_linked_entity "loader7" {call "ufb_gun_bind_man_3_b"}}}}
{if has_place "loader8" {if crew_in_place "loader8" {with_linked_entity "loader8" {call "ufb_gun_bind_man_3_b"}}}}
{if has_place "seat1" {if crew_in_place "seat1" {with_linked_entity "seat1" {call "ufb_gun_bind_man_3_b"}}}}
{if has_place "seat2" {if crew_in_place "seat2" {with_linked_entity "seat2" {call "ufb_gun_bind_man_3_b"}}}}
{if has_place "seat3" {if crew_in_place "seat3" {with_linked_entity "seat3" {call "ufb_gun_bind_man_3_b"}}}}
{if has_place "seat4" {if crew_in_place "seat4" {with_linked_entity "seat4" {call "ufb_gun_bind_man_3_b"}}}}
{if has_place "seat5" {if crew_in_place "seat5" {with_linked_entity "seat5" {call "ufb_gun_bind_man_3_b"}}}}
{if has_place "seat6" {if crew_in_place "seat6" {with_linked_entity "seat6" {call "ufb_gun_bind_man_3_b"}}}}
{if has_place "seat7" {if crew_in_place "seat7" {with_linked_entity "seat7" {call "ufb_gun_bind_man_3_b"}}}}
{if has_place "seat8" {if crew_in_place "seat8" {with_linked_entity "seat8" {call "ufb_gun_bind_man_3_b"}}}}
{if has_place "seat9" {if crew_in_place "seat9" {with_linked_entity "seat9" {call "ufb_gun_bind_man_3_b"}}}}
{if has_place "seat10" {if crew_in_place "seat10" {with_linked_entity "seat10" {call "ufb_gun_bind_man_3_b"}}}}
{if has_place "seat11" {if crew_in_place "seat11" {with_linked_entity "seat11" {call "ufb_gun_bind_man_3_b"}}}}
{if has_place "seat12" {if crew_in_place "seat12" {with_linked_entity "seat12" {call "ufb_gun_bind_man_3_b"}}}}
{if has_place "seat13" {if crew_in_place "seat13" {with_linked_entity "seat13" {call "ufb_gun_bind_man_3_b"}}}}
{if has_place "seat14" {if crew_in_place "seat14" {with_linked_entity "seat14" {call "ufb_gun_bind_man_3_b"}}}}
{if has_place "seat15" {if crew_in_place "seat15" {with_linked_entity "seat15" {call "ufb_gun_bind_man_3_b"}}}}
 }
 {on "ufb_gun_release_owner_3_b" {kill_delay "ufb_gun_owner_expiry"} {tags remove "_ufb_gun_owner_3_b"} {tags remove "_ufb_gun_escaped_3_b"} {tags remove "_ufb_gun_bound"}}
{on "ufb_gun_bind_4_b" sync
  {call "ufb_gun_left_cooldown_b"} {tags add "_ufb_gun_bound"}
  {kill_delay "ufb_gun_owner_expiry"}
  {delay 120 "ufb_gun_owner_expiry" {call "ufb_gun_release_owner_4_b"}}
  {spawn "ufb_smoke_screen_point" local_offset -700 0 0 constrain_after_dir {tags add "_ufb_gun_lease_4_b"} {delay 140 {delete}}}
  {if has_place "commander" {if crew_in_place "commander" {with_linked_entity "commander" {call "ufb_gun_bind_man_4_b"}}}}
{if has_place "driver" {if crew_in_place "driver" {with_linked_entity "driver" {call "ufb_gun_bind_man_4_b"}}}}
{if has_place "gunner" {if crew_in_place "gunner" {with_linked_entity "gunner" {call "ufb_gun_bind_man_4_b"}}}}
{if has_place "gunner1" {if crew_in_place "gunner1" {with_linked_entity "gunner1" {call "ufb_gun_bind_man_4_b"}}}}
{if has_place "gunner2" {if crew_in_place "gunner2" {with_linked_entity "gunner2" {call "ufb_gun_bind_man_4_b"}}}}
{if has_place "gunner3" {if crew_in_place "gunner3" {with_linked_entity "gunner3" {call "ufb_gun_bind_man_4_b"}}}}
{if has_place "gunner4" {if crew_in_place "gunner4" {with_linked_entity "gunner4" {call "ufb_gun_bind_man_4_b"}}}}
{if has_place "gunner5" {if crew_in_place "gunner5" {with_linked_entity "gunner5" {call "ufb_gun_bind_man_4_b"}}}}
{if has_place "gunner6" {if crew_in_place "gunner6" {with_linked_entity "gunner6" {call "ufb_gun_bind_man_4_b"}}}}
{if has_place "gunner7" {if crew_in_place "gunner7" {with_linked_entity "gunner7" {call "ufb_gun_bind_man_4_b"}}}}
{if has_place "gunner8" {if crew_in_place "gunner8" {with_linked_entity "gunner8" {call "ufb_gun_bind_man_4_b"}}}}
{if has_place "charger" {if crew_in_place "charger" {with_linked_entity "charger" {call "ufb_gun_bind_man_4_b"}}}}
{if has_place "charger1" {if crew_in_place "charger1" {with_linked_entity "charger1" {call "ufb_gun_bind_man_4_b"}}}}
{if has_place "charger2" {if crew_in_place "charger2" {with_linked_entity "charger2" {call "ufb_gun_bind_man_4_b"}}}}
{if has_place "charger3" {if crew_in_place "charger3" {with_linked_entity "charger3" {call "ufb_gun_bind_man_4_b"}}}}
{if has_place "charger4" {if crew_in_place "charger4" {with_linked_entity "charger4" {call "ufb_gun_bind_man_4_b"}}}}
{if has_place "charger5" {if crew_in_place "charger5" {with_linked_entity "charger5" {call "ufb_gun_bind_man_4_b"}}}}
{if has_place "charger6" {if crew_in_place "charger6" {with_linked_entity "charger6" {call "ufb_gun_bind_man_4_b"}}}}
{if has_place "charger7" {if crew_in_place "charger7" {with_linked_entity "charger7" {call "ufb_gun_bind_man_4_b"}}}}
{if has_place "charger8" {if crew_in_place "charger8" {with_linked_entity "charger8" {call "ufb_gun_bind_man_4_b"}}}}
{if has_place "loader" {if crew_in_place "loader" {with_linked_entity "loader" {call "ufb_gun_bind_man_4_b"}}}}
{if has_place "loader1" {if crew_in_place "loader1" {with_linked_entity "loader1" {call "ufb_gun_bind_man_4_b"}}}}
{if has_place "loader2" {if crew_in_place "loader2" {with_linked_entity "loader2" {call "ufb_gun_bind_man_4_b"}}}}
{if has_place "loader3" {if crew_in_place "loader3" {with_linked_entity "loader3" {call "ufb_gun_bind_man_4_b"}}}}
{if has_place "loader4" {if crew_in_place "loader4" {with_linked_entity "loader4" {call "ufb_gun_bind_man_4_b"}}}}
{if has_place "loader5" {if crew_in_place "loader5" {with_linked_entity "loader5" {call "ufb_gun_bind_man_4_b"}}}}
{if has_place "loader6" {if crew_in_place "loader6" {with_linked_entity "loader6" {call "ufb_gun_bind_man_4_b"}}}}
{if has_place "loader7" {if crew_in_place "loader7" {with_linked_entity "loader7" {call "ufb_gun_bind_man_4_b"}}}}
{if has_place "loader8" {if crew_in_place "loader8" {with_linked_entity "loader8" {call "ufb_gun_bind_man_4_b"}}}}
{if has_place "seat1" {if crew_in_place "seat1" {with_linked_entity "seat1" {call "ufb_gun_bind_man_4_b"}}}}
{if has_place "seat2" {if crew_in_place "seat2" {with_linked_entity "seat2" {call "ufb_gun_bind_man_4_b"}}}}
{if has_place "seat3" {if crew_in_place "seat3" {with_linked_entity "seat3" {call "ufb_gun_bind_man_4_b"}}}}
{if has_place "seat4" {if crew_in_place "seat4" {with_linked_entity "seat4" {call "ufb_gun_bind_man_4_b"}}}}
{if has_place "seat5" {if crew_in_place "seat5" {with_linked_entity "seat5" {call "ufb_gun_bind_man_4_b"}}}}
{if has_place "seat6" {if crew_in_place "seat6" {with_linked_entity "seat6" {call "ufb_gun_bind_man_4_b"}}}}
{if has_place "seat7" {if crew_in_place "seat7" {with_linked_entity "seat7" {call "ufb_gun_bind_man_4_b"}}}}
{if has_place "seat8" {if crew_in_place "seat8" {with_linked_entity "seat8" {call "ufb_gun_bind_man_4_b"}}}}
{if has_place "seat9" {if crew_in_place "seat9" {with_linked_entity "seat9" {call "ufb_gun_bind_man_4_b"}}}}
{if has_place "seat10" {if crew_in_place "seat10" {with_linked_entity "seat10" {call "ufb_gun_bind_man_4_b"}}}}
{if has_place "seat11" {if crew_in_place "seat11" {with_linked_entity "seat11" {call "ufb_gun_bind_man_4_b"}}}}
{if has_place "seat12" {if crew_in_place "seat12" {with_linked_entity "seat12" {call "ufb_gun_bind_man_4_b"}}}}
{if has_place "seat13" {if crew_in_place "seat13" {with_linked_entity "seat13" {call "ufb_gun_bind_man_4_b"}}}}
{if has_place "seat14" {if crew_in_place "seat14" {with_linked_entity "seat14" {call "ufb_gun_bind_man_4_b"}}}}
{if has_place "seat15" {if crew_in_place "seat15" {with_linked_entity "seat15" {call "ufb_gun_bind_man_4_b"}}}}
 }
 {on "ufb_gun_release_owner_4_b" {kill_delay "ufb_gun_owner_expiry"} {tags remove "_ufb_gun_owner_4_b"} {tags remove "_ufb_gun_escaped_4_b"} {tags remove "_ufb_gun_bound"}}
{on "ufb_gun_bind_5_b" sync
  {call "ufb_gun_left_cooldown_b"} {tags add "_ufb_gun_bound"}
  {kill_delay "ufb_gun_owner_expiry"}
  {delay 120 "ufb_gun_owner_expiry" {call "ufb_gun_release_owner_5_b"}}
  {spawn "ufb_smoke_screen_point" local_offset -700 0 0 constrain_after_dir {tags add "_ufb_gun_lease_5_b"} {delay 140 {delete}}}
  {if has_place "commander" {if crew_in_place "commander" {with_linked_entity "commander" {call "ufb_gun_bind_man_5_b"}}}}
{if has_place "driver" {if crew_in_place "driver" {with_linked_entity "driver" {call "ufb_gun_bind_man_5_b"}}}}
{if has_place "gunner" {if crew_in_place "gunner" {with_linked_entity "gunner" {call "ufb_gun_bind_man_5_b"}}}}
{if has_place "gunner1" {if crew_in_place "gunner1" {with_linked_entity "gunner1" {call "ufb_gun_bind_man_5_b"}}}}
{if has_place "gunner2" {if crew_in_place "gunner2" {with_linked_entity "gunner2" {call "ufb_gun_bind_man_5_b"}}}}
{if has_place "gunner3" {if crew_in_place "gunner3" {with_linked_entity "gunner3" {call "ufb_gun_bind_man_5_b"}}}}
{if has_place "gunner4" {if crew_in_place "gunner4" {with_linked_entity "gunner4" {call "ufb_gun_bind_man_5_b"}}}}
{if has_place "gunner5" {if crew_in_place "gunner5" {with_linked_entity "gunner5" {call "ufb_gun_bind_man_5_b"}}}}
{if has_place "gunner6" {if crew_in_place "gunner6" {with_linked_entity "gunner6" {call "ufb_gun_bind_man_5_b"}}}}
{if has_place "gunner7" {if crew_in_place "gunner7" {with_linked_entity "gunner7" {call "ufb_gun_bind_man_5_b"}}}}
{if has_place "gunner8" {if crew_in_place "gunner8" {with_linked_entity "gunner8" {call "ufb_gun_bind_man_5_b"}}}}
{if has_place "charger" {if crew_in_place "charger" {with_linked_entity "charger" {call "ufb_gun_bind_man_5_b"}}}}
{if has_place "charger1" {if crew_in_place "charger1" {with_linked_entity "charger1" {call "ufb_gun_bind_man_5_b"}}}}
{if has_place "charger2" {if crew_in_place "charger2" {with_linked_entity "charger2" {call "ufb_gun_bind_man_5_b"}}}}
{if has_place "charger3" {if crew_in_place "charger3" {with_linked_entity "charger3" {call "ufb_gun_bind_man_5_b"}}}}
{if has_place "charger4" {if crew_in_place "charger4" {with_linked_entity "charger4" {call "ufb_gun_bind_man_5_b"}}}}
{if has_place "charger5" {if crew_in_place "charger5" {with_linked_entity "charger5" {call "ufb_gun_bind_man_5_b"}}}}
{if has_place "charger6" {if crew_in_place "charger6" {with_linked_entity "charger6" {call "ufb_gun_bind_man_5_b"}}}}
{if has_place "charger7" {if crew_in_place "charger7" {with_linked_entity "charger7" {call "ufb_gun_bind_man_5_b"}}}}
{if has_place "charger8" {if crew_in_place "charger8" {with_linked_entity "charger8" {call "ufb_gun_bind_man_5_b"}}}}
{if has_place "loader" {if crew_in_place "loader" {with_linked_entity "loader" {call "ufb_gun_bind_man_5_b"}}}}
{if has_place "loader1" {if crew_in_place "loader1" {with_linked_entity "loader1" {call "ufb_gun_bind_man_5_b"}}}}
{if has_place "loader2" {if crew_in_place "loader2" {with_linked_entity "loader2" {call "ufb_gun_bind_man_5_b"}}}}
{if has_place "loader3" {if crew_in_place "loader3" {with_linked_entity "loader3" {call "ufb_gun_bind_man_5_b"}}}}
{if has_place "loader4" {if crew_in_place "loader4" {with_linked_entity "loader4" {call "ufb_gun_bind_man_5_b"}}}}
{if has_place "loader5" {if crew_in_place "loader5" {with_linked_entity "loader5" {call "ufb_gun_bind_man_5_b"}}}}
{if has_place "loader6" {if crew_in_place "loader6" {with_linked_entity "loader6" {call "ufb_gun_bind_man_5_b"}}}}
{if has_place "loader7" {if crew_in_place "loader7" {with_linked_entity "loader7" {call "ufb_gun_bind_man_5_b"}}}}
{if has_place "loader8" {if crew_in_place "loader8" {with_linked_entity "loader8" {call "ufb_gun_bind_man_5_b"}}}}
{if has_place "seat1" {if crew_in_place "seat1" {with_linked_entity "seat1" {call "ufb_gun_bind_man_5_b"}}}}
{if has_place "seat2" {if crew_in_place "seat2" {with_linked_entity "seat2" {call "ufb_gun_bind_man_5_b"}}}}
{if has_place "seat3" {if crew_in_place "seat3" {with_linked_entity "seat3" {call "ufb_gun_bind_man_5_b"}}}}
{if has_place "seat4" {if crew_in_place "seat4" {with_linked_entity "seat4" {call "ufb_gun_bind_man_5_b"}}}}
{if has_place "seat5" {if crew_in_place "seat5" {with_linked_entity "seat5" {call "ufb_gun_bind_man_5_b"}}}}
{if has_place "seat6" {if crew_in_place "seat6" {with_linked_entity "seat6" {call "ufb_gun_bind_man_5_b"}}}}
{if has_place "seat7" {if crew_in_place "seat7" {with_linked_entity "seat7" {call "ufb_gun_bind_man_5_b"}}}}
{if has_place "seat8" {if crew_in_place "seat8" {with_linked_entity "seat8" {call "ufb_gun_bind_man_5_b"}}}}
{if has_place "seat9" {if crew_in_place "seat9" {with_linked_entity "seat9" {call "ufb_gun_bind_man_5_b"}}}}
{if has_place "seat10" {if crew_in_place "seat10" {with_linked_entity "seat10" {call "ufb_gun_bind_man_5_b"}}}}
{if has_place "seat11" {if crew_in_place "seat11" {with_linked_entity "seat11" {call "ufb_gun_bind_man_5_b"}}}}
{if has_place "seat12" {if crew_in_place "seat12" {with_linked_entity "seat12" {call "ufb_gun_bind_man_5_b"}}}}
{if has_place "seat13" {if crew_in_place "seat13" {with_linked_entity "seat13" {call "ufb_gun_bind_man_5_b"}}}}
{if has_place "seat14" {if crew_in_place "seat14" {with_linked_entity "seat14" {call "ufb_gun_bind_man_5_b"}}}}
{if has_place "seat15" {if crew_in_place "seat15" {with_linked_entity "seat15" {call "ufb_gun_bind_man_5_b"}}}}
 }
 {on "ufb_gun_release_owner_5_b" {kill_delay "ufb_gun_owner_expiry"} {tags remove "_ufb_gun_owner_5_b"} {tags remove "_ufb_gun_escaped_5_b"} {tags remove "_ufb_gun_bound"}}
{on "ufb_gun_bind_6_b" sync
  {call "ufb_gun_left_cooldown_b"} {tags add "_ufb_gun_bound"}
  {kill_delay "ufb_gun_owner_expiry"}
  {delay 120 "ufb_gun_owner_expiry" {call "ufb_gun_release_owner_6_b"}}
  {spawn "ufb_smoke_screen_point" local_offset -700 0 0 constrain_after_dir {tags add "_ufb_gun_lease_6_b"} {delay 140 {delete}}}
  {if has_place "commander" {if crew_in_place "commander" {with_linked_entity "commander" {call "ufb_gun_bind_man_6_b"}}}}
{if has_place "driver" {if crew_in_place "driver" {with_linked_entity "driver" {call "ufb_gun_bind_man_6_b"}}}}
{if has_place "gunner" {if crew_in_place "gunner" {with_linked_entity "gunner" {call "ufb_gun_bind_man_6_b"}}}}
{if has_place "gunner1" {if crew_in_place "gunner1" {with_linked_entity "gunner1" {call "ufb_gun_bind_man_6_b"}}}}
{if has_place "gunner2" {if crew_in_place "gunner2" {with_linked_entity "gunner2" {call "ufb_gun_bind_man_6_b"}}}}
{if has_place "gunner3" {if crew_in_place "gunner3" {with_linked_entity "gunner3" {call "ufb_gun_bind_man_6_b"}}}}
{if has_place "gunner4" {if crew_in_place "gunner4" {with_linked_entity "gunner4" {call "ufb_gun_bind_man_6_b"}}}}
{if has_place "gunner5" {if crew_in_place "gunner5" {with_linked_entity "gunner5" {call "ufb_gun_bind_man_6_b"}}}}
{if has_place "gunner6" {if crew_in_place "gunner6" {with_linked_entity "gunner6" {call "ufb_gun_bind_man_6_b"}}}}
{if has_place "gunner7" {if crew_in_place "gunner7" {with_linked_entity "gunner7" {call "ufb_gun_bind_man_6_b"}}}}
{if has_place "gunner8" {if crew_in_place "gunner8" {with_linked_entity "gunner8" {call "ufb_gun_bind_man_6_b"}}}}
{if has_place "charger" {if crew_in_place "charger" {with_linked_entity "charger" {call "ufb_gun_bind_man_6_b"}}}}
{if has_place "charger1" {if crew_in_place "charger1" {with_linked_entity "charger1" {call "ufb_gun_bind_man_6_b"}}}}
{if has_place "charger2" {if crew_in_place "charger2" {with_linked_entity "charger2" {call "ufb_gun_bind_man_6_b"}}}}
{if has_place "charger3" {if crew_in_place "charger3" {with_linked_entity "charger3" {call "ufb_gun_bind_man_6_b"}}}}
{if has_place "charger4" {if crew_in_place "charger4" {with_linked_entity "charger4" {call "ufb_gun_bind_man_6_b"}}}}
{if has_place "charger5" {if crew_in_place "charger5" {with_linked_entity "charger5" {call "ufb_gun_bind_man_6_b"}}}}
{if has_place "charger6" {if crew_in_place "charger6" {with_linked_entity "charger6" {call "ufb_gun_bind_man_6_b"}}}}
{if has_place "charger7" {if crew_in_place "charger7" {with_linked_entity "charger7" {call "ufb_gun_bind_man_6_b"}}}}
{if has_place "charger8" {if crew_in_place "charger8" {with_linked_entity "charger8" {call "ufb_gun_bind_man_6_b"}}}}
{if has_place "loader" {if crew_in_place "loader" {with_linked_entity "loader" {call "ufb_gun_bind_man_6_b"}}}}
{if has_place "loader1" {if crew_in_place "loader1" {with_linked_entity "loader1" {call "ufb_gun_bind_man_6_b"}}}}
{if has_place "loader2" {if crew_in_place "loader2" {with_linked_entity "loader2" {call "ufb_gun_bind_man_6_b"}}}}
{if has_place "loader3" {if crew_in_place "loader3" {with_linked_entity "loader3" {call "ufb_gun_bind_man_6_b"}}}}
{if has_place "loader4" {if crew_in_place "loader4" {with_linked_entity "loader4" {call "ufb_gun_bind_man_6_b"}}}}
{if has_place "loader5" {if crew_in_place "loader5" {with_linked_entity "loader5" {call "ufb_gun_bind_man_6_b"}}}}
{if has_place "loader6" {if crew_in_place "loader6" {with_linked_entity "loader6" {call "ufb_gun_bind_man_6_b"}}}}
{if has_place "loader7" {if crew_in_place "loader7" {with_linked_entity "loader7" {call "ufb_gun_bind_man_6_b"}}}}
{if has_place "loader8" {if crew_in_place "loader8" {with_linked_entity "loader8" {call "ufb_gun_bind_man_6_b"}}}}
{if has_place "seat1" {if crew_in_place "seat1" {with_linked_entity "seat1" {call "ufb_gun_bind_man_6_b"}}}}
{if has_place "seat2" {if crew_in_place "seat2" {with_linked_entity "seat2" {call "ufb_gun_bind_man_6_b"}}}}
{if has_place "seat3" {if crew_in_place "seat3" {with_linked_entity "seat3" {call "ufb_gun_bind_man_6_b"}}}}
{if has_place "seat4" {if crew_in_place "seat4" {with_linked_entity "seat4" {call "ufb_gun_bind_man_6_b"}}}}
{if has_place "seat5" {if crew_in_place "seat5" {with_linked_entity "seat5" {call "ufb_gun_bind_man_6_b"}}}}
{if has_place "seat6" {if crew_in_place "seat6" {with_linked_entity "seat6" {call "ufb_gun_bind_man_6_b"}}}}
{if has_place "seat7" {if crew_in_place "seat7" {with_linked_entity "seat7" {call "ufb_gun_bind_man_6_b"}}}}
{if has_place "seat8" {if crew_in_place "seat8" {with_linked_entity "seat8" {call "ufb_gun_bind_man_6_b"}}}}
{if has_place "seat9" {if crew_in_place "seat9" {with_linked_entity "seat9" {call "ufb_gun_bind_man_6_b"}}}}
{if has_place "seat10" {if crew_in_place "seat10" {with_linked_entity "seat10" {call "ufb_gun_bind_man_6_b"}}}}
{if has_place "seat11" {if crew_in_place "seat11" {with_linked_entity "seat11" {call "ufb_gun_bind_man_6_b"}}}}
{if has_place "seat12" {if crew_in_place "seat12" {with_linked_entity "seat12" {call "ufb_gun_bind_man_6_b"}}}}
{if has_place "seat13" {if crew_in_place "seat13" {with_linked_entity "seat13" {call "ufb_gun_bind_man_6_b"}}}}
{if has_place "seat14" {if crew_in_place "seat14" {with_linked_entity "seat14" {call "ufb_gun_bind_man_6_b"}}}}
{if has_place "seat15" {if crew_in_place "seat15" {with_linked_entity "seat15" {call "ufb_gun_bind_man_6_b"}}}}
 }
 {on "ufb_gun_release_owner_6_b" {kill_delay "ufb_gun_owner_expiry"} {tags remove "_ufb_gun_owner_6_b"} {tags remove "_ufb_gun_escaped_6_b"} {tags remove "_ufb_gun_bound"}}
{on "ufb_gun_bind_7_b" sync
  {call "ufb_gun_left_cooldown_b"} {tags add "_ufb_gun_bound"}
  {kill_delay "ufb_gun_owner_expiry"}
  {delay 120 "ufb_gun_owner_expiry" {call "ufb_gun_release_owner_7_b"}}
  {spawn "ufb_smoke_screen_point" local_offset -700 0 0 constrain_after_dir {tags add "_ufb_gun_lease_7_b"} {delay 140 {delete}}}
  {if has_place "commander" {if crew_in_place "commander" {with_linked_entity "commander" {call "ufb_gun_bind_man_7_b"}}}}
{if has_place "driver" {if crew_in_place "driver" {with_linked_entity "driver" {call "ufb_gun_bind_man_7_b"}}}}
{if has_place "gunner" {if crew_in_place "gunner" {with_linked_entity "gunner" {call "ufb_gun_bind_man_7_b"}}}}
{if has_place "gunner1" {if crew_in_place "gunner1" {with_linked_entity "gunner1" {call "ufb_gun_bind_man_7_b"}}}}
{if has_place "gunner2" {if crew_in_place "gunner2" {with_linked_entity "gunner2" {call "ufb_gun_bind_man_7_b"}}}}
{if has_place "gunner3" {if crew_in_place "gunner3" {with_linked_entity "gunner3" {call "ufb_gun_bind_man_7_b"}}}}
{if has_place "gunner4" {if crew_in_place "gunner4" {with_linked_entity "gunner4" {call "ufb_gun_bind_man_7_b"}}}}
{if has_place "gunner5" {if crew_in_place "gunner5" {with_linked_entity "gunner5" {call "ufb_gun_bind_man_7_b"}}}}
{if has_place "gunner6" {if crew_in_place "gunner6" {with_linked_entity "gunner6" {call "ufb_gun_bind_man_7_b"}}}}
{if has_place "gunner7" {if crew_in_place "gunner7" {with_linked_entity "gunner7" {call "ufb_gun_bind_man_7_b"}}}}
{if has_place "gunner8" {if crew_in_place "gunner8" {with_linked_entity "gunner8" {call "ufb_gun_bind_man_7_b"}}}}
{if has_place "charger" {if crew_in_place "charger" {with_linked_entity "charger" {call "ufb_gun_bind_man_7_b"}}}}
{if has_place "charger1" {if crew_in_place "charger1" {with_linked_entity "charger1" {call "ufb_gun_bind_man_7_b"}}}}
{if has_place "charger2" {if crew_in_place "charger2" {with_linked_entity "charger2" {call "ufb_gun_bind_man_7_b"}}}}
{if has_place "charger3" {if crew_in_place "charger3" {with_linked_entity "charger3" {call "ufb_gun_bind_man_7_b"}}}}
{if has_place "charger4" {if crew_in_place "charger4" {with_linked_entity "charger4" {call "ufb_gun_bind_man_7_b"}}}}
{if has_place "charger5" {if crew_in_place "charger5" {with_linked_entity "charger5" {call "ufb_gun_bind_man_7_b"}}}}
{if has_place "charger6" {if crew_in_place "charger6" {with_linked_entity "charger6" {call "ufb_gun_bind_man_7_b"}}}}
{if has_place "charger7" {if crew_in_place "charger7" {with_linked_entity "charger7" {call "ufb_gun_bind_man_7_b"}}}}
{if has_place "charger8" {if crew_in_place "charger8" {with_linked_entity "charger8" {call "ufb_gun_bind_man_7_b"}}}}
{if has_place "loader" {if crew_in_place "loader" {with_linked_entity "loader" {call "ufb_gun_bind_man_7_b"}}}}
{if has_place "loader1" {if crew_in_place "loader1" {with_linked_entity "loader1" {call "ufb_gun_bind_man_7_b"}}}}
{if has_place "loader2" {if crew_in_place "loader2" {with_linked_entity "loader2" {call "ufb_gun_bind_man_7_b"}}}}
{if has_place "loader3" {if crew_in_place "loader3" {with_linked_entity "loader3" {call "ufb_gun_bind_man_7_b"}}}}
{if has_place "loader4" {if crew_in_place "loader4" {with_linked_entity "loader4" {call "ufb_gun_bind_man_7_b"}}}}
{if has_place "loader5" {if crew_in_place "loader5" {with_linked_entity "loader5" {call "ufb_gun_bind_man_7_b"}}}}
{if has_place "loader6" {if crew_in_place "loader6" {with_linked_entity "loader6" {call "ufb_gun_bind_man_7_b"}}}}
{if has_place "loader7" {if crew_in_place "loader7" {with_linked_entity "loader7" {call "ufb_gun_bind_man_7_b"}}}}
{if has_place "loader8" {if crew_in_place "loader8" {with_linked_entity "loader8" {call "ufb_gun_bind_man_7_b"}}}}
{if has_place "seat1" {if crew_in_place "seat1" {with_linked_entity "seat1" {call "ufb_gun_bind_man_7_b"}}}}
{if has_place "seat2" {if crew_in_place "seat2" {with_linked_entity "seat2" {call "ufb_gun_bind_man_7_b"}}}}
{if has_place "seat3" {if crew_in_place "seat3" {with_linked_entity "seat3" {call "ufb_gun_bind_man_7_b"}}}}
{if has_place "seat4" {if crew_in_place "seat4" {with_linked_entity "seat4" {call "ufb_gun_bind_man_7_b"}}}}
{if has_place "seat5" {if crew_in_place "seat5" {with_linked_entity "seat5" {call "ufb_gun_bind_man_7_b"}}}}
{if has_place "seat6" {if crew_in_place "seat6" {with_linked_entity "seat6" {call "ufb_gun_bind_man_7_b"}}}}
{if has_place "seat7" {if crew_in_place "seat7" {with_linked_entity "seat7" {call "ufb_gun_bind_man_7_b"}}}}
{if has_place "seat8" {if crew_in_place "seat8" {with_linked_entity "seat8" {call "ufb_gun_bind_man_7_b"}}}}
{if has_place "seat9" {if crew_in_place "seat9" {with_linked_entity "seat9" {call "ufb_gun_bind_man_7_b"}}}}
{if has_place "seat10" {if crew_in_place "seat10" {with_linked_entity "seat10" {call "ufb_gun_bind_man_7_b"}}}}
{if has_place "seat11" {if crew_in_place "seat11" {with_linked_entity "seat11" {call "ufb_gun_bind_man_7_b"}}}}
{if has_place "seat12" {if crew_in_place "seat12" {with_linked_entity "seat12" {call "ufb_gun_bind_man_7_b"}}}}
{if has_place "seat13" {if crew_in_place "seat13" {with_linked_entity "seat13" {call "ufb_gun_bind_man_7_b"}}}}
{if has_place "seat14" {if crew_in_place "seat14" {with_linked_entity "seat14" {call "ufb_gun_bind_man_7_b"}}}}
{if has_place "seat15" {if crew_in_place "seat15" {with_linked_entity "seat15" {call "ufb_gun_bind_man_7_b"}}}}
 }
 {on "ufb_gun_release_owner_7_b" {kill_delay "ufb_gun_owner_expiry"} {tags remove "_ufb_gun_owner_7_b"} {tags remove "_ufb_gun_escaped_7_b"} {tags remove "_ufb_gun_bound"}}
{on "ufb_gun_bind_8_b" sync
  {call "ufb_gun_left_cooldown_b"} {tags add "_ufb_gun_bound"}
  {kill_delay "ufb_gun_owner_expiry"}
  {delay 120 "ufb_gun_owner_expiry" {call "ufb_gun_release_owner_8_b"}}
  {spawn "ufb_smoke_screen_point" local_offset -700 0 0 constrain_after_dir {tags add "_ufb_gun_lease_8_b"} {delay 140 {delete}}}
  {if has_place "commander" {if crew_in_place "commander" {with_linked_entity "commander" {call "ufb_gun_bind_man_8_b"}}}}
{if has_place "driver" {if crew_in_place "driver" {with_linked_entity "driver" {call "ufb_gun_bind_man_8_b"}}}}
{if has_place "gunner" {if crew_in_place "gunner" {with_linked_entity "gunner" {call "ufb_gun_bind_man_8_b"}}}}
{if has_place "gunner1" {if crew_in_place "gunner1" {with_linked_entity "gunner1" {call "ufb_gun_bind_man_8_b"}}}}
{if has_place "gunner2" {if crew_in_place "gunner2" {with_linked_entity "gunner2" {call "ufb_gun_bind_man_8_b"}}}}
{if has_place "gunner3" {if crew_in_place "gunner3" {with_linked_entity "gunner3" {call "ufb_gun_bind_man_8_b"}}}}
{if has_place "gunner4" {if crew_in_place "gunner4" {with_linked_entity "gunner4" {call "ufb_gun_bind_man_8_b"}}}}
{if has_place "gunner5" {if crew_in_place "gunner5" {with_linked_entity "gunner5" {call "ufb_gun_bind_man_8_b"}}}}
{if has_place "gunner6" {if crew_in_place "gunner6" {with_linked_entity "gunner6" {call "ufb_gun_bind_man_8_b"}}}}
{if has_place "gunner7" {if crew_in_place "gunner7" {with_linked_entity "gunner7" {call "ufb_gun_bind_man_8_b"}}}}
{if has_place "gunner8" {if crew_in_place "gunner8" {with_linked_entity "gunner8" {call "ufb_gun_bind_man_8_b"}}}}
{if has_place "charger" {if crew_in_place "charger" {with_linked_entity "charger" {call "ufb_gun_bind_man_8_b"}}}}
{if has_place "charger1" {if crew_in_place "charger1" {with_linked_entity "charger1" {call "ufb_gun_bind_man_8_b"}}}}
{if has_place "charger2" {if crew_in_place "charger2" {with_linked_entity "charger2" {call "ufb_gun_bind_man_8_b"}}}}
{if has_place "charger3" {if crew_in_place "charger3" {with_linked_entity "charger3" {call "ufb_gun_bind_man_8_b"}}}}
{if has_place "charger4" {if crew_in_place "charger4" {with_linked_entity "charger4" {call "ufb_gun_bind_man_8_b"}}}}
{if has_place "charger5" {if crew_in_place "charger5" {with_linked_entity "charger5" {call "ufb_gun_bind_man_8_b"}}}}
{if has_place "charger6" {if crew_in_place "charger6" {with_linked_entity "charger6" {call "ufb_gun_bind_man_8_b"}}}}
{if has_place "charger7" {if crew_in_place "charger7" {with_linked_entity "charger7" {call "ufb_gun_bind_man_8_b"}}}}
{if has_place "charger8" {if crew_in_place "charger8" {with_linked_entity "charger8" {call "ufb_gun_bind_man_8_b"}}}}
{if has_place "loader" {if crew_in_place "loader" {with_linked_entity "loader" {call "ufb_gun_bind_man_8_b"}}}}
{if has_place "loader1" {if crew_in_place "loader1" {with_linked_entity "loader1" {call "ufb_gun_bind_man_8_b"}}}}
{if has_place "loader2" {if crew_in_place "loader2" {with_linked_entity "loader2" {call "ufb_gun_bind_man_8_b"}}}}
{if has_place "loader3" {if crew_in_place "loader3" {with_linked_entity "loader3" {call "ufb_gun_bind_man_8_b"}}}}
{if has_place "loader4" {if crew_in_place "loader4" {with_linked_entity "loader4" {call "ufb_gun_bind_man_8_b"}}}}
{if has_place "loader5" {if crew_in_place "loader5" {with_linked_entity "loader5" {call "ufb_gun_bind_man_8_b"}}}}
{if has_place "loader6" {if crew_in_place "loader6" {with_linked_entity "loader6" {call "ufb_gun_bind_man_8_b"}}}}
{if has_place "loader7" {if crew_in_place "loader7" {with_linked_entity "loader7" {call "ufb_gun_bind_man_8_b"}}}}
{if has_place "loader8" {if crew_in_place "loader8" {with_linked_entity "loader8" {call "ufb_gun_bind_man_8_b"}}}}
{if has_place "seat1" {if crew_in_place "seat1" {with_linked_entity "seat1" {call "ufb_gun_bind_man_8_b"}}}}
{if has_place "seat2" {if crew_in_place "seat2" {with_linked_entity "seat2" {call "ufb_gun_bind_man_8_b"}}}}
{if has_place "seat3" {if crew_in_place "seat3" {with_linked_entity "seat3" {call "ufb_gun_bind_man_8_b"}}}}
{if has_place "seat4" {if crew_in_place "seat4" {with_linked_entity "seat4" {call "ufb_gun_bind_man_8_b"}}}}
{if has_place "seat5" {if crew_in_place "seat5" {with_linked_entity "seat5" {call "ufb_gun_bind_man_8_b"}}}}
{if has_place "seat6" {if crew_in_place "seat6" {with_linked_entity "seat6" {call "ufb_gun_bind_man_8_b"}}}}
{if has_place "seat7" {if crew_in_place "seat7" {with_linked_entity "seat7" {call "ufb_gun_bind_man_8_b"}}}}
{if has_place "seat8" {if crew_in_place "seat8" {with_linked_entity "seat8" {call "ufb_gun_bind_man_8_b"}}}}
{if has_place "seat9" {if crew_in_place "seat9" {with_linked_entity "seat9" {call "ufb_gun_bind_man_8_b"}}}}
{if has_place "seat10" {if crew_in_place "seat10" {with_linked_entity "seat10" {call "ufb_gun_bind_man_8_b"}}}}
{if has_place "seat11" {if crew_in_place "seat11" {with_linked_entity "seat11" {call "ufb_gun_bind_man_8_b"}}}}
{if has_place "seat12" {if crew_in_place "seat12" {with_linked_entity "seat12" {call "ufb_gun_bind_man_8_b"}}}}
{if has_place "seat13" {if crew_in_place "seat13" {with_linked_entity "seat13" {call "ufb_gun_bind_man_8_b"}}}}
{if has_place "seat14" {if crew_in_place "seat14" {with_linked_entity "seat14" {call "ufb_gun_bind_man_8_b"}}}}
{if has_place "seat15" {if crew_in_place "seat15" {with_linked_entity "seat15" {call "ufb_gun_bind_man_8_b"}}}}
 }
 {on "ufb_gun_release_owner_8_b" {kill_delay "ufb_gun_owner_expiry"} {tags remove "_ufb_gun_owner_8_b"} {tags remove "_ufb_gun_escaped_8_b"} {tags remove "_ufb_gun_bound"}}
{on "ufb_gun_bind_9_b" sync
  {call "ufb_gun_left_cooldown_b"} {tags add "_ufb_gun_bound"}
  {kill_delay "ufb_gun_owner_expiry"}
  {delay 120 "ufb_gun_owner_expiry" {call "ufb_gun_release_owner_9_b"}}
  {spawn "ufb_smoke_screen_point" local_offset -700 0 0 constrain_after_dir {tags add "_ufb_gun_lease_9_b"} {delay 140 {delete}}}
  {if has_place "commander" {if crew_in_place "commander" {with_linked_entity "commander" {call "ufb_gun_bind_man_9_b"}}}}
{if has_place "driver" {if crew_in_place "driver" {with_linked_entity "driver" {call "ufb_gun_bind_man_9_b"}}}}
{if has_place "gunner" {if crew_in_place "gunner" {with_linked_entity "gunner" {call "ufb_gun_bind_man_9_b"}}}}
{if has_place "gunner1" {if crew_in_place "gunner1" {with_linked_entity "gunner1" {call "ufb_gun_bind_man_9_b"}}}}
{if has_place "gunner2" {if crew_in_place "gunner2" {with_linked_entity "gunner2" {call "ufb_gun_bind_man_9_b"}}}}
{if has_place "gunner3" {if crew_in_place "gunner3" {with_linked_entity "gunner3" {call "ufb_gun_bind_man_9_b"}}}}
{if has_place "gunner4" {if crew_in_place "gunner4" {with_linked_entity "gunner4" {call "ufb_gun_bind_man_9_b"}}}}
{if has_place "gunner5" {if crew_in_place "gunner5" {with_linked_entity "gunner5" {call "ufb_gun_bind_man_9_b"}}}}
{if has_place "gunner6" {if crew_in_place "gunner6" {with_linked_entity "gunner6" {call "ufb_gun_bind_man_9_b"}}}}
{if has_place "gunner7" {if crew_in_place "gunner7" {with_linked_entity "gunner7" {call "ufb_gun_bind_man_9_b"}}}}
{if has_place "gunner8" {if crew_in_place "gunner8" {with_linked_entity "gunner8" {call "ufb_gun_bind_man_9_b"}}}}
{if has_place "charger" {if crew_in_place "charger" {with_linked_entity "charger" {call "ufb_gun_bind_man_9_b"}}}}
{if has_place "charger1" {if crew_in_place "charger1" {with_linked_entity "charger1" {call "ufb_gun_bind_man_9_b"}}}}
{if has_place "charger2" {if crew_in_place "charger2" {with_linked_entity "charger2" {call "ufb_gun_bind_man_9_b"}}}}
{if has_place "charger3" {if crew_in_place "charger3" {with_linked_entity "charger3" {call "ufb_gun_bind_man_9_b"}}}}
{if has_place "charger4" {if crew_in_place "charger4" {with_linked_entity "charger4" {call "ufb_gun_bind_man_9_b"}}}}
{if has_place "charger5" {if crew_in_place "charger5" {with_linked_entity "charger5" {call "ufb_gun_bind_man_9_b"}}}}
{if has_place "charger6" {if crew_in_place "charger6" {with_linked_entity "charger6" {call "ufb_gun_bind_man_9_b"}}}}
{if has_place "charger7" {if crew_in_place "charger7" {with_linked_entity "charger7" {call "ufb_gun_bind_man_9_b"}}}}
{if has_place "charger8" {if crew_in_place "charger8" {with_linked_entity "charger8" {call "ufb_gun_bind_man_9_b"}}}}
{if has_place "loader" {if crew_in_place "loader" {with_linked_entity "loader" {call "ufb_gun_bind_man_9_b"}}}}
{if has_place "loader1" {if crew_in_place "loader1" {with_linked_entity "loader1" {call "ufb_gun_bind_man_9_b"}}}}
{if has_place "loader2" {if crew_in_place "loader2" {with_linked_entity "loader2" {call "ufb_gun_bind_man_9_b"}}}}
{if has_place "loader3" {if crew_in_place "loader3" {with_linked_entity "loader3" {call "ufb_gun_bind_man_9_b"}}}}
{if has_place "loader4" {if crew_in_place "loader4" {with_linked_entity "loader4" {call "ufb_gun_bind_man_9_b"}}}}
{if has_place "loader5" {if crew_in_place "loader5" {with_linked_entity "loader5" {call "ufb_gun_bind_man_9_b"}}}}
{if has_place "loader6" {if crew_in_place "loader6" {with_linked_entity "loader6" {call "ufb_gun_bind_man_9_b"}}}}
{if has_place "loader7" {if crew_in_place "loader7" {with_linked_entity "loader7" {call "ufb_gun_bind_man_9_b"}}}}
{if has_place "loader8" {if crew_in_place "loader8" {with_linked_entity "loader8" {call "ufb_gun_bind_man_9_b"}}}}
{if has_place "seat1" {if crew_in_place "seat1" {with_linked_entity "seat1" {call "ufb_gun_bind_man_9_b"}}}}
{if has_place "seat2" {if crew_in_place "seat2" {with_linked_entity "seat2" {call "ufb_gun_bind_man_9_b"}}}}
{if has_place "seat3" {if crew_in_place "seat3" {with_linked_entity "seat3" {call "ufb_gun_bind_man_9_b"}}}}
{if has_place "seat4" {if crew_in_place "seat4" {with_linked_entity "seat4" {call "ufb_gun_bind_man_9_b"}}}}
{if has_place "seat5" {if crew_in_place "seat5" {with_linked_entity "seat5" {call "ufb_gun_bind_man_9_b"}}}}
{if has_place "seat6" {if crew_in_place "seat6" {with_linked_entity "seat6" {call "ufb_gun_bind_man_9_b"}}}}
{if has_place "seat7" {if crew_in_place "seat7" {with_linked_entity "seat7" {call "ufb_gun_bind_man_9_b"}}}}
{if has_place "seat8" {if crew_in_place "seat8" {with_linked_entity "seat8" {call "ufb_gun_bind_man_9_b"}}}}
{if has_place "seat9" {if crew_in_place "seat9" {with_linked_entity "seat9" {call "ufb_gun_bind_man_9_b"}}}}
{if has_place "seat10" {if crew_in_place "seat10" {with_linked_entity "seat10" {call "ufb_gun_bind_man_9_b"}}}}
{if has_place "seat11" {if crew_in_place "seat11" {with_linked_entity "seat11" {call "ufb_gun_bind_man_9_b"}}}}
{if has_place "seat12" {if crew_in_place "seat12" {with_linked_entity "seat12" {call "ufb_gun_bind_man_9_b"}}}}
{if has_place "seat13" {if crew_in_place "seat13" {with_linked_entity "seat13" {call "ufb_gun_bind_man_9_b"}}}}
{if has_place "seat14" {if crew_in_place "seat14" {with_linked_entity "seat14" {call "ufb_gun_bind_man_9_b"}}}}
{if has_place "seat15" {if crew_in_place "seat15" {with_linked_entity "seat15" {call "ufb_gun_bind_man_9_b"}}}}
 }
 {on "ufb_gun_release_owner_9_b" {kill_delay "ufb_gun_owner_expiry"} {tags remove "_ufb_gun_owner_9_b"} {tags remove "_ufb_gun_escaped_9_b"} {tags remove "_ufb_gun_bound"}}
{on "ufb_gun_bind_10_b" sync
  {call "ufb_gun_left_cooldown_b"} {tags add "_ufb_gun_bound"}
  {kill_delay "ufb_gun_owner_expiry"}
  {delay 120 "ufb_gun_owner_expiry" {call "ufb_gun_release_owner_10_b"}}
  {spawn "ufb_smoke_screen_point" local_offset -700 0 0 constrain_after_dir {tags add "_ufb_gun_lease_10_b"} {delay 140 {delete}}}
  {if has_place "commander" {if crew_in_place "commander" {with_linked_entity "commander" {call "ufb_gun_bind_man_10_b"}}}}
{if has_place "driver" {if crew_in_place "driver" {with_linked_entity "driver" {call "ufb_gun_bind_man_10_b"}}}}
{if has_place "gunner" {if crew_in_place "gunner" {with_linked_entity "gunner" {call "ufb_gun_bind_man_10_b"}}}}
{if has_place "gunner1" {if crew_in_place "gunner1" {with_linked_entity "gunner1" {call "ufb_gun_bind_man_10_b"}}}}
{if has_place "gunner2" {if crew_in_place "gunner2" {with_linked_entity "gunner2" {call "ufb_gun_bind_man_10_b"}}}}
{if has_place "gunner3" {if crew_in_place "gunner3" {with_linked_entity "gunner3" {call "ufb_gun_bind_man_10_b"}}}}
{if has_place "gunner4" {if crew_in_place "gunner4" {with_linked_entity "gunner4" {call "ufb_gun_bind_man_10_b"}}}}
{if has_place "gunner5" {if crew_in_place "gunner5" {with_linked_entity "gunner5" {call "ufb_gun_bind_man_10_b"}}}}
{if has_place "gunner6" {if crew_in_place "gunner6" {with_linked_entity "gunner6" {call "ufb_gun_bind_man_10_b"}}}}
{if has_place "gunner7" {if crew_in_place "gunner7" {with_linked_entity "gunner7" {call "ufb_gun_bind_man_10_b"}}}}
{if has_place "gunner8" {if crew_in_place "gunner8" {with_linked_entity "gunner8" {call "ufb_gun_bind_man_10_b"}}}}
{if has_place "charger" {if crew_in_place "charger" {with_linked_entity "charger" {call "ufb_gun_bind_man_10_b"}}}}
{if has_place "charger1" {if crew_in_place "charger1" {with_linked_entity "charger1" {call "ufb_gun_bind_man_10_b"}}}}
{if has_place "charger2" {if crew_in_place "charger2" {with_linked_entity "charger2" {call "ufb_gun_bind_man_10_b"}}}}
{if has_place "charger3" {if crew_in_place "charger3" {with_linked_entity "charger3" {call "ufb_gun_bind_man_10_b"}}}}
{if has_place "charger4" {if crew_in_place "charger4" {with_linked_entity "charger4" {call "ufb_gun_bind_man_10_b"}}}}
{if has_place "charger5" {if crew_in_place "charger5" {with_linked_entity "charger5" {call "ufb_gun_bind_man_10_b"}}}}
{if has_place "charger6" {if crew_in_place "charger6" {with_linked_entity "charger6" {call "ufb_gun_bind_man_10_b"}}}}
{if has_place "charger7" {if crew_in_place "charger7" {with_linked_entity "charger7" {call "ufb_gun_bind_man_10_b"}}}}
{if has_place "charger8" {if crew_in_place "charger8" {with_linked_entity "charger8" {call "ufb_gun_bind_man_10_b"}}}}
{if has_place "loader" {if crew_in_place "loader" {with_linked_entity "loader" {call "ufb_gun_bind_man_10_b"}}}}
{if has_place "loader1" {if crew_in_place "loader1" {with_linked_entity "loader1" {call "ufb_gun_bind_man_10_b"}}}}
{if has_place "loader2" {if crew_in_place "loader2" {with_linked_entity "loader2" {call "ufb_gun_bind_man_10_b"}}}}
{if has_place "loader3" {if crew_in_place "loader3" {with_linked_entity "loader3" {call "ufb_gun_bind_man_10_b"}}}}
{if has_place "loader4" {if crew_in_place "loader4" {with_linked_entity "loader4" {call "ufb_gun_bind_man_10_b"}}}}
{if has_place "loader5" {if crew_in_place "loader5" {with_linked_entity "loader5" {call "ufb_gun_bind_man_10_b"}}}}
{if has_place "loader6" {if crew_in_place "loader6" {with_linked_entity "loader6" {call "ufb_gun_bind_man_10_b"}}}}
{if has_place "loader7" {if crew_in_place "loader7" {with_linked_entity "loader7" {call "ufb_gun_bind_man_10_b"}}}}
{if has_place "loader8" {if crew_in_place "loader8" {with_linked_entity "loader8" {call "ufb_gun_bind_man_10_b"}}}}
{if has_place "seat1" {if crew_in_place "seat1" {with_linked_entity "seat1" {call "ufb_gun_bind_man_10_b"}}}}
{if has_place "seat2" {if crew_in_place "seat2" {with_linked_entity "seat2" {call "ufb_gun_bind_man_10_b"}}}}
{if has_place "seat3" {if crew_in_place "seat3" {with_linked_entity "seat3" {call "ufb_gun_bind_man_10_b"}}}}
{if has_place "seat4" {if crew_in_place "seat4" {with_linked_entity "seat4" {call "ufb_gun_bind_man_10_b"}}}}
{if has_place "seat5" {if crew_in_place "seat5" {with_linked_entity "seat5" {call "ufb_gun_bind_man_10_b"}}}}
{if has_place "seat6" {if crew_in_place "seat6" {with_linked_entity "seat6" {call "ufb_gun_bind_man_10_b"}}}}
{if has_place "seat7" {if crew_in_place "seat7" {with_linked_entity "seat7" {call "ufb_gun_bind_man_10_b"}}}}
{if has_place "seat8" {if crew_in_place "seat8" {with_linked_entity "seat8" {call "ufb_gun_bind_man_10_b"}}}}
{if has_place "seat9" {if crew_in_place "seat9" {with_linked_entity "seat9" {call "ufb_gun_bind_man_10_b"}}}}
{if has_place "seat10" {if crew_in_place "seat10" {with_linked_entity "seat10" {call "ufb_gun_bind_man_10_b"}}}}
{if has_place "seat11" {if crew_in_place "seat11" {with_linked_entity "seat11" {call "ufb_gun_bind_man_10_b"}}}}
{if has_place "seat12" {if crew_in_place "seat12" {with_linked_entity "seat12" {call "ufb_gun_bind_man_10_b"}}}}
{if has_place "seat13" {if crew_in_place "seat13" {with_linked_entity "seat13" {call "ufb_gun_bind_man_10_b"}}}}
{if has_place "seat14" {if crew_in_place "seat14" {with_linked_entity "seat14" {call "ufb_gun_bind_man_10_b"}}}}
{if has_place "seat15" {if crew_in_place "seat15" {with_linked_entity "seat15" {call "ufb_gun_bind_man_10_b"}}}}
 }
 {on "ufb_gun_release_owner_10_b" {kill_delay "ufb_gun_owner_expiry"} {tags remove "_ufb_gun_owner_10_b"} {tags remove "_ufb_gun_escaped_10_b"} {tags remove "_ufb_gun_bound"}}
{on "ufb_gun_bind_11_b" sync
  {call "ufb_gun_left_cooldown_b"} {tags add "_ufb_gun_bound"}
  {kill_delay "ufb_gun_owner_expiry"}
  {delay 120 "ufb_gun_owner_expiry" {call "ufb_gun_release_owner_11_b"}}
  {spawn "ufb_smoke_screen_point" local_offset -700 0 0 constrain_after_dir {tags add "_ufb_gun_lease_11_b"} {delay 140 {delete}}}
  {if has_place "commander" {if crew_in_place "commander" {with_linked_entity "commander" {call "ufb_gun_bind_man_11_b"}}}}
{if has_place "driver" {if crew_in_place "driver" {with_linked_entity "driver" {call "ufb_gun_bind_man_11_b"}}}}
{if has_place "gunner" {if crew_in_place "gunner" {with_linked_entity "gunner" {call "ufb_gun_bind_man_11_b"}}}}
{if has_place "gunner1" {if crew_in_place "gunner1" {with_linked_entity "gunner1" {call "ufb_gun_bind_man_11_b"}}}}
{if has_place "gunner2" {if crew_in_place "gunner2" {with_linked_entity "gunner2" {call "ufb_gun_bind_man_11_b"}}}}
{if has_place "gunner3" {if crew_in_place "gunner3" {with_linked_entity "gunner3" {call "ufb_gun_bind_man_11_b"}}}}
{if has_place "gunner4" {if crew_in_place "gunner4" {with_linked_entity "gunner4" {call "ufb_gun_bind_man_11_b"}}}}
{if has_place "gunner5" {if crew_in_place "gunner5" {with_linked_entity "gunner5" {call "ufb_gun_bind_man_11_b"}}}}
{if has_place "gunner6" {if crew_in_place "gunner6" {with_linked_entity "gunner6" {call "ufb_gun_bind_man_11_b"}}}}
{if has_place "gunner7" {if crew_in_place "gunner7" {with_linked_entity "gunner7" {call "ufb_gun_bind_man_11_b"}}}}
{if has_place "gunner8" {if crew_in_place "gunner8" {with_linked_entity "gunner8" {call "ufb_gun_bind_man_11_b"}}}}
{if has_place "charger" {if crew_in_place "charger" {with_linked_entity "charger" {call "ufb_gun_bind_man_11_b"}}}}
{if has_place "charger1" {if crew_in_place "charger1" {with_linked_entity "charger1" {call "ufb_gun_bind_man_11_b"}}}}
{if has_place "charger2" {if crew_in_place "charger2" {with_linked_entity "charger2" {call "ufb_gun_bind_man_11_b"}}}}
{if has_place "charger3" {if crew_in_place "charger3" {with_linked_entity "charger3" {call "ufb_gun_bind_man_11_b"}}}}
{if has_place "charger4" {if crew_in_place "charger4" {with_linked_entity "charger4" {call "ufb_gun_bind_man_11_b"}}}}
{if has_place "charger5" {if crew_in_place "charger5" {with_linked_entity "charger5" {call "ufb_gun_bind_man_11_b"}}}}
{if has_place "charger6" {if crew_in_place "charger6" {with_linked_entity "charger6" {call "ufb_gun_bind_man_11_b"}}}}
{if has_place "charger7" {if crew_in_place "charger7" {with_linked_entity "charger7" {call "ufb_gun_bind_man_11_b"}}}}
{if has_place "charger8" {if crew_in_place "charger8" {with_linked_entity "charger8" {call "ufb_gun_bind_man_11_b"}}}}
{if has_place "loader" {if crew_in_place "loader" {with_linked_entity "loader" {call "ufb_gun_bind_man_11_b"}}}}
{if has_place "loader1" {if crew_in_place "loader1" {with_linked_entity "loader1" {call "ufb_gun_bind_man_11_b"}}}}
{if has_place "loader2" {if crew_in_place "loader2" {with_linked_entity "loader2" {call "ufb_gun_bind_man_11_b"}}}}
{if has_place "loader3" {if crew_in_place "loader3" {with_linked_entity "loader3" {call "ufb_gun_bind_man_11_b"}}}}
{if has_place "loader4" {if crew_in_place "loader4" {with_linked_entity "loader4" {call "ufb_gun_bind_man_11_b"}}}}
{if has_place "loader5" {if crew_in_place "loader5" {with_linked_entity "loader5" {call "ufb_gun_bind_man_11_b"}}}}
{if has_place "loader6" {if crew_in_place "loader6" {with_linked_entity "loader6" {call "ufb_gun_bind_man_11_b"}}}}
{if has_place "loader7" {if crew_in_place "loader7" {with_linked_entity "loader7" {call "ufb_gun_bind_man_11_b"}}}}
{if has_place "loader8" {if crew_in_place "loader8" {with_linked_entity "loader8" {call "ufb_gun_bind_man_11_b"}}}}
{if has_place "seat1" {if crew_in_place "seat1" {with_linked_entity "seat1" {call "ufb_gun_bind_man_11_b"}}}}
{if has_place "seat2" {if crew_in_place "seat2" {with_linked_entity "seat2" {call "ufb_gun_bind_man_11_b"}}}}
{if has_place "seat3" {if crew_in_place "seat3" {with_linked_entity "seat3" {call "ufb_gun_bind_man_11_b"}}}}
{if has_place "seat4" {if crew_in_place "seat4" {with_linked_entity "seat4" {call "ufb_gun_bind_man_11_b"}}}}
{if has_place "seat5" {if crew_in_place "seat5" {with_linked_entity "seat5" {call "ufb_gun_bind_man_11_b"}}}}
{if has_place "seat6" {if crew_in_place "seat6" {with_linked_entity "seat6" {call "ufb_gun_bind_man_11_b"}}}}
{if has_place "seat7" {if crew_in_place "seat7" {with_linked_entity "seat7" {call "ufb_gun_bind_man_11_b"}}}}
{if has_place "seat8" {if crew_in_place "seat8" {with_linked_entity "seat8" {call "ufb_gun_bind_man_11_b"}}}}
{if has_place "seat9" {if crew_in_place "seat9" {with_linked_entity "seat9" {call "ufb_gun_bind_man_11_b"}}}}
{if has_place "seat10" {if crew_in_place "seat10" {with_linked_entity "seat10" {call "ufb_gun_bind_man_11_b"}}}}
{if has_place "seat11" {if crew_in_place "seat11" {with_linked_entity "seat11" {call "ufb_gun_bind_man_11_b"}}}}
{if has_place "seat12" {if crew_in_place "seat12" {with_linked_entity "seat12" {call "ufb_gun_bind_man_11_b"}}}}
{if has_place "seat13" {if crew_in_place "seat13" {with_linked_entity "seat13" {call "ufb_gun_bind_man_11_b"}}}}
{if has_place "seat14" {if crew_in_place "seat14" {with_linked_entity "seat14" {call "ufb_gun_bind_man_11_b"}}}}
{if has_place "seat15" {if crew_in_place "seat15" {with_linked_entity "seat15" {call "ufb_gun_bind_man_11_b"}}}}
 }
 {on "ufb_gun_release_owner_11_b" {kill_delay "ufb_gun_owner_expiry"} {tags remove "_ufb_gun_owner_11_b"} {tags remove "_ufb_gun_escaped_11_b"} {tags remove "_ufb_gun_bound"}}
{on "ufb_gun_bind_12_b" sync
  {call "ufb_gun_left_cooldown_b"} {tags add "_ufb_gun_bound"}
  {kill_delay "ufb_gun_owner_expiry"}
  {delay 120 "ufb_gun_owner_expiry" {call "ufb_gun_release_owner_12_b"}}
  {spawn "ufb_smoke_screen_point" local_offset -700 0 0 constrain_after_dir {tags add "_ufb_gun_lease_12_b"} {delay 140 {delete}}}
  {if has_place "commander" {if crew_in_place "commander" {with_linked_entity "commander" {call "ufb_gun_bind_man_12_b"}}}}
{if has_place "driver" {if crew_in_place "driver" {with_linked_entity "driver" {call "ufb_gun_bind_man_12_b"}}}}
{if has_place "gunner" {if crew_in_place "gunner" {with_linked_entity "gunner" {call "ufb_gun_bind_man_12_b"}}}}
{if has_place "gunner1" {if crew_in_place "gunner1" {with_linked_entity "gunner1" {call "ufb_gun_bind_man_12_b"}}}}
{if has_place "gunner2" {if crew_in_place "gunner2" {with_linked_entity "gunner2" {call "ufb_gun_bind_man_12_b"}}}}
{if has_place "gunner3" {if crew_in_place "gunner3" {with_linked_entity "gunner3" {call "ufb_gun_bind_man_12_b"}}}}
{if has_place "gunner4" {if crew_in_place "gunner4" {with_linked_entity "gunner4" {call "ufb_gun_bind_man_12_b"}}}}
{if has_place "gunner5" {if crew_in_place "gunner5" {with_linked_entity "gunner5" {call "ufb_gun_bind_man_12_b"}}}}
{if has_place "gunner6" {if crew_in_place "gunner6" {with_linked_entity "gunner6" {call "ufb_gun_bind_man_12_b"}}}}
{if has_place "gunner7" {if crew_in_place "gunner7" {with_linked_entity "gunner7" {call "ufb_gun_bind_man_12_b"}}}}
{if has_place "gunner8" {if crew_in_place "gunner8" {with_linked_entity "gunner8" {call "ufb_gun_bind_man_12_b"}}}}
{if has_place "charger" {if crew_in_place "charger" {with_linked_entity "charger" {call "ufb_gun_bind_man_12_b"}}}}
{if has_place "charger1" {if crew_in_place "charger1" {with_linked_entity "charger1" {call "ufb_gun_bind_man_12_b"}}}}
{if has_place "charger2" {if crew_in_place "charger2" {with_linked_entity "charger2" {call "ufb_gun_bind_man_12_b"}}}}
{if has_place "charger3" {if crew_in_place "charger3" {with_linked_entity "charger3" {call "ufb_gun_bind_man_12_b"}}}}
{if has_place "charger4" {if crew_in_place "charger4" {with_linked_entity "charger4" {call "ufb_gun_bind_man_12_b"}}}}
{if has_place "charger5" {if crew_in_place "charger5" {with_linked_entity "charger5" {call "ufb_gun_bind_man_12_b"}}}}
{if has_place "charger6" {if crew_in_place "charger6" {with_linked_entity "charger6" {call "ufb_gun_bind_man_12_b"}}}}
{if has_place "charger7" {if crew_in_place "charger7" {with_linked_entity "charger7" {call "ufb_gun_bind_man_12_b"}}}}
{if has_place "charger8" {if crew_in_place "charger8" {with_linked_entity "charger8" {call "ufb_gun_bind_man_12_b"}}}}
{if has_place "loader" {if crew_in_place "loader" {with_linked_entity "loader" {call "ufb_gun_bind_man_12_b"}}}}
{if has_place "loader1" {if crew_in_place "loader1" {with_linked_entity "loader1" {call "ufb_gun_bind_man_12_b"}}}}
{if has_place "loader2" {if crew_in_place "loader2" {with_linked_entity "loader2" {call "ufb_gun_bind_man_12_b"}}}}
{if has_place "loader3" {if crew_in_place "loader3" {with_linked_entity "loader3" {call "ufb_gun_bind_man_12_b"}}}}
{if has_place "loader4" {if crew_in_place "loader4" {with_linked_entity "loader4" {call "ufb_gun_bind_man_12_b"}}}}
{if has_place "loader5" {if crew_in_place "loader5" {with_linked_entity "loader5" {call "ufb_gun_bind_man_12_b"}}}}
{if has_place "loader6" {if crew_in_place "loader6" {with_linked_entity "loader6" {call "ufb_gun_bind_man_12_b"}}}}
{if has_place "loader7" {if crew_in_place "loader7" {with_linked_entity "loader7" {call "ufb_gun_bind_man_12_b"}}}}
{if has_place "loader8" {if crew_in_place "loader8" {with_linked_entity "loader8" {call "ufb_gun_bind_man_12_b"}}}}
{if has_place "seat1" {if crew_in_place "seat1" {with_linked_entity "seat1" {call "ufb_gun_bind_man_12_b"}}}}
{if has_place "seat2" {if crew_in_place "seat2" {with_linked_entity "seat2" {call "ufb_gun_bind_man_12_b"}}}}
{if has_place "seat3" {if crew_in_place "seat3" {with_linked_entity "seat3" {call "ufb_gun_bind_man_12_b"}}}}
{if has_place "seat4" {if crew_in_place "seat4" {with_linked_entity "seat4" {call "ufb_gun_bind_man_12_b"}}}}
{if has_place "seat5" {if crew_in_place "seat5" {with_linked_entity "seat5" {call "ufb_gun_bind_man_12_b"}}}}
{if has_place "seat6" {if crew_in_place "seat6" {with_linked_entity "seat6" {call "ufb_gun_bind_man_12_b"}}}}
{if has_place "seat7" {if crew_in_place "seat7" {with_linked_entity "seat7" {call "ufb_gun_bind_man_12_b"}}}}
{if has_place "seat8" {if crew_in_place "seat8" {with_linked_entity "seat8" {call "ufb_gun_bind_man_12_b"}}}}
{if has_place "seat9" {if crew_in_place "seat9" {with_linked_entity "seat9" {call "ufb_gun_bind_man_12_b"}}}}
{if has_place "seat10" {if crew_in_place "seat10" {with_linked_entity "seat10" {call "ufb_gun_bind_man_12_b"}}}}
{if has_place "seat11" {if crew_in_place "seat11" {with_linked_entity "seat11" {call "ufb_gun_bind_man_12_b"}}}}
{if has_place "seat12" {if crew_in_place "seat12" {with_linked_entity "seat12" {call "ufb_gun_bind_man_12_b"}}}}
{if has_place "seat13" {if crew_in_place "seat13" {with_linked_entity "seat13" {call "ufb_gun_bind_man_12_b"}}}}
{if has_place "seat14" {if crew_in_place "seat14" {with_linked_entity "seat14" {call "ufb_gun_bind_man_12_b"}}}}
{if has_place "seat15" {if crew_in_place "seat15" {with_linked_entity "seat15" {call "ufb_gun_bind_man_12_b"}}}}
 }
 {on "ufb_gun_release_owner_12_b" {kill_delay "ufb_gun_owner_expiry"} {tags remove "_ufb_gun_owner_12_b"} {tags remove "_ufb_gun_escaped_12_b"} {tags remove "_ufb_gun_bound"}}
{on "ufb_gun_bind_13_b" sync
  {call "ufb_gun_left_cooldown_b"} {tags add "_ufb_gun_bound"}
  {kill_delay "ufb_gun_owner_expiry"}
  {delay 120 "ufb_gun_owner_expiry" {call "ufb_gun_release_owner_13_b"}}
  {spawn "ufb_smoke_screen_point" local_offset -700 0 0 constrain_after_dir {tags add "_ufb_gun_lease_13_b"} {delay 140 {delete}}}
  {if has_place "commander" {if crew_in_place "commander" {with_linked_entity "commander" {call "ufb_gun_bind_man_13_b"}}}}
{if has_place "driver" {if crew_in_place "driver" {with_linked_entity "driver" {call "ufb_gun_bind_man_13_b"}}}}
{if has_place "gunner" {if crew_in_place "gunner" {with_linked_entity "gunner" {call "ufb_gun_bind_man_13_b"}}}}
{if has_place "gunner1" {if crew_in_place "gunner1" {with_linked_entity "gunner1" {call "ufb_gun_bind_man_13_b"}}}}
{if has_place "gunner2" {if crew_in_place "gunner2" {with_linked_entity "gunner2" {call "ufb_gun_bind_man_13_b"}}}}
{if has_place "gunner3" {if crew_in_place "gunner3" {with_linked_entity "gunner3" {call "ufb_gun_bind_man_13_b"}}}}
{if has_place "gunner4" {if crew_in_place "gunner4" {with_linked_entity "gunner4" {call "ufb_gun_bind_man_13_b"}}}}
{if has_place "gunner5" {if crew_in_place "gunner5" {with_linked_entity "gunner5" {call "ufb_gun_bind_man_13_b"}}}}
{if has_place "gunner6" {if crew_in_place "gunner6" {with_linked_entity "gunner6" {call "ufb_gun_bind_man_13_b"}}}}
{if has_place "gunner7" {if crew_in_place "gunner7" {with_linked_entity "gunner7" {call "ufb_gun_bind_man_13_b"}}}}
{if has_place "gunner8" {if crew_in_place "gunner8" {with_linked_entity "gunner8" {call "ufb_gun_bind_man_13_b"}}}}
{if has_place "charger" {if crew_in_place "charger" {with_linked_entity "charger" {call "ufb_gun_bind_man_13_b"}}}}
{if has_place "charger1" {if crew_in_place "charger1" {with_linked_entity "charger1" {call "ufb_gun_bind_man_13_b"}}}}
{if has_place "charger2" {if crew_in_place "charger2" {with_linked_entity "charger2" {call "ufb_gun_bind_man_13_b"}}}}
{if has_place "charger3" {if crew_in_place "charger3" {with_linked_entity "charger3" {call "ufb_gun_bind_man_13_b"}}}}
{if has_place "charger4" {if crew_in_place "charger4" {with_linked_entity "charger4" {call "ufb_gun_bind_man_13_b"}}}}
{if has_place "charger5" {if crew_in_place "charger5" {with_linked_entity "charger5" {call "ufb_gun_bind_man_13_b"}}}}
{if has_place "charger6" {if crew_in_place "charger6" {with_linked_entity "charger6" {call "ufb_gun_bind_man_13_b"}}}}
{if has_place "charger7" {if crew_in_place "charger7" {with_linked_entity "charger7" {call "ufb_gun_bind_man_13_b"}}}}
{if has_place "charger8" {if crew_in_place "charger8" {with_linked_entity "charger8" {call "ufb_gun_bind_man_13_b"}}}}
{if has_place "loader" {if crew_in_place "loader" {with_linked_entity "loader" {call "ufb_gun_bind_man_13_b"}}}}
{if has_place "loader1" {if crew_in_place "loader1" {with_linked_entity "loader1" {call "ufb_gun_bind_man_13_b"}}}}
{if has_place "loader2" {if crew_in_place "loader2" {with_linked_entity "loader2" {call "ufb_gun_bind_man_13_b"}}}}
{if has_place "loader3" {if crew_in_place "loader3" {with_linked_entity "loader3" {call "ufb_gun_bind_man_13_b"}}}}
{if has_place "loader4" {if crew_in_place "loader4" {with_linked_entity "loader4" {call "ufb_gun_bind_man_13_b"}}}}
{if has_place "loader5" {if crew_in_place "loader5" {with_linked_entity "loader5" {call "ufb_gun_bind_man_13_b"}}}}
{if has_place "loader6" {if crew_in_place "loader6" {with_linked_entity "loader6" {call "ufb_gun_bind_man_13_b"}}}}
{if has_place "loader7" {if crew_in_place "loader7" {with_linked_entity "loader7" {call "ufb_gun_bind_man_13_b"}}}}
{if has_place "loader8" {if crew_in_place "loader8" {with_linked_entity "loader8" {call "ufb_gun_bind_man_13_b"}}}}
{if has_place "seat1" {if crew_in_place "seat1" {with_linked_entity "seat1" {call "ufb_gun_bind_man_13_b"}}}}
{if has_place "seat2" {if crew_in_place "seat2" {with_linked_entity "seat2" {call "ufb_gun_bind_man_13_b"}}}}
{if has_place "seat3" {if crew_in_place "seat3" {with_linked_entity "seat3" {call "ufb_gun_bind_man_13_b"}}}}
{if has_place "seat4" {if crew_in_place "seat4" {with_linked_entity "seat4" {call "ufb_gun_bind_man_13_b"}}}}
{if has_place "seat5" {if crew_in_place "seat5" {with_linked_entity "seat5" {call "ufb_gun_bind_man_13_b"}}}}
{if has_place "seat6" {if crew_in_place "seat6" {with_linked_entity "seat6" {call "ufb_gun_bind_man_13_b"}}}}
{if has_place "seat7" {if crew_in_place "seat7" {with_linked_entity "seat7" {call "ufb_gun_bind_man_13_b"}}}}
{if has_place "seat8" {if crew_in_place "seat8" {with_linked_entity "seat8" {call "ufb_gun_bind_man_13_b"}}}}
{if has_place "seat9" {if crew_in_place "seat9" {with_linked_entity "seat9" {call "ufb_gun_bind_man_13_b"}}}}
{if has_place "seat10" {if crew_in_place "seat10" {with_linked_entity "seat10" {call "ufb_gun_bind_man_13_b"}}}}
{if has_place "seat11" {if crew_in_place "seat11" {with_linked_entity "seat11" {call "ufb_gun_bind_man_13_b"}}}}
{if has_place "seat12" {if crew_in_place "seat12" {with_linked_entity "seat12" {call "ufb_gun_bind_man_13_b"}}}}
{if has_place "seat13" {if crew_in_place "seat13" {with_linked_entity "seat13" {call "ufb_gun_bind_man_13_b"}}}}
{if has_place "seat14" {if crew_in_place "seat14" {with_linked_entity "seat14" {call "ufb_gun_bind_man_13_b"}}}}
{if has_place "seat15" {if crew_in_place "seat15" {with_linked_entity "seat15" {call "ufb_gun_bind_man_13_b"}}}}
 }
 {on "ufb_gun_release_owner_13_b" {kill_delay "ufb_gun_owner_expiry"} {tags remove "_ufb_gun_owner_13_b"} {tags remove "_ufb_gun_escaped_13_b"} {tags remove "_ufb_gun_bound"}}
{on "ufb_gun_bind_14_b" sync
  {call "ufb_gun_left_cooldown_b"} {tags add "_ufb_gun_bound"}
  {kill_delay "ufb_gun_owner_expiry"}
  {delay 120 "ufb_gun_owner_expiry" {call "ufb_gun_release_owner_14_b"}}
  {spawn "ufb_smoke_screen_point" local_offset -700 0 0 constrain_after_dir {tags add "_ufb_gun_lease_14_b"} {delay 140 {delete}}}
  {if has_place "commander" {if crew_in_place "commander" {with_linked_entity "commander" {call "ufb_gun_bind_man_14_b"}}}}
{if has_place "driver" {if crew_in_place "driver" {with_linked_entity "driver" {call "ufb_gun_bind_man_14_b"}}}}
{if has_place "gunner" {if crew_in_place "gunner" {with_linked_entity "gunner" {call "ufb_gun_bind_man_14_b"}}}}
{if has_place "gunner1" {if crew_in_place "gunner1" {with_linked_entity "gunner1" {call "ufb_gun_bind_man_14_b"}}}}
{if has_place "gunner2" {if crew_in_place "gunner2" {with_linked_entity "gunner2" {call "ufb_gun_bind_man_14_b"}}}}
{if has_place "gunner3" {if crew_in_place "gunner3" {with_linked_entity "gunner3" {call "ufb_gun_bind_man_14_b"}}}}
{if has_place "gunner4" {if crew_in_place "gunner4" {with_linked_entity "gunner4" {call "ufb_gun_bind_man_14_b"}}}}
{if has_place "gunner5" {if crew_in_place "gunner5" {with_linked_entity "gunner5" {call "ufb_gun_bind_man_14_b"}}}}
{if has_place "gunner6" {if crew_in_place "gunner6" {with_linked_entity "gunner6" {call "ufb_gun_bind_man_14_b"}}}}
{if has_place "gunner7" {if crew_in_place "gunner7" {with_linked_entity "gunner7" {call "ufb_gun_bind_man_14_b"}}}}
{if has_place "gunner8" {if crew_in_place "gunner8" {with_linked_entity "gunner8" {call "ufb_gun_bind_man_14_b"}}}}
{if has_place "charger" {if crew_in_place "charger" {with_linked_entity "charger" {call "ufb_gun_bind_man_14_b"}}}}
{if has_place "charger1" {if crew_in_place "charger1" {with_linked_entity "charger1" {call "ufb_gun_bind_man_14_b"}}}}
{if has_place "charger2" {if crew_in_place "charger2" {with_linked_entity "charger2" {call "ufb_gun_bind_man_14_b"}}}}
{if has_place "charger3" {if crew_in_place "charger3" {with_linked_entity "charger3" {call "ufb_gun_bind_man_14_b"}}}}
{if has_place "charger4" {if crew_in_place "charger4" {with_linked_entity "charger4" {call "ufb_gun_bind_man_14_b"}}}}
{if has_place "charger5" {if crew_in_place "charger5" {with_linked_entity "charger5" {call "ufb_gun_bind_man_14_b"}}}}
{if has_place "charger6" {if crew_in_place "charger6" {with_linked_entity "charger6" {call "ufb_gun_bind_man_14_b"}}}}
{if has_place "charger7" {if crew_in_place "charger7" {with_linked_entity "charger7" {call "ufb_gun_bind_man_14_b"}}}}
{if has_place "charger8" {if crew_in_place "charger8" {with_linked_entity "charger8" {call "ufb_gun_bind_man_14_b"}}}}
{if has_place "loader" {if crew_in_place "loader" {with_linked_entity "loader" {call "ufb_gun_bind_man_14_b"}}}}
{if has_place "loader1" {if crew_in_place "loader1" {with_linked_entity "loader1" {call "ufb_gun_bind_man_14_b"}}}}
{if has_place "loader2" {if crew_in_place "loader2" {with_linked_entity "loader2" {call "ufb_gun_bind_man_14_b"}}}}
{if has_place "loader3" {if crew_in_place "loader3" {with_linked_entity "loader3" {call "ufb_gun_bind_man_14_b"}}}}
{if has_place "loader4" {if crew_in_place "loader4" {with_linked_entity "loader4" {call "ufb_gun_bind_man_14_b"}}}}
{if has_place "loader5" {if crew_in_place "loader5" {with_linked_entity "loader5" {call "ufb_gun_bind_man_14_b"}}}}
{if has_place "loader6" {if crew_in_place "loader6" {with_linked_entity "loader6" {call "ufb_gun_bind_man_14_b"}}}}
{if has_place "loader7" {if crew_in_place "loader7" {with_linked_entity "loader7" {call "ufb_gun_bind_man_14_b"}}}}
{if has_place "loader8" {if crew_in_place "loader8" {with_linked_entity "loader8" {call "ufb_gun_bind_man_14_b"}}}}
{if has_place "seat1" {if crew_in_place "seat1" {with_linked_entity "seat1" {call "ufb_gun_bind_man_14_b"}}}}
{if has_place "seat2" {if crew_in_place "seat2" {with_linked_entity "seat2" {call "ufb_gun_bind_man_14_b"}}}}
{if has_place "seat3" {if crew_in_place "seat3" {with_linked_entity "seat3" {call "ufb_gun_bind_man_14_b"}}}}
{if has_place "seat4" {if crew_in_place "seat4" {with_linked_entity "seat4" {call "ufb_gun_bind_man_14_b"}}}}
{if has_place "seat5" {if crew_in_place "seat5" {with_linked_entity "seat5" {call "ufb_gun_bind_man_14_b"}}}}
{if has_place "seat6" {if crew_in_place "seat6" {with_linked_entity "seat6" {call "ufb_gun_bind_man_14_b"}}}}
{if has_place "seat7" {if crew_in_place "seat7" {with_linked_entity "seat7" {call "ufb_gun_bind_man_14_b"}}}}
{if has_place "seat8" {if crew_in_place "seat8" {with_linked_entity "seat8" {call "ufb_gun_bind_man_14_b"}}}}
{if has_place "seat9" {if crew_in_place "seat9" {with_linked_entity "seat9" {call "ufb_gun_bind_man_14_b"}}}}
{if has_place "seat10" {if crew_in_place "seat10" {with_linked_entity "seat10" {call "ufb_gun_bind_man_14_b"}}}}
{if has_place "seat11" {if crew_in_place "seat11" {with_linked_entity "seat11" {call "ufb_gun_bind_man_14_b"}}}}
{if has_place "seat12" {if crew_in_place "seat12" {with_linked_entity "seat12" {call "ufb_gun_bind_man_14_b"}}}}
{if has_place "seat13" {if crew_in_place "seat13" {with_linked_entity "seat13" {call "ufb_gun_bind_man_14_b"}}}}
{if has_place "seat14" {if crew_in_place "seat14" {with_linked_entity "seat14" {call "ufb_gun_bind_man_14_b"}}}}
{if has_place "seat15" {if crew_in_place "seat15" {with_linked_entity "seat15" {call "ufb_gun_bind_man_14_b"}}}}
 }
 {on "ufb_gun_release_owner_14_b" {kill_delay "ufb_gun_owner_expiry"} {tags remove "_ufb_gun_owner_14_b"} {tags remove "_ufb_gun_escaped_14_b"} {tags remove "_ufb_gun_bound"}}
{on "ufb_gun_bind_15_b" sync
  {call "ufb_gun_left_cooldown_b"} {tags add "_ufb_gun_bound"}
  {kill_delay "ufb_gun_owner_expiry"}
  {delay 120 "ufb_gun_owner_expiry" {call "ufb_gun_release_owner_15_b"}}
  {spawn "ufb_smoke_screen_point" local_offset -700 0 0 constrain_after_dir {tags add "_ufb_gun_lease_15_b"} {delay 140 {delete}}}
  {if has_place "commander" {if crew_in_place "commander" {with_linked_entity "commander" {call "ufb_gun_bind_man_15_b"}}}}
{if has_place "driver" {if crew_in_place "driver" {with_linked_entity "driver" {call "ufb_gun_bind_man_15_b"}}}}
{if has_place "gunner" {if crew_in_place "gunner" {with_linked_entity "gunner" {call "ufb_gun_bind_man_15_b"}}}}
{if has_place "gunner1" {if crew_in_place "gunner1" {with_linked_entity "gunner1" {call "ufb_gun_bind_man_15_b"}}}}
{if has_place "gunner2" {if crew_in_place "gunner2" {with_linked_entity "gunner2" {call "ufb_gun_bind_man_15_b"}}}}
{if has_place "gunner3" {if crew_in_place "gunner3" {with_linked_entity "gunner3" {call "ufb_gun_bind_man_15_b"}}}}
{if has_place "gunner4" {if crew_in_place "gunner4" {with_linked_entity "gunner4" {call "ufb_gun_bind_man_15_b"}}}}
{if has_place "gunner5" {if crew_in_place "gunner5" {with_linked_entity "gunner5" {call "ufb_gun_bind_man_15_b"}}}}
{if has_place "gunner6" {if crew_in_place "gunner6" {with_linked_entity "gunner6" {call "ufb_gun_bind_man_15_b"}}}}
{if has_place "gunner7" {if crew_in_place "gunner7" {with_linked_entity "gunner7" {call "ufb_gun_bind_man_15_b"}}}}
{if has_place "gunner8" {if crew_in_place "gunner8" {with_linked_entity "gunner8" {call "ufb_gun_bind_man_15_b"}}}}
{if has_place "charger" {if crew_in_place "charger" {with_linked_entity "charger" {call "ufb_gun_bind_man_15_b"}}}}
{if has_place "charger1" {if crew_in_place "charger1" {with_linked_entity "charger1" {call "ufb_gun_bind_man_15_b"}}}}
{if has_place "charger2" {if crew_in_place "charger2" {with_linked_entity "charger2" {call "ufb_gun_bind_man_15_b"}}}}
{if has_place "charger3" {if crew_in_place "charger3" {with_linked_entity "charger3" {call "ufb_gun_bind_man_15_b"}}}}
{if has_place "charger4" {if crew_in_place "charger4" {with_linked_entity "charger4" {call "ufb_gun_bind_man_15_b"}}}}
{if has_place "charger5" {if crew_in_place "charger5" {with_linked_entity "charger5" {call "ufb_gun_bind_man_15_b"}}}}
{if has_place "charger6" {if crew_in_place "charger6" {with_linked_entity "charger6" {call "ufb_gun_bind_man_15_b"}}}}
{if has_place "charger7" {if crew_in_place "charger7" {with_linked_entity "charger7" {call "ufb_gun_bind_man_15_b"}}}}
{if has_place "charger8" {if crew_in_place "charger8" {with_linked_entity "charger8" {call "ufb_gun_bind_man_15_b"}}}}
{if has_place "loader" {if crew_in_place "loader" {with_linked_entity "loader" {call "ufb_gun_bind_man_15_b"}}}}
{if has_place "loader1" {if crew_in_place "loader1" {with_linked_entity "loader1" {call "ufb_gun_bind_man_15_b"}}}}
{if has_place "loader2" {if crew_in_place "loader2" {with_linked_entity "loader2" {call "ufb_gun_bind_man_15_b"}}}}
{if has_place "loader3" {if crew_in_place "loader3" {with_linked_entity "loader3" {call "ufb_gun_bind_man_15_b"}}}}
{if has_place "loader4" {if crew_in_place "loader4" {with_linked_entity "loader4" {call "ufb_gun_bind_man_15_b"}}}}
{if has_place "loader5" {if crew_in_place "loader5" {with_linked_entity "loader5" {call "ufb_gun_bind_man_15_b"}}}}
{if has_place "loader6" {if crew_in_place "loader6" {with_linked_entity "loader6" {call "ufb_gun_bind_man_15_b"}}}}
{if has_place "loader7" {if crew_in_place "loader7" {with_linked_entity "loader7" {call "ufb_gun_bind_man_15_b"}}}}
{if has_place "loader8" {if crew_in_place "loader8" {with_linked_entity "loader8" {call "ufb_gun_bind_man_15_b"}}}}
{if has_place "seat1" {if crew_in_place "seat1" {with_linked_entity "seat1" {call "ufb_gun_bind_man_15_b"}}}}
{if has_place "seat2" {if crew_in_place "seat2" {with_linked_entity "seat2" {call "ufb_gun_bind_man_15_b"}}}}
{if has_place "seat3" {if crew_in_place "seat3" {with_linked_entity "seat3" {call "ufb_gun_bind_man_15_b"}}}}
{if has_place "seat4" {if crew_in_place "seat4" {with_linked_entity "seat4" {call "ufb_gun_bind_man_15_b"}}}}
{if has_place "seat5" {if crew_in_place "seat5" {with_linked_entity "seat5" {call "ufb_gun_bind_man_15_b"}}}}
{if has_place "seat6" {if crew_in_place "seat6" {with_linked_entity "seat6" {call "ufb_gun_bind_man_15_b"}}}}
{if has_place "seat7" {if crew_in_place "seat7" {with_linked_entity "seat7" {call "ufb_gun_bind_man_15_b"}}}}
{if has_place "seat8" {if crew_in_place "seat8" {with_linked_entity "seat8" {call "ufb_gun_bind_man_15_b"}}}}
{if has_place "seat9" {if crew_in_place "seat9" {with_linked_entity "seat9" {call "ufb_gun_bind_man_15_b"}}}}
{if has_place "seat10" {if crew_in_place "seat10" {with_linked_entity "seat10" {call "ufb_gun_bind_man_15_b"}}}}
{if has_place "seat11" {if crew_in_place "seat11" {with_linked_entity "seat11" {call "ufb_gun_bind_man_15_b"}}}}
{if has_place "seat12" {if crew_in_place "seat12" {with_linked_entity "seat12" {call "ufb_gun_bind_man_15_b"}}}}
{if has_place "seat13" {if crew_in_place "seat13" {with_linked_entity "seat13" {call "ufb_gun_bind_man_15_b"}}}}
{if has_place "seat14" {if crew_in_place "seat14" {with_linked_entity "seat14" {call "ufb_gun_bind_man_15_b"}}}}
{if has_place "seat15" {if crew_in_place "seat15" {with_linked_entity "seat15" {call "ufb_gun_bind_man_15_b"}}}}
 }
 {on "ufb_gun_release_owner_15_b" {kill_delay "ufb_gun_owner_expiry"} {tags remove "_ufb_gun_owner_15_b"} {tags remove "_ufb_gun_escaped_15_b"} {tags remove "_ufb_gun_bound"}}
}
