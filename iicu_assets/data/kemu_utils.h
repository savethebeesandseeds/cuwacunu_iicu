#ifndef __KEMU_UTILS__
#define __KEMU_UTILS__
#include "../config/general_config.h"
#include "../config/states_config.h"
#include "../config/broker_config.h"
#include "../data/mewaajacune_utils.h"
//------------- KEMU ------------ ------------
typedef struct __cwcn_matrix {
    __cwcn_type_t **_matrx;
    __cwcn_type_t **_inv_matrx;
    int n_rows;
    int n_cols;
}__cwcn_matrix_t;
//------------- KEMU FUNKS ------------ ------
__cwcn_type_t kemu_sigmoidal(__cwcn_type_t x);
__cwcn_type_t kemu_tanh(__cwcn_type_t x);
__cwcn_type_t max_min_res_rand(__cwcn_type_t _max, __cwcn_type_t _min, int _res);
//------------- KEMU LINALG ------------ -----
__cwcn_matrix_t *fabric_cwcn_matrix(int n_rows, int n_cols);
void destroy_cwcn_matrix(__cwcn_matrix_t *_matrix);

void multiply_cwcn_matrix(__cwcn_matrix_t *dest_matrix, __cwcn_matrix_t *a_matrix, __cwcn_matrix_t *b_matrix);
void multiply_cwcn_inv_a_times_b(__cwcn_matrix_t *dest_matrix, __cwcn_matrix_t *a_matrix, __cwcn_matrix_t *b_matrix);
__cwcn_matrix_t *transpose_fabric_cwcn_matrix(__cwcn_matrix_t *_A);

void matrix_inv_by_gauss_jordan(__cwcn_matrix_t *_A);
int matrix_inv_by_lup(__cwcn_matrix_t *_A);

void print_matrix(__cwcn_matrix_t *_A);
void print_inv_matrix(__cwcn_matrix_t *_A);

int LUPDecompose(__cwcn_type_t **_A, int N, __cwcn_type_t Tol, int *P);
void LUPSolve(__cwcn_type_t **_A, int *P, __cwcn_type_t *b, int N, __cwcn_type_t *x);
void LUPInvert(__cwcn_type_t **_A, int *P, int N, __cwcn_type_t **IA);
__cwcn_type_t LUPDeterminant(__cwcn_type_t **_A, int *P, int N);
#endif