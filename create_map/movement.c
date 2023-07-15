#include "create_map.h"

int* check_directions(int** matrix, int i, int j){
    int* directions = calloc(5, sizeof(int));
    int len = 0;

    if (i-1 > 0 && matrix[i-1][j] == 0){
        directions[len++] = NORTH;
    }

    if (j+1 < MAP_SIZE-1 && matrix[i][j+1] == 0){
        directions[len++] = EAST;
    }

    if (i+1 < MAP_SIZE-1 && matrix[i+1][j] == 0){
        directions[len++] = SOUTH;
    }

    if (j-1 > 0 && matrix[i][j-1] == 0){
        directions[len++] = WEST;
    }

    directions[4] = len;
    return directions;
}

void go(int d, int* ptr_i, int* ptr_j){
    switch (d) {
        case NORTH:
            *ptr_i -= 1;
            break;

        case EAST:
            *ptr_j += 1;
            break;

        case SOUTH:
            *ptr_i += 1;
            break;

        case WEST:
            *ptr_j -= 1;
            break;

        default:
            break;
    }
}

int path(int** matrix, int i, int j, int* ptr_path_len){

    if (*ptr_path_len >= PATH_LEN) return 0;

    int* directions = check_directions(matrix, i, j);
    int arr_len = directions[4];

    if (arr_len == 0) return 1;

    int d = directions[ rand() % arr_len ];
    free(directions);

    go(d, &i,&j);
    matrix[i][j] = 1;
    (*ptr_path_len)++;

    return path(matrix, i, j, ptr_path_len);
}
