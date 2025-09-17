#include<stdio.h>
#include<stdlib.h>

void run()
{
    int n;
    printf("Enter n size of array:\n");
    scanf("%d",&n);
    int *arr = (int *)malloc(n * sizeof(int));

    if(arr == NULL) printf("Memory allocation failed");

    printf("Enter array elements:\n");
    for(int i = 0; i < n; i++)
        scanf("%d",&arr[i]);

    int min = arr[0], max = arr[0];
    for(int i = 1; i < n; i++)
    {
        if(arr[i] > max)
            max = arr[i];
        if(arr[i] < min)
            min = arr[i];
    }
    printf("Max: %d\nMin: %d\n",max,min);

    free(arr);
}


int main()
{
    run();
    return 0;
}