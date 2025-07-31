#include<stdio.h>

int main()
{
    float sp, cp;
    float profit,loss;

    printf("Enter selling price:\n");
    scanf("%f",&sp);
    printf("Enter Cost price:\n");
    scanf("%f",&cp);
    
    if(sp > cp)
        {
            profit = sp - cp;
            printf("Profit is %f",profit);
        }
    else if(sp < cp)
        {
            loss = cp - sp;
            printf("Loss is %f",loss);
        }
    else
        printf("Profit and loss is the same:");
    return 0;
}