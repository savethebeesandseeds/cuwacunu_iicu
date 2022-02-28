#include "sdl_utils.h"
void launch_step_event(){
    SDL_Event sdlevent = {};
    sdlevent.type = SDL_KEYDOWN;
    sdlevent.key.keysym.sym = SDLK_q;
    SDL_PushEvent(&sdlevent);
}
void sdl_draw_line(
    SDL_Renderer *renderer,
    int x1,
    int y1,
    int x2,
    int y2){
    SDL_RenderDrawLine(renderer, x1, y1, x2, y2); //#FIXME assert free surface
}
void sdl_draw_box(
    SDL_Renderer *renderer,
    int box_x,
    int box_y,
    int box_w,
    int box_h,
    SDL_Color box_color){
    SDL_SetRenderDrawColor(renderer,box_color.r,box_color.g,box_color.b,box_color.a);
    sdl_draw_line(renderer, box_x, box_y, box_x+box_w, box_y);
    sdl_draw_line(renderer, box_x, box_y, box_x, box_y+box_h);
    sdl_draw_line(renderer, box_x+box_w, box_y, box_x+box_w, box_y+box_h);
    sdl_draw_line(renderer, box_x, box_y+box_h, box_x+box_w, box_y+box_h);//... use fill rectangle and assert memory alocation
}
void sdl_draw_text( //#FIXME correct arguments order
    const char *caption,
    int captionX,
    int captionY,
    SDL_Color font_color,
    TTF_Font *font,
    SDL_Renderer *renderer){
    SDL_Surface *text_caption = TTF_RenderText_Blended(font, caption, font_color);
	SDL_Rect text_rect;
	SDL_Texture *caption_texture = SDL_CreateTextureFromSurface(renderer, text_caption);
	SDL_QueryTexture(caption_texture, NULL, NULL, &text_rect.w, &text_rect.h);
	text_rect.x=captionX;
	text_rect.y=captionY;
	SDL_RenderCopy(renderer, caption_texture, NULL, &text_rect);
    // ...//#FIXME assert if free surface
    SDL_FreeSurface(text_caption);
    SDL_DestroyTexture(caption_texture);
}

