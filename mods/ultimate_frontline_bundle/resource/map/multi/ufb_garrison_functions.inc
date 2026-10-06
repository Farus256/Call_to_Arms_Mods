			{"default_spawns"
				{"spawn"
					{entity "conquest_spawn_helper"}
					{waypoint "0"}
					{disable_random_spawn_position}
				}
				{"delay"
					{time 0.01}
				}
				{"entity_state"
					{selector
						{source standart}
						{ignore_captured_by_user 0}
						{amount 1
						}
						{tag conquest_spawn_helper}
					}
					{tag_add _default_a1}
					{tag_remove conquest_spawn_helper}
				}
				{"delay"
					{time 0.05}
				}
				{"placement"
					{selector
						{source standart}
						{ignore_captured_by_user 0}
						{tag _default_a1}
					}
					{target
						{ignore_captured_by_user 0}
						{tag a1}
					}
				}
				{"spawn"
					{entity "conquest_spawn_helper"}
					{waypoint "0"}
					{disable_random_spawn_position}
				}
				{"delay"
					{time 0.01}
				}
				{"entity_state"
					{selector
						{source standart}
						{ignore_captured_by_user 0}
						{amount 1
						}
						{tag conquest_spawn_helper}
					}
					{tag_add _default_a2}
					{tag_remove conquest_spawn_helper}
				}
				{"delay"
					{time 0.01}
				}
				{"placement"
					{selector
						{source standart}
						{ignore_captured_by_user 0}
						{tag _default_a2}
					}
					{target
						{ignore_captured_by_user 0}
						{tag a2}
					}
				}
				{"spawn"
					{entity "conquest_spawn_helper"}
					{waypoint "0"}
					{disable_random_spawn_position}
				}
				{"delay"
					{time 0.01}
				}
				{"entity_state"
					{selector
						{source standart}
						{ignore_captured_by_user 0}
						{amount 1
						}
						{tag conquest_spawn_helper}
					}
					{tag_add _default_a3}
					{tag_remove conquest_spawn_helper}
				}
				{"delay"
					{time 0.05}
				}
				{"placement"
					{selector
						{source standart}
						{ignore_captured_by_user 0}
						{tag _default_a3}
					}
					{target
						{ignore_captured_by_user 0}
						{tag a3}
					}
				}
				{"spawn"
					{entity "conquest_spawn_helper"}
					{waypoint "0"}
					{disable_random_spawn_position}
				}
				{"delay"
					{time 0.01}
				}
				{"entity_state"
					{selector
						{source standart}
						{ignore_captured_by_user 0}
						{amount 1
						}
						{tag conquest_spawn_helper}
					}
					{tag_add _default_a4}
					{tag_remove conquest_spawn_helper}
				}
				{"delay"
					{time 0.05}
				}
				{"placement"
					{selector
						{source standart}
						{ignore_captured_by_user 0}
						{tag _default_a4}
					}
					{target
						{ignore_captured_by_user 0}
						{tag a4}
					}
				}
				{"spawn"
					{entity "conquest_spawn_helper"}
					{waypoint "0"}
					{disable_random_spawn_position}
				}
				{"delay"
					{time 0.01}
				}
				{"entity_state"
					{selector
						{source standart}
						{ignore_captured_by_user 0}
						{amount 1
						}
						{tag conquest_spawn_helper}
					}
					{tag_add _default_b1}
					{tag_remove conquest_spawn_helper}
				}
				{"delay"
					{time 0.05}
				}
				{"placement"
					{selector
						{source standart}
						{ignore_captured_by_user 0}
						{tag _default_b1}
					}
					{target
						{ignore_captured_by_user 0}
						{tag b1}
					}
				}
				{"spawn"
					{entity "conquest_spawn_helper"}
					{waypoint "0"}
					{disable_random_spawn_position}
				}
				{"delay"
					{time 0.01}
				}
				{"entity_state"
					{selector
						{source standart}
						{ignore_captured_by_user 0}
						{amount 1
						}
						{tag conquest_spawn_helper}
					}
					{tag_add _default_b2}
					{tag_remove conquest_spawn_helper}
				}
				{"delay"
					{time 0.05}
				}
				{"placement"
					{selector
						{source standart}
						{ignore_captured_by_user 0}
						{tag _default_b2}
					}
					{target
						{ignore_captured_by_user 0}
						{tag b2}
					}
				}
				{"spawn"
					{entity "conquest_spawn_helper"}
					{waypoint "0"}
					{disable_random_spawn_position}
				}
				{"delay"
					{time 0.01}
				}
				{"entity_state"
					{selector
						{source standart}
						{ignore_captured_by_user 0}
						{amount 1
						}
						{tag conquest_spawn_helper}
					}
					{tag_add _default_b3}
					{tag_remove conquest_spawn_helper}
				}
				{"delay"
					{time 0.05}
				}
				{"placement"
					{selector
						{source standart}
						{ignore_captured_by_user 0}
						{tag _default_b3}
					}
					{target
						{ignore_captured_by_user 0}
						{tag b3}
					}
				}
				{"spawn"
					{entity "conquest_spawn_helper"}
					{waypoint "0"}
					{disable_random_spawn_position}
				}
				{"delay"
					{time 0.01}
				}
				{"entity_state"
					{selector
						{source standart}
						{ignore_captured_by_user 0}
						{amount 1
						}
						{tag conquest_spawn_helper}
					}
					{tag_add _default_b4}
					{tag_remove conquest_spawn_helper}
				}
				{"delay"
					{time 0.05}
				}
				{"placement"
					{selector
						{source standart}
						{ignore_captured_by_user 0}
						{tag _default_b4}
					}
					{target
						{ignore_captured_by_user 0}
						{tag b4}
					}
				}
				{"delay"
					{time 0.5}
				}
				{"switch"
					{"case"
						{condition
							{type cmp_i}
							{var "player_spawn_name$"}
							{op "=="}
							{value 1}
						}
						{"entity_state"
							{selector
								{source advanced}
								{ignore_captured_by_user 0}
								{group
									{select
										{tag
											{tag a1}
										}
									}
									{include
										{tag
											{tag spawn_a}
										}
									}
								}
							}
							{tag_add player_spawn}
						}
					}
					{"case"
						{condition
							{type cmp_i}
							{var "player_spawn_name$"}
							{op "=="}
							{value 2}
						}
						{"entity_state"
							{selector
								{source advanced}
								{ignore_captured_by_user 0}
								{group
									{select
										{tag
											{tag a2}
										}
									}
									{include
										{tag
											{tag spawn_a}
										}
									}
								}
							}
							{tag_add player_spawn}
						}
					}
					{"case"
						{condition
							{type cmp_i}
							{var "player_spawn_name$"}
							{op "=="}
							{value 3}
						}
						{"entity_state"
							{selector
								{source advanced}
								{ignore_captured_by_user 0}
								{group
									{select
										{tag
											{tag a3}
										}
									}
									{include
										{tag
											{tag spawn_a}
										}
									}
								}
							}
							{tag_add player_spawn}
						}
					}
					{"case"
						{condition
							{type cmp_i}
							{var "player_spawn_name$"}
							{op "=="}
							{value 4}
						}
						{"entity_state"
							{selector
								{source advanced}
								{ignore_captured_by_user 0}
								{group
									{select
										{tag
											{tag a4}
										}
									}
									{include
										{tag
											{tag spawn_a}
										}
									}
								}
							}
							{tag_add player_spawn}
						}
					}
					{"case"
						{condition
							{type cmp_i}
							{var "player_spawn_name$"}
							{op "=="}
							{value 5}
						}
						{"entity_state"
							{selector
								{source advanced}
								{ignore_captured_by_user 0}
								{group
									{select
										{tag
											{tag b1}
										}
									}
									{include
										{tag
											{tag spawn_b}
										}
									}
								}
							}
							{tag_add player_spawn}
						}
					}
					{"case"
						{condition
							{type cmp_i}
							{var "player_spawn_name$"}
							{op "=="}
							{value 6}
						}
						{"entity_state"
							{selector
								{source advanced}
								{ignore_captured_by_user 0}
								{group
									{select
										{tag
											{tag b2}
										}
									}
									{include
										{tag
											{tag spawn_b}
										}
									}
								}
							}
							{tag_add player_spawn}
						}
					}
					{"case"
						{condition
							{type cmp_i}
							{var "player_spawn_name$"}
							{op "=="}
							{value 7}
						}
						{"entity_state"
							{selector
								{source advanced}
								{ignore_captured_by_user 0}
								{group
									{select
										{tag
											{tag b3}
										}
									}
									{include
										{tag
											{tag spawn_b}
										}
									}
								}
							}
							{tag_add player_spawn}
						}
					}
					{"case"
						{condition
							{type cmp_i}
							{var "player_spawn_name$"}
							{op "=="}
							{value 8}
						}
						{"entity_state"
							{selector
								{source advanced}
								{ignore_captured_by_user 0}
								{group
									{select
										{tag
											{tag b4}
										}
									}
									{include
										{tag
											{tag spawn_b}
										}
									}
								}
							}
							{tag_add player_spawn}
						}
					}
					{"default"
						{"timer"
							{time 2}
							{title "mission/multi/dcg2_error04"}
						}
						{"con"
							{text "(Warning) - player spawn id unknown!"}
						}
					}
				}
			}
			{"flag1_bots_d"
				{"entity_state"
					{selector
						{source advanced}
						{ignore_captured_by_user 0}
						{group
							{select
								{tag
									{tag "_garrison_todo+"}
								}
							}
							{include
								{zone
									{zone "forward1"}
								}
								{prop
									{prop human}
								}
								{state
									{state operatable}
								}
							}
							{exclude
								{state
									{state inactive}
								}
								{state
									{state linked}
								}
							}
						}
						{amount 2
						}
					}
					{tag_add _botsf1_h}
				}
				{"entity_state"
					{selector
						{source advanced}
						{ignore_captured_by_user 0}
						{group
							{select
								{tag
									{tag "_garrison_todo+"}
								}
							}
							{include
								{zone
									{zone "forward1"}
								}
								{prop
									{prop vehicle}
								}
								{state
									{state operatable}
								}
							}
							{exclude
								{prop
									{prop car}
								}
								{prop
									{prop tank}
								}
								{prop
									{prop detect_artillery}
								}
								{prop
									{prop detect_artillery_small}
								}
							}
						}
						{amount 1
						}
					}
					{tag_add _botsf1_v}
				}
				{"delay"
					{time 0.1}
				}
				{"entity_state"
					{selector
						{source advanced}
						{ignore_captured_by_user 0}
						{group
							{select
								{tag
									{tag "_garrison_todo+"}
								}
							}
							{include
								{zone
									{zone "forward1"}
								}
								{prop
									{prop vehicle}
								}
								{state
									{state operatable}
								}
							}
							{exclude
								{tag
									{tag _botsf1_v}
								}
								{prop
									{prop detect_artillery}
								}
								{prop
									{prop detect_artillery_small}
								}
							}
						}
						{amount 1
						}
					}
					{tag_add _botsf1_ct}
				}
				{"delay"
					{time 0.1}
				}
				{"entity_state"
					{selector
						{source advanced}
						{ignore_captured_by_user 0}
						{group
							{select
								{tag
									{tag "_garrison_todo+"}
								}
							}
							{include
								{zone
									{zone "forward1"}
								}
								{prop
									{prop vehicle}
								}
								{state
									{state operatable}
								}
							}
							{exclude
								{tag
									{tag _botsf1_v}
								}
								{tag
									{tag _botsf1_ct}
								}
							}
						}
						{amount 1
						}
					}
					{tag_add _botsf1_artyc}
				}
				{"delay"
					{time 0.1}
				}
				{"entity_state"
					{selector
						{source standart}
						{ignore_captured_by_user 0}
						{tag _botsf1_v}
					}
					{tag_add "+garrisoned"}
					{tag_remove "_garrison_todo+"}
				}
				{"switch"
					{"case"
						{condition
							{type cmp_i}
							{var "bots_spawnside$"}
							{op "=="}
							{value 1}
						}
						{"switch"
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 5}}
{"waypoint"
							{who
								{type actor}
								{actors
									{ignore_captured_by_user 0}
									{tag _botsf1_ct}
									{type vehicle}
									{state operatable}
								}
							}
							{action
								{type start}
								{waypoint "15015"}
								{make_squad}
								{approach "safe teleport"}
							}
						}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 6}}
{"waypoint"
							{who
								{type actor}
								{actors
									{ignore_captured_by_user 0}
									{tag _botsf1_ct}
									{type vehicle}
									{state operatable}
								}
							}
							{action
								{type start}
								{waypoint "16015"}
								{make_squad}
								{approach "safe teleport"}
							}
						}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 7}}
{"waypoint"
							{who
								{type actor}
								{actors
									{ignore_captured_by_user 0}
									{tag _botsf1_ct}
									{type vehicle}
									{state operatable}
								}
							}
							{action
								{type start}
								{waypoint "17015"}
								{make_squad}
								{approach "safe teleport"}
							}
						}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 8}}
{"waypoint"
							{who
								{type actor}
								{actors
									{ignore_captured_by_user 0}
									{tag _botsf1_ct}
									{type vehicle}
									{state operatable}
								}
							}
							{action
								{type start}
								{waypoint "18015"}
								{make_squad}
								{approach "safe teleport"}
							}
						}}
{"default"
{"waypoint"
							{who
								{type actor}
								{actors
									{ignore_captured_by_user 0}
									{tag _botsf1_ct}
									{type vehicle}
									{state operatable}
								}
							}
							{action
								{type start}
								{waypoint "15"}
								{make_squad}
								{approach "safe teleport"}
							}
						}}}
						{"switch"
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 5}}
{"waypoint"
							{who
								{type actor}
								{actors
									{ignore_captured_by_user 0}
									{tag _botsf1_h}
									{type human}
									{state operatable}
								}
							}
							{action
								{type start}
								{waypoint "15001"}
								{make_squad}
								{approach "safe teleport"}
							}
						}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 6}}
{"waypoint"
							{who
								{type actor}
								{actors
									{ignore_captured_by_user 0}
									{tag _botsf1_h}
									{type human}
									{state operatable}
								}
							}
							{action
								{type start}
								{waypoint "16001"}
								{make_squad}
								{approach "safe teleport"}
							}
						}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 7}}
{"waypoint"
							{who
								{type actor}
								{actors
									{ignore_captured_by_user 0}
									{tag _botsf1_h}
									{type human}
									{state operatable}
								}
							}
							{action
								{type start}
								{waypoint "17001"}
								{make_squad}
								{approach "safe teleport"}
							}
						}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 8}}
{"waypoint"
							{who
								{type actor}
								{actors
									{ignore_captured_by_user 0}
									{tag _botsf1_h}
									{type human}
									{state operatable}
								}
							}
							{action
								{type start}
								{waypoint "18001"}
								{make_squad}
								{approach "safe teleport"}
							}
						}}
{"default"
{"waypoint"
							{who
								{type actor}
								{actors
									{ignore_captured_by_user 0}
									{tag _botsf1_h}
									{type human}
									{state operatable}
								}
							}
							{action
								{type start}
								{waypoint "1"}
								{make_squad}
								{approach "safe teleport"}
							}
						}}}
						{"delay"
							{time 0.1}
						}
						{"if"
							{condition
								{type entities}
								{selector
									{ignore_captured_by_user 0}
									{tag _botsf1_artyc}
									{zone "gamezone"}
									{type vehicle}
									{state inhabited}
								}
							}
							{"switch"
								{"case"
									{condition
										{type cmp_i}
										{var "arty1_rnd$"}
										{op "=="}
										{value 0}
									}
									{"switch"
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 5}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf1_artyc}
											}
										}
										{action
											{type start}
											{waypoint "15110"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 6}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf1_artyc}
											}
										}
										{action
											{type start}
											{waypoint "16110"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 7}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf1_artyc}
											}
										}
										{action
											{type start}
											{waypoint "17110"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 8}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf1_artyc}
											}
										}
										{action
											{type start}
											{waypoint "18110"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"default"
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf1_artyc}
											}
										}
										{action
											{type start}
											{waypoint "110"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}}
								}
								{"case"
									{condition
										{type cmp_i}
										{var "arty1_rnd$"}
										{op "=="}
										{value 1}
									}
									{"switch"
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 5}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf1_artyc}
											}
										}
										{action
											{type start}
											{waypoint "15111"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 6}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf1_artyc}
											}
										}
										{action
											{type start}
											{waypoint "16111"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 7}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf1_artyc}
											}
										}
										{action
											{type start}
											{waypoint "17111"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 8}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf1_artyc}
											}
										}
										{action
											{type start}
											{waypoint "18111"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"default"
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf1_artyc}
											}
										}
										{action
											{type start}
											{waypoint "111"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}}
								}
								{"case"
									{condition
										{type cmp_i}
										{var "arty1_rnd$"}
										{op "=="}
										{value 2}
									}
									{"switch"
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 5}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf1_artyc}
											}
										}
										{action
											{type start}
											{waypoint "15112"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 6}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf1_artyc}
											}
										}
										{action
											{type start}
											{waypoint "16112"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 7}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf1_artyc}
											}
										}
										{action
											{type start}
											{waypoint "17112"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 8}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf1_artyc}
											}
										}
										{action
											{type start}
											{waypoint "18112"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"default"
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf1_artyc}
											}
										}
										{action
											{type start}
											{waypoint "112"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}}
								}
								{"case"
									{condition
										{type cmp_i}
										{var "arty1_rnd$"}
										{op "=="}
										{value 3}
									}
									{"switch"
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 5}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf1_artyc}
											}
										}
										{action
											{type start}
											{waypoint "15230"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 6}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf1_artyc}
											}
										}
										{action
											{type start}
											{waypoint "16230"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 7}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf1_artyc}
											}
										}
										{action
											{type start}
											{waypoint "17230"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 8}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf1_artyc}
											}
										}
										{action
											{type start}
											{waypoint "18230"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"default"
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf1_artyc}
											}
										}
										{action
											{type start}
											{waypoint "230"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}}
								}
								{"default"
									{"switch"
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 5}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf1_artyc}
											}
										}
										{action
											{type start}
											{waypoint "15070"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 6}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf1_artyc}
											}
										}
										{action
											{type start}
											{waypoint "16070"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 7}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf1_artyc}
											}
										}
										{action
											{type start}
											{waypoint "17070"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 8}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf1_artyc}
											}
										}
										{action
											{type start}
											{waypoint "18070"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"default"
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf1_artyc}
											}
										}
										{action
											{type start}
											{waypoint "70"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}}
								}
							}
							{"delay"
								{time 0.1}
							}
							{"switch"
								{"case"
									{condition
										{type cmp_i}
										{var "arty1_rnd$"}
										{op "<<"}
										{value 4}
									}
									{"set_i"
										{var "arty1_rnd$"}
										{op "+"}
										{value 1}
									}
								}
								{"default"
									{"set_i"
										{var "arty1_rnd$"}
										{op "="}
										{value 0}
									}
								}
							}
							{"entity_state"
								{selector
									{source standart}
									{ignore_captured_by_user 0}
									{tag _botsf1_artyc}
								}
								{tag_add "+bots_ct"}
							}
						}
						{"delay"
							{time 0.1}
						}
						{"if"
							{condition
								{type entities}
								{selector
									{ignore_captured_by_user 0}
									{tag _botsf1_v}
									{zone "gamezone"}
									{type vehicle}
									{state operatable}
								}
							}
							{"switch"
								{"case"
									{condition
										{type cmp_i}
										{var "gun1_tele$"}
										{op "=="}
										{value 0}
									}
									{"switch"
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 5}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf1_v}
											}
										}
										{action
											{type start}
											{waypoint "15071"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 6}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf1_v}
											}
										}
										{action
											{type start}
											{waypoint "16071"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 7}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf1_v}
											}
										}
										{action
											{type start}
											{waypoint "17071"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 8}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf1_v}
											}
										}
										{action
											{type start}
											{waypoint "18071"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"default"
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf1_v}
											}
										}
										{action
											{type start}
											{waypoint "71"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}}
								}
								{"case"
									{condition
										{type cmp_i}
										{var "gun1_tele$"}
										{op "=="}
										{value 1}
									}
									{"switch"
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 5}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf1_v}
											}
										}
										{action
											{type start}
											{waypoint "15072"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 6}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf1_v}
											}
										}
										{action
											{type start}
											{waypoint "16072"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 7}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf1_v}
											}
										}
										{action
											{type start}
											{waypoint "17072"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 8}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf1_v}
											}
										}
										{action
											{type start}
											{waypoint "18072"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"default"
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf1_v}
											}
										}
										{action
											{type start}
											{waypoint "72"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}}
								}
								{"default"
									{"switch"
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 5}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf1_v}
											}
										}
										{action
											{type start}
											{waypoint "15073"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 6}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf1_v}
											}
										}
										{action
											{type start}
											{waypoint "16073"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 7}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf1_v}
											}
										}
										{action
											{type start}
											{waypoint "17073"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 8}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf1_v}
											}
										}
										{action
											{type start}
											{waypoint "18073"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"default"
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf1_v}
											}
										}
										{action
											{type start}
											{waypoint "73"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}}
								}
							}
							{"delay"
								{time 0.1}
							}
							{"switch"
								{"case"
									{condition
										{type cmp_i}
										{var "gun1_tele$"}
										{op "<<"}
										{value 2}
									}
									{"set_i"
										{var "gun1_tele$"}
										{op "+"}
										{value 1}
									}
								}
								{"default"
									{"set_i"
										{var "gun1_tele$"}
										{op "="}
										{value 0}
									}
								}
							}
						}
					}
					{"default"
						{"switch"
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 1}}
{"waypoint"
							{who
								{type actor}
								{actors
									{ignore_captured_by_user 0}
									{tag _botsf1_ct}
									{type vehicle}
									{state operatable}
								}
							}
							{action
								{type start}
								{waypoint "11020"}
								{make_squad}
								{approach "safe teleport"}
							}
						}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 2}}
{"waypoint"
							{who
								{type actor}
								{actors
									{ignore_captured_by_user 0}
									{tag _botsf1_ct}
									{type vehicle}
									{state operatable}
								}
							}
							{action
								{type start}
								{waypoint "12020"}
								{make_squad}
								{approach "safe teleport"}
							}
						}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 3}}
{"waypoint"
							{who
								{type actor}
								{actors
									{ignore_captured_by_user 0}
									{tag _botsf1_ct}
									{type vehicle}
									{state operatable}
								}
							}
							{action
								{type start}
								{waypoint "13020"}
								{make_squad}
								{approach "safe teleport"}
							}
						}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 4}}
{"waypoint"
							{who
								{type actor}
								{actors
									{ignore_captured_by_user 0}
									{tag _botsf1_ct}
									{type vehicle}
									{state operatable}
								}
							}
							{action
								{type start}
								{waypoint "14020"}
								{make_squad}
								{approach "safe teleport"}
							}
						}}
{"default"
{"waypoint"
							{who
								{type actor}
								{actors
									{ignore_captured_by_user 0}
									{tag _botsf1_ct}
									{type vehicle}
									{state operatable}
								}
							}
							{action
								{type start}
								{waypoint "20"}
								{make_squad}
								{approach "safe teleport"}
							}
						}}}
						{"switch"
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 1}}
{"waypoint"
							{who
								{type actor}
								{actors
									{ignore_captured_by_user 0}
									{tag _botsf1_h}
									{type human}
									{state operatable}
								}
							}
							{action
								{type start}
								{waypoint "11001"}
								{make_squad}
								{approach "safe teleport"}
							}
						}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 2}}
{"waypoint"
							{who
								{type actor}
								{actors
									{ignore_captured_by_user 0}
									{tag _botsf1_h}
									{type human}
									{state operatable}
								}
							}
							{action
								{type start}
								{waypoint "12001"}
								{make_squad}
								{approach "safe teleport"}
							}
						}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 3}}
{"waypoint"
							{who
								{type actor}
								{actors
									{ignore_captured_by_user 0}
									{tag _botsf1_h}
									{type human}
									{state operatable}
								}
							}
							{action
								{type start}
								{waypoint "13001"}
								{make_squad}
								{approach "safe teleport"}
							}
						}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 4}}
{"waypoint"
							{who
								{type actor}
								{actors
									{ignore_captured_by_user 0}
									{tag _botsf1_h}
									{type human}
									{state operatable}
								}
							}
							{action
								{type start}
								{waypoint "14001"}
								{make_squad}
								{approach "safe teleport"}
							}
						}}
{"default"
{"waypoint"
							{who
								{type actor}
								{actors
									{ignore_captured_by_user 0}
									{tag _botsf1_h}
									{type human}
									{state operatable}
								}
							}
							{action
								{type start}
								{waypoint "1"}
								{make_squad}
								{approach "safe teleport"}
							}
						}}}
						{"delay"
							{time 0.1}
						}
						{"if"
							{condition
								{type entities}
								{selector
									{ignore_captured_by_user 0}
									{tag _botsf1_artyc}
									{zone "gamezone"}
									{type vehicle}
									{state inhabited}
								}
							}
							{"switch"
								{"case"
									{condition
										{type cmp_i}
										{var "arty1_rnd$"}
										{op "=="}
										{value 0}
									}
									{"switch"
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 1}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf1_artyc}
											}
										}
										{action
											{type start}
											{waypoint "11170"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 2}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf1_artyc}
											}
										}
										{action
											{type start}
											{waypoint "12170"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 3}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf1_artyc}
											}
										}
										{action
											{type start}
											{waypoint "13170"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 4}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf1_artyc}
											}
										}
										{action
											{type start}
											{waypoint "14170"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"default"
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf1_artyc}
											}
										}
										{action
											{type start}
											{waypoint "170"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}}
								}
								{"case"
									{condition
										{type cmp_i}
										{var "arty1_rnd$"}
										{op "=="}
										{value 1}
									}
									{"switch"
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 1}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf1_artyc}
											}
										}
										{action
											{type start}
											{waypoint "11171"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 2}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf1_artyc}
											}
										}
										{action
											{type start}
											{waypoint "12171"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 3}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf1_artyc}
											}
										}
										{action
											{type start}
											{waypoint "13171"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 4}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf1_artyc}
											}
										}
										{action
											{type start}
											{waypoint "14171"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"default"
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf1_artyc}
											}
										}
										{action
											{type start}
											{waypoint "171"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}}
								}
								{"case"
									{condition
										{type cmp_i}
										{var "arty1_rnd$"}
										{op "=="}
										{value 2}
									}
									{"switch"
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 1}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf1_artyc}
											}
										}
										{action
											{type start}
											{waypoint "11172"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 2}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf1_artyc}
											}
										}
										{action
											{type start}
											{waypoint "12172"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 3}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf1_artyc}
											}
										}
										{action
											{type start}
											{waypoint "13172"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 4}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf1_artyc}
											}
										}
										{action
											{type start}
											{waypoint "14172"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"default"
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf1_artyc}
											}
										}
										{action
											{type start}
											{waypoint "172"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}}
								}
								{"case"
									{condition
										{type cmp_i}
										{var "arty1_rnd$"}
										{op "=="}
										{value 3}
									}
									{"switch"
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 1}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf1_artyc}
											}
										}
										{action
											{type start}
											{waypoint "11235"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 2}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf1_artyc}
											}
										}
										{action
											{type start}
											{waypoint "12235"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 3}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf1_artyc}
											}
										}
										{action
											{type start}
											{waypoint "13235"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 4}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf1_artyc}
											}
										}
										{action
											{type start}
											{waypoint "14235"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"default"
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf1_artyc}
											}
										}
										{action
											{type start}
											{waypoint "235"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}}
								}
								{"default"
									{"switch"
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 1}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf1_artyc}
											}
										}
										{action
											{type start}
											{waypoint "11090"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 2}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf1_artyc}
											}
										}
										{action
											{type start}
											{waypoint "12090"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 3}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf1_artyc}
											}
										}
										{action
											{type start}
											{waypoint "13090"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 4}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf1_artyc}
											}
										}
										{action
											{type start}
											{waypoint "14090"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"default"
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf1_artyc}
											}
										}
										{action
											{type start}
											{waypoint "90"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}}
								}
							}
							{"delay"
								{time 0.1}
							}
							{"switch"
								{"case"
									{condition
										{type cmp_i}
										{var "arty1_rnd$"}
										{op "<<"}
										{value 4}
									}
									{"set_i"
										{var "arty1_rnd$"}
										{op "+"}
										{value 1}
									}
								}
								{"default"
									{"set_i"
										{var "arty1_rnd$"}
										{op "="}
										{value 0}
									}
								}
							}
							{"entity_state"
								{selector
									{source standart}
									{ignore_captured_by_user 0}
									{tag _botsf1_artyc}
								}
								{tag_add "+bots_ct"}
							}
						}
						{"delay"
							{time 0.1}
						}
						{"if"
							{condition
								{type entities}
								{selector
									{ignore_captured_by_user 0}
									{tag _botsf1_v}
									{zone "gamezone"}
									{type vehicle}
									{state operatable}
								}
							}
							{"switch"
								{"case"
									{condition
										{type cmp_i}
										{var "gun1_tele$"}
										{op "=="}
										{value 0}
									}
									{"switch"
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 1}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf1_v}
											}
										}
										{action
											{type start}
											{waypoint "11091"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 2}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf1_v}
											}
										}
										{action
											{type start}
											{waypoint "12091"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 3}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf1_v}
											}
										}
										{action
											{type start}
											{waypoint "13091"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 4}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf1_v}
											}
										}
										{action
											{type start}
											{waypoint "14091"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"default"
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf1_v}
											}
										}
										{action
											{type start}
											{waypoint "91"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}}
								}
								{"case"
									{condition
										{type cmp_i}
										{var "gun1_tele$"}
										{op "=="}
										{value 1}
									}
									{"switch"
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 1}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf1_v}
											}
										}
										{action
											{type start}
											{waypoint "11092"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 2}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf1_v}
											}
										}
										{action
											{type start}
											{waypoint "12092"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 3}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf1_v}
											}
										}
										{action
											{type start}
											{waypoint "13092"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 4}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf1_v}
											}
										}
										{action
											{type start}
											{waypoint "14092"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"default"
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf1_v}
											}
										}
										{action
											{type start}
											{waypoint "92"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}}
								}
								{"default"
									{"switch"
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 1}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf1_v}
											}
										}
										{action
											{type start}
											{waypoint "11093"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 2}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf1_v}
											}
										}
										{action
											{type start}
											{waypoint "12093"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 3}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf1_v}
											}
										}
										{action
											{type start}
											{waypoint "13093"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 4}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf1_v}
											}
										}
										{action
											{type start}
											{waypoint "14093"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"default"
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf1_v}
											}
										}
										{action
											{type start}
											{waypoint "93"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}}
								}
							}
							{"delay"
								{time 0.1}
							}
							{"switch"
								{"case"
									{condition
										{type cmp_i}
										{var "gun1_tele$"}
										{op "<<"}
										{value 2}
									}
									{"set_i"
										{var "gun1_tele$"}
										{op "+"}
										{value 1}
									}
								}
								{"default"
									{"set_i"
										{var "gun1_tele$"}
										{op "="}
										{value 0}
									}
								}
							}
						}
					}
				}
				{"delay"
					{time 0.1}
				}
				{"entity_state"
					{selector
						{source standart}
						{ignore_captured_by_user 0}
						{tag _botsf1_h}
					}
					{tag_add "+garrisoned"}
					{tag_remove "_garrison_todo+"}
				}
				{"entity_state"
					{selector
						{source standart}
						{ignore_captured_by_user 0}
						{tag _botsf1_artyc}
					}
					{tag_add "+garrisoned"}
					{tag_remove "_garrison_todo+"}
				}
				{"delay"
					{time 0.1}
				}
				{"entity_state"
					{selector
						{source standart}
						{ignore_captured_by_user 0}
						{tag _botsf1_h}
					}
					{tag_remove _botsf1_h}
				}
				{"entity_state"
					{selector
						{source standart}
						{ignore_captured_by_user 0}
						{tag _botsf1_artyc}
					}
					{tag_remove _botsf1_artyc}
				}
			}
			{"flag2_bots_d"
				{"entity_state"
					{selector
						{source advanced}
						{ignore_captured_by_user 0}
						{group
							{select
								{tag
									{tag "_garrison_todo+"}
								}
							}
							{include
								{zone
									{zone "forward2"}
								}
								{prop
									{prop human}
								}
								{state
									{state operatable}
								}
							}
							{exclude
								{state
									{state inactive}
								}
								{state
									{state linked}
								}
							}
						}
						{amount 2
						}
					}
					{tag_add _botsf2_h}
				}
				{"entity_state"
					{selector
						{source advanced}
						{ignore_captured_by_user 0}
						{group
							{select
								{tag
									{tag "_garrison_todo+"}
								}
							}
							{include
								{zone
									{zone "forward2"}
								}
								{prop
									{prop vehicle}
								}
								{state
									{state operatable}
								}
							}
							{exclude
								{prop
									{prop car}
								}
								{prop
									{prop tank}
								}
								{prop
									{prop detect_artillery}
								}
								{prop
									{prop detect_artillery_small}
								}
							}
						}
						{amount 1
						}
					}
					{tag_add _botsf2_v}
				}
				{"delay"
					{time 0.1}
				}
				{"entity_state"
					{selector
						{source advanced}
						{ignore_captured_by_user 0}
						{group
							{select
								{tag
									{tag "_garrison_todo+"}
								}
							}
							{include
								{zone
									{zone "forward2"}
								}
								{prop
									{prop vehicle}
								}
								{state
									{state operatable}
								}
							}
							{exclude
								{tag
									{tag _botsf2_v}
								}
								{prop
									{prop detect_artillery}
								}
								{prop
									{prop detect_artillery_small}
								}
							}
						}
						{amount 1
						}
					}
					{tag_add _botsf2_ct}
				}
				{"delay"
					{time 0.1}
				}
				{"entity_state"
					{selector
						{source advanced}
						{ignore_captured_by_user 0}
						{group
							{select
								{tag
									{tag "_garrison_todo+"}
								}
							}
							{include
								{zone
									{zone "forward2"}
								}
								{prop
									{prop vehicle}
								}
								{state
									{state operatable}
								}
							}
							{exclude
								{tag
									{tag _botsf2_v}
								}
								{tag
									{tag _botsf2_ct}
								}
							}
						}
						{amount 1
						}
					}
					{tag_add _botsf2_artyc}
				}
				{"delay"
					{time 0.1}
				}
				{"entity_state"
					{selector
						{source standart}
						{ignore_captured_by_user 0}
						{tag _botsf2_v}
					}
					{tag_add "+garrisoned"}
					{tag_remove "_garrison_todo+"}
				}
				{"switch"
					{"case"
						{condition
							{type cmp_i}
							{var "bots_spawnside$"}
							{op "=="}
							{value 1}
						}
						{"switch"
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 5}}
{"waypoint"
							{who
								{type actor}
								{actors
									{ignore_captured_by_user 0}
									{tag _botsf2_ct}
									{type vehicle}
									{state operatable}
								}
							}
							{action
								{type start}
								{waypoint "15016"}
								{make_squad}
								{approach "safe teleport"}
							}
						}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 6}}
{"waypoint"
							{who
								{type actor}
								{actors
									{ignore_captured_by_user 0}
									{tag _botsf2_ct}
									{type vehicle}
									{state operatable}
								}
							}
							{action
								{type start}
								{waypoint "16016"}
								{make_squad}
								{approach "safe teleport"}
							}
						}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 7}}
{"waypoint"
							{who
								{type actor}
								{actors
									{ignore_captured_by_user 0}
									{tag _botsf2_ct}
									{type vehicle}
									{state operatable}
								}
							}
							{action
								{type start}
								{waypoint "17016"}
								{make_squad}
								{approach "safe teleport"}
							}
						}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 8}}
{"waypoint"
							{who
								{type actor}
								{actors
									{ignore_captured_by_user 0}
									{tag _botsf2_ct}
									{type vehicle}
									{state operatable}
								}
							}
							{action
								{type start}
								{waypoint "18016"}
								{make_squad}
								{approach "safe teleport"}
							}
						}}
{"default"
{"waypoint"
							{who
								{type actor}
								{actors
									{ignore_captured_by_user 0}
									{tag _botsf2_ct}
									{type vehicle}
									{state operatable}
								}
							}
							{action
								{type start}
								{waypoint "16"}
								{make_squad}
								{approach "safe teleport"}
							}
						}}}
						{"switch"
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 5}}
{"waypoint"
							{who
								{type actor}
								{actors
									{ignore_captured_by_user 0}
									{tag _botsf2_h}
									{type human}
									{state operatable}
								}
							}
							{action
								{type start}
								{waypoint "15002"}
								{make_squad}
								{approach "safe teleport"}
							}
						}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 6}}
{"waypoint"
							{who
								{type actor}
								{actors
									{ignore_captured_by_user 0}
									{tag _botsf2_h}
									{type human}
									{state operatable}
								}
							}
							{action
								{type start}
								{waypoint "16002"}
								{make_squad}
								{approach "safe teleport"}
							}
						}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 7}}
{"waypoint"
							{who
								{type actor}
								{actors
									{ignore_captured_by_user 0}
									{tag _botsf2_h}
									{type human}
									{state operatable}
								}
							}
							{action
								{type start}
								{waypoint "17002"}
								{make_squad}
								{approach "safe teleport"}
							}
						}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 8}}
{"waypoint"
							{who
								{type actor}
								{actors
									{ignore_captured_by_user 0}
									{tag _botsf2_h}
									{type human}
									{state operatable}
								}
							}
							{action
								{type start}
								{waypoint "18002"}
								{make_squad}
								{approach "safe teleport"}
							}
						}}
{"default"
{"waypoint"
							{who
								{type actor}
								{actors
									{ignore_captured_by_user 0}
									{tag _botsf2_h}
									{type human}
									{state operatable}
								}
							}
							{action
								{type start}
								{waypoint "2"}
								{make_squad}
								{approach "safe teleport"}
							}
						}}}
						{"delay"
							{time 0.1}
						}
						{"if"
							{condition
								{type entities}
								{selector
									{ignore_captured_by_user 0}
									{tag _botsf2_artyc}
									{zone "gamezone"}
									{type vehicle}
									{state inhabited}
								}
							}
							{"switch"
								{"case"
									{condition
										{type cmp_i}
										{var "arty2_rnd$"}
										{op "=="}
										{value 0}
									}
									{"switch"
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 5}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf2_artyc}
											}
										}
										{action
											{type start}
											{waypoint "15122"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 6}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf2_artyc}
											}
										}
										{action
											{type start}
											{waypoint "16122"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 7}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf2_artyc}
											}
										}
										{action
											{type start}
											{waypoint "17122"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 8}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf2_artyc}
											}
										}
										{action
											{type start}
											{waypoint "18122"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"default"
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf2_artyc}
											}
										}
										{action
											{type start}
											{waypoint "122"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}}
								}
								{"case"
									{condition
										{type cmp_i}
										{var "arty2_rnd$"}
										{op "=="}
										{value 1}
									}
									{"switch"
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 5}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf2_artyc}
											}
										}
										{action
											{type start}
											{waypoint "15123"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 6}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf2_artyc}
											}
										}
										{action
											{type start}
											{waypoint "16123"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 7}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf2_artyc}
											}
										}
										{action
											{type start}
											{waypoint "17123"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 8}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf2_artyc}
											}
										}
										{action
											{type start}
											{waypoint "18123"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"default"
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf2_artyc}
											}
										}
										{action
											{type start}
											{waypoint "123"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}}
								}
								{"case"
									{condition
										{type cmp_i}
										{var "arty2_rnd$"}
										{op "=="}
										{value 2}
									}
									{"switch"
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 5}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf2_artyc}
											}
										}
										{action
											{type start}
											{waypoint "15124"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 6}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf2_artyc}
											}
										}
										{action
											{type start}
											{waypoint "16124"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 7}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf2_artyc}
											}
										}
										{action
											{type start}
											{waypoint "17124"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 8}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf2_artyc}
											}
										}
										{action
											{type start}
											{waypoint "18124"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"default"
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf2_artyc}
											}
										}
										{action
											{type start}
											{waypoint "124"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}}
								}
								{"case"
									{condition
										{type cmp_i}
										{var "arty2_rnd$"}
										{op "=="}
										{value 3}
									}
									{"switch"
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 5}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf2_artyc}
											}
										}
										{action
											{type start}
											{waypoint "15231"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 6}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf2_artyc}
											}
										}
										{action
											{type start}
											{waypoint "16231"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 7}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf2_artyc}
											}
										}
										{action
											{type start}
											{waypoint "17231"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 8}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf2_artyc}
											}
										}
										{action
											{type start}
											{waypoint "18231"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"default"
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf2_artyc}
											}
										}
										{action
											{type start}
											{waypoint "231"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}}
								}
								{"default"
									{"switch"
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 5}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf2_artyc}
											}
										}
										{action
											{type start}
											{waypoint "15074"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 6}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf2_artyc}
											}
										}
										{action
											{type start}
											{waypoint "16074"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 7}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf2_artyc}
											}
										}
										{action
											{type start}
											{waypoint "17074"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 8}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf2_artyc}
											}
										}
										{action
											{type start}
											{waypoint "18074"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"default"
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf2_artyc}
											}
										}
										{action
											{type start}
											{waypoint "74"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}}
								}
							}
							{"delay"
								{time 0.1}
							}
							{"switch"
								{"case"
									{condition
										{type cmp_i}
										{var "arty2_rnd$"}
										{op "<<"}
										{value 4}
									}
									{"set_i"
										{var "arty2_rnd$"}
										{op "+"}
										{value 1}
									}
								}
								{"default"
									{"set_i"
										{var "arty2_rnd$"}
										{op "="}
										{value 0}
									}
								}
							}
							{"entity_state"
								{selector
									{source standart}
									{ignore_captured_by_user 0}
									{tag _botsf2_artyc}
								}
								{tag_add "+bots_ct"}
							}
						}
						{"delay"
							{time 0.1}
						}
						{"if"
							{condition
								{type entities}
								{selector
									{ignore_captured_by_user 0}
									{tag _botsf2_v}
									{zone "gamezone"}
									{type vehicle}
									{state operatable}
								}
							}
							{"switch"
								{"case"
									{condition
										{type cmp_i}
										{var "gun2_tele$"}
										{op "=="}
										{value 0}
									}
									{"switch"
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 5}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf2_v}
											}
										}
										{action
											{type start}
											{waypoint "15075"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 6}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf2_v}
											}
										}
										{action
											{type start}
											{waypoint "16075"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 7}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf2_v}
											}
										}
										{action
											{type start}
											{waypoint "17075"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 8}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf2_v}
											}
										}
										{action
											{type start}
											{waypoint "18075"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"default"
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf2_v}
											}
										}
										{action
											{type start}
											{waypoint "75"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}}
								}
								{"case"
									{condition
										{type cmp_i}
										{var "gun2_tele$"}
										{op "=="}
										{value 1}
									}
									{"switch"
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 5}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf2_v}
											}
										}
										{action
											{type start}
											{waypoint "15076"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 6}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf2_v}
											}
										}
										{action
											{type start}
											{waypoint "16076"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 7}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf2_v}
											}
										}
										{action
											{type start}
											{waypoint "17076"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 8}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf2_v}
											}
										}
										{action
											{type start}
											{waypoint "18076"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"default"
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf2_v}
											}
										}
										{action
											{type start}
											{waypoint "76"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}}
								}
								{"default"
									{"switch"
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 5}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf2_v}
											}
										}
										{action
											{type start}
											{waypoint "15077"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 6}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf2_v}
											}
										}
										{action
											{type start}
											{waypoint "16077"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 7}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf2_v}
											}
										}
										{action
											{type start}
											{waypoint "17077"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 8}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf2_v}
											}
										}
										{action
											{type start}
											{waypoint "18077"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"default"
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf2_v}
											}
										}
										{action
											{type start}
											{waypoint "77"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}}
								}
							}
							{"delay"
								{time 0.1}
							}
							{"switch"
								{"case"
									{condition
										{type cmp_i}
										{var "gun2_tele$"}
										{op "<<"}
										{value 2}
									}
									{"set_i"
										{var "gun2_tele$"}
										{op "+"}
										{value 1}
									}
								}
								{"default"
									{"set_i"
										{var "gun2_tele$"}
										{op "="}
										{value 0}
									}
								}
							}
						}
					}
					{"default"
						{"switch"
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 1}}
{"waypoint"
							{who
								{type actor}
								{actors
									{ignore_captured_by_user 0}
									{tag _botsf2_ct}
									{type vehicle}
									{state operatable}
								}
							}
							{action
								{type start}
								{waypoint "11021"}
								{make_squad}
								{approach "safe teleport"}
							}
						}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 2}}
{"waypoint"
							{who
								{type actor}
								{actors
									{ignore_captured_by_user 0}
									{tag _botsf2_ct}
									{type vehicle}
									{state operatable}
								}
							}
							{action
								{type start}
								{waypoint "12021"}
								{make_squad}
								{approach "safe teleport"}
							}
						}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 3}}
{"waypoint"
							{who
								{type actor}
								{actors
									{ignore_captured_by_user 0}
									{tag _botsf2_ct}
									{type vehicle}
									{state operatable}
								}
							}
							{action
								{type start}
								{waypoint "13021"}
								{make_squad}
								{approach "safe teleport"}
							}
						}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 4}}
{"waypoint"
							{who
								{type actor}
								{actors
									{ignore_captured_by_user 0}
									{tag _botsf2_ct}
									{type vehicle}
									{state operatable}
								}
							}
							{action
								{type start}
								{waypoint "14021"}
								{make_squad}
								{approach "safe teleport"}
							}
						}}
{"default"
{"waypoint"
							{who
								{type actor}
								{actors
									{ignore_captured_by_user 0}
									{tag _botsf2_ct}
									{type vehicle}
									{state operatable}
								}
							}
							{action
								{type start}
								{waypoint "21"}
								{make_squad}
								{approach "safe teleport"}
							}
						}}}
						{"switch"
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 1}}
{"waypoint"
							{who
								{type actor}
								{actors
									{ignore_captured_by_user 0}
									{tag _botsf2_h}
									{type human}
									{state operatable}
								}
							}
							{action
								{type start}
								{waypoint "11002"}
								{make_squad}
								{approach "safe teleport"}
							}
						}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 2}}
{"waypoint"
							{who
								{type actor}
								{actors
									{ignore_captured_by_user 0}
									{tag _botsf2_h}
									{type human}
									{state operatable}
								}
							}
							{action
								{type start}
								{waypoint "12002"}
								{make_squad}
								{approach "safe teleport"}
							}
						}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 3}}
{"waypoint"
							{who
								{type actor}
								{actors
									{ignore_captured_by_user 0}
									{tag _botsf2_h}
									{type human}
									{state operatable}
								}
							}
							{action
								{type start}
								{waypoint "13002"}
								{make_squad}
								{approach "safe teleport"}
							}
						}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 4}}
{"waypoint"
							{who
								{type actor}
								{actors
									{ignore_captured_by_user 0}
									{tag _botsf2_h}
									{type human}
									{state operatable}
								}
							}
							{action
								{type start}
								{waypoint "14002"}
								{make_squad}
								{approach "safe teleport"}
							}
						}}
{"default"
{"waypoint"
							{who
								{type actor}
								{actors
									{ignore_captured_by_user 0}
									{tag _botsf2_h}
									{type human}
									{state operatable}
								}
							}
							{action
								{type start}
								{waypoint "2"}
								{make_squad}
								{approach "safe teleport"}
							}
						}}}
						{"delay"
							{time 0.1}
						}
						{"if"
							{condition
								{type entities}
								{selector
									{ignore_captured_by_user 0}
									{tag _botsf2_artyc}
									{zone "gamezone"}
									{type vehicle}
									{state inhabited}
								}
							}
							{"switch"
								{"case"
									{condition
										{type cmp_i}
										{var "arty2_rnd$"}
										{op "=="}
										{value 0}
									}
									{"switch"
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 1}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf2_artyc}
											}
										}
										{action
											{type start}
											{waypoint "11182"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 2}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf2_artyc}
											}
										}
										{action
											{type start}
											{waypoint "12182"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 3}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf2_artyc}
											}
										}
										{action
											{type start}
											{waypoint "13182"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 4}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf2_artyc}
											}
										}
										{action
											{type start}
											{waypoint "14182"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"default"
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf2_artyc}
											}
										}
										{action
											{type start}
											{waypoint "182"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}}
								}
								{"case"
									{condition
										{type cmp_i}
										{var "arty2_rnd$"}
										{op "=="}
										{value 1}
									}
									{"switch"
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 1}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf2_artyc}
											}
										}
										{action
											{type start}
											{waypoint "11183"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 2}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf2_artyc}
											}
										}
										{action
											{type start}
											{waypoint "12183"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 3}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf2_artyc}
											}
										}
										{action
											{type start}
											{waypoint "13183"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 4}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf2_artyc}
											}
										}
										{action
											{type start}
											{waypoint "14183"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"default"
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf2_artyc}
											}
										}
										{action
											{type start}
											{waypoint "183"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}}
								}
								{"case"
									{condition
										{type cmp_i}
										{var "arty2_rnd$"}
										{op "=="}
										{value 2}
									}
									{"switch"
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 1}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf2_artyc}
											}
										}
										{action
											{type start}
											{waypoint "11184"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 2}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf2_artyc}
											}
										}
										{action
											{type start}
											{waypoint "12184"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 3}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf2_artyc}
											}
										}
										{action
											{type start}
											{waypoint "13184"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 4}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf2_artyc}
											}
										}
										{action
											{type start}
											{waypoint "14184"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"default"
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf2_artyc}
											}
										}
										{action
											{type start}
											{waypoint "184"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}}
								}
								{"case"
									{condition
										{type cmp_i}
										{var "arty2_rnd$"}
										{op "=="}
										{value 3}
									}
									{"switch"
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 1}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf2_artyc}
											}
										}
										{action
											{type start}
											{waypoint "11236"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 2}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf2_artyc}
											}
										}
										{action
											{type start}
											{waypoint "12236"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 3}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf2_artyc}
											}
										}
										{action
											{type start}
											{waypoint "13236"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 4}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf2_artyc}
											}
										}
										{action
											{type start}
											{waypoint "14236"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"default"
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf2_artyc}
											}
										}
										{action
											{type start}
											{waypoint "236"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}}
								}
								{"default"
									{"switch"
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 1}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf2_artyc}
											}
										}
										{action
											{type start}
											{waypoint "11094"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 2}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf2_artyc}
											}
										}
										{action
											{type start}
											{waypoint "12094"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 3}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf2_artyc}
											}
										}
										{action
											{type start}
											{waypoint "13094"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 4}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf2_artyc}
											}
										}
										{action
											{type start}
											{waypoint "14094"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"default"
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf2_artyc}
											}
										}
										{action
											{type start}
											{waypoint "94"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}}
								}
							}
							{"delay"
								{time 0.1}
							}
							{"switch"
								{"case"
									{condition
										{type cmp_i}
										{var "arty2_rnd$"}
										{op "<<"}
										{value 4}
									}
									{"set_i"
										{var "arty2_rnd$"}
										{op "+"}
										{value 1}
									}
								}
								{"default"
									{"set_i"
										{var "arty2_rnd$"}
										{op "="}
										{value 0}
									}
								}
							}
							{"entity_state"
								{selector
									{source standart}
									{ignore_captured_by_user 0}
									{tag _botsf2_artyc}
								}
								{tag_add "+bots_ct"}
							}
						}
						{"delay"
							{time 0.1}
						}
						{"if"
							{condition
								{type entities}
								{selector
									{ignore_captured_by_user 0}
									{tag _botsf2_v}
									{zone "gamezone"}
									{type vehicle}
									{state operatable}
								}
							}
							{"switch"
								{"case"
									{condition
										{type cmp_i}
										{var "gun2_tele$"}
										{op "=="}
										{value 0}
									}
									{"switch"
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 1}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf2_v}
											}
										}
										{action
											{type start}
											{waypoint "11095"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 2}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf2_v}
											}
										}
										{action
											{type start}
											{waypoint "12095"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 3}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf2_v}
											}
										}
										{action
											{type start}
											{waypoint "13095"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 4}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf2_v}
											}
										}
										{action
											{type start}
											{waypoint "14095"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"default"
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf2_v}
											}
										}
										{action
											{type start}
											{waypoint "95"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}}
								}
								{"case"
									{condition
										{type cmp_i}
										{var "gun2_tele$"}
										{op "=="}
										{value 1}
									}
									{"switch"
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 1}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf2_v}
											}
										}
										{action
											{type start}
											{waypoint "11096"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 2}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf2_v}
											}
										}
										{action
											{type start}
											{waypoint "12096"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 3}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf2_v}
											}
										}
										{action
											{type start}
											{waypoint "13096"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 4}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf2_v}
											}
										}
										{action
											{type start}
											{waypoint "14096"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"default"
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf2_v}
											}
										}
										{action
											{type start}
											{waypoint "96"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}}
								}
								{"default"
									{"switch"
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 1}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf2_v}
											}
										}
										{action
											{type start}
											{waypoint "11097"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 2}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf2_v}
											}
										}
										{action
											{type start}
											{waypoint "12097"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 3}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf2_v}
											}
										}
										{action
											{type start}
											{waypoint "13097"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 4}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf2_v}
											}
										}
										{action
											{type start}
											{waypoint "14097"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"default"
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf2_v}
											}
										}
										{action
											{type start}
											{waypoint "97"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}}
								}
							}
							{"delay"
								{time 0.1}
							}
							{"switch"
								{"case"
									{condition
										{type cmp_i}
										{var "gun2_tele$"}
										{op "<<"}
										{value 2}
									}
									{"set_i"
										{var "gun2_tele$"}
										{op "+"}
										{value 1}
									}
								}
								{"default"
									{"set_i"
										{var "gun2_tele$"}
										{op "="}
										{value 0}
									}
								}
							}
						}
					}
				}
				{"delay"
					{time 0.1}
				}
				{"entity_state"
					{selector
						{source standart}
						{ignore_captured_by_user 0}
						{tag _botsf2_h}
					}
					{tag_add "+garrisoned"}
					{tag_remove "_garrison_todo+"}
				}
				{"entity_state"
					{selector
						{source standart}
						{ignore_captured_by_user 0}
						{tag _botsf2_artyc}
					}
					{tag_add "+garrisoned"}
					{tag_remove "_garrison_todo+"}
				}
				{"delay"
					{time 0.1}
				}
				{"entity_state"
					{selector
						{source standart}
						{ignore_captured_by_user 0}
						{tag _botsf2_h}
					}
					{tag_remove _botsf2_h}
				}
				{"entity_state"
					{selector
						{source standart}
						{ignore_captured_by_user 0}
						{tag _botsf2_artyc}
					}
					{tag_remove _botsf2_artyc}
				}
			}
			{"flag3_bots_d"
				{"entity_state"
					{selector
						{source advanced}
						{ignore_captured_by_user 0}
						{group
							{select
								{tag
									{tag "_garrison_todo+"}
								}
							}
							{include
								{zone
									{zone "forward3"}
								}
								{prop
									{prop human}
								}
								{state
									{state operatable}
								}
							}
							{exclude
								{state
									{state inactive}
								}
								{state
									{state linked}
								}
							}
						}
						{amount 2
						}
					}
					{tag_add _botsf3_h}
				}
				{"entity_state"
					{selector
						{source advanced}
						{ignore_captured_by_user 0}
						{group
							{select
								{tag
									{tag "_garrison_todo+"}
								}
							}
							{include
								{zone
									{zone "forward3"}
								}
								{prop
									{prop vehicle}
								}
								{state
									{state operatable}
								}
							}
							{exclude
								{prop
									{prop car}
								}
								{prop
									{prop tank}
								}
								{prop
									{prop detect_artillery}
								}
								{prop
									{prop detect_artillery_small}
								}
							}
						}
						{amount 1
						}
					}
					{tag_add _botsf3_v}
				}
				{"delay"
					{time 0.1}
				}
				{"entity_state"
					{selector
						{source advanced}
						{ignore_captured_by_user 0}
						{group
							{select
								{tag
									{tag "_garrison_todo+"}
								}
							}
							{include
								{zone
									{zone "forward3"}
								}
								{prop
									{prop vehicle}
								}
								{state
									{state operatable}
								}
							}
							{exclude
								{tag
									{tag _botsf3_v}
								}
								{prop
									{prop detect_artillery}
								}
								{prop
									{prop detect_artillery_small}
								}
							}
						}
						{amount 1
						}
					}
					{tag_add _botsf3_ct}
				}
				{"delay"
					{time 0.1}
				}
				{"entity_state"
					{selector
						{source advanced}
						{ignore_captured_by_user 0}
						{group
							{select
								{tag
									{tag "_garrison_todo+"}
								}
							}
							{include
								{zone
									{zone "forward3"}
								}
								{prop
									{prop vehicle}
								}
								{state
									{state operatable}
								}
							}
							{exclude
								{tag
									{tag _botsf3_v}
								}
								{tag
									{tag _botsf3_ct}
								}
							}
						}
						{amount 1
						}
					}
					{tag_add _botsf3_artyc}
				}
				{"delay"
					{time 0.1}
				}
				{"entity_state"
					{selector
						{source standart}
						{ignore_captured_by_user 0}
						{tag _botsf3_v}
					}
					{tag_add "+garrisoned"}
					{tag_remove "_garrison_todo+"}
				}
				{"switch"
					{"case"
						{condition
							{type cmp_i}
							{var "bots_spawnside$"}
							{op "=="}
							{value 1}
						}
						{"switch"
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 5}}
{"waypoint"
							{who
								{type actor}
								{actors
									{ignore_captured_by_user 0}
									{tag _botsf3_ct}
									{type vehicle}
									{state operatable}
								}
							}
							{action
								{type start}
								{waypoint "15017"}
								{make_squad}
								{approach "safe teleport"}
							}
						}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 6}}
{"waypoint"
							{who
								{type actor}
								{actors
									{ignore_captured_by_user 0}
									{tag _botsf3_ct}
									{type vehicle}
									{state operatable}
								}
							}
							{action
								{type start}
								{waypoint "16017"}
								{make_squad}
								{approach "safe teleport"}
							}
						}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 7}}
{"waypoint"
							{who
								{type actor}
								{actors
									{ignore_captured_by_user 0}
									{tag _botsf3_ct}
									{type vehicle}
									{state operatable}
								}
							}
							{action
								{type start}
								{waypoint "17017"}
								{make_squad}
								{approach "safe teleport"}
							}
						}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 8}}
{"waypoint"
							{who
								{type actor}
								{actors
									{ignore_captured_by_user 0}
									{tag _botsf3_ct}
									{type vehicle}
									{state operatable}
								}
							}
							{action
								{type start}
								{waypoint "18017"}
								{make_squad}
								{approach "safe teleport"}
							}
						}}
{"default"
{"waypoint"
							{who
								{type actor}
								{actors
									{ignore_captured_by_user 0}
									{tag _botsf3_ct}
									{type vehicle}
									{state operatable}
								}
							}
							{action
								{type start}
								{waypoint "17"}
								{make_squad}
								{approach "safe teleport"}
							}
						}}}
						{"switch"
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 5}}
{"waypoint"
							{who
								{type actor}
								{actors
									{ignore_captured_by_user 0}
									{tag _botsf3_h}
									{type human}
									{state operatable}
								}
							}
							{action
								{type start}
								{waypoint "15003"}
								{make_squad}
								{approach "safe teleport"}
							}
						}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 6}}
{"waypoint"
							{who
								{type actor}
								{actors
									{ignore_captured_by_user 0}
									{tag _botsf3_h}
									{type human}
									{state operatable}
								}
							}
							{action
								{type start}
								{waypoint "16003"}
								{make_squad}
								{approach "safe teleport"}
							}
						}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 7}}
{"waypoint"
							{who
								{type actor}
								{actors
									{ignore_captured_by_user 0}
									{tag _botsf3_h}
									{type human}
									{state operatable}
								}
							}
							{action
								{type start}
								{waypoint "17003"}
								{make_squad}
								{approach "safe teleport"}
							}
						}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 8}}
{"waypoint"
							{who
								{type actor}
								{actors
									{ignore_captured_by_user 0}
									{tag _botsf3_h}
									{type human}
									{state operatable}
								}
							}
							{action
								{type start}
								{waypoint "18003"}
								{make_squad}
								{approach "safe teleport"}
							}
						}}
{"default"
{"waypoint"
							{who
								{type actor}
								{actors
									{ignore_captured_by_user 0}
									{tag _botsf3_h}
									{type human}
									{state operatable}
								}
							}
							{action
								{type start}
								{waypoint "3"}
								{make_squad}
								{approach "safe teleport"}
							}
						}}}
						{"delay"
							{time 0.1}
						}
						{"if"
							{condition
								{type entities}
								{selector
									{ignore_captured_by_user 0}
									{tag _botsf3_artyc}
									{zone "gamezone"}
									{type vehicle}
									{state inhabited}
								}
							}
							{"switch"
								{"case"
									{condition
										{type cmp_i}
										{var "arty3_rnd$"}
										{op "=="}
										{value 0}
									}
									{"switch"
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 5}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf3_artyc}
											}
										}
										{action
											{type start}
											{waypoint "15134"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 6}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf3_artyc}
											}
										}
										{action
											{type start}
											{waypoint "16134"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 7}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf3_artyc}
											}
										}
										{action
											{type start}
											{waypoint "17134"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 8}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf3_artyc}
											}
										}
										{action
											{type start}
											{waypoint "18134"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"default"
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf3_artyc}
											}
										}
										{action
											{type start}
											{waypoint "134"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}}
								}
								{"case"
									{condition
										{type cmp_i}
										{var "arty3_rnd$"}
										{op "=="}
										{value 1}
									}
									{"switch"
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 5}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf3_artyc}
											}
										}
										{action
											{type start}
											{waypoint "15135"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 6}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf3_artyc}
											}
										}
										{action
											{type start}
											{waypoint "16135"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 7}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf3_artyc}
											}
										}
										{action
											{type start}
											{waypoint "17135"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 8}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf3_artyc}
											}
										}
										{action
											{type start}
											{waypoint "18135"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"default"
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf3_artyc}
											}
										}
										{action
											{type start}
											{waypoint "135"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}}
								}
								{"case"
									{condition
										{type cmp_i}
										{var "arty3_rnd$"}
										{op "=="}
										{value 2}
									}
									{"switch"
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 5}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf3_artyc}
											}
										}
										{action
											{type start}
											{waypoint "15136"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 6}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf3_artyc}
											}
										}
										{action
											{type start}
											{waypoint "16136"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 7}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf3_artyc}
											}
										}
										{action
											{type start}
											{waypoint "17136"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 8}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf3_artyc}
											}
										}
										{action
											{type start}
											{waypoint "18136"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"default"
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf3_artyc}
											}
										}
										{action
											{type start}
											{waypoint "136"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}}
								}
								{"case"
									{condition
										{type cmp_i}
										{var "arty3_rnd$"}
										{op "=="}
										{value 3}
									}
									{"switch"
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 5}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf3_artyc}
											}
										}
										{action
											{type start}
											{waypoint "15232"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 6}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf3_artyc}
											}
										}
										{action
											{type start}
											{waypoint "16232"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 7}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf3_artyc}
											}
										}
										{action
											{type start}
											{waypoint "17232"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 8}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf3_artyc}
											}
										}
										{action
											{type start}
											{waypoint "18232"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"default"
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf3_artyc}
											}
										}
										{action
											{type start}
											{waypoint "232"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}}
								}
								{"default"
									{"switch"
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 5}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf3_artyc}
											}
										}
										{action
											{type start}
											{waypoint "15078"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 6}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf3_artyc}
											}
										}
										{action
											{type start}
											{waypoint "16078"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 7}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf3_artyc}
											}
										}
										{action
											{type start}
											{waypoint "17078"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 8}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf3_artyc}
											}
										}
										{action
											{type start}
											{waypoint "18078"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"default"
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf3_artyc}
											}
										}
										{action
											{type start}
											{waypoint "78"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}}
								}
							}
							{"delay"
								{time 0.1}
							}
							{"switch"
								{"case"
									{condition
										{type cmp_i}
										{var "arty3_rnd$"}
										{op "<<"}
										{value 4}
									}
									{"set_i"
										{var "arty3_rnd$"}
										{op "+"}
										{value 1}
									}
								}
								{"default"
									{"set_i"
										{var "arty3_rnd$"}
										{op "="}
										{value 0}
									}
								}
							}
							{"entity_state"
								{selector
									{source standart}
									{ignore_captured_by_user 0}
									{tag _botsf3_artyc}
								}
								{tag_add "+bots_ct"}
							}
						}
						{"delay"
							{time 0.1}
						}
						{"if"
							{condition
								{type entities}
								{selector
									{ignore_captured_by_user 0}
									{tag _botsf3_v}
									{zone "gamezone"}
									{type vehicle}
									{state operatable}
								}
							}
							{"switch"
								{"case"
									{condition
										{type cmp_i}
										{var "gun3_tele$"}
										{op "=="}
										{value 0}
									}
									{"switch"
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 5}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf3_v}
											}
										}
										{action
											{type start}
											{waypoint "15079"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 6}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf3_v}
											}
										}
										{action
											{type start}
											{waypoint "16079"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 7}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf3_v}
											}
										}
										{action
											{type start}
											{waypoint "17079"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 8}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf3_v}
											}
										}
										{action
											{type start}
											{waypoint "18079"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"default"
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf3_v}
											}
										}
										{action
											{type start}
											{waypoint "79"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}}
								}
								{"case"
									{condition
										{type cmp_i}
										{var "gun3_tele$"}
										{op "=="}
										{value 1}
									}
									{"switch"
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 5}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf3_v}
											}
										}
										{action
											{type start}
											{waypoint "15080"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 6}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf3_v}
											}
										}
										{action
											{type start}
											{waypoint "16080"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 7}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf3_v}
											}
										}
										{action
											{type start}
											{waypoint "17080"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 8}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf3_v}
											}
										}
										{action
											{type start}
											{waypoint "18080"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"default"
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf3_v}
											}
										}
										{action
											{type start}
											{waypoint "80"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}}
								}
								{"default"
									{"switch"
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 5}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf3_v}
											}
										}
										{action
											{type start}
											{waypoint "15081"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 6}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf3_v}
											}
										}
										{action
											{type start}
											{waypoint "16081"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 7}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf3_v}
											}
										}
										{action
											{type start}
											{waypoint "17081"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 8}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf3_v}
											}
										}
										{action
											{type start}
											{waypoint "18081"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"default"
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf3_v}
											}
										}
										{action
											{type start}
											{waypoint "81"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}}
								}
							}
							{"delay"
								{time 0.1}
							}
							{"switch"
								{"case"
									{condition
										{type cmp_i}
										{var "gun3_tele$"}
										{op "<<"}
										{value 2}
									}
									{"set_i"
										{var "gun3_tele$"}
										{op "+"}
										{value 1}
									}
								}
								{"default"
									{"set_i"
										{var "gun3_tele$"}
										{op "="}
										{value 0}
									}
								}
							}
						}
					}
					{"default"
						{"switch"
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 1}}
{"waypoint"
							{who
								{type actor}
								{actors
									{ignore_captured_by_user 0}
									{tag _botsf3_ct}
									{type vehicle}
									{state operatable}
								}
							}
							{action
								{type start}
								{waypoint "11022"}
								{make_squad}
								{approach "safe teleport"}
							}
						}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 2}}
{"waypoint"
							{who
								{type actor}
								{actors
									{ignore_captured_by_user 0}
									{tag _botsf3_ct}
									{type vehicle}
									{state operatable}
								}
							}
							{action
								{type start}
								{waypoint "12022"}
								{make_squad}
								{approach "safe teleport"}
							}
						}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 3}}
{"waypoint"
							{who
								{type actor}
								{actors
									{ignore_captured_by_user 0}
									{tag _botsf3_ct}
									{type vehicle}
									{state operatable}
								}
							}
							{action
								{type start}
								{waypoint "13022"}
								{make_squad}
								{approach "safe teleport"}
							}
						}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 4}}
{"waypoint"
							{who
								{type actor}
								{actors
									{ignore_captured_by_user 0}
									{tag _botsf3_ct}
									{type vehicle}
									{state operatable}
								}
							}
							{action
								{type start}
								{waypoint "14022"}
								{make_squad}
								{approach "safe teleport"}
							}
						}}
{"default"
{"waypoint"
							{who
								{type actor}
								{actors
									{ignore_captured_by_user 0}
									{tag _botsf3_ct}
									{type vehicle}
									{state operatable}
								}
							}
							{action
								{type start}
								{waypoint "22"}
								{make_squad}
								{approach "safe teleport"}
							}
						}}}
						{"switch"
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 1}}
{"waypoint"
							{who
								{type actor}
								{actors
									{ignore_captured_by_user 0}
									{tag _botsf3_h}
									{type human}
									{state operatable}
								}
							}
							{action
								{type start}
								{waypoint "11003"}
								{make_squad}
								{approach "safe teleport"}
							}
						}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 2}}
{"waypoint"
							{who
								{type actor}
								{actors
									{ignore_captured_by_user 0}
									{tag _botsf3_h}
									{type human}
									{state operatable}
								}
							}
							{action
								{type start}
								{waypoint "12003"}
								{make_squad}
								{approach "safe teleport"}
							}
						}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 3}}
{"waypoint"
							{who
								{type actor}
								{actors
									{ignore_captured_by_user 0}
									{tag _botsf3_h}
									{type human}
									{state operatable}
								}
							}
							{action
								{type start}
								{waypoint "13003"}
								{make_squad}
								{approach "safe teleport"}
							}
						}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 4}}
{"waypoint"
							{who
								{type actor}
								{actors
									{ignore_captured_by_user 0}
									{tag _botsf3_h}
									{type human}
									{state operatable}
								}
							}
							{action
								{type start}
								{waypoint "14003"}
								{make_squad}
								{approach "safe teleport"}
							}
						}}
{"default"
{"waypoint"
							{who
								{type actor}
								{actors
									{ignore_captured_by_user 0}
									{tag _botsf3_h}
									{type human}
									{state operatable}
								}
							}
							{action
								{type start}
								{waypoint "3"}
								{make_squad}
								{approach "safe teleport"}
							}
						}}}
						{"delay"
							{time 0.1}
						}
						{"if"
							{condition
								{type entities}
								{selector
									{ignore_captured_by_user 0}
									{tag _botsf3_artyc}
									{zone "gamezone"}
									{type vehicle}
									{state inhabited}
								}
							}
							{"switch"
								{"case"
									{condition
										{type cmp_i}
										{var "arty3_rnd$"}
										{op "=="}
										{value 0}
									}
									{"switch"
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 1}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf3_artyc}
											}
										}
										{action
											{type start}
											{waypoint "11194"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 2}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf3_artyc}
											}
										}
										{action
											{type start}
											{waypoint "12194"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 3}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf3_artyc}
											}
										}
										{action
											{type start}
											{waypoint "13194"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 4}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf3_artyc}
											}
										}
										{action
											{type start}
											{waypoint "14194"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"default"
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf3_artyc}
											}
										}
										{action
											{type start}
											{waypoint "194"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}}
								}
								{"case"
									{condition
										{type cmp_i}
										{var "arty3_rnd$"}
										{op "=="}
										{value 1}
									}
									{"switch"
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 1}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf3_artyc}
											}
										}
										{action
											{type start}
											{waypoint "11195"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 2}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf3_artyc}
											}
										}
										{action
											{type start}
											{waypoint "12195"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 3}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf3_artyc}
											}
										}
										{action
											{type start}
											{waypoint "13195"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 4}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf3_artyc}
											}
										}
										{action
											{type start}
											{waypoint "14195"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"default"
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf3_artyc}
											}
										}
										{action
											{type start}
											{waypoint "195"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}}
								}
								{"case"
									{condition
										{type cmp_i}
										{var "arty3_rnd$"}
										{op "=="}
										{value 2}
									}
									{"switch"
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 1}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf3_artyc}
											}
										}
										{action
											{type start}
											{waypoint "11196"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 2}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf3_artyc}
											}
										}
										{action
											{type start}
											{waypoint "12196"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 3}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf3_artyc}
											}
										}
										{action
											{type start}
											{waypoint "13196"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 4}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf3_artyc}
											}
										}
										{action
											{type start}
											{waypoint "14196"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"default"
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf3_artyc}
											}
										}
										{action
											{type start}
											{waypoint "196"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}}
								}
								{"case"
									{condition
										{type cmp_i}
										{var "arty3_rnd$"}
										{op "=="}
										{value 3}
									}
									{"switch"
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 1}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf3_artyc}
											}
										}
										{action
											{type start}
											{waypoint "11237"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 2}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf3_artyc}
											}
										}
										{action
											{type start}
											{waypoint "12237"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 3}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf3_artyc}
											}
										}
										{action
											{type start}
											{waypoint "13237"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 4}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf3_artyc}
											}
										}
										{action
											{type start}
											{waypoint "14237"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"default"
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf3_artyc}
											}
										}
										{action
											{type start}
											{waypoint "237"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}}
								}
								{"default"
									{"switch"
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 1}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf3_artyc}
											}
										}
										{action
											{type start}
											{waypoint "11098"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 2}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf3_artyc}
											}
										}
										{action
											{type start}
											{waypoint "12098"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 3}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf3_artyc}
											}
										}
										{action
											{type start}
											{waypoint "13098"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 4}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf3_artyc}
											}
										}
										{action
											{type start}
											{waypoint "14098"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"default"
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf3_artyc}
											}
										}
										{action
											{type start}
											{waypoint "98"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}}
								}
							}
							{"delay"
								{time 0.1}
							}
							{"switch"
								{"case"
									{condition
										{type cmp_i}
										{var "arty3_rnd$"}
										{op "<<"}
										{value 4}
									}
									{"set_i"
										{var "arty3_rnd$"}
										{op "+"}
										{value 1}
									}
								}
								{"default"
									{"set_i"
										{var "arty3_rnd$"}
										{op "="}
										{value 0}
									}
								}
							}
							{"entity_state"
								{selector
									{source standart}
									{ignore_captured_by_user 0}
									{tag _botsf3_artyc}
								}
								{tag_add "+bots_ct"}
							}
						}
						{"delay"
							{time 0.1}
						}
						{"if"
							{condition
								{type entities}
								{selector
									{ignore_captured_by_user 0}
									{tag _botsf3_v}
									{zone "gamezone"}
									{type vehicle}
									{state operatable}
								}
							}
							{"switch"
								{"case"
									{condition
										{type cmp_i}
										{var "gun3_tele$"}
										{op "=="}
										{value 0}
									}
									{"switch"
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 1}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf3_v}
											}
										}
										{action
											{type start}
											{waypoint "11099"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 2}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf3_v}
											}
										}
										{action
											{type start}
											{waypoint "12099"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 3}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf3_v}
											}
										}
										{action
											{type start}
											{waypoint "13099"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 4}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf3_v}
											}
										}
										{action
											{type start}
											{waypoint "14099"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"default"
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf3_v}
											}
										}
										{action
											{type start}
											{waypoint "99"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}}
								}
								{"case"
									{condition
										{type cmp_i}
										{var "gun3_tele$"}
										{op "=="}
										{value 1}
									}
									{"switch"
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 1}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf3_v}
											}
										}
										{action
											{type start}
											{waypoint "11100"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 2}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf3_v}
											}
										}
										{action
											{type start}
											{waypoint "12100"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 3}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf3_v}
											}
										}
										{action
											{type start}
											{waypoint "13100"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 4}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf3_v}
											}
										}
										{action
											{type start}
											{waypoint "14100"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"default"
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf3_v}
											}
										}
										{action
											{type start}
											{waypoint "100"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}}
								}
								{"default"
									{"switch"
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 1}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf3_v}
											}
										}
										{action
											{type start}
											{waypoint "11101"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 2}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf3_v}
											}
										}
										{action
											{type start}
											{waypoint "12101"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 3}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf3_v}
											}
										}
										{action
											{type start}
											{waypoint "13101"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 4}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf3_v}
											}
										}
										{action
											{type start}
											{waypoint "14101"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"default"
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf3_v}
											}
										}
										{action
											{type start}
											{waypoint "101"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}}
								}
							}
							{"delay"
								{time 0.1}
							}
							{"switch"
								{"case"
									{condition
										{type cmp_i}
										{var "gun3_tele$"}
										{op "<<"}
										{value 2}
									}
									{"set_i"
										{var "gun3_tele$"}
										{op "+"}
										{value 1}
									}
								}
								{"default"
									{"set_i"
										{var "gun3_tele$"}
										{op "="}
										{value 0}
									}
								}
							}
						}
					}
				}
				{"delay"
					{time 0.1}
				}
				{"entity_state"
					{selector
						{source standart}
						{ignore_captured_by_user 0}
						{tag _botsf3_h}
					}
					{tag_add "+garrisoned"}
					{tag_remove "_garrison_todo+"}
				}
				{"entity_state"
					{selector
						{source standart}
						{ignore_captured_by_user 0}
						{tag _botsf3_artyc}
					}
					{tag_add "+garrisoned"}
					{tag_remove "_garrison_todo+"}
				}
				{"delay"
					{time 0.1}
				}
				{"entity_state"
					{selector
						{source standart}
						{ignore_captured_by_user 0}
						{tag _botsf3_h}
					}
					{tag_remove _botsf3_h}
				}
				{"entity_state"
					{selector
						{source standart}
						{ignore_captured_by_user 0}
						{tag _botsf3_artyc}
					}
					{tag_remove _botsf3_artyc}
				}
			}
			{"flag4_bots_d"
				{"entity_state"
					{selector
						{source advanced}
						{ignore_captured_by_user 0}
						{group
							{select
								{tag
									{tag "_garrison_todo+"}
								}
							}
							{include
								{zone
									{zone "forward4"}
								}
								{prop
									{prop human}
								}
								{state
									{state operatable}
								}
							}
							{exclude
								{state
									{state inactive}
								}
								{state
									{state linked}
								}
							}
						}
						{amount 2
						}
					}
					{tag_add _botsf4_h}
				}
				{"entity_state"
					{selector
						{source advanced}
						{ignore_captured_by_user 0}
						{group
							{select
								{tag
									{tag "_garrison_todo+"}
								}
							}
							{include
								{zone
									{zone "forward4"}
								}
								{prop
									{prop vehicle}
								}
								{state
									{state operatable}
								}
							}
							{exclude
								{prop
									{prop car}
								}
								{prop
									{prop tank}
								}
								{prop
									{prop detect_artillery}
								}
								{prop
									{prop detect_artillery_small}
								}
							}
						}
						{amount 1
						}
					}
					{tag_add _botsf4_v}
				}
				{"delay"
					{time 0.1}
				}
				{"entity_state"
					{selector
						{source advanced}
						{ignore_captured_by_user 0}
						{group
							{select
								{tag
									{tag "_garrison_todo+"}
								}
							}
							{include
								{zone
									{zone "forward4"}
								}
								{prop
									{prop vehicle}
								}
								{state
									{state operatable}
								}
							}
							{exclude
								{tag
									{tag _botsf4_v}
								}
								{prop
									{prop detect_artillery}
								}
								{prop
									{prop detect_artillery_small}
								}
							}
						}
						{amount 1
						}
					}
					{tag_add _botsf4_ct}
				}
				{"delay"
					{time 0.1}
				}
				{"entity_state"
					{selector
						{source advanced}
						{ignore_captured_by_user 0}
						{group
							{select
								{tag
									{tag "_garrison_todo+"}
								}
							}
							{include
								{zone
									{zone "forward4"}
								}
								{prop
									{prop vehicle}
								}
								{state
									{state operatable}
								}
							}
							{exclude
								{tag
									{tag _botsf4_v}
								}
								{tag
									{tag _botsf4_ct}
								}
							}
						}
						{amount 1
						}
					}
					{tag_add _botsf4_artyc}
				}
				{"delay"
					{time 0.1}
				}
				{"entity_state"
					{selector
						{source standart}
						{ignore_captured_by_user 0}
						{tag _botsf4_v}
					}
					{tag_add "+garrisoned"}
					{tag_remove "_garrison_todo+"}
				}
				{"switch"
					{"case"
						{condition
							{type cmp_i}
							{var "bots_spawnside$"}
							{op "=="}
							{value 1}
						}
						{"switch"
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 5}}
{"waypoint"
							{who
								{type actor}
								{actors
									{ignore_captured_by_user 0}
									{tag _botsf4_ct}
									{type vehicle}
									{state operatable}
								}
							}
							{action
								{type start}
								{waypoint "15018"}
								{make_squad}
								{approach "safe teleport"}
							}
						}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 6}}
{"waypoint"
							{who
								{type actor}
								{actors
									{ignore_captured_by_user 0}
									{tag _botsf4_ct}
									{type vehicle}
									{state operatable}
								}
							}
							{action
								{type start}
								{waypoint "16018"}
								{make_squad}
								{approach "safe teleport"}
							}
						}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 7}}
{"waypoint"
							{who
								{type actor}
								{actors
									{ignore_captured_by_user 0}
									{tag _botsf4_ct}
									{type vehicle}
									{state operatable}
								}
							}
							{action
								{type start}
								{waypoint "17018"}
								{make_squad}
								{approach "safe teleport"}
							}
						}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 8}}
{"waypoint"
							{who
								{type actor}
								{actors
									{ignore_captured_by_user 0}
									{tag _botsf4_ct}
									{type vehicle}
									{state operatable}
								}
							}
							{action
								{type start}
								{waypoint "18018"}
								{make_squad}
								{approach "safe teleport"}
							}
						}}
{"default"
{"waypoint"
							{who
								{type actor}
								{actors
									{ignore_captured_by_user 0}
									{tag _botsf4_ct}
									{type vehicle}
									{state operatable}
								}
							}
							{action
								{type start}
								{waypoint "18"}
								{make_squad}
								{approach "safe teleport"}
							}
						}}}
						{"switch"
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 5}}
{"waypoint"
							{who
								{type actor}
								{actors
									{ignore_captured_by_user 0}
									{tag _botsf4_h}
									{type human}
									{state operatable}
								}
							}
							{action
								{type start}
								{waypoint "15004"}
								{make_squad}
								{approach "safe teleport"}
							}
						}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 6}}
{"waypoint"
							{who
								{type actor}
								{actors
									{ignore_captured_by_user 0}
									{tag _botsf4_h}
									{type human}
									{state operatable}
								}
							}
							{action
								{type start}
								{waypoint "16004"}
								{make_squad}
								{approach "safe teleport"}
							}
						}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 7}}
{"waypoint"
							{who
								{type actor}
								{actors
									{ignore_captured_by_user 0}
									{tag _botsf4_h}
									{type human}
									{state operatable}
								}
							}
							{action
								{type start}
								{waypoint "17004"}
								{make_squad}
								{approach "safe teleport"}
							}
						}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 8}}
{"waypoint"
							{who
								{type actor}
								{actors
									{ignore_captured_by_user 0}
									{tag _botsf4_h}
									{type human}
									{state operatable}
								}
							}
							{action
								{type start}
								{waypoint "18004"}
								{make_squad}
								{approach "safe teleport"}
							}
						}}
{"default"
{"waypoint"
							{who
								{type actor}
								{actors
									{ignore_captured_by_user 0}
									{tag _botsf4_h}
									{type human}
									{state operatable}
								}
							}
							{action
								{type start}
								{waypoint "4"}
								{make_squad}
								{approach "safe teleport"}
							}
						}}}
						{"delay"
							{time 0.1}
						}
						{"if"
							{condition
								{type entities}
								{selector
									{ignore_captured_by_user 0}
									{tag _botsf4_artyc}
									{zone "gamezone"}
									{type vehicle}
									{state inhabited}
								}
							}
							{"switch"
								{"case"
									{condition
										{type cmp_i}
										{var "arty4_rnd$"}
										{op "=="}
										{value 0}
									}
									{"switch"
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 5}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf4_artyc}
											}
										}
										{action
											{type start}
											{waypoint "15146"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 6}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf4_artyc}
											}
										}
										{action
											{type start}
											{waypoint "16146"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 7}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf4_artyc}
											}
										}
										{action
											{type start}
											{waypoint "17146"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 8}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf4_artyc}
											}
										}
										{action
											{type start}
											{waypoint "18146"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"default"
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf4_artyc}
											}
										}
										{action
											{type start}
											{waypoint "146"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}}
								}
								{"case"
									{condition
										{type cmp_i}
										{var "arty4_rnd$"}
										{op "=="}
										{value 1}
									}
									{"switch"
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 5}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf4_artyc}
											}
										}
										{action
											{type start}
											{waypoint "15147"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 6}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf4_artyc}
											}
										}
										{action
											{type start}
											{waypoint "16147"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 7}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf4_artyc}
											}
										}
										{action
											{type start}
											{waypoint "17147"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 8}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf4_artyc}
											}
										}
										{action
											{type start}
											{waypoint "18147"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"default"
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf4_artyc}
											}
										}
										{action
											{type start}
											{waypoint "147"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}}
								}
								{"case"
									{condition
										{type cmp_i}
										{var "arty4_rnd$"}
										{op "=="}
										{value 2}
									}
									{"switch"
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 5}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf4_artyc}
											}
										}
										{action
											{type start}
											{waypoint "15148"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 6}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf4_artyc}
											}
										}
										{action
											{type start}
											{waypoint "16148"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 7}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf4_artyc}
											}
										}
										{action
											{type start}
											{waypoint "17148"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 8}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf4_artyc}
											}
										}
										{action
											{type start}
											{waypoint "18148"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"default"
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf4_artyc}
											}
										}
										{action
											{type start}
											{waypoint "148"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}}
								}
								{"case"
									{condition
										{type cmp_i}
										{var "arty4_rnd$"}
										{op "=="}
										{value 3}
									}
									{"switch"
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 5}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf4_artyc}
											}
										}
										{action
											{type start}
											{waypoint "15233"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 6}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf4_artyc}
											}
										}
										{action
											{type start}
											{waypoint "16233"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 7}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf4_artyc}
											}
										}
										{action
											{type start}
											{waypoint "17233"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 8}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf4_artyc}
											}
										}
										{action
											{type start}
											{waypoint "18233"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"default"
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf4_artyc}
											}
										}
										{action
											{type start}
											{waypoint "233"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}}
								}
								{"default"
									{"switch"
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 5}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf4_artyc}
											}
										}
										{action
											{type start}
											{waypoint "15082"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 6}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf4_artyc}
											}
										}
										{action
											{type start}
											{waypoint "16082"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 7}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf4_artyc}
											}
										}
										{action
											{type start}
											{waypoint "17082"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 8}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf4_artyc}
											}
										}
										{action
											{type start}
											{waypoint "18082"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"default"
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf4_artyc}
											}
										}
										{action
											{type start}
											{waypoint "82"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}}
								}
							}
							{"delay"
								{time 0.1}
							}
							{"switch"
								{"case"
									{condition
										{type cmp_i}
										{var "arty4_rnd$"}
										{op "<<"}
										{value 4}
									}
									{"set_i"
										{var "arty4_rnd$"}
										{op "+"}
										{value 1}
									}
								}
								{"default"
									{"set_i"
										{var "arty4_rnd$"}
										{op "="}
										{value 0}
									}
								}
							}
							{"entity_state"
								{selector
									{source standart}
									{ignore_captured_by_user 0}
									{tag _botsf4_artyc}
								}
								{tag_add "+bots_ct"}
							}
						}
						{"delay"
							{time 0.1}
						}
						{"if"
							{condition
								{type entities}
								{selector
									{ignore_captured_by_user 0}
									{tag _botsf4_v}
									{zone "gamezone"}
									{type vehicle}
									{state operatable}
								}
							}
							{"switch"
								{"case"
									{condition
										{type cmp_i}
										{var "gun4_tele$"}
										{op "=="}
										{value 0}
									}
									{"switch"
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 5}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf4_v}
											}
										}
										{action
											{type start}
											{waypoint "15083"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 6}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf4_v}
											}
										}
										{action
											{type start}
											{waypoint "16083"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 7}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf4_v}
											}
										}
										{action
											{type start}
											{waypoint "17083"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 8}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf4_v}
											}
										}
										{action
											{type start}
											{waypoint "18083"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"default"
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf4_v}
											}
										}
										{action
											{type start}
											{waypoint "83"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}}
								}
								{"case"
									{condition
										{type cmp_i}
										{var "gun4_tele$"}
										{op "=="}
										{value 1}
									}
									{"switch"
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 5}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf4_v}
											}
										}
										{action
											{type start}
											{waypoint "15084"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 6}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf4_v}
											}
										}
										{action
											{type start}
											{waypoint "16084"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 7}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf4_v}
											}
										}
										{action
											{type start}
											{waypoint "17084"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 8}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf4_v}
											}
										}
										{action
											{type start}
											{waypoint "18084"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"default"
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf4_v}
											}
										}
										{action
											{type start}
											{waypoint "84"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}}
								}
								{"default"
									{"switch"
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 5}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf4_v}
											}
										}
										{action
											{type start}
											{waypoint "15085"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 6}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf4_v}
											}
										}
										{action
											{type start}
											{waypoint "16085"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 7}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf4_v}
											}
										}
										{action
											{type start}
											{waypoint "17085"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 8}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf4_v}
											}
										}
										{action
											{type start}
											{waypoint "18085"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"default"
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf4_v}
											}
										}
										{action
											{type start}
											{waypoint "85"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}}
								}
							}
							{"delay"
								{time 0.1}
							}
							{"switch"
								{"case"
									{condition
										{type cmp_i}
										{var "gun4_tele$"}
										{op "<<"}
										{value 2}
									}
									{"set_i"
										{var "gun4_tele$"}
										{op "+"}
										{value 1}
									}
								}
								{"default"
									{"set_i"
										{var "gun4_tele$"}
										{op "="}
										{value 0}
									}
								}
							}
						}
					}
					{"default"
						{"switch"
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 1}}
{"waypoint"
							{who
								{type actor}
								{actors
									{ignore_captured_by_user 0}
									{tag _botsf4_ct}
									{type vehicle}
									{state operatable}
								}
							}
							{action
								{type start}
								{waypoint "11023"}
								{make_squad}
								{approach "safe teleport"}
							}
						}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 2}}
{"waypoint"
							{who
								{type actor}
								{actors
									{ignore_captured_by_user 0}
									{tag _botsf4_ct}
									{type vehicle}
									{state operatable}
								}
							}
							{action
								{type start}
								{waypoint "12023"}
								{make_squad}
								{approach "safe teleport"}
							}
						}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 3}}
{"waypoint"
							{who
								{type actor}
								{actors
									{ignore_captured_by_user 0}
									{tag _botsf4_ct}
									{type vehicle}
									{state operatable}
								}
							}
							{action
								{type start}
								{waypoint "13023"}
								{make_squad}
								{approach "safe teleport"}
							}
						}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 4}}
{"waypoint"
							{who
								{type actor}
								{actors
									{ignore_captured_by_user 0}
									{tag _botsf4_ct}
									{type vehicle}
									{state operatable}
								}
							}
							{action
								{type start}
								{waypoint "14023"}
								{make_squad}
								{approach "safe teleport"}
							}
						}}
{"default"
{"waypoint"
							{who
								{type actor}
								{actors
									{ignore_captured_by_user 0}
									{tag _botsf4_ct}
									{type vehicle}
									{state operatable}
								}
							}
							{action
								{type start}
								{waypoint "23"}
								{make_squad}
								{approach "safe teleport"}
							}
						}}}
						{"switch"
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 1}}
{"waypoint"
							{who
								{type actor}
								{actors
									{ignore_captured_by_user 0}
									{tag _botsf4_h}
									{type human}
									{state operatable}
								}
							}
							{action
								{type start}
								{waypoint "11004"}
								{make_squad}
								{approach "safe teleport"}
							}
						}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 2}}
{"waypoint"
							{who
								{type actor}
								{actors
									{ignore_captured_by_user 0}
									{tag _botsf4_h}
									{type human}
									{state operatable}
								}
							}
							{action
								{type start}
								{waypoint "12004"}
								{make_squad}
								{approach "safe teleport"}
							}
						}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 3}}
{"waypoint"
							{who
								{type actor}
								{actors
									{ignore_captured_by_user 0}
									{tag _botsf4_h}
									{type human}
									{state operatable}
								}
							}
							{action
								{type start}
								{waypoint "13004"}
								{make_squad}
								{approach "safe teleport"}
							}
						}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 4}}
{"waypoint"
							{who
								{type actor}
								{actors
									{ignore_captured_by_user 0}
									{tag _botsf4_h}
									{type human}
									{state operatable}
								}
							}
							{action
								{type start}
								{waypoint "14004"}
								{make_squad}
								{approach "safe teleport"}
							}
						}}
{"default"
{"waypoint"
							{who
								{type actor}
								{actors
									{ignore_captured_by_user 0}
									{tag _botsf4_h}
									{type human}
									{state operatable}
								}
							}
							{action
								{type start}
								{waypoint "4"}
								{make_squad}
								{approach "safe teleport"}
							}
						}}}
						{"delay"
							{time 0.1}
						}
						{"if"
							{condition
								{type entities}
								{selector
									{ignore_captured_by_user 0}
									{tag _botsf4_artyc}
									{zone "gamezone"}
									{type vehicle}
									{state inhabited}
								}
							}
							{"switch"
								{"case"
									{condition
										{type cmp_i}
										{var "arty4_rnd$"}
										{op "=="}
										{value 0}
									}
									{"switch"
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 1}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf4_artyc}
											}
										}
										{action
											{type start}
											{waypoint "11206"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 2}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf4_artyc}
											}
										}
										{action
											{type start}
											{waypoint "12206"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 3}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf4_artyc}
											}
										}
										{action
											{type start}
											{waypoint "13206"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 4}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf4_artyc}
											}
										}
										{action
											{type start}
											{waypoint "14206"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"default"
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf4_artyc}
											}
										}
										{action
											{type start}
											{waypoint "206"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}}
								}
								{"case"
									{condition
										{type cmp_i}
										{var "arty4_rnd$"}
										{op "=="}
										{value 1}
									}
									{"switch"
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 1}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf4_artyc}
											}
										}
										{action
											{type start}
											{waypoint "11207"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 2}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf4_artyc}
											}
										}
										{action
											{type start}
											{waypoint "12207"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 3}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf4_artyc}
											}
										}
										{action
											{type start}
											{waypoint "13207"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 4}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf4_artyc}
											}
										}
										{action
											{type start}
											{waypoint "14207"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"default"
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf4_artyc}
											}
										}
										{action
											{type start}
											{waypoint "207"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}}
								}
								{"case"
									{condition
										{type cmp_i}
										{var "arty4_rnd$"}
										{op "=="}
										{value 2}
									}
									{"switch"
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 1}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf4_artyc}
											}
										}
										{action
											{type start}
											{waypoint "11208"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 2}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf4_artyc}
											}
										}
										{action
											{type start}
											{waypoint "12208"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 3}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf4_artyc}
											}
										}
										{action
											{type start}
											{waypoint "13208"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 4}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf4_artyc}
											}
										}
										{action
											{type start}
											{waypoint "14208"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"default"
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf4_artyc}
											}
										}
										{action
											{type start}
											{waypoint "208"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}}
								}
								{"case"
									{condition
										{type cmp_i}
										{var "arty4_rnd$"}
										{op "=="}
										{value 3}
									}
									{"switch"
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 1}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf4_artyc}
											}
										}
										{action
											{type start}
											{waypoint "11238"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 2}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf4_artyc}
											}
										}
										{action
											{type start}
											{waypoint "12238"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 3}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf4_artyc}
											}
										}
										{action
											{type start}
											{waypoint "13238"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 4}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf4_artyc}
											}
										}
										{action
											{type start}
											{waypoint "14238"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"default"
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf4_artyc}
											}
										}
										{action
											{type start}
											{waypoint "238"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}}
								}
								{"default"
									{"switch"
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 1}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf4_artyc}
											}
										}
										{action
											{type start}
											{waypoint "11102"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 2}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf4_artyc}
											}
										}
										{action
											{type start}
											{waypoint "12102"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 3}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf4_artyc}
											}
										}
										{action
											{type start}
											{waypoint "13102"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 4}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf4_artyc}
											}
										}
										{action
											{type start}
											{waypoint "14102"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"default"
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf4_artyc}
											}
										}
										{action
											{type start}
											{waypoint "102"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}}
								}
							}
							{"delay"
								{time 0.1}
							}
							{"switch"
								{"case"
									{condition
										{type cmp_i}
										{var "arty4_rnd$"}
										{op "<<"}
										{value 4}
									}
									{"set_i"
										{var "arty4_rnd$"}
										{op "+"}
										{value 1}
									}
								}
								{"default"
									{"set_i"
										{var "arty4_rnd$"}
										{op "="}
										{value 0}
									}
								}
							}
							{"entity_state"
								{selector
									{source standart}
									{ignore_captured_by_user 0}
									{tag _botsf4_artyc}
								}
								{tag_add "+bots_ct"}
							}
						}
						{"delay"
							{time 0.1}
						}
						{"if"
							{condition
								{type entities}
								{selector
									{ignore_captured_by_user 0}
									{tag _botsf4_v}
									{zone "gamezone"}
									{type vehicle}
									{state operatable}
								}
							}
							{"switch"
								{"case"
									{condition
										{type cmp_i}
										{var "gun4_tele$"}
										{op "=="}
										{value 0}
									}
									{"switch"
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 1}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf4_v}
											}
										}
										{action
											{type start}
											{waypoint "11103"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 2}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf4_v}
											}
										}
										{action
											{type start}
											{waypoint "12103"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 3}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf4_v}
											}
										}
										{action
											{type start}
											{waypoint "13103"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 4}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf4_v}
											}
										}
										{action
											{type start}
											{waypoint "14103"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"default"
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf4_v}
											}
										}
										{action
											{type start}
											{waypoint "103"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}}
								}
								{"case"
									{condition
										{type cmp_i}
										{var "gun4_tele$"}
										{op "=="}
										{value 1}
									}
									{"switch"
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 1}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf4_v}
											}
										}
										{action
											{type start}
											{waypoint "11104"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 2}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf4_v}
											}
										}
										{action
											{type start}
											{waypoint "12104"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 3}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf4_v}
											}
										}
										{action
											{type start}
											{waypoint "13104"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 4}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf4_v}
											}
										}
										{action
											{type start}
											{waypoint "14104"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"default"
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf4_v}
											}
										}
										{action
											{type start}
											{waypoint "104"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}}
								}
								{"default"
									{"switch"
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 1}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf4_v}
											}
										}
										{action
											{type start}
											{waypoint "11105"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 2}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf4_v}
											}
										}
										{action
											{type start}
											{waypoint "12105"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 3}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf4_v}
											}
										}
										{action
											{type start}
											{waypoint "13105"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 4}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf4_v}
											}
										}
										{action
											{type start}
											{waypoint "14105"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"default"
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf4_v}
											}
										}
										{action
											{type start}
											{waypoint "105"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}}
								}
							}
							{"delay"
								{time 0.1}
							}
							{"switch"
								{"case"
									{condition
										{type cmp_i}
										{var "gun4_tele$"}
										{op "<<"}
										{value 2}
									}
									{"set_i"
										{var "gun4_tele$"}
										{op "+"}
										{value 1}
									}
								}
								{"default"
									{"set_i"
										{var "gun4_tele$"}
										{op "="}
										{value 0}
									}
								}
							}
						}
					}
				}
				{"delay"
					{time 0.1}
				}
				{"entity_state"
					{selector
						{source standart}
						{ignore_captured_by_user 0}
						{tag _botsf4_h}
					}
					{tag_add "+garrisoned"}
					{tag_remove "_garrison_todo+"}
				}
				{"entity_state"
					{selector
						{source standart}
						{ignore_captured_by_user 0}
						{tag _botsf4_artyc}
					}
					{tag_add "+garrisoned"}
					{tag_remove "_garrison_todo+"}
				}
				{"delay"
					{time 0.1}
				}
				{"entity_state"
					{selector
						{source standart}
						{ignore_captured_by_user 0}
						{tag _botsf4_h}
					}
					{tag_remove _botsf4_h}
				}
				{"entity_state"
					{selector
						{source standart}
						{ignore_captured_by_user 0}
						{tag _botsf4_artyc}
					}
					{tag_remove _botsf4_artyc}
				}
			}
			{"flag5_bots_d"
				{"entity_state"
					{selector
						{source advanced}
						{ignore_captured_by_user 0}
						{group
							{select
								{tag
									{tag "_garrison_todo+"}
								}
							}
							{include
								{zone
									{zone "forward5"}
								}
								{prop
									{prop human}
								}
								{state
									{state operatable}
								}
							}
							{exclude
								{state
									{state inactive}
								}
								{state
									{state linked}
								}
							}
						}
						{amount 2
						}
					}
					{tag_add _botsf5_h}
				}
				{"entity_state"
					{selector
						{source advanced}
						{ignore_captured_by_user 0}
						{group
							{select
								{tag
									{tag "_garrison_todo+"}
								}
							}
							{include
								{zone
									{zone "forward5"}
								}
								{prop
									{prop vehicle}
								}
								{state
									{state operatable}
								}
							}
							{exclude
								{prop
									{prop car}
								}
								{prop
									{prop tank}
								}
								{prop
									{prop detect_artillery}
								}
								{prop
									{prop detect_artillery_small}
								}
							}
						}
						{amount 1
						}
					}
					{tag_add _botsf5_v}
				}
				{"delay"
					{time 0.1}
				}
				{"entity_state"
					{selector
						{source advanced}
						{ignore_captured_by_user 0}
						{group
							{select
								{tag
									{tag "_garrison_todo+"}
								}
							}
							{include
								{zone
									{zone "forward5"}
								}
								{prop
									{prop vehicle}
								}
								{state
									{state operatable}
								}
							}
							{exclude
								{tag
									{tag _botsf5_v}
								}
								{prop
									{prop detect_artillery}
								}
								{prop
									{prop detect_artillery_small}
								}
							}
						}
						{amount 1
						}
					}
					{tag_add _botsf5_ct}
				}
				{"delay"
					{time 0.1}
				}
				{"entity_state"
					{selector
						{source advanced}
						{ignore_captured_by_user 0}
						{group
							{select
								{tag
									{tag "_garrison_todo+"}
								}
							}
							{include
								{zone
									{zone "forward5"}
								}
								{prop
									{prop vehicle}
								}
								{state
									{state operatable}
								}
							}
							{exclude
								{tag
									{tag _botsf5_v}
								}
								{tag
									{tag _botsf5_ct}
								}
							}
						}
						{amount 1
						}
					}
					{tag_add _botsf5_artyc}
				}
				{"delay"
					{time 0.1}
				}
				{"entity_state"
					{selector
						{source standart}
						{ignore_captured_by_user 0}
						{tag _botsf5_v}
					}
					{tag_add "+garrisoned"}
					{tag_remove "_garrison_todo+"}
				}
				{"switch"
					{"case"
						{condition
							{type cmp_i}
							{var "bots_spawnside$"}
							{op "=="}
							{value 1}
						}
						{"switch"
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 5}}
{"waypoint"
							{who
								{type actor}
								{actors
									{ignore_captured_by_user 0}
									{tag _botsf5_ct}
									{type vehicle}
									{state operatable}
								}
							}
							{action
								{type start}
								{waypoint "15019"}
								{make_squad}
								{approach "safe teleport"}
							}
						}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 6}}
{"waypoint"
							{who
								{type actor}
								{actors
									{ignore_captured_by_user 0}
									{tag _botsf5_ct}
									{type vehicle}
									{state operatable}
								}
							}
							{action
								{type start}
								{waypoint "16019"}
								{make_squad}
								{approach "safe teleport"}
							}
						}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 7}}
{"waypoint"
							{who
								{type actor}
								{actors
									{ignore_captured_by_user 0}
									{tag _botsf5_ct}
									{type vehicle}
									{state operatable}
								}
							}
							{action
								{type start}
								{waypoint "17019"}
								{make_squad}
								{approach "safe teleport"}
							}
						}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 8}}
{"waypoint"
							{who
								{type actor}
								{actors
									{ignore_captured_by_user 0}
									{tag _botsf5_ct}
									{type vehicle}
									{state operatable}
								}
							}
							{action
								{type start}
								{waypoint "18019"}
								{make_squad}
								{approach "safe teleport"}
							}
						}}
{"default"
{"waypoint"
							{who
								{type actor}
								{actors
									{ignore_captured_by_user 0}
									{tag _botsf5_ct}
									{type vehicle}
									{state operatable}
								}
							}
							{action
								{type start}
								{waypoint "19"}
								{make_squad}
								{approach "safe teleport"}
							}
						}}}
						{"switch"
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 5}}
{"waypoint"
							{who
								{type actor}
								{actors
									{ignore_captured_by_user 0}
									{tag _botsf5_h}
									{type human}
									{state operatable}
								}
							}
							{action
								{type start}
								{waypoint "15005"}
								{make_squad}
								{approach "safe teleport"}
							}
						}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 6}}
{"waypoint"
							{who
								{type actor}
								{actors
									{ignore_captured_by_user 0}
									{tag _botsf5_h}
									{type human}
									{state operatable}
								}
							}
							{action
								{type start}
								{waypoint "16005"}
								{make_squad}
								{approach "safe teleport"}
							}
						}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 7}}
{"waypoint"
							{who
								{type actor}
								{actors
									{ignore_captured_by_user 0}
									{tag _botsf5_h}
									{type human}
									{state operatable}
								}
							}
							{action
								{type start}
								{waypoint "17005"}
								{make_squad}
								{approach "safe teleport"}
							}
						}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 8}}
{"waypoint"
							{who
								{type actor}
								{actors
									{ignore_captured_by_user 0}
									{tag _botsf5_h}
									{type human}
									{state operatable}
								}
							}
							{action
								{type start}
								{waypoint "18005"}
								{make_squad}
								{approach "safe teleport"}
							}
						}}
{"default"
{"waypoint"
							{who
								{type actor}
								{actors
									{ignore_captured_by_user 0}
									{tag _botsf5_h}
									{type human}
									{state operatable}
								}
							}
							{action
								{type start}
								{waypoint "5"}
								{make_squad}
								{approach "safe teleport"}
							}
						}}}
						{"delay"
							{time 0.1}
						}
						{"if"
							{condition
								{type entities}
								{selector
									{ignore_captured_by_user 0}
									{tag _botsf5_artyc}
									{zone "gamezone"}
									{type vehicle}
									{state inhabited}
								}
							}
							{"switch"
								{"case"
									{condition
										{type cmp_i}
										{var "arty5_rnd$"}
										{op "=="}
										{value 0}
									}
									{"switch"
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 5}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf5_artyc}
											}
										}
										{action
											{type start}
											{waypoint "15158"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 6}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf5_artyc}
											}
										}
										{action
											{type start}
											{waypoint "16158"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 7}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf5_artyc}
											}
										}
										{action
											{type start}
											{waypoint "17158"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 8}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf5_artyc}
											}
										}
										{action
											{type start}
											{waypoint "18158"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"default"
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf5_artyc}
											}
										}
										{action
											{type start}
											{waypoint "158"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}}
								}
								{"case"
									{condition
										{type cmp_i}
										{var "arty5_rnd$"}
										{op "=="}
										{value 1}
									}
									{"switch"
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 5}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf5_artyc}
											}
										}
										{action
											{type start}
											{waypoint "15159"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 6}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf5_artyc}
											}
										}
										{action
											{type start}
											{waypoint "16159"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 7}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf5_artyc}
											}
										}
										{action
											{type start}
											{waypoint "17159"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 8}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf5_artyc}
											}
										}
										{action
											{type start}
											{waypoint "18159"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"default"
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf5_artyc}
											}
										}
										{action
											{type start}
											{waypoint "159"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}}
								}
								{"case"
									{condition
										{type cmp_i}
										{var "arty5_rnd$"}
										{op "=="}
										{value 2}
									}
									{"switch"
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 5}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf5_artyc}
											}
										}
										{action
											{type start}
											{waypoint "15160"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 6}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf5_artyc}
											}
										}
										{action
											{type start}
											{waypoint "16160"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 7}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf5_artyc}
											}
										}
										{action
											{type start}
											{waypoint "17160"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 8}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf5_artyc}
											}
										}
										{action
											{type start}
											{waypoint "18160"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"default"
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf5_artyc}
											}
										}
										{action
											{type start}
											{waypoint "160"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}}
								}
								{"case"
									{condition
										{type cmp_i}
										{var "arty5_rnd$"}
										{op "=="}
										{value 3}
									}
									{"switch"
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 5}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf5_artyc}
											}
										}
										{action
											{type start}
											{waypoint "15234"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 6}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf5_artyc}
											}
										}
										{action
											{type start}
											{waypoint "16234"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 7}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf5_artyc}
											}
										}
										{action
											{type start}
											{waypoint "17234"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 8}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf5_artyc}
											}
										}
										{action
											{type start}
											{waypoint "18234"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"default"
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf5_artyc}
											}
										}
										{action
											{type start}
											{waypoint "234"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}}
								}
								{"default"
									{"switch"
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 5}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf5_artyc}
											}
										}
										{action
											{type start}
											{waypoint "15086"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 6}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf5_artyc}
											}
										}
										{action
											{type start}
											{waypoint "16086"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 7}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf5_artyc}
											}
										}
										{action
											{type start}
											{waypoint "17086"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 8}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf5_artyc}
											}
										}
										{action
											{type start}
											{waypoint "18086"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"default"
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf5_artyc}
											}
										}
										{action
											{type start}
											{waypoint "86"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}}
								}
							}
							{"delay"
								{time 0.1}
							}
							{"switch"
								{"case"
									{condition
										{type cmp_i}
										{var "arty5_rnd$"}
										{op "<<"}
										{value 4}
									}
									{"set_i"
										{var "arty5_rnd$"}
										{op "+"}
										{value 1}
									}
								}
								{"default"
									{"set_i"
										{var "arty5_rnd$"}
										{op "="}
										{value 0}
									}
								}
							}
							{"entity_state"
								{selector
									{source standart}
									{ignore_captured_by_user 0}
									{tag _botsf5_artyc}
								}
								{tag_add "+bots_ct"}
							}
						}
						{"delay"
							{time 0.1}
						}
						{"if"
							{condition
								{type entities}
								{selector
									{ignore_captured_by_user 0}
									{tag _botsf5_v}
									{zone "gamezone"}
									{type vehicle}
									{state operatable}
								}
							}
							{"switch"
								{"case"
									{condition
										{type cmp_i}
										{var "gun5_tele$"}
										{op "=="}
										{value 0}
									}
									{"switch"
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 5}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf5_v}
											}
										}
										{action
											{type start}
											{waypoint "15086"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 6}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf5_v}
											}
										}
										{action
											{type start}
											{waypoint "16086"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 7}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf5_v}
											}
										}
										{action
											{type start}
											{waypoint "17086"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 8}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf5_v}
											}
										}
										{action
											{type start}
											{waypoint "18086"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"default"
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf5_v}
											}
										}
										{action
											{type start}
											{waypoint "86"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}}
								}
								{"case"
									{condition
										{type cmp_i}
										{var "gun5_tele$"}
										{op "=="}
										{value 1}
									}
									{"switch"
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 5}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf5_v}
											}
										}
										{action
											{type start}
											{waypoint "15087"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 6}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf5_v}
											}
										}
										{action
											{type start}
											{waypoint "16087"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 7}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf5_v}
											}
										}
										{action
											{type start}
											{waypoint "17087"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 8}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf5_v}
											}
										}
										{action
											{type start}
											{waypoint "18087"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"default"
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf5_v}
											}
										}
										{action
											{type start}
											{waypoint "87"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}}
								}
								{"default"
									{"switch"
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 5}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf5_v}
											}
										}
										{action
											{type start}
											{waypoint "15088"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 6}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf5_v}
											}
										}
										{action
											{type start}
											{waypoint "16088"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 7}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf5_v}
											}
										}
										{action
											{type start}
											{waypoint "17088"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 8}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf5_v}
											}
										}
										{action
											{type start}
											{waypoint "18088"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"default"
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf5_v}
											}
										}
										{action
											{type start}
											{waypoint "88"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}}
								}
							}
							{"delay"
								{time 0.1}
							}
							{"switch"
								{"case"
									{condition
										{type cmp_i}
										{var "gun5_tele$"}
										{op "<<"}
										{value 2}
									}
									{"set_i"
										{var "gun5_tele$"}
										{op "+"}
										{value 1}
									}
								}
								{"default"
									{"set_i"
										{var "gun5_tele$"}
										{op "="}
										{value 0}
									}
								}
							}
						}
					}
					{"default"
						{"switch"
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 1}}
{"waypoint"
							{who
								{type actor}
								{actors
									{ignore_captured_by_user 0}
									{tag _botsf5_ct}
									{type vehicle}
									{state operatable}
								}
							}
							{action
								{type start}
								{waypoint "11024"}
								{make_squad}
								{approach "safe teleport"}
							}
						}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 2}}
{"waypoint"
							{who
								{type actor}
								{actors
									{ignore_captured_by_user 0}
									{tag _botsf5_ct}
									{type vehicle}
									{state operatable}
								}
							}
							{action
								{type start}
								{waypoint "12024"}
								{make_squad}
								{approach "safe teleport"}
							}
						}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 3}}
{"waypoint"
							{who
								{type actor}
								{actors
									{ignore_captured_by_user 0}
									{tag _botsf5_ct}
									{type vehicle}
									{state operatable}
								}
							}
							{action
								{type start}
								{waypoint "13024"}
								{make_squad}
								{approach "safe teleport"}
							}
						}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 4}}
{"waypoint"
							{who
								{type actor}
								{actors
									{ignore_captured_by_user 0}
									{tag _botsf5_ct}
									{type vehicle}
									{state operatable}
								}
							}
							{action
								{type start}
								{waypoint "14024"}
								{make_squad}
								{approach "safe teleport"}
							}
						}}
{"default"
{"waypoint"
							{who
								{type actor}
								{actors
									{ignore_captured_by_user 0}
									{tag _botsf5_ct}
									{type vehicle}
									{state operatable}
								}
							}
							{action
								{type start}
								{waypoint "24"}
								{make_squad}
								{approach "safe teleport"}
							}
						}}}
						{"switch"
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 1}}
{"waypoint"
							{who
								{type actor}
								{actors
									{ignore_captured_by_user 0}
									{tag _botsf5_h}
									{type human}
									{state operatable}
								}
							}
							{action
								{type start}
								{waypoint "11005"}
								{make_squad}
								{approach "safe teleport"}
							}
						}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 2}}
{"waypoint"
							{who
								{type actor}
								{actors
									{ignore_captured_by_user 0}
									{tag _botsf5_h}
									{type human}
									{state operatable}
								}
							}
							{action
								{type start}
								{waypoint "12005"}
								{make_squad}
								{approach "safe teleport"}
							}
						}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 3}}
{"waypoint"
							{who
								{type actor}
								{actors
									{ignore_captured_by_user 0}
									{tag _botsf5_h}
									{type human}
									{state operatable}
								}
							}
							{action
								{type start}
								{waypoint "13005"}
								{make_squad}
								{approach "safe teleport"}
							}
						}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 4}}
{"waypoint"
							{who
								{type actor}
								{actors
									{ignore_captured_by_user 0}
									{tag _botsf5_h}
									{type human}
									{state operatable}
								}
							}
							{action
								{type start}
								{waypoint "14005"}
								{make_squad}
								{approach "safe teleport"}
							}
						}}
{"default"
{"waypoint"
							{who
								{type actor}
								{actors
									{ignore_captured_by_user 0}
									{tag _botsf5_h}
									{type human}
									{state operatable}
								}
							}
							{action
								{type start}
								{waypoint "5"}
								{make_squad}
								{approach "safe teleport"}
							}
						}}}
						{"delay"
							{time 0.1}
						}
						{"if"
							{condition
								{type entities}
								{selector
									{ignore_captured_by_user 0}
									{tag _botsf5_artyc}
									{zone "gamezone"}
									{type vehicle}
									{state inhabited}
								}
							}
							{"switch"
								{"case"
									{condition
										{type cmp_i}
										{var "arty5_rnd$"}
										{op "=="}
										{value 0}
									}
									{"switch"
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 1}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf5_artyc}
											}
										}
										{action
											{type start}
											{waypoint "11218"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 2}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf5_artyc}
											}
										}
										{action
											{type start}
											{waypoint "12218"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 3}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf5_artyc}
											}
										}
										{action
											{type start}
											{waypoint "13218"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 4}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf5_artyc}
											}
										}
										{action
											{type start}
											{waypoint "14218"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"default"
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf5_artyc}
											}
										}
										{action
											{type start}
											{waypoint "218"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}}
								}
								{"case"
									{condition
										{type cmp_i}
										{var "arty5_rnd$"}
										{op "=="}
										{value 1}
									}
									{"switch"
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 1}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf5_artyc}
											}
										}
										{action
											{type start}
											{waypoint "11219"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 2}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf5_artyc}
											}
										}
										{action
											{type start}
											{waypoint "12219"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 3}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf5_artyc}
											}
										}
										{action
											{type start}
											{waypoint "13219"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 4}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf5_artyc}
											}
										}
										{action
											{type start}
											{waypoint "14219"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"default"
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf5_artyc}
											}
										}
										{action
											{type start}
											{waypoint "219"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}}
								}
								{"case"
									{condition
										{type cmp_i}
										{var "arty5_rnd$"}
										{op "=="}
										{value 2}
									}
									{"switch"
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 1}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf5_artyc}
											}
										}
										{action
											{type start}
											{waypoint "11220"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 2}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf5_artyc}
											}
										}
										{action
											{type start}
											{waypoint "12220"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 3}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf5_artyc}
											}
										}
										{action
											{type start}
											{waypoint "13220"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 4}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf5_artyc}
											}
										}
										{action
											{type start}
											{waypoint "14220"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"default"
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf5_artyc}
											}
										}
										{action
											{type start}
											{waypoint "220"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}}
								}
								{"case"
									{condition
										{type cmp_i}
										{var "arty5_rnd$"}
										{op "=="}
										{value 3}
									}
									{"switch"
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 1}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf5_artyc}
											}
										}
										{action
											{type start}
											{waypoint "11239"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 2}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf5_artyc}
											}
										}
										{action
											{type start}
											{waypoint "12239"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 3}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf5_artyc}
											}
										}
										{action
											{type start}
											{waypoint "13239"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 4}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf5_artyc}
											}
										}
										{action
											{type start}
											{waypoint "14239"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"default"
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf5_artyc}
											}
										}
										{action
											{type start}
											{waypoint "239"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}}
								}
								{"default"
									{"switch"
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 1}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf5_artyc}
											}
										}
										{action
											{type start}
											{waypoint "11106"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 2}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf5_artyc}
											}
										}
										{action
											{type start}
											{waypoint "12106"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 3}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf5_artyc}
											}
										}
										{action
											{type start}
											{waypoint "13106"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 4}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf5_artyc}
											}
										}
										{action
											{type start}
											{waypoint "14106"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"default"
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf5_artyc}
											}
										}
										{action
											{type start}
											{waypoint "106"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}}
								}
							}
							{"delay"
								{time 0.1}
							}
							{"switch"
								{"case"
									{condition
										{type cmp_i}
										{var "arty5_rnd$"}
										{op "<<"}
										{value 4}
									}
									{"set_i"
										{var "arty5_rnd$"}
										{op "+"}
										{value 1}
									}
								}
								{"default"
									{"set_i"
										{var "arty5_rnd$"}
										{op "="}
										{value 0}
									}
								}
							}
							{"entity_state"
								{selector
									{source standart}
									{ignore_captured_by_user 0}
									{tag _botsf5_artyc}
								}
								{tag_add "+bots_ct"}
							}
						}
						{"delay"
							{time 0.1}
						}
						{"if"
							{condition
								{type entities}
								{selector
									{ignore_captured_by_user 0}
									{tag _botsf5_v}
									{zone "gamezone"}
									{type vehicle}
									{state operatable}
								}
							}
							{"switch"
								{"case"
									{condition
										{type cmp_i}
										{var "gun5_tele$"}
										{op "=="}
										{value 0}
									}
									{"switch"
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 1}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf5_v}
											}
										}
										{action
											{type start}
											{waypoint "11107"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 2}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf5_v}
											}
										}
										{action
											{type start}
											{waypoint "12107"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 3}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf5_v}
											}
										}
										{action
											{type start}
											{waypoint "13107"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 4}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf5_v}
											}
										}
										{action
											{type start}
											{waypoint "14107"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"default"
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf5_v}
											}
										}
										{action
											{type start}
											{waypoint "107"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}}
								}
								{"case"
									{condition
										{type cmp_i}
										{var "gun5_tele$"}
										{op "=="}
										{value 1}
									}
									{"switch"
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 1}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf5_v}
											}
										}
										{action
											{type start}
											{waypoint "11108"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 2}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf5_v}
											}
										}
										{action
											{type start}
											{waypoint "12108"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 3}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf5_v}
											}
										}
										{action
											{type start}
											{waypoint "13108"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 4}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf5_v}
											}
										}
										{action
											{type start}
											{waypoint "14108"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"default"
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf5_v}
											}
										}
										{action
											{type start}
											{waypoint "108"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}}
								}
								{"default"
									{"switch"
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 1}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf5_v}
											}
										}
										{action
											{type start}
											{waypoint "11109"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 2}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf5_v}
											}
										}
										{action
											{type start}
											{waypoint "12109"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 3}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf5_v}
											}
										}
										{action
											{type start}
											{waypoint "13109"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value 4}}
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf5_v}
											}
										}
										{action
											{type start}
											{waypoint "14109"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}
{"default"
{"waypoint"
										{who
											{type actor}
											{actors
												{ignore_captured_by_user 0}
												{tag _botsf5_v}
											}
										}
										{action
											{type start}
											{waypoint "109"}
											{make_squad}
											{approach "safe teleport"}
										}
									}}}
								}
							}
							{"delay"
								{time 0.1}
							}
							{"switch"
								{"case"
									{condition
										{type cmp_i}
										{var "gun5_tele$"}
										{op "<<"}
										{value 2}
									}
									{"set_i"
										{var "gun5_tele$"}
										{op "+"}
										{value 1}
									}
								}
								{"default"
									{"set_i"
										{var "gun5_tele$"}
										{op "="}
										{value 0}
									}
								}
							}
						}
					}
				}
				{"delay"
					{time 0.1}
				}
				{"entity_state"
					{selector
						{source standart}
						{ignore_captured_by_user 0}
						{tag _botsf5_h}
					}
					{tag_add "+garrisoned"}
					{tag_remove "_garrison_todo+"}
				}
				{"entity_state"
					{selector
						{source standart}
						{ignore_captured_by_user 0}
						{tag _botsf5_artyc}
					}
					{tag_add "+garrisoned"}
					{tag_remove "_garrison_todo+"}
				}
				{"delay"
					{time 0.1}
				}
				{"entity_state"
					{selector
						{source standart}
						{ignore_captured_by_user 0}
						{tag _botsf5_h}
					}
					{tag_remove _botsf5_h}
				}
				{"entity_state"
					{selector
						{source standart}
						{ignore_captured_by_user 0}
						{tag _botsf5_artyc}
					}
					{tag_remove _botsf5_artyc}
				}
			}
			{"bot_mobiles_stop"
				{"switch"
					{"case"
						{condition
							{type cmp_i}
							{var "bots_spawnside$"}
							{op "=="}
							{value 1}
						}
						{"action"
							{drop orders}
							{action cancel}
							{target
								{ignore_captured_by_user 0}
								{tag null}
							}
						}
						{"delay"
							{time 0.2}
						}
						{"action"
							{action rotate}
							{target
								{ignore_captured_by_user 0}
								{tag player_spawn}
							}
						}
					}
					{"default"
						{"action"
							{drop orders}
							{action cancel}
							{target
								{ignore_captured_by_user 0}
								{tag null}
							}
						}
						{"delay"
							{time 0.2}
						}
						{"action"
							{action rotate}
							{target
								{ignore_captured_by_user 0}
								{tag player_spawn}
							}
						}
					}
				}
			}
			{"retreat_bail_bots"
				{"entity_state"
					{selector
						{source advanced}
						{ignore_captured_by_user 0}
						{group
							{select
								{tag
									{tag x_bot}
								}
							}
							{include
								{zone
									{zone "gamezone"}
								}
								{prop
									{prop human}
								}
								{state
									{state operatable}
								}
							}
							{exclude
								{state
									{state inactive}
								}
								{state
									{state linked}
								}
							}
						}
						{amount 6
						}
						{sort
							{type entity}
							{entity
								{ignore_captured_by_user 0}
								{tag _s_emits}
							}
						}
					}
					{tag_add _s_escape}
					{tag_remove x_bot}
				}
				{"delay"
					{time 0.1}
				}
				{"entity_state"
					{selector
						{source standart}
						{ignore_captured_by_user 0}
						{tag _s_emits}
					}
					{tag_remove _s_emits}
				}
				{"delay"
					{time 0.2}
				}
				{"entity_state"
					{selector
						{source advanced}
						{ignore_captured_by_user 0}
						{group
							{select
								{tag
									{tag x_bot}
								}
							}
							{include
								{zone
									{zone "gamezone"}
								}
								{prop
									{prop human}
								}
								{state
									{state operatable}
								}
							}
							{exclude
								{state
									{state inactive}
								}
								{state
									{state linked}
								}
							}
						}
						{amount 6
						}
						{sort
							{type entity}
							{entity
								{ignore_captured_by_user 0}
								{tag flag}
							}
						}
					}
					{tag_add _s_escape}
					{tag_remove x_bot}
				}
				{"delay"
					{time 0.3}
				}
				{"actor_state"
					{selector
						{source standart}
						{ignore_captured_by_user 0}
						{tag _s_escape}
						{type human}
						{state operatable}
					}
					{drop orders}
					{fire_mode return}
					{ai_move
						{mode disable}
					}
					{movement
						{speed bow}
						{kind fast}
						{type normal}
					}
				}
				{"switch"
					{"case"
						{condition
							{type cmp_i}
							{var "bots_spawnside$"}
							{op "=="}
							{value 1}
						}
						{"action"
							{selector
								{source standart}
								{ignore_captured_by_user 0}
								{tag _s_escape}
								{type human}
								{state operatable}
							}
							{action move}
							{target
								{ignore_captured_by_user 0}
								{amount 1
								}
								{tag spawn_a}
							}
						}
					}
					{"default"
						{"action"
							{selector
								{source standart}
								{ignore_captured_by_user 0}
								{tag _s_escape}
								{type human}
								{state operatable}
							}
							{action move}
							{target
								{ignore_captured_by_user 0}
								{amount 1
								}
								{tag spawn_b}
							}
						}
					}
				}
				{"delay"
					{time 0.1}
				}
				{"entity_state"
					{selector
						{source standart}
						{ignore_captured_by_user 0}
						{tag _s_escape}
					}
					{tag_add _escape}
					{tag_remove _s_escape}
				}
			}
			{"debug_garrison"
				{"switch"
					{"case"
						{condition
							{type cmp_i}
							{var "bots_spawnside$"}
							{op "=="}
							{value 1}
						}
						{"delay"
							{time 0.1}
						}
						{"if"
							{condition
								{type entities}
								{selector
									{source advanced}
									{ignore_captured_by_user 0}
									{group
										{select
											{tag
												{tag _s_moved}
											}
										}
										{include
											{tag
												{tag _s_move}
											}
										}
									}
								}
								{count
									{op "!="}
									{value 4}
								}
							}
							{"timer"
								{time 5}
								{title "mission/multi/dcg2_error01"}
							}
							{"con"
								{text "(Warning) - Not all Bot defender spawns have moved!(side:A)"}
							}
						}
						{"delay"
							{time 0.2}
						}
						{"if"
							{condition
								{type entities}
								{selector
									{source advanced}
									{ignore_captured_by_user 0}
									{group
										{select
											{tag
												{tag spawn_a}
											}
										}
										{exclude
											{zone
												{zone "forward1"}
											}
											{zone
												{zone "forward2"}
											}
											{zone
												{zone "forward3"}
											}
											{zone
												{zone "forward4"}
											}
											{zone
												{zone "forward5"}
											}
										}
									}
								}
							}
							{"objective_progress"
								{set 0}
								{add 0}
								{title "mission/multi/dcg2_error03"}
							}
							{"con"
								{text "(Warning) - At least one enemy bot garrison spawn is not in active forward# zone!"}
							}
							{"delay"
								{time 5}
							}
							{"objective_progress"
								{hide}
								{set 0}
								{add 0}
								{title "mission/multi/dcg2_error03"}
							}
						}
					}
					{"default"
						{"delay"
							{time 0.1}
						}
						{"if"
							{condition
								{type entities}
								{selector
									{source advanced}
									{ignore_captured_by_user 0}
									{group
										{select
											{tag
												{tag _s_moved}
											}
										}
										{include
											{tag
												{tag _s_move}
											}
										}
									}
								}
								{count
									{op "!="}
									{value 4}
								}
							}
							{"timer"
								{time 5}
								{title "mission/multi/dcg2_error02"}
							}
							{"con"
								{text "(Warning) - Not all Bot defender spawns have moved!(side:B)"}
							}
						}
						{"delay"
							{time 0.2}
						}
						{"if"
							{condition
								{type entities}
								{selector
									{source advanced}
									{ignore_captured_by_user 0}
									{group
										{select
											{tag
												{tag spawn_b}
											}
										}
										{exclude
											{zone
												{zone "forward1"}
											}
											{zone
												{zone "forward2"}
											}
											{zone
												{zone "forward3"}
											}
											{zone
												{zone "forward4"}
											}
											{zone
												{zone "forward5"}
											}
										}
									}
								}
							}
							{"objective_progress"
								{set 0}
								{add 0}
								{title "mission/multi/dcg2_error03"}
							}
							{"con"
								{text "(Warning) - At least one enemy bot garrison spawn is not in active forward# zone!"}
							}
							{"delay"
								{time 5}
							}
							{"objective_progress"
								{hide}
								{set 0}
								{add 0}
								{title "mission/multi/dcg2_error03"}
							}
						}
					}
				}
			}