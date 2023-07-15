#include "create_map.h"

int create_map() {
    int** matrix = create_matrix();
    int path_len = 0;

    srand(time(NULL));

    while (1)
    {
        int i = ( rand() % (MAP_SIZE-2) ) + 1;
        int j = ( rand() % (MAP_SIZE-2) ) + 1;

        if (path_len == 0 && matrix[i][j] == 0){
            matrix[i][j] = (path_len == 0 ? 2 : 2);
            path_len++;
        }

        else if (path_len != 0 && matrix[i][j] == 1){}

        else{
            continue;
        }

        do {

            int tmp = path(matrix, i, j, &path_len);
            if (tmp == 1) break;

        } while (path_len < PATH_LEN);

        if (path_len >= PATH_LEN) {
            break;
        }
    }

    out(matrix);
    destroy(matrix);
    return 0;
}
