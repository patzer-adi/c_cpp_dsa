#include<stdio.h>

void run()
{
    int n;
    int sum = 0;
    while(1)
    {
    printf("Enter numbers:\n");
    scanf("%d",&n);
    if(n<0)
    {
        printf("-ve number entered: (exit)\n");
        break;
    }
    sum += n;
    }

    printf("Sum of the +ve numbers is %d",sum);
}

int main()
{
    run();
    return 0;
}