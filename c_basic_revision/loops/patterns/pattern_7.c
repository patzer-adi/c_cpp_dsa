#include<stdio.h>
// pattern
/*
                *
             *  *
          *  *  *
       *  *  *  *
    *  *  *  *  *
 *  *  *  *  *  *

*/

void run()
{
    int m,n,i,j,k;
    printf("Enter n:\n");
    scanf("%d",&n);
    for(i = 0; i <= n; ++i)
    {
        for(int k = 0; k < n - i; k++)
        {
            printf("   ");
        }
        for(j = 0 ; j <= i; ++j)
        {
        printf(" * ");
        }
        printf("\n");
    }

}

int main()
{
    run();
    return 0;
}
