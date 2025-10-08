#include<stdio.h>
#include<stdlib.h>

void run()
{
    int n;
    printf("Enter n size of array:\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter array elements:\n");
    for(int i = 0; i < n; i++)
        scanf("%d",&arr[i]);

    int i = 0, j = n -1;
    while(i < j)
    {
        if(arr[i] != arr[j])
            {
                printf("Not palindrome\n");
                exit(0);
            }
        i++, j--;
    }
    printf("Palindrome\n");

}

int main()
{
    run();
    return 0;
}