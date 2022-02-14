#include "sdl_utils.h"
void draw_text(
    char *caption,
    int captionX,
    int captionY,
    SDL_Color font_color,
    TTF_Font *font,
    SDL_Renderer *renderer){
    SDL_Surface *text_caption = TTF_RenderText_Blended(font, caption, font_color);
	SDL_Rect text_rect;
	SDL_Texture *caption_texture = SDL_CreateTextureFromSurface(renderer, text_caption);
	SDL_QueryTexture(caption_texture, NULL, NULL, &text_rect.w, &text_rect.h);
	text_rect.x=captionX;
	text_rect.y=captionY;
	SDL_RenderCopy(renderer, caption_texture, NULL, &text_rect);
}
void draw_png(
    char *img_path,
    int x,int y,int w,int h,
    SDL_Renderer *renderer){
    SDL_Surface *surface = IMG_Load(img_path);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer,surface);
    SDL_FreeSurface(surface);
    SDL_Rect destination;
    destination.x = x;
    destination.y = y;
    destination.w = w;
    destination.h = h;
    SDL_RenderCopy(renderer,texture,NULL,&destination);
}
void DrawCircle(SDL_Renderer * renderer, int32_t centreX, int32_t centreY, int32_t radius){
    const int32_t diameter = (radius * 2);
    int32_t x = (radius - 1);
    int32_t y = 0;
    int32_t tx = 1;
    int32_t ty = 1;
    int32_t error = (tx - diameter);
    while (x >= y){
        //  Each of the following renders an octant of the circle
        SDL_RenderDrawPoint(renderer, centreX + x, centreY - y);
        SDL_RenderDrawPoint(renderer, centreX + x, centreY + y);
        SDL_RenderDrawPoint(renderer, centreX - x, centreY - y); // 
        SDL_RenderDrawPoint(renderer, centreX - x, centreY + y); // 
        SDL_RenderDrawPoint(renderer, centreX + y, centreY - x);
        SDL_RenderDrawPoint(renderer, centreX + y, centreY + x);
        SDL_RenderDrawPoint(renderer, centreX - y, centreY - x);
        SDL_RenderDrawPoint(renderer, centreX - y, centreY + x);

        if (error <= 0){
            ++y;
            error += ty;
            ty += 2;
        }
        if (error > 0){
            --x;
            tx += 2;
            error += (tx - diameter);
        }
    }
}