#include<stdio.h>

void run()
{
    int n,k,fact=1;
    printf("Enter n:\n");
    scanf("%d",&n);
    k =1;
    while(1)
    {
        int fact = 1;
        for(int f = k; f > 0; f--)
        {
            fact = fact * f;
        }
        if(fact <= n)
        {
            ++k;
            continue;
        }
        else
            break;
    }
    printf("%d",k-1);
}

int main()
{
    run();
    return 0;
}