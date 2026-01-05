#include <stdio.h>
int main() {
    int n,sum=0,d;
    scanf("%d",&n);
    do {
        d = n % 10;
        if(d % 2 != 0) sum += d;
        n /= 10;
    } while(n != 0);
    printf("%d",sum);
    return 0;
}
