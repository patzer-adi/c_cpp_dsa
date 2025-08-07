#include<stdio.h>

int main()
{
    int n1,n2,i=1,cnt=0,factors1=0,factors2=0;
    printf("Enter a number:");
    scanf("%d",&n1);
    printf("Enter another number:");
    scanf("%d",&n2);
    printf("factors n1:\n");
    while(i <= n1/2)
    {
        if(n1 % i == 0)
        {
            cnt++;
            printf("%d,\t",i);
            factors1 = factors1 + i;
        }
        i++;
    }

    printf("factors n2:\n");
    i=1;
    while(i <= n2/2)
    {
        if(n2 % i == 0)
        {
            //cnt++;
            printf("%d,\t",i);
            factors2 = factors2 + i;
        }
        i++;
    }
    printf("%d\n",cnt);

    printf("\n%d and %d\n", factors1, factors2);
    if(factors1 ==n2 && n1 == factors2)
        printf("%d & %d are amicable\n",n1,n2);
    else
        printf("%d & %d are not amicable\n",n1,n2);
    return 0;
}