# cmake_minimum_required(VERSION <specify CMake version here>)
project(c___practice)

set(CMAKE_CXX_STANDARD 14)

add_executable(c___practice main.cpp textmanipulator.h textmanipulator.cpp greeting.h greeting.cpp local_text_manipulator.h local_text_manipulator.cpp)