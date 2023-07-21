#ifndef PROJ_STRUCTS_H
#define PROJ_STRUCTS_H

typedef struct coords{
    int x;
    int y;
} coords;

typedef struct map{
    int** matrix;
    coords player_coords;
    int size;
} map;

#endif //PROJ_STRUCTS_H
