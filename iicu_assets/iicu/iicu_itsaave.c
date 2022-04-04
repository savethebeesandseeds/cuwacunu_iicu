#include "iicu_itsaave.h"
#include "../iicu/iicu_wikimyei.h"
__iicu_itsaave_t *itsaave_fabric(__inteligent_order_policy_t *_policy){
    assert(ALLIU_SIZE==0x01); // alliu asigments are not vectorized
    __iicu_itsaave_t *new_iicu_itsaave=malloc(sizeof(__iicu_itsaave_t));
    assert(new_iicu_itsaave!=NULL);
    new_iicu_itsaave->__it_pocket=fabric_pocket(); // load ? (not) (start state is commission as is initialized elsewhere)
    new_iicu_itsaave->__it_state=IT_NOTHING;
    new_iicu_itsaave->__it_alliu_start=0x00; // malloc(sizeof(__cwcn_type_t));
    new_iicu_itsaave->__it_alliu_end=0x00; // malloc(sizeof(__cwcn_type_t));
    new_iicu_itsaave->__it_alliu_quantity=0x00; // malloc(sizeof(__cwcn_type_t));
    if(_policy!=NULL){
        new_iicu_itsaave->__it_policy=policy_clone_fabric(_policy);
    } else {
        new_iicu_itsaave->__it_policy=NULL;
    }
    return new_iicu_itsaave;
}
void destroy_itsaave(__iicu_itsaave_t *_iicu_itsaave){
    destroy_pocket(_iicu_itsaave->__it_pocket);
    // free(_iicu_itsaave->__it_alliu_start);
    // free(_iicu_itsaave->__it_alliu_end);
    // free(_iicu_itsaave->__it_alliu_quantity);
    if(_iicu_itsaave->__it_policy!=NULL){free(_iicu_itsaave->__it_policy);}
    free(_iicu_itsaave);
}
__iicu_pocket_t *fabric_pocket(){
    __iicu_pocket_t *new_pocket=malloc(sizeof(__iicu_pocket_t));
    assert(new_pocket!=NULL);
    new_pocket->__holding_value=0x00; // must start at zero
    fprintf(stdout,"new_pocket [%p] ->__holding_value : %f \n",new_pocket,new_pocket->__holding_value);
    return new_pocket;
}
void destroy_pocket(__iicu_pocket_t *_iicu_pocket){
    free(_iicu_pocket);
}
void load_pocket_to_pocket(__iicu_pocket_t *dest_pocket, __iicu_pocket_t *src_pocket){
    dest_pocket->__holding_value+=src_pocket->__holding_value;
}

void active_itsaave_request(void *_iicu_wikimyei){
    get_state(_iicu_wikimyei)->__req_itsaave=0x01;
}
void desactive_itsaave_request(void *_iicu_wikimyei){
    get_state(_iicu_wikimyei)->__req_itsaave=0x00;
}
___cwcn_bool_t was_there_a_itsaave_request(void *_iicu_wikimyei){
    return get_state(_iicu_wikimyei)->__req_itsaave;
}

