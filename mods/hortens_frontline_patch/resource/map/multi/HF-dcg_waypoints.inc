			{"1007"
				{position 6284.75 6505.07 0}
				{transition "8"}
				{transition "9"}
			}
			{"1008"
				{position 1254.84 6569.14 0}
				{transition "10"}
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
				{transition "12"}
				{transition "13"}
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
				{transition "14"}
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
				{transition "16"}
				{transition "17"}
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
				{transition "18"}
				{transition "19"}
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
				{transition "20"}
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
				{transition "22"}
				{transition "26"}
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
				{transition "23"}
				{transition "25"}
			}
			{"1023"
				{position -7001.19 -4363.34 0}
				{transition "24"}
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
			
			
			{"1090"
				{position 0 0 0}
			}