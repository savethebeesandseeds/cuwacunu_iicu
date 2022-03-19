#ifndef __SDL_PLOT_ORBITAL__
#define __SDL_PLOT_ORBITAL__
#include "../config/sdl_config.h"
#include "../sdl_tools/sdl_utils.h"
#include "../sdl_tools/sdl_object.h"
#include "../data/kemu_utils.h"
#include "../data/nijcyota_utils.h"
#include "../data/mewaajacune_utils.h"
void sdl_draw_1d_orbital(__sdl_screen_object_t * obj_sdl, 
    __iicu_mewaajacune_t *_mewaajacune, 
    __iicu_nijcyota_t *_nijcyota,
    __iicu_staticques_t *_staticques);
#endif