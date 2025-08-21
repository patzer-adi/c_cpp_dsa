#include<stdio.h>

void run()
{
    int n,k,fact=1;
    printf("Enter n:\n");
    scanf("%d",&n);

    for(k = 2; fact <= n; ++k)
    {
        fact = fact * k;
        printf("%d = %d\n",k,fact);
    }
    printf("%d\n",k);
    printf("%d\n",fact);
    printf("The Largest k is %d",k-2);

}

int main()
{
    run();
    return 0;
}