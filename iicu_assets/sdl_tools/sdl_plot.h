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
	plot.h
	create a new SDL window, plot points in a created graph featuring a cartesian coordinate system
	@author Bertrand Martel
	@version 0.1
	@modified by waajacu
*/
#ifndef __SDL_PLOT__
#define __SDL_PLOT__
#ifdef __ANDROID__
#	include "SDL.h"
#	include "SDL_ttf.h"
#	include "android/log.h"
#	define APP_NAME "plot_sdl_impl"
#else
#	include "SDL2/SDL.h"
#	include "SDL2/SDL_ttf.h"
#endif

#include "math.h"
#include "stdio.h"
#include "stdlib.h"
#include "sdl_plot_linked_list.h"

#include "sdl_screen.h"
#include "sdl_utils.h"
#include "../config/sdl_config.h"
/**
 * @brief make_plot
 *      create a new SDL window and plot grap with given parameters
 * @param plot
 *      plot object (cf splot struct)
  * @param params
 *      plot parameters (cf plot_params struct)
 */
void make_plot(splot *plot, plot_params *params);


/**
 * @brief intialize_central_plot
 *      create a new SDL window and plot grap with given parameters
 */
int draw_plot_static_parts(sdl_screen_object_t *obj_sdl);

/**
 * @brief draw_scale_graduation
 *      draw graduation for the graph
 */
void draw_scale_graduation(SDL_Renderer * renderer,
	plot_params *params,
	splot *plot,
	float plot_width,
	float plot_heigth,
	SDL_Rect plot_mask_position,
	TTF_Font *font,
	SDL_Color font_color,
	int plot_position_x,
	int plot_position_y);

/**
 * @brief draw_points
 *      draw each coordinate points on the graph featuring cartesian coordinate system
 * @param renderers
 *      SDL renderer
 * @param caption_item
 *      caption item structure
 * @param params
 *      plot parameters (cf plot_params struct)
 * @param plot_width
 *      plot base width (with proportion to screen width)
 * @param plot_heigth
 *      plot bas heigth (with proportion to screen heigth)
 * @param plot_mask_position
 *      SDL rectangle giving position of plot base (x,y) from max x or max y due to stroke width
 */
void draw_points(SDL_Renderer* renderer,
	caption_item* caption_item,
	plot_params *params,
	float plot_width,
	float plot_heigth,
	SDL_Rect plot_mask_position);

/**
 * @brief draw_plot
 *      create a new SDL window and plot grap with given parameters
 * @param splot
 *      plot containing SDL objects
 * @param params
 *      plot parameters (cf plot_params struct)
 */
void draw_central_plot(sdl_screen_object_t *obj_sdl);

/**
 * @brief clean_plot
 *      full clean of SDL pointers and linked list clear
 */
void clean_plot(splot *plot, plot_params *params);

/**
 * @brief clean_screen
 *      full clean of SDL pointers and linked list clear
 */
void clean_screen(sdl_screen_object_t *obj_sdl);
/*
 * from : http://content.gpwiki.org/index.php/SDL:Tutorials:Drawing_and_Filling_Circles
 * 
 * This is an implementation of the Midpoint Circle Algorithm 
 * found on Wikipedia at the following link:
 *
 *   http://en.wikipedia.org/wiki/Midpoint_circle_algorithm
 *
 * The algorithm elegantly draws a circle quickly, using a
 * set_pixel function for clarity.
 */
void draw_circle(SDL_Renderer *renderer, int n_cx, int n_cy, int radius);

/*
 * from : http://content.gpwiki.org/index.php/SDL:Tutorials:Drawing_and_Filling_Circles
 *
 * SDL_Surface 32-bit circle-fill algorithm without using trig
 *
 * While I humbly call this "Celdecea's Method", odds are that the 
 * procedure has already been documented somewhere long ago.  All of
 * the circle-fill examples I came across utilized trig functions or
 * scanning neighbor pixels.  This algorithm identifies the width of
 * a semi-circle at each pixel height and draws a scan-line covering
 * that width.  
 *
 * The code is not optimized but very fast, owing to the fact that it
 * alters pixels in the provided surface directly rather than through
 * function calls.
 *
 * WARNING:  This function does not lock surfaces before altering, so
 * use SDL_LockSurface in any release situation.
 */
void fill_circle(SDL_Renderer *renderer, int cx, int cy, int radius);
#endif