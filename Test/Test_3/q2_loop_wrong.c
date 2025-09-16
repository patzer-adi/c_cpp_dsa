#include<stdio.h>

// pattern
/*
 * 1
 * 12
 * 123
 * 1234
 * 12345
 *
 * i wrotet this program using for loop first then while loop so this for looped version
 *
 */

void run()
{
    int m,n,i,j,k;
    printf("Enter n:\n");
    scanf("%d",&n);
    for(i = 1; i <= n; i++)
    {
        for(j = 1 ; j <= i; j++ )
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
