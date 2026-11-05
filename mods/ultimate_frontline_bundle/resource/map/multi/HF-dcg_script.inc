
;// Scripts written by Horten

;// Mod incompatibility messages
			{"hf debugging/error 01"
				{condition
					{terms
						{"1.entities"
							{selector
								{tag detect_error_test_vehicle}
							}
						}
					}
				}
				{actions
					{"delay"
						{time 1}
					}
					{"con"
						{text "(Warning) - HF dcg error 01: campaign_capture_the_flag is overwritten"}
					}
					{"timer"
						{time 30}
						{title "mission/multi/hf_dcg_error01"}
					}
					{"delay"
						{time 60}
					}
					{"trigger"
						{name "hf debugging/error 01"}
					}
				}
			}
			{"hf debugging/error 02"
				{condition
					{expression "1 & ((2 & 3) | (4 & 5) | (6 & 7) | (8 & 9) | (10 & 11))"}
					{terms
						{"1.event"
							{id "airplane_set"}
						}
						{"2.cmp_i"
							{var "bot_army$"}
							{op "=="}
							{value 1}
						}
						{"3.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag airstrike_rus_500}
										}
									}
								
{exclude {tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}}
}
							}
							{count
								{op "<<"}
								{value 1}
							}
						}
						{"4.cmp_i"
							{var "bot_army$"}
							{op "=="}
							{value 2}
						}
						{"5.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag airstrike_ger_250}
										}
									}
								
{exclude {tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}}
}
							}
							{count
								{op "<<"}
								{value 1}
							}
						}
						{"6.cmp_i"
							{var "bot_army$"}
							{op "=="}
							{value 3}
						}
						{"7.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag airstrike_fin_recon}
										}
									}
								
{exclude {tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}}
}
							}
							{count
								{op "<<"}
								{value 1}
							}
						}
						{"8.cmp_i"
							{var "bot_army$"}
							{op "=="}
							{value 4}
						}
						{"9.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag airstrike_usa_rocket_hvar}
										}
									}
								
{exclude {tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}}
}
							}
							{count
								{op "<<"}
								{value 1}
							}
						}
						{"10.cmp_i"
							{var "bot_army$"}
							{op "=="}
							{value 5}
						}
						{"11.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag airstrike_eng_100}
										}
									}
								
{exclude {tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}}
}
							}
							{count
								{op "<<"}
								{value 1}
							}
						}
					}
				}
				{actions
					{"delay"
						{time 0.1}
					}
					{"con"
						{text "(Warning) - HF dcg error 02: HF_dcg_entities is overwritten"}
					}
					{"timer"
						{time 30}
						{title "mission/multi/hf_dcg_error02"}
					}
					{"delay"
						{time 60}
					}
					{"trigger"
						{name "hf debugging/error 02"}
					}
				}
			}
			{## "hf debugging/error 03"
				{condition
					{expression "1 & 2 & !3"}
					{terms
						{"1.event"
							{id "dcg"}
						}
						{"2.cmp_i"
							{var "dcg_on$"}
							{op ">"}
							{value 0}
						}
						{"3.cmp_i"
							{var "hf_check_compat$"}
							{op ">"}
							{value 0}
						}
					}
				}
				{actions
					{"delay"
						{time 1}
					}
					{"con"
						{text "(Warning) - HF dcg error 03: LUA is overwritten"}
					}
					{"timer"
						{time 30}
						{title "mission/multi/hf_dcg_error03"}
					}
					{"delay"
						{time 60}
					}
					{"trigger"
						{name "hf debugging/error 03"}
					}
				}
			}

;//LUA related scripts
			{"hf lua/lua forced order"
				{condition
					{terms
						{"1.entities"
							{selector
								{source advanced}
								{group
									{select
										{zone_ex
											{zone "gamezone"}
										}
									}
									{include
										{state
											{state operatable}
										}
										{tag
											{tag _bot}
										}
										{tag
											{tag bot}
										}
									}
									{exclude
										{state
											{state dead}
										}
										{state
											{state inactive}
										}
										{tag
											{tag hidden}
										}
										{tag
											{tag _lua_mi}
										}
										{tag
											{tag cmp_def}
										}
										{tag
											{tag _lua_ignore}
										}
										{tag
											{tag _lua_alert}
										}
										{tag
											{tag repairing}
										}
										{state
											{state user_control}
										}
									
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
								}
							}
						}
					}
				}
				{actions
					{"delay"
						{time 300}
					}
					{"entity_state"
						{selector
							{source advanced}
							{group
								{select
									{zone_ex
										{zone "gamezone"}
									}
								}
								{include
									{tag
										{tag _bot}
									}
									{tag
										{tag bot}
									}
								}
								{exclude
									{state
										{state dead}
									}
									{state
										{state inactive}
									}
									{tag
										{tag _lua_mi}
									}
									{tag
										{tag _lua_ignore}
									}
									{tag
										{tag _lua_alert}
									}
									{tag
										{tag repairing}
									}
									{tag
										{tag bleeding}
									}
								
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
							}
						}
						{tag_add _lua_need_next_order}
					}
					{"delay"
						{time 60}
					}
					{"entity_state"
						{selector
							{tag _lua_need_next_order}
						}
						{tag_remove _lua_need_next_order}
					}
					{"delay"
						{time 1}
					}
					{"trigger"
						{name "hf lua/lua forced order"}
					}
				}
			}

;// Officers and other RP elements
			{"hf officer system/offmap supply approved"
				{condition
					{terms
						{"1.entities"
							{selector
								{tag undefined_supply_mission}
							}
						}
						{"2.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag officer}
										}
									}
									{include
										{state
											{state user_control}
										}
										{state
											{state operatable}
										}
										{prop
											{prop human}
										}
									}
									{exclude
										{state
											{state dead}
										}
										{state
											{state inactive}
										}
										{tag
											{tag _bot}
										}
										{tag
											{tag bot}
										}
										{tag
											{tag _lua_mi}
										}
										{tag
											{tag wounded}
										}
										{tag
											{tag bleeding}
										}
										{tag
											{tag _bleeding}
										}
										{tag
											{tag wounded_animation_playing}
										}
									
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
								}
							}
						}
						{"3.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag signaller}
										}
									}
									{include
										{state
											{state user_control}
										}
										{state
											{state operatable}
										}
										{prop
											{prop human}
										}
									}
									{exclude
										{state
											{state dead}
										}
										{state
											{state inactive}
										}
										{tag
											{tag _bot}
										}
										{tag
											{tag bot}
										}
										{tag
											{tag _lua_mi}
										}
										{tag
											{tag wounded}
										}
										{tag
											{tag bleeding}
										}
										{tag
											{tag _bleeding}
										}
										{tag
											{tag wounded_animation_playing}
										}
									
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
								}
							}
						}
					}
				}
				{actions
					{"delay"
						{time 0.1}
					}
					{"entity_state"
						{selector
							{tag undefined_supply_mission}
						}
						{tag_add approved_supply_mission}
						{tag_remove undefined_supply_mission}
					}
					{"delay"
						{time 0.75}
					}
					{"trigger"
						{name "hf officer system/offmap supply approved"}
					}
				}
			}
			{"hf officer system/supply fail var1"
				{condition
					{expression "1 & 2 & !3"}
					{terms
						{"1.entities"
							{selector
								{tag undefined_supply_mission}
							}
						}
						{"2.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag officer}
										}
									}
									{include
										{state
											{state user_control}
										}
										{state
											{state operatable}
										}
										{prop
											{prop human}
										}
									}
									{exclude
										{state
											{state dead}
										}
										{state
											{state inactive}
										}
										{tag
											{tag _bot}
										}
										{tag
											{tag bot}
										}
										{tag
											{tag _lua_mi}
										}
										{tag
											{tag wounded}
										}
										{tag
											{tag bleeding}
										}
										{tag
											{tag _bleeding}
										}
										{tag
											{tag wounded_animation_playing}
										}
									
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
								}
							}
						}
						{"3.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag signaller}
										}
									}
									{include
										{state
											{state user_control}
										}
										{state
											{state operatable}
										}
										{prop
											{prop human}
										}
									}
									{exclude
										{state
											{state dead}
										}
										{state
											{state inactive}
										}
										{tag
											{tag _bot}
										}
										{tag
											{tag bot}
										}
										{tag
											{tag _lua_mi}
										}
										{tag
											{tag wounded}
										}
										{tag
											{tag bleeding}
										}
										{tag
											{tag _bleeding}
										}
										{tag
											{tag wounded_animation_playing}
										}
									
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
								}
							}
						}
					}
				}
				{actions
					{"delay"
						{time 0.1}
					}
					{"talk"
						{selector
							{source advanced}
							{group
								{include
									{state
										{state user_control}
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
										{state dead}
									}
								
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
							}
							{amount 1
							}
						}
						{text "mission/multi/hq_failed_supply_var1"}
					}
					{"delay"
						{time 1}
					}
					{"trigger"
						{name "hf officer system/supply fail var1"}
					}
				}
			}
			{"hf officer system/supply fail var2"
				{condition
					{expression "1 & !2 & 3"}
					{terms
						{"1.entities"
							{selector
								{tag undefined_supply_mission}
							}
						}
						{"2.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag officer}
										}
									}
									{include
										{state
											{state user_control}
										}
										{state
											{state operatable}
										}
										{prop
											{prop human}
										}
									}
									{exclude
										{state
											{state dead}
										}
										{state
											{state inactive}
										}
										{tag
											{tag _bot}
										}
										{tag
											{tag bot}
										}
										{tag
											{tag _lua_mi}
										}
										{tag
											{tag wounded}
										}
										{tag
											{tag bleeding}
										}
										{tag
											{tag _bleeding}
										}
										{tag
											{tag wounded_animation_playing}
										}
									
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
								}
							}
						}
						{"3.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag signaller}
										}
									}
									{include
										{state
											{state user_control}
										}
										{state
											{state operatable}
										}
										{prop
											{prop human}
										}
									}
									{exclude
										{state
											{state dead}
										}
										{state
											{state inactive}
										}
										{tag
											{tag _bot}
										}
										{tag
											{tag bot}
										}
										{tag
											{tag _lua_mi}
										}
										{tag
											{tag wounded}
										}
										{tag
											{tag bleeding}
										}
										{tag
											{tag _bleeding}
										}
										{tag
											{tag wounded_animation_playing}
										}
									
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
								}
							}
						}
					}
				}
				{actions
					{"delay"
						{time 0.1}
					}
					{"talk"
						{selector
							{source advanced}
							{group
								{include
									{state
										{state user_control}
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
										{state dead}
									}
								
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
							}
							{amount 1
							}
						}
						{text "mission/multi/hq_failed_supply_var2"}
					}
					{"delay"
						{time 1}
					}
					{"trigger"
						{name "hf officer system/supply fail var2"}
					}
				}
			}
			{"hf officer system/supply fail var3"
				{condition
					{expression "1 & !2 & !3"}
					{terms
						{"1.entities"
							{selector
								{tag undefined_supply_mission}
							}
						}
						{"2.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag officer}
										}
									}
									{include
										{state
											{state user_control}
										}
										{state
											{state operatable}
										}
										{prop
											{prop human}
										}
									}
									{exclude
										{state
											{state dead}
										}
										{state
											{state inactive}
										}
										{tag
											{tag _bot}
										}
										{tag
											{tag bot}
										}
										{tag
											{tag _lua_mi}
										}
										{tag
											{tag wounded}
										}
										{tag
											{tag bleeding}
										}
										{tag
											{tag _bleeding}
										}
										{tag
											{tag wounded_animation_playing}
										}
									
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
								}
							}
						}
						{"3.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag signaller}
										}
									}
									{include
										{state
											{state user_control}
										}
										{state
											{state operatable}
										}
										{prop
											{prop human}
										}
									}
									{exclude
										{state
											{state dead}
										}
										{state
											{state inactive}
										}
										{tag
											{tag _bot}
										}
										{tag
											{tag bot}
										}
										{tag
											{tag _lua_mi}
										}
										{tag
											{tag wounded}
										}
										{tag
											{tag bleeding}
										}
										{tag
											{tag _bleeding}
										}
										{tag
											{tag wounded_animation_playing}
										}
									
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
								}
							}
						}
					}
				}
				{actions
					{"delay"
						{time 0.1}
					}
					{"talk"
						{selector
							{source advanced}
							{group
								{include
									{state
										{state user_control}
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
										{state dead}
									}
								
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
							}
							{amount 1
							}
						}
						{text "mission/multi/hq_failed_supply_var3"}
					}
					{"delay"
						{time 1}
					}
					{"trigger"
						{name "hf officer system/supply fail var3"}
					}
				}
			}
			{"hf officer system/offmap supply move"
				{condition
					{terms
						{"1.entities"
							{selector
								{tag approved_supply_mission}
							}
						}
					}
				}
				{actions
					{"delay"
						{time 5}
					}
					{"switch"
						{"case"
							{condition
								{type entities}
								{selector
									{tag small_offmap_supply_rus}
								}
							}
							{"delay"
								{time 0.1}
							}
							{"actor_to_waypoint"
								{selector
									{source advanced}
									{group
										{select
											{tag
												{tag small_offmap_supply_gaz_aaa}
											}
										}
										{include
											{tag
												{tag hidden}
											}
										}
										{exclude
											{tag
												{tag offmap_supply_on_map}
											}
											{tag
												{tag offmap_supply_deployed}
											}
											{player
												{player "2"}
											}
										
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
									}
									{amount 1
									}
								}
								{drop "orders sensor senseless"}
								{waypoint "1090"}
								{clone}
								{approach "safe teleport & rotate"}
							}
							{"delay"
								{time 0.1}
							}
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
									{"placement"
										{selector
											{source advanced}
											{group
												{select
													{tag
														{tag small_offmap_supply_gaz_aaa}
													}
												}
												{exclude
													{tag
														{tag hidden}
													}
													{tag
														{tag offmap_supply_on_map}
													}
													{tag
														{tag offmap_supply_deployed}
													}
												
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
											}
											{amount 1
											}
										}
										{target
											{source advanced}
											{group
												{select
													{tag
														{tag spawn_b}
													}
												}
												{exclude
													{tag
														{tag _p}
													}
													{tag
														{tag _d}
													}
													{tag
														{tag _placed}
													}
													{tag
														{tag _displayed}
													}
												}
											}
											{sort
												{type shuffle}
											}
										}
									}
								}
								{"case"
									{condition
										{type cmp_i}
										{var "bots_spawnside$"}
										{op "=="}
										{value 2}
									}
									{"delay"
										{time 0.1}
									}
									{"placement"
										{selector
											{source advanced}
											{group
												{select
													{tag
														{tag small_offmap_supply_gaz_aaa}
													}
												}
												{exclude
													{tag
														{tag hidden}
													}
													{tag
														{tag offmap_supply_on_map}
													}
													{tag
														{tag offmap_supply_deployed}
													}
												
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
											}
											{amount 1
											}
										}
										{target
											{source advanced}
											{group
												{select
													{tag
														{tag spawn_a}
													}
												}
												{exclude
													{tag
														{tag _p}
													}
													{tag
														{tag _d}
													}
													{tag
														{tag _placed}
													}
													{tag
														{tag _displayed}
													}
												}
											}
											{sort
												{type shuffle}
											}
										}
									}
								}
								{"default"}
							}
							{"delay"
								{time 0.1}
							}
							{"entity_state"
								{selector
									{source advanced}
									{group
										{select
											{tag
												{tag small_offmap_supply_gaz_aaa}
											}
										}
										{include
											{zone
												{zone "gamezone"}
											}
											{state
												{state operatable}
											}
										}
										{exclude
											{state
												{state dead}
											}
											{state
												{state inactive}
											}
											{tag
												{tag hidden}
											}
											{tag
												{tag offmap_supply_deployed}
											}
										
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
									}
								}
								{tag_add offmap_supply_on_map}
							}
							{"delay"
								{time 0.1}
							}
							{"player"
								{selector
									{source advanced}
									{group
										{select
											{tag
												{tag small_offmap_supply_gaz_aaa}
											}
											{tag
												{tag supply_driver}
											}
										}
										{include
											{zone
												{zone "gamezone"}
											}
											{state
												{state operatable}
											}
										}
										{exclude
											{state
												{state dead}
											}
											{state
												{state inactive}
											}
											{tag
												{tag hidden}
											}
											{tag
												{tag offmap_supply_deployed}
											}
											{tag
												{tag supply_driver_talk_off}
											}
										
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
									}
								}
								{operation set}
								{player "2"}
							}
							{"delay"
								{time 0.1}
							}
							{"actor_state"
								{selector
									{source advanced}
									{group
										{select
											{tag
												{tag small_offmap_supply_gaz_aaa}
											}
											{tag
												{tag supply_driver}
											}
										}
										{include
											{zone
												{zone "gamezone"}
											}
											{state
												{state operatable}
											}
										}
										{exclude
											{state
												{state dead}
											}
											{state
												{state inactive}
											}
											{tag
												{tag hidden}
											}
											{tag
												{tag offmap_supply_deployed}
											}
											{tag
												{tag supply_driver_talk_off}
											}
										
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
									}
								}
								{control user}
								{fire_mode hold}
								{move_mode hold}
								{ai_move
									{mode disable}
								}
								{movement
									{speed fast}
								}
							}
							{"delay"
								{time 0.1}
							}
							{"ables"
								{selector
									{source advanced}
									{group
										{select
											{tag
												{tag small_offmap_supply_gaz_aaa}
											}
											{tag
												{tag supply_driver}
											}
										}
										{include
											{zone
												{zone "gamezone"}
											}
											{state
												{state operatable}
											}
										}
										{exclude
											{state
												{state dead}
											}
											{state
												{state inactive}
											}
											{tag
												{tag hidden}
											}
											{tag
												{tag offmap_supply_deployed}
											}
											{tag
												{tag supply_driver_talk_off}
											}
										
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
									}
								}
								{remove select}
							}
							{"delay"
								{time 0.25}
							}
							{"action"
								{selector
									{source advanced}
									{group
										{select
											{tag
												{tag small_offmap_supply_gaz_aaa}
											}
										}
										{include
											{zone
												{zone "gamezone"}
											}
											{state
												{state operatable}
											}
										}
										{exclude
											{state
												{state dead}
											}
											{state
												{state inactive}
											}
											{tag
												{tag hidden}
											}
											{tag
												{tag offmap_supply_deployed}
											}
										
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
									}
								}
								{drop "orders sensor senseless"}
								{action move}
								{target
									{source advanced}
									{group
										{select
											{tag
												{tag supply_destination}
											}
										}
										{include
											{zone
												{zone "gamezone"}
											}
										}
										{exclude
											{tag
												{tag destination_point_occupied}
											}
										}
									}
								}
							}
							{"delay"
								{time 0.25}
							}
							{"entity_state"
								{selector
									{source advanced}
									{group
										{select
											{tag
												{tag small_offmap_supply_gaz_aaa}
											}
										}
										{include
											{zone
												{zone "gamezone"}
											}
											{state
												{state operatable}
											}
										}
										{exclude
											{tag
												{tag hidden}
											}
											{state
												{state dead}
											}
											{state
												{state inactive}
											}
										
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
									}
								}
								{tag_add offmap_supply_deployed}
							}
						}
						{"case"
							{condition
								{type entities}
								{selector
									{tag small_offmap_supply_ger}
								}
							}
							{"delay"
								{time 0.1}
							}
							{"actor_to_waypoint"
								{selector
									{source advanced}
									{group
										{select
											{tag
												{tag small_offmap_supply_blitz}
											}
										}
										{include
											{tag
												{tag hidden}
											}
										}
										{exclude
											{tag
												{tag offmap_supply_on_map}
											}
											{tag
												{tag offmap_supply_deployed}
											}
											{player
												{player "2"}
											}
										
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
									}
									{amount 1
									}
								}
								{drop "orders sensor senseless"}
								{waypoint "1090"}
								{clone}
								{approach "safe teleport & rotate"}
							}
							{"delay"
								{time 0.1}
							}
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
									{"placement"
										{selector
											{source advanced}
											{group
												{select
													{tag
														{tag small_offmap_supply_blitz}
													}
												}
												{exclude
													{tag
														{tag hidden}
													}
													{tag
														{tag offmap_supply_on_map}
													}
													{tag
														{tag offmap_supply_deployed}
													}
												
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
											}
											{amount 1
											}
										}
										{target
											{source advanced}
											{group
												{select
													{tag
														{tag spawn_b}
													}
												}
												{exclude
													{tag
														{tag _p}
													}
													{tag
														{tag _d}
													}
													{tag
														{tag _placed}
													}
													{tag
														{tag _displayed}
													}
												}
											}
											{sort
												{type shuffle}
											}
										}
									}
								}
								{"case"
									{condition
										{type cmp_i}
										{var "bots_spawnside$"}
										{op "=="}
										{value 2}
									}
									{"delay"
										{time 0.1}
									}
									{"placement"
										{selector
											{source advanced}
											{group
												{select
													{tag
														{tag small_offmap_supply_blitz}
													}
												}
												{exclude
													{tag
														{tag hidden}
													}
													{tag
														{tag offmap_supply_on_map}
													}
													{tag
														{tag offmap_supply_deployed}
													}
												
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
											}
											{amount 1
											}
										}
										{target
											{source advanced}
											{group
												{select
													{tag
														{tag spawn_a}
													}
												}
												{exclude
													{tag
														{tag _p}
													}
													{tag
														{tag _d}
													}
													{tag
														{tag _placed}
													}
													{tag
														{tag _displayed}
													}
												}
											}
											{sort
												{type shuffle}
											}
										}
									}
								}
								{"default"}
							}
							{"delay"
								{time 0.1}
							}
							{"entity_state"
								{selector
									{source advanced}
									{group
										{select
											{tag
												{tag small_offmap_supply_blitz}
											}
										}
										{include
											{zone
												{zone "gamezone"}
											}
											{state
												{state operatable}
											}
										}
										{exclude
											{state
												{state dead}
											}
											{state
												{state inactive}
											}
											{tag
												{tag hidden}
											}
											{tag
												{tag offmap_supply_deployed}
											}
										
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
									}
								}
								{tag_add offmap_supply_on_map}
							}
							{"delay"
								{time 0.1}
							}
							{"player"
								{selector
									{source advanced}
									{group
										{select
											{tag
												{tag small_offmap_supply_blitz}
											}
											{tag
												{tag supply_driver}
											}
										}
										{include
											{zone
												{zone "gamezone"}
											}
											{state
												{state operatable}
											}
										}
										{exclude
											{state
												{state dead}
											}
											{state
												{state inactive}
											}
											{tag
												{tag hidden}
											}
											{tag
												{tag offmap_supply_deployed}
											}
											{tag
												{tag supply_driver_talk_off}
											}
										
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
									}
								}
								{operation set}
								{player "2"}
							}
							{"delay"
								{time 0.1}
							}
							{"actor_state"
								{selector
									{source advanced}
									{group
										{select
											{tag
												{tag small_offmap_supply_blitz}
											}
											{tag
												{tag supply_driver}
											}
										}
										{include
											{zone
												{zone "gamezone"}
											}
											{state
												{state operatable}
											}
										}
										{exclude
											{state
												{state dead}
											}
											{state
												{state inactive}
											}
											{tag
												{tag hidden}
											}
											{tag
												{tag offmap_supply_deployed}
											}
											{tag
												{tag supply_driver_talk_off}
											}
										
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
									}
								}
								{control user}
								{fire_mode hold}
								{move_mode hold}
								{ai_move
									{mode disable}
								}
								{movement
									{speed fast}
								}
							}
							{"delay"
								{time 0.1}
							}
							{"ables"
								{selector
									{source advanced}
									{group
										{select
											{tag
												{tag small_offmap_supply_blitz}
											}
											{tag
												{tag supply_driver}
											}
										}
										{include
											{zone
												{zone "gamezone"}
											}
											{state
												{state operatable}
											}
										}
										{exclude
											{state
												{state dead}
											}
											{state
												{state inactive}
											}
											{tag
												{tag hidden}
											}
											{tag
												{tag offmap_supply_deployed}
											}
											{tag
												{tag supply_driver_talk_off}
											}
										
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
									}
								}
								{remove select}
							}
							{"delay"
								{time 0.25}
							}
							{"action"
								{selector
									{source advanced}
									{group
										{select
											{tag
												{tag small_offmap_supply_blitz}
											}
										}
										{include
											{zone
												{zone "gamezone"}
											}
											{state
												{state operatable}
											}
										}
										{exclude
											{state
												{state dead}
											}
											{state
												{state inactive}
											}
											{tag
												{tag hidden}
											}
											{tag
												{tag offmap_supply_deployed}
											}
										
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
									}
								}
								{drop "orders sensor senseless"}
								{action move}
								{target
									{source advanced}
									{group
										{select
											{tag
												{tag supply_destination}
											}
										}
										{include
											{zone
												{zone "gamezone"}
											}
										}
										{exclude
											{tag
												{tag destination_point_occupied}
											}
										}
									}
								}
							}
							{"delay"
								{time 0.25}
							}
							{"entity_state"
								{selector
									{source advanced}
									{group
										{select
											{tag
												{tag small_offmap_supply_blitz}
											}
										}
										{include
											{zone
												{zone "gamezone"}
											}
											{state
												{state operatable}
											}
										}
										{exclude
											{tag
												{tag hidden}
											}
											{state
												{state dead}
											}
											{state
												{state inactive}
											}
										
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
									}
								}
								{tag_add offmap_supply_deployed}
							}
						}
						{"case"
							{condition
								{type entities}
								{selector
									{tag small_offmap_supply_fin}
								}
							}
							{"delay"
								{time 0.1}
							}
							{"actor_to_waypoint"
								{selector
									{source advanced}
									{group
										{select
											{tag
												{tag small_offmap_supply_ford}
											}
										}
										{include
											{tag
												{tag hidden}
											}
										}
										{exclude
											{tag
												{tag offmap_supply_on_map}
											}
											{tag
												{tag offmap_supply_deployed}
											}
											{player
												{player "2"}
											}
										
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
									}
									{amount 1
									}
								}
								{drop "orders sensor senseless"}
								{waypoint "1090"}
								{clone}
								{approach "safe teleport & rotate"}
							}
							{"delay"
								{time 0.1}
							}
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
									{"placement"
										{selector
											{source advanced}
											{group
												{select
													{tag
														{tag small_offmap_supply_ford}
													}
												}
												{exclude
													{tag
														{tag hidden}
													}
													{tag
														{tag offmap_supply_on_map}
													}
													{tag
														{tag offmap_supply_deployed}
													}
												
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
											}
											{amount 1
											}
										}
										{target
											{source advanced}
											{group
												{select
													{tag
														{tag spawn_b}
													}
												}
												{exclude
													{tag
														{tag _p}
													}
													{tag
														{tag _d}
													}
													{tag
														{tag _placed}
													}
													{tag
														{tag _displayed}
													}
												}
											}
											{sort
												{type shuffle}
											}
										}
									}
								}
								{"case"
									{condition
										{type cmp_i}
										{var "bots_spawnside$"}
										{op "=="}
										{value 2}
									}
									{"delay"
										{time 0.1}
									}
									{"placement"
										{selector
											{source advanced}
											{group
												{select
													{tag
														{tag small_offmap_supply_ford}
													}
												}
												{exclude
													{tag
														{tag hidden}
													}
													{tag
														{tag offmap_supply_on_map}
													}
													{tag
														{tag offmap_supply_deployed}
													}
												
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
											}
											{amount 1
											}
										}
										{target
											{source advanced}
											{group
												{select
													{tag
														{tag spawn_a}
													}
												}
												{exclude
													{tag
														{tag _p}
													}
													{tag
														{tag _d}
													}
													{tag
														{tag _placed}
													}
													{tag
														{tag _displayed}
													}
												}
											}
											{sort
												{type shuffle}
											}
										}
									}
								}
								{"default"}
							}
							{"delay"
								{time 0.1}
							}
							{"entity_state"
								{selector
									{source advanced}
									{group
										{select
											{tag
												{tag small_offmap_supply_ford}
											}
										}
										{include
											{zone
												{zone "gamezone"}
											}
											{state
												{state operatable}
											}
										}
										{exclude
											{state
												{state dead}
											}
											{state
												{state inactive}
											}
											{tag
												{tag hidden}
											}
											{tag
												{tag offmap_supply_deployed}
											}
										
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
									}
								}
								{tag_add offmap_supply_on_map}
							}
							{"delay"
								{time 0.1}
							}
							{"player"
								{selector
									{source advanced}
									{group
										{select
											{tag
												{tag small_offmap_supply_ford}
											}
											{tag
												{tag supply_driver}
											}
										}
										{include
											{zone
												{zone "gamezone"}
											}
											{state
												{state operatable}
											}
										}
										{exclude
											{state
												{state dead}
											}
											{state
												{state inactive}
											}
											{tag
												{tag hidden}
											}
											{tag
												{tag offmap_supply_deployed}
											}
											{tag
												{tag supply_driver_talk_off}
											}
										
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
									}
								}
								{operation set}
								{player "2"}
							}
							{"delay"
								{time 0.1}
							}
							{"actor_state"
								{selector
									{source advanced}
									{group
										{select
											{tag
												{tag small_offmap_supply_ford}
											}
											{tag
												{tag supply_driver}
											}
										}
										{include
											{zone
												{zone "gamezone"}
											}
											{state
												{state operatable}
											}
										}
										{exclude
											{state
												{state dead}
											}
											{state
												{state inactive}
											}
											{tag
												{tag hidden}
											}
											{tag
												{tag offmap_supply_deployed}
											}
											{tag
												{tag supply_driver_talk_off}
											}
										
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
									}
								}
								{control user}
								{fire_mode hold}
								{move_mode hold}
								{ai_move
									{mode disable}
								}
								{movement
									{speed fast}
								}
							}
							{"delay"
								{time 0.1}
							}
							{"ables"
								{selector
									{source advanced}
									{group
										{select
											{tag
												{tag small_offmap_supply_ford}
											}
											{tag
												{tag supply_driver}
											}
										}
										{include
											{zone
												{zone "gamezone"}
											}
											{state
												{state operatable}
											}
										}
										{exclude
											{state
												{state dead}
											}
											{state
												{state inactive}
											}
											{tag
												{tag hidden}
											}
											{tag
												{tag offmap_supply_deployed}
											}
											{tag
												{tag supply_driver_talk_off}
											}
										
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
									}
								}
								{remove select}
							}
							{"delay"
								{time 0.25}
							}
							{"action"
								{selector
									{source advanced}
									{group
										{select
											{tag
												{tag small_offmap_supply_ford}
											}
										}
										{include
											{zone
												{zone "gamezone"}
											}
											{state
												{state operatable}
											}
										}
										{exclude
											{state
												{state dead}
											}
											{state
												{state inactive}
											}
											{tag
												{tag hidden}
											}
											{tag
												{tag offmap_supply_deployed}
											}
										
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
									}
								}
								{drop "orders sensor senseless"}
								{action move}
								{target
									{source advanced}
									{group
										{select
											{tag
												{tag supply_destination}
											}
										}
										{include
											{zone
												{zone "gamezone"}
											}
										}
										{exclude
											{tag
												{tag destination_point_occupied}
											}
										}
									}
								}
							}
							{"delay"
								{time 0.25}
							}
							{"entity_state"
								{selector
									{source advanced}
									{group
										{select
											{tag
												{tag small_offmap_supply_ford}
											}
										}
										{include
											{zone
												{zone "gamezone"}
											}
											{state
												{state operatable}
											}
										}
										{exclude
											{tag
												{tag hidden}
											}
											{state
												{state dead}
											}
											{state
												{state inactive}
											}
										
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
									}
								}
								{tag_add offmap_supply_deployed}
							}
						}
						{"case"
							{condition
								{type entities}
								{selector
									{tag small_offmap_supply_usa}
								}
							}
							{"delay"
								{time 0.1}
							}
							{"actor_to_waypoint"
								{selector
									{source advanced}
									{group
										{select
											{tag
												{tag small_offmap_supply_cckw}
											}
										}
										{include
											{tag
												{tag hidden}
											}
										}
										{exclude
											{tag
												{tag offmap_supply_on_map}
											}
											{tag
												{tag offmap_supply_deployed}
											}
											{player
												{player "2"}
											}
										
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
									}
									{amount 1
									}
								}
								{drop "orders sensor senseless"}
								{waypoint "1090"}
								{clone}
								{approach "safe teleport & rotate"}
							}
							{"delay"
								{time 0.1}
							}
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
									{"placement"
										{selector
											{source advanced}
											{group
												{select
													{tag
														{tag small_offmap_supply_cckw}
													}
												}
												{exclude
													{tag
														{tag hidden}
													}
													{tag
														{tag offmap_supply_on_map}
													}
													{tag
														{tag offmap_supply_deployed}
													}
												
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
											}
											{amount 1
											}
										}
										{target
											{source advanced}
											{group
												{select
													{tag
														{tag spawn_b}
													}
												}
												{exclude
													{tag
														{tag _p}
													}
													{tag
														{tag _d}
													}
													{tag
														{tag _placed}
													}
													{tag
														{tag _displayed}
													}
												}
											}
											{sort
												{type shuffle}
											}
										}
									}
								}
								{"case"
									{condition
										{type cmp_i}
										{var "bots_spawnside$"}
										{op "=="}
										{value 2}
									}
									{"delay"
										{time 0.1}
									}
									{"placement"
										{selector
											{source advanced}
											{group
												{select
													{tag
														{tag small_offmap_supply_cckw}
													}
												}
												{exclude
													{tag
														{tag hidden}
													}
													{tag
														{tag offmap_supply_on_map}
													}
													{tag
														{tag offmap_supply_deployed}
													}
												
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
											}
											{amount 1
											}
										}
										{target
											{source advanced}
											{group
												{select
													{tag
														{tag spawn_a}
													}
												}
												{exclude
													{tag
														{tag _p}
													}
													{tag
														{tag _d}
													}
													{tag
														{tag _placed}
													}
													{tag
														{tag _displayed}
													}
												}
											}
											{sort
												{type shuffle}
											}
										}
									}
								}
								{"default"}
							}
							{"delay"
								{time 0.1}
							}
							{"entity_state"
								{selector
									{source advanced}
									{group
										{select
											{tag
												{tag small_offmap_supply_cckw}
											}
										}
										{include
											{zone
												{zone "gamezone"}
											}
											{state
												{state operatable}
											}
										}
										{exclude
											{state
												{state dead}
											}
											{state
												{state inactive}
											}
											{tag
												{tag hidden}
											}
											{tag
												{tag offmap_supply_deployed}
											}
										
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
									}
								}
								{tag_add offmap_supply_on_map}
							}
							{"delay"
								{time 0.1}
							}
							{"player"
								{selector
									{source advanced}
									{group
										{select
											{tag
												{tag small_offmap_supply_cckw}
											}
											{tag
												{tag supply_driver}
											}
										}
										{include
											{zone
												{zone "gamezone"}
											}
											{state
												{state operatable}
											}
										}
										{exclude
											{state
												{state dead}
											}
											{state
												{state inactive}
											}
											{tag
												{tag hidden}
											}
											{tag
												{tag offmap_supply_deployed}
											}
											{tag
												{tag supply_driver_talk_off}
											}
										
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
									}
								}
								{operation set}
								{player "2"}
							}
							{"delay"
								{time 0.1}
							}
							{"actor_state"
								{selector
									{source advanced}
									{group
										{select
											{tag
												{tag small_offmap_supply_cckw}
											}
											{tag
												{tag supply_driver}
											}
										}
										{include
											{zone
												{zone "gamezone"}
											}
											{state
												{state operatable}
											}
										}
										{exclude
											{state
												{state dead}
											}
											{state
												{state inactive}
											}
											{tag
												{tag hidden}
											}
											{tag
												{tag offmap_supply_deployed}
											}
											{tag
												{tag supply_driver_talk_off}
											}
										
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
									}
								}
								{control user}
								{fire_mode hold}
								{move_mode hold}
								{ai_move
									{mode disable}
								}
								{movement
									{speed fast}
								}
							}
							{"delay"
								{time 0.1}
							}
							{"ables"
								{selector
									{source advanced}
									{group
										{select
											{tag
												{tag small_offmap_supply_cckw}
											}
											{tag
												{tag supply_driver}
											}
										}
										{include
											{zone
												{zone "gamezone"}
											}
											{state
												{state operatable}
											}
										}
										{exclude
											{state
												{state dead}
											}
											{state
												{state inactive}
											}
											{tag
												{tag hidden}
											}
											{tag
												{tag offmap_supply_deployed}
											}
											{tag
												{tag supply_driver_talk_off}
											}
										
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
									}
								}
								{remove select}
							}
							{"delay"
								{time 0.25}
							}
							{"action"
								{selector
									{source advanced}
									{group
										{select
											{tag
												{tag small_offmap_supply_cckw}
											}
										}
										{include
											{zone
												{zone "gamezone"}
											}
											{state
												{state operatable}
											}
										}
										{exclude
											{state
												{state dead}
											}
											{state
												{state inactive}
											}
											{tag
												{tag hidden}
											}
											{tag
												{tag offmap_supply_deployed}
											}
										
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
									}
								}
								{drop "orders sensor senseless"}
								{action move}
								{target
									{source advanced}
									{group
										{select
											{tag
												{tag supply_destination}
											}
										}
										{include
											{zone
												{zone "gamezone"}
											}
										}
										{exclude
											{tag
												{tag destination_point_occupied}
											}
										}
									}
								}
							}
							{"delay"
								{time 0.25}
							}
							{"entity_state"
								{selector
									{source advanced}
									{group
										{select
											{tag
												{tag small_offmap_supply_cckw}
											}
										}
										{include
											{zone
												{zone "gamezone"}
											}
											{state
												{state operatable}
											}
										}
										{exclude
											{tag
												{tag hidden}
											}
											{state
												{state dead}
											}
											{state
												{state inactive}
											}
										
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
									}
								}
								{tag_add offmap_supply_deployed}
							}
						}
						{"case"
							{condition
								{type entities}
								{selector
									{tag small_offmap_supply_eng}
								}
							}
							{"delay"
								{time 0.1}
							}
							{"actor_to_waypoint"
								{selector
									{source advanced}
									{group
										{select
											{tag
												{tag small_offmap_supply_bedford}
											}
										}
										{include
											{tag
												{tag hidden}
											}
										}
										{exclude
											{tag
												{tag offmap_supply_on_map}
											}
											{tag
												{tag offmap_supply_deployed}
											}
											{player
												{player "2"}
											}
										
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
									}
									{amount 1
									}
								}
								{drop "orders sensor senseless"}
								{waypoint "1090"}
								{clone}
								{approach "safe teleport & rotate"}
							}
							{"delay"
								{time 0.1}
							}
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
									{"placement"
										{selector
											{source advanced}
											{group
												{select
													{tag
														{tag small_offmap_supply_bedford}
													}
												}
												{exclude
													{tag
														{tag hidden}
													}
													{tag
														{tag offmap_supply_on_map}
													}
													{tag
														{tag offmap_supply_deployed}
													}
												
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
											}
											{amount 1
											}
										}
										{target
											{source advanced}
											{group
												{select
													{tag
														{tag spawn_b}
													}
												}
												{exclude
													{tag
														{tag _p}
													}
													{tag
														{tag _d}
													}
													{tag
														{tag _placed}
													}
													{tag
														{tag _displayed}
													}
												}
											}
											{sort
												{type shuffle}
											}
										}
									}
								}
								{"case"
									{condition
										{type cmp_i}
										{var "bots_spawnside$"}
										{op "=="}
										{value 2}
									}
									{"delay"
										{time 0.1}
									}
									{"placement"
										{selector
											{source advanced}
											{group
												{select
													{tag
														{tag small_offmap_supply_bedford}
													}
												}
												{exclude
													{tag
														{tag hidden}
													}
													{tag
														{tag offmap_supply_on_map}
													}
													{tag
														{tag offmap_supply_deployed}
													}
												
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
											}
											{amount 1
											}
										}
										{target
											{source advanced}
											{group
												{select
													{tag
														{tag spawn_a}
													}
												}
												{exclude
													{tag
														{tag _p}
													}
													{tag
														{tag _d}
													}
													{tag
														{tag _placed}
													}
													{tag
														{tag _displayed}
													}
												}
											}
											{sort
												{type shuffle}
											}
										}
									}
								}
								{"default"}
							}
							{"delay"
								{time 0.1}
							}
							{"entity_state"
								{selector
									{source advanced}
									{group
										{select
											{tag
												{tag small_offmap_supply_bedford}
											}
										}
										{include
											{zone
												{zone "gamezone"}
											}
											{state
												{state operatable}
											}
										}
										{exclude
											{state
												{state dead}
											}
											{state
												{state inactive}
											}
											{tag
												{tag hidden}
											}
											{tag
												{tag offmap_supply_deployed}
											}
										
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
									}
								}
								{tag_add offmap_supply_on_map}
							}
							{"delay"
								{time 0.1}
							}
							{"player"
								{selector
									{source advanced}
									{group
										{select
											{tag
												{tag small_offmap_supply_bedford}
											}
											{tag
												{tag supply_driver}
											}
										}
										{include
											{zone
												{zone "gamezone"}
											}
											{state
												{state operatable}
											}
										}
										{exclude
											{state
												{state dead}
											}
											{state
												{state inactive}
											}
											{tag
												{tag hidden}
											}
											{tag
												{tag offmap_supply_deployed}
											}
											{tag
												{tag supply_driver_talk_off}
											}
										
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
									}
								}
								{operation set}
								{player "2"}
							}
							{"delay"
								{time 0.1}
							}
							{"actor_state"
								{selector
									{source advanced}
									{group
										{select
											{tag
												{tag small_offmap_supply_bedford}
											}
											{tag
												{tag supply_driver}
											}
										}
										{include
											{zone
												{zone "gamezone"}
											}
											{state
												{state operatable}
											}
										}
										{exclude
											{state
												{state dead}
											}
											{state
												{state inactive}
											}
											{tag
												{tag hidden}
											}
											{tag
												{tag offmap_supply_deployed}
											}
											{tag
												{tag supply_driver_talk_off}
											}
										
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
									}
								}
								{control user}
								{fire_mode hold}
								{move_mode hold}
								{ai_move
									{mode disable}
								}
								{movement
									{speed fast}
								}
							}
							{"delay"
								{time 0.1}
							}
							{"ables"
								{selector
									{source advanced}
									{group
										{select
											{tag
												{tag small_offmap_supply_bedford}
											}
											{tag
												{tag supply_driver}
											}
										}
										{include
											{zone
												{zone "gamezone"}
											}
											{state
												{state operatable}
											}
										}
										{exclude
											{state
												{state dead}
											}
											{state
												{state inactive}
											}
											{tag
												{tag hidden}
											}
											{tag
												{tag offmap_supply_deployed}
											}
											{tag
												{tag supply_driver_talk_off}
											}
										
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
									}
								}
								{remove select}
							}
							{"delay"
								{time 0.25}
							}
							{"action"
								{selector
									{source advanced}
									{group
										{select
											{tag
												{tag small_offmap_supply_bedford}
											}
										}
										{include
											{zone
												{zone "gamezone"}
											}
											{state
												{state operatable}
											}
										}
										{exclude
											{state
												{state dead}
											}
											{state
												{state inactive}
											}
											{tag
												{tag hidden}
											}
											{tag
												{tag offmap_supply_deployed}
											}
										
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
									}
								}
								{drop "orders sensor senseless"}
								{action move}
								{target
									{source advanced}
									{group
										{select
											{tag
												{tag supply_destination}
											}
										}
										{include
											{zone
												{zone "gamezone"}
											}
										}
										{exclude
											{tag
												{tag destination_point_occupied}
											}
										}
									}
								}
							}
							{"delay"
								{time 0.25}
							}
							{"entity_state"
								{selector
									{source advanced}
									{group
										{select
											{tag
												{tag small_offmap_supply_bedford}
											}
										}
										{include
											{zone
												{zone "gamezone"}
											}
											{state
												{state operatable}
											}
										}
										{exclude
											{tag
												{tag hidden}
											}
											{state
												{state dead}
											}
											{state
												{state inactive}
											}
										
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
									}
								}
								{tag_add offmap_supply_deployed}
							}
						}
						{"default"}
					}
					{"delay"
						{time 2}
					}
					{"trigger"
						{name "hf officer system/offmap supply move"}
					}
				}
			}
			{"hf officer system/offmap supply arrived"
				{condition
					{terms
						{"2.near"
							{units
								{source advanced}
								{group
									{select
										{tag
											{tag supply_driver}
										}
									}
									{include
										{state
											{state operatable}
										}
									}
									{exclude
										{state
											{state dead}
										}
										{state
											{state inactive}
										}
										{tag
											{tag supply_driver_talk_off}
										}
									}
								}
								{amount 1
								}
							}
							{near_to
								{source advanced}
								{group
									{select
										{tag
											{tag destination_point_occupied}
										}
									}
								}
							}
							{distance 10}
						}
					}
				}
				{actions
					{"delay"
						{time 0.1}
					}
					{"entity_state"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag supply_driver}
									}
								}
								{include
									{player
										{player "2"}
									}
								}
								{exclude
									{state
										{state dead}
									}
									{state
										{state inactive}
									}
									{tag
										{tag supply_driver_talk_off}
									}
								
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
							}
							{sort
								{type entity}
								{entity
									{tag destination_point_occupied}
								}
							}
							{amount 1
							}
						}
						{tag_add supply_driver_talk}
					}
					{"delay"
						{time 0.1}
					}
					{"switch"
						{"case"
							{condition
								{type rand}
								{value 0.15}
							}
							{"delay"
								{time 0.1}
							}
							{"talk"
								{selector
									{source advanced}
									{group
										{select
											{tag
												{tag supply_driver_talk}
											}
										}
										{include
											{state
												{state operatable}
											}
										}
										{exclude
											{state
												{state dead}
											}
											{state
												{state inactive}
											}
											{tag
												{tag supply_driver_talk_off}
											}
										
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
									}
									{amount 1
									}
								}
								{text "mission/multi/supplies_arrived_var1"}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.15}
							}
							{"delay"
								{time 0.1}
							}
							{"talk"
								{selector
									{source advanced}
									{group
										{select
											{tag
												{tag supply_driver_talk}
											}
										}
										{include
											{state
												{state operatable}
											}
										}
										{exclude
											{state
												{state dead}
											}
											{state
												{state inactive}
											}
											{tag
												{tag supply_driver_talk_off}
											}
										
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
									}
									{amount 1
									}
								}
								{text "mission/multi/supplies_arrived_var2"}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.15}
							}
							{"delay"
								{time 0.1}
							}
							{"talk"
								{selector
									{source advanced}
									{group
										{select
											{tag
												{tag supply_driver_talk}
											}
										}
										{include
											{state
												{state operatable}
											}
										}
										{exclude
											{state
												{state dead}
											}
											{state
												{state inactive}
											}
											{tag
												{tag supply_driver_talk_off}
											}
										
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
									}
									{amount 1
									}
								}
								{text "mission/multi/supplies_arrived_var3"}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.15}
							}
							{"delay"
								{time 0.1}
							}
							{"talk"
								{selector
									{source advanced}
									{group
										{select
											{tag
												{tag supply_driver_talk}
											}
										}
										{include
											{state
												{state operatable}
											}
										}
										{exclude
											{state
												{state dead}
											}
											{state
												{state inactive}
											}
											{tag
												{tag supply_driver_talk_off}
											}
										
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
									}
									{amount 1
									}
								}
								{text "mission/multi/supplies_arrived_var4"}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.15}
							}
							{"delay"
								{time 0.1}
							}
							{"talk"
								{selector
									{source advanced}
									{group
										{select
											{tag
												{tag supply_driver_talk}
											}
										}
										{include
											{state
												{state operatable}
											}
										}
										{exclude
											{state
												{state dead}
											}
											{state
												{state inactive}
											}
											{tag
												{tag supply_driver_talk_off}
											}
										
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
									}
									{amount 1
									}
								}
								{text "mission/multi/supplies_arrived_var5"}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.15}
							}
							{"delay"
								{time 0.1}
							}
							{"talk"
								{selector
									{source advanced}
									{group
										{select
											{tag
												{tag supply_driver_talk}
											}
										}
										{include
											{state
												{state operatable}
											}
										}
										{exclude
											{state
												{state dead}
											}
											{state
												{state inactive}
											}
											{tag
												{tag supply_driver_talk_off}
											}
										
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
									}
									{amount 1
									}
								}
								{text "mission/multi/supplies_arrived_var6"}
							}
						}
						{"default"
							{"delay"
								{time 0.1}
							}
							{"talk"
								{selector
									{source advanced}
									{group
										{select
											{tag
												{tag supply_driver_talk}
											}
										}
										{include
											{state
												{state operatable}
											}
										}
										{exclude
											{state
												{state dead}
											}
											{state
												{state inactive}
											}
											{tag
												{tag supply_driver_talk_off}
											}
										
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
									}
									{amount 1
									}
								}
								{text "mission/multi/supplies_arrived_var1"}
							}
						}
					}
					{"delay"
						{time 0.1}
					}
					{"entity_state"
						{selector
							{tag supply_driver_talk}
						}
						{tag_add supply_driver_talk_off}
						{tag_remove supply_driver_talk}
					}
					{"delay"
						{time 3}
					}
					{"ables"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag offmap_supply}
									}
									{tag
										{tag supply_driver_talk_off}
									}
								}
								{include
									{state
										{state operatable}
									}
									{zone
										{zone "gamezone"}
									}
								}
								{exclude
									{state
										{state dead}
									}
									{state
										{state inactive}
									}
									{tag
										{tag hidden}
									}
								
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
							}
							{sort
								{type entity}
								{entity
									{tag destination_point_occupied}
								}
							}
							{amount 2
							}
						}
						{add select}
					}
					{"delay"
						{time 3}
					}
					{"trigger"
						{name "hf officer system/offmap supply arrived"}
					}
				}
			}
			{"hf officer system/airstrike fail var1"
				{condition
					{expression "1 & 2 & !3"}
					{terms
						{"1.entities"
							{selector
								{source advanced}
								{group
									{include
										{prop
											{prop airborne}
										}
										{state
											{state operatable}
										}
										{state
											{state inhabited}
										}
									}
									{exclude
										{state
											{state dead}
										}
										{state
											{state inactive}
										}
										{tag
											{tag airstrike_ai}
										}
										{tag
											{tag airstrike_rus}
										}
										{tag
											{tag airstrike_ger}
										}	
										{tag
											{tag airstrike_fin}
										}	
										{tag
											{tag airstrike_usa}
										}
										{tag
											{tag airstrike_eng}
										}										
										{tag
											{tag hidden}
										}
									
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
								}
							}
						}
						{"2.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag officer}
										}
									}
									{include
										{state
											{state user_control}
										}
										{state
											{state operatable}
										}
										{prop
											{prop human}
										}
									}
									{exclude
										{state
											{state dead}
										}
										{state
											{state inactive}
										}
										{tag
											{tag _bot}
										}
										{tag
											{tag bot}
										}
										{tag
											{tag _lua_mi}
										}
										{tag
											{tag wounded}
										}
										{tag
											{tag bleeding}
										}
										{tag
											{tag _bleeding}
										}
										{tag
											{tag wounded_animation_playing}
										}
									
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
								}
							}
						}
						{"3.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag signaller}
										}
									}
									{include
										{state
											{state user_control}
										}
										{state
											{state operatable}
										}
										{prop
											{prop human}
										}
									}
									{exclude
										{state
											{state dead}
										}
										{state
											{state inactive}
										}
										{tag
											{tag _bot}
										}
										{tag
											{tag bot}
										}
										{tag
											{tag _lua_mi}
										}
										{tag
											{tag wounded}
										}
										{tag
											{tag bleeding}
										}
										{tag
											{tag _bleeding}
										}
										{tag
											{tag wounded_animation_playing}
										}
									
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
								}
							}
						}
					}
				}
				{actions
					{"delay"
						{time 0.1}
					}
					{"delete"
						{selector
							{source advanced}
								{group
									{include
										{prop
											{prop airborne}
										}
										{state
											{state operatable}
										}
										{state
											{state inhabited}
										}
									}
									{exclude
										{state
											{state dead}
										}
										{state
											{state inactive}
										}
										{tag
											{tag airstrike_ai}
										}
										{tag
											{tag hidden}
										}
									
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
								}
						}
					}
					{"delay"
						{time 0.5}
					}
					{"talk"
						{selector
							{source advanced}
							{group
								{include
									{state
										{state user_control}
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
										{state dead}
									}
								
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
							}
							{amount 1
							}
						}
						{text "mission/multi/hq_failed_airstrike_var1"}
					}
					{"delay"
						{time 0.1}
					}
					{"trigger"
						{name "hf officer system/airstrike fail var1"}
					}
				}
			}
			{"hf officer system/airstrike fail var2"
				{condition
					{expression "1 & !2 & 3"}
					{terms
						{"1.entities"
							{selector
								{source advanced}
								{group
									{include
										{prop
											{prop airborne}
										}
										{state
											{state operatable}
										}
										{state
											{state inhabited}
										}
									}
									{exclude
										{state
											{state dead}
										}
										{state
											{state inactive}
										}
										{tag
											{tag airstrike_ai}
										}
										{tag
											{tag airstrike_rus}
										}
										{tag
											{tag airstrike_ger}
										}	
										{tag
											{tag airstrike_fin}
										}	
										{tag
											{tag airstrike_usa}
										}
										{tag
											{tag airstrike_eng}
										}	
										{tag
											{tag hidden}
										}
									
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
								}
							}
						}
						{"2.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag officer}
										}
									}
									{include
										{state
											{state user_control}
										}
										{state
											{state operatable}
										}
										{prop
											{prop human}
										}
									}
									{exclude
										{state
											{state dead}
										}
										{state
											{state inactive}
										}
										{tag
											{tag _bot}
										}
										{tag
											{tag bot}
										}
										{tag
											{tag _lua_mi}
										}
										{tag
											{tag wounded}
										}
										{tag
											{tag bleeding}
										}
										{tag
											{tag _bleeding}
										}
										{tag
											{tag wounded_animation_playing}
										}
									
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
								}
							}
						}
						{"3.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag signaller}
										}
									}
									{include
										{state
											{state user_control}
										}
										{state
											{state operatable}
										}
										{prop
											{prop human}
										}
									}
									{exclude
										{state
											{state dead}
										}
										{state
											{state inactive}
										}
										{tag
											{tag _bot}
										}
										{tag
											{tag bot}
										}
										{tag
											{tag _lua_mi}
										}
										{tag
											{tag wounded}
										}
										{tag
											{tag bleeding}
										}
										{tag
											{tag _bleeding}
										}
										{tag
											{tag wounded_animation_playing}
										}
									
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
								}
							}
						}
					}
				}
				{actions
					{"delay"
						{time 0.1}
					}
					{"delete"
						{selector
							{source advanced}
								{group
									{include
										{prop
											{prop airborne}
										}
										{state
											{state operatable}
										}
										{state
											{state inhabited}
										}
									}
									{exclude
										{state
											{state dead}
										}
										{state
											{state inactive}
										}
										{tag
											{tag airstrike_ai}
										}
										{tag
											{tag hidden}
										}
									
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
								}
						}
					}
					{"delay"
						{time 0.5}
					}
					{"talk"
						{selector
							{source advanced}
							{group
								{include
									{state
										{state user_control}
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
										{state dead}
									}
								
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
							}
							{amount 1
							}
						}
						{text "mission/multi/hq_failed_airstrike_var2"}
					}
					{"delay"
						{time 0.1}
					}
					{"trigger"
						{name "hf officer system/airstrike fail var2"}
					}
				}
			}
			{"hf officer system/airstrike fail var3"
				{condition
					{expression "1 & !2 & !3"}
					{terms
						{"1.entities"
							{selector
								{source advanced}
								{group
									{include
										{prop
											{prop airborne}
										}
										{state
											{state operatable}
										}
										{state
											{state inhabited}
										}
									}
									{exclude
										{state
											{state dead}
										}
										{state
											{state inactive}
										}
										{tag
											{tag airstrike_ai}
										}
										{tag
											{tag airstrike_rus}
										}
										{tag
											{tag airstrike_ger}
										}	
										{tag
											{tag airstrike_fin}
										}	
										{tag
											{tag airstrike_usa}
										}
										{tag
											{tag airstrike_eng}
										}	
										{tag
											{tag hidden}
										}
									
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
								}
							}
						}
						{"2.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag officer}
										}
									}
									{include
										{state
											{state user_control}
										}
										{state
											{state operatable}
										}
										{prop
											{prop human}
										}
									}
									{exclude
										{state
											{state dead}
										}
										{state
											{state inactive}
										}
										{tag
											{tag _bot}
										}
										{tag
											{tag bot}
										}
										{tag
											{tag _lua_mi}
										}
										{tag
											{tag wounded}
										}
										{tag
											{tag bleeding}
										}
										{tag
											{tag _bleeding}
										}
										{tag
											{tag wounded_animation_playing}
										}
									
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
								}
							}
						}
						{"3.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag signaller}
										}
									}
									{include
										{state
											{state user_control}
										}
										{state
											{state operatable}
										}
										{prop
											{prop human}
										}
									}
									{exclude
										{state
											{state dead}
										}
										{state
											{state inactive}
										}
										{tag
											{tag _bot}
										}
										{tag
											{tag bot}
										}
										{tag
											{tag _lua_mi}
										}
										{tag
											{tag wounded}
										}
										{tag
											{tag bleeding}
										}
										{tag
											{tag _bleeding}
										}
										{tag
											{tag wounded_animation_playing}
										}
									
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
								}
							}
						}
					}
				}
				{actions
					{"delay"
						{time 0.1}
					}
					{"delete"
						{selector
							{source advanced}
								{group
									{include
										{prop
											{prop airborne}
										}
										{state
											{state operatable}
										}
										{state
											{state inhabited}
										}
									}
									{exclude
										{state
											{state dead}
										}
										{state
											{state inactive}
										}
										{tag
											{tag airstrike_ai}
										}
										{tag
											{tag hidden}
										}
									
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
								}
						}
					}
					{"delay"
						{time 0.5}
					}
					{"talk"
						{selector
							{source advanced}
							{group
								{include
									{state
										{state user_control}
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
										{state dead}
									}
								
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
							}
							{amount 1
							}							
						}
						{text "mission/multi/hq_failed_airstrike_var3"}
					}
					{"delay"
						{time 0.1}
					}
					{"trigger"
						{name "hf officer system/airstrike fail var3"}
					}
				}
			}
			{"hf officer system/fire mission approved"
				{condition
					{terms
						{"1.entities"
							{selector
								{tag undefined_fire_mission}
							}
						}
						{"2.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag officer}
										}
									}
									{include
										{state
											{state user_control}
										}
										{state
											{state operatable}
										}
										{prop
											{prop human}
										}
									}
									{exclude
										{state
											{state dead}
										}
										{state
											{state inactive}
										}
										{tag
											{tag _bot}
										}
										{tag
											{tag bot}
										}
										{tag
											{tag _lua_mi}
										}
										{tag
											{tag wounded}
										}
										{tag
											{tag bleeding}
										}
										{tag
											{tag _bleeding}
										}
										{tag
											{tag wounded_animation_playing}
										}
									
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
								}
							}
						}
						{"3.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag signaller}
										}
									}
									{include
										{state
											{state user_control}
										}
										{state
											{state operatable}
										}
										{prop
											{prop human}
										}
									}
									{exclude
										{state
											{state dead}
										}
										{state
											{state inactive}
										}
										{tag
											{tag _bot}
										}
										{tag
											{tag bot}
										}
										{tag
											{tag _lua_mi}
										}
										{tag
											{tag wounded}
										}
										{tag
											{tag bleeding}
										}
										{tag
											{tag _bleeding}
										}
										{tag
											{tag wounded_animation_playing}
										}
									
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
								}
							}
						}
					}
				}
				{actions
					{"delay"
						{time 0.5}
					}
					{"entity_state"
						{selector
							{tag undefined_fire_mission}
						}
						{tag_add approved_fire_mission}
						{tag_remove undefined_fire_mission}
					}
					{"delay"
						{time 1}
					}
					{"trigger"
						{name "hf officer system/fire mission approved"}
					}
				}
			}
			{"hf officer system/fire mission fail var1"
				{condition
					{expression "1 & 2 & !3"}
					{terms
						{"1.entities"
							{selector
								{tag undefined_fire_mission}
							}
						}
						{"2.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag officer}
										}
									}
									{include
										{state
											{state user_control}
										}
										{state
											{state operatable}
										}
										{prop
											{prop human}
										}
									}
									{exclude
										{state
											{state dead}
										}
										{state
											{state inactive}
										}
										{tag
											{tag _bot}
										}
										{tag
											{tag bot}
										}
										{tag
											{tag _lua_mi}
										}
										{tag
											{tag wounded}
										}
										{tag
											{tag bleeding}
										}
										{tag
											{tag _bleeding}
										}
										{tag
											{tag wounded_animation_playing}
										}
									
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
								}
							}
						}
						{"3.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag signaller}
										}
									}
									{include
										{state
											{state user_control}
										}
										{state
											{state operatable}
										}
										{prop
											{prop human}
										}
									}
									{exclude
										{state
											{state dead}
										}
										{state
											{state inactive}
										}
										{tag
											{tag _bot}
										}
										{tag
											{tag bot}
										}
										{tag
											{tag _lua_mi}
										}
										{tag
											{tag wounded}
										}
										{tag
											{tag bleeding}
										}
										{tag
											{tag _bleeding}
										}
										{tag
											{tag wounded_animation_playing}
										}
									
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
								}
							}
						}
					}
				}
				{actions
					{"delay"
						{time 0.5}
					}
					{"talk"
						{selector
							{source advanced}
							{group
								{include
									{state
										{state user_control}
									}
									{state
										{state operatable}
									}
									{prop
										{prop human}
									}
								}
							
{exclude {tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}}
}
							{amount 1
							}							
						}
						{text "mission/multi/hq_failed_fire_mission_var1"}
					}
					{"delay"
						{time 3}
					}
					{"trigger"
						{name "hf officer system/fire mission fail var1"}
					}
				}
			}
			{"hf officer system/fire mission fail var2"
				{condition
					{expression "1 & !2 & 3"}
					{terms
						{"1.entities"
							{selector
								{tag undefined_fire_mission}
							}
						}
						{"2.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag officer}
										}
									}
									{include
										{state
											{state user_control}
										}
										{state
											{state operatable}
										}
										{prop
											{prop human}
										}
									}
									{exclude
										{state
											{state dead}
										}
										{state
											{state inactive}
										}
										{tag
											{tag _bot}
										}
										{tag
											{tag bot}
										}
										{tag
											{tag _lua_mi}
										}
										{tag
											{tag wounded}
										}
										{tag
											{tag bleeding}
										}
										{tag
											{tag _bleeding}
										}
										{tag
											{tag wounded_animation_playing}
										}
									
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
								}
							}
						}
						{"3.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag signaller}
										}
									}
									{include
										{state
											{state user_control}
										}
										{state
											{state operatable}
										}
										{prop
											{prop human}
										}
									}
									{exclude
										{state
											{state dead}
										}
										{state
											{state inactive}
										}
										{tag
											{tag _bot}
										}
										{tag
											{tag bot}
										}
										{tag
											{tag _lua_mi}
										}
										{tag
											{tag wounded}
										}
										{tag
											{tag bleeding}
										}
										{tag
											{tag _bleeding}
										}
										{tag
											{tag wounded_animation_playing}
										}
									
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
								}
							}
						}
					}
				}
				{actions
					{"delay"
						{time 0.5}
					}
					{"talk"
						{selector
							{source advanced}
							{group
								{include
									{state
										{state user_control}
									}
									{state
										{state operatable}
									}
									{prop
										{prop human}
									}
								}
							
{exclude {tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}}
}
							{amount 1
							}
						}
						{text "mission/multi/hq_failed_fire_mission_var2"}
					}
					{"delay"
						{time 3}
					}
					{"trigger"
						{name "hf officer system/fire mission fail var2"}
					}
				}
			}
			{"hf officer system/fire mission fail var3"
				{condition
					{expression "1 & !2 & !3"}
					{terms
						{"1.entities"
							{selector
								{tag undefined_fire_mission}
							}
						}
						{"2.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag officer}
										}
									}
									{include
										{state
											{state user_control}
										}
										{state
											{state operatable}
										}
										{prop
											{prop human}
										}
									}
									{exclude
										{state
											{state dead}
										}
										{state
											{state inactive}
										}
										{tag
											{tag _bot}
										}
										{tag
											{tag bot}
										}
										{tag
											{tag _lua_mi}
										}
										{tag
											{tag wounded}
										}
										{tag
											{tag bleeding}
										}
										{tag
											{tag _bleeding}
										}
										{tag
											{tag wounded_animation_playing}
										}
									
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
								}
							}
						}
						{"3.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag signaller}
										}
									}
									{include
										{state
											{state user_control}
										}
										{state
											{state operatable}
										}
										{prop
											{prop human}
										}
									}
									{exclude
										{state
											{state dead}
										}
										{state
											{state inactive}
										}
										{tag
											{tag _bot}
										}
										{tag
											{tag bot}
										}
										{tag
											{tag _lua_mi}
										}
										{tag
											{tag wounded}
										}
										{tag
											{tag bleeding}
										}
										{tag
											{tag _bleeding}
										}
										{tag
											{tag wounded_animation_playing}
										}
									
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
								}
							}
						}
					}
				}
				{actions
					{"delay"
						{time 0.5}
					}
					{"talk"
						{selector
							{source advanced}
							{group
								{include
									{state
										{state user_control}
									}
									{state
										{state operatable}
									}
									{prop
										{prop human}
									}
								}
							
{exclude {tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}}
}
							{amount 1
							}
						}
						{text "mission/multi/hq_failed_fire_mission_var3"}
					}
					{"delay"
						{time 3}
					}
					{"trigger"
						{name "hf officer system/fire mission fail var3"}
					}
				}
			}

