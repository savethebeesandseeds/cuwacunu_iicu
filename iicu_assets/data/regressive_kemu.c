#include "regressive_kemu.h"

void *regressive_launcher(void *_rg_thread_order){
    fprintf(stdout,"[cuwacunu:regressive] %sstart regressive_launcher%s\n",COLOR_WARNING,COLOR_REGULAR);
    // it finds for _iicu_regressive the best policy
    ((__regressive_thread_order_t*)_rg_thread_order)->__rg_thead_is_bussy=0x01;
    __iicu_wikimyei_t *temp_iicu_wikimyei=((__regressive_thread_order_t*)_rg_thread_order)->__ref_iicu_wikimyei;
    // --- --- --- 
    // --- --- --- #FIXME make bessech as a wrapper for optm methods
    beseech_mewaajacune(temp_iicu_wikimyei, 
        ((__regressive_thread_order_t*)_rg_thread_order)->__scene_id, 
        ((__regressive_thread_order_t*)_rg_thread_order)->__kline_id);
    beseech_regressive(temp_iicu_wikimyei, 
        ((__regressive_thread_order_t*)_rg_thread_order)->__scene_id);
    // --- --- --- 
    __iicu_regressive_t *temp_iicu_regressive=regressive_clone_fabric(
        get_regressive(temp_iicu_wikimyei, 
        ((__regressive_thread_order_t*)_rg_thread_order)->__scene_id)); // make a temporal copy
    temp_iicu_regressive->__rg_mewaajacune=mewaajacune_clone_fabric(
        get_mewaajacune(temp_iicu_wikimyei, 
        ((__regressive_thread_order_t*)_rg_thread_order)->__scene_id, 
        ((__regressive_thread_order_t*)_rg_thread_order)->__kline_id)); // load mewaajacune to temporal copy
    // --- --- --- 
    release_regressive(temp_iicu_wikimyei, 
        ((__regressive_thread_order_t*)_rg_thread_order)->__scene_id);
    release_mewaajacune(temp_iicu_wikimyei, 
        ((__regressive_thread_order_t*)_rg_thread_order)->__scene_id, 
        ((__regressive_thread_order_t*)_rg_thread_order)->__kline_id);
    // --- --- --- LAUNCH type METHOD
    switch(((__regressive_thread_order_t*)_rg_thread_order)->__rg_type){
    case RG_BISHOP_LINEAR_REGRESSION:
        bishop_linear_regression(temp_iicu_regressive);
        break;
    default:
        fprintf(stderr,"[cuwacunu:]%sERROR, not understood regressive type configured in regressive thread order%s\n",COLOR_DANGER,COLOR_REGULAR);
        break;
    }
    // --- --- --- #FIXME add tsdo
    // --- --- --- SAVES JKIMYEI RESULT
    beseech_mewaajacune(temp_iicu_wikimyei, 
        ((__regressive_thread_order_t*)_rg_thread_order)->__scene_id,
        ((__regressive_thread_order_t*)_rg_thread_order)->__kline_id);
    beseech_regressive(temp_iicu_wikimyei, 
        ((__regressive_thread_order_t*)_rg_thread_order)->__scene_id);
    // --- --- --- 
    rebase_regressive(get_regressive(temp_iicu_wikimyei, 
        ((__regressive_thread_order_t*)_rg_thread_order)->__scene_id), 
        temp_iicu_regressive);
    // --- --- --- 
    release_regressive(temp_iicu_wikimyei, 
        ((__regressive_thread_order_t*)_rg_thread_order)->__scene_id);
    release_mewaajacune(temp_iicu_wikimyei, 
        ((__regressive_thread_order_t*)_rg_thread_order)->__scene_id,
        ((__regressive_thread_order_t*)_rg_thread_order)->__kline_id);
    // --- --- --- 
    destroy_regressive(temp_iicu_regressive);
    // --- --- --- 
    ((__regressive_thread_order_t*)_rg_thread_order)->__rg_thead_is_bussy=0x00;
    fprintf(stdout,"[cuwacunu:regressive] %send regressive_launcher%s\n",COLOR_WARNING,COLOR_REGULAR);
    pthread_exit(NULL);
}


