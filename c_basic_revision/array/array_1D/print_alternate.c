#include <stdio.h>

void printAlternate( int arr [], int n ) {
    for ( int i = 0; i < n; i+=2 ) printf("%d",arr[i]);
}

int main () {

    int arr [] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(int);

    printAlternate(arr, n);

    return 0;

}