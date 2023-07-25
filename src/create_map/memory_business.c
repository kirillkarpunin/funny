#include "create_map.h"

map* create_struct(){
    int** matrix = calloc(MAP_SIZE, sizeof(char*));
    for (int i = 0; i < MAP_SIZE; i++){
        matrix[i] = calloc(MAP_SIZE, sizeof(char*));
    }

    map* world = malloc(sizeof(map));
    world->matrix = matrix;
    world->size = MAP_SIZE;

    return world;
}

void destroy(map* world){
    if (world->matrix)
    {
        for (int i = 0; i < MAP_SIZE; i++){
            free(world->matrix[i]);
        }
        free(world->matrix);
    }
    free(world);
}

