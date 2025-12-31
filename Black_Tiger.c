#include "huc.h"
#include "hucc-scroll.h"
#include "hucc-chrmap.h"
#include "hucc-blkmap.h"


#include "include/constants.c"
#include "include/variables.c"


#include "include/gfx_BG_INTRO.c"
#include "include/gfx_BG_LEVELS.c"
#include "include/gfx_BG_TITLE.c"
#include "include/gfx_SPRITES.c"


#include "include/tables_INTRO.c"
#include "include/tables_NPC.c"
#include "include/tables_OBJECT.c"
#include "include/tables_PLAYER.c"
#include "include/tables_SHOP.c"


#include "include/routines_INTRO.c"
#include "include/routines_LEVELS.c"
#include "include/routines_NPC.c"
#include "include/routines_SHOP.c"
#include "include/routines_TITLE.c"
#include "include/init.c"






main()
{
	if(!sgx_detect())
	{
        put_string("Halt: SGX hardware not found", 2, 13);

        for(;;)
        {
            // INFINITE LOOP //
        }
    }




    init_SYSTEM();
    
    
    init_VARIABLES();


    init_PLAYER();




    //**************************************************************************************//
    //                                                                                      //
    //                                         MAIN                                         //
    //                                                                                      //
    //**************************************************************************************//
    for(;;)
    {
        switch(sequence_id)
        {
            //-----------------------------------------------------------------------------//
            //                                    TITLE                                    //
            //-----------------------------------------------------------------------------//
            case SEQUENCE_TITLE:
                if(sequence_loaded == FALSE)
                {
                    init_TITLE();

                    sequence_loaded = TRUE;
                }

                else
                {
                    vsync();

                    joypad_BUTTONS_TITLE();
                    
                    satb_update();
                }

                break;


            //-----------------------------------------------------------------------------//
            //                                    INTRO                                    //
            //-----------------------------------------------------------------------------//
            case SEQUENCE_INTRO:
                if(sequence_loaded == FALSE)
                {
                    init_INTRO();

                    sequence_loaded = TRUE;
                }

                else
                {
                    vsync();

                    //put_number(vdc_map_pxl_x,3,0,0);
                    sequence_INTRO();
                    
                    joypad_BUTTONS_INTRO();

                    sgx_satb_update();
                }

                break;


            //-----------------------------------------------------------------------------//
            //                                    LEVEL                                    //
            //-----------------------------------------------------------------------------//
            case SEQUENCE_LEVEL:
                switch(level_id)
                {
                    case 1:
                        if(sequence_loaded == FALSE)
                        {
                            init_LEVEL();

                            sequence_loaded = TRUE;
                        }

                        else
                        {
                            //
                            while(display_level_text == TRUE)
                            {
                                vsync();
                                
                                global_counter += 1;

                                if(global_counter == 120)
                                {
                                    put_string("       ",13, 8);
                                    put_string("              ",10,13);
                                    put_string("            ",11,15);
                                    
                                    global_counter = 0;

                                    display_level_text = FALSE;
                                }
                            }

                            vsync();

                            update_PLAYER();
                            update_WEAPON();
                            //put_number(player_state,2,0,6);
                            //put_number(player_counter_attack,2,0,7);
                            //put_number(player_index_jump,2,0,8);

                        
                            scroll_object();
                            scroll_chest();
                            scroll_npc();

                            collision_PLAYER_OBJECT();
                            collision_PLAYER_NPC();

                            anim_OBJECTS();

                            display_TIME_LEVEL();

                            satb_update();
                            sgx_satb_update();

                            scroll_BG();

                            joypad_DIR();
                            joypad_BUTTONS();
                        }

                        break;


                    case 2:
                        vsync();
                        break;


                    case 3:
                        vsync();
                        break;


                    case 4:
                        vsync();
                        break;


                    case 5:
                        vsync();
                        break;

                }

                break;


            //-----------------------------------------------------------------------------//
            //                                     NPC                                     //
            //-----------------------------------------------------------------------------//
            case SEQUENCE_NPC:
                vsync();
                sequence_NPC();
                break;


            //-----------------------------------------------------------------------------//
            //                                    SHOP                                     //
            //-----------------------------------------------------------------------------//
            case SEQUENCE_SHOP:
                if(sequence_loaded == FALSE)
                {
                    init_SHOP();

                    sequence_loaded = TRUE;
                }
                
                else
                {
                    switch(shop_phase)
                    {
                        case SHOP_PHASE_ENTER:
                            vsync();

                            if(shop_counter == 0)
                            {
                                put_string("Maybe, i can sell you" ,  2 , 15);
                                put_string("something..." , 18 , 16);
                            }

                            else if(shop_counter == 120)
                            {
                                put_string("                     " ,  2 , 15);
                                put_string("            " , 18 , 16);

                                spr_x(24);
                                spr_y(144);
                                satb_update();

                                shop_phase = SHOP_PHASE_BUY;
                            }

                            shop_counter++;

                            break;
                    

                        case SHOP_PHASE_BUY:
                            vsync();

                            joypad_BUTTONS_SHOP();
                            display_TIME_SHOP();
                            satb_update();

                            break;


                        case SHOP_PHASE_EXIT:
                            vsync();

                            if(shop_counter == 0)
                            {
                                put_string("GOOD LUCK!" , 11 , 16);

                                // HIDE CURSOR //
                                spr_set(0);
                                spr_hide();
                                satb_update();
                            }

                            else if(shop_counter == 120)
                            {
                                disp_off();

                                // REINIT PLAYER //
                                init_PLAYER();

                                shop_phase = SHOP_PHASE_EXIT;
                                respawn = RESPAWN_SHOP;
                                sequence_loaded = FALSE;
                                sequence_id = SEQUENCE_LEVEL;
                            }

                            shop_counter++;

                            break;
                    }
                }

                break;
        }
    }
}

