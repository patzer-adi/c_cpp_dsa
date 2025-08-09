#include<stdio.h>

int main()
{
    int n;
    unsigned long long fact=1;
    printf("Enter a number to find factorial:");
    scanf("%d",&n);
    for(int i = 1; i <= n ; ++i)
    {
        fact = i * fact;
        printf("i: %d and %llu\n",i,fact);
    }
    printf("Factorial: %llu",fact);
}