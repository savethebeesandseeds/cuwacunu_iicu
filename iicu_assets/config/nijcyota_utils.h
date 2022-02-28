#ifndef __NIJCYOTA_CONFIG__
#define __NIJCYOTA_CONFIG__
#include "sdl_config.h"
#include "general_config.h"
//------------- NIJCYOTA ------------ ---------
typedef struct __iicu_nijcyota{
    int nijcyota_index;
    int alliu_index;
    int noise_box_x;
    int noise_box_y;
    int noise_box_w;
    int noise_box_h;
    int data_box_x;
    int data_box_y;
	SDL_Color line_color;
    ___cwcn_bool_t draw_perpendicular;
    ___cwcn_bool_t draw_line;
    ___cwcn_bool_t draw_dot;
	char *orbital_caption;
    int orbital_centreX;
    int orbital_centreY;
    int orbital_radius;
    float orbital_angle;
}__iicu_nijcyota_t;
/* NIJCYOTA FUNKS */
__iicu_nijcyota_t *nijcyota_fabric();
void destroy_nijcyota(__iicu_nijcyota_t *_nijcyota);
void update_iicu_nicjyota(__iicu_nijcyota_t *_nijcyota);
#endif