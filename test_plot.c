/**
 * The MIT License (MIT)
 *
 * Copyright (c) 2015 Bertrand Martel
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
	testing plot-sdl-lib : create a new SDL window, plot points in a created graph featuring a cartesian coordinate system
	@author Bertrand Martel
	@version 0.1
*/
#include "stdio.h"
#include "time.h"
#include <SDL2/SDL.h>
#include "iicu_assets/plotsdl/sdl_plot.h"
#include "iicu_assets/plotsdl/sdl_plot_linked_list.h"

int main(int argc, char* argv[]){
	if(argc!= 2){
		printf( "usage: %s font file name (.ttf)\n", argv[0] );
		return EXIT_FAILURE;
	}
	int ret=0;
	int gameover = 0;
	float rand_float;
	clock_t begin;
	clock_t end;
	double time_spent;

	splot c_plot;
	SDL_Event   event;
	plot_params screen_params;

	//populate plot parameter object
	screen_params.screen_width=800;
	screen_params.screen_heigth=640;
	screen_params.plot_window_title="plot-sdl";
	screen_params.font_text_path=argv[1];
	screen_params.font_text_size=18;
	screen_params.caption_text_x="Time (s)";
	screen_params.caption_text_y="Speed (Mbit/s)";
	// screen_params.caption_list = caption_list;
	// screen_params.coordinate_list = coordinate_list;
	screen_params.scale_x = 1;
	screen_params.scale_y = 10;
	screen_params.max_x = 1000;
	screen_params.max_y = 120;

	if (ret == EXIT_FAILURE) {
		printf("plot_graph return with status %d\n",ret);
		return EXIT_FAILURE;
	}

	// --- --- --- --- · --- --- --- --- 

	coordlist coordinate_list=NULL;
	surfacelist surface_list = NULL;
	//populate caption list
	captionlist caption_list = NULL;

	caption_list=push_back_caption(caption_list,"Download",0,0x0000FF); // color the point
	caption_list=push_back_caption(caption_list,"Upload"  ,1,0xFF0000); // color the point
	//print_list_caption(caption_list);
	
	ret = make_plot(&c_plot, &screen_params, NULL);
	coordinate_list = clear_coord(coordinate_list);
	if(EXIT_SUCCESS == evaluate_params(&screen_params)){
		while (!gameover){
			if (SDL_PollEvent(&event)){
				switch (event.type){
					case SDL_QUIT:
						gameover = 1;
						break;

				case SDL_KEYDOWN:
					switch (event.key.keysym.sym){
						case SDLK_ESCAPE:
						case SDLK_q:
							gameover = 1;
							break;

					}
					break;
				}
			}
			//populate coordinate list
			coordinate_list = clear_coord(coordinate_list);
			coordinate_list = NULL;
			for(int label=0;label<2;label++){
				for(int data_x=0;data_x<screen_params.max_x;data_x++){
					rand_float=(float)rand()/(float)RAND_MAX*screen_params.max_y;
					coordinate_list=push_back_coord(coordinate_list,label,data_x,rand_float);
					// for(int data_y=0;data_y<9;data_y++){
					// }
				}
			}
			screen_params.caption_list	= caption_list;
			screen_params.coordinate_list	= coordinate_list;
			// print_list_coord(coordinate_list);
			begin = clock();
			ret = update_plot(&c_plot, &screen_params, &surface_list);
			end = clock();
			time_spent = (double)(end-begin) / CLOCKS_PER_SEC;
			printf("[waka] :: time spend :: update_plot :: %f\n",time_spent);

			// break;
		}
	}
	clean_plot(&c_plot, &screen_params, &surface_list);
	
	if (ret == EXIT_FAILURE) {
		printf("plot_graph return with status %d\n",ret);
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}