cmake_minimum_required(VERSION 3.23)
project(array)

add_executable(array main.cpp array.hpp)

add_subdirectory(tests)