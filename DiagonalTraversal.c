#include <stdio.h>

void diagonalTraversal(int n, int mat[n][n]) {
    int total = 2 * n - 1;
    int diag[total][n];
    int size[total];

    // Initialize sizes
    for (int i = 0; i < total; i++) {
        size[i] = 0;
    }

    // Store diagonals
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int d = i + j;
            diag[d][size[d]] = mat[i][j];
            size[d]++;
        }
    }

    // Print result
    for (int i = 0; i < total; i++) {
        for (int j = 0; j < size[i]; j++) {
            printf("%d ", diag[i][j]);
        }
    }
}

int main() {
    int n = 3;

    int mat[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    diagonalTraversal(n, mat);
    return 0;
}
