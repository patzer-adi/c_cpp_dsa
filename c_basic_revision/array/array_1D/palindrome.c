#include<stdio.h>

int main()
{
    int n;
    printf("Enter n size of array:\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter array elements:\n");
    for(int i = 0; i < n; i++)
        scanf("%d",&arr[i]);


    int i = 0,flag =1;


    for(i=0; i < n && flag; i++)
    {
        if(arr[i] == arr[n - 1 -i])
            flag = 1;
        else
            flag = 0;
    }

    if(flag)
        printf("Palindrome");
    else
        printf("Not Palindrome");
    return 0;
}
