#include <stdio.h>

int main() {
    char ch;
    printf("Enter a character: ");
    scanf(" %c", &ch);   // space before %c prevents newline issues
    printf("You entered: %c\n", ch);
    return 0;
}
