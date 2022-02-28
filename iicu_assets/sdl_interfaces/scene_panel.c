#include "scene_panel.h"
void render_scene_panel(__iicu_wikimyei_t *_iicu_wikimyei){
    // --- --- --- --- · --- --- --- --- auxiliar variables
    float rand_event;
    float orb_angle;
    char orb_caption[256];
    // --- --- --- --- · --- --- --- --- DATA 1
    char aux_caption[512];
    sprintf(aux_caption,"SCENE : %d",_iicu_wikimyei->iicu_state.scene_id);
    sdl_draw_text(aux_caption,
        giicn(_iicu_wikimyei)->data_box_x,
        giicn(_iicu_wikimyei)->data_box_y,
        giicn(_iicu_wikimyei)->line_color,
        _iicu_wikimyei->obj_sdl->screen_font,
        _iicu_wikimyei->obj_sdl->renderer);
    sprintf(aux_caption,"SYMBOL : %s",_iicu_wikimyei->iicu_state.scene_symbol);
    sdl_draw_text(aux_caption,
        giicn(_iicu_wikimyei)->data_box_x,
        giicn(_iicu_wikimyei)->data_box_y+2*SCREEN_FONT_DELTA,
        giicn(_iicu_wikimyei)->line_color,
        _iicu_wikimyei->obj_sdl->screen_font,
        _iicu_wikimyei->obj_sdl->renderer);
    sprintf(aux_caption,"%f",giicn(_iicu_wikimyei)->orbital_angle);
    sdl_draw_text(aux_caption,
        giicn(_iicu_wikimyei)->data_box_x,
        giicn(_iicu_wikimyei)->data_box_y+4*SCREEN_FONT_DELTA,
        giicn(_iicu_wikimyei)->line_color,
        _iicu_wikimyei->obj_sdl->screen_font,
        _iicu_wikimyei->obj_sdl->renderer);
    // // --- --- --- --- · --- --- --- --- PLOT 1
    sdl_draw_noise_box(_iicu_wikimyei->obj_sdl, 
        giicm(_iicu_wikimyei), 
        giicn(_iicu_wikimyei));
    // --- --- --- --- · --- --- --- --- ORBITAL 1
    sdl_draw_1d_orbital(_iicu_wikimyei->obj_sdl, 
        giicm(_iicu_wikimyei), 
        giicn(_iicu_wikimyei));
}