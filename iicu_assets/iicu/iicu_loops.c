#include "iicu_loops.h"

void iicu_scene_loop(__iicu_wikimyei_t *_iicu_wikimyei){     
    // fprintf(stdout,"[ %s cuwacunu %s:] : start : iicu_scene_loop()\n",COLOR_CUWACUNU,COLOR_REGULAR);
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
    // fprintf(stdout,"[ %s cuwacunu %s:] : end   : iicu_scene_loop()\n",COLOR_CUWACUNU,COLOR_REGULAR);
}

void iicu_debug_loop(__iicu_wikimyei_t *_iicu_wikimyei){ 
    // fprintf(stdout,"[ %s cuwacunu %s:] : start : iicu_debug_loop()\n",COLOR_CUWACUNU,COLOR_REGULAR);
get_state(_iicu_wikimyei)->interface_id=IICU_SCREEN_PANEL_STATE_ID;
    // // --- --- --- --- · --- --- --- --- UPDATE 
        update_current_iicu_scene(_iicu_wikimyei);
    step_sdl_object(_iicu_wikimyei->__obj_sdl);
    refresh_current_iicu_scene(_iicu_wikimyei);
        beseech_all(_iicu_wikimyei);
            // render_state_panel(_iicu_wikimyei);
            render_debug_panel(_iicu_wikimyei);
        release_all(_iicu_wikimyei);
    draw_sdl_object(_iicu_wikimyei->__obj_sdl);
        #ifndef __cwcn_CLOCK_THREAD__
        miss_or_catch_sdl_event(_iicu_wikimyei);
        #else
        wait_for_sdl_event(_iicu_wikimyei); //handle_sdl_event(_iicu_wikimyei);
        #endif
    // fprintf(stdout,"[ %s cuwacunu %s:] : end   : iicu_debug_loop()\n",COLOR_CUWACUNU,COLOR_REGULAR);
}

void loading_loop(__iicu_wikimyei_t *_iicu_wikimyei){
    // fprintf(stdout,"[ %s cuwacunu %s:] : start : loading_loop()\n",COLOR_CUWACUNU,COLOR_REGULAR);
get_state(_iicu_wikimyei)->interface_id=LOADING_STATE_ID;
    step_sdl_object(_iicu_wikimyei->__obj_sdl);
        render_loading(_iicu_wikimyei);
    draw_sdl_object(_iicu_wikimyei->__obj_sdl);
        // update_iicu_state(_iicu_wikimyei);
        SDL_Delay(2500); // #FIXME innesessary
    // fprintf(stdout,"[ %s cuwacunu %s:] : end   : loading_loop()\n",COLOR_CUWACUNU,COLOR_REGULAR);
}

