#ifndef __SDL_PLOT_QUEUE__
#define __SDL_PLOT_QUEUE__
#include "../config/sdl_config.h"
#include "../config/general_config.h"
#include "sdl_utils.h"
#include "../data/mewaajacune_utils.h"
#include "../config/nijcyota_utils.h"
void sdl_draw_1d_plot(__sdl_screen_object_t *obj_sdl, 
    __iicu_mewaajacune_t *_mewaajacune, 
    __iicu_nijcyota_t *nujcyota);
#endif 