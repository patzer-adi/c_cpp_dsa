#include <stdio.h>
int main() {
    char c='A';
    do {
        printf("%c ",c);
        c++;
    } while(c<='Z');
    return 0;
}
