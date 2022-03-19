#include "iicu_loops.h"

void iicu_scene_loop(__iicu_wikimyei_t *_iicu_wikimyei){     
    // fprintf(stdout,"[cuwacunu:] : start : iicu_scene_loop()\n");
get_state(_iicu_wikimyei)->interface_id=IICU_SCREEN_PANEL_STATE_ID;
    // // --- --- --- --- · --- --- --- --- UPDATE 
        update_current_iicu_scene(_iicu_wikimyei);
    step_sdl_object(_iicu_wikimyei->__obj_sdl);
    refresh_current_iicu_scene(_iicu_wikimyei);
        beseech_current_all(_iicu_wikimyei);
            render_state_panel(_iicu_wikimyei);
            render_scene_panel(_iicu_wikimyei);
        release_current_all(_iicu_wikimyei);
    draw_sdl_object(_iicu_wikimyei->__obj_sdl);
        #ifndef __cwcn_CLOCK_THREAD__
        miss_or_catch_sdl_event(_iicu_wikimyei);
        #else
        wait_for_sdl_event(_iicu_wikimyei); //handle_sdl_event(_iicu_wikimyei);
        #endif
    // fprintf(stdout,"[cuwacunu:] : end   : iicu_scene_loop()\n");
}

void loading_loop(__iicu_wikimyei_t *_iicu_wikimyei){
    // fprintf(stdout,"[cuwacunu:] : start : loading_loop()\n");
get_state(_iicu_wikimyei)->interface_id=LOADING_STATE_ID;
    step_sdl_object(_iicu_wikimyei->__obj_sdl);
        render_loading(_iicu_wikimyei);
    draw_sdl_object(_iicu_wikimyei->__obj_sdl);
        update_iicu_state(_iicu_wikimyei);
    // fprintf(stdout,"[cuwacunu:] : end   : loading_loop()\n");
}

void home_loop(__iicu_wikimyei_t *_iicu_wikimyei){
    // fprintf(stdout,"[cuwacunu:] : start : home_loop()\n");
get_state(_iicu_wikimyei)->interface_id=HOME_STATE_ID;
    step_sdl_object(_iicu_wikimyei->__obj_sdl);
        // beseech_current_all(_iicu_wikimyei);
        // render_state_panel(_iicu_wikimyei);
        // release_current_all(_iicu_wikimyei);
        render_home(_iicu_wikimyei->__obj_sdl);
    draw_sdl_object(_iicu_wikimyei->__obj_sdl);
        // handle_sdl_event(_iicu_wikimyei);
        wait_for_sdl_event(_iicu_wikimyei);
    // fprintf(stdout,"[cuwacunu:] : end   : home_loop()\n");
}

