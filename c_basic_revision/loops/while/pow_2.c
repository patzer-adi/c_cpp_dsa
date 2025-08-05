#include<stdio.h>

int main()
{
    int x,y,count=0,pow=1;
    printf("Enter a number x:\n");
    scanf("%d",&x);
    printf("Enter a number y:\n");
    scanf("%d",&y);
    while(0 < y)
    {
       pow = pow*x;
       printf("pow: %d\n",pow);
       --y;
    }
    printf("Power: %d\n",pow);
    return 0;
}
