#include <stdio.h>

void run()
{
    int n;
    printf("Enter score (0-100):\n");
    scanf("%d", &n);

    (n >= 0 && n <= 100) ? 
        (n >= 40 ? 
            (printf("Pass\n"), (n >= 90 ? printf("Excellent!\n") : printf("Keep improving!\n"))) 
            : printf("Fail\n")) 
        : printf("Invalid Input\n");
}

int main()
{
    run();
    return 0;
}
