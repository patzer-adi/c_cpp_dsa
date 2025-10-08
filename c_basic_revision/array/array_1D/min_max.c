#include<stdio.h>

void run(int arr[], int n)
{
    int min = arr[0], max = arr[0];
    for(int i = 1; i < n; i++)
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
    int arr1[] = {1,7,8,2,9,5,17,3,4};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    run(arr1,n);
    int arr2[] = {0,12,17,-8,21,19,-5,7,3,-4,9,1};
    n = sizeof(arr2) / sizeof(arr2[0]);
    run(arr2,n);
    return 0;
}