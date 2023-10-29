#include <stdio.h>
#include "DJalgo.h"
#include <omp.h>

int main (){
    // commence par 0 : constant
    // commence par 1 : balanced

    int result = deutschJozsaAlgorithm_seq();
    printf("Result: %d\n", result);
    int result2 = deutschJozsaAlgorithm_para();
    printf("Result: %d\n", result2);
    return 0;
}