void fake_itsaave_method(void *_it_thread_order, int _scene_id, int _kline_id){
    // fake meaning no real money is in play
    int c_itsaave_eps=0x00;
    // --- --- --- --- --- --- 
    __iicu_wikimyei_t *c_iicu_wikimyei=((__itsaave_thread_order_t *)_it_thread_order)->__ref_iicu_wikimyei;
    // --- --- --- --- --- --- 
    beseech_jkimyei(c_iicu_wikimyei, _scene_id);
    beseech_staticques(c_iicu_wikimyei, _scene_id);
    // --- --- --- --- --- --- 
    __inteligent_order_policy_t *c_policy=policy_clone_fabric(get_jkimyei(c_iicu_wikimyei, _scene_id)->__jk_inteligent_order_policy);
    // --- --- --- --- --- --- 
    __iicu_itsaave_t *c_iicu_itsaave=itsaave_fabric(c_policy);
    // --- --- --- --- --- --- 
    __cwcn_type_t c_latest_alliu=gentil_get_alliu_latest(c_iicu_wikimyei, _scene_id);
    // --- --- --- --- --- --- 
    ((__itsaave_thread_order_t *)_it_thread_order)->__ref_iicu_itsaave=c_iicu_itsaave; // #FIXME seems weird
    // --- --- --- --- --- --- 
    // __iicu_staticques_t *get_staticques(c_iicu_wikimyei, _scene_id)=get_staticques(c_iicu_wikimyei, _scene_id);
    // --- --- --- --- --- --- 
    c_iicu_itsaave->__it_state=IT_OPEN;
    c_iicu_itsaave->__it_alliu_start=c_latest_alliu;
    c_iicu_itsaave->__it_alliu_quantity=c_policy->__base_margin_investment/c_iicu_itsaave->__it_alliu_start;
    c_iicu_itsaave->__it_alliu_uperbreak=(0x01+c_policy->__order_margin_uper)*c_iicu_itsaave->__it_alliu_start;
    c_iicu_itsaave->__it_alliu_downbreak=(0x01-c_policy->__order_margin_down)*c_iicu_itsaave->__it_alliu_start;
    c_iicu_itsaave->__it_pocket->__holding_value+=\
        (-0x01)*BROKER_MARKET_COMMISSION_MAKER*c_iicu_itsaave->__it_alliu_quantity*c_iicu_itsaave->__it_alliu_start;
    // --- --- --- --- --- --- 
    release_staticques(c_iicu_wikimyei, _scene_id);
    release_jkimyei(c_iicu_wikimyei, _scene_id);
    // --- --- --- --- --- --- 
    ((__itsaave_thread_order_t *)_it_thread_order)->__it_policy_is_bussy=0x01;
    // --- --- --- --- --- --- 
    while(0x01){
        // --- --- --- --- --- 
        beseech_staticques(c_iicu_wikimyei, _scene_id); 
        // --- --- --- --- --- 
        if(c_latest_alliu>=c_iicu_itsaave->__it_alliu_uperbreak){
            fprintf(stderr,"[%s cuwacunu %s:itsaave]:scene_id:[%d:%s]. %s IT_FINISHED_PROFIT %s\n",COLOR_CUWACUNU,COLOR_REGULAR,_scene_id,IICU_SCENES_SYMBOLS[_scene_id],COLOR_GOOD,COLOR_REGULAR);
            c_iicu_itsaave->__it_state=IT_FINISHED_PROFIT; // break on profit
        } else if(c_latest_alliu<=c_iicu_itsaave->__it_alliu_downbreak){
            fprintf(stderr,"[%s cuwacunu %s:itsaave]:scene_id:[%d:%s]. %s IT_FINISHED_LOSS %s\n",COLOR_CUWACUNU,COLOR_REGULAR,_scene_id,IICU_SCENES_SYMBOLS[_scene_id],COLOR_GOOD,COLOR_REGULAR);
            c_iicu_itsaave->__it_state=IT_FINISHED_LOSS; // break on loss
        }
        // --- --- --- --- --- 
        release_staticques(c_iicu_wikimyei, _scene_id);
        // --- --- --- --- --- 
        if(c_iicu_itsaave->__it_state!=IT_OPEN){
            beseech_staticques(c_iicu_wikimyei, _scene_id); 
            c_iicu_itsaave->__it_alliu_end=c_latest_alliu;
            c_iicu_itsaave->__it_pocket->__holding_value+=\
                (c_iicu_itsaave->__it_alliu_end-c_iicu_itsaave->__it_alliu_start)*c_iicu_itsaave->__it_alliu_quantity;
            c_iicu_itsaave->__it_pocket->__holding_value+=\
                (-0x01)*BROKER_MARKET_COMMISSION_TAKER*c_iicu_itsaave->__it_alliu_quantity*c_iicu_itsaave->__it_alliu_end;
            release_staticques(c_iicu_wikimyei, _scene_id);
            break;
        }
        // --- --- --- --- --- 
        c_itsaave_eps++;
        SDL_Delay(1/ITSAAVE_FRECUENCY);
        if(c_itsaave_eps>ITSAAVE_MAX_PERIODS){
            fprintf(stderr,"%s [ERROR] fake_itsaave_method scene_id:[%d] exceed maxima timeout...%s\n",COLOR_DANGER,_scene_id,COLOR_REGULAR);
            fprintf(stderr,"%s [fake_itsaave_method] scene_id:[%d] forcing release...%s\n",COLOR_DANGER,_scene_id,COLOR_REGULAR);
            break;
        }
        // --- --- --- --- --- 
    } // wait itsaave to release
    // --- --- --- --- --- --- 
    if(c_iicu_itsaave->__it_state!=IT_FINISHED_PROFIT && c_iicu_itsaave->__it_state!=IT_FINISHED_LOSS){
        fprintf(stderr,"[%s WARNING! %s] itsaave closed unfinished.\n",COLOR_DANGER,COLOR_REGULAR);
        fprintf(stderr,"[%s WARNING! %s] wikimyei continues on mayor warning.\n",COLOR_DANGER,COLOR_REGULAR);
    }
    beseech_wk_itsaave(c_iicu_wikimyei);
    beseech_scene_itsaave(c_iicu_wikimyei,_scene_id);
    // --- --- --- --- --- --- 
    load_pocket_to_pocket(\
        get_wk_itsaave(c_iicu_wikimyei)->__it_pocket, c_iicu_itsaave->__it_pocket); // load pocket_results to wikimyei
    load_pocket_to_pocket(\
        get_scene_itsaave(c_iicu_wikimyei,_scene_id)->__it_pocket, c_iicu_itsaave->__it_pocket); // load pocket_results to scene (the sum of all scenes sumes the wk in the context of pockets)
    // --- --- --- --- --- --- 
    release_scene_itsaave(c_iicu_wikimyei,_scene_id);
    release_wk_itsaave(c_iicu_wikimyei);
    // --- --- --- --- --- --- 
    destroy_policy(c_policy);
    destroy_itsaave(c_iicu_itsaave);

    // --- --- --- --- --- --- 
    #ifdef __FOREVER_RUNNING_ITSAAVE__
    fake_itsaave_method(_it_thread_order, _scene_id, _kline_id);
    #endif
}
void *itsaave_launcher(void *_it_thread_order){
    // --- --- --- --- --- --- 
    ((__itsaave_thread_order_t *)_it_thread_order)->__it_thead_is_bussy=0x01;
    // --- --- --- --- --- --- This efectivly forces all itsaave threads to run on the same core
    #ifdef __ITSAAVE_THREAD_FORCE_CORE
    cpu_set_t cpuset;
    int cpu = __ITSAAVE_THREAD_FORCE_CORE;
    CPU_ZERO(&cpuset);
    CPU_SET(cpu,&cpuset);
    #endif
    // --- --- --- --- --- --- 
    int c_scene_id=((__itsaave_thread_order_t *)_it_thread_order)->__scene_id;
    int c_kline_id=0x00; // can be any, so long as staticques keeps the last value updated for every kline // #FIXME 
    // --- --- --- --- --- --- 
    fprintf(stderr,"[%s cuwacunu %s:itsaave]:scene_id:[%d]. %sSTART%s\n",COLOR_CUWACUNU,COLOR_REGULAR,c_scene_id,COLOR_GOOD,COLOR_REGULAR);
    // --- --- --- --- --- --- 
    beseech_jkimyei(((__itsaave_thread_order_t *)_it_thread_order)->__ref_iicu_wikimyei,gcsid(((__itsaave_thread_order_t *)_it_thread_order)->__ref_iicu_wikimyei));
    ___cwcn_bool_t p_ready=policy_is_ready(get_jkimyei(((__itsaave_thread_order_t *)_it_thread_order)->__ref_iicu_wikimyei, c_scene_id)->__jk_inteligent_order_policy);
    release_jkimyei(((__itsaave_thread_order_t *)_it_thread_order)->__ref_iicu_wikimyei,gcsid(((__itsaave_thread_order_t *)_it_thread_order)->__ref_iicu_wikimyei));
    // --- --- --- --- --- --- 
    if(p_ready){
        switch(((__itsaave_thread_order_t*)_it_thread_order)->__it_type){
        case IT_FAKE:
            fake_itsaave_method(_it_thread_order, c_scene_id, c_kline_id);
            break;
        default:
            fprintf(stderr,"[%s cuwacunu %s:itsaave]%sERROR, not understood itsaave type, scene_id:[%d]. Configured in itsaave thread order%s\n",COLOR_CUWACUNU,COLOR_REGULAR,COLOR_DANGER, c_scene_id,COLOR_REGULAR);
            break;
        }
    } else {
        fprintf(stderr,"[%s cuwacunu %s:itsaave]: %s WARNING %s : scene_id:[%d] : policy_is_(NOT)_ready \n",COLOR_CUWACUNU,COLOR_REGULAR,COLOR_DANGER,COLOR_REGULAR,c_scene_id);
    }
    // --- --- --- --- --- --- 
    fprintf(stderr,"[%s cuwacunu %s:itsaave]:scene_id:[%d]. %sFINISH%s\n",COLOR_CUWACUNU,COLOR_REGULAR,c_scene_id,COLOR_GOOD,COLOR_REGULAR);
    ((__itsaave_thread_order_t *)_it_thread_order)->__it_thead_is_bussy=0x00;
    pthread_exit(NULL);
    // --- --- --- --- --- --- 
}
