#include <iostream>
using namespace std;

void gcdLcm(int a, int b) {
    int x = a, y = b;
    while (y != 0) {
        int temp = y;
        y = x % y;
        x = temp;
    }
    int gcd = x;
    int lcm = (a * b) / gcd;

    cout << "GCD = " << gcd << endl;
    cout << "LCM = " << lcm;
}

int main() {
    gcdLcm(12, 18);
    return 0;
}
