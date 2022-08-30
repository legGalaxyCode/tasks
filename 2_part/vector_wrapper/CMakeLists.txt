cmake_minimum_required(VERSION 3.20)
project(vector_wrapper)

add_executable(vector_wrapper main.cpp VectorWrapper.hpp)

set_target_properties(vector_wrapper PROPERTIES CXX_CLANG_TIDY "${CMAKE_CXX_CLANG_TIDY}")

add_subdirectory(tests)