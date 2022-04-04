#ifndef __DEBUG_PANEL__
#define __DEBUG_PANEL__
#include "../config/general_config.h"
#include "../config/sdl_config.h"
#include "../data/kemu_utils.h"
#include "../sdl_tools/sdl_object.h"
#include "../sdl_tools/sdl_noise_box.h"
#include "../sdl_tools/sdl_main_plot.h"
#include "../sdl_tools/sdl_plot_queue.h"
#include "../sdl_tools/sdl_plot_orbital.h"
#include "../sdl_tools/sdl_jkimyei.h"
#include "../sdl_tools/sdl_itsaave.h"
#include "../data/kemu_utils.h"
#include "../iicu/iicu_jkimyei.h"
#include "../iicu/iicu_wikimyei.h"
void render_debug_panel(__iicu_wikimyei_t *_iicu_wikimyei);
#endif