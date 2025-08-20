#include <stdio.h>

void run()
{
    int n;
    printf("Enter n:\n");
    scanf("%d", &n);

    int a = 1, b = 1, sum = 0;

    while (a < n)
    {
        if (a % 5 == 0)
            sum += a;

        int temp = a + b;
        a = b;
        b = temp;
    }

    printf("Sum = %d\n", sum);

}

int main()
{
    run();
    return 0;
}
