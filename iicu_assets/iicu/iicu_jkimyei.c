#include "iicu_jkimyei.h"
#include "../iicu/iicu_wikimyei.h"

// --- --- --- POLICY
__inteligent_order_policy_t *policy_fabric(){
    __inteligent_order_policy_t *new_iicu_policy=malloc(sizeof(__inteligent_order_policy_t));
    assert(new_iicu_policy!=NULL);
    new_iicu_policy->__order_margin_uper=0x00;
    new_iicu_policy->__order_margin_down=0x00;
    new_iicu_policy->__base_margin_investment=POLICY_BASE_INVESTMENT;
    new_iicu_policy->__policy_total_reward=0x00;//(-0x01)*__cwcn_infinite;
    return new_iicu_policy;
}
__inteligent_order_policy_t *policy_clone_fabric(__inteligent_order_policy_t *src_iicu_policy){
    __inteligent_order_policy_t *new_iicu_policy=policy_fabric();
    rebase_policy(new_iicu_policy, src_iicu_policy);
    return new_iicu_policy;
}
void rebase_policy(__inteligent_order_policy_t *dest_iicu_policy, __inteligent_order_policy_t *src_iicu_policy){
    SDL_Delay(50);
    dest_iicu_policy->__order_margin_down=src_iicu_policy->__order_margin_down;
    dest_iicu_policy->__order_margin_uper=src_iicu_policy->__order_margin_uper;
    dest_iicu_policy->__base_margin_investment=src_iicu_policy->__base_margin_investment;
    dest_iicu_policy->__policy_total_reward=src_iicu_policy->__policy_total_reward;
}
void destroy_policy(__inteligent_order_policy_t *_iicu_policy){
    free(_iicu_policy);
}
void plot_policy(__inteligent_order_policy_t *_iicu_policy){
    fprintf(stdout,"[policy:] \t __order_margin_uper:\t\t%f\n",_iicu_policy->__order_margin_uper);
    fprintf(stdout,"[policy:] \t __order_margin_down:\t\t%f\n",_iicu_policy->__order_margin_down);
    fprintf(stdout,"[policy:] \t __base_margin_investment:\t%f\n",_iicu_policy->__base_margin_investment);
    fprintf(stdout,"[policy:] \t __policy_total_reward:   \t%f\n",_iicu_policy->__policy_total_reward);
}
// --- --- --- JKIMYEI
__iicu_jkimyei_t *jkimyei_fabric(){
    __iicu_jkimyei_t *new_iicu_jkimyei=malloc(sizeof(__iicu_jkimyei_t));
    assert(new_iicu_jkimyei!=NULL);
    new_iicu_jkimyei->__jk_inteligent_order_policy=policy_fabric();
    new_iicu_jkimyei->__jk_mewaajacune=NULL;
    new_iicu_jkimyei->__jk_policy_has_computed=0x00;
    return new_iicu_jkimyei;
}
__iicu_jkimyei_t *jkimyei_clone_fabric(__iicu_jkimyei_t *src_iicu_jkimyei){
    __iicu_jkimyei_t *new_iicu_jkimyei=jkimyei_fabric();
    rebase_jkimyei(new_iicu_jkimyei,src_iicu_jkimyei);
    return new_iicu_jkimyei;
}
void rebase_jkimyei(__iicu_jkimyei_t *dest_iicu_jkimyei, __iicu_jkimyei_t *src_iicu_jkimyei){
    if(dest_iicu_jkimyei->__jk_inteligent_order_policy!=NULL){
        destroy_policy(dest_iicu_jkimyei->__jk_inteligent_order_policy);
        dest_iicu_jkimyei->__jk_inteligent_order_policy=NULL;
    }
    if(dest_iicu_jkimyei->__jk_mewaajacune!=NULL){
        // destroy_mewaajacune(dest_iicu_jkimyei->__jk_mewaajacune); // do not activate
        dest_iicu_jkimyei->__jk_mewaajacune=NULL;
    }
    if(src_iicu_jkimyei->__jk_inteligent_order_policy != NULL){
        dest_iicu_jkimyei->__jk_inteligent_order_policy=policy_clone_fabric(src_iicu_jkimyei->__jk_inteligent_order_policy);
    }
    dest_iicu_jkimyei->__jk_mewaajacune=src_iicu_jkimyei->__jk_mewaajacune;
    // if(src_iicu_jkimyei->__jk_mewaajacune != NULL){
    //     if(dest_iicu_jkimyei->__jk_mewaajacune!=NULL){
    //         rebase_mewaajacune(dest_iicu_jkimyei->__jk_mewaajacune,src_iicu_jkimyei->__jk_mewaajacune);
    //     } else {
    //         dest_iicu_jkimyei->__jk_mewaajacune=mewaajacune_clone_fabric(src_iicu_jkimyei->__jk_mewaajacune);
    //     }
    // }
    dest_iicu_jkimyei->__jk_policy_has_computed=src_iicu_jkimyei->__jk_policy_has_computed;
}
void destroy_jkimyei(__iicu_jkimyei_t *_iicu_jkimyei){
    destroy_policy(_iicu_jkimyei->__jk_inteligent_order_policy);
    free(_iicu_jkimyei);
}
/*
    jk funks
*/
___cwcn_bool_t policy_is_ready(__inteligent_order_policy_t *_iicu_policy){
    return (_iicu_policy->__order_margin_uper!=0x00) && (_iicu_policy->__order_margin_down!=0x00);
}

