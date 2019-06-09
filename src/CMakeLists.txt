cmake_minimum_required(VERSION 3.10)
project(autotype)

set(CMAKE_CXX_STANDARD 17)

add_library(autotype SHARED
        autotype.cpp
        autotype_type_info.cpp
        bad_autotype_cast.cpp
)

add_library(autotype_static STATIC
        autotype.cpp
        autotype_type_info.cpp
        bad_autotype_cast.cpp
)

set_target_properties(autotype autotype_static PROPERTIES
    PUBLIC_HEADER "autotype.hpp;autotype_type_info.hpp"
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/arc
)

install(TARGETS
    autotype
    autotype_static
    LIBRARY DESTINATION /usr/local/lib/autotype
    ARCHIVE DESTINATION /usr/local/lib/autotype
    PUBLIC_HEADER DESTINATION /usr/local/include/autotype
)
