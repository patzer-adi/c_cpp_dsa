#include<stdio.h>

int main()
{
    int n1,n2, gcd,lcm,n,d,rem;
    printf("Enter n1:");
    scanf("%d",&n1);
    printf("Enter n2:");
    scanf("%d",&n2);

    if(n1 < n2)
    {
        n = n2;
        d = n1;
    }
    else
    {
        n = n2;
        d = n1;
    }
    rem = n/d;
    while(rem != 0)
    {
    n = d;
    d = rem;
    rem = n % d;
    }
    gcd = d;
    lcm = n1 * n2 / gcd;
    printf("gcd: %d\nlcm: %d\n",gcd,lcm);
    return 0;
}
