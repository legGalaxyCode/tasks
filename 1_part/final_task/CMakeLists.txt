cmake_minimum_required(VERSION 3.20)
project(final_task)

add_executable(final_task main.cpp)

set_target_properties(final_task PROPERTIES CXX_CLANG_TIDY "${CMAKE_CXX_CLANG_TIDY}")