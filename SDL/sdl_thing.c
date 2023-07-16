#include "sdl_thing.h"

int create_window(){

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

    SDL_Rect rect = {START, START, SQR_SIZE, SQR_SIZE};
    SDL_Rect player = {-1, -1, -1, -1};

    int close = 0;

    while (!close)
    {
        SDL_Event event;

        while (SDL_PollEvent(&event))
        {

            if (event.type == SDL_KEYDOWN)
            {
                if (event.key.keysym.sym == SDLK_UP) {
                    rend = draw(rend, &rect, &player, UP);

                } else if (event.key.keysym.sym == SDLK_DOWN) {
                    rend = draw(rend, &rect, &player, DOWN);

                } else if (event.key.keysym.sym == SDLK_LEFT) {
                    rend = draw(rend, &rect, &player, LEFT);

                } else if (event.key.keysym.sym == SDLK_RIGHT) {
                    rend = draw(rend, &rect, &player, RIGHT);

                } else if (event.key.keysym.sym == SDLK_ESCAPE) {
                    close = 1;
                    break;

                } else if (event.key.keysym.sym == SDLK_r) {
                    rect = (SDL_Rect){START, START, SQR_SIZE, SQR_SIZE};
                    player = (SDL_Rect){-1, -1, -1, -1};
                    rend = draw(rend, &rect, &player, 0);
                }
            }

            else if (event.type == SDL_QUIT)
            {
                close = 1;
                break;
            }

            else
            {
                rend = draw(rend, &rect, &player, 0);
            }

            if (!rend) {
                SDL_DestroyWindow(win);
                SDL_Quit();
                return 1;
            }

        }
    }


    SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(win);
    SDL_Quit();
    return 0;
}
