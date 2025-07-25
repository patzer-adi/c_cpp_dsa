#include<stdio.h>
#include<math.h>

int main()
{
    int a,b,c,ans;
    float x,y;
    printf("Enter intgers a, b, c:\n");
    scanf("%d %d %d",&a,&b,&c);
    ans = b * b - 4 * a * c;
    if(ans < 0)
    {
    printf("the determinant is zero:");
    return 0;
    }
    x = -b + sqrt(ans);
    y = -b - sqrt(ans);
    printf("Roots: x,y: (%f,%f)\n",x,y);
    return 0;

}
