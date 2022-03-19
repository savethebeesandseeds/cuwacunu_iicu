#ifndef __THREAD_CONFIG__
#define __THREAD_CONFIG__
#include "time.h"
#include "stdio.h"
#include <pthread.h>
// #ifdef __unix__
// #include "unistd.h"
// #define __UNIX_OS__
// #elif defined(_WIN32) || defined(WIN32)
// #define __WIN_OS__
// #include "windows.h"
// #endif
#define MAIN_NUM_THREADS 10
#define INTERNAL_NUM_THREADS 64
#define BESEECH_TIMEOUT (Uint32) 10 // in [ms]
#define BESEECH_MAX_RETRY (int) 250 // in [ms]

#define STATE_THREAD_PERIOD (double) 5/1 // in [hertz]
#define BROKER_THREAD_PERIOD (double) 5/1 // in [hertz]
#define CLOCK_THREAD_PERIOD (double) 1/30 // in [hertz]
#define CLOCK_JKIMYEI_PERIOD (double) 15/1 // in [herts] meaning (1/segundo) #FIXME be carefull, each method invokes a thread of it self a high frequency here with a slow processor could rise not handled resources overflow.  

#define __cwcn_MAIN_THREAD__
#define __cwcn_BROKER_THREAD__
#define __cwcn_STATE_THREAD__
#define __cwcn_JKIMYEI_THREAD__
// #define __cwcn_CLOCK_THREAD__ // disabled cus' fps is done differtly #FIXME probably

// #define __UPDATE_ONLY_ACTIVE_BROKER_SYMBOL_INTERVAL__
#endif