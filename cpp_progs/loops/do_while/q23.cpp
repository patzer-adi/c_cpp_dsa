#include <stdio.h>
int main() {
    int i=0,x,sum=0;
    do {
        scanf("%d",&x);
        sum+=x;
        i++;
    } while(i<10);
    printf("%f",(float)sum/10);
    return 0;
}
