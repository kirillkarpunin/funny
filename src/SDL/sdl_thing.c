#include "sdl_thing.h"

data* create_window(map* world, data* glob_lev){

    data* level;
    if (!glob_lev)
    {
        if ( !(world->matrix) ) {
            printf("map error\n");
            return NULL;
        }

        if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER|SDL_INIT_EVENTS|SDL_INIT_AUDIO) != 0)
        {
            printf("error initializing SDL: %s\n", SDL_GetError());
            return NULL;
        }

        if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) != 0 )
        {
            printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
            SDL_Quit();
            return NULL;
        }

        level = init_window();
        if (level == NULL){
            printf("window init error\n");
            Mix_Quit();
            SDL_Quit();
            return NULL;
        }

        level->sounds = read_sounds();
        if (level->sounds == NULL){
            printf("sounds error\n");
            SDL_DestroyRenderer(level->rend);
            SDL_DestroyWindow(level->win);
            free(level);
            Mix_Quit();
            SDL_Quit();
            return NULL;
        }
    }

    else
    {
        level = glob_lev;
    }


    if ( title(world->try, level) ){
        printf("font error\n");
        SDL_DestroyRenderer(level->rend);
        SDL_DestroyWindow(level->win);
        Mix_HaltMusic();
        free_sounds(level->sounds);
        free(level);
        SDL_Quit();
        Mix_Quit();
        return NULL;
    }

    time_t now = 0;
    int close = 0;

    while (!close)
    {
        if (world->try == 4 && now == 0) now = time(0);
        if (now && difftime(time(0), now) > 25) {
            finale(level);
            break;
        }

        SDL_Event event;

        while (SDL_PollEvent(&event) && !close)
        {
            close = update(world, &event, level->sounds);
            level->rend = draw(level->rend, world);
        }
    }

    if (close == 2 && world->try != 4)
    {
        timer(1);
        return level;
    }
    else
    {
        SDL_DestroyRenderer(level->rend);
        SDL_DestroyWindow(level->win);
        Mix_HaltMusic();
        free_sounds(level->sounds);
        free(level);
        SDL_Quit();
        Mix_Quit();
        return NULL;
    }
}
