#include <stdio.h>

#define N 9

// Function to print Sudoku
void print(int grid[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%d ", grid[i][j]);
        printf("\n");
    }
}

// Check if safe
int isSafe(int grid[N][N], int row, int col, int num) {
    // Row check
    for (int x = 0; x < N; x++)
        if (grid[row][x] == num)
            return 0;

    // Column check
    for (int x = 0; x < N; x++)
        if (grid[x][col] == num)
            return 0;

    // 3x3 box check
    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[i + startRow][j + startCol] == num)
                return 0;

    return 1;
}

// Solve Sudoku using Backtracking
int solve(int grid[N][N]) {
    int row, col, found = 0;

    // Find empty cell
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (grid[row][col] == 0) {
                found = 1;
                goto END;
            }
        }
    }

END:
    if (!found)
        return 1; // solved

    // Try numbers 1-9
    for (int num = 1; num <= 9; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;

            if (solve(grid))
                return 1;

            // Backtrack
            grid[row][col] = 0;
        }
    }

    return 0;
}

int main() {
    int grid[N][N] = {
        {3,0,6,5,0,8,4,0,0},
        {5,2,0,0,0,0,0,0,0},
        {0,8,7,0,0,0,0,3,1},
        {0,0,3,0,1,0,0,8,0},
        {9,0,0,8,6,3,0,0,5},
        {0,5,0,0,9,0,6,0,0},
        {1,3,0,0,0,0,2,5,0},
        {0,0,0,0,0,0,0,7,4},
        {0,0,5,2,0,6,3,0,0}
    };

    if (solve(grid))
        print(grid);
    else
        printf("No solution exists");

    return 0;
}
