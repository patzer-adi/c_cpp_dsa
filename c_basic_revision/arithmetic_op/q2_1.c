#include<stdio.h>
#include<math.h>
int main()
{
    float x,y;
    float ans;
    printf("Enter two numbers:\n");
    scanf("%f %f",&x,&y);
    ans = x * x * x + 3 * x* x + 4* x - y * y * y ;
    printf("Answer: n1/n2: %f\n",ans);

    return 0;
}
