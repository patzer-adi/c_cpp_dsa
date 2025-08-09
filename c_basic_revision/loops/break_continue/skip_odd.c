#include <stdio.h>

void run()
{
    for (int i = 1; i <= 20; i++) {
        if (i % 2 != 0) {
            continue; 
        }
        printf("%d\n", i);
    }
    return;
}

int main() {
    run();
    return 0;

}