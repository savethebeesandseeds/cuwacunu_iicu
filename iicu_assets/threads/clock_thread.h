#ifndef __CLOCK_STATE_THREAD__
#define __CLOCK_STATE_THREAD__
#include <stdio.h>
#include <pthread.h>
#ifdef __ANDROID__
#   include "SDL.h"
#   include "SDL_ttf.h"
#   include "android/log.h"
#else
#   include "SDL2/SDL.h"
#   include "SDL2/SDL_ttf.h"
#endif
#include "../config/threads_config.h"
#include "../sdl_tools/sdl_utils.h"
void *IICU_clock_thread(void *threadid);
#endif