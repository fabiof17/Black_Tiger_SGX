#include "huc.h"
#include "hucc-scroll.h"
#include "hucc-chrmap.h"
#include "hucc-blkmap.h"








void init_VARIABLES()
{
    sequence_id = SEQUENCE_GAME;

    level_id = 1;

    sequence_loaded = FALSE;
}


init_PLAYER()
{
	player_id = 0;
	player_axis = AXIS_RIGHT;
	player_previous_axis = player_axis;
	player_counter_anim = 0;
	player_index_jump = 0;
	player_state = STATE_IDLE;
}



void init_LEVEL()
{
    if(level_id == 1)
    {
		// VSYNC //
		vsync();

        // LOAD DEFAULT FONT //
		load_default_font();




		// SET VDC 1 SCREEN SIZE (IN TILES) - 64x32 = 512x256 PIXELS
		set_screen_size(SCR_SIZE_64x32);


		// SET VDC 2 SCREEN SIZE (IN TILES) - 64x32 = 512x256 PIXELS
		sgx_set_screen_size(SCR_SIZE_64x32);


		// INIT SPRITE ATTRIBUTE TABLE //
		init_satb();




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

		// multimap is 2 screens wide //
		sgx_set_multimap( multimap_LV1_BG_B , 5 );


		//--------------------------------------------------------------------------------------//
		//                                    DRAW TILEMAP                                      //
		//--------------------------------------------------------------------------------------//

		// The blkmap is drawn using global variables for the top-left coordinate
		// in pixels, and the draw width and height in terms of 8x8 characters.

		sgx_map_pxl_x = 96;
		sgx_map_pxl_y = 512;

		sgx_map_draw_w = 63;
		sgx_map_draw_h = 29;

		sgx_draw_map();




		//**************************************************************************************//
		//                                                                                      //
		//                                        VDC 1                                         //
		//                                                                                      //
		//**************************************************************************************//

		//--------------------------------------------------------------------------------------//
		//                                    LOAD TILESET                                      //
		//--------------------------------------------------------------------------------------//

		load_vram( 0x1000, tileset_LV1_BG_A, SIZEOF(tileset_LV1_BG_A) >> 1 );


		//--------------------------------------------------------------------------------------//
		//                                 LOAD LIFABAR TILES                                   //
		//--------------------------------------------------------------------------------------//

		load_vram( LIFEBAR_1_VRAM_ADR, tileset_LIFE_RED, SIZEOF(tileset_LIFE_RED) >> 1 );
		load_vram( LIFEBAR_2_VRAM_ADR, tileset_LIFE_ORANGE, SIZEOF(tileset_LIFE_ORANGE) >> 1 );
		load_vram( LIFEBAR_3_VRAM_ADR, tileset_LIFE_YELLOW, SIZEOF(tileset_LIFE_YELLOW) >> 1 );
		load_vram( LIFEBAR_4_VRAM_ADR, tileset_LIFE_YELLOW, SIZEOF(tileset_LIFE_YELLOW) >> 1 );
		load_vram( LIFEBAR_5_VRAM_ADR, tileset_LIFE_EMPTY, SIZEOF(tileset_LIFE_EMPTY) >> 1 );


		//--------------------------------------------------------------------------------------//
		//                               LOAD WEAPON + ARMOR TILES                              //
		//--------------------------------------------------------------------------------------//

		load_vram( WEAPON_VRAM_ADR, tileset_WEAPON_1, SIZEOF(tileset_WEAPON_1) >> 1 );
		load_vram( ARMOR_VRAM_ADR, tileset_ARMOR_2, SIZEOF(tileset_ARMOR_2) >> 1 );


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

		vdc_map_draw_w = 32;
		vdc_map_draw_h = 28;

		draw_map();




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

		//--------------------------------------------------------------------------------------//
		//                                        PLAYER                                        //
		//--------------------------------------------------------------------------------------//

		// LOAD PLAYER TILES //
		// 0x2000
		// 32 TILES = 512 //
		// LOAD PLAYER FIRST FRAME OF ANIMATION (IDLE)
		load_vram(PLAYER_VRAM_ADR, tiles_SPR_PLAYER , TILES_16);


		// SELECT PLAYER CORE SPRITE //
		spr_set(player_id);


		player_pos_x = 112;
		player_pos_y = 128;


		spr_x(player_pos_x);
    	spr_y(player_pos_y);

		// SET TILES DATA FOR THE PLAYER //
		spr_pattern(PLAYER_VRAM_ADR);


		spr_ctrl(FLIP_MAS|SIZE_MAS, NO_FLIP|SZ_32x32);


		spr_pal(0);
		spr_pri(TRUE);


		// UPDATE PCE SAT //
		satb_update();




		//--------------------------------------------------------------------------------------//
		//                                LOAD SPRITES PALETTES                                 //
		//--------------------------------------------------------------------------------------//

		load_palette( 16, palette_PLAYER, 1 );




		//**************************************************************************************//
		//                                                                                      //
		//                                      VARIABLES                                       //
		//                                                                                      //
		//**************************************************************************************//

        //


		// VSYNC //
		vsync();

		// ENABLE DISPLAY //
		disp_on();
    }
}








