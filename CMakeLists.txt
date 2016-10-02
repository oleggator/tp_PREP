cmake_minimum_required(VERSION 3.6)
project(homework2)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99 -Weverything -g -O0")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

set(MATRIX_SOURCE_FILES matrix.c matrix.h)
add_library(matrix ${MATRIX_SOURCE_FILES})

set(SOURCE_FILES main.c)
add_executable(homework2 ${SOURCE_FILES})

target_link_libraries(homework2 matrix)
