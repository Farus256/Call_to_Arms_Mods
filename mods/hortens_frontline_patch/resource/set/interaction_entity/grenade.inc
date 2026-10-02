
;/*=========== Explosive Grenade Begin ===========*/

{"grenade"
	{on spawn
		{call "add_grenade_sound"}
	}
	{on "onThrow"
		{call "grenade_fx"}
		{volumes "body" disable contact}
	}
	{on "onThrowActivate"
		{volumes "body" enable contact}
	}
	{on contact
		{if stuff_activated
			{if effector "human"
				{call "fall_down"}
		 	else effector "cannon"
				;{link_grenade_to_nearest_human teleport}
			}
		}
	}
	{on "activate"
		{call "hide_marker"}
	}
	{on "in_hole"
		{break_window_in_hole}
		{link_grenade_to_nearest_human}
	}
	{on ground_hit
		{if not terrain_fx "water"
			{link_sound "grenadehit" "hit/ground/grenade/"}
			{play_sound "grenadehit"}
		}
	}
	{on "fall_down"
		{volumes disable contact}
		{fall_down}
	}

	{on "show_marker1"
		{view start "marker1"}
		{view start "marker3"}
	}

	{on "show_marker2"
		{view pause "marker1"}
		{view start "marker2"}
		{view pause "marker3"}
		{view start "marker4"}
	}

	{on "hide_marker"
		{view stop "marker1"}
		{view stop "marker2"}
		{view stop "marker3"}
		{view stop "marker4"}
	}

	{on bullet_hit
		{stuff_detonate}
	}
	{on blast_hit
		{if min_energy 0.8
			{stuff_detonate}
		}
	}
}

{"grenade fg"
	{on "onThrow"
		{delay 1.5
			{call "show_marker1"}
		}
		{delay 3.5
			{call "show_marker2"}
		}
	}
}

{"grenade dynamite"
	{on "undermine"
		{delay 7
			{call "show_marker1"}
		}
		{delay 9
			{call "show_marker2"}
		}
	}
	{on "onThrow"
		{call "undermine"}
	}
}

{"grenade contact"
	{on ground_hit
		{if stuff_activated
			{if not name "water"
				{call "ground_detonate"}
			}
		}
	}
	{on "in_hole" overload}
	{on contact
		{if stuff_activated
			{if not tagged "mine_planted"
				{if not tagged "grounded"
					{call "contact_detonate"}
				}
			}
		}
	}
	{on "ground_detonate"
		{call "detonate"}
	}
	{on "contact_detonate"
		{call "detonate"}
	}
	{on "detonate"
		{volumes disable all}
		{stuff_detonate}
	}
	{on "fall_down" overload}
}

{"grenade contact mine"
	{on "onThrow" overload
		{volumes "body" disable contact}
		{volumes "body1" disable contact}
	}
	{on "onThrowActivate" overload
		{volumes "body1" enable contact}
	}

	{on "ground_detonate" overload
		{volumes "body" enable contact}
		{tags add "grounded"}
	}
}

{"grenade fire"
	{on spawn
		{add_view "molotov_lit" "lit" "wick"}
		{view hide "lit"}
		{play_sound "equip"}
	}
	{on "grenade_fx"
		{view show "lit"}
		{view start "lit"}
		{play_sound "loop" 1}
	}
	{on "ground_detonate"
		{fire radius 2.5 time 7 heating 1.5}
		{fire radius 1.5 time 20 heating 0.5}
	}
	{on "contact_detonate" overload
		{volumes disable bullet contact blast}
		{fire radius 1.25 time 2 heating 15 effector follow}
		{fire radius 1 time 20 heating 0.5 effector follow}
		{delay 0
			{call "detonate"}
		}
	}
	{on "onThrow"
		{play_sound "throw"}
	}
}

{"grenade fire big"
	{on "ground_detonate" overload
		{call "detonate"}
		{fire radius 2.5 time 7 heating 2.5}
		{fire radius 2.5 time 20 heating 0.5}
	}
	{on "contact_detonate" overload
		{volumes disable bullet contact blast}
		{fire radius 2.00 time 2 heating 25 effector follow}
		{fire radius 1 time 20 heating 0.5 effector follow}
		{delay 0.01
			{call "detonate"}
		}
	}
}

