#ifndef __MAIN_THREAD__
#define __MAIN_THREAD__
#include "../config/threads_config.h"
// #FIXME remove unused includes
#include "../iicu/iicu_wikimyei.h"
#include "../sdl_interfaces/loading.h"
#include "../sdl_interfaces/home.h"
#include "../sdl_interfaces/debug_panel.h"
#include "../sdl_interfaces/state_panel.h"
// #include "../sdl_interfaces/login.h"
#include "../config/states_config.h"
#include "../iicu/iicu_loops.h"
void main_case_launch(__iicu_wikimyei_t *_iicu_wikimyei);
void *IICU_main_thread(void *_iicu_wikimyei);
#endif