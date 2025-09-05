#include<stdio.h>

void swap(int *a, int *b)
{
    int c;
    c = *a;
    *a = *b;
    *b = c;

    return;
}


void selection_sort(int A[], int n)
{

    int i,j,pos;
    for(i = 0; i < n-1; ++i)
    {
        pos = i;
    for(j = i+1; j < n; ++j)
    {
        if(A[j] < A[pos])
            pos = j; //find the minimum element position...
    }
    swap(&A[i],&A[pos]);
    }
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

   selection_sort(A,n);
   printf("Sorted Elements in Array:\n");
   for(int i = 0; i < n; ++i)
   {
       printf("%d\n",A[i]);
   }
}

int main()
{
    run();
    return 0;
}
