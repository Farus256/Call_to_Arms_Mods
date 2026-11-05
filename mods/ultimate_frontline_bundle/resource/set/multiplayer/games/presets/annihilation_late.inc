; == late WAR STANDARD RESOURCES ==
(define "standard_all"
	{common
		{unitset
			{value "late^conquestonly|doctrineonly"}
		}
		{commandPoints "*=%cp"}
		(include "global_parameters/unitlimits.inc")
		{chargeFactors
			{value "*=0"}
		}
		(include "global_parameters/budget.inc" s(%start) f(%finish) d(%doctrine))
	}
	{bots
		(include "global_parameters/bots_generic.inc" period("late"))
	}
)

; == late WAR CUSTOM RESOURCES ==
(define "custom_all"
	{common
		{unitset
			{value "late^conquestonly|doctrineonly"}
		}
		{commandPoints "*=%cp"}
		(include "global_parameters/unitlimits.inc")
		{chargeFactors
			{value "*=0"}
		}
		(include "global_parameters/budget_custom.inc" s(%start) f(%finish) d(%doctrine))
	}
	{bots
		(include "global_parameters/bots_generic.inc" period("late"))
	}
)

;------------------------------------------------------------------------------------------------------------
{presets
	{"c:late_custom_80"
		{gameMode "custom"}
		{unitMode "late"}
		{specMode "cp_annih_standard"}
		{apply "only_roster_late"}
		("custom_all"			start(2000) finish(2000) doctrine(0) cp(0:360,180:0))
	}
	{"c:late_custom_160"
		{gameMode "custom"}
		{unitMode "late"}
		{specMode "cp_annih_less_1"}
		{apply "only_roster_late"}
		("custom_all"			start(1600) finish(1600) doctrine(0) cp(0:300,180:0))
	}
	{"c:late_custom_140"
		{gameMode "custom"}
		{unitMode "late"}
		{specMode "cp_annih_less_2"}
		{apply "only_roster_late"}
		("custom_all"			start(1200) finish(1200) doctrine(0) cp(0:240,180:0))
	}
	{"c:late_custom_120"
		{gameMode "custom"}
		{unitMode "late"}
		{specMode "cp_annih_less_3"}
		{apply "only_roster_late"}
		("custom_all"			start(800) finish(800) doctrine(0) cp(0:180,180:0))
	}
	{"c:late_custom_200"
		{gameMode "custom"}
		{unitMode "late"}
		{specMode "cp_annih_more_1"}
		{apply "only_roster_late"}
		("custom_all"			start(2400) finish(2400) doctrine(0) cp(0:420,180:0))
	}
	{"c:late_custom_250"
		{gameMode "custom"}
		{unitMode "late"}
		{specMode "cp_annih_more_2"}
		{apply "only_roster_late"}
		("custom_all"			start(2800) finish(2800) doctrine(0) cp(0:500,180:0))
	}
	{"c:late_custom_100"
		{gameMode "custom"}
		{unitMode "late"}
		{specMode "cp_annih_dp"}
		{apply "only_roster_late"}
		("custom_all"			start(1000) finish(1000) doctrine(90) cp(0:300,180:0))
	}

	{"s:late_standard_100"
		{gameMode "standard"}
		{unitMode "late"}
		{specMode "all_normal"}
		{apply "only_roster_late"}
		("standard_all"			start(2000) finish(2000) doctrine(0) cp(0:360,180:0))
		{ranked}
	}
;------------------------------------------------------------------------------------------------------------
}