cmake_minimum_required(VERSION 3.20)
project(World)

set(CMAKE_CXX_STANDARD 20)

find_package(SFML COMPONENTS graphics audio REQUIRED)

add_library(World World.h World.cpp)

target_link_libraries(World sfml-graphics sfml-audio)
