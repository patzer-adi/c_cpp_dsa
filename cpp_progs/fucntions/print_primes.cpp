#include <iostream>
using namespace std;

void printPrimes(int start, int end) {
    for (int i = start; i <= end; i++) {
        if (i <= 1) continue;
        bool prime = true;
        for (int j = 2; j <= i / 2; j++) {
            if (i % j == 0) {
                prime = false;
                break;
            }
        }
        if (prime)
            cout << i << " ";
    }
}

int main() {
    printPrimes(10, 30);
    return 0;
}
