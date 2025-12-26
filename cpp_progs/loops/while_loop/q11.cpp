#include <iostream>
using namespace std;
int main() {
    int n, sum = 0;
    cin >> n;
    while (n > 0) {
        int d = n % 10;
        if (d % 2 != 0) sum += d;
        n /= 10;
    }
    cout << sum;
}
