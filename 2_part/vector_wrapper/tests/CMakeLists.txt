cmake_minimum_required(VERSION 3.20)
project(vector_wrapper_test)

enable_testing()

add_executable(vector_wrapper_test unit.cpp)
target_link_libraries(vector_wrapper_test GTest::gtest_main)
set_target_properties(vector_wrapper_test PROPERTIES CXX_CLANG_TIDY "")

include(GoogleTest)
gtest_discover_tests(vector_wrapper_test)