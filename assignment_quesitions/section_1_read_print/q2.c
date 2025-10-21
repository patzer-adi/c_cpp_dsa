#include <stdio.h>

int main() {
    int a, b, result;  // 'result' is the third variable

    // Input two integers
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

    // Addition
    result = a + b;
    printf("Addition: %d + %d = %d\n", a, b, result);

    // Subtraction
    result = a - b;
    printf("Subtraction: %d - %d = %d\n", a, b, result);

    // Division (check for division by zero)
    if(b != 0) {
        result = a / b;
        printf("Division: %d / %d = %d\n", a, b, result);
    } else {
        printf("Division by zero is not allowed.\n");
    }

    return 0;
}
