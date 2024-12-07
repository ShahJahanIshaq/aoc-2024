#include <stdio.h>
#include <stdbool.h>
#include "../../utils/io_utils.h"

#define MAX_NUMS 100

int nums[MAX_NUMS] = {0};
int n;
long ans, total;

bool backtrack(int curr_idx, long curr_ans);

int main(void) {
    long curr_ans;
    while (scanf("%ld: ", &ans) != EOF) {
        n = read_ints(stdin, nums);
        curr_ans = nums[0];
        backtrack(1, curr_ans);
    }

    printf("%ld\n", total);
    return 0;
}

bool backtrack(int curr_idx, long curr_ans) {
    if (curr_idx == n) {
        if (curr_ans == ans) {
            total += ans;
            return true;
        }
        return false;
    }
    // add curr_idx-th element
    if (backtrack(curr_idx + 1, curr_ans + nums[curr_idx])) {
        return true;
    }
    // multiply curr_idx-th element
    if (backtrack(curr_idx + 1, curr_ans * nums[curr_idx])) {
        return true;
    }
    return false;
}