{"grenade magnetic"
	{on contact 
		{if material "steel"
			{physics_work 0}
			{volumes disable contact}
			{call "position_checker"}
		}
	}
	{on "position_checker"
		{volumes "body" enable contact}
		{delay 0 {physics_work 1}}
		{impulse up -0.01 com}
		{delay 0.25 "position_checker"
			{call "position_checker"}
		}
	}
}

{"grenade timed"
	{on contact
		{if stuff_activated
			{if effector "vehicle"
				{volumes disable bullet contact blast} ;// keeps grenade from detonating multiple times (multiple blastwaves)
				{stuff_detonate}
			}
		}
	}
}

;/*=========== Explosive Grenade End ===========*/

;/*=========== Smoke Grenade Begin ===========*/

{"grenade smoke"
	{on spawn
		{call "add_smoke"}
	}
	{on "add_smoke"
		{add_view "smoke_cover-up_norm"		"smoke2" "root"}
		{add_view "smoke_cover-up_big"		"smoke3" "root"}
	}
	{on "onThrow"
		{volumes disable touch select}
	}
	{on ground_hit
		{if stuff_activated
			{if not name "water"
				{if not tagged "activated"
					{tags add "activated"}
					{delay 3
						{call "activate"}
					}
				}
			else
				{hide 1}
			}
		}
	}
	{on contact
		{if stuff_activated
			{if not tagged "activated"
				{tags add "activated"}
				{delay 3
					{call "activate"}
				}
			}
		}
	}
	{on "activate"
		(define "spawn_volume"
			{spawn "smoke_volume_%0" offset %1 %2 0
				{delay %3 {hide 1}}
			}
		)
		{play_sound "smoke_loop" 1}
		{view start "smoke1"}
		{view start "smoke2"}
		{spawn "smoke_volume_cylinder" {delay 85 {hide 1}}}
		{delay 3
			{view start "smoke3"}
			("spawn_volume" args cylinder 110 0 84)
			("spawn_volume" args cylinder -110 0 84)
			("spawn_volume" args cylinder 0 110 84)
			("spawn_volume" args cylinder 0 -110 84)
			("spawn_volume" args cylinder 110 110 84)
			("spawn_volume" args cylinder -110 -110 84)
			("spawn_volume" args cylinder -110 110 84)
			("spawn_volume" args cylinder 110 -110 84)
			{delay 2
				{view stop "smoke1"}
				{view stop "smoke2"}
			}
		}
		{delay 5
			("spawn_volume" args cylinder_sm 220 0 82)
			("spawn_volume" args cylinder_sm -220 0 82)
			("spawn_volume" args cylinder_sm 0 220 82)
			("spawn_volume" args cylinder_sm 0 -220 82)
		}
		{delay 85
			{view stop "smoke3"}
			{stop_sound "smoke_loop"}
			{play_sound "smoke_end"}
		}
		{delay 90
			{hide 1}
		}
	}
	{on blast_hit overload}			;// keeps smoke grenades from deleting by blast damage after being thrown
	{on bullet_hit overload}		;// keeps smoke grenades from deleting by bullet hit after being thrown
}

{"grenade smoke detonate wp"
	{on "activate" overload
		{if not tagged "activate"
			{tags add "activate"}
			{fire radius 1.25 time 1 heating 10}
			{play_sound "explode"}
			{delay 1
				{play_sound "burn_down"}
				{play_sound "smoke_loop"}
			}
			{spawn "ex_wp_grenade"}
			{spawn "shell_smoke_wp_size2"}
			{delay 60
				{stop_sound "smoke_loop"}
				{play_sound "smoke_end"}
				{delete}
			}
		}
	}
}

{"grenade smoke detonate sm"
	{on "activate" overload
		{if not tagged "activate"
			{tags add "activate"}
			{start_sound "detonation/he_size1/bkg/" use_position}
			{spawn "mortar_smoke"}
			{spawn "shell_smoke"}
			{delay 1
				{delete}
			}
		}
	}
}

