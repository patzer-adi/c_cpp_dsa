#include <stdio.h>
int main() {
    int n,temp,r=0;
    scanf("%d",&n);
    temp=n;
    do {
        r=r*10 + n%10;
        n/=10;
    } while(n!=0);
    if(r==temp) printf("Palindrome");
    else printf("Not Palindrome");
    return 0;
}
