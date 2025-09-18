#include<stdio.h>
#include<stdlib.h>

//TC - O(n)
//SC - O(n)

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

    int *temp = (int *)malloc(n * sizeof(int));
    for(int i = n-1, j=0; i >= 0, j<n ;--i,++j)
    {
        temp[j] = arr[i]; 
    }

    printf("Original array\n");
    for(int i = 0; i < n; i++)
        printf("%d\t",arr[i]);

    printf("\nReversed array\n");
    for(int i = 0; i < n; i++)
        printf("%d\t",temp[i]);

    free(arr);
    free(temp);
    if(arr == NULL && temp == NULL) printf("Memory deallocated");

}


int main()
{
    run();
    return 0;
}