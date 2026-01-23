#include <stdio.h>
int main() {
    int n,r=0;
    scanf("%d",&n);
    do {
        r = r*10 + n%10;
        n/=10;
    } while(n!=0);
    printf("%d",r);
    return 0;
}
