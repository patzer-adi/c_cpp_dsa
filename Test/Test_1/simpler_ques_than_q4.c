#include <stdio.h>

// 2 3 4 5 6 
// 3 4 5 6 7 
// 4 5 6 7 8 
// 5 6 7 8 9 
// 6 7 8 9 10

void run() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    int i = 1;
    int num = 1;

    while (i <= n) {
        for (int j = 1; j <= n; j++) {
            
                printf("%d ", i+j);
        }
        printf("\n");
        i++;
    }
}

int main() {
    run();
    return 0;
}
