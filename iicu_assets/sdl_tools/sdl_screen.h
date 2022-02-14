#ifndef __SDL_SCREEN__
#define __SDL_SCREEN__
#ifdef __ANDROID__
#	include "SDL.h"
#	include "SDL_ttf.h"
#else
#	include "SDL2/SDL.h"
#	include "SDL2/SDL_ttf.h"
#endif
#include <time.h>
#include "sdl_plot_linked_list.h"
//-------------SDL  FLAGs ------------ ------------ ---
typedef struct screen_flags {
	int interface_id;

} screen_flags_t;

typedef struct cwcn_iicu_state {
	int network_is_up;
	clock_t network_last_update;
	int broker_is_up;
	clock_t broker_last_update;
	int keyboard_is_up;
	clock_t keyboard_last_update;
	int controller_is_up;
	clock_t controller_last_update;
} cwcn_iicu_state_t;

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
	TTF_Font *screen_font;
	TTF_Font *home_font;
	TTF_Font *mark_font;
	SDL_Window *screen;
	SDL_Renderer *renderer;
	SDL_Event event;
	screen_flags_t screen_state;
	cwcn_iicu_state_t iicu_state;

} sdl_screen_object_t;

#include "../config/sdl_config.h"
#include "sdl_plot.h"
/**
 * @brief initialize_screen
 */
void initialize_screen(sdl_screen_object_t *obj_sdl);

/**
 * @brief clean_screen
 */
void clean_screen(sdl_screen_object_t *obj_sdl);

/**
 * @brief step_screen
 *      create a new SDL window and plot grap with given parameters
 */
int step_screen(sdl_screen_object_t *obj_sdl);

/**
 * @brief draw_screen
 *      create a new SDL window and plot grap with given parameters
 */
int draw_screen(sdl_screen_object_t *obj_sdl);

#endif