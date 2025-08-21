#include <stdio.h>

void run()
{
    int start, end, i;

    printf("Enter a Start number: ");
    scanf("%d", &start);

     printf("Enter n End number: ");
    scanf("%d", &end);

    for(i = start; i < end; i++)
    {
            if (i % 3 == 0 || i % 5 == 0 ) 
            {
                if (i % 3 == 0 && i % 5 == 0) 
                {
                    printf("%d is a FizzBuzz Trap!\n",i);
                }
                else if(i % 3 == 0) 
                {
                    printf("%d, Fizz\n",i);
                }
                else
                {
                    printf("%d, Buzz\n",i);
                }
            } 
            else 
            {
                    printf("%d, Safe\n", i);
                }
            

    }
    return;

}
int main() {
    
    run();
    return 0;
}
