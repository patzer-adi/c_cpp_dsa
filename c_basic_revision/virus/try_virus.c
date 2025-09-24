#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


void run()
{
    while(1)
    {
        int *arr = (int *)malloc(sizeof(int) * 1000);
        if(arr == NULL){
            printf("allocation did not happen");
            exit(-1);
        }
    }
}

int main()
{
    run();
    return 0;
}