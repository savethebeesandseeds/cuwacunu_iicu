#include "main_thread.h"

void *IICU_main_thread(void *threadid){
    fprintf(stdout,"[cuwacunu:] : start : IICU_main_thread()\n");
    // --- --- --- --- · --- --- --- --- INITIALIZE
    // __mewaajacune_t *c_mewaajacune=mewaajacune_fabric();
    sdl_screen_object_t obj_sdl;
    initialize_sdl_object(&obj_sdl);
    // --- --- --- --- · --- --- --- --- LOADING
    loading_loop(&obj_sdl);
    // --- --- --- --- · --- --- --- --- STATE
    initialize_iicu_state(&obj_sdl);
    initialize_iicu_scene(&obj_sdl);
    // --- --- --- --- · --- --- --- --- HOME
    home_loop(&obj_sdl);
    // --- --- --- --- · --- --- --- --- MAIN LOOP
    while (0xFF){
        iicu_scene_loop(&obj_sdl);
    }
    // --- --- --- --- · --- --- --- --- FINISH
	kill_all_iicu_scenes(&obj_sdl);
	kill_sdl_object(&obj_sdl);
    pthread_exit(NULL);
    fprintf(stdout,"[cuwacunu:] : end : IICU_main_thread()\n");
}
