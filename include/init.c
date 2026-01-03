#include "huc.h"
#include "hucc-scroll.h"
#include "hucc-chrmap.h"
#include "hucc-blkmap.h"








void init_SYSTEM()
{
	// DISABLE DISPLAY //
	disp_off();

	// VSYNC //
	vsync();

	// LOAD DEFAULT FONT //
	load_default_font();


	// SET VDC 1 SCREEN SIZE (IN TILES) - 32x32 = 256 PIXELS
	set_screen_size(SCR_SIZE_32x32);


	// SET VDC 2 SCREEN SIZE (IN TILES) - 32x32 = 256 PIXELS
	sgx_set_screen_size(SCR_SIZE_32x32);


	// INIT SPRITE ATTRIBUTE TABLE //
	init_satb();
	sgx_init_satb();


	// ENABLE DISPLAY //
	//disp_on();
}


void init_VARIABLES()
{
    sequence_id = SEQUENCE_TITLE; // SEQUENCE_TITLE | SEQUENCE_INTRO | SEQUENCE_LEVEL | SEQUENCE_SHOP

	letter_index = 0;

    level_id = 1;
	display_level_text = TRUE;

	life_amount = 3;
	credits_amount = 2;
	key_amount = 0;
	potion_amount = 0;
	zenny_amount = 0;

	weapon_level = 0;
	armor_level = 2;
	
	player_naked = FALSE;

	selected_npc = 0;
	index_x = 0;
	index_y = 0;
	item_index = 0;
	shop_counter = 0;
	shop_phase = SHOP_PHASE_ENTER;

	respawn = FALSE;

    sequence_loaded = FALSE;
}


void init_PLAYER()
{
	if(player_naked != RESPAWN_SHOP)
	{
		player_naked = FALSE;
	}
	
	player_id = PLAYER_START_INDEX;
	player_axis = AXIS_RIGHT;
	player_previous_axis = player_axis;
	player_counter_anim = 0;
	player_index_jump = 0;
	player_index_fall = 0;
	fall_ladder = FALSE;
	player_counter_attack = 0;
	player_attack = FALSE;
	player_state = STATE_IDLE;

	chain_id = player_id - 3;
}








void init_TITLE()
{
	// DISABLE DISPLAY //
	disp_off();
	

	// VSYNC //
	vsync();


	// SET VDC 1 SCREEN SIZE (IN TILES) - 64x64 = 256 PIXELS
	set_screen_size(SCR_SIZE_32x32);

	// SET VDC 2 SCREEN SIZE (IN TILES) - 32x32 = 512 PIXELS
	//sgx_set_screen_size(SCR_SIZE_32x32);




	//**************************************************************************************//
	//                                                                                      //
	//                                        VDC 1                                         //
	//                                                                                      //
	//**************************************************************************************//

	//--------------------------------------------------------------------------------------//
	//                                      LOAD FONT                                       //
	//--------------------------------------------------------------------------------------//

	load_vram( 0x0800, tileset_FONT_TITLE, SIZEOF(tileset_FONT_TITLE) >> 1 );

	set_font_pal(15);



	//--------------------------------------------------------------------------------------//
	//                                    LOAD TILEMAP                                      //
	//--------------------------------------------------------------------------------------//

	load_vram( 0x0000, tilemap_TITLE_BG_B, SIZEOF(tilemap_TITLE_BG_B) >> 1 );

	//--------------------------------------------------------------------------------------//
	//                                    LOAD TILESET                                      //
	//--------------------------------------------------------------------------------------//

	load_vram( 0x1000, tileset_TITLE_BG_B, SIZEOF(tileset_TITLE_BG_B) >> 1 );




	//put_string("PRESS RUN"   , 11 , 18);
	put_string("START GAME"  	, 11 , 18);

	put_string("LIFE"        	, 11 , 20);
	put_number(life_amount   	,  1 , 20 , 20);

	put_string("CREDITS"		, 11 , 21);
	put_number(credits_amount   ,  1 , 20 , 21);

	put_string("CAPCOM 1987" 	, 11 , 26);




	//--------------------------------------------------------------------------------------//
	//                                   LOAD BG PALETTES                                   //
	//--------------------------------------------------------------------------------------//

	load_palette( 0, palette_TITLE, 16 );




	//**************************************************************************************//
	//                                                                                      //
	//                                       SPRITES                                        //
	//                                                                                      //
	//**************************************************************************************//

	//--------------------------------------------------------------------------------------//
	//                                        CURSOR                                        //
	//--------------------------------------------------------------------------------------//

	// LOAD CURSOR TILES //
	load_vram(0x2000, tiles_SPR_SELECTOR , SIZEOF(tiles_SPR_SELECTOR) >> 1 );


	// SELECT CURSOR SPRITE //
	spr_set(0);


	spr_x(72);
	spr_y(144);

	// SET TILES DATA FOR THE CURSOR //
	spr_pattern(0x2000);


	spr_ctrl(FLIP_MAS|SIZE_MAS, NO_FLIP|SZ_16x16);


	spr_pal(16);
	spr_pri(TRUE);


	//--------------------------------------------------------------------------------------//
	//                                LOAD SPRITES PALETTES                                 //
	//--------------------------------------------------------------------------------------//

	load_palette( 16, palette_objects_2, 1 );




	// UPDATE PCE SAT //
	satb_update();




	// VSYNC //
	vsync();

	// ENABLE DISPLAY //
	disp_on();
}





