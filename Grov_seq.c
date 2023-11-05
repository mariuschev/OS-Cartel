#include <stdio.h>
#include <stdbool.h>

int oracle(int target, int guess) {
    return (target == guess) ? 1 : 0;
}

int groverAlgorithm(int target, int* list, int listSize) {
    for (int i = 0; i < listSize; i++) {
        if (oracle(target, list[i])) {
            printf("S | Target %d found at index %d.\n", target, i);
            return i;
        }
    }

    printf("Target not found in the list.\n");
    return -1;
}