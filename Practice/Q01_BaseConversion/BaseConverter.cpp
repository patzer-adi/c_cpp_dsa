#include "BaseConverter.hpp"
#include <iostream>
using namespace std;

string BaseConverter::convert() {
    if (number == 0) return "0";

    string digits = "0123456789ABCDEF";
    string result = "";
    int n = number;

    while (n > 0) {
        result = digits[n % base] + result;
        n /= base;
    }

    return result;
}

void BaseConverter::run() {
    try {
        cout << "Enter number and base: ";
        cin >> number >> base;

        if (base < 2 || base > 16)
            throw invalid_argument("Base must be between 2 and 16");
        if (number < 0)
            throw invalid_argument("Number must be positive");

        cout << convert() << endl;
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
}
