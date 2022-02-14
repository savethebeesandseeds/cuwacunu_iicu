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
#include "../sdl_tools/sdl_screen.h"
void draw_text(
    char *caption,
    int captionX,
    int captionY,
    SDL_Color font_color,
    TTF_Font *font,
    SDL_Renderer *renderer);
void draw_png(
    char *img_path,
    int x,int y,int w,int h,
    SDL_Renderer *renderer);
void DrawCircle(SDL_Renderer * renderer, int32_t centreX, int32_t centreY, int32_t radius);
#endif