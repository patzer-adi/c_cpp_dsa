#include<stdio.h>

void run()
{
    int n, x, count = 0;
    printf("Enter a number n:\n");
    scanf("%d",&n);
    int arr[n];
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    
    
    printf("Enter a elements in array:\n");
    for(int i = 0; i < n; i++)
    {
        printf("%d",arr[i]);
    }

    printf("Enter a number x to search frequency:\n");
    scanf("%d",&x);
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == x)
            count++;
    }
    printf("Count of %d is %d",x,count);
}


int main()
{
    run();
    return 0;
}