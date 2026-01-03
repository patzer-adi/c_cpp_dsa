#include <stdio.h>
int main() {
    int n,i=1,sum=0;
    scanf("%d",&n);
    do {
        sum += i;
        i+=2;
    } while(i <= n);
    printf("%d",sum);
    return 0;
}
