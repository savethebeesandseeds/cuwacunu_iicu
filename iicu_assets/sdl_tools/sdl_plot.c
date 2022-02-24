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
	plot.c
	create a new SDL window, plot points in a created graph featuring a cartesian coordinate system
	@author Bertrand Martel
	@version 0.1
	@modified by waajacu
*/
#include "sdl_plot.h"
void make_splot(sdl_screen_object_t *obj_sdl, int sceen_index){
    // --- --- --- --- 
	splot_t *cplot = &obj_sdl->iicu_scene[sceen_index].central_plot;
	splot_params_t *cplot_params = &cplot->splot_params;
	// --- --- sPLOT
    cplot->renderer         	= obj_sdl->renderer;
    cplot->screen_font         	= obj_sdl->screen_font;
    cplot->plot_surface			= NULL;
	cplot->plot_mask_surface	= NULL;
	cplot->caption_surface	    = NULL;
	cplot->caption_mask_surface	= NULL;
	cplot->captionX	            = NULL;
	cplot->captionY	            = NULL;
	cplot->textureX	            = NULL;
	cplot->textureY	            = NULL;
	// --- --- sPlot_params
    cplot_params->stroke_width=2;
    cplot_params->plot_width=600;
	cplot_params->plot_heigth=300;
    cplot_params->plot_x=100;
    cplot_params->plot_y=100;

    cplot_params->real_plot_width=cplot_params->plot_width*0.8;
	cplot_params->real_plot_heigth=cplot_params->plot_heigth*0.8;
	cplot_params->real_plot_caption_heigth=cplot_params->plot_heigth*0.05;
    // --- --- x,y
	cplot_params->caption_text_x="Time (s)";
	cplot_params->caption_text_y="Price";
	cplot_params->scale_x = 1;
	cplot_params->scale_y = 1;
	cplot_params->max_x = 10;
	cplot_params->max_y = 10;
    // #FIXME add dot size
    // --- --- data
    cplot_params->coordinate_list=NULL;         // left blank
    cplot_params->caption_list=NULL;            // left blank
    cplot_params->caption_list=push_back_caption(
		cplot_params->caption_list,"ONE",0,0x0000FF); // color the point
	cplot_params->caption_list=push_back_caption(
		cplot_params->caption_list,"TWO",1,0x00FF00); // color the point
    // --- --- colors
    cplot_params->plot_backgrownd_color.r=0;
    cplot_params->plot_backgrownd_color.g=0;
    cplot_params->plot_backgrownd_color.b=0;
    cplot_params->plot_backgrownd_color.a=255;

    // cplot_params->screen_backgrownd_color=...;
    // cplot_params->borders_color=...;
    // cplot_params->text_color=...;
    // --- --- --- --- shape
    cplot_params->plot_zone.x=cplot_params->plot_x;
	cplot_params->plot_zone.y=cplot_params->plot_y;
	cplot_params->plot_zone.w=cplot_params->plot_width;
	cplot_params->plot_zone.h=cplot_params->plot_heigth;

	cplot_params->plot_position.x=
		cplot_params->plot_zone.x+
		(cplot_params->plot_width/2)-
		(cplot_params->plot_width*0.47);
	cplot_params->plot_position.y=
		cplot_params->plot_zone.y+
		(cplot_params->plot_heigth*0.50)-
		(cplot_params->plot_heigth/2);
	cplot_params->plot_position.w=cplot_params->real_plot_width;
	cplot_params->plot_position.h=cplot_params->real_plot_heigth;

	cplot_params->plot_mask_position.x=
		cplot_params->plot_position.x-cplot_params->stroke_width;
	cplot_params->plot_mask_position.y=
		cplot_params->plot_position.y-cplot_params->stroke_width;
	cplot_params->plot_mask_position.w=
		cplot_params->real_plot_width+cplot_params->stroke_width*2;
	cplot_params->plot_mask_position.h=
		cplot_params->real_plot_heigth+cplot_params->stroke_width*2;

	cplot_params->plot_caption_position.x=cplot_params->plot_position.x;
	cplot_params->plot_caption_position.y=cplot_params->plot_position.y-15-cplot_params->real_plot_caption_heigth;
	cplot_params->plot_caption_position.w=cplot_params->real_plot_width;
	cplot_params->plot_caption_position.h=cplot_params->real_plot_caption_heigth;

	cplot_params->plot_caption_mask_position.x=cplot_params->plot_caption_position.x-cplot_params->stroke_width;
	cplot_params->plot_caption_mask_position.y=cplot_params->plot_caption_position.y-cplot_params->stroke_width;
	cplot_params->plot_caption_mask_position.w=cplot_params->real_plot_width+cplot_params->stroke_width*2;
	cplot_params->plot_caption_mask_position.h=cplot_params->real_plot_caption_heigth+cplot_params->stroke_width*2;

	cplot_params->caption_y_position.x=cplot_params->plot_position.x;
	cplot_params->caption_y_position.y=cplot_params->plot_position.y;

	fprintf(stdout,"[cuwacunu:] : data : make_splot() :: %d, %d, %d, %d\n",cplot->splot_params.plot_backgrownd_color.r,
		cplot->splot_params.plot_backgrownd_color.g,
		cplot->splot_params.plot_backgrownd_color.b,
		cplot->splot_params.plot_backgrownd_color.a);
}
/**
 * @brief draw_plot_static_parts
 *      create a new SDL window and plot grap with given parameters
 */
