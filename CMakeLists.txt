cmake_minimum_required(VERSION 3.26)
project(comparison_sorts C)

set(CMAKE_C_STANDARD 23)

find_package(ZLIB REQUIRED)

add_executable(comparison_sorts main.c
        sorting_functions.c
        sorting_functions.h
        tests.c
        tests.h
)
add_subdirectory(libxlsxwriter-main)
include_directories(libxlsxwriter-main/include)
target_link_libraries(comparison_sorts PRIVATE xlsxwriter ZLIB::ZLIB)