void home_loop(__iicu_wikimyei_t *_iicu_wikimyei){
    // fprintf(stdout,"[ %s cuwacunu %s:] : start : home_loop()\n",COLOR_CUWACUNU,COLOR_REGULAR);
get_state(_iicu_wikimyei)->interface_id=HOME_STATE_ID;
    step_sdl_object(_iicu_wikimyei->__obj_sdl);
        // beseech_current_all(_iicu_wikimyei);
        // render_state_panel(_iicu_wikimyei);
        // release_current_all(_iicu_wikimyei);
        render_home(_iicu_wikimyei->__obj_sdl);
    draw_sdl_object(_iicu_wikimyei->__obj_sdl);
        // handle_sdl_event(_iicu_wikimyei);
        wait_for_sdl_event(_iicu_wikimyei);
    // fprintf(stdout,"[ %s cuwacunu %s:] : end   : home_loop()\n",COLOR_CUWACUNU,COLOR_REGULAR);
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
    for(int _idx_th=0x00;_idx_th<INTERNAL_NUM_THREADS;_idx_th++){
        if(!get_pl_thread_order(_iicu_wikimyei,_idx_th)->__pl_thead_is_bussy){
            v_ret=_idx_th;
            break;
        }
    }
    return v_ret;
}
int get_next_aviable_staticques_thread(__iicu_wikimyei_t *_iicu_wikimyei){
    int v_ret=-0x01;
    for(int _idx_th=0x00;_idx_th<INTERNAL_NUM_THREADS;_idx_th++){
        if(!get_sq_thread_order(_iicu_wikimyei,_idx_th)->__sq_thead_is_bussy){
            v_ret=_idx_th;
            break;
        }
    }
    return v_ret;
}
int get_next_aviable_itsaave_thread(__iicu_wikimyei_t *_iicu_wikimyei){
    int v_ret=-0x01;
    for(int _idx_th=0x00;_idx_th<MAX_IICU_ITSAAVES;_idx_th++){
        if(!get_it_thread_order(_iicu_wikimyei,_idx_th)->__it_thead_is_bussy){
            v_ret=_idx_th;
            break;
        }
    }
    return v_ret;
}
void jkimyei_loop(__iicu_wikimyei_t *_iicu_wikimyei){ // #FIXME is only doing current mewaajacune
    // --- --- --- TRYING TO SET THE JK ORDER TO FIX        ^
    fprintf(stdout,"[ %s cuwacunu %s:] %s jkimyei_loop%s--- --- ---\n",COLOR_CUWACUNU,COLOR_REGULAR,COLOR_WARNING,COLOR_REGULAR);
    // --- --- --- 
    int rc;
    int th_idx;
    beseech_current_nijcyota(_iicu_wikimyei);
    int c_kline_id=giicn(_iicu_wikimyei)->jkimyei_klines_index;
    release_current_nijcyota(_iicu_wikimyei);
    // --- --- --- 
    #ifdef DO_JKIMYEI_RANDOM_MONTECARLO_SEARCH
    for(int scene_idx=0x00;scene_idx<MAX_IICU_SCENES;scene_idx++){
        th_idx=get_next_aviable_jkimyei_thread(_iicu_wikimyei);
        get_jk_thread_order(_iicu_wikimyei,th_idx)->__jk_type=JK_MONTECARLO;
        get_jk_thread_order(_iicu_wikimyei,th_idx)->__kline_id=c_kline_id; // #FIXME
        get_jk_thread_order(_iicu_wikimyei,th_idx)->__scene_id=scene_idx;
        if(th_idx!=-0x01){
            fprintf(stdout,"[launching:jkimyei_thread] [scene:[%d], kline:[%d]] thead sucess in id: %d for JK_MONTECARLO\n",scene_idx,c_kline_id,th_idx);
            get_jk_thread_order(_iicu_wikimyei,th_idx)->__jk_thead_is_bussy=0x01;
            rc=pthread_create(&get_jk_thread_order(_iicu_wikimyei,th_idx)->__jk_threads_launcher
                ,NULL,jkimyei_launcher,(void*)get_jk_thread_order(_iicu_wikimyei,th_idx));
            if(rc){fprintf(stderr,"ERROR; return code from pthread_create(jk_threads_launcher) is %d\n",rc);exit(-1);}
        } else {fprintf(stderr,"%s[ERROR:] unable to launch jkimyei_thread JK_MONTECARLO : unable to alocate required thread : %d %s\n",COLOR_DANGER,scene_idx,COLOR_REGULAR);}
    } 
    #endif
    // --- --- --- 
    // SDL_Delay(100000);
    // pthread_exit(NULL);
}

