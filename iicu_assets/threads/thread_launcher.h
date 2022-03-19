#ifndef __THREAD_LAUNCHER__
#define __THREAD_LAUNCHER__
#include "../config/threads_config.h"
#include "../threads/main_thread.h"
#include "../threads/clock_thread.h"
#include "../threads/broker_thread.h"
#include "../threads/state_thread.h"
#include "../threads/jkimyei_thread.h"
#include "../iicu/iicu_wikimyei.h"
void launch_IICU();
#endif