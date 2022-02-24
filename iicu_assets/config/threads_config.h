#ifndef __THREAD_CONFIG__
#define __THREAD_CONFIG__
#ifdef __unix__
#include "unistd.h"
#define __UNIX_OS__
#elif defined(_WIN32) || defined(WIN32)
#define __WIN_OS__
#include "windows.h"
#endif
#define NUM_THREADS 5
#define CLOCK_THREAD_PERIOD (double) 1/5
#endif