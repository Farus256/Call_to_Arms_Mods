game_entity
	{simulation {able 1} {state 1}}
	{constrain none}
	{obstacleID "nothing"}
	{collider "particle.big"}
	{props "harmless" "part" "delete_after_spawn"}
	{mass 1}
	{volume "body"
		{able clear {touch} {contact_ground}}
		{thickness 1}
		{able {Obstacle 0}}
	}
	{lodclass "part_small"}