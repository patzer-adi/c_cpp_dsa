#include<stdio.h>

//i wrote like this

void run()
{
    float amt, discount_per;;

    printf("Enter amount in rupees:\n");
    scanf("%f",&amt);

    if(amt < 50)
    {
        printf("Discount is 0%%\n"); // i made msitake by writing only %
        discount_per = 0;
    }
    else if(amt >= 50 && amt <= 100)
    {
        printf("Discount is 10%%\n");
        discount_per = 0.1;
    }
    else if(amt >= 101 && amt <= 200)
    {
        printf("Discount is 20%%\n");
        discount_per = 0.2;
    }
    else if(amt > 200)
    {
        printf("Discount is 30%%\n");
        discount_per = 0.3;
    }
    printf("Discounted Price is %f\n", amt - (amt * discount_per)); // i wrote this as redundant code
    return;
}


int main()
{
    run();
    return 0;
}
