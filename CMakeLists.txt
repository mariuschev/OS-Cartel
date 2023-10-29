cmake_minimum_required(VERSION 3.21)
project(OS_Cartel C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(OS_Cartel main.c DJalgo.c DJalgo.h)
