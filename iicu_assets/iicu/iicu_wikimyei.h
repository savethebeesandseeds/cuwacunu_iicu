#ifndef __IICU_WIKIMYEI__
#define __IICU_WIKIMYEI__
#include <stdlib.h>
#include "../sdl_tools/sdl_object.h"
#include "../data/kemu_utils.h"
#include "../data/mewaajacune_utils.h"
#include "../config/nijcyota_utils.h"
#include "../config/broker_config.h"
#include "../config/threads_config.h"
#include "../iicu/iicu_jkimyei.h"
#include "../iicu/iicu_itsaave.h"
#include "../data/regressive_kemu.h"
#include "../data/polinomial_kemu.h"
#include "../data/staticques_kemu.h"
//------------- STATE ------------ ------------
typedef struct _iicu_state_struct {
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
	double kline_last_update[MAX_IICU_SCENES][BROKER_CANDLE_N_INTERVALS]; // [in] seconds since Jan 1, 1970
	
	char scene_symbol[16]; // #FIXME somehow do something
	double fps;
	int scene_count;
	int scene_id;
	int interface_id;
	int kline_id[MAX_IICU_SCENES];


	void **__jk_thread_order; // aux holder of type(__jkimyei_thread_order_t) to launch jkimyei threads
	void **__rg_thread_order; // aux holder of type(__regression_thread_order_t) to launch regression threads
	void **__pl_thread_order; // aux holder of type(__polonomial_thread_order_t) to launch polonomial threads
	void **__sq_thread_order; // aux holder of type(__staticques_thread_order_t) to launch staticques threads
	void **__it_thread_order; // aux holder of type(__itsaave_thread_order_t) to launch staticques threads

	___cwcn_bool_t __req_itsaave;
	
	___cwcn_bool_t jkimyei_in_use[MAX_IICU_SCENES];
	___cwcn_bool_t polinomial_in_use[MAX_IICU_SCENES][BROKER_CANDLE_N_INTERVALS];
	___cwcn_bool_t regressive_in_use[MAX_IICU_SCENES][BROKER_CANDLE_N_INTERVALS];
	___cwcn_bool_t staticques_in_use[MAX_IICU_SCENES][BROKER_CANDLE_N_INTERVALS];
	___cwcn_bool_t mewaajacune_in_use[MAX_IICU_SCENES][BROKER_CANDLE_N_INTERVALS];
	___cwcn_bool_t scene_itsaave_in_use[MAX_IICU_SCENES]; // #FIXME add more wk
	___cwcn_bool_t wk_itsaave_in_use;
	___cwcn_bool_t nijcyota_in_use; // #FIXME add more wk
	
} __iicu_state_struct_t;
//------------- SCENE ------------ ------------
typedef struct _iicu_scene_struct {
	__iicu_nijcyota_t *__nijcyota;
	__iicu_jkimyei_t *__iicu_jkimyei;
	__iicu_itsaave_t *__scene_itsaave;
	__iicu_mewaajacune_t *__mewaajacune[BROKER_CANDLE_N_INTERVALS];
	__iicu_polinomial_t *__iicu_polinomial[BROKER_CANDLE_N_INTERVALS];
	__iicu_regressive_t *__iicu_regressive[BROKER_CANDLE_N_INTERVALS];
	__iicu_staticques_t *__iicu_staticques[BROKER_CANDLE_N_INTERVALS];
} __iicu_scene_struct_t;
//------------- WIKIMYEI ------------ ---------
typedef struct __iicu_wikimyei{
	__sdl_screen_object_t *__obj_sdl;
	__iicu_itsaave_t *__wk_tsaave;
	__iicu_state_struct_t *__iicu_state; // there is just one state
	__iicu_scene_struct_t *__iicu_scene[MAX_IICU_SCENES];
}__iicu_wikimyei_t;
//------------- JK_THREAD ------------ --------
typedef enum {JK_MONTECARLO}__jkimyei_types_t;
typedef struct __jkimyei_thread_order{
	int __scene_id;
	int __kline_id;
	__jkimyei_types_t __jk_type;
	pthread_t __jk_thread_launcher;
    ___cwcn_bool_t __jk_thead_is_bussy;
    __iicu_wikimyei_t *__ref_iicu_wikimyei; // just a copy to reference
}__jkimyei_thread_order_t;
//------------- IT_THREAD ------------ --------
typedef enum {IT_FAKE}__itsaave_types_t;
typedef struct __itsaave_thread_order {
	int __scene_id;
	int __it_id;
	__itsaave_types_t __it_type;
	pthread_t __it_thread_launcher;
    ___cwcn_bool_t __it_thead_is_bussy;
	___cwcn_bool_t __it_policy_is_bussy;
	__iicu_wikimyei_t *__ref_iicu_wikimyei;  // reference wikimyei
	__iicu_itsaave_t *__ref_iicu_itsaave; // reference itsaave
}__itsaave_thread_order_t;
//------------- RG_THREAD ------------ --------
typedef enum {RG_BISHOP_LINEAR_REGRESSION}__regressive_types_t;
typedef struct __regressive_thread_order{
	int __scene_id;
	int __kline_id;
	__regressive_types_t __rg_type;
	pthread_t __rg_thread_launcher;
    ___cwcn_bool_t __rg_thead_is_bussy;
    __iicu_wikimyei_t *__ref_iicu_wikimyei; // just a copy to reference
}__regressive_thread_order_t;
//------------- PL_THREAD ------------ --------
typedef enum {PL_KIKE_METHOD}__polinomial_types_t;
typedef struct __polinomial_thread_order{
	int __scene_id;
	int __kline_id;
	__polinomial_types_t __pl_type;
	pthread_t __pl_thread_launcher;
    ___cwcn_bool_t __pl_thead_is_bussy;
    __iicu_wikimyei_t *__ref_iicu_wikimyei; // just a copy to reference
}__polinomial_thread_order_t;
//------------- SQ_THREAD ------------ --------
typedef enum {FIRST_ORDER_AUTOREGRESSION, FIRST_ORDER_STATISTICS}__staticques_types_t;
typedef struct __staticques_thread_order{
	int __scene_id;
	int __kline_id;
	__staticques_types_t __sq_type;
	pthread_t __sq_thread_launcher;
    ___cwcn_bool_t __sq_thead_is_bussy;
    __iicu_wikimyei_t *__ref_iicu_wikimyei; // just a copy to reference
}__staticques_thread_order_t;

