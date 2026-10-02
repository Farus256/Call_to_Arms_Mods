; == midf WAR STANDARD RESOURCES ==
(define "standard_all"
	{teams
		{a
			{unitset
				{value "midf|frontline^conquestonly|doctrineonly"}
			}
			{commandPoints "*=%cp_a"}
			(include "global_parameters/unitlimits_frontline.inc")
			{chargeFactors
				{value "*=1.00"}
			}
			{balancingFactorBonus	;// only affects players on team A (not bots)
				{chargeDelay 1}		;// adjusts the initial delay only
				{charge 1.0}		;// adjusts the interval only
			}
			(include "global_parameters/frontline/budget_attacker.inc" s(%start_a) f(%finish_a) d(%doctrine_a))
		}
		{b
			{unitset
				{value "midf|frontline^conquestonly|doctrineonly"}
			}
			{commandPoints "*=%cp_b"}
			(include "global_parameters/unitlimits_frontline.inc")
			{chargeFactors
				{value "*=1.00"}
			}
			(include "global_parameters/frontline/budget_defender.inc" s(%start_b) f(%finish_b) d(%doctrine_b))
		}
	}

	{bots
		(include "global_parameters/frontline/bots_standard.inc" period("midf") start_a(%start_a) finish_a(%finish_a) start_b(%start_b) finish_b(%finish_b) doctrine_a(%doctrine_a) doctrine_b(%doctrine_b) cp_a(%cp_a) cp_b(%cp_b))
	}
)
(define "custom_all_fl"
	{teams
		{a
			{unitset
				{value "midf|frontline^conquestonly|doctrineonly"}
			}
			{commandPoints "*=%cp_a"}
			(include "global_parameters/unitlimits_frontline.inc")
			(include "global_parameters/frontline/budget_attacker.inc" s(%start_a) f(%finish_a) d(%doctrine_a))
			{chargeFactors
				{value "*=1.00"}
			}
		}
		{b 
			{unitset
				{value "midf|frontline^conquestonly|doctrineonly"}
			}
			{commandPoints "*=%cp_b"}
			(include "global_parameters/unitlimits_frontline.inc")
			(include "global_parameters/frontline/budget_defender.inc" s(%start_b) f(%finish_b) d(%doctrine_b))
			{chargeFactors
				{value "*=1.00"}
			}
		}
	}

	{bots
		(include "global_parameters/frontline/bots_standard.inc" period("midf") start_a(%start_a) finish_a(%finish_a) start_b(%start_b) finish_b(%finish_b) doctrine_a(%doctrine_a) doctrine_b(%doctrine_b) cp_a(%cp_a) cp_b(%cp_b))
	}
)

(define "test_mid"
	{common
		{chargeFactors
			{value "*=0"}
			{customize "0;0.25;0.5;1;2"}
		}
	}
	{teams
		{a
			{unitset
				{value "midf|frontline^conquestonly|doctrineonly"}
			}
			{commandPoints "*=%cp_a"}
			(include "global_parameters/unitlimits_frontline.inc")
			(include "global_parameters/frontline/budget_attacker.inc" s(%start_a) f(%finish_a) d(%doctrine_a))
		}
		{b
			{unitset
				{value "midf|frontline^conquestonly|doctrineonly"}
			}
			{commandPoints "*=%cp_b"}
			(include "global_parameters/unitlimits_frontline.inc")
			(include "global_parameters/frontline/budget_defender.inc" s(%start_b) f(%finish_b) d(%doctrine_b))
		}
	}
	{bots
		(include "global_parameters/frontline/bots_standard.inc" period("midf") start_a(%start_a) finish_a(%finish_a) start_b(%start_b) finish_b(%finish_b) doctrine_a(%doctrine_a) doctrine_b(%doctrine_b) cp_a(%cp_a) cp_b(%cp_b))
	}
)

