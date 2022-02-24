#ifndef __CWCN_PLOT__
#define __CWCN_PLOT__
#ifdef __ANDROID__
#	include "SDL.h"
#	include "SDL_ttf.h"
#	define APP_NAME "plot_sdl_impl"
#else
#	include "SDL2/SDL.h"
#	include "SDL2/SDL_ttf.h"
#endif
#include "sdl_utils.h"
#include "../config/sdl_config.h"
#include "sdl_object.h"

#endif