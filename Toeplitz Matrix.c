#include <iostream>
#include<vector>
using namespace std;

// function to check if diagonal elements are same
bool checkDiagonal(vector<vector<int>> &mat, int x, int y) {
    int n = mat.size(), m = mat[0].size();

    for(int i = x + 1, j = y + 1; 
            i < n && j < m; i++, j++) {
        if(mat[i][j] != mat[x][y])
            return false;
    }
    return true;
}

// Function to check whether given
// matrix is toeplitz matrix or not
bool isToeplitz(vector<vector<int>> &mat) {
    int n = mat.size(), m = mat[0].size();

    // check each descending diagonal starting from
    // first row and first column of the matrix
    for(int i = 0; i < m; i++)
        if(!checkDiagonal(mat, 0, i))
            return false;

    for(int i = 0; i < n; i++) 
        if(!checkDiagonal(mat, i, 0))
            return false;
    
    return true;
}

int main() {
    vector<vector<int>> mat = {
        {6, 7, 8},
        {4, 6, 7},
        {1, 4, 6}
    };
    if(isToeplitz(mat)) {
        cout << "true";
    } else {
        cout << "false";
    }
    return 0;
}
