#include <stdio.h>
int main() {
    int i=0,x,sum=0;
    do {
        scanf("%d",&x);
        if(x%2==0) sum+=x;
        i++;
    } while(i<10);
    printf("%d",sum);
    return 0;
}
