#include "create_map.h"

int** create_matrix(){
    int** matrix = calloc(MAP_SIZE, sizeof(char*));
    for (int i = 0; i < MAP_SIZE; i++){
        matrix[i] = calloc(MAP_SIZE, sizeof(char*));
    }

    return matrix;
}

void destroy(int** matrix){
    for (int i = 0; i < MAP_SIZE; i++){
        free(matrix[i]);
    }
    free(matrix);
}

void out(int** matrix){

    for (int i = 0; i < MAP_SIZE; i++){
        for (int j = 0; j < MAP_SIZE; j++){

            switch (matrix[i][j]){
                case 0:
                    printf("# ");
                    break;

                case 1:
                    printf(". ");
                    break;

                case 2:
                    printf("@ ");
                    break;
            }

        }
        printf("\n");
    }
}