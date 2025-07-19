#include<stdio.h>

int main()
{
    int n,cnt,fact=1;
    printf("Enter a number to find factorial:");
    scanf("%d",&n);
    while(n != 0)
    {
        fact = n * fact;
        n = n - 1;
    }
    printf("factorial: %d\n",fact);
    return 0;
}
