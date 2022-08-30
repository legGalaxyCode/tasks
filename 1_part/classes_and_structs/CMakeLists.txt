cmake_minimum_required(VERSION 3.20)
project(classes_and_structs)

set(CMAKE_CXX_STANDARD 17)

add_executable(classes_and_structs main.cpp classes.hpp)

set_target_properties(classes_and_structs PROPERTIES CXX_CLANG_TIDY "${CMAKE_CXX_CLANG_TIDY}")

add_subdirectory(tests)