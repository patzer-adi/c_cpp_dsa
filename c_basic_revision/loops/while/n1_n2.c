#include<stdio.h>

int main()
{
    int n1,n2;

    while(n1!=0 && n2 != 0)
    {
    printf("Enter two numbers:\n");
    scanf("%d %d",&n1,&n2);
    printf("Your Numbers are : %d %d\n",n1,n2);
    printf("\nSUm is: %d\n",n1+n2);
    if(n1 == n2 && n2 == 0)
        printf("Hint: still not zeo");
    }
    return 0;

}