#include "main_thread.h"

void main_case_launch(__iicu_wikimyei_t *_iicu_wikimyei){
    // --- --- --- --- · --- --- --- --- 
    switch(get_state(_iicu_wikimyei)->__scene_case_button){
    // --- --- --- --- · --- --- --- --- 
    case BUTTON_START:
    // --- --- --- --- · --- --- --- --- 
        iicu_scene_loop(_iicu_wikimyei);
    // --- --- --- --- · --- --- --- --- 
        break;
    // --- --- --- --- · --- --- --- --- 
    case BUTTON_SELECT:
    // --- --- --- --- · --- --- --- --- 
        iicu_debug_loop(_iicu_wikimyei);
    // --- --- --- --- · --- --- --- --- 
        break;
    // --- --- --- --- · --- --- --- --- 
    default:
    // --- --- --- --- · --- --- --- --- 
        break;
    // --- --- --- --- · --- --- --- --- 
    }
    // --- --- --- --- · --- --- --- --- 
}

void *IICU_main_thread(void *_iicu_wikimyei){
    fprintf(stdout,"[%s cuwacunu %s:] : start : IICU_main_thread()\n",COLOR_CUWACUNU,COLOR_REGULAR);
    // --- --- --- --- · --- --- --- --- LOADING
    loading_loop((__iicu_wikimyei_t*)_iicu_wikimyei);
    // --- --- --- --- · --- --- --- --- HOME
    home_loop((__iicu_wikimyei_t*)_iicu_wikimyei);
    // --- --- --- --- · --- --- --- --- MAIN LOOP
    while (0xFF){
        #ifndef __cwcn_CLOCK_THREAD__
        Uint32 start_time = SDL_GetTicks();
        #endif
        // --- --- --- --- · --- --- --- 
        main_case_launch(_iicu_wikimyei);
        // --- --- --- --- · --- --- --- 
        #ifndef __cwcn_CLOCK_THREAD__
        if((SDL_GetTicks()-start_time)<(1000*CLOCK_THREAD_PERIOD)){SDL_Delay((1000*CLOCK_THREAD_PERIOD)-(SDL_GetTicks()-start_time));}
        ((__iicu_wikimyei_t*)_iicu_wikimyei)->__iicu_state->fps=(float)((float)1000/((float)(SDL_GetTicks()-start_time)));
        #endif
    }
    // --- --- --- --- · --- --- --- --- FINISH
    destroy_iicu_wikimyei((__iicu_wikimyei_t*)_iicu_wikimyei); // #FIXME never acessed
    // --- --- --- --- · --- --- --- --- 
    fprintf(stdout,"[%s cuwacunu %s:] : end : IICU_main_thread()\n",COLOR_CUWACUNU,COLOR_REGULAR);
    // --- --- --- --- · --- --- --- --- 
	pthread_exit(NULL);
    // --- --- --- --- · --- --- --- --- 
}
