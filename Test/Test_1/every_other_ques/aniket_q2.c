#include <stdio.h>

void run()
{
        int num, sum = 0;

    while (1) {
        printf("Enter a number (-1 to stop): ");
        scanf("%d", &num);

        if (num == -1)
            break;

        sum += num;
        printf("Sum = %d\n", sum);

        if (sum % 13 == 0 && sum != 0) {
            printf("Sum divisible by 13. Resetting sum to 0.\n");
            sum = 0;
        }
    }

    return;
}

int main() {
    run();
    return 0;
}
