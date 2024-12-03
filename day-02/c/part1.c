#include <stdio.h>
#include <stdbool.h>
#include "../../utils/io_utils.h"

#define M 100

int main(void) {
    int reports[M], n, order, i, diff, safe_count = 0;
    bool safe;
    while ((n = read_ints(stdin, reports))) {
        safe = true;
        if (n > 1) {
            order = reports[1] > reports[0] ? 1 : -1;
            for (i = 1; i < n; i++) {
                diff = reports[i] - reports[i - 1];
                if (order == 1) {
                    if (!(diff >= 1 && diff <= 3)) {
                        safe = false;
                        break;
                    }
                } else {
                    if (!(diff >= -3 && diff <= -1)) {
                        safe = false;
                        break;
                    }
                }
            }
            if (safe) safe_count++;
        }
    }
    printf("%d\n", safe_count);
    return 0;
}