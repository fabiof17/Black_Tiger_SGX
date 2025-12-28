#include "huc.h"
#include "hucc-scroll.h"
#include "hucc-chrmap.h"
#include "hucc-blkmap.h"








void hide_LEVEL_SPRITES()
{
    char i;

    for(i=0 ; i<64 ; i++)
    {
        spr_set(i);
        spr_hide();
    }
}




//-----------------------------------------------------------------------------//
//                                     HUD                                     //
//-----------------------------------------------------------------------------//

void display_LIFE()
{
    put_number(life_amount,1,1,0);
}


void display_SCORE()
{
    put_number(score,6,14,1);
}


void display_TIME_LEVEL()
{
    put_number(minutes,1,1,3);

    if(seconds < 10)
    {
        put_number(0,1,3,3);
        put_number(seconds,1,4,3);
    }

    else
    {
        put_number(seconds,2,3,3);
    }

    time_counter += 1;

    if(time_counter == 60)
    {
        time_counter = 0;

        if(seconds > 0)
        {
            seconds -= 1;
        }

        else
        {
            if(minutes > 0)
            {
                seconds = 59;
                minutes -= 1;
            }

            else
            {
                seconds = 0;
                minutes = 0;
                // TIME OUT //
            }
        }
    } 
}


void display_KEY()
{
    put_number(key_amount,2,7,27);
}


void display_POTION()
{
    put_number(potion_amount,2,19,27);
}


void display_ZENNY()
{
    put_number(zenny_amount,5,26,4);
}




//-----------------------------------------------------------------------------//
//                                  SCROLLING                                  //
//-----------------------------------------------------------------------------//

void scroll_object()
{
    char i;
    onscreen_object_number = 0;

    for(i=0 ; i<level_object_number ; i++)
    {
        if(list_object_state[i] != STATE_FREE)
        {
            char scroll_allowed = FALSE;
            
            // IF OBJECT X POSITION IS INFERIOR TO SCREEN RIGHT SIDE //
            if(list_object_x_pos_ref[i] < sgx_map_pxl_x + 256)
            {
                // IF OBJECT X POSITION IS SUPERIOR TO SCREEN LEFT SIDE PLUS 16 PX //
                if(list_object_x_pos_ref[i] - sgx_map_pxl_x + 16 > 0)
                {
                    // IF OBJECT Y POSITION IS INFERIOR TO SCREEN BOTTOM //
                    if(list_object_y_pos_ref[i] < sgx_map_pxl_y + 224)
                    {
                        // IF OBJECT Y POSITION IS SUPERIOR TO SCREEN TOP PLUS 16 PX //
                        if(list_object_y_pos_ref[i] - sgx_map_pxl_y + 16 > 0)
                        {
                            // WE STORE THE OBJECT ID //
                            list_onscreen_object[onscreen_object_number] = i;
                            onscreen_object_number += 1;
                            scroll_allowed = TRUE;
                        }
                    }
                }
            }

            // IF OBJECTS IS WITHIN THE SCREEN LIMITS //
            if(scroll_allowed == TRUE)
            {
                list_object_x_pos[i] = list_object_x_pos_ref[i] - sgx_map_pxl_x;
                list_object_y_pos[i] = list_object_y_pos_ref[i] - sgx_map_pxl_y;
            }

            else
            {
                list_object_x_pos[i] = -16;
                list_object_y_pos[i] = -16;
            }

            sgx_spr_set(i + object_start_index);

			sgx_spr_x(list_object_x_pos[i]);
			sgx_spr_y(list_object_y_pos[i]);
        }
    }
}


void scroll_chest()
{
    char i;
    onscreen_chest_number = 0;

    for(i=0 ; i<level_chest_number ; i++)
    {
        if(list_chest_state[i] != STATE_FREE)
        {
            char scroll_allowed = FALSE;
            
            // IF CHEST X POSITION IS INFERIOR TO SCREEN RIGHT SIDE //
            if(list_chest_x_pos_ref[i] < sgx_map_pxl_x + 256)
            {
                // IF CHEST X POSITION IS SUPERIOR TO SCREEN LEFT SIDE PLUS 32 PX //
                if(list_chest_x_pos_ref[i] - sgx_map_pxl_x + 32 > 0)
                {
                    // IF CHEST Y POSITION IS INFERIOR TO SCREEN BOTTOM //
                    if(list_chest_y_pos_ref[i] < sgx_map_pxl_y + 224)
                    {
                        // IF CHEST Y POSITION IS SUPERIOR TO SCREEN TOP PLUS 32 PX //
                        if(list_chest_y_pos_ref[i] - sgx_map_pxl_y + 32 > 0)
                        {
                            // WE STORE THE CHEST ID //
                            list_onscreen_chest[onscreen_chest_number] = i;
                            onscreen_chest_number += 1;
                            
                            scroll_allowed = TRUE;
                        }
                    }
                }
            }

            // IF CHEST IS WITHIN THE SCREEN LIMITS //
            if(scroll_allowed == TRUE)
            {
                list_chest_x_pos[i] = list_chest_x_pos_ref[i] - sgx_map_pxl_x;
                list_chest_y_pos[i] = list_chest_y_pos_ref[i] - sgx_map_pxl_y;
            }

            else
            {
                list_chest_x_pos[i] = -32;
                list_chest_y_pos[i] = -32;
            }

            sgx_spr_set(i + chest_start_index);

			sgx_spr_x(list_chest_x_pos[i]);
			sgx_spr_y(list_chest_y_pos[i]);
        }
    }
}


