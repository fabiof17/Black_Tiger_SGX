#include "huc.h"
#include "hucc-scroll.h"
#include "hucc-chrmap.h"
#include "hucc-blkmap.h"








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
}










