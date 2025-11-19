#include "huc.h"
#include "hucc-scroll.h"
#include "hucc-chrmap.h"
#include "hucc-blkmap.h"


#include "include/constants.c"
#include "include/variables.c"


#include "include/gfx_BG.c"
#include "include/gfx_SPRITES.c"


#include "include/tables_NPC.c"
#include "include/tables_OBJECT.c"
#include "include/tables_PLAYER.c"
#include "include/tables_SHOP.c"



#include "include/routines_LEVELS.c"
#include "include/routines_SHOP.c"
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
                break;


            //-----------------------------------------------------------------------------//
            //                                    INTRO                                    //
            //-----------------------------------------------------------------------------//
            case SEQUENCE_INTRO:
                break;


            //-----------------------------------------------------------------------------//
            //                                    GAME                                     //
            //-----------------------------------------------------------------------------//
            case SEQUENCE_GAME:
                if(sequence_loaded == FALSE)
                {
                    init_LEVEL();

                    sequence_loaded = TRUE;
                }


                else
                {
                    switch(level_id)
                    {
                        case 1:
                            vsync();

                            update_PLAYER();
                            
                            //put_number(onscreen_npc_number,1,0,0);

                            joypad_DIR();
                            joypad_BUTTONS();

                            scroll_object();
                            scroll_chest();
                            scroll_npc();

                            check_OBJECT();
                            check_NPC();

                            display_TIME();

                            satb_update();

                            scroll_BG();
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
                }

                break;


            //-----------------------------------------------------------------------------//
            //                                     NPC                                     //
            //-----------------------------------------------------------------------------//
            case SEQUENCE_NPC:
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
                    vsync();

                    joypad_BUTTONS_SHOP();

                    //put_number(item_index,1,0,0);

                    satb_update();
                }

                break;
        }
    }
}

