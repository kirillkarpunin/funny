#include "sdl_thing.h"

int create_window(map* world){

    if ( !(world->matrix) ) {
        printf("map error\n");
        return 1;
    }

    if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER|SDL_INIT_EVENTS) != 0)
    {
        printf("error initializing SDL: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Window* win;
    SDL_Renderer* rend;

    if (init(&win, &rend)){
        SDL_Quit();
        return 1;
    }

    int close = 0;

    while (!close)
    {
        SDL_Event event;

        while (SDL_PollEvent(&event))
        {
            close = update(world, &event);
            rend = draw(rend, world);
        }
    }

    SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(win);
    SDL_Quit();
    return 0;
}
