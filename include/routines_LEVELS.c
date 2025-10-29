#include "huc.h"
#include "hucc-scroll.h"
#include "hucc-chrmap.h"
#include "hucc-blkmap.h"








int check_BG(signed char x_offset , signed char y_offset)
{
    int player_COLL_X;
    int player_COLL_Y;


    player_COLL_X = player_pos_x + x_offset;
    player_COLL_Y = player_pos_y + 32 - y_offset;//32

    get_map_block(player_COLL_X + sgx_map_pxl_x, player_COLL_Y + sgx_map_pxl_y);
}


int check_WALL_TR()
{
    int player_COLL_X;
    int player_COLL_Y;


    player_COLL_X = player_pos_x + 24;
    player_COLL_Y = player_pos_y + 15;


    get_map_block(player_COLL_X + sgx_map_pxl_x, player_COLL_Y + sgx_map_pxl_y);
}


int check_WALL_TL()
{
    int player_COLL_X;
    int player_COLL_Y;


    player_COLL_X = player_pos_x + 8;
    player_COLL_Y = player_pos_y + 15;


    get_map_block(player_COLL_X + sgx_map_pxl_x, player_COLL_Y + sgx_map_pxl_y);
}


int check_WALL_BR()
{
    int player_COLL_X;
    int player_COLL_Y;


    player_COLL_X = player_pos_x + 24;
    player_COLL_Y = player_pos_y + 31;


    get_map_block(player_COLL_X + sgx_map_pxl_x, player_COLL_Y + sgx_map_pxl_y);
}


int check_WALL_BL()
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
    player_COLL_Y = player_pos_y + 32;//32


    get_map_block(player_COLL_X + sgx_map_pxl_x, player_COLL_Y + sgx_map_pxl_y);
}


int check_FLOOR_L()
{
    int player_COLL_X;
    int player_COLL_Y;


    player_COLL_X = player_pos_x + 10;
    player_COLL_Y = player_pos_y + 32;//32


    get_map_block(player_COLL_X + sgx_map_pxl_x, player_COLL_Y + sgx_map_pxl_y);
}


