{"generic"
	(include "\set\interaction_terrain\effects\effects-defines.inc")
	{on ground_hit
		{if material "flesh"
			{delay 0.01 {volumes disable bullet blast contact touch}}
			{delay 10 {volumes enable bullet blast contact touch}}
			{if rand 0.25 {start_sound "human/bm_explosion" use_position}}			
			{if min_speed 10
				{if rand 0.05 {call "blood_low"}}
					else
					{if min_speed 1
						{if rand 0.02 {call "blood_low"}}
					}
			}	
		}
	}
	{on bullet_hit
		{if not under_water
			{if material "flesh"
				{if stuff "bullet_fx size1"						;	Pistol Caliber
					{if dead {spawn "blood_small_air"} else {spawn "blood_small"}{spawn "ufb_blood_spot_small" random_orientation}}

				else stuff "bullet_fx size2 intermediate"		;	Intermediate Rifle Caliber
					{if dead {spawn "blood_small_air"} else {spawn "blood_small"}{spawn "ufb_blood_spot_small" random_orientation}}
					("sonic_crack_s1")

				else stuff "bullet_fx size2"					;	Rifle Caliber
					{if dead {spawn "blood_small_air"} else {spawn "blood_small"}{spawn "ufb_blood_spot_small" random_orientation}}
					("sonic_crack_s2")

				else stuff "bullet_fx size3"					;	Large Rifle Caliber
					{if dead {spawn "blood_small_air"} else {spawn "blood_small"}{spawn "ufb_blood_spot_small" random_orientation}}
					("sonic_crack_s3")

				else stuff "15mm he"
					{spawn "object_hit_fg_15mm"}
					{spawn "hit_he_fragments_15mm"}
					{if dead {spawn "blood_small_air"} else {spawn "blood_small"}{spawn "ufb_blood_spot_small" random_orientation}}
					{spawn "blood_big"}

				else stuff "auto size2 he"
					{spawn "object_hit_fg_auto_size2"}
					{spawn "hit_he_fragments_size1"}
					{if dead {spawn "blood_small_air"} else {spawn "blood_small"}{spawn "ufb_blood_spot_small" random_orientation}}
					{spawn "blood_big"}

				else stuff "auto he"
					{spawn "object_hit_fg_auto"}
					{spawn "hit_he_fragments_auto"}
					{if dead {spawn "blood_small_air"} else {spawn "blood_small"}{spawn "ufb_blood_spot_small" random_orientation}}
					{spawn "blood_big"}

				else stuff "auto aphe"			;// plane autocannon
					{spawn "object_hit_fg_auto"}
					{spawn "hit_he_fragments_size1"}
					{if dead {spawn "blood_small_air"} else {spawn "blood_small"}{spawn "ufb_blood_spot_small" random_orientation}}
					{spawn "blood_big"}
					{blastwave c4 0.504 r0 0.2 r1 0.5 position}		; needs blast because ammo is pierce
					{blastwave c4 0.36 r0 0.75 r1 3.06 position}

				else stuff "auto pierce"
					("sonic_crack_s4")
					{if dead {spawn "blood_small_air"} else {spawn "blood_small"}{spawn "ufb_blood_spot_small" random_orientation}}
					{spawn "blood_big"}	

				else stuff "auto"
					("sonic_crack_s4")
					{if dead {spawn "blood_small_air"} else {spawn "blood_small"}{spawn "ufb_blood_spot_small" random_orientation}}
					{spawn "blood_big"}

				else stuff "rifle_grenade_at"
					{spawn "ex_air_small_heat"}
					{spawn "hit_he_fragments_size1"}
					{if not dead {spawn "blood" random_orientation}}

				else stuff "rifle_grenade"
					{spawn "ex_air_small"}
					{spawn "hit_he_fragments_size1"}
					{if not dead {spawn "blood" random_orientation}}

				else stuff "bomb size3"
					{spawn "ex_air_he_size5"}
					{spawn "hit_he_fragments_size3"}
					{spawn "blood_big"}

				else stuff "big mortar"
					{spawn "blood_big"}
					{spawn "ex_air_he_size3"}
					{spawn "hit_he_fragments_size3"}

				else stuff "small mortar"
					{if not dead {spawn "blood" random_orientation}}
					{spawn "ex_air_norm"}
					{spawn "hit_he_fragments_size1"}

				else stuff "mortar"
					{if not dead {spawn "blood" random_orientation}}
					{spawn "ex_air_big"}
					{spawn "hit_he_fragments_size2"}

				else stuff "rocketlauncher heat_shell size1"
					{spawn "ex_heat"}
					{if dead {spawn "blood_small_air"} else {spawn "blood_small"}{spawn "ufb_blood_spot_small" random_orientation}}
					{spawn "blood_big"}
					{blastwave c4 2.5 r0 2 r1 3.5 position}		; needs blast because ammo is pierce

				else stuff "rocketlauncher heat_shell size2"
					{spawn "ex_heat"}
					{if dead {spawn "blood_small_air"} else {spawn "blood_small"}{spawn "ufb_blood_spot_small" random_orientation}}
					{spawn "blood_big"}
					{blastwave c4 2.5 r0 2 r1 3.5 position}		; needs blast because ammo is pierce

				else stuff "shell size1 all_he"
					{if not dead {spawn "blood" random_orientation}}
					{spawn "ex_air_he_size1"}
					{spawn "hit_he_fragments_size1"}

				else stuff "shell size2 all_he"
					{if not dead {spawn "blood" random_orientation}}
					{spawn "ex_air_he_size2"}
					{spawn "hit_he_fragments_size2"}

				else stuff "shell size3 all_he"
					{spawn "blood_big"}
					{spawn "ex_air_he_size3"}
					{spawn "hit_he_fragments_size3"}

				else stuff "shell size4 all_he"
					{spawn "blood_big"}
					{spawn "ex_air_he_size4"}
					{spawn "hit_he_fragments_size4"}

				else stuff "size4 std_ap"
					{if dead {spawn "blood_small_air"} else {spawn "blood_small"}{spawn "ufb_blood_spot_small" random_orientation}}
					{spawn "blood_big"}

				else stuff "size4"
					("explosion_HE_s4")
					{spawn "blood_big"}
					{spawn "ex_air_he_size4"}
					{spawn "hit_he_fragments_size4"}

				else stuff "shell size2_heat_shell"
					{spawn "ex_air_big_heat"}
					{spawn "blood_big"}

				else stuff "shell size3_heat_shell"
					{spawn "ex_air_heat_size3"}
					{spawn "blood_big"}	

				else stuff "shell size4_heat_shell"
					{spawn "ex_air_heat_size3"}
					{spawn "blood_big"}	

				else stuff "heat_shell"
					{spawn "ex_heat"}
					{if dead {spawn "blood_small_air"} else {spawn "blood_small"}{spawn "ufb_blood_spot_small" random_orientation}}
					{spawn "blood_big"}

				else stuff "shell all_he"
					{if not dead {spawn "blood" random_orientation}}
					{spawn "ex_air_big"}
					{spawn "hit_he_fragments_size2"}

				else stuff "shell"
					{if dead {spawn "blood_small_air"} else {spawn "blood_small"}{spawn "ufb_blood_spot_small" random_orientation}}
					{spawn "blood_big"}

				else stuff "flare marker"							; Special Flare ammo for mission scripts 
					;{spawn "flare_marker"}
					{bullet_detonate}

				else stuff "barrage mortar_81 he"					; Flare for off-map 81mm mortar
					{spawn "mortar_barrage_81_he_pointer"}
					{bullet_detonate}

				else stuff "barrage mortar_120 sm"					; Flare for off-map 120mm mortar
					{spawn "mortar_barrage_120_sm_pointer"}
					{bullet_detonate}

				else stuff "flare mrls"								; Flare for off-map BM-13 barrage
					{spawn "flare_artillery_mrls_bm13"}
					{bullet_detonate}

				else stuff "flare artillery"						; Flare for off-map Artillery
					{spawn "flare_artillery"}
					{bullet_detonate}

				else stuff "flare illumination"						; Special Flare ammo for mission scripts
					{spawn "flare" offset 0 0 1400}
					{bullet_detonate}

				else stuff "flare_usa mortar_60"					; Flare for off-map 60mm mortar
					{spawn "flare_mortar_60"}
					{bullet_detonate}

				else stuff "flare_usa mortar_81"					; Flare for off-map 81mm mortar
					{spawn "flare_mortar_81"}
					{bullet_detonate}

				else stuff "flare_usa artillery_105"				; Flare for off-map 105mm
					{spawn "flare_artillery_105"}
					{bullet_detonate}

				else stuff "flare_usa artillery_105_vt"				; Flare for off-map 105mm VT airburst
					{spawn "flare_artillery_105_vt"}
					{bullet_detonate}

				else stuff "flare_usa artillery_155"				; Flare for off-map 155mm
					{spawn "flare_artillery_155"}
					{bullet_detonate}

				else stuff "flare_usa artillery_155_vt"				; Flare for off-map 155mm VT airburst
					{spawn "flare_artillery_155_vt"}
					{bullet_detonate}

				else stuff "flare_usa artillery_203"				; Flare for off-map 203mm
					{spawn "flare_artillery_203"}
					{bullet_detonate}

				else stuff "flare_usa artillery_203_vt"				; Flare for off-map 203mm VT airburst
					{spawn "flare_artillery_203_vt"}
					{bullet_detonate}

				else stuff "flare_usa artillery_240"				; Flare for off-map 240mm VT airburst
					{spawn "flare_artillery_240"}
					{bullet_detonate}

				else stuff "flare_eng mortar_81"					; Flare for off-map 81mm mortar
					{spawn "flare_mortar_81"}
					{bullet_detonate}

				else stuff "flare_eng mortar_107"					; Flare for off-map 107 mortar
					{spawn "flare_mortar_107"}
					{bullet_detonate}

				else stuff "flare_eng artillery_88"					; Flare for off-map 88mm
					{spawn "flare_artillery_88"}
					{bullet_detonate}

				else stuff "flare_eng artillery_114"				; Flare for off-map 114mm
					{spawn "flare_artillery_114"}
					{bullet_detonate}

				else stuff "flare_eng artillery_127"				; Flare for off-map 127mm
					{spawn "flare_artillery_127"}
					{bullet_detonate}

				else stuff "flare_eng artillery_140"				; Flare for off-map 140mm
					{spawn "flare_artillery_140"}
					{bullet_detonate}

				else stuff "flare_eng artillery_152"				; Flare for off-map 152mm
					{spawn "flare_artillery_155"}
					{bullet_detonate}

				else stuff "flare_eng artillery_183"				; Flare for off-map 183mm
					{spawn "flare_artillery_180"}
					{bullet_detonate}

				else stuff "flare_eng artillery_203"				; Flare for off-map 203mm
					{spawn "flare_artillery_203"}
					{bullet_detonate}
				}

			else material "ground"
				(include "killzones.inc")
				{if stuff "grenade fire"							; Molotov Grenades
					{spawn "ex_molot_ground"}

				else stuff "grapple_fx"								; grapple hook
					{if rain
						{spawn "ex_ap_size2"}
					else season "winter"
						{spawn "ex_ap_size2"}
					else
						{spawn "ex_ap_size2_dust"}
					}

				else stuff "bullet_fx size1"						; Pistol/SMG Ammo
					{if rain
						{spawn "ex_bul_sm"}
					else season "winter"
						{spawn "ex_bul_sm"}
					else
						{spawn "ex_bul_sm_dust"}
					}

				else stuff "bullet_fx size2 intermediate"
					{if rain
						{spawn "ex_bul_big"}
					else season "winter"
						{spawn "ex_bul_big"}
					else
						{spawn "ex_bul_big_dust"}
					}
					("sonic_crack_s1")

				else stuff "bullet_fx size2"						; Rifle/MG ammo
					{if rain
						{spawn "ex_bul_big"}
					else season "winter"
						{spawn "ex_bul_big"}
					else
						{spawn "ex_bul_big_dust"}
					}
					("sonic_crack_s2")

				else stuff "bullet_fx size3 api"					; AT Rifle/HMG ammo
					{if rain
						{spawn "ex_bul_heavy"}
					else season "winter"
						{spawn "ex_bul_heavy"}
					else
						{spawn "ex_bul_heavy_dust"}
					}
					{spawn "ex_bul_heavy_ex"}
					("sonic_crack_s3")

				else stuff "bullet_fx size3"						; AT Rifle/HMG ammo
					{if rain
						{spawn "ex_bul_heavy"}
					else season "winter"
						{spawn "ex_bul_heavy"}
					else
						{spawn "ex_bul_heavy_dust"}
					}
					("sonic_crack_s3")

				else stuff "rifle_grenade_at"
					{spawn "ex_heat"}
					{spawn "hit_he_fragments_size1"}
					
				else stuff "rifle_grenade"
					{if rain
						{spawn "ex_he_size1_mud"}
					else
						{spawn "ex_grenade_size1"}
					}

				else stuff "mortar big ic"							; 120mm Mortar incendiary
					{spawn "ex_ic_120_ground"}
					{spawn "burn_piece" dir_velocity}
					{spawn "burned_spot_round2" scale 1.4 random_orientation}
					{fire radius 4 time 20 heating 0.25}

				else stuff "mortar big bomb size1"					; 200 Mortar shells
					{spawn "shockwave_sphere"}
					{spawn "ex_bomb_50kg"}

				else stuff "mortar big bomb size2"					; 170 Mortar shell
					{spawn "shockwave_sphere"}
					{spawn "ex_bomb_100kg"}

				else stuff "mortar big bomb size3"					; 300 Mortar shell
					{spawn "shockwave_sphere"}
					{spawn "ex_bomb_100kg"}

				else stuff "big mortar"
					{if rain
							{spawn "ex_he_size3_mud"}
					else
							{spawn "ex_he_size3"}
					}
					{spawn "hit_he_fragments_size3"}

				else stuff "small mortar"
					{if rain
							{spawn "ex_he_size1_mud"}
					else
							{spawn "ex_he_size1"}
					{spawn "hit_he_fragments_size1"}
					}

				else stuff "mortar"
					{if rain
							{spawn "ex_he_size2_mud"}
					else
							{spawn "ex_he_size2"}
					}
					{spawn "hit_he_fragments_size2"}

				else stuff "shell size2_heat_shell"					; 75-104mm cannon HEAT shells
					{if rain
						{spawn "ex_heat_size2_mud"}
					else
						{spawn "ex_heat_size2"}
					}

				else stuff "shell size3_heat_shell"					; 105-149mm cannon HEAT shells
					{if rain
						{spawn "ex_heat_size3_mud"}
					else
						{spawn "ex_heat_size3"}
					}
					{spawn "shockwave_sphere"}

				else stuff "shell size4_heat_shell"					; 150mm cannon HEAT shells
					{if rain
						{spawn "ex_heat_size3_mud"}
					else
						{spawn "ex_heat_size3"}
					}
					{spawn "shockwave_sphere"}

				else stuff "rocketlauncher heat_shell size1"		; 60mm AT Rockets
					{spawn "shockwave"}
					{spawn "ex_heat"}
					{spawn "grenade_at_shellhole" terrain_texmod}

				else stuff "rocketlauncher heat_shell size2"		; AT Rockets
					{spawn "shockwave"}
					{if rain
						{spawn "ex_heat_size2_mud"}
						{spawn "grenade_at_shellhole" texmod "mud"}
					else
						{spawn "ex_heat_size2"}
						{spawn "grenade_at_shellhole" terrain_texmod}
					}

				else stuff "heat_shell"								; All HEAT Shells / AT Rockets
					{spawn "ex_heat"}
					{spawn "hit_he_fragments_size1"}

				else stuff "auto 15mm he"							; 15mm Autocannon HE shells
					{spawn "ex_he_autocannon_15mm"}

				else stuff "auto size1 he"							; 20-25mm Autocannon HE shells
					{if rain
						{spawn "ex_he_autocannon_mud"}
					else
						{spawn "ex_he_autocannon"}
					}

				else stuff "auto size1"								; 20-25mm Autocannon AP shells
					{if rain	
						{spawn "ex_ap_autocannon_mud"}
					else
						{spawn "ex_ap_autocannon"}
					}

				else stuff "auto size2 he"							; 37-40mm Autocannon HE shells
					{if rain
						{spawn "ex_grenade_size1_mud"}
					else
						{spawn "ex_grenade_size1"}
					}

				else stuff "auto size2"								; 37-40mm Autocannon AP shells
					{if rain
						{spawn "ex_ap_size1_mud"}
					else
						{spawn "ex_ap_size1"}
					}

				else stuff "shell size1 all_he"							; 37-74mm cannon HE shells
					{if rain
							{spawn "ex_he_size1_mud"}
					else
							{spawn "ex_he_size1"}
					}
					{spawn "hit_he_fragments_size1"}

				else stuff "shell size1"							; 37-74mm cannon AP shells
					{if rain
						{spawn "ex_ap_size1_mud"}
					else
						{spawn "ex_ap_size1"}
					}

				else stuff "shell size2 all_he"							; 75-104mm cannon HE shells
					{if rain
							{spawn "ex_he_size2_mud"}
					else
							{spawn "ex_he_size2"}
					}
					{spawn "hit_he_fragments_size2"}

				else stuff "shell size2"							; 75-104mm cannon AP shells
					{if rain
						{spawn "ex_ap_size2_mud"}
					else
						{spawn "ex_ap_size2"}
					}

				else stuff "shell size3 all_he"							; 105-149mm cannon HE shells
					{if rain
							{spawn "ex_he_size3_mud"}
					else
							{spawn "ex_he_size3"}
					}
					{spawn "hit_he_fragments_size3"}

				else stuff "shell size3"							; 105-149mm cannon AP shells
					{if rain
						{spawn "ex_ap_size3_mud"}
					else
						{spawn "ex_ap_size3"}
					}

				else stuff "shell size4 all_he"							; 150-169mm cannon HE shells
					{spawn "ex_he_size4"}
					{spawn "hit_he_fragments_size4"}

				else stuff "shell size4"							; 150-169mm cannon AP shells
					{if rain
						{spawn "ex_ap_size4_mud"}
					else
						{spawn "ex_ap_size4"}
					}

				else stuff "shell size5"							; 170mm+ cannon HE shells
					{spawn "ex_he_size5"}
					
				else stuff "shell size6"							; 240mm+ cannon HE shells
					{spawn "ex_he_size6"}

				else stuff "shell wp_size1"							; 50mm WP shells
					{spawn "ex_wp_size1"}									; initial explosion fx
					{spawn "shell_smoke_wp_size1"}							; actual smoke and vision volumes

				else stuff "shell wp_size2"							; 75-95mm WP shells
					{spawn "ex_wp_size2"}									; initial explosion fx
					{spawn "shell_smoke_wp_size2"}							; actual smoke and vision volumes

				else stuff "shell wp_size3"							; Large WP shells
					{spawn "ex_wp_size3"}									; initial explosion fx
					{spawn "shell_smoke_wp_size3"}							; actual smoke and vision volumes
					
				else stuff "shell wp_size4"							; 100-149mm WP shells
					{spawn "ex_wp_size4"}									; initial explosion fx
					{spawn "shell_smoke_wp_size4"}							; actual smoke and vision volumes

				else stuff "shell smoke_size1"						; 50mm Smoke shells
					{spawn "ex_sm_size2"}									; initial explosion fx
					{spawn "shell_smoke_size2"}								; actual smoke and vision volumes
					
				else stuff "shell smoke_size2"						; 75-95mm Smoke shells
					{spawn "ex_sm_size2"}									; initial explosion fx
					{spawn "shell_smoke_size2"}								; actual smoke and vision volumes

				else stuff "shell smoke_size3"						; 100-149mm Smoke shells
					{spawn "ex_sm_size3"}									; initial explosion fx
					{spawn "shell_smoke_size3"}								; actual smoke and vision volumes
					
				else stuff "shell smoke_size4"						; 150+mm Smoke shells
					{spawn "ex_sm_size4"}									; initial explosion fx
					{spawn "shell_smoke_size4"}								; actual smoke and vision volumes

				else stuff "bomb size1"								; 50-60kg bombs / explosives
					{spawn "shockwave_sphere"}
					{spawn "ex_bomb_50kg"}

				else stuff "bomb size2"								; 100-200kg bombs / explosives
					{spawn "shockwave_sphere"}
					{spawn "ex_bomb_100kg"}

				else stuff "bomb size3"								; 250kg+ bomb
					{spawn "shockwave_sphere"}
					{spawn "ex_bomb_250kg"}

				else stuff "flare marker"							; Special Flare ammo for mission scripts
					{spawn "flare_marker"}
					{spawn "spheredust_small"}
					{bullet_detonate}

				else stuff "barrage mortar_81 he"					; Flare for off-map 81mm mortar
					{spawn "mortar_barrage_81_he_pointer"}
					{bullet_detonate}

				else stuff "barrage mortar_120 sm"					; Flare for off-map 120mm mortar
					{spawn "mortar_barrage_120_sm_pointer"}
					{bullet_detonate}

				else stuff "flare illumination"						; Special Flare ammo for mission scripts
					{spawn "flare" offset 0 0 1400}
					{bullet_detonate}

				else stuff "flare artillery"						; Flare for off-map Artillery
					{spawn "flare_artillery"}
					{spawn "spheredust_small"}
					{bullet_detonate}

				else stuff "flare mrls"								; Flare for off-map BM-13 barrage
					{spawn "flare_artillery_mrls_bm13"}
					{spawn "spheredust_small"}
					{bullet_detonate}

				else stuff "flare_usa mortar_60"					; Flare for off-map 60mm mortar
					{spawn "flare_mortar_60"}
					{spawn "spheredust_small"}
					{bullet_detonate}

				else stuff "flare_usa mortar_81"					; Flare for off-map 81mm mortar
					{spawn "flare_mortar_81"}
					{spawn "spheredust_small"}
					{bullet_detonate}

				else stuff "flare_usa artillery_105"				; Flare for off-map 105mm
					{spawn "flare_artillery_105"}
					{spawn "spheredust_small"}
					{bullet_detonate}

				else stuff "flare_usa artillery_105_vt"				; Flare for off-map 105mm VT airburst
					{spawn "flare_artillery_105_vt"}
					{spawn "spheredust_small"}
					{bullet_detonate}

				else stuff "flare_usa artillery_155"				; Flare for off-map 155mm
					{spawn "flare_artillery_155"}
					{spawn "spheredust_small"}
					{bullet_detonate}

				else stuff "flare_usa artillery_155_vt"				; Flare for off-map 155mm VT airburst
					{spawn "flare_artillery_155_vt"}
					{spawn "spheredust_small"}
					{bullet_detonate}

				else stuff "flare_usa artillery_203"				; Flare for off-map 203mm
					{spawn "flare_artillery_203"}
					{spawn "spheredust_small"}
					{bullet_detonate}

				else stuff "flare_usa artillery_203_vt"				; Flare for off-map 203mm VT airburst
					{spawn "flare_artillery_203_vt"}
					{spawn "spheredust_small"}
					{bullet_detonate}

				else stuff "flare_usa artillery_240"				; Flare for off-map 240mm airburst
					{spawn "flare_artillery_240"}
					{spawn "spheredust_small"}
					{bullet_detonate}

				else stuff "flare_eng mortar_81"					; Flare for off-map 81mm mortar
					{spawn "flare_mortar_81"}
					{spawn "spheredust_small"}
					{bullet_detonate}

				else stuff "flare_eng mortar_107"					; Flare for off-map 107 mortar
					{spawn "flare_mortar_107"}
					{spawn "spheredust_small"}
					{bullet_detonate}

				else stuff "flare_eng artillery_88"					; Flare for off-map 88mm
					{spawn "flare_artillery_88"}
					{spawn "spheredust_small"}
					{bullet_detonate}

				else stuff "flare_eng artillery_114"				; Flare for off-map 114mm
					{spawn "flare_artillery_114"}
					{spawn "spheredust_small"}
					{bullet_detonate}

				else stuff "flare_eng artillery_127"				; Flare for off-map 127mm
					{spawn "flare_artillery_127"}
					{spawn "spheredust_small"}
					{bullet_detonate}

				else stuff "flare_eng artillery_140"				; Flare for off-map 140mm
					{spawn "flare_artillery_140"}
					{spawn "spheredust_small"}
					{bullet_detonate}

				else stuff "flare_eng artillery_152"				; Flare for off-map 152mm
					{spawn "flare_artillery_155"}
					{spawn "spheredust_small"}
					{bullet_detonate}

				else stuff "flare_eng artillery_183"				; Flare for off-map 183mm
					{spawn "flare_artillery_180"}
					{spawn "spheredust_small"}
					{bullet_detonate}

				else stuff "flare_eng artillery_203"				; Flare for off-map 203mm
					{spawn "flare_artillery_203"}
					{spawn "spheredust_small"}
					{bullet_detonate}

				else stuff "glass ic"							; Ampulomet glass ball
					{spawn "ex_glass_ic_ground"}
					{spawn "burn_piece" dir_velocity}
					{spawn "burned_spot_round2" random_orientation}
					{fire radius 2 time 20 heating 0.25}
				}

			else material "steel"
				(include "killzones.inc")
				{if stuff "bullet_fx size1"						;	Pistol Caliber
					{spawn "metal_hit_bul"}

				else stuff "bullet_fx size2 intermediate"		;	Intermediate Rifle Caliber
					("sonic_crack_s1")
					{spawn "metal_hit_bul"}

				else stuff "bullet_fx size2 api"				;	Rifle Caliber - API
					("sonic_crack_s2")
					{spawn "metal_hit_bul_api"}

				else stuff "bullet_fx size2"					;	Rifle Caliber
					("sonic_crack_s2")
					{spawn "metal_hit_bul"}

				else stuff "bullet_fx size3 api"				;	Large Rifle Caliber - API
					("sonic_crack_s3")
					{spawn "metal_hit_bul_at"}

				else stuff "bullet_fx size3"					;	Large Rifle Caliber
					("sonic_crack_s3")
					{spawn "metal_hit_bul_heavy"}

				else stuff "rifle_grenade_at"
					{spawn "metal_hit_heat_riflegrenade"}
					{spawn "hit_he_fragments_size1"}

				else stuff "rifle_grenade"
					{spawn "metal_hit_fg_small"}
					{spawn "hit_he_fragments_size1"}

				else stuff "grapple_fx"							; grapple hook
					{spawn "metal_hit_br_small"}

				else stuff "bomb size3"
				 	{spawn "metal_hit_fg_massive"}

				else stuff "big mortar"
					{spawn "metal_hit_fg_big"}
					{spawn "hit_he_fragments_size3"}

				else stuff "small mortar"
					{spawn "metal_hit_fg_small"}
					{spawn "hit_he_fragments_size1"}

				else stuff "mortar"
					{spawn "metal_hit_fg"}
					{spawn "hit_he_fragments_size2"}

				else stuff "mortar_smoke"
					{spawn "metal_hit_br"}

				else stuff "rocketlauncher heat_shell size1"
					{spawn "metal_hit_heat_riflegrenade"}
					{blastwave c4 2.5 r0 2 r1 3.5 position}		; needs blast because ammo is pierce

				else stuff "rocketlauncher heat_shell size2"
					{spawn "metal_hit_br_small_bazooka"}
					{blastwave c4 2.5 r0 2 r1 3.5 position}		; needs blast because ammo is pierce

				else stuff "15mm he"
					{spawn "metal_hit_fg_15mm"}
					{spawn "hit_he_fragments_15mm"}

				else stuff "auto size1 he"
					{spawn "metal_hit_fg_auto"}
					{spawn "hit_he_fragments_auto"}

				else stuff "auto size2 he"
					{spawn "metal_hit_fg_small"}
					{spawn "hit_he_fragments_auto"}

				else stuff "auto aphe"			;// plane autocannon
					{spawn "metal_hit_fg_auto"}
					{blastwave c4 0.504 r0 0.2 r1 0.5 position}		; needs blast because ammo is pierce
					{blastwave c4 0.36 r0 0.75 r1 3.06 position}

				else stuff "auto"
					{spawn "metal_hit_bul_zenite"}

				else stuff "size2 heat_shell"
					{spawn "metal_hit_br_heat"}

				else stuff "size3 heat_shell"
					{spawn "metal_hit_br_big_heat"}

				else stuff "size4 heat_shell"
					{spawn "metal_hit_br_big_heat"}

				else stuff "heat_shell"
					{spawn "metal_hit_br_heat"}

				else stuff "size1 hv_ap"
					{spawn "metal_hit_br_small_apcr"}

				else stuff "size2 hv_ap"
					{spawn "metal_hit_br_apcr"}

				else stuff "size3 hv_ap"
					{spawn "metal_hit_br_big_apcr"}

				else stuff "size4 hv_ap"
					{spawn "metal_hit_br_big_apcr"}

				else stuff "shell size1 all_he"
					{spawn "metal_hit_fg_small"}
					{spawn "hit_he_fragments_size1"}

				else stuff "shell size2 all_he"
					{spawn "metal_hit_fg"}
					{spawn "hit_he_fragments_size2"}

				else stuff "shell size3 all_he"
					{spawn "metal_hit_fg_big"}
					{spawn "hit_he_fragments_size3"}

				else stuff "shell size4 all_he"
					{spawn "metal_hit_fg_massive"}
					{spawn "hit_he_fragments_size4"}

				else stuff "shell size5"
					{spawn "object_hit_fg_massive"}

				else stuff "shell size6"
					{spawn "object_hit_fg_massive"}

				else stuff "shell size1 hasfiller"
					{spawn "metal_hit_br_small"}

				else stuff "shell size2 hasfiller"
					{spawn "metal_hit_br"}

				else stuff "shell size3 hasfiller"
					{spawn "metal_hit_br_big"}

				else stuff "shell size4 hasfiller"
					{spawn "metal_hit_br_big"}

				else stuff "shell size1"
					{spawn "metal_hit_br_small"}

				else stuff "shell size2"
					{spawn "metal_hit_br"}

				else stuff "shell size3"
					{spawn "metal_hit_br_big"}

				else stuff "shell size4"
					{spawn "metal_hit_br_big"}

				else stuff "shell small"
					{spawn "metal_hit_br_small"}

				else stuff "shell zenite"
					{spawn "metal_hit_bul_zenite"}

				else material "steelball"
					{spawn "metal_hit_bul"}

				else stuff "flare marker"							; Special Flare ammo for mission scripts 
					;{spawn "flare_marker"}
					{spawn "metal_hit_bul"}
					{bullet_detonate}

				else stuff "barrage mortar_81 he"					; Flare for off-map 81mm mortar
					{spawn "mortar_barrage_81_he_pointer"}
					{bullet_detonate}

				else stuff "barrage mortar_120 sm"					; Flare for off-map 120mm mortar
					{spawn "mortar_barrage_120_sm_pointer"}
					{bullet_detonate}

				else stuff "flare illumination"						; Special Flare ammo for mission scripts
					{spawn "flare" offset 0 0 1400}
					{bullet_detonate}

				else stuff "flare artillery"						; Flare for off-map Artillery
					{spawn "flare_artillery"}
					{spawn "metal_hit_bul"}
					{bullet_detonate}
					
				else stuff "flare mrls"								; Flare for off-map BM-13 barrage
					{spawn "flare_artillery_mrls_bm13"}
					{spawn "metal_hit_bul"}
					{bullet_detonate}

				else stuff "flare_usa mortar_60"					; Flare for off-map 60mm mortar
					{spawn "flare_mortar_60"}
					{spawn "metal_hit_bul"}
					{bullet_detonate}

				else stuff "flare_usa mortar_81"					; Flare for off-map 81mm mortar
					{spawn "flare_mortar_81"}
					{spawn "metal_hit_bul"}
					{bullet_detonate}

				else stuff "flare_usa artillery_105"				; Flare for off-map 105mm
					{spawn "flare_artillery_105"}
					{spawn "metal_hit_bul"}
					{bullet_detonate}

				else stuff "flare_usa artillery_105_vt"				; Flare for off-map 105mm VT airburst
					{spawn "flare_artillery_105_vt"}
					{spawn "metal_hit_bul"}
					{bullet_detonate}

				else stuff "flare_usa artillery_155"				; Flare for off-map 155mm
					{spawn "flare_artillery_155"}
					{spawn "metal_hit_bul"}
					{bullet_detonate}

				else stuff "flare_usa artillery_155_vt"				; Flare for off-map 155mm VT airburst
					{spawn "flare_artillery_155_vt"}
					{spawn "metal_hit_bul"}
					{bullet_detonate}

				else stuff "flare_usa artillery_203"				; Flare for off-map 203mm
					{spawn "flare_artillery_203"}
					{spawn "metal_hit_bul"}
					{bullet_detonate}

				else stuff "flare_usa artillery_203_vt"				; Flare for off-map 203mm VT airburst
					{spawn "flare_artillery_203_vt"}
					{spawn "metal_hit_bul"}
					{bullet_detonate}

				else stuff "flare_usa artillery_240"				; Flare for off-map 240mm airburst
					{spawn "flare_artillery_240"}
					{spawn "metal_hit_bul"}
					{bullet_detonate}

				else stuff "flare_eng mortar_81"					; Flare for off-map 81mm mortar
					{spawn "flare_mortar_81"}
					{spawn "metal_hit_bul"}
					{bullet_detonate}

				else stuff "flare_eng mortar_107"					; Flare for off-map 107 mortar
					{spawn "flare_mortar_107"}
					{spawn "metal_hit_bul"}
					{bullet_detonate}

				else stuff "flare_eng artillery_88"					; Flare for off-map 88mm
					{spawn "flare_artillery_88"}
					{spawn "metal_hit_bul"}
					{bullet_detonate}

				else stuff "flare_eng artillery_114"				; Flare for off-map 114mm
					{spawn "flare_artillery_114"}
					{spawn "metal_hit_bul"}
					{bullet_detonate}

				else stuff "flare_eng artillery_127"				; Flare for off-map 127mm
					{spawn "flare_artillery_127"}
					{spawn "metal_hit_bul"}
					{bullet_detonate}

				else stuff "flare_eng artillery_140"				; Flare for off-map 140mm
					{spawn "flare_artillery_140"}
					{spawn "metal_hit_bul"}
					{bullet_detonate}

				else stuff "flare_eng artillery_152"				; Flare for off-map 152mm
					{spawn "flare_artillery_155"}
					{spawn "metal_hit_bul"}
					{bullet_detonate}

				else stuff "flare_eng artillery_183"				; Flare for off-map 183mm
					{spawn "flare_artillery_180"}
					{spawn "metal_hit_bul"}
					{bullet_detonate}

				else stuff "flare_eng artillery_203"				; Flare for off-map 203mm
					{spawn "flare_artillery_203"}
					{spawn "metal_hit_bul"}
					{bullet_detonate}
				}

			else material "wood"
				(include "killzones.inc")
				{if stuff "bullet_fx size1"						;	Pistol Caliber
					{spawn "wood_hit_bul"}

				else stuff "bullet_fx size2 intermediate"		;	Intermediate Rifle Caliber
					("sonic_crack_s1")
					{spawn "wood_hit_bul"}

				else stuff "bullet_fx size2"					;	Rifle Caliber
					("sonic_crack_s2")
					{spawn "wood_hit_bul"}

				else stuff "bullet_fx size3 api"				;	Large Rifle Caliber
					("sonic_crack_s3")
					{spawn "ex_air_sm"}
					{spawn "wood_hit_bul"}

				else stuff "bullet_fx size3"
					("sonic_crack_s3")
					{spawn "wood_hit_bul"}

				else stuff "rifle_grenade_at"
					{spawn "metal_hit_heat_riflegrenade"}
					{spawn "hit_he_fragments_size1"}

				else stuff "rifle_grenade"
					{spawn "wood_hit_fg_small"}
					{spawn "hit_he_fragments_size1"}

				else stuff "grapple_fx"							; grapple hook
					{spawn "wood_hit_br"}

				else stuff "bomb size3"
					{spawn "wood_hit_fg_massive"}

				else stuff "big mortar"
					{spawn "wood_hit_fg_big"}
					{spawn "hit_he_fragments_size3"}

				else stuff "small mortar"
					{spawn "wood_hit_fg_small"}
					{spawn "hit_he_fragments_size1"}

				else stuff "mortar"
					{spawn "wood_hit_fg"}
					{spawn "hit_he_fragments_size2"}

				else stuff "mortar_smoke"
					{spawn "mortar_smoke"}
					{spawn "ex_air_sm"}
					{spawn "wood_hit_bul"}

				else stuff "rocketlauncher heat_shell size2"
					{spawn "metal_hit_heat"}
					;{spawn "wood_hit_fg"}
					{blastwave c4 2.5 r0 2 r1 3.5 position}		; needs blast because ammo is pierce

				else stuff "rocketlauncher heat_shell"
					{spawn "metal_hit_heat_riflegrenade"}
					;{spawn "wood_hit_fg_small"}
					{blastwave c4 2.5 r0 2 r1 3.5 position}		; needs blast because ammo is pierce

				else stuff "shell size2_heat_shell"
					{spawn "metal_hit_heat"}
					;{spawn "wood_hit_fg"}

				else stuff "shell size3_heat_shell"
					{spawn "metal_hit_heat_big"}
					;{spawn "wood_hit_fg_big"}

				else stuff "shell size4_heat_shell"
					{spawn "metal_hit_heat_big"}
					;{spawn "wood_hit_fg_big"}

				else stuff "15mm he"
					{spawn "object_hit_fg_15mm"}
					{spawn "hit_he_fragments_15mm"}

				else stuff "auto he size1"
					{spawn "object_hit_fg_auto"}
					{spawn "hit_he_fragments_auto"}

				else stuff "auto he size2"
					{spawn "wood_hit_fg_small"}
					{spawn "hit_he_fragments_auto"}

				else stuff "auto"
					{spawn "wood_hit_br_auto"}

				else stuff "shell size1 all_he"
					{spawn "wood_hit_fg_small"}
					{spawn "hit_he_fragments_size1"}

				else stuff "shell size2 all_he"
					{spawn "wood_hit_fg"}
					{spawn "hit_he_fragments_size2"}

				else stuff "shell size3 all_he"
					{spawn "wood_hit_fg_big"}
					{spawn "hit_he_fragments_size3"}

				else stuff "shell size4 all_he"
					{spawn "wood_hit_fg_massive"}
					{spawn "hit_he_fragments_size4"}

				else stuff "shell size5"
					{spawn "shockwave_sphere"}
					{spawn "ex_he_size5"}

				else stuff "shell size6"
					{spawn "shockwave_sphere"}
					{spawn "ex_he_size6"}

				else stuff "shell small"
					{spawn "ex_air_sm"}
					{spawn "wood_hit_br"}

				else stuff "shell all_he"
					{spawn "ex_mort_big_wood"}

				else stuff "shell"
					{spawn "wood_hit_br"}

				else stuff "flare marker"							; Special Flare ammo for mission scripts 
					;{spawn "flare_marker"}
					{spawn "wood_hit_bul"}
					{bullet_detonate}

				else stuff "barrage mortar_81 he"					; Flare for off-map 81mm mortar
					{spawn "mortar_barrage_81_he_pointer"}
					{bullet_detonate}

				else stuff "barrage mortar_120 sm"					; Flare for off-map 120mm mortar
					{spawn "mortar_barrage_120_sm_pointer"}
					{bullet_detonate}

				else stuff "flare illumination"						; Special Flare ammo for mission scripts
					{spawn "flare" offset 0 0 1400}
					{bullet_detonate}

				else stuff "flare artillery"						; Flare for off-map Artillery
					{spawn "flare_artillery"}
					{spawn "wood_hit_bul"}
					{bullet_detonate}
	
				else stuff "flare mrls"								; Flare for off-map BM-13 barrage
					{spawn "flare_artillery_mrls_bm13"}
					{spawn "wood_hit_bul"}
					{bullet_detonate}

				else stuff "flare_usa mortar_60"					; Flare for off-map 60mm mortar
					{spawn "flare_mortar_60"}
					{spawn "wood_hit_bul"}
					{bullet_detonate}

				else stuff "flare_usa mortar_81"					; Flare for off-map 81mm mortar
					{spawn "flare_mortar_81"}
					{spawn "wood_hit_bul"}
					{bullet_detonate}

				else stuff "flare_usa artillery_105"				; Flare for off-map 105mm
					{spawn "flare_artillery_105"}
					{spawn "wood_hit_bul"}
					{bullet_detonate}

				else stuff "flare_usa artillery_105_vt"				; Flare for off-map 105mm VT airburst
					{spawn "flare_artillery_105_vt"}
					{spawn "wood_hit_bul"}
					{bullet_detonate}

				else stuff "flare_usa artillery_155"				; Flare for off-map 155mm
					{spawn "flare_artillery_155"}
					{spawn "wood_hit_bul"}
					{bullet_detonate}

				else stuff "flare_usa artillery_155_vt"				; Flare for off-map 155mm VT airburst
					{spawn "flare_artillery_155_vt"}
					{spawn "wood_hit_bul"}
					{bullet_detonate}

				else stuff "flare_usa artillery_203"				; Flare for off-map 203mm
					{spawn "flare_artillery_203"}
					{spawn "wood_hit_bul"}
					{bullet_detonate}

				else stuff "flare_usa artillery_203_vt"				; Flare for off-map 203mm VT airburst
					{spawn "flare_artillery_203_vt"}
					{spawn "wood_hit_bul"}
					{bullet_detonate}

				else stuff "flare_usa artillery_240"				; Flare for off-map 240mm airburst
					{spawn "flare_artillery_240"}
					{spawn "wood_hit_bul"}
					{bullet_detonate}

				else stuff "flare_eng mortar_81"					; Flare for off-map 81mm mortar
					{spawn "flare_mortar_81"}
					{spawn "wood_hit_bul"}
					{bullet_detonate}

				else stuff "flare_eng mortar_107"					; Flare for off-map 107 mortar
					{spawn "flare_mortar_107"}
					{spawn "wood_hit_bul"}
					{bullet_detonate}

				else stuff "flare_eng artillery_88"					; Flare for off-map 88mm
					{spawn "flare_artillery_88"}
					{spawn "wood_hit_bul"}
					{bullet_detonate}

				else stuff "flare_eng artillery_114"				; Flare for off-map 114mm
					{spawn "flare_artillery_114"}
					{spawn "wood_hit_bul"}
					{bullet_detonate}

				else stuff "flare_eng artillery_127"				; Flare for off-map 127mm
					{spawn "flare_artillery_127"}
					{spawn "wood_hit_bul"}
					{bullet_detonate}

				else stuff "flare_eng artillery_140"				; Flare for off-map 140mm
					{spawn "flare_artillery_140"}
					{spawn "wood_hit_bul"}
					{bullet_detonate}

				else stuff "flare_eng artillery_152"				; Flare for off-map 152mm
					{spawn "flare_artillery_155"}
					{spawn "wood_hit_bul"}
					{bullet_detonate}

				else stuff "flare_eng artillery_183"				; Flare for off-map 183mm
					{spawn "flare_artillery_180"}
					{spawn "wood_hit_bul"}
					{bullet_detonate}

				else stuff "flare_eng artillery_203"				; Flare for off-map 203mm
					{spawn "flare_artillery_203"}
					{spawn "wood_hit_bul"}
					{bullet_detonate}

				else stuff "flame"

				else
					{spawn "wood_hit_br"}
				}

			else material "concrete"
				(include "killzones.inc")
				{if stuff "bullet_fx size1"						;	Pistol Caliber
					{spawn "stone_hit_bul"}

				else stuff "bullet_fx size2 intermediate"		;	Intermediate Rifle Caliber
					("sonic_crack_s1")
					{spawn "stone_hit_bul"}

				else stuff "bullet_fx size2"					;	Rifle Caliber
					("sonic_crack_s2")
					{spawn "stone_hit_bul"}

				else stuff "bullet_fx size3 api"				;	Large Rifle Caliber
					("sonic_crack_s3")
					{spawn "stone_hit_bul"}

				else stuff "bullet_fx size3"
					("sonic_crack_s3")
					{spawn "stone_hit_bul"}

				else stuff "rifle_grenade_at"
					{spawn "stone_hit_heat_small"}
					{spawn "hit_he_fragments_size1"}

				else stuff "rifle_grenade"
					{spawn "stone_hit_fg_small"}
					{spawn "hit_he_fragments_size1"}

				else stuff "grapple_fx"							; grapple hook
					{spawn "stone_hit_br_small"}

				else stuff "bomb size3"
					{spawn "stone_hit_fg_massive"}

				else stuff "big mortar"
					{spawn "stone_hit_fg_big"}
					{spawn "hit_he_fragments_size3"}

				else stuff "small mortar"
					{spawn "stone_hit_fg_small"}
					{spawn "hit_he_fragments_size1"}

				else stuff "mortar"
					{spawn "stone_hit_fg"}
					{spawn "hit_he_fragments_size2"}

				else stuff "rocketlauncher heat_shell size2"
					{spawn "stone_hit_heat"}
					{spawn "hit_he_fragments_size2"}
					{blastwave c4 2.5 r0 2 r1 3.5 position}		; needs blast because ammo is pierce

				else stuff "rocketlauncher heat_shell"
					{spawn "stone_hit_heat_small"}
					{spawn "hit_he_fragments_size1"}
					{blastwave c4 2.5 r0 2 r1 3.5 position}		; needs blast because ammo is pierce

				else stuff "shell size2_heat_shell"
					{spawn "stone_hit_heat"}
					{spawn "hit_he_fragments_size2"}

				else stuff "shell size3_heat_shell"
					{spawn "stone_hit_heat_big"}
					{spawn "hit_he_fragments_size3"}

				else stuff "shell size4_heat_shell"	
					{spawn "stone_hit_heat_big"}
					{spawn "hit_he_fragments_size3"}

				else stuff "15mm he"
					{spawn "object_hit_fg_15mm"}
					{spawn "hit_he_fragments_15mm"}

				else stuff "auto size1 he"
					{spawn "object_hit_fg_auto"}
					{spawn "hit_he_fragments_auto"}

				else stuff "auto size2 he"
					{spawn "stone_hit_fg_small"}
					{spawn "hit_he_fragments_size1"}

				else stuff "auto"
					("sonic_crack_s4")	
					{spawn "stone_hit_br_auto"}

				else stuff "shell size1 all_he"
					{spawn "stone_hit_fg_small"}
					{spawn "hit_he_fragments_size1"}

				else stuff "shell size2 all_he"
					{spawn "stone_hit_fg"}
					{spawn "hit_he_fragments_size2"}

				else stuff "shell size3 all_he"
					{spawn "stone_hit_fg_big"}
					{spawn "hit_he_fragments_size3"}

				else stuff "shell size4 all_he"
					{spawn "stone_hit_fg_massive"}
					{spawn "hit_he_fragments_size4"}

				else stuff "shell size5"
					{spawn "object_hit_fg_massive"}

				else stuff "shell size6"
					{spawn "object_hit_fg_massive"}

				else stuff "shell hv_ap"
					{spawn "stone_hit_br"}

				else stuff "shell small"
					{spawn "stone_hit_br_small"}

				else stuff "flare marker"							; Special Flare ammo for mission scripts 
					;{spawn "flare_marker"}
					{spawn "stone_hit_bul"}
					{bullet_detonate}

				else stuff "barrage mortar_81 he"					; Flare for off-map 81mm mortar
					{spawn "mortar_barrage_81_he_pointer"}
					{bullet_detonate}

				else stuff "barrage mortar_120 sm"					; Flare for off-map 120mm mortar
					{spawn "mortar_barrage_120_sm_pointer"}
					{bullet_detonate}

				else stuff "flare illumination"						; Special Flare ammo for mission scripts
					{spawn "flare" offset 0 0 1400}
					{bullet_detonate}

				else stuff "flare artillery"						; Flare for off-map Artillery
					{spawn "flare_artillery"}
					{spawn "stone_hit_bul"}
					{bullet_detonate}

				else stuff "flare mrls"								; Flare for off-map BM-13 barrage
					{spawn "flare_artillery_mrls_bm13"}
					{spawn "stone_hit_bul"}
					{bullet_detonate}

				else stuff "flare_usa mortar_60"					; Flare for off-map 60mm mortar
					{spawn "flare_mortar_60"}
					{spawn "stone_hit_bul"}
					{bullet_detonate}

				else stuff "flare_usa mortar_81"					; Flare for off-map 81mm mortar
					{spawn "flare_mortar_81"}
					{spawn "stone_hit_bul"}
					{bullet_detonate}

				else stuff "flare_usa artillery_105"				; Flare for off-map 105mm
					{spawn "flare_artillery_105"}
					{spawn "stone_hit_bul"}
					{bullet_detonate}

				else stuff "flare_usa artillery_105_vt"				; Flare for off-map 105mm VT airburst
					{spawn "flare_artillery_105_vt"}
					{spawn "stone_hit_bul"}
					{bullet_detonate}

				else stuff "flare_usa artillery_155"				; Flare for off-map 155mm
					{spawn "flare_artillery_155"}
					{spawn "stone_hit_bul"}
					{bullet_detonate}

				else stuff "flare_usa artillery_155_vt"				; Flare for off-map 155mm VT airburst
					{spawn "flare_artillery_155_vt"}
					{spawn "stone_hit_bul"}
					{bullet_detonate}

				else stuff "flare_usa artillery_203"				; Flare for off-map 203mm
					{spawn "flare_artillery_203"}
					{spawn "stone_hit_bul"}
					{bullet_detonate}

				else stuff "flare_usa artillery_203_vt"				; Flare for off-map 203mm VT airburst
					{spawn "flare_artillery_203_vt"}
					{spawn "stone_hit_bul"}
					{bullet_detonate}

				else stuff "flare_usa artillery_240"				; Flare for off-map 240mm airburst
					{spawn "flare_artillery_240"}
					{spawn "stone_hit_bul"}
					{bullet_detonate}

				else stuff "flare_eng mortar_81"					; Flare for off-map 81mm mortar
					{spawn "flare_mortar_81"}
					{spawn "stone_hit_bul"}
					{bullet_detonate}

				else stuff "flare_eng mortar_107"					; Flare for off-map 107 mortar
					{spawn "flare_mortar_107"}
					{spawn "stone_hit_bul"}
					{bullet_detonate}

				else stuff "flare_eng artillery_88"					; Flare for off-map 88mm
					{spawn "flare_artillery_88"}
					{spawn "stone_hit_bul"}
					{bullet_detonate}

				else stuff "flare_eng artillery_114"				; Flare for off-map 114mm
					{spawn "flare_artillery_114"}
					{spawn "stone_hit_bul"}
					{bullet_detonate}

				else stuff "flare_eng artillery_127"				; Flare for off-map 127mm
					{spawn "flare_artillery_127"}
					{spawn "stone_hit_bul"}
					{bullet_detonate}

				else stuff "flare_eng artillery_140"				; Flare for off-map 140mm
					{spawn "flare_artillery_140"}
					{spawn "stone_hit_bul"}
					{bullet_detonate}

				else stuff "flare_eng artillery_152"				; Flare for off-map 152mm
					{spawn "flare_artillery_155"}
					{spawn "stone_hit_bul"}
					{bullet_detonate}

				else stuff "flare_eng artillery_183"				; Flare for off-map 183mm
					{spawn "flare_artillery_180"}
					{spawn "stone_hit_bul"}
					{bullet_detonate}

				else stuff "flare_eng artillery_203"				; Flare for off-map 203mm
					{spawn "flare_artillery_203"}
					{spawn "stone_hit_bul"}
					{bullet_detonate}

				else stuff "flame"

				else stuff "glass ic"

				else
					{spawn "stone_hit_br"}
				}

			else material "straw"
				(include "killzones.inc")
				{if stuff "bullet_fx size1"						;	Pistol Caliber
					{spawn "wood_hit_bul"}

				else stuff "bullet_fx size2 intermediate"		;	Intermediate Rifle Caliber
					("sonic_crack_s1")
					{spawn "wood_hit_bul"}

				else stuff "bullet_fx size2"					;	Rifle Caliber
					("sonic_crack_s2")
					{spawn "wood_hit_bul"}

				else stuff "bullet_fx size3 api"				;	Large Rifle Caliber
					("sonic_crack_s3")
					{spawn "ex_air_sm"}
					{spawn "wood_hit_bul"}

				else stuff "bullet_fx size3"
					("sonic_crack_s3")
					{spawn "wood_hit_bul"}

				else stuff "rifle_grenade_at"
					{spawn "metal_hit_heat_riflegrenade"}
					{spawn "hit_he_fragments_size1"}

				else stuff "rifle_grenade"
					{spawn "wood_hit_fg_small"}
					{spawn "hit_he_fragments_size1"}

				else stuff "grapple_fx"							; grapple hook
					{spawn "wood_hit_br"}

				else stuff "bomb size3"
					{spawn "wood_hit_fg_massive"}

				else stuff "big mortar"
					{spawn "wood_hit_fg_big"}
					{spawn "hit_he_fragments_size3"}

				else stuff "small mortar"
					{spawn "wood_hit_fg_small"}
					{spawn "hit_he_fragments_size1"}

				else stuff "mortar"
					{spawn "wood_hit_fg"}
					{spawn "hit_he_fragments_size2"}

				else stuff "mortar_smoke"
					{spawn "mortar_smoke"}
					{spawn "ex_air_sm"}
					{spawn "wood_hit_bul"}

				else stuff "rocketlauncher heat_shell size2"
					{spawn "metal_hit_heat"}
					{blastwave c4 2.5 r0 2 r1 3.5 position}		; needs blast because ammo is pierce

				else stuff "rocketlauncher heat_shell"
					{spawn "metal_hit_heat_riflegrenade"}
					{blastwave c4 2.5 r0 2 r1 3.5 position}		; needs blast because ammo is pierce

				else stuff "shell size2_heat_shell"
					{spawn "metal_hit_heat"}

				else stuff "shell size3_heat_shell"
					{spawn "metal_hit_heat_big"}

				else stuff "shell size4_heat_shell"
					{spawn "metal_hit_heat_big"}

				else stuff "15mm he"
					{spawn "object_hit_fg_15mm"}
					{spawn "hit_he_fragments_15mm"}

				else stuff "auto he size1"
					{spawn "object_hit_fg_auto"}
					{spawn "hit_he_fragments_auto"}

				else stuff "auto he size2"
					{spawn "wood_hit_fg_small"}
					{spawn "hit_he_fragments_auto"}

				else stuff "auto"
					{spawn "wood_hit_br_auto"}

				else stuff "shell size1 all_he"
					{spawn "wood_hit_fg_small"}
					{spawn "hit_he_fragments_size1"}

				else stuff "shell size2 all_he"
					{spawn "wood_hit_fg"}
					{spawn "hit_he_fragments_size2"}

				else stuff "shell size3 all_he"
					{spawn "wood_hit_fg_big"}
					{spawn "hit_he_fragments_size3"}

				else stuff "shell size4 all_he"
					{spawn "wood_hit_fg_massive"}
					{spawn "hit_he_fragments_size4"}

				else stuff "shell size5"
					{spawn "shockwave_sphere"}
					{spawn "ex_he_size5"}

				else stuff "shell size6"
					{spawn "shockwave_sphere"}
					{spawn "ex_he_size6"}

				else stuff "shell small"
					{spawn "ex_air_sm"}
					{spawn "wood_hit_br"}

				else stuff "shell all_he"
					{spawn "ex_mort_big_wood"}

				else stuff "shell"
					{spawn "wood_hit_br"}

				else stuff "flare marker"							; Special Flare ammo for mission scripts 
					;{spawn "flare_marker"}
					{spawn "wood_hit_bul"}
					{bullet_detonate}

				else stuff "barrage mortar_81 he"					; Flare for off-map 81mm mortar
					{spawn "mortar_barrage_81_he_pointer"}
					{bullet_detonate}

				else stuff "barrage mortar_120 sm"					; Flare for off-map 120mm mortar
					{spawn "mortar_barrage_120_sm_pointer"}
					{bullet_detonate}

				else stuff "flare illumination"						; Special Flare ammo for mission scripts
					{spawn "flare" offset 0 0 1400}
					{bullet_detonate}

				else stuff "flare artillery"						; Flare for off-map Artillery
					{spawn "flare_artillery"}
					{spawn "wood_hit_bul"}
					{bullet_detonate}

				else stuff "flare mrls"								; Flare for off-map BM-13 barrage
					{spawn "flare_artillery_mrls_bm13"}
					{spawn "wood_hit_bul"}
					{bullet_detonate}

				else stuff "flare_usa mortar_60"					; Flare for off-map 60mm mortar
					{spawn "flare_mortar_60"}
					{spawn "wood_hit_bul"}
					{bullet_detonate}

				else stuff "flare_usa mortar_81"					; Flare for off-map 81mm mortar
					{spawn "flare_mortar_81"}
					{spawn "wood_hit_bul"}
					{bullet_detonate}

				else stuff "flare_usa artillery_105"				; Flare for off-map 105mm
					{spawn "flare_artillery_105"}
					{spawn "wood_hit_bul"}
					{bullet_detonate}

				else stuff "flare_usa artillery_105_vt"				; Flare for off-map 105mm VT airburst
					{spawn "flare_artillery_105_vt"}
					{spawn "wood_hit_bul"}
					{bullet_detonate}

				else stuff "flare_usa artillery_155"				; Flare for off-map 155mm
					{spawn "flare_artillery_155"}
					{spawn "wood_hit_bul"}
					{bullet_detonate}

				else stuff "flare_usa artillery_155_vt"				; Flare for off-map 155mm VT airburst
					{spawn "flare_artillery_155_vt"}
					{spawn "wood_hit_bul"}
					{bullet_detonate}

				else stuff "flare_usa artillery_203"				; Flare for off-map 203mm
					{spawn "flare_artillery_203"}
					{spawn "wood_hit_bul"}
					{bullet_detonate}

				else stuff "flare_usa artillery_203_vt"				; Flare for off-map 203mm VT airburst
					{spawn "flare_artillery_203_vt"}
					{spawn "wood_hit_bul"}
					{bullet_detonate}

				else stuff "flare_usa artillery_240"				; Flare for off-map 240mm airburst
					{spawn "flare_artillery_240"}
					{spawn "wood_hit_bul"}
					{bullet_detonate}

				else stuff "flare_eng mortar_81"					; Flare for off-map 81mm mortar
					{spawn "flare_mortar_81"}
					{spawn "wood_hit_bul"}
					{bullet_detonate}

				else stuff "flare_eng mortar_107"					; Flare for off-map 107 mortar
					{spawn "flare_mortar_107"}
					{spawn "wood_hit_bul"}
					{bullet_detonate}

				else stuff "flare_eng artillery_88"					; Flare for off-map 88mm
					{spawn "flare_artillery_88"}
					{spawn "wood_hit_bul"}
					{bullet_detonate}

				else stuff "flare_eng artillery_114"				; Flare for off-map 114mm
					{spawn "flare_artillery_114"}
					{spawn "wood_hit_bul"}
					{bullet_detonate}

				else stuff "flare_eng artillery_127"				; Flare for off-map 127mm
					{spawn "flare_artillery_127"}
					{spawn "wood_hit_bul"}
					{bullet_detonate}

				else stuff "flare_eng artillery_140"				; Flare for off-map 140mm
					{spawn "flare_artillery_140"}
					{spawn "wood_hit_bul"}
					{bullet_detonate}

				else stuff "flare_eng artillery_152"				; Flare for off-map 152mm
					{spawn "flare_artillery_155"}
					{spawn "wood_hit_bul"}
					{bullet_detonate}

				else stuff "flare_eng artillery_183"				; Flare for off-map 183mm
					{spawn "flare_artillery_180"}
					{spawn "wood_hit_bul"}
					{bullet_detonate}

				else stuff "flare_eng artillery_203"				; Flare for off-map 203mm
					{spawn "flare_artillery_203"}
					{spawn "wood_hit_bul"}
					{bullet_detonate}

				else stuff "flame"

				else
					{spawn "wood_hit_br"}
				}

			else material "sand"
				(include "killzones.inc")
				{if stuff "bullet_fx size1"						;	Pistol Caliber
					{spawn "sand_hit_bul_sm"}

				else stuff "bullet_fx size2 intermediate"		;	Intermediate Rifle Caliber
					("sonic_crack_s1")
					{spawn "sand_hit_bul_sm"}

				else stuff "bullet_fx size2"					;	Rifle Caliber
					("sonic_crack_s2")
					{spawn "sand_hit_bul_sm"}

				else stuff "bullet_fx size3"					;	Large Rifle Caliber
					("sonic_crack_s3")
					{spawn "ex_bul_heavy"}

				else stuff "rocketlauncher heat_shell size1"
					{spawn "sand_hit_heat_small"}
					{blastwave c4 2.5 r0 2 r1 3.5 position}		; needs blast because ammo is pierce

				else stuff "rocketlauncher heat_shell size2"
					{spawn "sand_hit_heat"}
					{blastwave c4 2.5 r0 2 r1 3.5 position}		; needs blast because ammo is pierce

				else stuff "rifle_grenade_at"
					{spawn "sand_hit_heat_small"}
					{spawn "hit_he_fragments_size1"}

				else stuff "rifle_grenade"
					{spawn "sand_hit_fg_small"}
					{spawn "hit_he_fragments_size1"}

				else stuff "size2 heat_shell"
					{spawn "sand_hit_heat"}
					{spawn "hit_he_fragments_size2"}

				else stuff "size3 heat_shell"
					{spawn "sand_hit_heat_big"}
					{spawn "hit_he_fragments_size2"}

				else stuff "size4 heat_shell"
					{spawn "sand_hit_heat_big"}
					{spawn "hit_he_fragments_size2"}

				else stuff "big mortar"
					{spawn "sand_hit_fg_big"}
					{spawn "hit_he_fragments_size3"}

				else stuff "small mortar"
					{spawn "sand_hit_fg_small"}
					{spawn "hit_he_fragments_size1"}

				else stuff "mortar"
					{spawn "sand_hit_fg"}
					{spawn "hit_he_fragments_size2"}

				else stuff "15mm he"
					{spawn "object_hit_fg_15mm"}
					{spawn "hit_he_fragments_15mm"}

				else stuff "shell auto size1 he"
					{spawn "object_hit_fg_auto"}
					{spawn "hit_he_fragments_auto"}

				else stuff "shell auto size1"
					{spawn "sand_hit_zenite"}

				else stuff "shell auto size2 he"
					{spawn "sand_hit_fg_small"}
					{spawn "hit_he_fragments_auto"}

				else stuff "shell auto size2"
					{spawn "sand_hit_zenite_big"}

				else stuff "shell size1 all_he"
					{spawn "sand_hit_fg_small"}
					{spawn "hit_he_fragments_size1"}

				else stuff "shell size1"
					{spawn "sand_hit_shell_37_57"}

				else stuff "shell size2 all_he"
					{spawn "sand_hit_fg"}
					{spawn "hit_he_fragments_size2"}

				else stuff "shell size2"
					{spawn "sand_hit_shell_75_100"}

				else stuff "shell size3 all_he"
					{spawn "sand_hit_fg_big"}
					{spawn "hit_he_fragments_size3"}

				else stuff "shell size3"
					{spawn "sand_hit_shell_105_128"}

				else stuff "shell size4 all_he"
					{spawn "sand_hit_fg_massive"}
					{spawn "hit_he_fragments_size4"}

				else stuff "shell size4"
					{spawn "sand_hit_shell_152"}

				else stuff "shell size5"
					{spawn "ex_he_size5 he"}

				else stuff "shell size6"
					{spawn "ex_he_size6"}

				else stuff "flare marker"							; Special Flare ammo for mission scripts 
					;{spawn "flare_marker"}
					{spawn "sand_hit_bul_sm"}
					{bullet_detonate}

				else stuff "barrage mortar_81 he"					; Flare for off-map 81mm mortar
					{spawn "mortar_barrage_81_he_pointer"}
					{bullet_detonate}

				else stuff "barrage mortar_120 sm"					; Flare for off-map 120mm mortar
					{spawn "mortar_barrage_120_sm_pointer"}
					{bullet_detonate}

				else stuff "flare illumination"						; Special Flare ammo for mission scripts
					{spawn "flare" offset 0 0 1400}
					{bullet_detonate}

				else stuff "flare artillery"						; Flare for off-map Artillery
					{spawn "flare_artillery"}
					{spawn "sand_hit_bul_sm"}
					{bullet_detonate}

				else stuff "flare mrls"								; Flare for off-map BM-13 barrage
					{spawn "flare_artillery_mrls_bm13"}
					{spawn "sand_hit_bul_sm"}
					{bullet_detonate}

				else stuff "flare_usa mortar_60"					; Flare for off-map 60mm mortar
					{spawn "flare_mortar_60"}
					{spawn "sand_hit_bul_sm"}
					{bullet_detonate}

				else stuff "flare_usa mortar_81"					; Flare for off-map 81mm mortar
					{spawn "flare_mortar_81"}
					{spawn "sand_hit_bul_sm"}
					{bullet_detonate}

				else stuff "flare_usa artillery_105"				; Flare for off-map 105mm
					{spawn "flare_artillery_105"}
					{spawn "sand_hit_bul_sm"}
					{bullet_detonate}

				else stuff "flare_usa artillery_105_vt"				; Flare for off-map 105mm VT airburst
					{spawn "flare_artillery_105_vt"}
					{spawn "sand_hit_bul_sm"}
					{bullet_detonate}

				else stuff "flare_usa artillery_155"				; Flare for off-map 155mm
					{spawn "flare_artillery_155"}
					{spawn "sand_hit_bul_sm"}
					{bullet_detonate}

				else stuff "flare_usa artillery_155_vt"				; Flare for off-map 155mm VT airburst
					{spawn "flare_artillery_155_vt"}
					{spawn "sand_hit_bul_sm"}
					{bullet_detonate}

				else stuff "flare_usa artillery_203"				; Flare for off-map 203mm
					{spawn "flare_artillery_203"}
					{spawn "sand_hit_bul_sm"}
					{bullet_detonate}

				else stuff "flare_usa artillery_203_vt"				; Flare for off-map 203mm VT airburst
					{spawn "flare_artillery_203_vt"}
					{spawn "sand_hit_bul_sm"}
					{bullet_detonate}

				else stuff "flare_usa artillery_240"				; Flare for off-map 240mm airburst
					{spawn "flare_artillery_240"}
					{spawn "sand_hit_bul_sm"}
					{bullet_detonate}

				else stuff "flare_eng mortar_81"					; Flare for off-map 81mm mortar
					{spawn "flare_mortar_81"}
					{spawn "sand_hit_bul_sm"}
					{bullet_detonate}

				else stuff "flare_eng mortar_107"					; Flare for off-map 107 mortar
					{spawn "flare_mortar_107"}
					{spawn "sand_hit_bul_sm"}
					{bullet_detonate}

				else stuff "flare_eng artillery_88"					; Flare for off-map 88mm
					{spawn "flare_artillery_88"}
					{spawn "sand_hit_bul_sm"}
					{bullet_detonate}

				else stuff "flare_eng artillery_114"				; Flare for off-map 114mm
					{spawn "flare_artillery_114"}
					{spawn "sand_hit_bul_sm"}
					{bullet_detonate}

				else stuff "flare_eng artillery_127"				; Flare for off-map 127mm
					{spawn "flare_artillery_127"}
					{spawn "sand_hit_bul_sm"}
					{bullet_detonate}

				else stuff "flare_eng artillery_140"				; Flare for off-map 140mm
					{spawn "flare_artillery_140"}
					{spawn "sand_hit_bul_sm"}
					{bullet_detonate}

				else stuff "flare_eng artillery_152"				; Flare for off-map 152mm
					{spawn "flare_artillery_155"}
					{spawn "sand_hit_bul_sm"}
					{bullet_detonate}

				else stuff "flare_eng artillery_183"				; Flare for off-map 183mm
					{spawn "flare_artillery_180"}
					{spawn "sand_hit_bul_sm"}
					{bullet_detonate}

				else stuff "flare_eng artillery_203"				; Flare for off-map 203mm
					{spawn "flare_artillery_203"}
					{spawn "sand_hit_bul_sm"}
					{bullet_detonate}

				else stuff "flame"

				else
					{spawn "sand_hit_small"}
				}

			else material "glass"
				{if stuff "flame"

				else stuff "rifle_grenade_at"
					("explosion_HEAT_s1")
					{spawn "metal_hit_heat_riflegrenade"}
					{spawn "hit_he_fragments_size1"}

				else stuff "rifle_grenade"
					{spawn "metal_hit_fg_small"}
					{spawn "hit_he_fragments_size1"}

				else stuff "bomb size3"
				 	{spawn "metal_hit_fg_massive"}

				else stuff "big mortar"
					{spawn "metal_hit_fg_big"}
					{spawn "hit_he_fragments_size3"}

				else stuff "small mortar"
					{spawn "metal_hit_fg_small"}
					{spawn "hit_he_fragments_size1"}

				else stuff "mortar"
					{spawn "metal_hit_fg"}
					{spawn "hit_he_fragments_size2"}

				else stuff "rocketlauncher heat_shell size1"
					{spawn "metal_hit_br_small_bazooka"}
					{blastwave c4 2.5 r0 2 r1 3.5 position}		; needs blast because ammo is pierce

				else stuff "rocketlauncher heat_shell size2"
					{spawn "metal_hit_br_small_bazooka"}
					{blastwave c4 2.5 r0 2 r1 3.5 position}		; needs blast because ammo is pierce

				else stuff "15mm he"
					{spawn "metal_hit_fg_15mm"}
					{spawn "hit_he_fragments_15mm"}

				else stuff "auto size1 he"
					{spawn "metal_hit_fg_auto"}
					{spawn "hit_he_fragments_auto"}

				else stuff "auto size2 he"
					{spawn "metal_hit_fg_small"}
					{spawn "hit_he_fragments_auto"}

				else stuff "auto aphe"			;// plane autocannon
					{spawn "metal_hit_fg_auto"}
					{blastwave c4 0.504 r0 0.2 r1 0.5 position}		; needs blast because ammo is pierce
					{blastwave c4 0.36 r0 0.75 r1 3.06 position}

				else stuff "size2 heat_shell"
					{spawn "metal_hit_br_heat"}

				else stuff "size3 heat_shell"
					{spawn "metal_hit_br_big_heat"}

				else stuff "size4 heat_shell"
					{spawn "metal_hit_br_big_heat"}

				else stuff "shell size1 all_he"
					{spawn "metal_hit_fg_small"}
					{spawn "hit_he_fragments_size1"}

				else stuff "shell size2 all_he"
					{spawn "metal_hit_fg"}
					{spawn "hit_he_fragments_size2"}

				else stuff "shell size3 all_he"
					{spawn "metal_hit_fg_big"}
					{spawn "hit_he_fragments_size3"}

				else stuff "shell size4 all_he"
					{spawn "metal_hit_fg_massive"}
					{spawn "hit_he_fragments_size4"}

				else stuff "shell size5"
					{spawn "object_hit_fg_massive"}

				else stuff "shell size6"
					{spawn "object_hit_fg_massive"}

				else stuff "barrage mortar_81 he"					; Flare for off-map 81mm mortar
					{spawn "mortar_barrage_81_he_pointer"}
					{bullet_detonate}

				else stuff "barrage mortar_120 sm"					; Flare for off-map 120mm mortar
					{spawn "mortar_barrage_120_sm_pointer"}
					{bullet_detonate}

				else stuff "flare illumination"						; Special Flare ammo for mission scripts
					{spawn "flare" offset 0 0 1400}
					{bullet_detonate}

				else stuff "flare artillery"						; Flare for off-map Artillery
					{spawn "flare_artillery"}
					{spawn "glass_hit"}
					{bullet_detonate}

				else stuff "flare mrls"								; Flare for off-map BM-13 barrage
					{spawn "flare_artillery_mrls_bm13"}
					{spawn "glass_hit"}
					{bullet_detonate}

				else stuff "flare_usa mortar_60"					; Flare for off-map 60mm mortar
					{spawn "flare_mortar_60"}
					{spawn "glass_hit"}
					{bullet_detonate}

				else stuff "flare_usa mortar_81"					; Flare for off-map 81mm mortar
					{spawn "flare_mortar_81"}
					{spawn "glass_hit"}
					{bullet_detonate}

				else stuff "flare_usa artillery_105"				; Flare for off-map 105mm
					{spawn "flare_artillery_105"}
					{spawn "glass_hit"}
					{bullet_detonate}

				else stuff "flare_usa artillery_105_vt"				; Flare for off-map 105mm VT airburst
					{spawn "flare_artillery_105_vt"}
					{spawn "glass_hit"}
					{bullet_detonate}

				else stuff "flare_usa artillery_155"				; Flare for off-map 155mm
					{spawn "flare_artillery_155"}
					{spawn "glass_hit"}
					{bullet_detonate}

				else stuff "flare_usa artillery_155_vt"				; Flare for off-map 155mm VT airburst
					{spawn "flare_artillery_155_vt"}
					{spawn "glass_hit"}
					{bullet_detonate}

				else stuff "flare_usa artillery_203"				; Flare for off-map 203mm
					{spawn "flare_artillery_203"}
					{spawn "glass_hit"}
					{bullet_detonate}

				else stuff "flare_usa artillery_203_vt"				; Flare for off-map 203mm VT airburst
					{spawn "flare_artillery_203_vt"}
					{spawn "glass_hit"}
					{bullet_detonate}

				else stuff "flare_usa artillery_240"				; Flare for off-map 240mm airburst
					{spawn "flare_artillery_240"}
					{spawn "glass_hit"}
					{bullet_detonate}

				else stuff "flare_eng mortar_81"					; Flare for off-map 81mm mortar
					{spawn "flare_mortar_81"}
					{spawn "glass_hit"}
					{bullet_detonate}

				else stuff "flare_eng mortar_107"					; Flare for off-map 107 mortar
					{spawn "flare_mortar_107"}
					{spawn "glass_hit"}
					{bullet_detonate}

				else stuff "flare_eng artillery_88"					; Flare for off-map 88mm
					{spawn "flare_artillery_88"}
					{spawn "glass_hit"}
					{bullet_detonate}

				else stuff "flare_eng artillery_114"				; Flare for off-map 114mm
					{spawn "flare_artillery_114"}
					{spawn "glass_hit"}
					{bullet_detonate}

				else stuff "flare_eng artillery_127"				; Flare for off-map 127mm
					{spawn "flare_artillery_127"}
					{spawn "glass_hit"}
					{bullet_detonate}

				else stuff "flare_eng artillery_140"				; Flare for off-map 140mm
					{spawn "flare_artillery_140"}
					{spawn "glass_hit"}
					{bullet_detonate}

				else stuff "flare_eng artillery_152"				; Flare for off-map 152mm
					{spawn "flare_artillery_155"}
					{spawn "glass_hit"}
					{bullet_detonate}

				else stuff "flare_eng artillery_183"				; Flare for off-map 183mm
					{spawn "flare_artillery_180"}
					{spawn "glass_hit"}
					{bullet_detonate}

				else stuff "flare_eng artillery_203"				; Flare for off-map 203mm
					{spawn "flare_artillery_203"}
					{spawn "glass_hit"}
					{bullet_detonate}

				else
					{spawn "glass_hit"}
				}

			else material "ice"
				{if stuff "shell all_he"
					("explosion_HE_s4")
					("explosion_s2_dirt")
					{spawn "ex_mort_sm_snow"}

				else stuff "shell hv_ap"
					{spawn "snow_hit_small"}

				else stuff "flame"

				else stuff "barrage mortar_81 he"					; Flare for off-map 81mm mortar
					{spawn "mortar_barrage_81_he_pointer"}
					{bullet_detonate}

				else stuff "barrage mortar_120 sm"					; Flare for off-map 120mm mortar
					{spawn "mortar_barrage_120_sm_pointer"}
					{bullet_detonate}

				else stuff "flare illumination"						; Special Flare ammo for mission scripts
					{spawn "flare" offset 0 0 1400}
					{bullet_detonate}

				else stuff "flare artillery"						; Flare for off-map Artillery
					{spawn "flare_artillery"}
					{spawn "ex_bul_sm_snow"}
					{bullet_detonate}

				else stuff "flare mrls"								; Flare for off-map BM-13 barrage
					{spawn "flare_artillery_mrls_bm13"}
					{spawn "ex_bul_sm_snow"}
					{bullet_detonate}

				else stuff "flare_usa mortar_60"					; Flare for off-map 60mm mortar
					{spawn "flare_mortar_60"}
					{spawn "ex_bul_sm_snow"}
					{bullet_detonate}

				else stuff "flare_usa mortar_81"					; Flare for off-map 81mm mortar
					{spawn "flare_mortar_81"}
					{spawn "ex_bul_sm_snow"}
					{bullet_detonate}

				else stuff "flare_usa artillery_105"				; Flare for off-map 105mm
					{spawn "flare_artillery_105"}
					{spawn "ex_bul_sm_snow"}
					{bullet_detonate}

				else stuff "flare_usa artillery_105_vt"				; Flare for off-map 105mm VT airburst
					{spawn "flare_artillery_105_vt"}
					{spawn "ex_bul_sm_snow"}
					{bullet_detonate}

				else stuff "flare_usa artillery_155"				; Flare for off-map 155mm
					{spawn "flare_artillery_155"}
					{spawn "ex_bul_sm_snow"}
					{bullet_detonate}

				else stuff "flare_usa artillery_155_vt"				; Flare for off-map 155mm VT airburst
					{spawn "flare_artillery_155_vt"}
					{spawn "ex_bul_sm_snow"}
					{bullet_detonate}

				else stuff "flare_usa artillery_203"				; Flare for off-map 203mm
					{spawn "flare_artillery_203"}
					{spawn "ex_bul_sm_snow"}
					{bullet_detonate}

				else stuff "flare_usa artillery_203_vt"				; Flare for off-map 203mm VT airburst
					{spawn "flare_artillery_203_vt"}
					{spawn "ex_bul_sm_snow"}
					{bullet_detonate}

				else stuff "flare_usa artillery_240"				; Flare for off-map 240mm airburst
					{spawn "flare_artillery_240"}
					{spawn "ex_bul_sm_snow"}
					{bullet_detonate}

				else stuff "flare_eng mortar_81"					; Flare for off-map 81mm mortar
					{spawn "flare_mortar_81"}
					{spawn "ex_bul_sm_snow"}
					{bullet_detonate}

				else stuff "flare_eng mortar_107"					; Flare for off-map 107 mortar
					{spawn "flare_mortar_107"}
					{spawn "ex_bul_sm_snow"}
					{bullet_detonate}

				else stuff "flare_eng artillery_88"					; Flare for off-map 88mm
					{spawn "flare_artillery_88"}
					{spawn "ex_bul_sm_snow"}
					{bullet_detonate}

				else stuff "flare_eng artillery_114"				; Flare for off-map 114mm
					{spawn "flare_artillery_114"}
					{spawn "ex_bul_sm_snow"}
					{bullet_detonate}

				else stuff "flare_eng artillery_127"				; Flare for off-map 127mm
					{spawn "flare_artillery_127"}
					{spawn "ex_bul_sm_snow"}
					{bullet_detonate}

				else stuff "flare_eng artillery_140"				; Flare for off-map 140mm
					{spawn "flare_artillery_140"}
					{spawn "ex_bul_sm_snow"}
					{bullet_detonate}

				else stuff "flare_eng artillery_152"				; Flare for off-map 152mm
					{spawn "flare_artillery_155"}
					{spawn "ex_bul_sm_snow"}
					{bullet_detonate}

				else stuff "flare_eng artillery_183"				; Flare for off-map 183mm
					{spawn "flare_artillery_180"}
					{spawn "ex_bul_sm_snow"}
					{bullet_detonate}

				else stuff "flare_eng artillery_203"				; Flare for off-map 203mm
					{spawn "flare_artillery_203"}
					{spawn "ex_bul_sm_snow"}
					{bullet_detonate}

				else
					{spawn "snow_hit_small"}
				}

			else material "fabric"
				{if stuff "flame"

				else stuff "rifle_grenade_at"
					{spawn "metal_hit_heat_riflegrenade"}
					{spawn "hit_he_fragments_size1"}

				else stuff "rifle_grenade"
					{spawn "fabric_hit_bul"}

				else stuff "big mortar"
					{spawn "fabric_hit_bul"}

				else stuff "small mortar"
					{spawn "fabric_hit_bul"}

				else stuff "mortar"
					{spawn "fabric_hit_bul"}

				else stuff "rocketlauncher heat_shell size1"
					{spawn "metal_hit_br_small_bazooka"}
					{blastwave c4 2.5 r0 2 r1 3.5 position}		; needs blast because ammo is pierce

				else stuff "rocketlauncher heat_shell size2"
					{spawn "metal_hit_br_small_bazooka"}
					{blastwave c4 2.5 r0 2 r1 3.5 position}		; needs blast because ammo is pierce

				else stuff "15mm he"
					{spawn "fabric_hit_bul"}

				else stuff "auto size1 he"
					{spawn "fabric_hit_bul"}

				else stuff "auto size2 he"
					{spawn "fabric_hit_bul"}

				else stuff "auto aphe"
					{spawn "fabric_hit_bul"}

				else stuff "auto"
					{spawn "fabric_hit_bul"}

				else stuff "size1 heat_shell"
					{spawn "metal_hit_br_small_heat"}

				else stuff "size2 heat_shell"
					{spawn "metal_hit_br_heat"}

				else stuff "size3 heat_shell"
					{spawn "metal_hit_br_big_heat"}

				else stuff "size4 heat_shell"
					{spawn "metal_hit_br_big_heat"}

				else stuff "shell size1"
					{spawn "fabric_hit_bul"}

				else stuff "shell size2"
					{spawn "fabric_hit_bul"}

				else stuff "shell size3"
					{spawn "fabric_hit_bul"}

				else stuff "shell size4"
					{spawn "fabric_hit_bul"}

				else stuff "shell size5"
					{spawn "fabric_hit_bul"}

				else stuff "shell size6"
					{spawn "fabric_hit_bul"}

				else stuff "barrage mortar_81 he"					; Flare for off-map 81mm mortar
					{spawn "mortar_barrage_81_he_pointer"}
					{bullet_detonate}

				else stuff "barrage mortar_120 sm"					; Flare for off-map 120mm mortar
					{spawn "mortar_barrage_120_sm_pointer"}
					{bullet_detonate}

				else stuff "flare illumination"						; Special Flare ammo for mission scripts
					{spawn "flare" offset 0 0 1400}
					{bullet_detonate}

				else stuff "flare artillery"						; Flare for off-map Artillery
					{spawn "flare_artillery"}
					{bullet_detonate}

				else stuff "flare mrls"								; Flare for off-map BM-13 barrage
					{spawn "flare_artillery_mrls_bm13"}
					{bullet_detonate}

				else stuff "flare_usa mortar_60"					; Flare for off-map 60mm mortar
					{spawn "flare_mortar_60"}
					{bullet_detonate}

				else stuff "flare_usa mortar_81"					; Flare for off-map 81mm mortar
					{spawn "flare_mortar_81"}
					{bullet_detonate}

				else stuff "flare_usa artillery_105"				; Flare for off-map 105mm
					{spawn "flare_artillery_105"}
					{bullet_detonate}

				else stuff "flare_usa artillery_105_vt"				; Flare for off-map 105mm VT airburst
					{spawn "flare_artillery_105_vt"}
					{bullet_detonate}

				else stuff "flare_usa artillery_155"				; Flare for off-map 155mm
					{spawn "flare_artillery_155"}
					{bullet_detonate}

				else stuff "flare_usa artillery_155_vt"				; Flare for off-map 155mm VT airburst
					{spawn "flare_artillery_155_vt"}
					{bullet_detonate}

				else stuff "flare_usa artillery_203"				; Flare for off-map 203mm
					{spawn "flare_artillery_203"}
					{bullet_detonate}

				else stuff "flare_usa artillery_203_vt"				; Flare for off-map 203mm VT airburst
					{spawn "flare_artillery_203_vt"}
					{bullet_detonate}

				else stuff "flare_usa artillery_240"				; Flare for off-map 240mm airburst
					{spawn "flare_artillery_240"}
					{bullet_detonate}

				else stuff "flare_eng mortar_81"					; Flare for off-map 81mm mortar
					{spawn "flare_mortar_81"}
					{bullet_detonate}

				else stuff "flare_eng mortar_107"					; Flare for off-map 107 mortar
					{spawn "flare_mortar_107"}
					{bullet_detonate}

				else stuff "flare_eng artillery_88"					; Flare for off-map 88mm
					{spawn "flare_artillery_88"}
					{bullet_detonate}

				else stuff "flare_eng artillery_114"				; Flare for off-map 114mm
					{spawn "flare_artillery_114"}
					{bullet_detonate}

				else stuff "flare_eng artillery_127"				; Flare for off-map 127mm
					{spawn "flare_artillery_127"}
					{bullet_detonate}

				else stuff "flare_eng artillery_140"				; Flare for off-map 140mm
					{spawn "flare_artillery_140"}
					{bullet_detonate}

				else stuff "flare_eng artillery_152"				; Flare for off-map 152mm
					{spawn "flare_artillery_155"}
					{bullet_detonate}

				else stuff "flare_eng artillery_183"				; Flare for off-map 183mm
					{spawn "flare_artillery_180"}
					{bullet_detonate}

				else stuff "flare_eng artillery_203"				; Flare for off-map 203mm
					{spawn "flare_artillery_203"}
					{bullet_detonate}

				else
					{spawn "fabric_hit_bul"}
				}
			}
		}
	}

	{on contact
		{if not under_water
			{if material "steel"
				{if stuff "mortar"
					{play_sound "reverb"}

				else stuff "size4"
					{play_sound "reverb"}

				else stuff "shell small he"
					{play_sound "reverb"}

				else stuff "shell small"
					{play_sound "reverb"}

				else stuff "shell hv_ap"
					{play_sound "reverb"}

				else stuff "shell all_he"
					{play_sound "reverb"}

				else stuff "shell"

				}

			else material "wood"
				{if stuff "mortar"
					{play_sound "reverb"}

				else stuff "shell hv_ap"
					{play_sound "reverb"}

				else stuff "shell all_he"
					{play_sound "reverb"}
				}

			else material "concrete"
				{if stuff "big shell all_he"

				else stuff "shell hv_ap"
					{play_sound "reverb3"}

				else stuff "shell all_he"
					{play_sound "reverb3"}
				}
			}
		}
	}
	
	{on "blood"	;// UFB: pool spawns removed (clipped into terrain on gibs)
	}
	
	{on "blood_low"	;// UFB: pool spawns removed (clipped into terrain on gibs)
	}	
	
}