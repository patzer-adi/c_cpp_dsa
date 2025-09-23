#include <stdio.h>
///   made a mistake in intializig j loop
void run()
{
    int n, i = 1;

    // Accept input from the user
    printf("Enter the value of n: ");
    scanf("%d", &n);

    // Outer loop for each line
    while (i <= n) {
        int j = 1;

        // Inner loop to print numbers from 1 to i
        while (j <= i) {
            printf("%d ", j);
            j++;
        }

        printf("\n");  // Move to next line
        i++;
    }
    return;
}

int main() {
    run();
    return 0;
}