#include <stdio.h>
int main() {
    int n,i=2,flag=0;
    scanf("%d",&n);
    do {
        if(n%i==0) { flag=1; break; }
        i++;
    } while(i<=n/2);
    if(flag==0) printf("Prime");
    else printf("Composite");
    return 0;
}
