#include<stdio.h>
// pattern
/*
pyramid pattern
 *
 */

void run()
{
    int m,n,i,j,k;
    printf("Enter n:\n");
    scanf("%d",&n);
    for(i = 1; i <= n; ++i)
    {
        for(k = 1; k <= n - i ; k++)
        {
            printf("  ");
        }
        for(j = 1 ; j <= (2 * i - 1 ); ++j)
        {
            printf("* ");
        }
        printf("\n");
    }

}

int main()
{
    run();
    return 0;
}
