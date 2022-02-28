#ifndef __STATE_PANEL__
#define __STATE_PANEL__
#include "../config/general_config.h"
#include "../config/sdl_config.h"
#include "../config/states_config.h"
#include "../sdl_tools/sdl_utils.h"
#include "../sdl_tools/sdl_object.h"
#include "../iicu/iicu_state_utils.h"
#include "../iicu/iicu_wikimyei.h"
void render_state_panel(__iicu_wikimyei_t *_iicu_wikimyei);
void negate_icon(SDL_Renderer *renderer,int x, int y, int w, int h);
#endif