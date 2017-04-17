cmake_minimum_required(VERSION 3.7)
project(dyc_programing_job_scheclue)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp "Scheduler.cpp" "Scheduler.h")
add_executable(dyc_programing_job_scheclue ${SOURCE_FILES})