#ifndef __STATE_UTILS__
#define __STATE_UTILS__
#include "../sdl_tools/sdl_control.h"
#include "../sdl_tools/sdl_object.h"
#include "../communications/broker_api.h"
#include "../config/states_config.h"
#include "../sdl_interfaces/iicu_scene.h"
void initialize_iicu_state(sdl_screen_object_t *obj_sdl);
void initialize_iicu_scene(sdl_screen_object_t *obj_sdl);
void update_iicu_state(sdl_screen_object_t *obj_sdl);
#endif