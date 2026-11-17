			{"1090"
				{position 0 0 0}
			}
			{"1007"
				{position 6284.75 6505.07 0}
				{transition "1008"}
				{transition "1009"}
			}
			{"1008"
				{position 1254.84 6569.14 0}
				{transition "1010"}
			}
			{"1009"
				{position 3427.16 3885.43 0}
				{commands
					{"delay"
						{time 0.1}
					}
					{"action"
						{action advance}
						{target
							{source advanced}
							{group
								{include
									{prop
										{prop vehicle}
									}
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
								}
							}
						}
					}
					{"entity_state"
						{tag_add bot_flank_finished}
						{tag_remove bot_flanker}
					}
					{"entity_state"
						{tag_remove bot_flank_in_progress}
					}
				}
			}
			{"1010"
				{position 796.964 6234.2 0}
				{commands
					{"delay"
						{time 0.1}
					}
					{"action"
						{action advance}
						{target
							{source advanced}
							{group
								{include
									{prop
										{prop vehicle}
									}
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
								}
							}
						}
					}
					{"entity_state"
						{tag_add bot_flank_finished}
						{tag_remove bot_flanker}
					}
					{"entity_state"
						{tag_remove bot_flank_in_progress}
					}
				}
			}
			{"1011"
				{position -6963.96 -6560.69 0}
				{transition "1012"}
				{transition "1013"}
			}
			{"1012"
				{position -4029.64 -3982.66 0}
				{commands
					{"delay"
						{time 0.1}
					}
					{"action"
						{action advance}
						{target
							{source advanced}
							{group
								{include
									{prop
										{prop vehicle}
									}
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
								}
							}
						}
					}
					{"entity_state"
						{tag_add bot_flank_finished}
						{tag_remove bot_flanker}
					}
					{"entity_state"
						{tag_remove bot_flank_in_progress}
					}
				}
			}
			{"1013"
				{position -7042.24 -1130.22 0}
				{transition "1014"}
			}
			{"1014"
				{position -6541.8 -721.097 0}
				{commands
					{"delay"
						{time 0.1}
					}
					{"action"
						{action advance}
						{target
							{source advanced}
							{group
								{include
									{prop
										{prop vehicle}
									}
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
								}
							}
						}
					}
					{"entity_state"
						{tag_add bot_flank_finished}
						{tag_remove bot_flanker}
					}
					{"entity_state"
						{tag_remove bot_flank_in_progress}
					}
				}
			}
		









			{"1015"
				{position 7111.65 4467.45 0}
				{transition "1016"}
				{transition "1017"}
				{commands
					{"delay"
						{time 0.1}
					}
					{"actor_state"
						{fire_mode return}
						{movement
							{speed fast}
						}
						{ai
							{follow_commander off}
							{no_retreat on}
						}
					}
				}
			}
			{"1016"
				{position 6533.61 6598.08 0}
				{transition "1018"}
				{transition "1019"}
			}
			{"1017"
				{position 5742.54 2754.63 0}
				{commands
					{"entity_state"
						{tag_add bot_inf_flank_finished}
						{tag_remove bot_inf_flanker}
					}
					{"entity_state"
						{tag_remove bot_inf_flank_in_progress}
					}
					{"action"
						{action advance}
						{target
							{source advanced}
							{group
								{include
									{prop
										{prop vehicle}
									}
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
								}
							}
						}
					}
				}
			}
			{"1018"
				{position 4214.88 7309.49 0}
				{transition "1020"}
			}
			{"1019"
				{position 4186.26 4498.34 0}
				{commands
					{"entity_state"
						{tag_add bot_inf_flank_finished}
						{tag_remove bot_inf_flanker}
					}
					{"entity_state"
						{tag_remove bot_inf_flank_in_progress}
					}
					{"action"
						{action advance}
						{target
							{source advanced}
							{group
								{include
									{prop
										{prop vehicle}
									}
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
								}
							}
						}
					}
				}
			}
			{"1020"
				{position 2370.9 6589.88 0}
				{commands
					{"entity_state"
						{tag_add bot_inf_flank_finished}
						{tag_remove bot_inf_flanker}
					}
					{"entity_state"
						{tag_remove bot_inf_flank_in_progress}
					}
					{"action"
						{action advance}
						{target
							{source advanced}
							{group
								{include
									{prop
										{prop vehicle}
									}
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
								}
							}
						}
					}
				}
			}
			{"1021"
				{position -5154.72 -7001.04 0}
				{transition "1022"}
				{transition "1026"}
				{commands
					{"delay"
						{time 0.1}
					}
					{"actor_state"
						{fire_mode return}
						{movement
							{speed fast}
						}
						{ai
							{follow_commander off}
							{no_retreat on}
						}
					}
				}
			}
			{"1022"
				{position -6622.34 -6331.23 0}
				{transition "1023"}
				{transition "1025"}
			}
			{"1023"
				{position -7001.19 -4363.34 0}
				{transition "1024"}
			}
			{"1024"
				{position -6222.24 -2752.52 0}
				{commands
					{"entity_state"
						{tag_add bot_inf_flank_finished}
						{tag_remove bot_inf_flanker}
					}
					{"entity_state"
						{tag_remove bot_inf_flank_in_progress}
					}
					{"action"
						{action advance}
						{target
							{source advanced}
							{group
								{include
									{prop
										{prop vehicle}
									}
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
								}
							}
						}
					}
				}
			}
			{"1025"
				{position -4260.38 -3861.65 0}
				{commands
					{"entity_state"
						{tag_add bot_inf_flank_finished}
						{tag_remove bot_inf_flanker}
					}
					{"entity_state"
						{tag_remove bot_inf_flank_in_progress}
					}
					{"action"
						{action advance}
						{target
							{source advanced}
							{group
								{include
									{prop
										{prop vehicle}
									}
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
								}
							}
						}
					}
				}
			}
			{"1026"
				{position -2827.14 -6102.3 0}
				{commands
					{"entity_state"
						{tag_add bot_inf_flank_finished}
						{tag_remove bot_inf_flanker}
					}
					{"entity_state"
						{tag_remove bot_inf_flank_in_progress}
					}
					{"action"
						{action advance}
						{target
							{source advanced}
							{group
								{include
									{prop
										{prop vehicle}
									}
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
								}
							}
						}
					}
				}
			}


			{"1027"
				{position -5291.51 -7948.07 0}
				{commands
					{"delay"
						{time 0.1}
					}
					{"delete"}
				}
			}
			{"1028"
				{position 464.105 7951.37 0}
				{commands
					{"delay"
						{time 0.1}
					}
					{"delete"}
				}
			}
			{"1029"
				{position 2317.96 -7960.78 0}
				{commands
					{"delay"
						{time 0.1}
					}
					{"delete"}
				}
			}
			{"1030"
				{position 7950.16 -3969.98 0}
				{commands
					{"delay"
						{time 0.1}
					}
					{"delete"}
				}
			}
			{"1031"
				{position 7941.9 3533.83 0}
				{commands
					{"delay"
						{time 0.1}
					}
					{"delete"}
				}
			}
			{"1032"
				{position -7951.74 4048.81 0}
				{commands
					{"delay"
						{time 0.1}
					}
					{"delete"}
				}
			}
			{"1033"
				{position -7897.23 -4032.64 0}
				{commands
					{"delay"
						{time 0.1}
					}
					{"delete"}
				}
			}
			{"2000"
				{position -333.319 652.273 0}
				{transition "2001"}
				{transition "2007"}
				{transition "2013"}
				{transition "2018"}
			}
			{"2001"
				{position 30.0463 6579.23 0}
				{transition "2002"}
			}
			{"2010"
				{position 3004.08 1205.65 0}
				{transition "2011"}
			}
			{"2011"
				{position 2396.95 4701.27 0}
				{transition "2012"}
			}
			{"2012"
				{position 1444.01 5981.19 0}
				{transition "2001"}
			}
			{"2013"
				{position -6979.52 475.192 0}
				{transition "2014"}
			}
			{"2014"
				{position -6618.75 -861.741 0}
				{transition "2015"}
			}
			{"2015"
				{position -3771.28 -2753.39 0}
				{transition "2016"}
			}
			{"2016"
				{position 2820.65 -2688.46 0}
				{transition "2017"}
			}
			{"2017"
				{position 5535.65 -1320.06 0}
				{transition "2018"}
			}
			{"2018"
				{position 6184.97 633.864 0}
				{transition "2019"}
			}
			{"2019"
				{position 5267.07 2536.72 0}
				{transition "2020"}
			}
			{"2002"
				{position -1299.76 6064.16 0}
				{transition "2003"}
			}
			{"2020"
				{position 2528.36 3353.03 0}
				{transition "2021"}
			}
			{"2021"
				{position -4467.04 3334.61 0}
				{transition "2022"}
			}
			{"2022"
				{position -6733.33 1771.22 0}
				{transition "2013"}
			}
			{"2003"
				{position -2156.73 4808.71 0}
				{transition "2004"}
			}
			{"2004"
				{position -2972.73 1452.37 0}
				{transition "2005"}
			}
			{"2005"
				{position -2938.52 -1900.85 0}
				{transition "2006"}
			}
			{"2006"
				{position -2210.92 -5211.14 0}
				{transition "2007"}
			}
			{"2007"
				{position -448.615 -5997.09 0}
				{transition "2008"}
			}
			{"2008"
				{position 1603.84 -5581.87 0}
				{transition "2009"}
			}
			{"2009"
				{position 2624.31 -2461.26 0}
				{transition "2010"}
			}