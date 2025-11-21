#include <stdio.h>

int main() {
    int n;
    float result;

    printf("Enter a number: ");
    scanf("%d", &n);

    if (n == 10)
        result = n / 2.0;
    else if (n == 20)
        result = n / 3.0;
    else if (n == 30)
        result = n / 4.0;
    else if (n == 50)
        result = n / 5.0;
    else {
        printf("Number not matched.\n");
        return 0;
    }

    printf("Result = %.2f\n", result);

    return 0;
}
