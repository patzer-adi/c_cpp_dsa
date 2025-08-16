#include <stdio.h>

void run()
{
    int num, original, remainder, result = 0, digits = 0;

    printf("Enter a number: ");
    scanf("%d", &num);

    original = num;

    int temp = num;
    while (temp != 0) {
        temp /= 10;
        digits++;
    }

    temp = num;

    while (temp != 0) {
        remainder = temp % 10;

        int power = 1;
        for (int i = 0; i < digits; i++) {
            power *= remainder;
        }

        result += power;
        temp /= 10;
    }

    if (result == original)
        printf("%d is an Armstrong number.\n", original);
    else
        printf("%d is not an Armstrong number.\n", original);

}

int main() {
    
    run();
    return 0;
}
