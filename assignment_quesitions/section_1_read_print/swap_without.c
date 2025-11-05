#include<stdio.h>

int main()
{
    int n1, n2;
    printf("Enter two numbers");
    scanf("%d%d",&n1,&n2);
    printf("Before swap:\nn1: %d\nn2: %d\n",n1,n2);
    n1 = n1 + n2;
    n2 = n1 - n2;
    n1 = n1 - n2;
    printf("After swap:\nn1: %d\nn2: %d\n",n1,n2);
    return 0;
}
