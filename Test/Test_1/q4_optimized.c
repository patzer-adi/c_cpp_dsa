#include <stdio.h>
/// Sir gave an optimized solution

void run() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    int i = 1;
    int num = 1;

    while (i <= n) {
        for (int j = 1; j <= n; j++) {
            if ((i + j) % 2) //we changed the conditon a bit so == 1 or == 0 is not required...
                printf("- ");
            else
                printf("%d ", num++); // we dont reuqire num++ on a different lines
        }// we dont need brackets for end of if's
        printf("\n");
        i++;
    }
}

int main() {
    run();
    return 0;
}
