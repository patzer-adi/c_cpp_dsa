#include <stdio.h>

void run()
{
    int n, num, max;

    printf("Enter the number of inputs: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        printf("Enter number %d: ", i);
        scanf("%d", &num);

        if (i == 1)
            max = num;
        else
            max = (num > max) ? num : max;

        printf("%d input max: %d\n", i, max);
    }
}

int main() 
    {
    run();

    return 0;
    }
