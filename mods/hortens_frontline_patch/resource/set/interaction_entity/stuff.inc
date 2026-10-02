;/*=========== Generic Weapon Settings Begin ===========*/

(define "shell_fx"
	{"stuff weapon %tag"
		{on spawn
			{add_view "%shell" "shell" "FXshell"}
		}
	}
)

("shell_fx" tag(pistol_shell)		shell(shell_pistol))
("shell_fx" tag(pistol2_shell)		shell(shell_pistol2))
("shell_fx" tag(inter_shell)		shell(shell_inter))
("shell_fx" tag(rifle_shell)		shell(shell_rifles))
("shell_fx" tag(hmg_shell)			shell(shell_hmgun))
("shell_fx" tag(ptr_shell)			shell(shell_ptr))
("shell_fx" tag(mgun_shell)			shell(shell_mgun))
("shell_fx" tag(shotgun_shell)		shell(shell_shotgun))

(define "link_fx"
	{"stuff weapon"
		{on spawn
			{add_view "%link" "link" "FXlinks"}
		}
	}
)

("link_fx" 							link(shell_link))

(define "flash_fx"
	{"stuff weapon %tag"
		{on spawn
			{if not prop "silenced"
				{add_view "%flash" "flashbarrel" "foresight%foresight"}
			else
				{add_view "flash_gun_silencer" "flashbarrel" "foresight%foresight"}
			}
		}
	}
)

("flash_fx" tag(pistol)			flash(flash_gun_small)	foresight(3))
("flash_fx" tag(smg)			flash(flash_gun_small)	foresight(11))
("flash_fx" tag(rifle)			flash(flash_gun_rifle)	foresight(12))
("flash_fx" tag(mgun)			flash(flash_gun_big)	foresight(14))
("flash_fx" tag(at_rifle)		flash(flash_gun_atrifle)foresight(18))
("flash_fx" tag(shotgun)		flash(flash_gun_hmg_m2hb)	foresight(3))

(define "ejectsmoke_fx"
	{"stuff weapon %tag"
		{on spawn
			{add_view "%ejectsmoke" "ejectsmoke" "fxshell"}
		}
	}
)

("ejectsmoke_fx" tag(smg)		ejectsmoke(ejectsmoke_small))
("ejectsmoke_fx" tag(rifle)		ejectsmoke(ejectsmoke_small))
("ejectsmoke_fx" tag(mgun)		ejectsmoke(ejectsmoke_big))

(define "holster_fx"
	{"stuff weapon %tag"
		{on spawn
			{link_sound "holster"	"human/holster/%sound"}
		}
	}
)

("holster_fx" tag(pistol)			sound(pistol))
("holster_fx" tag(smg)				sound(weapon))
("holster_fx" tag(rifle)			sound(weapon))
("holster_fx" tag(mgun)				sound(weapon))
("holster_fx" tag(shotgun)			sound(weapon))
("holster_fx" tag(ptr)				sound(big))
("holster_fx" tag(bazooka)			sound(big))
("holster_fx" tag(flame_thrower)	sound(flame))
("holster_fx" tag(melee)			sound(knife))

(define "sound_fx"
	{"stuff weapon %tag"
		{on spawn
			{if not prop "silenced"
			}
		}
	}
)

("sound_fx" tag(pistol)		sound(smg))
("sound_fx" tag(smg)		sound(smg))
("sound_fx" tag(rifle)		sound(rifle))
("sound_fx" tag(mgun)		sound(mg))
("sound_fx" tag(at_rifle)	sound(hmg))
("sound_fx" tag(shotgun)	sound(rifle))

{"stuff weapon"
	{on "drop_item"}			;// when item is not in hand and is dropped from inventory.
	
	{on "fire"
		{play_sound "mid"}
		{play_sound "far"}
		{play_sound "action_recoil"}
		{ani_play "recoil"}
		{ani_play "recoil2"}
		{view show "flashbarrel"}
		{view start "flashbarrel"}
		{delay 0.2 "fire"
			{view hide	"flashbarrel"}
			{view pause	"flashbarrel"}
		}
	}
	{on "link_human"
		{play_sound "holster"}
		{delay 0.4
			{ani_play "prepare"}
		}
	}
	{on "unlink_human"
		{ani_play "prepare" -1}
	}
	{on "link_human_sword"
		{play_sound "holster"}
	}
	{on "unlink_human_sword"
		{ani_play "prepare" -1}
	}
	{on "link_eject"
		{view start "link"}
		{delay 0.1 "link"
			{view pause "link"}
		}
	}
	{on "case_eject"
		{view start "shell"}
		{view show	"ejectsmoke"}
		{view start	"ejectsmoke"}
		{delay 0.1 "shell"
			{view pause "shell"}
			{view hide	"ejectsmoke"}
			{view pause	"ejectsmoke"}
		}
	}
	{on "weapon_reload"
		{kill_delay "bolt_action"}
		{ani_play "reload"}
		{call "magazine_delay"}
		{play_sound "eject_clip"}
		{delay 0.075
			{stop_sound "action_recoil"}
		}
	}
	(define "magazine"
		{on "magazine_delay" %override
			{delay %cut
				{view hide "bullet"}
				{view hide "belt"}
				{bone hide "belt_bullet01"}
				{bone hide "belt_bullet02"}
				{bone hide "belt_bullet03"}
				{bone hide "belt_bullet04"}
				{bone hide "belt_bullet05"}
				{bone hide "belt_bullet06"}
				{bone hide "belt_bullet07"}
				{bone hide "belt_bullet08"}
				{bone hide "belt_empty01"}
				{bone hide "belt_empty02"}
				{bone hide "belt_empty03"}
				{bone hide "belt_empty04"}
				{bone hide "belt_empty05"}
				{bone hide "belt_empty06"}
				{bone hide "belt_empty07"}
				{tear "piece_tiny_steel" bone "magazine" copy
					%impulse
				}
				{delay 0
					{view hide "magazine"}
					{delay %show
						{view show "magazine"}
						{view show "bullet"}
						{view show "belt"}
						{bone show "belt_bullet01"}
						{bone show "belt_bullet02"}
						{bone show "belt_bullet03"}
						{bone show "belt_bullet04"}
						{bone show "belt_bullet05"}
						{bone show "belt_bullet06"}
						{bone show "belt_bullet07"}
						{bone show "belt_bullet08"}
						{bone show "belt_empty01"}
						{bone show "belt_empty02"}
						{bone show "belt_empty03"}
						{bone show "belt_empty04"}
						{bone show "belt_empty05"}
						{bone show "belt_empty06"}
						{bone show "belt_empty07"}
					}
				}
			}
		}
	)
	("magazine" cut(0) show(1.8) override() impulse({impulse up -0.01 com}))

	(define "drop"
		{on ground_hit %override
			{if terrain_fx "road"
				{start_sound "weapon/drop/%material/rock"}

			else terrain_fx "rock"
				{start_sound "weapon/drop/%material/rock"}

			else terrain_fx "ice"
				{start_sound "weapon/drop/%material/rock"}
			
			else terrain_fx "snow"
				{start_sound "weapon/drop/%material/snow"}
			
			else terrain_fx "sand"
				{start_sound "weapon/drop/%material/snow"}
			
			else terrain_fx "bridge_wood"
				{start_sound  "weapon/drop/%material/wood"}
			
			else terrain_fx "shallow_water"

			else terrain_fx "water"

			else
				{start_sound "weapon/drop/%material/ground"}
			}
		}
	)
	("drop" material(metal) override())
}

{"stuff weapon wood_stock"
	("drop" material(wood) override(overload))
}

{"stuff weapon auto_eject"
	{on "fire"
		{call "instant_eject"}
	}
	{on "instant_eject"
		{call "case_eject"}
	}
}

{"stuff weapon auto_eject semi_auto"
	{on "instant_eject" overload
		{delay 0.065
			{call "case_eject"}
		}
	}
}

{"stuff weapon bolt_action"
	{on "fire"
		{tags add "fired"}
		{delay 0.35 "bolt_action"
			{ani_play "bolt_action" 1.5}
			{play_sound "open_bolt"}
			{delay 0.2 
				{call "case_eject"}
			}
		}
		{delay 0.4
			{tags remove "fired"}
		}
		{delay 0.7 "bolt_action1"
			{play_sound "close_bolt"}
		}
	}
	{on "weapon_reload" overload
		{kill_delay "bolt_action"}
		{kill_delay "bolt_action1"}
		{ani_play "reload"}
		{delay 0.35 
			{play_sound "open_bolt"}
		}
		{if tagged "fired"
			{delay 0.55
				{call "case_eject"}
			}
		else
		}
		{delay 5.5
			{play_sound "close_bolt"}
		}
	}
}

{"stuff weapon shotgun_double"
	{on "weapon_reload" overload
		{delay 0.5
			{ani_play "reload"}
		}
		(define "double_shot"
			{delay %0
				{tear "piece_tiny_steel" bone "shell%1" copy
					{impulse up -0.01}
				}
				{delay 0
					{view hide "shell%1"}
					{delay 2.0
						{view show "shell%1"}
					}
				}
			}
		)
		("double_shot" args 0.9 1)
		("double_shot" args 1.00 2)
	}
}

{"stuff weapon shotgun_pump"
	{on "fire"
		{tags add "fired"}
		{delay 0.35 "bolt_action"
			{ani_play "bolt_action" 1.0}
			{play_sound "open_bolt"}
			{delay 0.2 
				{call "case_eject"}
			}
		}
		{delay 0.4
			{tags remove "fired"}
		}
		{delay 0.6
			{play_sound "close_bolt"}
		}
	}
	{on "weapon_reload" overload
		{kill_delay "bolt_action"}
		{ani_play "reload"}
		{if tagged "fired"
			{delay 0.55
				{call "case_eject"}
			}
		else
		}
		{delay 5.5
			{play_sound "close_bolt"}
		}
	}
}

{"stuff weapon flare_gun"
	{on "weapon_reload" overload
		{delay 0.5
			{ani_play "reload"}
		}

		{delay 1
			{tear "piece_tiny_steel" bone "flare" copy
				{impulse up -0.01}
			}
			{delay 0
				{view hide "flare"}
				{delay 1.5
					{view show "flare"}
				}
			}
		}
	}
}


