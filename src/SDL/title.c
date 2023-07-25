#include "sdl_thing.h"

int title(int try, data* level){

    Mix_HaltMusic();

    char* str;
    switch (try)
    {
        case 1:
        {
            str = "i";
            break;
        }
        case 2:
        {
            str = "ii";
            break;
        }
        case 3:
        {
            str = "iii";
            break;
        }
        case 4:
        {
            str = "iv";
            break;
        }
        default:
            break;
    }

    SDL_SetRenderDrawColor(level->rend, 0, 0, 0, 0);
    SDL_RenderClear(level->rend);
    SDL_RenderPresent(level->rend);

    TTF_Init();
    TTF_Font* font = TTF_OpenFont("data/font.ttf", 24);
    if (!font) return 1;
    SDL_Color White = {255, 255, 255};

    SDL_Surface* surfaceMessage = TTF_RenderText_Solid(font, str, White);
    SDL_Texture* Message = SDL_CreateTextureFromSurface(level->rend, surfaceMessage);
    SDL_Rect Message_rect = {(670-50*strlen(str))/2, (600-50)/2, 50*strlen(str), 100};

    SDL_RenderCopy(level->rend, Message, NULL, &Message_rect);
    SDL_RenderPresent(level->rend);

    Mix_PlayChannel(-1, level->sounds->title, 0);

    timer(3);

    if (try == 4) Mix_PlayMusic(level->sounds->whisper, 1);
    else Mix_PlayMusic(level->sounds->ambient, 10);

    SDL_FreeSurface(surfaceMessage);
    SDL_DestroyTexture(Message);
    TTF_CloseFont(font);
    TTF_Quit();
    return 0;
}

void finale(data* level){

    Mix_HaltMusic();

    SDL_SetRenderDrawColor(level->rend, 0, 0, 0, 0);
    SDL_RenderClear(level->rend);
    SDL_RenderPresent(level->rend);

    TTF_Init();
    TTF_Font* font = TTF_OpenFont("data/font.ttf", 50);
    if (!font) return;

    SDL_Color White = {255, 255, 255};

    SDL_Surface* surfaceMessage = TTF_RenderText_Solid(font, "d", White);
    SDL_Texture* Message = SDL_CreateTextureFromSurface(level->rend, surfaceMessage);
    SDL_Rect Message_rect = {(670-200)/2, (600-100)/2, 200, 200};

    SDL_RenderCopy(level->rend, Message, NULL, &Message_rect);
    SDL_RenderPresent(level->rend);

    Mix_PlayChannel(-1, level->sounds->fin, 0);
    timer(2);

    SDL_FreeSurface(surfaceMessage);
    SDL_DestroyTexture(Message);
    TTF_CloseFont(font);
    TTF_Quit();
}