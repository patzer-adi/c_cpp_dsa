#include<stdio.h>
#define NAME "Aditya"
int main()
{
    const float pi = 3.14;
    int r;
    printf("Enter an integer:\n");
    scanf("%d",&r);
    printf("Defined name: %s\n", NAME);
    printf("Area on constant pi: %f\n",2 * pi * r * r);

    return 0;
}
