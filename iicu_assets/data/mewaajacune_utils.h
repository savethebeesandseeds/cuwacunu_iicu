#ifndef __MEWAAJACUNE_UTILS__
#define __MEWAAJACUNE_UTILS__
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>
#include "../config/general_config.h"
#include "../communications/broker_api.h"
/* MEWAAJACUNE DEFINITIONS */
typedef enum {_cwcn_FLAT, _cwcn_BEAR, _cwcn_BULL} __ujcamei_state_t;
//------------- TRAYECTORY ------------ -------
typedef struct __trayectory { // #FIXME too many fields
    time_t __alliu_timestamp;
    __cwcn_type_t *__alliu_state;
    __ujcamei_state_t __ujcamei_state;
}__trayectory_t;
//------------- LOAD QUEUE ------------ -------
typedef struct __load_queue { // load is a chain of pointers, this is a item; the load is hold in __iicu_mewaajacune_t
    __trayectory_t *__trayectory_item;
    struct __load_queue **__down;
    struct __load_queue **__up;
} __load_queue_t;
//------------- MEWAAJACUNE ------------ ------
typedef struct __mewaajacune {
    int __alliu_size;
    int __load_index;
    int __load_size;
    __load_queue_t *__load_head;
}__iicu_mewaajacune_t;
/* MEWAAJACUNE FUNK */
__iicu_mewaajacune_t *mewaajacune_fabric();
void destroy_mewaajacune(__iicu_mewaajacune_t *_mewaajacune);
void update_iicu_mewaajacune(__iicu_mewaajacune_t *_mewaajacune);

void trayectory_memcpy(__iicu_mewaajacune_t *_mewaajacune,__trayectory_t *trayectory_dest,__trayectory_t *trayectory_src);
__iicu_mewaajacune_t *mewaajacune_clone_fabric(__iicu_mewaajacune_t *src_mewaajacune);
void rebase_mewaajacune(__iicu_mewaajacune_t *dest_mewaajacune,__iicu_mewaajacune_t *src_mewaajacune); // copies src to dest, but kills none of them.

__load_queue_t *queue_item_fabric(__iicu_mewaajacune_t *_mewaajacune,__trayectory_t *_trayectory);
__trayectory_t *trayectory_fabric(__iicu_mewaajacune_t *_mewaajacune);
__load_queue_t *load_fabric(__iicu_mewaajacune_t *_mewaajacune);
int load_go_up(__iicu_mewaajacune_t *_mewaajacune);
int load_go_down(__iicu_mewaajacune_t *_mewaajacune);
void load_to_start(__iicu_mewaajacune_t *_mewaajacune);
void load_to_end(__iicu_mewaajacune_t *_mewaajacune);
void load_to_index(__iicu_mewaajacune_t *_mewaajacune, int _index);
int yield_next_trayectory(__iicu_mewaajacune_t *_mewaajacune);
__trayectory_t *get_load_trayectory_item(__iicu_mewaajacune_t *_mewaajacune);
__trayectory_t *glti(__iicu_mewaajacune_t *_mewaajacune);
__trayectory_t *get_load_trayectory_item_from_index(__iicu_mewaajacune_t *_mewaajacune, int _index, ___cwcn_bool_t _rneturn); // #FIXME stabilize the non unsigned (needed by load/jk fabrics)
void load_print_up_trayectory_pointers(__iicu_mewaajacune_t *_mewaajacune);
void load_print_up_trayectory_queue(__iicu_mewaajacune_t *_mewaajacune);
void load_print_down_trayectory_queue(__iicu_mewaajacune_t *_mewaajacune);
___cwcn_bool_t load_on_noob(__iicu_mewaajacune_t *_mewaajacune);
___cwcn_bool_t load_on_end(__iicu_mewaajacune_t *_mewaajacune);
___cwcn_bool_t load_on_start(__iicu_mewaajacune_t *_mewaajacune);
___cwcn_bool_t load_is_healty(__iicu_mewaajacune_t *_mewaajacune);
___cwcn_bool_t load_is_empty(__iicu_mewaajacune_t *_mewaajacune);
void kill_trayectory(__trayectory_t *_trayectory);
void kill_queue(__load_queue_t *_queue);
void empty_queue_on_last(__iicu_mewaajacune_t *_mewaajacune);
void empty_queue_on_first(__iicu_mewaajacune_t *_mewaajacune);
void kill_load(__iicu_mewaajacune_t *_mewaajacune);

__cwcn_type_t *alliu_state_index_to_list(__iicu_mewaajacune_t *_mewaajacune,int alliu_index);

// fast methods expect mewaajacune list as argument 
__cwcn_type_t fast_max_alliu_in_load(__iicu_mewaajacune_t *_mewaajacune,__cwcn_type_t *_c_mewaajacune_list);
__cwcn_type_t fast_min_alliu_in_load(__iicu_mewaajacune_t *_mewaajacune,__cwcn_type_t *_c_mewaajacune_list);
__cwcn_type_t fast_mean_alliu_in_load(__iicu_mewaajacune_t *_mewaajacune,__cwcn_type_t *_c_mewaajacune_list);
__cwcn_type_t fast_variance_alliu_in_load(__iicu_mewaajacune_t *_mewaajacune,__cwcn_type_t *_c_mewaajacune_list);
__cwcn_type_t fast_std_alliu_in_load(__iicu_mewaajacune_t *_mewaajacune,__cwcn_type_t *_c_mewaajacune_list);

// slow methods compute and free mewaajacune list 
__cwcn_type_t max_alliu_in_load(__iicu_mewaajacune_t *_mewaajacune,int alliu_index);
__cwcn_type_t min_alliu_in_load(__iicu_mewaajacune_t *_mewaajacune,int alliu_index);
__cwcn_type_t mean_alliu_in_load(__iicu_mewaajacune_t *_mewaajacune,int alliu_index);
__cwcn_type_t variance_alliu_in_load(__iicu_mewaajacune_t *_mewaajacune,int _alliu_index);
__cwcn_type_t std_alliu_in_load(__iicu_mewaajacune_t *_mewaajacune,int alliu_index);

// --- --- --- 
void test_populate_alliu(__iicu_mewaajacune_t *_mewaajacune);
void populate_alliu_with_klines(__iicu_mewaajacune_t *_mewaajacune, int _alliu_index, char *symbol, char *interval);
void test_populate_alliu_with_list(__iicu_mewaajacune_t *_mewaajacune, int _alliu_index, __cwcn_type_t *_list, int _size_of_list);
__cwcn_type_t request_latest_alliu(char *symbol);
#include "../data/kemu_utils.h"
#endif