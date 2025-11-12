// (d) Write a C program to
// 1. Reads n as the dimension of an x n 2D array (matrix).
// 2. Perform the following on the matrix :
// i. Print the largest element in the matrix ii. Print the smallest element in the matrix ii. Print the largest element on the diagonal

#include <stdio.h>

int main() {
    int n;
    printf("Enter dimension n: ");
    scanf("%d", &n);

    int matrix[n][n];

    // Accept matrix
    printf("Enter elements of %dx%d matrix:\n", n, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &matrix[i][j]);

    int largest = matrix[0][0];
    int smallest = matrix[0][0];
    int largest_diag = matrix[0][0];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] > largest)
                largest = matrix[i][j];
            if (matrix[i][j] < smallest)
                smallest = matrix[i][j];
        }
        if (matrix[i][i] > largest_diag)
            largest_diag = matrix[i][i];
    }

    printf("Largest element in matrix: %d\n", largest);
    printf("Smallest element in matrix: %d\n", smallest);
    printf("Largest element on diagonal: %d\n", largest_diag);

    return 0;
}