void scroll_npc()
{
    char i;
    onscreen_npc_number = 0;

    for(i=0 ; i<level_npc_number ; i++)
    {
        if(list_npc_state[i] != STATE_FREE)
        {
            char scroll_allowed = FALSE;
            
            // IF NPC X POSITION IS INFERIOR TO SCREEN RIGHT SIDE //
            if(list_npc_x_pos_ref[i] < sgx_map_pxl_x + 256)
            {
                // IF NPC X POSITION IS SUPERIOR TO SCREEN LEFT SIDE PLUS 32 PX //
                if(list_npc_x_pos_ref[i] - sgx_map_pxl_x + 32 > 0)
                {
                    // IF NPC Y POSITION IS INFERIOR TO SCREEN BOTTOM //
                    if(list_npc_y_pos_ref[i] < sgx_map_pxl_y + 224)
                    {
                        // IF NPC Y POSITION IS SUPERIOR TO SCREEN TOP PLUS 32 PX //
                        if(list_npc_y_pos_ref[i] - sgx_map_pxl_y + 32 > 0)
                        {
                            // WE STORE THE NPC ID //
                            list_onscreen_npc[onscreen_npc_number] = i;
                            onscreen_npc_number += 1;
                            
                            scroll_allowed = TRUE;
                        }
                    }
                }
            }

            // IF NPC IS WITHIN THE SCREEN LIMITS //
            if(scroll_allowed == TRUE)
            {
                list_npc_x_pos[i] = list_npc_x_pos_ref[i] - sgx_map_pxl_x;
                list_npc_y_pos[i] = list_npc_y_pos_ref[i] - sgx_map_pxl_y;
            }

            else
            {
                list_npc_x_pos[i] = -32;
                list_npc_y_pos[i] = -32;
            }

            sgx_spr_set(i + npc_start_index);

			sgx_spr_x(list_npc_x_pos[i]);
			sgx_spr_y(list_npc_y_pos[i]);
        }
    }
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
            camera_y_move = CAMERA_RECENTER_VELOCITY - (player_pos_y - 128);

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
            camera_y_move = CAMERA_RECENTER_VELOCITY - (128 - player_pos_y);

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




//-----------------------------------------------------------------------------//
//                                 COLLISIONS                                  //
//-----------------------------------------------------------------------------//

int check_TILE_DEPTH(signed char x_offset , signed char y_offset)
{
    int player_COLL_X;
    int player_COLL_Y;


    player_COLL_X = player_pos_x + x_offset;
    player_COLL_Y = player_pos_y + 32 - y_offset;//32

    get_map_block(player_COLL_X + sgx_map_pxl_x, player_COLL_Y + sgx_map_pxl_y);
}

// CHECK COLLISION PLAYER -> BG //
int collision_PLAYER_BG(signed char x_offset , signed char y_offset)
{
    int player_COLL_X;
    int player_COLL_Y;


    player_COLL_X = player_pos_x + x_offset;
    player_COLL_Y = player_pos_y + y_offset;

    get_map_block(player_COLL_X + sgx_map_pxl_x, player_COLL_Y + sgx_map_pxl_y);
}

// CHECK COLLISION PLAYER -> OBJECTS //
void collision_PLAYER_OBJECT()
{
    if(onscreen_object_number != 0)
    {
        char i;
        char current_object_id;
        char current_object_type;

        for(i=0 ; i<onscreen_object_number ; i++)
        {
            // RETRIEVE OBJECT INDEX IN THE LIST //
            current_object_id = list_onscreen_object[i];
            // RETRIEVE OBJECT TYPE //
            current_object_type = list_object_type[current_object_id];

            if(current_object_type != TYPE_POT)
            {
                if(abs( (player_pos_x + 16) - (list_object_x_pos[current_object_id] + 8) ) < OBJECT_MARGIN)
                {
                    if(abs( (player_pos_y + 16) - (list_object_y_pos[current_object_id] + 8) ) < OBJECT_MARGIN)
                    {
                        // THE OBJECT DISAPPEARS //
                        list_object_x_pos[current_object_id] = -16;
                        list_object_y_pos[current_object_id] = -16;
                        list_object_state[current_object_id] = STATE_FREE;

                        sgx_spr_set(current_object_id + object_start_index);
                        sgx_spr_x(list_object_x_pos[current_object_id]);
                        sgx_spr_y(list_object_y_pos[current_object_id]);
                        

                        switch(current_object_type)
                        {
                            case TYPE_HOURGLASS:
                                if(seconds + 30 > 59)
                                {
                                    seconds = seconds + 30 - 60;
                                    minutes += 1;
                                }

                                else
                                {
                                    seconds += 30;
                                }

                                break;

                            case TYPE_POW:
                                //
                                break;

                            case TYPE_GRAY_KEY:
                                key_amount += 1;
                                display_KEY();
                                break;

                            case TYPE_COIN_1:
                                zenny_amount += 1;
                                display_ZENNY();
                                break;

                            case TYPE_COIN_5:
                                zenny_amount += 5;
                                display_ZENNY();
                                break;

                            case TYPE_COIN_10:
                                zenny_amount += 10;
                                display_ZENNY();
                                break;

                            case TYPE_COIN_50:
                                zenny_amount += 50;
                                display_ZENNY();
                                break;

                            case TYPE_COIN_100:
                                zenny_amount += 100;
                                display_ZENNY();
                                break;

                            case TYPE_COIN_500:
                                zenny_amount += 500;
                                display_ZENNY();
                                break;

                            case TYPE_COIN_1000:
                                zenny_amount += 1000;
                                display_ZENNY();
                                break;

                            case TYPE_YASHICHI:
                                life_amount += 1;
                                break;
                        }
                    }
                }
            }
        }
    }
}

// CHECK COLLISION PLAYER -> NPCS //
void collision_PLAYER_NPC()
{
    if(onscreen_npc_number != 0)
    {
        if(player_state == STATE_IDLE || player_state == STATE_WALK)
        {
            char i,j;
            char current_npc_id;
            char current_npc_type;

            for(i=0 ; i<onscreen_npc_number ; i++)
            {
                // RETRIEVE NPC INDEX IN THE LIST //
                current_npc_id = list_onscreen_npc[i];

                if(list_npc_state[current_npc_id] == STATE_ACTIVE)
                {
                    // RETRIEVE NPC TYPE //
                    current_npc_type = list_npc_type[current_npc_id];

                    if(abs( (player_pos_x + 16) - (list_npc_x_pos[current_npc_id] + 16) ) < OBJECT_MARGIN)
                    {
                        if(abs( (player_pos_y + 16) - (list_npc_y_pos[current_npc_id] + 16) ) < OBJECT_MARGIN)
                        {               
                            global_counter = 0;
                            selected_npc = current_npc_id + npc_start_index;
                            list_npc_state[current_npc_id] = STATE_FREE;
                            sequence_id = SEQUENCE_NPC;

                            if(current_npc_type == TYPE_NPC_SHOP)
                            {                              
                                minutes_backup = minutes;
                                seconds_backup = seconds;
                                camera_pos_x_backup = sgx_map_pxl_x;
                                camera_pos_y_backup = list_npc_y_pos_ref[current_npc_id] - 128;
                            }
                        }
                    }
                }
            }
        }
    }
}

// CHECK COLLISION WEAPON -> OBJECTS //
void collision_WEAPON_OBJECTS()
{
    if(onscreen_object_number != 0)
    {
        char i;
        char current_object_id;
        char current_object_type;
        int weapon_pos_x;
        int weapon_pos_y;

        for(i=0 ; i<onscreen_object_number ; i++)
        {
            // RETRIEVE OBJECT INDEX IN THE LIST //
            current_object_id = list_onscreen_object[i];
            // RETRIEVE OBJECT TYPE //
            current_object_type = list_object_type[current_object_id];

            if(current_object_type == TYPE_POT)
            {
                if(list_object_state[current_object_id] == STATE_ACTIVE)
                {
                    // GET WEAPON POSITION //
                    spr_set(weapon_id);
                    weapon_pos_x = spr_get_x();
                    weapon_pos_y = spr_get_y();

                    if( abs( (weapon_pos_x + 8) - (list_object_x_pos[current_object_id] + 8) ) < 16 )
                    {
                        if( abs( (weapon_pos_y + 8) - (list_object_y_pos[current_object_id] + 8) ) < 8 )
                        {
                            // WEAPON STOPS UNDOLDING //
                            chain_unfold = FALSE;

                            // WE SHORTEN WEAPON ANIMATION DURATION //
                            player_counter_attack = 19;

                            // DECREASE POT ENERGY //
                            list_object_energy[current_object_id] -= 1;

                            // INIT POT COUNTER //
                            list_object_counter[current_object_id] = 0;

                            // POT GETS HIT //
                            list_object_state[current_object_id] = STATE_HIT;

                            // SELECT POT SPRITE //
                            sgx_spr_set(current_object_id + object_start_index);
                            
                            // CHECK OBJECT ENERGY //
                            switch(list_object_energy[current_object_id])
                            {
                                case 0:
                                    //sgx_spr_pattern(POT3_VRAM_ADR);


                                case 1:
                                    sgx_spr_pattern(POT2_VRAM_ADR);
                            }
                        }
                    }
                }
            }
        }
    }
}





//-----------------------------------------------------------------------------//
//                                   OBJECTS                                   //
//-----------------------------------------------------------------------------//

void anim_OBJECTS()
{
    if(onscreen_object_number != 0)
    {
        char i;
        char current_object_id;
        signed int object_pos_y;


        for(i=0 ; i<onscreen_object_number ; i++)
        {
            // RETRIEVE OBJECT INDEX IN THE LIST //
            current_object_id = list_onscreen_object[i];

            // IF POT HAS BEEN HIT BY THE WEAPON //
            if(list_object_state[current_object_id] == STATE_HIT)
            {
                // SELECT POT SPRITE //
                sgx_spr_set(current_object_id + object_start_index);
                
                // CHECK OBJECT ENERGY //
                if(list_object_energy[current_object_id] == 0)
                {
                    if(list_object_counter[current_object_id] == 0)
                    {
                        object_pos_y = sgx_spr_get_y();
                        sgx_spr_y(object_pos_y - 1);
                    }

                    else if(list_object_counter[current_object_id] == 1)
                    {
                        object_pos_y = sgx_spr_get_y();
                        sgx_spr_y(object_pos_y - 2);
                    }

                    else if(list_object_counter[current_object_id] == 2)
                    {
                        object_pos_y = sgx_spr_get_y();
                        sgx_spr_y(object_pos_y - 1);
                    }

                    else if(list_object_counter[current_object_id] == 8)
                    {
                        sgx_spr_pal(18);
                        sgx_spr_pattern(*(ptr_REWARD_VRAM_ADR+current_object_id));
                    }

                    else if(list_object_counter[current_object_id] == 9)
                    {
                        sgx_spr_pal(17);
                        sgx_spr_pattern(POT3_VRAM_ADR);
                    }

                    else if(list_object_counter[current_object_id] == 13)
                    {
                        sgx_spr_pal(18);
                        sgx_spr_pattern(*(ptr_REWARD_VRAM_ADR+current_object_id));
                    }

                    else if(list_object_counter[current_object_id] == 14)
                    {
                        sgx_spr_pal(17);
                        sgx_spr_pattern(POT4_VRAM_ADR);
                    }

                    else if(list_object_counter[current_object_id] == 18)
                    {
                        sgx_spr_pal(18);
                        sgx_spr_pattern(*(ptr_REWARD_VRAM_ADR+current_object_id));
                    }

                    else if(list_object_counter[current_object_id] == 19)
                    {
                        sgx_spr_pal(17);
                        sgx_spr_pattern(POT5_VRAM_ADR);
                    }

                    else if(list_object_counter[current_object_id] == 23)
                    {
                        sgx_spr_pal(18);
                        sgx_spr_pattern(*(ptr_REWARD_VRAM_ADR+current_object_id));
                    }

                    else if(list_object_counter[current_object_id] == 24)
                    {
                        sgx_spr_pal(17);
                        sgx_spr_pattern(POT6_VRAM_ADR);
                    }

                    else if(list_object_counter[current_object_id] == 28)
                    {
                        sgx_spr_pal(18);
                        sgx_spr_pattern(*(ptr_REWARD_VRAM_ADR+current_object_id));
                    }

                    else if(list_object_counter[current_object_id] == 29)
                    {
                        sgx_spr_pal(17);
                        sgx_spr_pattern(POT7_VRAM_ADR);
                    }

                    else if(list_object_counter[current_object_id] == 33)
                    {
                        sgx_spr_pal(18);
                        sgx_spr_pattern(*(ptr_REWARD_VRAM_ADR+current_object_id));
                    }

                    else if(list_object_counter[current_object_id] == 34)
                    {
                        sgx_spr_pal(17);
                        sgx_spr_pattern(POT8_VRAM_ADR);
                    }

                    else if(list_object_counter[current_object_id] == 38)
                    {
                        sgx_spr_pal(18);
                        sgx_spr_pattern(*(ptr_REWARD_VRAM_ADR+current_object_id));
                        list_object_type[current_object_id] = *(ptr_REWARD_TYPE+current_object_id);
                        list_object_state[current_object_id] = STATE_DROPPED;
                    }

                    list_object_counter[current_object_id] += 1;
                }
                

                else if(list_object_energy[current_object_id] == 1)
                {
                    if(list_object_counter[current_object_id] == 0)
                    {
                        object_pos_y = sgx_spr_get_y();
                        sgx_spr_y(object_pos_y - 1);
                    }

                    else if(list_object_counter[current_object_id] == 1)
                    {
                        object_pos_y = sgx_spr_get_y();
                        sgx_spr_y(object_pos_y - 2);
                    }

                    else if(list_object_counter[current_object_id] == 2)
                    {
                        object_pos_y = sgx_spr_get_y();
                        sgx_spr_y(object_pos_y - 1);
                    }

                    else if(list_object_counter[current_object_id] == 4)
                    {
                        list_object_state[current_object_id] = STATE_ACTIVE;
                    }

                    list_object_counter[current_object_id] += 1;
                }
            }
        }
    }
}







void joypad_BUTTONS()
{
    // JUMP //
    if(joytrg(JOYPAD_1) == JOY_I)
    {
        if(player_state == STATE_IDLE)
        {
            hit_wall = FALSE;
            
            player_counter_anim = 0;

            player_state = STATE_JUMP;

            spr_set(weapon_id);
            
            if(player_axis == AXIS_RIGHT)
            {
                spr_x(player_pos_x-5);
            }

            else
            {
                spr_x(player_pos_x+21);
            }
        }


        else if(player_state == STATE_WALK)
        {
            hit_wall = FALSE;
            
            player_counter_anim = 0;

            player_state = STATE_JUMP_RIGHT + player_axis;

            spr_set(weapon_id);
            
            if(player_axis == AXIS_RIGHT)
            {
                spr_x(player_pos_x-5);
            }

            else
            {
                spr_x(player_pos_x+21);
            }
        }


        else if(player_state == STATE_HANG || player_state == STATE_CLIMB_UP || player_state == STATE_CLIMB_DOWN)
        {
            if(player_attack == FALSE)
            {
                if(joy(JOYPAD_1) & JOY_RIGHT)
                {
                    hit_wall = FALSE;
                    
                    player_counter_anim = 0;

                    player_state = STATE_JUMP_RIGHT;

                    spr_set(weapon_id);
                    spr_x(player_pos_x-5);
                }

                else if(joy(JOYPAD_1) & JOY_LEFT)
                {
                    hit_wall = FALSE;
                    
                    player_counter_anim = 0;

                    player_state = STATE_JUMP_LEFT;

                    spr_set(weapon_id);
                    spr_x(player_pos_x+21);
                }

                else if(joy(JOYPAD_1) & JOY_UP)
                {
                    hit_wall = FALSE;
                    
                    player_counter_anim = 0;

                    collision_PLAYER_BG( 15 , 8 );

                    if(map_blk_flag == TILE_EMPTY)
                    {
                        player_state = STATE_JUMP_LADDER;

                        spr_set(weapon_id);
                        spr_y(player_pos_y+8);
                        
                        if(player_axis == AXIS_RIGHT)
                        {
                            spr_x(player_pos_x-5);
                        }

                        else
                        {
                            spr_x(player_pos_x+21);
                        }
                    }
                }
            }
        }
    }

    // ATTACK //
    else if(joytrg(JOYPAD_1) == JOY_II)
    {
        if(player_state == STATE_IDLE || player_state == STATE_WALK)
        {
            list_chain_active[0] = FALSE;
            list_chain_active[1] = FALSE;
            list_chain_active[2] = FALSE;

            chain_unfold = TRUE;
            player_counter_attack = 0;
            player_state = STATE_ATTACK;
        }

        else if(player_state == STATE_JUMP)
        {
            /*if(player_attack == FALSE)
            {
                chain_unfold = TRUE;
                player_counter_attack = 0;
                player_attack = TRUE;
            }*/
        }

        else if(player_state == STATE_CROUCH)
        {
            list_chain_active[0] = FALSE;
            list_chain_active[1] = FALSE;
            list_chain_active[2] = FALSE;

            chain_unfold = TRUE;
            player_counter_attack = 0;
            player_state = STATE_CROUCH_ATTACK;
        }

        else if(player_state == STATE_HANG || player_state == STATE_CLIMB_UP || player_state == STATE_CLIMB_DOWN)
        {
            if(player_attack == FALSE)
            {
                list_chain_active[0] = FALSE;
                list_chain_active[1] = FALSE;
                list_chain_active[2] = FALSE;
                
                player_counter_attack = 0;
                chain_unfold = TRUE;
                player_attack = TRUE;
                player_state = STATE_HANG;
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
            if(player_attack == FALSE)
            {
                player_counter_anim = 1;
                player_state = STATE_IDLE;
            }
        }


        else if(player_state == STATE_CLIMB_UP || player_state == STATE_CLIMB_DOWN)
        {
            if(player_attack == FALSE)
            {
                spr_set(player_id);
                spr_pattern(PLAYER_HANG_VRAM_ADR);
                player_counter_anim = 0;
                player_state = STATE_HANG;
            }
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

                spr_set(chain_id);
                spr_ctrl(FLIP_MAS, NO_FLIP_X);

                spr_set(chain_id+1);
                spr_ctrl(FLIP_MAS, NO_FLIP_X);

                spr_set(chain_id+2);
                spr_ctrl(FLIP_MAS, NO_FLIP_X);

                spr_set(weapon_id);
                spr_ctrl(FLIP_MAS, NO_FLIP_X);
                spr_x(player_pos_x+1);
            }

            if(joy(JOYPAD_1) & JOY_DOWN)
            {
                player_counter_anim = 1;
                player_state = STATE_CROUCH;
                return;
            }

            player_state = STATE_WALK;
        }


        else if(player_state == STATE_JUMP)
        {
            if(player_attack == FALSE)
            {
                if(player_axis == AXIS_LEFT)
                {
                    player_axis = AXIS_RIGHT;
                    player_previous_axis = player_axis;

                    spr_set(player_id);
                    spr_ctrl(FLIP_MAS, NO_FLIP_X);

                    spr_set(chain_id);
                    spr_ctrl(FLIP_MAS, NO_FLIP_X);

                    spr_set(chain_id+1);
                    spr_ctrl(FLIP_MAS, NO_FLIP_X);

                    spr_set(chain_id+2);
                    spr_ctrl(FLIP_MAS, NO_FLIP_X);

                    spr_set(weapon_id);
                    spr_ctrl(FLIP_MAS, NO_FLIP_X);
                    spr_x(player_pos_x-5);
                }

                if(player_index_jump > 11 && player_index_jump < 15)
                {
                    player_state = STATE_JUMP_RIGHT;                        
                }
            }
        }


        else if(player_state == STATE_JUMP_LEFT)
        {
            if(player_axis == AXIS_LEFT)
            {
                player_axis = AXIS_RIGHT;
                player_previous_axis = player_axis;

                spr_set(player_id);
                spr_ctrl(FLIP_MAS, NO_FLIP_X);

                spr_set(chain_id);
                spr_ctrl(FLIP_MAS, NO_FLIP_X);

                spr_set(chain_id+1);
                spr_ctrl(FLIP_MAS, NO_FLIP_X);

                spr_set(chain_id+2);
                spr_ctrl(FLIP_MAS, NO_FLIP_X);

                spr_set(weapon_id);
                spr_ctrl(FLIP_MAS, NO_FLIP_X);
                spr_x(player_pos_x-5);
            }
        }


        else if(player_state == STATE_CROUCH)
        {
            if(joy(JOYPAD_1) & JOY_DOWN)
            {
                if(player_axis == AXIS_LEFT)
                {
                    player_axis = AXIS_RIGHT;
                    player_previous_axis = player_axis;

                    spr_set(player_id);
                    spr_ctrl(FLIP_MAS, NO_FLIP_X);

                    spr_set(chain_id);
                    spr_ctrl(FLIP_MAS, NO_FLIP_X);

                    spr_set(chain_id+1);
                    spr_ctrl(FLIP_MAS, NO_FLIP_X);

                    spr_set(chain_id+2);
                    spr_ctrl(FLIP_MAS, NO_FLIP_X);

                    spr_set(weapon_id);
                    spr_ctrl(FLIP_MAS, NO_FLIP_X);
                    spr_x(player_pos_x-1);
                }
            }

            else
            {
                player_axis = AXIS_RIGHT;
                
                if(player_previous_axis != player_axis)
                {
                    player_previous_axis = player_axis;

                    spr_set(player_id);
                    spr_ctrl(FLIP_MAS, NO_FLIP_X);

                    spr_set(chain_id);
                    spr_ctrl(FLIP_MAS, NO_FLIP_X);

                    spr_set(chain_id+1);
                    spr_ctrl(FLIP_MAS, NO_FLIP_X);

                    spr_set(chain_id+2);
                    spr_ctrl(FLIP_MAS, NO_FLIP_X);

                    spr_set(weapon_id);
                    spr_ctrl(FLIP_MAS, NO_FLIP_X);
                    spr_x(player_pos_x+1);
                }

                player_state = STATE_WALK;
            }
        }


        else if(player_state == STATE_FALL)
        {
            if(player_attack == FALSE)
            {
                if(player_axis == AXIS_LEFT)
                {
                    player_axis = AXIS_RIGHT;
                    player_previous_axis = player_axis;

                    spr_set(player_id);
                    spr_ctrl(FLIP_MAS, NO_FLIP_X);

                    spr_set(chain_id);
                    spr_ctrl(FLIP_MAS, NO_FLIP_X);

                    spr_set(chain_id+1);
                    spr_ctrl(FLIP_MAS, NO_FLIP_X);

                    spr_set(chain_id+2);
                    spr_ctrl(FLIP_MAS, NO_FLIP_X);

                    spr_set(weapon_id);
                    spr_ctrl(FLIP_MAS, NO_FLIP_X);
                    spr_x(player_pos_x-4);
                }
            }
        }


        else if(player_state == STATE_HANG)
        {
            if(player_attack == FALSE)
            {
                if(player_axis == AXIS_LEFT)
                {
                    player_axis = AXIS_RIGHT;
                    player_previous_axis = player_axis;

                    spr_set(player_id);
                    spr_ctrl(FLIP_MAS, NO_FLIP_X);

                    spr_set(chain_id);
                    spr_ctrl(FLIP_MAS, NO_FLIP_X);

                    spr_set(chain_id+1);
                    spr_ctrl(FLIP_MAS, NO_FLIP_X);

                    spr_set(chain_id+2);
                    spr_ctrl(FLIP_MAS, NO_FLIP_X);

                    spr_set(weapon_id);
                    spr_ctrl(FLIP_MAS, NO_FLIP_X);
                    spr_x(player_pos_x+17);
                }
            }
        }


        else if(player_state == STATE_CLIMB_UP || player_state == STATE_CLIMB_DOWN)
        {
            spr_set(player_id);
            spr_pattern(PLAYER_HANG_VRAM_ADR);
            player_counter_anim = 0;
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

                spr_set(chain_id);
                spr_ctrl(FLIP_MAS, FLIP_X);

                spr_set(chain_id+1);
                spr_ctrl(FLIP_MAS, FLIP_X);

                spr_set(chain_id+2);
                spr_ctrl(FLIP_MAS, FLIP_X);

                spr_set(weapon_id);
                spr_ctrl(FLIP_MAS, FLIP_X);
                spr_x(player_pos_x+15);
            }

            if(joy(JOYPAD_1) & JOY_DOWN)
            {
                player_counter_anim = 1;
                player_state = STATE_CROUCH;
                return;
            }

            player_state = STATE_WALK;
        }


        else if(player_state == STATE_JUMP)
        {
            if(player_axis == AXIS_RIGHT)
            {
                player_axis = AXIS_LEFT;
                player_previous_axis = player_axis;

                spr_set(player_id);
                spr_ctrl(FLIP_MAS, FLIP_X);

                spr_set(chain_id);
                spr_ctrl(FLIP_MAS, FLIP_X);

                spr_set(chain_id+1);
                spr_ctrl(FLIP_MAS, FLIP_X);

                spr_set(chain_id+2);
                spr_ctrl(FLIP_MAS, FLIP_X);

                spr_set(weapon_id);
                spr_ctrl(FLIP_MAS, FLIP_X);
                spr_x(player_pos_x+21);
            }

            if(player_index_jump > 11 && player_index_jump < 15)
            {
                player_state = STATE_JUMP_LEFT;                        
            }
        }


        else if(player_state == STATE_JUMP_RIGHT)
        {
            if(player_axis == AXIS_RIGHT)
            {
                player_axis = AXIS_LEFT;
                player_previous_axis = player_axis;

                spr_set(player_id);
                spr_ctrl(FLIP_MAS, FLIP_X);

                spr_set(chain_id);
                spr_ctrl(FLIP_MAS, FLIP_X);

                spr_set(chain_id+1);
                spr_ctrl(FLIP_MAS, FLIP_X);

                spr_set(chain_id+2);
                spr_ctrl(FLIP_MAS, FLIP_X);

                spr_set(weapon_id);
                spr_ctrl(FLIP_MAS, FLIP_X);
                spr_x(player_pos_x+21);
            }
        }


        else if(player_state == STATE_CROUCH)
        {
            if(joy(JOYPAD_1) & JOY_DOWN)
            {
                if(joy(JOYPAD_1) & JOY_DOWN)
                {
                    player_axis = AXIS_LEFT;
                    player_previous_axis = player_axis;

                    spr_set(player_id);
                    spr_ctrl(FLIP_MAS, FLIP_X);

                    spr_set(chain_id);
                    spr_ctrl(FLIP_MAS, FLIP_X);

                    spr_set(chain_id+1);
                    spr_ctrl(FLIP_MAS, FLIP_X);

                    spr_set(chain_id+2);
                    spr_ctrl(FLIP_MAS, FLIP_X);

                    spr_set(weapon_id);
                    spr_ctrl(FLIP_MAS, FLIP_X);
                    spr_x(player_pos_x+17);
                }
            }

            else
            {
                player_axis = AXIS_LEFT;

                if(player_previous_axis != player_axis)
                {
                    player_previous_axis = player_axis;

                    spr_set(player_id);
                    spr_ctrl(FLIP_MAS, FLIP_X);

                    spr_set(chain_id);
                    spr_ctrl(FLIP_MAS, FLIP_X);

                    spr_set(chain_id+1);
                    spr_ctrl(FLIP_MAS, FLIP_X);

                    spr_set(chain_id+2);
                    spr_ctrl(FLIP_MAS, FLIP_X);

                    spr_set(weapon_id);
                    spr_ctrl(FLIP_MAS, FLIP_X);
                    spr_x(player_pos_x+15);
                }

                player_state = STATE_WALK;
            }
        }


        else if(player_state == STATE_FALL)
        {
            if(player_axis == AXIS_RIGHT)
            {
                player_axis = AXIS_LEFT;
                player_previous_axis = player_axis;

                spr_set(player_id);
                spr_ctrl(FLIP_MAS, FLIP_X);

                spr_set(chain_id);
                spr_ctrl(FLIP_MAS, FLIP_X);

                spr_set(chain_id+1);
                spr_ctrl(FLIP_MAS, FLIP_X);

                spr_set(chain_id+2);
                spr_ctrl(FLIP_MAS, FLIP_X);

                spr_set(weapon_id);
                spr_ctrl(FLIP_MAS, FLIP_X);
                spr_x(player_pos_x+20);
            }
        }

        
        else if(player_state == STATE_HANG)
        {
            if(player_axis == AXIS_RIGHT)
            {
                player_axis = AXIS_LEFT;
                player_previous_axis = player_axis;

                spr_set(player_id);
                spr_ctrl(FLIP_MAS, FLIP_X);

                spr_set(chain_id);
                spr_ctrl(FLIP_MAS, FLIP_X);

                spr_set(chain_id+1);
                spr_ctrl(FLIP_MAS, FLIP_X);

                spr_set(chain_id+2);
                spr_ctrl(FLIP_MAS, FLIP_X);

                spr_set(weapon_id);
                spr_ctrl(FLIP_MAS, FLIP_X);
                spr_x(player_pos_x-2);
            }
        }


        else if(player_state == STATE_CLIMB_UP || player_state == STATE_CLIMB_DOWN)
        {
            spr_set(player_id);
            spr_pattern(PLAYER_HANG_VRAM_ADR);
            player_counter_anim = 0;
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
            if(player_attack == FALSE)
            {
                unsigned char i;

                collision_PLAYER_BG( 15 , 8 );

                if(map_blk_flag == TILE_EMPTY)
                {
                    for(i=1 ; i<3 ; i++)
                    {
                        collision_PLAYER_BG( 15 , 8 + i );

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

                spr_set(weapon_id);
                spr_hide();

                player_state = STATE_CLIMB_UP;
            }
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
            if(player_attack == FALSE)
            {
                unsigned char i;

                collision_PLAYER_BG( 15 , 10 );

                if(map_blk_flag == TILE_EMPTY)
                {
                    for(i=1 ; i<3 ; i++)
                    {
                        collision_PLAYER_BG( 15 , 22 + i );

                        if(map_blk_flag == TILE_LADDER)
                        {
                            sgx_map_pxl_y += (2 - i);
                            break;
                        }

                        else
                        {
                            spr_set(player_id);
                            spr_pattern(PLAYER_FALL_VRAM_ADR);

                            spr_set(weapon_id);
                            spr_pattern(WEAPON_IDLE_VRAM_ADRESS);
                            spr_y(player_pos_y+4);

                            if(player_axis == AXIS_RIGHT)
                            {
                                spr_x(player_pos_x-4);
                            }
                            
                            else
                            {
                                spr_x(player_pos_x+20);
                            }
                            

                            jump_ladder = FALSE;
                            player_index_jump = 0;
                            player_index_fall = 0;
                            fall_ladder = TRUE;
                            player_state = STATE_FALL;
                        }
                    }
                }

                else
                {
                    spr_set(weapon_id);
                    spr_hide();
                    
                    sgx_map_pxl_y += 2;
                    player_state = STATE_CLIMB_DOWN;
                }
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
            spr_set(player_id);
            spr_pattern(PLAYER_IDLE_VRAM_ADR);

            player_counter_anim = 0;
        }

        recenter_CAMERA();


        // CHECK COLLISION WITH LEFT FLOOR //
        collision_PLAYER_BG( 10 , 32 );//8

        if(map_blk_flag == TILE_EMPTY)
        {
            // CHECK COLLISION WITH RIGHT FLOOR //
            collision_PLAYER_BG( 22 , 32 );//24

            if(map_blk_flag == TILE_EMPTY)
            {
                //set_far_base(TABLE_PLAYER_TILES_BANK[player_naked],TABLE_PLAYER_TILES_ADR[player_naked]);
                //far_load_vram(PLAYER_VRAM_ADR,TILES_16);

                jump_ladder = FALSE;
                player_index_jump = 0;
                player_index_fall = 0;
                player_state = STATE_FALL;
            }
        }

        spr_set(weapon_id);
        spr_pattern(WEAPON_IDLE_VRAM_ADRESS);
        spr_x(player_pos_x+8);
        spr_y(player_pos_y+16);
    }


    else if(player_state == STATE_WALK)
    {
        recenter_CAMERA();


		//--------------------------------------------------------------------------------------//
		//                                   FLOOR COLLISION                                    //
		//--------------------------------------------------------------------------------------//

        // CHECK COLLISION WITH LEFT FLOOR //
        collision_PLAYER_BG( 10 , 32 );//8

        if(map_blk_flag == TILE_EMPTY)
        {
            // CHECK COLLISION WITH RIGHT FLOOR //
            collision_PLAYER_BG( 22 , 32 );//24

            if(map_blk_flag == TILE_EMPTY)
            {
                /*spr_set(player_id);
                spr_pattern(PLAYER_IDLE_VRAM_ADR);

                spr_set(weapon_id);
                spr_pattern(WEAPON_IDLE_VRAM_ADRESS);
                spr_x(player_pos_x+8);
                spr_y(player_pos_y+16);*/

                jump_ladder = FALSE;
                player_index_jump = 0;
                player_index_fall = 0;
                player_state = STATE_FALL;
            }


            else
            {
                if(player_axis == AXIS_RIGHT)
                {
                    // CHECK COLLISION WITH RIGHT WALL //
                    collision_PLAYER_BG( 24 , 31 ); // 24+2

                    if(map_blk_flag == TILE_EMPTY)
                    {
                        sgx_map_pxl_x += 2;
                    }
                }

                else
                {
                    // CHECK COLLISION WITH LEFT WALL //
                    collision_PLAYER_BG( 8 , 31 ); // 8-2

                    if(map_blk_flag == TILE_EMPTY)
                    {
                        sgx_map_pxl_x -= 2;
                    }
                }
            }
        }


        else
        {
            if(player_axis == AXIS_RIGHT)
            {
                // CHECK COLLISION WITH RIGHT WALL //
                collision_PLAYER_BG( 24 , 31 ); // 24+2

                if(map_blk_flag == TILE_EMPTY)
                {
                    sgx_map_pxl_x += 2;
                }
            }

            else
            {
                // CHECK COLLISION WITH LEFT WALL //
                collision_PLAYER_BG( 8 , 31 ); // 8-2

                if(map_blk_flag == TILE_EMPTY)
                {
                    sgx_map_pxl_x -= 2;
                }
            }
        }




        spr_set(player_id);


        player_counter_anim += 1;


        // UPDATE PLAYER TILES //
        if(player_counter_anim == 1)
        {
            spr_pattern(PLAYER_IDLE_VRAM_ADR);

            spr_set(weapon_id);
            spr_pattern(WEAPON_IDLE_VRAM_ADRESS);
            spr_x(player_pos_x+8);
            weapon_y_offset = 16;
            //spr_y(player_pos_y+16);
        }


        else if(player_counter_anim == 2)
        {
            spr_pattern(PLAYER_WALK_1_VRAM_ADR);

            spr_set(weapon_id);
            spr_pattern(WEAPON_WALK_1_VRAM_ADRESS);
            weapon_y_offset = 17;
            //spr_y(player_pos_y+17);

            if(player_axis == AXIS_RIGHT)
            {
                spr_x(player_pos_x+5);
            }

            else
            {
                spr_x(player_pos_x+11);
            }
        }


        else if(player_counter_anim == 4)
        {
            spr_pattern(PLAYER_WALK_2_VRAM_ADR);
            
            spr_set(weapon_id);
            spr_pattern(WEAPON_WALK_2_VRAM_ADRESS);

            if(player_axis == AXIS_RIGHT)
            {
                spr_x(player_pos_x+3);
            }

            else
            {
                spr_x(player_pos_x+13);
            }
        }


        else if(player_counter_anim == 7)
        {
            //spr_set(player_id);
            spr_pattern(PLAYER_WALK_3_VRAM_ADR);

            spr_set(weapon_id);
            spr_pattern(WEAPON_WALK_1_VRAM_ADRESS);

            if(player_axis == AXIS_RIGHT)
            {
                spr_x(player_pos_x+5);
            }

            else
            {
                spr_x(player_pos_x+11);
            }
        }


        else if(player_counter_anim == 9)
        {
            //spr_set(player_id);
            spr_pattern(PLAYER_IDLE_VRAM_ADR);

            spr_set(weapon_id);
            spr_pattern(WEAPON_IDLE_VRAM_ADRESS);
            spr_x(player_pos_x+8);
            weapon_y_offset = 16;
            //pr_y(player_pos_y+16);
        }


        else if(player_counter_anim == 12)
        {
            spr_pattern(PLAYER_WALK_4_VRAM_ADR);

            spr_set(weapon_id);
            weapon_y_offset = 14;
            //spr_y(player_pos_y+14);

            if(player_axis == AXIS_RIGHT)
            {
                spr_x(player_pos_x+12);
            }

            else
            {
                spr_x(player_pos_x+4);
            }
        }


        else if(player_counter_anim == 15)
        {
            spr_pattern(PLAYER_WALK_5_VRAM_ADR);

            spr_set(weapon_id);
            weapon_y_offset = 12;
            //spr_y(player_pos_y+12);

            if(player_axis == AXIS_RIGHT)
            {
                spr_x(player_pos_x+15);
            }

            else
            {
                spr_x(player_pos_x+1);
            }
        }


        else if(player_counter_anim == 18)
        {
            spr_pattern(PLAYER_WALK_6_VRAM_ADR);

            spr_set(weapon_id);
            weapon_y_offset = 14;
            //spr_y(player_pos_y+14);

            if(player_axis == AXIS_RIGHT)
            {
                spr_x(player_pos_x+12);
            }

            else
            {
                spr_x(player_pos_x+4);
            } 
        }


        else if(player_counter_anim == 19)
        {
            player_counter_anim = 0;
        }


        spr_set(weapon_id);
        spr_y(player_pos_y + weapon_y_offset);
        //player_counter_anim += 1;

    }


    else if(player_state == STATE_JUMP)
    {
        unsigned char i;
        i = 1;


        if(player_counter_anim == 0)
        {
            spr_set(player_id);
            spr_pattern(PLAYER_JUMP_VRAM_ADR);

            player_counter_anim = 1;
        }


        player_pos_y += TABLE_PLAYER_JUMP_V[player_index_jump];

        // CHECK COLLISION WITH CEILING //
        collision_PLAYER_BG( 15 , 8 );

        if(map_blk_flag == TILE_BG)
        {
            for(i=1 ; i<8 ; i++)
            {
                collision_PLAYER_BG( 15 , 8 + i );
                {
                    if(map_blk_flag == TILE_EMPTY)
                    {
                        player_pos_y += i;
                        break;
                    }
                }
            }
        }


        if(player_attack == FALSE)
        {
            spr_set(weapon_id);
            spr_y(player_pos_y+8);
        }

        
        else
        {
            if(player_counter_attack == 0)
            {
                spr_set(player_id);
                spr_pattern(PLAYER_JUMP_ATTACK_1_VRAM_ADR);

                spr_set(weapon_id);
                spr_pattern(WEAPON_ATTACK_1_VRAM_ADRESS);

                if(player_axis == AXIS_RIGHT)
                {
                    spr_x(player_pos_x-14);
                }

                else
                {
                    spr_x(player_pos_x+29);
                }

                spr_y(player_pos_y-8);
            }

            else if(player_counter_attack == 6)
            {
                spr_set(player_id);
                spr_pattern(PLAYER_JUMP_ATTACK_2_VRAM_ADR);

                spr_set(weapon_id);
                spr_pattern(WEAPON_ATTACK_2_VRAM_ADRESS);

                if(player_axis == AXIS_RIGHT)
                {
                    spr_x(player_pos_x+32);
                    
                }
                
                else
                {
                    spr_x(player_pos_x-16);
                }

                spr_y(player_pos_y+6);
            }

            else if(player_counter_attack == 7)
            {
                spr_set(chain_id);
                spr_y(player_pos_y);

                if(player_axis == AXIS_RIGHT)
                {
                    spr_x(player_pos_x+32);

                    spr_set(weapon_id);
                    spr_x(player_pos_x+48);
                }
                
                else
                {
                    spr_x(player_pos_x-16);

                    spr_set(weapon_id);
                    spr_x(player_pos_x-32);
                }
            }

            else if(player_counter_attack == 8)
            {
                spr_set(chain_id+1);
                spr_y(player_pos_y);

                if(player_axis == AXIS_RIGHT)
                {
                    spr_x(player_pos_x+48);

                    spr_set(weapon_id);
                    spr_x(player_pos_x+64);
                }
                
                else
                {
                    spr_x(player_pos_x-32);

                    spr_set(weapon_id);
                    spr_x(player_pos_x-48);
                }
            }

            else if(player_counter_attack == 9)
            {
                spr_set(chain_id+2);
                spr_y(player_pos_y);

                if(player_axis == AXIS_RIGHT)
                {
                    spr_x(player_pos_x+64);

                    spr_set(weapon_id);
                    spr_x(player_pos_x+80);
                }
                
                else
                {
                    spr_x(player_pos_x-48);

                    spr_set(weapon_id);
                    spr_x(player_pos_x-64);
                }
            }

            else if(player_counter_attack == 23)
            {
                spr_set(chain_id);
                spr_hide();

                spr_set(chain_id+1);
                spr_hide();

                spr_set(chain_id+2);
                spr_hide();

                spr_set(player_id);
                spr_pattern(PLAYER_HANG_VRAM_ADR);

                spr_set(weapon_id);
                spr_pattern(WEAPON_IDLE_VRAM_ADRESS);
                spr_y(player_pos_y+5);

                if(player_axis == AXIS_RIGHT)
                {
                    spr_x(player_pos_x+17);
                }

                else
                {
                    spr_x(player_pos_x-2);
                }

                player_attack = FALSE;
                player_counter_attack = 0;
                player_state = STATE_HANG;
            }


            player_counter_attack += 1;
        }

        spr_set(player_id);
        spr_y(player_pos_y);



        if(player_index_jump < 34)
        {
            player_index_jump += 1;
        }




		//--------------------------------------------------------------------------------------//
		//                                   FLOOR COLLISION                                    //
		//--------------------------------------------------------------------------------------//

        if(player_index_jump > 14)
        {
            // CHECK COLLISION WITH LEFT FLOOR //
            collision_PLAYER_BG( 10 , 32 );

            // IF PLAYER TOUCHES THE GROUND TO THE LEFT //
            if(map_blk_flag == TILE_BG)
            {
                // CALCULATE HOW MANY PIXELS THE PLAYER MOVED INTO THE GROUND //
                for(i=1; i<11 ; i++ )
                {
                    check_TILE_DEPTH( 10 , i);

                    if(map_blk_flag == TILE_EMPTY)
                    {
                        //spr_set(player_id);
                        spr_pattern(PLAYER_IDLE_VRAM_ADR);
                        player_pos_y -= (i - 1);
                        spr_y(player_pos_y);
                        break;
                    }

                }

                if(player_attack == FALSE)
                {
                    spr_set(weapon_id);
                    spr_x(player_pos_x+8);
                    spr_y(player_pos_y+16);
                }

                player_counter_anim = 1;
                player_index_jump = 0;
                //hit_wall = FALSE;

                if(player_attack == FALSE)
                {
                    player_state = STATE_IDLE;
                }
                
                return;
            }

            // IF PLAYER TOUCHES THE GROUND TO THE RIGHT //
            else
            {
                // CHECK COLLISION WITH RIGHT FLOOR //
                collision_PLAYER_BG( 22 , 32 );

                if(map_blk_flag == TILE_BG)
                {
                    // CALCULATE HOW MANY PIXELS THE PLAYER MOVED INTO THE GROUND //
                    for(i=1; i<11 ; i++ )
                    {
                        check_TILE_DEPTH( 22 , i);

                        if(map_blk_flag == TILE_EMPTY)
                        {
                            //spr_set(player_id);
                            spr_pattern(PLAYER_IDLE_VRAM_ADR);
                            player_pos_y -= (i - 1);
                            spr_y(player_pos_y);
                            break;
                        }

                    }

                    if(player_attack == FALSE)
                    {
                        spr_set(weapon_id);
                        spr_x(player_pos_x+8);
                        spr_y(player_pos_y+16);
                    }

                    player_counter_anim = 1;
                    player_index_jump = 0;

                    if(player_attack == FALSE)
                    {
                        player_state = STATE_IDLE;
                    }

                    return;
                }
            }
        }




		//--------------------------------------------------------------------------------------//
		//                                   LADDER COLLISION                                   //
		//--------------------------------------------------------------------------------------//

        collision_PLAYER_BG( 16 , 16 );

        // IF PLAYER HITS THE LADDER //
        if(map_blk_flag == TILE_LADDER)
        {
            // CAMERA GOES 8 PX BACKWARD //
            sgx_map_pxl_x = ( (sgx_map_pxl_x >> 3) << 3 );

            // SO WE UPDATE THE MAP //
            sgx_scroll_map();

            // CHECK IF THE PLAYER STANDS RIGHT TO THE LADDER //
            collision_PLAYER_BG( 31 , 16 );

            if(map_blk_flag == TILE_LADDER)
            {
                sgx_map_pxl_x += 8;
            }

            spr_pattern(PLAYER_HANG_VRAM_ADR);
            player_counter_anim = 0;
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
            spr_set(player_id);
            spr_pattern(PLAYER_JUMP_VRAM_ADR);

            player_counter_anim = 1;
        }


        // SELECT PLAYER SPRITE //
        spr_set(player_id);


		//**************************************************************************************//
		//                                        H MOVE                                        //
		//**************************************************************************************//

		//--------------------------------------------------------------------------------------//
		//                                    WALL COLLISION                                    //
		//--------------------------------------------------------------------------------------//

        // CHECK COLLISION WITH BOTTOM RIGHT WALL //
        collision_PLAYER_BG( 24 , 31 );

        if(map_blk_flag != TILE_BG)
        {
            // CHECK COLLISION WITH TOP RIGHT WALL //
            collision_PLAYER_BG( 24 , 15 );

            if(map_blk_flag == TILE_BG)
            {
                check_TILE_DEPTH( 15 , -16 );

                if(map_blk_flag == TILE_EMPTY && jump_ladder == TRUE)
                {
                    jump_ladder = FALSE;
                    player_index_fall = 0;
                    player_state = STATE_FALL;
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
            check_TILE_DEPTH( 15 , -16 );

            if(map_blk_flag == TILE_EMPTY && jump_ladder == TRUE)
            {
                jump_ladder = FALSE;
                hit_wall = TRUE;
                player_index_fall = 0;
                player_state = STATE_FALL;
                return;
            }
        }




		//**************************************************************************************//
		//                                        V MOVE                                        //
		//**************************************************************************************//

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




		//--------------------------------------------------------------------------------------//
		//                                   FLOOR COLLISION                                    //
		//--------------------------------------------------------------------------------------//

        if(player_index_jump > 14)
        {
            // CHECK COLLISION WITH LEFT FLOOR //
            collision_PLAYER_BG( 10 , 32 );

            // IF PLAYER TOUCHES THE GROUND TO THE LEFT //
            if(map_blk_flag == TILE_BG)
            {
                // CALCULATE HOW MANY PIXELS THE PLAYER MOVED INTO THE GROUND //
                for(i=1; i<11 ; i++)
                {
                    check_TILE_DEPTH( 10 , i);

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

                spr_set(weapon_id);
                spr_y(player_pos_y+8);

                player_counter_anim = 1;
                player_index_jump = 0;
                jump_ladder = FALSE;
                hit_wall = FALSE;
                jump_max_index = 34;
                player_state = STATE_IDLE;
                return;
            }

            // IF PLAYER TOUCHES THE GROUND TO THE RIGHT //
            else
            {
                // CHECK COLLISION WITH RIGHT FLOOR //
                collision_PLAYER_BG( 22 , 32 );

                if(map_blk_flag == TILE_BG)
                {
                    // CALCULATE HOW MANY PIXELS THE PLAYER MOVED INTO THE GROUND //
                    for(i=1; i<11 ; i++)
                    {
                        check_TILE_DEPTH( 22 , i);

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

                    spr_set(weapon_id);
                    spr_y(player_pos_y+8);

                    player_counter_anim = 1;
                    player_index_jump = 0;
                    jump_ladder = FALSE;
                    hit_wall = FALSE;
                    jump_max_index = 34;
                    player_state = STATE_IDLE;
                    return;
                }
            }
        }




		//--------------------------------------------------------------------------------------//
		//                                   LADDER COLLISION                                   //
		//--------------------------------------------------------------------------------------//

        if(player_index_jump > 4)
        {
            collision_PLAYER_BG( 16 , 16 );

            // IF PLAYER HITS THE LADDER //
            if(map_blk_flag == TILE_LADDER)
            {
                // CAMERA GOES 8 PX BACKWARD //
                sgx_map_pxl_x = ( (sgx_map_pxl_x >> 3) << 3 );

                // SO WE UPDATE THE MAP //
                sgx_scroll_map();

                // CHECK IF THE PLAYER STANDS RIGHT TO THE LADDER //
                collision_PLAYER_BG( 31 , 16 );

                if(map_blk_flag == TILE_LADDER)
                {
                    sgx_map_pxl_x += 8;
                }

                spr_pattern(PLAYER_HANG_VRAM_ADR);
                player_counter_anim = 0;
                player_index_jump = 0;
                jump_ladder = TRUE;
                jump_max_index = 29;
                player_state = STATE_HANG;
            }
        }


        // SET PLAYER SPRITE NEW POSITION //
        spr_y(player_pos_y);
        spr_set(weapon_id);
        spr_y(player_pos_y+8);
    }


    else if(player_state == STATE_JUMP_LEFT)
    {
        unsigned char i, camera_y_move;
        i = 1;


        // UPDATE PLAYER TILES //
        if(player_counter_anim == 0)
        {
            spr_set(player_id);
            spr_pattern(PLAYER_JUMP_VRAM_ADR);

            player_counter_anim = 1;
        }


        // SELECT PLAYER SPRITE //
        spr_set(player_id);


		//**************************************************************************************//
		//                                        H MOVE                                        //
		//**************************************************************************************//

		//--------------------------------------------------------------------------------------//
		//                                    WALL COLLISION                                    //
		//--------------------------------------------------------------------------------------//

        // CHECK COLLISION WITH BOTTOM LEFT WALL //
        collision_PLAYER_BG( 8 , 31 );

        if(map_blk_flag != TILE_BG)
        {
            // CHECK COLLISION WITH TOP RIGHT WALL //
            collision_PLAYER_BG( 8 , 15 );

            if(map_blk_flag == TILE_BG)
            {
                check_TILE_DEPTH( 15 , -16 );

                if(map_blk_flag == TILE_EMPTY && jump_ladder == TRUE)
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
            check_TILE_DEPTH( 15 , -16 );

            if(map_blk_flag == TILE_EMPTY && jump_ladder == TRUE)
            {
                jump_ladder = FALSE;
                hit_wall = TRUE;
                player_index_fall = 0;
                player_state = STATE_FALL;
                return;
            }
        }




		//**************************************************************************************//
		//                                        V MOVE                                        //
		//**************************************************************************************//

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




		//--------------------------------------------------------------------------------------//
		//                                   FLOOR COLLISION                                    //
		//--------------------------------------------------------------------------------------//

        if(player_index_jump > 14)
        {
            // CHECK COLLISION WITH LEFT FLOOR //
            collision_PLAYER_BG( 10 , 32 );

            if(map_blk_flag == TILE_BG)
            {
                // CALCULATE HOW MANY PIXELS THE PLAYER MOVED INTO THE GROUND //
                for(i=1; i<11 ; i++)
                {
                    check_TILE_DEPTH( 10 , i);

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

                spr_set(weapon_id);
                spr_y(player_pos_y+8);

                player_counter_anim = 1;
                player_index_jump = 0;
                jump_ladder = FALSE;
                hit_wall = FALSE;
                jump_max_index = 34;
                player_state = STATE_IDLE;
                return;
            }

            else
            {
                // CHECK COLLISION WITH RIGHT FLOOR //
                collision_PLAYER_BG( 22 , 32 );

                if(map_blk_flag == TILE_BG)
                {
                    // CALCULATE HOW MANY PIXELS THE PLAYER MOVED INTO THE GROUND //
                    for(i=1; i<11 ; i++)
                    {
                        check_TILE_DEPTH( 22 , i);

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

                    spr_set(weapon_id);
                    spr_y(player_pos_y+8);

                    player_counter_anim = 1;
                    player_index_jump = 0;
                    jump_ladder = FALSE;
                    hit_wall = FALSE;
                    jump_max_index = 34;
                    player_state = STATE_IDLE;
                    return;
                }
            }
        }




		//--------------------------------------------------------------------------------------//
		//                                   LADDER COLLISION                                   //
		//--------------------------------------------------------------------------------------//

        if(player_index_jump > 4)
        {
            collision_PLAYER_BG( 16 , 16 );

            if(map_blk_flag == TILE_LADDER)
            {
                // CAMERA GOES 8 PX BACKWARD //
                sgx_map_pxl_x = ( (sgx_map_pxl_x >> 3) << 3 );

                // SO WE UPDATE THE MAP //
                sgx_scroll_map();

                // CHECK IF THE PLAYER STANDS RIGHT TO THE LADDER //
                collision_PLAYER_BG( 31 , 16 );

                if(map_blk_flag == TILE_LADDER)
                {
                    sgx_map_pxl_x += 8;
                }

                spr_pattern(PLAYER_HANG_VRAM_ADR);
                player_counter_anim = 0;
                player_index_jump = 0;
                jump_ladder = TRUE;
                jump_max_index = 29;
                player_state = STATE_HANG;
            }
        }


        // SET PLAYER SPRITE NEW POSITION //
        spr_y(player_pos_y);

        spr_set(weapon_id);
        spr_y(player_pos_y+8);
    }


    else if(player_state == STATE_CROUCH)
    {
        recenter_CAMERA();
        
        if(player_counter_anim == 1)
        {
            spr_set(player_id);
            spr_pattern(PLAYER_CROUCH_VRAM_ADR);

            spr_set(weapon_id);
            spr_pattern(WEAPON_IDLE_VRAM_ADRESS);
            
            if(player_axis == AXIS_RIGHT)
            {
                spr_x(player_pos_x-1);
            }

            else
            {
                spr_x(player_pos_x+17);
            }

            //spr_y(player_pos_y+18);
            
            player_counter_anim = 0;
        }

        spr_set(weapon_id);
        spr_y(player_pos_y+18);
        //recenter_CAMERA();
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


        check_TILE_DEPTH( 15 , 0);


        if(map_blk_flag == TILE_BG)
        {
            // CALCULATE HOW MANY PIXELS THE PLAYER MOVED INTO THE GROUND //
            for(i=1; i<11 ; i++ )
            {
                check_TILE_DEPTH( 15 , i);//20


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
            fall_ladder = FALSE;
            hit_wall = FALSE;
            jump_max_index = 34;
            player_state = STATE_IDLE;
            return;
        }


        collision_PLAYER_BG( 16 , 16 );

        // IF PLAYER HITS THE LADDER //
        if(map_blk_flag == TILE_LADDER)
        {
            // CAMERA GOES 8 PX BACKWARD //
            sgx_map_pxl_x = ( (sgx_map_pxl_x >> 3) << 3 );

            // SO WE UPDATE THE MAP //
            sgx_scroll_map();

            // CHECK IF THE PLAYER STANDS RIGHT TO THE LADDER //
            collision_PLAYER_BG( 31 , 16 );

            if(map_blk_flag == TILE_LADDER)
            {
                sgx_map_pxl_x += 8;
            }

            spr_pattern(PLAYER_HANG_VRAM_ADR);
            player_counter_anim = 0;//1
            player_index_jump = 0;
            player_index_fall = 0;
            jump_ladder = TRUE;
            jump_max_index = 29;
            player_state = STATE_HANG;
            return;
        }

        spr_y(player_pos_y);

        spr_set(weapon_id);

        if(fall_ladder == TRUE || hit_wall == TRUE)
        {
            spr_y(player_pos_y+8);
        }
    }


    else if(player_state == STATE_HANG)
    {
        recenter_CAMERA();

        if(player_attack == FALSE)
        {
            spr_set(weapon_id);
            spr_pattern(WEAPON_IDLE_VRAM_ADRESS);
            spr_y(player_pos_y+5);

            if(player_axis == AXIS_RIGHT)
            {
                spr_x(player_pos_x+17);
            }

            else
            {
                spr_x(player_pos_x-2);
            }
            
            player_counter_anim = 0;
        }
    }


    else if(player_state == STATE_CLIMB_UP)
    {
        if(player_counter_anim == 0)
        {
            spr_set(player_id);
            spr_pattern(PLAYER_CLIMB_1_VRAM_ADR); 
        }

        else if(player_counter_anim == 2)
        {
            spr_set(player_id);
            spr_pattern(PLAYER_CLIMB_2_VRAM_ADR); 
        }

        else if(player_counter_anim == 5)
        {
            spr_set(player_id);
            spr_pattern(PLAYER_CLIMB_3_VRAM_ADR); 
        }

        else if(player_counter_anim == 8)
        {
            spr_set(player_id);
            spr_pattern(PLAYER_CLIMB_4_VRAM_ADR); 
        }

        else if(player_counter_anim == 11)
        {
            spr_set(player_id);
            spr_pattern(PLAYER_CLIMB_5_VRAM_ADR); 
        }

        else if(player_counter_anim == 14)
        {
            spr_set(player_id);
            spr_pattern(PLAYER_CLIMB_6_VRAM_ADR); 
        }

        else if(player_counter_anim == 17)
        {
            spr_set(player_id);
            spr_pattern(PLAYER_CLIMB_3_VRAM_ADR); 
        }

        else if(player_counter_anim == 20)
        {
            spr_set(player_id);
            spr_pattern(PLAYER_CLIMB_2_VRAM_ADR); 
        }


        player_counter_anim += 1;

        if(player_counter_anim == 22)
        {
            player_counter_anim = 0;
        }

        recenter_CAMERA();
    }


    else if(player_state == STATE_CLIMB_DOWN)
    {
        if(player_counter_anim == 0)
        {
            spr_set(player_id);
            spr_pattern(PLAYER_CLIMB_1_VRAM_ADR); 
        }

        else if(player_counter_anim == 2)
        {
            spr_set(player_id);
            spr_pattern(PLAYER_CLIMB_2_VRAM_ADR); 
        }

        else if(player_counter_anim == 5)
        {
            spr_set(player_id);
            spr_pattern(PLAYER_CLIMB_3_VRAM_ADR); 
        }

        else if(player_counter_anim == 8)
        {
            spr_set(player_id);
            spr_pattern(PLAYER_CLIMB_4_VRAM_ADR); 
        }

        else if(player_counter_anim == 11)
        {
            spr_set(player_id);
            spr_pattern(PLAYER_CLIMB_5_VRAM_ADR); 
        }

        else if(player_counter_anim == 14)
        {
            spr_set(player_id);
            spr_pattern(PLAYER_CLIMB_4_VRAM_ADR); 
        }

        else if(player_counter_anim == 17)
        {
            spr_set(player_id);
            spr_pattern(PLAYER_CLIMB_3_VRAM_ADR); 
        }

        else if(player_counter_anim == 20)
        {
            spr_set(player_id);
            spr_pattern(PLAYER_CLIMB_2_VRAM_ADR); 
        }


        player_counter_anim += 1;

        if(player_counter_anim == 22)
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
            spr_set(player_id);
            spr_pattern(PLAYER_JUMP_VRAM_ADR); 

            player_counter_anim = 1;
        }


        player_pos_y += TABLE_PLAYER_JUMP_V[player_index_jump];

        // CHECK COLLISION WITH CEILING //
        collision_PLAYER_BG( 15 , 8 );

        if(map_blk_flag == TILE_BG)
        {
            for(i=1 ; i<8 ; i++)
            {
                collision_PLAYER_BG( 15 , 8 + i );
                {
                    if(map_blk_flag == TILE_EMPTY)
                    {
                        player_pos_y += i;
                        break;
                    }
                }
            }
        }

        spr_set(player_id);
        spr_y(player_pos_y);



        if(player_index_jump < 34)
        {
            player_index_jump += 1;
        }




		//--------------------------------------------------------------------------------------//
		//                                   LADDER COLLISION                                   //
		//--------------------------------------------------------------------------------------//

        if(player_index_jump > 18)
        {
            // CHECK COLLISION WITH LADDERS //
            collision_PLAYER_BG( 16 , 8 );

            // IF PLAYER HITS THE LADDER //
            if(map_blk_flag == TILE_LADDER)
            {
                // CAMERA GOES 8 PX BACKWARD //
                sgx_map_pxl_x = ( (sgx_map_pxl_x >> 3) << 3 );

                // SO WE UPDATE THE MAP //
                sgx_scroll_map();

                // CHECK IF THE PLAYER STANDS RIGHT TO THE LADDER //
                collision_PLAYER_BG( 31 , 8 );

                if(map_blk_flag == TILE_LADDER)
                {
                    sgx_map_pxl_x += 8;
                }

                //spr_set(player_id);
                spr_pattern(PLAYER_HANG_VRAM_ADR);

                player_counter_anim = 0;//
                player_index_jump = 0;
                jump_ladder = TRUE;
                jump_max_index = 29;
                player_state = STATE_HANG;
            }
        }

        spr_set(weapon_id);
        spr_y(player_pos_y+8);
    }

}


void update_WEAPON()
{
    if(player_state == STATE_ATTACK)
    {
        char i;
        
        recenter_CAMERA();

        if(player_counter_attack < 7)
        {
            spr_set(player_id);
            spr_pattern(PLAYER_ATTACK_1_VRAM_ADR);

            spr_set(weapon_id);
            spr_pattern(WEAPON_ATTACK_1_VRAM_ADRESS);

            if(player_axis == AXIS_RIGHT)
            {
                spr_x(player_pos_x-13);
            }

            else
            {
                spr_x(player_pos_x+29);
            }

            weapon_y_offset = -8;
            spr_y(player_pos_y + weapon_y_offset);
        }

        else if(player_counter_attack == 23)
        {
            spr_set(chain_id);
            spr_hide();

            spr_set(chain_id+1);
            spr_hide();

            spr_set(chain_id+2);
            spr_hide();

            spr_set(player_id);
            spr_pattern(PLAYER_IDLE_VRAM_ADR);

            spr_set(weapon_id);
            spr_pattern(WEAPON_IDLE_VRAM_ADRESS);
            spr_x(player_pos_x+8);
            spr_y(player_pos_y+16);

            player_attack = FALSE;
            player_counter_anim = 1;
            player_state = STATE_IDLE;
            return;
        }

        // CHAIN ANIMATION //
        if(chain_unfold == TRUE)
        {
            if(player_counter_attack == 6)
            {
                spr_set(player_id);
                spr_pattern(PLAYER_ATTACK_2_VRAM_ADR);

                spr_set(weapon_id);
                spr_pattern(WEAPON_ATTACK_2_VRAM_ADRESS);

                if(player_axis == AXIS_RIGHT)
                {
                    spr_x(player_pos_x+32);
                    
                }
                
                else
                {
                    spr_x(player_pos_x-16);
                }

                weapon_y_offset = 6;
                spr_y(player_pos_y + weapon_y_offset);

                collision_WEAPON_OBJECTS();
            }

            else if(player_counter_attack == 7)
            {
                list_chain_active[0] = TRUE;
                spr_set(chain_id);

                if(player_axis == AXIS_RIGHT)
                {
                    spr_x(player_pos_x+32);

                    spr_set(weapon_id);
                    spr_x(player_pos_x+48);
                }
                
                else
                {
                    spr_x(player_pos_x-16);

                    spr_set(weapon_id);
                    spr_x(player_pos_x-32);
                }

                spr_y(player_pos_y + weapon_y_offset);

                collision_WEAPON_OBJECTS();
            }

            else if(player_counter_attack == 8)
            {
                list_chain_active[1] = TRUE;
                spr_set(chain_id+1);

                if(player_axis == AXIS_RIGHT)
                {
                    spr_x(player_pos_x+48);

                    spr_set(weapon_id);
                    spr_x(player_pos_x+64);
                }
                
                else
                {
                    spr_x(player_pos_x-32);

                    spr_set(weapon_id);
                    spr_x(player_pos_x-48);
                }

                spr_y(player_pos_y + weapon_y_offset);

                collision_WEAPON_OBJECTS();
            }

            else if(player_counter_attack == 9)
            {
                list_chain_active[2] = TRUE;
                spr_set(chain_id+2);

                if(player_axis == AXIS_RIGHT)
                {
                    spr_x(player_pos_x+64);

                    spr_set(weapon_id);
                    spr_x(player_pos_x+80);
                }
                
                else
                {
                    spr_x(player_pos_x-48);

                    spr_set(weapon_id);
                    spr_x(player_pos_x-64);
                }

                spr_y(player_pos_y + weapon_y_offset);

                collision_WEAPON_OBJECTS();
            }
        }


        player_counter_attack += 1;


        // SET CHAIN Y POSITION //
        for(i=0 ; i<3 ; i++)
        {
            spr_set(chain_id+i);

            spr_y( ((player_pos_y + 16) * list_chain_active[i]) - 16); //list_chain_active[0] = TRUE;
        }
    }


    else if(player_state == STATE_CROUCH_ATTACK)
    {
        char i;
        
        recenter_CAMERA();

        if(player_counter_attack < 7)
        {
            spr_set(player_id);
            spr_pattern(PLAYER_CROUCH_ATTACK_1_VRAM_ADR);

            spr_set(weapon_id);
            spr_pattern(WEAPON_ATTACK_1_VRAM_ADRESS);

            if(player_axis == AXIS_RIGHT)
            {
                spr_x(player_pos_x-16);
            }

            else
            {
                spr_x(player_pos_x+32);
            }

            weapon_y_offset = 0;
            spr_y(player_pos_y + weapon_y_offset);
        }

        else if(player_counter_attack == 23)
        {
            spr_set(chain_id);
            spr_hide();

            spr_set(chain_id+1);
            spr_hide();

            spr_set(chain_id+2);
            spr_hide();

            spr_set(player_id);
            spr_pattern(PLAYER_CROUCH_VRAM_ADR);

            spr_set(weapon_id);
            spr_pattern(WEAPON_IDLE_VRAM_ADRESS);
            
            if(player_axis == AXIS_RIGHT)
            {
                spr_x(player_pos_x-1);
            }

            else
            {
                spr_x(player_pos_x+17);
            }

            spr_y(player_pos_y+18);

            player_attack = FALSE;
            player_counter_attack = 1;
            player_state = STATE_CROUCH;
            return;
        }

        // CHAIN ANIMATION //
        if(chain_unfold == TRUE)
        {
            if(player_counter_attack == 6)
            {
                spr_set(player_id);
                spr_pattern(PLAYER_CROUCH_ATTACK_2_VRAM_ADR);

                spr_set(weapon_id);
                spr_pattern(WEAPON_ATTACK_2_VRAM_ADRESS);

                if(player_axis == AXIS_RIGHT)
                {
                    spr_x(player_pos_x+32);
                    
                }
                
                else
                {
                    spr_x(player_pos_x-16);
                }

                weapon_y_offset = 14;
                spr_y(player_pos_y + weapon_y_offset);

                collision_WEAPON_OBJECTS();
            }

            else if(player_counter_attack == 7)
            {
                list_chain_active[0] = TRUE;
                spr_set(chain_id);

                if(player_axis == AXIS_RIGHT)
                {
                    spr_x(player_pos_x+32);

                    spr_set(weapon_id);
                    spr_x(player_pos_x+48);
                }
                
                else
                {
                    spr_x(player_pos_x-16);

                    spr_set(weapon_id);
                    spr_x(player_pos_x-32);
                }

                spr_y(player_pos_y + weapon_y_offset);

                collision_WEAPON_OBJECTS();
            }

            else if(player_counter_attack == 8)
            {
                list_chain_active[1] = TRUE;
                spr_set(chain_id+1);

                if(player_axis == AXIS_RIGHT)
                {
                    spr_x(player_pos_x+48);

                    spr_set(weapon_id);
                    spr_x(player_pos_x+64);
                }
                
                else
                {
                    spr_x(player_pos_x-32);

                    spr_set(weapon_id);
                    spr_x(player_pos_x-48);
                }

                spr_y(player_pos_y + weapon_y_offset);

                collision_WEAPON_OBJECTS();
            }

            else if(player_counter_attack == 9)
            {
                list_chain_active[2] = TRUE;
                spr_set(chain_id+2);

                if(player_axis == AXIS_RIGHT)
                {
                    spr_x(player_pos_x+64);

                    spr_set(weapon_id);
                    spr_x(player_pos_x+80);
                }
                
                else
                {
                    spr_x(player_pos_x-48);

                    spr_set(weapon_id);
                    spr_x(player_pos_x-64);
                }

                spr_y(player_pos_y + weapon_y_offset);

                collision_WEAPON_OBJECTS();
            }
        }


        player_counter_attack += 1;


        // SET CHAIN Y POSITION //
        for(i=0 ; i<3 ; i++)
        {
            spr_set(chain_id+i);

            spr_y( ((player_pos_y + 24) * list_chain_active[i]) - 16); //list_chain_active[0] = TRUE;
        }
    }


    else if(player_state == STATE_HANG)
    {
        if(player_attack == TRUE)
        {
            if(player_counter_attack < 7)
            {
                spr_set(player_id);
                spr_pattern(PLAYER_HANG_ATTACK_1_VRAM_ADR);

                spr_set(weapon_id);
                spr_pattern(WEAPON_ATTACK_1_VRAM_ADRESS);

                if(player_axis == AXIS_RIGHT)
                {
                    spr_x(player_pos_x-14);
                }

                else
                {
                    spr_x(player_pos_x+29);
                }

                spr_y(player_pos_y-8);
            }

            else if(player_counter_attack == 23)
            {
                spr_set(chain_id);
                spr_hide();

                spr_set(chain_id+1);
                spr_hide();

                spr_set(chain_id+2);
                spr_hide();

                spr_set(player_id);
                spr_pattern(PLAYER_HANG_VRAM_ADR);

                spr_set(weapon_id);
                spr_pattern(WEAPON_IDLE_VRAM_ADRESS);
                spr_y(player_pos_y+5);

                if(player_axis == AXIS_RIGHT)
                {
                    spr_x(player_pos_x+17);
                }

                else
                {
                    spr_x(player_pos_x-2);
                }

                player_attack = FALSE;
                player_counter_attack = 0;
                player_state = STATE_HANG;
            }

            // CHAIN ANIMATION //
            if(chain_unfold == TRUE)
            {
                if(player_counter_attack == 6)
                {
                    spr_set(player_id);
                    spr_pattern(PLAYER_HANG_ATTACK_2_VRAM_ADR);

                    spr_set(weapon_id);
                    spr_pattern(WEAPON_ATTACK_2_VRAM_ADRESS);

                    if(player_axis == AXIS_RIGHT)
                    {
                        spr_x(player_pos_x+32);
                        
                    }
                    
                    else
                    {
                        spr_x(player_pos_x-16);
                    }

                    spr_y(player_pos_y+6);

                    collision_WEAPON_OBJECTS();
                }

                else if(player_counter_attack == 7)
                {
                    spr_set(chain_id);
                    spr_y(player_pos_y);

                    if(player_axis == AXIS_RIGHT)
                    {
                        spr_x(player_pos_x+32);

                        spr_set(weapon_id);
                        spr_x(player_pos_x+48);
                    }
                    
                    else
                    {
                        spr_x(player_pos_x-16);

                        spr_set(weapon_id);
                        spr_x(player_pos_x-32);
                    }

                    collision_WEAPON_OBJECTS();
                }

                else if(player_counter_attack == 8)
                {
                    spr_set(chain_id+1);
                    spr_y(player_pos_y);

                    if(player_axis == AXIS_RIGHT)
                    {
                        spr_x(player_pos_x+48);

                        spr_set(weapon_id);
                        spr_x(player_pos_x+64);
                    }
                    
                    else
                    {
                        spr_x(player_pos_x-32);

                        spr_set(weapon_id);
                        spr_x(player_pos_x-48);
                    }

                    collision_WEAPON_OBJECTS();
                }

                else if(player_counter_attack == 9)
                {
                    spr_set(chain_id+2);
                    spr_y(player_pos_y);

                    if(player_axis == AXIS_RIGHT)
                    {
                        spr_x(player_pos_x+64);

                        spr_set(weapon_id);
                        spr_x(player_pos_x+80);
                    }
                    
                    else
                    {
                        spr_x(player_pos_x-48);

                        spr_set(weapon_id);
                        spr_x(player_pos_x-64);
                    }

                    collision_WEAPON_OBJECTS();
                }
            }


            player_counter_attack += 1;
        } 
    }
}
