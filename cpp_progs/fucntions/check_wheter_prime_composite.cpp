#include <iostream>
using namespace std;

void checkPrime(int n) {
    if (n <= 1) {
        cout << "Neither Prime nor Composite";
        return;
    }
    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0) {
            cout << "Composite Number";
            return;
        }
    }
    cout << "Prime Number";
}

int main() {
    checkPrime(7);
    return 0;
}
