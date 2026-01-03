#include <stdio.h>
int main() {
    int n,sum=0;
    scanf("%d",&n);
    do {
        sum += n % 10;
        n /= 10;
    } while(n != 0);
    printf("%d",sum);
    return 0;
}
