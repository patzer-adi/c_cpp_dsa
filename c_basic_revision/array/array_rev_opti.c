#include<stdio.h>
#include<stdlib.h>

//TC - O(n)
//SC - O(1)


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

    printf("Original array\n");
    for(int i = 0; i < n; i++)
        printf("%d\t",arr[i]);
    
    int temp;
    for(int i = 0; i < n/2;++i)
    {
        temp = arr[i];
        printf("temp %d = %d\n",i,temp);
        arr[i] = arr[n-1-i]; 
        printf("a[%d]= %d\n",i,arr[i]);
        arr[n-1-i] = temp;
        printf("a[%d] =%d\n",n-1-i,arr[n-1-i]);

    }


    printf("\nReversed array\n");
    for(int i = 0; i < n; i++)
        printf("%d\t",arr[i]);

    free(arr);
    if(arr == NULL) printf("Memory deallocated");

}


int main()
{
    run();
    return 0;
}