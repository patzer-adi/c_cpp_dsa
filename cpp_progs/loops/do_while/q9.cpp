#include <stdio.h>
int main() {
    int n,i=3;
    scanf("%d",&n);
    do {
        printf("%d ", i);
        i+=3;
    } while(i <= n);
    return 0;
}
