#include <stdio.h>
int main() {
    int i=1,n;
    scanf("%d",&n);
    do {
        printf("%d %d %d\n", i, i*i, i*i*i);
        i++;
    } while(i <= n);
    return 0;
}
