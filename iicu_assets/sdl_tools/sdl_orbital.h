#ifndef __SDL_ORBITAL__
#define __SDL_ORBITAL__
#ifdef __ANDROID__
#	include "SDL.h"
#	include "SDL_ttf.h"
#	define APP_NAME "plot_sdl_impl"
#else
#	include "SDL2/SDL.h"
#	include "SDL2/SDL_ttf.h"
#endif
#include "sdl_utils.h"
#include "../config/sdl_config.h"
#include "sdl_screen.h"
void DrawOrbital(sdl_screen_object_t obj_sdl, char *caption, int32_t centreX, int32_t centreY, int32_t radius, float angle, SDL_Color color);
void DrawCircle(SDL_Renderer * renderer, int32_t centreX, int32_t centreY, int32_t radius);
#endif