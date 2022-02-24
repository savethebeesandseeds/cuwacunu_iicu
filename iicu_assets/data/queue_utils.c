#include "queue_utils.h"
/*
    MEWAAJACUNE AND TRAYECTORY
*/
__trayectory_t *trayectory_fabric(__mewaajacune_t *_mewaajacune){
    __trayectory_t *new_trayectory=malloc(sizeof(__trayectory_t));
    #if defined(MEWAAJACUNE_DEBUG)
    fprintf(stdout,">> > ... request trayectory_fabric, alocated address: %p\n",new_trayectory);
    #endif
    if(!new_trayectory){
        fprintf(stderr,"ERROR, program seems unable to allocate memory for requested new trayectory\n");
        assert(new_trayectory!=NULL);
    }
    new_trayectory->__alliu_state=malloc(_mewaajacune->__alliu_size*sizeof(__cwcn_type_t));
    new_trayectory->__ujcamei_state=_cwcn_FLAT;
    #if defined(ALOCATION_DEBUG) // #FIXME this is only used here!
    fprintf(stdout,"%s     +++ [trayectory_fabric]:\n%s",COLOR_ALOCATION_ADD,COLOR_REGULAR);
    fprintf(stdout,"%s\t __alliu_state: %s%p:\n",COLOR_ALOCATION_ADD,COLOR_REGULAR,new_trayectory->__alliu_state);
    #endif
    return new_trayectory;
}
__load_queue_t *queue_item_fabric(__mewaajacune_t *_mewaajacune,__trayectory_t *_trayectory){
    __load_queue_t *new_queue_item=malloc(sizeof(__load_queue_t));
    new_queue_item->__trayectory_item=NULL; // #FIXME, queue_fabric seems unstable by allowing ty_item null
    new_queue_item->__up=malloc(sizeof(__load_queue_t*));
    new_queue_item->__down=malloc(sizeof(__load_queue_t*));
    #if defined(MEWAAJACUNE_DEBUG_LOAD)
    fprintf(stdout,">> > ... request to queue_item_fabric\n");
    #endif
    new_queue_item->__trayectory_item=_trayectory;
    #if defined(ALOCATION_DEBUG)
    fprintf(stdout,"     +++ [queue [%d] fabric]: \t %s[head:]%p,%s [up:]%p, [down:]%p, [ty:]%p\n",_mewaajacune->__load_index,COLOR_ALOCATION_ADD,new_queue_item,COLOR_REGULAR,*new_queue_item->__up,*new_queue_item->__down,new_queue_item->__trayectory_item);
    #endif
    assert(new_queue_item!=NULL);
    assert(new_queue_item->__up!=NULL);
    assert(new_queue_item->__down!=NULL);
    return new_queue_item;
}
__load_queue_t *load_fabric(__mewaajacune_t *_mewaajacune){
    assert(load_is_empty(_mewaajacune));
    #if defined(MEWAAJACUNE_DEBUG) || defined(MEWAAJACUNE_DEBUG_LOAD)
    fprintf(stdout,">> > ... request to [load_fabric], at load_index: %d\n",_mewaajacune->__load_index);
    #endif
    __load_queue_t *new_head=queue_item_fabric(_mewaajacune,trayectory_fabric(_mewaajacune));
    #if defined(ALOCATION_DEBUG)
    fprintf(stdout,"\t load_fabric %s[new head alocation:]%p%s\n",COLOR_L_GOOD,new_head,COLOR_REGULAR);
    #endif
    _mewaajacune->__load_index=0x00;
    _mewaajacune->__load_size=0x01;
    return new_head;
}
__mewaajacune_t *mewaajacune_fabric(){
    #if defined(MEWAAJACUNE_DEBUG)
    fprintf(stdout,">> > ... mewaajacune_fabric\n");
    #endif
    __mewaajacune_t *new_mewaajacune=malloc(sizeof(__mewaajacune_t));
    if(!new_mewaajacune){
        fprintf(stderr,"ERROR, unable to allocate new mewaajacune\n");
        assert(0x00);
    } // declaration MEWAAJACUNE FABRIC order is set, do not shuffle.
    new_mewaajacune->__alliu_size=0x01; 
    new_mewaajacune->__load_index=-1; // redundant (due to fabric load)
    new_mewaajacune->__load_size=0x00; // redundant (due to fabric load)
    new_mewaajacune->__load_head=NULL;//load_fabric(new_mewaajacune);
    assert(load_is_healty(new_mewaajacune));
    assert(load_is_empty(new_mewaajacune));
    return new_mewaajacune;
}
/*
    LOAD QUEUE
*/
int load_go_up(__mewaajacune_t *_mewaajacune){
    #if defined(MEWAAJACUNE_DEBUG_LOAD)
    fprintf(stdout,">> > ... request to go [up] on load index [%d]\n",_mewaajacune->__load_index);
    #endif
    if(load_is_empty(_mewaajacune)){
        #if defined(MEWAAJACUNE_DEBUG_LOAD)
        fprintf(stdout,"\t [return -1] load is empty\n");
        #endif
        return -0x01;
    }
    #if defined(MEWAAJACUNE_DEBUG_LOAD)
    if(load_on_end(_mewaajacune)){fprintf(stdout,"\t[go_up will return -1] on load index [%d] \t (is NULL)  load_up: %p\n",_mewaajacune->__load_index,*_mewaajacune->__load_head->__up);}
    #endif
    if(load_on_end(_mewaajacune)){
        assert(load_on_end(_mewaajacune));
        return -0x01;
    }
    _mewaajacune->__load_index+=0x01;
    _mewaajacune->__load_head=*_mewaajacune->__load_head->__up;
    return 0x00;
}
int load_go_down(__mewaajacune_t *_mewaajacune){
    #if defined(MEWAAJACUNE_DEBUG_LOAD)
    fprintf(stdout,">> > ... request to go [down] on load index [%d]\n",_mewaajacune->__load_index);
    #endif
    if(load_is_empty(_mewaajacune)){
        #if defined(MEWAAJACUNE_DEBUG_LOAD)
        fprintf(stdout,"\t [return -1] load is empty\n");
        #endif
        return -0x01;
    }
    #if defined(MEWAAJACUNE_DEBUG_LOAD)
    if(load_on_start(_mewaajacune)){fprintf(stdout,"\t load_go_down will [return -1] for load index [%d] (is NULL): [load_down:] %p\n",_mewaajacune->__load_index,*_mewaajacune->__load_head->__down);}
    #endif
    if(load_on_start(_mewaajacune)){
        assert(load_on_start(_mewaajacune));
        return -0x01;
    }
    _mewaajacune->__load_index+=-0x01;
    _mewaajacune->__load_head=*_mewaajacune->__load_head->__down;
    return 0x00;
}
void load_to_start(__mewaajacune_t *_mewaajacune){
    #if defined(MEWAAJACUNE_DEBUG_LOAD)
        fprintf(stdout,">> > ... load_to_start ; c_index: [%d]\n",_mewaajacune->__load_index);
    #endif
    while(load_go_down(_mewaajacune)!=-1){}
    assert(load_on_start(_mewaajacune));
}
void load_to_end(__mewaajacune_t *_mewaajacune){
    #if defined(MEWAAJACUNE_DEBUG_LOAD)
        fprintf(stdout,">> > ... load_to_end ; c_index: [%d]\n",_mewaajacune->__load_index);
    #endif
    while(load_go_up(_mewaajacune)!=-1){}
    assert(load_on_end(_mewaajacune));
}
void load_to_index(__mewaajacune_t *_mewaajacune, int _index){
    assert(_index<_mewaajacune->__load_size);
    if(!load_is_empty(_mewaajacune)){
        if(_mewaajacune->__load_size<_index){
            fprintf(stdout, ">> WARNING: requested load index [%d] is unreachable on load size [%d].\n",_index,_mewaajacune->__load_size);
        }
        if(_mewaajacune->__load_index<_index){
            while(_mewaajacune->__load_index!=_index){
                if(load_go_up(_mewaajacune)==-1){
                    break;
                }
            }
        }else if(_mewaajacune->__load_index>_index){
            while(_mewaajacune->__load_index!=_index){
                if(load_go_down(_mewaajacune)==-1){
                    break;
                }
            }
        }
        #if defined(MEWAAJACUNE_DEBUG_LOAD)
        fprintf(stdout,">> > ... load_to_index ; commanded: [%d] ; c_index: [%d]\n",_index, _mewaajacune->__load_index);
        #endif
    }
    #if defined(MEWAAJACUNE_DEBUG_LOAD)
    else{fprintf(stdout,">> > ... load_to_index avoided due to noob load, load_to_index ; commanded: [%d] ; c_index: [%d]\n",_index, _mewaajacune->__load_index);}
    #endif
}
int yield_next_trayectory(__mewaajacune_t *_mewaajacune){
    // #FIXME do something when with int 
    #if defined(MEWAAJACUNE_DEBUG)
    fprintf(stdout,">> > ... request to yield_next_trayectory\n");
    #endif
    assert(load_is_healty(_mewaajacune));
    if(load_is_empty(_mewaajacune)){
        assert(load_is_empty(_mewaajacune));
        _mewaajacune->__load_head=load_fabric(_mewaajacune);
        *_mewaajacune->__load_head->__down=NULL;
        *_mewaajacune->__load_head->__up=NULL;
    }else{
        load_to_end(_mewaajacune);
        __load_queue_t *new_head=queue_item_fabric(_mewaajacune,trayectory_fabric(_mewaajacune));
        *new_head->__down=_mewaajacune->__load_head;
        *new_head->__up=NULL;
        *_mewaajacune->__load_head->__up=new_head;
        _mewaajacune->__load_head=new_head;
        _mewaajacune->__load_index+=0x01;
        _mewaajacune->__load_size+=0x01;
    }
    #if defined(MEWAAJACUNE_DEBUG_LOAD)
    fprintf(stdout,"\t +++ [trayectory enqueued]: \t [head:] %p, \t [up:] %p, \t [down:] %p, \t [trayectory:] %p\n",_mewaajacune->__load_head,*_mewaajacune->__load_head->__up,*_mewaajacune->__load_head->__down, _mewaajacune->__load_head->__trayectory_item);
    #endif
    // #if defined(ALOCATION_DEBUG)
    // fprintf(stdout,"\t[yield_next_trayectory:]\n");
    // load_print_up_trayectory_pointers(_mewaajacune);
    // #endif
    #if defined(MEWAAJACUNE_DEBUG_v2)
    fprintf(stdout,">> > ... yield_next_trayectory, c_load_index:%d, c_load_size:%d\n", _mewaajacune->__load_index, _mewaajacune->__load_size);
    #endif
    return 0x00;
}
__trayectory_t *get_load_trayectory_item(__mewaajacune_t *_mewaajacune){
    return _mewaajacune->__load_head->__trayectory_item;
}
__trayectory_t *glti(__mewaajacune_t *_mewaajacune){
    return get_load_trayectory_item(_mewaajacune);
}
__trayectory_t *get_load_trayectory_item_from_index(__mewaajacune_t *_mewaajacune, int _index, ___cwcn_bool_t _rneturn){
    // _rneturn holds the flag to rever the head index displacement

    #if defined(MEWAAJACUNE_DEBUG_v2)
    fprintf(stdout,">> > ... get_load_trayectory_item_from_index\n");
    #endif
    __trayectory_t *rnetrival=NULL; // #FIXME, c noob knows not about this function
    if(load_is_empty(_mewaajacune)){return rnetrival;}
    int start_index=_mewaajacune->__load_index;
    load_to_index(_mewaajacune, _index);
    rnetrival=_mewaajacune->__load_head->__trayectory_item;
    if(!_rneturn){
        load_to_index(_mewaajacune,start_index);
    }
    return rnetrival;
}
void load_print_up_trayectory_pointers(__mewaajacune_t *_mewaajacune){
    fprintf(stdout,">> > ... request to load_print_up_trayectory_pointers: \n");
    if(load_is_empty(_mewaajacune)){fprintf(stdout,">> > ... \t [no load found]\n");}
    else{
        int c_index=_mewaajacune->__load_index;
        load_to_start(_mewaajacune);
        if(!load_is_empty(_mewaajacune)){do{
            fprintf(stdout,"   .     [%d] :: %s[head:]%p,%s \t[up:]%p, \t[down:]%p \t[ty:]%p\n", _mewaajacune->__load_index, COLOR_L_GOOD,_mewaajacune->__load_head, COLOR_REGULAR, _mewaajacune->__load_head->__up, _mewaajacune->__load_head->__down, _mewaajacune->__load_head->__trayectory_item);
            fprintf(stdout,"   .     [%d] :: [*head]\t\t, \t%s[*up]%p,%s \t%s[*down]%p,%s \t[*ty]\t\t\n",_mewaajacune->__load_index, COLOR_L_GOOD,*_mewaajacune->__load_head->__up, COLOR_REGULAR, COLOR_L_GOOD,*_mewaajacune->__load_head->__down,COLOR_REGULAR);
        }while(load_go_up(_mewaajacune)!=-1);}
        load_to_index(_mewaajacune, c_index);
    }
}
void load_print_up_trayectory_queue(__mewaajacune_t *_mewaajacune){
    fprintf(stdout,">> > ... request to load_print_up_trayectory_queue: \n");
    if(load_is_empty(_mewaajacune)){fprintf(stdout,">> > ... \t [no load found]\n");}
    else{
        int c_index=_mewaajacune->__load_index;
        load_to_start(_mewaajacune);
        if(!load_is_empty(_mewaajacune)){do{
            fprintf(stdout,">> : load index: [%d] :: alliu_state[0]: %.2f\n", _mewaajacune->__load_index, glti(_mewaajacune)->__alliu_state[0x00]);
        }while(load_go_up(_mewaajacune)!=-1);}
        load_to_index(_mewaajacune, c_index);
    }
}
void load_print_down_trayectory_queue(__mewaajacune_t *_mewaajacune){
    printf(">> > ... request to load_print_down_trayectory_queue: \n");
    if(load_is_empty(_mewaajacune)){fprintf(stdout,">> > ... \t [no load found]\n");}
    else{
        int c_index=_mewaajacune->__load_index;
        load_to_end(_mewaajacune);
        if(!load_is_empty(_mewaajacune)){do{
            fprintf(stdout,">> : load index: [%d] :: alliu_state[0]: %.2f\n", _mewaajacune->__load_index, glti(_mewaajacune)->__alliu_state[0x00]);
        }while(load_go_down(_mewaajacune)!=-1);}
        load_to_index(_mewaajacune, c_index);
    }
}
/*
*/
___cwcn_bool_t load_on_end(__mewaajacune_t *_mewaajacune){
    return _mewaajacune->__load_index-_mewaajacune->__load_size==-1;
}
___cwcn_bool_t load_on_start(__mewaajacune_t *_mewaajacune){
    return _mewaajacune->__load_index==0;
}
___cwcn_bool_t load_on_noob(__mewaajacune_t *_mewaajacune){
    return load_on_start(_mewaajacune) && load_on_end(_mewaajacune);
}
___cwcn_bool_t load_is_healty(__mewaajacune_t *_mewaajacune){
    if(load_is_empty(_mewaajacune)){
        #if defined(MEWAAJACUNE_DEBUG_HEALT)
        fprintf(stdout,"%s\t [empty load]: \tH E A L T\
        \n\t\tindex: \t\t\t\t\t\t%d, \
        \n\t\tload_is_empty(): \t\t\t\t\t%s %s\n", \
        COLOR_HEALT,\
        _mewaajacune->__load_index,\
        print_cwcn_bool((load_is_empty(_mewaajacune))),\
        COLOR_REGULAR\
        );
        #endif
        return ___CWCN_TRUE;
    } else {
        if(load_on_noob(_mewaajacune)){
            #if defined(MEWAAJACUNE_DEBUG_HEALT)
    fprintf(stdout,"\t %s[noob load]: \tH E A L T\
    \n\t\tindex: \t\t\t\t\t\t%d, \
    \n\t\t_mewaajacune->__load_head!=NULL: \t\t\t\t%s \t&&\
    \n\t\t_mewaajacune->__load_head->__trayectory_item!=NULL: \t%s \t&&\
    \n\t\t*_mewaajacune->__load_head->__up==NULL: \t\t\t%s \t&&\
    \n\t\t*_mewaajacune->__load_head->__down==NULL, \t\t\t%s \t&&\
    \n\t\t_mewaajacune->__load_index<_mewaajacune->__load_size: \t%s \t&&\
    \n\t\t!load_is_empty: \t\t\t\t\t%s%s\n",\
                            COLOR_HEALT,
                            _mewaajacune->__load_index,\
                            print_cwcn_bool((_mewaajacune->__load_head!=NULL)),\
                            print_cwcn_bool((_mewaajacune->__load_head->__trayectory_item!=NULL)),\
                            print_cwcn_bool((*_mewaajacune->__load_head->__up==NULL)),\
                            print_cwcn_bool((*_mewaajacune->__load_head->__down==NULL)),\
                            print_cwcn_bool((_mewaajacune->__load_index<_mewaajacune->__load_size)),\
                            print_cwcn_bool((!load_is_empty(_mewaajacune))),
                            COLOR_REGULAR
                            );
            #endif
            return  _mewaajacune->__load_head!=NULL &&\
                    _mewaajacune->__load_head->__trayectory_item!=NULL &&\
                    *_mewaajacune->__load_head->__up==NULL &&\
                    *_mewaajacune->__load_head->__down==NULL &&\
                    _mewaajacune->__load_index<_mewaajacune->__load_size &&\
                    !load_is_empty(_mewaajacune);
        }else if(load_on_end(_mewaajacune)){
            #if defined(MEWAAJACUNE_DEBUG_HEALT)
    fprintf(stdout,"%s\t [up extrema]: \tH E A L T\
    \n\t\tindex: \t\t\t\t\t\t%d, \
    \n\t\t_mewaajacune->__load_head!=NULL: \t\t\t\t%s \t&&\
    \n\t\t_mewaajacune->__load_head->__trayectory_item!=NULL: \t%s \t&&\
    \n\t\t*_mewaajacune->__load_head->__up==NULL: \t\t\t%s \t&&\
    \n\t\t_mewaajacune->__load_index<_mewaajacune->__load_size: \t%s \t&&\
    \n\t\t!load_is_empty: \t\t\t\t\t%s%s\n",\
                            COLOR_HEALT,
                            _mewaajacune->__load_index,\
                            print_cwcn_bool((_mewaajacune->__load_head!=NULL)),\
                            print_cwcn_bool((_mewaajacune->__load_head->__trayectory_item!=NULL)),\
                            print_cwcn_bool((*_mewaajacune->__load_head->__up==NULL)),\
                            print_cwcn_bool((_mewaajacune->__load_index<_mewaajacune->__load_size)),\
                            print_cwcn_bool((!load_is_empty(_mewaajacune))),
                            COLOR_REGULAR);
            #endif
            return  _mewaajacune->__load_head!=NULL &&\
                    _mewaajacune->__load_head->__trayectory_item!=NULL &&\
                    *_mewaajacune->__load_head->__up==NULL &&\
                    _mewaajacune->__load_index<_mewaajacune->__load_size &&\
                    !load_is_empty(_mewaajacune);
        } else if(load_on_start(_mewaajacune)){
            #if defined(MEWAAJACUNE_DEBUG_HEALT)
    fprintf(stdout,"%s\t [down extrema]: \tH E A L T\
    \n\t\tindex: \t\t\t\t\t\t%d, \
    \n\t\t_mewaajacune->__load_head!=NULL: \t%s \t&&\
    \n\t\t_mewaajacune->__load_head->__trayectory_item!=NULL: \t%s \t&&\
    \n\t\t*_mewaajacune->__load_head->__down==NULL: \t\t\t%s \t&&\
    \n\t\t_mewaajacune->__load_index<_mewaajacune->__load_size: \t%s \t&&\
    \n\t\t!load_is_empty: \t\t\t\t\t%s%s\n",\
                            COLOR_HEALT,
                            (_mewaajacune->__load_index),
                            print_cwcn_bool((_mewaajacune->__load_head!=NULL)),\
                            print_cwcn_bool((_mewaajacune->__load_head->__trayectory_item!=NULL)),\
                            print_cwcn_bool((*_mewaajacune->__load_head->__down==NULL)),\
                            print_cwcn_bool((_mewaajacune->__load_index<_mewaajacune->__load_size)),\
                            print_cwcn_bool((!load_is_empty(_mewaajacune))),
                            COLOR_REGULAR);
            #endif
            return  _mewaajacune->__load_head!=NULL &&\
                    _mewaajacune->__load_head->__trayectory_item!=NULL &&\
                    *_mewaajacune->__load_head->__down==NULL &&\
                    _mewaajacune->__load_index<_mewaajacune->__load_size &&\
                    !load_is_empty(_mewaajacune);
        } else {
            #if defined(MEWAAJACUNE_DEBUG_HEALT)
    fprintf(stdout,"%s\t[no extrema]: \tH E A L T\
    \n\t\tindex: \t\t\t\t\t\t%d, \
    \n\t\t_mewaajacune->__load_head!=NULL: \t\t\t\t%s \t&&\
    \n\t\t_mewaajacune->__load_head->__trayectory_item!=NULL: \t%s \t&&\
    \n\t\t_mewaajacune->__load_index<_mewaajacune->__load_size: \t%s \t&&\
    \n\t\t!load_is_empty: \t\t\t\t\t%s%s\n",\
                            COLOR_HEALT,
                            _mewaajacune->__load_index,\
                            print_cwcn_bool((_mewaajacune->__load_head!=NULL)),\
                            print_cwcn_bool((_mewaajacune->__load_head->__trayectory_item!=NULL)),\
                            print_cwcn_bool((_mewaajacune->__load_index<_mewaajacune->__load_size)),\
                            print_cwcn_bool((!load_is_empty(_mewaajacune))),
                            COLOR_REGULAR);
            #endif
            return  _mewaajacune->__load_head!=NULL &&\
                    _mewaajacune->__load_head->__trayectory_item!=NULL &&\
                    _mewaajacune->__load_index<_mewaajacune->__load_size &&\
                    !load_is_empty(_mewaajacune); // empty load is NOT healty
        }
    }
}
___cwcn_bool_t load_is_empty(__mewaajacune_t *_mewaajacune){
    assert(_mewaajacune->__load_index<_mewaajacune->__load_size);
    if(_mewaajacune->__load_head==NULL){ // #FIXME, add checks for ** pointer chain
        assert(_mewaajacune->__load_head==NULL);
        assert(_mewaajacune->__load_index==-0x01);
        assert(_mewaajacune->__load_size==0);
        return ___CWCN_TRUE;
    }else{
        assert(_mewaajacune->__load_head!=NULL);
        assert(_mewaajacune->__load_index>=0);
        assert(_mewaajacune->__load_size>0);
        return ___CWCN_FALSE;
    }
}
/*
*/
void kill_trayectory(__trayectory_t *_trayectory){
    #if defined(MEWAAJACUNE_DEBUG)
    fprintf(stdout,">> > ... request to kill_trayectory: %p\n",_trayectory);
    #endif
    free(_trayectory->__alliu_state);                       _trayectory->__alliu_state=NULL;
}
void kill_queue(__load_queue_t *_queue){
    #if defined(ALOCATION_DEBUG)
    fprintf(stdout,">> > --- [killin queue] \n\t(pass)[head:]%p, (kill)[up:]%p (kill)[down:]%p (kill)[ty:]%p\n",\
                    _queue,\
                    _queue->__up,\
                    _queue->__down,\
                    _queue->__trayectory_item);
    #endif
    kill_trayectory(_queue->__trayectory_item);
    free(_queue->__trayectory_item);    _queue->__trayectory_item=NULL;
    free(_queue->__down);               _queue->__down=NULL;
    free(_queue->__up);                 _queue->__up=NULL;
}
void empty_queue_on_last(__mewaajacune_t *_mewaajacune){
    assert(load_is_healty(_mewaajacune));
    load_to_end(_mewaajacune);
    if(_mewaajacune->__load_size>=0x02){
        load_go_down(_mewaajacune); // head is null
        #if defined(MEWAAJACUNE_DEBUG) || defined(ALOCATION_DEBUG)
        fprintf(stdout,"\t [killing load in]: [%d]->__up (load size: %d)\n",_mewaajacune->__load_index,_mewaajacune->__load_size);
        #endif
        assert(!load_on_end(_mewaajacune));
        kill_queue(*_mewaajacune->__load_head->__up);
        #if defined(ALOCATION_DEBUG)
        fprintf(stdout,">> > --- [killin *up] \n\t(kill)[*head->__up:]%p",*_mewaajacune->__load_head->__up);
        #endif
        free(*_mewaajacune->__load_head->__up);
        *_mewaajacune->__load_head->__up=NULL;
        assert(_mewaajacune->__load_head->__up!=NULL);
        assert(*_mewaajacune->__load_head->__up==NULL);
        assert(_mewaajacune->__load_head!=NULL);
        assert(_mewaajacune->__load_size>=0x02);
        _mewaajacune->__load_size--;
        assert(load_is_healty(_mewaajacune));
    } else if(_mewaajacune->__load_size==1){
        #if defined(MEWAAJACUNE_DEBUG) || defined(ALOCATION_DEBUG)
        #endif
        #if defined(MEWAAJACUNE_DEBUG) || defined(ALOCATION_DEBUG)
        fprintf(stdout,"\t [killing last queue]: [%d] with (load size: %d)\n",_mewaajacune->__load_index,_mewaajacune->__load_size);
        #endif
        assert(load_on_start(_mewaajacune) && load_on_end(_mewaajacune));
        kill_queue(_mewaajacune->__load_head);
        #if defined(ALOCATION_DEBUG)
        fprintf(stdout,">> > --- [killin head] \n\t(kill)[head:]%p",_mewaajacune->__load_head);
        #endif
        free(_mewaajacune->__load_head);
        _mewaajacune->__load_head=NULL;
        _mewaajacune->__load_size--;
        _mewaajacune->__load_index--;
        assert(load_is_empty(_mewaajacune));
        assert(load_is_healty(_mewaajacune)); // #FIXME an empty load is a healty load?
    }
    #if defined(ALOCATION_DEBUG)
    else{fprintf(stdout,">> > /// [skippin up queue] \t(item found to be NULL)\t at load index: [%d]\t with address: %p\n",_mewaajacune->__load_index,_mewaajacune->__load_head->__up);}
    #endif
}
void kill_load(__mewaajacune_t *_mewaajacune){
    #if defined(MEWAAJACUNE_DEBUG) || defined(ALOCATION_DEBUG)
    fprintf(stdout,">> > ... request to kill_load\n");
    #endif
    if(load_is_empty(_mewaajacune)){
        #if defined(MEWAAJACUNE_DEBUG)  || defined(ALOCATION_DEBUG)
        fprintf(stdout, "\t [found empty load]\n");
        #endif
    } else {
        do{
            empty_queue_on_last(_mewaajacune);
            // #if defined(ALOCATION_DEBUG)
            // printf("\t [current queue pointer state:]\n");
            // load_print_up_trayectory_pointers(_mewaajacune);
            // #endif
        }while(!load_is_empty(_mewaajacune));
    }
    assert(load_is_empty(_mewaajacune));
}
/*
    MAIN OBJECT DESTRUCTION 
*/
void destroy_mewaajacune(__mewaajacune_t *_mewaajacune){
    #if defined(MEWAAJACUNE_DEBUG) || defined(ALOCATION_DEBUG)
    fprintf(stdout,">> > ... destroy_mewaajacune [#FIXME alocation cleaning]\n");
    #endif
    kill_load(_mewaajacune);
    free(_mewaajacune); // #FIXME assert if needed outside
}
/*
    MAIN OBJECT STATISTICS
*/
__cwcn_type_t *alliu_index_to_list(__mewaajacune_t *_mewaajacune,int _alliu_index){ // don't forget to free the vector
    if(load_is_empty(_mewaajacune)){return NULL;}
    __cwcn_type_t load_n =_mewaajacune->__load_size;
    __cwcn_type_t *rnetrival=malloc(load_n*sizeof(__cwcn_type_t));
    for(int idx=0;idx<load_n;idx++){rnetrival[idx]=0;}
    if(rnetrival==NULL){fprintf(stderr,"[ERROR:] unable to allocate memory in alliu_index_to_list \n");}
    int start_index=_mewaajacune->__load_index;
    int rnetrival_index=0;
    for(load_to_start(_mewaajacune);load_go_up(_mewaajacune)!=-1;){
        rnetrival[rnetrival_index]=glti(_mewaajacune)->__alliu_state[_alliu_index];
        rnetrival_index++;
    }
    load_to_index(_mewaajacune,start_index);
    return rnetrival;
}
__cwcn_type_t max_alliu_in_load(__mewaajacune_t *_mewaajacune,int _alliu_index){
    // fprintf(stdout,"%d\n",_mewaajacune->__load_size);
    __cwcn_type_t *max_alliu_list=alliu_index_to_list(_mewaajacune,_alliu_index);
    __cwcn_type_t load_n =_mewaajacune->__load_size;
    __cwcn_type_t max_alliu=-__cwcn_infinite;
    for(int idx=0;idx<load_n;idx++){
        if(max_alliu_list[idx]>max_alliu){max_alliu=max_alliu_list[idx];}
    }
    free(max_alliu_list);
    return max_alliu;
}
__cwcn_type_t min_alliu_in_load(__mewaajacune_t *_mewaajacune,int _alliu_index){
    __cwcn_type_t *min_alliu_list=alliu_index_to_list(_mewaajacune,_alliu_index);
    __cwcn_type_t load_n =_mewaajacune->__load_size;
    __cwcn_type_t min_alliu=__cwcn_infinite;
    for(int idx=0;idx<load_n;idx++){
        if(min_alliu_list[idx]<min_alliu){min_alliu=min_alliu_list[idx];}
    }
    free(min_alliu_list);
    return min_alliu;

}
__cwcn_type_t mean_alliu_in_load(__mewaajacune_t *_mewaajacune,int _alliu_index){ // #FIXME double for this and the calling of alliu_index_to_list can be avoided, implement if critical velocity is required
    if(load_is_empty(_mewaajacune)){return 0;}
    __cwcn_type_t *mean_alliu_list=alliu_index_to_list(_mewaajacune,_alliu_index);
    __cwcn_type_t alliu_mean=0;
    __cwcn_type_t load_n =_mewaajacune->__load_size;
    for(int idx=0;idx<load_n;idx++){
        alliu_mean+=mean_alliu_list[idx];
    }
    free(mean_alliu_list);
    return alliu_mean/load_n;
}
__cwcn_type_t std_alliu_in_load(__mewaajacune_t *_mewaajacune,int _alliu_index){ // #FIXME double for this and the calling of alliu_index_to_list can be avoided, implement if critical velocity is required
    fprintf(stdout,"waka : : %d\n",_mewaajacune->__load_size);
    __cwcn_type_t load_n =_mewaajacune->__load_size;
    if(load_n<2){return 0;}
    __cwcn_type_t *std_alliu_list=alliu_index_to_list(_mewaajacune,_alliu_index);
    __cwcn_type_t alliu_mean=mean_alliu_in_load(_mewaajacune,_alliu_index); // #FIXME is just too much calling of lists...
    __cwcn_type_t alliu_sdt=0;
    for(int idx=0;idx<load_n;idx++){
        alliu_sdt+=pow(std_alliu_list[idx]-alliu_mean,2);
    }
    free(std_alliu_list);
    return alliu_sdt/(load_n-1);
}
