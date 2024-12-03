#include <stdio.h>
#include <stdbool.h>
#include "../../utils/io_utils.h"

#define M 100

int main(void) {
    int reports[M], dupReports[M - 1], n, order, i, j, i2, diff, safe_count = 0;
    bool safe;
    while ((n = read_ints(stdin, reports))) {
        for (j = 0; j < n; j++) {
            safe = true;
            for (i2 = 0, i = 0; i2 < n; i2++) {
                if (i2 == j) continue;
                dupReports[i++] = reports[i2];
            }
            if (n - 1 > 1) {
                order = dupReports[1] > dupReports[0] ? 1 : -1;
                for (i = 1; i < n - 1; i++) {
                    diff = dupReports[i] - dupReports[i - 1];
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
            }
            if (safe) {
                safe_count++;
                break;
            }
        }
    }
    printf("%d\n", safe_count);
    return 0;
}