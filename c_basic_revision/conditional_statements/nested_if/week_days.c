#include<stdio.h>

int main()
{
    int day;
    printf("Enter day number (1-7):\n");
    scanf("%d",&day);
    if(day == 1)
        printf("Day is Sunday.\n");
    else if(day == 2)
        printf("Day is Monday.\n");
    else if(day == 3)
        printf("Day is Tuesday.\n");
    else if(day == 4)
        printf("Day is Wednesday.\n");
    else if(day == 5)
        printf("Day is Thursday.\n");
    else if(day == 6)
        printf("Day is Friday.\n");
    else if(day == 7)
        printf("Day is Saturday\n");
    else
        printf("Invaid.\n");

    return 0;

}
