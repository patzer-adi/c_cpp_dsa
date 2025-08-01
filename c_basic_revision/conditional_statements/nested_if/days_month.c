#include<stdio.h>

int main()
{
    int month, year;
    printf("Enter month number:\n");
    scanf("%d",&month);
    if(month != 2)
        if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
            printf("Day in Month %d  are 31 .\n",month);
        else
            printf("Day in Month %d  are 30 .\n",month);
    else
    {
        printf("Enter year since february:\n");
        scanf("%d",&year);
        if((year % 400 == 0) || (year % 100 != 0 && year % 4 ==0))
            printf("Day in Month %d  are 29 .\n",month);
        else
            printf("Day in Month %d  are 28 .\n",month);
    }
    return 0;

}
