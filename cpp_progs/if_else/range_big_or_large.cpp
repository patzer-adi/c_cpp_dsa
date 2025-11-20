#include <stdio.h>

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    if (n >= 100 && n <= 200)
        printf("Small number\n");
    else if (n >= 201 && n <= 300)
        printf("Big number\n");
    else if (n >= 301 && n <= 400)
        printf("Large number\n");
    else if (n > 401)
        printf("Very large number\n");
    else
        printf("Below 100\n");

    return 0;
}