/*
    LINEAR REGRESSION (BISHOP TEXBOOK, IMPLEMENTATION IN C)
*/
void bishop_build_desing_matrix(__bishop_linear_regression_t *_blrk){
    // --- --- --- 
    __cwcn_matrix_t *c_desing_matrix=_blrk->__desing_matrix;
    assert(c_desing_matrix->n_rows==_blrk->__mewaajacune->__load_size); // unable to fit design matrix
    assert(c_desing_matrix->n_cols==HILBERT_DESING_SIZE); // unable to fit design matrix
    __cwcn_type_t **c_dmtx=c_desing_matrix->_matrx;
    // --- --- --- LINESPACE
    __cwcn_type_t *h_miu=malloc(HILBERT_DESING_SIZE*sizeof(__cwcn_type_t));
    __cwcn_type_t h_start_miu=-0x01; // since the regresion is done on normalized data this number means 1 std from the mean
    __cwcn_type_t h_end_miu=0x01; // since the regresion is done on normalized data this number means 1 std from the mean
    __cwcn_type_t h_step=(h_end_miu-h_start_miu)/(((__cwcn_type_t)HILBERT_DESING_SIZE-0x01));
    h_miu[0x00]=h_start_miu; // #FIXME know that value in position h_miu[0x00] (relax)
    for(int h_idx=0x01;h_idx<HILBERT_DESING_SIZE-0x01;h_idx++){
        h_miu[h_idx]=h_miu[h_idx-0x01]+h_step;
    }
    h_miu[HILBERT_DESING_SIZE-0x01]=h_end_miu;
    // --- --- --- 
    __cwcn_type_t hdss=(__cwcn_type_t)HILBERT_DESING_SPARTIAL_SCALE;
    switch(_blrk->__h_basis){
    case HILBERT_SIGMOIDAL:
        for(int mwj_idx=0x00;mwj_idx<_blrk->__mewaajacune->__load_size;mwj_idx++){
            c_dmtx[mwj_idx][0x00]=0x01; // the basis is one
            for(int h_idx=0x01;h_idx<HILBERT_DESING_SIZE;h_idx++){
                c_dmtx[mwj_idx][h_idx]=(_blrk->__mwjcn_matrx->_matrx[mwj_idx][0x00]-h_miu[h_idx])/hdss; // the items are sigmoidal
                c_dmtx[mwj_idx][h_idx]=kemu_sigmoidal(c_dmtx[mwj_idx][h_idx]);
            }
        }
        break;
    case HILBERT_TANH:
        for(int mwj_idx=0x00;mwj_idx<_blrk->__mewaajacune->__load_size;mwj_idx++){
            c_dmtx[mwj_idx][0x00]=0x01; // the basis is one
            for(int h_idx=0x01;h_idx<HILBERT_DESING_SIZE;h_idx++){
                c_dmtx[mwj_idx][h_idx]=(_blrk->__mwjcn_matrx->_matrx[mwj_idx][0x00]-h_miu[h_idx])/hdss; // the items are hyperbolic tangent
                c_dmtx[mwj_idx][h_idx]=kemu_tanh(c_dmtx[mwj_idx][h_idx]);
            }
        }
        break;
    default:
        assert(0x00);// not understsood hilbert basis on desing matrix
        break;
    }
    free(h_miu);
}

