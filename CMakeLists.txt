cmake_minimum_required(VERSION 3.13)
project(autotype)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/arc)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

set(SOURCE_FILES autotype.h autotype.cpp)

add_library(autotype SHARED ${SOURCE_FILES})

add_library(autotype_static STATIC ${SOURCE_FILES})