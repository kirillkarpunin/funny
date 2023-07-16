#ifndef PROJ_SDL_THING_H
#define PROJ_SDL_THING_H

#endif //PROJ_SDL_THING_H

#include "SDL2/SDL.h"
#include "stdio.h"

#define START 25
#define OFFSET 5
#define SQR_SIZE 20

#define UP 1
#define RIGHT 2
#define DOWN 3
#define LEFT 4

SDL_Renderer* draw(SDL_Renderer* rend, SDL_Rect* rect, SDL_Rect* player, int direction);
int init(SDL_Window** ptr_win, SDL_Renderer** ptr_rend);