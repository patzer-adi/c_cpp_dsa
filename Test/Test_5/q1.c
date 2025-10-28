// pattern
// 1 2 3 4 5
//   1 2 3 4
//     1 2 3
//       1 2
//         1

#include<stdio.h>

int main()
{
    int i=0,n,j;
    printf("Enter any number n:");
    scanf("%d",&n);
    while(i <= n)
    {
        j = 1;
        if(i <= j)
        {
        while(j <= n - i)
        {
            printf("%d",j);
        }
        }
        else 
        {
            while(j <= i)
                printf(" ");
        }
    }
return 0;
}