(define "flame_fx"
	{"stuff weapon flame_thrower %tag"
		{on spawn
			{add_view "flamer_fire"			"flame"	"foresight3"}
			;//{add_view "flamer_fire_barrel"	"fire"	"foresight3"} ;// does not hide in fow

			{link_sound "start"	"weapon/shot/flame/handheld/flamer_start"}
			{link_sound "loop"	"weapon/shot/flame/handheld/flamer_loop"}
			{link_sound "end"	"weapon/shot/flame/handheld/flamer_stop"}
		}
		{on "start_burst"
			{play_sound "start"}
			{delay 0.1 "loop"
				{play_sound "loop" 1}
			}
		}
		{on "end_burst"
			{kill_delay "loop"}
			{play_sound "end"}
			{stop_sound "loop"}
		}
		{on "link_human"
			;//{view show	"fire"}
			;//{view start	"fire"}
		}
		{on "unlink_human"
			;//{view pause	"fire"}
		}
		{on "fire" overload
			{spawn "%flame" "foresight3" x
				{impulse forward 30 rnd_dir 0.01 com}
				{gravity 0.65}
				{linear_damping 0}
			}
			{view start "flame"}
			{kill_delay "fire"}
			{delay 0.05
				{spawn "%flame" "foresight3" x
					{impulse forward 30 rnd_dir 0.01 com}
					{gravity 0.65}
					{linear_damping 0}
				}
			}
			{delay 0.1 "fire"
				{view pause "flame"}
			}
		}
	}
)

("flame_fx" tag(range_20)		flame(fx_piece_flame_20))
("flame_fx" tag(range_30)		flame(fx_piece_flame_30))
("flame_fx" tag(range_40)		flame(fx_piece_flame_40))


{"stuff weapon flare_gun signal"		;// for mission scripts to detect flare location
	{on spawn
		{tags add "osp30_signal_sp"}
	}
	{on "fire" overload
		{spawn "fx_flare_signal" "foresight3" x
			{impulse forward 15 rnd_dir 0.01 com}
			{gravity 0.3}
			{linear_damping 0}
		}
	}
}

{"stuff weapon rocketlauncher_fx"	;// tag
	{on "fire"
		{spawn "bazooka_shot"	"fxshot" x}
		{with_effector
			{if terrain_fx "water"
			else terrain_fx "shallow_water"
			else terrain_fx "mud"
			else terrain_fx "snow"
				{spawn "bazooka_snow"	"basis" x}
			else terrain_fx "ice"
				{spawn "bazooka_snow"	"basis" x}
			else
				{spawn "bazooka_dust"	"basis" x}
			}
		}
	}
	{on "link_human" overload
		{delay 1.3
			{ani_play "prepare"}
		}
	}
}

{"stuff weapon piat"
	{on spawn
		{link_sound "mid"			"weapon/shot/reactive/d2/ENG/PIAT/"}
	}
	{on "fire"
		{spawn "piat_shot_forward"	"fxshot" x}
		{play_sound "mid"}
	}
	{on "link_human" overload
		{delay 1.3
			{ani_play "prepare"}
		}
	}
}

{"stuff weapon bipod"			;// weapons with bipods
	{on spawn 
		{ani_wind "bipod_open" begin}
	}
	{on "link_human"
		{delay 0.6
			{ani_play "bipod_open"}
		}
	}
	{on "unlink_human"
		{ani_play "bipod_open" -1}
	}
	{on "link"					;// linked to vehicle
		{ani_wind "bipod_open" begin}
	}
	{on "link_open"				;// linked to vehicle opened
		{ani_wind "bipod_open" end}
	}
}

(define "Automatic"
	{tags add "firing"}			; Granular Head – played on EVERY shot
	{play_sound "action_recoil"}
	{play_sound "Head_Mid"}
	{play_sound "Head_Far"}

    	{kill_delay "burst_end"}

	{delay 0.025 "burst_end"
		{tags remove "firing"}		; Tail – plays only when the burst is complete
		{play_sound "Tail_Close"}
		{play_sound "Tail_Mid"}
		{play_sound "Tail_Far"}
	}
)

;/*=========== Generic Weapon Settings End ===========*/


