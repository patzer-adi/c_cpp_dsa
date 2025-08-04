#include<stdio.h>

int main()
{
    int n,fact=1;
    printf("Enter a number to find factorial:");
    scanf("%d",&n);
    for(int i = n; n !=0 ; --n)
    {
        fact = n * fact;
        printf("n: %d and %d\n",n,fact);
    }
    printf("Factorial: %d",fact);
}