{presets
	{"s:midf_standard_80"
		{gameMode "standard"}
		{unitMode "midf"}
		{specMode "all_normal"}
		{apply "only_roster_frontline_mid"}
		("standard_all"			start_b(2750) finish_b(2750) start_a(9000) finish_a(9000) doctrine_a(200) doctrine_b(120) cp_b(0:250,900:300,1500:350) cp_a(0:340,900:390,1500:440))
		{ranked}
	}	
	{"s:midf_custom_2v2"
		{gameMode "custom"}
		{unitMode "midf"}
		{specMode "cp_2v2"}
		{apply "only_roster_frontline_mid"}
		("custom_all_fl"			start_b(3440) finish_b(4065) start_a(11250) finish_a(11250) doctrine_a(200) doctrine_b(120) cp_b(0:400,900:450,1500:500) cp_a(0:500,900:550,1500:600))
	}
	{"s:midf_custom_4v4"
		{gameMode "custom"}
		{unitMode "midf"}
		{specMode "cp_4v4"}
		{apply "only_roster_frontline_mid"}
		("custom_all_fl"			start_b(3025) finish_b(3575) start_a(9900) finish_a(9900) doctrine_a(200) doctrine_b(120) cp_b(0:300,900:350,1500:400) cp_a(0:400,900:450,1500:500))
	}
	{"s:midf_custom_3v3"
		{gameMode "custom"}
		{unitMode "midf"}
		{specMode "cp_3v3"}
		{apply "only_roster_frontline_mid"}
		("custom_all_fl"			start_b(2750) finish_b(2750) start_a(9000) finish_a(9000) doctrine_a(200) doctrine_b(120) cp_b(0:220,900:270,1500:320) cp_a(0:300,900:350,1500:400))
	}
	{"c:midf_custom_5v5"
		{gameMode "custom"}
		{unitMode "midf"}
		{specMode "cp_5v5"}
		{apply "only_roster_frontline_mid"}
		("custom_all_fl"			start_b(2475) finish_b(2475) start_a(8100) finish_a(8100) doctrine_a(200) doctrine_b(120) cp_b(0:190,900:240,1500:290) cp_a(0:260,900:310,1500:360))
	}
	{"c:midf_custom_6v6"
		{gameMode "custom"}
		{unitMode "midf"}
		{specMode "cp_6v6"}
		{apply "only_roster_frontline_mid"}
		("custom_all_fl"			start_b(2065) finish_b(2065) start_a(6750) finish_a(6750) doctrine_a(200) doctrine_b(120) cp_b(0:160,900:210,1500:260) cp_a(0:220,900:270,1500:320))
	}
	{"c:midf_custom_7v7"
		{gameMode "custom"}
		{unitMode "midf"}
		{specMode "cp_7v7"}
		{apply "only_roster_frontline_mid"}
		("custom_all_fl"			start_b(1720) finish_b(1720) start_a(5625) finish_a(5625) doctrine_a(200) doctrine_b(120) cp_b(0:120,900:170,1500:220) cp_a(0:180,900:230,1500:280))
	}
	{"c:midf_custom_8v8"
		{gameMode "custom"}
		{unitMode "midf"}
		{specMode "cp_8v8"}
		{apply "only_roster_frontline_mid"}
		("custom_all_fl"			start_b(1375) finish_b(1375) start_a(4500) finish_a(4500) doctrine_a(200) doctrine_b(120) cp_b(0:90,900:140,1500:190) cp_a(0:140,900:190,1500:240))
	}
	{"s:test_mid"
		{gameMode "test"}
		{unitMode "midf"}
		{specMode "all_normal"}
		{apply "only_roster_frontline_mid"}
		("test_mid"				start_b(80000) finish_b(80000) start_a(80000) finish_a(80000) doctrine_a(2000) doctrine_b(2000) cp_b(0:2000,900:2000,1500:2000) cp_a(0:2000,900:2000,1500:2000))
	}
}