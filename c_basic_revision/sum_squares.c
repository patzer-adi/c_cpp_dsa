#include<stdio.h>

int main()
{
    int n,ans=0;
    printf("Enter a number:\n");
    scanf("%d",&n);

    for(int i = 0; i <= n; ++i)
    {
        ans = ans + i*i;
        printf("%d\n",ans);

    }
    printf("Answer: %d",ans);
    return 0;
}