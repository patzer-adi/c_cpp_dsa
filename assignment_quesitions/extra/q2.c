// Write a program to rotate the array elements to the right by k positions.
// Example: [1,2,3,4,5] → [5,1,2,3,4] for k=1.
#include <stdio.h>

int main() {
    int n, k;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements: ", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter number of positions to rotate: ");
    scanf("%d", &k);

    k = k % n;

    int temp[n];

    for(int i = 0; i < n; i++) {
        temp[(i + k) % n] = arr[i];
    }

    for(int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }

    printf("Array after rotating right by %d positions: ", k);
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
