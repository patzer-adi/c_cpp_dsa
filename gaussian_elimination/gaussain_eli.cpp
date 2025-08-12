#include<stdio.h>

void run()
{
    int i,j,k,n;
    float A[20][21], m, x[20], sum = 0.0;
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


    // elimination

    for(k = 1; k <= n; ++k)
    {
        for(i = k + 1; i <= n; ++i)
        {
            m = A[i][k] / A[k][k];

            for(j = 1; j <= n+1; ++j)
            {
                A[i][j] = A[i][j] - m* A[k][j];
            }//end fpr j
        }// end for i
    }//end for k


    x[n] = A[n][n+1] / A[n][n];

    for(i = n -1 ; i >= 1; --i)
    {
        sum = 0.0;
        for(j = i + 1 ; j <= n; ++j)
        {
            sum = sum + A[i][j] * x[j];
        }//end for j
    //A[i][n+1] = A[i][n+1] - sum;
    x[i] = (A[i][n+1] - sum) / A[i][i];
    }//end of i

    printf("Solution:");
    for(i = 1; i <= n; i++)
    {
        printf("\n x = %d=%f\t",i,x[i]);
    }
    return;
}

int main()
{
    run();
    return 0;
}
