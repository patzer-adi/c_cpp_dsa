#include<stdio.h>
#include<math.h>

int main()
{
    int a,b,c;
    double n1,n2,d,x0,x1;
    double tmp = 0;
    printf("Enter a,b,c values:\n");
    scanf("%d %d %d",&a,&b,&c);
    tmp = sqrt(b*b - 4 * a * c);
    n1 = - b + tmp;
    n2= -b - tmp;
    d = 2 * a;

    x0 = n1 / d;
    x1 = n2/d;

    printf("x0: %lf\n",x0);
    printf("x1: %lf\n",x1);

    return 0;
}
