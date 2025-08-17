#include <stdio.h>

void run()
{
    int n, day;
    printf("Enter the number of inputs: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter day number %d: ", i + 1);
        scanf("%d", &day);

        switch (day) {
            case 1:
                printf("Monday\n");
                break;
            case 2:
                printf("Tuesday\n");
                break;
            case 3:
                printf("Wednesday\n");
                break;
            case 4:
                printf("Thursday\n");
                break;
            case 5:
                printf("Friday\n");
                break;
            case 6:
                printf("Saturday\n");
                break;
            case 7:
                printf("Sunday\n");
                break;
            default:
                printf("Invalid day\n");
        }
    }

}

int main()
{        
    run();
    return 0;
}
