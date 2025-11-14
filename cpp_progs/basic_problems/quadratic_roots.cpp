#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c, d, r1, r2;

    printf("Enter a, b, c: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    d = b*b - 4*a*c;

    if (d > 0) {
        r1 = (-b + sqrt(d)) / (2*a);
        r2 = (-b - sqrt(d)) / (2*a);
        printf("Real roots: %.2lf and %.2lf\n", r1, r2);
    }
    else if (d == 0) {
        r1 = -b / (2*a);
        printf("Equal roots: %.2lf\n", r1);
    }
    else {
        printf("Complex roots\n");
    }

    return 0;
}
