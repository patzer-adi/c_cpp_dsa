#include <stdio.h>

void run()
{
    int n1, n2;

    printf("Enter two distinct integers:\n");
    scanf("%d %d", &n1, &n2);

    if (n1 == n2) {
        printf("Error: Numbers are not distinct.\n");
        return;
    }

    (n1 < n2) ?  (printf("The larger number is: %d\n",n2)) :  printf("The larger number is: %d\n",n1);
    return;
}

int main() {
    run();
    return 0;
}
