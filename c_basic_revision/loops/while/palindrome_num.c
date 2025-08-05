#include<stdio.h>

int main()
{
    int n;
    int i = 0,sum=0,rev =0;

    printf("Enter a number:\n");
    scanf("%d",&n);
    int temp =n;
    printf("Number: %d\n",n);
    while(n != 0)
    {
        sum = n % 10;
        n = n / 10;
        rev = rev * 10 + sum;
    }

    if(rev == temp)
        printf("Palindrome");
    else
        printf("Not Palindrome");
    return 0;
}
