#include <stdio.h>
int main() {
    int a[10],i=0,max;
    do {
        scanf("%d",&a[i]);
        i++;
    } while(i<10);

    max=a[0]; i=1;
    do {
        if(a[i]>max) max=a[i];
        i++;
    } while(i<10);
    printf("%d",max);
    return 0;
}