int check_LADDER(unsigned char x_offset , unsigned char y_offset)
{
    int player_COLL_X;
    int player_COLL_Y;


    player_COLL_X = player_pos_x + x_offset;
    player_COLL_Y = player_pos_y + y_offset;


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


void recenter_CAMERA()
{
    signed char camera_y_move;

    spr_set(player_id);


    if(player_pos_y < 128)
    {
        player_pos_y += CAMERA_RECENTER_VELOCITY;

        if(player_pos_y > 128)
        {
            //camera_y_move = (128 - player_pos_y);
            camera_y_move = (player_pos_y - 128);

            player_pos_y = 128;
        }

        else
        {
            camera_y_move = CAMERA_RECENTER_VELOCITY;
        }

        spr_y(player_pos_y);

        sgx_map_pxl_y -= camera_y_move;
    }


    else if(player_pos_y > 128)
    {
        player_pos_y -= CAMERA_RECENTER_VELOCITY;

        if(player_pos_y < 128)
        {
            //camera_y_move = (player_pos_y - 128);
            camera_y_move = (128 - player_pos_y);

            player_pos_y = 128;
        }

        else
        {
            camera_y_move = CAMERA_RECENTER_VELOCITY;
        }

        spr_y(player_pos_y);

        sgx_map_pxl_y += camera_y_move;
    }
}








void joypad_BUTTONS()
{
    if(joytrg(JOYPAD_1) == JOY_I)
    {
        if(player_state == STATE_IDLE)
        {
            player_counter_anim = 0;

            player_state = STATE_JUMP;
        }


        else if(player_state == STATE_WALK)
        {
            player_counter_anim = 0;

            player_state = STATE_JUMP_RIGHT + player_axis;
        }


        else if(player_state == STATE_HANG || player_state == STATE_CLIMB_UP || player_state == STATE_CLIMB_DOWN)
        {
            if(joy(JOYPAD_1) & JOY_RIGHT)
            {
                player_counter_anim = 0;

                player_state = STATE_JUMP_RIGHT;
            }

            else if(joy(JOYPAD_1) & JOY_LEFT)
            {
                player_counter_anim = 0;

                player_state = STATE_JUMP_LEFT;
            }

            else if(joy(JOYPAD_1) & JOY_UP)
            {
                player_counter_anim = 0;

                check_LADDER( 15 , 8 );

                if(map_blk_flag == TILE_EMPTY)
                {
                    player_state = STATE_JUMP_LADDER;
                }
            }
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
            player_counter_anim = 1;
            player_state = STATE_IDLE;
        }


        else if(player_state == STATE_CLIMB_UP || player_state == STATE_CLIMB_DOWN)
        {
            player_counter_anim = 1;
            player_state = STATE_HANG;
        }
    }


    //--------------------------------------------------------------------------------------//
    //                                     RIGHT BUTTON                                     //
    //--------------------------------------------------------------------------------------//

    if(joy(JOYPAD_1) & JOY_RIGHT)
    {
        if(player_state == STATE_IDLE || player_state == STATE_WALK)
        {
            player_axis = AXIS_RIGHT;

            if(player_previous_axis != player_axis)
            {
                player_previous_axis = player_axis;

                spr_set(player_id);
                spr_ctrl(FLIP_MAS, NO_FLIP_X);
            }

            if(joy(JOYPAD_1) & JOY_DOWN)
            {
                player_counter_anim = 1;
                player_state = STATE_CROUCH;
                return;
            }

            player_state = STATE_WALK;
        }


        else if(player_state == STATE_JUMP || player_state == STATE_JUMP_LEFT || player_state == STATE_CROUCH || player_state == STATE_FALL || player_state == STATE_HANG)
        {
            if(player_axis == AXIS_LEFT)
            {
                player_axis = AXIS_RIGHT;
                player_previous_axis = player_axis;

                spr_set(player_id);
                spr_ctrl(FLIP_MAS, NO_FLIP_X);
            }
        }


        else if(player_state == STATE_CLIMB_UP || player_state == STATE_CLIMB_DOWN)
        {
            player_counter_anim = 1;
            player_state = STATE_HANG;
        }
    }


    //--------------------------------------------------------------------------------------//
    //                                     LEFT BUTTON                                      //
    //--------------------------------------------------------------------------------------//

    else if(joy(JOYPAD_1) & JOY_LEFT)
    {
        if(player_state == STATE_IDLE || player_state == STATE_WALK)
        {
            player_axis = AXIS_LEFT;

            if(player_previous_axis != player_axis)
            {
                player_previous_axis = player_axis;

                spr_set(player_id);
                spr_ctrl(FLIP_MAS, FLIP_X);
            }

            if(joy(JOYPAD_1) & JOY_DOWN)
            {
                player_counter_anim = 1;
                player_state = STATE_CROUCH;
                return;
            }

            player_state = STATE_WALK;
        }


        else if(player_state == STATE_JUMP || player_state == STATE_JUMP_RIGHT || player_state == STATE_CROUCH || player_state == STATE_FALL || player_state == STATE_HANG)
        {
            if(player_axis == AXIS_RIGHT)
            {
                player_axis = AXIS_LEFT;
                player_previous_axis = player_axis;

                spr_set(player_id);
                spr_ctrl(FLIP_MAS, FLIP_X);
            }
        }


        else if(player_state == STATE_CLIMB_UP || player_state == STATE_CLIMB_DOWN)
        {
            player_counter_anim = 1;
            player_state = STATE_HANG;
        }
    }


    //--------------------------------------------------------------------------------------//
    //                                      UP BUTTON                                       //
    //--------------------------------------------------------------------------------------//

    else if(joy(JOYPAD_1) & JOY_UP)
    {
       if(player_state == STATE_HANG || player_state == STATE_CLIMB_UP || player_state == STATE_CLIMB_DOWN)
        {
            unsigned char i;

            check_LADDER( 15 , 8 );

            if(map_blk_flag == TILE_EMPTY)
            {
                for(i=1 ; i<3 ; i++)
                {
                    check_LADDER( 15 , 8 + i );

                    if(map_blk_flag == TILE_LADDER)
                    {
                        sgx_map_pxl_y -= (2 - i);
                        break;
                    }
                }
            }

            else
            {
                sgx_map_pxl_y -= 2;
            }

            player_state = STATE_CLIMB_UP;
        }
    }


    //--------------------------------------------------------------------------------------//
    //                                     DOWN BUTTON                                      //
    //--------------------------------------------------------------------------------------//

    else if(joy(JOYPAD_1) & JOY_DOWN)
    {
        if(player_state == STATE_IDLE || player_state == STATE_WALK)
        {
            player_counter_anim = 1;
            player_state = STATE_CROUCH;
        }


        else if(player_state == STATE_HANG || player_state == STATE_CLIMB_UP || player_state == STATE_CLIMB_DOWN)
        {
            unsigned char i;

            check_LADDER( 15 , 10 );

            if(map_blk_flag == TILE_EMPTY)
            {
                for(i=1 ; i<3 ; i++)
                {
                    check_LADDER( 15 , 22 + i );

                    if(map_blk_flag == TILE_LADDER)
                    {
                        sgx_map_pxl_y += (2 - i);
                        break;
                    }

                    else
                    {
                        load_vram(PLAYER_VRAM_ADR, tiles_SPR_PLAYER + TILES_224 , TILES_16);

                        jump_ladder = FALSE;
                        player_index_jump = 0;
                        player_state = STATE_FALL;
                    }
                }
            }

            else
            {
                sgx_map_pxl_y += 2;
                player_state = STATE_CLIMB_DOWN;
            }
        }
    }
}








void update_PLAYER()
{
    if(player_state == STATE_IDLE)
    {
        if(player_counter_anim == 1)
        {
            load_vram(PLAYER_VRAM_ADR, tiles_SPR_PLAYER , TILES_16);

            player_counter_anim = 0;
        }

        recenter_CAMERA();
    }


    else if(player_state == STATE_WALK)
    {
        recenter_CAMERA();


        if(player_axis == AXIS_RIGHT)
        {
            // CHECK COLLISION WITH FLOOR //
            check_FLOOR_L();

            if(map_blk_flag == TILE_EMPTY)
            {
                load_vram(PLAYER_VRAM_ADR, tiles_SPR_PLAYER , TILES_16);

                jump_ladder = FALSE;
                player_index_jump = 0;
                player_state = STATE_FALL;
            }



            // CHECK COLLISION WITH WALLS //
            check_WALL_BR();
            put_number(map_blk_flag,3,0,0);
            if(map_blk_flag == TILE_EMPTY)
            {
                sgx_map_pxl_x += 2;
            }
        }


        else if(player_axis == AXIS_LEFT)
        {
            // CHECK COLLISION WITH FLOOR //
            check_FLOOR_R();

            if(map_blk_flag == TILE_EMPTY)
            {
                load_vram(PLAYER_VRAM_ADR, tiles_SPR_PLAYER , TILES_16);

                jump_ladder = FALSE;
                player_index_jump = 0;
                player_state = STATE_FALL;
            }


            // CHECK COLLISION WITH BG //
            check_WALL_BL();

            if(map_blk_flag == TILE_EMPTY)
            {
                sgx_map_pxl_x -= 2;
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
            load_vram(PLAYER_VRAM_ADR, tiles_SPR_PLAYER + OFFSET_PLAYER_WALK_1 , TILES_16);
        }


        else if(player_counter_anim == 5)
        {
            load_vram(PLAYER_VRAM_ADR, tiles_SPR_PLAYER + OFFSET_PLAYER_WALK_2 , TILES_16);
        }


        else if(player_counter_anim == 8)
        {
            load_vram(PLAYER_VRAM_ADR, tiles_SPR_PLAYER + OFFSET_PLAYER_WALK_3 , TILES_16);
        }


        else if(player_counter_anim == 11)
        {
            load_vram(PLAYER_VRAM_ADR, tiles_SPR_PLAYER , TILES_16);
        }


        else if(player_counter_anim == 14)
        {
            load_vram(PLAYER_VRAM_ADR, tiles_SPR_PLAYER + OFFSET_PLAYER_WALK_4 , TILES_16);
        }


        else if(player_counter_anim == 17)
        {
            load_vram(PLAYER_VRAM_ADR, tiles_SPR_PLAYER + OFFSET_PLAYER_WALK_5 , TILES_16);
        }


        else if(player_counter_anim == 20)
        {
            load_vram(PLAYER_VRAM_ADR, tiles_SPR_PLAYER + OFFSET_PLAYER_WALK_6 , TILES_16);
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
        i = 1;


        if(player_counter_anim == 0)
        {
            load_vram(PLAYER_VRAM_ADR, tiles_SPR_PLAYER + TILES_112 , TILES_16);

            player_counter_anim = 1;
        }


        player_pos_y += TABLE_PLAYER_JUMP_V[player_index_jump];

        spr_set(player_id);
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
                    check_BG( 11 , i);
                }

                else
                {
                    check_BG( 10 , i);
                }


                if(map_blk_flag == TILE_EMPTY)
                {
                    load_vram(PLAYER_VRAM_ADR, tiles_SPR_PLAYER , TILES_16);

                    player_pos_y -= (i - 1);
                    spr_y(player_pos_y);
                    break;
                }

            }

            player_counter_anim = 1;
            player_index_jump = 0;
            player_state = STATE_IDLE;
            return;
        }


        // CHECK COLLISION WITH LADDERS //
        check_LADDER( 16 , 16 );

        // IF PLAYER HITS THE LADDER //
        if(map_blk_flag == TILE_LADDER)
        {
            // CAMERA GOES 8 PX BACKWARD //
            sgx_map_pxl_x = ( (sgx_map_pxl_x >> 3) << 3 );

            // SO WE UPDATE THE MAP //
            sgx_scroll_map();

            // CHECK IF THE PLAYER STANDS RIGHT TO THE LADDER //
            check_LADDER( 31 , 16 );

            if(map_blk_flag == TILE_LADDER)
            {
                sgx_map_pxl_x += 8;
            }

            player_counter_anim = 1;
            player_index_jump = 0;
            jump_ladder = TRUE;
            player_state = STATE_HANG;
        }
    }


    else if(player_state == STATE_JUMP_RIGHT)
    {
        unsigned char i, camera_y_move;
        i = 1;


        // UPDATE PLAYER TILES //
        if(player_counter_anim == 0)
        {
            load_vram(PLAYER_VRAM_ADR, tiles_SPR_PLAYER + TILES_112 , TILES_16);

            player_counter_anim = 1;
        }


        // SELECT PLAYER SPRITE //
        spr_set(player_id);


		//--------------------------------------------------------------------------------------//
		//                                        H MOVE                                        //
		//--------------------------------------------------------------------------------------//

        check_WALL_BR();

        if(map_blk_flag != TILE_BG)
        {
            check_WALL_TR();

            if(map_blk_flag == TILE_BG)
            {
                check_BG( 15 , -16 );

                if(map_blk_flag == TILE_EMPTY)
                {
                    jump_ladder = FALSE;
                    player_index_fall = 0;
                    player_state = STATE_FALL;
                    //put_number(8,1,0,0);
                    return;
                }
            }

            else
            {
                sgx_map_pxl_x += 2;
            }
        }

        else
        {
            check_BG( 15 , -16 );

            if(map_blk_flag == TILE_EMPTY)
            {
                jump_ladder = FALSE;
                player_index_fall = 0;
                player_state = STATE_FALL;
                //put_number(map_blk_flag,1,0,1);
                return;
            }
        }


		//--------------------------------------------------------------------------------------//
		//                                        V MOVE                                        //
		//--------------------------------------------------------------------------------------//

        // UPDATE PLAYER Y POSITION //
        if(jump_ladder == FALSE)
        {
            player_pos_y += TABLE_PLAYER_JUMP_V[player_index_jump];
        }

        else
        {
            player_pos_y += TABLE_PLAYER_JUMP_LADDER[player_index_jump];
        }



        // IF PLAYER GOES BELOW ITS BASE Y POSITION //
        if(player_pos_y >= PLAYER_BASE_Y_POS)
        {
            // THE CAMERA MOVES //
            // CALCULATE HOW MANY PIXELS THE CAMERA HAS TO MOVE DOWN //
            camera_y_move = player_pos_y - PLAYER_BASE_Y_POS;
            sgx_map_pxl_y += camera_y_move;

            // IF THE CAMERA HAS REACHED ITS MAX (LOWEST) POSITION //
            if(sgx_map_pxl_y > camera_max_y_position)
            {
                // THE CAMERA CAN NOT MOVE LOWER //
                sgx_map_pxl_y = camera_max_y_position;
            }

            // THE PLAYER STAYS AT ITS BASE Y POSITION //
            player_pos_y = PLAYER_BASE_Y_POS;

            spr_y(player_pos_y);
        }


        // UPDATE JUMP INDEX IN THE ARRAY //
        if(player_index_jump < jump_max_index)
        {
            player_index_jump += 1;
        }


        // CHECK COLLISION WITH THE FLOOR //
        check_FLOOR_L();


        if(map_blk_flag == TILE_BG)
        {
            // CALCULATE HOW MANY PIXELS THE PLAYER MOVED INTO THE GROUND //
            for(i=1; i<11 ; i++)
            {
                if(player_axis == AXIS_RIGHT)
                {
                    check_BG( 11 , i);
                }

                else
                {
                    check_BG( 10 , i);
                }


                if(map_blk_flag == TILE_EMPTY)
                {
                    if(player_pos_y != PLAYER_BASE_Y_POS)
                    {
                        player_pos_y -= (i - 1);
                    }

                    else
                    {
                        sgx_map_pxl_y -= (i - 1);
                    }

                    break;
                }
            }

            // SET PLAYER SPRITE NEW POSITION //
            spr_y(player_pos_y);

            player_counter_anim = 1;
            player_index_jump = 0;
            jump_ladder = FALSE;
            jump_max_index = 34;
            player_state = STATE_IDLE;
            return;
        }


        // CHECK COLLISION WITH LADDERS //
        if(player_index_jump > 4)
        {
            check_LADDER( 16 , 16 );

            // IF PLAYER HITS THE LADDER //
            if(map_blk_flag == TILE_LADDER)
            {
                // CAMERA GOES 8 PX BACKWARD //
                sgx_map_pxl_x = ( (sgx_map_pxl_x >> 3) << 3 );

                // SO WE UPDATE THE MAP //
                sgx_scroll_map();

                // CHECK IF THE PLAYER STANDS RIGHT TO THE LADDER //
                check_LADDER( 31 , 16 );

                if(map_blk_flag == TILE_LADDER)
                {
                    sgx_map_pxl_x += 8;
                }

                player_counter_anim = 1;
                player_index_jump = 0;
                jump_ladder = TRUE;
                jump_max_index = 29;
                player_state = STATE_HANG;
            }
        }


        // SET PLAYER SPRITE NEW POSITION //
        spr_y(player_pos_y);
    }


    else if(player_state == STATE_JUMP_LEFT)
    {
        unsigned char i, camera_y_move;
        i = 1;


        // UPDATE PLAYER TILES //
        if(player_counter_anim == 0)
        {
            load_vram(PLAYER_VRAM_ADR, tiles_SPR_PLAYER + TILES_112 , TILES_16);

            player_counter_anim = 1;
        }


        // SELECT PLAYER SPRITE //
        spr_set(player_id);


		//--------------------------------------------------------------------------------------//
		//                                        H MOVE                                        //
		//--------------------------------------------------------------------------------------//

        check_WALL_BL();

        if(map_blk_flag != TILE_BG)
        {
            check_WALL_TL();

            if(map_blk_flag == TILE_BG)
            {
                check_BG( 15 , -16 );

                if(map_blk_flag == TILE_EMPTY)
                {
                    jump_ladder = FALSE;
                    player_index_fall = 0;
                    player_state = STATE_FALL;
                    return;
                }
            }

            else
            {
                sgx_map_pxl_x -= 2;
            }
        }

        else
        {
            check_BG( 15 , -16 );

            if(map_blk_flag == TILE_EMPTY)
            {
                jump_ladder = FALSE;
                player_index_fall = 0;
                player_state = STATE_FALL;
                return;
            }
        }


		//--------------------------------------------------------------------------------------//
		//                                        V MOVE                                        //
		//--------------------------------------------------------------------------------------//

        // UPDATE PLAYER Y POSITION //
        if(jump_ladder == FALSE)
        {
            player_pos_y += TABLE_PLAYER_JUMP_V[player_index_jump];
        }

        else
        {
            player_pos_y += TABLE_PLAYER_JUMP_LADDER[player_index_jump];
        }


        // IF PLAYER GOES BELOW ITS BASE Y POSITION //
        if(player_pos_y >= PLAYER_BASE_Y_POS)
        {
            // THE CAMERA MOVES //
            // CALCULATE HOW MANY PIXELS THE CAMERA HAS TO MOVE DOWN //
            camera_y_move = player_pos_y - PLAYER_BASE_Y_POS;
            sgx_map_pxl_y += camera_y_move;

            // IF THE CAMERA HAS REACHED ITS MAX (LOWEST) POSITION //
            if(sgx_map_pxl_y > camera_max_y_position)
            {
                // THE CAMERA CAN NOT MOVE LOWER //
                sgx_map_pxl_y = camera_max_y_position;
            }

            // THE PLAYER STAYS AT ITS BASE Y POSITION //
            player_pos_y = PLAYER_BASE_Y_POS;

            spr_y(player_pos_y);
        }


        // UPDATE JUMP INDEX IN THE ARRAY //
        if(player_index_jump < jump_max_index)
        {
            player_index_jump += 1;
        }


        // CHECK COLLISION WITH THE FLOOR //
        check_FLOOR_R();


        if(map_blk_flag == TILE_BG)
        {
            // CALCULATE HOW MANY PIXELS THE PLAYER MOVED INTO THE GROUND //
            for(i=1; i<11 ; i++ )
            {
                if(player_axis == AXIS_RIGHT)
                {
                    check_BG( 11 , i);
                }

                else
                {
                    check_BG( 10 , i);
                }


                if(map_blk_flag == TILE_EMPTY)
                {
                    if(player_pos_y != PLAYER_BASE_Y_POS)
                    {
                        player_pos_y -= (i - 1);
                    }

                    else
                    {
                        sgx_map_pxl_y -= (i - 1);
                    }

                    break;
                }
            }

            // SET PLAYER SPRITE NEW POSITION //
            spr_y(player_pos_y);

            player_counter_anim = 1;
            player_index_jump = 0;
            jump_ladder = FALSE;
            jump_max_index = 34;
            player_state = STATE_IDLE;
            return;
        }


        // CHECK COLLISION WITH LADDERS //
        if(player_index_jump > 4)
        {
            check_LADDER( 16 , 16 );

            if(map_blk_flag == TILE_LADDER)
            {
                // CAMERA GOES 8 PX BACKWARD //
                sgx_map_pxl_x = ( (sgx_map_pxl_x >> 3) << 3 );

                // SO WE UPDATE THE MAP //
                sgx_scroll_map();

                // CHECK IF THE PLAYER STANDS RIGHT TO THE LADDER //
                check_LADDER( 31 , 16 );

                if(map_blk_flag == TILE_LADDER)
                {
                    sgx_map_pxl_x += 8;
                }

                player_counter_anim = 1;
                player_index_jump = 0;
                jump_ladder = TRUE;
                jump_max_index = 29;
                player_state = STATE_HANG;
            }
        }


        // SET PLAYER SPRITE NEW POSITION //
        spr_y(player_pos_y);
    }


    else if(player_state == STATE_CROUCH)
    {
        if(player_counter_anim == 1)
        {
            load_vram(PLAYER_VRAM_ADR, tiles_SPR_PLAYER + TILES_128 , TILES_16);

            player_counter_anim = 0;
        }

        recenter_CAMERA();
    }


    else if(player_state == STATE_FALL)
    {
        unsigned char i, camera_y_move;
        i = 1;


        spr_set(player_id);


        //--------------------------------------------------------------------------------------//
		//                                        V MOVE                                        //
		//--------------------------------------------------------------------------------------//

        // UPDATE PLAYER Y POSITION //
        player_pos_y += TABLE_PLAYER_FALL[player_index_fall];


        // IF PLAYER GOES BELOW ITS BASE Y POSITION //
        if(player_pos_y >= PLAYER_BASE_Y_POS)
        {
            // THE CAMERA MOVES //
            // CALCULATE HOW MANY PIXELS THE CAMERA HAS TO MOVE DOWN //
            camera_y_move = player_pos_y - PLAYER_BASE_Y_POS;
            sgx_map_pxl_y += camera_y_move;

            // IF THE CAMERA HAS REACHED ITS MAX (LOWEST) POSITION //
            if(sgx_map_pxl_y > camera_max_y_position)
            {
                // THE CAMERA CAN NOT MOVE LOWER //
                sgx_map_pxl_y = camera_max_y_position;
            }

            // THE PLAYER STAYS AT ITS BASE Y POSITION //
            player_pos_y = PLAYER_BASE_Y_POS;
        }


        // UPDATE JUMP INDEX IN THE ARRAY //
        // ARRAY MAX ENTRY : 20//
        if(player_index_fall < 20)
        {
            player_index_fall += 1;
        }


        //check_FLOOR_R();
        check_BG( 15 , 0);


        if(map_blk_flag == TILE_BG)
        {
            // CALCULATE HOW MANY PIXELS THE PLAYER MOVED INTO THE GROUND //
            for(i=1; i<11 ; i++ )
            {
                //if(player_axis == AXIS_RIGHT)
                //{
                    check_BG( 15 , i);//20
                //}

                /*else
                {
                    check_BG( 10 , i);
                }*/


                if(map_blk_flag == TILE_EMPTY)
                {
                    if(player_pos_y != PLAYER_BASE_Y_POS)
                    {
                        player_pos_y -= (i - 1);
                    }

                    else
                    {
                        sgx_map_pxl_y -= (i - 1);
                    }


                    break;
                }

            }

            spr_y(player_pos_y);

            player_counter_anim = 1;
            player_index_jump = 0;
            player_index_fall = 0;
            jump_ladder = FALSE;
            jump_max_index = 34;
            player_state = STATE_IDLE;
            return;
        }


        check_LADDER( 16 , 16 );

        // IF PLAYER HITS THE LADDER //
        if(map_blk_flag == TILE_LADDER)
        {
            // CAMERA GOES 8 PX BACKWARD //
            sgx_map_pxl_x = ( (sgx_map_pxl_x >> 3) << 3 );

            // SO WE UPDATE THE MAP //
            sgx_scroll_map();

            // CHECK IF THE PLAYER STANDS RIGHT TO THE LADDER //
            check_LADDER( 31 , 16 );

            if(map_blk_flag == TILE_LADDER)
            {
                sgx_map_pxl_x += 8;
            }

            player_counter_anim = 1;
            player_index_jump = 0;
            player_index_fall = 0;
            jump_ladder = TRUE;
            jump_max_index = 29;
            player_state = STATE_HANG;
            return;
        }


        spr_y(player_pos_y);
    }


    else if(player_state == STATE_HANG)
    {
        recenter_CAMERA();

        if(player_counter_anim == 1)
        {
            load_vram(PLAYER_VRAM_ADR, tiles_SPR_PLAYER + TILES_144 , TILES_16);

            player_counter_anim = 0;
        }
    }


    else if(player_state == STATE_CLIMB_UP)
    {
        if(player_counter_anim == 0)
        {
            load_vram(PLAYER_VRAM_ADR, tiles_SPR_PLAYER + TILES_160 , TILES_16);
        }

        else if(player_counter_anim == 3)
        {
            load_vram(PLAYER_VRAM_ADR, tiles_SPR_PLAYER + TILES_176 , TILES_16);
        }

        else if(player_counter_anim == 6)
        {
            load_vram(PLAYER_VRAM_ADR, tiles_SPR_PLAYER + TILES_192 , TILES_16);
        }

        else if(player_counter_anim == 9)
        {
            load_vram(PLAYER_VRAM_ADR, tiles_SPR_PLAYER + TILES_208 , TILES_16);
        }

        else if(player_counter_anim == 12)
        {
            load_vram(PLAYER_VRAM_ADR, tiles_SPR_PLAYER + TILES_192 , TILES_16);
        }

        else if(player_counter_anim == 15)
        {
            load_vram(PLAYER_VRAM_ADR, tiles_SPR_PLAYER + TILES_176 , TILES_16);
        }


        player_counter_anim += 1;

        if(player_counter_anim == 17)
        {
            player_counter_anim = 0;
        }

        recenter_CAMERA();
    }


    else if(player_state == STATE_CLIMB_DOWN)
    {
        if(player_counter_anim == 0)
        {
            load_vram(PLAYER_VRAM_ADR, tiles_SPR_PLAYER + TILES_176 , TILES_16);
        }

        else if(player_counter_anim == 3)
        {
            load_vram(PLAYER_VRAM_ADR, tiles_SPR_PLAYER + TILES_192 , TILES_16);
        }

        else if(player_counter_anim == 6)
        {
            load_vram(PLAYER_VRAM_ADR, tiles_SPR_PLAYER + TILES_208 , TILES_16);
        }

        else if(player_counter_anim == 9)
        {
            load_vram(PLAYER_VRAM_ADR, tiles_SPR_PLAYER + TILES_192 , TILES_16);
        }

        else if(player_counter_anim == 12)
        {
            load_vram(PLAYER_VRAM_ADR, tiles_SPR_PLAYER + TILES_176 , TILES_16);
        }

        else if(player_counter_anim == 15)
        {
            load_vram(PLAYER_VRAM_ADR, tiles_SPR_PLAYER + TILES_160 , TILES_16);
        }


        player_counter_anim += 1;

        if(player_counter_anim == 17)
        {
            player_counter_anim = 0;
        }

        recenter_CAMERA();
    }


    else if(player_state == STATE_JUMP_LADDER)
    {
        unsigned char i;
        i = 1;


        if(player_counter_anim == 0)
        {
            load_vram(PLAYER_VRAM_ADR, tiles_SPR_PLAYER + TILES_112 , TILES_16);

            player_counter_anim = 1;
        }


        player_pos_y += TABLE_PLAYER_JUMP_V[player_index_jump];

        spr_set(player_id);
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
                    check_BG( 11 , i);
                }

                else
                {
                    check_BG( 10 , i);
                }


                if(map_blk_flag == TILE_EMPTY)
                {
                    load_vram(PLAYER_VRAM_ADR, tiles_SPR_PLAYER , TILES_16);

                    player_pos_y -= (i - 1);
                    spr_y(player_pos_y);
                    break;
                }

            }

            player_counter_anim = 1;
            player_index_jump = 0;
            jump_ladder = FALSE;
            jump_max_index = 34;
            player_state = STATE_IDLE;
            return;
        }


        if(player_index_jump > 18)
        {
            // CHECK COLLISION WITH LADDERS //
            check_LADDER( 16 , 8 );

            // IF PLAYER HITS THE LADDER //
            if(map_blk_flag == TILE_LADDER)
            {
                // CAMERA GOES 8 PX BACKWARD //
                sgx_map_pxl_x = ( (sgx_map_pxl_x >> 3) << 3 );

                // SO WE UPDATE THE MAP //
                sgx_scroll_map();

                // CHECK IF THE PLAYER STANDS RIGHT TO THE LADDER //
                check_LADDER( 31 , 8 );

                if(map_blk_flag == TILE_LADDER)
                {
                    sgx_map_pxl_x += 8;
                }

                player_counter_anim = 1;
                player_index_jump = 0;
                jump_ladder = TRUE;
                jump_max_index = 29;
                player_state = STATE_HANG;
            }
        }
    }

}
