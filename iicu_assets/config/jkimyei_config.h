#ifndef __JKIMYEI_CONFIG__
#define __JKIMYEI_CONFIG__
#include "../config/general_config.h"
#include "../config/broker_config.h"
#define RANGE_EXPLORATION_MARGIN_UP_MAX (__cwcn_type_t) 0.050 // 5.0%
#define RANGE_EXPLORATION_MARGIN_UP_MIN (__cwcn_type_t) 2*BROKER_MARKET_TOTAL_COMMISSION // 2*0.2%
#define RANGE_EXPLORATION_MARGIN_DOWN_MAX (__cwcn_type_t) 0.050 // 5.0%
#define RANGE_EXPLORATION_MARGIN_DOWN_MIN (__cwcn_type_t) 2*BROKER_MARKET_TOTAL_COMMISSION // 2*0.2%

#define POLICY_BASE_INVESTMENT (__cwcn_type_t) 1.0

#define DO_JKIMYEI_RANDOM_MONTECARLO_SEARCH
#define MONTECARLO_EPISODES (int) 14500
#define MONTECARLO_RAND_REPS (int) 1 // every episode is run randomized to mean out the variance influence of the starting point
#define MONTECARLO_RAND_REPS_MAX (int) 0x01 //KLINES_N_LIMIT/50
#define MONTECARLO_RAND_REPS_LOW (int) 0x00
#endif