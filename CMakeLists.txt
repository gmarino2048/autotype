cmake_minimum_required(VERSION 3.10)
project(autotype)

set(CMAKE_CXX_STANDARD 17)

set(GTEST_DIR modules/googletest/googletest)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/arc)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

add_subdirectory(modules/googletest)
include_directories(googletest/googletest/include)

include_directories(include)
add_subdirectory(src)
add_subdirectory(test)