;/*=========== SPECIFIC WEAPONS BEGIN ===========*/
;/**=========== ENG WEAPONS Begin ===========**/
{"stuff weapon bren"				;// props added to bren gun
	{on spawn
		{link_sound 	"action_recoil"		"weapon/shot/smallarms/s3/recoil/eng/bren_gun/"}
		{link_sound		"Tail_Close"		"weapon/shot/smallarms/s3/d1/eng/bren_gun/tail/"}
		{link_sound		"Head_Mid"			"weapon/shot/smallarms/s3/d2/eng/bren_gun/head/"}
		{link_sound		"Tail_Mid"			"weapon/shot/smallarms/s3/d2/eng/bren_gun/tail/"}
		{link_sound		"Head_Far"			"weapon/shot/smallarms/s3/d3/eng/bren_gun/head/"}
		{link_sound		"Tail_Far"			"weapon/shot/smallarms/s3/d3/eng/bren_gun/tail/"}
	}
	{on "fire"
		("Automatic")
	}
	("magazine" cut(1.0) show(3.0) override(overload) impulse({impulse up -0.01}))
}
{"stuff weapon Cup_Discharger"				;// props added to SMLE No.1 MK III and Rifle No.4 Mk I w/ No.1 Mk. I Cup Discharger
	{on spawn
		{link_sound "open_bolt"		"weapon/reload/open_bolt/SMLE_No1_MkIII/"}
		{link_sound "close_bolt"	"weapon/reload/close_bolt/SMLE_No1_MkIII/"}
		{link_sound "action_recoil"	"weapon/action/recoil/bolt_action/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/eng/SMLE_No1_MkIII/Cup_Discharger/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/eng/SMLE_No1_MkIII/Cup_Discharger/"}
	}
}
{"stuff weapon Delisle"					;// props added to  DeLisle Carbine
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/bolt_action/"}
		{link_sound "open_bolt"		"weapon/reload/open_bolt/SMLE_No1_MkIII/"}
		{link_sound "close_bolt"	"weapon/reload/close_bolt/SMLE_No1_MkIII/"}
		{link_sound "mid"		"weapon/shot/smallarms/s1/d2/shared/surpressed_pistol/"}
	}
}
{"stuff weapon Enfield"					;// props added to all Enfield No.2 Mk.I
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/bolt_action/"}
		{link_sound "mid"		"weapon/shot/smallarms/s1/d2/ENG/Enfield_No2_MkI/"}
		{link_sound "far"		"weapon/shot/smallarms/s1/d3/ENG/Enfield_No2_MkI/"}
	}
}
{"stuff weapon Lanchester_MkI"				;// props added to Lanchester Mk. I Machine Carbine and Variants
	{on spawn
		{link_sound 	"action_recoil"		"weapon/action/recoil/open_bolt_smg/"}
		{link_sound		"Tail_Close"		"weapon/shot/smallarms/s1/d1/ENG/Lanchester_MkI/tail/"}
		{link_sound		"Head_Mid"			"weapon/shot/smallarms/s1/d2/ENG/Lanchester_MkI/head/"}
		{link_sound		"Tail_Mid"			"weapon/shot/smallarms/s1/d2/ENG/Lanchester_MkI/tail/"}
		{link_sound		"Head_Far"			"weapon/shot/smallarms/s1/d3/ENG/Lanchester_MkI/head/"}
		{link_sound		"Tail_Far"			"weapon/shot/smallarms/s1/d3/ENG/Lanchester_MkI/tail/"}
	}
	{on "fire"
		("Automatic")
	}
	("magazine" cut(0.75) show(1.6) override(overload) impulse({impulse up -0.01}))
}
{"stuff weapon Lewis_Gun"				;// props added to Lewis Gun Mk.I
	{on spawn
		{link_sound 	"action_recoil"		"weapon/shot/smallarms/s3/recoil/eng/bren_gun/"}
		{link_sound		"Tail_Close"		"weapon/shot/smallarms/s3/d1/eng/Lewis_Gun/tail/"}
		{link_sound		"Head_Mid"			"weapon/shot/smallarms/s3/d2/eng/Lewis_Gun/head/"}
		{link_sound		"Tail_Mid"			"weapon/shot/smallarms/s3/d2/eng/Lewis_Gun/tail/"}
		{link_sound		"Head_Far"			"weapon/shot/smallarms/s3/d3/eng/Lewis_Gun/head/"}
		{link_sound		"Tail_Far"			"weapon/shot/smallarms/s3/d3/eng/Lewis_Gun/tail/"}
	}
	{on "fire"
		("Automatic")
	}
	("magazine" cut(1.0) show(3.0) override(overload) impulse({impulse up -0.01}))
}
{"stuff weapon SMLE"					;// props added to SMLE No.1 MK III and Rifle No.4 Mk I 
	{on spawn
		{link_sound "open_bolt"		"weapon/reload/open_bolt/SMLE_No1_MkIII/"}
		{link_sound "close_bolt"	"weapon/reload/close_bolt/SMLE_No1_MkIII/"}
		{link_sound "action_recoil"	"weapon/action/recoil/bolt_action/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/eng/SMLE_No1_MkIII/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/eng/SMLE_No1_MkIII/"}
	}
}
{"stuff weapon STEN_Gun"				;// props added to STEN Gun and Variants
	{on spawn
		{link_sound 	"action_recoil"		"weapon/action/recoil/open_bolt_smg/"}
		{link_sound		"Tail_Close"		"weapon/shot/smallarms/s1/d1/ENG/STEN_Gun/tail/"}
		{link_sound		"Head_Mid"			"weapon/shot/smallarms/s1/d2/ENG/STEN_Gun/head/"}
		{link_sound		"Tail_Mid"			"weapon/shot/smallarms/s1/d2/ENG/STEN_Gun/tail/"}
		{link_sound		"Head_Far"			"weapon/shot/smallarms/s1/d3/ENG/STEN_Gun/head/"}
		{link_sound		"Tail_Far"			"weapon/shot/smallarms/s1/d3/ENG/STEN_Gun/tail/"}
	}
	{on "fire"
		("Automatic")
	}
	("magazine" cut(0.75) show(1.6) override(overload) impulse({impulse up -0.01}))
}
{"stuff weapon STEN_Gun_Suppressed"			;// props added to Suppressed STEN Gun Variants
	{on spawn
		{link_sound 	"action_recoil"		"weapon/action/recoil/open_bolt_smg/"}
		{link_sound		"Tail_Close"		"weapon/shot/smallarms/s1/d1/ENG/STEN_Gun_Suppressed/tail/"}
		{link_sound		"Head_Mid"			"weapon/shot/smallarms/s1/d2/ENG/STEN_Gun_Suppressed/head/"}
		{link_sound		"Tail_Mid"			"weapon/shot/smallarms/s1/d2/ENG/STEN_Gun_Suppressed/tail/"}
	}
	{on "fire"
		("Automatic")
	}
	("magazine" cut(0.75) show(1.6) override(overload) impulse({impulse up -0.01}))
}
{"stuff weapon PMC_MkI"					;// props added to Patchett Machine Carbine Mk. I
	{on spawn
		{link_sound 	"action_recoil"		"weapon/action/recoil/open_bolt_smg/"}
		{link_sound		"Tail_Close"		"weapon/shot/smallarms/s1/d1/ENG/PMC_MkI/tail/"}
		{link_sound		"Head_Mid"			"weapon/shot/smallarms/s1/d2/ENG/PMC_MkI/head/"}
		{link_sound		"Tail_Mid"			"weapon/shot/smallarms/s1/d2/ENG/PMC_MkI/tail/"}
		{link_sound		"Head_Far"			"weapon/shot/smallarms/s1/d3/ENG/PMC_MkI/head/"}
		{link_sound		"Tail_Far"			"weapon/shot/smallarms/s1/d3/ENG/PMC_MkI/tail/"}
	}
	{on "fire"
		("Automatic")
	}
	("magazine" cut(0.75) show(1.6) override(overload) impulse({impulse up -0.01}))
}
{"stuff weapon Vickers_GO"				;// props added to Vickers GO Mk.I and II
	{on spawn
		{link_sound 	"action_recoil"		"weapon/shot/smallarms/s3/recoil/eng/bren_gun/"}
		{link_sound		"Tail_Close"		"weapon/shot/smallarms/s3/d1/eng/Vickers_GO/tail/"}
		{link_sound		"Head_Mid"			"weapon/shot/smallarms/s3/d2/eng/Vickers_GO/head/"}
		{link_sound		"Tail_Mid"			"weapon/shot/smallarms/s3/d2/eng/Vickers_GO/tail/"}
		{link_sound		"Head_Far"			"weapon/shot/smallarms/s3/d3/eng/Vickers_GO/head/"}
		{link_sound		"Tail_Far"			"weapon/shot/smallarms/s3/d3/eng/Vickers_GO/tail/"}
	}
	{on "fire"
		("Automatic")
	}
	("magazine" cut(1.0) show(3.0) override(overload) impulse({impulse up -0.01}))
}
{"stuff weapon Webley"					;// props added to all Webley Revolver Variants
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/bolt_action/"}
		{link_sound "mid"		"weapon/shot/smallarms/s1/d2/ENG/Webley_MkIV/"}
		{link_sound "far"		"weapon/shot/smallarms/s1/d3/ENG/Webley_MkIV/"}
	}
}
{"stuff weapon Welrod"					;// props added to Welrod
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/bolt_action/"}
		{link_sound "mid"		"weapon/shot/smallarms/s1/d2/shared/surpressed_pistol/"}
	}
}
;/**=========== ENG WEAPONS End ===========**/
;/**=========== FRA WEAPONS Begin ===========**/
{"stuff weapon berthier_m1916"		;// props added to berthier mle 1916
	{on spawn
		{link_sound "open_bolt"		"weapon/reload/open_bolt/gevar_m96/"}
		{link_sound "close_bolt"	"weapon/reload/close_bolt/gevar_m96/"}
		{link_sound "action_recoil"	"weapon/action/recoil/bolt_action/"}
		{link_sound "mid"			"weapon/shot/smallarms/s3/d2/fin/gevar_m96/"}
		{link_sound "far"			"weapon/shot/smallarms/s3/d3/fin/gevar_m96/"}
	}
}
{"stuff weapon fm_24_29"			;// props added to fm 24-29
	{on spawn
		{link_sound		"action_recoil"		"weapon/shot/smallarms/s3/recoil/ger/mg26t/"}
		{link_sound		"Tail_Close"		"weapon/shot/smallarms/s3/d1/ger/mg26t/tail/"}
		{link_sound		"Head_Mid"			"weapon/shot/smallarms/s3/d2/ger/mg26t/head/"}
		{link_sound		"Tail_Mid"			"weapon/shot/smallarms/s3/d2/ger/mg26t/tail/"}
		{link_sound		"Head_Far"			"weapon/shot/smallarms/s3/d3/ger/mg26t/head/"}
		{link_sound		"Tail_Far"			"weapon/shot/smallarms/s3/d3/ger/mg26t/tail/"}
	}
	{on "fire"
		("Automatic")
	}
	("magazine" cut(1.0) show(3.0) override(overload) impulse({impulse up -0.01}))
}
;/**=========== FRA WEAPONS End ===========**/
;/**=========== FIN WEAPONS BEGIN ===========**/
{"stuff weapon boys_mk1"					;// props added to 14 mm pst kiv37:
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/at_rifle/bolt_action/"}
		{link_sound "mid"		"weapon/shot/smallarms/s4/d2/rus/ptr/"}		; placeholder
		{link_sound "far"		"weapon/shot/smallarms/s4/d3/rus/ptr/"}		; placeholder
	}
	{on "weapon_reload"
		{call "magazine_delay"}
	}
	("magazine" cut(1.00) show(2.75) override(overload) impulse({impulse up -0.01}))
}
{"stuff weapon bergmann_m20"				;// props added to 7,65 kp/bergmann
	{on spawn
		{link_sound 	"action_recoil"		"weapon/action/recoil/open_bolt_smg/"}
		{link_sound		"Tail_Close"		"weapon/shot/smallarms/s1/d1/rus/pps43/tail/"}
		{link_sound		"Head_Mid"			"weapon/shot/smallarms/s1/d2/rus/pps43/head/"}
		{link_sound		"Tail_Mid"			"weapon/shot/smallarms/s1/d2/rus/pps43/tail/"}
		{link_sound		"Head_Far"			"weapon/shot/smallarms/s1/d3/rus/pps43/head/"}
		{link_sound		"Tail_Far"			"weapon/shot/smallarms/s1/d3/rus/pps43/tail/"}
	}
	{on "fire"
		("Automatic")
	}
	("magazine" cut(0.75) show(1.6) override(overload) impulse({impulse up -0.01}))
}
{"stuff weapon chauchat"					;// props added to 800 pk 15
	{on spawn
		{link_sound 	"action_recoil"		"weapon/reload/action/recoil/open_bolt_mg/"}
		{link_sound		"Tail_Close"		"weapon/shot/smallarms/s3/d1/shared/mac1931/tail/"}
		{link_sound		"Head_Mid"			"weapon/shot/smallarms/s3/d2/shared/mac1931/head/"}
		{link_sound		"Tail_Mid"			"weapon/shot/smallarms/s3/d2/shared/mac1931/tail/"}
		{link_sound		"Head_Far"			"weapon/shot/smallarms/s3/d3/shared/mac1931/head/"}
		{link_sound		"Tail_Far"			"weapon/shot/smallarms/s3/d3/shared/mac1931/tail/"}
	}
	{on "fire"
		("Automatic")
	}
	("magazine" cut(1.00) show(1.95) override(overload) impulse({impulse up -0.01}))
}
{"stuff weapon pist_07"					;// props added to husqvarna m/1907
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/pistol/"}
		{link_sound "mid"		"weapon/shot/smallarms/s1/d2/fin/husqvarna_m1907/"}
		{link_sound "far"		"weapon/shot/smallarms/s1/d3/fin/husqvarna_m1907/"}
	}
}
{"stuff weapon kiv_96"					;// props added to gevar m/96
	{on spawn
		{link_sound "open_bolt"		"weapon/reload/open_bolt/gevar_m96/"}
		{link_sound "close_bolt"	"weapon/reload/close_bolt/gevar_m96/"}
		{link_sound "action_recoil"	"weapon/action/recoil/bolt_action/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/fin/gevar_m96/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/fin/gevar_m96/"}
	}
}
{"stuff weapon lahti_l35"					;// props added to 900 pist 35
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/pistol/"}
		{link_sound "mid"		"weapon/shot/smallarms/s1/d2/fin/l35/"}
		{link_sound "far"		"weapon/shot/smallarms/s1/d3/fin/l35/"}
	}
}
{"stuff weapon suomi_m31_drum"				;// props added to 900 kp 31 w/ drum magazine 
	{on spawn
		{link_sound 	"action_recoil"		"weapon/action/recoil/open_bolt_smg/"}
		{link_sound 	"Tail_Close"		"weapon/shot/smallarms/s1/d1/fin/kp31/tail/"}
		{link_sound 	"Head_Mid"			"weapon/shot/smallarms/s1/d2/fin/kp31/head/"}
		{link_sound 	"Tail_Mid"			"weapon/shot/smallarms/s1/d2/fin/kp31/tail/"}
		{link_sound 	"Head_Far"			"weapon/shot/smallarms/s1/d3/fin/kp31/head/"}
		{link_sound 	"Tail_Far"			"weapon/shot/smallarms/s1/d3/fin/kp31/tail/"}
	}
	{on "fire"
		("Automatic")
	}
	("magazine" cut(1.20) show(2.15) override(overload) impulse({impulse up -0.01}))
}
{"stuff weapon suomi_m31_sjr_drum"			;// props added to 900 kp 31 w/ drum magazine 
	{on spawn
		{link_sound 	"action_recoil"		"weapon/action/recoil/open_bolt_smg/"}
		{link_sound 	"Tail_Close"		"weapon/shot/smallarms/s1/d1/fin/kp31/tail/"}
		{link_sound 	"Head_Mid"			"weapon/shot/smallarms/s1/d2/fin/kp31/head/"}
		{link_sound 	"Tail_Mid"			"weapon/shot/smallarms/s1/d2/fin/kp31/tail/"}
		{link_sound 	"Head_Far"			"weapon/shot/smallarms/s1/d3/fin/kp31/head/"}
		{link_sound 	"Tail_Far"			"weapon/shot/smallarms/s1/d3/fin/kp31/tail/"}
	}
	{on "fire"
		("Automatic")
	}
	("magazine" cut(1.20) show(2.15) override(overload) impulse({impulse up -0.01}))
}
{"stuff weapon suomi_m31_stick"				;// props added to 900 kp 31 w/ stick magazine 
	{on spawn
		{link_sound 	"action_recoil"		"weapon/action/recoil/open_bolt_smg/"}
		{link_sound 	"Tail_Close"		"weapon/shot/smallarms/s1/d1/fin/kp31/tail/"}
		{link_sound 	"Head_Mid"			"weapon/shot/smallarms/s1/d2/fin/kp31/head/"}
		{link_sound 	"Tail_Mid"			"weapon/shot/smallarms/s1/d2/fin/kp31/tail/"}
		{link_sound 	"Head_Far"			"weapon/shot/smallarms/s1/d3/fin/kp31/head/"}
		{link_sound 	"Tail_Far"			"weapon/shot/smallarms/s1/d3/fin/kp31/tail/"}
	}
	{on "fire"
		("Automatic")
	}
	("magazine" cut(0.75) show(1.6) override(overload) impulse({impulse up -0.01}))
}
{"stuff weapon suomi_m31_sjr_stick"			;// props added to 900 kp 31 w/ stick magazine 
	{on spawn
		{link_sound 	"action_recoil"		"weapon/action/recoil/open_bolt_smg/"}
		{link_sound 	"Tail_Close"		"weapon/shot/smallarms/s1/d1/fin/kp31/tail/"}
		{link_sound 	"Head_Mid"			"weapon/shot/smallarms/s1/d2/fin/kp31/head/"}
		{link_sound 	"Tail_Mid"			"weapon/shot/smallarms/s1/d2/fin/kp31/tail/"}
		{link_sound 	"Head_Far"			"weapon/shot/smallarms/s1/d3/fin/kp31/head/"}
		{link_sound 	"Tail_Far"			"weapon/shot/smallarms/s1/d3/fin/kp31/tail/"}
	}
	{on "fire"
		("Automatic")
	}
	("magazine" cut(0.75) show(1.6) override(overload) impulse({impulse up -0.01}))
}
{"stuff weapon m26"							;// props added to 762 pk 26
	{on spawn 
		{link_sound 	"action_recoil"		"weapon/reload/action/recoil/open_bolt_mg/"}
		{link_sound		"Tail_Close"		"weapon/shot/smallarms/s3/d1/fin/ls26/tail/"}
		{link_sound		"Head_Mid"			"weapon/shot/smallarms/s3/d2/fin/ls26/head/"}
		{link_sound		"Tail_Mid"			"weapon/shot/smallarms/s3/d2/fin/ls26/tail/"}
		{link_sound		"Head_Far"			"weapon/shot/smallarms/s3/d3/fin/ls26/head/"}
		{link_sound		"Tail_Far"			"weapon/shot/smallarms/s3/d3/fin/ls26/tail/"}
	}
	{on "fire"
		("Automatic")
	}
}
{"stuff weapon mosin_m27"					;// props added to 762 kiv 91-27
	{on spawn
		{link_sound "open_bolt"		"weapon/reload/open_bolt/m9130/"}
		{link_sound "close_bolt"	"weapon/reload/close_bolt/m9130/"}
		{link_sound "action_recoil"	"weapon/action/recoil/bolt_action/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/fin/m39/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/fin/m39/"}
	}
}
{"stuff weapon mosin_m39"					;// props added to 762 kiv 39
	{on spawn
		{link_sound "open_bolt"		"weapon/reload/open_bolt/m9130/"}
		{link_sound "close_bolt"	"weapon/reload/close_bolt/m9130/"}
		{link_sound "action_recoil"	"weapon/action/recoil/bolt_action/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/fin/m39/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/fin/m39/"}
	}
}
{"stuff weapon madsen"						;// props added to 762 pk 20
	{on spawn 
		{link_sound "action_recoil"	"weapon/action/recoil/open_bolt_mg/reciprocating/"}
		{link_sound		"Tail_Close"		"weapon/shot/smallarms/s3/d1/fin/ls26/tail/"}
		{link_sound		"Head_Mid"			"weapon/shot/smallarms/s3/d2/fin/ls26/head/"}
		{link_sound		"Tail_Mid"			"weapon/shot/smallarms/s3/d2/fin/ls26/tail/"}
		{link_sound		"Head_Far"			"weapon/shot/smallarms/s3/d3/fin/ls26/head/"}
		{link_sound		"Tail_Far"			"weapon/shot/smallarms/s3/d3/fin/ls26/tail/"}
	}
	{on "fire"
		("Automatic")
	}
}
{"stuff weapon pk_21"					;// props added to kg m/21
	{on spawn
		{link_sound "action_recoil"	"weapon/reload/action/recoil/open_bolt_mg/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/fin/kg_m21/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/fin/kg_m21/"}
	}
	("magazine" cut(1.05) show(2.95) override(overload) impulse({impulse up -0.01}))
}
;/**=========== FIN WEAPONS END ===========**/
;/**=========== GER WEAPONS BEGIN ===========**/
{"stuff weapon mp28"						;// props added to mp 28
	{on spawn
		{link_sound 	"action_recoil"		"weapon/action/recoil/open_bolt_smg/"}
		{link_sound		"Tail_Close"		"weapon/shot/smallarms/s1/d1/ger/mp28/tail/"}
		{link_sound		"Head_Mid"			"weapon/shot/smallarms/s1/d2/ger/mp40/head/"}
		{link_sound		"Tail_Mid"			"weapon/shot/smallarms/s1/d2/ger/mp40/tail/"}
		{link_sound		"Head_Far"			"weapon/shot/smallarms/s1/d3/ger/mp40/head/"}
		{link_sound		"Tail_Far"			"weapon/shot/smallarms/s1/d3/ger/mp40/tail/"}
	}
	{on "fire"
		("Automatic")
	}
	("magazine" cut(0.75) show(1.6) override(overload) impulse({impulse up -0.01}))
}
{"stuff weapon mp40"						;// props added to mp 38, mp 40 variants and mp 41
	{on spawn
		{link_sound 	"action_recoil"		"weapon/action/recoil/open_bolt_smg/"}
		{link_sound		"Tail_Close"		"weapon/shot/smallarms/s1/d1/ger/mp40/tail/"}
		{link_sound		"Head_Mid"			"weapon/shot/smallarms/s1/d2/ger/mp40/head/"}
		{link_sound		"Tail_Mid"			"weapon/shot/smallarms/s1/d2/ger/mp40/tail/"}
		{link_sound		"Head_Far"			"weapon/shot/smallarms/s1/d3/ger/mp40/head/"}
		{link_sound		"Tail_Far"			"weapon/shot/smallarms/s1/d3/ger/mp40/tail/"}
	}
	{on "fire"
		("Automatic")
	}
	("magazine" cut(0.75) show(1.6) override(overload) impulse({impulse up -0.01}))
}
{"stuff weapon stg44"						;// props added to stg 44 and mkb 42(h)
	{on spawn
		{link_sound 	"action_recoil"		"weapon/action/recoil/closed_bolt/stg44/"}
		{link_sound		"Tail_Close"		"weapon/shot/smallarms/s2/d1/ger/stg44/tail/"}
		{link_sound		"Head_Mid"			"weapon/shot/smallarms/s2/d2/ger/stg44/head/"}
		{link_sound		"Tail_Mid"			"weapon/shot/smallarms/s2/d2/ger/stg44/tail/"}
		{link_sound		"Head_Far"			"weapon/shot/smallarms/s2/d3/ger/stg44/head/"}
		{link_sound		"Tail_Far"			"weapon/shot/smallarms/s2/d3/ger/stg44/tail/"}
	}
	{on "fire"
		("Automatic")
	}
	("magazine" cut(1.20) show(1.95) override(overload) impulse({impulse up -0.01}))
}
{"stuff weapon k98"							;// props added to all  k 98k variants
	{on spawn
		{link_sound "open_bolt"		"weapon/reload/open_bolt/k98k/"}
		{link_sound "close_bolt"	"weapon/reload/close_bolt/k98k/"}
		{link_sound "action_recoil"	"weapon/shot/smallarms/s3/recoil/ger/k98k/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/ger/k98k/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/ger/k98k/"}
	}
}
{"stuff weapon g41"							;// props added to g 41
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/closed_bolt/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/ger/g41/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/ger/g41/"}
	}
}
{"stuff weapon g43"							;// props added to all g/k 43 variants
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/closed_bolt/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/ger/g43/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/ger/g43/"}
	}
}
{"stuff weapon fg42"						;// props added to fg 42
	{on spawn
		{link_sound 	"action_recoil"		"weapon/action/recoil/closed_bolt/"}
		{link_sound		"Tail_Close"		"weapon/shot/smallarms/s3/d1/ger/fg42/tail/"}
		{link_sound		"Head_Mid"			"weapon/shot/smallarms/s3/d2/ger/fg42/head/"}
		{link_sound		"Tail_Mid"			"weapon/shot/smallarms/s3/d2/ger/fg42/tail/"}
		{link_sound		"Head_Far"			"weapon/shot/smallarms/s3/d3/ger/fg42/head/"}
		{link_sound		"Tail_Far"			"weapon/shot/smallarms/s3/d3/ger/fg42/tail/"}
	}
	{on "fire"
		("Automatic")
	}
	("magazine" cut(1) show(2.45) override(overload) impulse({impulse up -0.01}))
}
{"stuff weapon mg13_no_bipod"				;// props added to mg 13
	{on spawn
		{link_sound 	"action_recoil"		"weapon/action/recoil/closed_bolt/"}
		{link_sound		"Tail_Close"		"weapon/shot/smallarms/s3/d1/ger/mg13/tail/"}
		{link_sound		"Head_Mid"			"weapon/shot/smallarms/s3/d2/ger/mg13/head/"}
		{link_sound		"Tail_Mid"			"weapon/shot/smallarms/s3/d2/ger/mg13/tail/"}
		{link_sound		"Head_Far"			"weapon/shot/smallarms/s3/d3/ger/mg13/head/"}
		{link_sound		"Tail_Far"			"weapon/shot/smallarms/s3/d3/ger/mg13/tail/"}
	}
	{on "fire"
		("Automatic")
	}
	("magazine" cut(1) show(2.45) override(overload) impulse({impulse up -0.01}))
}
{"stuff weapon mg26t"						;// props added to mg 26(t)
	{on spawn
		{link_sound		"action_recoil"		"weapon/shot/smallarms/s3/recoil/ger/mg26t/"}
		{link_sound		"Tail_Close"		"weapon/shot/smallarms/s3/d1/ger/mg26t/tail/"}
		{link_sound		"Head_Mid"			"weapon/shot/smallarms/s3/d2/ger/mg26t/head/"}
		{link_sound		"Tail_Mid"			"weapon/shot/smallarms/s3/d2/ger/mg26t/tail/"}
		{link_sound		"Head_Far"			"weapon/shot/smallarms/s3/d3/ger/mg26t/head/"}
		{link_sound		"Tail_Far"			"weapon/shot/smallarms/s3/d3/ger/mg26t/tail/"}
	}
	{on "fire"
		("Automatic")
	}
	("magazine" cut(1.0) show(3.0) override(overload) impulse({impulse up -0.01}))
}
{"stuff weapon mg34_doubledrum"				;// props added to mg 34 w/ patronentrommel 34
	{on spawn
		{link_sound		"action_recoil"		"weapon/shot/smallarms/s3/recoil/ger/mg42/"}
		{link_sound		"Tail_Close"		"weapon/shot/smallarms/s3/d1/ger/mg34/tail/"}
		{link_sound		"Head_Mid"			"weapon/shot/smallarms/s3/d2/ger/mg34/head/"}
		{link_sound		"Tail_Mid"			"weapon/shot/smallarms/s3/d2/ger/mg34/tail/"}
		{link_sound		"Head_Far"			"weapon/shot/smallarms/s3/d3/ger/mg34/head/"}
		{link_sound		"Tail_Far"			"weapon/shot/smallarms/s3/d3/ger/mg34/tail/"}
	}
	{on "fire"
		("Automatic")
	}
	("magazine" cut(1) show(2.25) override(overload) impulse({impulse up 0.5 forward 0.9 0.1}))
}
{"stuff weapon mg34_drum"					;// props added to mg 34 w/ gurttrommel 34
	{on spawn
		{link_sound		"action_recoil"		"weapon/shot/smallarms/s3/recoil/ger/mg42/"}
		{link_sound		"Tail_Close"		"weapon/shot/smallarms/s3/d1/ger/mg34/tail/"}
		{link_sound		"Head_Mid"			"weapon/shot/smallarms/s3/d2/ger/mg34/head/"}
		{link_sound		"Tail_Mid"			"weapon/shot/smallarms/s3/d2/ger/mg34/tail/"}
		{link_sound		"Head_Far"			"weapon/shot/smallarms/s3/d3/ger/mg34/head/"}
		{link_sound		"Tail_Far"			"weapon/shot/smallarms/s3/d3/ger/mg34/tail/"}
	}
	{on "fire"
		("Automatic")
	}
	("magazine" cut(1) show(1.95) override(overload) impulse({impulse up 0.4 forward 0.9 0.1}))
}
{"stuff weapon mg34_belt"					;// props added to mg 34
	{on spawn
		{link_sound		"action_recoil"		"weapon/shot/smallarms/s3/recoil/ger/mg42/"}
		{link_sound		"Tail_Close"		"weapon/shot/smallarms/s3/d1/ger/mg34/tail/"}
		{link_sound		"Head_Mid"			"weapon/shot/smallarms/s3/d2/ger/mg34/head/"}
		{link_sound		"Tail_Mid"			"weapon/shot/smallarms/s3/d2/ger/mg34/tail/"}
		{link_sound		"Head_Far"			"weapon/shot/smallarms/s3/d3/ger/mg34/head/"}
		{link_sound		"Tail_Far"			"weapon/shot/smallarms/s3/d3/ger/mg34/tail/"}
	}
	{on "fire"
		("Automatic")
	}
}
{"stuff weapon mg34_belt_long"				;// props added to mg 34
	{on spawn
		{link_sound		"action_recoil"		"weapon/shot/smallarms/s3/recoil/ger/mg42/"}
		{link_sound		"Tail_Close"		"weapon/shot/smallarms/s3/d1/ger/mg34/tail/"}
		{link_sound		"Head_Mid"			"weapon/shot/smallarms/s3/d2/ger/mg34/head/"}
		{link_sound		"Tail_Mid"			"weapon/shot/smallarms/s3/d2/ger/mg34/tail/"}
		{link_sound		"Head_Far"			"weapon/shot/smallarms/s3/d3/ger/mg34/head/"}
		{link_sound		"Tail_Far"			"weapon/shot/smallarms/s3/d3/ger/mg34/tail/"}
	}
	{on "fire"
		("Automatic")
	}
}
{"stuff weapon mg42_drum"					;// props added to mg 42 w/ gurttrommel 34
	{on spawn
		{link_sound 	"action_recoil"		"weapon/shot/smallarms/s3/recoil/ger/mg42/"}
		{link_sound 	"Tail_Close"		"weapon/shot/smallarms/s3/d1/ger/mg42/tail/"}
		{link_sound 	"Head_Mid"			"weapon/shot/smallarms/s3/d2/ger/mg42/head/"}
		{link_sound 	"Tail_Mid"			"weapon/shot/smallarms/s3/d2/ger/mg42/tail/"}
		{link_sound 	"Head_Far"			"weapon/shot/smallarms/s3/d3/ger/mg42/head/"}
		{link_sound 	"Tail_Far"			"weapon/shot/smallarms/s3/d3/ger/mg42/tail/"}
	}
	{on "fire"
		("Automatic")
	}
	("magazine" cut(1) show(1.95) override(overload) impulse({impulse up 0.3 forward 0.9 0.1 cy 1.5 0.25}))
}
{"stuff weapon mg42_belt"					;// props added to mg 42
	{on spawn
		{link_sound		"action_recoil"		"weapon/shot/smallarms/s3/recoil/ger/mg42/"}
		{link_sound		"Tail_Close"		"weapon/shot/smallarms/s3/d1/ger/mg42/tail/"}
		{link_sound		"Head_Mid"			"weapon/shot/smallarms/s3/d2/ger/mg42/head/"}
		{link_sound		"Tail_Mid"			"weapon/shot/smallarms/s3/d2/ger/mg42/tail/"}
		{link_sound		"Head_Far"			"weapon/shot/smallarms/s3/d3/ger/mg42/head/"}
		{link_sound		"Tail_Far"			"weapon/shot/smallarms/s3/d3/ger/mg42/tail/"}
	}
	{on "fire"
		("Automatic")
	}
}
{"stuff weapon mg42_belt_long"				;// props added to mg 42
	{on spawn
		{link_sound 	"action_recoil"		"weapon/shot/smallarms/s3/recoil/ger/mg42/"}
		{link_sound 	"Tail_Close"		"weapon/shot/smallarms/s3/d1/ger/mg42/tail/"}
		{link_sound 	"Head_Mid"			"weapon/shot/smallarms/s3/d2/ger/mg42/head/"}
		{link_sound 	"Tail_Mid"			"weapon/shot/smallarms/s3/d2/ger/mg42/tail/"}
		{link_sound 	"Head_Far"			"weapon/shot/smallarms/s3/d3/ger/mg42/head/"}
		{link_sound 	"Tail_Far"			"weapon/shot/smallarms/s3/d3/ger/mg42/tail/"}
	}
	{on "fire"
		("Automatic")
	}
}
{"stuff weapon luger"						;// props added to p 08
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/pistol/"}
		{link_sound "mid"		"weapon/shot/smallarms/s1/d2/ger/p08/"}
		{link_sound "far"		"weapon/shot/smallarms/s1/d3/ger/p08/"}
	}
}
{"stuff weapon p38"							;// props added to p 38
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/pistol/"}
		{link_sound "mid"		"weapon/shot/smallarms/s1/d2/ger/p38/"}
		{link_sound "far"		"weapon/shot/smallarms/s1/d3/ger/p38/"}
	}
}
{"stuff weapon pzb_39"						;// props added to pzb 39
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/at_rifle/bolt_action/"}
		{link_sound "mid"		"weapon/shot/smallarms/s4/d2/rus/ptr/"}		; placeholder
		{link_sound "far"		"weapon/shot/smallarms/s4/d3/rus/ptr/"}		; placeholder
	}
}
{"stuff weapon panzerfaust"					;// props added to all panzerfaust variants
	{on spawn
		{link_sound "mid"		"weapon/shot/reactive/d2/ger/panzerfaust/"}
		{link_sound "far"		"weapon/shot/reactive/d3/ger/panzerfaust/"}
	}
}
{"stuff weapon schiessbecher"				;// props added to all k 98k rifle grenade launchers
	{on spawn
		{link_sound "open_bolt"		"weapon/reload/open_bolt/k98k/"}
		{link_sound "close_bolt"	"weapon/reload/close_bolt/k98k/"}
		{link_sound "action_recoil"	"weapon/action/recoil/bolt_action/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/ger/k98k/schiessbecher/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/ger/k98k/schiessbecher/"}
	}
}
;/**=========== GER WEAPONS END ===========**/
;/**=========== RUS WEAPONS BEGIN ===========**/

