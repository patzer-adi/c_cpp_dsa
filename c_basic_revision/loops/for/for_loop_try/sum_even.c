#include<stdio.h>

int main()
{
    int n,sum = 0;
    printf("Enter a number:\n");
    scanf("%d",&n);
    for(int i = 0; i < n; ++i)
    {
        if(i % 2 == 0)
        {
        printf("%d\n",i);
        sum = i + sum;
        }
    }
    printf("Sum till n: %d",sum);
    return 0;
}