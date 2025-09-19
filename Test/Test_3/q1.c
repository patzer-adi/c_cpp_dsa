#include <stdio.h>
// i think i made some mistakes

void run()
{
    int n;

    // Take a negative integer input
    printf("Enter a negative integer: ");
    scanf("%d", &n);

    // Validate input
    if (n >= 0) {
        printf("Please enter a negative integer.\n");
        return 1;
    }

    int i = 1;
    while (i >= n) {
        printf("%d: ", i);

        if (i % 3 == 0 && i % 5 == 0) {
            printf("Epic Combo!\n");
        } 
        else if (i % 2 == 0 && i % 3 == 0) {
            printf("FizzTwos!\n");
        } 
        else if (i % 5 == 0) {
            printf("Buzz Deep!\n");
        } 
        else if (i % 3 == 0) {
            printf("Fizz\n");
        } 
        else {
            printf("Chill\n");
        }
        i--;
    }
}

int main() {
    
    run();
    return 0;
}