#include <stdio.h>

void run()
{
    int n;
    printf("Enter n:\n");
    scanf("%d", &n);
    printf("Divisible by 3 or 5\n");
    for (int i = 1; i <= n; ++i) 
    {
        if (i % 3 == 0 || i % 5 == 0) 
        {  
            continue;
        }
        else
            printf("Not Divisble 3 0r 5, i = %d\n",i);
    }
    
    return;
}


int main() {
    
    run();
    return 0;
}
