#include "main.h"

int main(){

    map* world = create_map();
    create_window(world);
    destroy_struct(world);

    return 0;
}