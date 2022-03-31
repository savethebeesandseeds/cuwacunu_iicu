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

#define MAIN_NUM_THREADS 32
#define INTERNAL_NUM_THREADS 64
#define BESEECH_TIMEOUT (Uint32) 10 // in [ms]
#define BESEECH_MAX_RETRY (int) 250 // 

#define STATE_THREAD_PERIOD (double) 5/1 // in [hertz]
#define BROKER_THREAD_PERIOD (double) 1/1 // in [hertz]
#define CLOCK_THREAD_PERIOD (double) 1/30 // in [hertz]
#define CLOCK_JKIMYEI_PERIOD (double) 15/1 // in [hertz] meaning (1/segundo) #FIXME be carefull, each method invokes a thread of it self a high frequency here with a slow processor could rise not handled resources overflow.  
#define CLOCK_REGRESSIVE_PERIOD (double) 15/1 // in [hertz]
#define CLOCK_POLINOMIAL_PERIOD (double) 15/1 // in [hertz]
#define CLOCK_STATICQUES_PERIOD (double) 15/1 // in [hertz]
#define CLOCK_ITSAAVE_PERIOD (double) 1/1  // in [hertz]

// #define __cwcn_CLOCK_THREAD__ // disabled cus' fps is done differtly #FIXME probably
#define __cwcn_MAIN_THREAD__
#define __cwcn_BROKER_THREAD__
#define __cwcn_STATE_THREAD__
#define __cwcn_ITSAAVE_THREAD__
#define __cwcn_JKIMYEI_THREAD__
// #define __cwcn_REGRESSIVE_THREAD__
// #define __cwcn_POLINOMIAL_THREAD__
#define __cwcn_STATICQUES_THREAD__



#endif