void init_INTRO()
{
	char i;
	
	// DISABLE DISPLAY //
	disp_off();
	

	// VSYNC //
	vsync();


	// SET VDC 1 SCREEN SIZE (IN TILES) - 64x64 = 256 PIXELS
	set_screen_size(SCR_SIZE_64x64);

	// SET VDC 2 SCREEN SIZE (IN TILES) - 32x32 = 256 PIXELS
	sgx_set_screen_size(SCR_SIZE_32x32);




	//**************************************************************************************//
	//                                                                                      //
	//                                      VARIABLES                                       //
	//                                                                                      //
	//**************************************************************************************//

	global_counter = 1;

	vdc_map_pxl_x = 0;
	vdc_map_pxl_y = 0;




	//**************************************************************************************//
	//                                                                                      //
	//                                        VDC 1                                         //
	//                                                                                      //
	//**************************************************************************************//

	//--------------------------------------------------------------------------------------//
	//                                    LOAD TILEMAP                                      //
	//--------------------------------------------------------------------------------------//

	load_vram( 0x0000, tilemap_INTRO_BG_A, SIZEOF(tilemap_INTRO_BG_A) >> 1 );

	//--------------------------------------------------------------------------------------//
	//                                    LOAD TILESET                                      //
	//--------------------------------------------------------------------------------------//

	load_vram( 0x1000, tileset_INTRO_BG_A, SIZEOF(tileset_INTRO_BG_A) >> 1 );


	//--------------------------------------------------------------------------------------//
	//                                    SCROLL SPLIT                                      //
	//--------------------------------------------------------------------------------------//

	scroll_split(0,   0, vdc_map_pxl_x & (511), vdc_map_pxl_y & (511), BKG_ON | SPR_ON);




	//--------------------------------------------------------------------------------------//
	//                                      LOAD FONT                                       //
	//--------------------------------------------------------------------------------------//

	set_font_addr(0x3000);
	load_vram( 0x3000, tileset_FONT_INTRO, SIZEOF(tileset_FONT_INTRO) >> 1 );

	set_font_pal(15);



	//**************************************************************************************//
	//                                                                                      //
	//                                        VDC 2                                         //
	//                                                                                      //
	//**************************************************************************************//

	//--------------------------------------------------------------------------------------//
	//                                    LOAD TILEMAP                                      //
	//--------------------------------------------------------------------------------------//

	sgx_load_vram( 0x0000, tilemap_INTRO_BG_B, SIZEOF(tilemap_INTRO_BG_B) >> 1 );

	//--------------------------------------------------------------------------------------//
	//                                    LOAD TILESET                                      //
	//--------------------------------------------------------------------------------------//

	sgx_load_vram( 0x1000, tileset_INTRO_BG_B, SIZEOF(tileset_INTRO_BG_B) >> 1 );




	//--------------------------------------------------------------------------------------//
	//                                   LOAD BG PALETTES                                   //
	//--------------------------------------------------------------------------------------//

	// STORES DESTINATION PALETTE FOR FADE //
	load_palette( 0, palette_INTRO_1, 1 );
	load_palette( 15, palette_FONT_INTRO, 1 );




	//**************************************************************************************//
	//                                                                                      //
	//                                       SPRITES                                        //
	//                                                                                      //
	//**************************************************************************************//

	// HIDE CURSOR SPRITE FROM TITLE SCREEN //
	spr_set(0);
	spr_hide();

	//--------------------------------------------------------------------------------------//
	//                                        DRAGON                                        //
	//--------------------------------------------------------------------------------------//

	player_pos_x = 113;
	player_pos_y = 81;

	// LOAD DRAGON TILES //
	sgx_load_vram(DRAGON_INTRO_VRAM_ADR, tiles_SPR_DRAGON_INTRO , SIZEOF(tiles_SPR_DRAGON_INTRO) >> 1);


	for(i=0 ; i<8 ; i++)
	{
		sgx_spr_set(i);
		sgx_spr_x(player_pos_x + (i*32) - ((i>>2)*128));
		sgx_spr_y(player_pos_y + ((i>>2)*32));
		sgx_spr_pattern(DRAGON_INTRO_VRAM_ADR + (i*TILES_16));
		sgx_spr_ctrl(FLIP_MAS|SIZE_MAS, NO_FLIP|SZ_32x32);
		sgx_spr_pal(16);
		sgx_spr_pri(FALSE);
	}
	

	//--------------------------------------------------------------------------------------//
	//                                LOAD SPRITES PALETTES                                 //
	//--------------------------------------------------------------------------------------//

	load_palette( 16, palette_SPR_DRAGON_INTRO, 1 );



	// UPDATE SGX SAT //
	sgx_satb_update();

	// UPDATE PCE SAT //
	satb_update();


	// VSYNC //
	vsync();

	// ENABLE DISPLAY //
	disp_on();
}







