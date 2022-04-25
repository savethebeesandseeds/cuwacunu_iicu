#include "iicu_itsaave.h"
#include "../iicu/iicu_wikimyei.h"
void print_itsaave(__iicu_itsaave_t *_iicu_itsaave){
    fprintf(stdout,"\t printing iicu_itsaave: %p\n",_iicu_itsaave);
    fprintf(stdout,"\t __it_pocket: %p\n",_iicu_itsaave->__it_pocket);
    fprintf(stdout,"\t __it_state: %d\n",_iicu_itsaave->__it_state);
    fprintf(stdout,"\t __it_alliu_start: %f\n",_iicu_itsaave->__it_alliu_start);
    fprintf(stdout,"\t __it_alliu_end: %f\n",_iicu_itsaave->__it_alliu_end);
    fprintf(stdout,"\t __it_alliu_quantity: %f\n",_iicu_itsaave->__it_alliu_quantity);
    fprintf(stdout,"\t __it_alliu_uperbreak: %f\n",_iicu_itsaave->__it_alliu_uperbreak);
    fprintf(stdout,"\t __it_alliu_downbreak: %f\n",_iicu_itsaave->__it_alliu_downbreak);
    fprintf(stdout,"\t __it_policy: %p\n",_iicu_itsaave->__it_policy);
    if(_iicu_itsaave->__it_policy!=NULL){
        plot_policy(_iicu_itsaave->__it_policy);
    }
}
__iicu_itsaave_t *itsaave_fabric(__intelligent_order_policy_t *_policy){
    assert(ALLIU_SIZE==0x01); // alliu asigments are not vectorized
    __iicu_itsaave_t *new_iicu_itsaave=malloc(sizeof(__iicu_itsaave_t));
    assert(new_iicu_itsaave!=NULL);
    new_iicu_itsaave->__it_pocket=pocket_fabric(); // load ? (not) (start state is commission as is initialized elsewhere)
    new_iicu_itsaave->__it_state=IT_NOTHING;
    new_iicu_itsaave->__it_alliu_start=0x00; // malloc(sizeof(__cwcn_type_t));
    new_iicu_itsaave->__it_alliu_end=0x00; // malloc(sizeof(__cwcn_type_t));
    new_iicu_itsaave->__it_alliu_quantity=0x00; // malloc(sizeof(__cwcn_type_t));
    new_iicu_itsaave->__it_alliu_uperbreak=+__cwcn_infinite;
    new_iicu_itsaave->__it_alliu_downbreak=-__cwcn_infinite;
    if(_policy!=NULL){
        new_iicu_itsaave->__it_policy=policy_clone_fabric(_policy);
    } else {
        new_iicu_itsaave->__it_policy=NULL;
    }
    return new_iicu_itsaave;
}
__iicu_itsaave_t *itsaave_clone_fabric(__iicu_itsaave_t *src_iicu_itsaave){
    __iicu_itsaave_t *new_iicu_itsaave=malloc(sizeof(__iicu_itsaave_t));
    new_iicu_itsaave->__it_pocket=pocket_clone_fabric(src_iicu_itsaave->__it_pocket); // load ? (not) (start state is commission as is initialized elsewhere)
    new_iicu_itsaave->__it_state=src_iicu_itsaave->__it_state;
    new_iicu_itsaave->__it_alliu_start=src_iicu_itsaave->__it_alliu_start;
    new_iicu_itsaave->__it_alliu_end=src_iicu_itsaave->__it_alliu_end;
    new_iicu_itsaave->__it_alliu_quantity=src_iicu_itsaave->__it_alliu_quantity;
    new_iicu_itsaave->__it_alliu_uperbreak=src_iicu_itsaave->__it_alliu_uperbreak;
    new_iicu_itsaave->__it_alliu_downbreak=src_iicu_itsaave->__it_alliu_downbreak;
    if(src_iicu_itsaave->__it_policy!=NULL){
        new_iicu_itsaave->__it_policy=policy_clone_fabric(src_iicu_itsaave->__it_policy);
    } else {
        new_iicu_itsaave->__it_policy=NULL;
    }
    return new_iicu_itsaave;
}
void itsaave_to_stream(__iicu_itsaave_t *_iicu_itsaave, FILE *_dump_stream){
    if(_iicu_itsaave!=NULL){
        // --- --- 
        __iicu_itsaave_t *dump_iicu_itsaave=itsaave_clone_fabric(_iicu_itsaave);
        dump_iicu_itsaave->__it_pocket=NULL;
        dump_iicu_itsaave->__it_policy=NULL;
        // --- --- 
        fwrite(dump_iicu_itsaave,sizeof(__iicu_itsaave_t),1,_dump_stream);
        // --- --- 
        destroy_itsaave(dump_iicu_itsaave);
    }
}
void itsaave_load_from_stream(__iicu_itsaave_t *_iicu_itsaave, FILE *_dump_stream){
    __iicu_pocket_t *temp_it_pocket=_iicu_itsaave->__it_pocket;
    __intelligent_order_policy_t *temp_it_policy=_iicu_itsaave->__it_policy;
    fread(_iicu_itsaave,sizeof(__iicu_itsaave_t),1,_dump_stream);
    _iicu_itsaave->__it_pocket=temp_it_pocket;
    _iicu_itsaave->__it_policy=temp_it_policy;
    if(_iicu_itsaave->__it_state==IT_OPEN){
        _iicu_itsaave->__it_state=IT_LOADED_OPEN;
    }
}
void destroy_itsaave(__iicu_itsaave_t *_iicu_itsaave){
    destroy_pocket(_iicu_itsaave->__it_pocket);
    // free(_iicu_itsaave->__it_alliu_start);
    // free(_iicu_itsaave->__it_alliu_end);
    // free(_iicu_itsaave->__it_alliu_quantity);
    if(_iicu_itsaave->__it_policy!=NULL){free(_iicu_itsaave->__it_policy);}
    free(_iicu_itsaave);
}
__iicu_pocket_t *pocket_fabric(){
    __iicu_pocket_t *new_pocket=malloc(sizeof(__iicu_pocket_t));
    assert(new_pocket!=NULL);
    new_pocket->__holding_value=0x00; // must start at zero
    // fprintf(stdout,"new_pocket [%p] ->__holding_value : %f \n",new_pocket,new_pocket->__holding_value);
    return new_pocket;
}
__iicu_pocket_t *pocket_clone_fabric(__iicu_pocket_t *src_iicu_pocket){
    __iicu_pocket_t *new_pocket=malloc(sizeof(__iicu_pocket_t));
    assert(new_pocket!=NULL);
    new_pocket->__holding_value=src_iicu_pocket->__holding_value;
    // fprintf(stdout,"new_pocket [%p] ->__holding_value : %f \n",new_pocket,new_pocket->__holding_value);
    return new_pocket;
}
void pocket_load_from_stream(__iicu_pocket_t *_iicu_pocket, FILE *_dump_stream){
    fread(_iicu_pocket,sizeof(_iicu_pocket),1,_dump_stream);
}
void pocket_to_stream(__iicu_pocket_t *_iicu_pocket, FILE *_dump_stream){
    if(_iicu_pocket!=NULL){
        // --- --- 
        __iicu_pocket_t *dump_iicu_pocket=pocket_clone_fabric(_iicu_pocket);
        // --- --- 
        fwrite(dump_iicu_pocket,sizeof(*dump_iicu_pocket),1,_dump_stream);
        // --- --- 
        destroy_pocket(dump_iicu_pocket);
        // --- --- 
    }
}
void destroy_pocket(__iicu_pocket_t *_iicu_pocket){
    free(_iicu_pocket);
}
void load_pocket_to_pocket(__iicu_pocket_t *dest_pocket, __iicu_pocket_t *src_pocket){
    dest_pocket->__holding_value+=src_pocket->__holding_value;
}

