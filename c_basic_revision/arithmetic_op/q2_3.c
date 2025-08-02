#include<stdio.h>
#include<math.h>
int main()
{
    float x,y;
    float ans;
    printf("Enter two numbers:\n");
    scanf("%f %f",&x,&y);
    ans = sqrt( (4 * x * x + 8 * y * y + x * x * x + 5))/2 * x * x;
    printf("Answer: %f\n",ans);

    return 0;
}
