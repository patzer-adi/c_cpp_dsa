#include <stdio.h>
int main() {
    int n,f=1;
    scanf("%d",&n);
    do {
        f*=n;
        n--;
    } while(n>0);
    printf("%d",f);
    return 0;
}
