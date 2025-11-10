#include<stdio.h>

int main()
{
    int n1,n2,add,sub,mul,div,mod;
    printf("Enter n1 and n2:\n");
    scanf("%d %d",&n1,&n2);
    add = n1+n2;
    sub = n1-n2;
    mul = n1*n2;
    div = n1/n2;
    mod = n1%n2;
    printf("\nAddition: %d",add);
    printf("\nSubstraction: %d",sub);
    printf("\nMultiplication: %d",mul);
    printf("\nDivision: %d",div);
    printf("\nRemainder: %d",mod);

    return 0;
}
