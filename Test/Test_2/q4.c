#include <stdio.h>

void run()
{

    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        if( i % 2 == 1)
            printf("%d → Odd\n", i);
        else if (i % 2 == 0 && i % 4 == 0)
        {
            printf("%d → Even and multiple of 4\n", i);
        }
        else if (i % 2 == 0)
        {
            printf("%d → Even but not a multiple of 4\n", i);
        }
    }
    return;
}


int main() {

    run();
    return 0;
}
