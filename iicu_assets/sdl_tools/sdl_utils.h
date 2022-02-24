#ifndef __SDL_UTILS__
#define __SDL_UTILS__
#ifdef __ANDROID__
#	include "SDL.h"
#	include "SDL_ttf.h"
#	include "SDL_image.h"
#else
#	include "SDL2/SDL.h"
#	include "SDL2/SDL_ttf.h"
#	include "SDL2/SDL_image.h"
#endif
#include "../sdl_tools/sdl_object.h"
void launch_step_event();
void sdl_draw_text(
    char *caption,
    int captionX,
    int captionY,
    SDL_Color font_color,
    TTF_Font *font,
    SDL_Renderer *renderer);
void sdl_draw_line(
    SDL_Renderer *renderer,
    int x1,
    int y1,
    int x2,
    int y2);
void sdl_draw_png(
    char *img_path,
    int x,int y,int w,int h,
    SDL_Renderer *renderer);
void sdl_draw_circle(SDL_Renderer * renderer, int32_t centreX, int32_t centreY, int32_t radius);
void sdl_draw_filled_circle(SDL_Renderer *renderer, int cx, int cy, int radius);
#endif