#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define GRID_SIZE 256

bool is_within_grid(int row, int col, int rows, int cols);

char grid[GRID_SIZE][GRID_SIZE] = {0};

int main(void) {
    char line[GRID_SIZE] = {0};
    int i = 0;
    while (fgets(line, sizeof(line), stdin)) {
        line[strcspn(line, "\n")] = 0;
        strcpy(grid[i++], line);
    }
    int rows = i;
    int cols = strlen(grid[0]);
    printf("grid: %d %d\n", rows, cols);
    int start_row = -1, start_col;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == '^') {
                start_row = i;
                start_col = j;
                break;
            }
        }
        if (start_row >= 0) break;
    }
    printf("start: %d %d\n", start_row, start_col);

    int directions[4][2] = {
        {-1, 0}, {0, 1}, {1, 0}, {0, -1}
    };
    int directionIdx = 0;
    int curr_row = start_row, curr_col = start_col;
    int next_row, next_col;
    while (1) {
        next_row = curr_row + directions[directionIdx][0];
        next_col = curr_col + directions[directionIdx][1];
        if (is_within_grid(next_row, next_col, rows, cols)) {
            if (grid[next_row][next_col] == '#') {
                directionIdx++;
                directionIdx %= 4;
            } else {
                grid[curr_row][curr_col] = 'X';
                curr_row = next_row;
                curr_col = next_col;
            }
        } else {
            grid[curr_row][curr_col] = 'X';
            break;
        }
    }

    int visited_count = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 'X') {
                visited_count++;
            }
        }
    }

    printf("%d\n", visited_count);

    return 0;
}

bool is_within_grid(int row, int col, int rows, int cols) {
    if (row < 0 || col < 0 || row >= rows || col >= cols) {
        return false;
    }
    return true;
}