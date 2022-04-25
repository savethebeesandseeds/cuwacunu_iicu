#include "broker_utils.h"
void broker_websocketclient_factory(void *_iicu_wikimyei){
    ((__iicu_wikimyei_t*)_iicu_wikimyei)->__broker_wsclient=libwsclient_new(BINANCE_WEBSOCKET_ENDPOINT);
    ((__iicu_wikimyei_t*)_iicu_wikimyei)->__broker_wsclient->ref_struct=_iicu_wikimyei;
    libwsclient_onopen(((__iicu_wikimyei_t*)_iicu_wikimyei)->__broker_wsclient, &broker_websocket_on_open);
    libwsclient_onmessage(((__iicu_wikimyei_t*)_iicu_wikimyei)->__broker_wsclient, &broker_websocket_on_message);
    libwsclient_onerror(((__iicu_wikimyei_t*)_iicu_wikimyei)->__broker_wsclient, &broker_websocket_on_error);
    libwsclient_onclose(((__iicu_wikimyei_t*)_iicu_wikimyei)->__broker_wsclient, &broker_websocket_on_close);
}
void destroy_broker_websocketclient(__wsclient_t *_client){
    // #FIXME might be buggy
    libwsclient_finish(_client);
}

___cwcn_bool_t symbol_kline_broker_update_needed(void *_iicu_wikimyei, int _idx_scene, int _idx_kline){
    double c_time= (double) time(NULL);
    double d_time = c_time-get_state(_iicu_wikimyei)->kline_last_update[_idx_scene][_idx_kline];
    if(get_state(_iicu_wikimyei)->kline_last_update[_idx_scene][_idx_kline]==0x00 || d_time > BROKER_CANDLE_PERIODS[_idx_kline]){
        return 0x01;
    } else {
        return 0x00;
    }
}

        
void update_broker_mewaajacune_klines(void *_iicu_wikimyei){
    int test_index_kline;
    int c_scene;
    int c_kline;
    for(int idx_kline=0x00;idx_kline<BROKER_CANDLE_N_INTERVALS;idx_kline++){ // all intervals per symbol
        for(int idx_symb=0x00;idx_symb<MAX_IICU_SCENES;idx_symb++){ // all symbols
            beseech_all(_iicu_wikimyei);
            c_scene=gcsid(_iicu_wikimyei);
            c_kline=gcklid(_iicu_wikimyei);
            // beseech_nijcyota(_iicu_wikimyei);
            test_index_kline=giicn(_iicu_wikimyei)->jkimyei_klines_index;
            // release_nijcyota(_iicu_wikimyei);
            release_all(_iicu_wikimyei);
            if(symbol_kline_broker_update_needed(_iicu_wikimyei,c_scene,c_kline)){ // give priority to the active item
                update_mewaajacune_item(_iicu_wikimyei, IICU_SCENES_SYMBOLS[c_scene], BROKER_CANDLE_INTERVALS[c_kline]);
            }
            if(symbol_kline_broker_update_needed(_iicu_wikimyei,idx_symb,test_index_kline)){ // give priority to policy needs
                update_mewaajacune_item(_iicu_wikimyei, IICU_SCENES_SYMBOLS[idx_symb], BROKER_CANDLE_INTERVALS[test_index_kline]);
            }
            update_mewaajacune_item(_iicu_wikimyei, IICU_SCENES_SYMBOLS[idx_symb], BROKER_CANDLE_INTERVALS[idx_kline]);
        }
    }
}
void update_mewaajacune_item(void *_iicu_wikimyei, char *symbol, char *interval){
    int idx_kline=-1;
    int idx_scene=-1;
    for(int ctx_kline=0x00;ctx_kline<BROKER_CANDLE_N_INTERVALS;ctx_kline++){
        if(strcmp(BROKER_CANDLE_INTERVALS[ctx_kline], interval)==0){idx_kline=ctx_kline;break;}
    }
    for(int ctx_symb=0x00;ctx_symb<MAX_IICU_SCENES;ctx_symb++){ // all scenes
        if(strcmp(IICU_SCENES_SYMBOLS[ctx_symb],symbol)==0){idx_scene=ctx_symb;break;}
    }
    if(idx_kline!=-1 && idx_scene!=-1){
        // --- --- --- 
        beseech_nijcyota(_iicu_wikimyei);
        int _alliu_index=giicn(_iicu_wikimyei)->alliu_index;
        release_nijcyota(_iicu_wikimyei);
        // --- --- --- 
        if(symbol_kline_broker_update_needed(_iicu_wikimyei, idx_scene, idx_kline)){
            // --- temporal mewaajacune
            __iicu_mewaajacune_t *tmp_mewaajacune=mewaajacune_fabric();
            __cwcn_type_t tmp_mean=0x00;
            __cwcn_type_t tmp_std=0x00;
            // --- update temporal mewaajacune
            populate_alliu_with_klines(tmp_mewaajacune, _alliu_index, symbol, interval);
            tmp_mean=mean_alliu_in_load(tmp_mewaajacune, _alliu_index);
            tmp_std=std_alliu_in_load(tmp_mewaajacune, _alliu_index);
            get_state(_iicu_wikimyei)->kline_last_update[idx_scene][idx_kline]=(double) time(NULL);
            // --- safely update desired mewaajacune
            beseech_mewaajacune(_iicu_wikimyei, idx_scene, idx_kline);
            rebase_mewaajacune(get_mewaajacune(_iicu_wikimyei, idx_scene, idx_kline),tmp_mewaajacune);
            release_mewaajacune(_iicu_wikimyei, idx_scene, idx_kline);
            // --- safely destoy temporal mewaajacune
            destroy_mewaajacune(tmp_mewaajacune);
            // --- safely update desired staticques
            beseech_staticques(_iicu_wikimyei, idx_scene);
            get_staticques(_iicu_wikimyei, idx_scene)->__alliu_mean[idx_kline]=tmp_mean;
            get_staticques(_iicu_wikimyei, idx_scene)->__alliu_std[idx_kline]=tmp_std;
            release_staticques(_iicu_wikimyei, idx_scene);
        }
    } else {
        if(idx_kline==-1){fprintf(stderr,"[ERROR:] on function update_broker_mewaajacune_klines_interval_symbol : cound't find CANDLE INTERVAL %s...\n", interval);}
        if(idx_scene==-1){fprintf(stderr,"[ERROR:] on function update_broker_mewaajacune_klines_interval_symbol : cound't find SYMBOL %s...\n",symbol);}
        assert(0x00);
    }
}

