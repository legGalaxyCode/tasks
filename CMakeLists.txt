cmake_minimum_required(VERSION 3.23)
project(tasks)

set(CMAKE_CXX_STANDARD 17)
if (UNIX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -g -fno-omit-frame-pointer -fsanitize=address")
elseif (WIN32)
    if (CMAKE_CXX_COMPILER STREQUAL "GNU" OR "Clang")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -Werror -g -fno-omit-frame-pointer")
    else()
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -WX -g -fno-omit-frame-pointer")
    endif()
endif()

find_program(CLANG_TIDY_EXE NAMES clang-tidy)
if (CLANG_TIDY_EXE)
    message(STATUS "clang-tidy found: ${CLANG_TIDY_EXE}")
    set(CMAKE_CXX_CLANG_TIDY "clang-tidy")
else()
    message(STATUS "clang-tidy not found.")
endif()

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.12.1
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_subdirectory(TemplatesIntro)
add_subdirectory(VectorWrapper)
add_subdirectory(ArrayIterator)