#include <stdio.h>
int main() {
    int x,y,i=1,p=1;
    scanf("%d%d",&x,&y);
    do {
        p*=x;
        i++;
    } while(i<=y);
    printf("%d",p);
    return 0;
}