void broker_update_price_forall_symbols(void *_iicu_wikimyei){
    for(int scene_idx=0x00;scene_idx<MAX_IICU_SCENES;scene_idx++){
        // --- --- --- --- 
        __cwcn_type_t symbol_latest_alliu=(__cwcn_type_t) request_latest_alliu(IICU_SCENES_SYMBOLS[scene_idx]);
        // --- --- --- --- 
        beseech_staticques(_iicu_wikimyei, scene_idx);
        // --- --- --- --- 
        get_staticques(_iicu_wikimyei, scene_idx)->__alliu_latest=symbol_latest_alliu;
        // --- --- --- --- 
        release_staticques(_iicu_wikimyei, scene_idx);
        // --- --- --- --- 
    }
}

void broker_websocket_suscriber(__wsclient_t *c) {
	char *subscribe_str = malloc(1024*sizeof(char));
    char *scenes_str = malloc(1024*sizeof(char));
    char *scene_str = malloc(1024*sizeof(char));
    char *temp_sym = malloc(1024*sizeof(char));
    strcpy(scenes_str,"");
    for(int scene_idx=0x00;scene_idx<MAX_IICU_SCENES;scene_idx++){
        strcpy(temp_sym,IICU_SCENES_SYMBOLS[scene_idx]);
        __cwcn_to_lower(temp_sym);
        sprintf(scene_str,"\"%s@%s\"",temp_sym,BROKER_WEBSOCKET_SUBSCRIBE_TO);
        strcat(scenes_str,scene_str);
        if(scene_idx<MAX_IICU_SCENES-0x01){strcat(scenes_str,",");}
    }
	sprintf(subscribe_str,"{\"method\": \"SUBSCRIBE\",\"params\":[%s],\"id\": 72}",scenes_str);
	fprintf(stdout,"[cuwacunu:websocket] : subscribing to websocket : %s \n",subscribe_str);
	libwsclient_send(c, subscribe_str, -1);
    free(temp_sym);
    free(scene_str);
    free(scenes_str);
	free(subscribe_str);
}

int broker_websocket_on_close(__wsclient_t *c) { // #FIXME attempt to reconect
	fprintf(stderr, "[cuwacunu:websocket] broker_websocket_on_close called: %d\n", c->sockfd);
	// libwsclient_finish(client);
	// int libwsclient_open_connection(const char *host, const char *port) {
	// broker_websocket_suscriber(c); // does not work, maybe add delay
	return 0;
}

int broker_websocket_on_error(__wsclient_t *c, __wsclient_error_t *err) {
	fprintf(stderr, "[%s ERROR %s] : broker_websocket_on_error: (%d): %s\n",COLOR_DANGER,COLOR_REGULAR,err->code, err->str);
	if(err->extra_code) {
		errno = err->extra_code;
		perror("recv");
	}
	return 0;
}

