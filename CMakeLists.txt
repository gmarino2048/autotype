cmake_minimum_required(VERSION 3.10)
project(autotype)

set(CMAKE_CXX_STANDARD 17)

enable_testing()

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/arc)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

include_directories(
    include
    /usr/local/include
)

link_directories(
    /usr/lib
    /usr/local/lib
)

add_subdirectory(src)
add_subdirectory(test)

install(
    DIRECTORY include/
    DESTINATION /usr/local/include/autotype
    PATTERN "impl" EXCLUDE
)

install(TARGETS
    autotype
    autotype_static
    LIBRARY DESTINATION /usr/local/lib/autotype
    ARCHIVE DESTINATION /usr/local/lib/autotype
)