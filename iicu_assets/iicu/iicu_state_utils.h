#ifndef __IICU_STATE_UTILS__
#define __IICU_STATE_UTILS__
#include "../sdl_tools/sdl_control.h"
#include "../communications/broker_api.h"
#include "../config/general_config.h"
#include "../config/sdl_config.h"
#include "../config/states_config.h"
#include "../sdl_tools/sdl_object.h"
#include "../iicu/iicu_wikimyei.h"
/* STATE FUNKS */
void initialize_iicu_state(__iicu_wikimyei_t *_iicu_wikimyei);
void destroy_iicu_state(__iicu_wikimyei_t *_iicu_wikimyei);
void update_iicu_state(__iicu_wikimyei_t *_iicu_wikimyei);

int get_current_scene_id(__iicu_wikimyei_t *_iicu_wikimyei);
int gcsid(__iicu_wikimyei_t *_iicu_wikimyei);
int get_current_kline_id(__iicu_wikimyei_t *_iicu_wikimyei);
int gckid(__iicu_wikimyei_t *_iicu_wikimyei);
#endif