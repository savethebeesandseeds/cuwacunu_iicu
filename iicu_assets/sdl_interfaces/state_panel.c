#include "state_panel.h"

void render_state_panel(__iicu_wikimyei_t *_iicu_wikimyei){
    int x_zero = STATE_PANEL_x_ZERO;
    int y_zero = STATE_PANEL_y_ZERO;
    int dx = STATE_PANEL_w_ZERO + 15;
    int dy = 0;
    char *icon_path="";
    int icon_x;
    int icon_y;
    int icon_w=STATE_PANEL_w_ZERO;
    int icon_h=STATE_PANEL_h_ZERO;
    // // --- wifi state
    icon_x=x_zero;
    icon_y=y_zero;
    sdl_draw_loaded_texture(_iicu_wikimyei->obj_sdl->renderer,_iicu_wikimyei->iicu_state.network_texture,icon_x,icon_y,icon_w,icon_h);
    if(!_iicu_wikimyei->iicu_state.network_is_up){
        negate_icon(_iicu_wikimyei->obj_sdl->renderer, icon_x, icon_y, icon_w, icon_h);
    }
    // --- broker state
    icon_x+=-dx;
    icon_y+=-dy;
    sdl_draw_loaded_texture(_iicu_wikimyei->obj_sdl->renderer,_iicu_wikimyei->iicu_state.broker_texture,icon_x,icon_y,icon_w,icon_h);
    if(!_iicu_wikimyei->iicu_state.broker_is_up || !_iicu_wikimyei->iicu_state.network_is_up){
        negate_icon(_iicu_wikimyei->obj_sdl->renderer, icon_x, icon_y, icon_w, icon_h);
    }
    // --- keyboard state
    icon_x+=-dx;
    icon_y+=-dy;
    sdl_draw_loaded_texture(_iicu_wikimyei->obj_sdl->renderer,_iicu_wikimyei->iicu_state.keyboard_texture,icon_x,icon_y,icon_w,icon_h);
    if(!_iicu_wikimyei->iicu_state.keyboard_is_up){
        negate_icon(_iicu_wikimyei->obj_sdl->renderer, icon_x, icon_y, icon_w, icon_h);
    }
    // --- controller state
    icon_x+=-dx;
    icon_y+=-dy;
    sdl_draw_loaded_texture(_iicu_wikimyei->obj_sdl->renderer,_iicu_wikimyei->iicu_state.controller_texture,icon_x,icon_y,icon_w,icon_h);
    if(!_iicu_wikimyei->iicu_state.controller_is_up){
        negate_icon(_iicu_wikimyei->obj_sdl->renderer, icon_x, icon_y, icon_w, icon_h);
    }
    // --- fps
    #ifndef __cwcn_CLOCK_THREAD__
    char text_caption[64];
    SDL_Color fps_color={.r=171,.g=255,.b=171};
    sprintf(text_caption,"%d : fps",_iicu_wikimyei->iicu_state.fps);
    sdl_draw_text(
        text_caption,
        STATE_PANEL_x_ZERO - 35,
        STATE_PANEL_h_ZERO + 15,
        fps_color,
        _iicu_wikimyei->obj_sdl->screen_font,
        _iicu_wikimyei->obj_sdl->renderer);
    #endif
    // --- scene
    SDL_Color box_color={.r=71,.g=71,.b=71};
    SDL_Color box_selected_color={.r=171,.g=255,.b=171};
    int box_caption_x=0;
    int box_caption_y=((int)STATE_PANEL_SCENE_BOX_H)*((int)MAX_IICU_SCENES-1);
    for(int sidx=0;sidx<MAX_IICU_SCENES;sidx++){
        sprintf(text_caption,"%s",IICU_SCENES_SYMBOLS[sidx]);
        sdl_draw_box(
            _iicu_wikimyei->obj_sdl->renderer,
            box_caption_x,box_caption_y,
            STATE_PANEL_SCENE_BOX_W,
            STATE_PANEL_SCENE_BOX_H,
            sidx==_iicu_wikimyei->iicu_state.scene_id?box_selected_color:box_color);
        sdl_draw_text(
            text_caption,
            box_caption_x+5,box_caption_y,
            sidx==_iicu_wikimyei->iicu_state.scene_id?box_selected_color:box_color,
            _iicu_wikimyei->obj_sdl->screen_font,
            _iicu_wikimyei->obj_sdl->renderer);
        box_caption_y-=STATE_PANEL_SCENE_BOX_H;
    }
    box_caption_y=((int)STATE_PANEL_SCENE_BOX_H)*((int)MAX_IICU_SCENES-(int)0x01-(int)_iicu_wikimyei->iicu_state.scene_id);
    sdl_draw_box( //redraw selected box
        _iicu_wikimyei->obj_sdl->renderer,
        box_caption_x,box_caption_y,
        STATE_PANEL_SCENE_BOX_W,
        STATE_PANEL_SCENE_BOX_H,
        box_selected_color);
}
void negate_icon(SDL_Renderer *renderer,int x, int y, int w, int h){
    SDL_SetRenderDrawColor(renderer,255,0,0,255);
    sdl_draw_line(renderer, x, y, x+w, y+h);
    sdl_draw_line(renderer, x, 1+y, x+w, y+h+1);
    sdl_draw_line(renderer, x, 2+y, x+w, y+h+2);
}