{"grenade smoke launcher"			;// Smoke grenades for vehicles
	{on "add_smoke" overload
		{add_view "spark_grenade"				"sparks" "fx_smoke"}
		{add_view "smoke_grenade_launcher_init"	"smoke0" "fx_smoke"}
		{add_view "smoke_grenade_launcher"		"smoke1" "fx_smoke"}
		{add_view "smoke_cover_norm"			"smoke2" "root"}
		{add_view "smoke_cover_big"				"smoke3" "root"}
	}
	{on "onThrow" overload
		{delay 0.2
			{if stuff_activated
				{if not tagged "activated"
					{tags add "activated"}
					{call "activate"}
				}
			}
		}
	}
	{on ground_hit
		{if tagged "activated"
			{if name "water"
				{hide 1}
				{kill_delay "smoke"}
			}
		}
	}
	(define "spawn_volume"
		{spawn "smoke_volume_%0" offset %1 %2 0
			{delay %3 {hide 1}}
		}
	)
	(define "smoke_time"
		{on "activate" overload
			{volumes disable touch select}
			{play_sound "smoke_pop"}
			{play_sound "smoke_loop" 1}
			{view start "smoke1"}
			{view start "sparks"}
			{delay 1.5 "smoke"
				{view stop "sparks"}
				{delay 1 "smoke"
					{view start "smoke2"}
					("spawn_volume" args cylinder 0 110 %0)		;4
					("spawn_volume" args cylinder 0 0 %0)		;5
					("spawn_volume" args cylinder 0 -110 %0)	;6
					("spawn_volume" args cylinder 110 110 %0)	;1
					("spawn_volume" args cylinder 110 0 %0)		;2
					("spawn_volume" args cylinder 110 -110 %0)	;3
					("spawn_volume" args cylinder -110 110 %0)	;7
					("spawn_volume" args cylinder -110 0 %0)	;8
					("spawn_volume" args cylinder -110 -110 %0)	;9
				}
			}
			{delay 6 "smoke"
				{view start "smoke3"}
				("spawn_volume" args cylinder_sm 220 0 %1)
				("spawn_volume" args cylinder_sm -220 0 %1)
				("spawn_volume" args cylinder_sm 0 220 %1)
				("spawn_volume" args cylinder_sm 0 -220 %1)
			}
			{delay %0 "smoke"
				{call "delete_grenade"}
			}
		}
	)
	("smoke_time" args 84 82)
	{on "delete_grenade"
		{delay 0 "smoke"
			{view stop "smoke3"}
		}
		{delay 5 "smoke"
			{view stop "smoke2"}
		}
		{delay 5 "smoke"
			{view stop "smoke1"}
			{view start "smoke0"}
			{stop_sound "smoke_loop"}
			{play_sound "smoke_end"}
		}
		{delay 10 "smoke"
			{view stop "smoke0"}
		}
		{delay 15 "smoke"
			{hide 1}
		}
	}
}

{"grenade smoke yellow"
	{on "add_smoke" overload
		{add_view "smoke_yellow_small"	"smoke1" "root"}
		{add_view "smoke_yellow_norm"	"smoke2" "root"}
		;{add_view "smoke_yellow_big"	"smoke3" "root"}
	}
}

{"grenade smoke black"
	{on "add_smoke" overload
		{add_view "spark_grenade"						"sparks" "fx_smoke"}
		{add_view "smoke_black_grenade_launcher_init"	"smoke0" "fx_smoke"}
		{add_view "smoke_black_grenade_launcher"		"smoke1" "fx_smoke"}
		{add_view "smoke_black_cover_norm"				"smoke2" "root"}
		{add_view "smoke_black_cover_big"				"smoke3" "root"}
	}
}

{"grenade smoke paradrop_ammo"
	{on "activate" overload
		{volumes disable touch select}
		{play_sound "smoke_pop"}
		{play_sound "smoke_loop" 1}
		{view start "smoke1"}
		{delay 1.5 "smoke"
			{view start "smoke2"}
		}
		{delay 6 "smoke"
			;{view start "smoke3"}
		}
		{delay 9
			{start_sound "vehicle/airborne/cargo_plane_flyby.wav"}
		}
		{delay 17 "smoke"
			{call "spawn_ammo_crate"}
		}
		{delay 20 "smoke"
			;{view stop "smoke3"}
			{stop_sound "smoke_loop"}
			{play_sound "smoke_end"}
			{hide 1}
		}
	}
}

{"grenade smoke paradrop_ammo rus"
	{on "spawn_ammo_crate"
		{spawn "paradrop_ammo_rus" random_position 100 offset 0 0 1000}
	}
}
{"grenade smoke paradrop_ammo ger"
	{on "spawn_ammo_crate"
		{spawn "paradrop_ammo_ger" random_position 100 offset 0 0 1000}
	}
}
{"grenade smoke paradrop_ammo fin"
	{on "spawn_ammo_crate"
		{spawn "paradrop_ammo_fin" random_position 100 offset 0 0 1000}
	}
}

