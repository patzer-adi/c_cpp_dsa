#include<stdio.h>

int main()
{
int i,j,k,r,c;
float A[20][21], m, x[20], sum = 0.0,pivot;
printf("Enter nxm of matrix:\n");
scanf("%d %d",&r,&c);

printf("Enter the elments of augumented matrix:\n");
    for(i = 0; i < r; i++)
    {
        for(j = 0; j <= c; j++)
        {
            printf("A[%d][%d]: ",i,j);
            scanf("%f",&A[i][j]);
        }//end for j
    }//end for i


    //print matirx:
    printf("Enter the print matrix:\n");
    for(i = 0; i < r; i++)
    {
        for(j = 0; j <= c; j++)
        {
            printf("%f\t",A[i][j]);
        }
        printf("\n");
    }
//sailys code for converting 1st row as [1 x x]
/*
for(int i = n; i <= 0; --i)
    {  
        A[i][j] = A[i][j] / A[i][i];
    }
*/
    printf("Gauss elimination starts:\n");
    for(int pivotrow = 0; pivotrow < r; pivotrow++)
    {  
        pivot = A[pivotrow][pivotrow];
        //divide the first row by pivot element
        for(int col = 0; col < c+1; col++)
        {
            A[pivotrow][col] = A[pivotrow][col] / pivot; 
        }

        for(int row = pivotrow + 1; row < r; row++)
        {
            double ele = A[row][pivotrow];
            for(int col=0;col<c+1;col++)
            {
                A[row][col] = A[row][col] - (ele * A[pivotrow][col]);
            }
        }
    }
    printf("Enter the print of reduced matrix:\n");
    for(i = 0; i < r; i++)
    {
        for(j = 0; j <= c; j++)
        {
            printf("%f\t",A[i][j]);
        }
        printf("\n");
    }
    return 0;
}