void regressive_loop(__iicu_wikimyei_t *_iicu_wikimyei){ // #FIXME is only doing current mewaajacune
    // --- --- --- TRYING TO SET THE JK ORDER TO FIX        ^
    fprintf(stdout,"[ %s cuwacunu %s:] %s regressive_loop%s--- --- ---\n",COLOR_CUWACUNU,COLOR_REGULAR,COLOR_WARNING,COLOR_REGULAR);
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
        rc=pthread_create(&get_rg_thread_order(_iicu_wikimyei,th_idx)->__rg_threads_launcher
            ,NULL,regressive_launcher,(void*)get_rg_thread_order(_iicu_wikimyei,th_idx));
        if(rc){
            fprintf(stderr,"ERROR; return code from pthread_create(rg_threads_launcher) is %d\n",rc);
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
    fprintf(stdout,"[ %s cuwacunu %s:] %s polinomial_loop (#FIXME empty)%s--- --- ---\n",COLOR_CUWACUNU,COLOR_REGULAR,COLOR_WARNING,COLOR_REGULAR);
    // --- --- --- 
    // int rc;
    // int th_idx;
    // int c_scene_id=0x00; // #FIXME
    // int c_kline_id=0x00; // #FIXME
    // // --- --- --- 
    // #ifdef DO_POLINOMIAL_PL_KIKE_METHOD
    // th_idx=get_next_aviable_polinomial_thread(_iicu_wikimyei);
    // fprintf(stdout,"[launching:polinomial_thread] %d for PL_KIKE_METHOD\n",th_idx);
    // if(th_idx!=-0x01){
    //     get_pl_thread_order(_iicu_wikimyei,th_idx)->__pl_thead_is_bussy=0x01;
    //     get_pl_thread_order(_iicu_wikimyei,th_idx)->__pl_type=PL_KIKE_METHOD;
    //     get_pl_thread_order(_iicu_wikimyei,th_idx)->__scene_id=c_scene_id;
    //     get_pl_thread_order(_iicu_wikimyei,th_idx)->__kline_id=c_kline_id;
    //     rc=pthread_create(&get_pl_thread_order(_iicu_wikimyei,th_idx)->__pl_threads_launcher
    //         ,NULL,polinomial_launcher,(void*)get_pl_thread_order(_iicu_wikimyei,th_idx));
    //     if(rc){
    //         fprintf(stderr,"ERROR; return code from pthread_create(pl_threads_launcher) is %d\n",rc);
    //         exit(-1);
    //     }
    // } else {
    //     fprintf(stderr,"%s[ERROR:] unable to launch polinomial_thread PL_KIKE_METHOD%s\n",COLOR_DANGER,COLOR_REGULAR);
    // }
    // #endif
    // --- --- --- 
    // // SDL_Delay(100000);
    // // pthread_exit(NULL);
}

void staticques_loop(__iicu_wikimyei_t *_iicu_wikimyei){ // #FIXME is only doing current mewaajacune
    // --- --- --- TRYING TO SET THE JK ORDER TO FIX        ^
    fprintf(stdout,"[ %s cuwacunu %s:] %s staticques_loop (empty)%s--- --- ---\n",COLOR_CUWACUNU,COLOR_REGULAR,COLOR_WARNING,COLOR_REGULAR);
    // --- --- --- 
    int rc;
    int th_idx;
    // --- --- --- 
    for(int c_scene_id=0x00;c_scene_id<MAX_IICU_SCENES;c_scene_id++){ // all symbols #FIXME
        // --- --- --- 
        #ifdef DO_STATICQUES_FIRST_ORDER_STATISTICS
        th_idx=get_next_aviable_staticques_thread(_iicu_wikimyei);
        fprintf(stdout,"[launching:staticques_thread] %d for FIRST_ORDER_STATISTICS\n",th_idx);
        if(th_idx!=-0x01){
            get_sq_thread_order(_iicu_wikimyei,th_idx)->__sq_type=FIRST_ORDER_STATISTICS;
            get_sq_thread_order(_iicu_wikimyei,th_idx)->__scene_id=c_scene_id;
            rc=pthread_create(&get_sq_thread_order(_iicu_wikimyei,th_idx)->__sq_threads_launcher
                ,NULL,staticques_launcher,(void*)get_sq_thread_order(_iicu_wikimyei,th_idx));
            if(rc){
                fprintf(stderr,"ERROR; return code from pthread_create(sq_threads_launcher) is %d\n",rc);
                exit(-1);
            }
        } else {
            fprintf(stderr,"%s[ERROR:] unable to launch staticques_thread FIRST_ORDER_STATISTICS%s\n",COLOR_DANGER,COLOR_REGULAR);
        }
        #endif
        #ifdef DO_STATICQUES_FIRST_ORDER_AUTOREGRESSION
        th_idx=get_next_aviable_staticques_thread(_iicu_wikimyei);
        fprintf(stdout,"[launching:staticques_thread] %d for FIRST_ORDER_AUTOREGRESSION\n",th_idx);
        if(th_idx!=-0x01){
            get_sq_thread_order(_iicu_wikimyei,th_idx)->__sq_type=FIRST_ORDER_AUTOREGRESSION;
            get_sq_thread_order(_iicu_wikimyei,th_idx)->__scene_id=c_scene_id;
            rc=pthread_create(&get_sq_thread_order(_iicu_wikimyei,th_idx)->__sq_threads_launcher
                ,NULL,staticques_launcher,(void*)get_sq_thread_order(_iicu_wikimyei,th_idx));
            if(rc){
                fprintf(stderr,"ERROR; return code from pthread_create(sq_threads_launcher) is %d\n",rc);
                exit(-1);
            }
        } else {
            fprintf(stderr,"%s[ERROR:] unable to launch staticques_thread FIRST_ORDER_AUTOREGRESSION%s\n",COLOR_DANGER,COLOR_REGULAR);
        }
        #endif
        // --- --- --- 
    }
    // --- --- --- 
    // --- --- --- 
    // SDL_Delay(100000);
    // pthread_exit(NULL);
}

void itsaave_loop(__iicu_wikimyei_t *_iicu_wikimyei){ // #FIXME is only doing current mewaajacune
    // --- --- --- TRYING TO SET THE JK ORDER TO FIX        ^
    fprintf(stdout,"[ %s cuwacunu %s:] %s itsaave_loop (empty)%s--- --- ---\n",COLOR_CUWACUNU,COLOR_REGULAR,COLOR_WARNING,COLOR_REGULAR);
    // --- --- --- --- 
    int rc;
    int th_idx;
    // --- --- --- --- 
    beseech_jkimyei(_iicu_wikimyei,gcsid(_iicu_wikimyei));
    ___cwcn_bool_t jk_ready=giicjk(_iicu_wikimyei)->__jk_policy_has_computed;
    ___cwcn_bool_t it_request = was_there_a_itsaave_request(_iicu_wikimyei)==0x01;
    release_jkimyei(_iicu_wikimyei,gcsid(_iicu_wikimyei));
    if(jk_ready && it_request){
        // --- --- --- 
        // --- --- --- 
        th_idx=get_next_aviable_itsaave_thread(_iicu_wikimyei);
        // --- --- --- 
        if(th_idx!=-0x01){
            // --- --- 
            desactive_itsaave_request(_iicu_wikimyei);
            // --- --- 
            fprintf(stdout,"[%slaunching:itsaave_thread%s] %d \n",COLOR_GOOD,COLOR_REGULAR,th_idx);
            // --- --- 
            get_it_thread_order(
                _iicu_wikimyei,th_idx)->__scene_id=gcsid(_iicu_wikimyei);
            get_it_thread_order(
                _iicu_wikimyei,th_idx)->__it_id=th_idx;
            get_it_thread_order(
                _iicu_wikimyei,th_idx)->__it_type=IT_FAKE;
            get_it_thread_order(
                _iicu_wikimyei,th_idx)->__ref_iicu_wikimyei=_iicu_wikimyei;
            get_it_thread_order(
                _iicu_wikimyei,th_idx)->__it_policy_is_bussy=0x00;
            // --- --- 
            rc=pthread_create(&get_it_thread_order(_iicu_wikimyei,th_idx)->__it_threads_launcher
                ,NULL,itsaave_launcher,(void*)get_it_thread_order(_iicu_wikimyei,th_idx));
            // --- --- 
            if(rc){
                // --- 
                fprintf(stderr,"ERROR; return code from pthread_create(it_threads_launcher) is %d\n",rc);
                exit(-1);
            }
            // --- --- 
        } else {
            // --- --- 
            fprintf(stderr,"[%s ERROR %s:] unable to launch itsaave_thread : no aviable threads\n",COLOR_DANGER,COLOR_REGULAR);
        }
    } else {
        if(!jk_ready){
            fprintf(stderr,"[%s WARNING %s:] unable to launch itsaave_thread : jk policy is not loaded for scene [%d] : (NOT)__jk_policy_has_computed \n",COLOR_DANGER,COLOR_REGULAR,gcsid(_iicu_wikimyei));
        }
        // if(!was_there_a_itsaave_request(_iicu_wikimyei)==0x01){ // is ok not tu warn since this is the bottom activate
        //     fprintf(stderr,"[%s WARNING %s:] unable to launch itsaave_thread :  for scene [%d] : (NOT)was_there_a_itsaave_request \n",COLOR_DANGER,COLOR_REGULAR,gcsid(_iicu_wikimyei));
        // }
    }
    // --- --- --- --- 
    // SDL_Delay(100000);
    // pthread_exit(NULL);
}
