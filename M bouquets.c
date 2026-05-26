#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// function to check if the given number of days is
// valid for creating bouquets
bool check(vector<int> &arr, int k, int m, int days) {
    int bouquets = 0;
    int cnt = 0;

    // iterate through the bloom days of the flowers
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] <= days) {
            cnt += 1;
        }
        else {

            // if the current bloom day count is greater
            // than days, update bouquets and reset count
            bouquets += cnt / k;
            cnt = 0;
        }
    }

    bouquets += cnt / k;

    // check if current bouquets are greater than or
    // equal to the desired number of bouquets (m)
    return bouquets >= m;
}

int minDaysBloom(vector<int> &arr, int k, int m) {
    int maxDays = *max_element(arr.begin(), arr.end());

    for (int d = 0; d <= maxDays; d++) {
        if (check(arr, k, m, d))
            return d;
    }
    return -1;
}

int main() {
    vector<int> arr = {5, 5, 5, 5, 10, 5, 5};
    int k = 3, m = 2;

    cout << minDaysBloom(arr, k, m);
    return 0;
}
