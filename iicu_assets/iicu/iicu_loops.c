#include "iicu_loops.h"

void iicu_scene_loop(__iicu_wikimyei_t *_iicu_wikimyei){
    // fprintf(stdout,"[%s cuwacunu %s:] : start : iicu_scene_loop()\n",COLOR_CUWACUNU,COLOR_REGULAR);
get_state(_iicu_wikimyei)->interface_id=IICU_SCREEN_PANEL_STATE_ID;
    // // --- --- --- --- · --- --- --- --- UPDATE 
        update_current_iicu_scene(_iicu_wikimyei);
    step_sdl_object(_iicu_wikimyei->__obj_sdl);
    refresh_current_iicu_scene(_iicu_wikimyei);
        beseech_all(_iicu_wikimyei);
            render_state_panel(_iicu_wikimyei);
            render_scene_panel(_iicu_wikimyei);
        release_all(_iicu_wikimyei);
    draw_sdl_object(_iicu_wikimyei->__obj_sdl);
    // fprintf(stdout,"[%s cuwacunu %s:] : end   : iicu_scene_loop()\n",COLOR_CUWACUNU,COLOR_REGULAR);
}

void iicu_controls_loop(__iicu_wikimyei_t *_iicu_wikimyei){
    // fprintf(stdout,"[%s cuwacunu %s:] : start : iicu_controls_loop()\n",COLOR_CUWACUNU,COLOR_REGULAR);
    // // --- --- --- --- · --- --- --- --- UPDATE 
    #ifndef __cwcn_CLOCK_THREAD__
    miss_or_catch_sdl_event(_iicu_wikimyei);
    #else
    wait_for_sdl_event(_iicu_wikimyei); //handle_sdl_event(_iicu_wikimyei);
    #endif
    // fprintf(stdout,"[%s cuwacunu %s:] : end   : iicu_controls_loop()\n",COLOR_CUWACUNU,COLOR_REGULAR);
}

void iicu_debug_loop(__iicu_wikimyei_t *_iicu_wikimyei){ 
    // fprintf(stdout,"[%s cuwacunu %s:] : start : iicu_debug_loop()\n",COLOR_CUWACUNU,COLOR_REGULAR);
get_state(_iicu_wikimyei)->interface_id=IICU_SCREEN_PANEL_DEBUG_ID;
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
    // fprintf(stdout,"[%s cuwacunu %s:] : end   : iicu_debug_loop()\n",COLOR_CUWACUNU,COLOR_REGULAR);
}

void loading_loop(__iicu_wikimyei_t *_iicu_wikimyei){
    // fprintf(stdout,"[%s cuwacunu %s:] : start : loading_loop()\n",COLOR_CUWACUNU,COLOR_REGULAR);
get_state(_iicu_wikimyei)->interface_id=LOADING_STATE_ID;
    step_sdl_object(_iicu_wikimyei->__obj_sdl);
        render_loading(_iicu_wikimyei);
    draw_sdl_object(_iicu_wikimyei->__obj_sdl);
        // update_iicu_state(_iicu_wikimyei);
        SDL_Delay(2500); // #FIXME innesessary
    // fprintf(stdout,"[%s cuwacunu %s:] : end   : loading_loop()\n",COLOR_CUWACUNU,COLOR_REGULAR);
}

void home_loop(__iicu_wikimyei_t *_iicu_wikimyei){
    // fprintf(stdout,"[%s cuwacunu %s:] : start : home_loop()\n",COLOR_CUWACUNU,COLOR_REGULAR);
get_state(_iicu_wikimyei)->interface_id=HOME_STATE_ID;
    step_sdl_object(_iicu_wikimyei->__obj_sdl);
        // beseech_current_all(_iicu_wikimyei);
        // render_state_panel(_iicu_wikimyei);
        // release_current_all(_iicu_wikimyei);
        render_home(_iicu_wikimyei->__obj_sdl);
    draw_sdl_object(_iicu_wikimyei->__obj_sdl);
        // handle_sdl_event(_iicu_wikimyei);
        wait_for_sdl_event(_iicu_wikimyei);
    // fprintf(stdout,"[%s cuwacunu %s:] : end   : home_loop()\n",COLOR_CUWACUNU,COLOR_REGULAR);
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
    fprintf(stdout,"[%s cuwacunu %s:] %s jkimyei_loop%s--- --- ---\n",COLOR_CUWACUNU,COLOR_REGULAR,COLOR_WARNING,COLOR_REGULAR);
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
            fprintf(stdout,"[%s launching:jkimyei_thread %s] [scene:[%d], kline:[%d], thead id: [%d] for JK_MONTECARLO\n",COLOR_GOOD,COLOR_REGULAR,scene_idx,c_kline_id,th_idx);
            get_jk_thread_order(_iicu_wikimyei,th_idx)->__jk_thead_is_bussy=0x01;
            rc=pthread_create(&get_jk_thread_order(_iicu_wikimyei,th_idx)->__jk_threads_launcher
                ,NULL,jkimyei_launcher,(void*)get_jk_thread_order(_iicu_wikimyei,th_idx));
            if(rc){fprintf(stderr,"[%s ERROR: %s] return code from pthread_create(jk_threads_launcher) is %d\n",COLOR_DANGER,COLOR_REGULAR,rc);exit(-1);}
        } else {fprintf(stderr,"[%s ERROR: %s] unable to launch jkimyei_thread JK_MONTECARLO : unable to alocate required thread : %d\n",COLOR_DANGER,COLOR_REGULAR,scene_idx);}
    } 
    #endif
    // --- --- --- 
    // SDL_Delay(100000);
    // pthread_exit(NULL);
}

