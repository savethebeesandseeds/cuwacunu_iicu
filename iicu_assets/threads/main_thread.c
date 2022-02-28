#include "main_thread.h"

void *IICU_main_thread(void *threadid){
    fprintf(stdout,"[cuwacunu:] : start : IICU_main_thread()\n");
    // --- --- --- --- · --- --- --- --- INITIALIZE
    __iicu_wikimyei_t *c_iicu_wikimyei=iicu_wikimyei_fabric();
    // --- --- --- --- · --- --- --- --- LOADING
    loading_loop(c_iicu_wikimyei);
    // --- --- --- --- · --- --- --- --- HOME
    home_loop(c_iicu_wikimyei);
    // --- --- --- --- · --- --- --- --- MAIN LOOP
    while (0xFF){
        #ifndef __cwcn_CLOCK_THREAD__
        Uint32 start_time = SDL_GetTicks();
    iicu_scene_loop(c_iicu_wikimyei);
        if((SDL_GetTicks()-start_time)<(1000*CLOCK_THREAD_PERIOD)){
            SDL_Delay((1000*CLOCK_THREAD_PERIOD)-(SDL_GetTicks()-start_time));
        }
        c_iicu_wikimyei->iicu_state.fps=(int)((float)1000/((float)(SDL_GetTicks()-start_time)));
        #else 
    iicu_scene_loop(c_iicu_wikimyei);
        #endif
    }
    // --- --- --- --- · --- --- --- --- FINISH
    destroy_iicu_wikimyei(c_iicu_wikimyei);
    fprintf(stdout,"[cuwacunu:] : end : IICU_main_thread()\n");
	pthread_exit(NULL);
}
