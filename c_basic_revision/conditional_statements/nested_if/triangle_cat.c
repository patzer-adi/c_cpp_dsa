#include<stdio.h>

int main()
{
    int s1,s2,s3;
    printf("Enter three sides of a triangle:\n");
    scanf("%d %d %d",&s1,&s2,&s3);
    if( s1 == s2 && s2 == s3)
        printf("Triangle is equliateral\n");
    else if(s1 == s2  && s1 != s3 || s2 == s3  && s2 != s1 || s1 == s3  && s1 != s2)
        printf("Triangle is Isoceles\n");
    else if(s1 != s2 && s2 != s3 && s1 != s3)
        printf("It is a scalene triangle [all sides are unequal]\n");

    return 0;

}