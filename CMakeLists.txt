cmake_minimum_required(VERSION 3.25)
project(dataorient)

set(CMAKE_CXX_STANDARD 17)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

add_executable(dataorient main.cpp game.cpp game.hpp headers.hpp texturemanager.cpp texturemanager.hpp gameobject.cpp gameobject.hpp player.cpp player.hpp ball.cpp ball.hpp)

target_link_libraries(dataorient ${SDL_LIBRARY} -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf)