
// 1. Write a C program to Reads n integers into a dynamically allocated array. Perform the following on the array :
// i. Replace each even number with 0 and odd number with 1. ii. Sort the modified array in non-decreasing order. Example :
// arr = 4,3,2,1
// Output: 0,0,1,1]
// - Replace the even numbers (4 and 2) with 0 and the odd numbers (3 and 1) with 1. Now,
// arr = [0. 1, 0, 1].
// - After sorting arr in non-descending order, arr = [0, 0, 1, 1].

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Replace even with 0, odd with 1
    for (int i = 0; i < n; i++)
        arr[i] = (arr[i] % 2 == 0) ? 0 : 1;

    // Sort in non-decreasing order (simple bubble sort)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("Modified and sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    free(arr);
    return 0;
}
