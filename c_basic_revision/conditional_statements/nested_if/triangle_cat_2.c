#include<stdio.h>

int main()
{
    int s1,s2,s3;
    printf("Enter three sides of a triangle:\n");
    scanf("%d %d %d",&s1,&s2,&s3);
    if( s1 == s2)
        {
            if(s1 == s3)
                printf("Triangle is equilateral\n");
            else
                printf("Triangle is Isoceles\n");
        }
    else
    {
        if(s1 == s2 || s2 == s3)
            printf("Triangle is Isoceles.\n");
        else
            printf("Triangke is Scalene.\n");
    }
    return 0;

}