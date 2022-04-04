#include "home.h"

void render_home(__sdl_screen_object_t *obj_sdl){
    // --- DRAW central TEXT
    char *caption="CUWACUNU : IICU";
    int captionX=100;
    int captionY=100;
    SDL_Color font_color_1 = {201,251,201};
    sdl_draw_text(caption,captionX,captionY,font_color_1,obj_sdl->home_font,obj_sdl->renderer);
    // --- DRAW mark TEXT
    caption="By Waajacu";
    captionX=350;
    captionY=150;
    SDL_Color font_color_2 = {51,251,51};
    sdl_draw_text(caption,captionX,captionY,font_color_2,obj_sdl->mark_font,obj_sdl->renderer);
    // --- DRAW mark TEXT
    caption="press start |>";
    captionX=500;
    captionY=425;
    SDL_Color font_color_3 = {255,255,255};
    sdl_draw_text(caption,captionX,captionY,font_color_3,obj_sdl->screen_font,obj_sdl->renderer);
    caption="press select |____| (to debug)";
    captionX=500;
    captionY=440;
    SDL_Color font_color_4 = {255,255,255};
    sdl_draw_text(caption,captionX,captionY,font_color_4,obj_sdl->screen_font,obj_sdl->renderer);
}
