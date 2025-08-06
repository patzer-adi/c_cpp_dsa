#include<stdio.h>

int main()
{
    int n1,n2;
    do
    {
    printf("Enter two number:\n");
    scanf("%d %d",&n1,&n2);
    printf("Your Numbers are : %d %d\n",n1,n2);
    printf("\nSUm is: %d",n1+n2);
    }
    while(n1!=0 && n2 != 0);
    return 0;

}