#include "sdl_thing.h"

void timer(int n){
    time_t now = time(0);
    do {} while( difftime(time(0), now) < n );
}