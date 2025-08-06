#include<stdio.h>

int main()
{
    int n;
    printf("Enter a number:");
    scanf("%d",&n);
    do    
    {
        printf("%d\n",n % 10);
        n = n / 10;
    }while(n>0);
    return 0;
}