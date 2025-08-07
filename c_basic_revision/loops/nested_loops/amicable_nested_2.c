#include<stdio.h>

int main()
{
    int n1=1000, n2 = 1000;
    for(int i = 1; i < n1; i++)
    {   
        for(int j = i + 1; j < n2; j++)
        {
            int factors1 = 0, factors2 = 0;

            for(int k = 1; k <= i/2; ++k)
            {
            if(i % k == 0)
                factors1 = factors1 + k;
            }
            
            for(int k = 1; k <= j/2; ++k)
            {
            if(j % k == 0)
                factors2 = factors2 + k;
            }
        
        if(factors1 == j && factors2 == i)
            printf("%d and %d are amicable",i,j);
        }
    }
    return 0;
}