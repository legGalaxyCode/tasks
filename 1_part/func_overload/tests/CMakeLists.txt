cmake_minimum_required(VERSION 3.20)
project(func_overload_test)

set(CMAKE_CXX_STANDARD 17)

enable_testing()

add_executable(func_overload_test unit.cpp)
target_link_libraries(func_overload_test GTest::gtest_main)
set_target_properties(func_overload_test PROPERTIES CXX_CLANG_TIDY "")

include(GoogleTest)
gtest_discover_tests(func_overload_test)