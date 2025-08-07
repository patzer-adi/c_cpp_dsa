#include<stdio.h>

int main()
{
    int i,j,cnt=0;
    printf("Prime numbers:\n");
    for(int i = 2; i <= 1000; ++i)
    {
        cnt = 0;
    for(int j = 2; j <= i/2; ++j)
    {
        if(i % j == 0)
        {
            cnt++;
            break;
        }
    }

    if(cnt == 0)
        printf("%d\n",i);
    else
    continue;
    }
    return 0;
}