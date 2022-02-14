#ifndef __CUWACUNU_IICU__
#define __CUWACUNU_IICU__
#include "time.h"
#include "stdio.h"
#include <pthread.h>
#ifdef __ANDROID__
#   include "SDL.h"
#   include "SDL_ttf.h"
#   include "android/log.h"
#else
#   include "SDL2/SDL.h"
#   include "SDL2/SDL_ttf.h"
#endif
#ifdef __unix__
#include "unistd.h"
#define __UNIX_OS__
#elif defined(_WIN32) || defined(WIN32)
#define __WIN_OS__
#include "windows.h"
#endif

#include "../sdl_tools/sdl_control.h"
#include "../sdl_tools/sdl_screen.h"
#include "../sdl_tools/sdl_plot.h"
#include "../sdl_tools/sdl_plot_linked_list.h"
#include "../sdl_tools/sdl_orbital.h"
#include "../sdl_interfaces/loading.h"
#include "../sdl_interfaces/home.h"
#include "../sdl_interfaces/state_panel.h"
// #include "../sdl_interfaces/login.h"
#include "../config/sdl_config.h"
#include "../config/threads_config.h"
#include "../sdl_tools/sdl_utils.h"
#include "../data/data_utils.h"
#include "../config/states_config.h"

void home_loop(sdl_screen_object_t *obj_sdl);
void *IICU_main_loop(void *threadid);
void launch_IICU();
#endif