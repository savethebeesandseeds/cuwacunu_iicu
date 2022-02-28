#ifndef __CLOCK_THREAD__
#define __CLOCK_THREAD__
#include <stdio.h>
#include "../config/sdl_config.h"
#include "../config/threads_config.h"
#include "../sdl_tools/sdl_utils.h"
void *IICU_clock_thread(void *threadid);
#endif