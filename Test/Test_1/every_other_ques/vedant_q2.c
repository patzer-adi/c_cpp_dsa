#include <stdio.h>

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    for (int i = n; i >= 1; i--) {
        if (i % 10 == 4)
            continue;
        printf("%d ", i);
    }

    printf("\n");
    return 0;
}
