#include <iostream>
using namespace std;
int main() {
    int bin, dec = 0, base = 1;
    cin >> bin;
    while (bin > 0) {
        dec += (bin % 10) * base;
        base *= 2;
        bin /= 10;
    }
    cout << dec;
}
