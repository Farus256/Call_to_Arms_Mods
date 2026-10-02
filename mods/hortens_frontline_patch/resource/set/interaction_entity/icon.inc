

(define "at_weapon_icon"
	{on spawn
		{if difficulty "easy"
			{call "show"}
			{delay 1
				{view start "wp_view"}
			}
		else difficulty "normal"
			{call "show"}
			{delay 1
				{view start "wp_view"}
			}
		}
	}
	{on "link"					;// linked to vehicle
		{view hide "wp_view"}
	}
	{on "show" overload
		{add_view "%icon" "wp_view" "root" not_manual not_scenario}
	}
)

{"leuchtpistole34_ai" ;// flare
	("at_weapon_icon" icon(icon_flare))
}
{"leuchtpistole34" ;// flare
	("at_weapon_icon" icon(icon_flare))
}
{"osp30_ai" ;// flare
	("at_weapon_icon" icon(icon_flare))
}
{"osp30" ;// flare
	("at_weapon_icon" icon(icon_flare))
}
{"osp30_signal" ;// flare
	("at_weapon_icon" icon(icon_flare))
}
{"osp30_signal_sp" ;// flare
	("at_weapon_icon" icon(icon_flare))
}
{"flaregun_anm8" ;// flare
	("at_weapon_icon" icon(icon_flare))
}
{"flaregun_anm8_ai" ;// flare
	("at_weapon_icon" icon(icon_flare))
}
{"kampfpistole" ;// flare
	("at_weapon_icon" icon(icon_flare))
}
{"k98_antitank"
	("at_weapon_icon" icon(icon_k98at))
}
{"pzb_35p"
	("at_weapon_icon" icon(icon_pzb35p))
}
{"pzb_770i"
	("at_weapon_icon" icon(icon_pzb35p))
}
{"boys_mk1"
	("at_weapon_icon" icon(icon_boys))
}
{"panzershreck_54"
	("at_weapon_icon" icon(icon_panzerschreck))
}
{"panzershreck_43"
	("at_weapon_icon" icon(icon_panzerschreck))
}
{"k98_grenade_launcher"
	("at_weapon_icon" icon(icon_k98at))
}
{"g43_grenade_launcher"
	("at_weapon_icon" icon(icon_k98at))
}
{"mosin_grenade_launcher"
	("at_weapon_icon" icon(icon_k98at))
}
{"mosin_antitank"
	("at_weapon_icon" icon(icon_k98at))
}
{"ptrd"
	("at_weapon_icon" icon(icon_ptrd))
}
{"ptrs"
	("at_weapon_icon" icon(icon_ptrs))
}
{"pzb_39"
	("at_weapon_icon" icon(icon_pzb_39))
}
{"faustpatrone_30"
	("at_weapon_icon" icon(icon_panzerfaust))
	{on "fire"
		{delay 1
			{view stop "wp_view"}
		}
	}
}
{"panzerfaust_100"
	("at_weapon_icon" icon(icon_panzerfaust))
	{on "fire"
		{delay 1
			{view stop "wp_view"}
		}
	}
}
{"panzerfaust_30"
	("at_weapon_icon" icon(icon_panzerfaust))
	{on "fire"
		{delay 1
			{view stop "wp_view"}
		}
	}
}
{"panzerfaust_60"
	("at_weapon_icon" icon(icon_panzerfaust))
	{on "fire"
		{delay 1
			{view stop "wp_view"}
		}
	}
}
{"bazooka_m1"
	("at_weapon_icon" icon(icon_m1bazooka))
}
{"bazooka_m1a1"
	("at_weapon_icon" icon(icon_m1bazooka))
}
{"bazooka_m9"
	("at_weapon_icon" icon(icon_m1bazooka))
}
{"bazooka_m9a1"
	("at_weapon_icon" icon(icon_m1bazooka))
}
{"recoilless_m18"
	("at_weapon_icon" icon(icon_m1bazooka))
}
{"garand_grenade_launcher"
	("at_weapon_icon" icon(icon_k98at))
}
{"m1_carbine_grenade_launcher"
	("at_weapon_icon" icon(icon_k98at))
}
{"m1a1_carbine_grenade_launcher"
	("at_weapon_icon" icon(icon_k98at))
}
{"m1903_grenade_launcher"
	("at_weapon_icon" icon(icon_k98at))
}

{"piat"
	("at_weapon_icon" icon(icon_m1bazooka))
}

{"enfield_no4_mk1_grenade_launcher"
	("at_weapon_icon" icon(icon_k98at))
}

{"enfield_no1_mk3_grenade_launcher"
	("at_weapon_icon" icon(icon_k98at))
}