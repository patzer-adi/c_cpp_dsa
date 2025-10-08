#include<stdio.h>

void run()
{
    int n,m,x;
    printf("Enter value pf n,m:");
    scanf("%d%d",&n,&m);
    
     int arr[n][m];

    printf("Enter array elements:\n");
    for(int rows = 0; rows < m; rows++)
        for(int col = 0; col < m; col++)
        scanf("%d",&arr[rows][col]);

    

    printf("Printing array elements:\n");
    for(int rows = 0; rows < m; rows++)
    {
        for(int col = 0; col < m; col++)
        {
            printf("%d\t",arr[rows][col]);
        }
        printf("\n");
    }

    printf("Printing diagonals elements array elements in row x: %d:\n",x);
    for(int row = 0; row < n; row++)
        printf("%d\t",arr[row][row]);

}

int main()
{
    run();
    return 0;
}