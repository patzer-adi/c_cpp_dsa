#include <stdio.h>

int main() {
    int n;
    float result;

    printf("Enter a number: ");
    scanf("%d", &n);

    switch (n) {
        case 10:
        case 20:
        case 30:
            result = n / 2.0;
            break;

        case 40:
        case 50:
            result = n / 3.0;
            break;

        default:
            result = n / 4.0;
    }

    printf("Result = %.2f\n", result);

    return 0;
}
