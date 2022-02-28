#ifndef __IICU_LOOPS__
#define __IICU_LOOPS__
#include "stdio.h"
#include "../config/sdl_config.h"
#include "../sdl_interfaces/loading.h"
#include "../sdl_tools/sdl_object.h"
#include "../sdl_tools/sdl_control.h"
#include "../iicu/iicu_state_utils.h"
#include "../iicu/iicu_scene_utils.h"
#include "../iicu/iicu_wikimyei.h"
#include "../sdl_interfaces/home.h"
#include "../sdl_interfaces/state_panel.h"
#include "../sdl_interfaces/scene_panel.h"
#include "../data/data_utils.h"
#include "../config/threads_config.h"
void iicu_scene_loop(__iicu_wikimyei_t *_iicu_wikimyei);
void loading_loop(__iicu_wikimyei_t *_iicu_wikimyei);
void home_loop(__iicu_wikimyei_t *_iicu_wikimyei);
#endif