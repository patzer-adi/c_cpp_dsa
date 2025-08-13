#include<stdio.h>

#include<stdio.h>
//pattern columns are constant
/*
0 1     0 2     0 3
1 2     1 3
2 3
*/



void run()
{
    int n,i,j;
    printf("Enter n:");
    scanf("%d",&n);
    for(int i = 0; i < n-1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            printf("%d %d\t",i,j);
        }
        printf("\n");
    }
    return;
}

int main()
{
    run();
    return 0;
}