void draw_plot_static_parts(splot_t *cplot){

	//------------ texts -----------------------
	SDL_Color font_color = {255,255,255}; // outside screen labels and scales color
	cplot->captionX = TTF_RenderText_Blended(cplot->screen_font, cplot->splot_params.caption_text_x, font_color);
	cplot->captionY = TTF_RenderText_Blended(cplot->screen_font, cplot->splot_params.caption_text_y, font_color);

	//------------ background-----------------------
	SDL_SetRenderDrawColor(cplot->renderer,0,0,0,255); // outside plot area (labels, caption, backgrownd) color
	SDL_RenderFillRect(cplot->renderer, &cplot->splot_params.plot_zone);

	SDL_SetRenderDrawColor(cplot->renderer,255, 255, 255,255); // plot screen border
	SDL_RenderFillRect(cplot->renderer,&cplot->splot_params.plot_mask_position);

	SDL_SetRenderDrawColor(cplot->renderer,0, 0, 0,255); // plot screen backgrownd
	SDL_RenderFillRect(cplot->renderer,&cplot->splot_params.plot_position);

	SDL_SetRenderDrawColor(cplot->renderer,0, 0, 0,255); // legend screen border 
	SDL_RenderFillRect(cplot->renderer,&cplot->splot_params.plot_caption_mask_position);

	SDL_SetRenderDrawColor(cplot->renderer,0, 0, 0,255); // legend screen backgrownd
	SDL_RenderFillRect(cplot->renderer,&cplot->splot_params.plot_caption_position);

}


/**
 * @brief draw_central_plot
 * @param splot_t
 *      plot containing SDL objects
 */
