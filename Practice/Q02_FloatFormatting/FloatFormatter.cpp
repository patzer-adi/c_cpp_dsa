#include "FloatFormatter.hpp"
#include <iostream>
using namespace std;

string FloatFormatter::format() {
    // Remove trailing zeros from integral (becomes G)
    // Remove trailing zeros from fractional (becomes J)
    string G = integral;
    string J = fractional;

    while (G.size() > 1 && G.back() == '0') G.pop_back();
    while (J.size() > 1 && J.back() == '0') J.pop_back();

    // Decimal point at position 6, so left side = 5 chars
    int hashCount = 5 - (int)G.size();
    string hashes = "";
    for (int i = 0; i < hashCount; i++) hashes += '#';

    if (integral == "0") {
        G = "";
        hashes = "#####";
    }

    return G + hashes + "." + J;
}

void FloatFormatter::run() {
    try {
        string input;
        cout << "Enter a positive real number (F.I): ";
        cin >> input;

        size_t dot = input.find('.');
        if (dot == string::npos)
            throw invalid_argument("Input must contain a decimal point");

        fractional = input.substr(0, dot);
        integral = input.substr(dot + 1);

        cout << format() << endl;
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
}
