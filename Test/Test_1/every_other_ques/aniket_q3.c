#include <stdio.h>

void run()
{
    int temp;

    for (int i = 1; i <= 7; i++) {
        printf("Enter temperature for day %d: ", i);
        scanf("%d", &temp);

        if (temp >= 35)
            printf("Very Hot\n");
        else if (temp >= 25)
            printf("Warm\n");
        else if (temp >= 15)
            printf("Cool\n");
        else
            printf("Cold\n");
    }

}

int main() {
    run();
    return 0;
}
