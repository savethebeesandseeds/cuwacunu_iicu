#include "loading.h"

void render_loading(sdl_screen_object_t *obj_sdl){
    // --- 
    obj_sdl->screen_state.interface_id=LOADING_STATE_ID;
    // --- DRAW CENTRAL TEXT
    char *caption="CUWACUNU : IICU";
    int captionX=100;
    int captionY=100;
    SDL_Color font_color_1 = {201,251,201};
    draw_text(caption,captionX,captionY,font_color_1,obj_sdl->home_font,obj_sdl->renderer);
    // --- DRAW mark TEXT
    caption="loading ...";
    captionX=500;
    captionY=425;
    SDL_Color font_color_2 = {51,251,51};
    draw_text(caption,captionX,captionY,font_color_2,obj_sdl->mark_font,obj_sdl->renderer);
    // --- DRAW mark TEXT
    // caption="loading ...";
    // captionX=500;
    // captionY=425;
    // SDL_Color font_color_3 = {255,255,255};
    // draw_text(caption,captionX,captionY,font_color_3,obj_sdl->screen_font,obj_sdl->renderer);
}
