cmake_minimum_required(VERSION 3.10)
project(autotype)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        autotype_test
        autotype_type_info_test.cpp
        bad_autotype_cast_test.cpp
        autotype_test.cpp
)

set_target_properties(autotype_test
        PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/test/arc
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/test/lib
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/test/bin
)

target_link_libraries(
        autotype_test
        autotype_static
        gtest
        gtest_main
)