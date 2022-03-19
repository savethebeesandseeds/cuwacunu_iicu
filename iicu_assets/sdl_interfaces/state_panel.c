#include "state_panel.h"

void render_state_panel(__iicu_wikimyei_t *_iicu_wikimyei){
    int x_zero = STATE_PANEL_x_ZERO;
    int y_zero = STATE_PANEL_y_ZERO;
    int dx = STATE_PANEL_w_ZERO + 15;
    int dy = 0;
    int icon_x;
    int icon_y;
    int icon_w=STATE_PANEL_w_ZERO;
    int icon_h=STATE_PANEL_h_ZERO;
    // // --- wifi state
    icon_x=x_zero;
    icon_y=y_zero;
    sdl_draw_loaded_texture(_iicu_wikimyei->__obj_sdl->renderer,get_state(_iicu_wikimyei)->network_texture,icon_x,icon_y,icon_w,icon_h);
    if(!get_state(_iicu_wikimyei)->network_is_up){
        negate_icon(_iicu_wikimyei->__obj_sdl->renderer, icon_x, icon_y, icon_w, icon_h);
    }
    // --- broker state
    icon_x+=-dx;
    icon_y+=-dy;
    sdl_draw_loaded_texture(_iicu_wikimyei->__obj_sdl->renderer,get_state(_iicu_wikimyei)->broker_texture,icon_x,icon_y,icon_w,icon_h);
    if(!get_state(_iicu_wikimyei)->broker_is_up || !get_state(_iicu_wikimyei)->network_is_up){
        negate_icon(_iicu_wikimyei->__obj_sdl->renderer, icon_x, icon_y, icon_w, icon_h);
    }
    // --- keyboard state
    icon_x+=-dx;
    icon_y+=-dy;
    sdl_draw_loaded_texture(_iicu_wikimyei->__obj_sdl->renderer,get_state(_iicu_wikimyei)->keyboard_texture,icon_x,icon_y,icon_w,icon_h);
    if(!get_state(_iicu_wikimyei)->keyboard_is_up){
        negate_icon(_iicu_wikimyei->__obj_sdl->renderer, icon_x, icon_y, icon_w, icon_h);
    }
    // --- controller state
    icon_x+=-dx;
    icon_y+=-dy;
    sdl_draw_loaded_texture(_iicu_wikimyei->__obj_sdl->renderer,get_state(_iicu_wikimyei)->controller_texture,icon_x,icon_y,icon_w,icon_h);
    if(!get_state(_iicu_wikimyei)->controller_is_up){
        negate_icon(_iicu_wikimyei->__obj_sdl->renderer, icon_x, icon_y, icon_w, icon_h);
    }
    // --- fps
    #ifndef __cwcn_CLOCK_THREAD__
    char text_caption[64];
    SDL_Color fps_color={.r=171,.g=255,.b=171};
    sprintf(text_caption,"%d : fps",get_state(_iicu_wikimyei)->fps);
    sdl_draw_text(
        text_caption,
        STATE_PANEL_x_ZERO - 35,
        STATE_PANEL_h_ZERO + 15,
        fps_color,
        _iicu_wikimyei->__obj_sdl->screen_font,
        _iicu_wikimyei->__obj_sdl->renderer);
    #endif
    // --- scene boxes
    SDL_Color box_color={.r=71,.g=71,.b=71};
    SDL_Color box_selected_color={.r=171,.g=255,.b=171};
    int box_caption_x=(int)NIJCYOTA_MAIN_BOX_X-(int)STATE_PANEL_SCENE_BOX_W-0x02;
    int box_caption_y=(int)NIJCYOTA_MAIN_BOX_Y+(int)NIJCYOTA_MAIN_BOX_H;
    int selected_box_caption_y=0;
    for(int sidx=0;sidx<MAX_IICU_SCENES;sidx++){
        box_caption_y-=STATE_PANEL_SCENE_BOX_H;
        sprintf(text_caption,"%s",IICU_SCENES_SYMBOLS[sidx]);
        sdl_draw_box(
            _iicu_wikimyei->__obj_sdl->renderer,
            box_caption_x,box_caption_y,
            STATE_PANEL_SCENE_BOX_W,STATE_PANEL_SCENE_BOX_H,
            sidx==gcsid(_iicu_wikimyei)?box_selected_color:box_color);
        sdl_draw_text(
            text_caption,
            box_caption_x+0x05,box_caption_y,
            sidx==gcsid(_iicu_wikimyei)?box_selected_color:box_color,
            _iicu_wikimyei->__obj_sdl->screen_font,
            _iicu_wikimyei->__obj_sdl->renderer);
        selected_box_caption_y=sidx==gcsid(_iicu_wikimyei)?box_caption_y:selected_box_caption_y;
    }
    sdl_draw_box( //redraw selected scene box
        _iicu_wikimyei->__obj_sdl->renderer,
        box_caption_x,selected_box_caption_y,
        STATE_PANEL_SCENE_BOX_W,STATE_PANEL_SCENE_BOX_H,
        box_selected_color);
    // --- klines boxes
    box_caption_x=NIJCYOTA_MAIN_BOX_X+((int)STATE_PANEL_KLINES_BOX_W*((int)BROKER_CANDLE_N_INTERVALS-(int)0x01));
    box_caption_y=(int)NIJCYOTA_MAIN_BOX_Y-(int)2*(int)STATE_PANEL_KLINES_BOX_H;
    for(int kidx=0;kidx<BROKER_CANDLE_N_INTERVALS;kidx++){
        sprintf(text_caption,"%s",BROKER_CANDLE_INTERVALS[kidx]);
        sdl_draw_box(
            _iicu_wikimyei->__obj_sdl->renderer,
            box_caption_x,box_caption_y,
            STATE_PANEL_KLINES_BOX_W,STATE_PANEL_KLINES_BOX_H,
            kidx==gcklid(_iicu_wikimyei)?box_selected_color:box_color);
        sdl_draw_text(
            text_caption,
            box_caption_x+5,box_caption_y,
            kidx==gcklid(_iicu_wikimyei)?box_selected_color:box_color,
            _iicu_wikimyei->__obj_sdl->screen_font,
            _iicu_wikimyei->__obj_sdl->renderer);
        box_caption_x-=STATE_PANEL_KLINES_BOX_W;
    }
    box_caption_x=NIJCYOTA_MAIN_BOX_X+((int)STATE_PANEL_KLINES_BOX_W*((int)BROKER_CANDLE_N_INTERVALS-(int)0x01-(int)gcklid(_iicu_wikimyei)));
    sdl_draw_box( //redraw selected kline box
        _iicu_wikimyei->__obj_sdl->renderer,
        box_caption_x,box_caption_y,
        STATE_PANEL_KLINES_BOX_W,STATE_PANEL_KLINES_BOX_H,
        box_selected_color);
    
}
void negate_icon(SDL_Renderer *renderer,int x, int y, int w, int h){
    SDL_SetRenderDrawColor(renderer,255,0,0,255);
    sdl_draw_line(renderer, x, y, x+w, y+h);
    sdl_draw_line(renderer, x, 1+y, x+w, y+h+1);
    sdl_draw_line(renderer, x, 2+y, x+w, y+h+2);
}