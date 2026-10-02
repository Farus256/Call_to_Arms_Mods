{selector
	{unit "human" "range_90"}	;// "unit tag" or "unit type" + "current main weapon tag"

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
	}
}
{selector
	{unit "human" "range_70"}	;// "unit tag" or "unit type" + "current main weapon tag"

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
	}
}
{selector
	{unit "human" "range_60"}	;// "unit tag" or "unit type" + "current main weapon tag"

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
	}
}
{selector
	{unit "human" "range_50"}	;// "unit tag" or "unit type" + "current main weapon tag"

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
	}
}
{selector
	{unit "human" "range_40"}	;// "unit tag" or "unit type" + "current main weapon tag"

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
	}
}
{selector
	{unit "human" "range_30"}	;// "unit tag" or "unit type" + "current main weapon tag"

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
	}
}
{selector
	{unit "human" "ap"}	;// (at = molotov grenades, AT grenade launchers, Rocketlaunchers, AT rifles)

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
	}
}