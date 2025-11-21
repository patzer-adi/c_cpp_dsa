#include <stdio.h>

int main() {
    int n;
    float result;
    printf("Enter a number: ");
    scanf("%d", &n);

    if (n >= 100 && n <= 200) {
        result = n / 3.0;
        if (result < 50)
            printf("Small number\n");
        else
            printf("Not so big number\n");
    }
    else if (n > 200 && n <= 300) {
        result = n / 2.0;
        if (result < 110)
            printf("Result = %.2f\n", result);
        else {
            result /= 5.0;
            printf("Result = %.2f\n", result);
        }
    }
    else if (n > 300) {
        printf("Very big number\n");
    }
    else {
        printf("Less than 100\n");
    }

    return 0;
}
