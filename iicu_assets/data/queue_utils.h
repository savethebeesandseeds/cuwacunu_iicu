#ifndef __QUEUE_UTILS__
#define __QUEUE_UTILS__
/* MACRO UTILS */
typedef _Bool (___cwcn_bool_t);
#define ___CWCN_TRUE (___cwcn_bool_t) 0b1
#define ___CWCN_FALSE (___cwcn_bool_t) 0b0
#define print_cwcn_bool(a)((!!a == !!___CWCN_TRUE)?"TRUE":"FALSE")
typedef float (__cwcn_type_t); // #FIXME double is necesary for float in pow(.) deb.
#define __cwcn_type_size sizeof(__cwcn_type_t) // #FIXME not in use
typedef __cwcn_type_t (*__function_pointer_t)(__cwcn_type_t);
#define __function_pointer_t_size sizeof(__function_pointer_t)
#define __cwcn_infinite (__cwcn_type_t) 0xFFFFFFFF
#define max(a,b)({__typeof__(a) _a=(a);__typeof__(b) _b=(b);_a > _b ? _a : _b;})
#define min(a,b)({__typeof__(a) _a=(a);__typeof__(b) _b=(b);_a < _b ? _a : _b;})
typedef void (*__void_function_pointer_t)(void*);
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>
#include "../config/general_config.h"
/* MEWAAJACUNE DEFINITIONS */
typedef enum {_cwcn_FLAT, _cwcn_BEAR, _cwcn_BULL} __ujcamei_state_t;
typedef struct __trayectory { // #FIXME too many fields
    __cwcn_type_t *__alliu_state;
    __ujcamei_state_t __ujcamei_state;
}__trayectory_t;
typedef struct __load_queue { // load is a chain of pointers
    __trayectory_t *__trayectory_item;
    struct __load_queue **__down;
    struct __load_queue **__up;
} __load_queue_t;
typedef struct __mewaajacune {
    int __alliu_size;
    int __load_index;
    int __load_size;
    __load_queue_t *__load_head;
}__mewaajacune_t;

__mewaajacune_t *mewaajacune_fabric();
__load_queue_t *queue_item_fabric(__mewaajacune_t *_mewaajacune,__trayectory_t *_trayectory);
__trayectory_t *trayectory_fabric(__mewaajacune_t *_mewaajacune);
__load_queue_t *load_fabric(__mewaajacune_t *_mewaajacune);
int load_go_up(__mewaajacune_t *_mewaajacune);
int load_go_down(__mewaajacune_t *_mewaajacune);
void load_to_start(__mewaajacune_t *_mewaajacune);
void load_to_end(__mewaajacune_t *_mewaajacune);
void load_to_index(__mewaajacune_t *_mewaajacune, int _index);
int yield_next_trayectory(__mewaajacune_t *_mewaajacune);
__trayectory_t *get_load_trayectory_item(__mewaajacune_t *_mewaajacune);
__trayectory_t *glti(__mewaajacune_t *_mewaajacune);
__trayectory_t *get_load_trayectory_item_from_index(__mewaajacune_t *_mewaajacune, int _index, ___cwcn_bool_t _rneturn); // #FIXME stabilize the non unsigned (needed by load/jk fabrics)
void load_print_up_trayectory_pointers(__mewaajacune_t *_mewaajacune);
void load_print_up_trayectory_queue(__mewaajacune_t *_mewaajacune);
void load_print_down_trayectory_queue(__mewaajacune_t *_mewaajacune);
___cwcn_bool_t load_on_noob(__mewaajacune_t *_mewaajacune);
___cwcn_bool_t load_on_end(__mewaajacune_t *_mewaajacune);
___cwcn_bool_t load_on_start(__mewaajacune_t *_mewaajacune);
___cwcn_bool_t load_is_healty(__mewaajacune_t *_mewaajacune);
___cwcn_bool_t load_is_empty(__mewaajacune_t *_mewaajacune);
void kill_trayectory(__trayectory_t *_trayectory);
void kill_queue(__load_queue_t *_queue);
void empty_queue_on_last(__mewaajacune_t *_mewaajacune);
void kill_load(__mewaajacune_t *_mewaajacune);
void destroy_mewaajacune(__mewaajacune_t *_mewaajacune);

__cwcn_type_t *alliu_index_to_list(__mewaajacune_t *_mewaajacune,int alliu_index);
__cwcn_type_t max_alliu_in_load(__mewaajacune_t *_mewaajacune,int alliu_index);
__cwcn_type_t min_alliu_in_load(__mewaajacune_t *_mewaajacune,int alliu_index);
__cwcn_type_t mean_alliu_in_load(__mewaajacune_t *_mewaajacune,int alliu_index);
__cwcn_type_t std_alliu_in_load(__mewaajacune_t *_mewaajacune,int alliu_index);
#endif