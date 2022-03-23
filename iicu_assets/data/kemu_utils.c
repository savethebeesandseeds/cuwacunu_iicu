#include "kemu_utils.h"

__cwcn_type_t max_min_res_rand(__cwcn_type_t _max, __cwcn_type_t _min, int _res){
    return ((__cwcn_type_t)(rand() % _res))/((__cwcn_type_t)_res)*(_max-_min)+_min;
}
__cwcn_type_t kemu_sigmoidal(__cwcn_type_t x){
    return x/(1+fabs(x));
}
__cwcn_type_t kemu_tanh(__cwcn_type_t x){
    return tanh(x);
}


void print_matrix(__cwcn_matrix_t *_A){
    fprintf(stdout,"--- --- --- MATRIX\n");
    for(int _i=0x00;_i<_A->n_rows;_i++){
        for(int _j=0x00;_j<_A->n_cols;_j++){
            fprintf(stdout,"%f  ",_A->_matrx[_i][_j]);
        }
        fprintf(stdout,"\n");
    }
}
void print_inv_matrix(__cwcn_matrix_t *_A){
    fprintf(stdout,"--- --- --- INV\n");
    for(int _i=0x00;_i<_A->n_rows;_i++){
        for(int _j=0x00;_j<_A->n_cols;_j++){
            fprintf(stdout,"%f  ",_A->_inv_matrx[_i][_j]);
        }
        fprintf(stdout,"\n");
    }
}
__cwcn_matrix_t *fabric_cwcn_matrix(int n_rows, int n_cols){
    __cwcn_matrix_t *new_cwcn_matrix=malloc(n_rows*sizeof(__cwcn_matrix_t *));
    new_cwcn_matrix->_matrx=malloc(n_rows*sizeof(__cwcn_type_t *));
    new_cwcn_matrix->_inv_matrx=malloc(n_rows*sizeof(__cwcn_type_t *));
    new_cwcn_matrix->n_rows=n_rows;
    new_cwcn_matrix->n_cols=n_cols;
    for(int _i=0x00;_i<new_cwcn_matrix->n_rows;_i++){
        new_cwcn_matrix->_matrx[_i]=malloc(new_cwcn_matrix->n_cols*sizeof(__cwcn_type_t));
        new_cwcn_matrix->_inv_matrx[_i]=malloc(new_cwcn_matrix->n_cols*sizeof(__cwcn_type_t));
    }
    return new_cwcn_matrix;
}
__cwcn_matrix_t *clone_fabric_cwcn_matrix(__cwcn_matrix_t *src_cwcn_matrix){
    __cwcn_matrix_t *new_cwcn_matrix=NULL;
    rebase_cwcn_matrix(new_cwcn_matrix,src_cwcn_matrix);
    return new_cwcn_matrix;
}
void rebase_cwcn_matrix(__cwcn_matrix_t *dest_cwcn_matrix, __cwcn_matrix_t *src_cwcn_matrix){
    if(dest_cwcn_matrix!=NULL){
        destroy_cwcn_matrix(dest_cwcn_matrix);
    }
    dest_cwcn_matrix=fabric_cwcn_matrix(src_cwcn_matrix->n_rows, src_cwcn_matrix->n_cols);
    memcpy(dest_cwcn_matrix->_matrx,src_cwcn_matrix->_matrx,src_cwcn_matrix->n_rows*sizeof(__cwcn_type_t *));
    memcpy(dest_cwcn_matrix->_inv_matrx,src_cwcn_matrix->_inv_matrx,src_cwcn_matrix->n_rows*sizeof(__cwcn_type_t *));
    for(int _i=0x00;_i<dest_cwcn_matrix->n_rows;_i++){
        memcpy(dest_cwcn_matrix->_matrx[_i],src_cwcn_matrix->_matrx[_i],src_cwcn_matrix->n_cols*sizeof(__cwcn_type_t));
        memcpy(dest_cwcn_matrix->_inv_matrx[_i],src_cwcn_matrix->_inv_matrx[_i],src_cwcn_matrix->n_cols*sizeof(__cwcn_type_t));
    }
}
void destroy_cwcn_matrix(__cwcn_matrix_t *_matrix){
    for(int _i=0x00;_i<_matrix->n_rows;_i++){
        free(_matrix->_matrx[_i]);
        free(_matrix->_inv_matrx[_i]);
    }
    free(_matrix->_matrx);
}
void multiply_cwcn_matrix(__cwcn_matrix_t *dest_matrix, __cwcn_matrix_t *a_matrix, __cwcn_matrix_t *b_matrix){
    assert(a_matrix->n_cols==b_matrix->n_rows); // unable to multiply matrix
    assert(dest_matrix->n_rows==a_matrix->n_rows); // unable to multiply matrix
    assert(dest_matrix->n_cols==b_matrix->n_cols); // unable to multiply matrix
    __cwcn_type_t **dest_matrx=dest_matrix->_matrx;
    __cwcn_type_t **a_matrx=a_matrix->_matrx;
    __cwcn_type_t **b_matrx=b_matrix->_matrx;
    __cwcn_type_t sum=0x00;
    int a_nr,a_nc,b_nc;
    for(a_nr=0x00;a_nr<a_matrix->n_rows;a_nr++){
        for(b_nc=0x00;b_nc<b_matrix->n_cols;b_nc++){
            sum=0x00;
            for(a_nc=0x00;a_nc<a_matrix->n_cols;a_nc++){
                sum+=a_matrx[a_nr][a_nc]*b_matrx[a_nc][b_nc];
            }
            dest_matrx[a_nr][b_nc]=sum;
        }
    }
}
void multiply_cwcn_inv_a_times_b(__cwcn_matrix_t *dest_matrix, __cwcn_matrix_t *a_matrix, __cwcn_matrix_t *b_matrix){
    assert(a_matrix->n_cols==b_matrix->n_rows); // unable to multiply matrix
    assert(dest_matrix->n_rows==a_matrix->n_rows); // unable to multiply matrix
    assert(dest_matrix->n_cols==b_matrix->n_cols); // unable to multiply matrix
    __cwcn_type_t **dest_matrx=dest_matrix->_matrx;
    __cwcn_type_t **a_matrx=a_matrix->_inv_matrx;
    __cwcn_type_t **b_matrx=b_matrix->_matrx;
    __cwcn_type_t sum=0x00;
    int a_nr,a_nc,b_nc;
    for(a_nr=0x00;a_nr<a_matrix->n_rows;a_nr++){
        for(b_nc=0x00;b_nc<b_matrix->n_cols;b_nc++){
            sum=0x00;
            for(a_nc=0x00;a_nc<a_matrix->n_cols;a_nc++){
                sum+=a_matrx[a_nr][a_nc]*b_matrx[a_nc][b_nc];
            }
            dest_matrx[a_nr][b_nc]=sum;
        }
    }
}
__cwcn_matrix_t *transpose_fabric_cwcn_matrix(__cwcn_matrix_t *_A){
    __cwcn_matrix_t *new_A_T=fabric_cwcn_matrix(_A->n_cols,_A->n_rows);
    int a_nr,a_nc;
    for(a_nr=0x00;a_nr<_A->n_rows;a_nr++){
        for(a_nc=0x00;a_nc<_A->n_cols;a_nc++){
            new_A_T->_matrx[a_nc][a_nr]=_A->_matrx[a_nr][a_nc];
        }
    }
    return new_A_T;
}
void matrix_inv_by_gauss_jordan(__cwcn_matrix_t *_A){
    // --- initialize!
    int _i,_j,_k,matsize;
    __cwcn_type_t _temp;
    assert(_A->n_rows==_A->n_cols); // only square matrix have inverts
    matsize=_A->n_rows;
    __cwcn_type_t **temp_A=malloc(matsize*sizeof(__cwcn_type_t *));
    for(int _i=0x00;_i<matsize;_i++){
        temp_A[_i]=malloc(matsize*sizeof(__cwcn_type_t));
        for(int _j=0x00;_j<matsize;_j++){
            temp_A[_i][_j]=_A->_matrx[_i][_j];
            if(_i==_j){_A->_inv_matrx[_i][_j]=0x01;} else {_A->_inv_matrx[_i][_j]=0x00;}
        }
    }
    __cwcn_type_t **temp_INV_A=_A->_inv_matrx;
    // --- start of method!
    for(_k=0x00;_k<matsize;_k++){
        _temp=temp_A[_k][_k];
        for(_j=0x00;_j<matsize;_j++){
            temp_A[_k][_j]/=_temp;
            temp_INV_A[_k][_j]/=_temp;
        }
        for(_i=0x00;_i<matsize;_i++){
            _temp=temp_A[_i][_k];
            for(_j=0x00;_j<matsize;_j++){
                if(_i==_k){break;}
                temp_A[_i][_j]-=temp_A[_k][_j]*_temp;
                temp_INV_A[_i][_j]-=temp_INV_A[_k][_j]*_temp;
            }
        }
    }
    // --- end of method!
}

