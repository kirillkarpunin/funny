#include "sdl_thing.h"

int update(map* world, SDL_Event* event, audio* sounds){

    int i = world->player_coords.x;
    int j = world->player_coords.y;

    switch (event->type)
    {
        case SDL_KEYDOWN:
        {
            int ext = 0;

            switch (event->key.keysym.sym)
            {
                case SDLK_UP:
                {
                    if (j > 0 && world->matrix[i][j-1] != 0){

                        if (world->matrix[i][j-1] == 3){
                            ext = 2;
                            Mix_PlayChannel(-1, sounds->exit, 0);
                        }
                        else Mix_PlayChannel(-1, sounds->walk, 0);

                        world->matrix[i][j] = 1;

                        world->player_coords = (coords){i, j-1};
                        world->matrix[i][j-1] = 2;
                    }
                    else Mix_PlayChannel(-1, sounds->no_walk, 0);
                    return ext;
                }

                case SDLK_DOWN:
                {
                    if (j < world->size-1 && world->matrix[i][j+1] != 0){

                        if (world->matrix[i][j+1] == 3){
                            ext = 2;
                            Mix_PlayChannel(-1, sounds->exit, 0);
                        }
                        else Mix_PlayChannel(-1, sounds->walk, 0);

                        world->matrix[i][j] = 1;

                        world->player_coords = (coords){i, j+1};
                        world->matrix[i][j+1] = 2;
                    }
                    else Mix_PlayChannel(-1, sounds->no_walk, 0);
                    return ext;
                }

                case SDLK_LEFT:
                {
                    if (i > 0 && world->matrix[i-1][j] != 0){

                        if (world->matrix[i-1][j] == 3){
                            ext = 2;
                            Mix_PlayChannel(-1, sounds->exit, 0);
                        }
                        else Mix_PlayChannel(-1, sounds->walk, 0);

                        world->matrix[i][j] = 1;

                        world->player_coords = (coords){i-1, j};
                        world->matrix[i-1][j] = 2;
                    }
                    else Mix_PlayChannel(-1, sounds->no_walk, 0);
                    return ext;
                }

                case SDLK_RIGHT:
                {
                    if (i < world->size-1 && world->matrix[i+1][j] != 0){

                        if (world->matrix[i+1][j] == 3) {
                            ext = 2;
                            Mix_PlayChannel(-1, sounds->exit, 0);
                        }
                        else Mix_PlayChannel(-1, sounds->walk, 0);

                        world->matrix[i][j] = 1;

                        world->player_coords = (coords){i+1, j};
                        world->matrix[i+1][j] = 2;
                    }
                    else Mix_PlayChannel(-1, sounds->no_walk, 0);
                    return ext;
                }

                case SDLK_ESCAPE:
                {
                    return 1;
                }

                case SDLK_u:
                {
                    return 3;
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