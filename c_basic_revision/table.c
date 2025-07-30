#include<stdio.h>

int main()
{
    int n;
    printf("Enter a number:\n");
    scanf("%d",&n);

    printf("Table\n");
    for(int i = 0; i <= 12; ++i)
    {
        printf("%d x %d = %d\n",n,i,n*i);
    }
    return 0;
}