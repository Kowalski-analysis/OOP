cmake_minimum_required(VERSION 3.16.3)
project(part3)

set(CMAKE_CXX_STANDARD 20)

add_executable(EC planty_symbols.cpp planty_symbols.h my_func.cpp my_func.h ExternalCode_dialog.cpp ExternalCode_dialog.h ExternalCode.h ExternalCode.cpp new_main.cpp)
