#include <stdio.h>
//            1
//          1   1
//        1   2   1
//      1   3   3   1
//    1   4   6   4   1

void printPascalsTriangle(int n) {
    for (int line = 0; line < n; line++) {
        int num = 1;  // first number in a line is always 1
        for (int space = 0; space < n - line - 1; space++) {
            printf("  ");  // spacing for triangle shape
        }
        for (int i = 0; i <= line; i++) {
            printf("%4d", num);  
            num = num * (line - i) / (i + 1);  // formula for next binomial coefficient
        }
        printf("\n");
    }
}

int main() {
    int rows;
    printf("Enter number of rows: ");
    scanf("%d", &rows);

    printPascalsTriangle(rows);

    return 0;
}
