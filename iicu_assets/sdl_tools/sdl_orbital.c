#include "sdl_orbital.h"
void DrawOrbital(sdl_screen_object_t obj_sdl, char *caption, int32_t centreX, int32_t centreY, int32_t radius, float angle, SDL_Color color){
    int x1=centreX;
    int x2=centreX+(1+ORBITAL_EXCENTRICITY)*radius*0.95;
    int y1=centreY;
    int y2=centreY;

    SDL_SetRenderDrawColor(obj_sdl.renderer,color.r,color.g,color.b,color.a);
    DrawCircle(obj_sdl.renderer, centreX, centreY, radius);
    SDL_RenderDrawLine(obj_sdl.renderer, x1, y1, x2, y2);

    // float tan_angle=2*tanh(angle/180.0);
    // x1=centreX;
    // x2=centreX+cos(6./8.*MATH_PI)*radius*0.95;
    // y1=centreY;
    // y2=centreY-sin(6./8.*MATH_PI)*radius*0.95;
    // SDL_RenderDrawLine(obj_sdl.renderer, x1, y1, x2, y2);
    // y2=centreY+sin(6./8.*MATH_PI)*radius*0.95;
    // SDL_RenderDrawLine(obj_sdl.renderer, x1, y1, x2, y2);

    float dx = radius*cos(angle*MATH_PI/180.0);
    float dy = radius*sin(angle*MATH_PI/180.0);
    x1=centreX-ORBITAL_EXCENTRICITY*dx;
    x2=centreX+(1+ORBITAL_EXCENTRICITY)*dx;
    y1=centreY+ORBITAL_EXCENTRICITY*dy;
    y2=centreY-(1+ORBITAL_EXCENTRICITY)*dy;

    if(dy<0){SDL_SetRenderDrawColor(obj_sdl.renderer,255,0,0,255); // legend item border left
    } else  {SDL_SetRenderDrawColor(obj_sdl.renderer,0,255,0,255);} // legend item border left
    DrawCircle(obj_sdl.renderer, centreX, centreY, ORBITAL_EXCENTRICITY*radius);
    SDL_RenderDrawLine(obj_sdl.renderer, x1, y1, x2, y2);

    SDL_Surface *text_caption = TTF_RenderText_Blended(obj_sdl.font, caption, color);
	SDL_Rect text_rect;
	SDL_Texture *caption_texture = SDL_CreateTextureFromSurface(obj_sdl.renderer, text_caption);
	SDL_QueryTexture(caption_texture, NULL, NULL, &text_rect.w, &text_rect.h);
	text_rect.x=centreX+(1+ORBITAL_EXCENTRICITY)*radius*1.05;
	text_rect.y=centreY-SCREEN_FONT_SIZE;
	SDL_RenderCopy(obj_sdl.renderer, caption_texture, NULL, &text_rect);
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