void load_OBJECT_TILES()
{
	sgx_load_vram(POT1_VRAM_ADR, tiles_SPR_POT , SIZEOF(tiles_SPR_POT) >> 1);
	sgx_load_vram(POW_VRAM_ADR, tiles_SPR_POW , TILES_4);
	sgx_load_vram(GRAY_KEY_VRAM_ADR, tiles_SPR_GRAY_KEY , TILES_4);
	//sgx_load_vram(GOLD_KEY_VRAM_ADR, tiles_SPR_GOLD_KEY , TILES_4);
	//sgx_load_vram(LIFE_VRAM_ADR, tiles_SPR_LIFE , TILES_4);
	sgx_load_vram(COIN_1_VRAM_ADR, tiles_SPR_COIN_1 , TILES_4);
	sgx_load_vram(COIN_5_VRAM_ADR, tiles_SPR_COIN_5 , TILES_4);
	sgx_load_vram(COIN_10_VRAM_ADR, tiles_SPR_COIN_10 , TILES_4);
	sgx_load_vram(COIN_50_VRAM_ADR, tiles_SPR_COIN_50 , TILES_4);
	sgx_load_vram(COIN_100_VRAM_ADR, tiles_SPR_COIN_100 , TILES_4);
	sgx_load_vram(COIN_500_VRAM_ADR, tiles_SPR_COIN_500 , TILES_4);
	sgx_load_vram(COIN_1000_VRAM_ADR, tiles_SPR_COIN_1000 , TILES_4);
	sgx_load_vram(STAR_VRAM_ADR, tiles_SPR_STAR , TILES_4);
	sgx_load_vram(OCTOPUS_VRAM_ADR, tiles_SPR_OCTOPUS , TILES_4);
	sgx_load_vram(FRUIT_VRAM_ADR, tiles_SPR_FRUIT , TILES_4);
	sgx_load_vram(BARREL_VRAM_ADR, tiles_SPR_BARREL , TILES_4);
	sgx_load_vram(HOURGLASS_VRAM_ADR, tiles_SPR_HOURGLASS , TILES_4);
	sgx_load_vram(BAMBOO_VRAM_ADR, tiles_SPR_BAMBOO , TILES_4);
	sgx_load_vram(YASHICHI_VRAM_ADR, tiles_SPR_YASHICHI , TILES_4);
	sgx_load_vram(ELEPHANT_VRAM_ADR, tiles_SPR_ELEPHANT , TILES_4);
	sgx_load_vram(DRAGONFLY_VRAM_ADR, tiles_SPR_DRAGONFLY , TILES_4);
	sgx_load_vram(COW_VRAM_ADR, tiles_SPR_COW , TILES_4);
	sgx_load_vram(MOBICHAN_VRAM_ADR, tiles_SPR_MOBICHAN , TILES_4);
}


void load_CHEST_TILES()
{
	sgx_load_vram(CHEST_VRAM_ADR, tiles_SPR_CHEST , SIZEOF(tiles_SPR_CHEST) >> 1);
}


void load_NPC_TILES()
{
	sgx_load_vram(NPC_1_VRAM_ADR, tiles_SPR_NPC , SIZEOF(tiles_SPR_NPC) >> 1);
}


void init_OBJECT_LV1()
{
	signed char i;

	for(i=0 ; i<level_object_number ; i++)
	{
		// SET OBJECT PROPERTIES //
		list_object_type[i] = TABLE_OBJECT_TYPE_LV1[i];
		list_object_x_pos_ref[i] = TABLE_OBJECT_X_POS_REF_LV1[i];
		list_object_y_pos_ref[i] = TABLE_OBJECT_Y_POS_REF_LV1[i];
		list_object_x_pos[i] = -16;
		list_object_y_pos[i] = -16;
		
		// IF THE PLAYERS ENTERS THE LEVEL FOR THE 1RST TIME //
		// ALL OBJECTS ARE ACTIVE //
		if(respawn == FALSE)
		{
			list_object_state[i] = STATE_ACTIVE;
		}


		// SET OBJECT SPRITE //
		sgx_spr_set(i + object_start_index);
		sgx_spr_x(list_object_x_pos[i]);
		sgx_spr_y(list_object_y_pos[i]);
		sgx_spr_pri(TRUE);


		if(list_object_type[i] == TYPE_HOURGLASS)
		{
			list_object_energy[i] = 0;
			sgx_spr_pal(18);
			sgx_spr_pattern(HOURGLASS_VRAM_ADR);
			sgx_spr_ctrl(FLIP_MAS|SIZE_MAS, NO_FLIP|SZ_16x16);
		}

		else if(list_object_type[i] == TYPE_POT)
		{
			list_object_energy[i] = 2;
			sgx_spr_pal(17);
			sgx_spr_pattern(POT1_VRAM_ADR);
			sgx_spr_ctrl(FLIP_MAS|SIZE_MAS, NO_FLIP|SZ_16x16);
		}

		else if(list_object_type[i] == TYPE_POW)
		{
			list_object_energy[i] = 0;
			sgx_spr_pal(18);
			sgx_spr_pattern(POW_VRAM_ADR);
			sgx_spr_ctrl(FLIP_MAS|SIZE_MAS, NO_FLIP|SZ_16x16);
		}
	}
}