int matrix_inv_by_lup(__cwcn_matrix_t *_A){
    // --- initialize!
    __cwcn_type_t Tol=LU_DECOMPOSITION_TOLERANCE;
    int matsize;
    if(_A->n_rows!=_A->n_cols){ // only square matrix have inverts
        return 0;
    }
    matsize=_A->n_rows;
    int *P=malloc((matsize+0x01)*sizeof(int));
    // --- end of method!
    if(!LUPDecompose(_A->_matrx, matsize, Tol, P)){
        return 0;
    }
    LUPInvert(_A->_matrx, P, matsize, _A->_inv_matrx);
    // --- end of method!
    free(P);
    return 1;
}

// REFERENCE: https://en.wikipedia.org/wiki/LU_decomposition

/* INPUT: A - array of pointers to rows of a square matrix having dimension N
 *        Tol - small tolerance number to detect failure when the matrix is near degenerate
 * OUTPUT: Matrix A is changed, it contains a copy of both matrices L-E and U as A=(L-E)+U such that P*A=L*U.
 *        The permutation matrix is not stored as a matrix, but in an integer vector P of size N+1 
 *        containing column indexes where the permutation matrix has "1". The last element P[N]=S+N, 
 *        where S is the number of row exchanges needed for determinant computation, det(P)=(-1)^S    
 */
