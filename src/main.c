#include "main.h"

int main(){

    map* world;
    data* level = NULL;

    int try = 1;
    do{
        world = create_map(try);
        level = create_window(world, level);
        try++;
    } while (level != NULL);

    destroy(world);
    return 0;
}