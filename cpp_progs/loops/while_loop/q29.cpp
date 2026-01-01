#include <iostream>
using namespace std;
int main() {
    int n, a = 0, b = 1, c, i = 1;
    cin >> n;
    while (i <= n) {
        cout << a << " ";
        c = a + b;
        a = b;
        b = c;
        i++;
    }
}