{"stuff weapon dp_bipod"					;// props added to dp 27
	{on spawn
		{link_sound 	"action_recoil"		"weapon/action/recoil/open_bolt_mg/reciprocating/"}
		{link_sound 	"Tail_Close"		"weapon/shot/smallarms/s3/d1/rus/dp27/tail/"}
		{link_sound 	"Head_Mid"			"weapon/shot/smallarms/s3/d2/rus/dp27/head/"}
		{link_sound 	"Tail_Mid"			"weapon/shot/smallarms/s3/d2/rus/dp27/tail/"}
		{link_sound 	"Head_Far"			"weapon/shot/smallarms/s3/d3/rus/dp27/head/"}
		{link_sound 	"Tail_Far"			"weapon/shot/smallarms/s3/d3/rus/dp27/tail/"}
	}
	{on "fire"
		("Automatic")
	}
	("magazine" cut(0.75) show(2.5) override(overload) impulse({impulse up 0.3 forward 0.9 0.1 cy 1.5 0.25}))
}
{"stuff weapon dt"							;// props added to dt 
	{on spawn
		{link_sound 	"action_recoil"		"weapon/action/recoil/open_bolt_mg/reciprocating/"}
		{link_sound 	"Tail_Close"		"weapon/shot/smallarms/s3/d1/rus/dp27/tail/"}
		{link_sound 	"Head_Mid"			"weapon/shot/smallarms/s3/d2/rus/dp27/head/"}
		{link_sound 	"Tail_Mid"			"weapon/shot/smallarms/s3/d2/rus/dp27/tail/"}
		{link_sound 	"Head_Far"			"weapon/shot/smallarms/s3/d3/rus/dp27/head/"}
		{link_sound 	"Tail_Far"			"weapon/shot/smallarms/s3/d3/rus/dp27/tail/"}
	}
	{on "fire"
		("Automatic")
	}
	("magazine" cut(0.75) show(2.5) override(overload) impulse({impulse up 0.3 forward 0.9 0.1 cy 1.5 0.25}))
}
{"stuff weapon dyakonov"					;// props added mosin-nagant 1891/30 rifle grenade launchers
	{on spawn
		{link_sound "open_bolt"		"weapon/reload/open_bolt/mn9130/"}
		{link_sound "close_bolt"	"weapon/reload/close_bolt/mn9130/"}
		{link_sound "action_recoil"	"weapon/action/recoil/bolt_action/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/rus/m9130/dyakonov/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/rus/m9130/dyakonov/"}
	}
}
{"stuff weapon mosin"						;// props added to all  mosin-nagant 1891/30 variants and mosin carbine
	{on spawn
		{link_sound "open_bolt"		"weapon/reload/open_bolt/m9130/"}
		{link_sound "close_bolt"	"weapon/reload/close_bolt/m9130/"}
		{link_sound "action_recoil"	"weapon/action/recoil/bolt_action/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/rus/m9130/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/rus/m9130/"}
	}
}
{"stuff weapon mosin_silencer"				;// props added to all  mosin-nagant 1891/30 b
	{on spawn
		{link_sound "open_bolt"		"weapon/reload/open_bolt/m9130/"}
		{link_sound "close_bolt"	"weapon/reload/close_bolt/m9130/"}
		{link_sound "action_recoil"	"weapon/action/recoil/bolt_action/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/shared/surpressed_rifle/"}
	}
}
{"stuff weapon nagant_revolver"				;// props added to nagant 1895
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/bolt_action/"}
		{link_sound "mid"		"weapon/shot/smallarms/s1/d2/rus/m1895/"}
		{link_sound "far"		"weapon/shot/smallarms/s1/d3/rus/m1895/"}
	}
}
{"stuff weapon nagant_silencer"				;// props added to nagant 1895 b
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/bolt_action/"}
		{link_sound "mid"		"weapon/shot/smallarms/s1/d2/shared/surpressed_pistol/"}
	}
}
{"stuff weapon ppd40"						;// props added to ppd 40
	{on spawn
		{link_sound 	"action_recoil"		"weapon/action/recoil/open_bolt_smg/type2/"}
		{link_sound		"Tail_Close"		"weapon/shot/smallarms/s1/d1/rus/ppsh41/tail/"}
		{link_sound		"Head_Mid"			"weapon/shot/smallarms/s1/d2/rus/ppsh41/head/"}
		{link_sound		"Tail_Mid"			"weapon/shot/smallarms/s1/d2/rus/ppsh41/tail/"}
		{link_sound		"Head_Far"			"weapon/shot/smallarms/s1/d3/rus/ppsh41/head/"}
		{link_sound		"Tail_Far"			"weapon/shot/smallarms/s1/d3/rus/ppsh41/tail/"}
	}
	{on "fire"
		("Automatic")
	}
	("magazine" cut(1.20) show(2.15) override(overload) impulse({impulse up -0.01}))
}

