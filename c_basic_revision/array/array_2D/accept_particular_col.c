#include<stdio.h>

void run()
{
    int n,m;
    printf("Enter value of n,m:");
    scanf("%d%d",&n,&m);
    int arr[n][m];


    int x;
    printf("Enter value of x:");
    scanf("%d",&x);

    printf("Enter array elements in x: %d:\n",x);
    for(int row = 0; row < m; row++)
        scanf("%d",&arr[row][x]);
    
    printf("Printing array elements:\n");

    for(int rows = 0; rows < m; rows++)
    {
        for(int col = 0; col < m; col++)
        {
            printf("%d\t",arr[rows][col]);
        }
        printf("\n");
    }
}

int main()
{
    run();
    return 0;
}