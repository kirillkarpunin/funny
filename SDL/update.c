#include "sdl_thing.h"

int update(map* world, SDL_Event* event){

    int i = world->player_coords.x;
    int j = world->player_coords.y;

    switch (event->type)
    {
        case SDL_KEYDOWN:
        {
            switch (event->key.keysym.sym)
            {
                case SDLK_UP:
                {
                    if (j > 0 && world->matrix[i][j-1] != 0){
                        world->matrix[i][j] = 1;

                        world->player_coords = (coords){i, j-1};
                        world->matrix[i][j-1] = 2;
                    }

                    return 0;

                }

                case SDLK_DOWN:
                {
                    if (j < world->size-1 && world->matrix[i][j+1] != 0){
                        world->matrix[i][j] = 1;

                        world->player_coords = (coords){i, j+1};
                        world->matrix[i][j+1] = 2;
                    }

                    return 0;
                }

                case SDLK_LEFT:
                {
                    if (i > 0 && world->matrix[i-1][j] != 0){
                        world->matrix[i][j] = 1;

                        world->player_coords = (coords){i-1, j};
                        world->matrix[i-1][j] = 2;
                    }

                    return 0;
                }

                case SDLK_RIGHT:
                {
                    if (i < world->size-1 && world->matrix[i+1][j] != 0){
                        world->matrix[i][j] = 1;

                        world->player_coords = (coords){i+1, j};
                        world->matrix[i+1][j] = 2;
                    }

                    return 0;
                }

                case SDLK_ESCAPE:
                {
                    return 1;
                }

                default:
                {
                    return 0;
                }
            }
        }

        case SDL_QUIT:
        {
            return 1;
        }

        default:
        {
            return 0;
        }
    }

}