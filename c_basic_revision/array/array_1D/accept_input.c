#include<stdio.h>

void run()
{
    int arr[10];
    printf("Enter array elements:\n");
    for(int i = 0; i < 10; i++)
        scanf("%d",&arr[i]);
    
    printf("Printing array elements:\n");

    for(int j = 0; j < 10; j++)
        printf("%d\t",arr[j]);
}

int main()
{
    run();
    return 0;
}