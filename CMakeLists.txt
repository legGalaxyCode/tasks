cmake_minimum_required(VERSION 3.23)
project(tasks)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -g -fno-omit-frame-pointer")

#include(cmake/Helpers.cmake)

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.12.1
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

#include(cmake/Task.cmake)
add_subdirectory(TemplatesIntro)
add_subdirectory(VectorWrapper)