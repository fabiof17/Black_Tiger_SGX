#include "huc.h"
#include "hucc-scroll.h"
#include "hucc-chrmap.h"
#include "hucc-blkmap.h"







void display_TIME_SHOP()
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
                shop_counter = 0;    
                shop_phase = SHOP_PHASE_EXIT;
            }
        }
    } 
}



void joypad_BUTTONS_SHOP()
{
    if(joytrg(JOYPAD_1) & JOY_RIGHT)
    {   
        char max_index;
        
        if(index_y == 0)
        {
            max_index = 4;
        }

        else
        {
            max_index = 5;
        }

        if(index_x < max_index)
        {
            index_x += 1;
            item_index = (index_x + (index_y * 5));

            spr_set(0);
            spr_x(TABLE_CURSOR_POS_X[item_index]);
        }
    }

    
    else if(joytrg(JOYPAD_1) & JOY_LEFT)
    {
        if(index_x > 0)
        {
            index_x -= 1;
            item_index = (index_x + (index_y * 5));

            spr_set(0);
            spr_x(TABLE_CURSOR_POS_X[item_index]);
        }
    }


    else if(joytrg(JOYPAD_1) & JOY_UP)
    {
        if(index_y > 0)
        {
            if(item_index != 10)
            {
                index_y -= 1;
                item_index = (index_x + (index_y * 5));

                spr_set(0);
                spr_y(144);
            }
        }
    }


    else if(joytrg(JOYPAD_1) & JOY_DOWN)
    {
        if(index_y < 1)
        {
            index_y += 1;
            item_index = (index_x + (index_y * 5));

            spr_set(0);
            spr_y(168);
        }
    }


    else if(joytrg(JOYPAD_1) & JOY_I)
    {
        switch(item_index)
        {
            // WEAPON 2 //
            case 0:
                if(zenny_amount >= shop_prices[0])
                {
                    if(weapon_level < 2)
                    {
                        weapon_level = 2;
                        load_vram( WEAPON_VRAM_ADR, tileset_WEAPON_2, SIZEOF(tileset_WEAPON_2) >> 1 );

                        zenny_amount -= shop_prices[0];
                        display_ZENNY();
                    }
                }

                break;   


            // WEAPON 4 //
            case 1:
                if(zenny_amount >= shop_prices[1])
                {
                    if(weapon_level < 4)
                    {
                        weapon_level = 4;
                        load_vram( WEAPON_VRAM_ADR, tileset_WEAPON_4, SIZEOF(tileset_WEAPON_4) >> 1 );

                        zenny_amount -= shop_prices[1];
                        display_ZENNY();
                    }
                }

                break; 


            // WEAPON 5 //
            case 2:
                if(zenny_amount >= shop_prices[2])
                {
                    if(weapon_level < 5)
                    {
                        weapon_level = 5;
                        load_vram( WEAPON_VRAM_ADR, tileset_WEAPON_5, SIZEOF(tileset_WEAPON_5) >> 1 );

                        zenny_amount -= shop_prices[2];
                        display_ZENNY();
                    }
                }

                break;   


            // WEAPON 8 //
            case 3:
                if(zenny_amount >= shop_prices[3])
                {
                    if(weapon_level < 8)
                    {
                        weapon_level = 8;
                        load_vram( WEAPON_VRAM_ADR, tileset_WEAPON_8, SIZEOF(tileset_WEAPON_8) >> 1 );

                        zenny_amount -= shop_prices[3];
                        display_ZENNY();
                    }
                }

                break;  


            // KEY //
            case 4:
                if(zenny_amount >= shop_prices[4])
                {
                    key_amount += 1;

                    zenny_amount -= shop_prices[4];
                    display_KEY();
                }

                break;   


            // ARMOR 1 //
            case 5:
                if(zenny_amount >= shop_prices[5])
                {
                    if(armor_level < 1)
                    {
                        armor_level = 1;
                        load_vram( ARMOR_VRAM_ADR, tileset_ARMOR_1, SIZEOF(tileset_ARMOR_1) >> 1 );

                        zenny_amount -= shop_prices[5];
                        display_ZENNY();
                    }
                }

                break;   


            // ARMOR 2 //
            case 6:
                if(zenny_amount >= shop_prices[6])
                {
                    if(armor_level < 4)
                    {
                        armor_level = 4;
                        load_vram( ARMOR_VRAM_ADR, tileset_ARMOR_2, SIZEOF(tileset_ARMOR_2) >> 1 );

                        zenny_amount -= shop_prices[6];
                        display_ZENNY();
                    }
                }

                break;    


            // ARMOR 4 //
            case 7:
                if(zenny_amount >= shop_prices[7])
                {
                    if(armor_level < 5)
                    {
                        armor_level = 5;
                        load_vram( ARMOR_VRAM_ADR, tileset_ARMOR_4, SIZEOF(tileset_ARMOR_4) >> 1 );

                        zenny_amount -= shop_prices[7];
                        display_ZENNY();
                    }
                }

                break;   


            // ARMOR 8 //
            case 8:
                if(zenny_amount >= shop_prices[8])
                {
                    if(armor_level < 8)
                    {
                        armor_level = 8;
                        load_vram( ARMOR_VRAM_ADR, tileset_ARMOR_8, SIZEOF(tileset_ARMOR_8) >> 1 );

                        zenny_amount -= shop_prices[8];
                        display_ZENNY();
                    }
                }

                break;   


            // POTION //
            case 9:
                if(zenny_amount >= shop_prices[9])
                {
                    potion_amount += 1;

                    zenny_amount -= shop_prices[9];
                    display_POTION();
                }

                break;   


            // EXIT //
            case 10:
                shop_counter = 0;    
                shop_phase = SHOP_PHASE_EXIT;

                break;                  
        }
    }
}










