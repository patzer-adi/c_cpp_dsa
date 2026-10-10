#include "QuadraticFactorizer.hpp"
#include <cmath>
#include <sstream>
#include <iostream>
using namespace std;

static string formatNum(double val) {
    if (val == (int)val) return to_string((int)val);
    stringstream ss;
    ss << val;
    return ss.str();
}

string QuadraticFactorizer::factorize() {
    double disc = b * b - 4 * a * c;
    stringstream result;

    if (disc >= 0) {
        double r1 = (-b + sqrt(disc)) / (2 * a);
        double r2 = (-b - sqrt(disc)) / (2 * a);

        string s1 = "", s2 = "";

        if (a != 1) s1 += formatNum(a) + "x";
        else s1 += "x";
        if (-r1 > 0) s1 += "+" + formatNum(-r1);
        else if (-r1 < 0) s1 += formatNum(-r1);

        s2 += "x";
        if (-r2 > 0) s2 += "+" + formatNum(-r2);
        else if (-r2 < 0) s2 += formatNum(-r2);

        result << "(" << s1 << ")(" << s2 << ")";
    } else {
        double realPart = -b / (2 * a);
        double imagPart = sqrt(-disc) / (2 * a);

        string s1 = "x", s2 = "x";
        if (-realPart != 0) {
            if (-realPart > 0) { s1 += "+" + formatNum(-realPart); s2 += "+" + formatNum(-realPart); }
            else { s1 += formatNum(-realPart); s2 += formatNum(-realPart); }
        }
        s1 += "+" + formatNum(imagPart) + "i";
        s2 += "-" + formatNum(imagPart) + "i";

        if (a != 1) result << formatNum(a) << "(" << s1 << ")(" << s2 << ")";
        else result << "(" << s1 << ")(" << s2 << ")";
    }

    return result.str();
}

void QuadraticFactorizer::run() {
    try {
        cout << "Enter coefficients a b c: ";
        cin >> a >> b >> c;

        if (a == 0) throw invalid_argument("Coefficient 'a' cannot be zero");

        cout << factorize() << endl;
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
}