//------------- FUNKS ------------ ---------
__iicu_wikimyei_t *iicu_wikimyei_fabric(); // #NOTE wikimyei has multiple scenes, and one v-state.
void destroy_iicu_wikimyei(__iicu_wikimyei_t *_iicu_wikimyei);

void beseech_current_mewaajacune(__iicu_wikimyei_t *_iicu_wikimyei);
void release_current_mewaajacune(__iicu_wikimyei_t *_iicu_wikimyei);
void beseech_mewaajacune(__iicu_wikimyei_t *_iicu_wikimyei, int _scene_index,int _kline_index);
void release_mewaajacune(__iicu_wikimyei_t *_iicu_wikimyei, int _scene_index, int _kline_index);

void beseech_current_nijcyota(__iicu_wikimyei_t *_iicu_wikimyei);
void release_current_nijcyota(__iicu_wikimyei_t *_iicu_wikimyei);
void beseech_nijcyota(__iicu_wikimyei_t *_iicu_wikimyei);
void release_nijcyota(__iicu_wikimyei_t *_iicu_wikimyei);

void beseech_scene_itsaave(__iicu_wikimyei_t *_iicu_wikimyei, int _scene_index);
void release_scene_itsaave(__iicu_wikimyei_t *_iicu_wikimyei, int _scene_index);

void beseech_wk_itsaave(__iicu_wikimyei_t *_iicu_wikimyei);
void release_wk_itsaave(__iicu_wikimyei_t *_iicu_wikimyei);

void beseech_current_staticques(__iicu_wikimyei_t *_iicu_wikimyei);
void release_current_staticques(__iicu_wikimyei_t *_iicu_wikimyei);

void beseech_current_jkimyei(__iicu_wikimyei_t *_iicu_wikimyei);
void release_current_jkimyei(__iicu_wikimyei_t *_iicu_wikimyei);
void beseech_jkimyei(__iicu_wikimyei_t *_iicu_wikimyei, int _scene_index);
void release_jkimyei(__iicu_wikimyei_t *_iicu_wikimyei, int _scene_index);

void beseech_current_regressive(__iicu_wikimyei_t *_iicu_wikimyei);
void release_current_regressive(__iicu_wikimyei_t *_iicu_wikimyei);
void beseech_regressive(__iicu_wikimyei_t *_iicu_wikimyei, int _scene_index, int _kline_index);
void release_regressive(__iicu_wikimyei_t *_iicu_wikimyei, int _scene_index, int _kline_index);

void beseech_current_polinomial(__iicu_wikimyei_t *_iicu_wikimyei);
void release_current_polinomial(__iicu_wikimyei_t *_iicu_wikimyei);
void beseech_polinomial(__iicu_wikimyei_t *_iicu_wikimyei, int _scene_index, int _kline_index);
void release_polinomial(__iicu_wikimyei_t *_iicu_wikimyei, int _scene_index, int _kline_index);