__bishop_linear_regression_t *blrk_fabric(__iicu_regressive_t *_iicu_regressive){
    __bishop_linear_regression_t *new_blrk=malloc(sizeof(__bishop_linear_regression_t));
    new_blrk->__desing_matrix=fabric_cwcn_matrix(_iicu_regressive->__rg_mewaajacune->__load_size, HILBERT_DESING_SIZE);
    new_blrk->__moore_penrose_pseudo_inverse=fabric_cwcn_matrix(HILBERT_DESING_SIZE, _iicu_regressive->__rg_mewaajacune->__load_size);
    new_blrk->__w_coefs=fabric_cwcn_matrix(HILBERT_DESING_SIZE, 0X01);
    new_blrk->__h_basis=HILBERT_DESING_BASIS;
    new_blrk->__mewaajacune=_iicu_regressive->__rg_mewaajacune;
    new_blrk->__mwjcn_matrx=fabric_cwcn_matrix(_iicu_regressive->__rg_mewaajacune->__load_size, 0x01); // Hx1 = t
    load_mewaajacune_into_iicu_matrix(new_blrk->__mewaajacune, NIJCYOTA_ALLIU_INDEX, new_blrk->__mwjcn_matrx);
    // --- --- --- 
    new_blrk->__mwjcn_mean=mean_alliu_in_load(new_blrk->__mewaajacune, NIJCYOTA_ALLIU_INDEX);
    new_blrk->__mwjcn_std=std_alliu_in_load(new_blrk->__mewaajacune, NIJCYOTA_ALLIU_INDEX);
    for(int mwj_idx=0x00;mwj_idx<new_blrk->__mewaajacune->__load_size;mwj_idx++){
        new_blrk->__mwjcn_matrx->_matrx[mwj_idx][0x00]=(new_blrk->__mwjcn_matrx->_matrx[mwj_idx][0x00]-new_blrk->__mwjcn_mean)/new_blrk->__mwjcn_std; // normalize, remember to denormalize
    }
    // --- --- --- 
    return new_blrk;
}
void destroy_blrk(__bishop_linear_regression_t *_blrk){
    destroy_cwcn_matrix(_blrk->__desing_matrix);
    destroy_cwcn_matrix(_blrk->__moore_penrose_pseudo_inverse);
    destroy_cwcn_matrix(_blrk->__w_coefs);
    // do not destroy mewaajacune, on this object the mewaajacune is just a reference
    destroy_cwcn_matrix(_blrk->__mwjcn_matrx);
    free(_blrk);
}
void load_mewaajacune_into_iicu_matrix(__iicu_mewaajacune_t *_mewaajacune, int _alliu_index, __cwcn_matrix_t *_A){
    int start_index=_mewaajacune->__load_index;
    int d_ctx=0x00;
    load_to_start(_mewaajacune);
    if(_A->n_rows==_mewaajacune->__load_size){
        do{ // load mewaajacune alliu to rows
            _A->_matrx[d_ctx][0x00]=glti(_mewaajacune)->__alliu_state[_alliu_index];
            d_ctx++;
        }while(load_go_up(_mewaajacune)!=-0x01);
    } else if(_A->n_cols==_mewaajacune->__load_size){
        do{ // load mewaajacune alliu_to cols
            _A->_matrx[0x00][d_ctx]=glti(_mewaajacune)->__alliu_state[_alliu_index];
            d_ctx++;
        }while(load_go_up(_mewaajacune)!=-0x01);
    } else { // error, not found matching dimensions
        assert(0x00); // unable to load mewaajacune into matrix
    }
    load_to_index(_mewaajacune,start_index);
}
void bishop_linear_regression(__iicu_regressive_t *_iicu_regressive){
    // --- --- --- 
    clock_t begin;
	clock_t end;
	double time_spent;
    begin = clock();
    // Extracted from Bishop - Pattern recognition and machine learning .3 linear models for regression
    // __linear_fit_alliu_state // alliu_[0x01]
    // __linear_fit_relative_max_alliu_state // alliu_[0x02]
    // __linear_fit_relative_min_alliu_state // alliu_[0x03]
    __bishop_linear_regression_t *c_blrk=blrk_fabric(_iicu_regressive);
    bishop_build_desing_matrix(c_blrk); // phi
    __cwcn_matrix_t *c_phiT=transpose_fabric_cwcn_matrix(c_blrk->__desing_matrix); // phi^T
    __cwcn_matrix_t *c_phiTphi=fabric_cwcn_matrix(HILBERT_DESING_SIZE,HILBERT_DESING_SIZE);
    
    // --- --- --- --- 
    load_print_up_trayectory_queue(_iicu_regressive->__rg_mewaajacune);
    // --- --- --- --- 
    multiply_cwcn_matrix(c_phiTphi, c_phiT, c_blrk->__desing_matrix); // phi^T*phi
    int invertible=matrix_inv_by_lup(c_phiTphi); // (phi^T*phi)^(-1)
    if(invertible==0x01){
        multiply_cwcn_inv_a_times_b(c_blrk->__moore_penrose_pseudo_inverse, c_phiTphi,c_phiT); // (phi^T*phi)^(-1)*phi^T
        multiply_cwcn_matrix(c_blrk->__w_coefs, c_blrk->__moore_penrose_pseudo_inverse, c_blrk->__mwjcn_matrx); // ((phi^T*phi)^(-1)*phi^T)*t
        fprintf(stdout,"%s[cuwacunu:regressive] : bishop_linear_regression : __w_coefs : %s\n",COLOR_WARNING,COLOR_REGULAR);
        print_matrix(c_blrk->__w_coefs);
    } else {
        fprintf(stderr,"%s[ERROR:] non invertible matrix found on bishop_linear_regression!\n%s",COLOR_DANGER,COLOR_REGULAR);
    }
    destroy_cwcn_matrix(c_phiT);
    destroy_cwcn_matrix(c_phiTphi);
    destroy_blrk(c_blrk);
    // --- --- --- 
    end = clock();
    time_spent = (double)(end-begin) / CLOCKS_PER_SEC;
    _iicu_regressive->__rg_blrk_has_computed=0x01;
    // --- --- --- 
    fprintf(stdout,"[cuwacunu:regressive] %send bishop_linear_regression%s : time : %f [s]\n",COLOR_WARNING,COLOR_REGULAR,time_spent);
}



