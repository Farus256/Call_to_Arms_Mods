{selector
	{unit "human" "fg"}

	{group ;// humans
		{ignore	{class airborne}}

		; UFB: a hand frag is for nearby infantry before armored targets.
		{sort {class human} {attacking} {in_range 25}}
		{sort {class human} {in_range 25}}

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
		{sort {in_range 25}}
	}
}