;/*=========== Smoke Grenade End ===========*/

;/*=========== Throw Sounds Begin ===========*/



{"m24"
}

{"m24_smoke"
	{on "add_grenade_sound"
		{link_sound "smoke_pop"	"detonation/grenade_smoke/generic/pop"}
		{link_sound "smoke_loop"	"detonation/grenade_smoke/generic/detonation_misc_s1_smoke_generic_loop"}
		{link_sound "smoke_end"	"detonation/grenade_smoke/generic/detonation_misc_s1_smoke_generic_end_01"}
	}
}
{"m24_smoke_supplies"
	{on "add_grenade_sound"
		{link_sound "smoke_pop"	"detonation/grenade_smoke/generic/pop"}
		{link_sound "smoke_loop"	"detonation/grenade_smoke/generic/detonation_misc_s1_smoke_generic_loop"}
		{link_sound "smoke_end"	"detonation/grenade_smoke/generic/detonation_misc_s1_smoke_generic_end_01"}
	}
}

{"m24_geballteladung"
}

{"molotov_cocktail"
	{on "add_grenade_sound" overload
		{link_sound "equip" "weapon/equip/grenade/molotov_equip"}
		{link_sound "throw" "weapon/shot/grenade/molotov_throw"}
		{link_sound "loop" "weapon/equip/grenade/molotov_loop"}
	}
}

{"molotov_cocktail_fin"
	{on "add_grenade_sound" overload
		{link_sound "equip" "weapon/equip/grenade/molotov_equip"}
		{link_sound "throw" "weapon/shot/grenade/molotov_throw"}
		{link_sound "loop" "weapon/equip/grenade/molotov_loop"}
	}
}

{"molotov_bundle_fin"
	{on "add_grenade_sound" overload
		{link_sound "equip" "weapon/equip/grenade/molotov_equip"}
		{link_sound "throw" "weapon/shot/grenade/molotov_throw"}
		{link_sound "loop" "weapon/equip/grenade/molotov_loop"}
	}
}

{"rdg1_smoke"
	{on "add_grenade_sound"
		{link_sound "smoke_loop"	"detonation/grenade_smoke/generic/detonation_misc_s1_smoke_generic_loop"}
		{link_sound "smoke_end"	"detonation/grenade_smoke/generic/detonation_misc_s1_smoke_generic_end_01"}
	}
	("smoke_time" args 114 112)
}

{"rdg1_smoke_supplies"
	{on "add_grenade_sound"
		{link_sound "smoke_loop"	"detonation/grenade_smoke/generic/detonation_misc_s1_smoke_generic_loop"}
		{link_sound "smoke_end"	"detonation/grenade_smoke/generic/detonation_misc_s1_smoke_generic_end_01"}
	}
}

{"51mm_eng_mortar_sm"
	{on "add_grenade_sound"
		{link_sound "smoke_pop"	"detonation/grenade_smoke/generic/pop"}
		{link_sound "smoke_loop"	"detonation/grenade_smoke/generic/detonation_misc_s1_smoke_generic_loop"}
		{link_sound "smoke_end"	"detonation/grenade_smoke/generic/detonation_misc_s1_smoke_generic_end_01"}
	}
}

{"nbk39"
	{on "add_grenade_sound"
		{link_sound "smoke_pop"	"detonation/grenade_smoke/generic/pop"}
		{link_sound "smoke_loop"	"detonation/grenade_smoke/generic/detonation_misc_s1_smoke_generic_loop"}
		{link_sound "smoke_end"	"detonation/grenade_smoke/generic/detonation_misc_s1_smoke_generic_end_01"}
	}
	("smoke_time" args 144 142)
}

{"no8_smoke"
	{on "add_grenade_sound"
		{link_sound "smoke_pop"	"detonation/grenade_smoke/generic/pop"}
		{link_sound "smoke_loop"	"detonation/grenade_smoke/generic/detonation_misc_s1_smoke_generic_loop"}
		{link_sound "smoke_end"	"detonation/grenade_smoke/generic/detonation_misc_s1_smoke_generic_end_01"}
	}
}

