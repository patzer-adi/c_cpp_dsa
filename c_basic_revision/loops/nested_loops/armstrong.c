#include <stdio.h>
#include <math.h>

void run()
{
    int lower, upper;

    printf("Enter lower bound: ");
    scanf("%d", &lower);

    printf("Enter upper bound: ");
    scanf("%d", &upper);

    printf("Armstrong numbers between %d and %d are:\n", lower, upper);

    for (int num = lower; num <= upper; num++) {
        int original = num;
        int sum = 0;
        int digits = 0;

        int temp = num;
        while (temp != 0) {
            temp /= 10;
            digits++;
        }

        temp = num;

        while (temp != 0) {
            int digit = temp % 10;

            int power = 1;
            for (int i = 0; i < digits; i++) {
                power *= digit;
            }

            sum += power;
            temp /= 10;
        }

        if (sum == original) {
            printf("%d\n", original);
        }
    }
}

int main() {
    
    run();
    return 0;
}
