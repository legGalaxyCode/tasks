cmake_minimum_required(VERSION 3.23)
project(vector_wrapper_test)

enable_testing()

add_executable(vector_wrapper_test unit.cpp)
target_link_libraries(vector_wrapper_test GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(vector_wrapper_test)