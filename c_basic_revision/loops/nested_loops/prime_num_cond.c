//work it out

#include<stdio.h>

int main()
{
    int n,i,j;
    printf("Enter a number:\n");
    scanf("%d",&n);
    printf("Prime numbers:\n");
    for(int i = 2; i <= n; ++i)
    {
        int flag = 0;
        for(j = 2; j <= i / 2; ++j)
        {
        if(i % j == 0)
        {
            flag = 1;
            break;
        }
        }
        if(flag == 0)
            printf("%d\n",i);
    }
    return 0;
}