#include <stdio.h>

void run()
{
    int n;

    printf("Enter value of n: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        int j = 1;
        while (j <= 10) {
            int product = i * j;

            if (product % 5 == 0)
                printf("[%d] ", product);
            else
                printf("%d ", product);

            j++;
        }
        printf("\n");
    }

}

int main() {
    run();
    return 0;
}
