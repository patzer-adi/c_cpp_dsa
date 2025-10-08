#include<stdio.h>

void run()
{
    int n,m;
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
}

int main()
{
    run();
    return 0;
}