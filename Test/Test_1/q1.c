#include <stdio.h>

void run()
{
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    if (n % 3 == 0 || n % 5 == 0 ) 
    {
        if (n % 3 == 0 && n % 5 == 0) 
        {
            printf("FizzBuzz Trap!\n");
        }
        else if(n % 3 == 0) 
        {
            printf("Fizz\n");
        }
        else
        {
            printf("Buzz\n");
        }
    } 
    else 
    {
            printf("Safe\n");
        }
    
    return;
}
int main() {
    
    run();
    return 0;
}
