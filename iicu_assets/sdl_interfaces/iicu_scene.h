#ifndef __IICU_SCENE__
#define __IICU_SCENE__
#include <assert.h>
#include "../data/data_utils.h"
#include "../sdl_tools/sdl_object.h"
#include "../sdl_tools/sdl_plot.h"
#include "../sdl_tools/sdl_orbital.h"

void render_iicu_scene(sdl_screen_object_t *obj_sdl);
void fabric_iicu_scene(sdl_screen_object_t *obj_sdl);
void kill_iicu_scene(iicu_scene_struct_t *iicu_scene);
void refresh_iicu_scene(iicu_scene_struct_t *iicu_scene);
void refresh_current_iicu_scene(sdl_screen_object_t *obj_sdl);
void kill_current_iicu_scene(sdl_screen_object_t *obj_sdl);
void kill_all_iicu_scenes(sdl_screen_object_t *obj_sdl);
#endif