#include<stdio.h>

int main()
{
    int n,i=1,cnt=0;
    printf("Enter a number:");
    scanf("%d",&n);
    printf("factors:\n");
    while(i <= n/2)
    {
        if(n % i == 0)
        {
            cnt++;
            printf("%i,\t",n);
        }
        i++;
    }
    printf("%d\n",cnt);

    if(cnt < 2)
        printf("%d is a prime\n",n);
    else
        printf("%d is not a prime\n",n);
    return 0;
}
