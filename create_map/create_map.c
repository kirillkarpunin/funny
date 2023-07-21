#include "create_map.h"

map* create_map() {
    map* world = create_struct();
    int path_len = 0;

    srand(time(NULL));

    while (1)
    {
        int i = ( rand() % (MAP_SIZE-2) ) + 1;
        int j = ( rand() % (MAP_SIZE-2) ) + 1;

        if (path_len == 0 && world->matrix[i][j] == 0){

            world->player_coords = (coords){i, j};

            world->matrix[i][j] = 2;
            path_len++;
        }

        else if (path_len != 0 && world->matrix[i][j] == 1){}

        else{
            continue;
        }

        do {

            int tmp = path(world->matrix, i, j, &path_len);
            if (tmp == 1) break;

        } while (path_len < PATH_LEN);

        if (path_len >= PATH_LEN) {
            break;
        }
    }


    return world;
}