;// AI Looting

(define "hf_looting_body"
			{"hf inf ai/looting weapon/looting body: %tag"
				{condition
					{terms
						{"1.see_actors"
							{selector
								{source advanced}
								{group
									{select
										{zone_ex
											{zone "gamezone"}
										}
									}
									{include
										{prop
											{prop human}
										}
									}
									{exclude
										{state
											{state user_control}
										}
										{state
											{state dead}
										}
										{state
											{state inactive}
										}
										{tag
											{tag _lua_mi}
										}
										{tag
											{tag hidden}
										}
										{with_item
											{type existance}
											{item "loot_%tag"}
										}
									
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
								}
								{amount 1
								}
							}
							{enemy
								{source advanced}
								{group
									{select
										{zone_ex
											{zone "gamezone"}
										}
									}
									{include
										{prop
											{prop human}
										}
										{with_item
											{type existance}
											{item "loot_%tag"}
										}
									}
									{exclude
										{tag
											{tag _ai_wounded_target_linked}
										}
										{state
											{state linked}
										}
										{tag
											{tag hidden}
										}
										{state
											{state operatable}
										}
									}
								}
								{amount 1
								}
								{sort
									{type entity}
									{entity
										{source advanced}
										{group
											{select
												{zone_ex
													{zone "gamezone"}
												}
											}
											{include
												{state
													{state operatable}
												}
												{prop
													{prop human}
												}
											}
											{exclude
												{state
													{state dead}
												}
												{state
													{state inactive}
												}
												{tag
													{tag hidden}
												}
											}
										}
									}
								}
							}
							{distance
								{mode near_than}
								{meters 10}
							}
							{tag
								{"tag pair"}
								{"for selector" _ai_looting_%tag}
								{"for enemy" _ai_looting_target_%tag}
							}
						}
					}
				}
				{actions
					{"delay"
						{time 0.1}
					}
					{"entity_state"
						{selector
							{tag _ai_looting_%tag}
						}
						{tag_add _lua_mi}
					}
					{"entity_state"
						{selector
							{tag _ai_looting_%tag}
						}
						{tag_add _ai_looting_weapon}
					}
					; UFB: retain the soldier's existing stance and squad following.
					{"delay"
						{time 0.1}
					}
					{"inventory"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag _ai_looting_%tag}
									}
								}
								{include
									{state
										{state operatable}
									}
								}
							
{exclude {tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}}
}
						}
						{action take_from}
						{item "loot_%tag"}
						{entity
							{source advanced}
							{group
								{select
									{tag
										{tag _ai_looting_target_%tag}
									}
								}
								{include
									{with_item
										{type existance}
										{item "loot_%tag"}
									}
								}
							}
						}
					}
					{"delay"
						{time 4}
					}
					{"entity_state"
						{selector
							{tag _ai_looting_%tag}
						}
						{tag_remove _lua_mi}
					}
					{"entity_state"
						{selector
							{tag _ai_looting_%tag}
						}
						{tag_remove _ai_looting_weapon}
					}
					{"delay"
						{time 0.1}
					}
					{"entity_state"
						{selector
							{tag _ai_looting_%tag}
						}
						{tag_remove _ai_looting_%tag}
					}
					{"entity_state"
						{selector
							{tag _ai_looting_target_%tag}
						}
						{tag_remove _ai_looting_target_%tag}
					}
					{"delay"
						{time 0.1}
					}
					{"trigger"
						{name "hf inf ai/looting weapon/looting body: %tag"}
					}
				}
			}
)

("hf_looting_body" tag(rocketlauncher))
("hf_looting_body" tag(atrifle))
("hf_looting_body" tag(riflegrenade))
("hf_looting_body" tag(mgun))
("hf_looting_body" tag(smg))
("hf_looting_body" tag(semirifle))
("hf_looting_body" tag(autorifle))
("hf_looting_body" tag(battlerifle))
("hf_looting_body" tag(assaultrifle))

(define "hf_looting_ground"
			{"hf inf ai/looting weapon/looting ground: %tag"
				{condition
					{type 1}
					{terms
						{"1.near"
							{units
								{source advanced}
								{group
									{select
										{zone_ex
											{zone "gamezone"}
										}
									}
									{include
										{prop
											{prop human}
										}
										{state
											{state operatable}
										}
									}
									{exclude
										{state
											{state dead}
										}
										{state
											{state inactive}
										}
										{tag
											{tag bleeding}
										}
										{tag
											{tag _lua_mi}
										}
										{tag
											{tag _ai_do_not_disturb}
										}
										{state
											{state user_control}
										}
										{with_item
											{type existance}
											{item "loot_%tag"}
										}
									}
								}
								{amount 1
								}
							}
							{near_to
								{source advanced}
								{group
									{select
										{zone_ex
											{zone "gamezone"}
										}
									}
									{include
										{tag
											{tag loot_%tag}
										}
									}
									{exclude
										{state
											{state linked}
										}
									}
								}
								{amount 1
								}
							}
							{distance 8}
						}
					}
				}
				{actions
					{"delay"
						{time 0.1}
					}
					{"entity_state"
						{selector
							{source advanced}
							{group
								{select
									{zone_ex
										{zone "gamezone"}
									}
								}
								{include
									{prop
										{prop human}
									}
									{state
										{state operatable}
									}
								}
								{exclude
									{with_item
										{type existance}
										{item "loot_%tag"}
									}
									{state
										{state dead}
									}
									{state
										{state inactive}
									}
									{state
										{state linked}
									}
									{state
										{state user_control}
									}
									{tag
										{tag _lua_mi}
									}
									{tag
										{tag _ai_do_not_disturb}
									}
									{tag
										{tag bleeding}
									}
								
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
							}
							{amount 1
							}
							{sort
								{type entity}
								{entity
									{tag loot_%tag}
								}
							}
						}
						{tag_add _ai_loot_ground_%tag}
					}
					{"entity_state"
						{selector
							{tag _ai_loot_ground_%tag}
						}
						{tag_add _lua_mi}
					}
					{"delay"
						{time 0.1}
					}
					{"action"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag _ai_loot_ground_%tag}
									}
								}
								{include
									{state
										{state operatable}
									}
								}
							
{exclude {tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}}
}
							{amount 1
							}
						}
						{action collect}
						{target
							{source advanced}
							{group
								{select
									{tag
										{tag loot_%tag}
									}
								}
							}
							{sort
								{type entity}
								{entity
									{tag _ai_loot_ground_%tag}
									{type human}
									{state "not dead"}
								}
							}
						}
					}
					{"delay"
						{time 4}
					}
					{"entity_state"
						{selector
							{tag _ai_loot_ground_%tag}
						}
						{tag_remove _lua_mi}
					}
					{"delay"
						{time 0.1}
					}
					{"entity_state"
						{selector
							{tag _ai_loot_ground_%tag}
						}
						{tag_remove _ai_loot_ground_%tag}
					}
					{"delay"
						{time 0.1}
					}
					{"trigger"
						{name "hf inf ai/looting weapon/looting ground: %tag"}
					}
				}
			}
)

("hf_looting_ground" tag(rocketlauncher))
("hf_looting_ground" tag(atrifle))

;//Mine clearing
			{"hf inf ai/mine clearing/clear mines"
				{condition
					{expression "4 & 5 & 6 & 7 & (1 & 2 & 3)"}
					{terms
						{"1.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag mine_planted}
										}
									}
									{exclude
										{tag
											{tag cmp_def}
										}
									
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
								}
							}
						}
						{"2.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag ai_using_mine_detector}
										}
									}
								
