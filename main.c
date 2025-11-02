#include "huc.h"
#include "hucc-scroll.h"
#include "hucc-chrmap.h"
#include "hucc-blkmap.h"




#include "include/constants.c"
#include "include/variables.c"




#include "include/gfx_BG.c"
#include "include/gfx_SPRITES.c"



#include "include/tables_player.c"
#include "include/routines_LEVELS.c"
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




    init_VARIABLES();


    init_PLAYER();




    //**************************************************************************************//
    //                                                                                      //
    //                                      TITLE                                           //
    //                                                                                      //
    //**************************************************************************************//
    for(;;)
    {

        if(sequence_id == SEQUENCE_TITLE)
        {

        }


        else if(sequence_id == SEQUENCE_GAME)
        {
            // LOADING LOGO SCREEN //
            if(sequence_loaded == FALSE)
            {
                init_LEVEL();

                sequence_loaded = TRUE;
            }


            else
            {
                if(level_id == 1)
                {
                    vsync();

                    update_PLAYER();
                    //put_number(player_state,1,0,0);
                    //put_number(player_pos_y,3,0,1);
                    //put_number(sgx_map_pxl_y,3,0,2);


                    joypad_DIR();
                    joypad_BUTTONS();

                    satb_update();
                    scroll_BG();
                }

                else if(level_id == 2)
                {
                    //sequence_LV2();
                }

                else if(level_id == 3)
                {
                    //sequence_LV3();
                }

                else if(level_id == 4)
                {
                    //sequence_LV4();
                }

                else if(level_id == 5)
                {
                    //sequence_LV5();
                }
            }
        }
    }


}

