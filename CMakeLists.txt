cmake_minimum_required(VERSION 3.13)
project(autotype)

set(CMAKE_CXX_STANDARD 17)

set(GTEST_DIR test/googletest/googletest)

add_subdirectory(${GTEST_DIR})

if (APPLE)
    add_definitions(-DGTEST_USE_OWN_TR1_TUPLE)
    add_definitions(-D__GLIBCXX__)
endif (APPLE)

include_directories(${GTEST_DIR} ${GTEST_DIR}/include)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/arc)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

include_directories(src)
add_subdirectory(src)
add_subdirectory(test)