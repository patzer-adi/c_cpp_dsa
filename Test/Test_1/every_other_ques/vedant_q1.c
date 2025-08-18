#include <stdio.h>

void run()
{
    char color;

    printf("Enter a color code (R, G, B): ");
    scanf(" %c", &color);  

    if (color >= 'A' && color <= 'Z') {
        color = color + ('a' - 'A');
    }

    switch (color) {
        case 'r':
            printf("Mood: Angry\n");
            break;
        case 'g':
            printf("Mood: Happy\n");
            break;
        case 'b':
            printf("Mood: Sad\n");
            break;
        default:
            printf("Mood: Unknown color code\n");
    }
return;
}
int main() {
    
    run();
    return 0;
}
