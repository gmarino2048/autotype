cmake_minimum_required(VERSION 3.10)
project(autotype)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        autotype_test
        autotype_type_info_test.cpp
        bad_autotype_cast_test.cpp
        autotype_test.cpp
)

set(TEST_DIR ${CMAKE_SOURCE_DIR}/test/bin)

set_target_properties(autotype_test
        PROPERTIES
        POSITION_INDEPENDENT_CODE OFF
        RUNTIME_OUTPUT_DIRECTORY ${TEST_DIR}
)

target_link_libraries(
        autotype_test
        autotype_static
        pthread
        gtest
        gtest_main
)

add_test(autotype ${CMAKE_SOURCE_DIR}/test/bin/autotype_test)