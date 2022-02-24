#ifndef __SDL_PLOT_QUEUE__
#define __SDL_PLOT_QUEUE__
#ifdef __ANDROID__
#	include "SDL.h"
#	include "SDL_ttf.h"
#	include "SDL_image.h"
#else
#	include "SDL2/SDL.h"
#	include "SDL2/SDL_ttf.h"
#	include "SDL2/SDL_image.h"
#endif
#include "sdl_utils.h"
#include "../data/queue_utils.h"
#include "../config/general_config.h"
/*
    function: sdl_draw_y_plot_queue
    comment: x coordinates are assumed equispaced and ordered as in the queue
*/
void sdl_draw_y_plot_queue(SDL_Renderer * renderer, 
    __mewaajacune_t *_mewaajacune, 
    int alliu_index, 
    int box_x, 
    int box_y, 
    int box_w, 
    int box_h, 
    SDL_Color line_color, 
    ___cwcn_bool_t sdl_draw_line, 
    ___cwcn_bool_t draw_dot);
void draw_dot(SDL_Renderer * renderer, int32_t centreX, int32_t centreY, int32_t radius);
#endif 