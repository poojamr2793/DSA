#include <stdio.h>
#include <stdlib.h>

int* findSurpasser(int arr[], int n) {
  
    // Array to store surpasser counts
    int* res = (int*)malloc(n * sizeof(int));
  
    for (int i = 0; i < n; i++) {

        // Find surpasser for arr[i]
        int count = 0;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[i])
                count++;
        }
        res[i] = count;
    }
  
    return res;
}

int main() {
    int arr[] = {2, 7, 5, 3, 8, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int* res = findSurpasser(arr, n);
    for (int i = 0; i < n; i++)
        printf("%d ", res[i]);
    
    return 0;
}
