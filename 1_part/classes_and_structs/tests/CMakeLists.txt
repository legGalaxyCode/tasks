cmake_minimum_required(VERSION 3.20)
project(classes_and_structs_test)

set(CMAKE_CXX_STANDARD 17)

enable_testing()

add_executable(classes_and_structs_test unit.cpp)
target_link_libraries(classes_and_structs_test GTest::gtest_main)
set_target_properties(classes_and_structs_test PROPERTIES CXX_CLANG_TIDY "")

include(GoogleTest)
gtest_discover_tests(classes_and_structs_test)