#include <stdio.h>
#include <math.h>
int main() {
    int a[10],i=0;
    float mean=0,sd=0;
    do {
        scanf("%d",&a[i]);
        mean+=a[i];
        i++;
    } while(i<10);
    mean/=10;

    i=0;
    do {
        sd += pow(a[i]-mean,2);
        i++;
    } while(i<10);
    printf("%f",sqrt(sd/10));
    return 0;
}