void draw_central_plot(splot_t *cplot){
	//---------------------------------------------
	SDL_Color font_color= {171,171,171}; // outside screen labels and scales color
	draw_plot_static_parts(cplot);
	draw_scale_graduation(cplot->renderer,
		&cplot->splot_params,
		cplot,
		cplot->splot_params.real_plot_width,
		cplot->splot_params.real_plot_heigth,
		cplot->splot_params.plot_mask_position,
		cplot->screen_font,
		font_color,
		cplot->splot_params.plot_position.x,
		cplot->splot_params.plot_position.y);

	if (cplot->splot_params.caption_list!=NULL){
		caption_item *tmp = cplot->splot_params.caption_list;

		if (tmp!=NULL){
			int caption_offset=CAPTION_MARGIN;

			while(tmp != NULL){
				//plot cercle1
				int circle_x1=cplot->splot_params.plot_caption_mask_position.x+caption_offset;
				int circle_y1=cplot->splot_params.plot_caption_mask_position.y+cplot->splot_params.real_plot_caption_heigth/2+cplot->splot_params.stroke_width;

				SDL_SetRenderDrawColor(cplot->renderer,0,0,0,255); // legend item border left
				fill_circle(cplot->renderer,circle_x1,circle_y1,DOT_PLOT_RADIUS);

				SDL_SetRenderDrawColor(cplot->renderer,
					(tmp->caption_color & 0xFF0000)>>16, 
					(tmp->caption_color & 0x00FF00)>>8,
					tmp->caption_color & 0x0000FF,255); // legent item sphere left 

				fill_circle(cplot->renderer,circle_x1,circle_y1,DOT_PLOT_RADIUS-2);

				//plot cercle2
				caption_offset+=40;

				int circle_x2=cplot->splot_params.plot_caption_mask_position.x+caption_offset;
				int circle_y2=circle_y1;

				SDL_SetRenderDrawColor(cplot->renderer,0,0,0,255); // legend item border right
				fill_circle(cplot->renderer,circle_x2,circle_y2,DOT_PLOT_RADIUS);

				SDL_SetRenderDrawColor(cplot->renderer,
					(tmp->caption_color & 0xFF0000)>>16, 
					(tmp->caption_color & 0x00FF00)>>8,
					tmp->caption_color & 0x0000FF,255); // legent item sphere right

				fill_circle(cplot->renderer,circle_x2,circle_y2,DOT_PLOT_RADIUS-2);

				//draw line between two circles
				sdl_draw_line(cplot->renderer,circle_x1+DOT_PLOT_RADIUS+1,circle_y1,circle_x2-DOT_PLOT_RADIUS-1,circle_y2);

				//display caption
				SDL_Surface *caption_text_surface = TTF_RenderText_Blended(cplot->screen_font, tmp->caption_txt, font_color);
				SDL_Rect caption_text;
				SDL_Texture * texture_text = SDL_CreateTextureFromSurface(cplot->renderer, caption_text_surface);
				SDL_QueryTexture(texture_text, NULL, NULL, &caption_text.w, &caption_text.h);
				caption_text.x=circle_x2+DOT_PLOT_RADIUS+CAPTION_OFFSET_CIRCLE_TO_TEXT;
				caption_text.y=circle_y2-caption_text.h/2;
				SDL_RenderCopy(cplot->renderer, texture_text, NULL, &caption_text);

				caption_offset+=caption_text.w+DOT_PLOT_RADIUS+CAPTION_OFFSET_CIRCLE_TO_TEXT+CAPTION_OFFSET_DELIMITER;

				draw_points(cplot->renderer,
					tmp,
					&cplot->splot_params,
					cplot->splot_params.real_plot_width,
					cplot->splot_params.real_plot_heigth,
					cplot->splot_params.plot_mask_position);
				
				tmp = tmp->nxt;
			}
		}
	}
	// draw_sdl_object(cplot); // here the render is updated
	#ifdef __ANDROID__
	__android_log_print(ANDROID_LOG_VERBOSE,APP_NAME,"plot finished");
	#endif	
}
/**
 * @brief draw_points
 *      draw each coordinate points on the graph featuring cartesian coordinate system
 * @param renderers
 *      SDL renderer object
 * @param caption_item
 *      caption item object structure
 * @param params
 *      plot parameters (cf splot_params_t struct)
 * @param plot_width
 *      plot base width (with proportion to screen width)
 * @param plot_heigth
 *      plot bas heigth (with proportion to screen heigth)
 * @param plot_mask_position
 *      SDL rectangle giving position of plot base (x,y) from max x or max y due to stroke width
 */
void draw_points(
	SDL_Renderer* renderer,
	caption_item* caption_item,
	splot_params_t *params,
	float plot_width,
	float plot_heigth,
	SDL_Rect plot_mask_position)
{
	coordinate_item* tmp=params->coordinate_list;

	float scale_x_num=plot_width/(params->max_x/params->scale_x);
	float scale_y_num=plot_heigth/(params->max_y/params->scale_y);

	unsigned char isFirst=1;

	float previous_x=0;
	float previous_y=0;

	while (tmp!=NULL)
	{
		if (tmp->caption_id==caption_item->caption_id)
		{
			float circle_x1=plot_mask_position.x+1+(tmp->x/params->scale_x)*scale_x_num;
			float circle_y1=plot_mask_position.y+plot_heigth-(tmp->y/params->scale_y)*scale_y_num;

			SDL_SetRenderDrawColor(renderer,0,0,0,255); // plot screen point border

			fill_circle(renderer,circle_x1,circle_y1,DOT_PLOT_RADIUS);

			SDL_SetRenderDrawColor(renderer,
				(caption_item->caption_color & 0xFF0000)>>16, 
				(caption_item->caption_color & 0x00FF00)>>8,
				caption_item->caption_color & 0x0000FF,255); // plot screen color point inside

			fill_circle(renderer,circle_x1,circle_y1,DOT_PLOT_RADIUS-2);

			if (!isFirst)
			{
				sdl_draw_line(renderer,previous_x,previous_y,circle_x1,circle_y1);
			}

			previous_x=circle_x1;
			previous_y=circle_y1;

			if (isFirst)
			{
				isFirst=0;
			}
		}
		tmp=tmp->nxt;
	}
}

