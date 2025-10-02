#include <stdio.h>
#include <stdlib.h>

// Bubble Sort function
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n, i;
    int *arr;
    long long goodPairs = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Step 1: Sort with bubble sort
    bubbleSort(arr, n);

    // Step 2: Count good pairs using frequencies
    int count = 1;
    for (i = 1; i <= n; i++) {
        if (i < n && arr[i] == arr[i - 1]) {
            count++;
        } else {
            goodPairs += (long long)count * (count - 1) / 2;
            count = 1;
        }
    }

    printf("Number of good pairs: %lld\n", goodPairs);

    free(arr);
    return 0;
}
