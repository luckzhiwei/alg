cmake_minimum_required(VERSION 3.7)
project(dyc_programing_line)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Pipeline.cpp Pipeline.h)
add_executable(dyc_programing_line ${SOURCE_FILES})