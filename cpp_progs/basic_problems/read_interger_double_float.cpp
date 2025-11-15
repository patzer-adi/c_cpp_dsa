#include <stdio.h>

int main() {
    char str[50];

    printf("Enter a string: ");
    scanf("%s", str);   // <-- DOES NOT read spaces!

    printf("You entered: %s\n", str);
    return 0;
}
