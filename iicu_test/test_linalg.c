#include "../iicu_assets/config/general_config.h"
#include "../iicu_assets/config/sdl_config.h"
#include "../iicu_assets/data/kemu_utils.h"

int main(){

    int matsize=1000;
    __cwcn_matrix_t *A=fabric_cwcn_matrix(matsize, matsize);
    for(int _i=0x00;_i<matsize;_i++){
        for(int _j=0x00;_j<matsize;_j++){
            // fprintf(stdout,"[%d][%d]:",_i,_j);
            // scanf("%f",&A->_matrx[_i][_j]);
            A->_matrx[_i][_j]=rand()%100;
        }
    }
    // fprintf(stdout,"The input matrix is:\n");
    // print_matrix(A);
    // --- --- --- --- --- --- --- --- --- --- --- --- --- --- 
    Uint32 start_time = SDL_GetTicks();
    // --- --- --- --- --- --- --- --- --- --- --- --- --- --- test inv by gauss
    // matrix_inv_by_gauss_jordan(A);
    // print_matrix(A);
    // print_inv_matrix(A);
    // --- --- --- --- --- --- --- --- --- --- --- --- --- --- test LU decomposition
    matrix_inv_by_lup(A);
    // print_matrix(A);
    // print_inv_matrix(A);
    // for(int _i=0x00;_i<matsize;_i++){
    //     fprintf(stdout,"P[%d]:%f\n",_i,P[_i]);
    // }
    // --- --- --- --- --- --- --- --- --- --- --- --- --- --- 
    Uint32 end_time = SDL_GetTicks();
    // --- --- --- --- --- --- --- --- --- --- --- --- --- --- 
    Uint32 delta_time=end_time-start_time;
    fprintf(stdout,"EXE TIME : %d\n",delta_time);
    // fprintf(stdout,"The inverse matrix is:\n");
    // print_inv_matrix(A);
    destroy_cwcn_matrix(A);
}