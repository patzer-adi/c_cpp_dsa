#include <stdio.h>

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    if (n < 100)
        printf("Small number\n");
    else if (n > 100 && n <= 200)
        printf("Large number\n");
    else if (n > 1000)
        printf("Very large number\n");
    else
        printf("Between 201 and 1000\n");

    return 0;
}