void run_policy_on_mewaajacunwe(__iicu_jkimyei_t *_iicu_jkimyei){ // #FIXME change to mewaajacune_list
    // __inteligent_order_policy_t *c_policy=_iicu_jkimyei->__jk_inteligent_order_policy;
    // int start_index=_iicu_jkimyei->__jk_mewaajacune->__load_index;
    // load_to_start(_iicu_jkimyei->__jk_mewaajacune);
    // int index_a;
    // __cwcn_type_t alliu_a,alliu_b,alliu_delta;
    // do{ // make an order at every step
    //     index_a=_iicu_jkimyei->__jk_mewaajacune->__load_index;
    //     alliu_a=glti(_iicu_jkimyei->__jk_mewaajacune)->__alliu_state[NIJCYOTA_ALLIU_INDEX];
    //     do{ // evaluate if the order closes down or up
    //         alliu_b=glti(_iicu_jkimyei->__jk_mewaajacune)->__alliu_state[NIJCYOTA_ALLIU_INDEX];
    //         if(alliu_b>=(0x01+c_policy->__order_margin_uper)*alliu_a){
    //             alliu_delta=alliu_b-alliu_a;
    //             c_policy->__policy_total_reward+=alliu_delta*c_policy->__base_margin_investment;
    //             break;
    //         } else if(alliu_b<=(0x01-c_policy->__order_margin_down)*alliu_a){
    //             alliu_delta=alliu_b-alliu_a;
    //             c_policy->__policy_total_reward-=alliu_delta*c_policy->__base_margin_investment;
    //             break;
    //         }
    //     }while(load_go_up(_iicu_jkimyei->__jk_mewaajacune)!=-0x01);
    //     load_to_index(_iicu_jkimyei->__jk_mewaajacune,index_a);
    // }while(load_go_up(_iicu_jkimyei->__jk_mewaajacune)!=-0x01);
    // load_to_index(_iicu_jkimyei->__jk_mewaajacune,start_index);
    
    
    __cwcn_type_t *c_mewaajcune_list=alliu_state_index_to_list(_iicu_jkimyei->__jk_mewaajacune,NIJCYOTA_ALLIU_INDEX);
    __inteligent_order_policy_t *c_policy=_iicu_jkimyei->__jk_inteligent_order_policy;
    int index_a=0x00,index_b=-0x01,_a_,_b_;
    int l_size=_iicu_jkimyei->__jk_mewaajacune->__load_size;
    __cwcn_type_t alliu_a,alliu_b,alliu_delta;
    for(_a_=0x00;index_b+0x01<l_size;_a_++){
        index_a=index_b+0x01; // if jump
        // // // index_a=_a_; // if all index _a_
        alliu_a=c_mewaajcune_list[index_a];
        for(_b_=index_a;_b_<l_size && index_b<l_size;_b_++){
            index_b=_b_;
            alliu_b=c_mewaajcune_list[index_b];
            if(alliu_b>=(0x01+c_policy->__order_margin_uper)*alliu_a){
                alliu_delta=alliu_b-alliu_a;
                c_policy->__policy_total_reward+=alliu_delta*c_policy->__base_margin_investment/alliu_a;
                break;
            } else if(alliu_b<=(0x01-c_policy->__order_margin_down)*alliu_a){
                alliu_delta=alliu_b-alliu_a;
                c_policy->__policy_total_reward-=alliu_delta*c_policy->__base_margin_investment/alliu_a;
                break;
            }
        }
    }
    free(c_mewaajcune_list);
}

