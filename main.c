#include <stdio.h>
#include "Grov_seq.h"
#include "Grov_para.h"
#include <math.h>
#include <complex.h>
#include <pthread.h>
#include <time.h>

double get_current_time() {
    struct timespec tp;
    clock_gettime(CLOCK_MONOTONIC, &tp);
    return ((double)tp.tv_sec + (double)tp.tv_nsec * 1e-9);
}

int main (){
    int list[] = {3, 6, 8, 7, 12, 4, 2};
    int listSize = sizeof(list) / sizeof(list[0]);
    int target = 9;
    int iterations = (int)ceil(M_PI / (4.0 * sqrt(listSize))); // Number of iterations
    int num_threads = 4; // Number of threads to use
    double start = get_current_time();
    int resultat_para = grover_parallel_algorithm(listSize, target, num_threads, list);
    if (resultat_para != -1) {
        printf("P | Target %d found at index %d.\n",target, resultat_para);
    } else {
        printf("Target not found.\n");
    }
    double end = get_current_time();
    printf("Parallel execution time: %f seconds\n", end - start);
    start = get_current_time();
    groverAlgorithm(target, list, listSize);
    end = get_current_time();
    printf("Sequential execution time: %f seconds\n", end - start);


    return 0;
}

