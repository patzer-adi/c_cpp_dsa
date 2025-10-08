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


    printf("Printing upper triangluar elements array elements: %d:\n",x);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(i > j)  // row idx > col idx
                printf("%d\t",arr[i][j]);

}

int main()
{
    run();
    return 0;
}