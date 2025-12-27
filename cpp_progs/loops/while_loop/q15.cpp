#include <iostream>
using namespace std;
int main() {
    int x, i = 0, mul = 1;
    while (i < 10) {
        cin >> x;
        if (x % 2 != 0) mul *= x;
        i++;
    }
    cout << mul;
}
