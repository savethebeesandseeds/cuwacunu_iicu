#ifndef __MAIN_THREAD__
#define __MAIN_THREAD__
#include "time.h"
#include "stdio.h"
#include <pthread.h>
#ifdef __unix__
#include "unistd.h"
#define __UNIX_OS__
#elif defined(_WIN32) || defined(WIN32)
#define __WIN_OS__
#include "windows.h"
#endif

// #FIXME remove unused includes
#include "../sdl_tools/sdl_control.h"
#include "../sdl_tools/sdl_object.h"
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
#include "iicu_loops.h"
void *IICU_main_thread(void *threadid);
#endif