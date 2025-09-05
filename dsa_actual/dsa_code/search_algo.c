#include<stdio.h>

int binary_search(int A[], int l, int r, int x)
{
    int mid;
    while(l <= r)
    {
        mid = l + (r - l) / 2;
        if(A[mid] == x)
            return mid;
        if(A[mid] > x)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}

int linear_search(int A[], int n, int x)
{
    for(int i = 0; i < n; i++)
    {
        if(A[i] == x)
            return i;
    }
    return -1;
}


void run()
{
    int n,opt,x,found;
    printf("Enter n:\n");
    scanf("%d",&n);
    int A[n];
    printf("Enter Elements in Array:\n");
    for(int i = 0; i < n; ++i)
    {
        scanf("%d",&A[i]);
    }

    printf("Enter x to find element:\n");
    scanf("%d",&x);

    printf("Enter a 0 for Linear Search Algo\n1 for Binary Search Algo:\n");
    scanf("%d",&opt);


    if(opt == 0)
        found = linear_search(A,n,x);
    else if(opt == 1)
         found = binary_search(A,0,n,x);

    if(found != -1)
    {
         printf("Element %d found at position %d:\n",x,found+1);
    }
    else
        printf("Element not found");
}

int main()
{
    run();
    return 0;
}
