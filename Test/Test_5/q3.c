// Write a C program to
// 1. Reads n as the dimension of an X n 2D array (matrix).
// 2. Perform the following on the matrix :
// i. Accept the f x n matrix
// ii. Compute and print the sum of all elements in the Oth row ii. Compute and print the multiplication of all elements in 1% column iv. Compute and print the sum of all elements in the anti-diagonal
// v. Compute and print the sum of all elements in the matrix

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

    // Sum of 0th row
    int sum_row = 0;
    for (int j = 0; j < n; j++)
        sum_row += matrix[0][j];
    printf("Sum of 0th row: %d\n", sum_row);

    // Product of 1st column
    int prod_col = 1;
    for (int i = 0; i < n; i++)
        prod_col *= matrix[i][1];
    printf("Product of 1st column: %d\n", prod_col);

    // Sum of anti-diagonal
    int sum_anti = 0;
    for (int i = 0; i < n; i++)
        sum_anti += matrix[i][n - 1 - i];
    printf("Sum of anti-diagonal: %d\n", sum_anti);

    // Sum of all elements
    int sum_all = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            sum_all += matrix[i][j];
    printf("Sum of all elements: %d\n", sum_all);

    return 0;
}
