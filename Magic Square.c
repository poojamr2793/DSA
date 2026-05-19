#include <iostream>
#include <vector>
using namespace std;

bool isMagicSquare(vector<vector<int>>& mat) {
    int n = mat.size(); 
    int target = n * (n*n + 1) / 2;

    // track uniqueness
    vector<int> visited(n*n + 1, 0);

    int d1 = 0, d2 = 0;

    for (int i = 0; i < n; i++) {
        int rowSum = 0, colSum = 0;

        for (int j = 0; j < n; j++) {
            int valRow = mat[i][j];
            int valCol = mat[j][i];

            // range + duplicate check
            if (valRow < 1 || valRow > n*n || visited[valRow])
                return false;
            visited[valRow] = 1;

            rowSum += valRow;
            colSum += valCol;

            // diagonals
            if (i == j) d1 += valRow;
            if (i + j == n - 1) d2 += valRow;
        }

        if (rowSum != target || colSum != target)
            return false;
    }

    return d1 == target && d2 == target;
}

int main() {
    vector<vector<int>> mat = {
        {2,7,6},
        {9,5,1},
        {4,3,8}
    };

    cout << (isMagicSquare(mat) ? "Magic Square" : "Not a Magic Square");
    return 0;
}
