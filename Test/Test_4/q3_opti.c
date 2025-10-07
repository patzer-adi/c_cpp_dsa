#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;
    int *arr;
    int even_cnt = 0, odd_cnt = 0;

    printf("Enter the number of integers: ");
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

    for (i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            even_cnt++;
            arr[i] = 0; // Even
        } else {
            arr[i] = 1; // Odd
            odd_cnt;
        }
    }

    for (i = 0; i < n; i++) {
       if(i < even_cnt)
            arr[i] = 0;
        else
            arr[i] = 1;
    }


    printf("Output: [");
    for (i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    free(arr);
    return 0;
}
