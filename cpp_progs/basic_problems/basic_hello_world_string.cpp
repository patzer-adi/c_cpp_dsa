#include <stdio.h>

int main() {
    int i;
    float f;
    double d;
    long double ld;
    char c;

    printf("Enter int, float, double, long double and char:\n");
    scanf("%d %f %lf %Lf %c", &i, &f, &d, &ld, &c);

    printf("Int: %d\n", i);
    printf("Float: %f\n", f);
    printf("Double: %lf\n", d);
    printf("Long double: %Lf\n", ld);
    printf("Char: %c\n", c);

    return 0;
}
