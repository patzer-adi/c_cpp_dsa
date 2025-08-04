#include<stdio.h>

int main()
{
    int n,count=0,sum=0;
    printf("Enter a number:");
    scanf("%d",&n);
    while(n != 0)
    {
        sum = n % 10;
        n = n / 10;
        ++count;
    }
    printf("Count number of Digits: %d\n",count);
    return 0;
}
