#ifndef PROJ_CREATE_MAP_H
#define PROJ_CREATE_MAP_H

#endif //PROJ_CREATE_MAP_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE 25
#define PATH_LEN 370
// PATH_LEN must not be greater than (MAP_SIZE - 2)^2, otherwise the loop will never end
// optimal formula for PATH_LEN: (MAP_SIZE - 2)^2 * 0.7

#define NORTH 1
#define EAST 2
#define SOUTH 3
#define WEST 4


int* check_directions(int** matrix, int i, int j);
void go(int d, int* ptr_i, int* ptr_j);
int path(int** matrix, int i, int j, int* ptr_path_len);

int** create_matrix();
void destroy(int** matrix);
void out(int** matrix);