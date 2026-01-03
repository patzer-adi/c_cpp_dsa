#include <stdio.h>
int main() {
    int n,i=1;
    scanf("%d",&n);
    do {
        printf("%d ", i*i);
        i++;
    } while(i <= n);
    return 0;
}
