#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// returns the maximum achievable minimum 
// absolute difference
int helper(int i, int remk, int prev,
                vector<int>& arr, int k,
                vector<vector<vector<int>>>& memo) {

    // no more comparisons needed, neutral value
    if (remk == k)
        return INT_MAX; 

    // invalid, ran out of elements
    if (i == arr.size())
        return -1;

    if (memo[i][remk][prev + 1] != -2)
        return memo[i][remk][prev + 1];

    // skip current element
    int skip = 
        helper(i + 1, remk, prev, arr, k, memo);

    // take current element
    int diff = 
        (prev == -1) ? INT_MAX : abs(arr[i] - arr[prev]);
    int next = helper(i + 1, remk + 1, i, arr, k, memo);
    int take = (next == -1) ? -1 : min(diff, next);

    // store and return the max of both choices
    return memo[i][remk][prev + 1] = max(skip, take);
}

int maxMinDiff(vector<int>& arr, int k) {

    sort(arr.begin(), arr.end());
    int n = arr.size();

    // initialize 3D memo with -2 (uncomputed)
    vector<vector<vector<int>>> memo(n + 1,
        vector<vector<int>>(k + 1, vector<int>(n + 1, -2)));

    return helper(0, 0, -1, arr, k, memo);
}

int main() {

    vector<int> arr = {1, 4, 9, 0, 2, 13, 3};
    int k = 4;
    cout << maxMinDiff(arr, k) << endl; 

    return 0;
}
