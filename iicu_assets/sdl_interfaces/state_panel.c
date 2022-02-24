#include "state_panel.h"

void render_state_panel(sdl_screen_object_t *obj_sdl){
    int x_zero = STATE_PANEL_x_ZERO;
    int y_zero = STATE_PANEL_y_ZERO;
    int dx = STATE_PANEL_w_ZERO + 15;
    int dy = 0;
    char *icon_path="";
    int icon_x;
    int icon_y;
    int icon_w=STATE_PANEL_w_ZERO;
    int icon_h=STATE_PANEL_h_ZERO;
    // --- wifi state
    icon_path=STATE_PANEL_WIFI;
    icon_x=x_zero;
    icon_y=y_zero;
    sdl_draw_png(icon_path,icon_x,icon_y,icon_w,icon_h,obj_sdl->renderer);
    if(!obj_sdl->iicu_state.network_is_up){
        negate_icon(obj_sdl, icon_x, icon_y, icon_w, icon_h);
    }
    // --- broker state
    icon_path=STATE_PANEL_BROKER;
    icon_x+=-dx;
    icon_y+=-dy;
    sdl_draw_png(icon_path,icon_x,icon_y,icon_w,icon_h,obj_sdl->renderer);
    if(!obj_sdl->iicu_state.broker_is_up || !obj_sdl->iicu_state.network_is_up){
        negate_icon(obj_sdl, icon_x, icon_y, icon_w, icon_h);
    }
    // --- keyboard state
    icon_path=STATE_PANEL_KEYBOARD;
    icon_x+=-dx;
    icon_y+=-dy;
    sdl_draw_png(icon_path,icon_x,icon_y,icon_w,icon_h,obj_sdl->renderer);
    if(!obj_sdl->iicu_state.keyboard_is_up){
        negate_icon(obj_sdl, icon_x, icon_y, icon_w, icon_h);
    }
    // --- controller state
    icon_path=STATE_PANEL_CONTROLLER;
    icon_x+=-dx;
    icon_y+=-dy;
    sdl_draw_png(icon_path,icon_x,icon_y,icon_w,icon_h,obj_sdl->renderer);
    if(!obj_sdl->iicu_state.controller_is_up){
        negate_icon(obj_sdl, icon_x, icon_y, icon_w, icon_h);
    }
}
void negate_icon(sdl_screen_object_t *obj_sdl,int x, int y, int w, int h){
    SDL_SetRenderDrawColor(obj_sdl->renderer,255,0,0,255);
    sdl_draw_line(obj_sdl->renderer, x, y, x+w, y+h);
    sdl_draw_line(obj_sdl->renderer, x, 1+y, x+w, y+h+1);
    sdl_draw_line(obj_sdl->renderer, x, 2+y, x+w, y+h+2);
}