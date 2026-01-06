#include <stdio.h>
int main() {
    int i=0,x,sum=0,prod=1;
    do {
        scanf("%d",&x);
        sum += x;
        prod *= x;
        i++;
    } while(i < 5);
    printf("%d %d",sum,prod);
    return 0;
}
