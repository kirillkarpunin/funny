cmake_minimum_required(VERSION 3.25)
project(proj C)

set(CMAKE_C_STANDARD 11)

set(SDL2_PATH "D:\\CLion 2023.1.4\\SDL2-2.28.1\\x86_64-w64-mingw32")
find_package(SDL2 REQUIRED)
include_directories( ${SDL2_INCLUDE_DIR} )

add_executable(proj create_map/create_map.c create_map/matrix_business.c create_map/movement.c create_map/create_map.h
                    main.c main.h SDL/sdl_thing.c SDL/sdl_thing.h SDL/draw_map.c SDL/init.c SDL/update.c structs.h)

target_link_libraries(proj ${SDL2_LIBRARY})
