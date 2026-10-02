Purchases["conquest.ger"] = {
	{Repeat = 0, --infinite
		Units = {
			---[====[
			-- Error detect vehicle
				---[[
				{availability = "0.9", base = { "Infantry", "Single" }, class = {}, grade = "Grade2", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "detect_error_vehicle"},
				---]]

			-- Bonus
				-- buggy af
				---[[
				--{availability = "1.4", base = { "Tank" }, class = { "Medium" }, grade = "Grade2", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "ai_bonus_500"},
				--{availability = "1.4", base = { "Tank" }, class = { "Medium" }, grade = "Grade2", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "ai_bonus_750"},
				--{availability = "1.5", base = { "Tank" }, class = { "Medium" }, grade = "Grade2", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "ai_bonus_1000"},
				--{availability = "1.5", base = { "Tank" }, class = { "Medium" }, grade = "Grade2", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "ai_bonus_1250"},
				--{availability = "1.6", base = { "Tank" }, class = { "Medium" }, grade = "Grade2", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "ai_bonus_2000"},
				---]]
				
			-- Infantry
				---[[
													--Earlywar (1939-1941)
				--T1
				{availability = "1.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade1", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_grenzwacht_con(ger)"},
				{availability = "1.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade1", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_landwehr_con(ger)"},
				{availability = "1.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade1", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_lw_sicherung_early_con(ger)"},
				{availability = "1.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade1", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_km_sicherung_early_con(ger)"},
				--T2
				{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_waffen_rifle_early_con(ger)"},
				{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_pz_rifle_early_con(ger)"},
				{availability = "1.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Flexible" }, roles = { "Line" }, effects = {}, mobility = { "Mechanized" }, unit = "squad_pz_rifle_armor_early_con"}, --vehicle
				{availability = "1.2", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_regular_early_con(ger)"},
				{availability = "1.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Flexible" }, roles = { "Line" }, effects = {}, mobility = { "Motorized" }, unit = "squad_regular_motor_early_con"}, --vehicle
				{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_pionier_early_con(ger)"},
				{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_pz_pio_rifle_early_con(ger)"},
				{availability = "1.6", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_pz_pio_early_con"}, --vehicle
				{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade1", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_lw_schutze_early_con(ger)"},
				--T2+
				{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_regular_early_vet_con(ger)"},
				{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Offensive" }, roles = { "Assault" }, effects = { "VsInfantry" }, unit = "squad_stoss_early_con(ger)"},
				--T3
				{availability = "1.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade3", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_1st_cav_con(ger)"},
				{availability = "1.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade3", posture = { "Offensive" }, roles = { "Recon" }, effects = {}, unit = "squad_1st_cav_recon_con(ger)"},
				{availability = "1.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade3", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_heer_luftlande_con(ger)"},		
				{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade3", posture = { "Offensive" }, roles = { "Assault" }, effects = { "VsInfantry" }, unit = "squad_kriegsmarine_stoss_con(ger)"},
				{availability = "1.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade3", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_kustenjager_con(ger)"},
				--T3+
				{availability = "1.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade3", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_gd_early_con(ger)"},
				{availability = "1.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade3", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_gd_pio_early_con(ger)"},
				--T4
				{availability = "1.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade4", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_gebirgsjaeger_early_con(ger)"},
				{availability = "1.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade4", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_gebirgsjaeger_pio_early_con(ger)"},
				{availability = "1.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade4", posture = { "Offensive" }, roles = { "Recon" }, effects = {}, unit = "squad_gebirgsjaeger_recon_early_con(ger)"},
				{availability = "1.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade4", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_fallschirmjaeger_early_con(ger)"},
				{availability = "1.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade4", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_fallschirm_pio_early_con(ger)"},
				{availability = "1.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade4", posture = { "Offensive" }, roles = { "Recon" }, effects = {}, unit = "squad_fallschirm_recon_early_con(ger)"},
				{availability = "1.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade4", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_lw_luftlande_con(ger)"},
				{availability = "1.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade4", posture = { "Offensive" }, roles = { "Recon" }, effects = {}, unit = "squad_frontaufklarungs_con(ger)"},

													--Midwar (1941-1943)
				--T1
				{availability = "1.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade1", posture = { "Defensive" }, roles = { "Line" }, effects = {}, unit = "squad_osttruppen_con(ger)"},
				{availability = "1.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade1", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_strafbatallion_con(ger)"},
				{availability = "1.6", base = { "Infantry", "Squad" }, class = {}, grade = "Grade1", posture = { "Offensive" }, roles = { "Recon" }, effects = {}, unit = "squad_lvf_fusilier_con(fra)"},
				--T2
				{availability = "1.6", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_lvf_eclaireur_con(fra)"},
				{availability = "1.6", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_lvf_sapeur_con(fra)"},
				{availability = "1.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_lw_jag_mid_con(ger)"},
				{availability = "1.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_ostjager_con(ger)"},
				{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_pz_rifle_mid_con(ger)"},
				{availability = "1.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Offensive" }, roles = { "Recon" }, effects = {}, unit = "squad_pz_recon_mid_con(ger)"},
				{availability = "1.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Offensive" }, roles = { "Recon" }, effects = {}, mobility = { "Mechanized" }, unit = "squad_pz_recon_armor_mid_con"}, --vehicle
				{availability = "1.3", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_regular_con(ger)"},
				{availability = "1.6", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Flexible" }, roles = { "Line" }, effects = {}, mobility = { "Motorized" }, unit = "squad_regular_motor_con"}, --vehicle
				{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Defensive" }, roles = { "Line" }, effects = {}, unit = "squad_sicherung_con(ger)"},
				{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Offensive" }, roles = { "Recon" }, effects = {}, unit = "squad_recon_con(ger)"},
				{availability = "1.6", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Offensive" }, roles = { "Recon" }, effects = {}, mobility = { "Motorized" }, unit = "squad_recon_motor_con"}, --vehicle
				{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_pionier_con(ger)"},
				{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_pz_pio_rifle_mid_con(ger)"},
				{availability = "1.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Flexible" }, roles = { "Line" }, effects = {}, mobility = { "Mechanized" }, unit = "squad_pz_pio_con"}, --vehicle
				--T2+
				{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade3", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_regular_vet_con(ger)"},
				{availability = "1.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Offensive" }, roles = { "Assault" }, effects = { "VsInfantry" }, unit = "squad_stoss_mid_con(ger)"},
				{availability = "1.6", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Offensive" }, roles = { "Recon" }, effects = {}, unit = "squad_vet_waffen_recon_mid_con(ger)"},
				{availability = "1.6", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_vet_waffen_rifle_mid_con(ger)"},
				{availability = "1.6", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_vet_waffen_pio_mid_con(ger)"},
				--T3
				{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade3", posture = { "Flexible" }, roles = { "Line" }, effects = { "VsInfantry" }, unit = "squad_jaeger_con(ger)"},
				{availability = "1.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade3", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_blau_schutze_con(ger)"},
				{availability = "1.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade3", posture = { "Offensive" }, roles = { "Recon" }, effects = {}, unit = "squad_blau_recon_con(ger)"},
				{availability = "1.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade3", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_blau_pionier_con(ger)"},
				--T3+
				{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade3", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_gd_mid_con(ger)"},
				{availability = "1.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade3", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_gd_pio_mid_con(ger)"},
				{availability = "1.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade4", posture = { "Flexible" }, roles = { "Line" }, effects = {}, mobility = { "Motorized" }, unit = "squad_gd_motor_con"}, --vehicle
				{availability = "1.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade3", posture = { "Flexible" }, roles = { "Line" }, effects = {}, mobility = { "Mechanized" }, unit = "squad_gd_armor_con"}, --vehicle
				{availability = "1.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade3", posture = { "Flexible" }, roles = { "Line" }, effects = {}, mobility = { "Motorized" }, unit = "squad_gd_pio_motor_con"}, --vehicle
				{availability = "1.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade3", posture = { "Flexible" }, roles = { "Line" }, effects = {}, mobility = { "Mechanized" }, unit = "squad_gd_pio_armor_con"}, --vehicle
				--T4
				{availability = "1.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade4", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_gebirgsjaeger_con(ger)"},
				{availability = "1.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade4", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_gebirgsjaeger_pio_con(ger)"},
				{availability = "1.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade4", posture = { "Offensive" }, roles = { "Recon" }, effects = {}, unit = "squad_gebirgsjaeger_recon_con(ger)"},
				{availability = "1.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade4", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_gebirgsjaeger_reiter_con(ger)"},
				{availability = "1.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade4", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_fallschirmjaeger_con(ger)"},
				{availability = "1.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade4", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_fallschirm_pio_con(ger)"},
				{availability = "1.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade4", posture = { "Offensive" }, roles = { "Recon" }, effects = {}, unit = "squad_fallschirm_recon_con(ger)"},
				{availability = "1.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade4", posture = { "Offensive" }, roles = { "Assault" }, effects = {}, unit = "squad_brandenburger_con(ger)"},
				{availability = "1.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade4", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_gebirgsjaeger_con(ger)"},
				{availability = "1.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade4", posture = { "Flexible" }, roles = { "Line" }, effects = {}, mobility = { "Motorized" }, unit = "squad_fallschirmjaeger_motor_con"},
				{availability = "1.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade4", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_2nd_fallschirmjaeger_mid_con(ger)"},


													--Latewar (1943-1945)
				--T1
				{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade1", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_km_landes_late_con(ger)"},
				{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade1", posture = { "Offensive" }, roles = { "Assault" }, effects = { "VsInfantry" }, unit = "squad_volkssturm_stab1_con(ger)"},
				{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade1", posture = { "Offensive" }, roles = { "Assault" }, effects = { "VsInfantry" }, unit = "squad_volkssturm_stab2_con(ger)"},
				{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade1", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_lw_landes_con(ger)"},
				{availability = "1.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade1", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_29th_waffen_ersatz_con(ger)"},
				--T1+
				{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade1", posture = { "Offensive" }, roles = { "Assault" }, effects = { "VsInfantry" }, unit = "squad_volkssturm_stand_con(ger)"},
				{availability = "1.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade1", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_hg_ersatz_con(ger)"},
				--T2
				{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade1", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_km_fus_late_con(ger)"},
				{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade1", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_km_gren_late_con(ger)"},
				{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade1", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_km_pio_late_con(ger)"},
				{availability = "1.3", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Offensive" }, roles = { "Recon" }, effects = {}, unit = "squad_pz_recon_late_con(ger)"},
				{availability = "1.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Offensive" }, roles = { "Recon" }, effects = {}, mobility = { "Mechanized" }, unit = "squad_pz_recon_armor_late_con"}, --vehicle
				{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_pionier_late_con(ger)"},
				{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_pz_pio_rifle_late_con(ger)"},
				{availability = "1.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Flexible" }, roles = { "Line" }, effects = {}, mobility = { "Mechanized" }, unit = "squad_pz_pio_late_con"}, --vehicle
				{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_lw_jaeger_con(ger)"},
				{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_lw_pio_con(ger)"},
				{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Offensive" }, roles = { "Recon" }, effects = {}, unit = "squad_lw_recon_con(ger)"},
				{availability = "1.1", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_grenadier_con(ger)"},
				{availability = "1.1", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Offensive" }, roles = { "Assault" }, effects = { "VsInfantry" }, unit = "squad_sturmgren_con(ger)"},
				{availability = "1.1", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Offensive" }, roles = { "Assault" }, effects = { "VsInfantry" }, unit = "squad_sturmgren_heavy_con(ger)"},
				{availability = "1.1", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_volksg_con(ger)"},
				{availability = "1.1", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Offensive" }, roles = { "Assault" }, effects = { "VsInfantry" }, unit = "squad_volksg_sturm_con(ger)"},
				{availability = "1.2", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Offensive" }, roles = { "Assault" }, effects = { "VsInfantry" }, unit = "squad_volksg_heavy_con(ger)"},
				{availability = "1.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Flexible" }, roles = { "Line" }, effects = {}, mobility = { "Motorized" }, unit = "squad_pzgren_motor_con"}, --vehicle
				{availability = "1.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Flexible" }, roles = { "Line" }, effects = {}, mobility = { "Mechanized" }, unit = "squad_pzgren_armor_con"}, --vehicle
				{availability = "1.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Offensive" }, roles = { "Assault" }, effects = { "VsInfantry" }, mobility = { "Mechanized" }, unit = "squad_sturm_pzgren_armor_con"}, --vehicle
				{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_waffen_pzgren_late_con(ger)"},
				{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Offensive" }, roles = { "Recon" }, effects = {}, unit = "squad_waffen_pz_recon_late_con(ger)"},
				{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_waffen_pz_pio_late_con(ger)"},	
				{availability = "1.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_29th_waffen_fus_con(ger)"},
				{availability = "1.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_29th_waffen_gren_con_1(ger)"},
				{availability = "1.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_29th_waffen_gren_con_2(ger)"},
				{availability = "1.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_29th_waffen_pio_con(ger)"},

				--T2+
				{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade1", posture = { "Offensive" }, roles = { "Assault" }, effects = { "VsInfantry" }, unit = "squad_km_sturmgren_late_con(ger)"},
				{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Offensive" }, roles = { "Assault" }, effects = { "VsInfantry" }, unit = "squad_stoss_late_con(ger)"},
				{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_waffen_vet_pzgren_late_con(ger)"},
				--T3
				{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade3", posture = { "Offensive" }, roles = { "Assault" }, effects = { "VsInfantry" }, unit = "squad_sturmjager_con(ger)"},
				{availability = "1.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade3", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_waffen_karst_late_con(ger)"},
				{availability = "1.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade3", posture = { "Offensive" }, roles = { "Assault" }, effects = { "VsInfantry" }, mobility = { "Motorized" }, unit = "squad_sturm_begleitgren_motor_con"}, --vehicle
				{availability = "1.4", base = { "Infantry", "Squad" }, class = {}, grade = "Grade3", posture = { "Offensive" }, roles = { "Assault" }, effects = { "VsInfantry" }, unit = "squad_waffen_sturmpio_late_con(ger)"},
				--T3+
				{availability = "1.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade4", posture = { "Flexible" }, roles = { "Line" }, effects = {}, mobility = { "Mechanized" }, unit = "squad_pzg_gd_armor_con"}, --vehicle
				{availability = "1.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade3", posture = { "Flexible" }, roles = { "Line" }, effects = {}, mobility = { "Mechanized" }, unit = "squad_pzg_gd_pio_armor_con"}, --vehicle
				{availability = "1.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade4", posture = { "Flexible" }, roles = { "Line" }, effects = {}, mobility = { "Mechanized" }, unit = "squad_pzg_lehr_armor_con"}, --vehicle
				{availability = "1.6", base = { "Infantry", "Squad" }, class = {}, grade = "Grade4", posture = { "Offensive" }, roles = { "Assault" }, effects = { "VsInfantry" }, mobility = { "Mechanized" }, unit = "squad_sturm_pzg_lehr_armor_con"}, --vehicle
				{availability = "1.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade3", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_hg_pzgren_con(ger)"},
				{availability = "1.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade3", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_hg_pzpio_con(ger)"},
				{availability = "1.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade3", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_hg_pzauf_con(ger)"},
				{availability = "1.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade3", posture = { "Offensive" }, roles = { "Assault" }, effects = { "VsInfantry" }, unit = "squad_hg_sturmgren_con(ger)"},
				{availability = "1.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade3", posture = { "Flexible" }, roles = { "Line" }, effects = {}, mobility = { "Motorized" }, unit = "squad_hg_pzgren_motor_con"},
				{availability = "1.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade3", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_brand_jag_late_con(ger)"},
				{availability = "1.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade3", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_brand_pio_late_con(ger)"},
				--T4
				{availability = "1.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade4", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_gebirgsjaeger_late_con(ger)"},
				{availability = "1.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade4", posture = { "Offensive" }, roles = { "Recon" }, effects = {}, unit = "squad_gebirgs_recon_late_con(ger)"},
				{availability = "1.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade4", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_skijager_late_con(ger)"},
				{availability = "1.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade4", posture = { "Offensive" }, roles = { "Assault" }, effects = { "VsInfantry" }, unit = "squad_skijager_sturm_late_con(ger)"},
				{availability = "1.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade4", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_fallschirmjaeger_late_con(ger)"},
				{availability = "1.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade4", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_3rd_fallschirmjaeger_late_con(ger)"},
				{availability = "1.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade4", posture = { "Flexible" }, roles = { "Line" }, effects = {}, mobility = { "Motorized" }, unit = "squad_fallschirmjaeger_late_motor_con"}, --vehicle
				{availability = "1.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade4", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_fallschirm_pio_late_con(ger)"},
				{availability = "1.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade4", posture = { "Offensive" }, roles = { "Recon" }, effects = {}, unit = "squad_fallschirm_recon_late_con(ger)"},
				{availability = "1.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade4", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_mek_late_con(ger)"},
				{availability = "1.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade4", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_hochgebirgs_late_con(ger)"},
				{availability = "1.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade4", posture = { "Flexible" }, roles = { "Line" }, effects = {}, unit = "squad_brand_fallsch_late_con(ger)"},
				
				--AI only
				{availability = "1.5", base = { "Cannon" }, class = { "Medium" }, grade = "Grade2", posture = { "Defensive" }, roles = { "FieldGun" }, effects = { "VsVehicle", "VsArmor" }, unit = "squad_towed_gun1(ger)"},
				{availability = "1.5", base = { "Cannon" }, class = { "Medium" }, grade = "Grade2", posture = { "Defensive" }, roles = { "FieldGun" }, effects = { "VsVehicle", "VsArmor" }, unit = "squad_towed_gun2(ger)"},
				{availability = "1.5", base = { "Cannon" }, class = { "Medium" }, grade = "Grade2", posture = { "Defensive" }, roles = { "FieldGun" }, effects = { "VsVehicle", "VsArmor" }, unit = "squad_towed_gun3(ger)"},
				{availability = "1.5", base = { "Cannon" }, class = { "Medium" }, grade = "Grade2", posture = { "Defensive" }, roles = { "FieldGun" }, effects = { "VsVehicle", "VsArmor" }, unit = "squad_towed_gun4(ger)"},

				{availability = "1.5", base = { "Tank" }, class = { "Medium" }, grade = "Grade2", posture = { "Offensive" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "squad_france_jumpscare"},

				{availability = "1.4", base = { "Tank" }, class = { "Medium" }, grade = "Grade2", posture = { "Offensive" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "squad_sturmartillerie_early(ger)"},
				{availability = "1.4", base = { "Tank" }, class = { "Medium" }, grade = "Grade2", posture = { "Offensive" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "squad_sturmartillerie_mid(ger)"},
				{availability = "1.4", base = { "Tank" }, class = { "Medium" }, grade = "Grade2", posture = { "Offensive" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "squad_sturmartillerie_mid1(ger)"},
				{availability = "1.4", base = { "Tank" }, class = { "Medium" }, grade = "Grade2", posture = { "Offensive" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "squad_sturmartillerie_late(ger)"},
				{availability = "1.4", base = { "Tank" }, class = { "Medium" }, grade = "Grade2", posture = { "Offensive" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "squad_sturmartillerie_late1(ger)"},
				{availability = "1.4", base = { "Tank" }, class = { "Medium" }, grade = "Grade2", posture = { "Offensive" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "squad_sturmartillerie_late2(ger)"},
				{availability = "1.4", base = { "Tank" }, class = { "Medium" }, grade = "Grade2", posture = { "Offensive" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "squad_sturmartillerie_late3(ger)"},

				{availability = "1.5", base = { "Tank" }, class = { "Medium" }, grade = "Grade2", posture = { "Offensive" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "squad_hg_pzgren_ai(ger)"},
				{availability = "1.5", base = { "Tank" }, class = { "Medium" }, grade = "Grade2", posture = { "Offensive" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "squad_hg_pzpio_ai(ger)"},
				
				{availability = "1.3", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Flexible" }, roles = { "Line" }, effects = {}, mobility = { "Mechanized" }, unit = "squad_waffen_armor_con"},
				{availability = "1.4", base = { "Vehicle" }, class = { "Medium" }, grade = "Grade2", posture = { "Offensive" }, roles = { "Recon" }, effects = { "VsInfantry", "VsVehicle" }, unit = "squad_waffen_sdkfz231_con"},
				
				{availability = "1.4", base = { "SPG" }, class = { "Medium" }, grade = "Grade2", posture = { "Flexible" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, unit = "squad_marder2_lw_con"},

				{availability = "1.5", base = { "Tank" }, class = { "Light" }, grade = "Grade2", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "pz38h_735_late"},
				{availability = "1.5", base = { "Tank" }, class = { "Medium" }, grade = "Grade2", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "panzer35s_late"},

				{availability = "1.5", base = { "Infantry", "Single" }, class = {}, grade = "Grade2", posture = { "Offensive" }, roles = { "Assault" }, effects = { "VsInfantry" }, mobility = { "Motorized" }, unit = "squad_mot_sappers_ai"},

				--Singles/Teams
				{availability = "1.3", base = { "Infantry", "Single" }, class = {}, grade = "Grade2", posture = { "Flexible" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, unit = "single_at(ger)"},
				{availability = "1.4", base = { "Infantry", "Single" }, class = {}, grade = "Grade3", posture = { "Flexible" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, unit = "single_at_pzs_late_con(ger)"},

				{availability = "1.1", base = { "Infantry", "Single" }, class = {}, grade = "Grade2", posture = { "Flexible" }, roles = { "Recon" }, effects = {}, unit = "single_signaller(ger)"},
				{availability = "1.1", base = { "Infantry", "Single" }, class = {}, grade = "Grade2", posture = { "Flexible" }, roles = { "Recon" }, effects = {}, unit = "single_officer_ger"},
				{availability = "1.2", base = { "Infantry", "Single" }, class = {}, grade = "Grade1", posture = { "Flexible" }, roles = { "Recon" }, effects = {}, unit = "single_medic(ger)"},
				{availability = "1.4", base = { "Infantry", "Single" }, class = {}, grade = "Grade2", posture = { "Defensive" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, unit = "single_riflegrenade(ger)"},
				--{availability = "1.5", base = { "Infantry", "Single" }, class = {}, grade = "Grade1", posture = { "Defensive" }, roles = { "Recon" }, effects = {}, unit = "single_ap_miner(ger)"},
				--{availability = "1.5", base = { "Infantry", "Single" }, class = {}, grade = "Grade2", posture = { "Defensive" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, unit = "single_at_miner(ger)"},
				--{availability = "1.4", base = { "Infantry", "Single" }, class = {}, grade = "Grade1", posture = { "Offensive" }, roles = {}, effects = {}, unit = "single_engineer(ger)"},
				{availability = "1.5", base = { "Infantry", "Single" }, class = {}, grade = "Grade3", posture = { "Offensive" }, roles = { "Assault" }, effects = { "VsInfantry" }, unit = "single_flamer(ger)"},
				--{availability = "1.4", base = { "Infantry", "Single" }, class = {}, grade = "Grade1", posture = { "Flexible" }, roles = {}, effects = {}, unit = "single_tankman(ger)"},
				{availability = "1.4", base = { "Infantry", "Single" }, class = {}, grade = "Grade3", posture = { "Flexible" }, roles = { "Recon" }, effects = { "VsInfantry" }, unit = "single_sniper(ger)"},
				--]]

			-- Cannons
				---[[
				--{availability = "1.4", base = { "Cannon" }, class = { "Light" }, grade = "Grade1", posture = { "Defensive" }, roles = { "Unarmed", "Supply" }, effects = {}, unit = "inf_crate_ger"},
				--{availability = "1.4", base = { "Cannon" }, class = { "Light" }, grade = "Grade1", posture = { "Defensive" }, roles = { "Unarmed", "Supply" }, effects = {}, unit = "infantry_cart_if8"},
				--{availability = "1.4", base = { "Cannon" }, class = { "Light" }, grade = "Grade1", posture = { "Defensive" }, roles = { "Unarmed", "Supply" }, effects = {}, unit = "ammo_trailer"},
				--{availability = "1.4", base = { "Cannon" }, class = { "Light" }, grade = "Grade1", posture = { "Defensive" }, roles = {}, effects = {}, unit = "150mm_sw34_ger"},

				--HMGs
				{availability = "1.5", base = { "Cannon" }, class = { "Light" }, grade = "Grade2", posture = { "Defensive" }, roles = { "MG" }, effects = { "VsInfantry" }, unit = "mg08_ger"},
				{availability = "1.5", base = { "Cannon" }, class = { "Light" }, grade = "Grade2", posture = { "Defensive" }, roles = { "MG" }, effects = { "VsInfantry" }, unit = "mg34_lafette"},
				{availability = "1.5", base = { "Cannon" }, class = { "Light" }, grade = "Grade2", posture = { "Defensive" }, roles = { "MG" }, effects = { "VsInfantry" }, unit = "mg42_lafette"},
				{availability = "1.5", base = { "Cannon" }, class = { "Light" }, grade = "Grade2", posture = { "Defensive" }, roles = { "MG" }, effects = { "VsInfantry" }, unit = "mg131_lafette"},
				{availability = "1.6", base = { "Cannon" }, class = { "Light" }, grade = "Grade2", posture = { "Defensive" }, roles = { "MG" }, effects = { "VsInfantry" }, unit = "panzernest_krab_ger"},
				--Anti Aircraft
				{availability = "1.4", base = { "Cannon" }, class = { "Light" }, grade = "Grade1", posture = { "Defensive" }, roles = { "AirDefense" }, effects = { "VsInfantry", "VsVehicle" }, unit = "20mm_flak30"},
				{availability = "1.4", base = { "Cannon" }, class = { "Light" }, grade = "Grade2", posture = { "Defensive" }, roles = { "AirDefense" }, effects = { "VsInfantry", "VsVehicle" }, unit = "20mm_flak38"},
				{availability = "1.5", base = { "Cannon" }, class = { "Light" }, grade = "Grade3", posture = { "Defensive" }, roles = { "AirDefense" }, effects = { "VsInfantry", "VsVehicle" }, unit = "20mm_flakvierling38"},
				{availability = "1.5", base = { "Cannon" }, class = { "Medium" }, grade = "Grade3", posture = { "Defensive" }, roles = { "AirDefense" }, effects = { "VsInfantry", "VsVehicle" }, unit = "37mm_flak37"},
				{availability = "1.6", base = { "Cannon" }, class = { "Medium" }, grade = "Grade4", posture = { "Defensive" }, roles = { "AirDefense" }, effects = { "VsInfantry", "VsVehicle" }, unit = "50mm_flak41"},
				{availability = "1.5", base = { "Cannon" }, class = { "Heavy" }, grade = "Grade4", posture = { "Defensive" }, roles = { "AirDefense", "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, unit = "88mm_flak18"},
				{availability = "1.5", base = { "Cannon" }, class = { "Heavy" }, grade = "Grade4", posture = { "Defensive" }, roles = { "AirDefense", "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, unit = "88mm_flak36"},
				--Anti Tank
				{availability = "1.6", base = { "Cannon" }, class = { "Light" }, grade = "Grade1", posture = { "Defensive" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, unit = "28mm_pzb41"},
				{availability = "1.6", base = { "Cannon" }, class = { "Light" }, grade = "Grade1", posture = { "Defensive" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, unit = "37mm_pak36"},
				{availability = "1.6", base = { "Cannon" }, class = { "Light" }, grade = "Grade1", posture = { "Defensive" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, unit = "37mm_pak36_late"},
				{availability = "1.6", base = { "Cannon" }, class = { "Light" }, grade = "Grade2", posture = { "Defensive" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, unit = "42mm_pak41"},
				{availability = "1.5", base = { "Cannon" }, class = { "Light" }, grade = "Grade2", posture = { "Defensive" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, unit = "47mm_pakt"},
				{availability = "1.5", base = { "Cannon" }, class = { "Medium" }, grade = "Grade2", posture = { "Defensive" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, unit = "50mm_pak38"},
				{availability = "1.5", base = { "Cannon" }, class = { "Medium" }, grade = "Grade2", posture = { "Defensive" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, unit = "50mm_pak38_late"},
				{availability = "1.5", base = { "Cannon" }, class = { "Medium" }, grade = "Grade3", posture = { "Defensive" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, unit = "75mm_pak9738"},
				{availability = "1.5", base = { "Cannon" }, class = { "Medium" }, grade = "Grade3", posture = { "Defensive" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, unit = "75mm_pak9738_late"},
				{availability = "1.5", base = { "Cannon" }, class = { "Medium" }, grade = "Grade3", posture = { "Defensive" }, roles = { "FieldGun" }, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "76mm_f22_ger"},
				{availability = "1.5", base = { "Cannon" }, class = { "Medium" }, grade = "Grade3", posture = { "Defensive" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, unit = "75mm_pak40"},
				{availability = "1.5", base = { "Cannon" }, class = { "Heavy" }, grade = "Grade4", posture = { "Defensive" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, unit = "88mm_pak4341"},
				--Mortars
				{availability = "1.5", base = { "Cannon" }, class = { "Light" }, grade = "Grade2", posture = { "Defensive" }, roles = { "Mortar" }, effects = { "VsInfantry" }, unit = "50mm_legrw36"},
				{availability = "1.5", base = { "Cannon" }, class = { "Medium" }, grade = "Grade2", posture = { "Defensive" }, roles = { "Mortar" }, effects = { "VsInfantry" }, unit = "80mm_sgrw34"},
				{availability = "1.5", base = { "Cannon" }, class = { "Medium" }, grade = "Grade2", posture = { "Defensive" }, roles = { "Mortar" }, effects = { "VsInfantry" }, unit = "80mm_kzgrw42"},
				{availability = "1.5", base = { "Cannon" }, class = { "Heavy" }, grade = "Grade3", posture = { "Defensive" }, roles = { "Mortar" }, effects = { "VsInfantry" }, unit = "100mm_nbw35"},
				{availability = "1.5", base = { "Cannon" }, class = { "Heavy" }, grade = "Grade3", posture = { "Defensive" }, roles = { "Mortar" }, effects = { "VsInfantry" }, unit = "120mm_sgrw42"},
				{availability = "1.6", base = { "Cannon" }, class = { "Heavy" }, grade = "Grade4", posture = { "Defensive" }, roles = { "Mortar" }, effects = { "VsInfantry" }, unit = "200mm_ldgw40"},
				{availability = "1.5", base = { "Cannon" }, class = { "Heavy" }, grade = "Grade4", posture = { "Defensive" }, roles = { "Mortar" }, effects = { "VsInfantry" }, unit = "170mm_minewerfer_ger"},
				--Infantry Support
				{availability = "1.3", base = { "Cannon" }, class = { "Light" }, grade = "Grade2", posture = { "Defensive" }, roles = { "InfantryGun" }, effects = { "VsInfantry", "VsVehicle" }, unit = "75mm_leig18"},
				{availability = "1.5", base = { "Cannon" }, class = { "Light" }, grade = "Grade2", posture = { "Defensive" }, roles = { "InfantryGun" }, effects = { "VsInfantry", "VsVehicle" }, unit = "75mm_legebig18"},
				{availability = "1.4", base = { "Cannon" }, class = { "Light" }, grade = "Grade2", posture = { "Defensive" }, roles = { "InfantryGun" }, effects = { "VsInfantry", "VsVehicle" }, unit = "75mm_leig18_late"},
				{availability = "1.5", base = { "Cannon" }, class = { "Light" }, grade = "Grade2", posture = { "Defensive" }, roles = { "InfantryGun" }, effects = { "VsInfantry", "VsVehicle" }, unit = "75mm_legebig18_late"},
				{availability = "1.5", base = { "Cannon" }, class = { "Light" }, grade = "Grade2", posture = { "Defensive" }, roles = { "InfantryGun" }, effects = { "VsInfantry", "VsVehicle" }, unit = "75mm_lg40"},
				{availability = "1.5", base = { "Cannon" }, class = { "Heavy" }, grade = "Grade3", posture = { "Defensive" }, roles = { "InfantryGun" }, effects = { "VsInfantry", "VsVehicle" }, unit = "150mm_sig33"},
				{availability = "1.5", base = { "Cannon" }, class = { "Heavy" }, grade = "Grade3", posture = { "Defensive" }, roles = { "InfantryGun" }, effects = { "VsInfantry", "VsVehicle" }, unit = "150mm_sig33_late"},
				--Artillery
				{availability = "1.5", base = { "Cannon" }, class = { "Light" }, grade = "Grade2", posture = { "Defensive" }, roles = { "Artillery" }, effects = { "VsInfantry", "VsVehicle" }, unit = "105mm_lefh18"},
				{availability = "1.5", base = { "Cannon" }, class = { "Light" }, grade = "Grade2", posture = { "Defensive" }, roles = { "Artillery" }, effects = { "VsInfantry", "VsVehicle" }, unit = "105mm_k331f"},
				{availability = "1.5", base = { "Cannon" }, class = { "Light" }, grade = "Grade2", posture = { "Defensive" }, roles = { "Artillery" }, effects = { "VsInfantry", "VsVehicle" }, unit = "105mm_lefh18"},
				{availability = "1.5", base = { "Cannon" }, class = { "Light" }, grade = "Grade2", posture = { "Defensive" }, roles = { "Artillery" }, effects = { "VsInfantry", "VsVehicle" }, unit = "105mm_lefh18m"},
				{availability = "1.5", base = { "Cannon" }, class = { "Light" }, grade = "Grade2", posture = { "Defensive" }, roles = { "Artillery" }, effects = { "VsInfantry", "VsVehicle" }, unit = "105mm_lefh18_40"},
				{availability = "1.5", base = { "Cannon" }, class = { "Light" }, grade = "Grade2", posture = { "Defensive" }, roles = { "Artillery" }, effects = { "VsInfantry", "VsVehicle" }, unit = "105mm_sk18"},
				{availability = "1.5", base = { "Cannon" }, class = { "Medium" }, grade = "Grade3", posture = { "Defensive" }, roles = { "Artillery" }, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "150mm_sfh18"},
				{availability = "1.5", base = { "Cannon" }, class = { "Medium" }, grade = "Grade2", posture = { "Defensive" }, roles = { "Artillery" }, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "155mm_gpf_ger"},
				{availability = "1.6", base = { "Cannon" }, class = { "Heavy" }, grade = "Grade4", posture = { "Defensive" }, roles = { "Artillery" }, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "170mm_k18"},
				{availability = "1.6", base = { "Cannon" }, class = { "Heavy" }, grade = "Grade4", posture = { "Defensive" }, roles = { "Artillery" }, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "210mm_morser18"},
				{availability = "1.6", base = { "Cannon" }, class = { "Heavy" }, grade = "Grade2", posture = { "Defensive" }, roles = { "Artillery" }, effects = { "VsInfantry", "VsVehicle" }, unit = "220mm_morser531f"},
				{availability = "1.6", base = { "Cannon" }, class = { "Heavy" }, grade = "Grade2", posture = { "Defensive" }, roles = { "Artillery" }, effects = { "VsInfantry", "VsVehicle" }, unit = "squad_karl_gerat_con"}, --AI squad that costs less instead of original 600mm_thor
				--Rocket Artillery
				{availability = "1.4", base = { "Cannon" }, class = { "Medium" }, grade = "Grade3", posture = { "Defensive" }, roles = { "Artillery" }, effects = { "VsInfantry", "VsVehicle" }, unit = "150mm_nebelwerfer41"},
				{availability = "1.4", base = { "Cannon" }, class = { "Heavy" }, grade = "Grade3", posture = { "Defensive" }, roles = { "Artillery" }, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "210mm_nebelwerfer42"},
				{availability = "1.4", base = { "Cannon" }, class = { "Heavy" }, grade = "Grade4", posture = { "Defensive" }, roles = { "Artillery" }, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "300mm_nebelwerfer42"},
				--]]

			-- Wheel vehicles
				---[[
				{availability = "1.6", base = { "Vehicle" }, class = { "Light" }, grade = "Grade1", posture = { "Flexible" }, roles = { "MG" }, effects = { "VsInfantry" }, unit = "bmw_r71"},
				{availability = "1.6", base = { "Vehicle" }, class = { "Light" }, grade = "Grade1", posture = { "Flexible" }, roles = { "MG" }, effects = { "VsInfantry" }, unit = "kfz15"},
				--{availability = "1.5", base = { "Vehicle" }, class = { "Light" }, grade = "Grade1", posture = { "Flexible" }, roles = { "Unarmed", "Transport" }, effects = {}, unit = "kubelwagen"},
				{availability = "1.6", base = { "Vehicle" }, class = { "Light" }, grade = "Grade1", posture = { "Flexible" }, roles = { "MG" }, effects = { "VsInfantry" }, unit = "kubelwagen_mg"},
				{availability = "1.6", base = { "Vehicle" }, class = { "Light" }, grade = "Grade1", posture = { "Flexible" }, roles = { "MG" }, effects = { "VsInfantry" }, unit = "kubelwagen_dak"},
				{availability = "1.6", base = { "Vehicle" }, class = { "Light" }, grade = "Grade2", posture = { "Flexible" }, roles = { "MG" }, effects = { "VsInfantry" }, unit = "schwimmwagen_mg"},
				{availability = "1.5", base = { "Vehicle" }, class = { "Light" }, grade = "Grade1", posture = { "Flexible" }, roles = { "AirDefense" }, effects = { "VsInfantry", "VsVehicle" }, unit = "blitz3_6_flak30"},
				{availability = "1.6", base = { "Vehicle" }, class = { "Light" }, grade = "Grade2", posture = { "Flexible" }, roles = { "MG" }, effects = { "VsInfantry" }, unit = "kfz13"},
				{availability = "1.5", base = { "Vehicle" }, class = { "Light" }, grade = "Grade1", posture = { "Flexible" }, roles = { "Recon", "MG" }, effects = { "VsInfantry" }, unit = "sdkfz221"},
				{availability = "1.4", base = { "Vehicle" }, class = { "Light" }, grade = "Grade2", posture = { "Flexible" }, roles = { "Recon" }, effects = { "VsInfantry", "VsVehicle" }, unit = "sdkfz222a"},
				{availability = "1.4", base = { "Vehicle" }, class = { "Light" }, grade = "Grade2", posture = { "Flexible" }, roles = { "AirDefense" }, effects = { "VsInfantry", "VsVehicle" }, unit = "sdkfz222b"},
				{availability = "1.5", base = { "Vehicle" }, class = { "Medium" }, grade = "Grade2", posture = { "Flexible" }, roles = { "Recon" }, effects = { "VsInfantry", "VsVehicle" }, unit = "sdkfz231"},
				{availability = "1.6", base = { "Vehicle" }, class = { "Medium" }, grade = "Grade2", posture = { "Flexible" }, roles = { "Recon" }, effects = { "VsInfantry", "VsVehicle" }, unit = "p204_f"},
				{availability = "1.5", base = { "Vehicle" }, class = { "Medium" }, grade = "Grade3", posture = { "Flexible" }, roles = { "Recon" }, effects = { "VsInfantry", "VsVehicle" }, unit = "sdkfz234_1"},
				{availability = "1.5", base = { "Vehicle" }, class = { "Medium" }, grade = "Grade4", posture = { "Flexible" }, roles = { "Recon" }, effects = { "VsInfantry", "VsVehicle" }, unit = "sdkfz234_2"},
				{availability = "1.5", base = { "Vehicle" }, class = { "Medium" }, grade = "Grade3", posture = { "Flexible" }, roles = { "Recon" }, effects = { "VsInfantry", "VsVehicle" }, unit = "sdkfz234_3"},
				{availability = "1.5", base = { "Vehicle" }, class = { "Medium" }, grade = "Grade3", posture = { "Offensive" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, unit = "sdkfz234_4"},
				--{availability = "1.4", base = { "Vehicle" }, class = { "Light" }, grade = "Grade1", posture = { "Flexible" }, roles = { "Unarmed", "Transport" }, effects = {}, unit = "blitz3_6"},
				--{availability = "1.4", base = { "Vehicle" }, class = { "Light" }, grade = "Grade1", posture = { "Flexible" }, roles = { "Unarmed", "Supply" }, effects = {}, unit = "blitz3_6_art_ammo"},
				--{availability = "1.4", base = { "Vehicle" }, class = { "Light" }, grade = "Grade1", posture = { "Flexible" }, roles = { "Unarmed" }, effects = {}, unit = "blitz3_6_fuel"},
				--{availability = "1.4", base = { "Vehicle" }, class = { "Light" }, grade = "Grade1", posture = { "Flexible" }, roles = { "Unarmed" }, effects = {}, unit = "blitz3_6_engineering"},
				--{availability = "1.4", base = { "Vehicle" }, class = { "Light" }, grade = "Grade1", posture = { "Flexible" }, roles = { "Unarmed", "Supply" }, effects = {}, unit = "sdkfz6_ammo"},

				--]]

			-- Halftracks
				---[[
				--{availability = "1.6", base = { "Vehicle" }, class = { "Light" }, grade = "Grade1", posture = { "Flexible" }, roles = { "Unarmed", "Supply" }, effects = {}, unit = "kettenkrad_eng"},
				--{availability = "1.4", base = { "Vehicle" }, class = { "Light" }, grade = "Grade1", posture = { "Flexible" }, roles = { "Unarmed", "Transport" }, effects = {}, unit = "sdkfz10"},
				{availability = "1.7", base = { "Vehicle" }, class = { "Light" }, grade = "Grade2", posture = { "Flexible" }, roles = { "MG" }, effects = { "VsInfantry" }, unit = "sdkfz250a_1"},
				{availability = "1.6", base = { "Vehicle" }, class = { "Light" }, grade = "Grade2", posture = { "Flexible" }, roles = { "Recon" }, effects = { "VsInfantry", "VsVehicle" }, unit = "sdkfz250a_9"},
				{availability = "1.6", base = { "Vehicle" }, class = { "Light" }, grade = "Grade1", posture = { "Offensive" }, roles = { "AntiTank" }, effects = { "VsVehicle" }, unit = "sdkfz250a_11"},
				{availability = "1.6", base = { "Vehicle" }, class = { "Medium" }, grade = "Grade2", posture = { "Flexible" }, roles = { "MG" }, effects = { "VsInfantry" }, unit = "sdkfz251b"},
				{availability = "1.6", base = { "Vehicle" }, class = { "Medium" }, grade = "Grade2", posture = { "Flexible" }, roles = { "MG" }, effects = { "VsInfantry" }, unit = "sdkfz251c"},
				{availability = "1.6", base = { "Vehicle" }, class = { "Medium" }, grade = "Grade2", posture = { "Flexible" }, roles = { "MG" }, effects = { "VsInfantry" }, unit = "sdkfz251c_8"},
				{availability = "1.6", base = { "Vehicle" }, class = { "Medium" }, grade = "Grade2", posture = { "Offensive" }, roles = { "Mortar" }, effects = { "VsInfantry" }, unit = "sdkfz251c_2"},
				{availability = "1.5", base = { "Vehicle" }, class = { "Medium" }, grade = "Grade2", posture = { "Flexible" }, roles = { "MG" }, effects = { "VsInfantry" }, unit = "sdkfz251c_10"},
				{availability = "1.6", base = { "Vehicle" }, class = { "Medium" }, grade = "Grade2", posture = { "Flexible" }, roles = { "MG" }, effects = { "VsInfantry" }, unit = "sdkfz251d_1"},
				{availability = "1.6", base = { "Vehicle" }, class = { "Light" }, grade = "Grade1", posture = { "Flexible" }, roles = { "MG" }, effects = { "VsInfantry" }, unit = "unic304f"},		
				{availability = "1.5", base = { "Vehicle" }, class = { "Medium" }, grade = "Grade2", posture = { "Offensive" }, roles = { "Artillery" }, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "sdkfz251d_1_stuka"},
				{availability = "1.5", base = { "Vehicle" }, class = { "Medium" }, grade = "Grade2", posture = { "Flexible" }, roles = { "Assault" }, effects = { "VsInfantry" }, unit = "sdkfz251d_16"},
				{availability = "1.5", base = { "Vehicle" }, class = { "Medium" }, grade = "Grade2", posture = { "Flexible" }, roles = { "AirDefense" }, effects = { "VsInfantry", "VsVehicle" }, unit = "sdkfz251d_17"},
				{availability = "1.5", base = { "Vehicle" }, class = { "Medium" }, grade = "Grade3", posture = { "Flexible" }, roles = { "AirDefense" }, effects = { "VsInfantry", "VsVehicle" }, unit = "sdkfz251d_21"},
				{availability = "1.5", base = { "Vehicle" }, class = { "Medium" }, grade = "Grade3", posture = { "Offensive" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, unit = "sdkfz251d_22"},
				{availability = "1.5", base = { "Vehicle" }, class = { "Light" }, grade = "Grade1", posture = { "Flexible" }, roles = { "AirDefense" }, effects = { "VsInfantry", "VsVehicle" }, unit = "sdkfz10_4"},
				{availability = "1.5", base = { "Vehicle" }, class = { "Light" }, grade = "Grade1", posture = { "Flexible" }, roles = { "Unarmed", "Transport" }, effects = {}, unit = "sdkfz10_5"},
				{availability = "1.5", base = { "Vehicle" }, class = { "Medium" }, grade = "Grade3", posture = { "Flexible" }, roles = { "AirDefense" }, effects = { "VsInfantry", "VsVehicle" }, unit = "sdkfz6_2"},
				--{availability = "1.5", base = { "Vehicle" }, class = { "Medium" }, grade = "Grade3", posture = { "Flexible" }, roles = { "AirDefense" }, effects = { "VsInfantry", "VsVehicle" }, unit = "sdkfz7_1_unarmored"},
				{availability = "1.5", base = { "Vehicle" }, class = { "Medium" }, grade = "Grade3", posture = { "Flexible" }, roles = { "AirDefense" }, effects = { "VsInfantry", "VsVehicle" }, unit = "sdkfz7_1"},
				{availability = "1.5", base = { "Vehicle" }, class = { "Medium" }, grade = "Grade3", posture = { "Flexible" }, roles = { "AirDefense" }, effects = { "VsInfantry", "VsVehicle" }, unit = "sdkfz7_2"},
				{availability = "1.5", base = { "Vehicle" }, class = { "Light" }, grade = "Grade2", posture = { "Flexible" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, unit = "sdkfz10_pak38"},
				{availability = "1.5", base = { "Vehicle" }, class = { "Heavy" }, grade = "Grade3", posture = { "Flexible" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, unit = "sdkfz8_flak18"},
				{availability = "1.5", base = { "Vehicle" }, class = { "Medium" }, grade = "Grade3", posture = { "Flexible" }, roles = { "Artillery" }, effects = { "VsInfantry", "VsVehicle" }, unit = "panzerwerfer42"},
				--]]

			-- Tanks
				---[[
				{availability = "1.4", base = { "Tank" }, class = { "Light" }, grade = "Grade1", posture = { "Flexible" }, roles = { "MG" }, effects = { "VsInfantry" }, unit = "panzer1b"},
				{availability = "1.4", base = { "Tank" }, class = { "Light" }, grade = "Grade1", posture = { "Flexible" }, roles = { "MG" }, effects = { "VsInfantry" }, unit = "panzer1b_w40"},
				{availability = "1.6", base = { "Tank" }, class = { "Light" }, grade = "Grade2", posture = { "Flexible" }, roles = { "MG" }, effects = { "VsInfantry" }, unit = "panzer1f"},
				{availability = "1.2", base = { "Tank" }, class = { "Light" }, grade = "Grade2", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle" }, unit = "panzer2c"},
				{availability = "1.2", base = { "Tank" }, class = { "Light" }, grade = "Grade2", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle" }, unit = "panzer2f"},
				{availability = "1.4", base = { "Tank" }, class = { "Light" }, grade = "Grade2", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle" }, unit = "pz744e"},
				{availability = "1.4", base = { "Tank" }, class = { "Light" }, grade = "Grade2", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle" }, unit = "panzer2_flamm"},
				{availability = "1.5", base = { "Tank" }, class = { "Light" }, grade = "Grade3", posture = { "Flexible" }, roles = { "Recon" }, effects = { "VsInfantry", "VsVehicle" }, unit = "panzer2l"},
				{availability = "1.3", base = { "Tank" }, class = { "Light" }, grade = "Grade2", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "pz35t"},
				{availability = "1.3", base = { "Tank" }, class = { "Light" }, grade = "Grade2", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "pz38t_a"},
				{availability = "1.3", base = { "Tank" }, class = { "Light" }, grade = "Grade3", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "pz38t_f"},
				{availability = "1.2", base = { "Tank" }, class = { "Light" }, grade = "Grade3", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "pz38t_g"},
				{availability = "1.5", base = { "Tank" }, class = { "Light" }, grade = "Grade2", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "pz38h_735"},
				{availability = "1.6", base = { "Tank" }, class = { "Light" }, grade = "Grade2", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle" }, unit = "pz738i"},
				{availability = "1.6", base = { "Tank" }, class = { "Light" }, grade = "Grade2", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle" }, unit = "panzer731r"},
				{availability = "1.6", base = { "Tank" }, class = { "Light" }, grade = "Grade2", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle" }, unit = "panzer742r"},
				{availability = "1.6", base = { "Tank" }, class = { "Light" }, grade = "Grade2", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle" }, unit = "pz740r_9738"},
				{availability = "1.5", base = { "Tank" }, class = { "Medium" }, grade = "Grade2", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "pz747_41"},
				{availability = "1.5", base = { "Tank" }, class = { "Medium" }, grade = "Grade2", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "pz747_88"},
				{availability = "1.6", base = { "Tank" }, class = { "Heavy" }, grade = "Grade2", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "pz754r"},
				{availability = "1.6", base = { "Tank" }, class = { "Heavy" }, grade = "Grade2", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "pz756r"},

				{availability = "1.4", base = { "Tank" }, class = { "Medium" }, grade = "Grade2", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "panzer35s"},
				{availability = "1.1", base = { "Tank" }, class = { "Medium" }, grade = "Grade1", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "panzer3e"},
				{availability = "1.1", base = { "Tank" }, class = { "Medium" }, grade = "Grade1", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "panzer3f"},
				{availability = "1.1", base = { "Tank" }, class = { "Medium" }, grade = "Grade2", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "panzer3g"},
				{availability = "1.1", base = { "Tank" }, class = { "Medium" }, grade = "Grade2", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "panzer3j"},
				{availability = "1.1", base = { "Tank" }, class = { "Medium" }, grade = "Grade2", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "panzer3j_vorpanzer"}, 
				{availability = "1.1", base = { "Tank" }, class = { "Medium" }, grade = "Grade2", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "panzer3j1"},
				{availability = "1.2", base = { "Tank" }, class = { "Medium" }, grade = "Grade2", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "panzer3l"},
				{availability = "1.2", base = { "Tank" }, class = { "Medium" }, grade = "Grade2", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "panzer3m"},
				{availability = "1.3", base = { "Tank" }, class = { "Medium" }, grade = "Grade2", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "panzer3n"},
				{availability = "1.5", base = { "Tank" }, class = { "Medium" }, grade = "Grade3", posture = { "Offensive" }, roles = { "Assault" }, effects = { "VsInfantry" }, unit = "panzer3_flamm"},
				{availability = "1.1", base = { "Tank" }, class = { "Medium" }, grade = "Grade1", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "panzer4b"},
				{availability = "1.1", base = { "Tank" }, class = { "Medium" }, grade = "Grade1", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "panzer4d"},
				{availability = "1.1", base = { "Tank" }, class = { "Medium" }, grade = "Grade2", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "panzer4e"},
				{availability = "1.1", base = { "Tank" }, class = { "Medium" }, grade = "Grade2", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "panzer4f1"},
				{availability = "1.3", base = { "Tank" }, class = { "Medium" }, grade = "Grade2", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "panzer4f1_vorpanzer"}, 
				{availability = "1.1", base = { "Tank" }, class = { "Medium" }, grade = "Grade3", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "panzer4f2"},
				{availability = "1.1", base = { "Tank" }, class = { "Medium" }, grade = "Grade3", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "panzer4g"},
				{availability = "1.1", base = { "Tank" }, class = { "Medium" }, grade = "Grade3", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "panzer4h"},
				{availability = "1.1", base = { "Tank" }, class = { "Medium" }, grade = "Grade3", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "panzer4j"},
				{availability = "1.2", base = { "Tank" }, class = { "Medium" }, grade = "Grade3", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "panzer4j_late"}, 

				{availability = "1.2", base = { "Tank" }, class = { "Medium" }, grade = "Grade4", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "panzer5d"},
				{availability = "1.1", base = { "Tank" }, class = { "Medium" }, grade = "Grade4", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "panzer5a"},
				{availability = "1.1", base = { "Tank" }, class = { "Medium" }, grade = "Grade4", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "panzer5g"},
				{availability = "1.1", base = { "Tank" }, class = { "Medium" }, grade = "Grade4", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "panzer5g_armor"},
				{availability = "1.1", base = { "Tank" }, class = { "Medium" }, grade = "Grade4", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "panzer5g_fg1250"},
				{availability = "1.1", base = { "Tank" }, class = { "Heavy" }, grade = "Grade2", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "panzer5fg"},

				{availability = "1.5", base = { "Tank" }, class = { "Heavy" }, grade = "Grade1", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "panzerb2"},
				{availability = "1.6", base = { "Tank" }, class = { "Heavy" }, grade = "Grade2", posture = { "Offensive" }, roles = { "Assault" }, effects = { "VsInfantry", "VsVehicle" }, unit = "flammpanzer_b2"},
				{availability = "1.0", base = { "Tank" }, class = { "Heavy" }, grade = "Grade3", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "tiger1h_early"},
				{availability = "1.2", base = { "Tank" }, class = { "Heavy" }, grade = "Grade3", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "tiger1h"},
				{availability = "1.1", base = { "Tank" }, class = { "Heavy" }, grade = "Grade3", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "tiger1e"},
				{availability = "1.5", base = { "Tank" }, class = { "Heavy" }, grade = "Grade4", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "tiger1hunt"},
				{availability = "1.3", base = { "Tank" }, class = { "Heavy" }, grade = "Grade4", posture = { "Flexible" }, roles = { "Breakthrough" }, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "tiger2p"},
				{availability = "1.3", base = { "Tank" }, class = { "Heavy" }, grade = "Grade4", posture = { "Flexible" }, roles = { "Breakthrough" }, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "tiger2h"},
				--]]

			-- Self-Propelled Guns
				---[[
				{availability = "1.4", base = { "SPG" }, class = { "Light" }, grade = "Grade1", posture = { "Flexible" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, unit = "panzerjager1"},
				{availability = "1.4", base = { "SPG" }, class = { "Light" }, grade = "Grade2", posture = { "Flexible" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, unit = "marder2"},
				{availability = "1.3", base = { "SPG" }, class = { "Light" }, grade = "Grade2", posture = { "Flexible" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, unit = "marder3m"},
				{availability = "1.4", base = { "SPG" }, class = { "Light" }, grade = "Grade1", posture = { "Flexible" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, unit = "geschutzwagen_39h"},
				{availability = "1.2", base = { "SPG" }, class = { "Light" }, grade = "Grade3", posture = { "Flexible" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, unit = "hetzer"},

				{availability = "1.6", base = { "SPG" }, class = { "Light" }, grade = "Grade2", posture = { "Flexible" }, roles = { "AirDefense" }, effects = { "VsInfantry", "VsVehicle" }, unit = "grille_m"},

				{availability = "1.5", base = { "SPG" }, class = { "Light" }, grade = "Grade2", posture = { "Flexible" }, roles = { "InfantryGun" }, effects = { "VsInfantry", "VsVehicle" }, unit = "bison"},
				{availability = "1.5", base = { "SPG" }, class = { "Light" }, grade = "Grade4", posture = { "Flexible" }, roles = { "Artillery" }, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "pz38h_w40"},
				{availability = "1.5", base = { "SPG" }, class = { "Light" }, grade = "Grade2", posture = { "Flexible" }, roles = { "Artillery" }, effects = { "VsInfantry", "VsVehicle" }, unit = "grille_k"},
				{availability = "1.5", base = { "SPG" }, class = { "Light" }, grade = "Grade2", posture = { "Flexible" }, roles = { "Artillery" }, effects = { "VsInfantry", "VsVehicle" }, unit = "wespe"},
				{availability = "1.5", base = { "SPG" }, class = { "Light" }, grade = "Grade1", posture = { "Flexible" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, unit = "geschutzwagen_39h_lefh"},

				{availability = "1.4", base = { "SPG" }, class = { "Medium" }, grade = "Grade2", posture = { "Flexible" }, roles = { "InfantryGun" }, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "stug3a"},
				{availability = "1.4", base = { "SPG" }, class = { "Medium" }, grade = "Grade2", posture = { "Flexible" }, roles = { "InfantryGun" }, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "stug3b"},
				{availability = "1.4", base = { "SPG" }, class = { "Medium" }, grade = "Grade2", posture = { "Flexible" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, unit = "stug3e"},
				{availability = "1.4", base = { "SPG" }, class = { "Medium" }, grade = "Grade2", posture = { "Flexible" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, unit = "stug3f"},
				{availability = "1.4", base = { "SPG" }, class = { "Medium" }, grade = "Grade2", posture = { "Flexible" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, unit = "stug3g"},
				{availability = "1.4", base = { "SPG" }, class = { "Medium" }, grade = "Grade2", posture = { "Flexible" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, unit = "stug3g_late"},
				{availability = "1.4", base = { "SPG" }, class = { "Medium" }, grade = "Grade2", posture = { "Flexible" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, unit = "stug4"},
				{availability = "1.4", base = { "SPG" }, class = { "Medium" }, grade = "Grade2", posture = { "Flexible" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, unit = "stug4_late"},
				{availability = "1.4", base = { "SPG" }, class = { "Medium" }, grade = "Grade2", posture = { "Flexible" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, unit = "stug4_last"},
				{availability = "1.5", base = { "SPG" }, class = { "Medium" }, grade = "Grade2", posture = { "Flexible" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, unit = "stug853i"},
				{availability = "1.5", base = { "SPG" }, class = { "Medium" }, grade = "Grade2", posture = { "Flexible" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, unit = "stug852i"},
				{availability = "1.4", base = { "SPG" }, class = { "Medium" }, grade = "Grade3", posture = { "Flexible" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, unit = "jagdpanzer4_l48_early"},
				{availability = "1.4", base = { "SPG" }, class = { "Medium" }, grade = "Grade3", posture = { "Flexible" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, unit = "jagdpanzer4_l48"},
				{availability = "1.4", base = { "SPG" }, class = { "Medium" }, grade = "Grade3", posture = { "Flexible" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, unit = "panzer4_70_v"},
				{availability = "1.4", base = { "SPG" }, class = { "Medium" }, grade = "Grade2", posture = { "Flexible" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, unit = "panzer4_70_a"},
				{availability = "1.5", base = { "SPG" }, class = { "Medium" }, grade = "Grade2", posture = { "Flexible" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, unit = "dicker_max"},
				{availability = "1.5", base = { "SPG" }, class = { "Medium" }, grade = "Grade3", posture = { "Flexible" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, unit = "nashorn"},

				{availability = "1.4", base = { "SPG" }, class = { "Medium" }, grade = "Grade3", posture = { "Flexible" }, roles = { "AirDefense" }, effects = { "VsInfantry", "VsVehicle" }, unit = "wirbelwind"},
				{availability = "1.4", base = { "SPG" }, class = { "Medium" }, grade = "Grade3", posture = { "Flexible" }, roles = { "AirDefense" }, effects = { "VsInfantry", "VsVehicle" }, unit = "ostwind"},
				{availability = "1.5", base = { "SPG" }, class = { "Medium" }, grade = "Grade2", posture = { "Flexible" }, roles = { "AirDefense" }, effects = { "VsInfantry", "VsVehicle" }, unit = "kugelblitz"},

				{availability = "1.4", base = { "SPG" }, class = { "Medium" }, grade = "Grade3", posture = { "Flexible" }, roles = { "InfantryGun" }, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "stuh42"},
				{availability = "1.4", base = { "SPG" }, class = { "Medium" }, grade = "Grade3", posture = { "Flexible" }, roles = { "InfantryGun" }, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "stuh42_late"},
				{availability = "1.5", base = { "SPG" }, class = { "Medium" }, grade = "Grade2", posture = { "Flexible" }, roles = { "InfantryGun" }, effects = { "VsInfantry", "VsVehicle" }, unit = "sig33b"},
				{availability = "1.4", base = { "SPG" }, class = { "Medium" }, grade = "Grade3", posture = { "Flexible" }, roles = { "InfantryGun", "Breakthrough" }, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "sturmpanzer4"},
				{availability = "1.5", base = { "SPG" }, class = { "Medium" }, grade = "Grade3", posture = { "Flexible" }, roles = { "Artillery" }, effects = { "VsInfantry", "VsVehicle" }, unit = "hummel"},

				{availability = "1.5", base = { "SPG" }, class = { "Heavy" }, grade = "Grade4", posture = { "Flexible" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, unit = "ferdinand"},
				{availability = "1.5", base = { "SPG" }, class = { "Heavy" }, grade = "Grade2", posture = { "Flexible" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, unit = "elefant"},
				{availability = "1.4", base = { "SPG" }, class = { "Medium" }, grade = "Grade4", posture = { "Flexible" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, unit = "jagdpanther"},
				{availability = "1.5", base = { "SPG" }, class = { "Heavy" }, grade = "Grade4", posture = { "Flexible" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, unit = "jagdtiger"},
				{availability = "1.5", base = { "SPG" }, class = { "Heavy" }, grade = "Grade4", posture = { "Flexible" }, roles = { "InfantryGun", "Breakthrough" }, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, unit = "sturmtiger"},
				{availability = "1.5", base = { "SPG" }, class = { "Light" }, grade = "Grade2", posture = { "Flexible" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, unit = "sdkfz301wanze"},
				{availability = "1.5", base = { "Vehicle" }, class = { "Light" }, grade = "Grade2", posture = { "Offensive" }, roles = { "Assault" }, effects = { "VsVehicle", "VsArmor" }, unit = "sdkfz301b"},
				{availability = "1.5", base = { "Vehicle" }, class = { "Light" }, grade = "Grade2", posture = { "Offensive" }, roles = { "Assault" }, effects = { "VsVehicle", "VsArmor" }, unit = "sdkfz301c"},
				{availability = "1.4", base = { "Vehicle" }, class = { "Light" }, grade = "Grade2", posture = { "Offensive" }, roles = { "Assault" }, effects = { "VsVehicle", "VsArmor" }, unit = "sdkfz302"},
				{availability = "1.4", base = { "Vehicle" }, class = { "Light" }, grade = "Grade2", posture = { "Offensive" }, roles = { "Assault" }, effects = { "VsVehicle", "VsArmor" }, unit = "sdkfz303b"},
				--]]
			---]====]
		}
	}
}
