#include "sdl_thing.h"

SDL_Renderer* draw(SDL_Renderer* rend, map* world){

    SDL_SetRenderDrawColor(rend, 0, 0, 0, 0);
    SDL_RenderClear(rend);

    SDL_Rect sq = {START, START, SQR_SIZE, SQR_SIZE};

    for (int j = 0; j < world->size; j++)
    {
        for (int i = 0; i < world->size; i++)
        {
            if (world->matrix[i][j] == 0)
            {
                SDL_SetRenderDrawColor(rend, 255, 255, 255, 0);
                SDL_RenderDrawRect(rend, &sq);
                sq.x += (OFFSET+SQR_SIZE);
            }

            else if (world->matrix[i][j] == 1)
            {
                sq.x += (OFFSET+SQR_SIZE);
            }

            else
            {
                SDL_SetRenderDrawColor(rend, 0, 255, 0, 0);
                SDL_RenderDrawRect(rend, &sq);
                sq.x += (OFFSET+SQR_SIZE);
            }
        }

        sq.x = START;
        sq.y += (OFFSET+SQR_SIZE);
    }

    SDL_RenderPresent(rend);
    return rend;
}