int get_next_aviable_jkimyei_thread(__iicu_wikimyei_t *_iicu_wikimyei){
    int v_ret=-0x01;
    for(int _idx_th=0x00;_idx_th<INTERNAL_NUM_THREADS;_idx_th++){
        if(!get_jk_thread_order(_iicu_wikimyei,_idx_th)->__jk_thead_is_bussy){
            v_ret=_idx_th;
            break;
        }
    }
    return v_ret;
}
int get_next_aviable_regressive_thread(__iicu_wikimyei_t *_iicu_wikimyei){
    int v_ret=-0x01;
    for(int _idx_th=0x00;_idx_th<INTERNAL_NUM_THREADS;_idx_th++){
        if(!get_rg_thread_order(_iicu_wikimyei,_idx_th)->__rg_thead_is_bussy){
            v_ret=_idx_th;
            break;
        }
    }
    return v_ret;
}
int get_next_aviable_polinomial_thread(__iicu_wikimyei_t *_iicu_wikimyei){
    int v_ret=-0x01;
    for(int _idx_th=0x00;_idx_th<REGRESSIVE_NUM_THREADS;_idx_th++){
        if(!get_pl_thread_order(_iicu_wikimyei,_idx_th)->__pl_thead_is_bussy){
            v_ret=_idx_th;
            break;
        }
    }
    return v_ret;
}
int get_next_aviable_staticques_thread(__iicu_wikimyei_t *_iicu_wikimyei){
    int v_ret=-0x01;...
    for(int _idx_th=0x00;_idx_th<INTERNAL_NUM_THREADS;_idx_th++){
        if(!get_sq_thread_order(_iicu_wikimyei,_idx_th)->__sq_thead_is_bussy){
            v_ret=_idx_th;
            break;
        }
    }
    return v_ret;
}
void jkimyei_loop(__iicu_wikimyei_t *_iicu_wikimyei){ // #FIXME is only doing current mewaajacune
    // --- --- --- TRYING TO SET THE JK ORDER TO FIX        ^
    fprintf(stdout,"[cuwacunu:] %s jkimyei_loop%s--- ... ---\n",COLOR_WARNING,COLOR_REGULAR);
    // --- --- --- 
    int rc;
    int th_idx;
    int c_scene_id=0x00; // #FIXME
    int c_kline_id=0x00; // #FIXME
    // --- --- --- 
    #ifdef DO_JKIMYEI_RANDOM_MONTECARLO_SEARCH
    th_idx=get_next_aviable_jkimyei_thread(_iicu_wikimyei);
    fprintf(stdout,"[launching:jkimyei_thread] %d for JK_MONTECARLO\n",th_idx);
    if(th_idx!=-0x01){
        get_jk_thread_order(_iicu_wikimyei,th_idx)->__jk_thead_is_bussy=0x01;
        get_jk_thread_order(_iicu_wikimyei,th_idx)->__jk_type=JK_MONTECARLO;
        get_jk_thread_order(_iicu_wikimyei,th_idx)->__scene_id=c_scene_id;
        get_jk_thread_order(_iicu_wikimyei,th_idx)->__kline_id=c_kline_id;
        rc=pthread_create(&get_jk_thread_order(_iicu_wikimyei,th_idx)->__jk_thread_launcher
            ,NULL,jkimyei_launcher,(void*)get_jk_thread_order(_iicu_wikimyei,th_idx));
        if(rc){
            fprintf(stderr,"ERROR; return code from pthread_create(jk_thread_launcher) is %d\n",rc);
            exit(-1);
        }
    } else {
        fprintf(stderr,"%s[ERROR:] unable to launch jkimyei_thread JK_MONTECARLO%s\n",COLOR_DANGER,COLOR_REGULAR);
    }
    #endif
    // --- --- --- 
    // SDL_Delay(100000);
    // pthread_exit(NULL);
}

void regressive_loop(__iicu_wikimyei_t *_iicu_wikimyei){ // #FIXME is only doing current mewaajacune
    // --- --- --- TRYING TO SET THE JK ORDER TO FIX        ^
    fprintf(stdout,"[cuwacunu:] %s regressive_loop%s--- ... ---\n",COLOR_WARNING,COLOR_REGULAR);
    // --- --- --- 
    int rc;
    int th_idx;
    int c_scene_id=0x00; // #FIXME
    int c_kline_id=0x00; // #FIXME
    // --- --- --- 
    #ifdef DO_REGRESSIVE_BISHOP_LINEAR_REGRESSION
    th_idx=get_next_aviable_regressive_thread(_iicu_wikimyei);
    fprintf(stdout,"[launching:regressive_thread] %d for RG_BISHOP_LINEAR_REGRESSION\n",th_idx);
    if(th_idx!=-0x01){
        get_rg_thread_order(_iicu_wikimyei,th_idx)->__rg_thead_is_bussy=0x01;
        get_rg_thread_order(_iicu_wikimyei,th_idx)->__rg_type=RG_BISHOP_LINEAR_REGRESSION;
        get_rg_thread_order(_iicu_wikimyei,th_idx)->__scene_id=c_scene_id;
        get_rg_thread_order(_iicu_wikimyei,th_idx)->__kline_id=c_kline_id;
        rc=pthread_create(&get_rg_thread_order(_iicu_wikimyei,th_idx)->__rg_thread_launcher
            ,NULL,regressive_launcher,(void*)get_rg_thread_order(_iicu_wikimyei,th_idx));
        if(rc){
            fprintf(stderr,"ERROR; return code from pthread_create(rg_thread_launcher) is %d\n",rc);
            exit(-1);
        }
    } else {
        fprintf(stderr,"%s[ERROR:] unable to launch regressive_thread RG_BISHOP_LINEAR_REGRESSION%s\n",COLOR_DANGER,COLOR_REGULAR);
    }
    #endif
    // --- --- --- 
    // SDL_Delay(100000);
    // pthread_exit(NULL);
}

