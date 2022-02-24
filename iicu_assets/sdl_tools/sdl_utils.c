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
void sdl_draw_text( //#FIXME correct order
    char *caption,
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
    // ...//#FIXME free surface
}
void sdl_draw_png(
    char *img_path,
    int x,int y,int w,int h,
    SDL_Renderer *renderer){
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
    // ...//#FIXME free surface
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