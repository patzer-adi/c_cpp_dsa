#include<stdio.h>

int main()
{
    int n;
    do
    {
    printf("Enter a number:\n");
    scanf("%d",&n);
    printf("Your Number is : %d\n",n);
    if (n!=0) printf("Hint: still not zero"); else printf("exit");
    }
    while(n!=0);
    return 0;

}