#include<stdio.h>

// consant time complexity O(1)
int main()
{
    int n,sum;
    printf("Enter a number:\n");
    scanf("%d",&n);
    sum = (n+(n*n));
    // sum = n(n+1) [alternative method]
    printf("Sum: %d",sum);
    return 0;
}