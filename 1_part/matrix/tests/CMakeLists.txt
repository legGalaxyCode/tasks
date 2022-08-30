cmake_minimum_required(VERSION 3.20)
project(matrix_test)

set(CMAKE_CXX_STANDARD 17)

enable_testing()

add_executable(matrix_test unit.cpp)
target_link_libraries(matrix_test GTest::gtest_main)
set_target_properties(matrix_test PROPERTIES CXX_CLANG_TIDY "")

include(GoogleTest)
gtest_discover_tests(matrix_test)