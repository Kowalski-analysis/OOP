cmake_minimum_required(VERSION 3.20)
project(World)

set(CMAKE_CXX_STANDARD 20)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR F:/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(F:/SFML/include/SFML)

add_library(World World.h World.cpp)

target_link_libraries(
        World
        sfml-system
        sfml-window
        sfml-graphics
        sfml-audio
)