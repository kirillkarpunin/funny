cmake_minimum_required(VERSION 3.25)
project(proj C)

set(CMAKE_C_STANDARD 11)

include_directories(../lib/SDL2-2.28.1/include)
add_executable(proj create_map/create_map.c create_map/matrix_business.c create_map/movement.c create_map/create_map.h
                    main.c main.h)
