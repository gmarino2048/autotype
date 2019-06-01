cmake_minimum_required(VERSION 3.10)
project(autotype)

set(CMAKE_CXX_STANDARD 17)

add_library(autotype SHARED
        autotype.cpp
        autotype_type_info.cpp
        bad_autotype_cast.cpp)

add_library(autotype_static STATIC
        autotype.cpp
        autotype_type_info.cpp
        bad_autotype_cast.cpp)