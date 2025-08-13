#include<stdio.h>

//pattern columns 
//there is a problem in pattern check it
/*
0 1 2   0 2 2   0 3 2
1 2 3   1 3 3
2 3 4
*/

void run()
{
    int n,i,j,k;
    printf("Enter n:");
    scanf("%d",&n);
    for(i = 0; i < n-1; i++)
    {
        for(j = i + 1; j < n; j++)
        {

            for(k = j +1; j < n; j++)
            {
            printf("%d %d %d\t",i,j,k);
            }

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