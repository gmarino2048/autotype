cmake_minimum_required(VERSION 3.10)
project(autotype)

set(CMAKE_CXX_STANDARD 17)

enable_testing()

include(GNUInstallDirs)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/arc)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

include_directories(
    include
    ${CMAKE_INSTALL_INCLUDEDIR}
)

link_directories(
    /usr/lib
    ${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_LIBDIR} 
)

add_subdirectory(src)
add_subdirectory(test)

install(
    DIRECTORY include/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/autotype
    PATTERN "impl" EXCLUDE
)
