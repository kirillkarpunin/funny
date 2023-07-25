#ifndef PROJ_SDL_THING_H
#define PROJ_SDL_THING_H

#include "SDL.h"
#include "SDL_ttf.h"
#include "stdio.h"
#include "../structs.h"
#include "time.h"
#include "SDL_mixer.h"

#define START 25
#define OFFSET 5
#define SQR_SIZE 20

data* create_window(map* world, data* glob_lev);

data* init_window();

int update(map* world, SDL_Event* event, audio* sounds);
SDL_Renderer* draw(SDL_Renderer* rend, map* world);

int title (int try, data* level);
void finale(data* level);

audio* read_sounds();
void free_sounds(audio* sounds);

void timer(int n);

#endif //PROJ_SDL_THING_H