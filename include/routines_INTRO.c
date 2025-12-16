#include "huc.h"
#include "hucc-scroll.h"
#include "hucc-chrmap.h"
#include "hucc-blkmap.h"








void joypad_BUTTONS_INTRO()
{
    if(joytrg(JOYPAD_1) & JOY_RUN)
    {
        // DISABLE DISPLAY //
        disp_off();

        sequence_loaded = FALSE;

        sequence_id = SEQUENCE_GAME;
    }
}




void sequence_INTRO()
{
	//--------------------------------------------------------------------------------------//
	//                                    PALETTE FADING                                    //
	//--------------------------------------------------------------------------------------//

    char i;


    if(global_counter > 0 && global_counter < 43)
    {
        if(global_counter%6 == FALSE)
        {
            read_palette( 0, 1, palette_buffer );

            cross_fade_to(palette_INTRO_2 , palette_buffer , 16 , palette_step);
            cross_fade_to(palette_INTRO_2 , palette_buffer , 16 , palette_step+1);

            load_palette( 0, palette_buffer, 1 );

            palette_step += 2;
        }
    }
   
    

	//--------------------------------------------------------------------------------------//
	//                                     MOVE DRAGON                                      //
	//--------------------------------------------------------------------------------------//

    if(global_counter < 50)
    {
        player_pos_x -= 1;
        player_pos_y -= 1;
        
        for(i=0 ; i<8 ; i++)
        {
            sgx_spr_set(i);
            sgx_spr_x(player_pos_x + (i<<5) - ((i>>2)<<7));
            sgx_spr_y(player_pos_y + ((i>>2)<<5));
        }

        //--------------------------------------------------------------------------------------//
        //                                    DRAGON PATTERN                                    //
        //--------------------------------------------------------------------------------------//

        if(global_counter == 8)
        {
            for(i=0 ; i<8 ; i++)
            {
                sgx_spr_set(i);
                sgx_spr_pattern(DRAGON_INTRO_VRAM_ADR + (i*TILES_16) + TILES_128);
            }
        }

        else if(global_counter == 16)
        {
            for(i=0 ; i<8 ; i++)
            {
                sgx_spr_set(i);
                sgx_spr_pattern(DRAGON_INTRO_VRAM_ADR + (i*TILES_16) + TILES_256);
            }
        }

        else if(global_counter == 24)
        {
            for(i=0 ; i<8 ; i++)
            {
                sgx_spr_set(i);
                sgx_spr_pattern(DRAGON_INTRO_VRAM_ADR + (i*TILES_16));
            }
        }

        else if(global_counter == 32)
        {
            for(i=0 ; i<8 ; i++)
            {
                sgx_spr_set(i);
                sgx_spr_pattern(DRAGON_INTRO_VRAM_ADR + (i*TILES_16) + TILES_128);
            }
        }

        else if(global_counter == 40)
        {
            for(i=0 ; i<8 ; i++)
            {
                sgx_spr_set(i);
                sgx_spr_pattern(DRAGON_INTRO_VRAM_ADR + (i*TILES_16) + TILES_256);
            }
        }

        else if(global_counter == 48)
        {
            for(i=0 ; i<8 ; i++)
            {
                sgx_spr_set(i);
                sgx_spr_pattern(DRAGON_INTRO_VRAM_ADR + (i*TILES_16) + TILES_384);
            }
        }
    }




	//--------------------------------------------------------------------------------------//
	//                                        BOLTS                                         //
	//--------------------------------------------------------------------------------------//

    if(global_counter == 71)
    {
        load_palette( 0, palette_INTRO_3, 1 );

        vdc_map_pxl_x = 256;
        scroll_split(0,   0, vdc_map_pxl_x & (511), vdc_map_pxl_y & (511), BKG_ON | SPR_ON);
    }

    else if(global_counter == 76)
    {
        vdc_map_pxl_x = 0;
        scroll_split(0,   0, vdc_map_pxl_x & (511), vdc_map_pxl_y & (511), BKG_ON | SPR_ON);

        load_palette( 0, palette_INTRO_2, 1 );
    }

    else if(global_counter == 136)
    {
        load_palette( 0, palette_INTRO_3, 1 );

        vdc_map_pxl_x = 256;
        scroll_split(0,   0, vdc_map_pxl_x & (511), vdc_map_pxl_y & (511), BKG_ON | SPR_ON);
    }

    else if(global_counter == 140)
    {
        vdc_map_pxl_x = 0;
        scroll_split(0,   0, vdc_map_pxl_x & (511), vdc_map_pxl_y & (511), BKG_ON | SPR_ON);
    }

    else if(global_counter == 141)
    {
        load_palette( 0, palette_INTRO_2, 1 );
    }

    else if(global_counter == 145)
    {
        vdc_map_pxl_y = 256;
        scroll_split(0,   0, vdc_map_pxl_x & (511), vdc_map_pxl_y & (511), BKG_ON | SPR_ON);

        load_palette( 0, palette_INTRO_3, 1 );
    }

    else if(global_counter == 149)
    {
        vdc_map_pxl_y = 0;
        scroll_split(0,   0, vdc_map_pxl_x & (511), vdc_map_pxl_y & (511), BKG_ON | SPR_ON);
    }

    else if(global_counter == 150)
    {
        for(i=0 ; i<8 ; i++)
        {
            sgx_spr_set(i);
            sgx_spr_hide();
        }
        
        load_palette( 0, palette_INTRO_2, 1 );
    }

    else if(global_counter == 152)
    {
        for(i=0 ; i<8 ; i++)
        {
            sgx_spr_set(i);
            sgx_spr_x(player_pos_x + (i<<5) - ((i>>2)<<7));
            sgx_spr_y(player_pos_y + ((i>>2)<<5));
        }
    }

    else if(global_counter == 154)
    {
        for(i=0 ; i<8 ; i++)
        {
            sgx_spr_set(i);
            sgx_spr_hide();
        }

        vdc_map_pxl_x = 256;
        vdc_map_pxl_y = 256;
        scroll_split(0,   0, vdc_map_pxl_x & (511), vdc_map_pxl_y & (511), BKG_ON | SPR_ON);

        load_palette( 0, palette_INTRO_3, 1 );
    }

    else if(global_counter == 156)
    {
        for(i=0 ; i<8 ; i++)
        {
            sgx_spr_set(i);
            sgx_spr_x(player_pos_x + (i<<5) - ((i>>2)<<7));
            sgx_spr_y(player_pos_y + ((i>>2)<<5));
        }
    }

    else if(global_counter == 158)
    {
        for(i=0 ; i<8 ; i++)
        {
            sgx_spr_set(i);
            sgx_spr_hide();
        }

        vdc_map_pxl_x = 0;
        vdc_map_pxl_y = 0;
        scroll_split(0,   0, vdc_map_pxl_x & (511), vdc_map_pxl_y & (511), BKG_ON | SPR_ON);
    }

    else if(global_counter == 159)
    {
        vdc_map_pxl_y = 256;
        scroll_split(0,   0, vdc_map_pxl_x & (511), vdc_map_pxl_y & (511), BKG_ON | SPR_ON);
    }

    else if(global_counter == 160)
    {
        for(i=0 ; i<8 ; i++)
        {
            sgx_spr_set(i);
            sgx_spr_x(player_pos_x + (i<<5) - ((i>>2)<<7));
            sgx_spr_y(player_pos_y + ((i>>2)<<5));
        }

        vdc_map_pxl_x = 256;
        vdc_map_pxl_y = 0;
        scroll_split(0,   0, vdc_map_pxl_x & (511), vdc_map_pxl_y & (511), BKG_ON | SPR_ON);
    }

    else if(global_counter == 162)
    {
        for(i=0 ; i<8 ; i++)
        {
            sgx_spr_set(i);
            sgx_spr_hide();
        }
    }

    else if(global_counter == 163)
    {
        vdc_map_pxl_x = 0;
        vdc_map_pxl_y = 0;
        scroll_split(0,   0, vdc_map_pxl_x & (511), vdc_map_pxl_y & (511), BKG_ON | SPR_ON);
    }

    else if(global_counter == 164)
    {
        for(i=0 ; i<8 ; i++)
        {
            sgx_spr_set(i);
            sgx_spr_x(player_pos_x + (i<<5) - ((i>>2)<<7));
            sgx_spr_y(player_pos_y + ((i>>2)<<5));
        }

        load_palette( 0, palette_INTRO_2, 1 );
    }

    else if(global_counter == 166)
    {
        for(i=0 ; i<8 ; i++)
        {
            sgx_spr_set(i);
            sgx_spr_hide();
        }
    }

    else if(global_counter == 168)
    {
        for(i=0 ; i<8 ; i++)
        {
            sgx_spr_set(i);
            sgx_spr_x(player_pos_x + (i<<5) - ((i>>2)<<7));
            sgx_spr_y(player_pos_y + ((i>>2)<<5));
        }

        vdc_map_pxl_y = 256;
        scroll_split(0,   0, vdc_map_pxl_x & (511), vdc_map_pxl_y & (511), BKG_ON | SPR_ON);
        
        load_palette( 0, palette_INTRO_3, 1 );
    }

    else if(global_counter == 170)
    {
        for(i=0 ; i<8 ; i++)
        {
            sgx_spr_set(i);
            sgx_spr_hide();
        }
    }

    else if(global_counter == 172)
    {
        for(i=0 ; i<8 ; i++)
        {
            sgx_spr_set(i);
            sgx_spr_x(player_pos_x + (i<<5) - ((i>>2)<<7));
            sgx_spr_y(player_pos_y + ((i>>2)<<5));
        }

        vdc_map_pxl_y = 0;
        scroll_split(0,   0, vdc_map_pxl_x & (511), vdc_map_pxl_y & (511), BKG_ON | SPR_ON);
    }

    else if(global_counter == 173)
    {
        load_palette( 0, palette_INTRO_2, 1 );
    }

    else if(global_counter == 174)
    {
        for(i=0 ; i<8 ; i++)
        {
            sgx_spr_set(i);
            sgx_spr_hide();
        }
    }

    else if(global_counter == 176)
    {
        for(i=0 ; i<8 ; i++)
        {
            sgx_spr_set(i);
            sgx_spr_x(player_pos_x + (i<<5) - ((i>>2)<<7));
            sgx_spr_y(player_pos_y + ((i>>2)<<5));
        }
    }

    else if(global_counter == 177)
    {
        vdc_map_pxl_x = 256;
        vdc_map_pxl_y = 256;
        scroll_split(0,   0, vdc_map_pxl_x & (511), vdc_map_pxl_y & (511), BKG_ON | SPR_ON);

        load_palette( 0, palette_INTRO_3, 1 );
    }

    else if(global_counter == 178)
    {
        for(i=0 ; i<8 ; i++)
        {
            sgx_spr_set(i);
            sgx_spr_hide();
        }
    }

    else if(global_counter == 180)
    {
        for(i=0 ; i<8 ; i++)
        {
            sgx_spr_set(i);
            sgx_spr_x(player_pos_x + (i<<5) - ((i>>2)<<7));
            sgx_spr_y(player_pos_y + ((i>>2)<<5));
        }
    }

    else if(global_counter == 181)
    {
        vdc_map_pxl_x = 0;
        vdc_map_pxl_y = 0;
        scroll_split(0,   0, vdc_map_pxl_x & (511), vdc_map_pxl_y & (511), BKG_ON | SPR_ON);

        load_palette( 0, palette_INTRO_3, 1 );
    }

    else if(global_counter == 182)
    {
        for(i=0 ; i<8 ; i++)
        {
            sgx_spr_set(i);
            sgx_spr_hide();
        }

        load_palette( 0, palette_INTRO_2, 1 );
    }

    else if(global_counter == 184)
    {
        for(i=0 ; i<8 ; i++)
        {
            sgx_spr_set(i);
            sgx_spr_x(player_pos_x + (i<<5) - ((i>>2)<<7));
            sgx_spr_y(player_pos_y + ((i>>2)<<5));
        }
    }

    else if(global_counter == 186)
    {
        for(i=0 ; i<8 ; i++)
        {
            sgx_spr_set(i);
            sgx_spr_hide();
        }

        load_palette( 0, palette_INTRO_2, 1 );
    }

    else if(global_counter == 731)
    {
        load_palette( 0, palette_BLACK, 1 );
    }




	//--------------------------------------------------------------------------------------//
	//                                     TEXT DISPLAY                                     //
	//--------------------------------------------------------------------------------------//
    
    if(global_counter > 241)
    {       
        if(letter_counter < 446)
        {
            // EVERY 2 FRAMES //
            if(letter_counter%2 == FALSE)
            {            
                put_char(TABLE_INTRO_TEXT[letter_index] , 2 + index_x , 4 + ((letter_index / 28) << 1));

                letter_index += 1;
                index_x += 1;

                if(index_x == 28)
                {
                    index_x = 0;
                }
            }
        }

        letter_counter += 1;
    }


    global_counter += 1;
}










