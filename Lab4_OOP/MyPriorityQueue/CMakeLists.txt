cmake_minimum_required(VERSION 3.20)
project(MyPriorityQueue)

set(CMAKE_CXX_STANDARD 20)

add_library(MyPriorityQueue priority_queue.h priority_queue.cpp)
