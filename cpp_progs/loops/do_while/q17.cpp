#include <stdio.h>
int main() {
    int a[10],i=0;
    do {
        scanf("%d",&a[i]);
        i++;
    } while(i<10);

    i=0;
    do {
        printf("%d ",a[i]);
        i++;
    } while(i<10);

    printf("\nSize: %d",10);
    return 0;
}
