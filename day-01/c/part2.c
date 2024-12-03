#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../utils/io_utils.h"

#define N 1000
#define M 100000

int int_compare(const void *a, const void *b);
int get_difference_sum(int *arr1, int *arr2);
int get_similarity_score(int *arr1, int *arr2, int* counts);

int main(int argc, char *argv[]) {
    int arr1[N], arr2[N], counts[M], line[2];
    int idx = 0;

    for (int i = 0; i < M; i++) counts[i] = 0;

    while (read_ints(stdin, line) > 0) {
        arr1[idx] = line[0];
        arr2[idx] = line[1];
        counts[arr2[idx]]++;
        idx++;
    }

    qsort((void *) arr1, idx, sizeof(int), int_compare);
    qsort((void *) arr2, idx, sizeof(int), int_compare);

    int diff_sum = get_difference_sum(arr1, arr2);
    int sim_score = get_similarity_score(arr1, arr2, counts);

    printf("%d\n", diff_sum);
    printf("%d\n", sim_score);

    return 0;
}

int get_difference_sum(int *arr1, int *arr2) {
    int diff_sum = 0;
    for (int i = 0; i < N; i++) {
        diff_sum += abs(arr1[i] - arr2[i]);
    }
    return diff_sum;
}

int get_similarity_score(int *arr1, int *arr2, int *counts) {
    int sim_score = 0;
    for (int i = 0; i < N; i++) {
        sim_score += (arr1[i] * counts[arr1[i]]);
    }
    return sim_score;
}

int int_compare(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}