void polinomial_loop(__iicu_wikimyei_t *_iicu_wikimyei){ // #FIXME is only doing current mewaajacune
    // --- --- --- TRYING TO SET THE JK ORDER TO FIX        ^
    fprintf(stdout,"[cuwacunu:] %s polinomial_loop (#FIXME)%s--- ... ---\n",COLOR_WARNING,COLOR_REGULAR);
    // --- --- --- 
    // int rc;
    // int th_idx;
    // int c_scene_id=0x00; // #FIXME
    // int c_kline_id=0x00; // #FIXME
    // // --- --- --- 
    // #ifdef DO_REGRESSIVE_BISHOP_LINEAR_REGRESSION
    // th_idx=get_next_aviable_polinomial_thread(_iicu_wikimyei);
    // fprintf(stdout,"[launching:polinomial_thread] %d for RG_BISHOP_LINEAR_REGRESSION\n",th_idx);
    // if(th_idx!=-0x01){
    //     get_pl_thread_order(_iicu_wikimyei,th_idx)->__pl_thead_is_bussy=0x01;
    //     get_pl_thread_order(_iicu_wikimyei,th_idx)->__pl_type=RG_BISHOP_LINEAR_REGRESSION;
    //     get_pl_thread_order(_iicu_wikimyei,th_idx)->__scene_id=c_scene_id;
    //     get_pl_thread_order(_iicu_wikimyei,th_idx)->__kline_id=c_kline_id;
    //     rc=pthread_create(&get_pl_thread_order(_iicu_wikimyei,th_idx)->__pl_thread_launcher
    //         ,NULL,polinomial_launcher,(void*)get_pl_thread_order(_iicu_wikimyei,th_idx));
    //     if(rc){
    //         fprintf(stderr,"ERROR; return code from pthread_create(pl_thread_launcher) is %d\n",rc);
    //         exit(-1);
    //     }
    // } else {
    //     fprintf(stderr,"%s[ERROR:] unable to launch polinomial_thread RG_BISHOP_LINEAR_REGRESSION%s\n",COLOR_DANGER,COLOR_REGULAR);
    // }
    // #endif
    // --- --- --- 
    // SDL_Delay(100000);
    // pthread_exit(NULL);
}


void staticques_loop(__iicu_wikimyei_t *_iicu_wikimyei){ // #FIXME is only doing current mewaajacune
    // --- --- --- TRYING TO SET THE JK ORDER TO FIX        ^
    fprintf(stdout,"[cuwacunu:] %s staticques_loop (#FIXME)%s--- ... ---\n",COLOR_WARNING,COLOR_REGULAR);
    // --- --- --- 
    // int rc;
    // int th_idx;
    // int c_scene_id=0x00; // #FIXME
    // int c_kline_id=0x00; // #FIXME
    // --- --- --- 
    // #ifdef DO_REGRESSIVE_BISHOP_LINEAR_REGRESSION
    // th_idx=get_next_aviable_staticques_thread(_iicu_wikimyei);
    // fprintf(stdout,"[launching:staticques_thread] %d for RG_BISHOP_LINEAR_REGRESSION\n",th_idx);
    // if(th_idx!=-0x01){
    //     get_rg_thread_order(_iicu_wikimyei,th_idx)->__rg_thead_is_bussy=0x01;
    //     get_rg_thread_order(_iicu_wikimyei,th_idx)->__rg_type=RG_BISHOP_LINEAR_REGRESSION;
    //     get_rg_thread_order(_iicu_wikimyei,th_idx)->__scene_id=c_scene_id;
    //     get_rg_thread_order(_iicu_wikimyei,th_idx)->__kline_id=c_kline_id;
    //     rc=pthread_create(&get_rg_thread_order(_iicu_wikimyei,th_idx)->__rg_thread_launcher
    //         ,NULL,staticques_launcher,(void*)get_rg_thread_order(_iicu_wikimyei,th_idx));
    //     if(rc){
    //         fprintf(stderr,"ERROR; return code from pthread_create(rg_thread_launcher) is %d\n",rc);
    //         exit(-1);
    //     }
    // } else {
    //     fprintf(stderr,"%s[ERROR:] unable to launch staticques_thread RG_BISHOP_LINEAR_REGRESSION%s\n",COLOR_DANGER,COLOR_REGULAR);
    // }
    // #endif
    // --- --- --- 
    // SDL_Delay(100000);
    // pthread_exit(NULL);
}



