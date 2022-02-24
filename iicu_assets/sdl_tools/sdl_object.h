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
#include "../config/general_config.h"
//-------------SDL  FLAGs ------------ ------------ ---
typedef struct cwcn_iicu_state {
	int network_is_up;
	double network_last_update; // seconds since Jan 1, 1970
	int broker_is_up;
	double broker_last_update; // seconds since Jan 1, 1970
	int keyboard_is_up;
	double keyboard_last_update; // seconds since Jan 1, 1970
	int controller_is_up;
	double controller_last_update; // seconds since Jan 1, 1970
	
	int interface_id;
	int scene_id;
	int scene_count;
	
} cwcn_iicu_state_t;

//-------------Plot parameter structure  ------------
typedef struct plot_params {
	int plot_x;
	int plot_y;
	int plot_width;
	int plot_heigth;
	char * caption_text_x;
	char * caption_text_y;
	captionlist_t caption_list;
	coordlist_t coordinate_list;
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

} splot_params_t;
//-------------Plot SDL objects structure  ------------
typedef struct plot_struct{
	TTF_Font *screen_font; // pointer referenced to the same screen_font as in sdl_screen_object_t
	SDL_Renderer *renderer; // pointer referenced to the same renderer as in sdl_screen_object_t
	SDL_Surface *plot_surface; 			// not in use
	SDL_Surface *plot_mask_surface;		// not in use
	SDL_Surface *caption_surface;		// not in use
	SDL_Surface *caption_mask_surface;	// not in use
	SDL_Surface *captionX;
	SDL_Surface *captionY;
	SDL_Texture *textureX;
	SDL_Texture *textureY;
	splot_params_t splot_params;

} splot_t;

typedef struct iicu_scene_struct {
	splot_t central_plot;
} iicu_scene_struct_t;

//-------------SDL structure  ------------
typedef struct sdl_struct{
	TTF_Font *screen_font;
	TTF_Font *home_font;
	TTF_Font *mark_font;
	SDL_Window *screen;
	SDL_Renderer *renderer;
	SDL_Event event;
	cwcn_iicu_state_t iicu_state;
	iicu_scene_struct_t iicu_scene[MAX_IICU_SCREENS];
} sdl_screen_object_t;

#include "../config/sdl_config.h"
#include "sdl_plot.h"
#include "../sdl_interfaces/iicu_scene.h"
/**
 * @brief initialize_sdl_object
 */
void initialize_sdl_object(sdl_screen_object_t *obj_sdl);

/**
 * @brief kill_sdl_object
 */
void kill_sdl_object(sdl_screen_object_t *obj_sdl);

/**
 * @brief step_sdl_object
 */
int step_sdl_object(sdl_screen_object_t *obj_sdl);

/**
 * @brief draw_sdl_object
 */
int draw_sdl_object(sdl_screen_object_t *obj_sdl);

/**
 * @brief draw_plot
 */
coordlist_t get_coordinate_list(splot_t *cplot);
#endif