{"stuff weapon ppsh41_drum"					;// props added to ppsh 41 w/ drum magazine
	{on spawn
		{link_sound 	"action_recoil"		"weapon/action/recoil/open_bolt_smg/type2/"}
		{link_sound		"Tail_Close"		"weapon/shot/smallarms/s1/d1/rus/ppsh41/tail/"}
		{link_sound		"Head_Mid"			"weapon/shot/smallarms/s1/d2/rus/ppsh41/head/"}
		{link_sound		"Tail_Mid"			"weapon/shot/smallarms/s1/d2/rus/ppsh41/tail/"}
		{link_sound		"Head_Far"			"weapon/shot/smallarms/s1/d3/rus/ppsh41/head/"}
		{link_sound		"Tail_Far"			"weapon/shot/smallarms/s1/d3/rus/ppsh41/tail/"}
	}
	{on "fire"
		("Automatic")
	}
	("magazine" cut(1.20) show(2.15) override(overload) impulse({impulse up -0.01}))
}

{"stuff weapon ppsh41_stick"				;// props added to ppsh 41 w/ stick magazine 
	{on spawn
		{link_sound 	"action_recoil"		"weapon/action/recoil/open_bolt_smg/type2/"}
		{link_sound		"Tail_Close"		"weapon/shot/smallarms/s1/d1/rus/ppsh41/tail/"}
		{link_sound		"Head_Mid"			"weapon/shot/smallarms/s1/d2/rus/ppsh41/head/"}
		{link_sound		"Tail_Mid"			"weapon/shot/smallarms/s1/d2/rus/ppsh41/tail/"}
		{link_sound		"Head_Far"			"weapon/shot/smallarms/s1/d3/rus/ppsh41/head/"}
		{link_sound		"Tail_Far"			"weapon/shot/smallarms/s1/d3/rus/ppsh41/tail/"}
	}
	{on "fire"
		("Automatic")
	}
	("magazine" cut(0.75) show(1.6) override(overload) impulse({impulse up -0.01}))
}

