#include<stdio.h>

int main()
{
    int n,i=1,cnt=0;
    printf("Enter a number:");
    scanf("%d",&n);
    printf("factors:\n");
    for(i= 1;i <= n ; i++)
    {
        if(n % i == 0)
        {
            printf("%i,\t",i);
            break;
        }
    }

    if(cnt == 0)
        printf("%d is a prime\n",n);
    else
        printf("%d is not a prime\n",n);
    return 0;
}