void init_CHEST_LV1()
{
	signed char i;

	for(i=0 ; i<level_chest_number ; i++)
	{
		// SET CHEST PROPERTIES //
		list_chest_x_pos_ref[i] = TABLE_CHEST_X_POS_REF_LV1[i];
		list_chest_y_pos_ref[i] = TABLE_CHEST_Y_POS_REF_LV1[i];
		list_chest_x_pos[i] = -32;
		list_chest_y_pos[i] = -32;

		if(respawn == FALSE)
		{
			list_chest_state[i] = STATE_ACTIVE;
		}


		// SET CHEST SPRITE //
		sgx_spr_set(i + chest_start_index);
		sgx_spr_x(list_chest_x_pos[i]);
		sgx_spr_y(list_chest_y_pos[i]);
		sgx_spr_pri(TRUE);


		sgx_spr_pal(18);
		sgx_spr_pattern(CHEST_VRAM_ADR);
		sgx_spr_ctrl(FLIP_MAS|SIZE_MAS, NO_FLIP|SZ_32x32);
	}
}


void init_NPC_LV1()
{
	signed char i;

	for(i=0 ; i<level_npc_number ; i++)
	{
		// SET NPC PROPERTIES //
		list_npc_type[i] = TABLE_NPC_TYPE_LV1[i];
		list_npc_x_pos_ref[i] = TABLE_NPC_X_POS_REF_LV1[i];
		list_npc_y_pos_ref[i] = TABLE_NPC_Y_POS_REF_LV1[i];
		list_npc_reward[i] = TABLE_NPC_REWARD_LV1[i];
		list_npc_x_pos[i] = -32;
		list_npc_y_pos[i] = -32;

		if(respawn == FALSE)
		{
			list_npc_state[i] = STATE_ACTIVE;
		}


		// SET NPC SPRITE //
		sgx_spr_set(i + npc_start_index);
		sgx_spr_x(list_npc_x_pos[i]);
		sgx_spr_y(list_npc_y_pos[i]);
		sgx_spr_pri(TRUE);


		sgx_spr_pal(17);
		sgx_spr_pattern(NPC_1_VRAM_ADR);
		sgx_spr_ctrl(FLIP_MAS|SIZE_MAS, NO_FLIP|SZ_32x32);
	}
}






