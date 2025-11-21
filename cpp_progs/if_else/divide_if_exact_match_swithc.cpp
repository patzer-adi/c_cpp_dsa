#include <stdio.h>

int main() {
    int n;
    float result;

    printf("Enter a number: ");
    scanf("%d", &n);

    switch (n) {
        case 10: result = n / 2.0; break;
        case 20: result = n / 3.0; break;
        case 30: result = n / 4.0; break;
        case 40: result = n / 5.0; break;
        default:
            printf("Number not matched.\n");
            return 0;
    }

    printf("Result = %.2f\n", result);

    return 0;
}
