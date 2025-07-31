#include<stdio.h>

int main()
{
    int yr;
     printf("Enter Leap Year:");
    scanf("%d",&yr);
    if((yr % 4 == 0) && (yr % 100 != 0 || yr % 400 ==0))
    {
            printf("Year is leap");
    }
    else
        printf("Not leap");
}
