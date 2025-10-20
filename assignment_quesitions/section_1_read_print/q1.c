#include <stdio.h>

int main() {
    int a, b;

    // Input two integers
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

    // Addition
    a = a + b;          // store sum in 'a'
    printf("Addition: %d\n", a);

    // Subtraction
    b = a - b;          // original a = a+b, so b = (a+b)-b = a
    a = a - b;          // original b = a+b - a = b
    printf("After swapping to demonstrate subtraction logic:\n");
    printf("Subtraction: %d\n", a - b); // a - b

    // Division (a / b)
    // Note: we can reuse 'a' and 'b' but must ensure b != 0
    if(b != 0) {
        a = a / b;      // stores a/b in a
        printf("Division (a/b): %d\n", a);
    } else {
        printf("Division by zero is not allowed.\n");
    }

    return 0;
}
