#include <iostream>
using namespace std;

int main() {
    int x, y;
    long long result = 1;

    cout << "Enter base (x): ";
    cin >> x;
    cout << "Enter exponent (y): ";
    cin >> y;

    for (int i = 1; i <= y; i++) {
        result *= x;
    }

    cout << x << "^" << y << " = " << result;
    return 0;
}