// void clear_string(char *string_to_clear){
//     memset(string_to_clear,0,strlen(string_to_clear));
//     string_to_clear[0]='\0';
// }
// void print_text_color_format(text_color_format_t *_tcf){
//     fprintf(stdout,"_tcf->text_splace: %d\n",_tcf->text_splace);
//     fprintf(stdout,"_tcf->text_fplace: %d\n",_tcf->text_fplace);
//     fprintf(stdout,"_tcf->text_remaining: %s\n",_tcf->text_remaining);
//     fprintf(stdout,"_tcf->text_to_draw: %s\n",_tcf->text_to_draw);
//     fprintf(stdout,"_tcf->gcf->color_text: %s\n",_tcf->gcf->color_text);
// }
// int capture_text_color(char *remaining_caption, text_color_format_t *_tcf, gcolor_format_t *_gcf){
//     if(strlen(remaining_caption)!=0 && strstr(remaining_caption,_gcf->color_text)!=NULL){
//         int aux_fplace =(int)(strlen(remaining_caption)-strlen(strstr(remaining_caption,_gcf->color_text)));
//         if((text_fplace-strlen(_gcf->color_text)) <= 0x00){
//             _tcf->text_fplace=aux_fplace;
//             _tcf->text_splace=__cwcn_max((int) (_tcf->text_fplace-strlen(_gcf->color_text)), (int) 0x00);
//             _tcf->gcf->color_text=_gcf->color_text;
//             _tcf->gcf->text_color.r=_gcf->text_color.r;
//             _tcf->gcf->text_color.g=_gcf->text_color.g;
//             _tcf->gcf->text_color.b=_gcf->text_color.b;
//             memcpy(_tcf->text_to_draw,&remaining_caption[_tcf->text_splace],_tcf->text_fplace-_tcf->text_splace);
//             strcpy(_tcf->text_remaining,&remaining_caption[_tcf->text_fplace]);
//             return 1; // a text change was detected
//         } else {
//             return 0;
//         }
//     }
//     return 0;
// }
// int determine_text_color_format(char *remaining_caption, text_color_format_t *_tcf){
//     gcolor_format_t *test_gcolor_format=malloc(sizeof(gcolor_format_t));
//     test_gcolor_format->color_text=COLOR_L_GOOD;test_gcolor_format->text_color.r=COLOR_R_L_GOOD;test_gcolor_format->text_color.g=COLOR_G_L_GOOD;test_gcolor_format->text_color.b=COLOR_B_L_GOOD;
//     if(capture_text_color(remaining_caption, _tcf, test_gcolor_format)){free(test_gcolor_format);return 1;}
//     test_gcolor_format->color_text=COLOR_GOOD;test_gcolor_format->text_color.r=COLOR_R_GOOD;test_gcolor_format->text_color.g=COLOR_G_GOOD;test_gcolor_format->text_color.b=COLOR_B_GOOD;
//     if(capture_text_color(remaining_caption, _tcf, test_gcolor_format)){free(test_gcolor_format);return 1;}
//     test_gcolor_format->color_text=COLOR_L_DANGER;test_gcolor_format->text_color.r=COLOR_R_L_DANGER;test_gcolor_format->text_color.g=COLOR_G_L_DANGER;test_gcolor_format->text_color.b=COLOR_B_L_DANGER;
//     if(capture_text_color(remaining_caption, _tcf, test_gcolor_format)){free(test_gcolor_format);return 1;}
//     test_gcolor_format->color_text=COLOR_DANGER;test_gcolor_format->text_color.r=COLOR_R_DANGER;test_gcolor_format->text_color.g=COLOR_G_DANGER;test_gcolor_format->text_color.b=COLOR_B_DANGER;
//     if(capture_text_color(remaining_caption, _tcf, test_gcolor_format)){free(test_gcolor_format);return 1;}
//     test_gcolor_format->color_text=COLOR_L_WARNING;test_gcolor_format->text_color.r=COLOR_R_L_WARNING;test_gcolor_format->text_color.g=COLOR_G_L_WARNING;test_gcolor_format->text_color.b=COLOR_B_L_WARNING;
//     if(capture_text_color(remaining_caption, _tcf, test_gcolor_format)){free(test_gcolor_format);return 1;}
//     test_gcolor_format->color_text=COLOR_WARNING;test_gcolor_format->text_color.r=COLOR_R_WARNING;test_gcolor_format->text_color.g=COLOR_G_WARNING;test_gcolor_format->text_color.b=COLOR_B_WARNING;
//     if(capture_text_color(remaining_caption, _tcf, test_gcolor_format)){free(test_gcolor_format);return 1;}
//     free(test_gcolor_format);
//     return 0;
// }
// void sdl_draw_standar_color_text(
//     const char *caption,
//     int captionX,
//     int captionY,
//     int captionDX,
//     TTF_Font *font,
//     SDL_Renderer *renderer){
//     text_color_format_t *c_tcf=malloc(sizeof(text_color_format_t));
//     c_tcf->gcf=malloc(sizeof(gcolor_format_t));
//     c_tcf->text_splace=-1;
//     c_tcf->text_fplace=-1;
//     c_tcf->gcf->color_text=COLOR_REGULAR;
//     c_tcf->gcf->text_color.r=COLOR_R_REGULAR;
//     c_tcf->gcf->text_color.g=COLOR_G_REGULAR;
//     c_tcf->gcf->text_color.b=COLOR_B_REGULAR;
//     strcpy(c_tcf->text_remaining,caption);
//     while(strlen(c_tcf->text_remaining)!=0){
//         fprintf(stdout,"waka SdTART: %s\n",c_tcf->text_remaining);
//         if(!determine_text_color_format(c_tcf->text_remaining, c_tcf)){
//             sdl_draw_text(c_tcf->text_to_draw,captionX,captionY,c_tcf->gcf->text_color,font,renderer);
//         }
//         printf("remaining_caption -> %s \n",remaining_caption);
//         print_text_color_format(_tcf);
//         if(){
            
