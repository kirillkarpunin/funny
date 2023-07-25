#include "create_map.h"

map* create_map(int try) {
    map* world = create_struct();
    world->try = try;


    if (try == 4)
    {
       for (int i = 0; i < MAP_SIZE; i++)
       {
           for (int j = 0; j < MAP_SIZE; j++)
           {
               world->matrix[i][j] = 1;
           }
       }
       world->player_coords = (coords){MAP_SIZE/2, MAP_SIZE/2};
       world->matrix[world->player_coords.x][world->player_coords.y] = 2;
    }

    else
    {
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
    }

    return world;
}
