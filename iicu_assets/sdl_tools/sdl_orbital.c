#include "sdl_orbital.h"
void DrawOrbital(sdl_screen_object_t *obj_sdl, char *caption, int32_t centreX, int32_t centreY, int32_t radius, float angle, SDL_Color color){
    int x1=centreX;
    int x2=centreX+(1+ORBITAL_EXCENTRICITY)*radius*0.95;
    int y1=centreY;
    int y2=centreY;

    SDL_SetRenderDrawColor(obj_sdl->renderer,color.r,color.g,color.b,color.a);
    DrawCircle(obj_sdl->renderer, centreX, centreY, radius);
    SDL_RenderDrawLine(obj_sdl->renderer, x1, y1, x2, y2);

    // float tan_angle=2*tanh(angle/180.0);
    // x1=centreX;
    // x2=centreX+cos(6./8.*MATH_PI)*radius*0.95;
    // y1=centreY;
    // y2=centreY-sin(6./8.*MATH_PI)*radius*0.95;
    // SDL_RenderDrawLine(obj_sdl->renderer, x1, y1, x2, y2);
    // y2=centreY+sin(6./8.*MATH_PI)*radius*0.95;
    // SDL_RenderDrawLine(obj_sdl->renderer, x1, y1, x2, y2);

    float dx = radius*cos(angle*MATH_PI/180.0);
    float dy = radius*sin(angle*MATH_PI/180.0);
    x1=centreX-ORBITAL_EXCENTRICITY*dx;
    x2=centreX+(1+ORBITAL_EXCENTRICITY)*dx;
    y1=centreY+ORBITAL_EXCENTRICITY*dy;
    y2=centreY-(1+ORBITAL_EXCENTRICITY)*dy;

    if(dy<0){SDL_SetRenderDrawColor(obj_sdl->renderer,255,0,0,255); // legend item border left
    } else  {SDL_SetRenderDrawColor(obj_sdl->renderer,0,255,0,255);} // legend item border left
    DrawCircle(obj_sdl->renderer, centreX, centreY, ORBITAL_EXCENTRICITY*radius);
    SDL_RenderDrawLine(obj_sdl->renderer, x1, y1, x2, y2);

    // --- DRAW TEXT
    draw_text(caption,
        centreX+(1+ORBITAL_EXCENTRICITY)*radius*1.05,
        centreY-SCREEN_FONT_SIZE,
        color,
        obj_sdl->screen_font,
        obj_sdl->renderer);
}