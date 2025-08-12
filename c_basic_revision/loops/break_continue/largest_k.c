#include<stdio.h>

void run()
{
    int n,k,fact=1, largest_k;
    printf("Enter n:\n");
    scanf("%d",&n);

    for(int i = 2; i <= n; ++i)
    {
        k = i;
        fact=1;
        while(k != 0)
        {
            fact = fact * k;
            k--; 
        }
        //largest_k = k;
        printf("%d = %d\n",i,fact);
        if(fact <= n)
            continue;
        else
        {
            printf("The Largest k is %d",i-1);
            break;
        }

    }
}

int main()
{
    run();
    return 0;
}