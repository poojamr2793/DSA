#include <stdio.h>

int floorSqrt(int n) {
    
    // start iteration from 1 until the 
    // square of a number exceeds n
    int res = 1;
    while (res * res <= n) {
        res++;
    }
    
    // return the largest integer whose 
    // square is less than or equal to n
    return res - 1;
}

int main() {
    int n = 11;
    printf("%d", floorSqrt(n));
    return 0;
}
