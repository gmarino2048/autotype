cmake_minimum_required(VERSION 3.13)
project(autotype)

set(CMAKE_CXX_STANDARD 17)

add_executable(autotype_test autotype_test.cpp)
set_target_properties(autotype_test
        PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/test/arc
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/test/lib
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/test/bin)

