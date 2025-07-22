#include<stdio.h>

int main()
{
    int num, res;
    printf("Enter a number:\n");
    scanf("%d",&num);
    if(num >= 100 && num <200)
        {
            res = num / 3;
            if (res < 50)
                printf("small no and num / 3");
            else
                printf("Not a big num and num / 3");
        }
    else if(num >= 200 && num < 300)
        {   
            res = num / 2;
            if( res < 110)
                printf("a numbe / 2");
            else{
                res = num / 5;
                printf("number is / 5");
            }
        }
    else if(num > 300)
        printf("very big num");
    else
        printf("very small number ");
    return 0;
}