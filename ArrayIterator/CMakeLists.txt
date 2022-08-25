cmake_minimum_required(VERSION 3.20)
project(array_iterator)

add_executable(array_iterator main.cpp ArrayIterator.hpp)

set_target_properties(array_iterator PROPERTIES CXX_CLANG_TIDY "${CMAKE_CXX_CLANG_TIDY}")

add_subdirectory(tests)
