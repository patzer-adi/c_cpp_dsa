#include <stdio.h>

void run()
{
    int n,last_dig;
    printf("Enter n:\n");
    scanf("%d", &n);
    printf("Skipping last 5\n");
    for (int i = 0; i <= n; ++i) 
    {
        last_dig = i % 10;
        if (last_dig == 5) 
        {  
            continue;
        }
        else
            printf("i = %d\n",i);
    }
    
    return;
}


int main() {
    
    run();
    return 0;
}
