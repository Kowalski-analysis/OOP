cmake_minimum_required(VERSION 3.20)
project(Entities)

set(CMAKE_CXX_STANDARD 20)

add_library(Entities Entities.h Entities.cpp)

target_link_libraries(Entities World)