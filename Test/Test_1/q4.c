#include <stdio.h>
/// agian i wrote something like this

void run() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    int i = 1;
    int num = 1;

    while (i <= n) {
        for (int j = 1; j <= n; j++) {
            if ((i + j) % 2 == 0) {
                printf("%d ", num);
                num++;
            } else {
                printf("- ");
            }
        }
        printf("\n");
        i++;
    }
}

int main() {
    run();
    return 0;
}
