#ifndef __SDL_SCREEN__
#define __SDL_SCREEN__
#ifdef __ANDROID__
#	include "SDL.h"
#	include "SDL_ttf.h"
#else
#	include "SDL2/SDL.h"
#	include "SDL2/SDL_ttf.h"
#endif
#include "sdl_plot_linked_list.h"
//-------------Plot SDL objects structure  ------------
typedef struct plot_struct{
	SDL_Surface *plot_surface; 			// not in use
	SDL_Surface *plot_mask_surface;		// not in use
	SDL_Surface *caption_surface;		// not in use
	SDL_Surface *caption_mask_surface;	// not in use
	SDL_Surface *captionX;
	SDL_Surface *captionY;
	SDL_Texture *textureX;
	SDL_Texture *textureY;

} splot;
//-------------Plot parameter structure  ------------
typedef struct plot_params_struct{
	int plot_x;
	int plot_y;
	int plot_width;
	int plot_heigth;
	char * caption_text_x;
	char * caption_text_y;
	captionlist caption_list;
	coordlist coordinate_list;
	float scale_x;
	float scale_y;
	float max_x;
	float max_y;
	int stroke_width;
	float real_plot_width;
	float real_plot_heigth;
	float real_plot_caption_heigth;
	SDL_Color plot_backgrownd_color;
	SDL_Color screen_backgrownd_color;
	SDL_Color borders_color;
	SDL_Color text_color;
	SDL_Rect plot_zone;
	SDL_Rect plot_position;
	SDL_Rect plot_mask_position;
	SDL_Rect plot_caption_position;
	SDL_Rect plot_caption_mask_position;
	SDL_Rect caption_y_position;

} plot_params;
//-------------SDL structure  ------------
typedef struct sdl_struct{
	splot central_plot;
	plot_params central_plot_params;
	TTF_Font *font;
	SDL_Window *screen;
	SDL_Renderer *renderer;
	SDL_Event event;

} sdl_screen_object_t;
#endif