#include "DJalgo.h"
#include <stdio.h>
#include <omp.h>

// Oracle function - Replace this with your own constant or balanced function
int oracleFunction(int input) {
    // Example balanced function: f(x) = x XOR 1
    return input ^ 1;
}

// Deutsch-Jozsa algorithm
int deutschJozsaAlgorithm_seq() {
    int oracleOutput;
    int number = chooseNumber();
    // Apply the oracle function to 0 to determine if it's constant or balanced
    oracleOutput = oracleFunction(number);

    // Check if the oracle is constant or balanced
    if (oracleOutput == 0) {
        printf("The oracle function is constant.\n");
        return 0; // Constant function
    } else {
        printf("The oracle function is balanced.\n");
        return 1; // Balanced function
    }
}
int deutschJozsaAlgorithm_para() {
    int oracleOutput;
    int number = chooseNumber();

    // Parallelize the computation of the oracle function
#pragma omp parallel
    {
        int localOracleOutput;
#pragma omp for
        for (int i = 0; i < omp_get_num_threads(); i++) {
            localOracleOutput = oracleFunction(number);
        }

        // Combine the results from different threads (you can use any suitable reduction operation)
#pragma omp single
        {
            oracleOutput = localOracleOutput;
        }
    }

    // Check if the oracle is constant or balanced
    if (oracleOutput == 0) {
        printf("The oracle function is constant.\n");
        return 0; // Constant function
    } else {
        printf("The oracle function is balanced.\n");
        return 1; // Balanced function
    }
}


int chooseNumber(){
    int number;
    printf("Choose a number: ");
    scanf("%d", &number);
    return number;
}