void active_itsaave_request(void *_iicu_wikimyei){
    get_state(_iicu_wikimyei)->__req_itsaave=0x01;
    get_state(_iicu_wikimyei)->__req_scene_itsaave=gcsid(_iicu_wikimyei);
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
    __cwcn_type_t margin=0x00;
    __cwcn_type_t gains=0x00;
    __cwcn_type_t in_commission=0x00;
    __cwcn_type_t out_commission=0x00;
    // --- --- --- --- --- --- 
    __iicu_wikimyei_t *c_iicu_wikimyei=((__itsaave_thread_order_t *)_it_thread_order)->__ref_iicu_wikimyei;
    // --- --- --- --- --- --- 
    // beseech_staticques(c_iicu_wikimyei, _scene_id);
    beseech_jkimyei(c_iicu_wikimyei, _scene_id);
    beseech_scene_itsaave(c_iicu_wikimyei, _scene_id);
    // --- --- --- --- --- --- 
    // --- --- --- --- --- --- 
    __iicu_itsaave_t *c_scene_itsaave = get_scene_itsaave(c_iicu_wikimyei,_scene_id); // when ever it used remember to beesech
    __iicu_jkimyei_t *c_jkimyei = get_jkimyei(c_iicu_wikimyei, _scene_id); // when ever it used remember to beesech
    __intelligent_order_policy_t *c_policy=c_jkimyei->__jk_inteligent_order_policy; // when ever it used remember to beesech
    // --- --- --- --- --- --- 
    __cwcn_type_t c_latest_alliu = gentil_get_alliu_latest(c_iicu_wikimyei, _scene_id);
    // --- --- --- --- --- --- 
    // --- --- --- --- --- --- 
    if(c_scene_itsaave->__it_state!=IT_LOADED_OPEN){
        // --- --- --- --- --- 
        c_scene_itsaave->__it_alliu_start=c_latest_alliu;
        // --- --- --- --- --- 
        c_scene_itsaave->__it_alliu_quantity=c_policy->__base_margin_investment/c_scene_itsaave->__it_alliu_start;
        c_scene_itsaave->__it_alliu_uperbreak=(0x01+c_policy->__order_margin_uper)*c_scene_itsaave->__it_alliu_start;
        c_scene_itsaave->__it_alliu_downbreak=(0x01-c_policy->__order_margin_down)*c_scene_itsaave->__it_alliu_start;
        // --- --- --- --- --- 
        in_commission = (-0x01)*BROKER_MARKET_TOTAL_COMMISSION*c_scene_itsaave->__it_alliu_quantity*c_scene_itsaave->__it_alliu_start;
        c_scene_itsaave->__it_pocket->__holding_value += in_commission;
        // --- --- --- --- --- 
        // fprintf(stdout,"[%s cuwacunu %s:itsaave:_starting_:triggered ] %s \n: ITSAAVE[%d] :\n",COLOR_CUWACUNU,COLOR_REGULAR,COLOR_GOOD,_scene_id);
        // print_itsaave(c_scene_itsaave);
        // fprintf(stdout,"%s",COLOR_REGULAR);
    } else {
        in_commission = (-0x01)*BROKER_MARKET_TOTAL_COMMISSION*c_scene_itsaave->__it_alliu_quantity*c_scene_itsaave->__it_alliu_start;
        // fprintf(stdout,"[%s cuwacunu %s:itsaave:_starting_:loaded    ] %s \n: ITSAAVE[%d] :\n",COLOR_CUWACUNU,COLOR_REGULAR,COLOR_GOOD,_scene_id);
        // print_itsaave(c_scene_itsaave);
        // fprintf(stdout,"%s",COLOR_REGULAR);
    }
    // --- --- --- --- --- --- 
    c_scene_itsaave->__it_state=IT_OPEN;
    // --- --- --- --- --- --- 
    // --- --- --- --- --- --- 
    release_scene_itsaave(c_iicu_wikimyei, _scene_id);
    release_jkimyei(c_iicu_wikimyei, _scene_id);
    // release_staticques(c_iicu_wikimyei, _scene_id);
    // --- --- --- --- --- --- 
    ((__itsaave_thread_order_t *)_it_thread_order)->__it_policy_is_bussy=0x01;
    // --- --- --- --- --- --- 
    while(0x01){
        // --- --- --- --- --- 
        c_latest_alliu=gentil_get_alliu_latest(c_iicu_wikimyei, _scene_id);
        // --- --- --- --- --- 
        // beseech_staticques(c_iicu_wikimyei, _scene_id);
        beseech_scene_itsaave(c_iicu_wikimyei, _scene_id);
        // --- --- --- --- --- 
        if(c_latest_alliu>=c_scene_itsaave->__it_alliu_uperbreak){
            c_scene_itsaave->__it_state=IT_FINISHED_PROFIT; // break on profit
        } else if(c_latest_alliu<=c_scene_itsaave->__it_alliu_downbreak){
            c_scene_itsaave->__it_state=IT_FINISHED_LOSS; // break on loss
        }
        // --- --- --- --- --- 
        // --- --- --- --- --- 
        if(c_scene_itsaave->__it_state==IT_FINISHED_PROFIT || c_scene_itsaave->__it_state==IT_FINISHED_LOSS){
            // --- --- --- --- 
            // --- --- --- --- 
            c_scene_itsaave->__it_alliu_end=c_latest_alliu;
            // --- --- --- --- 
            out_commission=(-0x01)*BROKER_MARKET_TOTAL_COMMISSION*c_scene_itsaave->__it_alliu_quantity*c_scene_itsaave->__it_alliu_end;
            c_scene_itsaave->__it_pocket->__holding_value += out_commission;
            // --- --- --- --- 
            gains = (c_scene_itsaave->__it_alliu_end-c_scene_itsaave->__it_alliu_start)*c_scene_itsaave->__it_alliu_quantity;
            c_scene_itsaave->__it_pocket->__holding_value += gains;
            // --- --- --- --- 
            release_scene_itsaave(c_iicu_wikimyei, _scene_id);
            // --- --- --- --- 
            // --- --- --- --- 
            beseech_wk_itsaave(c_iicu_wikimyei);
            // --- --- --- --- 
            margin = gains + in_commission + out_commission;
            get_wk_itsaave(c_iicu_wikimyei)->__it_pocket->__holding_value += gains + in_commission + out_commission;
            // --- --- --- --- 
            release_wk_itsaave(c_iicu_wikimyei);        
            // --- --- --- --- 
            break;
        }
        // --- --- --- --- --- 
        release_scene_itsaave(c_iicu_wikimyei, _scene_id);
        // --- --- --- --- --- 
        if(c_scene_itsaave->__it_state==IT_FINISHED_PROFIT){
            fprintf(stderr,"[ cuwacunu:itsaave ]:scene_id:[%d:%s]. %s IT_FINISHED_PROFIT %s : %f \n",_scene_id,IICU_SCENES_SYMBOLS[_scene_id],COLOR_GOOD,COLOR_REGULAR,margin);
        } else if(c_scene_itsaave->__it_state==IT_FINISHED_LOSS){
            fprintf(stderr,"[ cuwacunu:itsaave ]:scene_id:[%d:%s]. %s IT_FINISHED_LOSS %s : %f \n",_scene_id,IICU_SCENES_SYMBOLS[_scene_id],COLOR_DANGER,COLOR_REGULAR,margin);
        }
        // --- --- --- --- --- 
        c_itsaave_eps++;
        SDL_Delay(1000/ITSAAVE_FRECUENCY);
        if(c_itsaave_eps>ITSAAVE_MAX_PERIODS){
            fprintf(stderr,"%s [ERROR] fake_itsaave_method scene_id:[%d] exceed maxima timeout...%s\n",COLOR_DANGER,_scene_id,COLOR_REGULAR);
            fprintf(stderr,"%s [fake_itsaave_method] scene_id:[%d] forcing release...%s\n",COLOR_DANGER,_scene_id,COLOR_REGULAR);
            break;
        }
        // --- --- --- --- --- 
    } // wait itsaave to finish
    // --- --- --- --- --- --- 
    beseech_scene_itsaave(c_iicu_wikimyei,_scene_id);
    // --- --- --- --- --- --- 
    if(c_scene_itsaave->__it_state!=IT_FINISHED_PROFIT && c_scene_itsaave->__it_state!=IT_FINISHED_LOSS){
        fprintf(stderr,"[%s WARNING! %s] itsaave closed unfinished.\n",COLOR_DANGER,COLOR_REGULAR);
        fprintf(stderr,"[%s WARNING! %s] wikimyei continues on mayor warning.\n",COLOR_DANGER,COLOR_REGULAR);
    }
    // --- --- --- --- --- --- 
    // --- --- --- --- --- --- 
    release_scene_itsaave(c_iicu_wikimyei,_scene_id);
    // --- --- --- --- --- --- 
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
    switch(((__itsaave_thread_order_t*)_it_thread_order)->__it_type){
    case IT_FAKE:
        fake_itsaave_method(_it_thread_order, c_scene_id, c_kline_id);
        break;
    default:
        fprintf(stderr,"[%s cuwacunu %s:itsaave]%sERROR, not understood itsaave type, scene_id:[%d]. Configured in itsaave thread order%s\n",COLOR_CUWACUNU,COLOR_REGULAR,COLOR_DANGER, c_scene_id,COLOR_REGULAR);
        break;
    }
    // --- --- --- --- --- --- 
    fprintf(stderr,"[%s cuwacunu %s:itsaave]:scene_id:[%d]. %sFINISH%s\n",COLOR_CUWACUNU,COLOR_REGULAR,c_scene_id,COLOR_GOOD,COLOR_REGULAR);
    ((__itsaave_thread_order_t *)_it_thread_order)->__it_thead_is_bussy=0x00;
    pthread_exit(NULL);
    // --- --- --- --- --- --- 
}
