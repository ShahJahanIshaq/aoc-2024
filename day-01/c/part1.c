#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../utils/io_utils.h"

#define N 1000

int int_compare(const void *a, const void *b);
int get_difference_sum(int *arr1, int *arr2);

int main(int argc, char *argv[]) {
    int arr1[N], arr2[N], line[2];
    int idx = 0;

    while (read_ints(stdin, line) > 0) {
        arr1[idx] = line[0];
        arr2[idx] = line[1];
        idx++;
    }

    qsort((void *) arr1, idx, sizeof(int), int_compare);
    qsort((void *) arr2, idx, sizeof(int), int_compare);

    int diff_sum = get_difference_sum(arr1, arr2);

    printf("%d\n", diff_sum);

    return 0;
}

int get_difference_sum(int *arr1, int *arr2) {
    int diff_sum = 0;
    for (int i = 0; i < N; i++) {
        diff_sum += abs(arr1[i] - arr2[i]);
    }
    return diff_sum;
}

int int_compare(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}