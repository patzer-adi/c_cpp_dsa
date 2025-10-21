#include <stdio.h>

int main() {
    int a, b;

    // Input two numbers
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    // Swap using arithmetic
    a = a + b;  // Step 1
    b = a - b;  // Step 2
    a = a - b;  // Step 3

    printf("After swapping (arithmetic method):\n");
    printf("a = %d, b = %d\n", a, b);

    return 0;
}
