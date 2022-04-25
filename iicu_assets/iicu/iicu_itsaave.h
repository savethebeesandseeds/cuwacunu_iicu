#ifndef __IICU_ITSAAVE__
#define __IICU_ITSAAVE__
#include "../config/general_config.h"
#include "../config/threads_config.h"
#include "../config/itsaave_config.h"
#include "../iicu/iicu_jkimyei.h"
typedef struct __iicu_pocket{
	__cwcn_type_t __holding_value;
}__iicu_pocket_t;
typedef enum {IT_NOTHING, IT_OPEN, IT_LOADED_OPEN, IT_FINISHED_PROFIT, IT_FINISHED_LOSS}__itsaave_state_t;
typedef struct __iicu_itsaave {
    __iicu_pocket_t *__it_pocket;
    __itsaave_state_t __it_state;
    __cwcn_type_t __it_alliu_quantity;
    __cwcn_type_t __it_alliu_start;
    __cwcn_type_t __it_alliu_end;
    __cwcn_type_t __it_alliu_uperbreak;
    __cwcn_type_t __it_alliu_downbreak;
    __intelligent_order_policy_t *__it_policy;
}__iicu_itsaave_t;
// --- --- --- 
void print_itsaave(__iicu_itsaave_t *_iicu_itsaave);
__iicu_itsaave_t *itsaave_fabric(__intelligent_order_policy_t *_policy);
__iicu_itsaave_t *itsaave_clone_fabric(__iicu_itsaave_t *src_iicu_itsaave);
void destroy_itsaave(__iicu_itsaave_t *_iicu_itsaave);
__iicu_pocket_t *pocket_fabric();
__iicu_pocket_t *pocket_clone_fabric(__iicu_pocket_t *src_iicu_pocket);
void destroy_pocket(__iicu_pocket_t *_iicu_pocket);
void load_pocket_to_pocket(__iicu_pocket_t *dest_pocket, __iicu_pocket_t *src_pocket);
void update_itsaave_pocket(__iicu_itsaave_t *_iicu_itsaave);
void active_itsaave_request(void *_iicu_wikimyei);
void desactive_itsaave_request(void *_iicu_wikimyei);
___cwcn_bool_t was_there_a_itsaave_request(void *_iicu_wikimyei);
void fake_itsaave_method(void *_it_thread_order, int _scene_id, int _kline_id);
void *itsaave_launcher(void *_it_thread_order);
void itsaave_to_stream(__iicu_itsaave_t *_iicu_itsaave, FILE *_dump_stream);
void pocket_to_stream(__iicu_pocket_t *_iicu_pocket, FILE *_dump_stream);
void pocket_load_from_stream(__iicu_pocket_t *_iicu_pocket, FILE *_dump_stream);
void itsaave_load_from_stream(__iicu_itsaave_t *_iicu_itsaave, FILE *_dump_stream);
#endif