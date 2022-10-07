cmake_minimum_required(VERSION 3.16.3)
project(Lab3_OOP_main)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lab3_OOP_main main.cpp funcs.cpp funcs.h)

include_directories(../Lab3_OOP_class)

target_link_libraries(Lab3_OOP_main Lab3_OOP_class)