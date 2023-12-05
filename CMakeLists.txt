# Copyright 2023-11-02 skylanwei 


cmake_minimum_required(VERSION 3.14)
project(libtrpc_server_tpl_common.a C CXX)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE DEBUG)

# include *.h
set(TRPC_INSTALL_PATH /usr/local/trpc-cpp/trpc)
include(${TRPC_INSTALL_PATH}/cmake/config/trpc_config.cmake)
include_directories(${INCLUDE_INSTALL_PATHS})

# lib directories
link_directories(${LIBRARY_INSTALL_PATHS})
link_directories("${CMAKE_CURRENT_SOURCE_DIR}/lib/")

# Include generated files
set(TARGET trpc_server_tpl_common)
set(LIBRARY_OUTPUT_PATH "${CMAKE_SOURCE_DIR}/lib")

aux_source_directory("${CMAKE_CURRENT_SOURCE_DIR}" SRC)
add_library(${TARGET} STATIC "${SRC}")
target_link_libraries(${TARGET})

