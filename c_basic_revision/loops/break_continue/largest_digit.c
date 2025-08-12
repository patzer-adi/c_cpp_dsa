#include<stdio.h>

void run()
{
    int n,largest_dig,temp;
    printf("Enter n:\n");
    scanf("%d",&n);
    int nTemp = n;
    largest_dig = n % 10;
    while(n != 0)
    {
        n = n / 10 ;
        temp = n % 10;
        if(temp > largest_dig)
        {
            largest_dig = temp;
        }
    }
    printf("Largest digit in %d is %d",nTemp,largest_dig);
}

int main()
{
    run();
    return 0;
}