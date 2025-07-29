#include<stdio.h>

// consant time complexity O(1)
int main()
{
    int n,sum;
    printf("Enter a number:\n");
    scanf("%d",&n);
    sum = (n*(n+1))/2;
    printf("Sum: %d",sum);
    return 0;
}