cmake_minimum_required(VERSION 3.20)
project(Lab2_OOP_main)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lab2_OOP_main main.cpp funcs.cpp funcs.h)

include_directories(../Lab2_OOP_class)

target_link_libraries(Lab2_OOP_main Lab2_OOP_class)