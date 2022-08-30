cmake_minimum_required(VERSION 3.20)
project(matrix)

set(CMAKE_CXX_STANDARD 17)

add_executable(matrix main.cpp matrix.hpp)

set_target_properties(matrix PROPERTIES CXX_CLANG_TIDY "${CMAKE_CXX_CLANG_TIDY}")

add_subdirectory(tests)