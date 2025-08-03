#include<stdio.h>
#include<math.h>
int main()
{
    float x,y;
    float ans;
    printf("Enter two numbers:\n");
    scanf("%f %f",&x,&y);
    ans = sqrt( 2 * x * x + 4 * y * y + x * x * x + 10 );
    printf("Answer: %f\n",ans);

    return 0;
}
