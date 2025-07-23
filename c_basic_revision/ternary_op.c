#include<stdio.h>

int main()
{
    int n,res;
    printf("Enter a number of +ve / -ve:\n");
    scanf("%d",&n);
    
    res = (n>0)?(printf("+ve\n")):(n==0)?(printf("is zero\n")):(printf("-ve\n"));
    printf("Result in res: %d\n",res);

    printf("Enter a number for even odd:\n");
    scanf("%d",&n);
    res = (n % 2 == 0)?(printf("even\n")):(printf("odd\n"));


    printf("Enter a year:\n");
    scanf("%d",&n); 
    
    res = ((n % 4 == 0)&& (n % 100!=0 || n % 400 == 0))?(printf("leap\n")):(printf("not leap\n"));

    int n1,n2;
    printf("Enter two numbers:\n");
    scanf("%d %d",&n1,&n2);
    res = (n1>n2)?(printf("a greater\n")):(printf("b greater\n"));
    printf("Result in res: %d\n",res);

    


    return 0;
}