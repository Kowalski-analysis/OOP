cmake_minimum_required(VERSION 3.20)
project(Interface)

set(CMAKE_CXX_STANDARD 20)

find_package(SFML COMPONENTS graphics audio REQUIRED)

add_library(Interface Menu.h Menu.cpp)

target_link_libraries(Interface sfml-graphics sfml-audio)