int broker_websocket_on_message(__wsclient_t *c, __wsclient_message_t *msg) {
	char *ch;
	char *sh;
	char *saveptr2;
	char *saveptr1;
	char *partial_str=malloc(strlen(msg->payload)+1);
	strcpy(partial_str,msg->payload);
	ch=strtok_r(partial_str, "{},", &saveptr1);
	if((sh = strstr(ch,"\"result\":null"))!=NULL){
		fprintf(stdout,"[cuwacunu:websocket] conextion stablished : %s\n",msg->payload);
		free(partial_str);
		return 0;
	}
    // --- --- --- --- 
    int c_scene_idx=-1;
    // --- --- --- --- 
    fprintf(stdout,"[cuwacunu:websocket] arriving message : %s\n",msg->payload);
	while(ch!=NULL){
		if((sh = strstr(ch,"\"e\":"))!=NULL){
			sh=strtok_r(sh, "\":", &saveptr2);
			sh=strtok_r(saveptr2, "\":", &saveptr2);
			// fprintf(stdout,"waka : [event type] : %s \n",sh);
		} else if ((sh = strstr(ch,"\"E\":"))!=NULL) {
			sh=strtok_r(sh, "\":", &saveptr2);
			sh=strtok_r(saveptr2, "\":", &saveptr2);
			// fprintf(stdout,"waka : [event time] : %s \n",sh);
		} else if ((sh = strstr(ch,"\"s\":"))!=NULL) {
			sh=strtok_r(sh, "\":", &saveptr2);
			sh=strtok_r(saveptr2, "\":", &saveptr2);
			// fprintf(stdout,"waka : [simbol] : %s \n",sh);
            for(int ctx_symb=0x00;ctx_symb<MAX_IICU_SCENES;ctx_symb++){ // all scenes
                if(strstr(sh,IICU_SCENES_SYMBOLS[ctx_symb])!=NULL){
                    c_scene_idx=ctx_symb;
                    break;
                }
            }
		} else if ((sh = strstr(ch,"\"c\":"))!=NULL) {
			sh=strtok_r(sh, "\":", &saveptr2);
			sh=strtok_r(saveptr2, "\":", &saveptr2);
			// fprintf(stdout,"waka : [close price] : %s \n",sh);
            #if defined(INTERPRET_CURRENT_PRICE_AS_CLOSE_PRICE)
            if(c_scene_idx!=-1){
                beseech_staticques(c->ref_struct, c_scene_idx);
                // --- --- --- --- 
                get_staticques(c->ref_struct, c_scene_idx)->__alliu_latest=strtof(sh,NULL);;
                // --- --- --- --- 
                release_staticques(c->ref_struct, c_scene_idx);
            } else {
                fprintf(stderr, "[ %sERROR! %s] unable to understand broker_websocket_on_message, symbol was not found \n",COLOR_DANGER,COLOR_REGULAR);
            }
            #endif
		} else if ((sh = strstr(ch,"\"o\":"))!=NULL) {
			sh=strtok_r(sh, "\":", &saveptr2);
			sh=strtok_r(saveptr2, "\":", &saveptr2);
			// fprintf(stdout,"waka : [open price] : %s \n",sh);
            #if defined(INTERPRET_CURRENT_PRICE_AS_OPEN_PRICE)
            if(c_scene_idx!=-1){
                beseech_staticques(c->ref_struct, c_scene_idx);
                // --- --- --- --- 
                get_staticques(c->ref_struct, c_scene_idx)->__alliu_latest=strtof(sh,NULL);;
                // --- --- --- --- 
                release_staticques(c->ref_struct, c_scene_idx);
            } else {
                fprintf(stderr, "[ %sERROR! %s] unable to understand broker_websocket_on_message, symbol was not found \n",COLOR_DANGER,COLOR_REGULAR);
            }
            #endif
		} else if ((sh = strstr(ch,"\"h\":"))!=NULL) {
			sh=strtok_r(sh, "\":", &saveptr2);
			sh=strtok_r(saveptr2, "\":", &saveptr2);
			// fprintf(stdout,"waka : [high price] : %s \n",sh);
		} else if ((sh = strstr(ch,"\"l\":"))!=NULL) {
			sh=strtok_r(sh, "\":", &saveptr2);
			sh=strtok_r(saveptr2, "\":", &saveptr2);
			// fprintf(stdout,"waka : [low price] : %s \n",sh);
		} else if ((sh = strstr(ch,"\"v\":"))!=NULL) {
			sh=strtok_r(sh, "\":", &saveptr2);
			sh=strtok_r(saveptr2, "\":", &saveptr2);
			// fprintf(stdout,"waka : [total traded base] : %s \n",sh);
		} else if ((sh = strstr(ch,"\"q\":"))!=NULL) {
			sh=strtok_r(sh, "\":", &saveptr2);
			sh=strtok_r(saveptr2, "\":", &saveptr2);
			// fprintf(stdout,"waka : [total traded quote] : %s \n",sh);
		} else{
			break;
		}
		ch=strtok_r(saveptr1, "{},", &saveptr1);
	}
	free(partial_str);
	return 0;
}

int broker_websocket_on_open(__wsclient_t *c) {
	fprintf(stderr, "[cuwacunu:websocket] broker_websocket_on_open called: [%d]\n", c->sockfd);
	broker_websocket_suscriber(c);
	return 0;
}