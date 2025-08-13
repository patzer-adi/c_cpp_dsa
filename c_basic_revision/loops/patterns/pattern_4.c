#include<stdio.h>
//pattern
/*
*       *       *
*       *       *
*       *       *
*       *       *
*/

void run()
{
    int m,n,i,j,k;
    printf("Enter m x n:\n");
    scanf("%d %d",&n, &m);
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++ )
        {
        printf("*\t");
        }
        printf("\n");
    }

}

int main()
{
    run();
    return 0;
}