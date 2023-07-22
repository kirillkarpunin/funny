#include "sdl_thing.h"

SDL_Renderer* draw(SDL_Renderer* rend, map* world){

    SDL_SetRenderDrawColor(rend, 0, 0, 0, 0);
    SDL_RenderClear(rend);

    SDL_Rect sq = {START, START, SQR_SIZE, SQR_SIZE};
    SDL_Rect frame = {START-OFFSET, START-OFFSET, OFFSET+(SQR_SIZE+OFFSET)*world->size, OFFSET+(SQR_SIZE+OFFSET)*world->size};

    SDL_SetRenderDrawColor(rend, 255, 255, 255, 0);
    SDL_RenderDrawRect(rend, &frame);

    coords start = {world->player_coords.x < 3 ? 0 : (world->player_coords.x > world->size-3 ? world->size-5 : world->player_coords.x-2),
                    world->player_coords.y < 3 ? 0 : (world->player_coords.y > world->size-3 ? world->size-5 : world->player_coords.y-2)};
    coords end = {world->player_coords.x < 3 ? 5 : (world->player_coords.x > world->size-3 ? world->size : world->player_coords.x+3),
                  world->player_coords.y < 3 ? 5 : (world->player_coords.y > world->size-3 ? world->size : world->player_coords.y+3)};

    for (int j = start.y; j < end.y; j++)
    {
        for (int i = start.x; i < end.x; i++)
        {
            sq.x = START+(OFFSET+SQR_SIZE)*i;
            sq.y = START+(OFFSET+SQR_SIZE)*j;

            if (world->matrix[i][j] == 0)
            {
                SDL_SetRenderDrawColor(rend, 255, 255, 255, 0);
                SDL_RenderDrawRect(rend, &sq);
            }

            else if (world->matrix[i][j] == 3)
            {
                SDL_SetRenderDrawColor(rend, 255, 0, 0, 0);
                SDL_RenderDrawRect(rend, &sq);
            }

            else if (world->matrix[i][j] == 2)
            {
                SDL_SetRenderDrawColor(rend, 0, 255, 0, 0);
                SDL_RenderDrawRect(rend, &sq);
            }
        }
    }

    SDL_RenderPresent(rend);
    return rend;
}
