#include <stdio.h>

void run()
{
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        char symbol = (i % 2 == 1) ? '#' : '*';
        for (int j = 1; j <= n; j++) {
            printf("%c ", symbol);
        }
        printf("\n");
    }

}


int main() {
    run();
    return 0;
}
