#include<stdio.h>

int main()
{
    int n;
    printf("Enter the end number:");
    scanf("%d",&n);
    int i1 = 0, i2=1,cnt = 0,fn;
    while(cnt <= n)
    {
    printf("%d\n",i1);
    fn = i1 + i2;
    i1 = i2;
    i2 = fn;
    cnt += 1;
    }
    return 0;
}
