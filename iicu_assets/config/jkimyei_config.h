#ifndef __JKIMYEI_CONFIG__
#define __JKIMYEI_CONFIG__
#include "../config/general_config.h"
#include "../config/broker_config.h"
#define RANGE_EXPLORATION_MARGIN_UP_MAX (__cwcn_type_t) 0.050 // 5.0%
#define RANGE_EXPLORATION_MARGIN_UP_MIN (__cwcn_type_t) BROKER_MARKET_TOTAL_COMMISSION // 0.2%
#define RANGE_EXPLORATION_MARGIN_DOWN_MAX (__cwcn_type_t) 0.050 // 5.0%
#define RANGE_EXPLORATION_MARGIN_DOWN_MIN (__cwcn_type_t) BROKER_MARKET_TOTAL_COMMISSION // 0.2%

#define DO_JKIMYEI_RANDOM_MONTECARLO_SEARCH
#define MONTECARLO_EPISODES (int) 5000

typedef enum {HILBERT_SIGMOIDAL,HILBERT_TANH} __hilbert_basis_t;
#define DO_REGRESSIVE_BISHOP_LINEAR_REGRESSION
#define HILBERT_DESING_SIZE (int) 10
#define HILBERT_DESING_BASIS (__hilbert_basis_t) HILBERT_TANH
#define HILBERT_DESING_SPARTIAL_SCALE (__cwcn_type_t) 2.0
#endif