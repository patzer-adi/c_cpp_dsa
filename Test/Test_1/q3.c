#include <stdio.h>
// i wrote like this
void run()
{
    int n, marks;

    printf("Enter number of students: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        printf("Enter marks for student %d: ", i);
        scanf("%d", &marks);

        if (marks >= 90) {
            printf("Grade A\n");
            continue;// continue is redundant
        } else {
            if (marks >= 75 && marks < 90) {
                printf("Grade B\n");
                continue;
            } else {
                if (marks >= 60 && marks < 75) {
                    printf("Grade C\n");
                    continue;
                } else {
                    if (marks >= 40 && marks < 60) {
                        printf("Grade D\n");
                        continue;
                    } else {
                        printf("Fail\n");
                        continue;
                    }
                }
            }
        }
    }

    return;

}

int main() {
    
    run();
    return 0;
}
