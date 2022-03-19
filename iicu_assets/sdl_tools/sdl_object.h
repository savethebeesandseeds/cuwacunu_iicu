#ifndef __SDL_OBJECT__
#define __SDL_OBJECT__
#include <time.h>
#ifdef __ANDROID__
#	include "SDL.h"
#	include "SDL_ttf.h"
#else
#	include "SDL2/SDL.h"
#	include "SDL2/SDL_ttf.h"
#endif
#include "../config/general_config.h"
//-------------SDL structure  ------------
typedef struct sdl_struct{
	TTF_Font *screen_font;
	TTF_Font *home_font;
	TTF_Font *mark_font;
	SDL_Window *screen;
	SDL_Renderer *renderer;
	SDL_Event event;
} __sdl_screen_object_t;

#include "../config/sdl_config.h"

__sdl_screen_object_t *fabric_obj_sdl();
void destroy_obj_sdl(__sdl_screen_object_t *obj_sdl);
/**
 * @brief initialize_sdl_object
 */
void initialize_sdl_object(__sdl_screen_object_t *obj_sdl);

/**
 * @brief kill_sdl_object
 */
void kill_sdl_object(__sdl_screen_object_t *obj_sdl);

/**
 * @brief step_sdl_object
 */
int step_sdl_object(__sdl_screen_object_t *obj_sdl);

/**
 * @brief draw_sdl_object
 */
int draw_sdl_object(__sdl_screen_object_t *obj_sdl);

#endif