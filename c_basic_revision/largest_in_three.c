#include<stdio.h>

int main()
{
    int n1,n2,n3;
    printf("Enter Three numbers:");
    scanf("%d %d %d",&n1,&n2,&n3);

    if(n1 > n2 && n1 > n3)
        printf("n1");
    else if(n2 > n1 && n2 > n3)
        printf("n2");
    else if(n3 > n1 && n3 > n2)
            printf("n3");
    else if(n1 == n2 && n1 > n3)
        printf("n1,n2");
    else if(n1 == n3 && n1 > n2)
        printf("n1,n3");
    else if(n2 == n3 && n2 > n3)
        printf("n2,n3");
    else 
        printf("equal");

    return 0;
}