void regressive_loop(__iicu_wikimyei_t *_iicu_wikimyei){ // #FIXME is only doing current mewaajacune
    // --- --- --- TRYING TO SET THE JK ORDER TO FIX        ^
    fprintf(stdout,"[%s cuwacunu %s:] %s regressive_loop%s--- --- ---\n",COLOR_CUWACUNU,COLOR_REGULAR,COLOR_WARNING,COLOR_REGULAR);
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
    fprintf(stdout,"[%s cuwacunu %s:] %s polinomial_loop (#FIXME empty)%s--- --- ---\n",COLOR_CUWACUNU,COLOR_REGULAR,COLOR_WARNING,COLOR_REGULAR);
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
    fprintf(stdout,"[%s cuwacunu %s:] %s staticques_loop (empty)%s--- --- ---\n",COLOR_CUWACUNU,COLOR_REGULAR,COLOR_WARNING,COLOR_REGULAR);
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
        SDL_Delay(150); // #NEEDED
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
    // --- --- --- --- TRYING TO SET THE JK ORDER TO FIX        ^
    fprintf(stdout,"[%s cuwacunu %s:] %s itsaave_loop (empty)%s--- --- ---\n",COLOR_CUWACUNU,COLOR_REGULAR,COLOR_WARNING,COLOR_REGULAR);
    // --- --- --- --- 
    int rc;
    int th_idx;
    int c_scene_id=0x00;
    // --- --- --- --- 
    ___cwcn_bool_t it_request=0x00;
    ___cwcn_bool_t jk_ready=0x00;
    ___cwcn_bool_t p_ready=0x00;
    ___cwcn_bool_t staticques_ready=0x00;
    // --- --- --- --- 
    ___cwcn_bool_t it_open=0x00;
    ___cwcn_bool_t it_load_open=0x00;
    ___cwcn_bool_t it_nothing=0x00;
    ___cwcn_bool_t it_profit=0x00;
    // --- --- --- --- 
    ___cwcn_bool_t launch_from_trigger=0x00;
    ___cwcn_bool_t cancel_trigger=0x00;
    ___cwcn_bool_t launch_from_loaded=0x00;

    // --- --- --- --- CHECK FOR LOADSTATE
    // --- --- --- --- --- --- 
    for(int c_s_id=0x00;c_s_id<MAX_IICU_SCENES;c_s_id++){
        c_scene_id=c_s_id;
        beseech_scene_itsaave(_iicu_wikimyei,c_scene_id);
        it_load_open = get_scene_itsaave(_iicu_wikimyei,c_scene_id)->__it_state==IT_LOADED_OPEN;
        release_scene_itsaave(_iicu_wikimyei,c_scene_id);
        if(it_load_open){break;}
    }
    launch_from_loaded = it_load_open;
    // --- --- --- --- CHECK FOR LAUNCH BY TRIGGER REQUEST
    // --- --- --- --- --- --- 
    if(!launch_from_loaded){
        // --- --- --- 
        c_scene_id = get_state(_iicu_wikimyei)->__req_scene_itsaave;
        it_request = was_there_a_itsaave_request(_iicu_wikimyei)==0x01;
        // --- --- --- 
        if(it_request){
            beseech_jkimyei(_iicu_wikimyei,c_scene_id);
            jk_ready = get_jkimyei(_iicu_wikimyei,c_scene_id)->__jk_policy_has_computed;
            p_ready = policy_is_ready(get_jkimyei(_iicu_wikimyei, c_scene_id)->__jk_inteligent_order_policy);
            release_jkimyei(_iicu_wikimyei,c_scene_id);
            // --- --- 
            if(jk_ready && p_ready){
                // --- 
                beseech_scene_itsaave(_iicu_wikimyei,c_scene_id);
                // --- 
                it_open = get_scene_itsaave(_iicu_wikimyei,c_scene_id)->__it_state==IT_OPEN;
                it_nothing = get_scene_itsaave(_iicu_wikimyei,c_scene_id)->__it_state==IT_NOTHING;
                it_profit = get_scene_itsaave(_iicu_wikimyei,c_scene_id)->__it_state==IT_FINISHED_PROFIT;
                it_profit = it_profit || get_scene_itsaave(_iicu_wikimyei,c_scene_id)->__it_state==IT_FINISHED_LOSS;
                // --- 
                launch_from_trigger = (jk_ready && p_ready && it_request && (it_nothing || it_profit || it_profit));
                cancel_trigger = (it_request && it_open);
                // --- 
                release_scene_itsaave(_iicu_wikimyei,c_scene_id);
                // --- 
            } else if (launch_from_trigger) {
                // --- WARN IF POLICY NOT LOADED
                if(!jk_ready){
                    fprintf(stderr,"[%s WARNING %s:] unable to launch itsaave_thread : [jkimyei  ] is not ready for scene [%d] \n",COLOR_WARNING,COLOR_REGULAR,gcsid(_iicu_wikimyei));
                }
                if(!p_ready){
                    fprintf(stderr,"[%s WARNING %s:] unable to launch itsaave_thread : [jk_policy] is not ready for scene [%d] \n",COLOR_WARNING,COLOR_REGULAR,gcsid(_iicu_wikimyei));
                }
                // --- 
            }
            // --- --- 
        }
        // --- --- --- 
    }
    // --- --- --- --- CANCEL TRIGGER (thre can be only one open itsaave per scene)
    if(cancel_trigger){
        desactive_itsaave_request(_iicu_wikimyei);
        launch_from_trigger=0x00;
    }
    // --- --- --- --- LAUNCH FROM TRIGGER (if jk is ready and user has commanded itsaave trigger)
    if(launch_from_trigger){
        fprintf(stdout,"[%s cuwacunu %s: itsaave ] itsaave triggerd for scene [%d]\n",COLOR_CUWACUNU,COLOR_REGULAR, c_scene_id);
    }
    // --- --- --- --- LAUNCH FROM LOADED (using save_n_load states has been loaded as open for itsaave)
    if(launch_from_loaded){
        fprintf(stdout,"[%s cuwacunu %s: itsaave ] itsaave loaded   for scene [%d]\n",COLOR_CUWACUNU,COLOR_REGULAR, c_scene_id);
    }
    // --- --- --- --- --- --- 
    // --- --- --- --- CHECK FOR STATICQUES READY
    beseech_staticques(_iicu_wikimyei, c_scene_id);
    staticques_ready = staticques_is_ready(get_staticques(_iicu_wikimyei, c_scene_id));
    release_staticques(_iicu_wikimyei, c_scene_id);
    // --- --- --- --- LAUNCH
    if(staticques_ready && (launch_from_trigger || launch_from_loaded)){
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
                _iicu_wikimyei,th_idx)->__scene_id=c_scene_id;
            get_it_thread_order(
                _iicu_wikimyei,th_idx)->__it_id=th_idx;
            get_it_thread_order(
                _iicu_wikimyei,th_idx)->__it_type=IT_FAKE;
            get_it_thread_order(
                _iicu_wikimyei,th_idx)->__ref_iicu_wikimyei=_iicu_wikimyei;
            get_it_thread_order(
                _iicu_wikimyei,th_idx)->__it_policy_is_bussy=0x00;
            // --- --- 
            beseech_scene_itsaave(_iicu_wikimyei,c_scene_id);
            get_it_thread_order(
                _iicu_wikimyei,th_idx)->__ref_iicu_itsaave=get_scene_itsaave(_iicu_wikimyei,c_scene_id);
            release_scene_itsaave(_iicu_wikimyei,c_scene_id);
            // --- --- 
            rc=pthread_create(&get_it_thread_order(_iicu_wikimyei,th_idx)->__it_threads_launcher
                ,NULL,itsaave_launcher,(void*)get_it_thread_order(_iicu_wikimyei,th_idx));
            // --- --- 
            if(rc){
                // --- 
                fprintf(stderr,"ERROR; return code from pthread_create(it_threads_launcher) is %d\n",rc);
                // --- 
                exit(-1);
                // --- 
            }
            // --- --- NEEDED DELAY, method is too fast so loads twice
            if(it_load_open){
                SDL_Delay(1000);
            }
            // --- --- 
        } else {
            // --- --- 
            fprintf(stderr,"[%s ERROR %s:] unable to launch itsaave_thread : no aviable threads\n",COLOR_DANGER,COLOR_REGULAR);
            // --- --- 
        }
        // --- --- --- 
    }
    // --- --- --- --- 
}

void save_n_load_loop(__iicu_wikimyei_t *_iicu_wikimyei){
    fprintf(stdout,"[%s cuwacunu %s:] %s save_n_load_loop (empty)%s--- --- ---\n",COLOR_CUWACUNU,COLOR_REGULAR,COLOR_WARNING,COLOR_REGULAR);
    save_itsaave_from_state_backup(_iicu_wikimyei);
    // SDL_Delay(1000);
    // load_itsaave_from_state_backup(_iicu_wikimyei);    
}