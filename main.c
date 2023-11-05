#include <stdio.h>
#include "Grov_seq.h"
#include "Grov_para.h"
#include <stdbool.h>
#include <stdlib.h>
#include <omp.h>

int main (){
    int list[] = {3, 6, 8, 7, 12, 4, 2};
    int listSize = sizeof(list) / sizeof(list[0]);
    int target = 7;
    groverAlgorithm(target, list, listSize);
    groverAlgorithm_para(target, listSize);

    return 0;
}

