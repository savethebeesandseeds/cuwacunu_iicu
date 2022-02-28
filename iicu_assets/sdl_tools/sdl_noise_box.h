#ifndef __NOISE_BOX__
#define __NOISE_BOX__
#include "../config/general_config.h"
#include "../config/sdl_config.h"
#include "../sdl_tools/sdl_utils.h"
#include "../sdl_tools/sdl_object.h"
#include "../config/nijcyota_utils.h"
#include "../data/mewaajacune_utils.h"
#include "../sdl_tools/sdl_plot_queue.h"
void sdl_draw_noise_box(__sdl_screen_object_t *obj_sdl, __iicu_mewaajacune_t *_mewaajacune, __iicu_nijcyota_t *_nijcyota);
#endif