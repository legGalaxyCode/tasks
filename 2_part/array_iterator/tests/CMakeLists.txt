cmake_minimum_required(VERSION 3.20)
project(array_iterator_test)

enable_testing()

add_executable(array_iterator_test unit.cpp)
target_link_libraries(array_iterator_test GTest::gtest_main)
set_target_properties(array_iterator_test PROPERTIES CXX_CLANG_TIDY "")

include(GoogleTest)
gtest_discover_tests(array_iterator_test)