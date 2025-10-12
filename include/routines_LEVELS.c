#include "huc.h"
#include "hucc-scroll.h"
#include "hucc-chrmap.h"
#include "hucc-blkmap.h"








int calculate_COLLISION_DEEP(unsigned char x , unsigned char y)
{
    int player_COLL_X;
    int player_COLL_Y;


    player_COLL_X = player_pos_x + x;
    player_COLL_Y = player_pos_y + 32 - y;


    get_map_block(player_COLL_X + sgx_map_pxl_y, player_COLL_Y + sgx_map_pxl_y);
}


int check_WALL_R()
{
    int player_COLL_X;
    int player_COLL_Y;


    player_COLL_X = player_pos_x + 23;
    player_COLL_Y = player_pos_y + 31;


    get_map_block(player_COLL_X + sgx_map_pxl_x, player_COLL_Y + sgx_map_pxl_y);
}


int check_WALL_L()
{
    int player_COLL_X;
    int player_COLL_Y;


    player_COLL_X = player_pos_x + 8;
    player_COLL_Y = player_pos_y + 31;


    get_map_block(player_COLL_X + sgx_map_pxl_x, player_COLL_Y + sgx_map_pxl_y);
}


int check_FLOOR_R()
{
    int player_COLL_X;
    int player_COLL_Y;


    player_COLL_X = player_pos_x + 11;
    player_COLL_Y = player_pos_y + 32;


    get_map_block(player_COLL_X + sgx_map_pxl_x, player_COLL_Y + sgx_map_pxl_y);
}


int check_FLOOR_L()
{
    int player_COLL_X;
    int player_COLL_Y;


    player_COLL_X = player_pos_x + 10;
    player_COLL_Y = player_pos_y + 32;


    get_map_block(player_COLL_X + sgx_map_pxl_x, player_COLL_Y + sgx_map_pxl_y);
}








void scroll_BG()
{
        // UPDATE VDC2 BG //
        sgx_scroll_map();

        //--------------------------------------------------------------------------------------//
        //                                        VDC 2                                         //
        //--------------------------------------------------------------------------------------//

        sgx_scroll_split(0,   0, sgx_map_pxl_x & (BAT_SIZE_W - 1), sgx_map_pxl_y & (BAT_SIZE_H - 1), BKG_ON | SPR_ON);
}








void joypad_BUTTONS()
{
    if(joytrg(JOYPAD_1) == JOY_I)
    {
        if(player_state == STATE_IDLE)
        {
            load_vram(PLAYER_VRAM_ADR, tiles_SPR_PLAYER + TILES_112 , TILES_16);

            player_counter_anim = 0;

            player_state = STATE_JUMP;
        }
    }
}


void joypad_DIR()
{
    //--------------------------------------------------------------------------------------//
    //                                        NO DIR                                        //
    //--------------------------------------------------------------------------------------//

    if(! (joy(JOYPAD_1) & JOY_DIR_PRESSED) )
    {
        if(player_state == STATE_WALK || player_state == STATE_CROUCH)
        {
            // A OPTIMISER G_PREVIOUS_STATE //
            load_vram(PLAYER_VRAM_ADR, tiles_SPR_PLAYER , TILES_16);

            player_counter_anim = 0;

            player_state = STATE_IDLE;

            return;
        }
    }


    //--------------------------------------------------------------------------------------//
    //                                     RIGHT BUTTON                                     //
    //--------------------------------------------------------------------------------------//

    if(joy(JOYPAD_1) & JOY_RIGHT)
    {
        if(player_state == STATE_IDLE || player_state == STATE_WALK)
        {
            player_state = STATE_WALK;
            player_axis = AXIS_RIGHT;

            if(player_previous_axis != player_axis)
            {
                player_previous_axis = player_axis;

                spr_set(player_id);
                spr_ctrl(FLIP_MAS, NO_FLIP_X);
            }
        }


        else if(player_state == STATE_JUMP)
        {
            if(player_axis == AXIS_LEFT)
            {
                player_axis = AXIS_RIGHT;
                player_previous_axis = player_axis;

                spr_set(player_id);
                spr_ctrl(FLIP_MAS, NO_FLIP_X);
            }
        }


        else if(player_state == STATE_CROUCH)
        {
            if(player_axis == AXIS_LEFT)
            {
                player_axis = AXIS_RIGHT;
                player_previous_axis = player_axis;

                spr_set(player_id);
                spr_ctrl(FLIP_MAS, NO_FLIP_X);
            }
        }
    }


    //--------------------------------------------------------------------------------------//
    //                                     LEFT BUTTON                                      //
    //--------------------------------------------------------------------------------------//

    else if(joy(JOYPAD_1) & JOY_LEFT)
    {
        if(player_state == STATE_IDLE || player_state == STATE_WALK)
        {
            player_state = STATE_WALK;
            player_axis = AXIS_LEFT;

            if(player_previous_axis != player_axis)
            {
                player_previous_axis = player_axis;

                spr_set(player_id);
                spr_ctrl(FLIP_MAS, FLIP_X);
            }
        }


        else if(player_state == STATE_JUMP)
        {
            if(player_axis == AXIS_RIGHT)
            {
                player_axis = AXIS_LEFT;
                player_previous_axis = player_axis;

                spr_set(player_id);
                spr_ctrl(FLIP_MAS, FLIP_X);
            }
        }


        else if(player_state == STATE_CROUCH)
        {
            if(player_axis == AXIS_RIGHT)
            {
                player_axis = AXIS_LEFT;
                player_previous_axis = player_axis;

                spr_set(player_id);
                spr_ctrl(FLIP_MAS, FLIP_X);
            }
        }
    }


    //--------------------------------------------------------------------------------------//
    //                                      UP BUTTON                                       //
    //--------------------------------------------------------------------------------------//

    else if(joy(JOYPAD_1) & JOY_UP)
    {
        //
    }


    //--------------------------------------------------------------------------------------//
    //                                     DOWN BUTTON                                      //
    //--------------------------------------------------------------------------------------//

    else if(joy(JOYPAD_1) & JOY_DOWN)
    {
        if(player_state == STATE_IDLE || player_state == STATE_WALK)
        {
            player_state = STATE_CROUCH;

            load_vram(PLAYER_VRAM_ADR, tiles_SPR_PLAYER + TILES_128 , TILES_16);
        }
    }
}




