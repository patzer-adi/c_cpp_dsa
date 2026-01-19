#include <stdio.h>
int main() {
    int n,a=0,b=1,c,i=1;
    scanf("%d",&n);
    do {
        printf("%d ",a);
        c=a+b;
        a=b;
        b=c;
        i++;
    } while(i<=n);
    return 0;
}
