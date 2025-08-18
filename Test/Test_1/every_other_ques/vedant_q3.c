#include <stdio.h>

void run()
{
    int n, num;

    printf("Enter how many numbers: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &num);

        (num % 2 == 0) ? printf("Even\n") : printf("Odd\n");
    }

}

int main() {
    run();
    return 0;
}
