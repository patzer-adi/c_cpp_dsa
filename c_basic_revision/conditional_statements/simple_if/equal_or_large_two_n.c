#include<stdio.h>

int main()
{
    int n1,n2;
    printf("Enter Two numbers:");
    scanf("%d %d",&n1,&n2);

    if(n1 > n2)
        printf("n1 %d is larger\n",n1);
    else if(n1 < n2)
        printf("n2 %d is larger\n",n2);
    else
        printf("equal\n");

    return 0;
}
