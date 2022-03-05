#ifndef __IICU_WIKIMYEI__
#define __IICU_WIKIMYEI__
#include <stdlib.h>
#include "../sdl_tools/sdl_object.h"
#include "../data/kemu_utils.h"
#include "../data/nijcyota_utils.h"
#include "../data/mewaajacune_utils.h"
#include "../config/broker_config.h"
#include "../config/threads_config.h"
//------------- STATE ------------ ------------
typedef struct __iicu_state_struct {
	SDL_Texture *network_texture;
	SDL_Texture *broker_texture;
	SDL_Texture *keyboard_texture;
	SDL_Texture *controller_texture;
	double network_last_update; // seconds since Jan 1, 1970
	double broker_last_update; // seconds since Jan 1, 1970
	double keyboard_last_update; // seconds since Jan 1, 1970
	double controller_last_update; // seconds since Jan 1, 1970
	int network_is_up;
	int broker_is_up;
	int keyboard_is_up;
	int controller_is_up;
	double kline_last_update[MAX_IICU_SCENES][BROKER_CANDLE_N_INTERVALS]; // [List] seconds since Jan 1, 1970
	int kline_id[MAX_IICU_SCENES];
	
	char scene_symbol[16];
	int fps;
	int interface_id;
	int scene_id;
	int scene_count;

	___cwcn_bool_t kemu_in_use[MAX_IICU_SCENES][BROKER_CANDLE_N_INTERVALS];
	___cwcn_bool_t mewaajacune_in_use[MAX_IICU_SCENES][BROKER_CANDLE_N_INTERVALS];
} __iicu_state_struct_t;
//------------- SCENE ------------ ------------
typedef struct __iicu_scene_struct {
	__iicu_nijcyota_t *nijcyota;
	__iicu_kemu_t *kemu[BROKER_CANDLE_N_INTERVALS];
	__iicu_mewaajacune_t *mewaajacune[BROKER_CANDLE_N_INTERVALS];
} __iicu_scene_struct_t;
//------------- WIKIMYEI ------------ ---------
typedef struct __iicu_wikimyei{
	__sdl_screen_object_t *obj_sdl;
	__iicu_state_struct_t iicu_state;
	__iicu_scene_struct_t iicu_scene[MAX_IICU_SCENES];
}__iicu_wikimyei_t;
//------------- FUNKS ------------ ---------
__iicu_wikimyei_t *iicu_wikimyei_fabric(); // #NOTE wikimyei has multiple scenes, and one v-state.
void destroy_iicu_wikimyei(__iicu_wikimyei_t *_iicu_wikimyei);
void beseech_current_mewaajacune(__iicu_wikimyei_t *_iicu_wikimyei);
void release_current_mewaajacune(__iicu_wikimyei_t *_iicu_wikimyei);
void beseech_mewaajacune(__iicu_wikimyei_t *_iicu_wikimyei, int _scene_index,int _kline_index);
void release_mewaajacune(__iicu_wikimyei_t *_iicu_wikimyei, int _scene_index, int _kline_index);

void beseech_current_kemu(__iicu_wikimyei_t *_iicu_wikimyei);
void release_current_kemu(__iicu_wikimyei_t *_iicu_wikimyei);
void beseech_kemu(__iicu_wikimyei_t *_iicu_wikimyei, int _scene_index,int _kline_index);
void release_kemu(__iicu_wikimyei_t *_iicu_wikimyei, int _scene_index, int _kline_index);

void beseech_all(__iicu_wikimyei_t *_iicu_wikimyei);
void release_all(__iicu_wikimyei_t *_iicu_wikimyei);

__iicu_scene_struct_t *get_current_scene(__iicu_wikimyei_t *_iicu_wikimyei);
__iicu_scene_struct_t *giics(__iicu_wikimyei_t *_iicu_wikimyei);
__iicu_nijcyota_t *get_current_nijcyota(__iicu_wikimyei_t *_iicu_wikimyei);
__iicu_nijcyota_t *giicn(__iicu_wikimyei_t *_iicu_wikimyei);
__iicu_mewaajacune_t *get_mewaajacune(__iicu_wikimyei_t *_iicu_wikimyei, int _scene_id,int _kline_id);
__iicu_mewaajacune_t *get_current_mewaajacune(__iicu_wikimyei_t *_iicu_wikimyei);
__iicu_mewaajacune_t *giicm(__iicu_wikimyei_t *_iicu_wikimyei);
__iicu_kemu_t *get_kemu(__iicu_wikimyei_t *_iicu_wikimyei, int _scene_id,int _kline_id);
__iicu_kemu_t *get_current_kemu(__iicu_wikimyei_t *_iicu_wikimyei);
__iicu_kemu_t *giick(__iicu_wikimyei_t *_iicu_wikimyei);
#include "../iicu/iicu_state_utils.h"
#include "../iicu/iicu_scene_utils.h"
#endif