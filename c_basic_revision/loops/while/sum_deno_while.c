#include<stdio.h>

int main()
{
    int n;
    double ans = 0;

    printf("Enter a number:\n");
    scanf("%d",&n);
    int i = 0;
    while(i < n)
    {
        ans = ans + (1 / i+1);
        printf("%2f\n",ans);
        ++i;
    }
    printf("Answer: %2f",ans);
    return 0;
}
