#include <stdio.h>

void run()
{
    int n;
    printf("Enter n:\n");
    scanf("%d", &n);
    printf("Divisible by both 4 and 6\n");
    for (int i = 2; i <= n; ++i) 
    {
        if (i % 4 == 0 && i % 6 == 0) 
        {  
            printf("%d\n", i);
            break;
        }
        else
            printf("none,i = %d\n",i);
    }
    
    return;
}


int main() {
    
    run();
    return 0;
}
