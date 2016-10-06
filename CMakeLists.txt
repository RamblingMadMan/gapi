cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)
project(gapi)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_subdirectory(spec_parser)
add_subdirectory(src)

if(COMPILE_TEST)
	add_subdirectory(test)
endif(COMPILE_TEST)
