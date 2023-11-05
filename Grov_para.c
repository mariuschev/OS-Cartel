#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <omp.h>
#include "grov_para.h"

int oracle(int target, int guess) {
    return (target == guess) ? 1 : 0;
}

int groverAlgorithm_para(int target, int maxGuesses) {
    int guess = 0;
    int N = 1 << maxGuesses;  // Total number of possible states

    int result = -1;  // Initialize the result to indicate "not found"

#pragma omp parallel for
    for (int iteration = 0; iteration < maxGuesses; iteration++) {
        int local_result = -1;  // Initialize the local result for this thread
        int thread_id = omp_get_thread_num();
        int num_threads = omp_get_num_threads();

        // Divide the search space among threads
        for (int i = thread_id; i < N; i += num_threads) {
            // Apply oracle
            if (oracle(target, i)) {
                local_result = i;
            }
        }

#pragma omp critical
        {
            // Update the global result atomically
            if (local_result != -1) {
                result = local_result;
            }
        }
    }

    if (result != -1) {
        printf("Target %d found at index %d.\n", target, result);
    } else {
        printf("Target not found.\n");
    }

    return result;
}