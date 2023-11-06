//
// Created by Louise LAVERGNE on 05/11/2023.
//

#ifndef OS_CARTEL_GROV_PARA_H
#define OS_CARTEL_GROV_PARA_H
#include <omp.h>
#include <stdio.h>

int grover_parallel_algorithm(int size, int target, int num_threads, int *values);

#endif //OS_CARTEL_GROV_PARA_H