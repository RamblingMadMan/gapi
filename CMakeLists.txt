cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)
project(gapi)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(src)
add_subdirectory(test)
