#include "save_n_load_thread.h"
void load_itsaave_from_state_backup(__iicu_wikimyei_t *_iicu_wikimyei){
    fprintf(stdout,"[%s WARNING %s] : on load_itsaave_from_state_backup assert symbol has not changed. \n",COLOR_WARNING, COLOR_REGULAR);
    // size_t stream_size=0;
    // FILE *dump_stream;
    // // --- --- 
    // __iicu_wikimyei_t *dump_iicu_wikimyei=malloc(sizeof(__iicu_wikimyei_t));
    // memcpy(&dump_iicu_wikimyei,&_iicu_wikimyei,sizeof(__iicu_wikimyei_t));
    // // --- --- 
    // char *dump_str=NULL;
    // dump_stream = open_memstream(&dump_str,&stream_size);
    // fwrite(dump_iicu_wikimyei,sizeof(dump_iicu_wikimyei),1,dump_stream);
    // fread(dump_str,sizeof(dump_iicu_wikimyei),1,dump_stream);
    
    // // fprintf(dump_stream,"%s",dump_str);
    // // int c;
    // // while((c=getc(dump_stream))!=EOF){
    // //     putchar(c);
    // // }
    // // fgets(dump_str,,dump_stream);
    // printf("stream: %s\n",dump_str);
    // // --- --- 
    // SDL_Delay(1000);
    // // --- --- 
    // free(dump_iicu_wikimyei);
    // fclose(dump_stream);






    // --- --- 
    // char *test_file=NULL;
    // size_t stream_size=0;
    // FILE *test_stream;
    // // test_file = fopen("./test_file_wk","w");
    // test_stream = open_memstream(&test_file,&stream_size);
    // fwrite(_iicu_wikimyei,sizeof(*_iicu_wikimyei),1,test_stream);
    // // fclose(test_file);
    // __iicu_wikimyei_t *test_iicu_wikimyei=malloc(sizeof(__iicu_wikimyei_t));
    // getchar();
    // // test_file = fopen("./test_file_wk","r");
    // fread(test_iicu_wikimyei,sizeof(*test_iicu_wikimyei),1,test_stream);
    // fprintf(stdout,"printing_wikimeyi:\n");
    // fprintf(stdout,"%p:\n",_iicu_wikimyei->__obj_sdl);
    // fprintf(stdout,"%p:\n",test_iicu_wikimyei->__obj_sdl);
    // fprintf(stdout,"%d:\n",gcsid(_iicu_wikimyei));
    // fprintf(stdout,"%d:\n",gcsid(test_iicu_wikimyei));
    // fprintf(stdout,"end printing_wikimeyi\n");
    // // fclose(test_file);
    // free(test_iicu_wikimyei);
    
    // FILE *load_file = fopen(ITSAAVE_COOKIE_FILE,"r");
    // FILE *test_file = fopen("test_wk_file","r"); // #FIXME pilas con el check
    // if(load_file!=NULL){
    //     // test_file = fopen("./test_file_wk","w");
    //     test_stream = open_memstream(&test_file,&stream_size);
    //     fwrite(_iicu_wikimyei,sizeof(*_iicu_wikimyei),1,test_stream);
    //     // fclose(test_file);
    //     __iicu_wikimyei_t *test_iicu_wikimyei=malloc(sizeof(__iicu_wikimyei_t *));
    //     // test_file = fopen("./test_file_wk","r");
    //     fread(test_iicu_wikimyei,sizeof(*test_iicu_wikimyei),1,test_stream);
    //     fprintf(stdout,"printing_wikimeyi:\n");
    //     fprintf(stdout,"%p:\n",_iicu_wikimyei->__obj_sdl);
    //     fprintf(stdout,"%p:\n",test_iicu_wikimyei->__obj_sdl);
    //     fprintf(stdout,"%d:\n",gcsid(_iicu_wikimyei));
    //     fprintf(stdout,"%d:\n",gcsid(test_iicu_wikimyei));
    //     fprintf(stdout,"end printing_wikimeyi\n");
    //     // fclose(test_file);
    //     free(test_iicu_wikimyei);
    //     unsigned char *ciphertext=malloc(sizeof(int)*5024);
    //     char *buff=malloc(sizeof(int)*5024);
    //     char *dump_to = malloc(sizeof(int)*5024);
    //     strcpy(dump_to,"");
    //     strcpy(buff,"");
    //     int size_count=0;
    //     while(fgets(buff,5,load_file)){
    //         ciphertext[size_count]=(char)strtol(buff,NULL,0);
    //         size_count++;
    //     }
    //     ciphertext[size_count]='\0';
    //     char *decodedtext = (char *) ciphertext;
    //     RCsi(SAVE_n_LOAD_KEY, decodedtext, ciphertext);
    //     str_hex_decode(dump_to, ciphertext);
    //     fprintf(stdout,"[cuwacunu:save_backup] decoded:%s\n",dump_to);
    //     fclose(load_file);
    //     fclose(test_file);
    //     free(ciphertext);
    //     free(buff);
    //     free(dump_to);
    // } else {
    //     fprintf(stderr,"[cuwacunu:] %sERROR%s, unable to load_itsaave_from_state_backup\n",COLOR_DANGER,COLOR_REGULAR);
    // }

    // --- --- --- 
    FILE *load_file;
    // char *dump_str_itsaave;
    // char *dump_str_pocket;
    char dump_file_name[64];
    // --- --- --- 
    // load all itsaaves and all itsaave_pocket(s)
    // --- --- --- 
    for(int scene_idx=0x00;scene_idx<MAX_IICU_SCENES;scene_idx++){
        beseech_scene_itsaave(_iicu_wikimyei, scene_idx);
        // --- --- scene itsaave
        sprintf(dump_file_name,"%s[%d]",ITSAAVE_COOKIE_FILE,scene_idx);
        // --- --- 
        load_file = fopen(dump_file_name,"r");
        if(load_file!=NULL){
            // --- 
            itsaave_load_from_stream(get_scene_itsaave(_iicu_wikimyei, scene_idx),load_file);
            // --- 
            fclose(load_file);
            // --- 
        } else {
            fprintf(stderr,"[cuwacunu:] %sERROR%s, unable to load_itsaave_from_state_backup [for scene_itsaave[%d]] \n",COLOR_DANGER,COLOR_REGULAR,scene_idx);
        }
        // --- --- scene pocket
        sprintf(dump_file_name,"%s[%d]",POCKET_COOKIE_FILE,scene_idx);
        // --- --- 
        load_file = fopen(dump_file_name,"r");
        if(load_file!=NULL){
            // --- 
            pocket_load_from_stream(get_scene_itsaave(_iicu_wikimyei, scene_idx)->__it_pocket,load_file);
            // --- 
            fclose(load_file);
            // --- 
        } else {
            fprintf(stderr,"[cuwacunu:] %sERROR%s, unable to load_itsaave_from_state_backup [for scene_itsaave[%d]->__it_pocket] \n",COLOR_DANGER,COLOR_REGULAR,scene_idx);
        }
        // --- --- 
        // print_itsaave(get_scene_itsaave(_iicu_wikimyei, scene_idx));
        // --- --- 
        release_scene_itsaave(_iicu_wikimyei, scene_idx);
        // --- --- 
    }
    // --- --- --- save wikimyei itsaave and wikimyei itsaave_pocket
    // --- --- --- 
    beseech_wk_itsaave(_iicu_wikimyei);
    // --- --- --- 
    // --- --- --- wk_itsaave
    sprintf(dump_file_name,"%s[wk]",ITSAAVE_COOKIE_FILE);
    load_file = fopen(dump_file_name,"r");
    if(load_file!=NULL){
        // --- --- 
        itsaave_load_from_stream(get_wk_itsaave(_iicu_wikimyei),load_file);
        // --- --- 
        fclose(load_file);
        // --- --- 
    } else {
        fprintf(stderr,"[cuwacunu:] %sERROR%s, unable to load_itsaave_from_state_backup [for wk_itsaave] \n",COLOR_DANGER,COLOR_REGULAR);
    }
    // --- --- --- 
    // --- --- --- wk_itsaave->__it_pocket
    sprintf(dump_file_name,"%s[wk]",POCKET_COOKIE_FILE);
    load_file = fopen(dump_file_name,"r");
    if(load_file!=NULL){
        // --- --- 
        pocket_load_from_stream(get_wk_itsaave(_iicu_wikimyei)->__it_pocket, load_file);
        // --- --- 
        fclose(load_file);
        // --- --- 
    } else {
        fprintf(stderr,"[cuwacunu:] %sERROR%s, unable to load_itsaave_from_state_backup [for wk_itsaave->__it_pocket] \n",COLOR_DANGER,COLOR_REGULAR);
    }
    // --- --- ---
    // print_itsaave(get_wk_itsaave(_iicu_wikimyei)); 
    release_wk_itsaave(_iicu_wikimyei);
    // --- --- --- 
}
void save_itsaave_from_state_backup(__iicu_wikimyei_t *_iicu_wikimyei){
    // --- --- --- 
    FILE *save_file;
    // char *dump_str_itsaave;
    // char *dump_str_pocket;
    char dump_file_name[64];
    // --- --- --- 
    // save all itsaaves and all itsaave_pocket(s)
    // --- --- --- 
    for(int scene_idx=0x00;scene_idx<MAX_IICU_SCENES;scene_idx++){
        beseech_scene_itsaave(_iicu_wikimyei, scene_idx);
        // --- --- scene itsaave
        sprintf(dump_file_name,"%s[%d]",ITSAAVE_COOKIE_FILE,scene_idx);
        // --- --- 
        save_file = fopen(dump_file_name,"w");
        if(save_file!=NULL){
            // --- #FIXME encrypt 
            itsaave_to_stream(get_scene_itsaave(_iicu_wikimyei, scene_idx),save_file);
            // --- 
            // unsigned char *ciphertext = malloc(sizeof(int) * strlen(dump_str_itsaave));
            // RCsi(SAVE_n_LOAD_KEY, dump_str_itsaave, ciphertext);
            // // --- 
            // for(size_t _i = 0; _i < strlen(dump_str_itsaave); _i++){
            //     fprintf(save_file,"0x%02hhx", ciphertext[_i]);
            // }
            // // --- 
            // free(ciphertext);
            fclose(save_file);
            // --- 
        } else {
            fprintf(stderr,"[cuwacunu:] %sERROR%s, unable to save_itsaave_from_state_backup [for scene_itsaave[%d]] \n",COLOR_DANGER,COLOR_REGULAR,scene_idx);
        }
        // --- --- scene pocket
        sprintf(dump_file_name,"%s[%d]",POCKET_COOKIE_FILE,scene_idx);
        // --- --- 
        save_file = fopen(dump_file_name,"w");
        if(save_file!=NULL){
            // --- 
            pocket_to_stream(get_scene_itsaave(_iicu_wikimyei, scene_idx)->__it_pocket,save_file);
            // --- 
            // unsigned char *ciphertext = malloc(sizeof(int) * strlen(dump_str_pocket));
            // RCsi(SAVE_n_LOAD_KEY, dump_str_pocket, ciphertext);
            // // --- 
            // for(size_t _i = 0; _i < strlen(dump_str_pocket); _i++){
            //     fprintf(save_file,"0x%02hhx", ciphertext[_i]);
            // }
            // // --- 
            // free(ciphertext);
            fclose(save_file);
            // --- 
        } else {
            fprintf(stderr,"[cuwacunu:] %sERROR%s, unable to save_itsaave_from_state_backup [for scene_itsaave[%d]->__it_pocket] \n",COLOR_DANGER,COLOR_REGULAR,scene_idx);
        }
        // --- --- 
        release_scene_itsaave(_iicu_wikimyei, scene_idx);
        // --- --- 
    }
    // --- --- --- save wikimyei itsaave and wikimyei itsaave_pocket
    // --- --- --- 
    beseech_wk_itsaave(_iicu_wikimyei);
    // --- --- --- 
    // --- --- --- wk_itsaave
    sprintf(dump_file_name,"%s[wk]",ITSAAVE_COOKIE_FILE);
    save_file = fopen(dump_file_name,"w");
    if(save_file!=NULL){
        // --- --- 
        itsaave_to_stream(get_wk_itsaave(_iicu_wikimyei),save_file);
        // --- --- 
        // unsigned char *ciphertext = malloc(sizeof(int) * strlen(dump_str_itsaave));
        // RCsi(SAVE_n_LOAD_KEY, dump_str_itsaave, ciphertext);
        // // --- --- 
        // for(size_t _i = 0; _i < strlen(dump_str_itsaave); _i++){
        //     fprintf(save_file,"0x%02hhx", ciphertext[_i]);
        // }
        // // --- --- 
        // free(ciphertext);
        fclose(save_file);
        // --- --- 
    } else {
        fprintf(stderr,"[cuwacunu:] %sERROR%s, unable to save_itsaave_from_state_backup [for wk_itsaave] \n",COLOR_DANGER,COLOR_REGULAR);
    }
    // --- --- --- 
    // --- --- --- wk_itsaave->__it_pocket
    sprintf(dump_file_name,"%s[wk]",POCKET_COOKIE_FILE);
    save_file = fopen(dump_file_name,"w");
    if(save_file!=NULL){
        // --- --- 
        pocket_to_stream(get_wk_itsaave(_iicu_wikimyei)->__it_pocket,save_file);
        // --- --- 
        // unsigned char *ciphertext = malloc(sizeof(int) * strlen(dump_str_pocket));
        // RCsi(SAVE_n_LOAD_KEY, dump_str_pocket, ciphertext);
        // // --- --- 
        // for(size_t _i = 0; _i < strlen(dump_str_pocket); _i++){
        //     fprintf(save_file,"0x%02hhx", ciphertext[_i]);
        // }
        // // --- --- 
        // free(ciphertext);
        fclose(save_file);
        // --- --- 
    } else {
        fprintf(stderr,"[cuwacunu:] %sERROR%s, unable to save_itsaave_from_state_backup [for wk_itsaave->__it_pocket] \n",COLOR_DANGER,COLOR_REGULAR);
    }
    // --- --- --- 
    release_wk_itsaave(_iicu_wikimyei);
    // --- --- --- 
    // char *plaintext="waka--1++1234567890.,abcdefghijklmnopqrstuvwxyz;:ABCDEFGHIJKLMNOPQRSTUVWXYZ{}[]()";
    // unsigned char *ciphertext = malloc(sizeof(int) * strlen(plaintext));
    // RCsi(SAVE_n_LOAD_KEY, plaintext, ciphertext);
    // fprintf(stdout,"[cuwacunu:save_backup] encoded:");
    // for(size_t _i = 0; _i < strlen(plaintext); _i++){
    //     fprintf(stdout,"0x%02hhx", ciphertext[_i]);
    //     fprintf(save_file,"0x%02hhx", ciphertext[_i]);
    // }
    // fprintf(stdout,"\n");
    // fclose(save_file);
    // fclose(test_file);
    // free(ciphertext);
    // } else {
    //     fprintf(stderr,"[cuwacunu:] %sERROR%s, unable to save_itsaave_from_state_backup\n",COLOR_DANGER,COLOR_REGULAR);
    // }
}
void *IICU_save_n_load_thread(void *_iicu_wikimyei){
    fprintf(stdout,"[%s cuwacunu %s:] : start : IICU_save_n_load_thread()\n",COLOR_CUWACUNU,COLOR_REGULAR);
    while(0xFF){
        fprintf(stdout,"[%s cuwacunu %s:] step save & load thread--- ... ---\n",COLOR_CUWACUNU,COLOR_REGULAR);
        Uint32 start_time = SDL_GetTicks();
        save_n_load_loop(_iicu_wikimyei);
        if((SDL_GetTicks()-start_time)<(1000*CLOCK_SAVE_n_LOAD_PERIOD)){
            SDL_Delay((1000*CLOCK_SAVE_n_LOAD_PERIOD)-(SDL_GetTicks()-start_time));
        }
    }
    fprintf(stdout,"[%s cuwacunu %s:] : end : IICU_save_n_load_thread()\n",COLOR_CUWACUNU,COLOR_REGULAR);
    pthread_exit(NULL);
}
