// Given an array containing numbers from 1 to n with one number missing. (Hint: Use
// the formula n*(n+1)/2 or sum comparison).

#include <stdio.h>

int main() {
    int n;
    
    // Input the size of the array
    printf("Enter the size of the array (n-1 elements): ");
    scanf("%d", &n);

    int arr[n-1];
    printf("Enter %d elements (from 1 to %d, with one missing): ", n-1, n);
    for(int i = 0; i < n-1; i++) {
        scanf("%d", &arr[i]);
    }

    // Calculate the expected sum of 1 to n
    int expectedSum = n * (n + 1) / 2;

    // Calculate the sum of given elements
    int actualSum = 0;
    for(int i = 0; i < n-1; i++) {
        actualSum += arr[i];
    }

    // The missing number is the difference
    int missingNumber = expectedSum - actualSum;
    printf("The missing number is: %d\n", missingNumber);

    return 0;
}
