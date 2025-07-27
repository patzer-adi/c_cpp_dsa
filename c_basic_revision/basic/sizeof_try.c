#include<stdio.h>

int main()
{
    int n;
    float n1;
    double n2;
    char ch;
    printf("Enter an integer float, a double, character :\n");
    scanf("%d %f %lf %c",&n,&n1,&n2,&ch);
    printf("%d and its size %d:\n",n,sizeof(n));
    printf("%f and its size %d:\n",n1,sizeof(n1));
    printf("%lf and its size %d:\n",n2,sizeof(n2));
    printf("%c and its size %d:\n",ch,sizeof(ch));
    return 0;
}
