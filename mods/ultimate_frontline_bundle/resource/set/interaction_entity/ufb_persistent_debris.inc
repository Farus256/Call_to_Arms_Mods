; Only explicitly marked metal and sandbag fragments; casings keep stock cleanup.
{"ufb_persistent_debris" {on "check_delete_part" overload}}
{"small part ufb_persistent_debris"
 {on spawn overload
  {delay 0.01 {volumes disable bullet contact blast touch}}
  {delay 2 {call "activate_volumes"}}
 }
}
{"medium part ufb_persistent_debris"
 {on spawn overload
  {delay 0.05 {volumes disable bullet contact blast touch}}
  {delay 1 {volumes enable bullet contact blast}}
 }
}
