#include<stdio.h>

void run()
{
    int n;
    while(1)
    {
    printf("Enter numbers:\n");
    scanf("%d",&n);
    if(n<0)
    {
        printf("-ve number entered:");
        break;
    }
    }
}

int main()
{
    run();
    return 0;
}