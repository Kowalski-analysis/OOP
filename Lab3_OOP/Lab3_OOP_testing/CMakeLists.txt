cmake_minimum_required(VERSION 3.16.3)
project(Lab3_OOP_testing)

set(CMAKE_CXX_STANDARD 20)

######### googletest init #########
include(FetchContent)
FetchContent_Declare(
        googletest

        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
######### googletest init end #########

add_executable(Lab3_OOP_testing testing.cpp)

######### links to static libs #########
include_directories(../Lab3_OOP_class)
target_link_libraries(Lab3_OOP_testing gtest_main Lab3_OOP_class)
