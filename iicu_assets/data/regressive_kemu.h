#ifndef __REGRESSIVE_KEMU__
#define __REGRESSIVE_KEMU__
#include "../config/general_config.h"
#include "../config/threads_config.h"
#include "../data/kemu_utils.h"
#include "../data/mewaajacune_utils.h"
#include "../config/regressive_config.h"
typedef struct __cwcn_bishop_linear_regression_kemu {
    __cwcn_matrix_t *__moore_penrose_pseudo_inverse;
    __cwcn_matrix_t *__desing_matrix;
    __cwcn_matrix_t *__w_coefs; // including bias
    __hilbert_basis_t __h_basis; // hilbert space basis
    __iicu_mewaajacune_t *__mewaajacune; // data
    __cwcn_matrix_t *__mwjcn_matrx; // data as a matrix
    __cwcn_type_t __mwjcn_mean;
    __cwcn_type_t __mwjcn_std;
}__bishop_linear_regression_t;
typedef struct __regressive{
    ___cwcn_bool_t __rg_blrk_has_computed; // to know if rg is empty
    __iicu_mewaajacune_t *__rg_mewaajacune;
    __bishop_linear_regression_t *__rg_blrk;
}__iicu_regressive_t;

void *regressive_launcher(void *_regressive_thread_order);

__bishop_linear_regression_t *blrk_fabric(__iicu_regressive_t *_regressive);
__bishop_linear_regression_t *blrk_clone_fabric(__iicu_regressive_t *scr_iicu_regressive, __bishop_linear_regression_t *src_blrk);
void rebase_blrk(__bishop_linear_regression_t *dest_blrk, __bishop_linear_regression_t *src_blrk);
void destroy_blrk(__bishop_linear_regression_t *_blrk);

__iicu_regressive_t *regressive_fabric();
__iicu_regressive_t *regressive_clone_fabric(__iicu_regressive_t *src_iicu_regressive);
void rebase_regressive(__iicu_regressive_t *dest_iicu_regressive, __iicu_regressive_t *src_iicu_regressive);
void destroy_regressive(__iicu_regressive_t *_iicu_regressive);

void bishop_build_desing_matrix(__bishop_linear_regression_t *_blrk);
void bishop_linear_regression(__iicu_regressive_t *_regressive);
void load_mewaajacune_into_iicu_matrix(__iicu_mewaajacune_t *_mewaajacune, int _alliu_index, __cwcn_matrix_t *_A);
#endif