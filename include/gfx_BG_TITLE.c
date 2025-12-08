#include "huc.h"
#include "hucc-scroll.h"
#include "hucc-chrmap.h"
#include "hucc-blkmap.h"








#incchr(tileset_FONT_TITLE,"res/maps/tiles_FONT_TITLE.png");


//**************************************************************************************//
//                                                                                      //
//                                        TITLE                                         //
//                                                                                      //
//**************************************************************************************//

#incchr(tileset_TITLE_BG_B, "res/maps/tilemap_TITLE_BG_B.png", _OPTIMIZE)

#incbat(tilemap_TITLE_BG_B,"res/maps/tilemap_TITLE_BG_B.png", 0x1000 , 32 , 28 , tileset_TITLE_BG_B);

#incpal(palette_TITLE, "res/maps/tilemap_TITLE_BG_B.png")