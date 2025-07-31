#include<stdio.h>

int main()
{
    int n;
    printf("Enter a number:\n");
    scanf("%d",&n);
    if(n == 0)
        printf("zero\n");
    else if(n > 0)
        printf("positive\n");
    else
        printf("Negative\n");
    return 0;
}
