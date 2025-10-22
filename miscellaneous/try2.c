#include<stdio.h>
int main()
{
    int n=0, rem=0;
    printf("Enter a number: ");
    scanf("%d",&n);
    for(int i=0;i<=n;i++){

    rem = n%10;
    printf("%d",rem);
    n=n/10;
    }
    return 0;
} 