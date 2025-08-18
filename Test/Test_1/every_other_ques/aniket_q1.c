#include <stdio.h>

void run()
{
    int hasHorn, canFly;

    printf("Does it have a horn? (1 for Yes, 0 for No): ");
    scanf("%d", &hasHorn);

    printf("Can it fly? (1 for Yes, 0 for No): ");
    scanf("%d", &canFly);

    if (hasHorn == 1) {
        if (canFly == 1)
            printf("Alicorn\n");
        else
            printf("Unicorn\n");
    } else {
        if (canFly == 1)
            printf("Pegasus\n");
        else
            printf("Horse\n");
    }
}

int main() {
    
    run();
    return 0;
}
