#ifndef __IICU_SCENE_UTILS__
#define __IICU_SCENE_UTILS__
#include <assert.h>
#include "../config/general_config.h"
#include "../config/sdl_config.h"
#include "../data/kemu_utils.h"
#include "../data/nijcyota_utils.h"
#include "../data/mewaajacune_utils.h"
#include "../iicu/iicu_wikimyei.h"
/* SCENE FUNKS */
void fabric_iicu_scene(__iicu_scene_struct_t *_iicu_scene);
void fabric_all_iicu_scenes(__iicu_wikimyei_t *_iicu_wikimyei);
void destroy_iicu_scene(__iicu_scene_struct_t *_iicu_scene);
void destroy_all_iicu_scenes(__iicu_wikimyei_t *_iicu_wikimyei);
void refresh_iicu_scene(__iicu_scene_struct_t *_iicu_scene);
void refresh_current_iicu_scene(__iicu_wikimyei_t *_iicu_wikimyei);
void update_current_iicu_scene(__iicu_wikimyei_t *_iicu_wikimyei);
void iicu_scene_go_up(__iicu_wikimyei_t *_iicu_wikimyei);
void iicu_scene_go_down(__iicu_wikimyei_t *_iicu_wikimyei);
void iicu_klines_increse(__iicu_wikimyei_t *_iicu_wikimyei);
void iicu_klines_decrese(__iicu_wikimyei_t *_iicu_wikimyei);
#endif