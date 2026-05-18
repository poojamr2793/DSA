#include <stdio.h>

int lowerBound(int arr[], int n, int target) {
  
    // compare target with each element in array
    for (int i = 0; i < n; ++i) {
      
        // if equal or larger value found
        // return its index
        if(arr[i] >= target) {
            return i;
        }
    }
  	
    // if all elements are smaller, return length
    return n;
}

int main() {
    int arr[] = {2, 3, 7, 10, 11, 11, 25};
    int target = 9;
    int n = sizeof(arr) / sizeof(arr[0]);
  
    printf("%d", lowerBound(arr, n, target));
    return 0;
}
