# Copyright Robert Lehmann <lehmrob@posteo.net>
#
# SPDX-License-Identifier: MIT
#

cmake_policy(SET CMP0048 NEW)
cmake_minimum_required(VERSION 3.12)
project(tarfile VERSION 1.0.0)

add_library(${CMAKE_PROJECT_NAME})
target_sources(${CMAKE_PROJECT_NAME} PRIVATE
    src/TarFile.cpp
    )
