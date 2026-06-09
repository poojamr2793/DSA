#include <stdio.h>

int upperBound(int arr[], int n, int target) {

    // Compare target with each element in array
    for (int i = 0; i < n; ++i) {

        // If larger value found, return its index
        if (arr[i] > target) {
            return i;
        }
    }

    // If all elements are smaller, return length
    return n;
}

int main() {
    int arr[] = {2, 3, 7, 10, 11, 11, 25};
    int target = 11;
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("%d", upperBound(arr, n, target));
    return 0;
}