void monte_carlo_random_search(__iicu_jkimyei_t *_iicu_jkimyei){
    fprintf(stdout,"[%s cuwacunu %s:jkimyei] %s [ start ] %s monte_carlo_random_search\n",COLOR_CUWACUNU,COLOR_REGULAR,COLOR_JKIMYEI,COLOR_REGULAR);
    // --- --- --- 
    __inteligent_order_policy_t *best_policy=policy_fabric();
    ___cwcn_bool_t first_run=0x01;
    clock_t begin;
	clock_t end;
	double time_spent;
    begin = clock();
    // --- --- --- START OF THE METHOD
    __cwcn_type_t mc_up_max=RANGE_EXPLORATION_MARGIN_UP_MAX;
    __cwcn_type_t mc_up_min=RANGE_EXPLORATION_MARGIN_UP_MIN;
    __cwcn_type_t mc_down_max=RANGE_EXPLORATION_MARGIN_DOWN_MAX;
    __cwcn_type_t mc_down_min=RANGE_EXPLORATION_MARGIN_DOWN_MIN;
    int mc_res=100;
    for(int ctx_episode=0x00;ctx_episode<MONTECARLO_EPISODES;ctx_episode++){
        // #FIXME add reset policy function
        _iicu_jkimyei->__jk_inteligent_order_policy->__policy_total_reward=0x00;
        _iicu_jkimyei->__jk_inteligent_order_policy->__order_margin_uper=max_min_res_rand(mc_up_max, mc_up_min, mc_res);
        _iicu_jkimyei->__jk_inteligent_order_policy->__order_margin_down=max_min_res_rand(mc_down_max, mc_down_min, mc_res);
        run_policy_on_mewaajacunwe(_iicu_jkimyei);
        if(first_run || _iicu_jkimyei->__jk_inteligent_order_policy->__policy_total_reward>best_policy->__policy_total_reward){
            first_run=0x00;
            rebase_policy(best_policy,_iicu_jkimyei->__jk_inteligent_order_policy);
        }
    }
    // --- --- --- 
    // --- --- --- 
    rebase_policy(_iicu_jkimyei->__jk_inteligent_order_policy,best_policy); // put the best policy inside _iicu_jkimyei
    destroy_policy(best_policy);
    // --- --- --- 
    end = clock();
    time_spent = (double)(end-begin) / CLOCKS_PER_SEC;
    // --- --- --- 
    _iicu_jkimyei->__jk_policy_has_computed=0x01;
    fprintf(stdout,"[%s cuwacunu %s:jkimyei] %s [ end ] %s monte_carlo_random_search : steps : %d : time : %f [s]\n",COLOR_CUWACUNU,COLOR_REGULAR,COLOR_JKIMYEI,COLOR_REGULAR,MONTECARLO_EPISODES,time_spent);
}


