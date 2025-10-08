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
    for(int col = 0; col < m; col++)
        scanf("%d",&arr[x-1][col]);
    
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