int LUPDecompose(__cwcn_type_t **_A, int N, __cwcn_type_t Tol, int *P) {

    int i, j, k, imax; 
    __cwcn_type_t maxA, *ptr, absA;

    for (i = 0; i <= N; i++)
        P[i] = i; //Unit permutation matrix, P[N] initialized with N

    for (i = 0; i < N; i++) {
        maxA = 0.0;
        imax = i;

        for (k = i; k < N; k++)
            if ((absA = fabs(_A[k][i])) > maxA) { 
                maxA = absA;
                imax = k;
            }

        if (maxA < Tol) return 0; //failure, matrix is degenerate

        if (imax != i) {
            //pivoting P
            j = P[i];
            P[i] = P[imax];
            P[imax] = j;

            //pivoting rows of A
            ptr = _A[i];
            _A[i] = _A[imax];
            _A[imax] = ptr;

            //counting pivots starting from N (for determinant)
            P[N]++;
        }

        for (j = i + 1; j < N; j++) {
            _A[j][i] /= _A[i][i];

            for (k = i + 1; k < N; k++)
                _A[j][k] -= _A[j][i] * _A[i][k];
        }
    }

    return 1;  //decomposition done 
}

/* INPUT: A,P filled in LUPDecompose; b - rhs vector; N - dimension
 * OUTPUT: x - solution vector of A*x=b
 */
void LUPSolve(__cwcn_type_t **_A, int *P, __cwcn_type_t *b, int N, __cwcn_type_t *x) {

    for (int i = 0; i < N; i++) {
        x[i] = b[P[i]];

        for (int k = 0; k < i; k++)
            x[i] -= _A[i][k] * x[k];
    }

    for (int i = N - 1; i >= 0; i--) {
        for (int k = i + 1; k < N; k++)
            x[i] -= _A[i][k] * x[k];

        x[i] /= _A[i][i];
    }
}

/* INPUT: A,P filled in LUPDecompose; N - dimension
 * OUTPUT: IA is the inverse of the initial matrix
 */
void LUPInvert(__cwcn_type_t **_A, int *P, int N, __cwcn_type_t **IA) {
  
    for (int j = 0; j < N; j++) {
        for (int i = 0; i < N; i++) {
            IA[i][j] = P[i] == j ? 1.0 : 0.0;

            for (int k = 0; k < i; k++)
                IA[i][j] -= _A[i][k] * IA[k][j];
        }

        for (int i = N - 1; i >= 0; i--) {
            for (int k = i + 1; k < N; k++)
                IA[i][j] -= _A[i][k] * IA[k][j];

            IA[i][j] /= _A[i][i];
        }
    }
}

/* INPUT: A,P filled in LUPDecompose; N - dimension. 
 * OUTPUT: Function returns the determinant of the initial matrix
 */
__cwcn_type_t LUPDeterminant(__cwcn_type_t **_A, int *P, int N) {

    __cwcn_type_t det = _A[0][0];

    for (int i = 1; i < N; i++)
        det *= _A[i][i];

    return (P[N] - N) % 2 == 0 ? det : -det;
}
