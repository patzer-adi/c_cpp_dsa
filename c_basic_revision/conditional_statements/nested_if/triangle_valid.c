#include<stdio.h>

int main()
{
    int a1,a2,a3;
    printf("Enter three angles of a triangle:\n");
    scanf("%d %d %d",&a1,&a2,&a3);
   if(a1 > 0 && a2 > 0 && a3 > 0)
   {
    if( a1 + a2 + a3 == 180)
        printf("Triangle is valid\n");
    else
        printf("It is not a triangle mathematically");
   }
    return 0;
}
