#include<stdio.h>

int main()
{
    int n;
    printf("Enter a number:\n");
    scanf("%d",&n);

    printf("Table\n");
    for(int i = 2; i <= n; ++i)
    {
        printf("Table for %d\n",i);
        for(int j = 1; j <= 12; j++)
        {
        printf("%d x %d = %d\n",i,j,n*j);
        }
        printf("\n");
    }
    return 0;
}