void init_HUD()
{
	//**************************************************************************************//
	//                                                                                      //
	//                                        VDC 1                                         //
	//                                                                                      //
	//**************************************************************************************//

	//--------------------------------------------------------------------------------------//
	//                                      LOAD FONT                                       //
	//--------------------------------------------------------------------------------------//

	set_font_addr(0x0800);

	load_vram( 0x0800, tileset_FONT_TITLE, SIZEOF(tileset_FONT_TITLE) >> 1 );

	set_font_pal(15);


	//--------------------------------------------------------------------------------------//
	//                                    LOAD TILESET                                      //
	//--------------------------------------------------------------------------------------//

	load_vram( 0x1000, tileset_HUD, SIZEOF(tileset_HUD) >> 1 );


	//--------------------------------------------------------------------------------------//
	//                                 LOAD LIFEBAR TILES                                   //
	//--------------------------------------------------------------------------------------//

	load_vram( LIFEBAR_1_VRAM_ADR, tileset_LIFE_RED, SIZEOF(tileset_LIFE_RED) >> 1 );
	load_vram( LIFEBAR_2_VRAM_ADR, tileset_LIFE_ORANGE, SIZEOF(tileset_LIFE_ORANGE) >> 1 );
	load_vram( LIFEBAR_3_VRAM_ADR, tileset_LIFE_YELLOW, SIZEOF(tileset_LIFE_YELLOW) >> 1 );
	load_vram( LIFEBAR_4_VRAM_ADR, tileset_LIFE_YELLOW, SIZEOF(tileset_LIFE_YELLOW) >> 1 );
	load_vram( LIFEBAR_5_VRAM_ADR, tileset_LIFE_EMPTY, SIZEOF(tileset_LIFE_EMPTY) >> 1 );


	//--------------------------------------------------------------------------------------//
	//                               LOAD WEAPON + ARMOR TILES                              //
	//--------------------------------------------------------------------------------------//

	if(weapon_level == 1)
	{
		load_vram( WEAPON_ICON_VRAM_ADR, tileset_WEAPON_1, SIZEOF(tileset_WEAPON_1) >> 1 );
	}

	else if(weapon_level == 2)
	{
		load_vram( WEAPON_ICON_VRAM_ADR, tileset_WEAPON_2, SIZEOF(tileset_WEAPON_2) >> 1 );
	}

	else if(weapon_level == 3)
	{
		load_vram( WEAPON_ICON_VRAM_ADR, tileset_WEAPON_4, SIZEOF(tileset_WEAPON_4) >> 1 );
	}

	else if(weapon_level == 4)
	{
		load_vram( WEAPON_ICON_VRAM_ADR, tileset_WEAPON_5, SIZEOF(tileset_WEAPON_5) >> 1 );
	}

	else if(weapon_level == 5)
	{
		load_vram( WEAPON_ICON_VRAM_ADR, tileset_WEAPON_8, SIZEOF(tileset_WEAPON_8) >> 1 );
	}




	if(armor_level == 1)
	{
		load_vram( ARMOR_VRAM_ADR, tileset_ARMOR_1, SIZEOF(tileset_ARMOR_1) >> 1 );
	}

	else if(armor_level == 2)
	{
		load_vram( ARMOR_VRAM_ADR, tileset_ARMOR_2, SIZEOF(tileset_ARMOR_2) >> 1 );
	}

	else if(armor_level == 3)
	{
		load_vram( ARMOR_VRAM_ADR, tileset_ARMOR_4, SIZEOF(tileset_ARMOR_4) >> 1 );
	}

	else if(armor_level == 4)
	{
		load_vram( ARMOR_VRAM_ADR, tileset_ARMOR_8, SIZEOF(tileset_ARMOR_8) >> 1 );
	}




	//--------------------------------------------------------------------------------------//
	//                                     SET MULTIMAP                                     //
	//--------------------------------------------------------------------------------------//

	// multimap is 2 screens wide //
	set_multimap( multimap_LV1_BG_A , 5 );


	//--------------------------------------------------------------------------------------//
	//                                    DRAW TILEMAP                                      //
	//--------------------------------------------------------------------------------------//

	// The blkmap is drawn using global variables for the top-left coordinate
	// in pixels, and the draw width and height in terms of 8x8 characters.

	vdc_map_pxl_x = 0;
	vdc_map_pxl_y = 0;

	vdc_map_draw_w = 64;//32
	vdc_map_draw_h = 32;//28

	draw_map();


	//**************************************************************************************//
	//                                                                                      //
	//                                  SETUP SCROLL_SPLIT                                  //
	//                                                                                      //
	//**************************************************************************************//

	//--------------------------------------------------------------------------------------//
	//                                        VDC 1                                         //
	//--------------------------------------------------------------------------------------//

	scroll_split(0,   0, 0,  0, BKG_ON | SPR_ON);
	scroll_split(1,  48, 0, 48, BKG_ON | SPR_ON);
	scroll_split(2,  80, 0, 80, BKG_ON | SPR_ON);


	display_LIFE();
	display_SCORE();
	display_TIME_LEVEL();
	display_KEY();
	display_POTION();
	display_ZENNY();
}


