#include <stdio.h>
#include <unistd.h>  // for usleep()

int main()
{
    int count = 1;
    while(1)
    {
        printf("Time??\n");
        count++;
        usleep(200000);  // delay for 200,000 microseconds = 0.2 seconds
    }
    return 0;
}
