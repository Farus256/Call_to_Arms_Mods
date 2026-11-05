{selector
	{unit "human" "range_90"}	;// "unit tag" or "unit type" + "current main weapon tag"

	{group
		; UFB: automatic AT targeting reserves infantry for explicit critical/manual shots.
		{ignore {class human}}	;// priority of vehicles to attack assuming more than one is in weapon's range
		{sort {class tank_heavy}}		
		{sort {class tank_medium}}
		{sort {class tank_light}}
		
		{sort {class howitzer}}
		{sort {class cannon_big}}
		{sort {class cannon_zenite}}

		{sort {class cannon_small}}
		
		{sort {class armoredcar}}
		{sort {class armoredcar_l}}
		
		{sort {class cannon_bullet}}
		{sort {class car}}
		{sort {in_range 100}}
	}
}
{selector
	{unit "human" "range_70"}	;// "unit tag" or "unit type" + "current main weapon tag"

	{group
		; UFB: automatic AT targeting reserves infantry for explicit critical/manual shots.
		{ignore {class human}}	;// priority of vehicles to attack assuming more than one is in weapon's range
		{sort {class tank_heavy}}		
		{sort {class tank_medium}}
		{sort {class tank_light}}
		
		{sort {class howitzer}}
		{sort {class cannon_big}}
		{sort {class cannon_zenite}}

		{sort {class cannon_small}}
		
		{sort {class armoredcar}}
		{sort {class armoredcar_l}}
		
		{sort {class cannon_bullet}}
		{sort {class car}}
		{sort {in_range 80}}
	}
}
{selector
	{unit "human" "range_60"}	;// "unit tag" or "unit type" + "current main weapon tag"

	{group
		; UFB: automatic AT targeting reserves infantry for explicit critical/manual shots.
		{ignore {class human}}	;// priority of vehicles to attack assuming more than one is in weapon's range
		{sort {class tank_heavy}}		
		{sort {class tank_medium}}
		{sort {class tank_light}}
		
		{sort {class howitzer}}
		{sort {class cannon_big}}
		{sort {class cannon_zenite}}

		{sort {class cannon_small}}
		
		{sort {class armoredcar}}
		{sort {class armoredcar_l}}
		
		{sort {class cannon_bullet}}
		{sort {class car}}
		{sort {in_range 70}}
	}
}
{selector
	{unit "human" "range_50"}	;// "unit tag" or "unit type" + "current main weapon tag"

	{group
		; UFB: automatic AT targeting reserves infantry for explicit critical/manual shots.
		{ignore {class human}}	;// priority of vehicles to attack assuming more than one is in weapon's range
		{sort {class tank_heavy}}		
		{sort {class tank_medium}}
		{sort {class tank_light}}
		
		{sort {class howitzer}}
		{sort {class cannon_big}}
		{sort {class cannon_zenite}}

		{sort {class cannon_small}}
		
		{sort {class armoredcar}}
		{sort {class armoredcar_l}}
		
		{sort {class cannon_bullet}}
		{sort {class car}}
		{sort {in_range 60}}
	}
}
{selector
	{unit "human" "range_40"}	;// "unit tag" or "unit type" + "current main weapon tag"

	{group
		; UFB: automatic AT targeting reserves infantry for explicit critical/manual shots.
		{ignore {class human}}	;// priority of vehicles to attack assuming more than one is in weapon's range
		{sort {class tank_heavy}}		
		{sort {class tank_medium}}
		{sort {class tank_light}}
		
		{sort {class howitzer}}
		{sort {class cannon_big}}
		{sort {class cannon_zenite}}

		{sort {class cannon_small}}
		
		{sort {class armoredcar}}
		{sort {class armoredcar_l}}
		
		{sort {class cannon_bullet}}
		{sort {class car}}
		{sort {in_range 50}}
	}
}
{selector
	{unit "human" "range_30"}	;// "unit tag" or "unit type" + "current main weapon tag"

	{group
		; UFB: automatic AT targeting reserves infantry for explicit critical/manual shots.
		{ignore {class human}}	;// priority of vehicles to attack assuming more than one is in weapon's range
		{sort {class tank_heavy}}		
		{sort {class tank_medium}}
		{sort {class tank_light}}
		
		{sort {class howitzer}}
		{sort {class cannon_big}}
		{sort {class cannon_zenite}}

		{sort {class cannon_small}}
		
		{sort {class armoredcar}}
		{sort {class armoredcar_l}}
		
		{sort {class cannon_bullet}}
		{sort {class car}}
		{sort {in_range 40}}
	}
}

{selector
	{unit "human" "at_rifle"}	;// (at_rifle = at rifles and rifle grenades)

	{group	;// priority of vehicles to attack assuming more than one is in weapon's range
		{sort {class tank_heavy}}		
		{sort {class tank_medium}}
		{sort {class tank_light}}
		
		{sort {class howitzer}}
		{sort {class cannon_big}}
		{sort {class cannon_zenite}}

		{sort {class cannon_small}}
		
		{sort {class armoredcar}}
		{sort {class armoredcar_l}}
		
		{sort {class cannon_bullet}}
		{sort {class car}}
		{sort {in_range 130}}
	}
}

{selector
	{unit "human" "at"}	;// (at = molotov grenades, AT grenade launchers, Rocketlaunchers, AT rifles)

	{group	;// priority of vehicles to attack assuming more than one is in weapon's range
		{sort {class tank_heavy}}		
		{sort {class tank_medium}}
		{sort {class tank_light}}
		
		{sort {class howitzer}}
		{sort {class cannon_big}}
		{sort {class cannon_zenite}}

		{sort {class cannon_small}}
		
		{sort {class armoredcar}}
		{sort {class armoredcar_l}}
		
		{sort {class cannon_bullet}}
		{sort {class car}}
		{sort {in_range 30}}
	}
}
{selector
	{unit "human" "ap"}	;// (at = molotov grenades, AT grenade launchers, Rocketlaunchers, AT rifles)

	{group
		; UFB: automatic AT targeting reserves infantry for explicit critical/manual shots.
		{ignore {class human}}	;// priority of vehicles to attack assuming more than one is in weapon's range
		{sort {class tank_heavy}}		
		{sort {class tank_medium}}
		{sort {class tank_light}}
		
		{sort {class howitzer}}
		{sort {class cannon_big}}
		{sort {class cannon_zenite}}

		{sort {class cannon_small}}
		
		{sort {class armoredcar}}
		{sort {class armoredcar_l}}
		
		{sort {class cannon_bullet}}
		{sort {class car}}
		{sort {in_range 30}}
	}
}