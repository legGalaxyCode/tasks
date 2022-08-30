cmake_minimum_required(VERSION 3.20)
project(array_test)

enable_testing()

add_executable(array_test unit.cpp)
target_link_libraries(array_test GTest::gtest_main)
set_target_properties(array_test PROPERTIES CXX_CLANG_TIDY "")

include(GoogleTest)
gtest_discover_tests(array_test)

set_tests_properties(${TESTS} PROPERTIES TIMEOUT 10)