cmake_minimum_required(VERSION 3.20)
project(Lab4_OOP)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(World)
add_subdirectory(Buildings)
add_subdirectory(Entities)
add_subdirectory(Testing)
add_subdirectory(MyPriorityQueue)

add_executable(Lab4_OOP main.cpp)

target_link_libraries(
        Lab4_OOP
        Entities
        Buildings
        World
        MyPriorityQueue
)