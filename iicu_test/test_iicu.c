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
#ifdef __unix__
#include "unistd.h"
#define __UNIX_OS__
#elif defined(_WIN32) || defined(WIN32)
#define __WIN_OS__
#include "windows.h"
#endif

#include "../iicu_assets/sdl_tools/sdl_screen.h"
#include "../iicu_assets/sdl_tools/sdl_plot.h"
#include "../iicu_assets/sdl_tools/sdl_plot_linked_list.h"
#include "../iicu_assets/sdl_tools/sdl_orbital.h"
#include "../iicu_assets/config/sdl_config.h"
#include "../iicu_assets/config/threads_config.h"
#include "../iicu_assets/sdl_tools/sdl_utils.h"
#include "../iicu_assets/data/data_utils.h"



void *PrintHello(void *threadid){
    long tid;
    tid=(long)threadid;
    while(1){
        printf("Hello World! It's me, thread #%ld!\n",tid);
        #ifdef __UNIX_OS__
        sleep(1);
        #elif defined(__WIN_OS__)
        Sleep(1000);
        #else
        fprintf(stderr,"ERROR, unable to identify operating system\n");
        exit(-1);
        #endif
    }
    pthread_exit(NULL);
}
void *sdl_central_loop(void *threadid){
	clock_t begin;
	clock_t end;
	double time_spent;

    float rand_event;
    float orb_angle;
    char orb_caption[20];
	// --- --- --- --- · --- --- --- --- SCREEN
    sdl_screen_object_t c_obj_sdl;
    c_obj_sdl=initialize_screen(c_obj_sdl);
    SDL_Color orbitalColor={.r = 255, .g = 255, .b = 255, .a = 255};

    // --- --- --- --- · --- --- --- --- LOOP
    while (0xFF){
        // --- --- --- --- · --- --- --- --- populate coordinate list
        c_obj_sdl=populate_central_plot_coordinate_list(c_obj_sdl);
        begin = clock();
        
        // --- --- --- --- · --- --- --- --- PLOT 
        // step_screen(c_obj_sdl);
        step_screen(c_obj_sdl);
        draw_central_plot(c_obj_sdl);
        rand_event=(float)rand()/(float)RAND_MAX;
        orb_angle=(float)rand_event*360.0-180.0;
        sprintf(orb_caption,"orbital :: %f",orb_angle);
        DrawOrbital(c_obj_sdl, orb_caption, 750, 250, 40, orb_angle, orbitalColor);
        rand_event=(float)rand()/(float)RAND_MAX;
        orb_angle=(float)rand_event*360.0-180.0;
        sprintf(orb_caption,"orbital :: %f",orb_angle);
        DrawOrbital(c_obj_sdl, orb_caption, 750, 350, 40, orb_angle, orbitalColor);
        // DrawCircle(c_obj_sdl.renderer, 250, 250, 30);
        // DrawCircle(c_obj_sdl.renderer, 250, 250, 20);
        // DrawCircle(c_obj_sdl.renderer, 250, 250, 10);
        // DrawCircle(c_obj_sdl.renderer, 250, 250, 5);
        draw_screen(c_obj_sdl);
        end = clock();
        time_spent = (double)(end-begin) / CLOCKS_PER_SEC;
        printf("[waka] :: update screen :: fps :: %f\n",1/time_spent);
        
        wait_for_sdl_event(c_obj_sdl);
    }
	clean_plot(&c_obj_sdl.central_plot, &c_obj_sdl.central_plot_params);
    clean_screen(c_obj_sdl);
    pthread_exit(NULL);
}

int main(int argc, char* argv[]){
    pthread_t threads[1];
    int rc;
    long t;
    rc=pthread_create(&threads[0],NULL,sdl_central_loop,(void*)1);
    if(rc){
        printf("ERROR; return code from pthread_create() is %d\n",rc);
        exit(-1);
    }
    for(t=1;t<1;t++){
        printf("In main: creating thread%ld\n",t);
        rc=pthread_create(&threads[t],NULL,PrintHello,(void*)t);
        if(rc){
            printf("ERROR; return code from pthread_create() is %d\n",rc);
            exit(-1);
        }
    }
    pthread_exit(NULL);
	return EXIT_SUCCESS;
}
