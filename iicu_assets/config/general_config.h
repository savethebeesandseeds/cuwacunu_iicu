#ifndef __GENERAL_CONFIG__
#define __GENERAL_CONFIG__
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
#define __cwcn_max(a,b)({__typeof__(a) _a=(a);__typeof__(b) _b=(b);_a > _b ? _a : _b;})
#define __cwcn_min(a,b)({__typeof__(a) _a=(a);__typeof__(b) _b=(b);_a < _b ? _a : _b;})
typedef void (*__void_function_pointer_t)(void*);

// #define DEBUG_QUEUE
// #define ALOCATION_DEBUG
#define MAX_IICU_SCENES (int) 4 // if augmented augment also IICU_SCENES_SYMBOLS
#define IICU_SCENES_SYMBOLS (char[MAX_IICU_SCENES][12])  {"BTCUSDT","ETHUSDT","BTTCUSDT","ADAUSDT"}

// FIXME fix colors
#define COLOR_L_GOOD "\033[0;32m"
// #define COLOR_L_GOOD "1"
#define COLOR_R_L_GOOD 71
#define COLOR_G_L_GOOD 255
#define COLOR_B_L_GOOD 0
#define COLOR_GOOD "\033[1;32m"
// #define COLOR_GOOD "CdOLOR_GOOD"
#define COLOR_R_GOOD 71
#define COLOR_G_GOOD 255
#define COLOR_B_GOOD 0
#define COLOR_L_DANGER "\033[0;31m"
// #define COLOR_L_DANGER "3"
#define COLOR_R_L_DANGER 255
#define COLOR_G_L_DANGER 71
#define COLOR_B_L_DANGER 0
#define COLOR_DANGER "\033[1;31m"
// #define COLOR_DANGER "CdOLOR_DANGER"
#define COLOR_R_DANGER 255
#define COLOR_G_DANGER 71
#define COLOR_B_DANGER 0
#define COLOR_L_WARNING "\033[0;42m"
// #define COLOR_L_WARNING "5"
#define COLOR_R_L_WARNING 71
#define COLOR_G_L_WARNING 255
#define COLOR_B_L_WARNING 255
#define COLOR_WARNING "\033[1;31m"
// #define COLOR_WARNING "6"
#define COLOR_R_WARNING 71
#define COLOR_G_WARNING 255
#define COLOR_B_WARNING 255
#define COLOR_REGULAR "\033[0m"
// #define COLOR_REGULAR "CdOLOR_REGULAR"
#define COLOR_R_REGULAR 171
#define COLOR_G_REGULAR 171
#define COLOR_B_REGULAR 171
#endif