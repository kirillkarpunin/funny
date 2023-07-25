cmake_minimum_required(VERSION 3.25)
project(game C)

set(CMAKE_C_STANDARD 11)

set(SDL2_PATH "D:\\CLion 2023.1.4\\SDL2-2.28.1\\x86_64-w64-mingw32")
find_package(SDL2 REQUIRED)

include_directories( ${SDL2_INCLUDE_DIR} )

set(SDL2TTF_PATH "D:\\CLion 2023.1.4\\SDL2_ttf-2.20.2\\x86_64-w64-mingw32")
find_package(SDL2TTF REQUIRED)

include_directories( ${SDL2TTF_INCLUDE_DIR} )

set( SDL2_MIXER_PATH "D:\\CLion 2023.1.4\\SDL2_mixer-2.6.3\\x86_64-w64-mingw32")
find_package(SDL2_MIXER REQUIRED)

include_directories( ${SDL2_MIXER_INCLUDE_DIR} )

add_executable(game create_map/create_map.c create_map/memory_business.c create_map/movement.c create_map/create_map.h
                    main.c main.h SDL/sdl_thing.c SDL/sdl_thing.h SDL/draw.c SDL/init_window.c SDL/update.c structs.h SDL/title.c SDL/sounds.c SDL/timer.c)

target_link_libraries(game ${SDL2_LIBRARY})
target_link_libraries(game ${SDL2TTF_LIBRARY})
target_link_libraries(game ${SDL2_MIXER_LIBRARY})
