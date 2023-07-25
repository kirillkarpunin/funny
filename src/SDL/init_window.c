#include "sdl_thing.h"

data* init_window(){

    data* level = malloc(sizeof(data));

    level->win = SDL_CreateWindow("game",
                                       SDL_WINDOWPOS_CENTERED,
                                       SDL_WINDOWPOS_CENTERED,
                                       670, 670, SDL_WINDOW_SHOWN);
    if (!(level->win))
    {
        printf("error creating window: %s\n", SDL_GetError());
        return NULL;
    }

    Uint32 render_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
    level->rend = SDL_CreateRenderer(level->win, -1, render_flags);
    if (!(level->rend))
    {
        printf("error creating renderer: %s\n", SDL_GetError());
        SDL_DestroyWindow(level->win);
        return NULL;
    }

    return level;
}
