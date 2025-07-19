#include<stdio.h>

int main()
{
    int n,rev=0,sum=0;
    printf("Enter a number:");
    scanf("%d",&n);
    while(n != 0)
    {
        sum = n % 10;
        n = n / 10;
        rev = rev * 10 + sum;
    }
    printf("Reverse: %d\n",rev);
    return 0;
}
