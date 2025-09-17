#include<stdio.h>

void run()
{
    int n;
    printf("Enter n size of array:\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter array elements:\n");
    for(int i = 0; i < n; i++)
        scanf("%d",&arr[i]);
        
    int min = arr[0], max = arr[0];
    for(int i = 1; i < n+1; i++)
    {
        if(arr[i] > max)
            max = arr[i];
        if(arr[i] < min)
            min = arr[i];
    }
    printf("Max: %d\nMin: %d\n",max,min);
}


int main()
{
    run();
    return 0;
}