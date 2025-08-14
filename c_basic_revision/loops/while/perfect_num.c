#include<stdio.h>

int main()
{
    int n1,i=1,cnt=0,factors1=0;
    printf("Enter a number:");
    scanf("%d",&n1);
    printf("factors n1:\n");
    while(i < n1)
    {
        if(n1 % i == 0)
        {
            cnt++;
            printf("%d,\t",i);
            factors1 = factors1 + i;
        }
        i++;
    }


    if(factors1 ==n1)
        printf("%d is a perfect number:\n",n1);
    else
        printf("%d is not perfect\n",n1);
    return 0;
}
