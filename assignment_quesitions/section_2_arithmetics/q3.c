// Accept the coefficients a, b and c of a quadratic equation and find its roots

#include <stdio.h>
#include <math.h>  // for sqrt()

int main() {
    double a, b, c;
    double discriminant, root1, root2, realPart, imagPart;

    // Input coefficients
    printf("Enter coefficients a, b and c: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    // Check if it's a valid quadratic equation
    if (a == 0) {
        printf("Not a quadratic equation (a cannot be 0).\n");
        return 0;
    }

    // Calculate discriminant
    discriminant = b * b - 4 * a * c;

    // Check discriminant to determine the nature of roots
    if (discriminant > 0) {
        // Two distinct real roots
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("Roots are real and distinct:\n");
        printf("Root 1 = %.2lf\n", root1);
        printf("Root 2 = %.2lf\n", root2);
    }
    else if (discriminant == 0) {
        // Two equal real roots
        root1 = -b / (2 * a);
        printf("Roots are real and equal:\n");
        printf("Root 1 = Root 2 = %.2lf\n", root1);
    }
    else {
        // Complex (imaginary) roots
        realPart = -b / (2 * a);
        imagPart = sqrt(-discriminant) / (2 * a);
        printf("Roots are complex and imaginary:\n");
        printf("Root 1 = %.2lf + %.2lfi\n", realPart, imagPart);
        printf("Root 2 = %.2lf - %.2lfi\n", realPart, imagPart);
    }

    return 0;
}