{"nbks"
	{on "add_grenade_sound"
		{link_sound "smoke_pop"	"detonation/grenade_smoke/generic/pop"}
		{link_sound "smoke_loop"	"detonation/grenade_smoke/generic/detonation_misc_s1_smoke_generic_loop"}
		{link_sound "smoke_end"	"detonation/grenade_smoke/generic/detonation_misc_s1_smoke_generic_end_01"}
	}
	("smoke_time" args 60 58)
}

{"svkkr_pm"
	{on "add_grenade_sound"
		{link_sound "smoke_pop"	"detonation/grenade_smoke/generic/pop"}
		{link_sound "smoke_loop"	"detonation/grenade_smoke/generic/detonation_misc_s1_smoke_generic_loop"}
		{link_sound "smoke_end"	"detonation/grenade_smoke/generic/detonation_misc_s1_smoke_generic_end_01"}
	}
	("smoke_time" args 60 58)
}

{"m42_wp"
	{on "add_grenade_sound"
		{link_sound "explode" 	"detonation/grenade_wp/explode/"}
		{link_sound "burn_down" "detonation/grenade_wp/burn_down/"}
		{link_sound "smoke_pop"	"detonation/grenade_smoke/generic/pop"}
		{link_sound "smoke_loop" "detonation/grenade_smoke/generic/detonation_misc_s1_smoke_generic_loop"}
		{link_sound "smoke_end"	"detonation/grenade_smoke/generic/detonation_misc_s1_smoke_generic_end_01"}
	}
}

{"m43_smoke"
	{on "add_grenade_sound"
		{link_sound "smoke_pop"	"detonation/grenade_smoke/generic/pop"}
		{link_sound "smoke_loop"	"detonation/grenade_smoke/generic/detonation_misc_s1_smoke_generic_loop"}
		{link_sound "smoke_end"	"detonation/grenade_smoke/generic/detonation_misc_s1_smoke_generic_end_01"}
	}
}

{"pwm_l"
	{on bullet_hit overload} ;disables detonation except when thrown. Prevents cumulative crash
	{on blast_hit overload}	;disables detonation except when thrown. Prevents cumulative crash
}

{"rpg40"
	{on bullet_hit overload} ;disables detonation except when thrown. Prevents cumulative crash
	{on blast_hit overload}	;disables detonation except when thrown. Prevents cumulative crash
}

{"rpg43"
	{on bullet_hit overload} ;disables detonation except when thrown. Prevents cumulative crash
	{on blast_hit overload} ;disables detonation except when thrown. Prevents cumulative crash
}

{"anm8_smoke"
	{on "add_grenade_sound"
		{link_sound "smoke_pop"	"detonation/grenade_smoke/generic/pop"}
		{link_sound "smoke_loop"	"detonation/grenade_smoke/generic/detonation_misc_s1_smoke_generic_loop"}
		{link_sound "smoke_end"	"detonation/grenade_smoke/generic/detonation_misc_s1_smoke_generic_end_01"}
	}
}

{"m15_wp"
	{on "add_grenade_sound"
		{link_sound "explode" 	"detonation/grenade_wp/explode/"}
		{link_sound "burn_down" "detonation/grenade_wp/burn_down/"}
		{link_sound "smoke_pop"	"detonation/grenade_smoke/generic/pop"}
		{link_sound "smoke_loop" "detonation/grenade_smoke/generic/detonation_misc_s1_smoke_generic_loop"}
		{link_sound "smoke_end"	"detonation/grenade_smoke/generic/detonation_misc_s1_smoke_generic_end_01"}
	}
}

{"no74"
	{on "grenade_fx"
		{tear "piece_tiny_steel" bone "casing1" {impulse forward 1.01 0.25 dir 1 1 rnd_dir 1}}
		{tear "piece_tiny_steel" bone "casing2" {impulse forward -1.01 0.25  dir -1 1 rnd_dir -1}}
	}
}

{"no82"
}

{"no77_wp"
	{on "add_grenade_sound"
		{link_sound "explode" 	"detonation/grenade_wp/explode/"}
		{link_sound "burn_down" "detonation/grenade_wp/burn_down/"}
		{link_sound "smoke_pop"	"detonation/grenade_smoke/generic/pop"}
		{link_sound "smoke_loop" "detonation/grenade_smoke/generic/detonation_misc_s1_smoke_generic_loop"}
		{link_sound "smoke_end"	"detonation/grenade_smoke/generic/detonation_misc_s1_smoke_generic_end_01"}
	}
	
	{on "detonate" overload
		{call "activate"}
	}
}

;=========== Throw Sounds End ===========*/