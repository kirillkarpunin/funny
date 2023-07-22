#ifndef PROJ_SDL_THING_H
#define PROJ_SDL_THING_H

#include "SDL2/SDL.h"
#include "stdio.h"
#include "../structs.h"

#define START 25
#define OFFSET 5
#define SQR_SIZE 20

int create_window(map* world);

int init(SDL_Window** ptr_win, SDL_Renderer** ptr_rend);

int update(map* world, SDL_Event* event);
SDL_Renderer* draw(SDL_Renderer* rend, map* world);

#endif //PROJ_SDL_THING_H