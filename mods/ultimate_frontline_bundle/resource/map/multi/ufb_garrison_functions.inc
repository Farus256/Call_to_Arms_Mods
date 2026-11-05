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
								{waypoint "4615"}
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
								{waypoint "5465"}
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
								{waypoint "6315"}
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
								{waypoint "7165"}
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
								{waypoint "4601"}
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
								{waypoint "5451"}
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
								{waypoint "6301"}
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
								{waypoint "7151"}
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
											{waypoint "4710"}
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
											{waypoint "5560"}
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
											{waypoint "6410"}
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
											{waypoint "7260"}
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
											{waypoint "4711"}
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
											{waypoint "5561"}
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
											{waypoint "6411"}
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
											{waypoint "7261"}
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
											{waypoint "4712"}
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
											{waypoint "5562"}
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
											{waypoint "6412"}
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
											{waypoint "7262"}
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
											{waypoint "4830"}
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
											{waypoint "5680"}
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
											{waypoint "6530"}
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
											{waypoint "7380"}
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
											{waypoint "4670"}
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
											{waypoint "5520"}
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
											{waypoint "6370"}
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
											{waypoint "7220"}
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
											{waypoint "4671"}
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
											{waypoint "5521"}
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
											{waypoint "6371"}
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
											{waypoint "7221"}
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
											{waypoint "4672"}
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
											{waypoint "5522"}
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
											{waypoint "6372"}
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
											{waypoint "7222"}
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
											{waypoint "4673"}
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
											{waypoint "5523"}
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
											{waypoint "6373"}
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
											{waypoint "7223"}
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
								{waypoint "1220"}
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
								{waypoint "2070"}
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
								{waypoint "2920"}
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
								{waypoint "3770"}
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
								{waypoint "1201"}
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
								{waypoint "2051"}
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
								{waypoint "2901"}
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
								{waypoint "3751"}
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
											{waypoint "1370"}
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
											{waypoint "2220"}
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
											{waypoint "3070"}
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
											{waypoint "3920"}
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
											{waypoint "1371"}
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
											{waypoint "2221"}
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
											{waypoint "3071"}
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
											{waypoint "3921"}
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
											{waypoint "1372"}
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
											{waypoint "2222"}
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
											{waypoint "3072"}
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
											{waypoint "3922"}
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
											{waypoint "1435"}
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
											{waypoint "2285"}
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
											{waypoint "3135"}
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
											{waypoint "3985"}
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
											{waypoint "1290"}
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
											{waypoint "2140"}
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
											{waypoint "2990"}
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
											{waypoint "3840"}
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
											{waypoint "1291"}
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
											{waypoint "2141"}
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
											{waypoint "2991"}
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
											{waypoint "3841"}
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
											{waypoint "1292"}
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
											{waypoint "2142"}
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
											{waypoint "2992"}
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
											{waypoint "3842"}
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
											{waypoint "1293"}
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
											{waypoint "2143"}
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
											{waypoint "2993"}
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
											{waypoint "3843"}
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
								{waypoint "4616"}
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
								{waypoint "5466"}
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
								{waypoint "6316"}
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
								{waypoint "7166"}
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
								{waypoint "4602"}
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
								{waypoint "5452"}
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
								{waypoint "6302"}
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
								{waypoint "7152"}
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
											{waypoint "4722"}
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
											{waypoint "5572"}
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
											{waypoint "6422"}
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
											{waypoint "7272"}
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
											{waypoint "4723"}
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
											{waypoint "5573"}
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
											{waypoint "6423"}
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
											{waypoint "7273"}
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
											{waypoint "4724"}
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
											{waypoint "5574"}
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
											{waypoint "6424"}
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
											{waypoint "7274"}
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
											{waypoint "4831"}
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
											{waypoint "5681"}
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
											{waypoint "6531"}
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
											{waypoint "7381"}
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
											{waypoint "4674"}
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
											{waypoint "5524"}
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
											{waypoint "6374"}
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
											{waypoint "7224"}
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
											{waypoint "4675"}
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
											{waypoint "5525"}
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
											{waypoint "6375"}
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
											{waypoint "7225"}
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
											{waypoint "4676"}
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
											{waypoint "5526"}
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
											{waypoint "6376"}
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
											{waypoint "7226"}
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
											{waypoint "4677"}
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
											{waypoint "5527"}
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
											{waypoint "6377"}
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
											{waypoint "7227"}
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
								{waypoint "1221"}
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
								{waypoint "2071"}
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
								{waypoint "2921"}
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
								{waypoint "3771"}
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
								{waypoint "1202"}
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
								{waypoint "2052"}
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
								{waypoint "2902"}
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
								{waypoint "3752"}
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
											{waypoint "1382"}
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
											{waypoint "2232"}
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
											{waypoint "3082"}
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
											{waypoint "3932"}
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
											{waypoint "1383"}
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
											{waypoint "2233"}
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
											{waypoint "3083"}
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
											{waypoint "3933"}
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
											{waypoint "1384"}
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
											{waypoint "2234"}
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
											{waypoint "3084"}
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
											{waypoint "3934"}
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
											{waypoint "1436"}
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
											{waypoint "2286"}
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
											{waypoint "3136"}
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
											{waypoint "3986"}
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
											{waypoint "1294"}
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
											{waypoint "2144"}
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
											{waypoint "2994"}
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
											{waypoint "3844"}
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
											{waypoint "1295"}
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
											{waypoint "2145"}
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
											{waypoint "2995"}
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
											{waypoint "3845"}
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
											{waypoint "1296"}
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
											{waypoint "2146"}
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
											{waypoint "2996"}
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
											{waypoint "3846"}
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
											{waypoint "1297"}
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
											{waypoint "2147"}
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
											{waypoint "2997"}
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
											{waypoint "3847"}
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
								{waypoint "4617"}
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
								{waypoint "5467"}
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
								{waypoint "6317"}
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
								{waypoint "7167"}
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
								{waypoint "4603"}
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
								{waypoint "5453"}
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
								{waypoint "6303"}
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
								{waypoint "7153"}
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
											{waypoint "4734"}
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
											{waypoint "5584"}
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
											{waypoint "6434"}
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
											{waypoint "7284"}
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
											{waypoint "4735"}
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
											{waypoint "5585"}
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
											{waypoint "6435"}
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
											{waypoint "7285"}
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
											{waypoint "4736"}
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
											{waypoint "5586"}
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
											{waypoint "6436"}
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
											{waypoint "7286"}
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
											{waypoint "4832"}
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
											{waypoint "5682"}
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
											{waypoint "6532"}
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
											{waypoint "7382"}
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
											{waypoint "4678"}
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
											{waypoint "5528"}
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
											{waypoint "6378"}
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
											{waypoint "7228"}
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
											{waypoint "4679"}
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
											{waypoint "5529"}
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
											{waypoint "6379"}
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
											{waypoint "7229"}
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
											{waypoint "4680"}
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
											{waypoint "5530"}
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
											{waypoint "6380"}
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
											{waypoint "7230"}
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
											{waypoint "4681"}
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
											{waypoint "5531"}
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
											{waypoint "6381"}
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
											{waypoint "7231"}
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
								{waypoint "1222"}
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
								{waypoint "2072"}
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
								{waypoint "2922"}
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
								{waypoint "3772"}
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
								{waypoint "1203"}
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
								{waypoint "2053"}
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
								{waypoint "2903"}
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
								{waypoint "3753"}
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
											{waypoint "1394"}
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
											{waypoint "2244"}
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
											{waypoint "3094"}
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
											{waypoint "3944"}
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
											{waypoint "1395"}
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
											{waypoint "2245"}
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
											{waypoint "3095"}
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
											{waypoint "3945"}
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
											{waypoint "1396"}
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
											{waypoint "2246"}
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
											{waypoint "3096"}
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
											{waypoint "3946"}
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
											{waypoint "1437"}
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
											{waypoint "2287"}
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
											{waypoint "3137"}
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
											{waypoint "3987"}
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
											{waypoint "1298"}
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
											{waypoint "2148"}
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
											{waypoint "2998"}
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
											{waypoint "3848"}
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
											{waypoint "1299"}
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
											{waypoint "2149"}
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
											{waypoint "2999"}
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
											{waypoint "3849"}
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
											{waypoint "1300"}
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
											{waypoint "2150"}
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
											{waypoint "3000"}
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
											{waypoint "3850"}
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
											{waypoint "1301"}
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
											{waypoint "2151"}
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
											{waypoint "3001"}
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
											{waypoint "3851"}
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
								{waypoint "4618"}
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
								{waypoint "5468"}
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
								{waypoint "6318"}
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
								{waypoint "7168"}
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
								{waypoint "4604"}
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
								{waypoint "5454"}
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
								{waypoint "6304"}
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
								{waypoint "7154"}
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
											{waypoint "4746"}
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
											{waypoint "5596"}
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
											{waypoint "6446"}
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
											{waypoint "7296"}
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
											{waypoint "4747"}
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
											{waypoint "5597"}
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
											{waypoint "6447"}
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
											{waypoint "7297"}
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
											{waypoint "4748"}
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
											{waypoint "5598"}
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
											{waypoint "6448"}
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
											{waypoint "7298"}
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
											{waypoint "4833"}
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
											{waypoint "5683"}
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
											{waypoint "6533"}
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
											{waypoint "7383"}
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
											{waypoint "4682"}
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
											{waypoint "5532"}
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
											{waypoint "6382"}
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
											{waypoint "7232"}
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
											{waypoint "4683"}
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
											{waypoint "5533"}
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
											{waypoint "6383"}
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
											{waypoint "7233"}
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
											{waypoint "4684"}
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
											{waypoint "5534"}
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
											{waypoint "6384"}
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
											{waypoint "7234"}
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
											{waypoint "4685"}
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
											{waypoint "5535"}
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
											{waypoint "6385"}
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
											{waypoint "7235"}
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
								{waypoint "1223"}
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
								{waypoint "2073"}
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
								{waypoint "2923"}
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
								{waypoint "3773"}
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
								{waypoint "1204"}
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
								{waypoint "2054"}
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
								{waypoint "2904"}
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
								{waypoint "3754"}
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
											{waypoint "1406"}
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
											{waypoint "2256"}
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
											{waypoint "3106"}
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
											{waypoint "3956"}
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
											{waypoint "1407"}
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
											{waypoint "2257"}
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
											{waypoint "3107"}
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
											{waypoint "3957"}
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
											{waypoint "1408"}
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
											{waypoint "2258"}
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
											{waypoint "3108"}
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
											{waypoint "3958"}
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
											{waypoint "1438"}
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
											{waypoint "2288"}
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
											{waypoint "3138"}
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
											{waypoint "3988"}
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
											{waypoint "1302"}
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
											{waypoint "2152"}
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
											{waypoint "3002"}
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
											{waypoint "3852"}
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
											{waypoint "1303"}
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
											{waypoint "2153"}
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
											{waypoint "3003"}
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
											{waypoint "3853"}
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
											{waypoint "1304"}
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
											{waypoint "2154"}
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
											{waypoint "3004"}
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
											{waypoint "3854"}
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
											{waypoint "1305"}
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
											{waypoint "2155"}
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
											{waypoint "3005"}
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
											{waypoint "3855"}
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
								{waypoint "4619"}
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
								{waypoint "5469"}
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
								{waypoint "6319"}
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
								{waypoint "7169"}
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
								{waypoint "4605"}
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
								{waypoint "5455"}
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
								{waypoint "6305"}
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
								{waypoint "7155"}
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
											{waypoint "4758"}
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
											{waypoint "5608"}
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
											{waypoint "6458"}
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
											{waypoint "7308"}
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
											{waypoint "4759"}
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
											{waypoint "5609"}
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
											{waypoint "6459"}
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
											{waypoint "7309"}
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
											{waypoint "4760"}
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
											{waypoint "5610"}
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
											{waypoint "6460"}
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
											{waypoint "7310"}
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
											{waypoint "4834"}
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
											{waypoint "5684"}
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
											{waypoint "6534"}
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
											{waypoint "7384"}
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
											{waypoint "4686"}
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
											{waypoint "5536"}
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
											{waypoint "6386"}
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
											{waypoint "7236"}
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
											{waypoint "4686"}
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
											{waypoint "5536"}
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
											{waypoint "6386"}
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
											{waypoint "7236"}
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
											{waypoint "4687"}
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
											{waypoint "5537"}
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
											{waypoint "6387"}
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
											{waypoint "7237"}
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
											{waypoint "4688"}
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
											{waypoint "5538"}
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
											{waypoint "6388"}
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
											{waypoint "7238"}
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
								{waypoint "1224"}
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
								{waypoint "2074"}
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
								{waypoint "2924"}
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
								{waypoint "3774"}
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
								{waypoint "1205"}
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
								{waypoint "2055"}
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
								{waypoint "2905"}
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
								{waypoint "3755"}
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
											{waypoint "1418"}
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
											{waypoint "2268"}
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
											{waypoint "3118"}
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
											{waypoint "3968"}
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
											{waypoint "1419"}
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
											{waypoint "2269"}
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
											{waypoint "3119"}
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
											{waypoint "3969"}
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
											{waypoint "1420"}
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
											{waypoint "2270"}
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
											{waypoint "3120"}
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
											{waypoint "3970"}
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
											{waypoint "1439"}
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
											{waypoint "2289"}
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
											{waypoint "3139"}
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
											{waypoint "3989"}
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
											{waypoint "1306"}
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
											{waypoint "2156"}
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
											{waypoint "3006"}
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
											{waypoint "3856"}
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
											{waypoint "1307"}
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
											{waypoint "2157"}
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
											{waypoint "3007"}
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
											{waypoint "3857"}
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
											{waypoint "1308"}
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
											{waypoint "2158"}
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
											{waypoint "3008"}
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
											{waypoint "3858"}
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
											{waypoint "1309"}
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
											{waypoint "2159"}
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
											{waypoint "3009"}
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
											{waypoint "3859"}
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