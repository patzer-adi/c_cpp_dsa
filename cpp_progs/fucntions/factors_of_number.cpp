#include <iostream>
using namespace std;

void factors(int n) {
    for (int i = 1; i <= n; i++) {
        if (n % i == 0)
            cout << i << " ";
    }
}

int main() {
    factors(24);
    return 0;
}
