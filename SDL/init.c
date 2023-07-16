#include "sdl_thing.h"

int init(SDL_Window** ptr_win, SDL_Renderer** ptr_rend){
    *ptr_win = SDL_CreateWindow("game",
                                       SDL_WINDOWPOS_CENTERED,
                                       SDL_WINDOWPOS_CENTERED,
                                       670, 670, SDL_WINDOW_SHOWN);
    if (!(*ptr_win))
    {
        printf("error creating window: %s\n", SDL_GetError());
        return 1;
    }

    Uint32 render_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
    *ptr_rend = SDL_CreateRenderer(*ptr_win, -1, render_flags);
    if (!(*ptr_rend))
    {
        printf("error creating renderer: %s\n", SDL_GetError());
        SDL_DestroyWindow(*ptr_win);
        return 1;
    }

    return 0;
}
