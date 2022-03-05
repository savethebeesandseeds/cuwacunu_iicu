#ifndef __THREAD_CONFIG__
#define __THREAD_CONFIG__
#include "time.h"
#include "stdio.h"
#include <pthread.h>
#ifdef __unix__
#include "unistd.h"
#define __UNIX_OS__
#elif defined(_WIN32) || defined(WIN32)
#define __WIN_OS__
#include "windows.h"
#endif
#define NUM_THREADS 5
#define BESEECH_TIMEOUT (Uint32) 10 // in [ms]
#define BESEECH_MAX_RETRY (int) 250 // in [ms]
#define STATE_THREAD_PERIOD (double) 5/1 // in [hertz]
#define BROKER_THREAD_PERIOD (double) 5/1 // in [hertz]
#define CLOCK_THREAD_PERIOD (double) 1/30 // in [hertz]
#define __cwcn_MAIN_THREAD__
#define __cwcn_BROKER_THREAD__
// #define __cwcn_CLOCK_THREAD__
// #define __UPDATE_ONLY_ACTIVE_BROKER_SYMBOL_INTERVAL__
#endif