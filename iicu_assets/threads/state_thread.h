#ifndef __STATE_THREAD__
#define __STATE_THREAD__
#include "../config/sdl_config.h"
#include "../config/threads_config.h"
#include "../sdl_tools/sdl_utils.h"
#include "../iicu/iicu_wikimyei.h"
#include "../iicu/iicu_state_utils.h"
void *IICU_state_thread(void *_iicu_wikimyei);
#endif