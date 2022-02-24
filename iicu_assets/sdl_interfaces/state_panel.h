#ifndef __SDL_STATE_PANEL__
#define __SDL_STATE_PANEL__
#include "../config/sdl_config.h"
#include "../config/states_config.h"
#include "../sdl_tools/sdl_utils.h"
#include "../sdl_tools/sdl_object.h"
#include "../iicu/state_utils.h"
void render_state_panel(sdl_screen_object_t *obj_sdl);
void negate_icon(sdl_screen_object_t *obj_sdl,int x, int y, int w, int h);
#endif