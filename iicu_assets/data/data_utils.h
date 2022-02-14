#ifndef __DATA_UTILS__
#define __DATA_UTILS__
#include "stdio.h"
#ifdef __ANDROID__
#   include "SDL.h"
#   include "SDL_ttf.h"
#   include "android/log.h"
#else
#   include "SDL2/SDL.h"
#   include "SDL2/SDL_ttf.h"
#endif
#include "../sdl_tools/sdl_screen.h"
void populate_central_plot_coordinate_list(sdl_screen_object_t *obj_sdl);
#endif