cmake_minimum_required(VERSION 3.20)
project(Lab4_OOP)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lab4_OOP main.cpp World/World.cpp World/World.h Entities/Entities.cpp Entities/Entities.h
        Buildings/Buildings.cpp Buildings/Buildings.h Map.cpp Map.h Images.cpp Images.h View.cpp)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR F:/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(F:/SFML/include/SFML)
target_link_libraries(Lab4_OOP sfml-system sfml-window sfml-graphics sfml-audio)