void *jkimyei_launcher(void *_jk_thread_order){
    #ifdef __JKIMYEI_THREAD_FORCE_CORE
    cpu_set_t cpuset;
    int cpu = __JKIMYEI_THREAD_FORCE_CORE;
    CPU_ZERO(&cpuset);
    CPU_SET(cpu,&cpuset);
    #endif
    int c_scene_id = ((__jkimyei_thread_order_t*)_jk_thread_order)->__scene_id;
    int c_kline_id = ((__jkimyei_thread_order_t*)_jk_thread_order)->__kline_id;
    fprintf(stdout,"[%s cuwacunu %s:jkimyei] %s [ start ] %s jkimyei_launcher for type order : scene:[%d], kline:[%d]\n",COLOR_CUWACUNU,COLOR_REGULAR,COLOR_JKIMYEI,COLOR_REGULAR,c_scene_id,c_kline_id);
    // it finds for _iicu_jkimyei the best policy
    ((__jkimyei_thread_order_t*)_jk_thread_order)->__jk_thead_is_bussy=0x01;
    __iicu_wikimyei_t *temp_iicu_wikimyei=((__jkimyei_thread_order_t*)_jk_thread_order)->__ref_iicu_wikimyei;
    // --- --- --- wait for scene kline to be loaded
    wait_scene_kline_load(temp_iicu_wikimyei, c_scene_id,c_kline_id);
    // --- --- --- #FIXME make bessech as a wrapper for optm methods
    beseech_mewaajacune(temp_iicu_wikimyei, c_scene_id, c_kline_id);
    beseech_jkimyei(temp_iicu_wikimyei, c_scene_id);
    // --- --- --- 
    __iicu_jkimyei_t *temp_iicu_jkimyei=jkimyei_clone_fabric(get_jkimyei(temp_iicu_wikimyei, c_scene_id)); // make a temporal copy
    temp_iicu_jkimyei->__jk_mewaajacune=mewaajacune_clone_fabric(
        get_mewaajacune(temp_iicu_wikimyei, c_scene_id, c_kline_id)); // load mewaajacune to temporal copy
    // --- --- --- 
    release_jkimyei(temp_iicu_wikimyei, c_scene_id);
    release_mewaajacune(temp_iicu_wikimyei, c_scene_id, c_kline_id);
    // --- --- --- LAUNCH type METHOD
    switch(((__jkimyei_thread_order_t*)_jk_thread_order)->__jk_type){
    case JK_MONTECARLO:
        monte_carlo_random_search(temp_iicu_jkimyei);
        break;
    default:
        fprintf(stderr,"[%s cuwacunu %s:] %s ERROR %s, not understood jkimyei type configured in jkimyei thread order\n",COLOR_CUWACUNU,COLOR_REGULAR,COLOR_DANGER,COLOR_REGULAR);
        break;
    }
    // --- --- --- 
    fprintf(stdout,"[%s cuwacunu %s:jkimyei] %s [ printing policy ] %s : scene:[%d] kline:[%d]\n",COLOR_CUWACUNU,COLOR_REGULAR,COLOR_JKIMYEI,COLOR_REGULAR,c_scene_id,c_kline_id);
    plot_policy(temp_iicu_jkimyei->__jk_inteligent_order_policy);
    // --- --- --- #FIXME add tsdo
    // --- --- --- SAVES JKIMYEI RESULT
    beseech_mewaajacune(temp_iicu_wikimyei, c_scene_id,c_kline_id);
    beseech_jkimyei(temp_iicu_wikimyei, c_scene_id);
    // --- --- --- 
    rebase_jkimyei(get_jkimyei(temp_iicu_wikimyei, c_scene_id), temp_iicu_jkimyei);
    // --- --- --- 
    release_jkimyei(temp_iicu_wikimyei, c_scene_id);
    release_mewaajacune(temp_iicu_wikimyei, c_scene_id,c_kline_id);
    // --- --- --- 
    destroy_jkimyei(temp_iicu_jkimyei);
    // --- --- --- 
    ((__jkimyei_thread_order_t*)_jk_thread_order)->__jk_thead_is_bussy=0x00;
    fprintf(stdout,"[%s cuwacunu %s:jkimyei] %s [ end ] %s jkimyei_launcher : for type order : [scene:%d, kline:%d]\n",COLOR_CUWACUNU,COLOR_REGULAR,COLOR_JKIMYEI,COLOR_REGULAR,c_scene_id,c_kline_id);
    pthread_exit(NULL);
}
