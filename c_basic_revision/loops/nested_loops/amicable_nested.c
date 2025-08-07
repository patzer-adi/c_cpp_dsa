#include<stdio.h>

int main()
{
    int n,i,j,k,factors1=0,factors2=0;
    int n1 = 1000, n2 = 1000;
    i = 1;
    while(i < n1)
    {
        j = i + 1;
        while(j < n2)
        {
            factors1 = 0;
            factors2 = 0;

            k = 1;
            while(k <= i / 2)
            {
            if(i % k == 0)
                factors1 += k;
            ++k;
            }
            k = 1;
            while( k <= j /2)
            {
                if(j % k == 0)
                    factors2 += k;
            ++k;
            }
            if(factors1 == j && factors2 == i)
                printf("%d & %d amicable\n",i,j);
            ++j;
        }
    ++i;
    }
    return 0;
}