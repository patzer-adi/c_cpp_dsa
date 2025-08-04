#include<stdio.h>

int main()
{
    int n,fact=1;
    printf("Enter a number to find factorial:");
    scanf("%d",&n);
    for(; n !=0 ;)
    {
        fact = n * fact;
        n = n - 1;
        printf("n: %d and %d\n",n,fact);
    }
    printf("Factorial: %d",fact);
}