__iicu_regressive_t *regressive_fabric(){
    __iicu_regressive_t *new_iicu_regressive=malloc(sizeof(__iicu_regressive_t));
    new_iicu_regressive->__rg_mewaajacune=NULL;
    new_iicu_regressive->__rg_blrk=blrk_fabric(new_iicu_regressive)
    new_iicu_regressive->__rg_blrk_has_computed=0x00;
    return new_iicu_regressive;
}
__iicu_regressive_t *regressive_clone_fabric(__iicu_regressive_t *src_iicu_regressive){
    __iicu_regressive_t *new_iicu_regressive=regressive_fabric();
    rebase_regressive(new_iicu_regressive,src_iicu_regressive);
    return new_iicu_regressive;
}
void rebase_regressive(__iicu_regressive_t *dest_iicu_regressive, __iicu_regressive_t *src_iicu_regressive){
    if(dest_iicu_regressive->__rg_blrk!=NULL){
        destroy_blrk(dest_iicu_regressive->__rg_blrk);
        dest_iicu_regressive->__rg_blrk=NULL;
    }
    if(dest_iicu_regressive->__rg_mewaajacune!=NULL){
        // destroy_mewaajacune(dest_iicu_jkimyei->__rg_mewaajacune); // do not activate
        dest_iicu_regressive->__rg_mewaajacune=NULL;
    }
    if(src_iicu_regressive->__rg_blrk != NULL){
        dest_iicu_regressive->__rg_blrk=blrk_clone_fabric(src_iicu_regressive->__rg_blrk);
    }
    if(src_iicu_regressive->__rg_mewaajacune != NULL){
        if(dest_iicu_regressive->__rg_mewaajacune!=NULL){
            rebase_mewaajacune(dest_iicu_regressive->__rg_mewaajacune,src_iicu_regressive->__rg_mewaajacune);
        } else {
            dest_iicu_regressive->__rg_mewaajacune=mewaajacune_clone_fabric(src_iicu_regressive->__rg_mewaajacune);
        }
    }
    dest_iicu_regressive->__rg_blrk_has_computed=src_iicu_regressive->__rg_blrk_has_computed;
}
void destroy_regressive(__iicu_regressive_t *_iicu_regressive){
    destroy_blrk(_iicu_regressive->__rg_blrk);
    free(_iicu_regressive);
}