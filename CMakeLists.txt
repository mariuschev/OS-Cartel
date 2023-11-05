cmake_minimum_required(VERSION 3.21)
project(OS_Cartel C)

set(CMAKE_C_STANDARD 11)

include_directories(.)
find_package(OpenMP REQUIRED)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")

add_executable(OS_Cartel main.c Grov_seq.c Grov_seq.h Grov_par.c Grov_par.h)