{"stuff weapon pps43"						;// props added to pps 43
	{on spawn
		{link_sound 	"action_recoil"		"weapon/action/recoil/open_bolt_smg/type2/"}
		{link_sound		"Tail_Close"		"weapon/shot/smallarms/s1/d1/rus/pps43/tail/"}
		{link_sound		"Head_Mid"			"weapon/shot/smallarms/s1/d2/rus/pps43/head/"}
		{link_sound		"Tail_Mid"			"weapon/shot/smallarms/s1/d2/rus/pps43/tail/"}
		{link_sound		"Head_Far"			"weapon/shot/smallarms/s1/d3/rus/pps43/head/"}
		{link_sound		"Tail_Far"			"weapon/shot/smallarms/s1/d3/rus/pps43/tail/"}
	}
	{on "fire"
		("Automatic")
	}
	("magazine" cut(0.75) show(1.6) override(overload) impulse({impulse up -0.01}))
}
{"stuff weapon ptrd"
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/at_rifle/bolt_action/"}
		{link_sound "mid"		"weapon/shot/smallarms/s4/d2/rus/ptr/"}
		{link_sound "far"		"weapon/shot/smallarms/s4/d3/rus/ptr/"}
	}
	{on "weapon_reload" overload
		{delay 3.2
			{ani_play "reload"}
		}
	}
}
{"stuff weapon ptrs"
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/at_rifle/semi_auto/"}
		{link_sound "mid"		"weapon/shot/smallarms/s4/d2/rus/ptr/"}
		{link_sound "far"		"weapon/shot/smallarms/s4/d3/rus/ptr/"}
	}
	{on "weapon_reload" overload
		{delay 0.5
			{kill_delay "bolt_action"}
			{ani_play "reload"}
			{view hide "bullet"}
			{call "magazine_delay"}
		}
	}
	("magazine" cut(0.1) show(2.9) override(overload) impulse({impulse up -0.01}))
}
{"stuff weapon svt"							;// props added to avt 40, svt 38, svt 40, and skt 40
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/closed_bolt/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/rus/svt40/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/rus/svt40/"}
	}
	("magazine" cut(1.75) show(2.1) override(overload) impulse({impulse up -0.01}))
}
{"stuff weapon tt33"						;// props added to tt 33
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/pistol/"}
		{link_sound "mid"			"weapon/shot/smallarms/s1/d2/rus/tt33/"}
		{link_sound "far"			"weapon/shot/smallarms/s1/d3/rus/tt33/"}
	}
}
;/**=========== RUS WEAPONS END ===========**/
;/**=========== USA WEAPONS Begin ===========**/
{"stuff weapon browning_m2"					;// props added to browning m2hb .50 cal
	("magazine" cut(0.1) show(5.85) override(overload) impulse({impulse up -0.01 com}))
}
{"stuff weapon m12_shotgun"
	{on spawn	
		{link_sound "open_bolt"		"weapon/reload/open_bolt/m12/"}
		{link_sound "close_bolt"	"weapon/reload/close_bolt/m12/"}
	}
}
{"stuff weapon browning_m19a4"				;// props added to browning m1919a4 .30 cal
	{on spawn
		{link_sound 	"action_recoil"		"weapon/action/recoil/open_bolt_mg/"}
		{link_sound 	"Tail_Close"		"weapon/shot/smallarms/s3/d1/usa/m1919a4/tail/"}
		{link_sound 	"Head_Mid"			"weapon/shot/smallarms/s3/d2/usa/m1919a4/head/"}
		{link_sound 	"Tail_Mid"			"weapon/shot/smallarms/s3/d2/usa/m1919a4/tail/"}
		{link_sound 	"Head_Far"			"weapon/shot/smallarms/s3/d3/usa/m1919a4/head/"}
		{link_sound 	"Tail_Far"			"weapon/shot/smallarms/s3/d3/usa/m1919a4/tail/"}
	}
	{on "fire"
		("Automatic")
	}
}
{"stuff weapon bar"							;// props added to m1918a2 bar 
	{on spawn
		{link_sound 	"action_recoil"		"weapon/shot/smallarms/s3/recoil/usa/m1918a2_bar/"}
		{link_sound 	"Tail_Close"		"weapon/shot/smallarms/s3/d1/usa/m1918a2_bar/tail/"}
		{link_sound 	"Head_Mid"			"weapon/shot/smallarms/s3/d2/usa/m1918a2_bar/head/"}
		{link_sound 	"Tail_Mid"			"weapon/shot/smallarms/s3/d2/usa/m1918a2_bar/tail/"}
		{link_sound 	"Head_Far"			"weapon/shot/smallarms/s3/d3/usa/m1918a2_bar/head/"}
		{link_sound 	"Tail_Far"			"weapon/shot/smallarms/s3/d3/usa/m1918a2_bar/tail/"}
	}
	{on "fire"
		("Automatic")
	}
	("magazine" cut(1.05) show(2.95) override(overload) impulse({impulse up -0.01}))
}
{"stuff weapon garand"						;// props added to m1 garand
	{on spawn
		{add_view "shell_rifle_m1_garand"	"shell"		"fxshell"}
		{link_sound "action_recoil"	"weapon/shot/smallarms/s3/recoil/usa/m1_garand/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/usa/m1_garand/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/usa/m1_garand/"}
		{link_sound "eject_clip"	"weapon/reload/m1_garand/clip_eject/"}
	}
	("magazine" cut(0.1) show(2.9) override(overload) impulse({impulse up 2}))
}
{"stuff weapon garand_grenade_launcher"		;// props added to m1 garand w/ m7 grenade launcher
	{on spawn
		{add_view "shell_rifle_m1_garand"	"shell"		"fxshell"}
		{link_sound "action_recoil"	"weapon/shot/smallarms/s3/recoil/usa/m1_garand/"}
		{link_sound "mid"			"weapon/shot/smallarms/s3/d2/usa/m1_garand/m7_grenade_launcher/"}
		{link_sound "far"			"weapon/shot/smallarms/s3/d3/usa/m1_garand/m7_grenade_launcher/"}
	}
}
{"stuff weapon hdm"
	{on spawn
		{link_sound "action_recoil"	"weapon/shot/smallarms/s1/recoil/usa/m1911a1/"}
		{link_sound "mid"		"weapon/shot/smallarms/s1/d2/shared/surpressed_pistol/"}
	}
}
{"stuff weapon m3_grease"					;// props added to m3 grease gun
	{on spawn
		{link_sound 	"action_recoil"		"weapon/shot/smallarms/s1/recoil/usa/m3_greasegun/"}
		{link_sound 	"Tail_Close"		"weapon/shot/smallarms/s1/d1/usa/m3_greasegun/tail/"}
		{link_sound 	"Head_Mid"			"weapon/shot/smallarms/s1/d2/usa/m3_greasegun/head/"}
		{link_sound 	"Tail_Mid"			"weapon/shot/smallarms/s1/d2/usa/m3_greasegun/tail/"}
		{link_sound 	"Head_Far"			"weapon/shot/smallarms/s1/d3/usa/m3_greasegun/head/"}
		{link_sound 	"Tail_Far"			"weapon/shot/smallarms/s1/d3/usa/m3_greasegun/tail/"}
	}
	{on "fire"
		("Automatic")
	}
	("magazine" cut(0.75) show(1.6) override(overload) impulse({impulse up -0.01}))
}
{"stuff weapon thompson"					;// props added to all thompson variants
	{on spawn
		{link_sound 	"action_recoil"		"weapon/shot/smallarms/s1/recoil/usa/m1a1_thompson/"}
		{link_sound 	"Tail_Close"		"weapon/shot/smallarms/s1/d1/usa/m1a1_thompson/tail/"}
		{link_sound 	"Head_Mid"			"weapon/shot/smallarms/s1/d2/usa/m1a1_thompson/head/"}
		{link_sound 	"Tail_Mid"			"weapon/shot/smallarms/s1/d2/usa/m1a1_thompson/tail/"}
		{link_sound 	"Head_Far"			"weapon/shot/smallarms/s1/d3/usa/m1a1_thompson/head/"}
		{link_sound 	"Tail_Far"			"weapon/shot/smallarms/s1/d3/usa/m1a1_thompson/tail/"}
	}
	{on "fire"
		("Automatic")
	}
	("magazine" cut(0.75) show(1.6) override(overload) impulse({impulse up -0.01}))
}
{"stuff weapon thompson_drum"				;// props added to thompson with drum
	{on spawn
		{link_sound 	"action_recoil"		"weapon/shot/smallarms/s1/recoil/usa/m1a1_thompson/"}
		{link_sound 	"Tail_Close"		"weapon/shot/smallarms/s1/d1/usa/m1a1_thompson/tail/"}
		{link_sound 	"Head_Mid"			"weapon/shot/smallarms/s1/d2/usa/m1a1_thompson/head/"}
		{link_sound 	"Tail_Mid"			"weapon/shot/smallarms/s1/d2/usa/m1a1_thompson/tail/"}
		{link_sound 	"Head_Far"			"weapon/shot/smallarms/s1/d3/usa/m1a1_thompson/head/"}
		{link_sound 	"Tail_Far"			"weapon/shot/smallarms/s1/d3/usa/m1a1_thompson/tail/"}
	}
	{on "fire"
		("Automatic")
	}
	("magazine" cut(1.05) show(2.15) override(overload) impulse({impulse up -0.01}))
}
{"stuff weapon m1_carbine"					;// props added to m1 and m1a1 carbines
	{on spawn
		{link_sound "action_recoil"	"weapon/shot/smallarms/s2/recoil/usa/m1_carbine/"}
		{link_sound "mid"			"weapon/shot/smallarms/s2/d2/usa/m1_carbine/"}
		{link_sound "far"			"weapon/shot/smallarms/s2/d3/usa/m1_carbine/"}
	}
	("magazine" cut(1.05) show(1.95) override(overload) impulse({impulse up -0.01}))
}
{"stuff weapon m1_carbine_grenade_launcher"	;// props added to m1 carbine w/ m8 grenade launcher
	{on spawn
		{link_sound "action_recoil"	"weapon/shot/smallarms/s2/recoil/usa/m1_carbine/"}
		{link_sound "mid"			"weapon/shot/smallarms/s2/d2/usa/m1_carbine/m8_grenade_launcher/"}
		{link_sound "far"			"weapon/shot/smallarms/s2/d3/usa/m1_carbine/m8_grenade_launcher/"}
	}
}
{"stuff weapon m1a1_carbine_grenade_launcher"	;// props added to m1a1 carbine w/ m8 grenade launcher
	{on spawn
		{link_sound "action_recoil"	"weapon/shot/smallarms/s2/recoil/usa/m1_carbine/"}
		{link_sound "mid"			"weapon/shot/smallarms/s2/d2/usa/m1_carbine/m8_grenade_launcher/"}
		{link_sound "far"			"weapon/shot/smallarms/s2/d3/usa/m1_carbine/m8_grenade_launcher/"}
	}
}
{"stuff weapon m1903"						;// props added to m1903a3 & m1903a4
	{on spawn
		{link_sound "open_bolt"		"weapon/reload/open_bolt/m1903a3/"}
		{link_sound "close_bolt"	"weapon/reload/close_bolt/m1903a3/"}
		{link_sound "action_recoil"	"weapon/shot/smallarms/s3/recoil/usa/m1903a3/"}
		{link_sound "mid"			"weapon/shot/smallarms/s3/d2/usa/m1903a3/"}
		{link_sound "far"			"weapon/shot/smallarms/s3/d3/usa/m1903a3/"}
	}
}
{"stuff weapon m1903_grenade_launcher"		;// props added to m1903a3 w/ m1 grenade launcher
	{on spawn
		{link_sound "open_bolt"		"weapon/reload/open_bolt/m1903a3/"}
		{link_sound "close_bolt"	"weapon/reload/close_bolt/m1903a3/"}
		{link_sound "action_recoil"	"weapon/shot/smallarms/s3/recoil/usa/m1903a3/"}
		{link_sound "mid"			"weapon/shot/smallarms/s3/d2/usa/m1903a3/m1_grenade_launcher/"}
		{link_sound "far"			"weapon/shot/smallarms/s3/d3/usa/m1903a3/m1_grenade_launcher/"}
	}
}
{"stuff weapon m1911"						;// props added to m1911a1
	{on spawn
		{link_sound "action_recoil"	"weapon/shot/smallarms/s1/recoil/usa/m1911a1/"}
		{link_sound "mid"			"weapon/shot/smallarms/s1/d2/usa/m1911a1/"}
		{link_sound "far"			"weapon/shot/smallarms/s1/d3/usa/m1911a1/"}
	}
}
{"stuff weapon recoilless_m18"
	{on spawn
		{link_sound "mid"			"weapon/shot/reactive/d2/shared/rocket_launcher/"}
		{link_sound "far"			"weapon/shot/reactive/d3/shared/rocket_launcher/"}
	}
}
;/**=========== USA WEAPONS END ===========**/
;/**=========== SWE WEAPONS BEGIN ===========**/
{"stuff weapon m1907"						;// props added to husqvarna m/07
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/pistol/"}
		{link_sound "mid"			"weapon/shot/smallarms/s1/d2/rus/tt33/"}
		{link_sound "far"			"weapon/shot/smallarms/s1/d3/rus/tt33/"}
	}
}
{"stuff weapon gevar_m96"					;// props added to gevar m/1896
	{on spawn
		{link_sound "open_bolt"		"weapon/reload/open_bolt/k98k/"}
		{link_sound "close_bolt"	"weapon/reload/close_bolt/k98k/"}
		{link_sound "action_recoil"	"weapon/shot/smallarms/s3/recoil/ger/k98k/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/ger/k98k/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/ger/k98k/"}
	}
}
{"stuff weapon kg_m21"						;// props added to kulsprutegevär m/21
	{on spawn
		{link_sound		"action_recoil"		"weapon/shot/smallarms/s3/recoil/usa/m1918a2_bar/"}
		{link_sound		"Tail_Close"		"weapon/shot/smallarms/s3/d1/fin/KG_m21/tail/"}
		{link_sound		"Head_Mid"			"weapon/shot/smallarms/s3/d2/fin/KG_m21/head/"}
		{link_sound		"Tail_Mid"			"weapon/shot/smallarms/s3/d2/fin/KG_m21/tail/"}
		{link_sound		"Head_Far"			"weapon/shot/smallarms/s3/d3/fin/KG_m21/head/"}
		{link_sound		"Tail_Far"			"weapon/shot/smallarms/s3/d3/fin/KG_m21/tail/"}
	}
	{on "fire"
		("Automatic")
	}
	("magazine" cut(1.05) show(2.95) override(overload) impulse({impulse up -0.01}))
}
;/**=========== SWE WEAPONS END ===========**/
;/*=========== SPECIFIC WEAPONS END ===========*/
;/*=========== SHARED WEAPONS BEGIN ===========*/
{"stuff weapon hipower_1935"				;// props added to fn browning hi-power p35
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/pistol/"}
		{link_sound "mid"			"weapon/shot/smallarms/s1/d2/shared/fn_browning_hipower_p35/"}
		{link_sound "far"			"weapon/shot/smallarms/s1/d3/shared/fn_browning_hipower_p35/"}
	}
}
{"stuff weapon rocket_launcher"				;// props added to all shoulder fired rocket launchers
	{on spawn
		{link_sound "mid"			"weapon/shot/reactive/d2/shared/rocket_launcher/"}
		{link_sound "far"			"weapon/shot/reactive/d3/shared/rocket_launcher/"}
	}
}
{"stuff weapon shotgun"						;// props added to
	{on spawn
		{link_sound "action_recoil"		"weapon/action/recoil/bolt_action/"}
		{link_sound "mid"			"weapon/shot/smallarms/s2/d2/shared/shotgun/"}
		{link_sound "far"			"weapon/shot/smallarms/s2/d3/shared/shotgun/"}
	}
}
;/***=========== SHARED WEAPONS END ===========***/

