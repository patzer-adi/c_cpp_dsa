#include<stdio.h>
#include<limits.h>

int main()
{
    int n;
    printf("Enter number of elements:");
    scanf("%d",&n);
    int a[n];
    printf("Enter array elements:\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Printing array elements:\n");
    for(int i = 0; i < n; i++)
    {
        printf("%d\t",a[i]);
    }
    int min=a[0], max=a[0], avg=0;
    for(int i = 0; i < n; i++)
    {
        if(a[i] < min)
        {
        min = a[i];
        }
        if(a[i] > max)
        {
            max = a[i];
        }
        avg += a[i];
    }
    avg = avg / n;
    printf("\nMin:%d\n,Max: %d\n,Avg: %d\n",min,max,avg);
}
