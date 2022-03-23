#ifndef __JKIMYEI_CONFIG__
#define __JKIMYEI_CONFIG__
#include "../config/general_config.h"
#include "../config/broker_config.h"
#define RANGE_EXPLORATION_MARGIN_UP_MAX (__cwcn_type_t) 0.050 // 5.0%
#define RANGE_EXPLORATION_MARGIN_UP_MIN (__cwcn_type_t) BROKER_MARKET_TOTAL_COMMISSION // 0.2%
#define RANGE_EXPLORATION_MARGIN_DOWN_MAX (__cwcn_type_t) 0.050 // 5.0%
#define RANGE_EXPLORATION_MARGIN_DOWN_MIN (__cwcn_type_t) BROKER_MARKET_TOTAL_COMMISSION // 0.2%

#define DO_JKIMYEI_RANDOM_MONTECARLO_SEARCH
#define MONTECARLO_EPISODES (int) 50000
#endif