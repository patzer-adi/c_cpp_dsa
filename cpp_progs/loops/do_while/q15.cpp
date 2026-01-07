#include <stdio.h>
int main() {
    int i=0,x,prod=1;
    do {
        scanf("%d",&x);
        if(x%2!=0) prod*=x;
        i++;
    } while(i<10);
    printf("%d",prod);
    return 0;
}
