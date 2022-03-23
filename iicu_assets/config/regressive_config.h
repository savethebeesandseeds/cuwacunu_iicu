#ifndef __REGRESSIVE_CONFIG__
#define __REGRESSIVE_CONFIG__
#include "../config/general_config.h"
#include "../config/broker_config.h"

#define DO_REGRESSIVE_BISHOP_LINEAR_REGRESSION
typedef enum {HILBERT_SIGMOIDAL,HILBERT_TANH} __hilbert_basis_t;
#define HILBERT_DESING_SIZE (int) 10
#define HILBERT_DESING_BASIS (__hilbert_basis_t) HILBERT_TANH
#define HILBERT_DESING_SPARTIAL_SCALE (__cwcn_type_t) 2.0

#endif