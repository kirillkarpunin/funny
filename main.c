#include "main.h"

int main(){

    map* world = create_map();
    create_window(world);
    destroy(world);

    return 0;
}