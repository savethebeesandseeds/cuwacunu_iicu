#include "loading.h"

void render_loading(__iicu_wikimyei_t *_iicu_wikimyei){
    // --- DRAW CENTRAL TEXT
    char *caption=SDL_SCREEN_TITLE;
    int captionX=100;
    int captionY=100;
    SDL_Color font_color_1 = {201,251,201};
    sdl_draw_text(caption,captionX,captionY,font_color_1,
        _iicu_wikimyei->__obj_sdl->home_font,_iicu_wikimyei->__obj_sdl->renderer);
    // --- DRAW mark TEXT
    caption="loading ...";
    captionX=500;
    captionY=425;
    SDL_Color font_color_2 = {51,251,51};
    sdl_draw_text(caption,captionX,captionY,font_color_2,
        _iicu_wikimyei->__obj_sdl->mark_font,_iicu_wikimyei->__obj_sdl->renderer);
}