void beseech_current_staticques(__iicu_wikimyei_t *_iicu_wikimyei);
void release_current_staticques(__iicu_wikimyei_t *_iicu_wikimyei);
void beseech_staticques(__iicu_wikimyei_t *_iicu_wikimyei, int _scene_index, int _kline_index);
void release_staticques(__iicu_wikimyei_t *_iicu_wikimyei, int _scene_index, int _kline_index);

void beseech_current_all(__iicu_wikimyei_t *_iicu_wikimyei);
void release_current_all(__iicu_wikimyei_t *_iicu_wikimyei);
void beseech_all(__iicu_wikimyei_t *_iicu_wikimyei);
void release_all(__iicu_wikimyei_t *_iicu_wikimyei);

__iicu_itsaave_t *get_wk_itsaave(__iicu_wikimyei_t *_iicu_wikimyei);
__iicu_itsaave_t *get_scene_itsaave(__iicu_wikimyei_t *_iicu_wikimyei, int _scene_id);

__iicu_scene_struct_t *get_scene(__iicu_wikimyei_t *_iicu_wikimyei, int _scene_id);
__iicu_scene_struct_t *get_current_scene(__iicu_wikimyei_t *_iicu_wikimyei);
__iicu_scene_struct_t *giics(__iicu_wikimyei_t *_iicu_wikimyei);

__iicu_nijcyota_t *get_current_nijcyota(__iicu_wikimyei_t *_iicu_wikimyei);
__iicu_nijcyota_t *giicn(__iicu_wikimyei_t *_iicu_wikimyei);

__iicu_mewaajacune_t *get_mewaajacune(__iicu_wikimyei_t *_iicu_wikimyei, int _scene_id,int _kline_id);
__iicu_mewaajacune_t *get_current_mewaajacune(__iicu_wikimyei_t *_iicu_wikimyei);
__iicu_mewaajacune_t *giicm(__iicu_wikimyei_t *_iicu_wikimyei);

__iicu_jkimyei_t *get_jkimyei(__iicu_wikimyei_t *_iicu_wikimyei, int _scene_id);
__iicu_jkimyei_t *get_current_jkimyei(__iicu_wikimyei_t *_iicu_wikimyei);
__iicu_jkimyei_t *giicjk(__iicu_wikimyei_t *_iicu_wikimyei);

__iicu_regressive_t *get_regressive(__iicu_wikimyei_t *_iicu_wikimyei, int _scene_id, int _kline_id);
__iicu_regressive_t *get_current_regressive(__iicu_wikimyei_t *_iicu_wikimyei);
__iicu_regressive_t *giicrg(__iicu_wikimyei_t *_iicu_wikimyei);

__iicu_polinomial_t *get_polinomial(__iicu_wikimyei_t *_iicu_wikimyei, int _scene_id, int _kline_id);
__iicu_polinomial_t *get_current_polinomial(__iicu_wikimyei_t *_iicu_wikimyei);
__iicu_polinomial_t *giicpl(__iicu_wikimyei_t *_iicu_wikimyei);

__iicu_staticques_t *get_staticques(__iicu_wikimyei_t *_iicu_wikimyei, int _scene_id, int _kline_id);
__iicu_staticques_t *get_current_staticques(__iicu_wikimyei_t *_iicu_wikimyei);
__iicu_staticques_t *giicsq(__iicu_wikimyei_t *_iicu_wikimyei);

__iicu_state_struct_t *get_state(__iicu_wikimyei_t *_iicu_wikimyei);
__jkimyei_thread_order_t *get_jk_thread_order(__iicu_wikimyei_t *_iicu_wikimyei, int _jk_id);
__regressive_thread_order_t *get_rg_thread_order(__iicu_wikimyei_t *_iicu_wikimyei, int _rg_id);
__polinomial_thread_order_t *get_pl_thread_order(__iicu_wikimyei_t *_iicu_wikimyei, int _pl_id);
__staticques_thread_order_t *get_sq_thread_order(__iicu_wikimyei_t *_iicu_wikimyei, int _sq_id);
__itsaave_thread_order_t *get_it_thread_order(__iicu_wikimyei_t *_iicu_wikimyei, int _it_id);

int get_current_scene_id(__iicu_wikimyei_t *_iicu_wikimyei);
int gcsid(__iicu_wikimyei_t *_iicu_wikimyei);
int get_current_kline_id(__iicu_wikimyei_t *_iicu_wikimyei);
int gcklid(__iicu_wikimyei_t *_iicu_wikimyei);

void wait_scene_kline_load(__iicu_wikimyei_t *_iicu_wikimyei, int _scene_id, int _kline_id);
#include "../iicu/iicu_state_utils.h"
#include "../iicu/iicu_scene_utils.h"
#endif