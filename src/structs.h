#ifndef PROJ_STRUCTS_H
#define PROJ_STRUCTS_H

#include "SDL.h"
#include "SDL_mixer.h"

typedef struct coords{
    int x;
    int y;
} coords;

typedef struct map{
    int** matrix;
    coords player_coords;
    int size;
    int try;
} map;

typedef struct audio{
    Mix_Chunk* walk;
    Mix_Chunk* no_walk;
    Mix_Chunk* exit;
    Mix_Chunk* fin;
    Mix_Music* ambient;
    Mix_Music* whisper;
    Mix_Chunk* title;
} audio;

typedef struct data{
    SDL_Window* win;
    SDL_Renderer* rend;
    audio* sounds;
    SDL_Surface* icon;
} data;

#endif //PROJ_STRUCTS_H
