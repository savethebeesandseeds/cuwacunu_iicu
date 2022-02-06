/**
 * The MIT License (MIT)
 *
 * Copyright (c) 2021 Waajacu
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
/**
	main.c
	@author waajacu
	@version 0.1
*/
#include "time.h"
#include "stdio.h"
#include <pthread.h>
#ifdef __ANDROID__
#   include "SDL.h"
#   include "SDL_ttf.h"
#   include "android/log.h"
#else
#   include "SDL2/SDL.h"
#   include "SDL2/SDL_ttf.h"
#endif
#include "iicu_assets/plotsdl/sdl_plot.h"
#include "iicu_assets/plotsdl/sdl_plot_linked_list.h"
#include "iicu_assets/sdl_config.h"
#include "iicu_assets/sdl_utils.h"
#include "iicu_assets/threads_config.h"


// void *PrintHello(void*threadid){
//     long tid;
//     tid=(long)threadid;
//     printf("Hello World! It's me, thread #%ld!\n",tid);
//     pthread_exit(NULL);
// }
// int main(intargc,char*argv[]){
//     pthread_tthreads[NUM_THREADS];
//     int rc;
//     long t;
//     for(t=0;t<NUM_THREADS;t++){
//         printf("In main: creating thread%ld\n",t);
//         rc=pthread_create(&threads[t],NULL,PrintHello,(void*)t);
//         if(rc){
//             printf("ERROR; return code from pthread_create() is %d\n",rc);
//             exit(-1);
//         }
//     }
//     pthread_exit(NULL); 
// }
int main(int argc, char* argv[]){
	if(argc!= 2){
		printf( "usage: %s font file name (.ttf)\n", argv[0] );
		return EXIT_FAILURE;
	}
	int ret=0;
	int gameover = SDL_EVENT_CONTINUE;

	float rand_float;
	clock_t begin;
	clock_t end;
	double time_spent;

	splot c_plot;
	SDL_Event event;
	plot_params screen_params;

	//populate plot parameter object
	screen_params=central_plot_config(screen_params);
    
	// --- --- --- --- · --- --- --- --- CAPTION LIST
    //populate caption list
	captionlist caption_list = NULL;
	caption_list=push_back_caption(caption_list,"ETH",0,0x0000FF); // color the point
	caption_list=push_back_caption(caption_list,"BTC",1,0x00FF00); // color the point
    screen_params.caption_list	= caption_list;
	//print_list_caption(caption_list);

	// --- --- --- --- · --- --- --- --- SURFACE
    surfacelist surface_list = NULL;
	
	// --- --- --- --- · --- --- --- --- WINDOW
	SDL_Window *c_screen = SDL_CreateWindow(
		screen_params.plot_window_title,
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		screen_params.screen_width, 
		screen_params.screen_heigth,
		SDL_WINDOW_SHOWN);
	
    // --- --- --- --- · --- --- --- --- PLEASE NENA, PLOT NENA, PLOT!
	ret = make_plot(&c_plot, &screen_params, c_screen);

	if(EXIT_SUCCESS == evaluate_params(&screen_params)){
		while (gameover!=SDL_EVENT_BREAK){
            // --- --- --- --- · --- --- --- --- populate coordinate list
			screen_params.coordinate_list = clear_coord(screen_params.coordinate_list);
			screen_params.coordinate_list = NULL;
			for(int label=0;label<2;label++){
				for(int data_x=0;data_x<=screen_params.max_x;data_x++){
					rand_float=(float)rand()/(float)RAND_MAX*screen_params.max_y;
					screen_params.coordinate_list=push_back_coord(screen_params.coordinate_list,label,data_x,rand_float);
				}
			}
			// print_list_coord(screen_params.coordinate_list);
	        // --- --- --- --- · --- --- --- --- PLOT SUGGAR
			begin = clock();
			ret = update_plot(&c_plot, &screen_params, &surface_list);
			end = clock();
			time_spent = (double)(end-begin) / CLOCKS_PER_SEC;
			printf("[waka] :: time spend :: update_plot :: %f\n",time_spent);
            if (ret == EXIT_FAILURE) {
                printf("[%s] return with status %d\n",screen_params.plot_window_title,ret);
                return EXIT_FAILURE;
            }
			// wait event, manage sdl input events
            // gameover=wait_for_sdl_event(event);
		}
	}
	clean_plot(&c_plot, &screen_params, &surface_list);
	return EXIT_SUCCESS;
}