#include<stdio.h>
//pattern columns are constant
/*
* * *
* * *
* * *
* * *
*/


void run()
{
    int n,i,j,k;
    printf("Enter n:\n");
    scanf("%d",&n);
    for(i = 0; i < n; i++)
    {
        printf("* * *\n");
    }

}

int main()
{
    run();
    return 0;
}