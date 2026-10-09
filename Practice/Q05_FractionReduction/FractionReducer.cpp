#include "FractionReducer.hpp"
#include <iostream>
#include <cmath>
using namespace std;

int FractionReducer::gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

void FractionReducer::run() {
    try {
        string input;
        cout << "Enter a positive real number: ";
        cin >> input;

        // Split at decimal point
        size_t dot = input.find('.');
        if (dot == string::npos)
            throw invalid_argument("Input must have a decimal point");

        string intPart = input.substr(0, dot);
        string fracPart = input.substr(dot + 1);

        int integral = stoi(intPart);
        int numerator = stoi(fracPart);

        // Denominator = 10^(number of digits in fracPart)
        int denominator = 1;
        for (int i = 0; i < (int)fracPart.size(); i++)
            denominator *= 10;

        if (numerator == 0) {
            cout << integral << endl;
            return;
        }

        // Reduce the fraction
        int g = gcd(numerator, denominator);
        numerator /= g;
        denominator /= g;

        if (integral != 0)
            cout << integral << " + " << numerator << " / " << denominator << endl;
        else
            cout << numerator << " / " << denominator << endl;

    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
}
