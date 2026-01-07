#include <stdio.h>
int main() {
    int i=0,x,sum=0,prod=1;
    do {
        scanf("%d",&x);
        if(x%2==0) sum+=x;
        else prod*=x;
        i++;
    } while(i<10);
    printf("%d %d",sum,prod);
    return 0;
}
