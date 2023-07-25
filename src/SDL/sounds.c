#include "sdl_thing.h"

audio* read_sounds(){
    audio* sounds = malloc(sizeof(audio));
    sounds->walk = Mix_LoadWAV("data/walk.wav");
    sounds->no_walk = Mix_LoadWAV("data/no_walk.wav");
    sounds->exit = Mix_LoadWAV("data/exit.wav");
    sounds->ambient = Mix_LoadMUS("data/ambient.wav");
    sounds->whisper = Mix_LoadMUS("data/whisper.wav");
    sounds->title = Mix_LoadWAV("data/title.wav");
    sounds->fin = Mix_LoadWAV("data/fin.wav");

    if (sounds->walk == NULL || sounds->no_walk == NULL || sounds->exit == NULL ||
    sounds->ambient == NULL || sounds->title == NULL || sounds->whisper == NULL || sounds->fin == NULL){
        return NULL;
    }
    return sounds;
}

void free_sounds(audio* sounds){
    Mix_FreeChunk(sounds->walk);
    Mix_FreeChunk(sounds->no_walk);
    Mix_FreeChunk(sounds->exit);
    Mix_FreeMusic(sounds->ambient);
    Mix_FreeMusic(sounds->whisper);
    Mix_FreeChunk(sounds->title);
    Mix_FreeChunk(sounds->fin);
    free(sounds);
}