# Copyright Robert Lehmann <lehmrob@posteo.net>
#
# SPDX-License-Identifier: MIT
#

cmake_policy(SET CMP0048 NEW)
cmake_minimum_required(VERSION 3.12)
project(tarfile VERSION 1.0.0)

add_compile_options(-Wall -Wextra -pedantic -Werror)

add_library(${CMAKE_PROJECT_NAME})
target_sources(${CMAKE_PROJECT_NAME} PRIVATE
    src/TarFile.cpp
    src/Header.cpp
    )

add_executable(simple
    example/simple.cpp
    )

target_link_libraries(simple ${CMAKE_PROJECT_NAME})

set(CATCH_BUILD_STATIC_LIBRARY CACHE BOOL ON) 
add_subdirectory(${CMAKE_SOURCE_DIR}/3rdparty/catch2)

enable_testing()
add_subdirectory(tests)

