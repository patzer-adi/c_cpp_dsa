#include<stdio.h>

int main()
{
int i,j,k,n;
    float A[20][21], m, x[20], sum = 0.0,pivot;
    printf("Enter nxn of matrix:\n");
    scanf("%d",&n);

    printf("Enter the elments of augumented matrix:\n");
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= (n+1); j++)
        {
            printf("A[%d][%d]: ",i,j);
            scanf("%f",&A[i][j]);
        }//end for j
    }//end for i

    printf("Gauss elimination starts:\n");
    for(int i = 0; i <= n; i++)
    {

        for(int j = i + 1; j <= n + 1; i++)
        {
            A[i][j] = A[i][j] / A[i][i];
        }
    }

    return 0;
}