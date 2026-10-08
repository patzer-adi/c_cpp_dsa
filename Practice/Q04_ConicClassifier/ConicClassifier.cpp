#include "ConicClassifier.hpp"
#include <cmath>
#include <iostream>
using namespace std;

string ConicClassifier::classify() {
    double delta = a * (b * c - f * f) - h * (h * c - f * g) + g * (h * f - b * g);
    double abh2 = a * b - h * h;
    double eps = 1e-6;

    if (fabs(delta) > eps) {
        if (abh2 > eps) {
            if (fabs(a - b) < eps && fabs(h) < eps) return "circle";
            else return "ellipse";
        } else if (fabs(abh2) < eps) {
            return "parabola";
        } else {
            return "hyperbola";
        }
    } else {
        if (abh2 > eps) return "two imaginary lines";
        else if (fabs(abh2) < eps) return "two real parallel lines";
        else return "two real intersecting lines";
    }
}

void ConicClassifier::run() {
    try {
        cout << "Enter coefficients a b c h g f: ";
        cin >> a >> b >> c >> h >> g >> f;
        cout << classify() << endl;
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
}
