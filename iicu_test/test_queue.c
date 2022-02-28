#ifdef __ANDROID__
#	include "SDL.h"
#	include "SDL_ttf.h"
#	include "android/log.h"
#	define APP_NAME "plot_sdl_impl"
#else
#	include "SDL2/SDL.h"
#	include "SDL2/SDL_ttf.h"
#endif
// #include "../iicu_assets/data/mewaajacune_utils.c"
// #include "../iicu_assets/config/general_config.h"
// #include "../iicu_assets/sdl_tools/sdl_object.h"
#include "../iicu_assets/iicu/iicu_loops.h"
#include "../iicu_assets/sdl_tools/sdl_plot_queue.h"
#include "../iicu_assets/config/threads_config.h"
int main(int argc, char* argv[]){
    clock_t begin;
	clock_t end;
	double time_spent;
    // --- --- --- --- · --- --- --- --- INITIALIZE
    __sdl_screen_object_t c_obj_sdl;
    initialize_sdl_object(&c_obj_sdl);
    // --- --- --- --- · --- --- --- --- LOADING
    // loading_loop(&c_obj_sdl);
    // --- --- --- --- · --- --- --- --- PLOTTING
    __iicu_mewaajacune_t *c_mewaajacune=mewaajacune_fabric();
    __iicu_nijcyota_t *c_nijcyota=nijyota_fabric();

    while(0x01){
        Uint32 start_time = SDL_GetTicks();
        begin = clock();
        test_populate_alliu(c_mewaajacune);
        end = clock();
        time_spent = (double)(end-begin) / CLOCKS_PER_SEC;
        printf("[waka] :: time spend populating queue :: %f [s]\n",time_spent);
        begin = clock();
        // load_print_up_trayectory_queue(c_mewaajacune);
        step_sdl_object(&c_obj_sdl);
        sdl_draw_1d_plot(c_obj_sdl, c_mewaajacune, c_nijcyota);
        // --- --- DRAW VERTICAL LINES
        // --- --- DRAW HORIZONTAL LINES
        // sdl_draw_line(
        //     c_obj_sdl.renderer,
        //     box_x,
        //     box_y+,
        //     box_x+box_w,
        //     box_y+);
        draw_sdl_object(&c_obj_sdl);
        end = clock();
        time_spent = (double)(end-begin) / CLOCKS_PER_SEC;
        printf("[waka] :: time spend drawing plot :: %f [s]\n",time_spent);
        if((SDL_GetTicks()-start_time)<(1000*CLOCK_THREAD_PERIOD)){
            SDL_Delay((1000*CLOCK_THREAD_PERIOD)-(SDL_GetTicks()-start_time));
        }
        printf("[waka] :: fps : %f\n",((float)1000)/((float)(SDL_GetTicks()-start_time)));
        miss_or_catch_sdl_event(&c_obj_sdl);
    }
    wait_for_sdl_event(&c_obj_sdl);
    // home_loop(&c_obj_sdl);
    destroy_mewaajacune(c_mewaajacune);
    free(c_plot_params);

	return EXIT_SUCCESS;
}
