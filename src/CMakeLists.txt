cmake_minimum_required(VERSION 3.13)
project(autotype)

set(CMAKE_CXX_STANDARD 17)

add_library(autotype SHARED autotype.h autotype.cpp)
add_library(autotype_static STATIC autotype.h autotype.cpp)