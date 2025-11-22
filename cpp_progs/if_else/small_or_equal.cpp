#include <stdio.h>

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    if (n < 10)
        printf("Small number\n");
    else if (n > 10)
        printf("Large number\n");
    else
        printf("Equal to 10\n");

    return 0;
}
