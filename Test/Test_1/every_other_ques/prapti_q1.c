#include <stdio.h>

void run()
{
     int num;
    
    printf("Enter an integer: ");
    scanf("%d", &num);
    
    (num % 2 == 0) ? printf("The number %d is Even.\n", num) 
                   : printf("The number %d is Odd.\n", num);
    return;
}
int main() {
    
    run();
    return 0;
}