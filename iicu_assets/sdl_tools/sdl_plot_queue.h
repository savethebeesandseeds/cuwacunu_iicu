#ifndef __SDL_PLOT_QUEUE__
#define __SDL_PLOT_QUEUE__
#include "../config/sdl_config.h"
#include "../config/general_config.h"
#include "sdl_utils.h"
#include "../data/mewaajacune_utils.h"
#include "../data/nijcyota_utils.h"
void sdl_draw_1d_plot(__sdl_screen_object_t *obj_sdl, 
    __iicu_mewaajacune_t *_mewaajacune, 
    int alliu_index,
    int box_x,
    int box_y,
    int box_w,
    int box_h,
    SDL_Color line_color,
    ___cwcn_bool_t draw_line,
    ___cwcn_bool_t draw_perpendicular,
    ___cwcn_bool_t draw_dot);
#endif 