#include <stdio.h>

void run()
{
        int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    for (int i = n; i >= 1; i--) {
        if (i % 10 == 4)
            continue;
        printf("%d ", i);
    }

    printf("\n");
    return;
}

int main() {

    run();
    return 0;
}
