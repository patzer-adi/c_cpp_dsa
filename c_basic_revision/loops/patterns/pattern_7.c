#include<stdio.h>
// pattern
/*

*/

void run()
{
    int m,n,i,j,k;
    printf("Enter n:\n");
    scanf("%d",&n);
    for(i = n; i > 0; i--)
    {
        for(j = i ; j > 0; j++)
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