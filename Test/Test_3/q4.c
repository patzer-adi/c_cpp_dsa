#include <stdio.h>
#include <stdlib.h>

void run()
{
    int n;

    // Read number of elements
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Dynamically allocate array
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Read elements
    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Counters for positive, negative, zero
    int positiveCount = 0, negativeCount = 0, zeroCount = 0;

    // Count positive, negative, and zero using for loop with if-else
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            positiveCount++;
        } else if (arr[i] < 0) {
            negativeCount++;
        } else {
            zeroCount++;
        }
    }

    // Print counts
    printf("Positive count: %d\n", positiveCount);
    printf("Negative count: %d\n", negativeCount);
    printf("Zero count: %d\n", zeroCount);

    // Nested loops to print pairs with positive sum
    printf("Pairs with positive sum:\n");
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((arr[i] + arr[j]) > 0) {
                printf("(%d, %d)\n", arr[i], arr[j]);
            }
        }
    }

    free(arr);
    return;
}

int main() {
    run();
    return 0;
}