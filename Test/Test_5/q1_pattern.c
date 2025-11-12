// 1. Attempt ALL Write a C program that prints the following pattern using a while loop: Accept n from the user. For example n = 5, the output should be

// 1 2 3 4 5
// 	1 2 3 4
//     1 2 3
//        1 2
//          1


#include <stdio.h>

int main() {
    int n, i, j, space;
    printf("Enter n: ");
    scanf("%d", &n);

    i = n;
    while (i >= 1) {
        space = n - i;
        while (space > 0) {
            printf("  "); // two spaces
            space--;
        }

        j = 1;
        while (j <= i) {
            printf("%d ", j);
            j++;
        }
        printf("\n");
        i--;
    }
    return 0;
}