void init_LEVEL()
{
    if(level_id == 1)
    {
		char i;
		
		// VSYNC //
		vsync();


		// DISABLE DISPLAY //
		disp_off();


		// SET VDC 1 SCREEN SIZE (IN TILES) - 64x32 = 512x256 PIXELS
		set_screen_size(SCR_SIZE_64x32);


		// SET VDC 2 SCREEN SIZE (IN TILES) - 64x32 = 512x256 PIXELS
		sgx_set_screen_size(SCR_SIZE_64x32);


		// INIT SPRITE ATTRIBUTE TABLE //
		//init_satb();




		//**************************************************************************************//
		//                                                                                      //
		//                                      VARIABLES                                       //
		//                                                                                      //
		//**************************************************************************************//

		time_counter = 0;
		
		if(respawn == RESPAWN_SHOP)
		{
			minutes = minutes_backup;
			seconds = seconds_backup;
		}

		else
		{
			minutes = 1;
			seconds = 59;
		}

		global_counter			= 0;
		camera_max_y_position	= 768;
		score					= 0;
		level_object_number		= OBJECT_NUMBER_LV1;
		level_chest_number		= CHEST_NUMBER_LV1;
		level_npc_number		= NPC_NUMBER_LV1;
		object_start_index		= OBJECT_START_INDEX_LV1;
		chest_start_index		= CHEST_START_INDEX_LV1;
		npc_start_index			= NPC_START_INDEX_LV1;
		jump_ladder				= FALSE;

		//
		ptr_REWARD_TYPE     	= TABLE_REWARD_TYPE_LV1;
		ptr_REWARD_VRAM_ADR 	= TABLE_REWARD_VRAM_ADR_LV1;



		//**************************************************************************************//
		//                                                                                      //
		//                                        VDC 2                                         //
		//                                                                                      //
		//**************************************************************************************//

		//--------------------------------------------------------------------------------------//
		//                                    LOAD TILESET                                      //
		//--------------------------------------------------------------------------------------//

		sgx_load_vram( 0x1000, tileset_LV1_BG_B, SIZEOF(tileset_LV1_BG_B) >> 1 );


		//--------------------------------------------------------------------------------------//
		//                               LOAD WALL & DOOR TILES                                 //
		//--------------------------------------------------------------------------------------//

		sgx_load_vram( LV1_WALL_VRAM_ADR, tileset_LV1_WALL, SIZEOF(tileset_LV1_WALL) >> 1 );
		sgx_load_vram( LV1_DOOR_VRAM_ADR, tileset_LV1_DOOR_OPEN, SIZEOF(tileset_LV1_DOOR_OPEN) >> 1 );


		//--------------------------------------------------------------------------------------//
		//                                     SET MULTIMAP                                     //
		//--------------------------------------------------------------------------------------//

		// multimap is 5 screens wide //
		sgx_set_multimap( multimap_LV1_BG_B , 5 );


		//--------------------------------------------------------------------------------------//
		//                                    DRAW TILEMAP                                      //
		//--------------------------------------------------------------------------------------//

		// The blkmap is drawn using global variables for the top-left coordinate
		// in pixels, and the draw width and height in terms of 8x8 characters.

		if(respawn == FALSE)
		{
			sgx_map_pxl_x = 96;
			sgx_map_pxl_y = 768;
		}

		else if(respawn == RESPAWN_SHOP)
		{
			sgx_map_pxl_x = camera_pos_x_backup;
			sgx_map_pxl_y = camera_pos_y_backup;
		}


		sgx_map_draw_w = 63;
		sgx_map_draw_h = 29;

		sgx_draw_map();




		//**************************************************************************************//
		//                                                                                      //
		//                                         HUD                                          //
		//                                                                                      //
		//**************************************************************************************//

		init_HUD();


		if(display_level_text == TRUE)
		{
			put_string("ROUND",13, 8);
			put_number(level_id,1,19,8);
			put_string("READY PLAYER 1",10,13);
			put_string("SAVE   LIVES",11,15);
			put_number(life_amount,1,16,15);
		}


		


		//**************************************************************************************//
		//                                                                                      //
		//                                  SETUP SCROLL_SPLIT                                  //
		//                                                                                      //
		//**************************************************************************************//

		//--------------------------------------------------------------------------------------//
		//                                        VDC 2                                         //
		//--------------------------------------------------------------------------------------//

		sgx_scroll_map();

		sgx_scroll_split(0,   0, sgx_map_pxl_x & (BAT_SIZE_W - 1), sgx_map_pxl_y & (BAT_SIZE_H - 1), BKG_ON | SPR_ON);




		//--------------------------------------------------------------------------------------//
		//                                   LOAD BG PALETTES                                   //
		//--------------------------------------------------------------------------------------//

		// LOAD ALL PALETTES AT BG PALETTE 0 //
		load_palette( 0, palette_LV1, 16 );




		//**************************************************************************************//
		//                                                                                      //
		//                                       SPRITES                                        //
		//                                                                                      //
		//**************************************************************************************//

		// HIDE DRAGON SPRITES FROM INTRO //
		for(i=0 ; i<8 ; i++)
		{
			sgx_spr_set(i);
			sgx_spr_hide();
		}

		//--------------------------------------------------------------------------------------//
		//                                        PLAYER                                        //
		//--------------------------------------------------------------------------------------//

		// LOAD ALL PLAYER TILES //
	    set_far_base(TABLE_PLAYER_TILES_BANK[player_naked],TABLE_PLAYER_TILES_ADR[player_naked]);
        far_load_vram(PLAYER_VRAM_ADR,TILES_400);


		// SELECT PLAYER CORE SPRITE //
		spr_set(player_id); // PLAYER_START_INDEX


		player_pos_x = 112;
		player_pos_y = PLAYER_BASE_Y_POS;


		spr_x(player_pos_x);
    	spr_y(player_pos_y);

		// SET TILES DATA FOR THE PLAYER //
		spr_pattern(PLAYER_VRAM_ADR);

		// SET SPRITE FLIP //
		spr_ctrl(FLIP_MAS|SIZE_MAS, NO_FLIP|SZ_32x32);

		


		spr_pal(0);
		spr_pri(TRUE);


		//--------------------------------------------------------------------------------------//
		//                                        CHAIN                                         //
		//--------------------------------------------------------------------------------------//

		load_vram(CHAIN_VRAM_ADR, tiles_SPR_CHAIN , TILES_4);

		for(i=0 ; i<3 ; i++)
		{
			spr_set(chain_id+i);
			spr_pattern(CHAIN_VRAM_ADR);
			spr_ctrl(FLIP_MAS|SIZE_MAS, NO_FLIP|SZ_16x16);
			spr_hide();

			spr_pal(0);
			spr_pri(TRUE);
		}
		

		//--------------------------------------------------------------------------------------//
		//                                        WEAPON                                        //
		//--------------------------------------------------------------------------------------//

		if(weapon_level == 0)
		{
			load_vram(WEAPON_VRAM_ADR, tiles_SPR_WEAPON_0 , SIZEOF(tiles_SPR_WEAPON_0) >> 1);
		}

		else if(weapon_level == 1)
		{
			load_vram(WEAPON_VRAM_ADR, tiles_SPR_WEAPON_1 , SIZEOF(tiles_SPR_WEAPON_1) >> 1);
		}

		else if(weapon_level == 2)
		{
			load_vram(WEAPON_VRAM_ADR, tiles_SPR_WEAPON_2 , SIZEOF(tiles_SPR_WEAPON_2) >> 1);
		}

		else if(weapon_level == 3)
		{
			load_vram(WEAPON_VRAM_ADR, tiles_SPR_WEAPON_3 , SIZEOF(tiles_SPR_WEAPON_3) >> 1);
		}

		else if(weapon_level == 4)
		{
			load_vram(WEAPON_VRAM_ADR, tiles_SPR_WEAPON_4 , SIZEOF(tiles_SPR_WEAPON_4) >> 1);
		}		

		
		weapon_id = chain_id-1;
		spr_set(weapon_id);
		spr_pattern(WEAPON_VRAM_ADR);
		spr_ctrl(FLIP_MAS|SIZE_MAS, NO_FLIP|SZ_16x16);

		spr_x(player_pos_x+8);
		spr_y(player_pos_y+16);
		spr_pri(TRUE);

		// WEAPON 4 USES PAL2
		if(weapon_level == 4)
		{
			spr_pal(2);
		}
		// ALL OTHERS USE PAL0
		else
		{
			spr_pal(0);
		}
				
		


		//--------------------------------------------------------------------------------------//
		//                                       OBJECTS                                        //
		//--------------------------------------------------------------------------------------//

		load_OBJECT_TILES();
		init_OBJECT_LV1();
		scroll_object();


		//--------------------------------------------------------------------------------------//
		//                                        CHESTS                                        //
		//--------------------------------------------------------------------------------------//

		load_CHEST_TILES();
		init_CHEST_LV1();
		scroll_chest();


		//--------------------------------------------------------------------------------------//
		//                                         NPCS                                         //
		//--------------------------------------------------------------------------------------//

		load_NPC_TILES();
		init_NPC_LV1();




		//--------------------------------------------------------------------------------------//
		//                                       ENEMIES                                        //
		//--------------------------------------------------------------------------------------//

		load_vram(ORC_VRAM_ADR, tiles_SPR_ORC , SIZEOF(tiles_SPR_ORC) >> 1);
		load_vram(SERPENT_VRAM_ADR, tiles_SPR_SERPENT , TILES_96);
		load_vram(PLANT_VRAM_ADR, tiles_SPR_PLANT , TILES_160);




		// UPDATE PCE SAT //
		satb_update();

		// UPDATE SGX SAT //
		sgx_satb_update();


		//--------------------------------------------------------------------------------------//
		//                                LOAD SPRITES PALETTES                                 //
		//--------------------------------------------------------------------------------------//

		if(armor_level == 8)
		{
			load_palette( 16, palette_PLAYER_8, 1 );
		}

		else if(armor_level == 5)
		{
			load_palette( 16, palette_PLAYER_5, 1 );
		}

		else if(armor_level == 4)
		{
			load_palette( 16, palette_PLAYER_4, 1 );
		}

		else
		{
			load_palette( 16, palette_PLAYER_1, 1 );
		}


		load_palette( 17, palette_objects_1,   1 );
		load_palette( 18, palette_objects_2,   1 );
		load_palette( 19, palette_SPR_ORC,  1 );
		load_palette( 20, palette_SPR_PLANT,   1 );




		// VSYNC //
		vsync();

		// ENABLE DISPLAY //
		disp_on();
    }
}