/**
 * @brief draw_scale_graduation
 *      draw graduation for the graph
 * @param renderer
 *      SDL renderer object
 * @param params
 *      plot parameters (cf splot_params_t struct)
 * @param plot
 *      structure containing textures and surfaces
 * @param plot_width
 *      plot base width (with proportion to screen width)
 * @param plot_heigth
 *      plot bas heigth (with proportion to screen heigth)
 * @param plot_mask_position
 *      SDL rectangle giving position of plot base (x,y) from max x or max y due to stroke width
 * @param font
 *      SDL font used for captions
 * @param font_color
 *      font color to be used
 * @param plot_position_x
 *      x position of plot
 * @param plot_position_y
 *      y position of plot
 */
void draw_scale_graduation(SDL_Renderer * renderer,
	splot_params_t *params,
	splot_t *plot,
	float plot_width,
	float plot_heigth,
	SDL_Rect plot_mask_position,
	TTF_Font *font,
	SDL_Color font_color,
	int plot_position_x,
	int plot_position_y){

	int scale_x_num=plot_width/(params->max_x/params->scale_x);
	int scale_y_num=plot_heigth/(params->max_y/params->scale_y);

	int init_pos_x=plot_mask_position.x+1;
	int init_pos_y=plot_mask_position.y+plot_heigth+1;

	int current_scale=0;

	int point_number_x=(params->max_x/params->scale_x);

	int i = 0;

	int regular_caption_text_heigth=0;
	int regular_caption_text_width=0;

	for (i = 0; i< point_number_x+1;i++){

		SDL_SetRenderDrawColor(renderer,255,255,255,255); // plot screen X scale lines 
		sdl_draw_line(renderer,init_pos_x,init_pos_y,init_pos_x,init_pos_y-GRADUATION_HEIGTH);

		char text[10];
		sprintf(text,"%d",current_scale);

		SDL_Surface *caption_text_surface = TTF_RenderText_Blended(font, text, font_color);
		SDL_Rect caption_text;
		SDL_Texture * texture_text = SDL_CreateTextureFromSurface(renderer, caption_text_surface);
		SDL_QueryTexture(texture_text, NULL, NULL, &caption_text.w, &caption_text.h);
		caption_text.x=init_pos_x-caption_text.w/2;
		caption_text.y=init_pos_y+5;
		SDL_RenderCopy(renderer, texture_text, NULL, &caption_text);

		init_pos_x+=scale_x_num;
		current_scale+=params->scale_x;

		regular_caption_text_heigth=caption_text.h;
	}

	current_scale=0;
	init_pos_x=plot_mask_position.x+1;
	init_pos_y=plot_mask_position.y+plot_heigth+2;

	for (i = 0; i< (params->max_y/params->scale_y)+1;i++){

		SDL_SetRenderDrawColor(renderer,255,255,255,255); // plot screen X scale lines
		sdl_draw_line(renderer,init_pos_x,init_pos_y,init_pos_x+GRADUATION_HEIGTH,init_pos_y);

		char text[10];
		sprintf(text,"%d",current_scale);

		SDL_Surface *caption_text_surface = TTF_RenderText_Blended(font, text, font_color);
		SDL_Rect caption_text;
		SDL_Texture * texture_text = SDL_CreateTextureFromSurface(renderer, caption_text_surface);
		SDL_QueryTexture(texture_text, NULL, NULL, &caption_text.w, &caption_text.h);
		caption_text.x=init_pos_x-caption_text.w-10;
		caption_text.y=init_pos_y-caption_text.h/2;
		SDL_RenderCopy(renderer, texture_text, NULL, &caption_text);

		init_pos_y-=scale_y_num;

		current_scale+=params->scale_y;

		regular_caption_text_width=caption_text.w;
	}

	//caption y
	SDL_Rect text_caption_y;
	plot->textureY = SDL_CreateTextureFromSurface(renderer, plot->captionY);
	SDL_QueryTexture(plot->textureY, NULL, NULL, &text_caption_y.w, &text_caption_y.h);
	text_caption_y.x=-1*regular_caption_text_width;
	text_caption_y.y=plot_mask_position.y+plot_heigth/1+text_caption_y.w/4;

	//rotate caption y
	SDL_Point caption_center={plot_position_x-CAPTION_Y_LABEL_OFFSET,0};
	SDL_RendererFlip flip = SDL_FLIP_HORIZONTAL | SDL_FLIP_VERTICAL;
	SDL_RenderCopyEx(renderer,plot->textureY,NULL,&text_caption_y,90,&caption_center,flip);

	//caption x
	SDL_Rect text_caption_x;
	plot->textureX = SDL_CreateTextureFromSurface(renderer, plot->captionX);
	SDL_QueryTexture(plot->textureX, NULL, NULL, &text_caption_x.w, &text_caption_x.h);
	text_caption_x.x=params->plot_width*2/3-text_caption_x.w/2;
	text_caption_x.y=plot_position_y+plot_heigth+1*regular_caption_text_heigth;
	SDL_RenderCopy(renderer, plot->textureX, NULL, &text_caption_x);
}

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
void draw_circle(SDL_Renderer *renderer, int n_cx, int n_cy, int radius)
{
	// if the first pixel in the screen is represented by (0,0) (which is in sdl)
	// remember that the beginning of the circle is not in the middle of the pixel
	// but to the left-top from it:
 
	double error = (double)-radius;
	double x = (double)radius -0.5;
	double y = (double)0.5;
	double cx = n_cx - 0.5;
	double cy = n_cy - 0.5;
 
	while (x >= y)
	{
		SDL_RenderDrawPoint(renderer, (int)(cx + x), (int)(cy + y));
		SDL_RenderDrawPoint(renderer, (int)(cx + y), (int)(cy + x));
 
		if (x != 0)
		{
			SDL_RenderDrawPoint(renderer, (int)(cx - x), (int)(cy + y));
			SDL_RenderDrawPoint(renderer, (int)(cx + y), (int)(cy - x));
		}
 
		if (y != 0)
		{
			SDL_RenderDrawPoint(renderer, (int)(cx + x), (int)(cy - y));
			SDL_RenderDrawPoint(renderer, (int)(cx - y), (int)(cy + x));
		}
 
		if (x != 0 && y != 0)
		{
			SDL_RenderDrawPoint(renderer, (int)(cx - x), (int)(cy - y));
			SDL_RenderDrawPoint(renderer, (int)(cx - y), (int)(cy - x));
		}
 
		error += y;
		++y;
		error += y;
 
		if (error >= 0)
		{
			--x;
			error -= x;
			error -= x;
		}
	}
}

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
void fill_circle(SDL_Renderer *renderer, int cx, int cy, int radius)
{
	// Note that there is more to altering the bitrate of this 
	// method than just changing this value.  See how pixels are
	// altered at the following web page for tips:
	//   http://www.libsdl.org/intro.en/usingvideo.html
	// static const int BPP = 4;

	double r = (double)radius;

	double dy = 0;

	for (dy = 1; dy <= r; dy += 1.0)
	{
		// This loop is unrolled a bit, only iterating through half of the
		// height of the circle.  The result is used to draw a scan line and
		// its mirror image below it.

		// The following formula has been simplified from our original.  We
		// are using half of the width of the circle because we are provided
		// with a center and we need left/right coordinates.

		double dx = floor(sqrt((2.0 * r * dy) - (dy * dy)));
		int x = cx - dx;

		for (; x <= cx + dx; x++)
		{
			SDL_RenderDrawPoint(renderer,x,((int)(cy + r - dy)));
			SDL_RenderDrawPoint(renderer,x,((int)(cy - r + dy)));
		}
	}
}
