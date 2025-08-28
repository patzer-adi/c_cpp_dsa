#include <stdio.h>

void run()
{
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    int i = n;

    while (1) {
        printf("%d", i);
        i--;
        if (i == 0) {
           break;
        }
        else
        {
            printf("-");
        }
    }

    printf("\n");
    return;
}

int main() {
    run();
    return 0;
}