void init_SHOP()
{
	char i;
	char item_id;


	// DISABLE DISPLAY //
	disp_off();
	

	// VSYNC //
	vsync();


	// HIDE ALL LEVEL SPRITES //
	hide_LEVEL_SPRITES();


	// SET VDC 1 SCREEN SIZE (IN TILES) - 32x32 = 256 PIXELS
	set_screen_size(SCR_SIZE_64x32);


	// SET VDC 2 SCREEN SIZE (IN TILES) - 32x32 = 256 PIXELS
	sgx_set_screen_size(SCR_SIZE_32x32);




	//**************************************************************************************//
	//                                                                                      //
	//                                      VARIABLES                                       //
	//                                                                                      //
	//**************************************************************************************//

	index_x = 0;
	index_y = 0;
	item_index = 0;

	minutes = 0;
	seconds = 30;

	shop_counter = 0;
	shop_phase = SHOP_PHASE_ENTER;

	if(level_id == 1)
	{
		ptr_SHOP_ITEM_PRICES = &TABLE_SHOP_PRICES_LV1[0];
	}
	




	//**************************************************************************************//
	//                                                                                      //
	//                                        VDC 2                                         //
	//                                                                                      //
	//**************************************************************************************//

	//--------------------------------------------------------------------------------------//
	//                                      LOAD FONT                                       //
	//--------------------------------------------------------------------------------------//

	load_vram( 0x0800, tileset_FONT, SIZEOF(tileset_FONT) >> 1 );

	set_font_pal(15);


	//--------------------------------------------------------------------------------------//
	//                                    LOAD TILESET                                      //
	//--------------------------------------------------------------------------------------//

	sgx_load_vram( 0x1000, tileset_SHOP_BG_B, SIZEOF(tileset_SHOP_BG_B) >> 1 );


	//--------------------------------------------------------------------------------------//
	//                                      LOAD ITEMS                                      //
	//--------------------------------------------------------------------------------------//

	for(i=0 ; i<10 ; i++)
	{
		set_far_base(TABLE_SHOP_ITEMS_TILES_BANK[i],TABLE_SHOP_ITEMS_TILES_ADR[i]);
		sgx_far_load_vram( 0x1000 + (i * TILES_4), TILES_4 );
	}


	//--------------------------------------------------------------------------------------//
	//                                      SET BLOCKS                                      //
	//--------------------------------------------------------------------------------------//

	sgx_set_blocks( blocks_SHOP_BG_B , tilemap_mask , 256 );



	//--------------------------------------------------------------------------------------//
	//                                       SET MAP                                        //
	//--------------------------------------------------------------------------------------//

	sgx_set_blkmap( map_SHOP_BG_B, COUNTOF(map_SHOP_BG_B) );


	//--------------------------------------------------------------------------------------//
	//                                    DRAW TILEMAP                                      //
	//--------------------------------------------------------------------------------------//

	// The blkmap is drawn using global variables for the top-left coordinate
	// in pixels, and the draw width and height in terms of 8x8 characters.

	sgx_map_pxl_x = 0;
	sgx_map_pxl_y = 0;

	sgx_map_draw_w = 32;
	sgx_map_draw_h = 28;


	//**************************************************************************************//
	//                                                                                      //
	//                                  SETUP SCROLL_SPLIT                                  //
	//                                                                                      //
	//**************************************************************************************//

	sgx_draw_map();

	sgx_scroll_split(0,   0, sgx_map_pxl_x & (BAT_SIZE_W - 1), sgx_map_pxl_y & (BAT_SIZE_H - 1), BKG_ON | SPR_ON);




	//**************************************************************************************//
	//                                                                                      //
	//                                         HUD                                          //
	//                                                                                      //
	//**************************************************************************************//

	init_HUD();




	//--------------------------------------------------------------------------------------//
	//                                     DRAW PRICES                                      //
	//--------------------------------------------------------------------------------------//

	shop_prices[0] = *(ptr_SHOP_ITEM_PRICES);
	shop_prices[1] = *(ptr_SHOP_ITEM_PRICES+1);
	shop_prices[2] = *(ptr_SHOP_ITEM_PRICES+2);
	shop_prices[3] = *(ptr_SHOP_ITEM_PRICES+3);
	shop_prices[4] = *(ptr_SHOP_ITEM_PRICES+4);
	
	shop_prices[5] = *(ptr_SHOP_ITEM_PRICES+5);
	shop_prices[6] = *(ptr_SHOP_ITEM_PRICES+6);
	shop_prices[7] = *(ptr_SHOP_ITEM_PRICES+7);
	shop_prices[8] = *(ptr_SHOP_ITEM_PRICES+8);
	shop_prices[9] = *(ptr_SHOP_ITEM_PRICES+9);


	put_number(shop_prices[0],4,2,20);
	put_number(shop_prices[1],4,7,20);
	put_number(shop_prices[2],4,12,20);
	put_number(shop_prices[3],4,17,20);
	put_number(shop_prices[4],4,22,20);

	put_number(shop_prices[5],4,2,23);
	put_number(shop_prices[6],4,7,23);
	put_number(shop_prices[7],4,12,23);
	put_number(shop_prices[8],4,17,23);
	put_number(shop_prices[9],4,22,23);




	//--------------------------------------------------------------------------------------//
	//                                   LOAD BG PALETTES                                   //
	//--------------------------------------------------------------------------------------//

	load_palette( 0, palette_SHOP, 16 );




	//**************************************************************************************//
	//                                                                                      //
	//                                       SPRITES                                        //
	//                                                                                      //
	//**************************************************************************************//

	//--------------------------------------------------------------------------------------//
	//                                   HIDE ALL SPRITES                                   //
	//--------------------------------------------------------------------------------------//

	for(i=0 ; i<63 ; i++)
	{
		spr_set(i);
		spr_hide();

		sgx_spr_set(i);
		sgx_spr_hide();
	}

	//--------------------------------------------------------------------------------------//
	//                                        CURSOR                                        //
	//--------------------------------------------------------------------------------------//

	// LOAD CURSOR TILES //
	load_vram(0x2000, tiles_SPR_CURSOR , TILES_16);


	// SELECT CURSOR SPRITE //
	spr_set(0);
	spr_hide();


	//spr_x(24);
	//spr_y(144);

	// SET TILES DATA FOR THE CURSOR //
	spr_pattern(0x2000);


	spr_ctrl(FLIP_MAS|SIZE_MAS, NO_FLIP|SZ_32x32);


	spr_pal(16);
	spr_pri(TRUE);


	// UPDATE PCE SAT //
	satb_update();
	sgx_satb_update();



	//--------------------------------------------------------------------------------------//
	//                                LOAD SPRITES PALETTES                                 //
	//--------------------------------------------------------------------------------------//

	load_palette( 16, palette_objects_2, 1 );



	// VSYNC //
	vsync();

	// ENABLE DISPLAY //
	disp_on();
}



