; == late WAR STANDARD RESOURCES ==
(define "standard_all"
	{teams
		{a ;// PLAYER DEFENDER TEAM
			{unitset
				{value "late^conquestonly|doctrineonly"}
			}
			{commandPoints "*=%cp_a"}
			(include "global_parameters/unitlimits.inc")
			{chargeFactors
				{value "*=1.00"}
			}
			{balancingFactorBonus	;// only affects players on team A users (not bots)
				{chargeDelay 1}		;// adjusts the initial delay only
				{charge 1.0}		;// adjusts the interval only
			}
			(include "global_parameters/last_stand/budget_defender.inc" s(%start_a) f(%finish_a) d(%doctrine))
		}
		{b ;// AI ATTACKER TEAM
			{unitset
				{value "late^conquestonly|doctrineonly"}
			}
			{commandPoints "*=%cp_b"}
			(include "global_parameters/unitlimits.inc")
			{chargeFactors
				{value "*=1.00"}
			}
			(include "global_parameters/last_stand/budget_attacker.inc" s(%start_b) f(%finish_b) d(%doctrine))
		}
	}

	{bots
		(include "global_parameters/last_stand/bots_standard.inc" period("late") start_a(%start_a) finish_a(%finish_a) start_b(%start_b) finish_b(%finish_b) doctrine(%doctrine) cp_a(%cp_a) cp_b(%cp_b))
	}
)


; == LATE WAR CUSTOM RESOURCES ==
(define "custom_all"
	{common
		{chargeFactors
			{value "*=1.00"}
			{customize "0;0.25;0.5;1;2"}
		}
	}
	{teams
		{a ;// PLAYER DEFENDER TEAM
			{unitset
				{value "late^conquestonly|doctrineonly"}
			}
			{commandPoints "*=%cp_a"}
			(include "global_parameters/unitlimits.inc")
			(include "global_parameters/last_stand/budget_defender_custom.inc" s(%start_a) f(%finish_a) d(%doctrine))
		}
		{b ;// AI ATTACKER TEAM
			{unitset
				{value "late^conquestonly|doctrineonly"}
			}
			{commandPoints "*=%cp_b"}
			(include "global_parameters/unitlimits.inc")
			(include "global_parameters/last_stand/budget_attacker_custom.inc" s(%start_b) f(%finish_b) d(%doctrine))
		}
	}

	{bots
		(include "global_parameters/last_stand/bots_custom.inc" period("late") start_a(%start_a) finish_a(%finish_a) start_b(%start_b) finish_b(%finish_b) doctrine(%doctrine) cp_a(%cp_a) cp_b(%cp_b))
	}
)


; == LATE WAR TEST ==
(define "test_late"
	{teams
		{a ;// PLAYER DEFENDER TEAM
			{unitset
				{value "late^conquestonly|doctrineonly"}
			}
			{commandPoints "*=%cp_a"}
			{unitLimits ""}
			{chargeFactors
				{value "*=0"}
			}
			(include "global_parameters/last_stand/budget_defender.inc" s(%start_a) f(%finish_a) d(%doctrine))
		}
		{b ;// AI ATTACKER TEAM
			{unitset
				{value "late^conquestonly|doctrineonly"}
			}
			{commandPoints "*=%cp_b"}
			{unitLimits ""}
			{chargeFactors
				{value "*=0"}
			}
			(include "global_parameters/last_stand/budget_attacker.inc" s(%start_b) f(%finish_b) d(%doctrine))
		}
	}

	{bots
		(include "global_parameters/last_stand/bots_standard.inc" period("late") start_a(%start_a) finish_a(%finish_a) start_b(%start_b) finish_b(%finish_b) doctrine(%doctrine) cp_a(%cp_a) cp_b(%cp_b))
	}
)

;------------------------------------------------------------------------------------------------------------
{presets
	{"s:late_standard_80"
		{gameMode "standard"}
		{unitMode "late"}
		{specMode "all_normal"}
		{apply "only_roster_late"}
		("standard_all"			start_a(500) finish_a(1800) start_b(500) finish_b(4500) doctrine(200) cp_a(0:160,900:160,1500:160) cp_b(0:440,900:440,1500:440))
		{ranked}
	}
;------------------------------------------------------------------------------------------------------------

; // custom games here

	{"c:late_custom_60"
		{gameMode "custom"}
		{unitMode "late"}
		{specMode "cp_60"}
		{apply "only_roster_late"}
		("custom_all"			start_a(500) finish_a(1800) start_b(500) finish_b(4500) doctrine(200) cp_a(0:120,900:120,1500:120) cp_b(0:440,900:440,1500:440))
	}
	{"c:late_custom_80"
		{gameMode "custom"}
		{unitMode "late"}
		{specMode "cp_80"}
		{apply "only_roster_late"}
		("custom_all"			start_a(550) finish_a(2400) start_b(550) finish_b(6000) doctrine(200) cp_a(0:160,900:160,1500:160) cp_b(0:480,900:480,1500:480))
	}
	{"c:late_custom_100"
		{gameMode "custom"}
		{unitMode "late"}
		{specMode "cp_100"}
		{apply "only_roster_late"}
		("custom_all"			start_a(600) finish_a(3000) start_b(600) finish_b(7500) doctrine(200) cp_a(0:200,900:200,1500:200) cp_b(0:520,900:520,1500:520))
	}
	{"c:late_custom_120"
		{gameMode "custom"}
		{unitMode "late"}
		{specMode "cp_120"}
		{apply "only_roster_late"}
		("custom_all"			start_a(650) finish_a(3600) start_b(650) finish_b(9000) doctrine(200) cp_a(0:240,900:240,1500:240) cp_b(0:560,900:560,1500:560))
	}

;------------------------------------------------------------------------------------------------------------

	{"s:test_late"
		{gameMode "test"}
		{unitMode "late"}
		{specMode "all_normal"}
		{apply "only_roster_late"}
		("test_late"			start_a(50000) finish_a(50000) start_b(50000) finish_b(50000) doctrine(2000) cp_a(2000) cp_b(2000))
	}
}