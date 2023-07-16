#include "sdl_thing.h"

SDL_Renderer* draw(SDL_Renderer* rend, SDL_Rect* rect, SDL_Rect* player, int direction){

    if (player->x == -1)
    {
        FILE* f = fopen("map.txt", "r");
        if (!f){
            printf("cannot read map");
            return NULL;
        }

        SDL_SetRenderDrawColor(rend, 0, 0, 0, 0);
        SDL_RenderClear(rend);

        SDL_SetRenderDrawColor(rend, 255, 255, 255, 0);

        char c = (char)getc(f);

        while ( c > 0 ) {

            switch (c){
                case '#':
                    SDL_RenderDrawRect(rend, rect);

                    rect->x += (OFFSET + SQR_SIZE);
                    break;

                case '.':
                    rect->x += (OFFSET + SQR_SIZE);
                    break;

                case '@':

                    player->x = rect->x;
                    player->y = rect->y;
                    player->h = SQR_SIZE;
                    player->w = SQR_SIZE;

                    SDL_SetRenderDrawColor(rend, 0, 255, 0, 0);
                    SDL_RenderDrawRect(rend, player);
                    SDL_SetRenderDrawColor(rend, 255, 255, 255, 0);

                    rect->x += (OFFSET + SQR_SIZE);
                    break;

                case '\n':
                    rect->x = START;
                    rect->y += (OFFSET + SQR_SIZE);
                    break;

                default:
                    break;
            }

            c = (char)getc(f);

        }
        fclose(f);
    }

    else
    {

        SDL_SetRenderDrawColor(rend, 0, 0, 0, 0);
        SDL_RenderDrawRect(rend, player);

        switch (direction)
        {
            case UP:
                player->y -= (SQR_SIZE + OFFSET);
                break;

            case RIGHT:
                player->x += (SQR_SIZE + OFFSET);
                break;

            case DOWN:
                player->y += (SQR_SIZE + OFFSET);
                break;

            case LEFT:
                player->x -= (SQR_SIZE + OFFSET);
                break;

            default:
                break;

        }

        SDL_SetRenderDrawColor(rend, 0, 255, 0, 0);
        SDL_RenderDrawRect(rend, player);
    }

    SDL_RenderPresent(rend);
    return rend;

}
