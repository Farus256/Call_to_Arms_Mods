;==============================================================================================================================
; Warrior250's Configurations for _reg_human_anm, for modularity and easier tracking. 
; This now acts as a hub for WAVE modules.
; Allows me to reduce the amount of duplicated files for each patches when they just don't really modify any values
; VANILLA

	; WAVE FILES
	(include "#WAVE.inc")
	(include "#WAVE_BOLTING.inc")	
	(include "HF_WAVE_MOTION.inc")
	(include "#WAVE_MOTION_Combat.inc")
	(include "#WAVE_WEAPONSTANCE.inc")


; UFB: restore HF 4 registrations absent from the WAVE-HF movement file.
{sequence "stand_fire_gun_down_1" 		{file "weapon\anim_smg_stand_shoot_01_down.anm"}	{speed 1}{smooth 0.1}}
{sequence "stand_fire_gun_up_1" 		{file "weapon\anim_smg_stand_shoot_01_up.anm"}		{resume}{speed 1}{smooth 0.1}}
{sequence "grenade_deflect" {smooth 0.2} {speed 1} {events {38 "deflect_release_pose"}}}
