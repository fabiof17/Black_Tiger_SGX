#include "huc.h"
#include "hucc-scroll.h"
#include "hucc-chrmap.h"
#include "hucc-blkmap.h"







void joypad_BUTTONS_TITLE()
{
    int selector_pos;
    
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
            selector_pos = 144;
            spr_y(selector_pos);
        }

        else if(selector_pos == 168)
        {
            selector_pos = 160;
            spr_y(selector_pos);
        }
    }


    else if(joytrg(JOYPAD_1) & JOY_DOWN)
    {
        spr_set(0);
        selector_pos = spr_get_y();

        if(selector_pos == 144)
        {
            selector_pos = 160;
            spr_y(selector_pos);
        }

        else if(selector_pos == 160)
        {
            selector_pos = 168;
            spr_y(selector_pos);
        }        
    }


    else if(joytrg(JOYPAD_1) & JOY_I || joytrg(JOYPAD_1) & JOY_II || joytrg(JOYPAD_1) & JOY_RUN)
    {
        spr_set(0);
        selector_pos = spr_get_y();

        // IF CURSOR IS ON START GAME //
        if(selector_pos == 144)
        {
            // DISABLE DISPLAY //
            disp_off();

            sequence_loaded = FALSE;

            sequence_id = SEQUENCE_INTRO;
        }
    }
}










