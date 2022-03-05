#include "sdl_noise_box.h"
void sdl_draw_noise_box(__sdl_screen_object_t *obj_sdl, __iicu_mewaajacune_t *_mewaajacune, __iicu_nijcyota_t *_nijcyota){
    // , char *caption // #ASERTME make no caption.
    // assert(strcpm(caption,"")); // whatever
    // giics(_iicu_wikimyei)-> // gets something called a scene

    // Picture is reported stable.
    sdl_draw_1d_plot(obj_sdl, 
        _mewaajacune, 
        _nijcyota->alliu_index,
        _nijcyota->noise_box_x,
        _nijcyota->noise_box_y,
        _nijcyota->noise_box_w,
        _nijcyota->noise_box_h,
        _nijcyota->line_color,
        _nijcyota->draw_line,
        _nijcyota->draw_perpendicular,
        _nijcyota->draw_dot);
    // still stable after drawing.
    // just drawing... no captions.
}