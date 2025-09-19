#include <stdio.h>
#include <stdlib.h>

void run()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Dynamically allocate memory
    int *arr = (int*) malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    double avg = (double)sum / n;
    printf("The average of the array elements is: %.2lf\n", avg);

    free(arr);
    return;
}

int main() {
    run();
    return 0;
}