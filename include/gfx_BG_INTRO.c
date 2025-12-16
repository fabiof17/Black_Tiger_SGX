#include "huc.h"
#include "hucc-scroll.h"
#include "hucc-chrmap.h"
#include "hucc-blkmap.h"








#incchr(tileset_FONT_INTRO,"res/maps/tiles_FONT_INTRO.png");

#incpal(palette_FONT_INTRO, "res/maps/tiles_FONT_INTRO.png")

#incpal(palette_BLACK, "res/palettes/palette_BLACK.png")


//**************************************************************************************//
//                                                                                      //
//                                        TITLE                                         //
//                                                                                      //
//**************************************************************************************//

#incchr(tileset_INTRO_BG_B, "res/maps/tilemap_INTRO_BG_B.png", _OPTIMIZE)
#incbat(tilemap_INTRO_BG_B,"res/maps/tilemap_INTRO_BG_B.png", 0x1000 , 32 , 28 , tileset_INTRO_BG_B);

#incchr(tileset_INTRO_BG_A, "res/maps/tilemap_INTRO_BG_A.png", _OPTIMIZE)
#incbat(tilemap_INTRO_BG_A,"res/maps/tilemap_INTRO_BG_A.png", 0x1000 , 64 , 64 , tileset_INTRO_BG_A);

#incpal(palette_INTRO_1, "res/maps/tilemap_INTRO_BG_B.png")
#incpal(palette_INTRO_2, "res/palettes/palette_INTRO_2.png")
#incpal(palette_INTRO_3, "res/palettes/palette_INTRO_3.png")

