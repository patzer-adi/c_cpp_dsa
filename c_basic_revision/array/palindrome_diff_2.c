// Space comp : O(1)
// Time comp: O(n/2)

//Space and time dont increase  based on input i.e scanf... we only want what we require for computation

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

    int i = 0, j = n -1, flag = 1;
    while(i < j)
    {
        if(arr[i] != arr[j])
            {
                flag = 0;
                break;
            }
        i++, j--;
    }
    if(flag)
        printf("Palindrome\n");
    else
        printf("Not palindrome.\n");

}

int main()
{
    run();
    return 0;
}