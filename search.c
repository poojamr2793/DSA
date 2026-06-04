#include <stdbool.h>
#include <stdio.h>

bool searchMatrix(int n, int m, int mat[n][m], int x)
{
    // Traverse every element in the matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == x)
                return true;
        }
    }
    return false;
}

int main()
{
    int mat[3][3] = {{1, 5, 9}, {14, 20, 21}, {30, 34, 43}};
    int n = 3, m = 3;
    int x = 14;

    if (searchMatrix(n, m, mat, x))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}
