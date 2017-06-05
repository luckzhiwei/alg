cmake_minimum_required(VERSION 3.7)
project(bellman_ford)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)
add_executable(bellman_ford ${SOURCE_FILES})