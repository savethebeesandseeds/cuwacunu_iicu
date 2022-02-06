// #include <stdlib.h>
// #include <stdio.h>
// #include <SDL2/SDL.h>

// int main(int argc, char *argv[]){
//     printf("SDL test\n");
//     return 0;
// }

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
const int WIDTH = 900;
const int HEIGHT = 360;
const int SPRITE_SIZE = 124;

int main(int argc, char *argv[]){
    SDL_Surface *imageSurface = NULL;
    SDL_Surface *windowSurface = NULL;
    SDL_Surface *temp = NULL;
    SDL_Surface *sprite = NULL;
    SDL_Surface *SDL_DisplayFormat(SDL_Surface *surface);
    SDL_Rect    rcSprite;
    SDL_Rect    gdSprite;
    SDL_Event windowEvent;
    SDL_Event   event;
    SDL_Renderer *renderer = NULL;
    SDL_Texture *texture;
    SDL_Texture *spriteTexture;

    const Uint8 *keystate;
    int colorkey;
    int count;
    int xPosition = 0;
    int yPosition = 0;
    int gameover = 0;

    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window *window = SDL_CreateWindow("WINDOW HEADER", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);
    windowSurface = SDL_GetWindowSurface(window);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);

    imageSurface = IMG_Load("./iicu_resources/waacamaya.jpg");
    sprite= IMG_Load("./iicu_resources/waacamaya_c.jpg");

    texture = SDL_CreateTextureFromSurface(renderer, imageSurface);
    spriteTexture = SDL_CreateTextureFromSurface(renderer, sprite);

    SDL_FreeSurface(sprite);
    SDL_FreeSurface(imageSurface);

    //rcSprite used as source rectangle, gdSprite as destination rectangle. Initialize them to the same position
    rcSprite.x = xPosition;
    rcSprite.y = yPosition;
    rcSprite.w = SPRITE_SIZE;
    rcSprite.h = SPRITE_SIZE;

    gdSprite.x = xPosition;
    gdSprite.y = yPosition;
    gdSprite.w = SPRITE_SIZE;
    gdSprite.h = SPRITE_SIZE;
    while (!gameover){
        if (SDL_PollEvent(&event)){
            switch (event.type){
                case SDL_QUIT:
                    gameover = 1;
                    break;

            case SDL_KEYDOWN:
                switch (event.key.keysym.sym){
                    case SDLK_ESCAPE:
                    case SDLK_q:
                        gameover = 1;
                        break;

                }
                break;
            }
        }
        keystate = SDL_GetKeyboardState(NULL);
        // When key pressed, update the destination rectangle
        if (keystate[SDL_SCANCODE_LEFT] ){              gdSprite.x -= 2;                    }
        if (keystate[SDL_SCANCODE_RIGHT]){              gdSprite.x += 2;                    }
        if (keystate[SDL_SCANCODE_UP]   ){              gdSprite.y -= 2;                    }
        if (keystate[SDL_SCANCODE_DOWN] ){              gdSprite.y += 2;                    }
        if (gdSprite.x < 0              ){              gdSprite.x = 0;                     }
        else if (gdSprite.x > WIDTH - SPRITE_SIZE   ){  gdSprite.x = WIDTH - SPRITE_SIZE;   }
        if(gdSprite.y < 0               ){              gdSprite.y = 0;                     }
        else if (gdSprite.y > HEIGHT - SPRITE_SIZE  ){  gdSprite.y = HEIGHT - SPRITE_SIZE;  }
        //Render the window
        SDL_RenderClear(renderer);
        // SDL_RenderCopy(renderer, texture, NULL, NULL);
        // SDL_RenderCopy(renderer, spriteTexture, &rcSprite, &gdSprite);
        SDL_RenderCopy(renderer, spriteTexture, NULL, &gdSprite);
        SDL_RenderPresent(renderer);
        //SDL_BlitSurface(imageSurface, NULL, windowSurface, NULL);
        //SDL_BlitSurface(sprite, NULL, imageSurface, &rcSprite);
        //SDL_UpdateWindowSurface(window);
        //update the source rectangle to move with the sprite??
        rcSprite.x = gdSprite.x;
        rcSprite.y = gdSprite.y;
    }
    SDL_DestroyTexture(spriteTexture);
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}