;/*=========== MODDED WEAPONS BEGIN ===========*/
{"stuff weapon fedorov_avtomat"				;// props added to Fedorov Avtomat
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/closed_bolt/"}
		{link_sound "mid"			"weapon/shot/smallarms/s3/d2/usa/m1918a2_bar/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/ger/g41/"}
	}
	("magazine" cut(1.75) show(2.1) override(overload) impulse({impulse up -0.01}))
}
{"stuff weapon m38"							;// props added to Carcano M38
	{on spawn
		{link_sound "open_bolt"		"weapon/reload/open_bolt/m1903a3/"}
		{link_sound "close_bolt"	"weapon/reload/close_bolt/m1903a3/"}
		{link_sound "action_recoil"	"weapon/shot/smallarms/s3/recoil/usa/m1903a3/"}
		{link_sound "mid"			"weapon/shot/smallarms/s3/d2/ger/k98k/"}
		{link_sound "far"			"weapon/shot/smallarms/s3/d3/ger/k98k/"}
	}
}
{"stuff weapon pzb_783r"					;// props added to PzB 783r
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/at_rifle/bolt_action/"}
		{link_sound "mid"		"weapon/shot/smallarms/s4/d2/rus/ptr/"}
		{link_sound "far"		"weapon/shot/smallarms/s4/d3/rus/ptr/"}
	}
	{on "weapon_reload" overload
		{delay 3.2
			{ani_play "reload"}
		}
	}
}
{"stuff weapon pzb_35p"						;// props added to PzB 35
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/at_rifle/bolt_action/"}
		{link_sound "mid"			"weapon/shot/smallarms/s4/d2/rus/ptr/"}
		{link_sound "far"			"weapon/shot/smallarms/s4/d3/rus/ptr/"}
	}
	{on "weapon_reload"
		{call "magazine_delay"}
	}
	("magazine" cut(2.75) show(3.2) override(overload) impulse({impulse up -0.01}))
}
{"stuff weapon pzb_770i"					;// props added to PzB 35
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/at_rifle/bolt_action/"}
		{link_sound "mid"			"weapon/shot/smallarms/s4/d2/rus/ptr/"}
		{link_sound "far"			"weapon/shot/smallarms/s4/d3/rus/ptr/"}
	}
	{on "weapon_reload"
		{call "magazine_delay"}
	}
	("magazine" cut(2.75) show(3.2) override(overload) impulse({impulse up -0.01}))
}
{"stuff weapon mg13_bipod"					;// props added to MG 13
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/closed_bolt/"}
		{link_sound "mid"			"weapon/shot/smallarms/s3/d2/ger/mg13/"}
		{link_sound "far"			"weapon/shot/smallarms/s3/d3/ger/mg13/"}
	}
	("magazine" cut(1) show(2.45) override(overload) impulse({impulse up -0.01}))
}
{"stuff weapon mg13k_bipod"					;// props added to MG 13k
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/closed_bolt/"}
		{link_sound "mid"			"weapon/shot/smallarms/s3/d2/ger/mg13/"}
		{link_sound "far"			"weapon/shot/smallarms/s3/d3/ger/mg13/"}
	}
	("magazine" cut(1) show(2.45) override(overload) impulse({impulse up -0.01}))
}
{"stuff weapon mg13_no_bipod_drum"			;// props added to MG 13
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/closed_bolt/"}
		{link_sound "mid"			"weapon/shot/smallarms/s3/d2/ger/mg13/"}
		{link_sound "far"			"weapon/shot/smallarms/s3/d3/ger/mg13/"}
	}
	("magazine" cut(1) show(2.45) override(overload) impulse({impulse up -0.01}))
}
{"stuff weapon mg13_bipod_drum"				;// props added to MG 13
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/closed_bolt/"}
		{link_sound "mid"			"weapon/shot/smallarms/s3/d2/ger/mg13/"}
		{link_sound "far"			"weapon/shot/smallarms/s3/d3/ger/mg13/"}
	}
	("magazine" cut(1) show(2.45) override(overload) impulse({impulse up -0.01}))
}
{"stuff weapon mg15"						;// props added to MG 13
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/open_bolt_mg/"}
		{link_sound "mid"			"weapon/shot/smallarms/s3/d2/ger/mg13/"}
		{link_sound "far"			"weapon/shot/smallarms/s3/d3/ger/mg13/"}
	}
	("magazine" cut(1) show(2.45) override(overload) impulse({impulse up -0.01}))
}
{"stuff weapon Lewis_Gun_rus"				;// props added to Lewis Gun Mk.I
	{on spawn
		{link_sound "action_recoil"	"weapon/shot/smallarms/s3/recoil/eng/bren_gun/"}
		{link_sound "mid"			"weapon/shot/smallarms/s3/d2/eng/Lewis_Gun/"}
		{link_sound "far"			"weapon/shot/smallarms/s3/d3/eng/Lewis_Gun/"}
	}
	("magazine" cut(1.0) show(3.0) override(overload) impulse({impulse up -0.01}))
}
{"stuff weapon mg08_15"						;// props added to MG 08/15
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/open_bolt_MG/reciprocating/"}
		{link_sound	"mid"			"weapon/shot/smallarms/s3/d2/GER/MG08/"}
		{link_sound	"far"			"weapon/shot/smallarms/s3/d3/GER/MG08/"}
	}
	("magazine" cut(1.0) show(3.0) override(overload) impulse({impulse up -0.01}))
}
{"stuff weapon mg37t_bipod"					;// props added to MG 37(t) on a tripod
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/open_bolt_mg/"}
		{link_sound	"mid"			"weapon/shot/smallarms/s3/d2/Shared/ZB37/"}
		{link_sound	"far"			"weapon/shot/smallarms/s3/d3/Shared/ZB37/"}
	}
}
{"stuff weapon mg131"						;// props added to MG 131
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/closed_bolt/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/GER/FG42/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/GER/FG42/"}
	}
}
{"stuff weapon ppd34"						;// props added to PPD-34
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/open_bolt_smg/type2/"}
		{link_sound "mid"		"weapon/shot/smallarms/s1/d2/rus/ppsh41/"}
		{link_sound "far"		"weapon/shot/smallarms/s1/d3/rus/ppsh41/"}
	}
	("magazine" cut(0.75) show(1.6) override(overload) impulse({impulse up -0.01}))
}
{"stuff weapon ppd34_38"					;// props added to PPD-34/38
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/open_bolt_smg/type2/"}
		{link_sound "mid"		"weapon/shot/smallarms/s1/d2/rus/ppsh41/"}
		{link_sound "far"		"weapon/shot/smallarms/s1/d3/rus/ppsh41/"}
	}
	("magazine" cut(1.20) show(2.15) override(overload) impulse({impulse up -0.01}))
}
{"stuff weapon ppd38"						;// props added to PPD-34/38
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/open_bolt_smg/type2/"}
		{link_sound "mid"		"weapon/shot/smallarms/s1/d2/rus/ppsh41/"}
		{link_sound "far"		"weapon/shot/smallarms/s1/d3/rus/ppsh41/"}
	}
	("magazine" cut(1.20) show(2.15) override(overload) impulse({impulse up -0.01}))
}
{"stuff weapon mosin_scope_silencer"		;// props added to silenced Mosin-Nagant with scope
	{on spawn
		{link_sound "open_bolt"		"weapon/reload/open_bolt/m9130/"}
		{link_sound "close_bolt"	"weapon/reload/close_bolt/m9130/"}
		{link_sound "action_recoil"	"weapon/action/recoil/bolt_action/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/shared/surpressed_rifle/"}
	}
}
{"stuff weapon dpm_bipod"					;// props added to DPM
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/open_bolt_mg/reciprocating/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/rus/dp27/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/rus/dp27/"}
	}
	("magazine" cut(0.75) show(2.5) override(overload) impulse({impulse up 0.3 forward 0.9 0.1 cy 1.5 0.25}))
}
{"stuff weapon mg099i"						;// props added to Breda M30
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/closed_bolt/"}
		{link_sound "mid"			"weapon/shot/smallarms/s3/d2/eng/Lewis_Gun/"}
		{link_sound "far"			"weapon/shot/smallarms/s3/d3/eng/Lewis_Gun/"}
	}
	{on "weapon_reload" overload
		{kill_delay "bolt_action"}
		{delay 0.75
			{ani_play "reload"}
		}
		{call "magazine_delay"}
		{play_sound "eject_clip"}
		{delay 0.075
			{stop_sound "action_recoil"}
		}
	}
}
{"stuff weapon vg_gustloff"					;// props added to VG Gustloff
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/closed_bolt/stg44/"}
		{link_sound "mid"		"weapon/shot/smallarms/s2/d2/ger/stg44/"}
		{link_sound "far"		"weapon/shot/smallarms/s2/d3/ger/stg44/"}
	}
	("magazine" cut(1.20) show(1.95) override(overload) impulse({impulse up -0.01}))
}
{"stuff weapon vg2"							;// props added to VG2
	{on spawn
		{link_sound "open_bolt"		"weapon/reload/open_bolt/m9130/"}
		{link_sound "close_bolt"	"weapon/reload/close_bolt/m9130/"}
		{link_sound "action_recoil"	"weapon/action/recoil/bolt_action/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/ger/k98k/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/ger/k98k/"}
	}
	("magazine" cut(1.20) show(1.95) override(overload) impulse({impulse up -0.01}))
}
{"stuff weapon mp3008"						;// props added to MP 3008
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/open_bolt_smg/"}
		{link_sound "mid"		"weapon/shot/smallarms/s1/d2/ger/mp40/"}
		{link_sound "far"		"weapon/shot/smallarms/s1/d3/ger/mp40/"}
	}
	("magazine" cut(0.75) show(1.6) override(overload) impulse({impulse up -0.01}))
}
{"stuff weapon lafette_mg34_belt_long"		;// props added to MG 34
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/open_bolt_mg/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/ger/mg34/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/ger/mg34/"}
	}
}
{"stuff weapon lafette_mg42_belt_long"		;// props added to MG 42
	{on spawn
		{link_sound "action_recoil"	"weapon/shot/smallarms/s3/recoil/ger/mg42/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/ger/mg42/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/ger/mg42/"}
	}
}
{"stuff weapon sword"						;// props added to swords
	{on "fire" overload
	}
}

;/***=========== MODDED WEAPONS END ===========***/