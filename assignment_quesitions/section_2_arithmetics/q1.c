//

// Accept an integer x and compute: x
// 2 and x
// 2 + 2x #include <stdio.h>

int main() {
    int x;
    int result1, result2;

    // Input integer
    printf("Enter an integer value for x: ");
    scanf("%d", &x);

    // Compute expressions
    result1 = x * x;             // x²
    result2 = (x * x) + (2 * x); // x² + 2x

    // Display results
    printf("x^2 = %d\n", result1);
    printf("x^2 + 2x = %d\n", result2);

    return 0;
}
