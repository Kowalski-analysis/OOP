cmake_minimum_required(VERSION 3.20)
project(Buildings)

set(CMAKE_CXX_STANDARD 20)

add_library(Buildings Buildings.h Buildings.cpp)

target_link_libraries(
        Buildings
        World
)

