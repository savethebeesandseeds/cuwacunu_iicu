#ifndef __SDL_UTILS__
#define __SDL_UTILS__
#include "../config/general_config.h"
#include "../config/sdl_config.h"
#include "../sdl_tools/sdl_object.h"
typedef struct gcolor_format {
    char color_text[512];
    SDL_Color text_color;
}gcolor_format_t;
typedef struct text_color_format {
    int text_splace;
    int text_fplace;
    char text_remaining[512];
    char text_to_draw[512];
    gcolor_format_t gcf;
}text_color_format_t;

void launch_step_event();
// void clear_string(char *string_to_clear);
// void print_text_color_format(text_color_format_t *_tcf);
// int capture_text_color(
//     char *remaining_caption, 
//     text_color_format_t *_tcf, 
//     gcolor_format_t *_gcf);
// int determine_text_color_format(
//     char *remaining_caption, 
//     text_color_format_t *_tcf);
// void sdl_draw_standar_color_text(
//     const char *caption,
//     int captionX,
//     int captionY,
//     int captionDX,
//     TTF_Font *font,
//     SDL_Renderer *renderer);
void sdl_draw_text(
    const char *caption,
    int captionX,
    int captionY,
    SDL_Color font_color,
    TTF_Font *font,
    SDL_Renderer *renderer);
void sdl_draw_box(
    SDL_Renderer *renderer,
    int box_x,
    int box_y,
    int box_w,
    int box_h,
    SDL_Color box_color);
void sdl_draw_loaded_texture(SDL_Renderer * renderer,SDL_Texture *texture,int x,int y,int w,int h);
void sdl_draw_line(
    SDL_Renderer *renderer,
    int x1,
    int y1,
    int x2,
    int y2);
void sdl_draw_png(
    char *img_path,
    int x,int y,int w,int h,
    SDL_Renderer *renderer);
void sdl_draw_circle(SDL_Renderer * renderer, int32_t centreX, int32_t centreY, int32_t radius);
void sdl_draw_filled_circle(SDL_Renderer *renderer, int cx, int cy, int radius);
#endif