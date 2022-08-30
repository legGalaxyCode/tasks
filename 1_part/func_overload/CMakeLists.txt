cmake_minimum_required(VERSION 3.20)
project(func_overload)

add_executable(func_overload main.cpp function.hpp)

set_target_properties(func_overload PROPERTIES CXX_CLANG_TIDY "${CMAKE_CXX_CLANG_TIDY}")

add_subdirectory(tests)