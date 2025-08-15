#include <stdio.h>

void run()
{
    int n, m;
    printf("Enter n: ");
    scanf("%d", &n);

    printf("Enter m: ");
    scanf("%d", &m);

    int i = n + 1;
    do {
        if (i % m == 0) {
            printf("First number greater than %d divisible by %d is: %d\n", n, m, i);
            break;
        }
        i++;
    }
    while(i % m != 0);
    return;
}

int main() {
    
    run();

    return 0;
}