void update_PLAYER()
{
    if(player_state == STATE_WALK)
    {
        if(player_axis == AXIS_RIGHT)
        {
            // CHECK COLLISION WITH FLOOR //
            check_FLOOR_R();

            if(map_blk_flag == TILE_EMPTY)
            {
                player_counter_anim = 0;

                player_state = STATE_FALL;

                return;
            }



            // CHECK COLLISION WITH WALLS //
            check_WALL_R();

            if(map_blk_flag == TILE_EMPTY)
            {
                sgx_map_pxl_x += 2;

                vdc_map_pxl_x = sgx_map_pxl_x;

                scroll_BG();
            }
        }


        else if(player_axis == AXIS_LEFT)
        {
            // CHECK COLLISION WITH FLOOR //
            check_FLOOR_L();

            if(map_blk_flag == TILE_EMPTY)
            {
                player_counter_anim = 0;

                player_state = STATE_FALL;

                return;
            }


            // CHECK COLLISION WITH BG //
            check_WALL_L();

            if(map_blk_flag == TILE_EMPTY)
            {
                sgx_map_pxl_x -= 2;

                vdc_map_pxl_x = sgx_map_pxl_x;

                scroll_BG();
            }
        }




        spr_set(player_id);


        // UPDATE PLAYER TILES //
        if(player_counter_anim == 0)
        {
            load_vram(PLAYER_VRAM_ADR, tiles_SPR_PLAYER , TILES_16);
        }


        else if(player_counter_anim == 2)
        {
            load_vram(PLAYER_VRAM_ADR, tiles_SPR_PLAYER + TILES_16 , TILES_16);
        }


        else if(player_counter_anim == 5)
        {
            load_vram(PLAYER_VRAM_ADR, tiles_SPR_PLAYER + TILES_32 , TILES_16);
        }


        else if(player_counter_anim == 8)
        {
            load_vram(PLAYER_VRAM_ADR, tiles_SPR_PLAYER + TILES_48 , TILES_16);
        }


        else if(player_counter_anim == 11)
        {
            load_vram(PLAYER_VRAM_ADR, tiles_SPR_PLAYER , TILES_16);
        }


        else if(player_counter_anim == 14)
        {
            load_vram(PLAYER_VRAM_ADR, tiles_SPR_PLAYER + TILES_64 , TILES_16);
        }


        else if(player_counter_anim == 17)
        {
            load_vram(PLAYER_VRAM_ADR, tiles_SPR_PLAYER + TILES_80 , TILES_16);
        }


        else if(player_counter_anim == 20)
        {
            load_vram(PLAYER_VRAM_ADR, tiles_SPR_PLAYER + TILES_96 , TILES_16);
        }


        else if(player_counter_anim == 22)
        {
            player_counter_anim = 0;

            return;
        }


        player_counter_anim += 1;

    }


    else if(player_state == STATE_JUMP)
    {
        unsigned char i;
        i = 0;


        spr_set(player_id);
        player_pos_y += TABLE_PLAYER_JUMP_V[player_index_jump];
        spr_y(player_pos_y);



        if(player_index_jump < 34)
        {
            player_index_jump += 1;
        }


        // CHECK COLLISION WITH FLOOR //
        if(player_axis == AXIS_RIGHT)
        {
            check_FLOOR_R();
        }

        else
        {
            check_FLOOR_L();
        }


        if(map_blk_flag == TILE_BG)
        {
            // CALCULATE HOW MANY PIXELS THE PLAYER MOVED INTO THE GROUND //
            for(i=1; i<11 ; i++ )
            {
                if(player_axis == AXIS_RIGHT)
                {
                    calculate_COLLISION_DEEP( 11 , i);
                }

                else
                {
                    calculate_COLLISION_DEEP( 10 , i);
                }


                if(map_blk_flag == TILE_EMPTY)
                {
                    load_vram(PLAYER_VRAM_ADR, tiles_SPR_PLAYER , TILES_16);

                    player_pos_y -= (i - 1);
                    spr_y(player_pos_y);

                    break;
                }

            }


            load_vram(PLAYER_VRAM_ADR, tiles_SPR_PLAYER , TILES_16);

            player_counter_anim = 0;
            player_index_jump = 0;

            player_state = STATE_IDLE;

            return;
        }
    }


    else if(player_state == STATE_FALL)
    {
        //
    }
}
