#include<stdio.h>

int main()
{
    int n;
    printf("Enter a number:\n");
    scanf("%d",&n);

    printf("Table\n");
    int i = 2;
    while(i <= n)
    {
        printf("Table for %d\n",i);
        int j = 1;
        while(j <= 12)
        {
        printf("%d x %d = %d\n",i,j,n*j);
        j++;
        }
        printf("\n");
        ++i;
    }
    return 0;
}