// 1       2       3       4
// 1       2       3
// 1       2
// 1
#include<stdio.h>

void run()
{
    int n;
    printf("Enter n:\n");
    scanf("%d",&n);
    for(int i = 1; i <= n; i++)
    {
        for(int j = i; j < n; j++)
        {
            printf("\t");
        }
        for(int j = 1; j <= i; j++)
        {
            printf("%d\t",j);
        }
        printf("\n");
    }
}

int main()
{
    run();
    return 0;
}