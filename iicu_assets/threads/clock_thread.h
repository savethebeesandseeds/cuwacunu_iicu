#ifndef __CLOCK_THREAD__
#define __CLOCK_THREAD__
#include "../config/sdl_config.h"
#include "../config/threads_config.h"
#include "../sdl_tools/sdl_utils.h"
#include "../iicu/iicu_wikimyei.h"
void *IICU_clock_thread(void *_iicu_wikimyei);
#endif