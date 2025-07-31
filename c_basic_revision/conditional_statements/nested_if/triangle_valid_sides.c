#include<stdio.h>

int main()
{    
    int s1,s2,s3;
    printf("Enter three sides of a triangle:\n");
    scanf("%d %d %d",&s1,&s2,&s3);
    
    if( s1 + s2 < s3 || s2 + s3 < s1 || s1 + s3 < s2 || (s1 == s2 && s2 == s3))
        printf("Triangle is valid\n");
    else
        printf("It is not a triangle mathematically");

    return 0;
}