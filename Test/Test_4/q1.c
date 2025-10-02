#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, j;
    int *arr;
    int positiveCount = 0, negativeCount = 0, zeroCount = 0;

    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n; i++) {
        if (arr[i] > 0) {
            positiveCount++;
        } else if (arr[i] < 0) {
            negativeCount++;
        } else {
            zeroCount++;
        }
    }

    printf("Positive count: %d\n", positiveCount);
    printf("Negative count: %d\n", negativeCount);
    printf("Zero count: %d\n", zeroCount);

    printf("Pairs with positive sum:\n");
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] > 0) {
                printf("(%d, %d)\n", arr[i], arr[j]);
            }
        }
    }

    free(arr);
    return 0;
}
