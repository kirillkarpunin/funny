#ifndef PROJ_CREATE_MAP_H
#define PROJ_CREATE_MAP_H

#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include <time.h>
#include "../structs.h"

#define MAP_SIZE 25
#define PATH_LEN 370
// PATH_LEN must not be greater than (MAP_SIZE - 2)^2, otherwise the loop will never end
// optimal formula for PATH_LEN: (MAP_SIZE - 2)^2 * 0.7

#define NORTH 1
#define EAST 2
#define SOUTH 3
#define WEST 4

map* create_map();

int* check_directions(int** matrix, int i, int j);
void go(int d, int* ptr_i, int* ptr_j);
int path(int** matrix, int i, int j, int* ptr_path_len);

map* create_struct();
void destroy_struct(map* world);

#endif //PROJ_CREATE_MAP_H