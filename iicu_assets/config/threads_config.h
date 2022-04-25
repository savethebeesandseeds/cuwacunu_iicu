#ifndef __THREAD_CONFIG__
#define __THREAD_CONFIG__
#define _GNU_SOURCE
// #include <linux/sched.h> // for cpu_set_t
#include <sched.h> // for cpu_set_t
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
#define LOWFORCE_BEESECH // this allows beseech breaks

#define INTERNAL_NUM_THREADS 16
#define MAIN_NUM_THREADS 64 // please have this number be high enough (see the threads_launcher)
#define BESEECH_TIMEOUT (Uint32) 50 // in [ms]
#define BESEECH_MAX_RETRY (int) 100 // 

#define CLOCK_STATE_PERIOD (double) 5/1 // in [segs]
#define CLOCK_BROKER_PERIOD (double) 10/1 // in [segs]
#define CLOCK_MAIN_PERIOD (double) 1/3 // in [segs]
#define CLOCK_JKIMYEI_PERIOD (double) 30/1 // in [segs] meaning (1/segundo) #FIXME be carefull, each method invokes a thread of it self a high frequency here with a slow processor could rise not handled resources overflow.  
#define CLOCK_REGRESSIVE_PERIOD (double) 15/1 // in [segs]
#define CLOCK_POLINOMIAL_PERIOD (double) 15/1 // in [segs]
#define CLOCK_STATICQUES_PERIOD (double) 2/1 // in [segs]
#define CLOCK_ITSAAVE_PERIOD (double) 1/2  // in [segs]
#define CLOCK_CONTROLS_PERIOD (double) CLOCK_MAIN_PERIOD // in [segs]
#define CLOCK_SAVE_n_LOAD_PERIOD (double) 5/1  // in [segs] --- this is the most critical period; keep high --- save is slow

// #define __cwcn_CLOCK_THREAD__ // disabled cus' fps is done differtly #FIXME probably
#define __cwcn_CONTROLS_THREAD__
// #define __cwcn_SAVE_n_LOAD_THREAD__
#define __cwcn_MAIN_THREAD__
#define __cwcn_BROKER_THREAD__
// #define __cwcn_STATICQUES_THREAD__
#define __cwcn_STATE_THREAD__
#define __cwcn_JKIMYEI_THREAD__
#define __cwcn_ITSAAVE_THREAD__
// #define __cwcn_REGRESSIVE_THREAD__
// #define __cwcn_POLINOMIAL_THREAD__


// #define __MAIN_THREAD_FORCE_CORE 2
// // #define __BROKER_THREAD_FORCE_CORE _ // this one has no effect, try no to overload the broker api
// #define __STATICQUES_THREAD_FORCE_CORE 3 // comment to disable behaviour
// #define __STATE_THREAD_FORCE_CORE 3
// #define __ITSAAVE_THREAD_FORCE_CORE 1 // this solve an issue
// // #define __JKIMYEI_THREAD_FORCE_CORE 1
// #define __REGRESSIVE_THREAD_FORCE_CORE 4
// #define __POLINOMIAL_THREAD_FORCE_CORE 4


#endif