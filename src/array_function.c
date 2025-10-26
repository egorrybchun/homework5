#include "../include/array_function.h"
#include <stdio.h>
#include <stdlib.h>

int* join_int_arrays(int* src1, size_t size_src1, int* src2, size_t size_src2) {
    int* dest = (int*)malloc((size_src1 + size_src2) * sizeof(int));

    if (dest == NULL) {
        return NULL;
    }

    for (size_t i = 0; i < size_src1; i++) {
        dest[i] = src1[i];
    }

    for (size_t i = 0; i < size_src2; i++) {
        dest[size_src1 + i] = src2[i];
    }

    return dest;
    free(dest);
}

int* join_and_sort_int_arrays(int* src1, size_t size_src1, int* src2, size_t size_src2) {
    int* dest = (int*)malloc((size_src1 + size_src2) * sizeof(int));

    if (dest == NULL) {
        return NULL;
    }

    size_t i1 = 0, i2 = 0, i3 = 0;

    while (i1 < size_src1 && i2 < size_src2) {
        if (src1[i1] <= src2[i2]) {
            dest[i3++] = src1[i1++];
        } else {
            dest[i3++] = src2[i2++];
        }
    }

    while (i1 < size_src1) {
        dest[i3++] = src1[i1++];
    }

    while (i2 < size_src2) {
        dest[i3++] = src2[i2++];
    }

    return dest;
    free(dest);
}

void get_min_and_max_from_int_array(int* src, size_t size, int* min, int* max) {
    if (size == 0) {
        return;
    }

    *min = src[0];
    *max = src[0];

    for (size_t i = 1; i < size; i++) {
        if (src[i] < *min) {
            *min = src[i];
        }
        if (src[i] > *max) {
            *max = src[i];
        }
    }
}
