; == EARLY WAR STANDARD RESOURCES ==
(define "standard_all"
	{common
		{unitset
			{value "early^conquestonly|doctrineonly"}
		}
		{commandPoints "*=%cp"}
		(include "global_parameters/unitlimits.inc")
		{chargeFactors
			{value "*=1.00"}
		}
		(include "global_parameters/budget.inc" s(%start) f(%finish) d(%doctrine))
	}
	{bots
		(include "global_parameters/bots_generic.inc" period("early"))
	}
)

; == EARLY WAR CUSTOM RESOURCES ==
(define "custom_all"
	{common
		{unitset
			{value "early^conquestonly|doctrineonly"}
		}
		{commandPoints "*=%cp"}
		(include "global_parameters/unitlimits.inc")
		{chargeFactors
			{value "*=1.00"}
			{customize "0;0.25;0.5;1;2"}
		}
		(include "global_parameters/budget_custom.inc" s(%start) f(%finish) d(%doctrine))
	}
	{bots
		(include "global_parameters/bots_generic.inc" period("early"))
	}
)

;------------------------------------------------------------------------------------------------------------
{presets
	{"s:early_standard_100"
		{gameMode "standard"}
		{unitMode "early"}
		{specMode "all_normal"}
		{apply "only_roster_early"}
		("standard_all"			start(200) finish(4500) doctrine(200) cp(0:200,300:300,900:400,1800:450))
		{ranked}
	}
;------------------------------------------------------------------------------------------------------------	

	{"c:early_custom_150_300"
		{gameMode "custom"}
		{unitMode "early"}
		{specMode "cp_vanilla_more_2"}
		{apply "only_roster_early"}
		("custom_all"			start(200) finish(8000) doctrine(200) cp(0:300,300:400,900:500,1800:600))
	}

	{"c:early_custom_125_250"
		{gameMode "custom"}
		{unitMode "early"}
		{specMode "cp_vanilla_more_1"}
		{apply "only_roster_early"}
		("custom_all"			start(200) finish(6000) doctrine(200) cp(0:250,300:350,900:450,1800:500))
	}

	{"c:early_default_100_200"
		{gameMode "custom"}
		{unitMode "early"}
		{specMode "cp_vanilla_default"}
		{apply "only_roster_early"}
		("custom_all"			start(200) finish(4500) doctrine(200) cp(0:200,300:300,900:400,1800:450))
	}

	{"c:early_custom_100_225"
		{gameMode "custom"}
		{unitMode "early"}
		{specMode "cp_vanilla_less_1"}
		{apply "only_roster_early"}
		("custom_all"			start(200) finish(3750) doctrine(200) cp(0:200,300:250,900:350,1800:400))
	}

	{"c:early_custom_100_175"
		{gameMode "custom"}
		{unitMode "early"}
		{specMode "cp_vanilla_less_6"}
		{apply "only_roster_early"}
		("custom_all"			start(200) finish(3500) doctrine(200) cp(0:200,300:250,900:300,1800:350))
	}

	{"c:early_custom_80_150"
		{gameMode "custom"}
		{unitMode "early"}
		{specMode "cp_vanilla_less_2"}
		{apply "only_roster_early"}
		("custom_all"			start(200) finish(3000) doctrine(200) cp(0:150,300:200,900:250,1800:300))
	}

	{"c:early_custom_60_120"
		{gameMode "custom"}
		{unitMode "early"}
		{specMode "cp_vanilla_less_3"}
		{apply "only_roster_early"}
		("custom_all"			start(200) finish(2500) doctrine(200) cp(0:120,300:160,900:200,1800:240))
	}

	{"c:early_custom_50_100"
		{gameMode "custom"}
		{unitMode "early"}
		{specMode "cp_vanilla_less_4"}
		{apply "only_roster_early"}
		("custom_all"			start(200) finish(2000) doctrine(200) cp(0:100,300:140,900:180,1800:200))
	}

	{"c:early_custom_50_50"
		{gameMode "custom"}
		{unitMode "early"}
		{specMode "cp_vanilla_less_5"}
		{apply "only_roster_early"}
		("custom_all"			start(200) finish(1500) doctrine(200) cp(0:100,300:100,900:120,1800:120))
	}
	
;------------------------------------------------------------------------------------------------------------
}