{exclude {tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}}
}
							}
						}
						{"3.cmp_i"
							{var "user_is_defender$"}
							{op "=="}
							{value 1}
						}
						{"4.cmp_i" {var "attacker_retreat_requested$"} {op "=="} {value 0}}
						{"5.cmp_i" {var "defender_retreat_requested$"} {op "=="} {value 0}}
						{"6.cmp_i" {var "bot_retreat_active$"} {op "=="} {value 0}}
						{"7.cmp_i" {var "winner_decided$"} {op "=="} {value 0}}
					}
				}
				{actions
					{"delay"
						{time 0.5}
					}
					{"switch"
						{"case"
							{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
							{"switch"
								{"case"
									{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
									{"switch"
										{"case"
											{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
											{"switch"
												{"case"
													{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
													{"actor_state"
														{selector
															{tag ai_using_mine_detector}
														}
														{fire_mode hold}
														{ai_move
															{mode disable}
														}
														{movement
															{speed fast}
														}
														{ai
															{follow_commander off}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
					{"loop" 6
						{"switch"
							{"case"
								{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
								{"switch"
									{"case"
										{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
										{"switch"
											{"case"
												{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
												{"switch"
													{"case"
														{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
														{"entity_state"
															{selector
																{source advanced}
																{group
																	{select
																		{tag
																			{tag mine_planted}
																		}
																	}
																	{exclude
																		{tag
																			{tag selected_for_clearing}
																		}
																		{state
																			{state inactive}
																		}
																		{tag
																			{tag mine_to_clear}
																		}
																	
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
																}
																{sort
																	{type entity}
																	{entity
																		{source advanced}
																		{group
																			{select
																				{tag
																					{tag mine_to_clear}
																				}
																			}
																			{exclude
																				{state
																					{state inactive}
																				}
																			}
																		}
																		{amount 1
																		}
																	}
																}
																{amount 1
																}
															}
															{tag_add mine_to_clear}
														}
													}
												}
											}
										}
									}
								}
							}
						}
						{"delay"
							{time 0.5}
						}
						{"switch"
							{"case"
								{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
								{"switch"
									{"case"
										{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
										{"switch"
											{"case"
												{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
												{"switch"
													{"case"
														{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
														{"action"
															{selector
																{amount 1
																}
																{tag ai_using_mine_detector}
															}
															{action advance}
															{target
																{source advanced}
																{group
																	{select
																		{tag
																			{tag mine_to_clear}
																		}
																	}
																	{exclude
																		{tag
																			{tag selected_for_clearing}
																		}
																		{state
																			{state inactive}
																		}
																	}
																}
																{amount 1
																}
																{sort
																	{type entity}
																	{entity
																		{amount 1
																		}
																		{tag ai_using_mine_detector}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
						{"delay"
							{time 0.5}
						}
						{"switch"
							{"case"
								{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
								{"switch"
									{"case"
										{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
										{"switch"
											{"case"
												{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
												{"switch"
													{"case"
														{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
														{"entity_state"
															{selector
																{source advanced}
																{group
																	{select
																		{tag
																			{tag mine_to_clear}
																		}
																	}
																	{exclude
																		{state
																			{state inactive}
																		}
																	
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
																}
															}
															{tag_add selected_for_clearing}
															{tag_remove mine_to_clear}
														}
													}
												}
											}
										}
									}
								}
							}
						}
						{"delay"
							{time 0.5}
						}
					}
					{"delay"
						{time 0.5}
					}
					{"entity_state"
						{selector
							{tag selected_for_clearing}
						}
						{tag_remove selected_for_clearing}
					}
					{"delay"
						{time 10}
					}
					{"trigger"
						{name "hf inf ai/mine clearing/clear mines"}
					}
				}
			}
			{"hf inf ai/mine clearing/clear mines tag"
				{condition
					{expression "4 & 5 & 6 & 7 & (1 & 2 & 3)"}
					{terms
						{"1.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag bot}
										}
										{tag
											{tag _bot}
										}
									}
									{include
										{with_item
											{type amount}
											{item "mine_detector"}
											{min 1}
										}
									}
									{exclude
										{state
											{state dead}
										}
										{state
											{state inactive}
										}
										{state
											{state user_control}
										}
										{state
											{state linked}
										}										
									
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
								}
							}
						}
						{"2.near"
							{units
								{source advanced}
								{group
									{select
										{tag
											{tag bot}
										}
										{tag
											{tag _bot}
										}
									}
									{include
										{with_item
											{type amount}
											{item "mine_detector"}
											{min 1}
										}
									}
									{exclude
										{state
											{state dead}
										}
										{state
											{state inactive}
										}
										{state
											{state user_control}
										}
									}
								}
							}
							{near_to
								{source advanced}
								{group
									{select
										{tag
											{tag mine_planted}
										}
									}
								}
							}
							{distance 140}
						}
						{"3.cmp_i"
							{var "user_is_defender$"}
							{op "=="}
							{value 1}
						}
						{"4.cmp_i" {var "attacker_retreat_requested$"} {op "=="} {value 0}}
						{"5.cmp_i" {var "defender_retreat_requested$"} {op "=="} {value 0}}
						{"6.cmp_i" {var "bot_retreat_active$"} {op "=="} {value 0}}
						{"7.cmp_i" {var "winner_decided$"} {op "=="} {value 0}}
					}
				}
				{actions
					{"delay"
						{time 0.1}
					}
					{"select"
						{source advanced}
						{group
							{select
								{tag
									{tag bot}
								}
								{tag
									{tag _bot}
								}
							}
							{include
								{with_item
									{type amount}
									{item "mine_detector"}
									{min 1}
								}
							}
							{exclude
								{tag
									{tag ai_using_mine_detector}
								}
							}
						}
					}
					{"delay"
						{time 0.1}
					}
					{"switch"
						{"case"
							{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
							{"switch"
								{"case"
									{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
									{"switch"
										{"case"
											{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
											{"switch"
												{"case"
													{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
													{"entity_state"
														{selector
															{source current}
														}
														{tag_add ai_mine_detector}
													}
												}
											}
										}
									}
								}
							}
						}
					}
					{"switch"
						{"case"
							{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
							{"switch"
								{"case"
									{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
									{"switch"
										{"case"
											{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
											{"switch"
												{"case"
													{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
													{"entity_state"
														{selector
															{source current}
														}
														{tag_add _lua_mi}
													}
												}
											}
										}
									}
								}
							}
						}
					}
					{"delay"
						{time 0.1}
					}
					{"switch"
						{"case"
							{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
							{"switch"
								{"case"
									{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
									{"switch"
										{"case"
											{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
											{"switch"
												{"case"
													{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
													{"inventory"
														{selector
															{source advanced}
															{group
																{select
																	{tag
																		{tag ai_mine_detector}
																	}
																}
																{exclude
																	{tag
																		{tag ai_using_mine_detector}
																	}
																
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
															}
														}
														{action take}
														{item "mine_detector"}
													}
												}
											}
										}
									}
								}
							}
						}
					}
					{"delay"
						{time 2}
					}
					{"switch"
						{"case"
							{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
							{"switch"
								{"case"
									{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
									{"switch"
										{"case"
											{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
											{"switch"
												{"case"
													{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
													{"entity_state"
														{selector
															{source advanced}
															{group
																{select
																	{tag
																		{tag ai_mine_detector}
																	}
																}
																{include
																	{with_item
																		{type using}
																		{item "mine_detector"}
																	}
																}
															
{exclude {tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}}
}
														}
														{tag_add ai_using_mine_detector}
														{tag_remove ai_mine_detector}
													}
												}
											}
										}
									}
								}
							}
						}
					}
					{"delay"
						{time 10}
					}
					{"trigger"
						{name "hf inf ai/mine clearing/clear mines tag"}
					}
				}
			}
			{"hf inf ai/mine clearing/clear mines detag"
				{condition
					{terms
						{"1.entities"
							{selector
								{tag ai_using_mine_detector}
							}
						}
						{"2.entities"
							{selector
								{tag mine_planted}
							}
							{count
								{op "=="}
								{value 0}
							}
						}
					}
				}
				{actions
					{"delay"
						{time 0.1}
					}
					{"switch"
						{"case"
							{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
							{"switch"
								{"case"
									{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
									{"switch"
										{"case"
											{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
											{"switch"
												{"case"
													{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
													{"action"
														{selector
															{tag ai_using_mine_detector}
														}
														{drop orders}
														{action cancel}
													}
												}
											}
										}
									}
								}
							}
						}
					}
					{"delay"
						{time 0.1}
					}
					{"switch"
						{"case"
							{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
							{"switch"
								{"case"
									{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
									{"switch"
										{"case"
											{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
											{"switch"
												{"case"
													{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
													{"actor_state"
														{selector
															{tag ai_using_mine_detector}
														}
														{drop orders}
														{control AI}
														{fire_mode open}
														{move_mode free}
														{ai_move
															{mode enable}
														}
														{movement
															{speed assault}
														}
													}
												}
											}
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
							{source advanced}
							{group
								{select
									{tag
										{tag ai_mine_detector}
									}
								}
							
{exclude {tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}}
}
						}
						{tag_remove ai_mine_detector}
					}
					{"delay"
						{time 0.1}
					}
					{"switch"
						{"case"
							{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
							{"switch"
								{"case"
									{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
									{"switch"
										{"case"
											{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
											{"switch"
												{"case"
													{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
													{"entity_state"
														{selector
															{source advanced}
															{group
																{select
																	{tag
																		{tag ai_using_mine_detector}
																	}
																}
															
{exclude {tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}}
}
														}
														{tag_remove _lua_mi}
													}
												}
											}
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
							{source advanced}
							{group
								{select
									{tag
										{tag ai_using_mine_detector}
									}
								}
							
{exclude {tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}}
}
						}
						{tag_remove ai_using_mine_detector}
					}
					{"delay"
						{time 10}
					}
					{"trigger"
						{name "hf inf ai/mine clearing/clear mines detag"}
					}
				}
			}

;// Arty AI
			{"hf arty ai/part 1"
				{condition
					{expression "(!1 & !2) & 3 & 4 & 5 & 6"}
					{terms
						{"1.near"
							{units
								{source advanced}
								{group
									{include
										{tag
											{tag bot_arty}
										}
									}
									{exclude
										{tag
											{tag bot_arty_move}
										}
										{tag
											{tag bot_arty_fire}
										}
										{state
											{state linked}
										}
										{tag
											{tag bot_arty_skedaddle}
										}
										{tag
											{tag range_less_than_320}
										}
									}
								}
							}
							{near_to
								{source advanced}
								{group
									{include
										{state
											{state user_control}
										}
									}
									{exclude
										{state
											{state dead}
										}
										{state
											{state inactive}
										}
										{tag
											{tag exploded}
										}
										{tag
											{tag ammo_cooked}
										}
										{tag
											{tag burned}
										}
										{tag
											{tag no_scavenge}
										}
										{tag
											{tag destroyed}
										}
										{tag
											{tag vehicle_destroyed}
										}
										{prop
											{prop human}
										}
									}
								}
							}
							{distance 320}
						}
						{"2.entities"
							{selector
								{source advanced}
								{group
									{include
										{tag
											{tag bot_arty_fire}
										}
									}
									{exclude
										{tag
											{tag bot_arty_skedaddle}
										}
										{state
											{state "dead inactive"}
										}
									
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
								}
							}
						}
						{"3.cmp_i" {var "attacker_retreat_requested$"} {op "=="} {value 0}}
						{"4.cmp_i" {var "defender_retreat_requested$"} {op "=="} {value 0}}
						{"5.cmp_i" {var "bot_retreat_active$"} {op "=="} {value 0}}
						{"6.cmp_i" {var "winner_decided$"} {op "=="} {value 0}}
					}
				}
				{actions
					{"delay"
						{time 0.1}
					}
					{"switch"
						{"case"
							{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
							{"switch"
								{"case"
									{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
									{"switch"
										{"case"
											{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
											{"switch"
												{"case"
													{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
													{"entity_state"
														{selector
															{source advanced}
															{group
																{include
																	{tag
																		{tag bot_arty}
																	}
																}
																{exclude
																	{state
																		{state dead}
																	}
																	{state
																		{state inactive}
																	}
																	{state
																		{state user_control}
																	}
																	{tag
																		{tag bot_arty_skedaddle}
																	}
																	{tag
																		{tag range_less_than_320}
																	}
																	{tag
																		{tag range_more_than_400}
																	}
																
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
															}
														}
														{tag_add bot_arty_move}
														{tag_remove bot_arty_fire}
													}
												}
											}
										}
									}
								}
							}
						}
					}
					{"delay"
						{time 0.1}
					}
					{"switch"
						{"case"
							{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
							{"switch"
								{"case"
									{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
									{"switch"
										{"case"
											{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
											{"switch"
												{"case"
													{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
													{"entity_state"
														{selector
															{source advanced}
															{group
																{select
																	{tag
																		{tag bot_arty_move}
																	}
																}
																{exclude
																	{tag
																		{tag range_less_than_320}
																	}
																	{tag
																		{tag range_more_than_320}
																	}
																
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
															}
														}
														{tag_remove bot_arty_fortified}
													}
												}
											}
										}
									}
								}
							}
						}
					}
					{"delay"
						{time 0.1}
					}
					{"switch"
						{"case"
							{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
							{"switch"
								{"case"
									{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
									{"switch"
										{"case"
											{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
											{"switch"
												{"case"
													{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
													{"actor_state"
														{selector
															{source advanced}
															{group
																{include
																	{tag
																		{tag bot_arty_move}
																	}
																}
																{exclude
																	{tag
																		{tag range_less_than_320}
																	}
																	{tag
																		{tag range_more_than_320}
																	}
																
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
															}
														}
														{drop "orders sensor"}
														{movement
															{speed fast}
														}
														{cannon move}
													}
												}
											}
										}
									}
								}
							}
						}
					}
					{"delay"
						{time 3.5}
					}
					{"switch"
						{"case"
							{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
							{"switch"
								{"case"
									{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
									{"switch"
										{"case"
											{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
											{"switch"
												{"case"
													{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
													{"action"
														{selector
															{source advanced}
															{group
																{select
																	{tag
																		{tag bot_arty_move}
																	}
																}
																{exclude
																	{tag
																		{tag range_less_than_320}
																	}
																	{tag
																		{tag range_more_than_400}
																	}
																
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
															}
														}
														{drop orders}
														{action move}
														{target
															{source advanced}
															{group
																{include
																	{state
																		{state user_control}
																	}
																	{prop
																		{prop vehicle}
																	}
																}
																{exclude
																	{prop
																		{prop human}
																	}
																	{state
																		{state "dead inactive"}
																	}
																	{tag
																		{tag exploded}
																	}
																	{tag
																		{tag ammo_cooked}
																	}
																	{tag
																		{tag burned}
																	}
																	{tag
																		{tag no_scavenge}
																	}
																	{tag
																		{tag destroyed}
																	}
																	{tag
																		{tag vehicle_destroyed}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
					{"delay"
						{time 60}
					}
					{"switch"
						{"case"
							{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
							{"switch"
								{"case"
									{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
									{"switch"
										{"case"
											{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
											{"switch"
												{"case"
													{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
													{"entity_state"
														{selector
															{source advanced}
															{group
																{select
																	{tag
																		{tag bot_arty_move}
																	}
																}
																{exclude
																	{tag
																		{tag range_less_than_320}
																	}
																	{tag
																		{tag range_more_than_400}
																	}
																
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
															}
														}
														{tag_remove bot_arty_move}
													}
												}
											}
										}
									}
								}
							}
						}
					}
					{"delay"
						{time 0.1}
					}
					{"switch"
						{"case"
							{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
							{"switch"
								{"case"
									{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
									{"switch"
										{"case"
											{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
											{"switch"
												{"case"
													{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
													{"trigger"
														{name "hf arty ai/part 1"}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
			{"hf arty ai/part 1.1"
				{condition
					{expression "(!1 & !2) & 3 & 4 & 5 & 6"}
					{terms
						{"1.near"
							{units
								{source advanced}
								{group
									{include
										{tag
											{tag bot_arty}
										}
										{tag
											{tag range_less_than_320}
										}
									}
									{exclude
										{tag
											{tag bot_arty_move}
										}
										{tag
											{tag bot_arty_fire}
										}
										{state
											{state linked}
										}
										{tag
											{tag bot_arty_skedaddle}
										}
									}
								}
							}
							{near_to
								{source advanced}
								{group
									{include
										{state
											{state user_control}
										}
									}
									{exclude
										{state
											{state dead}
										}
										{state
											{state inactive}
										}
										{tag
											{tag exploded}
										}
										{tag
											{tag ammo_cooked}
										}
										{tag
											{tag burned}
										}
										{tag
											{tag no_scavenge}
										}
										{tag
											{tag destroyed}
										}
										{tag
											{tag vehicle_destroyed}
										}
										{prop
											{prop human}
										}
									}
								}
							}
							{distance 260}
						}
						{"2.entities"
							{selector
								{source advanced}
								{group
									{include
										{tag
											{tag bot_arty_fire}
										}
									}
									{exclude
										{tag
											{tag bot_arty_skedaddle}
										}
										{state
											{state dead}
										}
										{state
											{state inactive}
										}
									
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
								}
							}
						}
						{"3.cmp_i" {var "attacker_retreat_requested$"} {op "=="} {value 0}}
						{"4.cmp_i" {var "defender_retreat_requested$"} {op "=="} {value 0}}
						{"5.cmp_i" {var "bot_retreat_active$"} {op "=="} {value 0}}
						{"6.cmp_i" {var "winner_decided$"} {op "=="} {value 0}}
					}
				}
				{actions
					{"delay"
						{time 0.1}
					}
					{"switch"
						{"case"
							{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
							{"switch"
								{"case"
									{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
									{"switch"
										{"case"
											{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
											{"switch"
												{"case"
													{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
													{"entity_state"
														{selector
															{source advanced}
															{group
																{include
																	{tag
																		{tag bot_arty}
																	}
																	{tag
																		{tag range_less_than_320}
																	}
																}
																{exclude
																	{state
																		{state "dead inactive user_control"}
																	}
																	{tag
																		{tag bot_arty_skedaddle}
																	}
																
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
															}
														}
														{tag_add bot_arty_move}
														{tag_remove bot_arty_fire}
													}
												}
											}
										}
									}
								}
							}
						}
					}
					{"delay"
						{time 0.1}
					}
					{"switch"
						{"case"
							{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
							{"switch"
								{"case"
									{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
									{"switch"
										{"case"
											{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
											{"switch"
												{"case"
													{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
													{"entity_state"
														{selector
															{source advanced}
															{group
																{select
																	{tag
																		{tag bot_arty_move}
																	}
																}
																{include
																	{tag
																		{tag range_less_than_320}
																	}
																}
															
{exclude {tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}}
}
														}
														{tag_remove bot_arty_fortified}
													}
												}
											}
										}
									}
								}
							}
						}
					}
					{"delay"
						{time 0.1}
					}
					{"switch"
						{"case"
							{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
							{"switch"
								{"case"
									{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
									{"switch"
										{"case"
											{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
											{"switch"
												{"case"
													{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
													{"actor_state"
														{selector
															{source advanced}
															{group
																{select
																	{tag
																		{tag bot_arty_move}
																	}
																}
																{include
																	{tag
																		{tag range_less_than_320}
																	}
																}
															
{exclude {tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}}
}
														}
														{drop "orders sensor"}
														{movement
															{speed fast}
														}
														{cannon move}
													}
												}
											}
										}
									}
								}
							}
						}
					}
					{"delay"
						{time 3.5}
					}
					{"switch"
						{"case"
							{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
							{"switch"
								{"case"
									{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
									{"switch"
										{"case"
											{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
											{"switch"
												{"case"
													{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
													{"action"
														{selector
															{source advanced}
															{group
																{select
																	{tag
																		{tag bot_arty_move}
																	}
																}
																{include
																	{tag
																		{tag range_less_than_320}
																	}
																}
															
{exclude {tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}}
}
														}
														{drop orders}
														{action move}
														{target
															{source advanced}
															{group
																{include
																	{state
																		{state user_control}
																	}
																	{prop
																		{prop vehicle}
																	}
																}
																{exclude
																	{prop
																		{prop human}
																	}
																	{state
																		{state "dead inactive"}
																	}
																	{tag
																		{tag exploded}
																	}
																	{tag
																		{tag ammo_cooked}
																	}
																	{tag
																		{tag burned}
																	}
																	{tag
																		{tag no_scavenge}
																	}
																	{tag
																		{tag destroyed}
																	}
																	{tag
																		{tag vehicle_destroyed}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
					{"delay"
						{time 60}
					}
					{"switch"
						{"case"
							{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
							{"switch"
								{"case"
									{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
									{"switch"
										{"case"
											{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
											{"switch"
												{"case"
													{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
													{"entity_state"
														{selector
															{source advanced}
															{group
																{select
																	{tag
																		{tag bot_arty_move}
																	}
																}
																{include
																	{tag
																		{tag range_less_than_320}
																	}
																}
															
{exclude {tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}}
}
														}
														{tag_remove bot_arty_move}
													}
												}
											}
										}
									}
								}
							}
						}
					}
					{"delay"
						{time 0.1}
					}
					{"switch"
						{"case"
							{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
							{"switch"
								{"case"
									{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
									{"switch"
										{"case"
											{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
											{"switch"
												{"case"
													{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
													{"trigger"
														{name "hf arty ai/part 1.1"}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
			{"hf arty ai/part 1.2"
				{condition
					{expression "(!1 & !2) & 3 & 4 & 5 & 6"}
					{terms
						{"1.near"
							{units
								{source advanced}
								{group
									{include
										{tag
											{tag bot_arty}
										}
										{tag
											{tag range_more_than_400}
										}
									}
									{exclude
										{tag
											{tag bot_arty_move}
										}
										{tag
											{tag bot_arty_fire}
										}
										{state
											{state linked}
										}
										{tag
											{tag bot_arty_skedaddle}
										}
									}
								}
							}
							{near_to
								{source advanced}
								{group
									{include
										{state
											{state user_control}
										}
									}
									{exclude
										{state
											{state "dead inactive"}
										}
										{tag
											{tag exploded}
										}
										{tag
											{tag ammo_cooked}
										}
										{tag
											{tag burned}
										}
										{tag
											{tag no_scavenge}
										}
										{tag
											{tag destroyed}
										}
										{tag
											{tag vehicle_destroyed}
										}
										{prop
											{prop human}
										}
									}
								}
							}
							{distance 405}
						}
						{"2.entities"
							{selector
								{source advanced}
								{group
									{include
										{tag
											{tag bot_arty_fire}
										}
									}
									{exclude
										{tag
											{tag bot_arty_skedaddle}
										}
										{state
											{state "dead inactive"}
										}
									
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
								}
							}
						}
						{"3.cmp_i" {var "attacker_retreat_requested$"} {op "=="} {value 0}}
						{"4.cmp_i" {var "defender_retreat_requested$"} {op "=="} {value 0}}
						{"5.cmp_i" {var "bot_retreat_active$"} {op "=="} {value 0}}
						{"6.cmp_i" {var "winner_decided$"} {op "=="} {value 0}}
					}
				}
				{actions
					{"delay"
						{time 0.1}
					}
					{"switch"
						{"case"
							{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
							{"switch"
								{"case"
									{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
									{"switch"
										{"case"
											{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
											{"switch"
												{"case"
													{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
													{"entity_state"
														{selector
															{source advanced}
															{group
																{include
																	{tag
																		{tag bot_arty}
																	}
																	{tag
																		{tag range_more_than_400}
																	}
																}
																{exclude
																	{state
																		{state "dead inactive user_control"}
																	}
																	{tag
																		{tag bot_arty_skedaddle}
																	}
																
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
															}
														}
														{tag_add bot_arty_move}
														{tag_remove bot_arty_fire}
													}
												}
											}
										}
									}
								}
							}
						}
					}
					{"delay"
						{time 0.1}
					}
					{"switch"
						{"case"
							{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
							{"switch"
								{"case"
									{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
									{"switch"
										{"case"
											{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
											{"switch"
												{"case"
													{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
													{"entity_state"
														{selector
															{source advanced}
															{group
																{select
																	{tag
																		{tag bot_arty_move}
																	}
																}
																{include
																	{tag
																		{tag range_more_than_400}
																	}
																}
															
{exclude {tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}}
}
														}
														{tag_remove bot_arty_fortified}
													}
												}
											}
										}
									}
								}
							}
						}
					}
					{"delay"
						{time 0.1}
					}
					{"switch"
						{"case"
							{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
							{"switch"
								{"case"
									{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
									{"switch"
										{"case"
											{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
											{"switch"
												{"case"
													{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
													{"actor_state"
														{selector
															{source advanced}
															{group
																{select
																	{tag
																		{tag bot_arty_move}
																	}
																}
																{include
																	{tag
																		{tag range_more_than_400}
																	}
																}
															
{exclude {tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}}
}
														}
														{drop "orders sensor"}
														{movement
															{speed fast}
														}
														{cannon move}
													}
												}
											}
										}
									}
								}
							}
						}
					}
					{"delay"
						{time 3.5}
					}
					{"switch"
						{"case"
							{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
							{"switch"
								{"case"
									{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
									{"switch"
										{"case"
											{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
											{"switch"
												{"case"
													{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
													{"action"
														{selector
															{source advanced}
															{group
																{select
																	{tag
																		{tag bot_arty_move}
																	}
																}
																{include
																	{tag
																		{tag range_more_than_400}
																	}
																}
															
{exclude {tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}}
}
														}
														{drop orders}
														{action move}
														{target
															{source advanced}
															{group
																{include
																	{state
																		{state user_control}
																	}
																	{prop
																		{prop vehicle}
																	}
																}
																{exclude
																	{prop
																		{prop human}
																	}
																	{state
																		{state "dead inactive"}
																	}
																	{tag
																		{tag exploded}
																	}
																	{tag
																		{tag ammo_cooked}
																	}
																	{tag
																		{tag burned}
																	}
																	{tag
																		{tag no_scavenge}
																	}
																	{tag
																		{tag destroyed}
																	}
																	{tag
																		{tag vehicle_destroyed}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
					{"delay"
						{time 60}
					}
					{"switch"
						{"case"
							{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
							{"switch"
								{"case"
									{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
									{"switch"
										{"case"
											{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
											{"switch"
												{"case"
													{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
													{"entity_state"
														{selector
															{source advanced}
															{group
																{select
																	{tag
																		{tag bot_arty_move}
																	}
																}
																{include
																	{tag
																		{tag range_more_than_400}
																	}
																}
															
{exclude {tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}}
}
														}
														{tag_remove bot_arty_move}
													}
												}
											}
										}
									}
								}
							}
						}
					}
					{"delay"
						{time 0.1}
					}
					{"switch"
						{"case"
							{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
							{"switch"
								{"case"
									{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
									{"switch"
										{"case"
											{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
											{"switch"
												{"case"
													{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
													{"trigger"
														{name "hf arty ai/part 1.2"}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
			{"hf arty ai/part 2"
				{condition
					{expression "(1) & 2 & 3 & 4 & 5"}
					{terms
						{"1.near"
							{units
								{source advanced}
								{group
									{select
										{tag
											{tag bot_arty}
										}
									}
									{exclude
										{tag
											{tag bot_arty_skedaddle}
										}
										{tag
											{tag range_less_than_320}
										}
										{tag
											{tag range_more_than_400}
										}
									}
								}
							}
							{near_to
								{source advanced}
								{group
									{include
										{state
											{state user_control}
										}
									}
									{exclude
										{state
											{state "dead inactive"}
										}
										{tag
											{tag exploded}
										}
										{tag
											{tag ammo_cooked}
										}
										{tag
											{tag burned}
										}
										{tag
											{tag no_scavenge}
										}
										{tag
											{tag destroyed}
										}
										{tag
											{tag vehicle_destroyed}
										}
										{prop
											{prop human}
										}
									}
								}
							}
							{distance 310}
						}
						{"2.cmp_i" {var "attacker_retreat_requested$"} {op "=="} {value 0}}
						{"3.cmp_i" {var "defender_retreat_requested$"} {op "=="} {value 0}}
						{"4.cmp_i" {var "bot_retreat_active$"} {op "=="} {value 0}}
						{"5.cmp_i" {var "winner_decided$"} {op "=="} {value 0}}
					}
				}
				{actions
					{"delay"
						{time 0.1}
					}
					{"switch"
						{"case"
							{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
							{"switch"
								{"case"
									{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
									{"switch"
										{"case"
											{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
											{"switch"
												{"case"
													{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
													{"entity_state"
														{selector
															{source advanced}
															{group
																{select
																	{tag
																		{tag bot_arty}
																	}
																}
																{exclude
																	{tag
																		{tag bot_arty_skedaddle}
																	}
																	{state
																		{state "dead inactive"}
																	}
																	{tag
																		{tag range_less_than_320}
																	}
																	{tag
																		{tag range_more_than_400}
																	}
																
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
															}
														}
														{tag_add bot_arty_fire}
														{tag_remove bot_arty_move}
													}
													{"actor_state"
														{selector
															{source advanced}
															{group
																{select
																	{tag
																		{tag bot_arty_fire}
																	}
																}
																{exclude
																	{tag
																		{tag range_less_than_320}
																	}
																	{tag
																		{tag range_more_than_400}
																	}
																
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
															}
														}
														{drop orders}
														{move_mode hold}
														{cannon fire}
													}
												}
											}
										}
									}
								}
							}
						}
					}
					{"delay"
						{time 4}
					}
					{"switch"
						{"case"
							{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
							{"switch"
								{"case"
									{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
									{"switch"
										{"case"
											{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
											{"switch"
												{"case"
													{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
													{"effect"
														{selector
															{source advanced}
															{group
																{select
																	{tag
																		{tag bot_arty_fire}
																	}
																}
																{exclude
																	{tag
																		{tag bot_arty_fortified}
																	}
																	{tag
																		{tag "+mobilegun"}
																	}
																	{tag
																		{tag range_less_than_320}
																	}
																	{tag
																		{tag range_more_than_400}
																	}
																
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
															}
														}
														{effect construction_sandbag_cannon_standard}
													}
												}
											}
										}
									}
								}
							}
						}
					}
					{"delay"
						{time 6}
					}
					{"switch"
						{"case"
							{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
							{"switch"
								{"case"
									{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
									{"switch"
										{"case"
											{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
											{"switch"
												{"case"
													{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
													{"entity_state"
														{selector
															{source advanced}
															{group
																{select
																	{tag
																		{tag bot_arty_fire}
																	}
																}
																{exclude
																	{state
																		{state "dead inactive"}
																	}
																	{tag
																		{tag range_less_than_320}
																	}
																	{tag
																		{tag range_more_than_400}
																	}
																
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
															}
														}
														{tag_add bot_arty_fortified}
													}
												}
											}
										}
									}
								}
							}
						}
					}
					{"delay"
						{time 1}
					}
					{"switch"
						{"case"
							{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
							{"switch"
								{"case"
									{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
									{"switch"
										{"case"
											{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
											{"switch"
												{"case"
													{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
													{"action"
														{selector
															{source advanced}
															{group
																{select
																	{tag
																		{tag bot_arty_fire}
																	}
																}
																{exclude
																	{tag
																		{tag range_less_than_320}
																	}
																	{tag
																		{tag range_more_than_400}
																	}
																
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
															}
														}
														{action rotate}
														{target
															{source advanced}
															{group
																{include
																	{tag
																		{tag _user}
																	}
																}
																{exclude
																	{prop
																		{prop human}
																	}
																	{state
																		{state "dead inactive"}
																	}
																	{tag
																		{tag exploded}
																	}
																	{tag
																		{tag ammo_cooked}
																	}
																	{tag
																		{tag burned}
																	}
																	{tag
																		{tag no_scavenge}
																	}
																	{tag
																		{tag destroyed}
																	}
																	{tag
																		{tag vehicle_destroyed}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
					{"delay"
						{time 0.25}
					}
					{"switch"
						{"case"
							{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
							{"switch"
								{"case"
									{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
									{"switch"
										{"case"
											{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
											{"switch"
												{"case"
													{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
													{"actor_fire"
														{selector
															{source advanced}
															{group
																{select
																	{tag
																		{tag bot_arty_fire}
																	}
																}
																{exclude
																	{tag
																		{tag range_less_than_320}
																	}
																	{tag
																		{tag range_more_than_400}
																	}
																
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
															}
														}
														{attack enemies}
														{enemies
															{source advanced}
															{group
																{include
																	{tag
																		{tag _user}
																	}
																}
																{exclude
																	{prop
																		{prop human}
																	}
																	{state
																		{state "dead inactive"}
																	}
																	{tag
																		{tag exploded}
																	}
																	{tag
																		{tag ammo_cooked}
																	}
																	{tag
																		{tag burned}
																	}
																	{tag
																		{tag no_scavenge}
																	}
																	{tag
																		{tag destroyed}
																	}
																	{tag
																		{tag vehicle_destroyed}
																	}
																}
															}
														}
														{interval 0}
														{time 30}
													}
												}
											}
										}
									}
								}
							}
						}
					}
					{"delay"
						{time 45}
					}
					{"switch"
						{"case"
							{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
							{"switch"
								{"case"
									{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
									{"switch"
										{"case"
											{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
											{"switch"
												{"case"
													{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
													{"action"
														{selector
															{source advanced}
															{group
																{select
																	{tag
																		{tag bot_arty_fire}
																	}
																}
																{exclude
																	{tag
																		{tag range_less_than_320}
																	}
																	{tag
																		{tag range_more_than_400}
																	}
																
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
															}
														}
														{action suppression_fire}
														{target
															{source advanced}
															{group
																{include
																	{tag
																		{tag _user}
																	}
																}
																{exclude
																	{prop
																		{prop human}
																	}
																	{state
																		{state "dead inactive"}
																	}
																	{tag
																		{tag exploded}
																	}
																	{tag
																		{tag ammo_cooked}
																	}
																	{tag
																		{tag burned}
																	}
																	{tag
																		{tag no_scavenge}
																	}
																	{tag
																		{tag destroyed}
																	}
																	{tag
																		{tag vehicle_destroyed}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
					{"delay"
						{time 45}
					}
					{"switch"
						{"case"
							{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
							{"switch"
								{"case"
									{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
									{"switch"
										{"case"
											{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
											{"switch"
												{"case"
													{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
													{"actor_fire"
														{selector
															{source advanced}
															{group
																{select
																	{tag
																		{tag bot_arty_fire}
																	}
																}
																{exclude
																	{tag
																		{tag range_less_than_320}
																	}
																	{tag
																		{tag range_more_than_400}
																	}
																
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
															}
														}
														{attack enemies}
														{enemies
															{source advanced}
															{group
																{include
																	{tag
																		{tag _user}
																	}
																}
																{exclude
																	{prop
																		{prop human}
																	}
																	{state
																		{state "dead inactive"}
																	}
																	{tag
																		{tag exploded}
																	}
																	{tag
																		{tag ammo_cooked}
																	}
																	{tag
																		{tag burned}
																	}
																	{tag
																		{tag no_scavenge}
																	}
																	{tag
																		{tag destroyed}
																	}
																	{tag
																		{tag vehicle_destroyed}
																	}
																}
															}
														}
														{interval 0}
														{time 30}
													}
												}
											}
										}
									}
								}
							}
						}
					}
					{"delay"
						{time 45}
					}
					{"switch"
						{"case"
							{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
							{"switch"
								{"case"
									{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
									{"switch"
										{"case"
											{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
											{"switch"
												{"case"
													{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
													{"action"
														{selector
															{source advanced}
															{group
																{select
																	{tag
																		{tag bot_arty_fire}
																	}
																}
																{exclude
																	{tag
																		{tag range_less_than_320}
																	}
																	{tag
																		{tag range_more_than_400}
																	}
																
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
															}
														}
														{action suppression_fire}
														{target
															{source advanced}
															{group
																{include
																	{tag
																		{tag _user}
																	}
																}
																{exclude
																	{prop
																		{prop human}
																	}
																	{state
																		{state "dead inactive"}
																	}
																	{tag
																		{tag exploded}
																	}
																	{tag
																		{tag ammo_cooked}
																	}
																	{tag
																		{tag burned}
																	}
																	{tag
																		{tag no_scavenge}
																	}
																	{tag
																		{tag destroyed}
																	}
																	{tag
																		{tag vehicle_destroyed}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
					{"delay"
						{time 45}
					}
					{"switch"
						{"case"
							{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
							{"switch"
								{"case"
									{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
									{"switch"
										{"case"
											{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
											{"switch"
												{"case"
													{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
													{"entity_state"
														{selector
															{source advanced}
															{group
																{select
																	{tag
																		{tag bot_arty_fire}
																	}
																}
																{exclude
																	{tag
																		{tag range_less_than_320}
																	}
																	{tag
																		{tag range_more_than_400}
																	}
																
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
															}
														}
														{tag_remove bot_arty_fire}
													}
												}
											}
										}
									}
								}
							}
						}
					}
					{"delay"
						{time 0.5}
					}
					{"switch"
						{"case"
							{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
							{"switch"
								{"case"
									{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
									{"switch"
										{"case"
											{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
											{"switch"
												{"case"
													{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
													{"trigger"
														{name "hf arty ai/part 2"}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
			{"hf arty ai/part 2.1"
				{condition
					{expression "(1) & 2 & 3 & 4 & 5"}
					{terms
						{"1.near"
							{units
								{source advanced}
								{group
									{select
										{tag
											{tag bot_arty}
										}
									}
									{include
										{tag
											{tag range_less_than_320}
										}
									}
									{exclude
										{tag
											{tag bot_arty_skedaddle}
										}
									}
								}
							}
							{near_to
								{source advanced}
								{group
									{include
										{state
											{state user_control}
										}
									}
									{exclude
										{state
											{state "dead inactive"}
										}
										{tag
											{tag exploded}
										}
										{tag
											{tag ammo_cooked}
										}
										{tag
											{tag burned}
										}
										{tag
											{tag no_scavenge}
										}
										{tag
											{tag destroyed}
										}
										{tag
											{tag vehicle_destroyed}
										}
										{prop
											{prop human}
										}
									}
								}
							}
							{distance 250}
						}
						{"2.cmp_i" {var "attacker_retreat_requested$"} {op "=="} {value 0}}
						{"3.cmp_i" {var "defender_retreat_requested$"} {op "=="} {value 0}}
						{"4.cmp_i" {var "bot_retreat_active$"} {op "=="} {value 0}}
						{"5.cmp_i" {var "winner_decided$"} {op "=="} {value 0}}
					}
				}
				{actions
					{"delay"
						{time 0.1}
					}
					{"switch"
						{"case"
							{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
							{"switch"
								{"case"
									{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
									{"switch"
										{"case"
											{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
											{"switch"
												{"case"
													{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
													{"entity_state"
														{selector
															{source advanced}
															{group
																{select
																	{tag
																		{tag bot_arty}
																	}
																}
																{include
																	{tag
																		{tag range_less_than_320}
																	}
																}
																{exclude
																	{tag
																		{tag bot_arty_skedaddle}
																	}
																	{state
																		{state "dead inactive"}
																	}
																
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
															}
														}
														{tag_add bot_arty_fire}
														{tag_remove bot_arty_move}
													}
													{"actor_state"
														{selector
															{source advanced}
															{group
																{select
																	{tag
																		{tag bot_arty_fire}
																	}
																}
																{include
																	{tag
																		{tag range_less_than_320}
																	}
																}
															
{exclude {tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}}
}
														}
														{drop orders}
														{move_mode hold}
														{cannon fire}
													}
												}
											}
										}
									}
								}
							}
						}
					}
					{"delay"
						{time 4}
					}
					{"switch"
						{"case"
							{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
							{"switch"
								{"case"
									{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
									{"switch"
										{"case"
											{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
											{"switch"
												{"case"
													{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
													{"effect"
														{selector
															{source advanced}
															{group
																{select
																	{tag
																		{tag bot_arty_fire}
																	}
																}
																{include
																	{tag
																		{tag range_less_than_320}
																	}
																}
																{exclude
																	{tag
																		{tag bot_arty_fortified}
																	}
																	{tag
																		{tag "+mobilegun"}
																	}
																
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
															}
														}
														{effect construction_sandbag_cannon_standard}
													}
												}
											}
										}
									}
								}
							}
						}
					}
					{"delay"
						{time 6}
					}
					{"switch"
						{"case"
							{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
							{"switch"
								{"case"
									{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
									{"switch"
										{"case"
											{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
											{"switch"
												{"case"
													{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
													{"entity_state"
														{selector
															{source advanced}
															{group
																{select
																	{tag
																		{tag bot_arty_fire}
																	}
																}
																{include
																	{tag
																		{tag range_less_than_320}
																	}
																}
																{exclude
																	{state
																		{state "dead inactive"}
																	}
																
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
															}
														}
														{tag_add bot_arty_fortified}
													}
												}
											}
										}
									}
								}
							}
						}
					}
					{"delay"
						{time 1}
					}
					{"switch"
						{"case"
							{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
							{"switch"
								{"case"
									{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
									{"switch"
										{"case"
											{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
											{"switch"
												{"case"
													{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
													{"action"
														{selector
															{source advanced}
															{group
																{select
																	{tag
																		{tag bot_arty_fire}
																	}
																}
																{include
																	{tag
																		{tag range_less_than_320}
																	}
																}
															
{exclude {tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}}
}
														}
														{action rotate}
														{target
															{source advanced}
															{group
																{include
																	{tag
																		{tag _user}
																	}
																}
																{exclude
																	{prop
																		{prop human}
																	}
																	{state
																		{state "dead inactive"}
																	}
																	{tag
																		{tag exploded}
																	}
																	{tag
																		{tag ammo_cooked}
																	}
																	{tag
																		{tag burned}
																	}
																	{tag
																		{tag no_scavenge}
																	}
																	{tag
																		{tag destroyed}
																	}
																	{tag
																		{tag vehicle_destroyed}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
					{"delay"
						{time 0.25}
					}
					{"switch"
						{"case"
							{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
							{"switch"
								{"case"
									{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
									{"switch"
										{"case"
											{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
											{"switch"
												{"case"
													{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
													{"actor_fire"
														{selector
															{source advanced}
															{group
																{select
																	{tag
																		{tag bot_arty_fire}
																	}
																}
																{include
																	{tag
																		{tag range_less_than_320}
																	}
																}
															
{exclude {tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}}
}
														}
														{attack enemies}
														{enemies
															{source advanced}
															{group
																{include
																	{tag
																		{tag _user}
																	}
																}
																{exclude
																	{prop
																		{prop human}
																	}
																	{state
																		{state "dead inactive"}
																	}
																	{tag
																		{tag exploded}
																	}
																	{tag
																		{tag ammo_cooked}
																	}
																	{tag
																		{tag burned}
																	}
																	{tag
																		{tag no_scavenge}
																	}
																	{tag
																		{tag destroyed}
																	}
																	{tag
																		{tag vehicle_destroyed}
																	}
																}
															}
														}
														{interval 0}
														{time 30}
													}
												}
											}
										}
									}
								}
							}
						}
					}
					{"delay"
						{time 45}
					}
					{"switch"
						{"case"
							{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
							{"switch"
								{"case"
									{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
									{"switch"
										{"case"
											{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
											{"switch"
												{"case"
													{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
													{"action"
														{selector
															{source advanced}
															{group
																{select
																	{tag
																		{tag bot_arty_fire}
																	}
																}
																{include
																	{tag
																		{tag range_less_than_320}
																	}
																}
															
{exclude {tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}}
}
														}
														{action suppression_fire}
														{target
															{source advanced}
															{group
																{include
																	{tag
																		{tag _user}
																	}
																}
																{exclude
																	{prop
																		{prop human}
																	}
																	{state
																		{state "dead inactive"}
																	}
																	{tag
																		{tag exploded}
																	}
																	{tag
																		{tag ammo_cooked}
																	}
																	{tag
																		{tag burned}
																	}
																	{tag
																		{tag no_scavenge}
																	}
																	{tag
																		{tag destroyed}
																	}
																	{tag
																		{tag vehicle_destroyed}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
					{"delay"
						{time 45}
					}
					{"switch"
						{"case"
							{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
							{"switch"
								{"case"
									{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
									{"switch"
										{"case"
											{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
											{"switch"
												{"case"
													{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
													{"actor_fire"
														{selector
															{source advanced}
															{group
																{select
																	{tag
																		{tag bot_arty_fire}
																	}
																}
																{include
																	{tag
																		{tag range_less_than_320}
																	}
																}
															
{exclude {tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}}
}
														}
														{attack enemies}
														{enemies
															{source advanced}
															{group
																{include
																	{tag
																		{tag _user}
																	}
																}
																{exclude
																	{prop
																		{prop human}
																	}
																	{state
																		{state "dead inactive"}
																	}
																	{tag
																		{tag exploded}
																	}
																	{tag
																		{tag ammo_cooked}
																	}
																	{tag
																		{tag burned}
																	}
																	{tag
																		{tag no_scavenge}
																	}
																	{tag
																		{tag destroyed}
																	}
																	{tag
																		{tag vehicle_destroyed}
																	}
																}
															}
														}
														{interval 0}
														{time 30}
													}
												}
											}
										}
									}
								}
							}
						}
					}
					{"delay"
						{time 45}
					}
					{"switch"
						{"case"
							{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
							{"switch"
								{"case"
									{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
									{"switch"
										{"case"
											{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
											{"switch"
												{"case"
													{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
													{"action"
														{selector
															{source advanced}
															{group
																{select
																	{tag
																		{tag bot_arty_fire}
																	}
																}
																{include
																	{tag
																		{tag range_less_than_320}
																	}
																}
															
{exclude {tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}}
}
														}
														{action suppression_fire}
														{target
															{source advanced}
															{group
																{include
																	{tag
																		{tag _user}
																	}
																}
																{exclude
																	{prop
																		{prop human}
																	}
																	{state
																		{state "dead inactive"}
																	}
																	{tag
																		{tag exploded}
																	}
																	{tag
																		{tag ammo_cooked}
																	}
																	{tag
																		{tag burned}
																	}
																	{tag
																		{tag no_scavenge}
																	}
																	{tag
																		{tag destroyed}
																	}
																	{tag
																		{tag vehicle_destroyed}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
					{"delay"
						{time 60}
					}
					{"switch"
						{"case"
							{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
							{"switch"
								{"case"
									{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
									{"switch"
										{"case"
											{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
											{"switch"
												{"case"
													{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
													{"entity_state"
														{selector
															{source advanced}
															{group
																{select
																	{tag
																		{tag bot_arty_fire}
																	}
																}
																{include
																	{tag
																		{tag range_less_than_320}
																	}
																}
															
{exclude {tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}}
}
														}
														{tag_remove bot_arty_fire}
													}
												}
											}
										}
									}
								}
							}
						}
					}
					{"delay"
						{time 0.5}
					}
					{"switch"
						{"case"
							{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
							{"switch"
								{"case"
									{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
									{"switch"
										{"case"
											{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
											{"switch"
												{"case"
													{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
													{"trigger"
														{name "hf arty ai/part 2.1"}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
			{"hf arty ai/part 2.2"
				{condition
					{expression "(1) & 2 & 3 & 4 & 5"}
					{terms
						{"1.near"
							{units
								{source advanced}
								{group
									{select
										{tag
											{tag bot_arty}
										}
									}
									{include
										{tag
											{tag range_more_than_400}
										}
									}
									{exclude
										{tag
											{tag bot_arty_skedaddle}
										}
									}
								}
							}
							{near_to
								{source advanced}
								{group
									{include
										{state
											{state user_control}
										}
									}
									{exclude
										{state
											{state "dead inactive"}
										}
										{tag
											{tag exploded}
										}
										{tag
											{tag ammo_cooked}
										}
										{tag
											{tag burned}
										}
										{tag
											{tag no_scavenge}
										}
										{tag
											{tag destroyed}
										}
										{tag
											{tag vehicle_destroyed}
										}
										{prop
											{prop human}
										}
									}
								}
							}
							{distance 400}
						}
						{"2.cmp_i" {var "attacker_retreat_requested$"} {op "=="} {value 0}}
						{"3.cmp_i" {var "defender_retreat_requested$"} {op "=="} {value 0}}
						{"4.cmp_i" {var "bot_retreat_active$"} {op "=="} {value 0}}
						{"5.cmp_i" {var "winner_decided$"} {op "=="} {value 0}}
					}
				}
				{actions
					{"delay"
						{time 0.1}
					}
					{"switch"
						{"case"
							{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
							{"switch"
								{"case"
									{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
									{"switch"
										{"case"
											{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
											{"switch"
												{"case"
													{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
													{"entity_state"
														{selector
															{source advanced}
															{group
																{select
																	{tag
																		{tag bot_arty}
																	}
																}
																{include
																	{tag
																		{tag range_more_than_400}
																	}
																}
																{exclude
																	{tag
																		{tag bot_arty_skedaddle}
																	}
																	{state
																		{state "dead inactive"}
																	}
																
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
															}
														}
														{tag_add bot_arty_fire}
														{tag_remove bot_arty_move}
													}
													{"actor_state"
														{selector
															{source advanced}
															{group
																{select
																	{tag
																		{tag bot_arty_fire}
																	}
																}
																{include
																	{tag
																		{tag range_more_than_400}
																	}
																}
															
{exclude {tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}}
}
														}
														{drop orders}
														{move_mode hold}
														{cannon fire}
													}
												}
											}
										}
									}
								}
							}
						}
					}
					{"delay"
						{time 4}
					}
					{"switch"
						{"case"
							{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
							{"switch"
								{"case"
									{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
									{"switch"
										{"case"
											{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
											{"switch"
												{"case"
													{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
													{"effect"
														{selector
															{source advanced}
															{group
																{select
																	{tag
																		{tag bot_arty_fire}
																	}
																}
																{include
																	{tag
																		{tag range_more_than_400}
																	}
																}
																{exclude
																	{tag
																		{tag bot_arty_fortified}
																	}
																	{tag
																		{tag "+mobilegun"}
																	}
																
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
															}
														}
														{effect construction_sandbag_cannon_standard}
													}
												}
											}
										}
									}
								}
							}
						}
					}
					{"delay"
						{time 6}
					}
					{"switch"
						{"case"
							{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
							{"switch"
								{"case"
									{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
									{"switch"
										{"case"
											{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
											{"switch"
												{"case"
													{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
													{"entity_state"
														{selector
															{source advanced}
															{group
																{select
																	{tag
																		{tag bot_arty_fire}
																	}
																}
																{include
																	{tag
																		{tag range_more_than_400}
																	}
																}
																{exclude
																	{state
																		{state "dead inactive"}
																	}
																
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
															}
														}
														{tag_add bot_arty_fortified}
													}
												}
											}
										}
									}
								}
							}
						}
					}
					{"delay"
						{time 1}
					}
					{"switch"
						{"case"
							{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
							{"switch"
								{"case"
									{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
									{"switch"
										{"case"
											{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
											{"switch"
												{"case"
													{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
													{"action"
														{selector
															{source advanced}
															{group
																{select
																	{tag
																		{tag bot_arty_fire}
																	}
																}
																{include
																	{tag
																		{tag range_more_than_400}
																	}
																}
															
{exclude {tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}}
}
														}
														{action rotate}
														{target
															{source advanced}
															{group
																{include
																	{tag
																		{tag _user}
																	}
																}
																{exclude
																	{prop
																		{prop human}
																	}
																	{state
																		{state "dead inactive"}
																	}
																	{tag
																		{tag exploded}
																	}
																	{tag
																		{tag ammo_cooked}
																	}
																	{tag
																		{tag burned}
																	}
																	{tag
																		{tag no_scavenge}
																	}
																	{tag
																		{tag destroyed}
																	}
																	{tag
																		{tag vehicle_destroyed}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
					{"delay"
						{time 0.25}
					}
					{"switch"
						{"case"
							{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
							{"switch"
								{"case"
									{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
									{"switch"
										{"case"
											{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
											{"switch"
												{"case"
													{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
													{"actor_fire"
														{selector
															{source advanced}
															{group
																{select
																	{tag
																		{tag bot_arty_fire}
																	}
																}
																{include
																	{tag
																		{tag range_more_than_400}
																	}
																}
															
{exclude {tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}}
}
														}
														{attack enemies}
														{enemies
															{source advanced}
															{group
																{include
																	{tag
																		{tag _user}
																	}
																}
																{exclude
																	{prop
																		{prop human}
																	}
																	{state
																		{state "dead inactive"}
																	}
																	{tag
																		{tag exploded}
																	}
																	{tag
																		{tag ammo_cooked}
																	}
																	{tag
																		{tag burned}
																	}
																	{tag
																		{tag no_scavenge}
																	}
																	{tag
																		{tag destroyed}
																	}
																	{tag
																		{tag vehicle_destroyed}
																	}
																}
															}
														}
														{interval 0}
														{time 30}
													}
												}
											}
										}
									}
								}
							}
						}
					}
					{"delay"
						{time 45}
					}
					{"switch"
						{"case"
							{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
							{"switch"
								{"case"
									{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
									{"switch"
										{"case"
											{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
											{"switch"
												{"case"
													{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
													{"action"
														{selector
															{source advanced}
															{group
																{select
																	{tag
																		{tag bot_arty_fire}
																	}
																}
																{include
																	{tag
																		{tag range_more_than_400}
																	}
																}
															
{exclude {tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}}
}
														}
														{action suppression_fire}
														{target
															{source advanced}
															{group
																{include
																	{tag
																		{tag _user}
																	}
																}
																{exclude
																	{prop
																		{prop human}
																	}
																	{state
																		{state "dead inactive"}
																	}
																	{tag
																		{tag exploded}
																	}
																	{tag
																		{tag ammo_cooked}
																	}
																	{tag
																		{tag burned}
																	}
																	{tag
																		{tag no_scavenge}
																	}
																	{tag
																		{tag destroyed}
																	}
																	{tag
																		{tag vehicle_destroyed}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
					{"delay"
						{time 45}
					}
					{"switch"
						{"case"
							{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
							{"switch"
								{"case"
									{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
									{"switch"
										{"case"
											{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
											{"switch"
												{"case"
													{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
													{"actor_fire"
														{selector
															{source advanced}
															{group
																{select
																	{tag
																		{tag bot_arty_fire}
																	}
																}
																{include
																	{tag
																		{tag range_more_than_400}
																	}
																}
															
{exclude {tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}}
}
														}
														{attack enemies}
														{enemies
															{source advanced}
															{group
																{include
																	{tag
																		{tag _user}
																	}
																}
																{exclude
																	{prop
																		{prop human}
																	}
																	{state
																		{state "dead inactive"}
																	}
																	{tag
																		{tag exploded}
																	}
																	{tag
																		{tag ammo_cooked}
																	}
																	{tag
																		{tag burned}
																	}
																	{tag
																		{tag no_scavenge}
																	}
																	{tag
																		{tag destroyed}
																	}
																	{tag
																		{tag vehicle_destroyed}
																	}
																}
															}
														}
														{interval 0}
														{time 30}
													}
												}
											}
										}
									}
								}
							}
						}
					}
					{"delay"
						{time 45}
					}
					{"switch"
						{"case"
							{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
							{"switch"
								{"case"
									{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
									{"switch"
										{"case"
											{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
											{"switch"
												{"case"
													{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
													{"action"
														{selector
															{source advanced}
															{group
																{select
																	{tag
																		{tag bot_arty_fire}
																	}
																}
																{include
																	{tag
																		{tag range_more_than_400}
																	}
																}
															
{exclude {tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}}
}
														}
														{action suppression_fire}
														{target
															{source advanced}
															{group
																{include
																	{tag
																		{tag _user}
																	}
																}
																{exclude
																	{prop
																		{prop human}
																	}
																	{state
																		{state "dead inactive"}
																	}
																	{tag
																		{tag exploded}
																	}
																	{tag
																		{tag ammo_cooked}
																	}
																	{tag
																		{tag burned}
																	}
																	{tag
																		{tag no_scavenge}
																	}
																	{tag
																		{tag destroyed}
																	}
																	{tag
																		{tag vehicle_destroyed}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
					{"delay"
						{time 60}
					}
					{"switch"
						{"case"
							{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
							{"switch"
								{"case"
									{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
									{"switch"
										{"case"
											{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
											{"switch"
												{"case"
													{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
													{"entity_state"
														{selector
															{source advanced}
															{group
																{select
																	{tag
																		{tag bot_arty_fire}
																	}
																}
																{include
																	{tag
																		{tag range_more_than_400}
																	}
																}
															
{exclude {tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}}
}
														}
														{tag_remove bot_arty_fire}
													}
												}
											}
										}
									}
								}
							}
						}
					}
					{"delay"
						{time 0.5}
					}
					{"switch"
						{"case"
							{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
							{"switch"
								{"case"
									{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
									{"switch"
										{"case"
											{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
											{"switch"
												{"case"
													{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
													{"trigger"
														{name "hf arty ai/part 2.2"}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
			{"hf arty ai/part 3"
				{condition
					{expression "(1 & 2 & !3) & 4 & 5 & 6 & 7"}
					{terms
						{"1.entities"
							{selector
								{tag bot_arty}
							}
						}
						{"2.entities"
							{selector
								{tag bot_aa}
							}
						}
						{"3.entities"
							{selector
								{tag bot_aa_guard}
								{state "not dead"}
							}
							{count
								{op ">="}
								{value 2}
							}
						}
						{"4.cmp_i" {var "attacker_retreat_requested$"} {op "=="} {value 0}}
						{"5.cmp_i" {var "defender_retreat_requested$"} {op "=="} {value 0}}
						{"6.cmp_i" {var "bot_retreat_active$"} {op "=="} {value 0}}
						{"7.cmp_i" {var "winner_decided$"} {op "=="} {value 0}}
					}
				}
				{actions
					{"delay"
						{time 0.1}
					}
					{"switch"
						{"case"
							{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
							{"switch"
								{"case"
									{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
									{"switch"
										{"case"
											{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
											{"switch"
												{"case"
													{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
													{"entity_state"
														{selector
															{amount 1
															}
															{tag bot_aa}
														}
														{tag_add bot_aa_guard}
													}
													{"entity_state"
														{selector
															{amount 1
															}
															{tag bot_aa_guard}
														}
														{tag_add bot_aa_guard_move}
													}
												}
											}
										}
									}
								}
							}
						}
					}
					{"delay"
						{time 0.1}
					}
					{"switch"
						{"case"
							{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
							{"switch"
								{"case"
									{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
									{"switch"
										{"case"
											{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
											{"switch"
												{"case"
													{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
													{"entity_state"
														{selector
															{amount 1
															}
															{tag bot_arty}
															{state "not dead"}
														}
														{tag_add bot_arty_guard}
													}
												}
											}
										}
									}
								}
							}
						}
					}
					{"delay"
						{time 2}
					}
					{"switch"
						{"case"
							{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
							{"switch"
								{"case"
									{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
									{"switch"
										{"case"
											{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
											{"switch"
												{"case"
													{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
													{"actor_state"
														{selector
															{source advanced}
															{group
																{select
																	{tag
																		{tag bot_aa_guard}
																	}
																}
																{exclude
																	{state
																		{state "dead inactive user_control"}
																	}
																	{tag
																		{tag bot_aa_guard_setlled}
																	}
																
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
															}
														}
														{drop "orders sensor"}
														{move_mode hold}
														{ai_move
															{mode disable}
															{enable_on enemy}
														}
														{movement
															{speed fast}
														}
														{cannon move}
													}
												}
											}
										}
									}
								}
							}
						}
					}
					{"delay"
						{time 2}
					}
					{"switch"
						{"case"
							{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
							{"switch"
								{"case"
									{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
									{"switch"
										{"case"
											{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
											{"switch"
												{"case"
													{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
													{"action"
														{selector
															{amount 1
															}
															{tag bot_aa_guard_move}
															{state "not dead"}
														}
														{drop orders}
														{action move}
														{target
															{source advanced}
															{group
																{select
																	{tag
																		{tag bot_arty_guard}
																	}
																}
																{exclude
																	{state
																		{state "dead inactive user_control"}
																	}
																}
															}
															{amount 1
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
					{"delay"
						{time 30}
					}
					{"switch"
						{"case"
							{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
							{"switch"
								{"case"
									{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
									{"switch"
										{"case"
											{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
											{"switch"
												{"case"
													{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
													{"trigger"
														{name "hf arty ai/part 3"}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
			{"hf arty ai/part 4"
				{condition
					{expression "(1) & 2 & 3 & 4 & 5"}
					{terms
						{"1.near"
							{units
								{source advanced}
								{group
									{select
										{tag
											{tag bot_aa_guard}
										}
									}
									{exclude
										{state
											{state "dead inactive user_control"}
										}
									}
								}
								{amount 1
								}
							}
							{near_to
								{amount 1
								}
								{tag bot_arty_guard}
							}
							{distance 30}
						}
						{"2.cmp_i" {var "attacker_retreat_requested$"} {op "=="} {value 0}}
						{"3.cmp_i" {var "defender_retreat_requested$"} {op "=="} {value 0}}
						{"4.cmp_i" {var "bot_retreat_active$"} {op "=="} {value 0}}
						{"5.cmp_i" {var "winner_decided$"} {op "=="} {value 0}}
					}
				}
				{actions
					{"delay"
						{time 0.1}
					}
					{"switch"
						{"case"
							{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
							{"switch"
								{"case"
									{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
									{"switch"
										{"case"
											{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
											{"switch"
												{"case"
													{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
													{"entity_state"
														{selector
															{tag bot_aa_guard_move}
														}
														{tag_remove bot_aa_guard_move}
													}
													{"actor_state"
														{selector
															{amount 1
															}
															{tag bot_aa_guard}
															{state "not dead"}
														}
														{drop orders}
														{move_mode hold}
														{ai_move
															{mode disable}
															{enable_on enemy}
														}
														{cannon fire}
													}
												}
											}
										}
									}
								}
							}
						}
					}
					{"delay"
						{time 0.1}
					}
					{"switch"
						{"case"
							{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
							{"switch"
								{"case"
									{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
									{"switch"
										{"case"
											{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
											{"switch"
												{"case"
													{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
													{"effect"
														{selector
															{amount 1
															}
															{tag bot_aa_guard}
														}
														{effect engine_off}
													}
												}
											}
										}
									}
								}
							}
						}
					}
					{"delay"
						{time 10}
					}
					{"switch"
						{"case"
							{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
							{"switch"
								{"case"
									{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
									{"switch"
										{"case"
											{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
											{"switch"
												{"case"
													{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
													{"trigger"
														{name "hf arty ai/part 4"}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
			{"hf arty ai/part 5"
				{condition
					{expression "(!1 & 2) & 3 & 4 & 5 & 6"}
					{terms
						{"1.near"
							{units
								{amount 1
								}
								{tag bot_aa_guard}
								{state "not dead"}
							}
							{near_to
								{amount 1
								}
								{tag bot_arty_guard}
							}
							{distance 35}
						}
						{"2.near"
							{units
								{amount 1
								}
								{tag bot_aa_guard}
							}
							{near_to
								{amount 1
								}
								{tag bot_arty_guard}
							}
							{distance 50}
						}
						{"3.cmp_i" {var "attacker_retreat_requested$"} {op "=="} {value 0}}
						{"4.cmp_i" {var "defender_retreat_requested$"} {op "=="} {value 0}}
						{"5.cmp_i" {var "bot_retreat_active$"} {op "=="} {value 0}}
						{"6.cmp_i" {var "winner_decided$"} {op "=="} {value 0}}
					}
				}
				{actions
					{"delay"
						{time 2}
					}
					{"switch"
						{"case"
							{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
							{"switch"
								{"case"
									{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
									{"switch"
										{"case"
											{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
											{"switch"
												{"case"
													{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
													{"effect"
														{selector
															{tag bot_aa_guard_move}
														}
														{effect engine_on}
													}
												}
											}
										}
									}
								}
							}
						}
					}
					{"delay"
						{time 1}
					}
					{"switch"
						{"case"
							{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
							{"switch"
								{"case"
									{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
									{"switch"
										{"case"
											{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
											{"switch"
												{"case"
													{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
													{"action"
														{selector
															{amount 1
															}
															{tag bot_aa_guard_move}
															{state "not dead"}
														}
														{drop orders}
														{action move}
														{target
															{amount 1
															}
															{tag bot_arty_guard}
															{state "not dead"}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
					{"delay"
						{time 10}
					}
					{"switch"
						{"case"
							{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
							{"switch"
								{"case"
									{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
									{"switch"
										{"case"
											{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
											{"switch"
												{"case"
													{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
													{"trigger"
														{name "hf arty ai/part 5"}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
			
;// Medic AI
			{"hf inf ai/wounded evac/wounded pick up"
				{condition
					{expression "1 & !2 & !3"}
					{terms
						{"1.see_actors"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag _bot}
										}
										{tag
											{tag bot}
										}
									}
									{include
										{state
											{state operatable}
										}
									}
									{exclude
										{tag
											{tag bot_medic}
										}
										{tag
											{tag _ai_do_not_disturb}
										}
										{state
											{state dead}
										}
										{state
											{state inactive}
										}
										{state
											{state user_control}
										}
										{tag
											{tag _ai_wounded_carrier_selected}
										}
										{tag
											{tag _ai_wounded_carrier_linked}
										}
										{tag
											{tag _ai_medic}
										}
										{tag
											{tag _ai_wounded_false_tag}
										}
										{tag
											{tag bleeding}
										}
									
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
								}
							}
							{enemy
								{source advanced}
								{group
									{select
										{tag
											{tag _bot}
										}
										{tag
											{tag bot}
										}
									}
									{include
										{tag
											{tag bleeding}
										}
									}
									{exclude
										{state
											{state user_control}
										}
										{tag
											{tag _ai_wounded_target}
										}
										{tag
											{tag _ai_wounded_target_linked}
										}
										{tag
											{tag _ai_wounded_false_tag}
										}
									}
								}
							}
							{distance
								{mode near_than}
								{meters 10}
							}
							{tag
								{"tag pair"}
								{"for selector" _ai_wounded_carrier}
								{"for enemy" _ai_wounded_target}
							}
						}
						{"2.see_actors"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag _ai_wounded_carrier}
										}
									}
									{include
										{state
											{state operatable}
										}
									}
									{exclude
										{tag
											{tag bot_medic}
										}
										{tag
											{tag _ai_do_not_disturb}
										}
										{state
											{state dead}
										}
										{state
											{state inactive}
										}
										{state
											{state user_control}
										}
										{tag
											{tag _ai_wounded_carrier_selected}
										}
										{tag
											{tag _ai_wounded_carrier_linked}
										}
										{tag
											{tag _ai_medic}
										}
										{tag
											{tag bleeding}
										}
									
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
								}
							}
							{enemy
								{source advanced}
								{group
									{select
										{tag
											{tag _ai_medic}
										}
									}
									{include
										{state
											{state operatable}
										}
									}
									{exclude
										{tag
											{tag bleeding}
										}
									}
								}
							}
							{distance
								{mode near_than}
								{meters 30}
							}
						}
						{"3.see_actors"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag _ai_wounded_carrier}
										}
									}
									{include
										{state
											{state operatable}
										}
									}
									{exclude
										{state
											{state dead}
										}
										{state
											{state inactive}
										}
										{tag
											{tag bleeding}
										}
									
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
								}
							}
							{enemy
								{source advanced}
								{group
									{select
										{zone_ex
											{zone "gamezone"}
										}
									}
									{include
										{state
											{state user_control}
										}
										{state
											{state operatable}
										}
									}
									{exclude
										{state
											{state dead}
										}
										{state
											{state inactive}
										}
										{tag
											{tag bleeding}
										}
									}
								}
							}
							{distance
								{mode near_than}
								{meters 30}
							}
						}
					}
				}
				{actions
					{"delay"
						{time 0.1}
					}
					{"entity_state"
						{selector
							{amount 1
							}
							{tag _ai_wounded_carrier}
							{type human}
							{state "not dead"}
						}
						{tag_add _ai_wounded_carrier_selected}
						{tag_remove _ai_wounded_carrier}
					}
					{"entity_state"
						{selector
							{tag _ai_wounded_carrier_selected}
							{type human}
							{state "not dead"}
						}
						{tag_add _lua_mi}
					}
					{"delay"
						{time 0.1}
					}
					{"action"
						{selector
							{amount 1
							}
							{tag _ai_wounded_carrier_selected}
							{type human}
							{state "not dead"}
						}
						{drop "orders sensor senseless"}
						{action collect}
						{target
							{source advanced}
							{group
								{select
									{tag
										{tag _ai_wounded_target}
									}
								}
							}
							{sort
								{type entity}
								{entity
									{amount 1
									}
									{tag _ai_wounded_carrier_selected}
								}
							}
						}
					}
					{"delay"
						{time 8}
					}
					{"trigger"
						{name "hf inf ai/wounded evac/wounded pick up"}
					}
				}
			}
			{"hf inf ai/wounded evac/wounded carry away"
				{condition
					{terms
						{"1.see_actors"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag _ai_wounded_carrier_selected}
										}
									}
									{include
										{with_item
											{type existance}
											{item "human"}
										}
									}
									{exclude
										{tag
											{tag _ai_wounded_carrier_linked}
										}
									
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
								}
							}
							{enemy
								{source advanced}
								{group
									{select
										{tag
											{tag _ai_wounded_target}
										}
									}
									{exclude
										{tag
											{tag _ai_wounded_target_linked}
										}
									}
								}
							}
							{distance
								{mode near_than}
								{meters 1.5}
							}
							{tag
								{"tag pair"}
								{"for selector" _ai_wounded_carrier_linked}
								{"for enemy" _ai_wounded_target_linked}
							}
						}
					}
				}
				{actions
					{"delay"
						{time 0.1}
					}
					{"entity_state"
						{selector
							{tag _ai_wounded_carrier_linked}
						}
						{tag_remove _ai_wounded_carrier}
					}
					{"entity_state"
						{selector
							{tag _ai_wounded_carrier_linked}
						}
						{tag_remove _ai_wounded_carrier_selected}
					}
					{"entity_state"
						{selector
							{tag _ai_wounded_target_linked}
						}
						{tag_remove _ai_wounded_target}
					}
					{"delay"
						{time 0.1}
					}
					{"switch"
						{"case"
							{condition
								{type cmp_i}
								{var "medical_tent_active$"}
								{op "!="}
								{value 1}
							}
							{"delay"
								{time 0.1}
							}
							{"call"
								{function "carry_wounded_tent_false"}
								{context
									{specified}
									{selector
										{source advanced}
										{group
											{select
												{tag
													{tag _ai_wounded_carrier_linked}
												}
											}
											{include
												{with_item
													{type existance}
													{item "human"}
												}
												{state
													{state operatable}
												}
											}
										
{exclude {tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}}
}
									}
								}
							}
						}
						{"case"
							{condition
								{type cmp_i}
								{var "medical_tent_active$"}
								{op "=="}
								{value 1}
							}
							{"delay"
								{time 0.1}
							}
							{"action"
								{selector
									{source advanced}
									{group
										{select
											{tag
												{tag _ai_wounded_carrier_linked}
											}
										}
										{include
											{with_item
												{type existance}
												{item "human"}
											}
										}
									
{exclude {tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}}
}
								}
								{drop "orders sensor senseless"}
								{action move}
								{target
									{tag map_point_medic_rally_ai}
								}
							}
						}
					}
					{"delay"
						{time 5}
					}
					{"trigger"
						{name "hf inf ai/wounded evac/wounded carry away"}
					}
				}
			}
			{"hf inf ai/medics/medics spawn"
				{condition
					{terms
						{"1.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag _bot}
										}
										{tag
											{tag bot}
										}
									}
									{include
										{tag
											{tag bleeding}
										}
									}
									{exclude
										{state
											{state user_control}
										}
									
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
}
								}
							}
							{count
								{op ">"}
								{value 3}
							}
						}
						{"2.entities"
							{selector
								{source advanced}
								{group
									{select
										{zone_ex
											{zone "gamezone"}
										}
									}
									{include
										{tag
											{tag _ai_medic}
										}
										{state
											{state operatable}
										}
									}
								
{exclude {tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}}
}
							}
							{count
								{op "<<"}
								{value 1}
							}
						}
					}
				}
				{actions
					{"delay"
						{time 0.1}
					}
					{"set_i"
						{var "wounded_quota_met$"}
						{op "="}
						{value 1}
					}
					{"delay"
						{time 0.1}
					}
					{"switch"
						{"case"
							{condition
								{type cmp_i}
								{var "bot_army$"}
								{op "=="}
								{value 1}
							}
							{"delay"
								{time 0.1}
							}
							{"actor_to_waypoint"
								{selector
									{source advanced}
									{group
										{select
											{tag
												{tag bot_medic}
											}
										}
										{include
											{tag
												{tag hidden}
											}
											{tag
												{tag rus}
											}
										}
									
{exclude {tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}}
}
									{amount 2
									}
								}
								{waypoint "1090"}
								{clone}
								{approach "safe teleport & rotate"}
							}
						}
						{"case"
							{condition
								{type cmp_i}
								{var "bot_army$"}
								{op "=="}
								{value 2}
							}
							{"delay"
								{time 0.1}
							}
							{"actor_to_waypoint"
								{selector
									{source advanced}
									{group
										{select
											{tag
												{tag bot_medic}
											}
										}
										{include
											{tag
												{tag hidden}
											}
											{tag
												{tag ger}
											}
										}
									
{exclude {tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}}
}
									{amount 2
									}
								}
								{waypoint "1090"}
								{clone}
								{approach "safe teleport & rotate"}
							}
						}
						{"case"
							{condition
								{type cmp_i}
								{var "bot_army$"}
								{op "=="}
								{value 3}
							}
							{"delay"
								{time 0.1}
							}
							{"actor_to_waypoint"
								{selector
									{source advanced}
									{group
										{select
											{tag
												{tag bot_medic}
											}
										}
										{include
											{tag
												{tag hidden}
											}
											{tag
												{tag fin}
											}
										}
									
{exclude {tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}}
}
									{amount 2
									}
								}
								{waypoint "1090"}
								{clone}
								{approach "safe teleport & rotate"}
							}
						}
						{"case"
							{condition
								{type cmp_i}
								{var "bot_army$"}
								{op "=="}
								{value 4}
							}
							{"delay"
								{time 0.1}
							}
							{"actor_to_waypoint"
								{selector
									{source advanced}
									{group
										{select
											{tag
												{tag bot_medic}
											}
										}
										{include
											{tag
												{tag hidden}
											}
											{tag
												{tag usa}
											}
										}
									
{exclude {tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}}
}
									{amount 2
									}
								}
								{waypoint "1090"}
								{clone}
								{approach "safe teleport & rotate"}
							}
						}
						{"case"
							{condition
								{type cmp_i}
								{var "bot_army$"}
								{op "=="}
								{value 5}
							}
							{"delay"
								{time 0.1}
							}
							{"actor_to_waypoint"
								{selector
									{source advanced}
									{group
										{select
											{tag
												{tag bot_medic}
											}
										}
										{include
											{tag
												{tag hidden}
											}
											{tag
												{tag eng}
											}
										}
									
{exclude {tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}}
}
									{amount 2
									}
								}
								{waypoint "1090"}
								{clone}
								{approach "safe teleport & rotate"}
							}
						}
					}
					{"delay"
						{time 0.1}
					}
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
							{"placement"
								{selector
									{source advanced}
									{group
										{select
											{zone_ex
												{zone "gamezone"}
											}
										}
										{include
											{tag
												{tag bot_medic}
											}
										}
										{exclude
											{tag
												{tag hidden}
											}
										
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
}
									}
									{amount 2
									}
								}
								{target
									{source advanced}
									{group
										{select
											{tag
												{tag spawn_a}
											}
										}
									}
									{sort
										{type shuffle}
									}
								}
							}
						}
						{"case"
							{condition
								{type cmp_i}
								{var "bots_spawnside$"}
								{op "=="}
								{value 2}
							}
							{"delay"
								{time 0.1}
							}
							{"placement"
								{selector
									{source advanced}
									{group
										{select
											{zone_ex
												{zone "gamezone"}
											}
										}
										{include
											{tag
												{tag bot_medic}
											}
										}
										{exclude
											{tag
												{tag hidden}
											}
										
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
}
									}
									{amount 2
									}
								}
								{target
									{source advanced}
									{group
										{select
											{tag
												{tag spawn_b}
											}
										}
									}
									{sort
										{type shuffle}
									}
								}
							}
						}
					}
					{"delay"
						{time 0.1}
					}
					{"player"
						{selector
							{source advanced}
							{group
								{select
									{zone_ex
										{zone "gamezone"}
									}
								}
								{include
									{tag
										{tag bot_medic}
									}
								}
								{exclude
									{tag
										{tag hidden}
									}
								
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
}
							}
						}
						{operation set}
						{player "1"}
					}
					{"delay"
						{time 0.1}
					}
					{"entity_state"
						{selector
							{source advanced}
							{group
								{select
									{zone_ex
										{zone "gamezone"}
									}
								}
								{include
									{tag
										{tag bot_medic}
									}
								}
								{exclude
									{tag
										{tag hidden}
									}
								
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
}
							}
							{amount 2
							}
						}
						{tag_add _ai_medic}
					}
					{"actor_state"
						{selector
							{source advanced}
							{group
								{select
									{zone_ex
										{zone "gamezone"}
									}
								}
								{include
									{tag
										{tag bot_medic}
									}
								}
								{exclude
									{tag
										{tag hidden}
									}
								
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
}
							}
						}
						{human
							{health 200}
						}
					}
					{"delay"
						{time 0.1}
					}
					{"entity_state"
						{selector
							{source advanced}
							{group
								{select
									{zone_ex
										{zone "gamezone"}
									}
								}
								{include
									{tag
										{tag bot_medic}
									}
								}
								{exclude
									{tag
										{tag hidden}
									}
									{tag
										{tag _ai_medic_passive}
									}
								
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
}
							}
							{amount 1
							}
						}
						{tag_add _ai_medic_active}
						{tag_remove bot_medic}
					}
					{"delay"
						{time 0.1}
					}
					{"entity_state"
						{selector
							{source advanced}
							{group
								{select
									{zone_ex
										{zone "gamezone"}
									}
								}
								{include
									{tag
										{tag bot_medic}
									}
								}
								{exclude
									{tag
										{tag hidden}
									}
									{tag
										{tag _ai_medic_active}
									}
								
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
}
							}
							{amount 1
							}
						}
						{tag_add _ai_medic_passive}
						{tag_remove bot_medic}
					}
					{"delay"
						{time 0.1}
					}
					{"action"
						{selector
							{tag _ai_medic}
							{type human}
							{state "not dead"}
						}
						{drop "orders sensor senseless"}
						{action advance}
						{target
							{source advanced}
							{group
								{select
									{zone_ex
										{zone "combat"}
									}
								}
								{include
									{tag
										{tag _bot}
									}
									{tag
										{tag bot}
									}
									{tag
										{tag bleeding}
									}
								}
							}
						}
					}
					{"delay"
						{time 300}
					}
					{"trigger"
						{name "hf inf ai/medics/medics spawn"}
					}
				}
			}
			{"hf inf ai/medics/medic passive"
				{condition
					{terms
						{"1.entities"
							{selector
								{source advanced}
								{group
									{select
										{zone_ex
											{zone "combat"}
										}
									}
									{include
										{tag
											{tag _ai_medic_passive}
										}
										{state
											{state operatable}
										}
									}
									{exclude
										{state
											{state dead}
										}
										{state
											{state inactive}
										}
										{tag
											{tag bleeding}
										}
									
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
}
								}
							}
						}
					}
				}
				{actions
					{"switch"
						{"case"
							{condition
								{type cmp_i}
								{var "medical_tent_active$"}
								{op "!="}
								{value 1}
							}
							{"delay"
								{time 15}
							}
							{"action"
								{selector
									{source advanced}
									{group
										{select
											{zone_ex
												{zone "combat"}
											}
										}
										{include
											{tag
												{tag _ai_medic_passive}
											}
											{state
												{state operatable}
											}
										}
										{exclude
											{state
												{state dead}
											}
											{state
												{state inactive}
											}
										
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
}
									}
								}
								{drop "orders sensor senseless"}
								{action cancel}
							}
							{"delay"
								{time 0.5}
							}
							{"animation"
								{selector
									{source advanced}
									{group
										{select
											{zone_ex
												{zone "combat"}
											}
										}
										{include
											{tag
												{tag _ai_medic_passive}
											}
											{state
												{state operatable}
											}
										}
										{exclude
											{state
												{state dead}
											}
											{state
												{state inactive}
											}
										
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
}
									}
								}
								{drop "orders sensor senseless"}
								{collage squat_construct_sandbag}
								{cicledelay 0}
								{delay 0}
								{totalTime 4}
							}
							{"effect"
								{selector
									{source advanced}
									{group
										{select
											{zone_ex
												{zone "combat"}
											}
										}
										{include
											{tag
												{tag _ai_medic_passive}
											}
											{state
												{state operatable}
											}
										}
										{exclude
											{state
												{state dead}
											}
											{state
												{state inactive}
											}
										
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
}
									}
								}
								{effect ai_medic_passive_build_tent}
							}
							{"delay"
								{time 5}
							}
							{"actor_state"
								{selector
									{source advanced}
									{group
										{include
											{tag
												{tag _ai_medic_passive_built_tent}
											}
											{state
												{state operatable}
											}
										}
										{exclude
											{state
												{state dead}
											}
											{state
												{state inactive}
											}
										
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
}
									}
								}
								{fire_mode hold}
								{move_mode zone}
								{move_radius 15}
							}
							{"delay"
								{time 0.1}
							}
							{"if"
								{condition
									{type entities}
									{selector
										{source advanced}
										{group
											{select
												{tag
													{tag _ai_medic_passive_built_tent}
												}
											}
											{include
												{state
													{state operatable}
												}
											}
											{exclude
												{state
													{state dead}
												}
												{state
													{state inactive}
												}
											
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
}
										}
									}
								}
								{"set_i"
									{var "medical_tent_active$"}
									{op "="}
									{value 1}
								}
							}
						}
						{"case"
							{condition
								{type cmp_i}
								{var "medical_tent_active$"}
								{op "=="}
								{value 1}
							}
							{"delay"
								{time 0.1}
							}
							{"action"
								{selector
									{tag _ai_medic_passive}
								}
								{drop "orders sensor senseless"}
								{action move}
								{target
									{tag map_point_medic_rally_ai}
								}
							}
						}
					}
					{"delay"
						{time 120}
					}
					{"trigger"
						{name "hf inf ai/medics/medic passive"}
					}
				}
			}
			{"hf inf ai/wounded evac/wounded carrier near tent"
				{condition
					{terms
						{"1.near"
							{units
								{source advanced}
								{group
									{select
										{tag
											{tag _ai_wounded_carrier_linked}
										}
									}
									{include
										{with_item
											{type existance}
											{item "human"}
										}
									}
								}
							}
							{near_to
								{tag map_point_medic_rally_ai}
							}
							{distance 10}
						}
					}
				}
				{actions
					{"entity_state"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag _ai_wounded_carrier_linked}
									}
								}
								{include
									{with_item
										{type existance}
										{item "human"}
									}
								}
							
{exclude {tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}}
}
							{sort
								{type entity}
								{entity
									{source advanced}
									{group
										{select
											{tag
												{tag map_point_medic_rally_ai}
											}
										}
									}
								}
							}
							{amount 1
							}
						}
						{tag_add _ai_wounded_carrier_drop}
					}
					{"delay"
						{time 0.75 -0.25}
					}
					{"action"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag _ai_wounded_carrier_drop}
									}
								}
								{include
									{with_item
										{type existance}
										{item "human"}
									}
								}
							
{exclude {tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}}
}
						}
						{drop orders}
						{action cancel}
					}
					{"delay"
						{time 1}
					}
					{"inventory"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag _ai_wounded_carrier_drop}
									}
								}
								{include
									{with_item
										{type existance}
										{item "human"}
									}
								}
							
{exclude {tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}}
}
						}
						{action drop}
					}
					{"delay"
						{time 3}
					}
					{"if"
						{condition
							{type near}
							{units
								{source advanced}
								{group
									{select
										{tag
											{tag _ai_wounded_target_linked}
										}
									}
								}
							}
							{near_to
								{source advanced}
								{group
									{select
										{tag
											{tag _ai_wounded_carrier_drop}
										}
									}
									{exclude
										{with_item
											{type existance}
											{item "human"}
										}
									}
								}
							}
							{distance 5}
						}
						{"entity_state"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag _ai_wounded_target_linked}
										}
									}
								
{exclude {tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}}
}
								{sort
									{type entity}
									{entity
										{source advanced}
										{group
											{select
												{tag
													{tag _ai_wounded_carrier_drop}
												}
											}
											{exclude
												{with_item
													{type existance}
													{item "human"}
												}
											}
										}
									}
								}
							}
							{tag_remove _ai_wounded_target_linked}
						}
					}
					{"actor_state"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag _ai_wounded_carrier_drop}
									}
								}
								{exclude
									{with_item
										{type existance}
										{item "human"}
									}
								
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
							}
						}
						{drop orders}
						{weapon_prepare on}
						{ai_move
							{mode enable}
						}
					}
					{"delay"
						{time 1}
					}
					{"action"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag _ai_wounded_carrier_drop}
									}
								}
								{exclude
									{with_item
										{type existance}
										{item "human"}
									}
								
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
							}
						}
						{drop orders}
						{action advance}
						{target
							{tag player}
						}
					}
					{"effect"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag _ai_wounded_carrier_drop}
									}
								}
								{exclude
									{with_item
										{type existance}
										{item "human"}
									}
								
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
							}
						}
						{effect ai_generic_cooldown_60sec}
					}
					{"entity_state"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag _ai_wounded_carrier_drop}
									}
								}
								{exclude
									{with_item
										{type existance}
										{item "human"}
									}
								
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
							}
						}
						{tag_remove _lua_mi}
					}
					{"entity_state"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag _ai_wounded_carrier_drop}
									}
								}
								{exclude
									{with_item
										{type existance}
										{item "human"}
									}
								
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
							}
						}
						{tag_remove _ai_wounded_carrier_linked}
					}
					{"entity_state"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag _ai_wounded_carrier_drop}
									}
								}
								{exclude
									{with_item
										{type existance}
										{item "human"}
									}
								
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
							}
						}
						{tag_remove _ai_wounded_carrier_drop}
					}
					{"delay"
						{time 3}
					}
					{"trigger"
						{name "hf inf ai/wounded evac/wounded carrier near tent"}
					}
				}
			}
			{"hf inf ai/medics/medic active move"
				{condition
					{expression "1 & !2"}
					{terms
						{"1.see_actors"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag _ai_medic_active}
										}
									}
									{include
										{state
											{state operatable}
										}
									}
									{exclude
										{tag
											{tag bleeding}
										}
										{state
											{state dead}
										}
										{state
											{state inactive}
										}
										{tag
											{tag _ai_medic_active_in_range}
										}
									
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
}
								}
							}
							{enemy
								{source advanced}
								{group
									{select
										{tag
											{tag _bot}
										}
										{tag
											{tag bot}
										}
									}
									{include
										{tag
											{tag bleeding}
										}
									}
								}
								{sort
									{type entity}
									{entity
										{tag _ai_medic_active}
										{type human}
										{state "not dead"}
									}
								}
							}
							{distance
								{mode near_than}
								{meters 250}
							}
							{tag
								{"tag pair"}
								{"for selector" _ai_medic_active_working}
							}
						}
						{"2.see_actors"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag _ai_medic_active}
										}
									}
									{include
										{state
											{state operatable}
										}
									}
								
{exclude {tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}}
}
							}
							{enemy
								{source advanced}
								{group
									{select
										{tag
											{tag _bot}
										}
										{tag
											{tag bot}
										}
									}
									{include
										{tag
											{tag bleeding}
										}
									}
								}
							}
							{distance
								{mode near_than}
								{meters 13}
							}
						}
					}
				}
				{actions
					{"delay"
						{time 0.1}
					}
					{"action"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag _ai_medic_active_working}
									}
								}
								{include
									{state
										{state operatable}
									}
								}
								{exclude
									{state
										{state dead}
									}
									{state
										{state inactive}
									}
									{tag
										{tag bleeding}
									}
									{tag
										{tag _ai_medic_active_in_range}
									}
								
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
}
							}
						}
						{drop orders}
						{action move}
						{target
							{source advanced}
							{group
								{select
									{tag
										{tag _bot}
									}
									{tag
										{tag bot}
									}
								}
								{include
									{tag
										{tag bleeding}
									}
								}
							}
							{sort
								{type entity}
								{entity
									{source advanced}
									{group
										{select
											{tag
												{tag _ai_medic_active}
											}
										}
										{include
											{state
												{state operatable}
											}
										}
									}
								}
							}
							{amount 1
							}
						}
					}
					{"delay"
						{time 1}
					}
					{"entity_state"
						{selector
							{tag _ai_medic_active_working}
						}
						{tag_remove _ai_medic_active_working}
					}
					{"delay"
						{time 12}
					}
					{"trigger"
						{name "hf inf ai/medics/medic active move"}
					}
				}
			}
			{"hf inf ai/wounded evac/wounded carrier inv check"
				{condition
					{terms
						{"1.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag _ai_wounded_carrier_linked}
										}
									}
									{include
										{state
											{state operatable}
										}
									}
									{exclude
										{with_item
											{type existance}
											{item "human"}
										}
									
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
								}
							}
							{count
								{op ">"}
								{value 1}
							}
						}
					}
				}
				{actions
					{"delay"
						{time 2}
					}
					{"actor_state"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag _ai_wounded_carrier_linked}
									}
								}
								{include
									{state
										{state operatable}
									}
								}
								{exclude
									{with_item
										{type existance}
										{item "human"}
									}
								
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
							}
						}
						{drop orders}
						{weapon_prepare on}
						{ai_move
							{mode enable}
						}
					}
					{"entity_state"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag _ai_wounded_carrier_linked}
									}
								}
								{include
									{state
										{state operatable}
									}
								}
								{exclude
									{with_item
										{type existance}
										{item "human"}
									}
								
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
							}
						}
						{tag_remove _ai_wounded_carrier_linked}
					}
					{"delay"
						{time 8}
					}
					{"trigger"
						{name "hf inf ai/wounded evac/wounded carrier inv check"}
					}
				}
			}
			{"hf inf ai/wounded evac/wounded carrier anim check"
				{condition
					{expression "!1 & 2"}
					{terms
						{"1.see_actors"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag _ai_wounded_carrier_linked}
										}
									}
									{include
										{with_item
											{type existance}
											{item "human"}
										}
										{state
											{state operatable}
										}
									}
								
{exclude {tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}}
}
							}
							{enemy
								{source advanced}
								{group
									{select
										{tag
											{tag _ai_wounded_target_linked}
										}
									}
									{include
										{tag
											{tag hf_wounded_carry_pose}
										}
										{tag
											{tag bleeding}
										}
									}
								}
							}
							{distance
								{mode near_than}
								{meters 2}
							}
						}
						{"2.see_actors"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag _ai_wounded_carrier_linked}
										}
									}
									{include
										{with_item
											{type existance}
											{item "human"}
										}
									}
								
{exclude {tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}}
}
							}
							{enemy
								{source advanced}
								{group
									{select
										{tag
											{tag hf_wounded_death_played}
										}
									}
								}
							}
							{distance
								{mode near_than}
								{meters 3}
							}
							{tag
								{"tag pair"}
								{"for selector" _ai_wounded_carrier_abort}
							}
						}
					}
				}
				{actions
					{"delay"
						{time 1}
					}
					{"inventory"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag _ai_wounded_carrier_abort}
									}
								}
								{include
									{with_item
										{type existance}
										{item "human"}
									}
								}
							
{exclude {tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}}
}
						}
						{action drop}
					}
					{"delay"
						{time 2.5}
					}
					{"actor_state"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag _ai_wounded_carrier_abort}
									}
								}
								{include
									{state
										{state operatable}
									}
								}
								{exclude
									{with_item
										{type existance}
										{item "human"}
									}
								
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
							}
						}
						{drop orders}
						{weapon_prepare on}
						{ai_move
							{mode enable}
						}
					}
					{"delay"
						{time 0.1}
					}
					{"entity_state"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag _ai_wounded_carrier_abort}
									}
								}
								{include
									{state
										{state operatable}
									}
								}
								{exclude
									{with_item
										{type existance}
										{item "human"}
									}
								
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
							}
						}
						{tag_remove _ai_wounded_carrier_abort}
					}
					{"delay"
						{time 5}
					}
					{"trigger"
						{name "hf inf ai/wounded evac/wounded carrier anim check"}
					}
				}
			}

;// Flanking AI
			{"hf flanking ai/detect and action"
				{condition
					{type 1}
					{terms
						{"1.entities"
							{selector
								{source advanced}
								{group
									{include
										{tag
											{tag _bot}
										}
										{tag
											{tag bot}
										}
										{state
											{state operatable}
										}
										{state
											{state chassis_work}
										}
										{state
											{state inhabited}
										}
									}
									{exclude
										{zone
											{zone "combat"}
										}
										{tag
											{tag body_break}
										}
										{tag
											{tag trans_break}
										}
										{tag
											{tag trackl_broken}
										}
										{tag
											{tag trackr_broken}
										}
										{state
											{state dead}
										}
										{state
											{state inactive}
										}
										{state
											{state user_control}
										}
										{tag
											{tag gun_broken}
										}
										{tag
											{tag turret_brake}
										}
										{tag
											{tag bot_arty}
										}
										{tag
											{tag _lua_mi}
										}
										{tag
											{tag bot_flank_finished}
										}
										{tag
											{tag bot_flank_in_progress}
										}
										{tag
											{tag bot_flanker}
										}	
										{prop
											{prop airborne}
										}
										{prop
											{prop cannon}
										}
									
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
								}
							}
							{count
								{op ">"}
								{value 2}
							}
						}
					}
				}
				{actions
					{"delay"
						{time 0.1}
					}
					{"entity_state"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag _bot}
									}
									{tag
										{tag bot}
									}
								}
								{include
									{state
										{state operatable}
									}
									{state
										{state chassis_work}
									}
									{state
										{state inhabited}
									}
								}
								{exclude
									{state
										{state dead}
									}
									{state
										{state inactive}
									}
									{state
										{state user_control}
									}
									{zone
										{zone "combat"}
									}
									{tag
										{tag bot_arty}
									}
									{tag
										{tag _lua_mi}
									}
									{tag
										{tag _user}
									}
									{tag
										{tag bot_flank_finished}
									}
									{tag
										{tag bot_flank_in_progress}
									}
									{tag
										{tag bot_flanker}
									}
									{prop
										{prop airborne}
									}
									{prop
										{prop cannon}
									}
								
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
							}
							{amount 1
							}
						}
						{tag_add bot_flanker}
					}
					{"delay"
						{time 0.1}
					}
					{"entity_state"
						{selector
							{tag bot_flanker}
						}
						{tag_add _lua_mi}
					}
					{"effect"
						{selector
							{tag bot_flanker}
						}
						{effect flanker_update_lights}
					}
					{"delay"
						{time 0.5}
					}
					{"switch"
						{"case"
							{condition
								{type rand}
								{value 0.25}
							}
							{"delay"
								{time 0.1}
							}
							{"actor_to_waypoint"
								{selector
									{amount 1
									}
									{tag bot_flanker}
								}
								{waypoint "1007"}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.25}
							}
							{"delay"
								{time 0.1}
							}
							{"actor_to_waypoint"
								{selector
									{amount 1
									}
									{tag bot_flanker}
								}
								{waypoint "1011"}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.25}
							}
							{"delay"
								{time 0.1}
							}
							{"actor_to_waypoint"
								{selector
									{amount 1
									}
									{tag bot_flanker}
								}
								{waypoint "1007"}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.25}
							}
							{"delay"
								{time 0.1}
							}
							{"actor_to_waypoint"
								{selector
									{amount 1
									}
									{tag bot_flanker}
								}
								{waypoint "1011"}
							}
						}
						{"default"
							{"delay"
								{time 0.1}
							}
							{"actor_to_waypoint"
								{selector
									{tag bot_flanker}
								}
								{waypoint "1007"}
							}
						}
					}
					{"delay"
						{time 0.1}
					}
					{"entity_state"
						{selector
							{tag bot_flanker}
						}
						{tag_add bot_flank_in_progress}
					}
					{"delay"
						{time 90}
					}
					{"trigger"
						{name "hf flanking ai/detect and action"}
					}
				}
			}


			{"hf flanking infantry ai/detect and action"
				{condition
					{terms
						{"1.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag _bot}
										}
										{tag
											{tag bot}
										}
									}
									{include
										{prop
											{prop human}
										}
										{with_item
											{type existance}
											{item "knife"}
										}
										{state
											{state operatable}
										}
									}
									{exclude
										{state
											{state dead}
										}
										{state
											{state inactive}
										}
										{state
											{state user_control}
										}
										{tag
											{tag bot_inf_flank_finished}
										}
										{tag
											{tag bot_inf_flank_in_progress}
										}
										{zone
											{zone "combat"}
										}
									
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
								}
							}
							{count
								{op ">"}
								{value 1}
							}
						}
					}
				}
				{actions
					{"delay"
						{time 0.1}
					}
					{"entity_state"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag _bot}
									}
									{tag
										{tag bot}
									}
								}
								{include
									{prop
										{prop human}
									}
									{with_item
										{type existance}
										{item "knife"}
									}
									{state
										{state operatable}
									}
								}
								{exclude
									{state
										{state dead}
									}
									{state
										{state inactive}
									}
									{state
										{state user_control}
									}
									{tag
										{tag bot_inf_flank_finished}
									}
									{tag
										{tag bot_inf_flank_in_progress}
									}
									{zone
										{zone "combat"}
									}
								
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
							}
						}
						{tag_add bot_inf_flanker}
					}
					{"delay"
						{time 0.1}
					}
					{"entity_state"
						{selector
							{tag bot_inf_flanker}
						}
						{tag_add _lua_mi}
					}
					{"delay"
						{time 0.1}
					}
					{"actor_state"
						{selector
							{tag bot_inf_flanker}
							{type human}
							{state "not dead"}
						}
						{fire_mode return}
						{movement
							{speed fast}
						}
						{human
							{stamina 200}
						}
						{ai
							{no_retreat on}
							{follow_commander off}
						}
					}
					{"delay"
						{time 0.5}
					}
					{"switch"
						{"case"
							{condition
								{type rand}
								{value 0.4}
							}
							{"delay"
								{time 0.1}
							}
							{"actor_to_waypoint"
								{selector
									{tag bot_inf_flanker}
									{type human}
									{state "not dead"}
								}
								{waypoint "1015"}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.4}
							}
							{"delay"
								{time 0.1}
							}
							{"actor_to_waypoint"
								{selector
									{tag bot_inf_flanker}
									{type human}
									{state "not dead"}
								}
								{waypoint "1021"}
							}
						}
						{"default"
							{"delay"
								{time 0.1}
							}
							{"actor_to_waypoint"
								{selector
									{amount 4
									}
									{tag bot_inf_flanker}
									{type human}
									{state "not dead"}
								}
								{waypoint "1015"}
							}
							{"delay"
								{time 0.1}
							}
							{"actor_to_waypoint"
								{selector
									{amount 4
									}
									{tag bot_inf_flanker}
									{type human}
									{state "not dead"}
								}
								{waypoint "1021"}
							}
						}
					}
					{"delay"
						{time 0.1}
					}
					{"entity_state"
						{selector
							{tag bot_inf_flanker}
							{type human}
							{state "not dead"}
						}
						{tag_add bot_inf_flank_in_progress}
					}
					{"delay"
						{time 300}
					}
					{"trigger"
						{name "hf flanking infantry ai/detect and action"}
					}
				}
			}
			
			
;// Melee AI
			{"hf inf ai/melee/melee"
				{condition
					{terms
						{"1.see_actors"
							{selector
								{source advanced}
								{group
									{include
										{prop
											{prop human}
										}
										{tag
											{tag _bot}
										}
										{tag
											{tag bot}
										}
										{with_item
											{type existance}
											{item "sword"}
										}
										{state
											{state operatable}
										}
									}
									{exclude
										{state
											{state dead}
										}
										{state
											{state inactive}
										}
										{state
											{state user_control}
										}
										{tag
											{tag _user}
										}
										{tag
											{tag _user_ally}
										}
									
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
								}
							}
							{enemy
								{source advanced}
								{group
									{include
										{prop
											{prop human}
										}
										{tag
											{tag _user}
										}
										{state
											{state operatable}
										}
									}
									{exclude
										{state
											{state dead}
										}
										{state
											{state inactive}
										}
										{state
											{state user_control}
										}
										{tag
											{tag _bleedout_}
										}
										{tag
											{tag bleeding}
										}
										{tag
											{tag bot}
										}
										{movement_type
											{type swim}
										}
										{movement_type
											{type crawl}
										}
										{movement_type
											{type squat}
										}
									}
								}
							}
							{distance
								{mode near_than}
								{meters 10}
							}
							{detection located}
							{tag
								{"tag pair"}
								{"for selector" ai_close_inf}
								{"for enemy" ai_close_inf_target}
							}
						}
					}
				}
				{actions
					{"delay"
						{time 0.1}
					}
					{"entity_state"
						{selector
							{tag ai_close_inf}
						}
						{tag_add _lua_mi}
					}
					{"inventory"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag ai_close_inf}
									}
								}
								{exclude
									{with_item
										{type using}
										{item "sword"}
									}
								
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
							}
						}
						{action take}
						{item "sword"}
					}
					{"delay"
						{time 0.25}
					}
					{"actor_state"
						{selector
							{tag ai_close_inf}
						}
						{movement
							{speed fast}
							{kind fast}
							{type normal}
						}
						{ai
							{follow_commander off}
						}
					}
					{"delay"
						{time 0.25}
					}
					{"talk"
						{selector
							{tag ai_close_inf}
						}
						{say attack}
						{text ""}
					}
					{"action"
						{selector
							{tag ai_close_inf}
						}
						{drop orders}
						{action advance}
						{target
							{tag ai_close_inf_target}
						}
					}
					{"delay"
						{time 1}
					}
					{"entity_state"
						{selector
							{tag ai_close_inf}
						}
						{tag_remove _lua_mi}
					}
					{"entity_state"
						{selector
							{tag ai_close_inf}
						}
						{tag_remove ai_close_inf}
					}
					{"delay"
						{time 0.1}
					}
					{"entity_state"
						{selector
							{tag ai_close_inf_target}
						}
						{tag_remove ai_close_inf_target}
					}
					{"delay"
						{time 0.75}
					}
					{"trigger"
						{name "hf inf ai/melee/melee"}
					}
				}
			}


;// Obnoxious grenade spam
			{"hf inf ai/grenade ap"
				{condition
					{terms
						{"1.see_actors"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag _bot}
										}
										{tag
											{tag bot}
										}
									}
									{include
										{with_item
											{type amount}
											{item "fg"}
											{min 1}
										}
										{state
											{state operatable}
										}
										{prop
											{prop human}
										}
									}
									{exclude
										{state
											{state dead}
										}
										{state
											{state inactive}
										}
										{state
											{state user_control}
										}
										{state
											{state linked}
										}
										{tag
											{tag _lua_mi}
										}
										{tag
											{tag _ai_do_not_disturb}
										}
										{tag
											{tag wounded}
										}
										{tag
											{tag bleeding}
										}
										{tag
											{tag _bleeding}
										}
										{tag
											{tag wounded_animation_playing}
										}
										{tag
											{tag repairing}
										}
										{tag
											{tag reloading}
										}
									
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
								}
							}
							{enemy
								{source advanced}
								{group
									{select
										{tag
											{tag _user}
										}
									}
									{include
										{prop
											{prop human}
										}
										{state
											{state user_control}
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
											{prop vehicle}
										}
										{state
											{state dead}
										}
										{state
											{state inactive}
										}
										{state
											{state linked}
										}
										{tag
											{tag _bot}
										}
										{tag
											{tag bot}
										}
										{tag
											{tag bleeding}
										}
										{tag
											{tag _bleeding}
										}
										{tag
											{tag _bleedout_}
										}
										{tag
											{tag wounded_animation_playing}
										}
										{tag
											{tag wounded_dead}
										}
										{tag
											{tag wounded}
										}
									}
								}
							}
							{distance
								{mode in_range}
								{min 18}
								{max 26}
							}
							{detection located}
							{tag
								{"tag pair"}
								{"for selector" _ai_ap_grenade}
								{"for enemy" _ai_ap_target}
							}
						}
					}
				}
				{actions
					{"delay"
						{time 0.1}
					}
					{"action"
						{selector
							{tag _ai_ap_grenade}
							{type human}
							{state "not dead"}
						}
						{drop orders}
						{action cancel}
					}
					{"delay"
						{time 0.2}
					}
					{"inventory"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag _ai_ap_grenade}
									}
								}
								{exclude
									{with_item
										{type using}
										{item "fg"}
									}
									{state
										{state dead}
									}
									{state
										{state inactive}
									}
								
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
							}
						}
						{action take}
						{item "fg"}
					}
					{"delay"
						{time 1}
					}
					{"action"
						{selector
							{amount 1
							}
							{tag _ai_ap_grenade}
							{type human}
							{state "not dead"}
						}
						{drop "orders sensor senseless"}
						{action attack_ground}
						{target
							{tag _ai_ap_target}
						}
					}
					{"delay"
						{time 3}
					}
					{"action"
						{selector
							{tag _ai_ap_grenade}
							{type human}
							{state "not dead"}
						}
						{drop orders}
						{action rotate}
						{target
							{tag _ai_ap_target}
						}
					}
					{"delay"
						{time 0.1}
					}
					{"entity_state"
						{selector
							{tag _ai_ap_grenade}
						}
						{tag_remove _ai_ap_grenade}
					}
					{"delay"
						{time 0.25}
					}
					{"entity_state"
						{selector
							{tag _ai_ap_target}
						}
						{tag_remove _ai_ap_target}
					}
					{"delay"
						{time 0.25}
					}
					{"trigger"
						{name "hf inf ai/grenade ap"}
					}
				}
			}
			{"hf inf ai/grenade smoke 120m"
				{condition
					{expression "2 & 3 & 4 & 5 & (1)"}
					{terms
						{"1.see_actors"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag _bot}
										}
										{tag
											{tag bot}
										}
									}
									{include
										{with_item
											{type amount}
											{item "smoke"}
											{min 1}
										}
										{state
											{state operatable}
										}
										{prop
											{prop human}
										}
									}
									{exclude
										{with_item
											{type existance}
											{item "m15_wp" "grenade"}
										}
										{with_item
											{type existance}
											{item "m42_wp" "grenade"}
										}
										{with_item
											{type existance}
											{item "no77_wp" "grenade"}
										}
										{state
											{state dead}
										}
										{state
											{state inactive}
										}
										{state
											{state user_control}
										}
										{state
											{state linked}
										}
										{tag
											{tag _lua_mi}
										}
										{tag
											{tag _ai_do_not_disturb}
										}
										{tag
											{tag wounded}
										}
										{tag
											{tag bleeding}
										}
										{tag
											{tag _bleeding}
										}
										{tag
											{tag wounded_animation_playing}
										}
										{tag
											{tag repairing}
										}
										{tag
											{tag reloading}
										}
									
{tag {tag _ai_ap_grenade}}
{tag {tag _ai_at_grenade}}
{tag {tag _ufb_smoke_120m_actor}}
{tag {tag ai_close_inf}}
{tag {tag _ai_wirecutter_in_action}}
{tag {tag bot_inf_flank_in_progress}}
{tag {tag _lua_ignore}}
{tag {tag bot_arty}}
{tag {tag bot_aa_guard}}
{tag {tag crew}}
{tag {tag _ai_medic}}
{tag {tag bot_medic}}
{tag {tag tcrew}}
{tag {tag ecrew}}
{tag {tag ecrew_a}}
{tag {tag ecrew_b}}
{prop {prop crew}}

{tag {tag _ufb_smoke_120m_actor}}
{tag {tag _ufb_smoke_60m_actor}}
{tag {tag _ufb_smoke_wirecutter_actor}}

{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
								}
							}
							{enemy
								{source advanced}
								{group
									{select
										{tag
											{tag _user}
										}
									}
									{include
										{state
											{state user_control}
										}
									}
									{exclude
										{state
											{state dead}
										}
										{state
											{state inactive}
										}
										{tag
											{tag _bot}
										}
										{tag
											{tag bot}
										}
										{tag
											{tag bleeding}
										}
										{tag
											{tag _bleeding}
										}
										{tag
											{tag _bleedout_}
										}
										{tag
											{tag wounded_animation_playing}
										}
										{tag
											{tag wounded_dead}
										}
										{tag
											{tag wounded}
										}
										{prop
											{prop airborne}
										}

{tag {tag _ufb_smoke_120m_target}}
{tag {tag _ufb_smoke_60m_target}}
{tag {tag _ufb_smoke_wirecutter_target}}
}
								}
							}
							{distance
								{mode in_range}
								{min 65}
								{max 120}
							}
							{detection visible}
							{tag
								{"tag pair"}
								{"for selector" _ufb_smoke_120m_actor}
								{"for enemy" _ufb_smoke_120m_target}
							}
						}
						{"2.cmp_i" {var "attacker_retreat_requested$"} {op "=="} {value 0}}
						{"3.cmp_i" {var "defender_retreat_requested$"} {op "=="} {value 0}}
						{"4.cmp_i" {var "bot_retreat_active$"} {op "=="} {value 0}}
						{"5.cmp_i" {var "winner_decided$"} {op "=="} {value 0}}
					}
				}
				{actions
					{"delay"
						{time 0.1}
					}
					{"switch"
						{"case"
							{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
							{"switch"
								{"case"
									{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
									{"switch"
										{"case"
											{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
											{"switch"
												{"case"
													{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
													{"inventory"
														{selector
															{source advanced}
															{group
																{select
																	{tag
																		{tag _ufb_smoke_120m_actor}
																	}
																}
																{exclude
																	{with_item
																		{type using}
																		{item "smoke"}
																	}
																	{state
																		{state dead}
																	}
																	{state
																		{state inactive}
																	}
																
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
															}
														}
														{action take}
														{item "smoke"}
													}
												}
											}
										}
									}
								}
							}
						}
					}
					{"delay"
						{time 0.5}
					}
					{"switch"
						{"case"
							{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
							{"switch"
								{"case"
									{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
									{"switch"
										{"case"
											{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
											{"switch"
												{"case"
													{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
													{"action"
														{selector
															{amount 1
															}
															{tag _ufb_smoke_120m_actor}
															{type human}
															{state "not dead"}
														}
														{drop orders}
														{action rotate}
														{target
															{ignore_captured_by_user 0}
															{tag _ufb_smoke_120m_target}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
					{"delay"
						{time 1}
					}
					{"switch"
						{"case"
							{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
							{"switch"
								{"case"
									{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
									{"switch"
										{"case"
											{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
											{"switch"
												{"case"
													{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
													; UFB: throw toward a 10 m ground point after facing the distant threat.
													{"effect" {selector
															{amount 1
															}
															{tag _ufb_smoke_120m_actor}
															{type human}
															{state "not dead"}
														} {effect ufb_smoke_screen_120m}}
												}
											}
										}
									}
								}
							}
						}
					}
					{"switch"
						{"case"
							{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
							{"switch"
								{"case"
									{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
									{"switch"
										{"case"
											{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
											{"switch"
												{"case"
													{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
													; UFB: throw toward a 10 m ground point after facing the distant threat.
													{"action"
														{selector
															{amount 1
															}
															{tag _ufb_smoke_120m_actor}
															{type human}
															{state "not dead"}
														}
														{drop orders}
														{action throw_sk_grenade}
														{target
															{ignore_captured_by_user 0}
															{tag _ufb_smoke_120m_screen}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
					{"delay"
						{time 2.5}
					}
					{"switch"
						{"case"
							{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
							{"switch"
								{"case"
									{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
									{"switch"
										{"case"
											{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
											{"switch"
												{"case"
													{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
													{"actor_to_cover"
														{selector
															{tag _ufb_smoke_120m_actor}
														}
														{drop orders}
													}
												}
											}
										}
									}
								}
							}
						}
					}
					{"delay"
						{time 0.1}
					}
					; UFB: keep this threat reserved through the smoke retry interval.

					{"delay"
						{time 0.1}
					}
					{"entity_state"
						{selector
							{tag _ufb_smoke_120m_actor}
						}
						{tag_remove _ufb_smoke_120m_actor}
					}
					{"delay"
						{time 18}
					}
					{"entity_state"
						{selector
							{tag _ufb_smoke_120m_target}
						}
						{tag_remove _ufb_smoke_120m_target}
					}
{"trigger"
						{name "hf inf ai/grenade smoke 120m"}
					}
				}
			}
			{"hf inf ai/grenade smoke 60m"
				{condition
					{expression "2 & 3 & 4 & 5 & (1)"}
					{terms
						{"1.see_actors"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag _bot}
										}
										{tag
											{tag bot}
										}
									}
									{include
										{with_item
											{type amount}
											{item "smoke"}
											{min 1}
										}
										{state
											{state operatable}
										}
										{prop
											{prop human}
										}
									}
									{exclude
										{with_item
											{type existance}
											{item "m15_wp" "grenade"}
										}
										{with_item
											{type existance}
											{item "m42_wp" "grenade"}
										}
										{with_item
											{type existance}
											{item "no77_wp" "grenade"}
										}
										{state
											{state dead}
										}
										{state
											{state inactive}
										}
										{state
											{state user_control}
										}
										{state
											{state linked}
										}
										{tag
											{tag _lua_mi}
										}
										{tag
											{tag _ai_do_not_disturb}
										}
										{tag
											{tag wounded}
										}
										{tag
											{tag bleeding}
										}
										{tag
											{tag _bleeding}
										}
										{tag
											{tag wounded_animation_playing}
										}
										{tag
											{tag repairing}
										}
										{tag
											{tag reloading}
										}
									
{tag {tag _ai_ap_grenade}}
{tag {tag _ai_at_grenade}}
{tag {tag _ufb_smoke_60m_actor}}
{tag {tag ai_close_inf}}
{tag {tag _ai_wirecutter_in_action}}
{tag {tag bot_inf_flank_in_progress}}
{tag {tag _lua_ignore}}
{tag {tag bot_arty}}
{tag {tag bot_aa_guard}}
{tag {tag crew}}
{tag {tag _ai_medic}}
{tag {tag bot_medic}}
{tag {tag tcrew}}
{tag {tag ecrew}}
{tag {tag ecrew_a}}
{tag {tag ecrew_b}}
{prop {prop crew}}

{tag {tag _ufb_smoke_120m_actor}}
{tag {tag _ufb_smoke_60m_actor}}
{tag {tag _ufb_smoke_wirecutter_actor}}

{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
								}
							}
							{enemy
								{source advanced}
								{group
									{select
										{tag
											{tag _user}
										}
									}
									{include
										{state
											{state user_control}
										}
									}
									{exclude
										{state
											{state dead}
										}
										{state
											{state inactive}
										}
										{tag
											{tag _bot}
										}
										{tag
											{tag bot}
										}
										{tag
											{tag bleeding}
										}
										{tag
											{tag _bleeding}
										}
										{tag
											{tag _bleedout_}
										}
										{tag
											{tag wounded_animation_playing}
										}
										{tag
											{tag wounded_dead}
										}
										{tag
											{tag wounded}
										}
										{prop
											{prop airborne}
										}

{tag {tag _ufb_smoke_120m_target}}
{tag {tag _ufb_smoke_60m_target}}
{tag {tag _ufb_smoke_wirecutter_target}}
}
								}
							}
							{distance
								{mode in_range}
								{min 33}
								{max 60}
							}
							{detection visible}
							{tag
								{"tag pair"}
								{"for selector" _ufb_smoke_60m_actor}
								{"for enemy" _ufb_smoke_60m_target}
							}
						}
						{"2.cmp_i" {var "attacker_retreat_requested$"} {op "=="} {value 0}}
						{"3.cmp_i" {var "defender_retreat_requested$"} {op "=="} {value 0}}
						{"4.cmp_i" {var "bot_retreat_active$"} {op "=="} {value 0}}
						{"5.cmp_i" {var "winner_decided$"} {op "=="} {value 0}}
					}
				}
				{actions
					{"delay"
						{time 0.1}
					}
					{"switch"
						{"case"
							{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
							{"switch"
								{"case"
									{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
									{"switch"
										{"case"
											{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
											{"switch"
												{"case"
													{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
													{"inventory"
														{selector
															{source advanced}
															{group
																{select
																	{tag
																		{tag _ufb_smoke_60m_actor}
																	}
																}
																{exclude
																	{with_item
																		{type using}
																		{item "smoke"}
																	}
																	{state
																		{state dead}
																	}
																	{state
																		{state inactive}
																	}
																
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
															}
														}
														{action take}
														{item "smoke"}
													}
												}
											}
										}
									}
								}
							}
						}
					}
					{"delay"
						{time 0.5}
					}
					{"switch"
						{"case"
							{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
							{"switch"
								{"case"
									{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
									{"switch"
										{"case"
											{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
											{"switch"
												{"case"
													{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
													{"action"
														{selector
															{amount 1
															}
															{tag _ufb_smoke_60m_actor}
															{type human}
															{state "not dead"}
														}
														{drop orders}
														{action rotate}
														{target
															{ignore_captured_by_user 0}
															{tag _ufb_smoke_60m_target}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
					{"delay"
						{time 1}
					}
					{"switch"
						{"case"
							{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
							{"switch"
								{"case"
									{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
									{"switch"
										{"case"
											{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
											{"switch"
												{"case"
													{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
													; UFB: throw toward a 10 m ground point after facing the distant threat.
													{"effect" {selector
															{amount 1
															}
															{tag _ufb_smoke_60m_actor}
															{type human}
															{state "not dead"}
														} {effect ufb_smoke_screen_60m}}
												}
											}
										}
									}
								}
							}
						}
					}
					{"switch"
						{"case"
							{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
							{"switch"
								{"case"
									{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
									{"switch"
										{"case"
											{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
											{"switch"
												{"case"
													{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
													; UFB: throw toward a 10 m ground point after facing the distant threat.
													{"action"
														{selector
															{amount 1
															}
															{tag _ufb_smoke_60m_actor}
															{type human}
															{state "not dead"}
														}
														{drop orders}
														{action throw_sk_grenade}
														{target
															{ignore_captured_by_user 0}
															{tag _ufb_smoke_60m_screen}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
					{"delay"
						{time 2.5}
					}
					{"switch"
						{"case"
							{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
							{"switch"
								{"case"
									{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
									{"switch"
										{"case"
											{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
											{"switch"
												{"case"
													{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
													{"actor_to_cover"
														{selector
															{tag _ufb_smoke_60m_actor}
														}
														{drop orders}
													}
												}
											}
										}
									}
								}
							}
						}
					}
					{"delay"
						{time 0.1}
					}
					; UFB: keep this threat reserved through the smoke retry interval.

					{"delay"
						{time 0.1}
					}
					{"entity_state"
						{selector
							{tag _ufb_smoke_60m_actor}
						}
						{tag_remove _ufb_smoke_60m_actor}
					}
					{"delay"
						{time 18}
					}
					{"entity_state"
						{selector
							{tag _ufb_smoke_60m_target}
						}
						{tag_remove _ufb_smoke_60m_target}
					}
{"trigger"
						{name "hf inf ai/grenade smoke 60m"}
					}
				}
			}
			{"hf inf ai/near player"
				{condition
					{terms
						{"1.see_actors"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag _bot}
										}
										{tag
											{tag bot}
										}
									}
									{include
										{state
											{state operatable}
										}
										{prop
											{prop human}
										}
									}
									{exclude
										{state
											{state dead}
										}
										{state
											{state inactive}
										}
										{state
											{state user_control}
										}
										{state
											{state linked}
										}
										{tag
											{tag _lua_mi}
										}
										{tag
											{tag _ai_do_not_disturb}
										}
										{tag
											{tag wounded}
										}
										{tag
											{tag bleeding}
										}
										{tag
											{tag _bleeding}
										}
										{tag
											{tag wounded_animation_playing}
										}
										{tag
											{tag repairing}
										}
										{tag
											{tag reloading}
										}
										{with_item
											{type existance}
											{item "sword"}
										}
										{tag
											{tag _ai_near_player_cooldown}
										}
										{tag
											{tag _ai_ap_grenade}
										}
										{tag
											{tag _ai_at_grenade}
										}
									
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
								}
							}
							{enemy
								{source advanced}
								{group
									{select
										{tag
											{tag _user}
										}
									}
									{include
										{state
											{state user_control}
										}
										{state
											{state operatable}
										}
									}
									{exclude
										{state
											{state dead}
										}
										{state
											{state inactive}
										}
										{state
											{state linked}
										}
										{tag
											{tag _bot}
										}
										{tag
											{tag bot}
										}
										{tag
											{tag bleeding}
										}
										{tag
											{tag _bleeding}
										}
										{tag
											{tag _bleedout_}
										}
										{tag
											{tag wounded_animation_playing}
										}
										{tag
											{tag wounded_dead}
										}
										{tag
											{tag wounded}
										}
										{prop
											{prop airborne}
										}
									}
								}
							}
							{distance
								{mode near_than}
								{meters 13}
							}
							{detection visible}
							{tag
								{"tag pair"}
								{"for selector" _ai_near_player}
							}
						}
					}
				}
				{actions
					{"delay"
						{time 0.1}
					}
					{"actor_state"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag _ai_near_player}
									}
								}
								{include
									{state
										{state operatable}
									}
								}
								{exclude
									{state
										{state dead}
									}
									{state
										{state inactive}
									}
									{state
										{state user_control}
									}
									{tag
										{tag _lua_mi}
									}
									{tag
										{tag _ai_do_not_disturb}
									}
									{tag
										{tag wounded}
									}
									{tag
										{tag bleeding}
									}
									{tag
										{tag _bleeding}
									}
									{tag
										{tag wounded_animation_playing}
									}
									{tag
										{tag repairing}
									}
									{tag
										{tag reloading}
									}
									{with_item
										{type existance}
										{item "sword"}
									}
								
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
							}
						}
						{drop orders}
						{fire_mode open}
					}
					{"delay"
						{time 0.1}
					}
					{"effect"
						{selector
							{tag _ai_near_player}
						}
						{effect ai_near_player_cooldown}
					}
					{"delay"
						{time 0.1}
					}
					{"entity_state"
						{selector
							{tag _ai_near_player}
						}
						{tag_remove _ai_near_player}
					}
					{"delay"
						{time 1}
					}
					{"trigger"
						{name "hf inf ai/near player"}
					}
				}
			}
			{"hf inf ai/antitank/grenade at"
				{condition
					{terms
						{"1.see_actors"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag _bot}
										}
										{tag
											{tag bot}
										}
									}
									{include
										{with_item
											{type amount}
											{item "at"}
											{min 1}
										}
										{state
											{state operatable}
										}
										{prop
											{prop human}
										}
									}
									{exclude
										{state
											{state dead}
										}
										{state
											{state inactive}
										}
										{state
											{state user_control}
										}
										{state
											{state linked}
										}
										{tag
											{tag _lua_mi}
										}
										{tag
											{tag _ai_do_not_disturb}
										}										
										{tag
											{tag wounded}
										}
										{tag
											{tag bleeding}
										}
										{tag
											{tag _bleeding}
										}
										{tag
											{tag wounded_animation_playing}
										}
										{tag
											{tag repairing}
										}
										{tag
											{tag reloading}
										}
									
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
								}
							}
							{enemy
								{source advanced}
								{group
									{select
										{tag
											{tag _user}
										}
									}
									{include
										{state
											{state operatable}
										}
									}
									{exclude
										{prop
											{prop human}
										}
										{state
											{state dead}
										}
										{state
											{state inactive}
										}
										{tag
											{tag _bot}
										}
										{tag
											{tag bot}
										}
										{prop
											{prop creature}
										}
									}
								}
							}
							{distance
								{mode near_than}
								{meters 25}
							}
							{detection visible}
							{tag
								{"tag pair"}
								{"for selector" _ai_at_grenade}
								{"for enemy" _ai_at_target}
							}
						}
					}
				}
				{actions
					{"delay"
						{time 0.1}
					}
					{"action"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag _ai_at_grenade}
									}
								}
								{exclude
									{tag
										{tag _ai_at_launcher_30}
									}
									{tag
										{tag _ai_at_launcher_40}
									}
									{tag
										{tag _ai_at_launcher_50}
									}
									{tag
										{tag _ai_at_launcher_70}
									}
									{state
										{state dead}
									}
									{state
										{state inactive}
									}
								
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
							}
						}
						{drop orders}
						{action cancel}
					}
					{"delay"
						{time 0.2}
					}
					{"action"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag _ai_at_grenade}
									}
								}
								{exclude
									{tag
										{tag _ai_at_launcher_30}
									}
									{tag
										{tag _ai_at_launcher_40}
									}
									{tag
										{tag _ai_at_launcher_50}
									}
									{tag
										{tag _ai_at_launcher_70}
									}
									{with_item
										{type using}
										{item "rocketlauncher"}
									}
									{state
										{state dead}
									}
									{state
										{state inactive}
									}
								
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
							}
						}
						{drop "orders sensor senseless"}
						{action attack}
						{target
							{tag _ai_at_target}
						}
						{volume body1}
					}
					{"delay"
						{time 3}
					}
					{"entity_state"
						{selector
							{tag _ai_at_grenade}
						}
						{tag_remove _ai_at_grenade}
					}
					{"delay"
						{time 0.1}
					}
					{"entity_state"
						{selector
							{tag _ai_at_target}
						}
						{tag_remove _ai_at_target}
					}
					{"delay"
						{time 1.5}
					}
					{"trigger"
						{name "hf inf ai/antitank/grenade at"}
					}
				}
			}

(define "hf_rocketlauncher"			
			{"hf inf ai/antitank/rocketlauncher %meters"
				{condition
					{terms
						{"1.see_actors"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag _bot}
										}
										{tag
											{tag bot}
										}
									}
									{include
										{with_item
											{type amount}
											{item "range_%meters"}
											{min 1}
										}
										{state
											{state operatable}
										}
										{prop
											{prop human}
										}
									}
									{exclude
										{state
											{state dead}
										}
										{state
											{state inactive}
										}
										{state
											{state user_control}
										}
										{state
											{state linked}
										}
										{tag
											{tag _lua_mi}
										}
										{tag
											{tag _ai_do_not_disturb}
										}										
										{tag
											{tag wounded}
										}
										{tag
											{tag bleeding}
										}
										{tag
											{tag _bleeding}
										}
										{tag
											{tag wounded_animation_playing}
										}
										{tag
											{tag repairing}
										}
										{tag
											{tag reloading}
										}
									
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
								}
							}
							{enemy
								{source advanced}
								{group
									{select
										{tag
											{tag _user}
										}
									}
									{include
										{state
											{state operatable}
										}
									}
									{exclude
										{prop
											{prop human}
										}
										{state
											{state dead}
										}
										{state
											{state inactive}
										}
										{tag
											{tag _bot}
										}
										{tag
											{tag bot}
										}
										{prop
											{prop creature}
										}
									}
								}
							}
							{distance
								{mode in_range}
								{min %r1}
								{max %meters}
							}
							{detection visible}
							{tag
								{"tag pair"}
								{"for selector" _ai_at_launcher_%meters}
								{"for enemy" _ai_at_launcher_target_%meters}
							}
						}
					}
				}
				{actions
					{"delay"
						{time 0.1}
					}
					; UFB: recheck native AT range before drawing or issuing an attack.
{"if" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {group {select {tag {tag _ai_at_launcher_%meters}}} {include {prop {prop human}} {state {state operatable}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {state {state user_control}} {tag {tag _ufb_job_reserved}} {tag {tag _ufb_combat_busy}} {tag {tag _ufb_healing_active}} {tag {tag medic}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group {select {tag {tag _ai_at_launcher_target_%meters}}} {include {state {state operatable}}} {exclude {state {state dead}} {state {state inactive}}}}} {distance {mode in_range} {min 0} {max %meters}} {detection visible}}
{"inventory"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag _ai_at_launcher_%meters}
									}
								}
								{exclude
									{with_item
										{type using}
										{item "range_%meters"}
									}
									{state
										{state dead}
									}
									{state
										{state inactive}
									}
								
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
							}
						}
						{action take}
						{item "range_%meters"}
					}
}
					{"delay"
						{time 1.25}
					}
					; UFB: recheck native AT range before drawing or issuing an attack.
{"if" {condition {type see_actors} {selector {source advanced} {ignore_captured_by_user 1} {group {select {tag {tag _ai_at_launcher_%meters}}} {include {prop {prop human}} {state {state operatable}}} {exclude {state {state dead}} {state {state inactive}} {state {state linked}} {state {state user_control}} {tag {tag _ufb_job_reserved}} {tag {tag _ufb_combat_busy}} {tag {tag _ufb_healing_active}} {tag {tag medic}}}}} {enemy {source advanced} {ignore_captured_by_user 0} {group {select {tag {tag _ai_at_launcher_target_%meters}}} {include {state {state operatable}}} {exclude {state {state dead}} {state {state inactive}}}}} {distance {mode in_range} {min 0} {max %meters}} {detection visible}}
{"action"
						{selector
							{amount 1
							}
							{tag _ai_at_launcher_%meters}
							{type human}
							{state "not dead"}
						}
						{drop "orders sensor senseless"}
						{action attack}
						{target
							{tag _ai_at_launcher_target_%meters}
						}
						{volume body1}
					}
}
					{"delay"
						{time 1.5}
					}
					{"entity_state"
						{selector
							{tag _ai_at_launcher_%meters}
						}
						{tag_remove _ai_at_launcher_%meters}
					}
					{"delay"
						{time 0.1}
					}
					{"entity_state"
						{selector
							{tag _ai_at_launcher_target_%meters}
						}
						{tag_remove _ai_at_launcher_target_%meters}
					}
					{"delay"
						{time 1.5}
					}
					{"trigger"
						{name "hf inf ai/antitank/rocketlauncher %meters"}
					}
				}
			}
)
("hf_rocketlauncher" r1(16) r2(50) meters(30))
("hf_rocketlauncher" r1(16) r2(60) meters(40))
("hf_rocketlauncher" r1(16) r2(70) meters(50))
("hf_rocketlauncher" r1(16) r2(80) meters(60))
("hf_rocketlauncher" r1(16) r2(90) meters(70))
("hf_rocketlauncher" r1(16) r2(100) meters(80))
("hf_rocketlauncher" r1(16) r2(110) meters(90))

			{"hf inf ai/under mg fire"
				{condition
					{expression "2 & 3 & 4 & 5 & (1)"}
					{terms
						{"1.see_actors"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag _bot}
										}
										{tag
											{tag bot}
										}
									}
									{include
										{state
											{state operatable}
										}
										{prop
											{prop human}
										}
									}
									{exclude
										{state
											{state dead}
										}
										{state
											{state inactive}
										}
										{state
											{state user_control}
										}
										{tag
											{tag _lua_mi}
										}
										{tag
											{tag _ai_do_not_disturb}
										}										
										{tag
											{tag wounded}
										}
										{tag
											{tag bleeding}
										}
										{tag
											{tag _bleeding}
										}
										{tag
											{tag wounded_animation_playing}
										}
										{tag
											{tag repairing}
										}
										{tag
											{tag reloading}
										}
									
{tag {tag crew}}
{tag {tag _ai_medic}}
{tag {tag bot_medic}}
{tag {tag tcrew}}
{tag {tag ecrew}}
{tag {tag ecrew_a}}
{tag {tag ecrew_b}}
{tag {tag _ufb_crew_safe}}
{tag {tag _ai_ap_grenade}}
{tag {tag _ai_at_grenade}}
{tag {tag _ufb_smoke_120m_actor}}
{tag {tag _ufb_smoke_60m_actor}}
{tag {tag _ufb_smoke_wirecutter_actor}}
{tag {tag _ai_at_launcher_30}}
{tag {tag _ai_at_launcher_40}}
{tag {tag _ai_at_launcher_50}}
{tag {tag _ai_at_launcher_60}}
{tag {tag _ai_at_launcher_70}}
{tag {tag _ai_at_launcher_90}}
{prop {prop crew}}
{state {state linked}}
{tag {tag _ufb_hf_cover_active}}

{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
								}
							}
							{enemy
								{source advanced}
								{group
									{select
										{tag
											{tag _user}
										}
									}
									{include
										{with_item
											{type using}
											{item "mgun"}
										}
										{state
											{state user_control}
										}
										{state
											{state operatable}
										}
									
 {prop {prop shooting}}
}
									{exclude
										{state
											{state dead}
										}
										{state
											{state inactive}
										}
										{tag
											{tag _bot}
										}
										{tag
											{tag bot}
										}
										{tag
											{tag bleeding}
										}
										{tag
											{tag _bleeding}
										}
										{tag
											{tag _bleedout_}
										}
										{tag
											{tag wounded_animation_playing}
										}
										{tag
											{tag wounded_dead}
										}
										{tag
											{tag wounded}
										}
										{prop
											{prop airborne}
										}
									}
								}
							}
							{distance
								{mode in_range}
								{min 40}
								{max 120}
							}
							{detection visible}
							{tag
								{"tag pair"}
								{"for selector" _ai_suppressed_by_mg}
								{"for enemy" _ai_mg_target}
							}
						}
						{"2.cmp_i" {var "attacker_retreat_requested$"} {op "=="} {value 0}}
						{"3.cmp_i" {var "defender_retreat_requested$"} {op "=="} {value 0}}
						{"4.cmp_i" {var "bot_retreat_active$"} {op "=="} {value 0}}
						{"5.cmp_i" {var "winner_decided$"} {op "=="} {value 0}}
					}
				}
				{actions
					{"delay"
						{time 0.25}
					}
					{"switch"
						{"case"
							{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
							{"switch"
								{"case"
									{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
									{"switch"
										{"case"
											{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
											{"switch"
												{"case"
													{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
													{"actor_to_cover"
														{selector
															{source advanced}
															{group
																{select
																	{tag
																		{tag _ai_suppressed_by_mg}
																	}
																}
																{exclude
																	{tag
																		{tag reloading}
																	}
																	{tag
																		{tag _ai_ap_grenade}
																	}
																	{tag
																		{tag _ai_at_grenade}
																	}
																
{tag {tag _ufb_smoke_120m_actor}}
{tag {tag _ufb_smoke_60m_actor}}
{tag {tag _ufb_smoke_wirecutter_actor}}

{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
															}
														}
														{drop orders}
													}
												}
											}
										}
									}
								}
							}
						}
					}
					{"switch"
						{"case"
							{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
							{"switch"
								{"case"
									{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
									{"switch"
										{"case"
											{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
											{"switch"
												{"case"
													{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
													{"effect" {selector
															{source advanced}
															{group
																{select
																	{tag
																		{tag _ai_suppressed_by_mg}
																	}
																}
																{exclude
																	{tag
																		{tag reloading}
																	}
																	{tag
																		{tag _ai_ap_grenade}
																	}
																	{tag
																		{tag _ai_at_grenade}
																	}
																
{tag {tag _ufb_smoke_120m_actor}}
{tag {tag _ufb_smoke_60m_actor}}
{tag {tag _ufb_smoke_wirecutter_actor}}

{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
															}
														} {effect ufb_hf_cover_committed}}
												}
											}
										}
									}
								}
							}
						}
					}
					{"delay"
						{time 1}
					}
					{"entity_state"
						{selector
							{tag _ai_suppressed_by_mg}
						}
						{tag_remove _ai_suppressed_by_mg}
					}
					{"delay"
						{time 5}
					}
					{"entity_state" {selector {tag _ai_mg_target}} {tag_remove _ai_mg_target}}
{"trigger"
						{name "hf inf ai/under mg fire"}
					}
				}
			}
			{"hf inf ai/ai mgunner"
				{condition
					{expression "2 & 3 & 4 & 5 & (1)"}
					{terms
						{"1.see_actors"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag _bot}
										}
										{tag
											{tag bot}
										}
									}
									{include
										{with_item
											{type using}
											{item "mgun"}
										}
										{state
											{state operatable}
										}
										{prop
											{prop human}
										}
									}
									{exclude
										{state
											{state dead}
										}
										{state
											{state inactive}
										}
										{state
											{state user_control}
										}
										{tag
											{tag _lua_mi}
										}
										{tag
											{tag _ai_do_not_disturb}
										}										
										{tag
											{tag wounded}
										}
										{tag
											{tag bleeding}
										}
										{tag
											{tag _bleeding}
										}
										{tag
											{tag wounded_animation_playing}
										}
										{tag
											{tag repairing}
										}
										{tag
											{tag reloading}
										}
									
{tag {tag crew}}
{tag {tag _ai_medic}}
{tag {tag bot_medic}}
{tag {tag tcrew}}
{tag {tag ecrew}}
{tag {tag ecrew_a}}
{tag {tag ecrew_b}}
{tag {tag _ufb_crew_safe}}
{tag {tag _ai_ap_grenade}}
{tag {tag _ai_at_grenade}}
{tag {tag _ufb_smoke_120m_actor}}
{tag {tag _ufb_smoke_60m_actor}}
{tag {tag _ufb_smoke_wirecutter_actor}}
{tag {tag _ai_at_launcher_30}}
{tag {tag _ai_at_launcher_40}}
{tag {tag _ai_at_launcher_50}}
{tag {tag _ai_at_launcher_60}}
{tag {tag _ai_at_launcher_70}}
{tag {tag _ai_at_launcher_90}}
{prop {prop crew}}
{state {state linked}}
{tag {tag _ufb_hf_cover_active}}

{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
								}
							}
							{enemy
								{source advanced}
								{group
									{select
										{tag
											{tag _user}
										}
									}
									{include
										{state
											{state user_control}
										}
										{state
											{state operatable}
										}
									}
									{exclude
										{state
											{state dead}
										}
										{state
											{state inactive}
										}
										{tag
											{tag _bot}
										}
										{tag
											{tag bot}
										}
										{tag
											{tag bleeding}
										}
										{tag
											{tag _bleeding}
										}
										{tag
											{tag _bleedout_}
										}
										{tag
											{tag wounded_animation_playing}
										}
										{tag
											{tag wounded_dead}
										}
										{tag
											{tag wounded}
										}
										{prop
											{prop airborne}
										}
									}
								}
							}
							{distance
								{mode in_range}
								{min 30}
								{max 120}
							}
							{detection visible}
							{tag
								{"tag pair"}
								{"for selector" _ai_mgunner}
							}
						}
						{"2.cmp_i" {var "attacker_retreat_requested$"} {op "=="} {value 0}}
						{"3.cmp_i" {var "defender_retreat_requested$"} {op "=="} {value 0}}
						{"4.cmp_i" {var "bot_retreat_active$"} {op "=="} {value 0}}
						{"5.cmp_i" {var "winner_decided$"} {op "=="} {value 0}}
					}
				}
				{actions
					{"delay"
						{time 0.5}
					}
					{"switch"
						{"case"
							{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
							{"switch"
								{"case"
									{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
									{"switch"
										{"case"
											{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
											{"switch"
												{"case"
													{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
													{"actor_to_cover"
														{selector
															{source advanced}
															{group
																{select
																	{tag
																		{tag _ai_mgunner}
																	}
																}
																{exclude
																	{tag
																		{tag reloading}
																	}
																	{tag
																		{tag _ai_ap_grenade}
																	}
																	{tag
																		{tag _ai_at_grenade}
																	}
																
{tag {tag _ufb_smoke_120m_actor}}
{tag {tag _ufb_smoke_60m_actor}}
{tag {tag _ufb_smoke_wirecutter_actor}}

{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
															}
														}
														{drop orders}
													}
												}
											}
										}
									}
								}
							}
						}
					}
					{"switch"
						{"case"
							{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
							{"switch"
								{"case"
									{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
									{"switch"
										{"case"
											{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
											{"switch"
												{"case"
													{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
													{"effect" {selector
															{source advanced}
															{group
																{select
																	{tag
																		{tag _ai_mgunner}
																	}
																}
																{exclude
																	{tag
																		{tag reloading}
																	}
																	{tag
																		{tag _ai_ap_grenade}
																	}
																	{tag
																		{tag _ai_at_grenade}
																	}
																
{tag {tag _ufb_smoke_120m_actor}}
{tag {tag _ufb_smoke_60m_actor}}
{tag {tag _ufb_smoke_wirecutter_actor}}

{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
															}
														} {effect ufb_hf_cover_committed}}
												}
											}
										}
									}
								}
							}
						}
					}
					{"delay"
						{time 0.5}
					}
					{"entity_state"
						{selector
							{tag _ai_mgunner}
						}
						{tag_remove _ai_mgunner}
					}
					{"delay"
						{time 5}
					}
					{"trigger"
						{name "hf inf ai/ai mgunner"}
					}
				}
			}
			{"hf inf ai/ai reloads"
				{condition
					{expression "2 & 3 & 4 & 5 & (1)"}
					{terms
						{"1.see_actors"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag _bot}
										}
										{tag
											{tag bot}
										}
									}
									{include
										{tag
											{tag reloading}
										}
										{state
											{state operatable}
										}
										{prop
											{prop human}
										}
									}
									{exclude
										{state
											{state dead}
										}
										{state
											{state inactive}
										}
										{state
											{state user_control}
										}
										{tag
											{tag _lua_mi}
										}
										{tag
											{tag _ai_do_not_disturb}
										}										
										{tag
											{tag wounded}
										}
										{tag
											{tag bleeding}
										}
										{tag
											{tag _bleeding}
										}
										{tag
											{tag wounded_animation_playing}
										}
										{tag
											{tag repairing}
										}
										{tag
											{tag _ai_ap_grenade}
										}
									
{tag {tag _ufb_smoke_120m_actor}}
{tag {tag _ufb_smoke_60m_actor}}
{tag {tag _ufb_smoke_wirecutter_actor}}
{tag {tag _ufb_hf_cover_active}}

{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
								}
							}
							{enemy
								{source advanced}
								{group
									{select
										{tag
											{tag _user}
										}
									}
									{include
										{state
											{state user_control}
										}
									}
									{exclude
										{state
											{state dead}
										}
										{state
											{state inactive}
										}
										{tag
											{tag _bot}
										}
										{tag
											{tag bot}
										}
										{tag
											{tag bleeding}
										}
										{tag
											{tag _bleeding}
										}
										{tag
											{tag _bleedout_}
										}
										{tag
											{tag wounded_animation_playing}
										}
										{tag
											{tag wounded_dead}
										}
										{tag
											{tag wounded}
										}
										{prop
											{prop airborne}
										}
									}
								}
							}
							{distance
								{mode in_range}
								{min 24}
								{max 80}
							}
							{detection visible}
							{tag
								{"tag pair"}
								{"for selector" _ai_reloading}
							}
						}
						{"2.cmp_i" {var "attacker_retreat_requested$"} {op "=="} {value 0}}
						{"3.cmp_i" {var "defender_retreat_requested$"} {op "=="} {value 0}}
						{"4.cmp_i" {var "bot_retreat_active$"} {op "=="} {value 0}}
						{"5.cmp_i" {var "winner_decided$"} {op "=="} {value 0}}
					}
				}
				{actions
					{"delay"
						{time 3}
					}
					{"switch"
						{"case"
							{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
							{"switch"
								{"case"
									{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
									{"switch"
										{"case"
											{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
											{"switch"
												{"case"
													{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
													{"actor_to_cover"
														{selector
															{tag _ai_reloading}
														}
														{drop orders}
													}
												}
											}
										}
									}
								}
							}
						}
					}
					{"switch"
						{"case"
							{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
							{"switch"
								{"case"
									{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
									{"switch"
										{"case"
											{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
											{"switch"
												{"case"
													{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
													{"effect" {selector
															{tag _ai_reloading}
														} {effect ufb_hf_cover_committed}}
												}
											}
										}
									}
								}
							}
						}
					}
					{"delay"
						{time 1}
					}
					{"entity_state"
						{selector
							{tag _ai_reloading}
						}
						{tag_remove _ai_reloading}
					}
					{"delay"
						{time 3}
					}
					{"trigger"
						{name "hf inf ai/ai reloads"}
					}
				}
			}

;// Pilots
			{"hf inf ai/pilot bailed out"
				{condition
					{terms
						{"1.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag pilot}
										}
									}
									{include
										{state
											{state operatable}
										}
										{prop
											{prop human}
										}
									}
									{exclude
										{state
											{state dead}
										}
										{state
											{state inactive}
										}
										{state
											{state user_control}
										}
										{state
											{state linked}
										}
										{tag
											{tag _ai_pilot_surrender}
										}
										{tag
											{tag _ai_pilot_escaping}
										}
										{tag
											{tag _ai_pilot_surrendered}
										}
									
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
								}
							}
						}
					}
				}
				{actions
					{"delay"
						{time 0.1}
					}
					{"actor_state"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag pilot}
									}
								}
								{include
									{prop
										{prop human}
									}
									{state
										{state operatable}
									}
								}
								{exclude
									{state
										{state dead}
									}
									{state
										{state inactive}
									}
									{state
										{state linked}
									}
									{state
										{state user_control}
									}
								
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
							}
						}
						{drop orders}
						{fire_mode return}
						{move_mode hold}
						{ai_move
							{mode disable}
							{enable_on "injure enemy"}
						}
						{movement
							{speed fast}
						}
						{ai
							{retreat_ratio 2}
						}
					}
					{"delay"
						{time 3}
					}
					{"switch"
						{"case"
							{condition
								{type rand}
								{value 0.15}
							}
							{"delay"
								{time 0.1}
							}
							{"actor_to_waypoint"
								{selector
									{source advanced}
									{group
										{select
											{tag
												{tag pilot}
											}
										}
										{exclude
											{state
												{state dead}
											}
											{state
												{state inactive}
											}
											{state
												{state user_control}
											}
											{tag
												{tag _ai_pilot_surrender}
											}
											{tag
												{tag _ai_pilot_escaping}
											}
											{tag
												{tag _ai_pilot_surrendered}
											}
										
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
									}
								}
								{waypoint "1027"}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.15}
							}
							{"delay"
								{time 0.1}
							}
							{"actor_to_waypoint"
								{selector
									{source advanced}
									{group
										{select
											{tag
												{tag pilot}
											}
										}
										{exclude
											{state
												{state dead}
											}
											{state
												{state inactive}
											}
											{state
												{state user_control}
											}
											{tag
												{tag _ai_pilot_surrender}
											}
											{tag
												{tag _ai_pilot_escaping}
											}
											{tag
												{tag _ai_pilot_surrendered}
											}
										
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
									}
								}
								{waypoint "1028"}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.15}
							}
							{"delay"
								{time 0.1}
							}
							{"actor_to_waypoint"
								{selector
									{source advanced}
									{group
										{select
											{tag
												{tag pilot}
											}
										}
										{exclude
											{state
												{state dead}
											}
											{state
												{state inactive}
											}
											{state
												{state user_control}
											}
											{tag
												{tag _ai_pilot_surrender}
											}
											{tag
												{tag _ai_pilot_escaping}
											}
											{tag
												{tag _ai_pilot_surrendered}
											}
										
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
									}
								}
								{waypoint "1029"}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.15}
							}
							{"delay"
								{time 0.1}
							}
							{"actor_to_waypoint"
								{selector
									{source advanced}
									{group
										{select
											{tag
												{tag pilot}
											}
										}
										{exclude
											{state
												{state dead}
											}
											{state
												{state inactive}
											}
											{state
												{state user_control}
											}
											{tag
												{tag _ai_pilot_surrender}
											}
											{tag
												{tag _ai_pilot_escaping}
											}
											{tag
												{tag _ai_pilot_surrendered}
											}
										
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
									}
								}
								{waypoint "1030"}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.15}
							}
							{"delay"
								{time 0.1}
							}
							{"actor_to_waypoint"
								{selector
									{source advanced}
									{group
										{select
											{tag
												{tag pilot}
											}
										}
										{exclude
											{state
												{state dead}
											}
											{state
												{state inactive}
											}
											{state
												{state user_control}
											}
											{tag
												{tag _ai_pilot_surrender}
											}
											{tag
												{tag _ai_pilot_escaping}
											}
											{tag
												{tag _ai_pilot_surrendered}
											}
										
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
									}
								}
								{waypoint "1031"}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.15}
							}
							{"delay"
								{time 0.1}
							}
							{"actor_to_waypoint"
								{selector
									{source advanced}
									{group
										{select
											{tag
												{tag pilot}
											}
										}
										{exclude
											{state
												{state dead}
											}
											{state
												{state inactive}
											}
											{state
												{state user_control}
											}
											{tag
												{tag _ai_pilot_surrender}
											}
											{tag
												{tag _ai_pilot_escaping}
											}
											{tag
												{tag _ai_pilot_surrendered}
											}
										
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
									}
								}
								{waypoint "1032"}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.15}
							}
							{"delay"
								{time 0.1}
							}
							{"actor_to_waypoint"
								{selector
									{source advanced}
									{group
										{select
											{tag
												{tag pilot}
											}
										}
										{exclude
											{state
												{state dead}
											}
											{state
												{state inactive}
											}
											{state
												{state user_control}
											}
											{tag
												{tag _ai_pilot_surrender}
											}
											{tag
												{tag _ai_pilot_escaping}
											}
											{tag
												{tag _ai_pilot_surrendered}
											}
										
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
									}
								}
								{waypoint "1033"}
							}
						}
						{"default"
							{"delay"
								{time 0.1}
							}
							{"actor_to_waypoint"
								{selector
									{source advanced}
									{group
										{select
											{tag
												{tag pilot}
											}
										}
										{exclude
											{state
												{state dead}
											}
											{state
												{state inactive}
											}
											{state
												{state user_control}
											}
											{tag
												{tag _ai_pilot_surrender}
											}
											{tag
												{tag _ai_pilot_escaping}
											}
											{tag
												{tag _ai_pilot_surrendered}
											}
										
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
									}
								}
								{waypoint "1033"}
							}
						}
					}
					{"delay"
						{time 0.5}
					}
					{"entity_state"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag pilot}
									}
								}
								{include
									{state
										{state operatable}
									}
								}
								{exclude
									{state
										{state dead}
									}
									{state
										{state inactive}
									}
									{state
										{state user_control}
									}
									{tag
										{tag _ai_pilot_surrender}
									}
									{tag
										{tag _ai_pilot_surrendered}
									}
								
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
							}
						}
						{tag_add _ai_pilot_escaping}
					}
					{"delay"
						{time 10}
					}
					{"trigger"
						{name "hf inf ai/pilot bailed out"}
					}
				}
			}
			{"hf inf ai/pilot surrender"
				{condition
					{terms
						{"1.see_actors"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag _ai_pilot_escaping}
										}
									}
									{include
										{state
											{state operatable}
										}
										{prop
											{prop human}
										}
									}
									{exclude
										{state
											{state dead}
										}
										{state
											{state inactive}
										}
										{state
											{state linked}
										}
										{state
											{state user_control}
										}
										{tag
											{tag _ai_pilot_surrendered}
										}
										{tag
											{tag _ai_pilot_surrender}
										}
									
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
								}
							}
							{enemy
								{source advanced}
								{group
									{select
										{tag
											{tag _user}
										}
									}
									{include
										{state
											{state operatable}
										}
									}
									{exclude
										{state
											{state dead}
										}
										{state
											{state inactive}
										}
										{state
											{state linked}
										}
										{prop
											{prop cannon}
										}
									}
								}
							}
							{distance
								{mode near_than}
								{meters 90}
							}
							{detection visible}
							{tag
								{"tag pair"}
								{"for selector" _ai_pilot_surrender}
							}
						}
					}
				}
				{actions
					{"delay"
						{time 0.1}
					}
					{"entity_state"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag _ai_pilot_surrender}
									}
								}
							
{exclude {tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}}
}
						}
						{tag_remove _ai_pilot_escaping}
					}
					{"delay"
						{time 1}
					}
					{"actor_state"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag _ai_pilot_surrender}
									}
								}
								{include
									{state
										{state operatable}
									}
								}
								{exclude
									{state
										{state dead}
									}
									{state
										{state inactive}
									}
									{state
										{state user_control}
									}
								
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
							}
						}
						{drop orders}
						{fire_mode hold}
						{move_mode hold}
						{ai_move
							{mode disable}
						}
						{movement
							{speed slow}
							{type normal}
						}
					}
					{"delay"
						{time 0.25}
					}
					{"player"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag _ai_pilot_surrender}
									}
								}
								{include
									{state
										{state operatable}
									}
								}
								{exclude
									{state
										{state dead}
									}
									{state
										{state inactive}
									}
									{state
										{state user_control}
									}
									{state
										{state linked}
									}
								
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
							}
						}
						{operation set}
						{player "0"}
					}
					{"delay"
						{time 0.25}
					}
					{"inventory"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag _ai_pilot_surrender}
									}
								}
							
{exclude {tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}}
}
						}
						{action drop}
					}
					{"delay"
						{time 2}
					}
					{"actor_state"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag _ai_pilot_surrender}
									}
								}
								{include
									{state
										{state operatable}
									}
								}
								{exclude
									{state
										{state dead}
									}
									{state
										{state inactive}
									}
									{state
										{state user_control}
									}
								
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
							}
						}
						{fire_mode hold}
						{move_mode hold}
						{ai_move
							{mode disable}
						}
						{movement
							{speed slow}
							{type normal}
						}
					}
					{"delay"
						{time 0.5}
					}
					{"animation"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag _ai_pilot_surrender}
									}
								}
								{include
									{state
										{state operatable}
									}
								}
								{exclude
									{state
										{state dead}
									}
									{state
										{state inactive}
									}
									{state
										{state user_control}
									}
									{state
										{state linked}
									}
								
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
							}
						}
						{drop "orders sensor"}
						{collage stand_giveup_1}
						{cicledelay 9000}
						{delay 9000}
						{flags loop}
					}
					{"delay"
						{time 0.1}
					}
					{"actor_state"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag _ai_pilot_surrender}
									}
								}
								{exclude
									{state
										{state dead}
									}
									{state
										{state inactive}
									}
									{state
										{state user_control}
									}
								
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
							}
						}
						{fire_mode hold}
						{move_mode hold}
						{ai_move
							{mode disable}
						}
						{movement
							{speed slow}
							{type normal}
						}
					}
					{"delay"
						{time 0.1}
					}
					{"entity_state"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag _ai_pilot_surrender}
									}
								}
								{exclude
									{state
										{state dead}
									}
									{state
										{state inactive}
									}
									{state
										{state user_control}
									}
									{state
										{state linked}
									}
								
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
							}
						}
						{tag_add _ai_pilot_surrendered}
						{tag_remove _ai_pilot_surrender}
					}
					{"delay"
						{time 0.1}
					}
					{"talk"
						{selector
							{source advanced}
							{ignore_captured_by_user 0}
							{group
								{select
									{tag
										{tag _ai_pilot_surrendered}
									}
								}
								{include
									{prop
										{prop human}
									}
									{state
										{state operatable}
									}
								}
							
{exclude {tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}}
}
							{amount 1
							}
						}
						{text "mission/multi/ai_pilot_surrender"}
					}
					{"delay"
						{time 5}
					}
					{"trigger"
						{name "hf inf ai/pilot surrender"}
					}
				}
			}

;// Wirecutting script
			{"hf inf ai/grenade smoke wirecutter"
				{condition
					{expression "2 & 3 & 4 & 5 & (1)"}
					{terms
						{"1.see_actors"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag _bot}
										}
										{tag
											{tag bot}
										}
									}
									{include
										{with_item
											{type amount}
											{item "smoke"}
											{min 1}
										}
										{state
											{state operatable}
										}
										{prop
											{prop human}
										}
									}
									{exclude
										{state
											{state dead}
										}
										{state
											{state inactive}
										}
										{state
											{state user_control}
										}
										{state
											{state linked}
										}
										{tag
											{tag _lua_mi}
										}
										{tag
											{tag _ai_do_not_disturb}
										}										
										{tag
											{tag wounded}
										}
										{tag
											{tag bleeding}
										}
										{tag
											{tag _bleeding}
										}
										{tag
											{tag wounded_animation_playing}
										}
										{tag
											{tag repairing}
										}
										{tag
											{tag reloading}
										}
									
{tag {tag _ai_ap_grenade}}
{tag {tag _ai_at_grenade}}
{tag {tag _ufb_smoke_wirecutter_actor}}
{tag {tag ai_close_inf}}
{tag {tag _ai_wirecutter_in_action}}
{tag {tag bot_inf_flank_in_progress}}
{tag {tag _lua_ignore}}
{tag {tag bot_arty}}
{tag {tag bot_aa_guard}}
{tag {tag crew}}
{tag {tag _ai_medic}}
{tag {tag bot_medic}}
{tag {tag tcrew}}
{tag {tag ecrew}}
{tag {tag ecrew_a}}
{tag {tag ecrew_b}}
{prop {prop crew}}

{tag {tag _ufb_smoke_120m_actor}}
{tag {tag _ufb_smoke_60m_actor}}
{tag {tag _ufb_smoke_wirecutter_actor}}

{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
								}
							}
							{enemy
								{source advanced}
								{group
									{select
										{tag
											{tag _bot}
										}
										{tag
											{tag bot}
										}
									}
									{include
										{state
											{state operatable}
										}
										{tag
											{tag _ai_wirecutter_in_action}
										}
									}
									{exclude
										{state
											{state dead}
										}
										{state
											{state inactive}
										}
										{tag
											{tag bleeding}
										}
										{tag
											{tag _bleeding}
										}
										{tag
											{tag _bleedout_}
										}
										{tag
											{tag wounded_animation_playing}
										}
										{tag
											{tag wounded_dead}
										}
										{tag
											{tag wounded}
										}
									
{tag {tag _ai_ap_grenade}}
{tag {tag _ai_at_grenade}}
{tag {tag _ufb_smoke_wirecutter_actor}}
{tag {tag ai_close_inf}}

{tag {tag bot_inf_flank_in_progress}}
{tag {tag _lua_ignore}}
{tag {tag bot_arty}}
{tag {tag bot_aa_guard}}
{tag {tag crew}}
{tag {tag _ai_medic}}
{tag {tag bot_medic}}
{tag {tag repairing}}
{tag {tag tcrew}}
{tag {tag ecrew}}
{tag {tag ecrew_a}}
{tag {tag ecrew_b}}
{prop {prop crew}}

{tag {tag _ufb_smoke_120m_target}}
{tag {tag _ufb_smoke_60m_target}}
{tag {tag _ufb_smoke_wirecutter_target}}
}
								}
							}
							{distance
								{mode in_range}
								{min 7}
								{max 44}
							}
							{detection visible}
							{tag
								{"tag pair"}
								{"for selector" _ufb_smoke_wirecutter_actor}
								{"for enemy" _ufb_smoke_wirecutter_target}
							}
						}
						{"2.cmp_i" {var "attacker_retreat_requested$"} {op "=="} {value 0}}
						{"3.cmp_i" {var "defender_retreat_requested$"} {op "=="} {value 0}}
						{"4.cmp_i" {var "bot_retreat_active$"} {op "=="} {value 0}}
						{"5.cmp_i" {var "winner_decided$"} {op "=="} {value 0}}
					}
				}
				{actions
					{"delay"
						{time 0.1}
					}
					{"switch"
						{"case"
							{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
							{"switch"
								{"case"
									{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
									{"switch"
										{"case"
											{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
											{"switch"
												{"case"
													{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
													{"inventory"
														{selector
															{source advanced}
															{group
																{select
																	{tag
																		{tag _ufb_smoke_wirecutter_actor}
																	}
																}
																{exclude
																	{with_item
																		{type using}
																		{item "smoke"}
																	}
																	{state
																		{state dead}
																	}
																	{state
																		{state inactive}
																	}
																
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
															}
														}
														{action take}
														{item "smoke"}
													}
												}
											}
										}
									}
								}
							}
						}
					}
					{"delay"
						{time 0.5}
					}
					{"switch"
						{"case"
							{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
							{"switch"
								{"case"
									{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
									{"switch"
										{"case"
											{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
											{"switch"
												{"case"
													{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
													{"action"
														{selector
															{amount 1
															}
															{tag _ufb_smoke_wirecutter_actor}
															{type human}
															{state "not dead"}
														}
														{drop orders}
														{action rotate}
														{target
															{ignore_captured_by_user 0}
															{tag _ufb_smoke_wirecutter_target}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
					{"delay"
						{time 1}
					}
					{"switch"
						{"case"
							{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
							{"switch"
								{"case"
									{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
									{"switch"
										{"case"
											{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
											{"switch"
												{"case"
													{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
													; UFB: throw toward a 10 m ground point after facing the distant threat.
													{"effect" {selector
															{amount 1
															}
															{tag _ufb_smoke_wirecutter_actor}
															{type human}
															{state "not dead"}
														} {effect ufb_smoke_screen_wirecutter}}
												}
											}
										}
									}
								}
							}
						}
					}
					{"switch"
						{"case"
							{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
							{"switch"
								{"case"
									{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
									{"switch"
										{"case"
											{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
											{"switch"
												{"case"
													{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
													; UFB: throw toward a 10 m ground point after facing the distant threat.
													{"action"
														{selector
															{amount 1
															}
															{tag _ufb_smoke_wirecutter_actor}
															{type human}
															{state "not dead"}
														}
														{drop orders}
														{action throw_sk_grenade}
														{target
															{ignore_captured_by_user 0}
															{tag _ufb_smoke_wirecutter_screen}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
					{"delay"
						{time 2.5}
					}
					{"switch"
						{"case"
							{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
							{"switch"
								{"case"
									{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
									{"switch"
										{"case"
											{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
											{"switch"
												{"case"
													{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
													{"actor_to_cover"
														{selector
															{tag _ufb_smoke_wirecutter_actor}
														}
														{drop orders}
													}
												}
											}
										}
									}
								}
							}
						}
					}
					{"delay"
						{time 0.1}
					}
					; UFB: keep this threat reserved through the smoke retry interval.

					{"delay"
						{time 0.1}
					}
					{"entity_state"
						{selector
							{tag _ufb_smoke_wirecutter_actor}
						}
						{tag_remove _ufb_smoke_wirecutter_actor}
					}
					{"delay"
						{time 18}
					}
					{"entity_state"
						{selector
							{tag _ufb_smoke_wirecutter_target}
						}
						{tag_remove _ufb_smoke_wirecutter_target}
					}
{"trigger"
						{name "hf inf ai/grenade smoke wirecutter"}
					}
				}
			}
			{"hf inf ai/barbwire detect and tag"
				{condition
					{terms
						{"1.near"
							{units
								{source advanced}
								{group
									{select
										{tag
											{tag _bot}
										}
										{tag
											{tag bot}
										}
									}
									{include
										{state
											{state operatable}
										}
										{with_item
											{type existance}
											{item "wirecutters"}
										}
										{prop
											{prop human}
										}
									}
									{exclude
										{state
											{state dead}
										}
										{state
											{state inactive}
										}
										{state
											{state user_control}
										}
										{with_item
											{type using}
											{item "mine_detector"}
										}
										{state
											{state linked}
										}
									}
								}
							}
							{near_to
								{amount 3
								}
								{tag barbed_wire}
							}
							{distance 40}
						}
					}
				}
				{actions
					{"delay"
						{time 0.1}
					}
					{"entity_state"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag _bot}
									}
									{tag
										{tag bot}
									}
								}
								{include
									{state
										{state operatable}
									}
									{with_item
										{type existance}
										{item "wirecutters"}
									}
								}
								{exclude
									{state
										{state dead}
									}
									{state
										{state inactive}
									}
									{state
										{state user_control}
									}
									{with_item
										{type using}
										{item "mine_detector"}
									}
									{tag
										{tag _ai_wirecutter_do}
									}
									{tag
										{tag _ai_wirecutter_in_action}
									}
									{state
										{state linked}
									}
								
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
							}
							{amount 1
							}
							{sort
								{type entity}
								{entity
									{amount 4
									}
									{tag barbed_wire}
								}
							}
						}
						{tag_add _ai_wirecutter}
					}
					{"delay"
						{time 0.1}
					}
					{"entity_state"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag barbed_wire}
									}
								}
							
{exclude {tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}}
}
							{amount 4
							}
							{sort
								{type entity}
								{entity
									{source advanced}
									{group
										{select
											{tag
												{tag _ai_wirecutter}
											}
										}
										{include
											{state
												{state operatable}
											}
										}
										{exclude
											{state
												{state dead}
											}
											{state
												{state inactive}
											}
											{state
												{state user_control}
											}
										}
									}
								}
							}
						}
						{tag_add barbed_wire_target}
					}
					{"delay"
						{time 0.1}
					}
					{"entity_state"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag _ai_wirecutter}
									}
								}
							
{exclude {tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}}
}
						}
						{tag_add _lua_mi}
					}
					{"delay"
						{time 10}
					}
					{"trigger"
						{name "hf inf ai/barbwire detect and tag"}
					}
				}
			}
			{"hf inf ai/barbwire action"
				{condition
					{terms
						{"1.trigger"
							{name "hf inf ai/barbwire detect and tag"}
						}
					}
				}
				{actions
					{"delay"
						{time 2}
					}
					{"entity_state"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag _ai_wirecutter}
									}
								}
								{include
									{state
										{state operatable}
									}
									{prop
										{prop human}
									}
								}
								{exclude
									{state
										{state dead}
									}
									{state
										{state inactive}
									}
									{tag
										{tag _ai_wirecutter_in_action}
									}
								
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
							}
							{sort
								{type entity}
								{entity
									{amount 1
									}
									{tag barbed_wire}
								}
							}
							{amount 1
							}
						}
						{tag_add _ai_wirecutter_do}
					}
					{"delay"
						{time 0.1}
					}
					{"actor_state"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag _ai_wirecutter_do}
									}
								}
								{exclude
									{tag
										{tag _ai_wirecutter_in_action}
									}
								
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
							}
						}
						{fire_mode hold}
						{move_mode zone}
						{move_radius 10}
						{ai_move
							{mode disable}
						}
					}
					{"delay"
						{time 0.1}
					}
					{"action"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag _ai_wirecutter_do}
									}
								}
								{include
									{state
										{state operatable}
									}
								}
								{exclude
									{tag
										{tag _ai_wirecutter_in_action}
									}
									{state
										{state dead}
									}
									{state
										{state inactive}
									}
									{tag
										{tag _ai_generic_cooldown_10sec}
									}
								
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
							}
						}
						{drop "orders sensor senseless"}
						{action move}
						{target
							{source advanced}
							{group
								{select
									{tag
										{tag barbed_wire_target}
									}
								}
								{exclude
									{tag
										{tag barbed_wire_occupied}
									}
								}
							}
							{amount 1
							}
							{sort
								{type shuffle}
							}
						}
					}
					{"delay"
						{time 1}
					}
					{"effect"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag _ai_wirecutter_do}
									}
								}
								{include
									{state
										{state operatable}
									}
								}
								{exclude
									{state
										{state dead}
									}
									{state
										{state inactive}
									}
								
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
							}
						}
						{effect ai_generic_cooldown_10sec}
					}
					{"entity_state"
						{selector
							{tag _ai_wirecutter_do}
						}
						{tag_remove _ai_wirecutter_do}
					}
					{"delay"
						{time 0.1}
					}
					{"trigger"
						{name "hf inf ai/barbwire action"}
					}
				}
			}
			{"hf inf ai/barbwire cut detect"
				{condition
					{expression "2 & 3 & 4 & 5 & (1)"}
					{terms
						{"1.near"
							{units
								{source advanced}
								{group
									{select
										{tag
											{tag _ai_wirecutter}
										}
									}
									{include
										{state
											{state operatable}
										}
										{prop
											{prop human}
										}
									}
									{exclude
										{state
											{state dead}
										}
										{state
											{state inactive}
										}
										{tag
											{tag _ai_wirecutter_in_action}
										}
									}
								}
							}
							{near_to
								{amount 1
								}
								{tag barbed_wire_target}
							}
							{distance 3}
						}
						{"2.cmp_i" {var "attacker_retreat_requested$"} {op "=="} {value 0}}
						{"3.cmp_i" {var "defender_retreat_requested$"} {op "=="} {value 0}}
						{"4.cmp_i" {var "bot_retreat_active$"} {op "=="} {value 0}}
						{"5.cmp_i" {var "winner_decided$"} {op "=="} {value 0}}
					}
				}
				{actions
					{"delay"
						{time 0.1}
					}
					{"switch"
						{"case"
							{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
							{"switch"
								{"case"
									{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
									{"switch"
										{"case"
											{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
											{"switch"
												{"case"
													{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
													{"entity_state"
														{selector
															{source advanced}
															{group
																{select
																	{tag
																		{tag _ai_wirecutter}
																	}
																}
																{include
																	{state
																		{state operatable}
																	}
																}
																{exclude
																	{state
																		{state dead}
																	}
																	{state
																		{state inactive}
																	}
																
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
															}
															{sort
																{type entity}
																{entity
																	{amount 1
																	}
																	{tag barbed_wire_target}
																}
															}
															{amount 1
															}
														}
														{tag_add _ai_wirecutter_in_action}
													}
												}
											}
										}
									}
								}
							}
						}
					}
					{"delay"
						{time 1}
					}
					{"trigger"
						{name "hf inf ai/barbwire cut detect"}
					}
				}
			}
			{"hf inf ai/barbwire cut action"
				{condition
					{expression "2 & 3 & 4 & 5 & (1)"}
					{terms
						{"1.near"
							{units
								{source advanced}
								{group
									{select
										{tag
											{tag _ai_wirecutter_in_action}
										}
									}
									{include
										{state
											{state operatable}
										}
										{prop
											{prop human}
										}
									}
									{exclude
										{state
											{state dead}
										}
										{state
											{state inactive}
										}
									}
								}
							}
							{near_to
								{amount 1
								}
								{tag barbed_wire_target}
							}
							{distance 3}
						}
						{"2.cmp_i" {var "attacker_retreat_requested$"} {op "=="} {value 0}}
						{"3.cmp_i" {var "defender_retreat_requested$"} {op "=="} {value 0}}
						{"4.cmp_i" {var "bot_retreat_active$"} {op "=="} {value 0}}
						{"5.cmp_i" {var "winner_decided$"} {op "=="} {value 0}}
					}
				}
				{actions
					{"delay"
						{time 0.1}
					}
					{"switch"
						{"case"
							{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
							{"switch"
								{"case"
									{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
									{"switch"
										{"case"
											{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
											{"switch"
												{"case"
													{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
													{"entity_state"
														{selector
															{source advanced}
															{group
																{select
																	{tag
																		{tag _ai_wirecutter}
																	}
																}
															
{exclude {tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}}
}
															{sort
																{type entity}
																{entity
																	{amount 1
																	}
																	{tag barbed_wire_target}
																}
															}
															{amount 1
															}
														}
														{tag_add _ai_wirecutter_in_action}
													}
												}
											}
										}
									}
								}
							}
						}
					}
					{"switch"
						{"case"
							{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
							{"switch"
								{"case"
									{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
									{"switch"
										{"case"
											{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
											{"switch"
												{"case"
													{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
													{"entity_state"
														{selector
															{source advanced}
															{amount 1
															}
															{group
																{select
																	{tag
																		{tag barbed_wire_target}
																	}
																}
															
{exclude {tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}}
}
															{sort
																{type entity}
																{entity
																	{source advanced}
																	{group
																		{select
																			{tag
																				{tag _ai_wirecutter_in_action}
																			}
																		}
																		{include
																			{state
																				{state operatable}
																			}
																		}
																		{exclude
																			{state
																				{state dead}
																			}
																			{state
																				{state inactive}
																			}
																		}
																	}
																}
															}
														}
														{tag_add barbed_wire_occupied}
													}
												}
											}
										}
									}
								}
							}
						}
					}
					{"delay"
						{time 0.1}
					}
					{"switch"
						{"case"
							{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
							{"switch"
								{"case"
									{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
									{"switch"
										{"case"
											{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
											{"switch"
												{"case"
													{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
													{"inventory"
														{selector
															{source advanced}
															{group
																{select
																	{tag
																		{tag _ai_wirecutter_in_action}
																	}
																}
																{exclude
																	{with_item
																		{type using}
																		{item "wirecutters"}
																	}
																
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
															}
														}
														{action take}
														{item "wirecutters"}
													}
												}
											}
										}
									}
								}
							}
						}
					}
					{"delay"
						{time 0.1}
					}
					{"switch"
						{"case"
							{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
							{"switch"
								{"case"
									{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
									{"switch"
										{"case"
											{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
											{"switch"
												{"case"
													{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
													{"action"
														{selector
															{source advanced}
															{group
																{select
																	{tag
																		{tag _ai_wirecutter_in_action}
																	}
																}
																{include
																	{state
																		{state operatable}
																	}
																}
																{exclude
																	{state
																		{state dead}
																	}
																	{state
																		{state inactive}
																	}
																
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
															}
														}
														{action move}
														{target
															{source advanced}
															{group
																{select
																	{tag
																		{tag barbed_wire_occupied}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
					{"delay"
						{time 1.5}
					}
					{"switch"
						{"case"
							{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
							{"switch"
								{"case"
									{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
									{"switch"
										{"case"
											{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
											{"switch"
												{"case"
													{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
													{"animation"
														{selector
															{source advanced}
															{group
																{select
																	{tag
																		{tag _ai_wirecutter_in_action}
																	}
																}
															
{exclude {tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}}
}
														}
														{collage stand_cut_wire}
														{cicledelay 0}
														{delay 0}
													}
												}
											}
										}
									}
								}
							}
						}
					}
					{"delay"
						{time 3.5}
					}
					{"if"
						{condition
							{type near}
							{units
								{tag _ai_wirecutter_in_action}
								{type human}
								{state "not dead"}
							}
							{near_to
								{amount 1
								}
								{tag barbed_wire_occupied}
							}
							{distance 5}
						}
						{"delay"
							{time 0.1}
						}
						{"switch"
							{"case"
								{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
								{"switch"
									{"case"
										{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
										{"switch"
											{"case"
												{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
												{"switch"
													{"case"
														{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
														{"effect"
															{selector
																{source advanced}
																{group
																	{select
																		{tag
																			{tag barbed_wire_occupied}
																		}
																	}
																
{exclude {tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}}
}
																{amount 1
																}
																{sort
																	{type entity}
																	{entity
																		{amount 1
																		}
																		{tag _ai_wirecutter_in_action}
																		{type human}
																		{state "not dead"}
																	}
																}
															}
															{effect change_model}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
					{"delay"
						{time 1.25}
					}
					{"switch"
						{"case"
							{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
							{"switch"
								{"case"
									{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
									{"switch"
										{"case"
											{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
											{"switch"
												{"case"
													{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
													{"entity_state"
														{selector
															{tag _ai_wirecutter}
														}
														{tag_remove _lua_mi}
													}
												}
											}
										}
									}
								}
							}
						}
					}
					{"entity_state"
						{selector
							{tag _ai_wirecutter}
						}
						{tag_remove _ai_wirecutter_in_action}
					}
					{"delay"
						{time 0.5}
					}
					{"trigger"
						{name "hf inf ai/barbwire cut action"}
					}
				}
			}

;// Motorised infantry script
			{"hf motor ai/motor inf truck is empty"
				{condition
					{terms
						{"1.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag _ai_veh_empty}
										}
									}
									{include
										{state
											{state inhabited}
										}
										{state
											{state chassis_work}
										}
									}
									{exclude
										{state
											{state dead}
										}
										{state
											{state inactive}
										}
										{tag
											{tag _ai_veh_empty_rtb}
										}
									
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
								}
							}
						}
					}
				}
				{actions
					{"delay"
						{time 0.1}
					}
					{"if"
						{condition
							{type cmp_i}
							{var "bots_spawnside$"}
							{op "=="}
							{value 1}
						}
						{"switch"
							{"case"
								{condition
									{type rand}
									{value 0.25}
								}
								{"delay"
									{time 0.1}
								}
								{"action"
									{selector
										{source advanced}
										{group
											{select
												{tag
													{tag _ai_veh_empty}
												}
											}
											{include
												{state
													{state inhabited}
												}
												{state
													{state chassis_work}
												}
											}
											{exclude
												{state
													{state dead}
												}
												{state
													{state inactive}
												}
											
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
										}
									}
									{drop orders}
									{action move}
									{target
										{zone "a_1"}
									}
								}
							}
							{"case"
								{condition
									{type rand}
									{value 0.25}
								}
								{"delay"
									{time 0.1}
								}
								{"action"
									{selector
										{source advanced}
										{group
											{select
												{tag
													{tag _ai_veh_empty}
												}
											}
											{include
												{state
													{state inhabited}
												}
												{state
													{state chassis_work}
												}
											}
											{exclude
												{state
													{state dead}
												}
												{state
													{state inactive}
												}
											
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
										}
									}
									{drop orders}
									{action move}
									{target
										{zone "a_2"}
									}
								}
							}
							{"case"
								{condition
									{type rand}
									{value 0.25}
								}
								{"delay"
									{time 0.1}
								}
								{"action"
									{selector
										{source advanced}
										{group
											{select
												{tag
													{tag _ai_veh_empty}
												}
											}
											{include
												{state
													{state inhabited}
												}
												{state
													{state chassis_work}
												}
											}
											{exclude
												{state
													{state dead}
												}
												{state
													{state inactive}
												}
											
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
										}
									}
									{drop orders}
									{action move}
									{target
										{zone "a_3"}
									}
								}
							}
							{"case"
								{condition
									{type rand}
									{value 0.25}
								}
								{"delay"
									{time 0.1}
								}
								{"action"
									{selector
										{source advanced}
										{group
											{select
												{tag
													{tag _ai_veh_empty}
												}
											}
											{include
												{state
													{state inhabited}
												}
												{state
													{state chassis_work}
												}
											}
											{exclude
												{state
													{state dead}
												}
												{state
													{state inactive}
												}
											
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
										}
									}
									{drop orders}
									{action move}
									{target
										{zone "a_4"}
									}
								}
							}
							{"default"
								{"delay"
									{time 0.1}
								}
								{"action"
									{selector
										{source advanced}
										{group
											{select
												{tag
													{tag _ai_veh_empty}
												}
											}
											{include
												{state
													{state inhabited}
												}
												{state
													{state chassis_work}
												}
											}
											{exclude
												{state
													{state dead}
												}
												{state
													{state inactive}
												}
											
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
										}
									}
									{drop orders}
									{action move}
									{target
										{zone "a_1"}
									}
								}
							}
						}
					}
					{"if"
						{condition
							{type cmp_i}
							{var "bots_spawnside$"}
							{op "=="}
							{value 2}
						}
						{"switch"
							{"case"
								{condition
									{type rand}
									{value 0.25}
								}
								{"delay"
									{time 0.1}
								}
								{"action"
									{selector
										{source advanced}
										{group
											{select
												{tag
													{tag _ai_veh_empty}
												}
											}
											{include
												{state
													{state inhabited}
												}
												{state
													{state chassis_work}
												}
											}
											{exclude
												{state
													{state dead}
												}
												{state
													{state inactive}
												}
											
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
										}
									}
									{drop orders}
									{action move}
									{target
										{zone "b_1"}
									}
								}
							}
							{"case"
								{condition
									{type rand}
									{value 0.25}
								}
								{"delay"
									{time 0.1}
								}
								{"action"
									{selector
										{source advanced}
										{group
											{select
												{tag
													{tag _ai_veh_empty}
												}
											}
											{include
												{state
													{state inhabited}
												}
												{state
													{state chassis_work}
												}
											}
											{exclude
												{state
													{state dead}
												}
												{state
													{state inactive}
												}
											
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
										}
									}
									{drop orders}
									{action move}
									{target
										{zone "b_2"}
									}
								}
							}
							{"case"
								{condition
									{type rand}
									{value 0.25}
								}
								{"delay"
									{time 0.1}
								}
								{"action"
									{selector
										{source advanced}
										{group
											{select
												{tag
													{tag _ai_veh_empty}
												}
											}
											{include
												{state
													{state inhabited}
												}
												{state
													{state chassis_work}
												}
											}
											{exclude
												{state
													{state dead}
												}
												{state
													{state inactive}
												}
											
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
										}
									}
									{drop orders}
									{action move}
									{target
										{zone "b_3"}
									}
								}
							}
							{"case"
								{condition
									{type rand}
									{value 0.25}
								}
								{"delay"
									{time 0.1}
								}
								{"action"
									{selector
										{source advanced}
										{group
											{select
												{tag
													{tag _ai_veh_empty}
												}
											}
											{include
												{state
													{state inhabited}
												}
												{state
													{state chassis_work}
												}
											}
											{exclude
												{state
													{state dead}
												}
												{state
													{state inactive}
												}
											
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
										}
									}
									{drop orders}
									{action move}
									{target
										{zone "b_4"}
									}
								}
							}
							{"default"
								{"delay"
									{time 0.1}
								}
								{"action"
									{selector
										{source advanced}
										{group
											{select
												{tag
													{tag _ai_veh_empty}
												}
											}
											{include
												{state
													{state inhabited}
												}
												{state
													{state chassis_work}
												}
											}
											{exclude
												{state
													{state dead}
												}
												{state
													{state inactive}
												}
											
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
										}
									}
									{drop orders}
									{action move}
									{target
										{zone "b_1"}
									}
								}
							}
						}
					}
					{"delay"
						{time 1}
					}
					{"entity_state"
						{selector
							{tag _ai_veh_empty}
						}
						{tag_add _ai_veh_empty_rtb}
					}
					{"delay"
						{time 0.1}
					}
					{"entity_state"
						{selector
							{tag _ai_veh_empty_rtb}
						}
						{tag_add _lua_mi}
					}
					{"delay"
						{time 0.1}
					}
					{"actor_state"
						{selector
							{tag _ai_veh_empty_rtb}
						}
						{ai_move
							{mode disable}
						}
						{movement
							{speed fast}
						}
						{ai
							{follow_commander off}
						}
					}
					{"delay"
						{time 5}
					}
					{"trigger"
						{name "hf motor ai/motor inf truck is empty"}
					}
				}
			}
			{"hf motor ai/motor inf truck delete a_1"
				{condition
					{terms
						{"1.entities"
							{selector
								{tag _ai_veh_empty_rtb}
								{zone "a_1"}
							}
						}
					}
				}
				{actions
					{"delay"
						{time 5}
					}
					{"delete"
						{selector
							{tag _ai_veh_empty}
							{zone "a_1"}
						}
					}
					{"delay"
						{time 5}
					}
					{"trigger"
						{name "hf motor ai/motor inf truck delete a_1"}
					}
				}
			}
			{"hf motor ai/motor inf truck delete a_2"
				{condition
					{terms
						{"1.entities"
							{selector
								{tag _ai_veh_empty_rtb}
								{zone "a_2"}
							}
						}
					}
				}
				{actions
					{"delay"
						{time 5}
					}
					{"delete"
						{selector
							{tag _ai_veh_empty}
							{zone "a_2"}
						}
					}
					{"delay"
						{time 5}
					}
					{"trigger"
						{name "hf motor ai/motor inf truck delete a_2"}
					}
				}
			}
			{"hf motor ai/motor inf truck delete a_3"
				{condition
					{terms
						{"1.entities"
							{selector
								{tag _ai_veh_empty_rtb}
								{zone "a_3"}
							}
						}
					}
				}
				{actions
					{"delay"
						{time 5}
					}
					{"delete"
						{selector
							{tag _ai_veh_empty}
							{zone "a_3"}
						}
					}
					{"delay"
						{time 5}
					}
					{"trigger"
						{name "hf motor ai/motor inf truck delete a_3"}
					}
				}
			}
			{"hf motor ai/motor inf truck delete a_4"
				{condition
					{terms
						{"1.entities"
							{selector
								{tag _ai_veh_empty_rtb}
								{zone "a_4"}
							}
						}
					}
				}
				{actions
					{"delay"
						{time 5}
					}
					{"delete"
						{selector
							{tag _ai_veh_empty}
							{zone "a_4"}
						}
					}
					{"delay"
						{time 5}
					}
					{"trigger"
						{name "hf motor ai/motor inf truck delete a_4"}
					}
				}
			}
			{"hf motor ai/motor inf truck delete b_1"
				{condition
					{terms
						{"1.entities"
							{selector
								{tag _ai_veh_empty_rtb}
								{zone "b_1"}
							}
						}
					}
				}
				{actions
					{"delay"
						{time 5}
					}
					{"delete"
						{selector
							{tag _ai_veh_empty}
							{zone "b_1"}
						}
					}
					{"delay"
						{time 5}
					}
					{"trigger"
						{name "hf motor ai/motor inf truck delete b_1"}
					}
				}
			}
			{"hf motor ai/motor inf truck delete b_2"
				{condition
					{terms
						{"1.entities"
							{selector
								{tag _ai_veh_empty_rtb}
								{zone "b_2"}
							}
						}
					}
				}
				{actions
					{"delay"
						{time 5}
					}
					{"delete"
						{selector
							{tag _ai_veh_empty}
							{zone "b_2"}
						}
					}
					{"delay"
						{time 5}
					}
					{"trigger"
						{name "hf motor ai/motor inf truck delete b_2"}
					}
				}
			}
			{"hf motor ai/motor inf truck delete b_3"
				{condition
					{terms
						{"1.entities"
							{selector
								{tag _ai_veh_empty_rtb}
								{zone "b_3"}
							}
						}
					}
				}
				{actions
					{"delay"
						{time 5}
					}
					{"delete"
						{selector
							{tag _ai_veh_empty}
							{zone "b_3"}
						}
					}
					{"delay"
						{time 5}
					}
					{"trigger"
						{name "hf motor ai/motor inf truck delete b_3"}
					}
				}
			}
			{"hf motor ai/motor inf truck delete b_4"
				{condition
					{terms
						{"1.entities"
							{selector
								{tag _ai_veh_empty_rtb}
								{zone "b_4"}
							}
						}
					}
				}
				{actions
					{"delay"
						{time 5}
					}
					{"delete"
						{selector
							{tag _ai_veh_empty}
							{zone "b_4"}
						}
					}
					{"delay"
						{time 5}
					}
					{"trigger"
						{name "hf motor ai/motor inf truck delete b_4"}
					}
				}
			}

;// Modified airstrike script, moved from dcg_script.inc
			{"dcg/ai_air_decide"
				{condition
					{expression "1 & 2 & !3 & !4 & ((5 & 6) | 7)"}
					{terms
						{"1.event"
							{id "ai_air_possible"}
						}
						{"2.cmp_i"
							{var "ai_air_on$"}
							{op "=="}
							{value 0}
						}
						{"3.cmp_i"
							{var "bot_difficulty$"}
							{op "=="}
							{value 1}
						}
						{"4.cmp_i"
							{var "bot_difficulty$"}
							{op "=="}
							{value 2}
						}
						{"5.cmp_i"
							{var "bot_difficulty$"}
							{op "=="}
							{value 3}
						}
						{"6.cmp_i"
							{var "tier2$"}
							{op "=="}
							{value 1}
						}
						{"7.cmp_i"
							{var "bot_difficulty$"}
							{op "=="}
							{value 4}
						}
					}
				}
				{actions
					{"delay"
						{time 1}
					}
					{"switch"
						{"case"
							{condition
								{type cmp_i}
								{var "flag1$"}
								{op ">"}
								{value 0}
							}
							{"delay"
								{time 0.1}
							}
							{"switch"
								{"case"
									{condition
										{type entities}
										{selector
											{ignore_captured_by_user 0}
											{tag player}
											{zone "forward1"}
											{type human}
											{state operatable}
										}
									}
									{"delay"
										{time 0.1}
									}
									{"set_i"
										{var "ai_air_on$"}
										{op "="}
										{value 1}
									}
								}
								{"default"}
							}
						}
						{"default"}
					}
					{"delay"
						{time 2}
					}
					{"switch"
						{"case"
							{condition
								{type cmp_i}
								{var "ai_air_on$"}
								{op "=="}
								{value 0}
							}
							{"delay"
								{time 0.1}
							}
							{"switch"
								{"case"
									{condition
										{type cmp_i}
										{var "flag2$"}
										{op ">"}
										{value 0}
									}
									{"delay"
										{time 0.1}
									}
									{"switch"
										{"case"
											{condition
												{type entities}
												{selector
													{ignore_captured_by_user 0}
													{tag player}
													{zone "forward2"}
													{type human}
													{state operatable}
												}
											}
											{"delay"
												{time 0.1}
											}
											{"set_i"
												{var "ai_air_on$"}
												{op "="}
												{value 2}
											}
										}
										{"default"}
									}
								}
								{"default"}
							}
						}
						{"default"}
					}
					{"delay"
						{time 2}
					}
					{"switch"
						{"case"
							{condition
								{type cmp_i}
								{var "ai_air_on$"}
								{op "=="}
								{value 0}
							}
							{"delay"
								{time 0.1}
							}
							{"switch"
								{"case"
									{condition
										{type cmp_i}
										{var "flag3$"}
										{op ">"}
										{value 0}
									}
									{"delay"
										{time 0.1}
									}
									{"switch"
										{"case"
											{condition
												{type entities}
												{selector
													{ignore_captured_by_user 0}
													{tag player}
													{zone "forward3"}
													{type human}
													{state operatable}
												}
											}
											{"delay"
												{time 0.1}
											}
											{"set_i"
												{var "ai_air_on$"}
												{op "="}
												{value 3}
											}
										}
										{"default"}
									}
								}
								{"default"}
							}
						}
						{"default"}
					}
					{"delay"
						{time 2}
					}
					{"switch"
						{"case"
							{condition
								{type cmp_i}
								{var "ai_air_on$"}
								{op "=="}
								{value 0}
							}
							{"delay"
								{time 0.1}
							}
							{"switch"
								{"case"
									{condition
										{type cmp_i}
										{var "flag4$"}
										{op ">"}
										{value 0}
									}
									{"delay"
										{time 0.1}
									}
									{"switch"
										{"case"
											{condition
												{type entities}
												{selector
													{ignore_captured_by_user 0}
													{tag player}
													{zone "forward4"}
													{type human}
													{state operatable}
												}
											}
											{"delay"
												{time 0.1}
											}
											{"set_i"
												{var "ai_air_on$"}
												{op "="}
												{value 4}
											}
										}
										{"default"}
									}
								}
								{"default"}
							}
						}
						{"default"}
					}
					{"delay"
						{time 2}
					}
					{"switch"
						{"case"
							{condition
								{type cmp_i}
								{var "ai_air_on$"}
								{op "=="}
								{value 0}
							}
							{"delay"
								{time 0.1}
							}
							{"switch"
								{"case"
									{condition
										{type cmp_i}
										{var "flag5$"}
										{op ">"}
										{value 0}
									}
									{"delay"
										{time 0.1}
									}
									{"switch"
										{"case"
											{condition
												{type entities}
												{selector
													{ignore_captured_by_user 0}
													{tag player}
													{zone "forward5"}
													{type human}
													{state operatable}
												}
											}
											{"delay"
												{time 0.1}
											}
											{"set_i"
												{var "ai_air_on$"}
												{op "="}
												{value 5}
											}
										}
										{"default"}
									}
								}
								{"default"}
							}
						}
						{"default"}
					}
					{"delay"
						{time 25}
					}
					{"trigger"
						{name "dcg/ai_air_decide"}
					}
				}
			}
			{"dcg/ai_airstrike"
				{condition
					{expression "1 & !2 & !3 & ((4 & 5) | 6)"}
					{terms
						{"1.event"
							{id "ai_air_on"}
						}
						{"2.cmp_i"
							{var "bot_difficulty$"}
							{op "=="}
							{value 1}
						}
						{"3.cmp_i"
							{var "bot_difficulty$"}
							{op "=="}
							{value 2}
						}
						{"4.cmp_i"
							{var "bot_difficulty$"}
							{op "=="}
							{value 3}
						}
						{"5.cmp_i"
							{var "tier2$"}
							{op "=="}
							{value 1}
						}
						{"6.cmp_i"
							{var "bot_difficulty$"}
							{op "=="}
							{value 4}
						}
					}
				}
				{actions
					{"delay"
						{time 0.1}
					}
					{"entity_state"
						{selector
							{ignore_captured_by_user 0}
							{tag enemy_air}
						}
						{tag_remove enemy_air}
					}
					{"delay"
						{time 0.1}
					}
					{"switch"
						{"case"
							{condition
								{type cmp_i}
								{var "user_team$"}
								{op "=="}
								{value 1}
							}
							{"delay"
								{time 0.1}
							}
							{"actor_to_waypoint"
								{selector
									{source advanced}
									{ignore_captured_by_user 0}
									{group
										{select
											{tag
												{tag airstrike_ger_250}
											}	
											{tag
												{tag airstrike_ger_50}
											}													
											{tag
												{tag airstrike_rus}
											}
											{tag
												{tag airstrike_rus_500}
											}
											{tag
												{tag airstrike_rus_50}
											}
											{tag
												{tag airstrike_rus_rocket}
											}											
											{tag
												{tag airstrike_fin}
											}
											{tag
												{tag airstrike_usa}
											}
											{tag
												{tag airstrike_usa_rocket_hvar}
											}
											{tag
												{tag airstrike_usa_rocket_m8}
											}
											{tag
												{tag airstrike_eng_250}
											}
											{tag
												{tag airstrike_eng_250_2}
											}	
											{tag
												{tag airstrike_eng_100}
											}	
										}
										{include
											{tag
												{tag hidden}
											}
										}
									
{exclude {tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}}
}
									{amount 1
									}
								}
								{waypoint "0"}
								{clone}
								{approach "safe teleport & rotate"}
							}
						}
						{"default"
							{"delay"
								{time 0.1}
							}
							{"actor_to_waypoint"
								{selector
									{source advanced}
									{ignore_captured_by_user 0}
									{group
										{select
											{tag
												{tag airstrike_ger_250}
											}	
											{tag
												{tag airstrike_ger_50}
											}												
											{tag
												{tag airstrike_rus}
											}
											{tag
												{tag airstrike_rus_500}
											}
											{tag
												{tag airstrike_rus_50}
											}
											{tag
												{tag airstrike_rus_rocket}
											}											
											{tag
												{tag airstrike_fin}
											}
											{tag
												{tag airstrike_usa}
											}
											{tag
												{tag airstrike_usa_rocket_hvar}
											}
											{tag
												{tag airstrike_usa_rocket_m8}
											}		
											{tag
												{tag airstrike_eng_250}
											}
											{tag
												{tag airstrike_eng_250_2}
											}	
											{tag
												{tag airstrike_eng_100}
											}												
										}
										{include
											{tag
												{tag hidden}
											}
										}
									
{exclude {tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}}
}
									{amount 1
									}
								}
								{waypoint "6"}
								{clone}
								{approach "safe teleport & rotate"}
							}
						}
					}
				}
			}
			{"dcg/ai_airstrike_do"
				{condition
					{expression "(1 & 2 & 4) | (1 & 3 & !4)"}
					{terms
						{"1.event"
							{id "ai_air_on"}
						}
						{"2.entities"
							{selector
								{source advanced}
								{ignore_captured_by_user 0}
								{group
									{select
										{zone
											{zone "a_1"}
										}
										{zone
											{zone "a_2"}
										}
										{zone
											{zone "a_3"}
										}
										{zone
											{zone "a_4"}
										}
									}
									{include
										{tag
											{tag enemy_air}
										}
										{prop
											{prop vehicle}
										}
										{state
											{state operatable}
										}
									}
								
{exclude {tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}}
}
							}
						}
						{"3.entities"
							{selector
								{source advanced}
								{ignore_captured_by_user 0}
								{group
									{select
										{zone
											{zone "b_1"}
										}
										{zone
											{zone "b_2"}
										}
										{zone
											{zone "b_3"}
										}
										{zone
											{zone "b_4"}
										}
									}
									{include
										{tag
											{tag enemy_air}
										}
										{prop
											{prop vehicle}
										}
										{state
											{state operatable}
										}
									}
								
{exclude {tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}}
}
							}
						}
						{"4.cmp_i"
							{var "user_team$"}
							{op "=="}
							{value 1}
						}
					}
				}
				{actions
					{"delay"
						{time 4.5}
					}
					{"switch"
						{"case"
							{condition
								{type entities}
								{selector
									{ignore_captured_by_user 0}
									{tag ai_air_target}
									{zone "gamezone"}
								}
							}
							{"delay"
								{time 0.1}
							}
						}
						{"default"
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
												{tag _user}
											}
										}
										{include
											{zone
												{zone "gamezone"}
											}
											{state
												{state "operatable user_control"}
											}
										}
										{exclude
											{state
												{state inactive}
											}
											{state
												{state linked}
											}
										
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
									}
								}
								{tag_add ai_air_target}
							}
						}
					}
					{"delay"
						{time 1.1}
					}
					{"switch"
						{"case"
							{condition
								{type entities}
								{selector
									{source advanced}
									{ignore_captured_by_user 0}
									{group
										{select
											{tag
												{tag enemy_air}
											}
										}
										{include
											{tag
												{tag altitude_high}
											}
										}
										{exclude
											{tag
												{tag recon_plane}
											}
										
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
									}
								}
							}
							{"delay"
								{time 0.1}
							}
							{"event"
								{event "ai_air_on"}
								{mode reset}
								{delay 0}
							}
							{"air_attack"
								{selector
									{ignore_captured_by_user 0}
									{tag enemy_air}
									{type vehicle}
									{state inhabited}
								}
								{drop "orders sensor senseless"}
								{enemies
									{ignore_captured_by_user 0}
									{tag ai_air_target}
								}
								{attack_altitude 50}
							}
						}
						{"case"
							{condition
								{type entities}
								{selector
									{source advanced}
									{ignore_captured_by_user 0}
									{group
										{select
											{tag
												{tag enemy_air}
											}
										}
										{include
											{tag
												{tag altitude_low}
											}
										}
										{exclude
											{tag
												{tag altitude_high}
											}
											{tag
												{tag recon_plane}
											}
										
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
									}
								}
							}
							{"delay"
								{time 0.1}
							}
							{"air_attack"
								{selector
									{ignore_captured_by_user 0}
									{tag enemy_air}
									{type vehicle}
									{state inhabited}
								}
								{drop "orders sensor senseless"}
								{enemies
									{ignore_captured_by_user 0}
									{tag ai_air_target}
								}
								{attack_altitude 45}
							}
						}
						{"case"
							{condition
								{type entities}
								{selector
									{source advanced}
									{ignore_captured_by_user 0}
									{group
										{select
											{tag
												{tag enemy_air}
											}
										}
										{include
											{tag
												{tag recon_plane}
											}
										}
										{exclude
											{tag
												{tag altitude_high}
											}
											{tag
												{tag altitude_low}
											}											
										
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
									}
								}
							}
							{"delay"
								{time 0.2}
							}							
							{"action"
								{selector
									{ignore_captured_by_user 0}
									{tag enemy_air}
									{type vehicle}
									{state inhabited}
								}
								{drop "orders sensor senseless"}
								{action move}
							}
						}
						{"default"
							{"delay"
								{time 0.1}
							}
							{"air_attack"
								{selector
									{ignore_captured_by_user 0}
									{tag enemy_air}
									{type vehicle}
									{state inhabited}
								}
								{drop "orders sensor senseless"}
								{enemies
									{ignore_captured_by_user 0}
									{tag ai_air_target}
								}
								{attack_altitude 50}
							}
						}
					}
				}
			}
			{"dcg/ai_air_chance"
				{condition
					{expression "1 & !2 & !3 & ((4 & 5) | 6)"}
					{terms
						{"1.event"
							{id "airplane_set"}
						}
						{"2.cmp_i"
							{var "bot_difficulty$"}
							{op "=="}
							{value 1}
						}
						{"3.cmp_i"
							{var "bot_difficulty$"}
							{op "=="}
							{value 2}
						}
						{"4.cmp_i"
							{var "bot_difficulty$"}
							{op "=="}
							{value 3}
						}
						{"5.cmp_i"
							{var "tier2$"}
							{op "=="}
							{value 1}
						}
						{"6.cmp_i"
							{var "bot_difficulty$"}
							{op "=="}
							{value 4}
						}
					}
				}
				{actions
					{"delay"
						{time 1}
					}
					{"event"
						{event "ai_air_possible"}
						{mode reset}
						{delay 0}
					}
					{"switch"
						{"case"
							{condition
								{type rand}
								{value 0.1}
							}
							{"delay"
								{time 450}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.1}
							}
							{"delay"
								{time 450}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.1}
							}
							{"delay"
								{time 450}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.1}
							}
							{"delay"
								{time 450}
							}
						}
						{"default"
							{"delay"
								{time 450}
							}
						}
					}
					{"delay"
						{time 1}
					}
					{"switch"
						{##"case"
							{condition
								{type rand}
								{value 0.25}
							}
							{"delay"
								{time 0.1}
							}
							{"trigger"
								{name "dcg/ai_air_chance"}
							}
						}
						{"default"
							{"delay"
								{time 0.1}
							}
							{"event"
								{event "ai_air_possible"}
								{mode set}
								{delay 0}
							}
						}
					}
				}
			}
			{"dcg/ai_air_on"
				{condition
					{expression "1 & 2 & 3 & 4 & 5"}
					{terms
						{"1.event"
							{id "dcg"}
						}
						{"2.cmp_i"
							{var "enemyid$"}
							{op ">"}
							{value 0}
						}
						{"3.entities"
							{selector
								{ignore_captured_by_user 0}
								{tag _user}
								{zone "gamezone"}
								{state operatable}
							}
						}
						{"4.cmp_i"
							{var "ai_air_on$"}
							{op ">"}
							{value 0}
						}
						{"5.cmp_i"
							{var "dcg_on$"}
							{op ">"}
							{value 0}
						}
					}
				}
				{actions
					{"delay"
						{time 0.1}
					}
					{"event"
						{event "ai_air_on"}
						{mode set}
						{delay 0}
					}
					{"delay"
						{time 1}
					}
					{"entity_state"
						{selector
							{ignore_captured_by_user 0}
							{tag ai_air_target}
						}
						{tag_remove ai_air_target}
					}
					{"delay"
						{time 5}
					}
					{"switch"
						{"case"
							{condition
								{type entities}
								{selector
									{source advanced}
									{ignore_captured_by_user 0}
									{group
										{select
											{tag
												{tag _user}
											}
										}
										{include
											{zone
												{zone "combat"}
											}
											{prop
												{prop vehicle}
											}											
											{state
												{state operatable}
											}
											{state
												{state user_control}
											}
										}
										{exclude
											{tag
												{tag destroyed}
											}
										
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
									}
								}
							}
							{"delay"
								{time 0.1}
							}
							{"switch"
								{"case"
									{condition
										{type cmp_i}
										{var "ai_air_on$"}
										{op "=="}
										{value 5}
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
														{tag _user}
													}
												}
												{include
													{zone
														{zone "gamezone"}
													}
													{prop
														{prop vehicle}
													}												
													{state
														{state operatable}
													}
													{state
														{state user_control}
													}
												}
												{exclude
													{tag
														{tag destroyed}
													}
												
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
											}
											{sort
												{type waypoint}
												{wpid "5"}
											}
											{amount 1
											}
										}
										{tag_add ai_air_target}
									}
								}
								{"case"
									{condition
										{type cmp_i}
										{var "ai_air_on$"}
										{op "=="}
										{value 2}
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
														{tag _user}
													}
												}
												{include
													{zone
														{zone "gamezone"}
													}
													{prop
														{prop vehicle}
													}													
													{state
														{state operatable}
													}
													{state
														{state user_control}
													}
												}
												{exclude
													{tag
														{tag destroyed}
													}
												
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
											}
											{sort
												{type waypoint}
												{wpid "2"}
											}
											{amount 1
											}
										}
										{tag_add ai_air_target}
									}
								}
								{"case"
									{condition
										{type cmp_i}
										{var "ai_air_on$"}
										{op "=="}
										{value 3}
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
														{tag _user}
													}
												}
												{include
													{zone
														{zone "gamezone"}
													}
													{prop
														{prop vehicle}
													}											
													{state
														{state operatable}
													}
													{state
														{state user_control}
													}
												}
												{exclude
													{tag
														{tag destroyed}
													}
												
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
											}
											{sort
												{type waypoint}
												{wpid "3"}
											}
											{amount 1
											}
										}
										{tag_add ai_air_target}
									}
								}
								{"case"
									{condition
										{type cmp_i}
										{var "ai_air_on$"}
										{op "=="}
										{value 4}
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
														{tag _user}
													}
												}
												{include
													{zone
														{zone "gamezone"}
													}
													{prop
														{prop vehicle}
													}													
													{state
														{state operatable}
													}
													{state
														{state user_control}
													}
												}
												{exclude
													{tag
														{tag destroyed}
													}
												
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
											}
											{sort
												{type waypoint}
												{wpid "4"}
											}
											{amount 1
											}
										}
										{tag_add ai_air_target}
									}
								}
								{"default"
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
														{tag _user}
													}
												}
												{include
													{zone
														{zone "gamezone"}
													}
													{prop
														{prop vehicle}
													}													
													{state
														{state operatable}
													}
													{state
														{state user_control}
													}
												}
												{exclude
													{tag
														{tag destroyed}
													}
												
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
											}
											{sort
												{type waypoint}
												{wpid "1"}
											}
											{amount 1
											}
										}
										{tag_add ai_air_target}
									}
								}
							}
						}
						{"default"
							{"delay"
								{time 0.1}
							}
							{"switch"
								{"case"
									{condition
										{type cmp_i}
										{var "ai_air_on$"}
										{op "=="}
										{value 5}
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
														{tag _user}
													}
												}
												{include
													{zone
														{zone "gamezone"}
													}
													{state
														{state "operatable user_control"}
													}
												}
												{exclude
													{state
														{state inactive}
													}
												
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
											}
											{sort
												{type waypoint}
												{wpid "5"}
											}
											{amount 1
											}
										}
										{tag_add ai_air_target}
									}
								}
								{"case"
									{condition
										{type cmp_i}
										{var "ai_air_on$"}
										{op "=="}
										{value 2}
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
														{tag _user}
													}
												}
												{include
													{zone
														{zone "gamezone"}
													}
													{state
														{state "operatable user_control"}
													}
												}
												{exclude
													{state
														{state inactive}
													}
												
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
											}
											{sort
												{type waypoint}
												{wpid "2"}
											}
											{amount 1
											}
										}
										{tag_add ai_air_target}
									}
								}
								{"case"
									{condition
										{type cmp_i}
										{var "ai_air_on$"}
										{op "=="}
										{value 3}
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
														{tag _user}
													}
												}
												{include
													{zone
														{zone "gamezone"}
													}
													{state
														{state "operatable user_control"}
													}
												}
												{exclude
													{state
														{state inactive}
													}
												
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
											}
											{sort
												{type waypoint}
												{wpid "3"}
											}
											{amount 1
											}
										}
										{tag_add ai_air_target}
									}
								}
								{"case"
									{condition
										{type cmp_i}
										{var "ai_air_on$"}
										{op "=="}
										{value 4}
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
														{tag _user}
													}
												}
												{include
													{zone
														{zone "gamezone"}
													}
													{state
														{state "operatable user_control"}
													}
												}
												{exclude
													{state
														{state inactive}
													}
												
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
											}
											{sort
												{type waypoint}
												{wpid "4"}
											}
											{amount 1
											}
										}
										{tag_add ai_air_target}
									}
								}
								{"default"
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
														{tag _user}
													}
												}
												{include
													{zone
														{zone "gamezone"}
													}
													{state
														{state "operatable user_control"}
													}
												}
												{exclude
													{state
														{state inactive}
													}
												
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
											}
											{sort
												{type waypoint}
												{wpid "1"}
											}
											{amount 1
											}
										}
										{tag_add ai_air_target}
									}
								}
							}
						}
					}
				}
			}
			{"dcg/warning_air"
				{condition
					{expression "!1 & 2"}
					{terms
						{"1.event"
							{id "talk_on"}
						}
						{"2.trigger"
							{name "dcg/ai_airstrike"}
						}
					}
				}
				{actions
					{"delay"
						{time 0.1}
					}
					{"event"
						{event "talk_on"}
						{mode set}
						{delay 0}
					}
					{"delay"
						{time 6}
					}
					{"switch"
						{"case"
							{condition
								{type rand}
								{value 0.5}
							}
							{"delay"
								{time 0.1}
							}
							{"talk"
								{selector
									{ignore_captured_by_user 0}
									{amount 1
									}
									{tag player}
									{zone "gamezone"}
									{type human}
									{state "not dead"}
								}
								{text "mission/multi/enemy_plane_alert2"}
							}
						}
						{"default"
							{"delay"
								{time 0.1}
							}
							{"talk"
								{selector
									{ignore_captured_by_user 0}
									{amount 1
									}
									{tag player}
									{zone "gamezone"}
									{type human}
									{state "not dead"}
								}
								{text "mission/multi/enemy_plane_alert1"}
							}
						}
					}
					{"delay"
						{time 8}
					}
					{"event"
						{event "talk_on"}
						{mode reset}
						{delay 0}
					}
					{"delay"
						{time 1200}
					}
					{"trigger"
						{name "dcg/ai_air_chance"}
					}
					{"delay"
						{time 0.1}
					}
					{"trigger"
						{name "dcg/ai_airstrike"}
					}
					{"delay"
						{time 0.1}
					}
					{"trigger"
						{name "dcg/ai_airstrike_do"}
					}
					{"delay"
						{time 0.1}
					}
					{"trigger"
						{name "dcg/warning_air"}
					}	
					{"delay"
						{time 0.1}
					}
					{"trigger"
						{name "dcg/ai_air_on"}
					}						
					{"set_i"
						{var "ai_air_on$"}
						{op "="}
						{value 0}
					}	
					{"event"
						{event "airplane_set"}
						{mode set}
						{delay 0}
					}					
				}
			}

;// Bot tags
			{"lua/HF_bot_tags"
				{condition
					{terms
						{"1.cmp_i"
							{var "dcg_on$"}
							{op ">"}
							{value 2}
						}
						{"2.entities"
							{selector
								{source advanced}
								{ignore_captured_by_user 0}
								{group
									{select
										{zone
											{zone "gamezone"}
										}
									}
									{include
										{state
											{state operatable}
										}
									}
									{exclude
										{tag
											{tag _bot}
										}
										{tag
											{tag bot}
										}
										{tag
											{tag _animal}
										}
										{tag
											{tag cmp_def}
										}
										{tag
											{tag air_vehicle}
										}
										{player
											{player "0"}
										}
										{state
											{state user_control}
										}
									
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
								}
							}
						}
					}
				}
				{actions
					{"delay"
						{time 0.1}
					}
					{"entity_state"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag _ai}
									}
								}
								{include
									{prop
										{prop human}
									}
									{with_item
										{type existance}
										{item "tent_kit"}
									}
								}
								{exclude
									{tag
										{tag bot_medic}
									}
									{state
										{state user_control}
									}
								
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
							}
						}
						{tag_add bot_medic}
					}
					{"delay"
						{time 0.5}
					}
					{"entity_state"
						{selector
							{source advanced}
							{ignore_captured_by_user 0}
							{group
								{select
									{tag
										{tag _ai}
									}
								}
								{include
									{prop
										{prop detect_artillery}
									}
									{state
										{state operatable}
									}
								}
								{exclude
									{tag
										{tag bot_arty}
									}
									{state
										{state user_control}
									}
								
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
							}
						}
						{tag_add bot_arty}
					}
					{"delay"
						{time 0.5}
					}
					{"entity_state"
						{selector
							{source advanced}
							{ignore_captured_by_user 0}
							{group
								{select
									{tag
										{tag _ai}
									}
								}
								{include
									{tag
										{tag anti_air}
									}
									{state
										{state operatable}
									}
								}
								{exclude
									{tag
										{tag bot_aa}
									}
									{prop
										{prop cannon}
									}
									{prop
										{prop cannon_small}
									}
									{state
										{state user_control}
									}
								
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
							}
						}
						{tag_add bot_aa}
					}
					{"delay"
						{time 6}
					}
					{"trigger"
						{name "lua/HF_bot_tags"}
					}
				}
			}

;// Tank AI
			{"hf tank ai/finish off"
				{condition
					{expression "2 & 3 & 4 & 5 & (1)"}
					{terms
						{"1.see_actors"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag _bot}
										}
										{tag
											{tag bot}
										}
									}
									{include
										{state
											{state "operatable chassis_work inhabited"}
										}
										{prop
											{prop tank}
										}
									}
									{exclude
										{prop
											{prop human}
										}
										{prop
											{prop vehicle}
										}
										{prop
											{prop car}
										}
										{state
											{state user_control}
										}
										{tag
											{tag _user}
										}
										{tag
											{tag player}
										}
										{tag
											{tag ai_start_finishing_off}
										}
										{tag
											{tag ai_enemy_near_cooldown}
										}
										{tag
											{tag "+mobilegun"}
										}
									
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
								}
								{amount 1
								}
							}
							{enemy
								{source advanced}
								{group
									{include
										{state
											{state user_control}
										}
										{prop
											{prop tank}
										}
									}
									{exclude
										{prop
											{prop human}
										}
										{destroyed_components
											{masks
												"body"
											}
										}
										{destroyed_components
											{masks
												"ammo"
											}
										}
										{destroyed_components
											{masks
												"engine"
											}
										}
									}
								}
							}
							{distance
								{mode in_range}
								{min 50}
								{max 190}
							}
							{detection located}
							{tag
								{"tag pair"}
								{"for selector" ai_start_finishing_off}
								{"for enemy" ai_target_finishing_off}
							}
						}
						{"2.cmp_i" {var "attacker_retreat_requested$"} {op "=="} {value 0}}
						{"3.cmp_i" {var "defender_retreat_requested$"} {op "=="} {value 0}}
						{"4.cmp_i" {var "bot_retreat_active$"} {op "=="} {value 0}}
						{"5.cmp_i" {var "winner_decided$"} {op "=="} {value 0}}
					}
				}
				{actions
					{"delay"
						{time 0.01}
					}
					{"switch"
						{"case"
							{condition
								{type see_actors}
								{selector
									{tag ai_start_finishing_off}
								}
								{enemy
									{source advanced}
									{group
										{select
											{tag
												{tag ai_target_finishing_off}
											}
										}
										{include
											{state
												{state user_control}
											}
											{prop
												{prop tank}
											}
										}
										{exclude
											{prop
												{prop human}
											}
											{destroyed_components
												{masks
													"body"
												}
											}
											{destroyed_components
												{masks
													"ammo"
												}
											}
											{destroyed_components
												{masks
													"engine"
												}
											}
										}
									}
								}
								{distance
									{mode in_range}
									{min 0}
									{max 180}
								}
								{detection located}
							}
							{"delay"
								{time 0.01}
							}
						}
						{"default"
							{"switch"
								{"case"
									{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
									{"switch"
										{"case"
											{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
											{"switch"
												{"case"
													{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
													{"switch"
														{"case"
															{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
															{"actor_fire"
																{selector
																	{tag ai_start_finishing_off}
																}
																{attack enemies}
																{enemies
																	{tag ai_target_finishing_off}
																}
																{interval 0}
																{time 20}
																{burst_mode long}
															}
														}
													}
												}
											}
										}
									}
								}
							}
							{"delay"
								{time 10}
							}
						}
					}
					{"switch"
						{"case"
							{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
							{"switch"
								{"case"
									{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
									{"switch"
										{"case"
											{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
											{"switch"
												{"case"
													{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
													{"entity_state"
														{selector
															{tag ai_start_finishing_off}
														}
														{tag_add ai_enemy_near_cooldown}
													}
												}
											}
										}
									}
								}
							}
						}
					}
					{"entity_state"
						{selector
							{tag ai_target_finishing_off}
						}
						{tag_remove ai_target_finishing_off}
					}
					{"delay"
						{time 0.01}
					}
					{"switch"
						{"case"
							{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
							{"switch"
								{"case"
									{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
									{"switch"
										{"case"
											{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
											{"switch"
												{"case"
													{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
													{"effect"
														{selector
															{tag ai_start_finishing_off}
														}
														{effect cooldown_reset}
													}
												}
											}
										}
									}
								}
							}
						}
					}
					{"trigger"
						{name "hf tank ai/finish off"}
					}
				}
			}
			
(define "ai_alert_range_antitank"
			{"hf tank ai/range %r1"
				{condition
					{terms
						{"1.see_actors"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag range_%r1}
										}
									}
									{exclude
										{state
											{state dead}
										}
										{state
											{state inactive}
										}
										{state
											{state user_control}
										}
										{prop
											{prop human}
										}
										{prop
											{prop cannon}
										}
										{tag
											{tag _ai_tank_alert_cooldown}
										}
									
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
								}
							}
							{enemy
								{source advanced}
								{group
									{include
										{state
											{state operatable}
										}
										{state
											{state user_control}
										}
									}
									{exclude
										{prop
											{prop airborne}
										}
										{prop
											{prop captor}
										}
										{tag
											{tag _bot}
										}
										{tag
											{tag bot}
										}
									}
								}
							}
							{distance
								{mode near_than}
								{meters %r2}
							}
							{tag
								{"tag pair"}
								{"for selector" _ai_tank_range_%r1_alert}
								{"for enemy" _ai_tank_range_%r1_target}
							}
						}
					}
				}
				{actions
					{"delay"
						{time 0.5}
					}
					{"actor_state"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag _ai_tank_range_%r1_alert}
									}
								}
								{exclude
									{tag
										{tag _ai_tank_alert_cooldown}
									}
								
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
							}
						}
						{drop orders}
						{fire_mode open}
						{move_mode zone}
						{move_radius 20}
					}
					{"delay"
						{time 0.1}
					}
					{"effect"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag _ai_tank_range_%r1_alert}
									}
								}
								{exclude
									{tag
										{tag _ai_tank_alert_cooldown}
									}
								
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
							}
						}
						{effect ai_tank_alert_cooldown}
					}
					{"delay"
						{time 0.5}
					}
					{"action"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag _ai_tank_range_%r1_alert}
									}
								}
								{exclude
									
								
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
							}
						}
						{action rotate}
						{target
							{source advanced}
							{group
								{select
									{tag
										{tag _ai_tank_range_%r1_target}
									}
								}
							}
						}
					}
					{"delay"
						{time 1}
					}
					{"action"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag _ai_tank_range_%r1_alert}
									}
								}
							
{exclude {tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}}
}
						}
						{drop orders}
						{action attack}
						{target
							{tag _ai_tank_range_%r1_target}
						}
					}
					{"delay"
						{time 3}
					}
					{"actor_state"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag _ai_tank_range_%r1_alert}
									}
								}
								{exclude
									
								
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
							}
						}
						{fire_mode open}
						{move_mode hold}
					}
					{"delay"
						{time 0.1}
					}
					{"entity_state"
						{selector
							{tag _ai_tank_range_%r1_target}
						}
						{tag_remove _ai_tank_range_%r1_target}
					}
					{"delay"
						{time 0.1}
					}
					{"entity_state"
						{selector
							{tag _ai_tank_range_%r1_alert}
						}
						{tag_remove _ai_tank_range_%r1_alert}
					}
					{"delay"
						{time 1}
					}
					{"trigger"
						{name "hf tank ai/range %r1"}
					}
				}
			}
)

("ai_alert_range_antitank" r1(160) r2(170))
("ai_alert_range_antitank" r1(170) r2(180))
("ai_alert_range_antitank" r1(180) r2(190))
("ai_alert_range_antitank" r1(190) r2(200))
("ai_alert_range_antitank" r1(200) r2(210))
("ai_alert_range_antitank" r1(210) r2(220))
("ai_alert_range_antitank" r1(220) r2(230))


(define "ai_alert_range_antipersonnel"
			{"hf tank ai/range %r1"
				{condition
					{expression "2 & 3 & 4 & 5 & (1)"}
					{terms
						{"1.see_actors"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag range_%r1}
										}
									}
									{exclude
										{state
											{state dead}
										}
										{state
											{state inactive}
										}
										{state
											{state user_control}
										}
										{prop
											{prop human}
										}
										{prop
											{prop cannon}
										}
										{tag
											{tag _ai_tank_alert_cooldown}
										}
									
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
								}
							}
							{enemy
								{source advanced}
								{group
									{include
										{state
											{state operatable}
										}
										{state
											{state user_control}
										}
										{prop
											{prop human}
										}
									}
									{exclude
										{prop
											{prop airborne}
										}
										{prop
											{prop vehicle}
										}
										{prop
											{prop captor}
										}
										{tag
											{tag _bot}
										}
										{tag
											{tag bot}
										}
									}
								}
							}
							{distance
								{mode near_than}
								{meters (* 1.5 %r2)}
							}
							{tag
								{"tag pair"}
								{"for selector" _ai_tank_range_%r1_alert}
								{"for enemy" _ai_tank_range_%r1_target}
							}
						}
						{"2.cmp_i" {var "attacker_retreat_requested$"} {op "=="} {value 0}}
						{"3.cmp_i" {var "defender_retreat_requested$"} {op "=="} {value 0}}
						{"4.cmp_i" {var "bot_retreat_active$"} {op "=="} {value 0}}
						{"5.cmp_i" {var "winner_decided$"} {op "=="} {value 0}}
					}
				}
				{actions
					{"delay"
						{time 0.5}
					}
					{"switch"
						{"case"
							{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
							{"switch"
								{"case"
									{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
									{"switch"
										{"case"
											{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
											{"switch"
												{"case"
													{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
													{"actor_state"
														{selector
															{source advanced}
															{group
																{select
																	{tag
																		{tag _ai_tank_range_%r1_alert}
																	}
																}
																{exclude
																	{tag
																		{tag _ai_tank_alert_cooldown}
																	}
																
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
															}
														}
														{drop orders}
														{fire_mode open}
														{move_mode zone}
														{move_radius 20}
													}
												}
											}
										}
									}
								}
							}
						}
					}
					{"delay"
						{time 0.1}
					}
					{"switch"
						{"case"
							{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
							{"switch"
								{"case"
									{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
									{"switch"
										{"case"
											{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
											{"switch"
												{"case"
													{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
													{"effect"
														{selector
															{source advanced}
															{group
																{select
																	{tag
																		{tag _ai_tank_range_%r1_alert}
																	}
																}
																{exclude
																	{tag
																		{tag _ai_tank_alert_cooldown}
																	}
																
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
															}
														}
														{effect ai_tank_alert_cooldown}
													}
												}
											}
										}
									}
								}
							}
						}
					}
					{"delay"
						{time 0.5}
					}
					{"switch"
						{"case"
							{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
							{"switch"
								{"case"
									{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
									{"switch"
										{"case"
											{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
											{"switch"
												{"case"
													{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
													{"action"
														{selector
															{source advanced}
															{group
																{select
																	{tag
																		{tag _ai_tank_range_%r1_alert}
																	}
																}
																{exclude
																	; UFB: actor already reserved by this range task.
																
{tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}
}
															}
														}
														{action rotate}
														{target
															{source advanced}
															{group
																{select
																	{tag
																		{tag _ai_tank_range_%r1_target}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
					{"delay"
						{time 1}
					}
					{"switch"
						{"case"
							{condition {type cmp_i} {var "attacker_retreat_requested$"} {op "=="} {value 0}}
							{"switch"
								{"case"
									{condition {type cmp_i} {var "defender_retreat_requested$"} {op "=="} {value 0}}
									{"switch"
										{"case"
											{condition {type cmp_i} {var "bot_retreat_active$"} {op "=="} {value 0}}
											{"switch"
												{"case"
													{condition {type cmp_i} {var "winner_decided$"} {op "=="} {value 0}}
													{"action"
														{selector
															{source advanced}
															{group
																{select
																	{tag
																		{tag _ai_tank_range_%r1_alert}
																	}
																}
															
{exclude {tag {tag _ufb_job_reserved}}
{tag {tag _ufb_combat_busy}}
{tag {tag _ufb_healing_active}}
{tag {tag medic}}}
}
														}
														{drop orders}
														{action attack}
														{target
															{tag _ai_tank_range_%r1_target}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
					{"delay"
						{time 3}
					}
					; UFB: retain the existing 20m maneuver zone; no indefinite hold.
					{"delay"
						{time 0.1}
					}
					{"entity_state"
						{selector
							{tag _ai_tank_range_%r1_target}
						}
						{tag_remove _ai_tank_range_%r1_target}
					}
					{"delay"
						{time 0.1}
					}
					{"entity_state"
						{selector
							{tag _ai_tank_range_%r1_alert}
						}
						{tag_remove _ai_tank_range_%r1_alert}
					}
					{"delay"
						{time 1}
					}
					{"trigger"
						{name "hf tank ai/range %r1"}
					}
				}
			}
)

("ai_alert_range_antipersonnel" r1(120) r2(124))
("ai_alert_range_antipersonnel" r1(130) r2(134))
("ai_alert_range_antipersonnel" r1(140) r2(144))
("ai_alert_range_antipersonnel" r1(150) r2(154))
(include "/map/multi/ufb_crew_safety.inc")
