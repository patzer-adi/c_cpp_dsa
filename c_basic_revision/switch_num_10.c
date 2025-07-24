#include<stdio.h>

int main()
{
    int n,res;
    printf("Enter a number of +ve / -ve:\n");
    scanf("%d",&n);
    res = (n<10)?(0):(n==10)?(-1):(1);
    switch(res)
    {
        case 0:
        printf("Small");
        break;
        case 1:
        printf("Larger");
        break;
        default:
        printf("Equal");
        break;
    }

    return 0;
}