//         }
//         getchar();
//     }
//     fprintf(stdout,"waka END: %s\n",c_tcf->text_remaining);
//     free(c_tcf->gcf);
//     free(c_tcf);
// }
void sdl_draw_loaded_texture(SDL_Renderer * renderer,SDL_Texture *texture,int x,int y,int w,int h){
    SDL_Rect destination;
    destination.x = x;
    destination.y = y;
    destination.w = w;
    destination.h = h;
    SDL_RenderCopy(renderer,texture,NULL,&destination);
}
void sdl_draw_png( // very SLOW
    char *img_path,
    int x,int y,int w,int h,
    SDL_Renderer *renderer){
    printf("[WARNING:] sdl_draw_png is very slow of a method, use sdl_draw_loaded_texture instead.\n");
    SDL_Surface *surface = IMG_Load(img_path);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer,surface);
    SDL_FreeSurface(surface);
    SDL_Rect destination;
    destination.x = x;
    destination.y = y;
    destination.w = w;
    destination.h = h;
    SDL_RenderCopy(renderer,texture,NULL,&destination);
    SDL_DestroyTexture(texture);
}
void sdl_draw_circle(SDL_Renderer * renderer, int32_t centreX, int32_t centreY, int32_t radius){
    const int32_t diameter = (radius * 2);
    int32_t x = (radius - 1);
    int32_t y = 0;
    int32_t tx = 1;
    int32_t ty = 1;
    int32_t error = (tx - diameter);
    while (x >= y){
        //  Each of the following renders an octant of the circle
        SDL_RenderDrawPoint(renderer, centreX + x, centreY - y);
        SDL_RenderDrawPoint(renderer, centreX + x, centreY + y);
        SDL_RenderDrawPoint(renderer, centreX - x, centreY - y); // 
        SDL_RenderDrawPoint(renderer, centreX - x, centreY + y); // 
        SDL_RenderDrawPoint(renderer, centreX + y, centreY - x);
        SDL_RenderDrawPoint(renderer, centreX + y, centreY + x);
        SDL_RenderDrawPoint(renderer, centreX - y, centreY - x);
        SDL_RenderDrawPoint(renderer, centreX - y, centreY + x);

        if (error <= 0){
            ++y;
            error += ty;
            ty += 2;
        }
        if (error > 0){
            --x;
            tx += 2;
            error += (tx - diameter);
        }
    }
    // ...//#FIXME free surface
}

/*
 * from : http://content.gpwiki.org/index.php/SDL:Tutorials:Drawing_and_Filling_Circles
 *
 * SDL_Surface 32-bit circle-fill algorithm without using trig
 *
 * While I humbly call this "Celdecea's Method", odds are that the 
 * procedure has already been documented somewhere long ago.  All of
 * the circle-fill examples I came across utilized trig functions or
 * scanning neighbor pixels.  This algorithm identifies the width of
 * a semi-circle at each pixel height and draws a scan-line covering
 * that width.  
 *
 * The code is not optimized but very fast, owing to the fact that it
 * alters pixels in the provided surface directly rather than through
 * function calls.
 *
 * WARNING:  This function does not lock surfaces before altering, so
 * use SDL_LockSurface in any release situation.
 */
void sdl_draw_filled_circle(SDL_Renderer *renderer, int cx, int cy, int radius)
{
	// Note that there is more to altering the bitrate of this 
	// method than just changing this value.  See how pixels are
	// altered at the following web page for tips:
	//   http://www.libsdl.org/intro.en/usingvideo.html
	// static const int BPP = 4;
	
	// SDL_LockSurface(surface); #FIXME find what surfaces are it talking about
	/* Surface is locked */

	double r = (double)radius;

	double dy = 0;

	/* Direct pixel access on surface here */
	for (dy = 1; dy <= r; dy += 1.0)
	{
		// This loop is unrolled a bit, only iterating through half of the
		// height of the circle.  The result is used to draw a scan line and
		// its mirror image below it.

		// The following formula has been simplified from our original.  We
		// are using half of the width of the circle because we are provided
		// with a center and we need left/right coordinates.

		double dx = floor(sqrt((2.0 * r * dy) - (dy * dy)));
		int x = cx - dx;

		for (; x <= cx + dx; x++)
		{
			SDL_RenderDrawPoint(renderer,x,((int)(cy + r - dy)));
			SDL_RenderDrawPoint(renderer,x,((int)(cy - r + dy)));
		}
	}

	/* Surface is unlocked */
	// SDL_UnlockSurface(surface); #FIXME find what surfaces are it talking about 
    // ...//#FIXME free surface
}