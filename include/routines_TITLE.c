#include "huc.h"
#include "hucc-scroll.h"
#include "hucc-chrmap.h"
#include "hucc-blkmap.h"







void joypad_BUTTONS_TITLE()
{
    char selector_pos;
    
    if(joytrg(JOYPAD_1) & JOY_RIGHT)
    {   
        spr_set(0);
        selector_pos = spr_get_y();

        if(selector_pos == 160)
        {
            if(life_amount < 9)
            {
                life_amount += 1;
                put_number(life_amount   	,  1 , 20 , 20);
            }
        }

        else if(selector_pos == 168)
        {
            if(credits_amount < 5)
            {
                credits_amount += 1;
                put_number(credits_amount   ,  1 , 20 , 21);
            }
        }
    }

    
    else if(joytrg(JOYPAD_1) & JOY_LEFT)
    {
        spr_set(0);
        selector_pos = spr_get_y();

        if(selector_pos == 160)
        {
            if(life_amount > 3)
            {
                life_amount -= 1;
                put_number(life_amount   	,  1 , 20 , 20);
            }
        }

        else if(selector_pos == 168)
        {
            if(credits_amount > 2)
            {
                credits_amount -= 1;
                put_number(credits_amount   ,  1 , 20 , 21);
            }
        }
    }


    else if(joytrg(JOYPAD_1) & JOY_UP)
    {
        spr_set(0);
        selector_pos = spr_get_y();

        if(selector_pos == 160)
        {
            spr_y(144);
        }

        else if(selector_pos == 168)
        {
            spr_y(160);
        }
    }


    else if(joytrg(JOYPAD_1) & JOY_DOWN)
    {
        spr_set(0);
        selector_pos = spr_get_y();

        if(selector_pos == 144)
        {
            spr_y(160);
        }

        else if(selector_pos == 160)
        {
            spr_y(168);
        }        
    }


    else if(joytrg(JOYPAD_1) & JOY_I)
    {
        spr_set(0);
        selector_pos = spr_get_y();
    }
}










