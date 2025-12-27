#include <iostream>
using namespace std;
int main() {
    int a[5], i = 0, sum = 0, mul = 1;
    while (i < 5) {
        cin >> a[i];
        sum += a[i];
        mul *= a[i];
        i++;
    }
    cout << sum << " " << mul;
}
