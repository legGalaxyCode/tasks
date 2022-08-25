cmake_minimum_required(VERSION 3.23)
project(array)

add_executable(array main.cpp array.hpp)

set_target_properties(array PROPERTIES CXX_CLANG_TIDY "${CMAKE_CXX_CLANG_TIDY}")

add_subdirectory(tests)