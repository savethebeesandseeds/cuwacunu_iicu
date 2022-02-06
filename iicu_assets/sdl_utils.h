#ifndef __THREAD_CONFIG__
#define __THREAD_CONFIG__
#include "plotsdl/sdl_plot.h"
#include "sdl_config.h"
#ifdef __ANDROID__
#   include "SDL.h"
#   include "SDL_ttf.h"
#   include "android/log.h"
#else
#   include "SDL2/SDL.h"
#   include "SDL2/SDL_ttf.h"
#endif
int wait_for_sdl_event(SDL_Event event);
#endif